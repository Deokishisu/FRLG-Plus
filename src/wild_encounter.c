#include "global.h"
#include "random.h"
#include "wild_encounter.h"
#include "event_data.h"
#include "fieldmap.h"
#include "roamer.h"
#include "field_player_avatar.h"
#include "battle_setup.h"
#include "overworld.h"
#include "metatile_behavior.h"
#include "event_scripts.h"
#include "script.h"
#include "link.h"
#include "quest_log.h"
#include "constants/maps.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/weather.h"

struct WildEncounterData
{
    u32 rngState;
    u16 prevMetatileBehavior;
    u16 encounterRateBuff;
    u8 stepsSinceLastEncounter;
    u8 abilityEffect;
    u16 leadMonHeldItem;
};

static EWRAM_DATA struct WildEncounterData sWildEncounterData = {};
static EWRAM_DATA bool8 sWildEncountersDisabled = FALSE;

static bool8 UnlockedTanobyOrAreNotInTanoby(void);
static u32 GenerateUnownPersonalityByLetter(u8 letter);
static bool8 IsWildLevelAllowedByRepel(u8 level);
static void ApplyFluteEncounterRateMod(u32 *rate);
static u8 GetFluteEncounterRateModType(void);
static void ApplyCleanseTagEncounterRateMod(u32 *rate);
static bool8 IsLeadMonHoldingCleanseTag(void);
static u16 WildEncounterRandom(void);
static void AddToWildEncounterRateBuff(u8 encouterRate);
static u8 PickWildMonNature(void);
static bool8 IsAbilityAllowingEncounter(u8 level);
static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u8 ability, u8 *monIndex);
static bool8 TryGetRandomWildMonIndexByType(const struct WildPokemon *wildMon, u8 type, u8 numMon, u8 *monIndex);
static u8 ViridianForestNuzlockeOverride(const struct WildPokemonInfo * info, u8 slot);

#include "data/wild_encounters.h"

static const u8 sUnownLetterSlots[][12] = {
  //  A   A   A   A   A   A   A   A   A   A   A   ?
    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 27},
  //  C   C   C   D   D   D   H   H   H   U   U   O
    { 2,  2,  2,  3,  3,  3,  7,  7,  7, 20, 20, 14},
  //  N   N   N   N   S   S   S   S   I   I   E   E
    {13, 13, 13, 13, 18, 18, 18, 18,  8,  8,  4,  4},
  //  P   P   L   L   J   J   R   R   R   Q   Q   Q
    {15, 15, 11, 11,  9,  9, 17, 17, 17, 16, 16, 16},
  //  Y   Y   T   T   G   G   G   F   F   F   K   K
    {24, 24, 19, 19,  6,  6,  6,  5,  5,  5, 10, 10},
  //  V   V   V   W   W   W   X   X   M   M   B   B
    {21, 21, 21, 22, 22, 22, 23, 23, 12, 12,  1,  1},
  //  Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   !
    {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26},
};

void DisableWildEncounters(bool8 state)
{
    sWildEncountersDisabled = state;
}

static u8 ChooseWildMonIndex_Land(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_LAND_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_0)
        return 0;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_1)
        return 1;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_2)
        return 2;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_3)
        return 3;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_4)
        return 4;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_5)
        return 5;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_6)
        return 6;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_7)
        return 7;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_8)
        return 8;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        return 9;
    else if (rand == ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        return 10;
    else
        return 11;
}

static u8 ChooseWildMonIndex_WaterRock(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_WATER_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_0)
        return 0;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_1)
        return 1;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_2)
        return 2;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_3)
        return 3;
    else
        return 4;
}

enum
{
    OLD_ROD,
    GOOD_ROD,
    SUPER_ROD
};

static u8 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    u8 rand = Random() % max(max(ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL, ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL),
                             ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL);

    switch (rod)
    {
    case OLD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0)
            wildMonIndex = 0;
        else
            wildMonIndex = 1;
        break;
    case GOOD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2)
            wildMonIndex = 2;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3)
            wildMonIndex = 3;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
            wildMonIndex = 4;
        break;
    case SUPER_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5)
            wildMonIndex = 5;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6)
            wildMonIndex = 6;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7)
            wildMonIndex = 7;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 8;
        if (rand == ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 9;
        break;
    }
    return wildMonIndex;
}

static u8 ChooseWildMonLevel(const struct WildPokemon * info)
{
    u8 lo;
    u8 hi;
    u8 mod;
    u8 res;
    if (info->maxLevel >= info->minLevel)
    {
        lo = info->minLevel;
        hi = info->maxLevel;
    }
    else
    {
        lo = info->maxLevel;
        hi = info->minLevel;
    }
    mod = hi - lo + 1;
    res = Random() % mod;

    // check ability for max level mon
    if (!GetMonData(&gPlayerParty[0], MON_DATA_IS_EGG))
    {
        u8 ability = GetMonAbility(&gPlayerParty[0]);
        if (ability == ABILITY_HUSTLE || ability == ABILITY_VITAL_SPIRIT || ability == ABILITY_PRESSURE)
        {
            if (Random() % 2 == 0)
                return hi;

            if (res != 0)
                res--;
        }
    }

    return lo + res;
}

static u16 GetCurrentMapWildMonHeaderId(void)
{
    u32 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader * wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == 0xFF)
            break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlock1Ptr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SIX_ISLAND_ALTERING_CAVE) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(SIX_ISLAND_ALTERING_CAVE))
            {
                u16 alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
                if (alteringCaveId > 8)
                    alteringCaveId = 0;

                i += alteringCaveId;
            }

            if (!UnlockedTanobyOrAreNotInTanoby())
                break;
            return i;
        }
    }

    return -1;
}

static bool8 UnlockedTanobyOrAreNotInTanoby(void)
{
    if (FlagGet(FLAG_SYS_UNLOCKED_TANOBY_RUINS))
        return TRUE;
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER))
        return TRUE;
    if (!(gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER)
    ))
        return TRUE;
    return FALSE;
}

static void GenerateWildMon(u16 species, u8 level, u8 slot)
{
    bool32 checkCuteCharm;
    u32 personality;
    s8 chamber;
    ZeroEnemyPartyMons();

    checkCuteCharm = TRUE;

    switch (gBaseStats[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        checkCuteCharm = FALSE;
        break;
    }

    if (species != SPECIES_UNOWN)
    {
        if (checkCuteCharm
        && !GetMonData(&gPlayerParty[0], MON_DATA_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_CUTE_CHARM
        && Random() % 3 != 0)
        {
            u16 leadingMonSpecies = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES);
            u32 leadingMonPersonality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);
            u8 gender = GetGenderFromSpeciesAndPersonality(leadingMonSpecies, leadingMonPersonality);

            // misses mon is genderless check, although no genderless mon can have cute charm as ability
            if (gender == MON_FEMALE)
                gender = MON_MALE;
            else
                gender = MON_FEMALE;

            CreateMonWithGenderNatureLetter(&gEnemyParty[0], species, level, 32, gender, PickWildMonNature(), 0);
            return;
        }
        CreateMonWithNature(&gEnemyParty[0], species, level, 32, PickWildMonNature());
    }
    else
    {
        chamber = gSaveBlock1Ptr->location.mapNum - MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER);
        personality = GenerateUnownPersonalityByLetter(sUnownLetterSlots[chamber][slot]);
        CreateMon(&gEnemyParty[0], species, level, 32, TRUE, personality, FALSE, 0);
    }
}

static u32 GenerateUnownPersonalityByLetter(u8 letter)
{
    u32 personality;
    do
    {
        personality = (Random() << 16) | Random();
    } while (GetUnownLetterByPersonalityLoByte(personality) != letter);
    return personality;
}

u8 GetUnownLetterByPersonalityLoByte(u32 personality)
{
    return (((personality & 0x3000000) >> 18) | ((personality & 0x30000) >> 12) | ((personality & 0x300) >> 6) | (personality & 0x3)) % 0x1C;
}

enum
{
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING,
};

#define WILD_CHECK_REPEL    0x1
#define WILD_CHECK_KEEN_EYE 0x2

static bool8 TryGenerateWildMon(const struct WildPokemonInfo * info, u8 area, u8 flags)
{
    u8 slot = 0;
    u8 level;
    switch (area)
    {
    case WILD_AREA_LAND:
        if (TryGetAbilityInfluencedWildMonIndex(info->wildPokemon, TYPE_STEEL, ABILITY_MAGNET_PULL, &slot))
            break;
        if (TryGetAbilityInfluencedWildMonIndex(info->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &slot))
            break;

        slot = ChooseWildMonIndex_Land();
        break;
    case WILD_AREA_WATER:
        if (TryGetAbilityInfluencedWildMonIndex(info->wildPokemon, TYPE_ELECTRIC, ABILITY_STATIC, &slot))
            break;

        slot = ChooseWildMonIndex_WaterRock();
        break;
    case WILD_AREA_ROCKS:
        slot = ChooseWildMonIndex_WaterRock();
        break;
    }
    if(gMapHeader.mapLayoutId == LAYOUT_VIRIDIAN_FOREST && gSaveBlock1Ptr->keyFlags.nuzlocke == 1)
        slot = ViridianForestNuzlockeOverride(info, slot);
    level = ChooseWildMonLevel(&info->wildPokemon[slot]);
    if (flags & WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
    {
        return FALSE;
    }
    if (flags & WILD_CHECK_KEEN_EYE && !IsAbilityAllowingEncounter(level))
        return FALSE;

    GenerateWildMon(info->wildPokemon[slot].species, level, slot);
    return TRUE;
}

static u16 GenerateFishingEncounter(const struct WildPokemonInfo * info, u8 rod)
{
    u8 slot = ChooseWildMonIndex_Fishing(rod);
    u8 level = ChooseWildMonLevel(&info->wildPokemon[slot]);
    GenerateWildMon(info->wildPokemon[slot].species, level, slot);
    return info->wildPokemon[slot].species;
}

static bool8 DoWildEncounterRateDiceRoll(u16 a0)
{
    if (WildEncounterRandom() % 1600 < a0)
        return TRUE;
    return FALSE;
}

static bool8 DoWildEncounterRateTest(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    encounterRate += sWildEncounterData.encounterRateBuff * 16 / 200;
    ApplyFluteEncounterRateMod(&encounterRate);
    ApplyCleanseTagEncounterRateMod(&encounterRate);
    if (!ignoreAbility)
    {
        switch (sWildEncounterData.abilityEffect)
        {
        case 1:
            encounterRate /= 2;
            break;
        case 2:
            encounterRate *= 2;
            break;
        }
    }
    if (encounterRate > 1600)
        encounterRate = 1600;
    return DoWildEncounterRateDiceRoll(encounterRate);
}

static u8 GetAbilityEncounterRateModType(void)
{
    sWildEncounterData.abilityEffect = 0;
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        u8 ability = GetMonAbility(&gPlayerParty[0]);
        if (ability == ABILITY_STENCH)
            sWildEncounterData.abilityEffect = 1;
        else if (ability == ABILITY_ILLUMINATE)
            sWildEncounterData.abilityEffect = 2;
        else if (ability == ABILITY_WHITE_SMOKE)
            sWildEncounterData.abilityEffect = 1;
        else if (ability == ABILITY_ARENA_TRAP)
            sWildEncounterData.abilityEffect = 2;
        else if (ability == ABILITY_SAND_VEIL && gSaveBlock1Ptr->weather == WEATHER_SANDSTORM)
            sWildEncounterData.abilityEffect = 1;
    }
    return sWildEncounterData.abilityEffect;
}

static bool8 DoGlobalWildEncounterDiceRoll(void)
{
    if ((Random() % 100) >= 60)
        return FALSE;
    return TRUE;
}

bool8 StandardWildEncounter(u32 currMetatileAttrs, u16 previousMetatileBehavior)
{
    u16 headerId;
    struct Roamer * roamer;
    const struct WildPokemonInfo * currentLandTable;
    const struct WildPokemonInfo * currentWaterTable;

    headerId = GetCurrentMapWildMonHeaderId();
    if(gSaveBlock1Ptr->keyFlags.version == 0)
    {
        currentLandTable = gWildMonHeaders[headerId].landMonsInfo_FR;
        currentWaterTable = gWildMonHeaders[headerId].waterMonsInfo_FR;
    }
    else
    {
        currentLandTable = gWildMonHeaders[headerId].landMonsInfo_LG;
        currentWaterTable = gWildMonHeaders[headerId].waterMonsInfo_LG;
    }

    if (sWildEncountersDisabled == TRUE)
        return FALSE;

    if (headerId != 0xFFFF)
    {
        if (GetMetatileAttributeFromRawMetatileBehavior(currMetatileAttrs, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_LAND)
        {
            if (currentLandTable == NULL)
                return FALSE;
            else if (previousMetatileBehavior != GetMetatileAttributeFromRawMetatileBehavior(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR) && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            if (DoWildEncounterRateTest(currentLandTable->encounterRate, FALSE) != TRUE)
            {
                AddToWildEncounterRateBuff(currentLandTable->encounterRate);
                return FALSE;
            }

            else if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                {
                    return FALSE;
                }

                StartRoamerBattle();
                return TRUE;
            }
            else
            {

                // try a regular wild land encounter
                if (TryGenerateWildMon(currentLandTable, WILD_AREA_LAND, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    StartWildBattle();
                    return TRUE;
                }
                else
                {
                    AddToWildEncounterRateBuff(currentLandTable->encounterRate);
                }
            }
        }
        else if (GetMetatileAttributeFromRawMetatileBehavior(currMetatileAttrs, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_WATER
                 || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridge(GetMetatileAttributeFromRawMetatileBehavior(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR)) == TRUE))
        {
            if (currentWaterTable == NULL)
                return FALSE;
            else if (previousMetatileBehavior != GetMetatileAttributeFromRawMetatileBehavior(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR) && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            else if (DoWildEncounterRateTest(currentWaterTable->encounterRate, FALSE) != TRUE)
            {
                AddToWildEncounterRateBuff(currentWaterTable->encounterRate);
                return FALSE;
            }

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                {
                    return FALSE;
                }

                StartRoamerBattle();
                return TRUE;
            }
            else // try a regular surfing encounter
            {
                if (TryGenerateWildMon(currentWaterTable, WILD_AREA_WATER, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
                {
                    StartWildBattle();
                    return TRUE;
                }
                else
                {
                    AddToWildEncounterRateBuff(currentWaterTable->encounterRate);
                }
            }
        }
    }

    return FALSE;
}

void RockSmashWildEncounter(void)
{
    u16 headerIdx = GetCurrentMapWildMonHeaderId();
    const struct WildPokemonInfo * currentRockTable;

    if(gSaveBlock1Ptr->keyFlags.version == 0)
    {
        currentRockTable = gWildMonHeaders[headerIdx].rockSmashMonsInfo_FR;
    }
    else
    {
        currentRockTable = gWildMonHeaders[headerIdx].rockSmashMonsInfo_LG;
    }
    if (headerIdx == 0xFFFF)
        gSpecialVar_Result = FALSE;
    else if (currentRockTable == NULL)
        gSpecialVar_Result = FALSE;
    else if (DoWildEncounterRateTest(currentRockTable->encounterRate, TRUE) != TRUE)
        gSpecialVar_Result = FALSE;
    else if (TryGenerateWildMon(currentRockTable, WILD_AREA_ROCKS, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE) == TRUE)
    {
        StartWildBattle();
        gSpecialVar_Result = TRUE;
    }
    else
        gSpecialVar_Result = FALSE;
}

bool8 SweetScentWildEncounter(void)
{
    s16 x, y;
    u16 headerId;
    const struct WildPokemonInfo * currentLandTable;
    const struct WildPokemonInfo * currentWaterTable;

    headerId = GetCurrentMapWildMonHeaderId();
    if(gSaveBlock1Ptr->keyFlags.version == 0)
    {
        currentLandTable = gWildMonHeaders[headerId].landMonsInfo_FR;
        currentWaterTable = gWildMonHeaders[headerId].waterMonsInfo_FR;
    }
    else
    {
        currentLandTable = gWildMonHeaders[headerId].landMonsInfo_LG;
        currentWaterTable = gWildMonHeaders[headerId].waterMonsInfo_LG;
    }

    PlayerGetDestCoords(&x, &y);
    if (headerId != 0xFFFF)
    {
        if (MapGridGetMetatileAttributeAt(x, y, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_LAND)
        {
            if (TryStartRoamerEncounter() == TRUE)
            {
                StartRoamerBattle();
                return TRUE;
            }

            if (currentLandTable == NULL)
                return FALSE;

            TryGenerateWildMon(currentLandTable, WILD_AREA_LAND, 0);

            StartWildBattle();
            return TRUE;
        }
        else if (MapGridGetMetatileAttributeAt(x, y, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_WATER)
        {
            if (TryStartRoamerEncounter() == TRUE)
            {
                StartRoamerBattle();
                return TRUE;
            }

            if (currentWaterTable == NULL)
                return FALSE;

            TryGenerateWildMon(currentWaterTable, WILD_AREA_WATER, 0);
            StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 DoesCurrentMapHaveFishingMons(void)
{
    u16 headerIdx = GetCurrentMapWildMonHeaderId();
    const struct WildPokemonInfo * currentFishTable;

    if(gSaveBlock1Ptr->keyFlags.version == 0)
    {
        currentFishTable = gWildMonHeaders[headerIdx].fishingMonsInfo_FR;
    }
    else
    {
        currentFishTable = gWildMonHeaders[headerIdx].fishingMonsInfo_LG;
    }
    if (headerIdx == 0xFFFF)
        return FALSE;
    if (currentFishTable == NULL)
        return FALSE;
    return TRUE;
}

void FishingWildEncounter(u8 rod)
{
    const struct WildPokemonInfo * currentFishTable;

    if(gSaveBlock1Ptr->keyFlags.version == 0)
    {
        currentFishTable = gWildMonHeaders[GetCurrentMapWildMonHeaderId()].fishingMonsInfo_FR;
    }
    else
    {
        currentFishTable = gWildMonHeaders[GetCurrentMapWildMonHeaderId()].fishingMonsInfo_LG;
    }
    GenerateFishingEncounter(currentFishTable, rod);
    IncrementGameStat(GAME_STAT_FISHING_CAPTURES);
    StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    u16 headerId;
    const struct WildPokemonInfo * landMonsInfo;
    const struct WildPokemonInfo * waterMonsInfo;

    headerId = GetCurrentMapWildMonHeaderId();
    if(gSaveBlock1Ptr->keyFlags.version == 0)
    {
        landMonsInfo = gWildMonHeaders[headerId].landMonsInfo_FR;
        waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo_FR;
    }
    else
    {
        landMonsInfo = gWildMonHeaders[headerId].landMonsInfo_LG;
        waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo_LG;
    }

    *isWaterMon = FALSE;
    if (headerId == 0xFFFF)
        return SPECIES_NONE;
    // Neither
    if (landMonsInfo == NULL && waterMonsInfo == NULL)
        return SPECIES_NONE;
        // Land Pokemon
    else if (landMonsInfo != NULL && waterMonsInfo == NULL)
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
        // Water Pokemon
    else if (landMonsInfo == NULL && waterMonsInfo != NULL)
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    // Either land or water Pokemon
    if ((Random() % 100) < 80)
    {
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    }
    else
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
}

u16 GetLocalWaterMon(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF)
    {
        const struct WildPokemonInfo * waterMonsInfo;
        if(gSaveBlock1Ptr->keyFlags.version == 0)
        {
            waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo_FR;
        }
        else
        {
            waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo_LG;
        }

        if (waterMonsInfo)
            return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    return SPECIES_NONE;
}

bool8 UpdateRepelCounter(void)
{
    u16 steps;

    if (InUnionRoom() == TRUE)
        return FALSE;

    if (gQuestLogState == QL_STATE_PLAYBACK)
        return FALSE;

    steps = VarGet(VAR_REPEL_STEP_COUNT);

    if (steps != 0)
    {
        steps--;
        VarSet(VAR_REPEL_STEP_COUNT, steps);
        if (steps == 0)
        {
            ScriptContext1_SetupScript(EventScript_RepelWoreOff);
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 IsWildLevelAllowedByRepel(u8 wildLevel)
{
    u32 i;

    if (!VarGet(VAR_REPEL_STEP_COUNT))
        return TRUE;

    if(gSaveBlock1Ptr->keyFlags.nuzlocke == 1 && NuzlockeFlagGet(GetCurrentRegionMapSectionId()) == FALSE) //if Nuzlocke & first encounter not done Repel doesn't work.
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            u8 ourLevel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);

            if (wildLevel < ourLevel)
                return FALSE;
            else
                return TRUE;
        }
    }

    return FALSE;
}

static void ApplyFluteEncounterRateMod(u32 *encounterRate)
{
    switch (GetFluteEncounterRateModType())
    {
    case 1:
        *encounterRate += *encounterRate / 2;
        break;
    case 2:
        *encounterRate = *encounterRate / 2;
        break;
    }
}

static u8 GetFluteEncounterRateModType(void)
{
    if (FlagGet(FLAG_SYS_WHITE_FLUTE_ACTIVE) == TRUE)
        return 1;
    else if (FlagGet(FLAG_SYS_BLACK_FLUTE_ACTIVE) == TRUE)
        return 2;
    else
        return 0;
}

static void ApplyCleanseTagEncounterRateMod(u32 *encounterRate)
{
    if (IsLeadMonHoldingCleanseTag())
        *encounterRate = *encounterRate * 2 / 3;
}

static bool8 IsLeadMonHoldingCleanseTag(void)
{
    if (sWildEncounterData.leadMonHeldItem == ITEM_CLEANSE_TAG)
        return TRUE;
    else
        return FALSE;
}

void SeedWildEncounterRng(u16 seed)
{
    sWildEncounterData.rngState = seed;
    ResetEncounterRateModifiers();
}

static u16 WildEncounterRandom(void)
{
    sWildEncounterData.rngState *= 1103515245;
    sWildEncounterData.rngState += 12345;
    return sWildEncounterData.rngState >> 16;
}

static u8 GetMapBaseEncounterCooldown(u8 encounterType)
{
    u16 headerIdx = GetCurrentMapWildMonHeaderId();
    const struct WildPokemonInfo * currentLandTable;
    const struct WildPokemonInfo * currentWaterTable;

    if(gSaveBlock1Ptr->keyFlags.version == 0)
    {
        currentLandTable = gWildMonHeaders[headerIdx].landMonsInfo_FR;
        currentWaterTable = gWildMonHeaders[headerIdx].waterMonsInfo_FR;
    }
    else
    {
        currentLandTable = gWildMonHeaders[headerIdx].landMonsInfo_LG;
        currentWaterTable = gWildMonHeaders[headerIdx].waterMonsInfo_LG;
    }

    if (headerIdx == 0xFFFF)
        return 0xFF;
    if (encounterType == TILE_ENCOUNTER_LAND)
    {
        if (currentLandTable == NULL)
            return 0xFF;
        if (currentLandTable->encounterRate >= 80)
            return 0;
        if (currentLandTable->encounterRate < 10)
            return 8;
        return 8 - (currentLandTable->encounterRate / 10);
    }
    if (encounterType == TILE_ENCOUNTER_WATER)
    {
        if (currentWaterTable == NULL)
            return 0xFF;
        if (currentWaterTable->encounterRate >= 80)
            return 0;
        if (currentWaterTable->encounterRate < 10)
            return 8;
        return 8 - (currentWaterTable->encounterRate / 10);
    }
    return 0xFF;
}

void ResetEncounterRateModifiers(void)
{
    sWildEncounterData.encounterRateBuff = 0;
    sWildEncounterData.stepsSinceLastEncounter = 0;
}

static bool8 HandleWildEncounterCooldown(u32 currMetatileAttrs)
{
    u8 encounterType = GetMetatileAttributeFromRawMetatileBehavior(currMetatileAttrs, METATILE_ATTRIBUTE_ENCOUNTER_TYPE);
    u32 minSteps;
    u32 encRate;
    if (encounterType == TILE_ENCOUNTER_NONE)
        return FALSE;
    minSteps = GetMapBaseEncounterCooldown(encounterType);
    if (minSteps == 0xFF)
        return FALSE;
    minSteps *= 256;
    encRate = 5 * 256;
    switch (GetFluteEncounterRateModType())
    {
    case 1:
        minSteps -= minSteps / 2;
        encRate += encRate / 2;
        break;
    case 2:
        minSteps *= 2;
        encRate /= 2;
        break;
    }
    sWildEncounterData.leadMonHeldItem = GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM);
    if (IsLeadMonHoldingCleanseTag() == TRUE)
    {
        minSteps += minSteps / 3;
        encRate -= encRate / 3;
    }
    switch (GetAbilityEncounterRateModType())
    {
    case 1:
        minSteps *= 2;
        encRate /= 2;
        break;
    case 2:
        minSteps /= 2;
        encRate *= 2;
        break;
    }
    minSteps /= 256;
    encRate /= 256;
    if (sWildEncounterData.stepsSinceLastEncounter >= minSteps)
        return TRUE;
    sWildEncounterData.stepsSinceLastEncounter++;
    if ((Random() % 100) < encRate)
        return TRUE;
    return FALSE;
}

bool8 TryStandardWildEncounter(u32 currMetatileAttrs)
{
    if (!HandleWildEncounterCooldown(currMetatileAttrs))
    {
        sWildEncounterData.prevMetatileBehavior = GetMetatileAttributeFromRawMetatileBehavior(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR);
        return FALSE;
    }
    else if (StandardWildEncounter(currMetatileAttrs, sWildEncounterData.prevMetatileBehavior) == TRUE)
    {
        sWildEncounterData.encounterRateBuff = 0;
        sWildEncounterData.stepsSinceLastEncounter = 0;
        sWildEncounterData.prevMetatileBehavior = GetMetatileAttributeFromRawMetatileBehavior(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR);
        return TRUE;
    }
    else
    {
        sWildEncounterData.prevMetatileBehavior = GetMetatileAttributeFromRawMetatileBehavior(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR);
        return FALSE;
    }
}

static void AddToWildEncounterRateBuff(u8 encounterRate)
{
    if (VarGet(VAR_REPEL_STEP_COUNT) == 0)
        sWildEncounterData.encounterRateBuff += encounterRate;
    else
        sWildEncounterData.encounterRateBuff = 0;
}

static u8 PickWildMonNature(void)
{
    // check synchronize for a pokemon with the same ability
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG)
        && GetMonAbility(&gPlayerParty[0]) == ABILITY_SYNCHRONIZE
        && Random() % 2 == 0)
    {
        return GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY) % 25;
    }

    // random nature
    return Random() % 25;
}

static bool8 IsAbilityAllowingEncounter(u8 level)
{
    u8 ability;

    if (GetMonData(&gPlayerParty[0], MON_DATA_IS_EGG))
        return TRUE;

    ability = GetMonAbility(&gPlayerParty[0]);
    if (ability == ABILITY_KEEN_EYE || ability == ABILITY_INTIMIDATE)
    {
        u8 playerMonLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        if (playerMonLevel > 5 && level <= playerMonLevel - 5 && !(Random() % 2))
            return FALSE;
    }

    return TRUE;
}

static bool8 TryGetAbilityInfluencedWildMonIndex(const struct WildPokemon *wildMon, u8 type, u8 ability, u8 *monIndex)
{
    if (GetMonData(&gPlayerParty[0], MON_DATA_IS_EGG))
        return FALSE;
    else if (GetMonAbility(&gPlayerParty[0]) != ability)
        return FALSE;
    else if (Random() % 2 != 0)
        return FALSE;

    return TryGetRandomWildMonIndexByType(wildMon, type, LAND_WILD_COUNT, monIndex);
}

static bool8 TryGetRandomWildMonIndexByType(const struct WildPokemon *wildMon, u8 type, u8 numMon, u8 *monIndex)
{
    u8 validIndexes[numMon]; // variable length array, an interesting feature
    u8 i, validMonCount;

    for (i = 0; i < numMon; i++)
        validIndexes[i] = 0;

    for (validMonCount = 0, i = 0; i < numMon; i++)
    {
        if (gBaseStats[wildMon[i].species].type1 == type || gBaseStats[wildMon[i].species].type2 == type)
            validIndexes[validMonCount++] = i;
    }

    if (validMonCount == 0 || validMonCount == numMon)
        return FALSE;

    *monIndex = validIndexes[Random() % validMonCount];
    return TRUE;
}

// Grinding for Brock can be miserable in Nuzlocke Mode, especially with Challenge Mode on.
// This gives a 47% chance of a Caterpie/Weedle encounter to be bumped up to a Metapod/Kakuna one.
// If that happens, there's a 50% chance the level will be bumped up to the max possible as well.
// This will increase experience gains in Viridian Forest to make the grind less tedious.
// Once the player gets the fossil from Mt. Moon, this function stops modifying the encounters,
// it also does not interfere with the first encounter for this area.
// When this is active, there is a ~42.4% chance to encounter a Caterpie/Weedle and
// ~52.6% chance to encounter Metapod/Kakuna. Pikachu takes up the last 5%.

static u8 ViridianForestNuzlockeOverride(const struct WildPokemonInfo * info, u8 slot)
{
    u8 rand;

    if(FlagGet(FLAG_GOT_FOSSIL_FROM_MT_MOON))
        return slot;

    if (NuzlockeFlagGet(GetCurrentRegionMapSectionId()) == FALSE)
    {   // not a dupe && first encounter; don't modify slot to preserve first encounter odds
        if(!IsWildMonNuzlockeDupe(info->wildPokemon[slot].species))
            return slot;
    }

    switch(slot)
    {
        case 0: // Caterpie
        case 2: // ^
        case 4: // ^
            rand = Random() % 100;
            if(rand < 47) //switch to a Metapod
            {
                if(rand < 24) //highest level Metapod
                {
                    if(gSaveBlock1Ptr->keyFlags.version == 0) //FR
                        slot = 6;
                    else
                        slot = 10;
                }
                else //not highest level
                {
                    if(gSaveBlock1Ptr->keyFlags.version == 0) //FR
                        slot = 6;
                    else
                    {
                        switch(slot)
                            {
                                case 1:
                                    slot = 7;
                                    break;
                                case 3:
                                    slot = 10;
                                    break;
                                case 5:
                                    slot = 8;
                                    break;
                            }
                    }
                }
            }
            break;
        case 1: // Weedle
        case 3: // ^
        case 5: // ^
            rand = Random() % 100;
            if(rand < 47) //switch to a Kakuna
            {
                if(rand < 24) //highest level Kakuna
                {
                    if(gSaveBlock1Ptr->keyFlags.version == 1) //LG
                        slot = 6;
                    else
                        slot = 10;
                }
                else //not highest level
                {
                    if(gSaveBlock1Ptr->keyFlags.version == 1) //LG
                        slot = 6;
                    else
                    {
                        switch(slot)
                        {
                            case 1:
                                slot = 7;
                                break;
                            case 3:
                                slot = 10;
                                break;
                            case 5:
                                slot = 8;
                                break;
                        }
                    }
                }
            }
            break; 
    }
    return slot;
}