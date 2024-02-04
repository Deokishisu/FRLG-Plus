#include "global.h"
#include "gflib.h"
#include "berry.h"
#include "decompress.h"
#include "graphics.h"
#include "item_menu_icons.h"
#include "menu_helpers.h"
#include "constants/items.h"

enum {
    TAG_BAG = 100,
    TAG_SWAP_LINE,
    TAG_ITEM_ICON,
    TAG_ITEM_ICON_ALT,
};

#define TAG_BERRY_CHECK_CIRCLE_GFX 10000
#define TAG_BERRY_PIC_PAL 30020

struct CompressedTilesPal
{
    const u32 *tiles;
    const u32 *pal;
};

#define NUM_SWAP_LINE_SPRITES 9

// Indexes for sItemMenuIconSpriteIds
enum {
    SPR_BAG,
    SPR_SWAP_LINE_START,
    SPR_ITEM_ICON = SPR_SWAP_LINE_START + NUM_SWAP_LINE_SPRITES,
    SPR_ITEM_ICON_ALT,
    SPR_COUNT
};

enum {
    ANIM_SWAP_LINE_START,
    ANIM_SWAP_LINE_MID,
    ANIM_SWAP_LINE_END,
};

enum {
    AFFINEANIM_BAG_IDLE,
    AFFINEANIM_BAG_SHAKE,
};

static EWRAM_DATA u8 sItemMenuIconSpriteIds[SPR_COUNT] = {0};
static EWRAM_DATA void *sItemIconTilesBuffer = NULL;
static EWRAM_DATA void *sItemIconTilesBufferPadded = NULL;

static void SpriteCB_BagVisualSwitchingPockets(struct Sprite *sprite);
static void SpriteCB_ShakeBagSprite(struct Sprite *sprite);

static const struct OamData sOamData_Bag = {
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1,
    .paletteNum = 0
};

static const union AnimCmd sAnim_Bag_OpenPokeBallsPocket[] = {
    ANIMCMD_FRAME(   0, 5),
    ANIMCMD_FRAME(0x40, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Bag_OpenItemsPocket[] = {
    ANIMCMD_FRAME(   0, 5),
    ANIMCMD_FRAME(0x80, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Bag_OpenKeyItemsPocket[] = {
    ANIMCMD_FRAME(   0, 5),
    ANIMCMD_FRAME(0xc0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Bag_OpenMedicinePocket[] = {
    ANIMCMD_FRAME(   0, 5),
    ANIMCMD_FRAME(0x100, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Bag_OpenHeldItemsPocket[] = {
    ANIMCMD_FRAME(   0, 5),
    ANIMCMD_FRAME(0x140, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Bag[] = {
    [POCKET_ITEMS - 1]      = sAnim_Bag_OpenItemsPocket,
    [POCKET_MEDICINE - 1]   = sAnim_Bag_OpenMedicinePocket,
    [POCKET_KEY_ITEMS - 1]  = sAnim_Bag_OpenKeyItemsPocket,
    [POCKET_HELD_ITEMS - 1] = sAnim_Bag_OpenHeldItemsPocket,
    [POCKET_POKE_BALLS - 1] = sAnim_Bag_OpenPokeBallsPocket,
};

static const union AffineAnimCmd sAffineAnim_BagIdle[] = {
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_BagShake[] = {
    AFFINEANIMCMD_FRAME(0, 0, -2, 2),
    AFFINEANIMCMD_FRAME(0, 0,  2, 4),
    AFFINEANIMCMD_FRAME(0, 0, -2, 4),
    AFFINEANIMCMD_FRAME(0, 0,  2, 2),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnimTable_Bag[] = {
    [AFFINEANIM_BAG_IDLE]  = sAffineAnim_BagIdle,
    [AFFINEANIM_BAG_SHAKE] = sAffineAnim_BagShake
};

const struct CompressedSpriteSheet gSpriteSheet_BagMale = {
    .data = gBagMale_Gfx,
    .size = 0x3000,
    .tag = TAG_BAG
};

const struct CompressedSpriteSheet gSpriteSheet_BagFemale = {
    .data = gBagFemale_Gfx,
    .size = 0x3000,
    .tag = TAG_BAG
};

const struct CompressedSpritePalette gSpritePalette_Bag = {
    .data = gBag_Pal,
    .tag = TAG_BAG
};

static const struct SpriteTemplate sSpriteTemplate_Bag = {
    .tileTag = TAG_BAG,
    .paletteTag = TAG_BAG,
    .oam = &sOamData_Bag,
    .anims = sAnims_Bag,
    .images = NULL,
    .affineAnims = sAffineAnimTable_Bag,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_SwapLine = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
    .paletteNum = 1
};

static const union AnimCmd sAnim_SwapLine_Start[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_SwapLine_Mid[] = {
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_SwapLine_End[] = {
    ANIMCMD_FRAME(0, 0, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_SwapLine[] = {
    [ANIM_SWAP_LINE_START] = sAnim_SwapLine_Start,
    [ANIM_SWAP_LINE_MID]   = sAnim_SwapLine_Mid,
    [ANIM_SWAP_LINE_END]   = sAnim_SwapLine_End
};

const struct CompressedSpriteSheet gBagSwapSpriteSheet = {
    .data = gSwapLine_Gfx,
    .size = 0x100,
    .tag = TAG_SWAP_LINE
};

const struct CompressedSpritePalette gBagSwapSpritePalette = {
    .data = gSwapLine_Pal,
    .tag = TAG_SWAP_LINE
};

static const struct SpriteTemplate sSpriteTemplate_SwapLine = {
    .tileTag = TAG_SWAP_LINE,
    .paletteTag = TAG_SWAP_LINE,
    .oam = &sOamData_SwapLine,
    .anims = sAnims_SwapLine,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_ItemIcon = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
    .paletteNum = 2
};

static const union AnimCmd sAnim_ItemIcon[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ItemIcon[] = {
    sAnim_ItemIcon
};

static const struct SpriteTemplate sSpriteTemplate_ItemIcon = {
    .tileTag = TAG_ITEM_ICON,
    .paletteTag = TAG_ITEM_ICON,
    .oam = &sOamData_ItemIcon,
    .anims = sAnims_ItemIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sBerryPicOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 7,
    .affineParam = 0
};

static const struct OamData sBerryPicRotatingOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 7,
    .affineParam = 0
};

static const union AnimCmd sAnim_BerryPic[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sBerryPicSpriteAnimTable[] =
{
    sAnim_BerryPic
};

static const struct SpriteFrameImage sBerryPicSpriteImageTable[] =
{
    {&gDecompressionBuffer[0], 0x800},
};

static const struct SpriteTemplate sBerryPicSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicOamData,
    .anims = sBerryPicSpriteAnimTable,
    .images = sBerryPicSpriteImageTable,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AffineAnimCmd sSpriteAffineAnim_BerryPicRotation1[] =
{
    AFFINEANIMCMD_FRAME(-1, -1, 253, 96),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(-2, -2, 255, 64),
    AFFINEANIMCMD_FRAME(-8, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -8, 0, 16),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd sSpriteAffineAnim_BerryPicRotation2[] =
{
    AFFINEANIMCMD_FRAME(-1, -1, 3, 96),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(-2, -2, 1, 64),
    AFFINEANIMCMD_FRAME(-8, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -8, 0, 16),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sBerryPicRotatingAnimCmds[] =
{
    sSpriteAffineAnim_BerryPicRotation1,
    sSpriteAffineAnim_BerryPicRotation2
};

static const struct SpriteTemplate sBerryPicRotatingSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicRotatingOamData,
    .anims = sBerryPicSpriteAnimTable,
    .images = sBerryPicSpriteImageTable,
    .affineAnims = sBerryPicRotatingAnimCmds,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedTilesPal sBerryPicTable[] =
{
    [ITEM_TO_BERRY(ITEM_CHERI_BERRY)  - 1] = {gBerryPic_Cheri,  gBerryPalette_Cheri},
    [ITEM_TO_BERRY(ITEM_CHESTO_BERRY) - 1] = {gBerryPic_Chesto, gBerryPalette_Chesto},
    [ITEM_TO_BERRY(ITEM_PECHA_BERRY)  - 1] = {gBerryPic_Pecha,  gBerryPalette_Pecha},
    [ITEM_TO_BERRY(ITEM_RAWST_BERRY)  - 1] = {gBerryPic_Rawst,  gBerryPalette_Rawst},
    [ITEM_TO_BERRY(ITEM_ASPEAR_BERRY) - 1] = {gBerryPic_Aspear, gBerryPalette_Aspear},
    [ITEM_TO_BERRY(ITEM_LEPPA_BERRY)  - 1] = {gBerryPic_Leppa,  gBerryPalette_Leppa},
    [ITEM_TO_BERRY(ITEM_ORAN_BERRY)   - 1] = {gBerryPic_Oran,   gBerryPalette_Oran},
    [ITEM_TO_BERRY(ITEM_PERSIM_BERRY) - 1] = {gBerryPic_Persim, gBerryPalette_Persim},
    [ITEM_TO_BERRY(ITEM_LUM_BERRY)    - 1] = {gBerryPic_Lum,    gBerryPalette_Lum},
    [ITEM_TO_BERRY(ITEM_SITRUS_BERRY) - 1] = {gBerryPic_Sitrus, gBerryPalette_Sitrus},
    [ITEM_TO_BERRY(ITEM_FIGY_BERRY)   - 1] = {gBerryPic_Figy,   gBerryPalette_Figy},
    [ITEM_TO_BERRY(ITEM_WIKI_BERRY)   - 1] = {gBerryPic_Wiki,   gBerryPalette_Wiki},
    [ITEM_TO_BERRY(ITEM_MAGO_BERRY)   - 1] = {gBerryPic_Mago,   gBerryPalette_Mago},
    [ITEM_TO_BERRY(ITEM_AGUAV_BERRY)  - 1] = {gBerryPic_Aguav,  gBerryPalette_Aguav},
    [ITEM_TO_BERRY(ITEM_IAPAPA_BERRY) - 1] = {gBerryPic_Iapapa, gBerryPalette_Iapapa},
    [ITEM_TO_BERRY(ITEM_RAZZ_BERRY)   - 1] = {gBerryPic_Razz,   gBerryPalette_Razz},
    [ITEM_TO_BERRY(ITEM_BLUK_BERRY)   - 1] = {gBerryPic_Bluk,   gBerryPalette_Bluk},
    [ITEM_TO_BERRY(ITEM_NANAB_BERRY)  - 1] = {gBerryPic_Nanab,  gBerryPalette_Nanab},
    [ITEM_TO_BERRY(ITEM_WEPEAR_BERRY) - 1] = {gBerryPic_Wepear, gBerryPalette_Wepear},
    [ITEM_TO_BERRY(ITEM_PINAP_BERRY)  - 1] = {gBerryPic_Pinap,  gBerryPalette_Pinap},
    [ITEM_TO_BERRY(ITEM_POMEG_BERRY)  - 1] = {gBerryPic_Pomeg,  gBerryPalette_Pomeg},
    [ITEM_TO_BERRY(ITEM_KELPSY_BERRY) - 1] = {gBerryPic_Kelpsy, gBerryPalette_Kelpsy},
    [ITEM_TO_BERRY(ITEM_QUALOT_BERRY) - 1] = {gBerryPic_Qualot, gBerryPalette_Qualot},
    [ITEM_TO_BERRY(ITEM_HONDEW_BERRY) - 1] = {gBerryPic_Hondew, gBerryPalette_Hondew},
    [ITEM_TO_BERRY(ITEM_GREPA_BERRY)  - 1] = {gBerryPic_Grepa,  gBerryPalette_Grepa},
    [ITEM_TO_BERRY(ITEM_TAMATO_BERRY) - 1] = {gBerryPic_Tamato, gBerryPalette_Tamato},
    [ITEM_TO_BERRY(ITEM_CORNN_BERRY)  - 1] = {gBerryPic_Cornn,  gBerryPalette_Cornn},
    [ITEM_TO_BERRY(ITEM_MAGOST_BERRY) - 1] = {gBerryPic_Magost, gBerryPalette_Magost},
    [ITEM_TO_BERRY(ITEM_RABUTA_BERRY) - 1] = {gBerryPic_Rabuta, gBerryPalette_Rabuta},
    [ITEM_TO_BERRY(ITEM_NOMEL_BERRY)  - 1] = {gBerryPic_Nomel,  gBerryPalette_Nomel},
    [ITEM_TO_BERRY(ITEM_SPELON_BERRY) - 1] = {gBerryPic_Spelon, gBerryPalette_Spelon},
    [ITEM_TO_BERRY(ITEM_PAMTRE_BERRY) - 1] = {gBerryPic_Pamtre, gBerryPalette_Pamtre},
    [ITEM_TO_BERRY(ITEM_WATMEL_BERRY) - 1] = {gBerryPic_Watmel, gBerryPalette_Watmel},
    [ITEM_TO_BERRY(ITEM_DURIN_BERRY)  - 1] = {gBerryPic_Durin,  gBerryPalette_Durin},
    [ITEM_TO_BERRY(ITEM_BELUE_BERRY)  - 1] = {gBerryPic_Belue,  gBerryPalette_Belue},
    [ITEM_TO_BERRY(ITEM_LIECHI_BERRY) - 1] = {gBerryPic_Liechi, gBerryPalette_Liechi},
    [ITEM_TO_BERRY(ITEM_GANLON_BERRY) - 1] = {gBerryPic_Ganlon, gBerryPalette_Ganlon},
    [ITEM_TO_BERRY(ITEM_SALAC_BERRY)  - 1] = {gBerryPic_Salac,  gBerryPalette_Salac},
    [ITEM_TO_BERRY(ITEM_PETAYA_BERRY) - 1] = {gBerryPic_Petaya, gBerryPalette_Petaya},
    [ITEM_TO_BERRY(ITEM_APICOT_BERRY) - 1] = {gBerryPic_Apicot, gBerryPalette_Apicot},
    [ITEM_TO_BERRY(ITEM_LANSAT_BERRY) - 1] = {gBerryPic_Lansat, gBerryPalette_Lansat},
    [ITEM_TO_BERRY(ITEM_STARF_BERRY)  - 1] = {gBerryPic_Starf,  gBerryPalette_Starf},
    [ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) - 1] = {gBerryPic_Enigma, gBerryPalette_Enigma},
};

const struct CompressedSpriteSheet gBerryCheckCircleSpriteSheet =
{
    gBerryCheckCircle_Gfx, 0x800, TAG_BERRY_CHECK_CIRCLE_GFX
};

const struct CompressedSpritePalette gBerryCheckCirclePaletteTable =
{
    gBerryCheck_Pal, TAG_BERRY_CHECK_CIRCLE_GFX
};

static const struct OamData sBerryCheckCircleOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_BerryCheckCircle[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sBerryCheckCircleSpriteAnimTable[] =
{
    sSpriteAnim_BerryCheckCircle
};

static const struct SpriteTemplate sBerryCheckCircleSpriteTemplate =
{
    .tileTag = TAG_BERRY_CHECK_CIRCLE_GFX,
    .paletteTag = TAG_BERRY_CHECK_CIRCLE_GFX,
    .oam = &sBerryCheckCircleOamData,
    .anims = sBerryCheckCircleSpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

#include "data/item_icon_table.h"

void ResetItemMenuIconState(void)
{
    u32 i;

    for (i = 0; i < SPR_COUNT; i++)
        sItemMenuIconSpriteIds[i] = SPRITE_NONE;
}

void CreateBagSprite(u8 animNum)
{
    sItemMenuIconSpriteIds[SPR_BAG] = CreateSprite(&sSpriteTemplate_Bag, 40, 68, 0);
    SetBagVisualPocketId(animNum);
}

void SetBagVisualPocketId(u8 animNum)
{
    struct Sprite *sprite = &gSprites[sItemMenuIconSpriteIds[SPR_BAG]];
    sprite->y2 = -5;
    sprite->callback = SpriteCB_BagVisualSwitchingPockets;
    StartSpriteAnim(sprite, animNum);
}

static void SpriteCB_BagVisualSwitchingPockets(struct Sprite *sprite)
{
    if (sprite->y2 != 0)
        sprite->y2++;
    else
        sprite->callback = SpriteCallbackDummy;
}

void ShakeBagSprite(void)
{
    struct Sprite *sprite = &gSprites[sItemMenuIconSpriteIds[SPR_BAG]];
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, AFFINEANIM_BAG_SHAKE);
        sprite->callback = SpriteCB_ShakeBagSprite;
    }
}

static void SpriteCB_ShakeBagSprite(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, AFFINEANIM_BAG_IDLE);
        sprite->callback = SpriteCallbackDummy;
    }
}

void CreateSwapLine(void)
{
    u32 i;
    u8 * spriteIds = &sItemMenuIconSpriteIds[SPR_SWAP_LINE_START];

    for (i = 0; i < NUM_SWAP_LINE_SPRITES; i++)
    {
        spriteIds[i] = CreateSprite(&sSpriteTemplate_SwapLine, i * 16 + 96, 7, 0);
        switch (i)
        {
        case 0:
            // ANIM_SWAP_LINE_START, by default
            break;
        case NUM_SWAP_LINE_SPRITES - 1:
            StartSpriteAnim(&gSprites[spriteIds[i]], ANIM_SWAP_LINE_END);
            break;
        default:
            StartSpriteAnim(&gSprites[spriteIds[i]], ANIM_SWAP_LINE_MID);
            break;
        }
        gSprites[spriteIds[i]].invisible = TRUE;
    }
}

void SetSwapLineInvisibility(bool8 invisible)
{
    u32 i;
    u8 * spriteIds = &sItemMenuIconSpriteIds[SPR_SWAP_LINE_START];

    for (i = 0; i < NUM_SWAP_LINE_SPRITES; i++)
        gSprites[spriteIds[i]].invisible = invisible;
}

void UpdateSwapLinePos(s16 x, u16 y)
{
    u32 i;
    u8 * spriteIds = &sItemMenuIconSpriteIds[SPR_SWAP_LINE_START];

    for (i = 0; i < NUM_SWAP_LINE_SPRITES; i++)
    {
        gSprites[spriteIds[i]].x2 = x;
        gSprites[spriteIds[i]].y = y + 7;
    }
}

static bool8 TryAllocItemIconTilesBuffers(void)
{
    void ** ptr1, ** ptr2;

    ptr1 = &sItemIconTilesBuffer;
    *ptr1 = Alloc(0x120);
    if (*ptr1 == NULL)
        return FALSE;
    ptr2 = &sItemIconTilesBufferPadded;
    *ptr2 = AllocZeroed(0x200);
    if (*ptr2 == NULL)
    {
        Free(*ptr1);
        return FALSE;
    }
    return TRUE;
}

void CopyItemIconPicTo4x4Buffer(const void *src, void *dest)
{
    u32 i;

    for (i = 0; i < 3; i++)
        CpuCopy16(src + 0x60 * i, dest + 0x80 * i, 0x60);
}

u8 AddItemIconObject(u16 tilesTag, u16 paletteTag, u16 itemId)
{
    struct SpriteTemplate template;
    struct SpriteSheet spriteSheet;
    struct CompressedSpritePalette spritePalette;
    u8 spriteId;

    if (!TryAllocItemIconTilesBuffers())
        return MAX_SPRITES;

    LZDecompressWram(GetItemIconGfxPtr(itemId, ITEMICON_TILES), sItemIconTilesBuffer);
    CopyItemIconPicTo4x4Buffer(sItemIconTilesBuffer, sItemIconTilesBufferPadded);
    spriteSheet.data = sItemIconTilesBufferPadded;
    spriteSheet.size = 0x200;
    spriteSheet.tag = tilesTag;
    LoadSpriteSheet(&spriteSheet);

    spritePalette.data = GetItemIconGfxPtr(itemId, ITEMICON_PAL);
    spritePalette.tag = paletteTag;
    LoadCompressedSpritePalette(&spritePalette);

    CpuCopy16(&sSpriteTemplate_ItemIcon, &template, sizeof(struct SpriteTemplate));
    template.tileTag = tilesTag;
    template.paletteTag = paletteTag;
    spriteId = CreateSprite(&template, 0, 0, 0);

    Free(sItemIconTilesBuffer);
    Free(sItemIconTilesBufferPadded);
    return spriteId;
}

u8 AddItemIconObjectWithCustomObjectTemplate(const struct SpriteTemplate * origTemplate, u16 tilesTag, u16 paletteTag, u16 itemId)
{
    struct SpriteTemplate template;
    struct SpriteSheet spriteSheet;
    struct CompressedSpritePalette spritePalette;
    u8 spriteId;

    if (!TryAllocItemIconTilesBuffers())
        return MAX_SPRITES;

    LZDecompressWram(GetItemIconGfxPtr(itemId, ITEMICON_TILES), sItemIconTilesBuffer);
    CopyItemIconPicTo4x4Buffer(sItemIconTilesBuffer, sItemIconTilesBufferPadded);
    spriteSheet.data = sItemIconTilesBufferPadded;
    spriteSheet.size = 0x200;
    spriteSheet.tag = tilesTag;
    LoadSpriteSheet(&spriteSheet);

    spritePalette.data = GetItemIconGfxPtr(itemId, ITEMICON_PAL);
    spritePalette.tag = paletteTag;
    LoadCompressedSpritePalette(&spritePalette);

    CpuCopy16(origTemplate, &template, sizeof(struct SpriteTemplate));
    template.tileTag = tilesTag;
    template.paletteTag = paletteTag;
    spriteId = CreateSprite(&template, 0, 0, 0);

    Free(sItemIconTilesBuffer);
    Free(sItemIconTilesBufferPadded);
    return spriteId;
}

void CreateItemMenuIcon(u16 itemId, u8 idx)
{
    u8 * spriteIds = &sItemMenuIconSpriteIds[SPR_ITEM_ICON];
    u8 spriteId;

    if (spriteIds[idx] == SPRITE_NONE)
    {
        // Either TAG_ITEM_ICON or TAG_ITEM_ICON_ALT
        FreeSpriteTilesByTag(TAG_ITEM_ICON + idx);
        FreeSpritePaletteByTag(TAG_ITEM_ICON + idx);
        spriteId = AddItemIconObject(TAG_ITEM_ICON + idx, TAG_ITEM_ICON + idx, itemId);
        if (spriteId != MAX_SPRITES)
        {
            spriteIds[idx] = spriteId;
            gSprites[spriteId].x2 = 24;
            gSprites[spriteId].y2 = 140;
        }
    }
}

void DestroyItemMenuIcon(u8 idx)
{
    u8 * spriteIds = &sItemMenuIconSpriteIds[SPR_ITEM_ICON];

    if (spriteIds[idx] != SPRITE_NONE)
    {
        DestroySpriteAndFreeResources(&gSprites[spriteIds[idx]]);
        spriteIds[idx] = SPRITE_NONE;
    }
}

// attrId is either ITEMICON_TILES or ITEMICON_PAL
const u32 *GetItemIconGfxPtr(u16 itemId, u8 attrId)
{
    if (itemId > ITEMS_COUNT)
        itemId = ITEM_NONE;
    return sItemIconTable[itemId][attrId];
}

void CreateBerryPouchItemIcon(u16 itemId, u8 idx)
{
    u8 * spriteIds = &sItemMenuIconSpriteIds[SPR_ITEM_ICON];
    u8 spriteId;

    if (spriteIds[idx] == SPRITE_NONE)
    {
        // Either TAG_ITEM_ICON or TAG_ITEM_ICON_ALT
        FreeSpriteTilesByTag(TAG_ITEM_ICON + idx);
        FreeSpritePaletteByTag(TAG_ITEM_ICON + idx);
        spriteId = AddItemIconObject(TAG_ITEM_ICON + idx, TAG_ITEM_ICON + idx, itemId);
        if (spriteId != MAX_SPRITES)
        {
            spriteIds[idx] = spriteId;
            gSprites[spriteId].x2 = 24;
            gSprites[spriteId].y2 = 147; // This value is the only difference from CreateItemMenuIcon
        }
    }
}

void LoadListMenuSwapLineGfx(void)
{
    LoadCompressedSpriteSheet(&gBagSwapSpriteSheet);
    LoadCompressedSpritePalette(&gBagSwapSpritePalette);
}

void CreateSwapLineSprites(u8 *spriteIds, u8 count)
{
    u32 i;

    for (i = 0; i < count; i++)
    {
        spriteIds[i] = CreateSprite(&sSpriteTemplate_SwapLine, i * 16, 0, 0);
        if (i != 0)
            StartSpriteAnim(&gSprites[spriteIds[i]], 1);

        gSprites[spriteIds[i]].invisible = TRUE;
    }
}

void SetSwapLineSpritesInvisibility(u8 *spriteIds, u8 count, bool8 invisible)
{
    u32 i;

    for (i = 0; i < count; i++)
        gSprites[spriteIds[i]].invisible = invisible;
}

void UpdateSwapLineSpritesPos(u8 *spriteIds, u8 count, s16 x, u16 y)
{
    u8 i;
    bool8 hasMargin = count & SWAP_LINE_HAS_MARGIN;
    count &= ~SWAP_LINE_HAS_MARGIN;

    for (i = 0; i < count; i++)
    {
        // If the list menu has a right margin, the swap line
        // shouldn't extend all the way to the edge of the screen.
        // If this is the last sprite in the line, move it a bit
        // to the left to keep it out of the margin.
        if (i == count - 1 && hasMargin)
            gSprites[spriteIds[i]].x2 = x - 8;
        else
            gSprites[spriteIds[i]].x2 = x;

        gSprites[spriteIds[i]].y = 1 + y;
    }
}

static void ArrangeBerryGfx(void *src, void *dest)
{
    u8 i, j;

    memset(dest, 0, 0x800);

    // Create top margin
    dest += 0x100;

    for (i = 0; i < 6; i++)
    {
        // Create left margin
        dest += 0x20;

        // Copy one row of berry's icon
        for (j = 0; j < 6; j++)
        {
            memcpy(dest, src, 0x20);
            dest += 0x20;
            src += 0x20;
        }

        // Create right margin
        if (i != 5)
            dest += 0x20;
    }
}

static void LoadBerryGfx(u8 berryId)
{
    struct CompressedSpritePalette pal;

    if (berryId == ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) - 1 && IsEnigmaBerryValid())
    {
        // unknown empty if statement
    }

    pal.data = sBerryPicTable[berryId].pal;
    pal.tag = TAG_BERRY_PIC_PAL;
    LoadCompressedSpritePalette(&pal);
    LZDecompressWram(sBerryPicTable[berryId].tiles, &gDecompressionBuffer[0x1000]);
    ArrangeBerryGfx(&gDecompressionBuffer[0x1000], &gDecompressionBuffer[0]);
}

u8 CreateBerryTagSprite(u8 id, s16 x, s16 y)
{
    LoadBerryGfx(id);
    return CreateSprite(&sBerryPicSpriteTemplate, x, y, 0);
}

void FreeBerryTagSpritePalette(void)
{
    FreeSpritePaletteByTag(TAG_BERRY_PIC_PAL);
}

// For throwing berries into the Berry Blender
u8 CreateSpinningBerrySprite(u8 berryId, u8 x, u8 y, bool8 startAffine)
{
    u8 spriteId;

    FreeSpritePaletteByTag(TAG_BERRY_PIC_PAL);
    LoadBerryGfx(berryId);
    spriteId = CreateSprite(&sBerryPicRotatingSpriteTemplate, x, y, 0);
    if (startAffine == TRUE)
        StartSpriteAffineAnim(&gSprites[spriteId], 1);

    return spriteId;
}

u8 CreateBerryFlavorCircleSprite(s16 x)
{
    return CreateSprite(&sBerryCheckCircleSpriteTemplate, x, 116, 0);
}
