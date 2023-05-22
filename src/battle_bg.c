#include "global.h"
#include "gflib.h"
#include "battle.h"
#include "battle_bg.h"
#include "battle_message.h"
#include "decompress.h"
#include "event_data.h"
#include "graphics.h"
#include "link.h"
#include "new_menu_helpers.h"
#include "overworld.h"
#include "text_window.h"
#include "trig.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/trainer_classes.h"

#define TAG_VS_LETTERS 10000

#ifdef BATTLE_MOVE_ICONS
#define B_WIN_MOVE_TYPE_WIDTH          5
#define B_WIN_MOVE_TYPE_PALETTE_NUM    10
#define B_WIN_DUMMY_MAP_LEFT           27
#define B_WIN_DUMMY_WIDTH              2
#define B_WIN_DUMMY_HEIGHT             2
#define B_WIN_DUMMY_PALETTE_NUM        10
#else // BATTLE_MOVE_ICONS
#define B_WIN_MOVE_TYPE_WIDTH          8
#define B_WIN_MOVE_TYPE_PALETTE_NUM    5
#define B_WIN_DUMMY_MAP_LEFT           25
#define B_WIN_DUMMY_WIDTH              0
#define B_WIN_DUMMY_HEIGHT             0
#define B_WIN_DUMMY_PALETTE_NUM        5
#endif // BATTLE_MOVE_ICONS

struct BattleBackground
{
    const void *tileset;
    const void *tilemap;
    const void *entryTileset;
    const void *entryTilemap;
    const void *palette;
};

static void CB2_unused(void);
static u8 GetBattleTerrainOverride(void);

static const u8 gUnknown_824829C[] = {1, 2};

static const struct OamData gOamData_82482A0 = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0x000,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData gOamData_82482A8 = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0x040,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd gUnknown_82482B0[] = {
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd gUnknown_82482C0[] = {
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(0x18, 0x18, 0x0, 0x80),
    AFFINEANIMCMD_FRAME(0x18, 0x18, 0x0, 0x80),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const gAffineAnimTable_82482E0[] = {
    gUnknown_82482B0,
    gUnknown_82482C0
};

static const struct SpriteTemplate sVsLetter_V_SpriteTemplate = {
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &gOamData_82482A0,
    .anims = gDummySpriteAnimTable,
    .affineAnims = gAffineAnimTable_82482E0,
    .callback = SpriteCB_VsLetterDummy
};

static const struct SpriteTemplate sVsLetter_S_SpriteTemplate = {
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &gOamData_82482A8,
    .anims = gDummySpriteAnimTable,
    .affineAnims = gAffineAnimTable_82482E0,
    .callback = SpriteCB_VsLetterDummy
};

static const struct CompressedSpriteSheet sVsLettersSpriteSheet = {
    gVsLettersGfx,
    0x1000,
    TAG_VS_LETTERS
};

const struct BgTemplate gBattleBgTemplates[4] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }, {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 26,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

static const struct WindowTemplate gUnknown_8248330[] = {
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 0x090
    }, {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 35,
        .width = 14,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 0x1c0
    }, {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 35,
        .width = 12,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x190
    }, {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 55,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x300
    }, {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 55,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x310
    }, {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 57,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x320
    }, {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 57,
        .width = 8,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x330
    }, {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 55,
        .width = 3,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x290
    }, { // B_WIN_MOVE_TYPE
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 57,
        .width = B_WIN_MOVE_TYPE_WIDTH,
        .height = 2,
        .paletteNum = B_WIN_MOVE_TYPE_PALETTE_NUM,
        .baseBlock = 0x296
    }, {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 55,
        .width = 5,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x2a6
    }, { // B_WIN_DUMMY
        .bg = 0,
        .tilemapLeft = B_WIN_DUMMY_MAP_LEFT,
        .tilemapTop = 57,
        .width = B_WIN_DUMMY_WIDTH,
        .height = B_WIN_DUMMY_HEIGHT,
        .paletteNum = B_WIN_DUMMY_PALETTE_NUM,
        .baseBlock = 0x2b0
    }, {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 55,
        .width = 8,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x2b0
    }, {
        .bg = 1,
        .tilemapLeft = 19,
        .tilemapTop = 8,
        .width = 10,
        .height = 11,
        .paletteNum = 5,
        .baseBlock = 0x100
    }, {
        .bg = 2,
        .tilemapLeft = 18,
        .tilemapTop = 0,
        .width = 12,
        .height = 3,
        .paletteNum = 6,
        .baseBlock = 0x16e
    }, {
        .bg = 0,
        .tilemapLeft = 25,
        .tilemapTop = 9,
        .width = 4,
        .height = 4,
        .paletteNum = 5,
        .baseBlock = 0x100
    }, {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 7,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x020
    }, {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 7,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x040
    }, {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 7,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x020
    }, {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 7,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x040
    }, {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 7,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x060
    }, {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 7,
        .height = 2,
        .paletteNum = 5,
        .baseBlock = 0x080
    }, {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x0a0
    }, {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x0a0
    }, {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 0x0b0
    }, {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 7,
        .baseBlock = 0x090
    }, DUMMY_WIN_TEMPLATE
};

static const u32 sBattleTerrainPalette_Grass[] = INCBIN_U32("graphics/battle_terrain/grass/terrain.gbapal.lz");
static const u32 sBattleTerrainTiles_Grass[] = INCBIN_U32("graphics/battle_terrain/grass/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_Grass[] = INCBIN_U32("graphics/battle_terrain/grass/terrain.bin.lz");
static const u32 sBattleTerrainAnimTiles_Grass[] = INCBIN_U32("graphics/battle_terrain/grass/anim.4bpp.lz");
static const u32 sBattleTerrainAnimTilemap_Grass[] = INCBIN_U32("graphics/battle_terrain/grass/anim.bin.lz");

static const u32 sBattleTerrainPalette_LongGrass[] = INCBIN_U32("graphics/battle_terrain/longgrass/terrain.gbapal.lz");
static const u32 sBattleTerrainTiles_LongGrass[] = INCBIN_U32("graphics/battle_terrain/longgrass/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_LongGrass[] = INCBIN_U32("graphics/battle_terrain/longgrass/terrain.bin.lz");
static const u32 sBattleTerrainAnimTiles_LongGrass[] = INCBIN_U32("graphics/battle_terrain/longgrass/anim.4bpp.lz");
static const u32 sBattleTerrainAnimTilemap_LongGrass[] = INCBIN_U32("graphics/battle_terrain/longgrass/anim.bin.lz");

static const u32 sBattleTerrainPalette_Sand[] = INCBIN_U32("graphics/battle_terrain/sand/terrain.gbapal.lz");
static const u32 sBattleTerrainTiles_Sand[] = INCBIN_U32("graphics/battle_terrain/sand/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_Sand[] = INCBIN_U32("graphics/battle_terrain/sand/terrain.bin.lz");
static const u32 sBattleTerrainAnimTiles_Sand[] = INCBIN_U32("graphics/battle_terrain/sand/anim.4bpp.lz");
static const u32 sBattleTerrainAnimTilemap_Sand[] = INCBIN_U32("graphics/battle_terrain/sand/anim.bin.lz");

static const u32 sBattleTerrainPalette_Underwater[] = INCBIN_U32("graphics/battle_terrain/underwater/terrain.gbapal.lz");
static const u32 sBattleTerrainTiles_Underwater[] = INCBIN_U32("graphics/battle_terrain/underwater/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_Underwater[] = INCBIN_U32("graphics/battle_terrain/underwater/terrain.bin.lz");
static const u32 sBattleTerrainAnimTiles_Underwater[] = INCBIN_U32("graphics/battle_terrain/underwater/anim.4bpp.lz");
static const u32 sBattleTerrainAnimTilemap_Underwater[] = INCBIN_U32("graphics/battle_terrain/underwater/anim.bin.lz");

static const u32 sBattleTerrainPalette_Water[] = INCBIN_U32("graphics/battle_terrain/water/terrain.gbapal.lz");
static const u32 sBattleTerrainTiles_Water[] = INCBIN_U32("graphics/battle_terrain/water/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_Water[] = INCBIN_U32("graphics/battle_terrain/water/terrain.bin.lz");
static const u32 sBattleTerrainAnimTiles_Water[] = INCBIN_U32("graphics/battle_terrain/water/anim.4bpp.lz");
static const u32 sBattleTerrainAnimTilemap_Water[] = INCBIN_U32("graphics/battle_terrain/water/anim.bin.lz");

static const u32 sBattleTerrainPalette_Pond[] = INCBIN_U32("graphics/battle_terrain/pond/terrain.gbapal.lz");
static const u32 sBattleTerrainTiles_Pond[] = INCBIN_U32("graphics/battle_terrain/pond/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_Pond[] = INCBIN_U32("graphics/battle_terrain/pond/terrain.bin.lz");
static const u32 sBattleTerrainAnimTiles_Pond[] = INCBIN_U32("graphics/battle_terrain/pond/anim.4bpp.lz");
static const u32 sBattleTerrainAnimTilemap_Pond[] = INCBIN_U32("graphics/battle_terrain/pond/anim.bin.lz");

static const u32 sBattleTerrainPalette_Mountain[] = INCBIN_U32("graphics/battle_terrain/mountain/terrain.gbapal.lz");
static const u32 sBattleTerrainTiles_Mountain[] = INCBIN_U32("graphics/battle_terrain/mountain/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_Mountain[] = INCBIN_U32("graphics/battle_terrain/mountain/terrain.bin.lz");
static const u32 sBattleTerrainAnimTiles_Mountain[] = INCBIN_U32("graphics/battle_terrain/mountain/anim.4bpp.lz");
static const u32 sBattleTerrainAnimTilemap_Mountain[] = INCBIN_U32("graphics/battle_terrain/mountain/anim.bin.lz");

static const u32 sBattleTerrainPalette_Cave[] = INCBIN_U32("graphics/battle_terrain/cave/terrain.gbapal.lz");
static const u32 sBattleTerrainTiles_Cave[] = INCBIN_U32("graphics/battle_terrain/cave/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_Cave[] = INCBIN_U32("graphics/battle_terrain/cave/terrain.bin.lz");
static const u32 sBattleTerrainAnimTiles_Cave[] = INCBIN_U32("graphics/battle_terrain/cave/anim.4bpp.lz");
static const u32 sBattleTerrainAnimTilemap_Cave[] = INCBIN_U32("graphics/battle_terrain/cave/anim.bin.lz");

static const u32 sBattleTerrainPalette_Building[] = INCBIN_U32("graphics/battle_terrain/building/terrain.gbapal.lz");
static const u32 sBattleTerrainTiles_Building[] = INCBIN_U32("graphics/battle_terrain/building/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_Building[] = INCBIN_U32("graphics/battle_terrain/building/terrain.bin.lz");
static const u32 sBattleTerrainAnimTiles_Building[] = INCBIN_U32("graphics/battle_terrain/building/anim.4bpp.lz");
static const u32 sBattleTerrainAnimTilemap_Building[] = INCBIN_U32("graphics/battle_terrain/building/anim.bin.lz");

static const u32 sBattleTerrainPalette_Link[] = INCBIN_U32("graphics/battle_terrain/indoor/link.gbapal.lz");
static const u32 sBattleTerrainPalette_Gym[] = INCBIN_U32("graphics/battle_terrain/indoor/gym.gbapal.lz");
static const u32 sBattleTerrainPalette_Leader[] = INCBIN_U32("graphics/battle_terrain/indoor/leader.gbapal.lz");
static const u32 sBattleTerrainPalette_Indoor2[] = INCBIN_U32("graphics/battle_terrain/indoor/2.gbapal.lz");
static const u32 sBattleTerrainPalette_Indoor1[] = INCBIN_U32("graphics/battle_terrain/indoor/1.gbapal.lz");
static const u32 sBattleTerrainPalette_Lorelei[] = INCBIN_U32("graphics/battle_terrain/indoor/lorelei.gbapal.lz");
static const u32 sBattleTerrainPalette_Bruno[] = INCBIN_U32("graphics/battle_terrain/indoor/bruno.gbapal.lz");
static const u32 sBattleTerrainPalette_Agatha[] = INCBIN_U32("graphics/battle_terrain/indoor/agatha.gbapal.lz");
static const u32 sBattleTerrainPalette_Lance[] = INCBIN_U32("graphics/battle_terrain/indoor/lance.gbapal.lz");
static const u32 sBattleTerrainPalette_Champion[] = INCBIN_U32("graphics/battle_terrain/indoor/champion.gbapal.lz");
static const u32 sBattleTerrainPalette_Plain[] = INCBIN_U32("graphics/battle_terrain/indoor/plain.gbapal.lz");
static const u32 sBattleTerrainTiles_Indoor[] = INCBIN_U32("graphics/battle_terrain/indoor/terrain.4bpp.lz");
static const u32 sBattleTerrainTilemap_Indoor[] = INCBIN_U32("graphics/battle_terrain/indoor/terrain.bin.lz");

static const struct BattleBackground sBattleTerrainTable[] = {
    [BATTLE_TERRAIN_GRASS] =
    {
        .tileset = sBattleTerrainTiles_Grass,
        .tilemap = sBattleTerrainTilemap_Grass,
        .entryTileset = sBattleTerrainAnimTiles_Grass,
        .entryTilemap = sBattleTerrainAnimTilemap_Grass,
        .palette = sBattleTerrainPalette_Grass
    },
    [BATTLE_TERRAIN_LONG_GRASS] =
    {
        .tileset = sBattleTerrainTiles_LongGrass,
        .tilemap = sBattleTerrainTilemap_LongGrass,
        .entryTileset = sBattleTerrainAnimTiles_LongGrass,
        .entryTilemap = sBattleTerrainAnimTilemap_LongGrass,
        .palette = sBattleTerrainPalette_LongGrass
    },
    [BATTLE_TERRAIN_SAND] =
    {
        .tileset = sBattleTerrainTiles_Sand,
        .tilemap = sBattleTerrainTilemap_Sand,
        .entryTileset = sBattleTerrainAnimTiles_Sand,
        .entryTilemap = sBattleTerrainAnimTilemap_Sand,
        .palette = sBattleTerrainPalette_Sand
    },
    [BATTLE_TERRAIN_UNDERWATER] =
    {
        .tileset = sBattleTerrainTiles_Underwater,
        .tilemap = sBattleTerrainTilemap_Underwater,
        .entryTileset = sBattleTerrainAnimTiles_Underwater,
        .entryTilemap = sBattleTerrainAnimTilemap_Underwater,
        .palette = sBattleTerrainPalette_Underwater
    },
    [BATTLE_TERRAIN_WATER] =
    {
        .tileset = sBattleTerrainTiles_Water,
        .tilemap = sBattleTerrainTilemap_Water,
        .entryTileset = sBattleTerrainAnimTiles_Water,
        .entryTilemap = sBattleTerrainAnimTilemap_Water,
        .palette = sBattleTerrainPalette_Water
    },
    [BATTLE_TERRAIN_POND] =
    {
        .tileset = sBattleTerrainTiles_Pond,
        .tilemap = sBattleTerrainTilemap_Pond,
        .entryTileset = sBattleTerrainAnimTiles_Pond,
        .entryTilemap = sBattleTerrainAnimTilemap_Pond,
        .palette = sBattleTerrainPalette_Pond
    },
    [BATTLE_TERRAIN_MOUNTAIN] =
    {
        .tileset = sBattleTerrainTiles_Mountain,
        .tilemap = sBattleTerrainTilemap_Mountain,
        .entryTileset = sBattleTerrainAnimTiles_Mountain,
        .entryTilemap = sBattleTerrainAnimTilemap_Mountain,
        .palette = sBattleTerrainPalette_Mountain
    },
    [BATTLE_TERRAIN_CAVE] =
    {
        .tileset = sBattleTerrainTiles_Cave,
        .tilemap = sBattleTerrainTilemap_Cave,
        .entryTileset = sBattleTerrainAnimTiles_Cave,
        .entryTilemap = sBattleTerrainAnimTilemap_Cave,
        .palette = sBattleTerrainPalette_Cave
    },
    [BATTLE_TERRAIN_BUILDING] =
    {
        .tileset = sBattleTerrainTiles_Building,
        .tilemap = sBattleTerrainTilemap_Building,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Building
    },
    [BATTLE_TERRAIN_PLAIN] =
    {
        .tileset = sBattleTerrainTiles_Building,
        .tilemap = sBattleTerrainTilemap_Building,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Plain
    },
    [BATTLE_TERRAIN_LINK] =
    {
        .tileset = sBattleTerrainTiles_Building,
        .tilemap = sBattleTerrainTilemap_Building,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Link
    },
    [BATTLE_TERRAIN_GYM] =
    {
        .tileset = sBattleTerrainTiles_Building,
        .tilemap = sBattleTerrainTilemap_Building,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Gym
    },
    [BATTLE_TERRAIN_LEADER] =
    {
        .tileset = sBattleTerrainTiles_Building,
        .tilemap = sBattleTerrainTilemap_Building,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Leader
    },
    [BATTLE_TERRAIN_INDOOR_2] =
    {
        .tileset = sBattleTerrainTiles_Indoor,
        .tilemap = sBattleTerrainTilemap_Indoor,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Indoor2
    },
    [BATTLE_TERRAIN_INDOOR_1] =
    {
        .tileset = sBattleTerrainTiles_Indoor,
        .tilemap = sBattleTerrainTilemap_Indoor,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Indoor1
    },
    [BATTLE_TERRAIN_LORELEI] =
    {
        .tileset = sBattleTerrainTiles_Indoor,
        .tilemap = sBattleTerrainTilemap_Indoor,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Lorelei
    },
    [BATTLE_TERRAIN_BRUNO] =
    {
        .tileset = sBattleTerrainTiles_Indoor,
        .tilemap = sBattleTerrainTilemap_Indoor,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Bruno
    },
    [BATTLE_TERRAIN_AGATHA] =
    {
        .tileset = sBattleTerrainTiles_Indoor,
        .tilemap = sBattleTerrainTilemap_Indoor,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Agatha
    },
    [BATTLE_TERRAIN_LANCE] =
    {
        .tileset = sBattleTerrainTiles_Indoor,
        .tilemap = sBattleTerrainTilemap_Indoor,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Lance
    },
    [BATTLE_TERRAIN_CHAMPION] =
    {
        .tileset = sBattleTerrainTiles_Indoor,
        .tilemap = sBattleTerrainTilemap_Indoor,
        .entryTileset = sBattleTerrainAnimTiles_Building,
        .entryTilemap = sBattleTerrainAnimTilemap_Building,
        .palette = sBattleTerrainPalette_Champion
    }
};

static const struct {
    u8 mapScene;
    u8 battleTerrain;
} sMapBattleSceneMapping[] = {
    {MAP_BATTLE_SCENE_GYM,      BATTLE_TERRAIN_GYM},
    {MAP_BATTLE_SCENE_INDOOR_1, BATTLE_TERRAIN_INDOOR_1},
    {MAP_BATTLE_SCENE_INDOOR_2, BATTLE_TERRAIN_INDOOR_2},
    {MAP_BATTLE_SCENE_LORELEI,  BATTLE_TERRAIN_LORELEI},
    {MAP_BATTLE_SCENE_BRUNO,    BATTLE_TERRAIN_BRUNO},
    {MAP_BATTLE_SCENE_AGATHA,   BATTLE_TERRAIN_AGATHA},
    {MAP_BATTLE_SCENE_LANCE,    BATTLE_TERRAIN_LANCE},
    {MAP_BATTLE_SCENE_LINK,     BATTLE_TERRAIN_LINK}
};

UNUSED void CreateUnknownDebugSprite(void)
{
    u8 spriteId;

    ResetSpriteData();
    spriteId = CreateSprite(&gUnknownDebugSprite, 0, 0, 0);
    gSprites[spriteId].invisible = TRUE;
    SetMainCallback2(CB2_unused);
}

static void CB2_unused(void)
{
    AnimateSprites();
    BuildOamBuffer();
}

static u8 GetBattleTerrainByMapScene(u8 mapBattleScene)
{
    int i;
    for (i = 0; i < NELEMS(sMapBattleSceneMapping); i++)
    {
        if (mapBattleScene == sMapBattleSceneMapping[i].mapScene)
            return sMapBattleSceneMapping[i].battleTerrain;
    }
    return 9;
}

static void LoadBattleTerrainGfx(u16 terrain)
{
    if (terrain >= NELEMS(sBattleTerrainTable))
        terrain = 9;
    // Copy to bg3
    LZDecompressVram(sBattleTerrainTable[terrain].tileset, (void *)BG_CHAR_ADDR(2));
    LZDecompressVram(sBattleTerrainTable[terrain].tilemap, (void *)BG_SCREEN_ADDR(26));
    LoadCompressedPalette(sBattleTerrainTable[terrain].palette, 0x20, 0x60);
}

static void LoadBattleTerrainEntryGfx(u16 terrain)
{
    if(gSaveBlock2Ptr->optionsBattleIntroAnim) //don't do entry anim graphics if set to Fast
        return;

    if (terrain >= NELEMS(sBattleTerrainTable))
        terrain = 9;
    // Copy to bg1
    LZDecompressVram(sBattleTerrainTable[terrain].entryTileset, (void *)BG_CHAR_ADDR(1));
    LZDecompressVram(sBattleTerrainTable[terrain].entryTilemap, (void *)BG_SCREEN_ADDR(28));
}

UNUSED void GetBattleTerrainGfxPtrs(u8 terrain, const u32 **tilesPtr, const u32 **mapPtr, const u32 **palPtr)
{
    if (terrain > 9)
        terrain = 9;
    *tilesPtr = sBattleTerrainTable[terrain].tileset;
    *mapPtr = sBattleTerrainTable[terrain].tilemap;
    *palPtr = sBattleTerrainTable[terrain].palette;
}

void sub_800F324(void)
{
    ResetBgsAndClearDma3BusyFlags(FALSE);
    InitBgsFromTemplates(0, gBattleBgTemplates, NELEMS(gBattleBgTemplates));
    InitWindows(gUnknown_8248330);
    DeactivateAllTextPrinters();
}

void InitBattleBgsVideo(void)
{
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    sub_800F324();
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_OBJWIN_ON);
}

void LoadBattleMenuWindowGfx(void)
{
    TextWindow_SetUserSelectedFrame(2, 0x012, 0x10);
    TextWindow_SetUserSelectedFrame(2, 0x022, 0x10);
    gPlttBufferUnfaded[0x5C] = RGB( 9,  9,  9);
    gPlttBufferUnfaded[0x5D] = RGB( 9,  9,  9);
    gPlttBufferUnfaded[0x5E] = RGB(31, 31, 31);
    gPlttBufferUnfaded[0x5F] = RGB( 26,  26,  25);
    CpuCopy16(&gPlttBufferUnfaded[0x5C], &gPlttBufferFaded[0x5C], 8);
    if (gBattleTypeFlags & (BATTLE_TYPE_FIRST_BATTLE | BATTLE_TYPE_POKEDUDE))
    {
        Menu_LoadStdPalAt(0x70);
        TextWindow_LoadResourcesStdFrame0(0, 0x030, 0x70);
        gPlttBufferUnfaded[0x76] = RGB( 0,  0,  0);
        CpuCopy16(&gPlttBufferUnfaded[0x76], &gPlttBufferFaded[0x76], 2);
    }
}

void DrawMainBattleBackground(void)
{
    LoadBattleTerrainGfx(GetBattleTerrainOverride());
}

void LoadBattleTextboxAndBackground(void)
{
    LZDecompressVram(gBattleTextboxTiles, (void *)BG_CHAR_ADDR(0));
    CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0x000);
    CopyBgTilemapBufferToVram(0);
    LoadCompressedPalette(gBattleTextboxPalette, 0x00, 0x40);
    LoadBattleMenuWindowGfx();
    DrawMainBattleBackground();
}

static void DrawLinkBattleParticipantPokeballs(u8 taskId, u8 multiplayerId, u8 bgId, u8 destX, u8 destY)
{
    s32 i;
    u16 pokeballStatuses = 0;
    u16 tiles[6];

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gTasks[taskId].data[5] != 0)
        {
            switch (multiplayerId)
            {
            case 0:
                pokeballStatuses = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            case 2:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                pokeballStatuses = 0x3F & gTasks[taskId].data[4];
                break;
            }
        }
        else
        {
            switch (multiplayerId)
            {
            case 0:
                pokeballStatuses = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                pokeballStatuses = 0x3F & gTasks[taskId].data[4];
                break;
            case 2:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            }
        }

        for (i = 0; i < 3; i++)
            tiles[i] = ((pokeballStatuses & (3 << (i * 2))) >> (i * 2)) + 0x6001;

        CopyToBgTilemapBufferRect_ChangePalette(bgId, tiles, destX, destY, 3, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
    else
    {
        if (multiplayerId == gBattleStruct->multiplayerId)
            pokeballStatuses = gTasks[taskId].data[3];
        else
            pokeballStatuses = gTasks[taskId].data[4];

        for (i = 0; i < 6; i++)
            tiles[i] = ((pokeballStatuses & (3 << (i * 2))) >> (i * 2)) + 0x6001;

        CopyToBgTilemapBufferRect_ChangePalette(bgId, tiles, destX, destY, 6, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
}

static void DrawLinkBattleVsScreenOutcomeText(void)
{
    if (gBattleOutcome == B_OUTCOME_DREW)
    {
        BattlePutTextOnWindow(gText_Draw, 0x15);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleOutcome == B_OUTCOME_WON)
        {
            switch (gLinkPlayers[gBattleStruct->multiplayerId].id)
            {
            case 0:
                BattlePutTextOnWindow(gText_Win, 0x16);
                BattlePutTextOnWindow(gText_Loss, 0x17);
                break;
            case 1:
                BattlePutTextOnWindow(gText_Win, 0x17);
                BattlePutTextOnWindow(gText_Loss, 0x16);
                break;
            case 2:
                BattlePutTextOnWindow(gText_Win, 0x16);
                BattlePutTextOnWindow(gText_Loss, 0x17);
                break;
            case 3:
                BattlePutTextOnWindow(gText_Win, 0x17);
                BattlePutTextOnWindow(gText_Loss, 0x16);
                break;
            }
        }
        else
        {
            switch (gLinkPlayers[gBattleStruct->multiplayerId].id)
            {
            case 0:
                BattlePutTextOnWindow(gText_Win, 0x17);
                BattlePutTextOnWindow(gText_Loss, 0x16);
                break;
            case 1:
                BattlePutTextOnWindow(gText_Win, 0x16);
                BattlePutTextOnWindow(gText_Loss, 0x17);
                break;
            case 2:
                BattlePutTextOnWindow(gText_Win, 0x17);
                BattlePutTextOnWindow(gText_Loss, 0x16);
                break;
            case 3:
                BattlePutTextOnWindow(gText_Win, 0x16);
                BattlePutTextOnWindow(gText_Loss, 0x17);
                break;
            }
        }
    }
    else if (gBattleOutcome == B_OUTCOME_WON)
    {
        if (gLinkPlayers[gBattleStruct->multiplayerId].id != 0)
        {
            BattlePutTextOnWindow(gText_Win, 0x17);
            BattlePutTextOnWindow(gText_Loss, 0x16);
        }
        else
        {
            BattlePutTextOnWindow(gText_Win, 0x16);
            BattlePutTextOnWindow(gText_Loss, 0x17);
        }
    }
    else
    {
        if (gLinkPlayers[gBattleStruct->multiplayerId].id != 0)
        {
            BattlePutTextOnWindow(gText_Win, 0x16);
            BattlePutTextOnWindow(gText_Loss, 0x17);
        }
        else
        {
            BattlePutTextOnWindow(gText_Win, 0x17);
            BattlePutTextOnWindow(gText_Loss, 0x16);
        }
    }
}

void InitLinkBattleVsScreen(u8 taskId)
{
    struct LinkPlayer *linkPlayer;
    u8 *name;
    s32 i, palId;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            for (i = 0; i < MAX_BATTLERS_COUNT; i++)
            {
                name = gLinkPlayers[i].name;
                linkPlayer = &gLinkPlayers[i];

                switch (linkPlayer->id)
                {
                case 0:
                    BattlePutTextOnWindow(name, 0x11);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 1, 2, 4);
                    break;
                case 1:
                    BattlePutTextOnWindow(name, 0x12);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 2, 2, 4);
                    break;
                case 2:
                    BattlePutTextOnWindow(name, 0x13);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 1, 2, 8);
                    break;
                case 3:
                    BattlePutTextOnWindow(name, 0x14);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 2, 2, 8);
                    break;
                }
            }
        }
        else
        {
            u8 playerId = gBattleStruct->multiplayerId;
            u8 opponentId = playerId ^ BIT_SIDE;
            u8 opponentId_copy = opponentId;

            if (gLinkPlayers[playerId].id != 0)
                opponentId = playerId, playerId = opponentId_copy;

            name = gLinkPlayers[playerId].name;
            BattlePutTextOnWindow(name, 0xF);

            name = gLinkPlayers[opponentId].name;
            BattlePutTextOnWindow(name, 0x10);

            DrawLinkBattleParticipantPokeballs(taskId, playerId, 1, 2, 7);
            DrawLinkBattleParticipantPokeballs(taskId, opponentId, 2, 2, 7);
        }
        gTasks[taskId].data[0]++;
        break;
    case 1:
        palId = AllocSpritePalette(TAG_VS_LETTERS);
        gPlttBufferUnfaded[palId * 16 + 0x10F] = gPlttBufferFaded[palId * 16 + 0x10F] = RGB(31, 31, 31);
        gBattleStruct->linkBattleVsSpriteId_V = CreateSprite(&sVsLetter_V_SpriteTemplate, 108, 80, 0);
        gBattleStruct->linkBattleVsSpriteId_S = CreateSprite(&sVsLetter_S_SpriteTemplate, 132, 80, 0);
        gSprites[gBattleStruct->linkBattleVsSpriteId_V].invisible = TRUE;
        gSprites[gBattleStruct->linkBattleVsSpriteId_S].invisible = TRUE;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        if (gTasks[taskId].data[5] != 0)
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG1_Y = -36;
            gBattle_BG2_Y = -36;
        }
        else
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG1_Y = (Cos2(gTasks[taskId].data[1]) / 32) - 164;
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG2_Y = (Cos2(gTasks[taskId].data[2]) / 32) - 164;
        }

        if (gTasks[taskId].data[2] != 0)
        {
            gTasks[taskId].data[2] -= 2;
            gTasks[taskId].data[1] += 2;
        }
        else
        {
            if (gTasks[taskId].data[5] != 0)
                DrawLinkBattleVsScreenOutcomeText();

            PlaySE(SE_M_HARDEN);
            DestroyTask(taskId);
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].invisible = FALSE;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].invisible = FALSE;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].oam.tileNum += 0x40;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[0] = 0;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[0] = 1;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[1] = gSprites[gBattleStruct->linkBattleVsSpriteId_V].pos1.x;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[1] = gSprites[gBattleStruct->linkBattleVsSpriteId_S].pos1.x;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[2] = 0;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[2] = 0;
        }
        break;
    }
}

void DrawBattleEntryBackground(void)
{
    struct Trainer* sTrainers;

    if(FlagGet(FLAG_MASTER_TRAINER_BATTLE))
        sTrainers = (struct Trainer*)gMasterTrainers;
    else
        sTrainers = (struct Trainer*)gTrainers;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        LZDecompressVram(gFile_graphics_battle_transitions_vs_frame_sheet, (void*)(BG_CHAR_ADDR(1)));
        LZDecompressVram(gVsLettersGfx, (void*)(VRAM + 0x10000));
        LoadCompressedPalette(gFile_graphics_battle_transitions_vs_frame_palette, 0x60, 0x20);
        SetBgAttribute(1, BG_ATTR_SCREENSIZE, 1);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT512x256);
        CopyToBgTilemapBuffer(1, gFile_graphics_battle_transitions_vs_frame_tilemap, 0, 0);
        CopyToBgTilemapBuffer(2, gFile_graphics_battle_transitions_vs_frame_tilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        gBattle_BG1_Y = -164;
        gBattle_BG2_Y = -164;
        LoadCompressedSpriteSheetUsingHeap(&sVsLettersSpriteSheet);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_POKEDUDE)
    {
        LoadBattleTerrainEntryGfx(BATTLE_TERRAIN_GRASS);
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_TRAINER_TOWER | BATTLE_TYPE_LINK | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_EREADER_TRAINER))
    {
        LoadBattleTerrainEntryGfx(BATTLE_TERRAIN_BUILDING);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
    {
        if (gGameVersion == VERSION_FIRE_RED)
        {
            LoadBattleTerrainEntryGfx(BATTLE_TERRAIN_CAVE);
        }
        else
        {
            LoadBattleTerrainEntryGfx(BATTLE_TERRAIN_WATER);
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u8 trainerClass = sTrainers[gTrainerBattleOpponent_A].trainerClass;
            if (trainerClass == CLASS_LEADER_2)
            {
                LoadBattleTerrainEntryGfx(BATTLE_TERRAIN_BUILDING);
                return;
            }
            else if (trainerClass == CLASS_CHAMPION_2)
            {
                LoadBattleTerrainEntryGfx(BATTLE_TERRAIN_BUILDING);
                return;
            }
        }

        if (GetCurrentMapBattleScene() == MAP_BATTLE_SCENE_NORMAL)
        {
            LoadBattleTerrainEntryGfx(gBattleTerrain);
        }
        else
        {
            LoadBattleTerrainEntryGfx(BATTLE_TERRAIN_BUILDING);
        }
    }
}

static u8 GetBattleTerrainOverride(void)
{
    u8 battleScene;
    struct Trainer* sTrainers;

    if(FlagGet(FLAG_MASTER_TRAINER_BATTLE))
        sTrainers = (struct Trainer*)gMasterTrainers;
    else
        sTrainers = (struct Trainer*)gTrainers;

    if (gBattleTypeFlags & (BATTLE_TYPE_TRAINER_TOWER | BATTLE_TYPE_LINK | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_EREADER_TRAINER))
    {
        return BATTLE_TERRAIN_LINK;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_POKEDUDE)
    {
        gBattleTerrain = BATTLE_TERRAIN_GRASS;
        return BATTLE_TERRAIN_GRASS;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        if (sTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_LEADER_2)
        {
            return BATTLE_TERRAIN_LEADER;
        }
        else if (sTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_CHAMPION_2)
        {
            return BATTLE_TERRAIN_CHAMPION;
        }
    }
    battleScene = GetCurrentMapBattleScene();
    if (battleScene == MAP_BATTLE_SCENE_NORMAL)
    {
        return gBattleTerrain;
    }
    return GetBattleTerrainByMapScene(battleScene);
}

bool8 LoadChosenBattleElement(u8 caseId)
{
    bool8 ret = FALSE;
    u8 battleScene;
    switch (caseId)
    {
    case 0:
        LZDecompressVram(gBattleTextboxTiles, (void *)BG_CHAR_ADDR(0));
        break;
    case 1:
        CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0x000);
        CopyBgTilemapBufferToVram(0);
        break;
    case 2:
        LoadCompressedPalette(gBattleTextboxPalette, 0x00, 0x40);
        break;
    case 3:
        battleScene = GetBattleTerrainOverride();
        LZDecompressVram(sBattleTerrainTable[battleScene].tileset, (void *)BG_CHAR_ADDR(2));
        // fallthrough
    case 4:
        battleScene = GetBattleTerrainOverride();
        LZDecompressVram(sBattleTerrainTable[battleScene].tilemap, (void *)BG_SCREEN_ADDR(26));
        break;
    case 5:
        battleScene = GetBattleTerrainOverride();
        LoadCompressedPalette(sBattleTerrainTable[battleScene].palette, 0x20, 0x60);
        break;
    case 6:
        LoadBattleMenuWindowGfx();
        break;
    default:
        ret = TRUE;
        break;
    }
    return ret;
}
