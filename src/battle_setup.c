#include "global.h"
#include "task.h"
#include "help_system.h"
#include "overworld.h"
#include "item.h"
#include "sound.h"
#include "pokemon.h"
#include "load_save.h"
#include "safari_zone.h"
#include "quest_log.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "strings.h"
#include "string_util.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "metatile_behavior.h"
#include "event_scripts.h"
#include "fldeff.h"
#include "fieldmap.h"
#include "field_control_avatar.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_message_box.h"
#include "vs_seeker.h"
#include "battle.h"
#include "battle_transition.h"
#include "battle_controllers.h"
#include "pokedex.h"
#include "constants/battle_setup.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/pokemon.h"
#include "constants/trainer_classes.h"

enum
{
    TRAINER_PARAM_LOAD_VAL_8BIT,
    TRAINER_PARAM_LOAD_VAL_16BIT,
    TRAINER_PARAM_LOAD_VAL_32BIT,
    TRAINER_PARAM_CLEAR_VAL_8BIT,
    TRAINER_PARAM_CLEAR_VAL_16BIT,
    TRAINER_PARAM_CLEAR_VAL_32BIT,
    TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR,
};

struct TrainerBattleParameter
{
    void *varPtr;
    u8 ptrType;
};

static void DoSafariBattle(void);
static void DoGhostBattle(void);
static void DoStandardWildBattle(void);
static void CB2_EndWildBattle(void);
static u8 GetWildBattleTransition(void);
static u8 GetTrainerBattleTransition(void);
static void CB2_EndScriptedWildBattle(void);
static void CB2_EndMarowakBattle(void);
static bool32 IsPlayerDefeated(u32 battleOutcome);
static void CB2_EndTrainerBattle(void);
static const u8 *GetIntroSpeechOfApproachingTrainer(void);
static const u8 *GetTrainerCantBattleSpeech(void);
s8 GetScaledLevel(void);

static EWRAM_DATA u16 sTrainerBattleMode = 0;
EWRAM_DATA u16 gTrainerBattleOpponent_A = 0;
static EWRAM_DATA u16 sTrainerObjectEventLocalId = 0;
static EWRAM_DATA u8 *sTrainerAIntroSpeech = NULL;
static EWRAM_DATA u8 *sTrainerADefeatSpeech = NULL;
static EWRAM_DATA u8 *sTrainerVictorySpeech = NULL;
static EWRAM_DATA u8 *sTrainerCannotBattleSpeech = NULL;
static EWRAM_DATA u8 *sTrainerBattleEndScript = NULL;
static EWRAM_DATA u8 *sTrainerABattleScriptRetAddr = NULL;
static EWRAM_DATA u16 sRivalBattleFlags = 0;
EWRAM_DATA u8 HasAlreadyCapturedHere = 0;

static const u8 sBattleTransitionTable_Wild[][2] =
{
    { B_TRANSITION_SLICED_SCREEN,        B_TRANSITION_WHITEFADE_IN_STRIPES },
    { B_TRANSITION_CLOCKWISE_BLACKFADE,  B_TRANSITION_GRID_SQUARES         },
    { B_TRANSITION_BLUR,                 B_TRANSITION_GRID_SQUARES         },
    { B_TRANSITION_BLACK_WAVE_TO_RIGHT,  B_TRANSITION_FULLSCREEN_WAVE      },
};

static const u8 sBattleTransitionTable_Trainer[][2] =
{
    { B_TRANSITION_SLIDING_POKEBALLS,    B_TRANSITION_BLACK_DOODLES        },
    { B_TRANSITION_HORIZONTAL_CORRUGATE, B_TRANSITION_BIG_POKEBALL         },
    { B_TRANSITION_BLUR,                 B_TRANSITION_GRID_SQUARES         },
    { B_TRANSITION_DISTORTED_WAVE,       B_TRANSITION_FULLSCREEN_WAVE      },
};

static const struct TrainerBattleParameter sOrdinaryBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sContinueScriptBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sDoubleBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sOrdinaryNoIntroBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sEarlyRivalBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sRivalBattleFlags,            TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

static const struct TrainerBattleParameter sContinueScriptDoubleBattleParams[] =
{
    {&sTrainerBattleMode,           TRAINER_PARAM_LOAD_VAL_8BIT},
    {&gTrainerBattleOpponent_A,     TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerObjectEventLocalId,   TRAINER_PARAM_LOAD_VAL_16BIT},
    {&sTrainerAIntroSpeech,         TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerADefeatSpeech,        TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerVictorySpeech,        TRAINER_PARAM_CLEAR_VAL_32BIT},
    {&sTrainerCannotBattleSpeech,   TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerABattleScriptRetAddr, TRAINER_PARAM_LOAD_VAL_32BIT},
    {&sTrainerBattleEndScript,      TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR},
};

const u8 NuzlockeLUT[MAPSEC_COUNT] = //84 used, 214 total
{   //any mapsec not in this list = 0x0
    [MAPSEC_PALLET_TOWN] = 0x1,
    [MAPSEC_VIRIDIAN_CITY] = 0x2,
    [MAPSEC_CERULEAN_CITY] = 0x3,
    [MAPSEC_VERMILION_CITY] = 0x4,
    [MAPSEC_CELADON_CITY] = 0x5,
    [MAPSEC_FUCHSIA_CITY] = 0x6,
    [MAPSEC_CINNABAR_ISLAND] = 0x7,
    [MAPSEC_ROUTE_1] = 0x8,
    [MAPSEC_ROUTE_2] = 0x9,
    [MAPSEC_ROUTE_3] = 0xA,
    [MAPSEC_ROUTE_4] = 0xB,
    [MAPSEC_ROUTE_5] = 0xC,
    [MAPSEC_ROUTE_6] = 0xD,
    [MAPSEC_ROUTE_7] = 0xE,
    [MAPSEC_ROUTE_8] = 0xF,
    [MAPSEC_ROUTE_9] = 0x10,
    [MAPSEC_ROUTE_10] = 0x11,
    [MAPSEC_ROUTE_11] = 0x12,
    [MAPSEC_ROUTE_12] = 0x13,
    [MAPSEC_ROUTE_13] = 0x14,
    [MAPSEC_ROUTE_14] = 0x15,
    [MAPSEC_ROUTE_15] = 0x16,
    [MAPSEC_ROUTE_16] = 0x17,
    [MAPSEC_ROUTE_17] = 0x18,
    [MAPSEC_ROUTE_18] = 0x19,
    [MAPSEC_ROUTE_19] = 0x1A,
    [MAPSEC_ROUTE_20] = 0x1B,
    [MAPSEC_ROUTE_21] = 0x1C,
    [MAPSEC_ROUTE_22] = 0x1D,
    [MAPSEC_ROUTE_23] = 0x1E,
    [MAPSEC_ROUTE_24] = 0x1F,
    [MAPSEC_ROUTE_25] = 0x20,
    [MAPSEC_VIRIDIAN_FOREST] = 0x21,
    [MAPSEC_MT_MOON] = 0x22,
    [MAPSEC_S_S_ANNE] = 0x23,
    [MAPSEC_DIGLETTS_CAVE] = 0x24,
    [MAPSEC_KANTO_VICTORY_ROAD] = 0x25,
    [MAPSEC_POKEMON_MANSION] = 0x26,
    [MAPSEC_KANTO_SAFARI_ZONE] = 0x27,
    [MAPSEC_ROCK_TUNNEL] = 0x28,
    [MAPSEC_SEAFOAM_ISLANDS] = 0x29,
    [MAPSEC_POKEMON_TOWER] = 0x2A,
    [MAPSEC_CERULEAN_CAVE] = 0x2B,
    [MAPSEC_POWER_PLANT] = 0x2C,
    [MAPSEC_ONE_ISLAND] = 0x2D,
    [MAPSEC_FOUR_ISLAND] = 0x2E,
    [MAPSEC_FIVE_ISLAND] = 0x2F,
    [MAPSEC_KINDLE_ROAD] = 0x30,
    [MAPSEC_TREASURE_BEACH] = 0x31,
    [MAPSEC_CAPE_BRINK] = 0x32,
    [MAPSEC_BOND_BRIDGE] = 0x33,
    [MAPSEC_THREE_ISLE_PORT] = 0x34,
    [MAPSEC_RESORT_GORGEOUS] = 0x35,
    [MAPSEC_WATER_LABYRINTH] = 0x36,
    [MAPSEC_FIVE_ISLE_MEADOW] = 0x37,
    [MAPSEC_MEMORIAL_PILLAR] = 0x38,
    [MAPSEC_OUTCAST_ISLAND] = 0x39,
    [MAPSEC_GREEN_PATH] = 0x3A,
    [MAPSEC_WATER_PATH] = 0x3B,
    [MAPSEC_RUIN_VALLEY] = 0x3C,
    [MAPSEC_TRAINER_TOWER] = 0x3D,
    [MAPSEC_CANYON_ENTRANCE] = 0x3E,
    [MAPSEC_SEVAULT_CANYON] = 0x3F,
    [MAPSEC_TANOBY_RUINS] = 0x40,
    [MAPSEC_NAVEL_ROCK] = 0x41,
    [MAPSEC_MT_EMBER] = 0x42,
    [MAPSEC_BERRY_FOREST] = 0x43,
    [MAPSEC_ICEFALL_CAVE] = 0x44,
    [MAPSEC_LOST_CAVE] = 0x45,
    [MAPSEC_PATTERN_BUSH] = 0x46,
    [MAPSEC_ALTERING_CAVE] = 0x47,
    [MAPSEC_MONEAN_CHAMBER] = 0x48,
    [MAPSEC_LIPTOO_CHAMBER] = 0x49,
    [MAPSEC_WEEPTH_CHAMBER] = 0x4A,
    [MAPSEC_DILFORD_CHAMBER] = 0x4B,
    [MAPSEC_SCUFIB_CHAMBER] = 0x4C,
    [MAPSEC_RIXY_CHAMBER] = 0x4D,
    [MAPSEC_VIAPOIS_CHAMBER] = 0x4E,
    //Other Safari Zone areas here, taking up 0x4F to 0x53
    [MAPSEC_ARTISAN_CAVE] = 0x54,
    [MAPSEC_SOUTHERN_ISLAND] = 0x55, //84
    [MAPSEC_UNDERWATER_124] = 0x33, //reused Bond Bridge; same area but Underwater
    [MAPSEC_BATTLE_FRONTIER] = 0x56
};


#define tState data[0]
#define tTransition data[1]

static void Task_BattleStart(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        if (!FldEffPoison_IsActive())
        {
        	HelpSystem_Disable();
            BT_StartOnField(tTransition);
            ++tState;
        }
        break;
    case 1:
        if (BT_IsDone() == TRUE)
        {
        	HelpSystem_Enable();
            CleanupOverworldWindowsAndTilemaps();
            SetMainCallback2(CB2_InitBattle);
            RestartWildEncounterImmunitySteps();
            ClearPoisonStepCounter();
            DestroyTask(taskId);
        }
        break;
    }
}

static void CreateBattleStartTask(u8 transition, u16 song) // song == 0 means default music for current map
{
    u8 taskId = CreateTask(Task_BattleStart, 1);

    gTasks[taskId].tTransition = transition;
    PlayMapChosenOrBattleBGM(song);
}

static bool8 CheckSilphScopeInPokemonTower(u16 mapGroup, u16 mapNum)
{
    if (mapGroup == MAP_GROUP(POKEMON_TOWER_1F)
     && ((u16)(mapNum - MAP_NUM(POKEMON_TOWER_1F)) <= 6)
     && !(CheckBagHasItem(ITEM_SILPH_SCOPE, 1)))
        return TRUE;
    else
        return FALSE;
}

void StartWildBattle(void)
{
    if (GetSafariZoneFlag())
        DoSafariBattle();
    else if (CheckSilphScopeInPokemonTower(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
        DoGhostBattle();
    else
        DoStandardWildBattle();
}

static void DoStandardWildBattle(void)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    StopPlayerAvatar();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = 0;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void StartRoamerBattle(void)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    StopPlayerAvatar();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_ROAMER;
    CreateBattleStartTask(GetWildBattleTransition(), MUS_C_VS_LEGEND_BEAST);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

static void DoSafariBattle(void)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    StopPlayerAvatar();
    gMain.savedCallback = CB2_EndSafariBattle;
    gBattleTypeFlags = BATTLE_TYPE_SAFARI;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
}

static void DoGhostBattle(void)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    StopPlayerAvatar();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_GHOST;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, gText_Ghost);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

static void DoTrainerBattle(void)
{
    CreateBattleStartTask(GetTrainerBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_TRAINER_BATTLES);
}

void StartOldManTutorialBattle(void)
{
    CreateMaleMon(&gEnemyParty[0], SPECIES_WEEDLE, 5);
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_ReturnToFieldContinueScriptPlayMapMusic;
    gBattleTypeFlags = BATTLE_TYPE_OLD_MAN_TUTORIAL;
    CreateBattleStartTask(B_TRANSITION_SLICED_SCREEN, 0);
}

void StartScriptedWildBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_WILD_SCRIPTED;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void StartMarowakBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndMarowakBattle;
    if (CheckBagHasItem(ITEM_SILPH_SCOPE, 1))
    {
        gBattleTypeFlags = BATTLE_TYPE_GHOST | BATTLE_TYPE_GHOST_UNVEILED;
        CreateMonWithGenderNatureLetter(gEnemyParty, SPECIES_MAROWAK, 30, 31, MON_FEMALE, NATURE_SERIOUS, 0);
    }
    else
    {
        gBattleTypeFlags = BATTLE_TYPE_GHOST;
    }
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, gText_Ghost);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void StartSouthernIslandBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY;
    CreateBattleStartTask(GetWildBattleTransition(), MUS_RS_VS_WILD);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void StartLegendaryBattle(void)
{
    u16 species;
    
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_LEGENDARY_FRLG;
    species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    switch (species)
    {
    case SPECIES_MEWTWO:
        CreateBattleStartTask(B_TRANSITION_BLUR, MUS_VS_MEWTWO);
        break;
    case SPECIES_MEW:
        CreateBattleStartTask(B_TRANSITION_GRID_SQUARES, MUS_VS_MEWTWO);
        break;
    case SPECIES_DEOXYS:
        CreateBattleStartTask(B_TRANSITION_BLUR, MUS_VS_DEOXYS);
        break;
    case SPECIES_MOLTRES:
    case SPECIES_ARTICUNO:
    case SPECIES_ZAPDOS:
    case SPECIES_HO_OH:
    case SPECIES_LUGIA:
        CreateBattleStartTask(B_TRANSITION_BLUR, MUS_VS_LEGEND);
        break;
    default:
        CreateBattleStartTask(B_TRANSITION_BLUR, MUS_RS_VS_TRAINER);
        break;
    }
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void StartGroudonKyogreBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_KYOGRE_GROUDON;
    if (gGameVersion == VERSION_FIRE_RED)
        CreateBattleStartTask(B_TRANSITION_BLACK_DOODLES, MUS_RS_VS_TRAINER);
    else // pointless, exactly the same
        CreateBattleStartTask(B_TRANSITION_BLACK_DOODLES, MUS_RS_VS_TRAINER);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

void StartRegiBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_REGI;
    CreateBattleStartTask(B_TRANSITION_BLUR, MUS_RS_VS_TRAINER);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
}

// not used
static void sub_807FAF8(void)
{
    LoadPlayerParty();
    CB2_EndWildBattle();
}

// not used
static void sub_807FB08(void)
{
    ScriptContext2_Enable();
    FreezeObjectEvents();
    StopPlayerAvatar();
    gMain.savedCallback = sub_807FAF8;
    SavePlayerParty();
    InitPokedudePartyAndOpponent();
    CreateBattleStartTask(GetWildBattleTransition(), 0);
}

bool8 CheckNuzlockeDupeFlags(u16 species)
{
    u8 index = species / 8; //get byte in array
    u8 bit = species % 8;   //get bit in byte
    u8 mask = 1 << bit;

    return (gSaveBlock1Ptr->nuzlockeDupeFlags[index] & mask) != 0;
}

bool8 IsWildMonNuzlockeDupe(u16 species)
{
    u32 i;
    for (i = 0; i < EVOS_PER_LINE; i++)
    {   
        if (CheckNuzlockeDupeFlags(SpeciesToNationalPokedexNum(gEvolutionLines[species][i])))
            return TRUE;
    }
    return FALSE;
}

void SetNuzlockeDupeFlags(u16 species)
{
    u8 index = species / 8; //get byte in array
    u8 bit = species % 8;   //get bit in byte
    u8 mask = 1 << bit;

    gSaveBlock1Ptr->nuzlockeDupeFlags[index] |= mask;
}

static void CB2_EndWildBattle(void)
{
    if(gSaveBlock1Ptr->keyFlags.nuzlocke == 1)
    {   
        if(!IsWildMonNuzlockeDupe(GetMonData(&gEnemyParty[0], MON_DATA_SPECIES)))
        {
            NuzlockeFlagSet(GetCurrentRegionMapSectionId());
        }
    }
    CpuFill16(0, (void *)BG_PLTT, BG_PLTT_SIZE);
    ResetOamRange(0, 128);
    if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(CB2_ReturnToField);
        gFieldCallback = FieldCB_SafariZoneRanOutOfBalls;
    }
}

static void CB2_EndScriptedWildBattle(void)
{
    if(gSaveBlock1Ptr->keyFlags.nuzlocke == 1)
    {   
        if(!IsWildMonNuzlockeDupe(GetMonData(&gEnemyParty[0], MON_DATA_SPECIES)))
        {
            NuzlockeFlagSet(GetCurrentRegionMapSectionId());
        }
    }
    CpuFill16(0, (void *)BG_PLTT, BG_PLTT_SIZE);
    ResetOamRange(0, 128);
    if (IsPlayerDefeated(gBattleOutcome) == TRUE)
        SetMainCallback2(CB2_WhiteOut);
    else
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void CB2_EndMarowakBattle(void)
{
    CpuFill16(0, (void *)BG_PLTT, BG_PLTT_SIZE);
    ResetOamRange(0, 128);
    if (IsPlayerDefeated(gBattleOutcome))
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        // If result is TRUE player didnt defeat Marowak, force player back from stairs
        if (gBattleOutcome == B_OUTCOME_WON)
            gSpecialVar_Result = FALSE;
        else
            gSpecialVar_Result = TRUE;
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}

u8 GetBattleTerrainFromField(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (MetatileBehavior_IsTallGrass_2(tileBehavior))
        return BATTLE_TERRAIN_GRASS;
    if (MetatileBehavior_IsLongGrass(tileBehavior))
        return BATTLE_TERRAIN_LONG_GRASS;
    if (MetatileBehavior_IsSandOrShallowFlowingWater(tileBehavior))
        return BATTLE_TERRAIN_SAND;
    switch (gMapHeader.mapType)
    {
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
        break;
    case MAP_TYPE_UNDERGROUND:
        if (MetatileBehavior_IsIndoorEncounter(tileBehavior))
            return BATTLE_TERRAIN_BUILDING;
        if (MetatileBehavior_IsSurfable(tileBehavior))
            return BATTLE_TERRAIN_POND;
        return BATTLE_TERRAIN_CAVE;
    case MAP_TYPE_INDOOR:
    case MAP_TYPE_SECRET_BASE:
        return BATTLE_TERRAIN_BUILDING;
    case MAP_TYPE_UNDERWATER:
        return BATTLE_TERRAIN_UNDERWATER;
    case MAP_TYPE_OCEAN_ROUTE:
        if (MetatileBehavior_IsSurfable(tileBehavior))
            return BATTLE_TERRAIN_WATER;
        return BATTLE_TERRAIN_PLAIN;
    }
    if (MetatileBehavior_IsDeepSemiDeepOrSplashingWater(tileBehavior))
        return BATTLE_TERRAIN_WATER;
    if (MetatileBehavior_IsSurfable(tileBehavior))
        return BATTLE_TERRAIN_POND;
    if (MetatileBehavior_IsMountain(tileBehavior))
        return BATTLE_TERRAIN_MOUNTAIN;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        if (MetatileBehavior_GetBridgeType(tileBehavior))
            return BATTLE_TERRAIN_POND;
        if (MetatileBehavior_IsBridge(tileBehavior) == TRUE)
            return BATTLE_TERRAIN_WATER;
    }
    return BATTLE_TERRAIN_PLAIN;
}

static u8 GetBattleTransitionTypeByMap(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (Overworld_GetFlashLevel())
        return B_TRANSITION_HORIZONTAL_CORRUGATE;
    if (!MetatileBehavior_IsSurfable(tileBehavior))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_UNDERGROUND:
            return B_TRANSITION_DISTORTED_WAVE;
        case MAP_TYPE_UNDERWATER:
            return B_TRANSITION_BIG_POKEBALL;
        default:
            return B_TRANSITION_BLUR;
        }
    }
    return B_TRANSITION_BIG_POKEBALL;
}

static u16 GetSumOfPlayerPartyLevel(u8 numMons)
{
    u8 sum = 0;
    s32 i;

    for (i = 0; i < PARTY_SIZE; ++i)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);

        if (species != SPECIES_EGG && species != SPECIES_NONE && GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
        {
            sum += GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            if (--numMons == 0)
                break;
        }
    }
    return sum;
}

static u8 GetSumOfEnemyPartyLevel(u16 opponentId, u8 numMons)
{
    u32 i;
    u8 sum;
    u32 count = numMons;
    s8 levelScaling = GetScaledLevel();

    if (gTrainers[opponentId].partySize < count)
        count = gTrainers[opponentId].partySize;
    sum = 0;
    switch (gTrainers[opponentId].partyFlags)
    {
    case 0:
        {
            const struct TrainerMonNoItemDefaultMoves *party;

            party = gTrainers[opponentId].party.NoItemDefaultMoves;
            for (i = 0; i < count; ++i)
                sum += (party[i].lvl + levelScaling);
        }
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET:
        {
            const struct TrainerMonNoItemCustomMoves *party;

            party = gTrainers[opponentId].party.NoItemCustomMoves;
            for (i = 0; i < count; ++i)
                sum += (party[i].lvl + levelScaling);
        }
        break;
    case F_TRAINER_PARTY_HELD_ITEM:
        {
            const struct TrainerMonItemDefaultMoves *party;

            party = gTrainers[opponentId].party.ItemDefaultMoves;
            for (i = 0; i < count; ++i)
                sum += (party[i].lvl + levelScaling);
        }
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
        {
            const struct TrainerMonItemCustomMoves *party;

            party = gTrainers[opponentId].party.ItemCustomMoves;
            for (i = 0; i < count; ++i)
                sum += (party[i].lvl + levelScaling);
        }
        break;
    case F_TRAINER_PARTY_EVS:
        {
            const struct TrainerMonItemCustomMovesEVs *party;

            party = gTrainers[opponentId].party.ItemCustomMovesEVs;
            for (i = 0; i < count; ++i)
                sum += (party[i].lvl + levelScaling);
        }
    }
    if(FlagGet(FLAG_MASTER_TRAINER_BATTLE))
    {
        return GetMonData(gPlayerParty[0], MON_DATA_LEVEL, NULL);
    }
    return sum;
}

static u8 GetWildBattleTransition(void)
{
    u8 transitionType = GetBattleTransitionTypeByMap();
    u8 enemyLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u8 playerLevel = GetSumOfPlayerPartyLevel(1);

    if (enemyLevel < playerLevel)
        return sBattleTransitionTable_Wild[transitionType][0];
    else
        return sBattleTransitionTable_Wild[transitionType][1];
}

static u8 GetTrainerBattleTransition(void)
{
    u8 minPartyCount;
    u8 transitionType;
    u8 enemyLevel;
    u8 playerLevel;
    struct Trainer* sTrainers;

    if(FlagGet(FLAG_MASTER_TRAINER_BATTLE))
        sTrainers = (struct Trainer*)gMasterTrainers;
    else
        sTrainers = (struct Trainer*)gTrainers;

    if (gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
        return B_TRANSITION_BLUE;
    if (sTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_ELITE_FOUR_2)
    {
        if (gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_LORELEI || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_LORELEI_2 || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_LORELEI_CHALLENGE || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_LORELEI_CHALLENGE_2)
            return B_TRANSITION_LORELEI;
        if (gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_BRUNO || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_BRUNO_2 || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_BRUNO_CHALLENGE || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_BRUNO_CHALLENGE_2)
            return B_TRANSITION_BRUNO;
        if (gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_AGATHA || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_AGATHA_2 || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_AGATHA_CHALLENGE || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_AGATHA_CHALLENGE_2)
            return B_TRANSITION_AGATHA;
        if (gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_LANCE || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_LANCE_2 || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_LANCE_CHALLENGE || gTrainerBattleOpponent_A == TRAINER_ELITE_FOUR_LANCE_CHALLENGE_2)
            return B_TRANSITION_LANCE;
        return B_TRANSITION_BLUE;
    }
    if (sTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_CHAMPION_2)
        return B_TRANSITION_BLUE;
    if (sTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_PKMN_PROF)
        return B_TRANSITION_OAK;
    if (sTrainers[gTrainerBattleOpponent_A].doubleBattle == TRUE)
        minPartyCount = 2; // double battles always at least have 2 pokemon.
    else
        minPartyCount = 1;
    transitionType = GetBattleTransitionTypeByMap();
    enemyLevel = GetSumOfEnemyPartyLevel(gTrainerBattleOpponent_A, minPartyCount);
    playerLevel = GetSumOfPlayerPartyLevel(minPartyCount);
    if (enemyLevel < playerLevel)
        return sBattleTransitionTable_Trainer[transitionType][0];
    else
        return sBattleTransitionTable_Trainer[transitionType][1];
}

u8 BattleSetup_GetBattleTowerBattleTransition(void)
{
    u8 enemyLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u8 playerLevel = GetSumOfPlayerPartyLevel(1);

    if (enemyLevel < playerLevel)
        return B_TRANSITION_SLIDING_POKEBALLS;
    else
        return B_TRANSITION_BIG_POKEBALL;
}

static u32 TrainerBattleLoadArg32(const u8 *ptr)
{
    return T1_READ_32(ptr);
}

static u16 TrainerBattleLoadArg16(const u8 *ptr)
{
    return T1_READ_16(ptr);
}

static u8 TrainerBattleLoadArg8(const u8 *ptr)
{
    return T1_READ_8(ptr);
}

static u16 GetTrainerAFlag(void)
{
    return TRAINER_FLAGS_START + gTrainerBattleOpponent_A;
}

static bool32 IsPlayerDefeated(u32 battleOutcome)
{
    switch (battleOutcome)
    {
    case B_OUTCOME_LOST:
    case B_OUTCOME_DREW:
        return TRUE;
    case B_OUTCOME_WON:
    case B_OUTCOME_RAN:
    case B_OUTCOME_PLAYER_TELEPORTED:
    case B_OUTCOME_MON_FLED:
    case B_OUTCOME_CAUGHT:
        return FALSE;
    default:
        return FALSE;
    }
}

static void InitTrainerBattleVariables(void)
{
    sTrainerBattleMode = 0;
    gTrainerBattleOpponent_A = 0;
    sTrainerObjectEventLocalId = 0;
    sTrainerAIntroSpeech = NULL;
    sTrainerADefeatSpeech = NULL;
    sTrainerVictorySpeech = NULL;
    sTrainerCannotBattleSpeech = NULL;
    sTrainerBattleEndScript = NULL;
    sTrainerABattleScriptRetAddr = NULL;
    sRivalBattleFlags = 0;
}

static inline void SetU8(void *ptr, u8 value)
{
    *(u8 *)(ptr) = value;
}

static inline void SetU16(void *ptr, u16 value)
{
    *(u16 *)(ptr) = value;
}

static inline void SetU32(void *ptr, u32 value)
{
    *(u32 *)(ptr) = value;
}

static inline void SetPtr(const void *ptr, const void *value)
{
    *(const void **)(ptr) = value;
}

static void TrainerBattleLoadArgs(const struct TrainerBattleParameter *specs, const u8 *data)
{
    while (1)
    {
        switch (specs->ptrType)
        {
        case TRAINER_PARAM_LOAD_VAL_8BIT:
            SetU8(specs->varPtr, TrainerBattleLoadArg8(data));
            data += 1;
            break;
        case TRAINER_PARAM_LOAD_VAL_16BIT:
            SetU16(specs->varPtr, TrainerBattleLoadArg16(data));
            data += 2;
            break;
        case TRAINER_PARAM_LOAD_VAL_32BIT:
            SetU32(specs->varPtr, TrainerBattleLoadArg32(data));
            data += 4;
            break;
        case TRAINER_PARAM_CLEAR_VAL_8BIT:
            SetU8(specs->varPtr, 0);
            break;
        case TRAINER_PARAM_CLEAR_VAL_16BIT:
            SetU16(specs->varPtr, 0);
            break;
        case TRAINER_PARAM_CLEAR_VAL_32BIT:
            SetU32(specs->varPtr, 0);
            break;
        case TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR:
            SetPtr(specs->varPtr, data);
            return;
        }
        ++specs;
    }
}

static void SetMapVarsToTrainer(void)
{
    if (sTrainerObjectEventLocalId != 0)
    {
        gSpecialVar_LastTalked = sTrainerObjectEventLocalId;
        gSelectedObjectEvent = GetObjectEventIdByLocalIdAndMap(sTrainerObjectEventLocalId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    }
}

const u8 *BattleSetup_ConfigureTrainerBattle(const u8 *data)
{
    InitTrainerBattleVariables();
    sTrainerBattleMode = TrainerBattleLoadArg8(data);
    switch (sTrainerBattleMode)
    {
    case TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT:
        TrainerBattleLoadArgs(sOrdinaryNoIntroBattleParams, data);
        return EventScript_DoNoIntroTrainerBattle;
    case TRAINER_BATTLE_DOUBLE:
        TrainerBattleLoadArgs(sDoubleBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_TryDoDoubleTrainerBattle;
    case TRAINER_BATTLE_CONTINUE_SCRIPT:
    case TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC:
        TrainerBattleLoadArgs(sContinueScriptBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_TryDoNormalTrainerBattle;
    case TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE:
    case TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC:
        TrainerBattleLoadArgs(sContinueScriptDoubleBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_TryDoDoubleTrainerBattle;
    case TRAINER_BATTLE_REMATCH_DOUBLE:
        FinishRecordingQuestLogScene();
        TrainerBattleLoadArgs(sDoubleBattleParams, data);
        SetMapVarsToTrainer();
        gTrainerBattleOpponent_A = GetRematchTrainerId(gTrainerBattleOpponent_A);
        return EventScript_TryDoDoubleRematchBattle;
    case TRAINER_BATTLE_REMATCH:
        FinishRecordingQuestLogScene();
        TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
        SetMapVarsToTrainer();
        gTrainerBattleOpponent_A = GetRematchTrainerId(gTrainerBattleOpponent_A);
        return EventScript_TryDoRematchBattle;
    case TRAINER_BATTLE_EARLY_RIVAL:
        TrainerBattleLoadArgs(sEarlyRivalBattleParams, data);
        return EventScript_DoNoIntroTrainerBattle;
    default:
        TrainerBattleLoadArgs(sOrdinaryBattleParams, data);
        SetMapVarsToTrainer();
        return EventScript_TryDoNormalTrainerBattle;
    }
}

void ConfigureAndSetUpOneTrainerBattle(u8 trainerEventObjId, const u8 *trainerScript)
{
    gSelectedObjectEvent = trainerEventObjId;
    gSpecialVar_LastTalked = gObjectEvents[trainerEventObjId].localId;
    BattleSetup_ConfigureTrainerBattle(trainerScript + 1);
    ScriptContext1_SetupScript(EventScript_DoTrainerBattleFromApproach);
    ScriptContext2_Enable();
}

bool32 GetTrainerFlagFromScriptPointer(const u8 *data)
{
    u32 flag = TrainerBattleLoadArg16(data + 2);

    return FlagGet(TRAINER_FLAGS_START + flag);
}

void SetUpTrainerMovement(void)
{
    struct ObjectEvent *objectEvent = &gObjectEvents[gSelectedObjectEvent];

    SetTrainerMovementType(objectEvent, GetTrainerFacingDirectionMovementType(objectEvent->facingDirection));
}

u8 GetTrainerBattleMode(void)
{
    return sTrainerBattleMode;
}

u16 GetRivalBattleFlags(void)
{
    return sRivalBattleFlags;
}

u16 Script_HasTrainerBeenFought(void)
{
    if(FlagGet(FLAG_MASTER_TRAINER_BATTLE))
    {
        return CheckMasterTrainerFlag(gSpecialVar_0x8009);
    }
    return FlagGet(GetTrainerAFlag());
}

void SetBattledTrainerFlag(void)
{
    if(FlagGet(FLAG_MASTER_TRAINER_BATTLE))
    {
        SetMasterTrainerFlag(gSpecialVar_0x8009);
        return;
    }
    FlagSet(GetTrainerAFlag());
}

// not used
static void SetBattledTrainerFlag2(void)
{
    FlagSet(GetTrainerAFlag());
}

bool8 HasTrainerBeenFought(u16 trainerId)
{
    if(FlagGet(FLAG_MASTER_TRAINER_BATTLE))
    {
        return CheckMasterTrainerFlag(gSpecialVar_0x8009);
    }
    return FlagGet(TRAINER_FLAGS_START + trainerId);
}

void SetTrainerFlag(u16 trainerId)
{
    if(FlagGet(FLAG_MASTER_TRAINER_BATTLE))
    {
        SetMasterTrainerFlag(gSpecialVar_0x8009);
        return;
    }
    FlagSet(TRAINER_FLAGS_START + trainerId);
}

void ClearTrainerFlag(u16 trainerId)
{
    FlagClear(TRAINER_FLAGS_START + trainerId);
}

void StartTrainerBattle(void)
{
    gBattleTypeFlags = BATTLE_TYPE_TRAINER;
    if (GetTrainerBattleMode() == TRAINER_BATTLE_EARLY_RIVAL && GetRivalBattleFlags() & RIVAL_BATTLE_TUTORIAL)
        gBattleTypeFlags |= BATTLE_TYPE_FIRST_BATTLE;
    gMain.savedCallback = CB2_EndTrainerBattle;
    DoTrainerBattle();
    ScriptContext1_Stop();
}

static void CB2_EndTrainerBattle(void)
{
    if (sTrainerBattleMode == TRAINER_BATTLE_EARLY_RIVAL)
    {
        if (IsPlayerDefeated(gBattleOutcome) == TRUE)
        {
            gSpecialVar_Result = TRUE;
            if (sRivalBattleFlags & RIVAL_BATTLE_HEAL_AFTER)
            {
                HealPlayerPartyOak();
            }
            else
            {
                SetMainCallback2(CB2_WhiteOut);
                return;
            }
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            SetBattledTrainerFlag();
            QuestLogEvents_HandleEndTrainerBattle();
        }
        else
        {
            gSpecialVar_Result = FALSE;
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            SetBattledTrainerFlag();
            QuestLogEvents_HandleEndTrainerBattle();
        }

    }
    else
    {
        if(FlagGet(FLAG_MASTER_TRAINER_BATTLE))
        {
            if(IsPlayerDefeated(gBattleOutcome) == TRUE)
            {
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
                QuestLogEvents_HandleEndTrainerBattle();
            }
            else
            {
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
                SetBattledTrainerFlag();
                QuestLogEvents_HandleEndTrainerBattle();
            }
            return;
        }
        if (gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
        {
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        }
        else if (IsPlayerDefeated(gBattleOutcome) == TRUE)
        {
            SetMainCallback2(CB2_WhiteOut);
        }
        else
        {
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            SetBattledTrainerFlag();
            QuestLogEvents_HandleEndTrainerBattle();
        }
    }
}

static void CB2_EndRematchBattle(void)
{
    if (gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
    else if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        SetBattledTrainerFlag();
        ClearRematchStateOfLastTalked();
        ResetDeferredLinkEvent();
    }
}

void StartRematchBattle(void)
{
    gBattleTypeFlags = BATTLE_TYPE_TRAINER;
    gMain.savedCallback = CB2_EndRematchBattle;
    DoTrainerBattle();
    ScriptContext1_Stop();
}

void ShowTrainerIntroSpeech(void)
{
    ShowFieldMessage(GetIntroSpeechOfApproachingTrainer());
}

const u8 *BattleSetup_GetScriptAddrAfterBattle(void)
{
    if (sTrainerBattleEndScript != NULL)
        return sTrainerBattleEndScript;
    else
        return EventScript_ReleaseEnd;
}

const u8 *BattleSetup_GetTrainerPostBattleScript(void)
{
    if (sTrainerABattleScriptRetAddr != NULL)
        return sTrainerABattleScriptRetAddr;
    else
        return EventScript_ReleaseEnd;
}

void ShowTrainerCantBattleSpeech(void)
{
    ShowFieldMessage(GetTrainerCantBattleSpeech());
}

void PlayTrainerEncounterMusic(void)
{
    u16 music;

    if (!QL_IS_PLAYBACK_STATE
     && sTrainerBattleMode != TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC
     && sTrainerBattleMode != TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC)
    {
        switch (GetTrainerEncounterMusicId(gTrainerBattleOpponent_A))
        {
        case TRAINER_ENCOUNTER_MUSIC_FEMALE:
        case TRAINER_ENCOUNTER_MUSIC_GIRL:
        case TRAINER_ENCOUNTER_MUSIC_TWINS:
            music = MUS_ENCOUNTER_GIRL;
            break;
        case TRAINER_ENCOUNTER_MUSIC_MALE:
        case TRAINER_ENCOUNTER_MUSIC_INTENSE:
        case TRAINER_ENCOUNTER_MUSIC_COOL:
        case TRAINER_ENCOUNTER_MUSIC_SWIMMER:
        case TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR:
        case TRAINER_ENCOUNTER_MUSIC_HIKER:
        case TRAINER_ENCOUNTER_MUSIC_INTERVIEWER:
        case TRAINER_ENCOUNTER_MUSIC_RICH:
            music = MUS_ENCOUNTER_BOY;
            break;
        default:
            music = MUS_ENCOUNTER_ROCKET;
            break;
        }
        PlayNewMapMusic(music);
    }
}

static const u8 *ReturnEmptyStringIfNull(const u8 *string)
{
    if (string == NULL)
        return gString_Dummy;
    else
        return string;
}

static const u8 *GetIntroSpeechOfApproachingTrainer(void)
{
    return ReturnEmptyStringIfNull(sTrainerAIntroSpeech);
}

const u8 *GetTrainerALoseText(void)
{
    const u8 *string = sTrainerADefeatSpeech;

    StringExpandPlaceholders(gStringVar4, ReturnEmptyStringIfNull(string));
    return gStringVar4;
}

const u8 *GetTrainerWonSpeech(void)
{
    StringExpandPlaceholders(gStringVar4, ReturnEmptyStringIfNull(sTrainerVictorySpeech));
    return gStringVar4;
}

static const u8 *GetTrainerCantBattleSpeech(void)
{
    return ReturnEmptyStringIfNull(sTrainerCannotBattleSpeech);
}

s8 GetScaledLevel(void)
{
    u8 levelScaling = gMapHeader.levelScaling;

    if(gSaveBlock1Ptr->keyFlags.difficulty == DIFFICULTY_CHALLENGE)
    {
        //we're good, just return
        return levelScaling;
    }
    else if(gSaveBlock1Ptr->keyFlags.difficulty == DIFFICULTY_EASY)
    {
        levelScaling = 0 - levelScaling;
        return levelScaling;
    }
    else
    {   //normal mode
        levelScaling = 0;
        return levelScaling;
    }
}