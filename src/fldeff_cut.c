#include "global.h"
#include "gflib.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "faraway_island.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_specials.h"
#include "fldeff.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "trig.h"
#include "constants/abilities.h"
#include "constants/event_objects.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

#define CUT_GRASS_SPRITE_COUNT 8
#define CUT_SIDE 3

static EWRAM_DATA u8 *sCutGrassSpriteArrayPtr = NULL;
static EWRAM_DATA bool8 sScheduleOpenDottedHole = FALSE;

static void FieldCallback_CutGrass(void);
static void FieldCallback_CutTree(void);
static void FieldMoveCallback_CutGrass(void);
static void SetCutGrassMetatileAt(s16 x, s16 y);
static void SpriteCallback_CutGrass_Init(struct Sprite * sprite);
static void SpriteCallback_CutGrass_Run(struct Sprite * sprite);
static void SpriteCallback_CutGrass_Cleanup(struct Sprite * sprite);
static void FieldMoveCallback_CutTree(void);
static void CleanupLongGrass(s16 x, s16 y);

extern const u8 FarawayIsland_Interior_EventScript_HideMewWhenGrassCut[];

static const u16 sCutGrassMetatileMapping[][2] = {
    {
        METATILE_ID(General, Plain_Grass),
        METATILE_ID(General, Plain_Mowed)
    }, {
        METATILE_ID(General, ThinTreeTop_Grass),
        METATILE_ID(General, ThinTreeTop_Mowed)
    }, {
        METATILE_ID(General, WideTreeTopLeft_Grass),
        METATILE_ID(General, WideTreeTopLeft_Mowed)
    }, {
        METATILE_ID(General, WideTreeTopRight_Grass),
        METATILE_ID(General, WideTreeTopRight_Mowed)
    }, {
        METATILE_ID(CeladonCity, CyclingRoad_Grass),
        METATILE_ID(CeladonCity, CyclingRoad_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopLeft_Grass),
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopLeft_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopMiddle_Grass),
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopMiddle_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopRight_Grass),
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopRight_Mowed)
    }, {
        METATILE_ID(ViridianForest, HugeTreeTopMiddle_Grass),
        METATILE_ID(ViridianForest, HugeTreeTopMiddle_Mowed)
    }, {
        METATILE_ID(SeviiIslands67, LongGrass_Top), //long grass top
        METATILE_ID(SeviiIslands67, EmeraldMowed) //Emerald mowed grass
    }, {
        METATILE_ID(SeviiIslands67, LongGrass_Bottom), //long grass bottom
        METATILE_ID(SeviiIslands67, EmeraldMowed) //Emerald mowed grass
    }, {
        METATILE_ID(SeviiIslands123, OneIsland_Grass), //One Island tall grass
        METATILE_ID(SeviiIslands123, OneIsland_Mowed) //One Island mowed grass
    }, {
        METATILE_ID(SeviiIslands123, OneIsland_AshGrass), //One Island tall grass
        METATILE_ID(SeviiIslands123, OneIsland_Mowed) //One Island mowed grass
    }, {
        METATILE_ID(BerryForest, ThreeIsland_Grass), //Three Island yellow grass
        METATILE_ID(General, Plain_Mowed) //Three Island yellow grass
    }, {
        METATILE_ID(SeviiIslands5, Micro_Grass),
        METATILE_ID(SeviiIslands5, Micro_Mowed)
    }, {
        METATILE_ID(SeviiIslands5, MicroWideTreeTopLeft_Grass),
        METATILE_ID(SeviiIslands5, MicroWideTreeTopLeft_Mowed)
    }, {
        METATILE_ID(SeviiIslands5, MicroWideTreeTopRight_Grass),
        METATILE_ID(SeviiIslands5, MicroWideTreeTopRight_Mowed)
    }, {    // Safari Zone Long Grass
        METATILE_ID(FuchsiaCity, LongGrassTop_LeftTree),
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopLeft_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, LongGrassTop_MiddleTree),
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopMiddle_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, LongGrassTop_RightTree),
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopRight_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, LongGrassBottom_LeftTree),
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopLeft_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, LongGrassBottom_MiddleTree),
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopMiddle_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, LongGrassBottom_RightTree),
        METATILE_ID(FuchsiaCity, SafariZoneTreeTopRight_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, LongGrassTop_MountainLeft),
        METATILE_ID(FuchsiaCity, SafariMountainTopLeft_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, LongGrassTop_MountainRight),
        METATILE_ID(FuchsiaCity, SafariMountainTopRight_Mowed)
    }, {
        METATILE_ID(FuchsiaCity, LongGrassBottom_MountainLeft),
        METATILE_ID(General, MountainCornerTopLeft | METATILE_COLLISION_MASK)
    }, {
        METATILE_ID(FuchsiaCity, LongGrassBottom_MountainRight),
        METATILE_ID(General, MountainCornerTopRight | METATILE_COLLISION_MASK)
    }, {
        METATILE_ID(SeviiIslands6, ForestTreeCorner_Left),
        METATILE_ID(SeviiIslands6, ForestTreeCorner_Left_Mowed | METATILE_COLLISION_MASK) // for some reason this calls the wrong tile
    }, {
        METATILE_ID(SeviiIslands6, ForestTreeCorner_Right),
        METATILE_ID(SeviiIslands6, ForestTreeCorner_Right_Mowed | METATILE_COLLISION_MASK)
    }, {
        METATILE_ID(SeviiIslands6, ForestTreeTop),
        METATILE_ID(SeviiIslands6, ForestTreeTop_Mowed)
    }, {
        METATILE_ID(SeviiIslands67, Grass_BottomLeftCorner),
        METATILE_ID(SeviiIslands67, BottomLeftCorner)
    }, {
        METATILE_ID(SeviiIslands67, Grass_BottomRightCorner),
        METATILE_ID(SeviiIslands67, BottomRightCorner)
    }, {
        METATILE_ID(SeviiIslands67, Grass_Down),
        METATILE_ID(SeviiIslands67, Down)
    }, {
        METATILE_ID(SeviiIslands67, Grass_InnerCornerBottomLeft),
        METATILE_ID(SeviiIslands67, InnerCornerBottomLeft)
    }, {
        METATILE_ID(SeviiIslands67, Grass_InnerCornerBottomRight),
        METATILE_ID(SeviiIslands67, InnerCornerBottomRight)
    }, {
        METATILE_ID(SeviiIslands67, Grass_InnerCornerTopLeft),
        METATILE_ID(SeviiIslands67, InnerCornerTopLeft)
    }, {
        METATILE_ID(SeviiIslands67, Grass_InnerCornerTopRight),
        METATILE_ID(SeviiIslands67, InnerCornerTopRight)
    }, {
        METATILE_ID(SeviiIslands67, Grass_InnerCornersTopRightBottomLeft),
        METATILE_ID(SeviiIslands67, InnerCornersTopRightBottomLeft)
    }, {
        METATILE_ID(SeviiIslands67, Grass_Left),
        METATILE_ID(SeviiIslands67, Left)
    }, {
        METATILE_ID(SeviiIslands67, Grass_Plain),
        METATILE_ID(SeviiIslands67, Plain)
    }, {
        METATILE_ID(SeviiIslands67, Grass_Right),
        METATILE_ID(SeviiIslands67, Right)
    }, {
        METATILE_ID(SeviiIslands67, Grass_RightInnerCornerTopLeft),
        METATILE_ID(SeviiIslands67, RightInnerCornerTopLeft)
    }, {
        METATILE_ID(SeviiIslands67, Grass_TopLeftCorner),
        METATILE_ID(SeviiIslands67, TopLeftCorner)
    }, {
        METATILE_ID(SeviiIslands67, Grass_TopRightCorner),
        METATILE_ID(SeviiIslands67, TopRightCorner)
    }, {
        METATILE_ID(SeviiIslands67, Grass_Up),
        METATILE_ID(SeviiIslands67, Up)
    }, {
        0xffff,
        0xffff
    }
};

static const struct OamData sOamData_FldEff_CutGrass = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0x001,
    .priority = 1,
    .paletteNum = 0x1,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_Fldeff_CutGrass_0[] = {
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sSpriteAnimTable_FldEff_CutGrass[] = {
    sSpriteAnim_Fldeff_CutGrass_0
};

static const struct SpriteFrameImage sSpriteFrameImages_FldEff_CutGrass[] = {
    {gUnknown_8398648, 0x20}
};

const struct SpritePalette gFldEffPalette_CutGrass[] = {
    gUnknown_8398688, 4096
};

static const struct SpriteTemplate sSpriteTemplate_FldEff_CutGrass = {
    .tileTag = 0xFFFF,
    .paletteTag = 4096,
    .oam = &sOamData_FldEff_CutGrass,
    .anims = sSpriteAnimTable_FldEff_CutGrass,
    .images = sSpriteFrameImages_FldEff_CutGrass,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_CutGrass_Init
};

static u8 MetatileAtCoordsIsGrassTile(s16 x, s16 y)
{
    return TestMetatileAttributeBit(MapGridGetMetatileAttributeAt(x, y, METATILE_ATTRIBUTE_TERRAIN), TILE_TERRAIN_GRASS);
}

bool8 SetUpFieldMove_Cut(void)
{
    s16 x, y;
    u8 i, j;
    sScheduleOpenDottedHole = FALSE;
    if (CutMoveRuinValleyCheck() == TRUE)
    {
        sScheduleOpenDottedHole = TRUE;
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_CutGrass;
        return TRUE;
    }

    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_CUT_TREE) == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_CutTree;
        return TRUE;
    }
    
    else
    {
        PlayerGetDestCoords(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    
        for (i = 0; i < CUT_SIDE; i++)
        {
            y = gPlayerFacingPosition.y - 1 + i;
            for (j = 0; j < CUT_SIDE; j++)
            {
                x = gPlayerFacingPosition.x - 1 + j;
                if (MapGridGetZCoordAt(x, y) == gPlayerFacingPosition.height)
                {
                    if (MetatileAtCoordsIsGrassTile(x, y) == TRUE)
                    {
                        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
                        gPostMenuFieldCallback = FieldCallback_CutGrass;
                        return TRUE;
                    }
                }
            }
        }
        return FALSE;
    }
}

static void FieldCallback_CutGrass(void)
{
    FieldEffectStart(FLDEFF_USE_CUT_ON_GRASS);
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
}

bool8 FldEff_UseCutOnGrass(void)
{
    u8 taskId = CreateFieldEffectShowMon();
    FLDEFF_SET_FUNC_TO_DATA(FieldMoveCallback_CutGrass);
    IncrementGameStat(GAME_STAT_USED_CUT);
    return FALSE;
}

static void FieldCallback_CutTree(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(EventScript_FldEffCut);
}

bool8 FldEff_UseCutOnTree(void)
{
    u8 taskId = CreateFieldEffectShowMon();
    FLDEFF_SET_FUNC_TO_DATA(FieldMoveCallback_CutTree);
    IncrementGameStat(GAME_STAT_USED_CUT);
    return FALSE;
}

static void FieldMoveCallback_CutGrass(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_CUT_ON_GRASS);
    if (sScheduleOpenDottedHole == TRUE)
        CutMoveOpenDottedHoleDoor();
    else
        FieldEffectStart(FLDEFF_CUT_GRASS);
}

bool8 FldEff_CutGrass(void)
{
    u8 i, j;
    s16 x, y;
    u8 cutRange;
    u8 userAbility;
    u8 TileCountFromPlayer_X;
    u8 TileCountFromPlayer_Y;
    s32 neg1;
    struct MapPosition *pos;

    i = 0;
    PlaySE(SE_M_CUT);
    PlayerGetDestCoords(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    userAbility = GetMonAbility(&gPlayerParty[GetCursorSelectionMonId()]);
    if(userAbility == ABILITY_HYPER_CUTTER)
    {
        cutRange = 5;
        TileCountFromPlayer_X = 2;
        TileCountFromPlayer_Y = 2;
    }
    else
    {
        cutRange = 3;
        TileCountFromPlayer_X = 1;
        TileCountFromPlayer_Y = 1;
    }

    for (i = 0, pos = &gPlayerFacingPosition, neg1 = 0xFFFF; i < cutRange; i++)
    {
        y = i + neg1 + pos->y;
        if(userAbility == ABILITY_HYPER_CUTTER)
        {
            y -= 1;
        }
        for (j = 0; j < cutRange; j++)
        {
            x = j + neg1 + pos->x;
            if(userAbility == ABILITY_HYPER_CUTTER)
            {
                x -= 1;
            }
            if (MapGridGetZCoordAt(x, y) == pos->height)
            {
                if (MetatileAtCoordsIsGrassTile(x, y) == TRUE)
                {
                    SetCutGrassMetatileAt(x, y);
                    EnableObjectGroundEffectsByXY(x, y);
                }
            }
        }
    }
    CleanupLongGrass(gPlayerFacingPosition.x - TileCountFromPlayer_X, gPlayerFacingPosition.y - (1 + TileCountFromPlayer_Y));
    DrawWholeMapView();
    sCutGrassSpriteArrayPtr = Alloc(CUT_GRASS_SPRITE_COUNT);
    for (i = 0; i < 8; i++)
    {
        sCutGrassSpriteArrayPtr[i] = CreateSprite(&sSpriteTemplate_FldEff_CutGrass, gSprites[gPlayerAvatar.spriteId].oam.x + 8, gSprites[gPlayerAvatar.spriteId].oam.y + 20, 0);
        gSprites[sCutGrassSpriteArrayPtr[i]].data[2] = i * (0x100 / CUT_GRASS_SPRITE_COUNT);
    }
    return FALSE;
}

static void SetCutGrassMetatileAt(s16 x, s16 y)
{
    u16 i = 0;
    u16 metatileId = MapGridGetMetatileIdAt(x, y);
    while (1)
    {
        if (sCutGrassMetatileMapping[i][0] == 0xFFFF)
            return;
        if (sCutGrassMetatileMapping[i][0] == metatileId)
        {
            MapGridSetMetatileIdAt(x, y, sCutGrassMetatileMapping[i][1]);
            break;
        }
        i++;
    }
}

static bool8 MetatileIsLongGrass(u32 metatileId, bool8 isTop)
{
    if(isTop)
    {
        switch(metatileId)
        {
            case METATILE_FuchsiaCity_LongGrassTop_LeftTree:
            case METATILE_FuchsiaCity_LongGrassTop_MiddleTree:
            case METATILE_FuchsiaCity_LongGrassTop_RightTree:
            case METATILE_FuchsiaCity_LongGrassTop_MountainLeft:
            case METATILE_FuchsiaCity_LongGrassTop_MountainRight:
            case METATILE_SeviiIslands67_LongGrass_Top:
            case METATILE_SeviiIslands6_ForestTreeTop:
                return TRUE;
            default:
                return FALSE;
        }
    }
    else
    {
        switch(metatileId)
        {
            case METATILE_FuchsiaCity_LongGrassBottom_LeftTree:
            case METATILE_FuchsiaCity_LongGrassBottom_MiddleTree:
            case METATILE_FuchsiaCity_LongGrassBottom_RightTree:
            case METATILE_FuchsiaCity_LongGrassBottom_MountainLeft:
            case METATILE_FuchsiaCity_LongGrassBottom_MountainRight:
            case METATILE_SeviiIslands67_LongGrass_Bottom:
            case METATILE_SeviiIslands6_ForestTreeCorner_Left:
            case METATILE_SeviiIslands6_ForestTreeCorner_Right:
                return TRUE;
            default:
                return FALSE;
        }
    }
}

static bool8 MetatileIsMowedLongGrass(u32 metatileId)
{
    switch(metatileId)
    {
        case METATILE_SeviiIslands67_EmeraldMowed:
        case METATILE_FuchsiaCity_SafariZoneTreeTopLeft_Mowed:
        case METATILE_FuchsiaCity_SafariZoneTreeTopMiddle_Mowed:
        case METATILE_FuchsiaCity_SafariZoneTreeTopRight_Mowed:
        case METATILE_General_MountainCornerTopLeft:
        case METATILE_General_MountainCornerTopRight:
        case METATILE_FuchsiaCity_SafariMountainTopLeft_Mowed:
        case METATILE_FuchsiaCity_SafariMountainTopRight_Mowed:
        case METATILE_SeviiIslands6_ForestTreeCorner_Left_Mowed:
        case METATILE_SeviiIslands6_ForestTreeCorner_Right_Mowed:
        case METATILE_SeviiIslands6_ForestTreeTop_Mowed:
            return TRUE;
        default:
            return FALSE;
    }
}

static u32 GetMowedMetatileBasedOnInput(u32 metatileId, bool8 isTop)
{   
    u32 i;
    if(isTop)
    {
        for(i = 0; sCutGrassMetatileMapping[i][0] != 0xFFFF; i++)
        {
            if(sCutGrassMetatileMapping[i][0] != metatileId)
                continue;
            else
                return sCutGrassMetatileMapping[i][1]; //return bottom
        }
    }
    else
    {
        for(i = 0; sCutGrassMetatileMapping[i][0] != 0xFFFF; i++)
        {
            if(sCutGrassMetatileMapping[i][1] != metatileId)
                continue;
            else
                return sCutGrassMetatileMapping[i][0]; //return top
        }
    }
    return 0x0;
}

static void CleanupLongGrass(s16 x, s16 y)
{
    u16 i = 0;
    s16 lowerY;
    u8 cutRange;
    u8 userAbility = GetMonAbility(&gPlayerParty[GetCursorSelectionMonId()]);

    if(userAbility == ABILITY_HYPER_CUTTER)
    {
        cutRange = 5;
    }
    else
    {
        cutRange = 3;
    }

    lowerY = y + cutRange;

    for (i = 0; i < cutRange; i++)
    {
        s16 currentX = x + i;
        if (MetatileIsLongGrass(MapGridGetMetatileIdAt(currentX, y), TRUE))
        {
            u16 topGrassMetatile = MapGridGetMetatileIdAt(currentX, y);
            u16 underneathTop = MapGridGetMetatileIdAt(currentX, y + 1);
            if(MetatileIsMowedLongGrass(underneathTop)) //if underneath a long grass top, set that tile to long grass bottom
                MapGridSetMetatileIdAt(currentX, y + 1, METATILE_SeviiIslands67_LongGrass_Bottom);
            //MapGridSetMetatileIdAt(currentX, y + 1, GetMowedMetatileBasedOnInput(topGrassMetatile, TRUE)); //should grab corresponding bottom to topGrassMetatile
        }
        if (MetatileIsMowedLongGrass(MapGridGetMetatileIdAt(currentX, lowerY))) //if the lowest range got cut
        {
            if (MetatileIsLongGrass(MapGridGetMetatileIdAt(currentX, lowerY + 1), FALSE)) //and the tile under that range is an orphaned bottom
                MapGridSetMetatileIdAt(currentX, lowerY + 1, GetMowedMetatileBasedOnInput(MapGridGetMetatileIdAt(currentX, lowerY + 1), TRUE));
            //MapGridSetMetatileIdAt(currentX, lowerY + 1, METATILE_SeviiIslands67_EmeraldMowed); //mow it.
        }
    }
}

static void SpriteCallback_CutGrass_Init(struct Sprite * sprite)
{
    sprite->data[0] = 8;
    sprite->data[1] = 0;
    sprite->data[3] = 0;
    sprite->callback = SpriteCallback_CutGrass_Run;
}

static void SpriteCallback_CutGrass_Run(struct Sprite * sprite)
{
    sprite->pos2.x = Sin(sprite->data[2], sprite->data[0]);
    sprite->pos2.y = Cos(sprite->data[2], sprite->data[0]);
    sprite->data[2] += 8;
    sprite->data[2] &= 0xFF;
    sprite->data[0]++;
    sprite->data[0] += sprite->data[3] >> 2;
    sprite->data[3]++;
    if (sprite->data[1] != 28)
        sprite->data[1]++;
    else
        sprite->callback = SpriteCallback_CutGrass_Cleanup;
}

static void SpriteCallback_CutGrass_Cleanup(struct Sprite * sprite)
{
    u32 i;
    for (i = 1; i < CUT_GRASS_SPRITE_COUNT; i++)
    {
        DestroySprite(&gSprites[sCutGrassSpriteArrayPtr[i]]);
    }
    FieldEffectStop(&gSprites[sCutGrassSpriteArrayPtr[0]], FLDEFF_CUT_GRASS);
    Free(sCutGrassSpriteArrayPtr);
    ClearPlayerHeldMovementAndUnfreezeObjectEvents();
    ScriptContext2_Disable();

    if (IsMewPlayingHideAndSeek() == TRUE)
        ScriptContext1_SetupScript(FarawayIsland_Interior_EventScript_HideMewWhenGrassCut);
}

static void FieldMoveCallback_CutTree(void)
{
    PlaySE(SE_M_CUT);
    FieldEffectActiveListRemove(FLDEFF_USE_CUT_ON_TREE);
    EnableBothScriptContexts();
}
