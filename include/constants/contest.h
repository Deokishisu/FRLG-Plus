#ifndef GUARD_CONSTANTS_CONTEST_H
#define GUARD_CONSTANTS_CONTEST_H

#define APPLAUSE_METER_SIZE 5
#define CONTEST_NUM_APPEALS 5
#define CONTEST_LAST_APPEAL (CONTEST_NUM_APPEALS - 1)
#define MAX_CONTEST_MOVE_HEARTS 8

#define CONTESTANT_NONE 0xFF

#define LINK_CONTEST_FLAG_IS_LINK       (1 << 0)
#define LINK_CONTEST_FLAG_IS_WIRELESS   (1 << 1)
#define LINK_CONTEST_FLAG_HAS_RS_PLAYER (1 << 2)

#define CONTEST_RANK_NORMAL  0
#define CONTEST_RANK_SUPER   1
#define CONTEST_RANK_HYPER   2
#define CONTEST_RANK_MASTER  3
#define CONTEST_RANK_LINK    4

// States for VAR_CONTEST_TYPE
#define CONTEST_TYPE_NPC_NORMAL  (CONTEST_RANK_NORMAL + 1)
#define CONTEST_TYPE_NPC_SUPER   (CONTEST_RANK_SUPER + 1)
#define CONTEST_TYPE_NPC_HYPER   (CONTEST_RANK_HYPER + 1)
#define CONTEST_TYPE_NPC_MASTER  (CONTEST_RANK_MASTER + 1)
#define CONTEST_TYPE_LINK        (CONTEST_RANK_LINK + 1)

// IDs below - 1 are indexes into gSaveBlock2Ptr->contestWinners[]
// CONTEST_WINNER_ARTIST is for the winner of the most recent contest, and is not saved.
#define CONTEST_WINNER_ARTIST 0
#define CONTEST_WINNER_HALL_1 1
#define CONTEST_WINNER_HALL_2 2
#define CONTEST_WINNER_HALL_3 3
#define CONTEST_WINNER_HALL_4 4
#define CONTEST_WINNER_HALL_5 5
#define CONTEST_WINNER_HALL_6 6
#define NUM_CONTEST_HALL_WINNERS 6
#define CONTEST_WINNER_MUSEUM_COOL   7
#define CONTEST_WINNER_MUSEUM_BEAUTY 8
#define CONTEST_WINNER_MUSEUM_CUTE   9
#define CONTEST_WINNER_MUSEUM_SMART  10
#define CONTEST_WINNER_MUSEUM_TOUGH  11
// NUM_CONTEST_WINNERS in constants/global.h

#define MUSEUM_CONTEST_WINNERS_START (CONTEST_WINNER_MUSEUM_COOL - 1)

#define CONTEST_SAVE_FOR_MUSEUM ((u8)-1)
#define CONTEST_SAVE_FOR_ARTIST ((u8)-2)

// The number of possible captions for a Contest painting, per category
#define NUM_PAINTING_CAPTIONS 3

#define CANT_ENTER_CONTEST             0
#define CAN_ENTER_CONTEST_EQUAL_RANK   1
#define CAN_ENTER_CONTEST_HIGH_RANK    2
#define CANT_ENTER_CONTEST_EGG         3
#define CANT_ENTER_CONTEST_FAINTED     4
#define CANT_ENTER_CONTEST_BANNED      5

#define CONTEST_AI_CHECK_BAD_MOVE   (1 << 0)
#define CONTEST_AI_CHECK_COMBO      (1 << 1)
#define CONTEST_AI_CHECK_BORING     (1 << 2)
#define CONTEST_AI_CHECK_EXCITEMENT (1 << 3)
#define CONTEST_AI_CHECK_ORDER      (1 << 4)
#define CONTEST_AI_CHECK_GOOD_MOVE  (1 << 5)
#define CONTEST_AI_ERRATIC          (1 << 6)
#define CONTEST_AI_DUMMY_1          (1 << 7)
#define CONTEST_AI_DUMMY_2          (1 << 8)
#define CONTEST_AI_DUMMY_3          (1 << 9)
#define CONTEST_AI_DUMMY_4          (1 << 10)
#define CONTEST_AI_DUMMY_5          (1 << 11)
#define CONTEST_AI_DUMMY_6          (1 << 12)
#define CONTEST_AI_DUMMY_7          (1 << 13)
#define CONTEST_AI_DUMMY_8          (1 << 14)
#define CONTEST_AI_DUMMY_9          (1 << 15)
#define CONTEST_AI_DUMMY_10         (1 << 16)
#define CONTEST_AI_DUMMY_11         (1 << 17)
#define CONTEST_AI_DUMMY_12         (1 << 18)
#define CONTEST_AI_DUMMY_13         (1 << 19)
#define CONTEST_AI_DUMMY_14         (1 << 20)
#define CONTEST_AI_DUMMY_15         (1 << 21)
#define CONTEST_AI_DUMMY_16         (1 << 22)
#define CONTEST_AI_DUMMY_17         (1 << 23)
#define CONTEST_AI_DUMMY_18         (1 << 24)
#define CONTEST_AI_DUMMY_19         (1 << 25)
#define CONTEST_AI_DUMMY_20         (1 << 26)
#define CONTEST_AI_DUMMY_21         (1 << 27)
#define CONTEST_AI_DUMMY_22         (1 << 28)
#define CONTEST_AI_DUMMY_23         (1 << 29)
#define CONTEST_AI_DUMMY_24         (1 << 30)
#define CONTEST_AI_DUMMY_25         (1 << 31)

// The below scripts are used by every AI contest opponent
// It includes every non-dummy script
#define CONTEST_AI_COMMON   (CONTEST_AI_CHECK_BAD_MOVE | CONTEST_AI_CHECK_COMBO | CONTEST_AI_CHECK_BORING | \
                             CONTEST_AI_CHECK_EXCITEMENT | CONTEST_AI_CHECK_ORDER | CONTEST_AI_CHECK_GOOD_MOVE | CONTEST_AI_ERRATIC | \
                             CONTEST_AI_DUMMY_1 | CONTEST_AI_DUMMY_2 | CONTEST_AI_DUMMY_3 | CONTEST_AI_DUMMY_4 | CONTEST_AI_DUMMY_5)

#define CONTEST_EFFECT_HIGHLY_APPEALING                         0
#define CONTEST_EFFECT_USER_MORE_EASILY_STARTLED                1
#define CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES           2
#define CONTEST_EFFECT_REPETITION_NOT_BORING                    3
#define CONTEST_EFFECT_AVOID_STARTLE_ONCE                       4
#define CONTEST_EFFECT_AVOID_STARTLE                            5
#define CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY                   6
#define CONTEST_EFFECT_USER_LESS_EASILY_STARTLED                7
#define CONTEST_EFFECT_STARTLE_FRONT_MON                        8
#define CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS               9
#define CONTEST_EFFECT_STARTLE_PREV_MON                         10
#define CONTEST_EFFECT_STARTLE_PREV_MONS                        11
#define CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON                  12
#define CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS                  13
#define CONTEST_EFFECT_STARTLE_PREV_MON_2                       14
#define CONTEST_EFFECT_STARTLE_PREV_MONS_2                      15
#define CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION                    16
#define CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION        17
#define CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN            18
#define CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL            19
#define CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL                 20
#define CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL               21
#define CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL                 22
#define CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL                23
#define CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL                24
#define CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS               25
#define CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS              26
#define CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS            27
#define CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION    28
#define CONTEST_EFFECT_BETTER_IF_FIRST                          29
#define CONTEST_EFFECT_BETTER_IF_LAST                           30
#define CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES              31
#define CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE               32
#define CONTEST_EFFECT_BETTER_WHEN_LATER                        33
#define CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING                34
#define CONTEST_EFFECT_BETTER_IF_SAME_TYPE                      35
#define CONTEST_EFFECT_BETTER_IF_DIFF_TYPE                      36
#define CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL                  37
#define CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS    38
#define CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION               39
#define CONTEST_EFFECT_NEXT_APPEAL_EARLIER                      40
#define CONTEST_EFFECT_NEXT_APPEAL_LATER                        41
#define CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER        42
#define CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER                 43
#define CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST           44
#define CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS     45
#define CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED             46
#define CONTEST_EFFECT_DONT_EXCITE_AUDIENCE                     47

// Each of the above effects is grouped into one of these effect type categories
// Only a few of these get checked by the AI, the rest go unused
#define CONTEST_EFFECT_TYPE_APPEAL         0
#define CONTEST_EFFECT_TYPE_AVOID_STARTLE  1
#define CONTEST_EFFECT_TYPE_STARTLE_MON    2
#define CONTEST_EFFECT_TYPE_STARTLE_MONS   3
#define CONTEST_EFFECT_TYPE_WORSEN         4
#define CONTEST_EFFECT_TYPE_SPECIAL_APPEAL 5
#define CONTEST_EFFECT_TYPE_TURN_ORDER     6

#define COMBO_STARTER_RAIN_DANCE    1
#define COMBO_STARTER_RAGE          2
#define COMBO_STARTER_FOCUS_ENERGY  3
#define COMBO_STARTER_HYPNOSIS      4
#define COMBO_STARTER_ENDURE        5
#define COMBO_STARTER_HORN_ATTACK   6
#define COMBO_STARTER_SWORDS_DANCE  7
#define COMBO_STARTER_STOCKPILE     8
#define COMBO_STARTER_SUNNY_DAY     9
#define COMBO_STARTER_REST          10
#define COMBO_STARTER_VICE_GRIP     11
#define COMBO_STARTER_DEFENSE_CURL  12
#define COMBO_STARTER_CHARGE        13
#define COMBO_STARTER_ROCK_THROW    14
#define COMBO_STARTER_YAWN          15
#define COMBO_STARTER_SCARY_FACE    16
#define COMBO_STARTER_POWDER_SNOW   17
#define COMBO_STARTER_LOCK_ON       18
#define COMBO_STARTER_SOFT_BOILED   19
#define COMBO_STARTER_MEAN_LOOK     20
#define COMBO_STARTER_SCRATCH       21
#define COMBO_STARTER_GROWTH        22
#define COMBO_STARTER_HAIL          23
#define COMBO_STARTER_SANDSTORM     24
#define COMBO_STARTER_BELLY_DRUM    25
#define COMBO_STARTER_MIND_READER   26
#define COMBO_STARTER_DRAGON_BREATH 27
#define COMBO_STARTER_DRAGON_RAGE   28
#define COMBO_STARTER_DRAGON_DANCE  29
#define COMBO_STARTER_SURF          30
#define COMBO_STARTER_DIVE          31
#define COMBO_STARTER_STRING_SHOT   32
#define COMBO_STARTER_LEER          33
#define COMBO_STARTER_TAUNT         34
#define COMBO_STARTER_CHARM         35
#define COMBO_STARTER_HARDEN        36
#define COMBO_STARTER_SING          37
#define COMBO_STARTER_EARTHQUAKE    38
#define COMBO_STARTER_DOUBLE_TEAM   39
#define COMBO_STARTER_CURSE         40
#define COMBO_STARTER_SWEET_SCENT   41
#define COMBO_STARTER_SLUDGE        42
#define COMBO_STARTER_SLUDGE_BOMB   43
#define COMBO_STARTER_THUNDER_PUNCH 44
#define COMBO_STARTER_FIRE_PUNCH    45
#define COMBO_STARTER_ICE_PUNCH     46
#define COMBO_STARTER_PECK          47
#define COMBO_STARTER_METAL_SOUND   48
#define COMBO_STARTER_MUD_SPORT     49
#define COMBO_STARTER_WATER_SPORT   50
#define COMBO_STARTER_BONE_CLUB     51
#define COMBO_STARTER_BONEMERANG    52
#define COMBO_STARTER_BONE_RUSH     53
#define COMBO_STARTER_SAND_ATTACK   54
#define COMBO_STARTER_MUD_SLAP      55
#define COMBO_STARTER_FAKE_OUT      56
#define COMBO_STARTER_PSYCHIC       57
#define COMBO_STARTER_KINESIS       58
#define COMBO_STARTER_CONFUSION     59
#define COMBO_STARTER_POUND         60
#define COMBO_STARTER_SMOG          61
#define COMBO_STARTER_CALM_MIND     62

// Contest OBJ_EVENT_GFX_ constants
// This is necessary because struct ContestPokemon's trainerGfxId field
// needs to stay u8 for compatibility with vanilla. These constants get
// converted to either vanilla or FRLG+ OBJ_EVENT_GFX_* for display or
// sending to vanilla in E-Mode link contests.

// FRLG+
#define CONTEST_OBJ_DAISY                    1
#define CONTEST_OBJ_LITTLE_BOY               2
#define CONTEST_OBJ_BALDING_MAN              3
#define CONTEST_OBJ_BEAUTY                   4
#define CONTEST_OBJ_LITTLE_GIRL              5
#define CONTEST_OBJ_YOUNGSTER                6
#define CONTEST_OBJ_BLACKBELT                7
#define CONTEST_OBJ_PICNICKER                8
#define CONTEST_OBJ_BATTLE_GIRL              9
#define CONTEST_OBJ_GENTLEMAN               10
#define CONTEST_OBJ_POKEMON_RANGER_F        11
#define CONTEST_OBJ_BOY                     12
#define CONTEST_OBJ_FAT_MAN                 13
#define CONTEST_OBJ_CHANNELER               14
#define CONTEST_OBJ_PSYCHIC_F               15
#define CONTEST_OBJ_ENGINEER                16
#define CONTEST_OBJ_CAMPER                  17
#define CONTEST_OBJ_BUG_CATCHER             18
#define CONTEST_OBJ_PAINTER                 19
#define CONTEST_OBJ_TUBER_F                 20
#define CONTEST_OBJ_POKE_MANIAC             21
#define CONTEST_OBJ_POKEMON_RANGER_M        22
#define CONTEST_OBJ_WOMAN_3                 23
#define CONTEST_OBJ_CHEF                    24
#define CONTEST_OBJ_AROMA_LADY              25
#define CONTEST_OBJ_BIRD_KEEPER             26
#define CONTEST_OBJ_OLD_WOMAN               27
#define CONTEST_OBJ_JUGGLER                 28
#define CONTEST_OBJ_OLD_MAN_1               29
#define CONTEST_OBJ_SAILOR                  30
#define CONTEST_OBJ_WORKER_M                31
#define CONTEST_OBJ_YOUNG_COUPLE_M          32
#define CONTEST_OBJ_CLERK                   33
#define CONTEST_OBJ_CAPTAIN                 34
#define CONTEST_OBJ_HIKER                   35
#define CONTEST_OBJ_RUIN_MANIAC             36
#define CONTEST_OBJ_YOUNG_COUPLE_F          37
#define CONTEST_OBJ_WOMAN_1                 38
#define CONTEST_OBJ_COOLTRAINER_M           39
#define CONTEST_OBJ_CABLE_CLUB_RECEPTIONIST 40
#define CONTEST_OBJ_SCIENTIST               41
#define CONTEST_OBJ_ROCKER                  42
#define CONTEST_OBJ_FISHER                  43
#define CONTEST_OBJ_TUBER_M_LAND            44
#define CONTEST_OBJ_SUPER_NERD              45
#define CONTEST_OBJ_MAN                     46
#define CONTEST_OBJ_BURGLAR                 47
#define CONTEST_OBJ_POKEMON_BREEDER         48
#define CONTEST_OBJ_COOLTRAINER_F           49

// Emerald (Only Emerald can have AI Contest Opponents in Link Mode)
#define CONTEST_OBJ_RS_MAN_4                50
#define CONTEST_OBJ_RS_BOY_1                51
#define CONTEST_OBJ_RS_GIRL_1               52
#define CONTEST_OBJ_RS_LITTLE_BOY           53
#define CONTEST_OBJ_RS_WOMAN_1              54
#define CONTEST_OBJ_RS_POKEFAN_F            55
#define CONTEST_OBJ_RS_BLACK_BELT           56
#define CONTEST_OBJ_RS_YOUNGSTER            57
#define CONTEST_OBJ_RS_WOMAN_4              58
#define CONTEST_OBJ_RS_CAMPER               59
#define CONTEST_OBJ_RS_LASS                 60
#define CONTEST_OBJ_RS_SCHOOL_KID_M         61
#define CONTEST_OBJ_RS_GIRL_2               62
#define CONTEST_OBJ_RS_MAN_3                63
#define CONTEST_OBJ_RS_TWIN                 64
#define CONTEST_OBJ_RS_RICH_BOY             65
#define CONTEST_OBJ_RS_WOMAN_2              66
#define CONTEST_OBJ_RS_HEX_MANIAC           67
#define CONTEST_OBJ_RS_WOMAN_5              68
#define CONTEST_OBJ_RS_HIKER                69
#define CONTEST_OBJ_RS_TUBER_F              70
#define CONTEST_OBJ_RS_NINJA_BOY            71
#define CONTEST_OBJ_RS_BEAUTY               72
#define CONTEST_OBJ_RS_MAN_5                73
#define CONTEST_OBJ_RS_MANIAC               74
#define CONTEST_OBJ_RS_PICNICKER            75
#define CONTEST_OBJ_RS_RUNNING_TRIATHLETE_M 76
#define CONTEST_OBJ_RS_FAT_MAN              77
#define CONTEST_OBJ_RS_PSYCHIC_M            78
#define CONTEST_OBJ_RS_EXPERT_M             79
#define CONTEST_OBJ_RS_TEALA                80
#define CONTEST_OBJ_RS_GENTLEMAN            81
#define CONTEST_OBJ_RS_EXPERT_F             82
#define CONTEST_OBJ_RS_SAILOR               83
#define CONTEST_OBJ_RS_GIRL_3               84
#define CONTEST_OBJ_RS_BUG_CATCHER          85
#define CONTEST_OBJ_RS_POKEFAN_M            86
#define CONTEST_OBJ_RS_SCIENTIST_1          87

// Player Characters
#define CONTEST_OBJ_RED_NORMAL              88
#define CONTEST_OBJ_GREEN_NORMAL            89
#define CONTEST_OBJ_RS_BRENDAN              90
#define CONTEST_OBJ_RS_MAY                  91
#define CONTEST_OBJ_EM_BRENDAN              92
#define CONTEST_OBJ_EM_MAY                  93

// Vanilla Emerald OBJ_EVENT_GFX_* constants that
// correspond to vanilla contest AI opponents.
// Used in ConvertContestObjToEmerald() and
// ConvertEmeraldToContestObj().

#define EM_OBJ_EVT_GFX_MAN_4                65
#define EM_OBJ_EVT_GFX_BOY_1                 7
#define EM_OBJ_EVT_GFX_GIRL_1                8
#define EM_OBJ_EVT_GFX_LITTLE_BOY           11
#define EM_OBJ_EVT_GFX_WOMAN_1              16
#define EM_OBJ_EVT_GFX_POKEFAN_F            18
#define EM_OBJ_EVT_GFX_BLACK_BELT           44
#define EM_OBJ_EVT_GFX_YOUNGSTER            35
#define EM_OBJ_EVT_GFX_WOMAN_4              26
#define EM_OBJ_EVT_GFX_CAMPER               31
#define EM_OBJ_EVT_GFX_LASS                 47
#define EM_OBJ_EVT_GFX_SCHOOL_KID_M         38
#define EM_OBJ_EVT_GFX_GIRL_2               10
#define EM_OBJ_EVT_GFX_MAN_3                33
#define EM_OBJ_EVT_GFX_TWIN                  6
#define EM_OBJ_EVT_GFX_RICH_BOY             15
#define EM_OBJ_EVT_GFX_WOMAN_2              20
#define EM_OBJ_EVT_GFX_HEX_MANIAC           40
#define EM_OBJ_EVT_GFX_WOMAN_5              34
#define EM_OBJ_EVT_GFX_HIKER                55
#define EM_OBJ_EVT_GFX_TUBER_F              53
#define EM_OBJ_EVT_GFX_NINJA_BOY             5
#define EM_OBJ_EVT_GFX_BEAUTY               45
#define EM_OBJ_EVT_GFX_MAN_5                66
#define EM_OBJ_EVT_GFX_MANIAC               39
#define EM_OBJ_EVT_GFX_PICNICKER            32
#define EM_OBJ_EVT_GFX_RUNNING_TRIATHLETE_M 51
#define EM_OBJ_EVT_GFX_FAT_MAN              17
#define EM_OBJ_EVT_GFX_PSYCHIC_M            37
#define EM_OBJ_EVT_GFX_EXPERT_M             21
#define EM_OBJ_EVT_GFX_TEALA                85
#define EM_OBJ_EVT_GFX_GENTLEMAN            48
#define EM_OBJ_EVT_GFX_EXPERT_F             22
#define EM_OBJ_EVT_GFX_SAILOR               49
#define EM_OBJ_EVT_GFX_GIRL_3               14
#define EM_OBJ_EVT_GFX_BUG_CATCHER          36
#define EM_OBJ_EVT_GFX_POKEFAN_M            25
#define EM_OBJ_EVT_GFX_SCIENTIST_1          46
#define EM_OBJ_EVT_GFX_RED                  230
#define EM_OBJ_EVT_GFX_LEAF                 231
#define EM_OBJ_EVT_GFX_RS_BRENDAN           235
#define EM_OBJ_EVT_GFX_RS_MAY               236
#define EM_OBJ_EVT_GFX_LINK_BRENDAN         216
#define EM_OBJ_EVT_GFX_LINK_MAY             217

#endif  // GUARD_CONSTANTS_CONTEST_H
