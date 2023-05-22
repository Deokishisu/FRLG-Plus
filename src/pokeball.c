#include "global.h"
#include "gflib.h"
#include "battle.h"
#include "battle_anim.h"
#include "decompress.h"
#include "graphics.h"
#include "m4a.h"
#include "pokeball.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "link.h"
#include "battle_gfx_sfx_util.h"
#include "constants/songs.h"

#define tFrames          data[0]
#define tPan             data[1]
#define tThrowId         data[2]
#define tBattler         data[3]
#define tOpponentBattler data[4]

#define sBattler         data[6]

#define GFX_TAG_POKE_BALL    55000
#define GFX_TAG_GREAT_BALL   55001
#define GFX_TAG_SAFARI_BALL  55002
#define GFX_TAG_ULTRA_BALL   55003
#define GFX_TAG_MASTER_BALL  55004
#define GFX_TAG_NET_BALL     55005
#define GFX_TAG_DIVE_BALL    55006
#define GFX_TAG_NEST_BALL    55007
#define GFX_TAG_REPEAT_BALL  55008
#define GFX_TAG_TIMER_BALL   55009
#define GFX_TAG_LUXURY_BALL  55010
#define GFX_TAG_PREMIER_BALL 55011

// Function Declarations
static void Task_DoPokeballSendOutAnim(u8 taskId);
static void SpriteCB_TestBallThrow(struct Sprite *sprite);
static void sub_804AC88(struct Sprite *sprite);
static void sub_804AC94(struct Sprite *sprite);
static void sub_804AD00(struct Sprite *sprite);
static void sub_804AD98(struct Sprite *sprite);
static void sub_804ADEC(struct Sprite *sprite);
static void sub_804AEE4(struct Sprite *sprite);
static void sub_804AF24(struct Sprite *sprite);
static void Task_PlayCryWhenReleasedFromBall(u8 taskId);
static void SpriteCB_ReleaseMonFromBall(struct Sprite *sprite);
static void sub_804B484(struct Sprite *sprite);
static void HandleBallAnimEnd(struct Sprite *sprite);
static void sub_804B5C8(struct Sprite *sprite);
static void SpriteCB_PlayerMonSendOut_0(struct Sprite *sprite);
static void SpriteCB_PlayerMonSendOut_1(struct Sprite *sprite);
static void SpriteCB_PlayerMonSendOut_2(struct Sprite *sprite);
static void SpriteCB_ReleaseMon2FromBall(struct Sprite *sprite);
static void SpriteCB_OpponentMonSendOut_0(struct Sprite *sprite);
static void SpriteCB_OpponentMonSendOut_1(struct Sprite *sprite);
#ifdef NEW_OPPONENT_SEND_MON_ANIM
static void SpriteCB_OpponentMonSendOut_2(struct Sprite *sprite);
#endif
static u8 LaunchBallStarsTaskForPokeball(u8 x, u8 y, u8 kindOfStars, u8 d);
static u8 LaunchBallFadeMonTaskForPokeball(bool8 unFadeLater, u8 battlerId, u32 arg2);
static void sub_804B9E8(struct Sprite *sprite);
static void sub_804BAA4(struct Sprite *sprite);
static void sub_804BC50(struct Sprite *sprite);
static void sub_804BCF8(struct Sprite *sprite);
static void sub_804BD6C(struct Sprite *sprite);
static void sub_804BE24(struct Sprite *sprite);
static void sub_804BE48(struct Sprite *sprite);
static void SpriteCB_HitAnimHealthoxEffect(struct Sprite *sprite);
static u16 GetBattlerPokeballItemId(u8 battlerId);

// Data
const struct CompressedSpriteSheet gBallSpriteSheets[POKEBALL_COUNT] =
{
    {gInterfaceGfx_PokeBall,    384, GFX_TAG_POKE_BALL},
    {gInterfaceGfx_GreatBall,   384, GFX_TAG_GREAT_BALL},
    {gInterfaceGfx_SafariBall,  384, GFX_TAG_SAFARI_BALL},
    {gInterfaceGfx_UltraBall,   384, GFX_TAG_ULTRA_BALL},
    {gInterfaceGfx_MasterBall,  384, GFX_TAG_MASTER_BALL},
    {gInterfaceGfx_NetBall,     384, GFX_TAG_NET_BALL},
    {gInterfaceGfx_DiveBall,    384, GFX_TAG_DIVE_BALL},
    {gInterfaceGfx_NestBall,    384, GFX_TAG_NEST_BALL},
    {gInterfaceGfx_RepeatBall,  384, GFX_TAG_REPEAT_BALL},
    {gInterfaceGfx_TimerBall,   384, GFX_TAG_TIMER_BALL},
    {gInterfaceGfx_LuxuryBall,  384, GFX_TAG_LUXURY_BALL},
    {gInterfaceGfx_PremierBall, 384, GFX_TAG_PREMIER_BALL},
};

const struct CompressedSpritePalette gBallSpritePalettes[POKEBALL_COUNT] =
{
    {gInterfacePal_PokeBall,    GFX_TAG_POKE_BALL},
    {gInterfacePal_GreatBall,   GFX_TAG_GREAT_BALL},
    {gInterfacePal_SafariBall,  GFX_TAG_SAFARI_BALL},
    {gInterfacePal_UltraBall,   GFX_TAG_ULTRA_BALL},
    {gInterfacePal_MasterBall,  GFX_TAG_MASTER_BALL},
    {gInterfacePal_NetBall,     GFX_TAG_NET_BALL},
    {gInterfacePal_DiveBall,    GFX_TAG_DIVE_BALL},
    {gInterfacePal_NestBall,    GFX_TAG_NEST_BALL},
    {gInterfacePal_RepeatBall,  GFX_TAG_REPEAT_BALL},
    {gInterfacePal_TimerBall,   GFX_TAG_TIMER_BALL},
    {gInterfacePal_LuxuryBall,  GFX_TAG_LUXURY_BALL},
    {gInterfacePal_PremierBall, GFX_TAG_PREMIER_BALL},
};

static const struct OamData sBallOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sBallAnimSeq3[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sBallAnimSeq5[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sBallAnimSeq4[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sBallAnimSeq6[] =
{
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sBallAnimSeq0[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sBallAnimSeq1[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

static const union AnimCmd sBallAnimSeq2[] =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sBallAnimSequences[] =
{
    sBallAnimSeq0,
    sBallAnimSeq1,
    sBallAnimSeq2,
    sBallAnimSeq3,
    sBallAnimSeq4,
    sBallAnimSeq5,
    sBallAnimSeq6,
};

static const union AffineAnimCmd sBallAffineAnimSeq0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sBallAffineAnimSeq1[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -3, 1),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sBallAffineAnimSeq2[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 3, 1),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sBallAffineAnimSeq3[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sBallAffineAnimSeq4[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 25, 1),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd *const sBallAffineAnimSequences[] =
{
    sBallAffineAnimSeq0,
    sBallAffineAnimSeq1,
    sBallAffineAnimSeq2,
    sBallAffineAnimSeq3,
    sBallAffineAnimSeq4,
};

const struct SpriteTemplate gBallSpriteTemplates[POKEBALL_COUNT] =
{
    {
        .tileTag = GFX_TAG_POKE_BALL,
        .paletteTag = GFX_TAG_POKE_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_GREAT_BALL,
        .paletteTag = GFX_TAG_GREAT_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_SAFARI_BALL,
        .paletteTag = GFX_TAG_SAFARI_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_ULTRA_BALL,
        .paletteTag = GFX_TAG_ULTRA_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_MASTER_BALL,
        .paletteTag = GFX_TAG_MASTER_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_NET_BALL,
        .paletteTag = GFX_TAG_NET_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_DIVE_BALL,
        .paletteTag = GFX_TAG_DIVE_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_NEST_BALL,
        .paletteTag = GFX_TAG_NEST_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_REPEAT_BALL,
        .paletteTag = GFX_TAG_REPEAT_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_TIMER_BALL,
        .paletteTag = GFX_TAG_TIMER_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_LUXURY_BALL,
        .paletteTag = GFX_TAG_LUXURY_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
    {
        .tileTag = GFX_TAG_PREMIER_BALL,
        .paletteTag = GFX_TAG_PREMIER_BALL,
        .oam = &sBallOamData,
        .anims = sBallAnimSequences,
        .images = NULL,
        .affineAnims = sBallAffineAnimSequences,
        .callback = SpriteCB_TestBallThrow,
    },
};

// Functions
u8 DoPokeballSendOutAnimation(s16 pan, u8 kindOfThrow)
{
    u8 taskId;
    
    gDoingBattleAnim = TRUE;
    gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].ballAnimActive = TRUE;
    taskId = CreateTask(Task_DoPokeballSendOutAnim, 5);
    gTasks[taskId].tPan = pan;
    gTasks[taskId].tThrowId = kindOfThrow;
    gTasks[taskId].tBattler = gActiveBattler;
    return 0;
}

static void Task_DoPokeballSendOutAnim(u8 taskId)
{
    u16 throwCaseId;
    u8 battlerId;
    u16 itemId, ballId;
    u8 ballSpriteId;
    bool8 notSendOut = FALSE;
    s16 x, y;
    u32 gender;

    if (gTasks[taskId].tFrames == 0)
    {
        gTasks[taskId].tFrames++;
        return;
    }

    throwCaseId = gTasks[taskId].tThrowId;
    battlerId = gTasks[taskId].tBattler;

    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
        itemId = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_POKEBALL);
    else
        itemId = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_POKEBALL);

    ballId = ItemIdToBallId(itemId);
    LoadBallGfx(ballId);
    
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        gender = gLinkPlayers[GetBattlerMultiplayerId(battlerId)].gender;
    else
        gender = gSaveBlock2Ptr->playerGender;
    
    ballSpriteId = CreateSprite(&gBallSpriteTemplates[ballId], 32, 80, 29);
    gSprites[ballSpriteId].data[0] = 0x80;
    gSprites[ballSpriteId].data[1] = 0;
    gSprites[ballSpriteId].data[7] = throwCaseId;

    switch (throwCaseId)
    {
    case POKEBALL_PLAYER_SENDOUT:
        if (gBattleTypeFlags & BATTLE_TYPE_POKEDUDE)
        {
            x = 32;
            y = 64;
        }
        else
        {
            gender = !!gender; // something unknown got optimized out
            x = 48;
            y = 70;
        }

        gBattlerTarget = battlerId;
        if(!gSaveBlock2Ptr->optionsThrowAnim)
        {
            gSprites[ballSpriteId].pos1.x = x;
            gSprites[ballSpriteId].pos1.y = y;
            gSprites[ballSpriteId].callback = SpriteCB_PlayerMonSendOut_1;
            //PlaySE(SE_BALL_THROW);
        }
        else
        {
            gSprites[ballSpriteId].pos1.x = x + 24;
            gSprites[ballSpriteId].pos1.y = y + 32;
            gSprites[ballSpriteId].callback = SpriteCB_PlayerMonSendOut_0;
        }
        break;
    case POKEBALL_OPPONENT_SENDOUT:
        gBattlerTarget = battlerId;
        gSprites[ballSpriteId].data[0] = 0;
        if(!gSaveBlock2Ptr->optionsThrowAnim)
        {
#ifdef NEW_OPPONENT_SEND_MON_ANIM
            gSprites[ballSpriteId].pos1.x = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_X) + 24;
            gSprites[ballSpriteId].pos1.y = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y) - 16;
#else
            gSprites[ballSpriteId].pos1.x = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_X);
            gSprites[ballSpriteId].pos1.y = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y) + 24;
#endif
            gSprites[ballSpriteId].callback = SpriteCB_OpponentMonSendOut_1;
            //PlaySE(SE_BALL_THROW);
        }
        else
        {
            gSprites[ballSpriteId].pos1.x = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_X);
            gSprites[ballSpriteId].pos1.y = GetBattlerSpriteCoord(battlerId, BATTLER_COORD_Y) + 24;
            gSprites[ballSpriteId].callback = SpriteCB_PlayerMonSendOut_0;
        }
        break;
    default:
        gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        notSendOut = TRUE;
        break;
    }

    gSprites[ballSpriteId].sBattler = gBattlerTarget;
    if (!notSendOut)
    {
        DestroyTask(taskId);
        return;
    }

    // this will perform an unused ball throw animation
    gSprites[ballSpriteId].data[0] = 34;
    gSprites[ballSpriteId].data[2] = GetBattlerSpriteCoord(gBattlerTarget, BATTLER_COORD_X);
    gSprites[ballSpriteId].data[4] = GetBattlerSpriteCoord(gBattlerTarget, BATTLER_COORD_Y) - 16;
    gSprites[ballSpriteId].data[5] = -40;
    InitAnimArcTranslation(&gSprites[ballSpriteId]);
    gSprites[ballSpriteId].oam.affineParam = taskId;
    gTasks[taskId].tOpponentBattler = gBattlerTarget;
    gTasks[taskId].func = TaskDummy;
    PlaySE(SE_BALL_THROW);
}

static void SpriteCB_TestBallThrow(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        u16 ballId;
        u8 taskId = sprite->oam.affineParam;
        u8 opponentBattler = gTasks[taskId].tOpponentBattler;
        u8 noOfShakes = gTasks[taskId].tThrowId;

        StartSpriteAnim(sprite, 1);
        sprite->affineAnimPaused = TRUE;
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->data[5] = 0;
        ballId = ItemIdToBallId(GetBattlerPokeballItemId(opponentBattler));
        LaunchBallStarsTask(sprite->pos1.x, sprite->pos1.y - 5, 1, 0x1C, ballId);
        sprite->data[0] = LaunchBallFadeMonTask(FALSE, opponentBattler, 14, ballId);
        sprite->sBattler = opponentBattler;
        sprite->data[7] = noOfShakes;
        DestroyTask(taskId);
        sprite->callback = sub_804AC88;
    }
}

#undef tFrames
#undef tPan
#undef tThrowId
#undef tBattler
#undef tOpponentBattler

static void sub_804AC88(struct Sprite *sprite)
{
    sprite->callback = sub_804AC94;
}

static void sub_804AC94(struct Sprite *sprite)
{
    if (++sprite->data[5] == 10)
    {
        sprite->data[5] = 0;
        sprite->callback = sub_804AD00;
        StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[sprite->sBattler]], 2);
        AnimateSprite(&gSprites[gBattlerSpriteIds[sprite->sBattler]]);
        gSprites[gBattlerSpriteIds[sprite->sBattler]].data[1] = 0;
    }
}

static void sub_804AD00(struct Sprite *sprite)
{
    sprite->data[5]++;
    if (sprite->data[5] == 11)
        PlaySE(SE_BALL_TRADE);
    
    if (gSprites[gBattlerSpriteIds[sprite->sBattler]].affineAnimEnded)
    {
        StartSpriteAnim(sprite, 2);
        gSprites[gBattlerSpriteIds[sprite->sBattler]].invisible = TRUE;
        sprite->data[5] = 0;
        sprite->callback = sub_804AD98;
    }
    else
    {
        gSprites[gBattlerSpriteIds[sprite->sBattler]].data[1] += 0x60;
        gSprites[gBattlerSpriteIds[sprite->sBattler]].pos2.y = -gSprites[gBattlerSpriteIds[sprite->sBattler]].data[1] >> 8;
    }
}

static void sub_804AD98(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sprite->data[5]++;
        if (sprite->data[5] == 1)
        {
            sprite->data[3] = 0;
            sprite->data[4] = 32;
            sprite->data[5] = 0;
            sprite->pos1.y += Cos(0, 32);
            sprite->pos2.y = -Cos(0, sprite->data[4]);
            sprite->callback = sub_804ADEC;
        }
    }
}

static void sub_804ADEC(struct Sprite *sprite)
{
    bool8 r5 = FALSE;

    switch (sprite->data[3] & 0xFF)
    {
    case 0:
        sprite->pos2.y = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] += 4 + (sprite->data[3] >> 8);
        if (sprite->data[5] >= 64)
        {
            sprite->data[4] -= 10;
            sprite->data[3] += 0x101;
            if (sprite->data[3] >> 8 == 4)
                r5 = TRUE;
            switch (sprite->data[3] >> 8)
            {
            case 1:
                PlaySE(SE_BALL_BOUNCE_1);
                break;
            case 2:
                PlaySE(SE_BALL_BOUNCE_2);
                break;
            case 3:
                PlaySE(SE_BALL_BOUNCE_3);
                break;
            default:
                PlaySE(SE_BALL_BOUNCE_4);
                break;
            }
        }
        break;
    case 1:
        sprite->pos2.y = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] -= 4 + (sprite->data[3] >> 8);
        if (sprite->data[5] <= 0)
        {
            sprite->data[5] = 0;
            sprite->data[3] &= 0xFF00;
        }
        break;
    }
    if (r5)
    {
        sprite->data[3] = 0;
        sprite->pos1.y += Cos(64, 32);
        sprite->pos2.y = 0;
        if (sprite->data[7] == 0)
        {
            sprite->callback = SpriteCB_ReleaseMonFromBall;
        }
        else
        {
            sprite->callback = sub_804AEE4;
            sprite->data[4] = 1;
            sprite->data[5] = 0;
        }
    }
}

static void sub_804AEE4(struct Sprite *sprite)
{
    sprite->data[3]++;
    if (sprite->data[3] == 31)
    {
        sprite->data[3] = 0;
        sprite->affineAnimPaused = TRUE;
        StartSpriteAffineAnim(sprite, 1);
        sprite->callback = sub_804AF24;
        PlaySE(SE_BALL);
    }
}

static void sub_804AF24(struct Sprite *sprite)
{
    switch (sprite->data[3] & 0xFF)
    {
    case 0:
    case 2:
        sprite->pos2.x += sprite->data[4];
        sprite->data[5] += sprite->data[4];
        sprite->affineAnimPaused = FALSE;
        if (sprite->data[5] > 3 || sprite->data[5] < -3)
        {
            sprite->data[3]++;
            sprite->data[5] = 0;
        }
        break;
    case 1:
        sprite->data[5]++;
        if (sprite->data[5] == 1)
        {
            sprite->data[5] = 0;
            sprite->data[4] = -sprite->data[4];
            sprite->data[3]++;
            sprite->affineAnimPaused = FALSE;
            if (sprite->data[4] < 0)
                ChangeSpriteAffineAnim(sprite, 2);
            else
                ChangeSpriteAffineAnim(sprite, 1);
        }
        else
        {
            sprite->affineAnimPaused = TRUE;
        }
        break;
    case 3:
        sprite->data[3] += 0x100;
        if (sprite->data[3] >> 8 == sprite->data[7])
        {
            sprite->callback = SpriteCB_ReleaseMonFromBall;
        }
        else
        {
            if (sprite->data[7] == 4 && sprite->data[3] >> 8 == 3)
            {
                sprite->callback = sub_804B484;
                sprite->affineAnimPaused = TRUE;
            }
            else
            {
                sprite->data[3]++;
                sprite->affineAnimPaused = TRUE;
            }
        }
        break;
    case 4:
    default:
        sprite->data[5]++;
        if (sprite->data[5] == 31)
        {
            sprite->data[5] = 0;
            sprite->data[3] &= 0xFF00;
            StartSpriteAffineAnim(sprite, 3);
            if (sprite->data[4] < 0)
                StartSpriteAffineAnim(sprite, 2);
            else
                StartSpriteAffineAnim(sprite, 1);
            
            PlaySE(SE_BALL);
        }
        break;
    }
}

#define tCryTaskSpecies         data[0]
#define tCryTaskPan             data[1]
#define tCryTaskWantedCry       data[2]
#define tCryTaskMonPtr1         data[3]
#define tCryTaskMonPtr2         data[4]
#define tCryTaskFrames          data[10]
#define tCryTaskState           data[15]

static void Task_PlayCryWhenReleasedFromBall(u8 taskId)
{
    u8 state2 = gTasks[taskId].data[2];
    s8 pan = gTasks[taskId].tCryTaskPan;
    u16 species = gTasks[taskId].tCryTaskSpecies;
    struct Pokemon *mon = (void*)(u32)((u32)(gTasks[taskId].tCryTaskMonPtr1 << 0x10) | ((u16)gTasks[taskId].tCryTaskMonPtr2));

    switch (gTasks[taskId].tCryTaskState)
    {
    case 0:
    default:
        if (gTasks[taskId].data[8] < 3)
            gTasks[taskId].data[8]++;
        else
            gTasks[taskId].tCryTaskState = state2 + 1;
        break;
    case 1:
        if (ShouldPlayNormalPokeCry(mon) == TRUE)
            PlayCry3(species, pan, 0);
        else
            PlayCry3(species, pan, 11);
        
        DestroyTask(taskId);
        break;
    case 2:
        StopCryAndClearCrySongs();
        gTasks[taskId].tCryTaskFrames = 3;
        gTasks[taskId].tCryTaskState = 20;
        break;
    case 20:
        if (gTasks[taskId].tCryTaskFrames == 0)
        {
            if (ShouldPlayNormalPokeCry(mon) == TRUE)
                PlayCry4(species, pan, 1);
            else
                PlayCry4(species, pan, 12);

            DestroyTask(taskId);
        }
        else
        {
            gTasks[taskId].tCryTaskFrames--;
        }
        break;
    case 3:
        gTasks[taskId].tCryTaskFrames = 6;
        gTasks[taskId].tCryTaskState = 30;
        break;
    case 30:
        if (gTasks[taskId].tCryTaskFrames != 0)
        {
            gTasks[taskId].tCryTaskFrames--;
            break;
        }
        gTasks[taskId].tCryTaskState++;
    case 31:
        if (!IsCryPlayingOrClearCrySongs())
        {
            StopCryAndClearCrySongs();
            gTasks[taskId].tCryTaskFrames = 3;
            gTasks[taskId].tCryTaskState++;
        }
        break;
    case 32:
        if (gTasks[taskId].tCryTaskFrames != 0)
        {
            gTasks[taskId].tCryTaskFrames--;
            break;
        }
        
        if (ShouldPlayNormalPokeCry(mon) == TRUE)
            PlayCry4(species, pan, 0);
        else
            PlayCry4(species, pan, 11);

        DestroyTask(taskId);
        break;
    }
}

static void SpriteCB_ReleaseMonFromBall(struct Sprite *sprite)
{
    u8 battlerId = sprite->sBattler;
    u32 ballId;

    StartSpriteAnim(sprite, 1);
    ballId = ItemIdToBallId(GetBattlerPokeballItemId(battlerId));
    LaunchBallStarsTask(sprite->pos1.x, sprite->pos1.y - 5, 1, 0x1C, ballId);
    sprite->data[0] = LaunchBallFadeMonTask(1, sprite->sBattler, 14, ballId);
    sprite->callback = HandleBallAnimEnd;

    if (gMain.inBattle)
    {
        struct Pokemon *mon;
        u16 species;
        s8 pan;
        u16 wantedCryCase;
        u8 taskId;

        if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
        {
            mon = &gEnemyParty[gBattlerPartyIndexes[battlerId]];
            pan = 25;
        }
        else
        {
            mon = &gPlayerParty[gBattlerPartyIndexes[battlerId]];
            pan = -25;
        }

        species = GetMonData(mon, MON_DATA_SPECIES);
        if ((battlerId == GetBattlerAtPosition(B_POSITION_PLAYER_LEFT) || battlerId == GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT))
         && IsDoubleBattle() && gBattleSpritesDataPtr->animationData->healthboxSlideInStarted)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                if (IsBGMPlaying())
                    m4aMPlayStop(&gMPlayInfo_BGM);
            }
            else
            {
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 128);
            }
        }

        if (!IsDoubleBattle() || !gBattleSpritesDataPtr->animationData->healthboxSlideInStarted)
            wantedCryCase = 0;
        else if (battlerId == GetBattlerAtPosition(B_POSITION_PLAYER_LEFT) || battlerId == GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT))
            wantedCryCase = 1;
        else
            wantedCryCase = 2;
        
        taskId = CreateTask(Task_PlayCryWhenReleasedFromBall, 3);
        gTasks[taskId].tCryTaskSpecies = species;
        gTasks[taskId].tCryTaskPan = pan;
        gTasks[taskId].tCryTaskWantedCry = wantedCryCase;
        gTasks[taskId].tCryTaskMonPtr1 = (u32)(mon) >> 0x10;
        gTasks[taskId].tCryTaskMonPtr2 = (u32)(mon);
        gTasks[taskId].tCryTaskState = 0;
    }

    StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[sprite->sBattler]], 1);
    AnimateSprite(&gSprites[gBattlerSpriteIds[sprite->sBattler]]);
    gSprites[gBattlerSpriteIds[sprite->sBattler]].data[1] = 0x1000;
}

#undef tCryTaskSpecies
#undef tCryTaskPan
#undef tCryTaskWantedCry
#undef tCryTaskMonPtr1
#undef tCryTaskMonPtr2
#undef tCryTaskFrames
#undef tCryTaskState

static void sub_804B484(struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    sprite->callback = sub_804B5C8;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

static void HandleBallAnimEnd(struct Sprite *sprite)
{
    bool8 affineAnimEnded = FALSE;
    u8 battlerId = sprite->sBattler;

    gSprites[gBattlerSpriteIds[battlerId]].invisible = FALSE;
    if (sprite->animEnded)
        sprite->invisible = TRUE;
    if (gSprites[gBattlerSpriteIds[battlerId]].affineAnimEnded)
    {
        StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[battlerId]], 0);
        affineAnimEnded = TRUE;
    }
    else
    {
        gSprites[gBattlerSpriteIds[battlerId]].data[1] -= 288;
        gSprites[gBattlerSpriteIds[battlerId]].pos2.y = gSprites[gBattlerSpriteIds[battlerId]].data[1] >> 8;
    }
    if (sprite->animEnded && affineAnimEnded)
    {
        s32 i, doneBattlers;

        gSprites[gBattlerSpriteIds[battlerId]].pos2.y = 0;
        gDoingBattleAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battlerId].ballAnimActive = FALSE;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);

        for (doneBattlers = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (!gBattleSpritesDataPtr->healthBoxesData[i].ballAnimActive)
                doneBattlers++;
        }
        if (doneBattlers == MAX_BATTLERS_COUNT)
        {
            for (i = 0; i < POKEBALL_COUNT; i++)
                FreeBallGfx(i);
        }
    }
}

static void sub_804B5C8(struct Sprite *sprite)
{
    u8 battlerId = sprite->sBattler;

    sprite->data[4]++;
    if (sprite->data[4] == 40)
    {
        return;
    }
    else if (sprite->data[4] == 95)
    {
        gDoingBattleAnim = FALSE;
        m4aMPlayAllStop();
        PlaySE(MUS_CAUGHT_INTRO);
    }
    else if (sprite->data[4] == 315)
    {
        FreeOamMatrix(gSprites[gBattlerSpriteIds[sprite->sBattler]].oam.matrixNum);
        DestroySprite(&gSprites[gBattlerSpriteIds[sprite->sBattler]]);
        DestroySpriteAndFreeResources(sprite);
        if (gMain.inBattle)
            gBattleSpritesDataPtr->healthBoxesData[battlerId].ballAnimActive = FALSE;
    }
}

static void SpriteCB_PlayerMonSendOut_0(struct Sprite *sprite)
{
    sprite->data[0] = 0;
    if (IsDoubleBattle() && gBattleSpritesDataPtr->animationData->healthboxSlideInStarted
     && sprite->sBattler == GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT))
        sprite->callback = SpriteCB_ReleaseMon2FromBall;
    else
        sprite->callback = SpriteCB_ReleaseMonFromBall;
}

static void SpriteCB_PlayerMonSendOut_1(struct Sprite *sprite)
{
    sprite->data[0] = 25;
    sprite->data[2] = GetBattlerSpriteCoord(sprite->sBattler, 2);
    sprite->data[4] = GetBattlerSpriteCoord(sprite->sBattler, 3) + 24;
    sprite->data[5] = -30;
    sprite->oam.affineParam = sprite->sBattler;
    InitAnimArcTranslation(sprite);
    sprite->callback = SpriteCB_PlayerMonSendOut_2;
}

#define HIBYTE(x) (((x) >> 8) & 0xFF)

static void SpriteCB_PlayerMonSendOut_2(struct Sprite *sprite)
{
    u32 r6;
    u32 r7;

    if (HIBYTE(sprite->data[7]) >= 35 && HIBYTE(sprite->data[7]) < 80)
    {
        s16 r4;

        if ((sprite->oam.affineParam & 0xFF00) == 0)
        {
            r6 = sprite->data[1] & 1;
            r7 = sprite->data[2] & 1;
            sprite->data[1] = ((sprite->data[1] / 3) & ~1) | r6;
            sprite->data[2] = ((sprite->data[2] / 3) & ~1) | r7;
            StartSpriteAffineAnim(sprite, 4);
        }
        r4 = sprite->data[0];
        AnimTranslateLinear(sprite);
        sprite->data[7] += sprite->sBattler / 3;
        sprite->pos2.y += Sin(HIBYTE(sprite->data[7]), sprite->data[5]);
        sprite->oam.affineParam += 0x100;
        if ((sprite->oam.affineParam >> 8) % 3 != 0)
            sprite->data[0] = r4;
        else
            sprite->data[0] = r4 - 1;
        if (HIBYTE(sprite->data[7]) >= 80)
        {
            r6 = sprite->data[1] & 1;
            r7 = sprite->data[2] & 1;
            sprite->data[1] = ((sprite->data[1] * 3) & ~1) | r6;
            sprite->data[2] = ((sprite->data[2] * 3) & ~1) | r7;
        }
    }
    else
    {
        if (TranslateAnimHorizontalArc(sprite))
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.x = sprite->pos2.y = 0;
            sprite->sBattler = sprite->oam.affineParam & 0xFF;
            sprite->data[0] = 0;

            if (IsDoubleBattle() && gBattleSpritesDataPtr->animationData->healthboxSlideInStarted
             && sprite->sBattler == GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT))
                sprite->callback = SpriteCB_ReleaseMon2FromBall;
            else
                sprite->callback = SpriteCB_ReleaseMonFromBall;

            StartSpriteAffineAnim(sprite, 0);
        }
    }
}

static void SpriteCB_ReleaseMon2FromBall(struct Sprite *sprite)
{
    if (sprite->data[0]++ > 24)
    {
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_ReleaseMonFromBall;
    }
}

static void SpriteCB_OpponentMonSendOut_0(struct Sprite *sprite)
{
    sprite->data[0] = 0;
    if (IsDoubleBattle() && gBattleSpritesDataPtr->animationData->healthboxSlideInStarted
     && sprite->sBattler == GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))
        sprite->callback = SpriteCB_ReleaseMon2FromBall;
    else
        sprite->callback = SpriteCB_ReleaseMonFromBall;
}

#ifdef NEW_OPPONENT_SEND_MON_ANIM
static void SpriteCB_OpponentMonSendOut_1(struct Sprite *sprite)
{
    sprite->data[0] = 25;
    sprite->data[2] = GetBattlerSpriteCoord(sprite->sBattler, BATTLER_COORD_X);
    sprite->data[4] = GetBattlerSpriteCoord(sprite->sBattler, BATTLER_COORD_Y) + 24;
    sprite->data[5] = -30;
    sprite->oam.affineParam = sprite->sBattler;
    InitAnimArcTranslation(sprite);
    sprite->callback = SpriteCB_OpponentMonSendOut_2;
}

static void SpriteCB_OpponentMonSendOut_2(struct Sprite *sprite)
{
    u32 r6;
    u32 r7;

    if (HIBYTE(sprite->data[7]) >= 35 && HIBYTE(sprite->data[7]) < 80)
    {
        s16 r4;

        if ((sprite->oam.affineParam & 0xFF00) == 0)
        {
            r6 = sprite->data[1] & 1;
            r7 = sprite->data[2] & 1;
            sprite->data[1] = ((sprite->data[1] / 3) & ~1) | r6;
            sprite->data[2] = ((sprite->data[2] / 3) & ~1) | r7;
            StartSpriteAffineAnim(sprite, 4);
        }
        r4 = sprite->data[0];
        AnimTranslateLinear(sprite);
        sprite->data[7] += sprite->sBattler / 3;
        sprite->pos2.y += Sin(HIBYTE(sprite->data[7]), sprite->data[5]);
        sprite->oam.affineParam += 0x100;
        if ((sprite->oam.affineParam >> 8) % 3 != 0)
            sprite->data[0] = r4;
        else
            sprite->data[0] = r4 - 1;
        if (HIBYTE(sprite->data[7]) >= 80)
        {
            r6 = sprite->data[1] & 1;
            r7 = sprite->data[2] & 1;
            sprite->data[1] = ((sprite->data[1] * 3) & ~1) | r6;
            sprite->data[2] = ((sprite->data[2] * 3) & ~1) | r7;
        }
    }
    else
    {
        if (TranslateAnimHorizontalArc(sprite))
        {
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.y = 0;
            sprite->pos2.x = 0;
            sprite->sBattler = sprite->oam.affineParam & 0xFF;
            sprite->data[0] = 0;

            if (IsDoubleBattle() && gBattleSpritesDataPtr->animationData->healthboxSlideInStarted
             && sprite->sBattler == GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))
                sprite->callback = SpriteCB_ReleaseMon2FromBall;
            else
                sprite->callback = SpriteCB_ReleaseMonFromBall;

            StartSpriteAffineAnim(sprite, 0);
        }
    }
}
#else // NEW_OPPONENT_SEND_MON_ANIM
static void SpriteCB_OpponentMonSendOut_1(struct Sprite *sprite)
{
    sprite->data[0]++;
    if (sprite->data[0] > 15)
    {
        sprite->data[0] = 0;
        if (IsDoubleBattle() && gBattleSpritesDataPtr->animationData->healthboxSlideInStarted
         && sprite->sBattler == GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))
            sprite->callback = SpriteCB_ReleaseMon2FromBall;
        else
            sprite->callback = SpriteCB_ReleaseMonFromBall;
    }
}
#endif // NEW_OPPONENT_SEND_MON_ANIM

#undef sBattler

static u8 LaunchBallStarsTaskForPokeball(u8 x, u8 y, u8 kindOfStars, u8 d)
{
    return LaunchBallStarsTask(x, y, kindOfStars, d, BALL_POKE);
}

static u8 LaunchBallFadeMonTaskForPokeball(bool8 unFadeLater, u8 battlerId, u32 arg2)
{
    return LaunchBallFadeMonTask(unFadeLater, battlerId, arg2, BALL_POKE);
}

void CreatePokeballSpriteToReleaseMon(u8 monSpriteId, u8 battlerId, u8 x, u8 y, u8 oamPriority, u8 subpriortiy, u8 g, u32 h)
{
    u8 spriteId;

    LoadCompressedSpriteSheetUsingHeap(&gBallSpriteSheets[0]);
    LoadCompressedSpritePaletteUsingHeap(&gBallSpritePalettes[0]);
    spriteId = CreateSprite(&gBallSpriteTemplates[0], x, y, subpriortiy);
    gSprites[spriteId].data[0] = monSpriteId;
    gSprites[spriteId].data[5] = gSprites[monSpriteId].pos1.x;
    gSprites[spriteId].data[6] = gSprites[monSpriteId].pos1.y;
    gSprites[monSpriteId].pos1.x = x;
    gSprites[monSpriteId].pos1.y = y;
    gSprites[spriteId].data[1] = g;
    gSprites[spriteId].data[2] = battlerId;
    gSprites[spriteId].data[3] = h;
    gSprites[spriteId].data[4] = h >> 0x10;
    gSprites[spriteId].oam.priority = oamPriority;
    gSprites[spriteId].callback = sub_804B9E8;
    gSprites[monSpriteId].invisible = TRUE;
}

static void sub_804B9E8(struct Sprite *sprite)
{
    if (sprite->data[1] == 0)
    {
        u8 r5;
        u8 r7 = sprite->data[0];
        u8 battlerId = sprite->data[2];
        u32 r4 = (u16)sprite->data[3] | ((u16)sprite->data[4] << 16);

        if (sprite->subpriority != 0)
            r5 = sprite->subpriority - 1;
        else
            r5 = 0;

        StartSpriteAnim(sprite, 1);
        LaunchBallStarsTaskForPokeball(sprite->pos1.x, sprite->pos1.y - 5, sprite->oam.priority, r5);
        sprite->data[1] = LaunchBallFadeMonTaskForPokeball(1, battlerId, r4);
        sprite->callback = sub_804BAA4;
        gSprites[r7].invisible = FALSE;
        StartSpriteAffineAnim(&gSprites[r7], 1);
        AnimateSprite(&gSprites[r7]);
        gSprites[r7].data[1] = 0x1000;
        sprite->data[7] = 0;
    }
    else
    {
        sprite->data[1]--;
    }
}

static void sub_804BAA4(struct Sprite *sprite)
{
    bool8 r12 = FALSE;
    bool8 r6 = FALSE;
    u8 monSpriteId = sprite->data[0];
    u16 var1;
    u16 var2;

    if (sprite->animEnded)
        sprite->invisible = TRUE;
    
    if (gSprites[monSpriteId].affineAnimEnded)
    {
        StartSpriteAffineAnim(&gSprites[monSpriteId], 0);
        r12 = TRUE;
    }
    
    var1 = (sprite->data[5] - sprite->pos1.x) * sprite->data[7] / 128 + sprite->pos1.x;
    var2 = (sprite->data[6] - sprite->pos1.y) * sprite->data[7] / 128 + sprite->pos1.y;
    gSprites[monSpriteId].pos1.x = var1;
    gSprites[monSpriteId].pos1.y = var2;
    if (sprite->data[7] < 128)
    {
        s16 sine = -(gSineTable[(u8)sprite->data[7]] / 8);

        sprite->data[7] += 4;
        gSprites[monSpriteId].pos2.x = sine;
        gSprites[monSpriteId].pos2.y = sine;
    }
    else
    {
        gSprites[monSpriteId].pos1.x = sprite->data[5];
        gSprites[monSpriteId].pos1.y = sprite->data[6];
        gSprites[monSpriteId].pos2.x = 0;
        gSprites[monSpriteId].pos2.y = 0;
        r6 = TRUE;
    }
    
    if (sprite->animEnded && r12 && r6)
        DestroySpriteAndFreeResources(sprite);
}

u8 CreateTradePokeballSprite(u8 a, u8 b, u8 x, u8 y, u8 oamPriority, u8 subPriority, u8 g, u32 h)
{
    u8 spriteId;

    LoadCompressedSpriteSheetUsingHeap(&gBallSpriteSheets[0]);
    LoadCompressedSpritePaletteUsingHeap(&gBallSpritePalettes[0]);
    spriteId = CreateSprite(&gBallSpriteTemplates[0], x, y, subPriority);
    gSprites[spriteId].data[0] = a;
    gSprites[spriteId].data[1] = g;
    gSprites[spriteId].data[2] = b;
    gSprites[spriteId].data[3] = h;
    gSprites[spriteId].data[4] = h >> 16;
    gSprites[spriteId].oam.priority = oamPriority;
    gSprites[spriteId].callback = sub_804BC50;
    return spriteId;
}

static void sub_804BC50(struct Sprite *sprite)
{
    if (sprite->data[1] == 0)
    {
        u8 r6;
        u8 r7 = sprite->data[0];
        u8 r8 = sprite->data[2];
        u32 r5 = (u16)sprite->data[3] | ((u16)sprite->data[4] << 16);

        if (sprite->subpriority != 0)
            r6 = sprite->subpriority - 1;
        else
            r6 = 0;

        StartSpriteAnim(sprite, 1);
        LaunchBallStarsTaskForPokeball(sprite->pos1.x, sprite->pos1.y - 5, sprite->oam.priority, r6);
        sprite->data[1] = LaunchBallFadeMonTaskForPokeball(1, r8, r5);
        sprite->callback = sub_804BCF8;
        StartSpriteAffineAnim(&gSprites[r7], 2);
        AnimateSprite(&gSprites[r7]);
        gSprites[r7].data[1] = 0;
    }
    else
    {
        sprite->data[1]--;
    }
}

static void sub_804BCF8(struct Sprite *sprite)
{
    u8 r1;

    sprite->data[5]++;
    if (sprite->data[5] == 11)
        PlaySE(SE_BALL_TRADE);
    
    r1 = sprite->data[0];
    if (gSprites[r1].affineAnimEnded)
    {
        StartSpriteAnim(sprite, 2);
        gSprites[r1].invisible = TRUE;
        sprite->data[5] = 0;
        sprite->callback = sub_804BD6C;
    }
    else
    {
        gSprites[r1].data[1] += 96;
        gSprites[r1].pos2.y = -gSprites[r1].data[1] >> 8;
    }
}

static void sub_804BD6C(struct Sprite *sprite)
{
    if (sprite->animEnded)
        sprite->callback = SpriteCallbackDummy;
}

void DestroySpriteAndFreeResources2(struct Sprite *sprite)
{
    DestroySpriteAndFreeResources(sprite);
}

void StartHealthboxSlideIn(u8 battlerId)
{
    struct Sprite *healthboxSprite = &gSprites[gHealthboxSpriteIds[battlerId]];

    healthboxSprite->data[0] = 5;
    healthboxSprite->data[1] = 0;
    healthboxSprite->pos2.x = 0x73;
    healthboxSprite->pos2.y = 0;
    healthboxSprite->callback = sub_804BE48;
    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
    {
        healthboxSprite->data[0] = -healthboxSprite->data[0];
        healthboxSprite->data[1] = -healthboxSprite->data[1];
        healthboxSprite->pos2.x = -healthboxSprite->pos2.x;
        healthboxSprite->pos2.y = -healthboxSprite->pos2.y;
    }
    
    gSprites[healthboxSprite->data[5]].callback(&gSprites[healthboxSprite->data[5]]);
    if (GetBattlerPosition(battlerId) == B_POSITION_PLAYER_RIGHT)
        healthboxSprite->callback = sub_804BE24;
}

static void sub_804BE24(struct Sprite *sprite)
{
    sprite->data[1]++;
    if (sprite->data[1] == 20)
    {
        sprite->data[1] = 0;
        sprite->callback = sub_804BE48;
    }
}

static void sub_804BE48(struct Sprite *sprite)
{
    sprite->pos2.x -= sprite->data[0];
    sprite->pos2.y -= sprite->data[1];
    if (sprite->pos2.x == 0 && sprite->pos2.y == 0)
        sprite->callback = SpriteCallbackDummy;
}

void DoHitAnimHealthboxEffect(u8 battlerId)
{
    u8 spriteId;

    spriteId = CreateInvisibleSpriteWithCallback(SpriteCB_HitAnimHealthoxEffect);
    gSprites[spriteId].data[0] = 1;
    gSprites[spriteId].data[1] = gHealthboxSpriteIds[battlerId];
    gSprites[spriteId].callback = SpriteCB_HitAnimHealthoxEffect;
}

static void SpriteCB_HitAnimHealthoxEffect(struct Sprite *sprite)
{
    u8 r1 = sprite->data[1];

    gSprites[r1].pos2.y = sprite->data[0];
    sprite->data[0] = -sprite->data[0];
    sprite->data[2]++;
    if (sprite->data[2] == 21)
    {
        gSprites[r1].pos2.x = 0;
        gSprites[r1].pos2.y = 0;
        DestroySprite(sprite);
    }
}

void LoadBallGfx(u8 ballId)
{
    u16 var;

    if (GetSpriteTileStartByTag(gBallSpriteSheets[ballId].tag) == SPRITE_INVALID_TAG)
    {
        LoadCompressedSpriteSheetUsingHeap(&gBallSpriteSheets[ballId]);
        LoadCompressedSpritePaletteUsingHeap(&gBallSpritePalettes[ballId]);
    }
    
    switch (ballId)
    {
    case BALL_DIVE:
    case BALL_LUXURY:
    case BALL_PREMIER:
        break;
    default:
        var = GetSpriteTileStartByTag(gBallSpriteSheets[ballId].tag);
        LZDecompressVram(gOpenPokeballGfx, (void *)(VRAM + 0x10100 + var * 32));
        break;
    }
}

void FreeBallGfx(u8 ballId)
{
    FreeSpriteTilesByTag(gBallSpriteSheets[ballId].tag);
    FreeSpritePaletteByTag(gBallSpritePalettes[ballId].tag);
}

static u16 GetBattlerPokeballItemId(u8 battlerId)
{
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        return GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_POKEBALL);
    else
        return GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_POKEBALL);
}

