#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "config.h"
#include "gba/gba.h"
#include <string.h>
#include "constants/global.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/species.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")

#if defined (__APPLE__) || defined (__CYGWIN__) || defined(__CLION_IDE__)
// Get the IDE to stfu

// We define it this way to fool preproc.
#define INCBIN(...) {0}
#define INCBIN_U8  INCBIN
#define INCBIN_U16 INCBIN
#define INCBIN_U32 INCBIN
#define INCBIN_S8  INCBIN
#define INCBIN_S16 INCBIN
#define INCBIN_S32 INCBIN
#define _(x) (x)
#define __(x) (x)
#endif // __APPLE__

#define NELEMS(array) (sizeof(array) / sizeof((array)[0]))

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

// useful math macros

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a number from Q8.8 fixed-point format
#define Q_8_8_TO_INT(n) ((s16)((n) >> 8))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * 4096))

// Converts a number from Q4.12 fixed-point format
#define Q_4_12_TO_INT(n) ((s16)((n) >> 12))

// Converts a number to QN.S fixed-point format (16-bits)
#define Q_N_S(s, n) ((s16)((n) * (1 << (s))))

// converts a number from QN.S fixed-point format (16-bits)
#define Q_N_S_TO_INT(s, n) ((s16)((n) >> (s)))

// Converts a number to Q24.8 fixed-point format
#define Q_24_8(n) ((s32)((n) << 8))

// Converts a number from Q24.8 fixed-point format
#define Q_24_8_TO_INT(n) ((s32)((n) >> 8))

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

#if MODERN
#define abs(x) (((x) < 0) ? -(x) : (x))
#endif

// There are many quirks in the source code which have overarching behavioral differences from
// a number of other files. For example, diploma.c seems to declare rodata before each use while
// other files declare out of order and must be at the beginning. There are also a number of
// macros which differ from one file to the next due to the method of obtaining the result, such
// as these below. Because of this, there is a theory (Two Team Theory) that states that these
// programming projects had more than 1 "programming team" which utilized different macros for
// each of the files that were worked on.
#define T1_READ_8(ptr)  ((ptr)[0])
#define T1_READ_16(ptr) ((ptr)[0] | ((ptr)[1] << 8))
#define T1_READ_32(ptr) ((ptr)[0] | ((ptr)[1] << 8) | ((ptr)[2] << 16) | ((ptr)[3] << 24))
#define T1_READ_PTR(ptr) (u8*) T1_READ_32(ptr)

// T2_READ_8 is a duplicate to remain consistent with each group.
#define T2_READ_8(ptr)  ((ptr)[0])
#define T2_READ_16(ptr) ((ptr)[0] + ((ptr)[1] << 8))
#define T2_READ_32(ptr) ((ptr)[0] + ((ptr)[1] << 8) + ((ptr)[2] << 16) + ((ptr)[3] << 24))
#define T2_READ_PTR(ptr) (void*) T2_READ_32(ptr)

// This macro is required to prevent the compiler from optimizing
// a dpad up/down check in sub_812CAD8 (fame_checker.c).
// We suspect it was used globally.
// GameFreak never ceases to amaze.
// TODO: Propagate use of this macro
#define TEST_BUTTON(field, button) ({(field) & (button);})
#define JOY_NEW(button)  TEST_BUTTON(gMain.newKeys,  button)
#define JOY_HELD(button) TEST_BUTTON(gMain.heldKeys, button)
#define JOY_REPT(button) TEST_BUTTON(gMain.newAndRepeatedKeys, button)

#define S16TOPOSFLOAT(val)   \
({                           \
    s16 v = (val);           \
    float f = (float)v;      \
    if(v < 0) f += 65536.0f; \
    f;                       \
})

extern u8 gStringVar1[];
extern u8 gStringVar2[];
extern u8 gStringVar3[];
extern u8 gStringVar4[];

#define ROUND_BITS_TO_BYTES(numBits)(((numBits) / 8) + (((numBits) % 8) ? 1 : 0))

#define DEX_FLAGS_NO (ROUND_BITS_TO_BYTES(NUM_SPECIES))
#define NUM_FLAG_BYTES (ROUND_BITS_TO_BYTES(FLAGS_COUNT))

#define TOTAL_BOXES_COUNT       14
#define IN_BOX_COUNT            30

struct Coords8
{
    s8 x;
    s8 y;
};

struct UCoords8
{
    u8 x;
    u8 y;
};

struct Coords16
{
    s16 x;
    s16 y;
};

struct UCoords16
{
    u16 x;
    u16 y;
};

struct Coords32
{
    s32 x;
    s32 y;
};

struct UCoords32
{
    u32 x;
    u32 y;
};

struct Time
{
    /*0x00*/ s16 days;
    /*0x02*/ s8 hours;
    /*0x03*/ s8 minutes;
    /*0x04*/ s8 seconds;
};

struct Pokedex
{
    /*0x00*/ u8 order;
    /*0x01*/ u8 unknown1;
    /*0x02*/ u8 nationalMagic; // must equal 0xDA in order to have National mode
    /*0x03*/ u8 unknown2; // set to 0xB9 when national dex is first enabled
    /*0x04*/ u32 unownPersonality; // set when you first see Unown
    /*0x08*/ u32 spindaPersonality; // set when you first see Spinda
    /*0x0C*/ u32 unknown3;
    /*0x10*/ u8 owned[DEX_FLAGS_NO];
    /*0x44*/ u8 seen[DEX_FLAGS_NO];
};

struct PokemonJumpResults // possibly used in the game itself?
{
    u16 jumpsInRow;
    u16 field2;
    u16 excellentsInRow;
    u16 field6;
    u32 field8;
    u32 bestJumpScore;
};

struct BerryPickingResults // possibly used in the game itself? Size may be wrong as well
{
    u32 bestScore;
    u16 berriesPicked;
    u16 berriesPickedInRow;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 field_E;
    u8 field_F;
};

struct BerryCrush
{
    u16 berryCrushResults[4];
    u32 berryPowderAmount;
    u32 unk;
};

#define PLAYER_NAME_LENGTH   7

#define LINK_B_RECORDS_COUNT 5

struct LinkBattleRecord
{
    u8 name[PLAYER_NAME_LENGTH + 1];
    u16 trainerId;
    u16 wins;
    u16 losses;
    u16 draws;
};

struct LinkBattleRecords
{
    struct LinkBattleRecord entries[LINK_B_RECORDS_COUNT];
    u8 languages[LINK_B_RECORDS_COUNT];
};

#include "constants/game_stat.h"
#include "global.fieldmap.h"
#include "global.berry.h"
#include "pokemon.h"

struct BattleTowerRecord // record mixing
{
    /*0x00*/ u8 battleTowerLevelType; // 0 = level 50, 1 = level 100
    /*0x01*/ u8 trainerClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[8];
    /*0x0C*/ u8 trainerId[4];
    /*0x10*/ u16 greeting[6];
    /*0x1C*/ struct BattleTowerPokemon party[3];
    /*0xA0*/ u32 checksum;
};

struct BattleTowerEReaderTrainer
{
    /*0x4A0 0x3F0 0x00*/ u8 unk0;
    /*0x4A1 0x3F1 0x01*/ u8 trainerClass;
    /*0x4A2 0x3F2 0x02*/ u16 winStreak;
    /*0x4A4 0x3F4 0x04*/ u8 name[8];
    /*0x4AC 0x3FC 0x0C*/ u8 trainerId[4];
    /*0x4B0 0x400 0x10*/ u16 greeting[6];
    /*0x4BC 0x40C 0x1C*/ u16 farewellPlayerLost[6];
    /*0x4C8 0x418 0x28*/ u16 farewellPlayerWon[6];
    /*0x4D4 0x424 0x34*/ struct BattleTowerPokemon party[3];
    /*0x558 0x4A8 0xB8*/ u32 checksum;
};

struct BattleTowerData // Leftover from R/S
{
    /*0x0000, 0x00B0*/ struct BattleTowerRecord playerRecord;
    /*0x00A4, 0x0154*/ struct BattleTowerRecord records[5]; // from record mixing
    /*0x03D8, 0x0488*/ u16 firstMonSpecies; // species of the first pokemon in the player's battle tower party
    /*0x03DA, 0x048A*/ u16 defeatedBySpecies; // species of the pokemon that defated the player
    /*0x03DC, 0x048C*/ u8 defeatedByTrainerName[8];
    /*0x03E4, 0x0494*/ u8 firstMonNickname[POKEMON_NAME_LENGTH]; // nickname of the first pokemon in the player's battle tower party
    /*0x03F0, 0x04A0*/ struct BattleTowerEReaderTrainer ereaderTrainer;
    /*0x04AC, 0x055C*/ u8 battleTowerLevelType:1; // 0 = level 50; 1 = level 100
    /*0x04AC, 0x055C*/ u8 unk_554:1;
    /*0x04AD, 0x055D*/ u8 battleOutcome;
    /*0x04AE, 0x055E*/ u8 var_4AE[2];
    /*0x04B0, 0x0560*/ u16 curChallengeBattleNum[2]; // 1-based index of battle in the current challenge. (challenges consist of 7 battles)
    /*0x04B4, 0x0564*/ u16 curStreakChallengesNum[2]; // 1-based index of the current challenge in the current streak.
    /*0x04B8, 0x0568*/ u16 recordWinStreaks[2];
    /*0x04BC, 0x056C*/ u8 battleTowerTrainerId; // index for gBattleTowerTrainers table
    /*0x04BD, 0x056D*/ u8 selectedPartyMons[0x3]; // indices of the 3 selected player party mons.
    /*0x04C0, 0x0570*/ u16 prizeItem;
    /*0x04C2, 0x0572*/ u8 battledTrainerIds[6];
    /*0x04C8, 0x0578*/ u16 totalBattleTowerWins;
    /*0x04CA, 0x057A*/ u16 bestBattleTowerWinStreak;
    /*0x04CC, 0x057C*/ u16 currentWinStreaks[2];
    /*0x04D0, 0x0580*/ u8 lastStreakLevelType; // 0 = level 50, 1 = level 100.  level type of the last streak. Used by tv to report the level mode.
    /*0x04D1, 0x0581*/ u8 filler_4D1[0x317];
}; /* size = 0x7E8 */

struct SaveBlock2
{
    /*0x000*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x008*/ u8 playerGender; // MALE, FEMALE
    /*0x009*/ u8 specialSaveWarpFlags;
    /*0x00A*/ u8 playerTrainerId[4];
    /*0x00E*/ u16 playTimeHours;
    /*0x010*/ u8 playTimeMinutes;
    /*0x011*/ u8 playTimeSeconds;
    /*0x012*/ u8 playTimeVBlanks;
    /*0x013*/ u8 optionsButtonMode:2;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
              u8 optionsHpBarAnimSpeed:2; //speed at which health bar animates
              u8 optionsPadding:4;
    /*0x014*/ u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST/INSTANT]
              u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
    /*0x15*/  u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
              u16 optionsBattleStyle:2; // OPTIONS_BATTLE_STYLE_[PREDICT/SHIFT/SET]
              u16 optionsBattleSceneOff:1; // whether battle animations are disabled
              u16 optionsBattleTransitions:1; // whether battle transitions are disabled
              u16 optionsBattleIntroAnim:1; // whether battle intro slide is disabled
              u16 optionsExpBarAnimSpeed:1;  // whether exp bar animates instantly
    /*0x018*/ struct Pokedex pokedex;
    /*0x090*/ u8 filler_90[0x8];
    /*0x098*/ struct Time localTimeOffset;
    /*0x0A0*/ struct Time lastBerryTreeUpdate;
    /*0x0A8*/ u32 gcnLinkFlags; // Read by Pokemon Colosseum/XD
    /*0x0AC*/ u8 field_AC;
    /*0x0AD*/ u8 field_AD;
    /*0x0B0*/ struct BattleTowerData battleTower;
    /*0x898*/ u16 mapView[0x100];
    /*0xA98*/ struct LinkBattleRecords linkBattleRecords;
    /*0xAF0*/ struct BerryCrush berryCrush;
    /*0xB00*/ struct PokemonJumpResults pokeJump;
    /*0xB10*/ struct BerryPickingResults berryPick;
    /*0xB20*/ u8 filler_B20[0x400];
    /*0xF20*/ u32 encryptionKey;
}; // size: 0xF24

extern struct SaveBlock2 *gSaveBlock2Ptr;

struct SecretBaseParty
{
    u32 personality[PARTY_SIZE];
    u16 moves[PARTY_SIZE * 4];
    u16 species[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];
    u8 levels[PARTY_SIZE];
    u8 EVs[PARTY_SIZE];
};

struct SecretBaseRecord
{
    /*0x1A9C*/ u8 secretBaseId;
    /*0x1A9D*/ u8 sbr_field_1_0:4;
    /*0x1A9D*/ u8 gender:1;
    /*0x1A9D*/ u8 sbr_field_1_5:1;
    /*0x1A9D*/ u8 sbr_field_1_6:2;
    /*0x1A9E*/ u8 trainerName[PLAYER_NAME_LENGTH];
    /*0x1AA5*/ u8 trainerId[4]; // byte 0 is used for determining trainer class
    /*0x1AA9*/ u8 language;
    /*0x1AAA*/ u16 sbr_field_e;
    /*0x1AAC*/ u8 sbr_field_10;
    /*0x1AAD*/ u8 sbr_field_11;
    /*0x1AAE*/ u8 decorations[16];
    /*0x1ABE*/ u8 decorationPos[16];
    /*0x1AD0*/ struct SecretBaseParty party;
};

struct WarpData
{
    s8 mapGroup;
    s8 mapNum;
    s8 warpId;
    s16 x, y;
};

struct ItemSlot
{
    u16 itemId;
    u16 quantity;
};

struct Pokeblock
{
    u8 color;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 feel;
};

struct Roamer
{
    /*0x00*/ u32 ivs;
    /*0x04*/ u32 personality;
    /*0x08*/ u16 species;
    /*0x0A*/ u16 hp;
    /*0x0C*/ u8 level;
    /*0x0D*/ u8 status;
    /*0x0E*/ u8 cool;
    /*0x0F*/ u8 beauty;
    /*0x10*/ u8 cute;
    /*0x11*/ u8 smart;
    /*0x12*/ u8 tough;
    /*0x13*/ bool8 active;
    /*0x14*/ u8 filler[0x8];
};

struct RamScriptData
{
    u8 magic;
    u8 mapGroup;
    u8 mapNum;
    u8 objectId;
    u8 script[995];
};

struct RamScript
{
    u32 checksum;
    struct RamScriptData data;
};

struct EasyChatPair
{
    u16 unk0_0:7;
    u16 unk0_7:7;
    u16 unk1_6:1;
    u16 unk2;
    u16 words[2];
}; /*size = 0x8*/

struct MailStruct
{
    /*0x00*/ u16 words[9];
    /*0x12*/ u8 playerName[8];
    /*0x1A*/ u8 trainerId[4];
    /*0x1E*/ u16 species;
    /*0x20*/ u16 itemId;
};

struct MauvilleManCommon
{
    u8 id;
};

struct MauvilleManBard
{
    /*0x00*/ u8 id;
    /*0x02*/ u16 songLyrics[BARD_SONG_LENGTH];
    /*0x0E*/ u16 temporaryLyrics[BARD_SONG_LENGTH];
    /*0x1A*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x22*/ u8 filler_2DB6[0x3];
    /*0x25*/ u8 playerTrainerId[TRAINER_ID_LENGTH];
    /*0x29*/ bool8 hasChangedSong;
    /*0x2A*/ u8 language;
}; /*size = 0x2C*/

struct MauvilleManStoryteller
{
    u8 id;
    bool8 alreadyRecorded;
    u8 filler2[2];
    u8 gameStatIDs[NUM_STORYTELLER_TALES];
    u8 trainerNames[NUM_STORYTELLER_TALES][PLAYER_NAME_LENGTH];
    u8 statValues[NUM_STORYTELLER_TALES][4];
    u8 language[NUM_STORYTELLER_TALES];
};

struct MauvilleManGiddy
{
    /*0x00*/ u8 id;
    /*0x01*/ u8 taleCounter;
    /*0x02*/ u8 questionNum;
    /*0x04*/ u16 randomWords[10];
    /*0x18*/ u8 questionList[8];
    /*0x20*/ u8 language;
}; /*size = 0x2C*/

struct MauvilleManHipster
{
    u8 id;
    bool8 alreadySpoken;
    u8 language;
};

struct MauvilleOldManTrader
{
    u8 id;
    u8 decorIds[NUM_TRADER_ITEMS];
    u8 playerNames[NUM_TRADER_ITEMS][11];
    u8 alreadyTraded;
    u8 language[NUM_TRADER_ITEMS];
};

typedef union OldMan
{
    struct MauvilleManCommon common;
    struct MauvilleManBard bard;
    struct MauvilleManGiddy giddy;
    struct MauvilleManHipster hipster;
    struct MauvilleOldManTrader trader;
    struct MauvilleManStoryteller storyteller;
    u8 filler[0x40];
} OldMan;

struct RecordMixing_UnknownStructSub
{
    u32 unk0;
    u8 data[0x34];
    //u8 data[0x38];
};

struct RecordMixing_UnknownStruct
{
    struct RecordMixing_UnknownStructSub data[2];
    u32 unk70;
    u16 unk74[0x2];
};

struct RecordMixingGiftData
{
    u8 unk0;
    u8 quantity;
    u16 itemId;
    u8 filler4[8];
};

struct RecordMixingGift
{
    int checksum;
    struct RecordMixingGiftData data;
};

struct ContestWinner
{
    u32 personality;
    u32 trainerId;
    u16 species;
    u8 contestCategory;
    u8 monName[11];
    u8 trainerName[8];
    u8 contestRank;
};

struct DayCareMail
{
    struct MailStruct message;
    u8 OT_name[OT_NAME_LENGTH + 1];
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 gameLanguage:4;
    u8 monLanguage:4;
};

struct DaycareMon
{
    struct BoxPokemon mon;
    struct DayCareMail mail;
    u32 steps;
};

#define DAYCARE_MON_COUNT   2

struct DayCare
{
    struct DaycareMon mons[DAYCARE_MON_COUNT];
    u32 offspringPersonality;
    u8 stepCounter;
};

struct RecordMixingDayCareMail
{
    struct DayCareMail mail[DAYCARE_MON_COUNT];
    u32 numDaycareMons;
    bool16 holdsItem[DAYCARE_MON_COUNT];
};

struct MENewsJisanStruct
{
    u8 unk_0_0:2;
    u8 unk_0_2:3;
    u8 unk_0_5:3;
    u8 berry;
};

struct QuestLogNPCData
{
    u32 x:8;
    u32 negx:1;
    u32 y:8;
    u32 negy:1;
    u32 elevation:6;
    u32 movementType:8;
};

#define BERRY_TREES_COUNT  128
#define MAIL_COUNT         (PARTY_SIZE + 10)
#define PC_MAIL_NUM(i)     (PARTY_SIZE + (i))

struct QuestLogObjectEvent
{
    /*0x00*/ u8 active:1;
    /*0x00*/ u8 triggerGroundEffectsOnStop:1;
    /*0x00*/ u8 disableCoveringGroundEffects:1;
    /*0x00*/ u8 landingJump:1;
    /*0x00*/ u8 frozen:1;
    /*0x00*/ u8 facingDirectionLocked:1;
    /*0x00*/ u8 disableAnim:1;
    /*0x00*/ u8 enableAnim:1;
    /*0x01*/ u8 inanimate:1;
    /*0x01*/ u8 invisible:1;
    /*0x01*/ u8 offScreen:1;
    /*0x01*/ u8 trackedByCamera:1;
    /*0x01*/ u8 isPlayer:1;
    /*0x01*/ u8 spriteAnimPausedBackup:1;
    /*0x01*/ u8 spriteAffineAnimPausedBackup:1;
    /*0x01*/ u8 disableJumpLandingGroundEffect:1;
    /*0x02*/ u8 fixedPriority:1;
    /*0x02*/ u8 mapobj_unk_18:4;
    /*0x02*/ u8 unused_02_5:3;
    /*0x03*/ u8 mapobj_unk_0B_0:4;
    /*0x03*/ u8 elevation:4;
    /*0x04*/ u8 graphicsId;
    /*0x05*/ u8 animPattern;
    /*0x06*/ u8 trainerType;
    /*0x07*/ u8 localId;
    /*0x08*/ u8 mapNum;
    /*0x09*/ u8 mapGroup;
    /*0x0a*/ s16 x;
    /*0x0c*/ s16 y;
    /*0x0e*/ u8 trainerRange_berryTreeId;
    /*0x0f*/ u8 previousMetatileBehavior;
    /*0x10*/ u8 directionSequenceIndex;
    /*0x11*/ u8 animId;
};

struct QuestLog
{
    /*0x0000*/ u8 startType;
    /*0x0001*/ u8 mapGroup;
    /*0x0002*/ u8 mapNum;
    /*0x0003*/ u8 warpId;
    /*0x0004*/ s16 x;
    /*0x0006*/ s16 y;
    /*0x0008*/ struct QuestLogObjectEvent unk_008[OBJECT_EVENTS_COUNT];

    // These arrays hold the game state for
    // playing back the quest log
    /*0x0148*/ u8 flags[NUM_FLAG_BYTES];
    /*0x02c8*/ u16 vars[VARS_COUNT];
    /*0x0468*/ struct QuestLogNPCData npcData[64];
    /*0x0568*/ u16 script[128];
    /*0x0668*/ u16 end[0];
};

#include "fame_checker.h"

struct FameCheckerSaveData
{
    /*3a54*/ u16 pickState:2;
    u16 flavorTextFlags:12;
    u16 unk_0_E:2;
};

#define NUM_EASY_CHAT_EXTRA_PHRASES 33
#define EASY_CHAT_EXTRA_PHRASES_SIZE ((NUM_EASY_CHAT_EXTRA_PHRASES >> 3) + (NUM_EASY_CHAT_EXTRA_PHRASES % 8 ? 1 : 0))

struct MEWonderNewsData
{
    u16 newsId;
    u8 shareState;
    u8 unk_03;
    u8 unk_04[40];
    u8 unk_2C[10][40];
};

struct MEWonderNewsStruct
{
    u32 crc;
    struct MEWonderNewsData data;
};

struct MEWonderCardData
{
    u16 cardId;
    u16 unk_02;
    u32 unk_04;
    u8 unk_08_0:2;
    u8 unk_08_2:4;
    u8 shareState:2;
    u8 recvMonCapacity;
    u8 unk_0A[40];
    u8 unk_32[40];
    u8 unk_5A[4][40];
    u8 unk_FA[40];
    u8 unk_122[40];
};

struct MEWonderCardStruct
{
    u32 crc;
    struct MEWonderCardData data;
};

struct MEventBuffer_3430_Sub
{
    u16 linkWins;
    u16 linkLosses;
    u16 linkTrades;
    u16 unk_06;
    u16 distributedMons[2][7]; // [0][x] = species
                               // [1][x] = ???
};

struct MEventBuffer_3430
{
    u32 crc;
    struct MEventBuffer_3430_Sub data;
};

struct MEventBuffers
{
    /*0x000 0x3120*/ struct MEWonderNewsStruct menews;
    /*0x1c0 0x32e0*/ struct MEWonderCardStruct mecard;
    /*0x310 0x3430*/ struct MEventBuffer_3430 buffer_310;
    /*0x338 0x3458*/ u16 ec_profile_maybe[4];
    /*0x340 0x3460*/ struct MENewsJisanStruct me_jisan;
    /*0x344 0x3464*/ u32 unk_344[2][5];
}; // 0x36C 0x348C

struct TrainerTower
{
    u32 timer;
    u32 bestTime;
    u8 floorsCleared;
    u8 unk9;
    bool8 receivedPrize:1;
    bool8 checkedFinalTime:1;
    bool8 spokeToOwner:1;
    bool8 hasLost:1;
    bool8 unkA_4:1;
    bool8 validated:1;
};

struct TrainerRematchState
{
    u16 stepCounter;
    u8 rematches[100];
};

struct TrainerNameRecord
{
    u32 trainerId;
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
};

struct KeySystemFlags
{
    u16 difficulty:2;   //0 for normal, 1 for challenge, 2 for easy, 3 for maybe another mode?
    u16 version:1;      //0 for FR, 1 for LG
    u16 nuzlocke:1;     //0 for normal, 1 for Nuzlocke mode
    u16 ivCalcMode:2;   //0 for normal, 1 for all 31, 2 for all zero
    u16 evCalcMode:1;   //0 for normal, 1 for all zero
    u16 noPMC:1;        //0 for normal, 1 for no Pokemon Center healing.
    u16 expMod:2;       //0 for 0x, 1 for 1/2x, 2 for 1x, 3 for 2x 
    u16 padding:4;
    u16 changedCalcMode:1; //set if calc mode is changed to recalc party on save load
    u16 inKeySystemMenu:1; //Needed for Help Menu regardless of Button Mode
    u16 padding2;
};

// For external event data storage. The majority of these may have never been used.
// In FRLG, the only known used fields are the PokeCoupon and BoxRS ones, but hacking the distribution discs allows FRLG to receive events and set the others
struct ExternalEventData
{
    u8 unknownExternalDataFields1[7]; // if actually used, may be broken up into different fields.
    u32 unknownExternalDataFields2:8;
    u32 currentPokeCoupons:24; // PokéCoupons stored by Pokémon Colosseum and XD from Mt. Battle runs. Earned PokéCoupons are also added to totalEarnedPokeCoupons. Colosseum/XD caps this at 9,999,999, but will read up to 16,777,215.
    u32 gotGoldPokeCouponTitleReward:1; // Master Ball from JP Colosseum Bonus Disc; for reaching 30,000 totalEarnedPokeCoupons
    u32 gotSilverPokeCouponTitleReward:1; // Light Ball Pikachu from JP Colosseum Bonus Disc; for reaching 5000 totalEarnedPokeCoupons
    u32 gotBronzePokeCouponTitleReward:1; // PP Max from JP Colosseum Bonus Disc; for reaching 2500 totalEarnedPokeCoupons
    u32 receivedAgetoCelebi:1; // from JP Colosseum Bonus Disc
    u32 unknownExternalDataFields3:4;
    u32 totalEarnedPokeCoupons:24; // Used by the JP Colosseum bonus disc. Determines PokéCoupon rank to distribute rewards. Unread in International games. Colosseum/XD caps this at 9,999,999.
    u8 unknownExternalDataFields4[5]; // if actually used, may be broken up into different fields.
} __attribute__((packed)); /*size = 0x14*/

// For external event flags. The majority of these may have never been used.
// In FRLG, Jirachi cannot normally be received, but hacking the distribution discs allows FRLG to receive Jirachi and set the flag
struct ExternalEventFlags
{
    u8 usedBoxRS:1; // Set by Pokémon Box: Ruby & Sapphire; denotes whether this save has connected to it and triggered the free False Swipe Swablu Egg giveaway.
    u8 boxRSEggsUnlocked:2; // Set by Pokémon Box: Ruby & Sapphire; denotes the number of Eggs unlocked from deposits; 1 for ExtremeSpeed Zigzagoon (at 100 deposited), 2 for Pay Day Skitty (at 500 deposited), 3 for Surf Pichu (at 1499 deposited)
    u8 padding:5;
    u8 unknownFlag1;
    u8 receivedGCNJirachi; // Both the US Colosseum Bonus Disc and PAL/AUS Pokémon Channel use this field. One cannot receive a WISHMKR Jirachi and CHANNEL Jirachi with the same savefile.
    u8 unknownFlag3;
    u8 unknownFlag4;
    u8 unknownFlag5;
    u8 unknownFlag6;
    u8 unknownFlag7;
    u8 unknownFlag8;
    u8 unknownFlag9;
    u8 unknownFlag10;
    u8 unknownFlag11;
    u8 unknownFlag12;
    u8 unknownFlag13;
    u8 unknownFlag14;
    u8 unknownFlag15;
    u8 unknownFlag16;
    u8 unknownFlag17;
    u8 unknownFlag18;
    u8 unknownFlag19;
    u8 unknownFlag20;

} __attribute__((packed));/*size = 0x15*/

#define UNION_ROOM_KB_ROW_COUNT 10

struct SaveBlock1
{
    /*0x0000*/ struct Coords16 pos;
    /*0x0004*/ struct WarpData location;
    /*0x000C*/ struct WarpData continueGameWarp;
    /*0x0014*/ struct WarpData dynamicWarp;
    /*0x001C*/ struct WarpData lastHealLocation;
    /*0x0024*/ struct WarpData escapeWarp;
    /*0x002C*/ u16 savedMusic;
    /*0x002E*/ u8 weather;
    /*0x002F*/ u8 weatherCycleStage;
    /*0x0030*/ u8 flashLevel;
    /*0x0032*/ u16 mapLayoutId;
    /*0x0034*/ u8 playerPartyCount;
    /*0x0038*/ struct Pokemon playerParty[PARTY_SIZE];
    /*0x0290*/ u32 money;
    /*0x0294*/ u16 coins;
    /*0x0296*/ u16 registeredItem; // registered for use with SELECT button, could probably be stripped to less than a byte as an index into a table of only registerable items
    /*0x0298*/ struct ItemSlot pcItems[PC_ITEMS_COUNT];
    /*0x0310*/ struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT]; //now holds 47 items
    /*0x053C*/ struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
               u8 bagPocket_TMHM[8]; // 8 bytes fills all TMs/HMs
               u8 bagPocket_KeyItems[BAG_KEYITEMS_COUNT]; // stripped to one byte indices, 36 slots now for all legal FRLG Key Items at once + 2 more for cheaters/alignment.
               struct ItemSlot bagPocket_Medicine[BAG_MEDICINE_COUNT];
               struct ItemSlot bagPocket_HoldItems[BAG_HELD_ITEMS_COUNT];
               u8 leftoverItemSlots[92]; //padding to prevent shifting the saveblock, Berry Pocket was moved elsewhere
    /*0x05F8*/ u8 seen1[52]; //made unreferenced & can be gotten rid of, though PKHeX presumably will still set this
    /*0x062C*/ u8 filler_062C[5]; // unused; was berryBlenderRecords which was obviously unused
               u8 masterTrainerTitle; // 0 is none, 152 is Grandmaster, 1-151 is {Kanto species} Master
    /*0x0632*/ u16 lastViewedPokedexEntry; // For easier viewing of roamers
               struct KeySystemFlags keyFlags; //Key System flags
    /*0x0638*/ u16 trainerRematchStepCounter;
    /*0x063A*/ u8 ALIGNED(2) trainerRematches[100];
    /*0x06A0*/ struct ObjectEvent objectEvents[OBJECT_EVENTS_COUNT];
    /*0x08E0*/ struct ObjectEventTemplate objectEventTemplates[64];
    /*0x0EE0*/ u8 flags[NUM_FLAG_BYTES];
    /*0x1000*/ u16 vars[VARS_COUNT];
    /*0x1200*/ u32 gameStats[NUM_GAME_STATS];
    /*0x1300*/ struct QuestLog questLog[QUEST_LOG_SCENE_COUNT];
    /*0x2CA0*/ u16 easyChatProfile[6];
    /*0x2CAC*/ u16 easyChatBattleStart[6]; //referred to, but functionally unused
    /*0x2CB8*/ u16 easyChatBattleWon[6]; //referred to, but functionally unused
    /*0x2CC4*/ u16 easyChatBattleLost[6]; //referred to, but functionally unused
    /*0x2CD0*/ struct MailStruct mail[MAIL_COUNT];
    /*0x2F10*/ u8 additionalPhrases[EASY_CHAT_EXTRA_PHRASES_SIZE];
    /*0x2F18*/ u8 filler_oldMan[64]; // unused, was struct OldMan oldMan
    /*0x2F54*/ u8 filler_EasyChatPairs[36]; // unused, was struct EasyChatPair easyChatPairs[5], which was 40 bytes, but I had to add 2 bytes to the Daycare struct (which got padded to 4).
    /*0x2F80*/ struct DayCare daycare;
    /*0x309C*/ u8 giftRibbons[11];
    /*0x30A7*/ struct ExternalEventData externalEventData;
    /*0x30BB*/ struct ExternalEventFlags externalEventFlags;
    /*0x30D0*/ struct Roamer roamer;
    /*0x30EC*/ struct EnigmaBerry enigmaBerry;
    /*0x3120*/ struct MEventBuffers mysteryEventBuffers; //0x36C in length
    /*0x348C*/ u8 filler_348C[176];
    //^^^this & the mysteryEventBuffers field are labeled "FreeWork" & combined in the source, though 0x36C of FreeWork is set aside for MEventBuffers in mevent.c,
    //^^^which is likely where the above field was documented from. The rest of FreeWork is unreferenced in the source, so this field is likely unused.
               u8 nuzlockeDupeFlags[52]; //taken from filler_348c field, which was originally 400 bytes. Used to prevent hijacking the dupe clause in Nuzlocke by catching fainted Pokemon.
               struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT]; //taken from filler_348C field, which was originally 400 bytes
    /*0x361C*/ struct RamScript ramScript;
    /*0x3A08*/ u8 filler3A08[16]; //Record Mixing gift. Unused.
    /*0x3A18*/ u8 seen2[52]; //made unreferenced & can be gotten rid of, though PKHeX presumably will still set this
    /*0x3A4C*/ u8 rivalName[PLAYER_NAME_LENGTH + 1];
    /*0x3A54*/ struct FameCheckerSaveData fameChecker[NUM_FAMECHECKER_PERSONS];
    /*0x3A94*/ u8 filler3A94[44]; //max fame checker people is actually 32, so this is the unused 16 entries
               u8 masterTrainerFlags[20]; //taken from above filler3A94 field, which was originally 64 bytes long. 1 byte longer than necessary for alignment.
    /*0x3AD4*/ u8 registeredTexts[UNION_ROOM_KB_ROW_COUNT][21];
    /*0x3BA8*/ struct TrainerNameRecord trainerNameRecords[20];
    /*0x3C98*/ struct DaycareMon route5DayCareMon;
    /*0x3D24*/ u8 filler3D24[16]; //some sort of win/loss/draw records that are never referred to. An RFU thing. Mystery Event?
    /*0x3D34*/ u32 towerChallengeId;
    /*0x3D38*/ struct TrainerTower trainerTower[NUM_TOWER_CHALLENGE_TYPES];
}; // size: 0x3D68

struct MapPosition
{
    s16 x;
    s16 y;
    s8 height;
};

extern struct SaveBlock1* gSaveBlock1Ptr;
extern u8 gReservedSpritePaletteCount;

#endif // GUARD_GLOBAL_H
