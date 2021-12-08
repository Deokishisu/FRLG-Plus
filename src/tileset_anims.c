#include "global.h"

static EWRAM_DATA struct {
    const u16 *src;
    u16 *dest;
    u16 size;
} sTilesetDMA3TransferBuffer[20] = {0};

static u8 sTilesetDMA3TransferBufferSize;
static u16 sPrimaryTilesetAnimCounter;
static u16 sPrimaryTilesetAnimCounterMax;
static u16 sSecondaryTilesetAnimCounter;
static u16 sSecondaryTilesetAnimCounterMax;
static void (*sPrimaryTilesetAnimCallback)(u16);
static void (*sSecondaryTilesetAnimCallback)(u16);

static void _InitPrimaryTilesetAnimation(void);
static void _InitSecondaryTilesetAnimation(void);

static const u16 gUnknown_83A73E0[] = INCBIN_U16("graphics/tileset_anims/anim_0_0.bin");
static const u16 gUnknown_83A7460[] = INCBIN_U16("graphics/tileset_anims/anim_0_1.bin");
static const u16 gUnknown_83A74E0[] = INCBIN_U16("graphics/tileset_anims/anim_0_2.bin");
static const u16 gUnknown_83A7560[] = INCBIN_U16("graphics/tileset_anims/anim_0_3.bin");
static const u16 gUnknown_83A75E0[] = INCBIN_U16("graphics/tileset_anims/anim_0_4.bin");

static const u16 *const gUnknown_83A7660[] = {
    gUnknown_83A73E0,
    gUnknown_83A7460,
    gUnknown_83A74E0,
    gUnknown_83A7560,
    gUnknown_83A75E0
};

static const u16 gUnknown_83A7674[] = INCBIN_U16("graphics/tileset_anims/anim_1_0.bin");
static const u16 gUnknown_83A7C74[] = INCBIN_U16("graphics/tileset_anims/anim_1_1.bin");
static const u16 gUnknown_83A8274[] = INCBIN_U16("graphics/tileset_anims/anim_1_2.bin");
static const u16 gUnknown_83A8874[] = INCBIN_U16("graphics/tileset_anims/anim_1_3.bin");
static const u16 gUnknown_83A8E74[] = INCBIN_U16("graphics/tileset_anims/anim_1_4.bin");
static const u16 gUnknown_83A9474[] = INCBIN_U16("graphics/tileset_anims/anim_1_5.bin");
static const u16 gUnknown_83A9A74[] = INCBIN_U16("graphics/tileset_anims/anim_1_6.bin");
static const u16 gUnknown_83AA074[] = INCBIN_U16("graphics/tileset_anims/anim_1_7.bin");

static const u16 *const gUnknown_83AA654[] = {
    gUnknown_83A7674,
    gUnknown_83A7C74,
    gUnknown_83A8274,
    gUnknown_83A8874,
    gUnknown_83A8E74,
    gUnknown_83A9474,
    gUnknown_83A9A74,
    gUnknown_83AA074
};

static const u16 gUnknown_83AA674[] = INCBIN_U16("graphics/tileset_anims/anim_2_0.bin");
static const u16 gUnknown_83AA8B4[] = INCBIN_U16("graphics/tileset_anims/anim_2_1.bin");
static const u16 gUnknown_83AAAF4[] = INCBIN_U16("graphics/tileset_anims/anim_2_2.bin");
static const u16 gUnknown_83AAD34[] = INCBIN_U16("graphics/tileset_anims/anim_2_3.bin");
static const u16 gUnknown_83AAF74[] = INCBIN_U16("graphics/tileset_anims/anim_2_4.bin");
static const u16 gUnknown_83AB1B4[] = INCBIN_U16("graphics/tileset_anims/anim_2_5.bin");
static const u16 gUnknown_83AB3F4[] = INCBIN_U16("graphics/tileset_anims/anim_2_6.bin");
static const u16 gUnknown_83AB634[] = INCBIN_U16("graphics/tileset_anims/anim_2_7.bin");

static const u16 *const gUnknown_83AB874[] = {
    gUnknown_83AA674,
    gUnknown_83AA8B4,
    gUnknown_83AAAF4,
    gUnknown_83AAD34,
    gUnknown_83AAF74,
    gUnknown_83AB1B4,
    gUnknown_83AB3F4,
    gUnknown_83AB634
};

static const u16 gUnknown_83AB894[] = INCBIN_U16("graphics/tileset_anims/anim_3_0.bin");
static const u16 gUnknown_83AB994[] = INCBIN_U16("graphics/tileset_anims/anim_3_1.bin");
static const u16 gUnknown_83ABA94[] = INCBIN_U16("graphics/tileset_anims/anim_3_2.bin");
static const u16 gUnknown_83ABB94[] = INCBIN_U16("graphics/tileset_anims/anim_3_3.bin");
static const u16 gUnknown_83ABC94[] = INCBIN_U16("graphics/tileset_anims/anim_3_4.bin");
static const u16 gUnknown_83ABD94[16] = {};

static const u16 *const gUnknown_83ABDB4[] = {
    gUnknown_83AB894,
    gUnknown_83AB994,
    gUnknown_83ABA94,
    gUnknown_83ABB94,
    gUnknown_83ABC94
};

static const u16 gUnknown_83ABDC8[] = INCBIN_U16("graphics/tileset_anims/anim_4_0.bin");
static const u16 gUnknown_83ABEC8[] = INCBIN_U16("graphics/tileset_anims/anim_4_1.bin");
static const u16 gUnknown_83ABFC8[] = INCBIN_U16("graphics/tileset_anims/anim_4_2.bin");
static const u16 gUnknown_83AC0C8[] = INCBIN_U16("graphics/tileset_anims/anim_4_3.bin");
static const u16 gUnknown_83AC1C8[0x10] = {};

static const u16 *const gUnknown_83AC1E8[] = {
    gUnknown_83ABDC8,
    gUnknown_83ABEC8,
    gUnknown_83ABFC8,
    gUnknown_83AC0C8
};

static const u16 gUnknown_83AC1F8[] = INCBIN_U16("graphics/tileset_anims/anim_5_0.bin");
static const u16 gUnknown_83AC2F8[] = INCBIN_U16("graphics/tileset_anims/anim_5_1.bin");
static const u16 gUnknown_83AC3F8[] = INCBIN_U16("graphics/tileset_anims/anim_5_2.bin");
static const u16 gUnknown_83AC4F8[] = INCBIN_U16("graphics/tileset_anims/anim_5_3.bin");

static const u16 *const gUnknown_83AC5F8[] = {
    gUnknown_83AC1F8,
    gUnknown_83AC2F8,
    gUnknown_83AC3F8,
    gUnknown_83AC4F8
};

static const u16 gUnknown_83AC608[] = INCBIN_U16("graphics/tileset_anims/anim_6_0.bin");
static const u16 gUnknown_83AC6E8[] = INCBIN_U16("graphics/tileset_anims/anim_6_1.bin");

static const u16 *const gUnknown_83AC7C8[] = {
    gUnknown_83AC608,
    gUnknown_83AC6E8
};

static const u16 gUnknown_83AC7D0[] = INCBIN_U16("graphics/tileset_anims/anim_7_0.bin");
static const u16 gUnknown_83AC850[] = INCBIN_U16("graphics/tileset_anims/anim_7_1.bin");
static const u16 gUnknown_83AC8D0[] = INCBIN_U16("graphics/tileset_anims/anim_7_2.bin");

static const u16 *const gUnknown_83AC950[] = {
    gUnknown_83AC7D0,
    gUnknown_83AC850,
    gUnknown_83AC8D0,
    gUnknown_83AC850
};

static const u16 gTilesetAnims_Underwater_Seaweed_Frame0[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/0.4bpp");
static const u16 gTilesetAnims_Underwater_Seaweed_Frame1[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/1.4bpp");
static const u16 gTilesetAnims_Underwater_Seaweed_Frame2[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/2.4bpp");
static const u16 gTilesetAnims_Underwater_Seaweed_Frame3[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/3.4bpp");

static const u16 *const gTilesetAnims_Underwater_Seaweed[] = {
    gTilesetAnims_Underwater_Seaweed_Frame0,
    gTilesetAnims_Underwater_Seaweed_Frame1,
    gTilesetAnims_Underwater_Seaweed_Frame2,
    gTilesetAnims_Underwater_Seaweed_Frame3
};

const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flag/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flag/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flag/2.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideWest_Flag[] = {
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame0,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame1,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame2,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame3
};

const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flag/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flag/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flag/2.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideEast_Flag[] = {
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame0,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame1,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame2,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame3
};

const u16 gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame0[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flower/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame1[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flower/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame2[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsidewest/anim/flower/2.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideWest_Flower[] = {
    gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame0,
    gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame1,
    gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame0,
    gTilesetAnims_BattleFrontierOutsideWest_Flower_Frame2
};

const u16 gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame0[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flower/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame1[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flower/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame2[] = INCBIN_U16("data/tilesets/secondary/battlefrontieroutsideeast/anim/flower/2.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideEast_Flower[] = {
    gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame0,
    gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame1,
    gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame0,
    gTilesetAnims_BattleFrontierOutsideEast_Flower_Frame2
};

static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame0[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/0.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame1[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/1.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame2[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/2.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame3[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/3.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame4[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/4.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame5[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/5.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame6[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/6.4bpp");
static const u16 gTilesetAnims_Mossdeep_Tree_Base_Frame7[] = INCBIN_U16("data/tilesets/secondary/seviiislands5/anim/mossdeep_tree_base/7.4bpp");

static const u16 *const gTilesetAnims_Mossdeep_Tree_Base[] = {
    gTilesetAnims_Mossdeep_Tree_Base_Frame0,
    gTilesetAnims_Mossdeep_Tree_Base_Frame1,
    gTilesetAnims_Mossdeep_Tree_Base_Frame2,
    gTilesetAnims_Mossdeep_Tree_Base_Frame3,
    gTilesetAnims_Mossdeep_Tree_Base_Frame4,
    gTilesetAnims_Mossdeep_Tree_Base_Frame5,
    gTilesetAnims_Mossdeep_Tree_Base_Frame6,
    gTilesetAnims_Mossdeep_Tree_Base_Frame7
};

static void ResetTilesetAnimBuffer(void)
{
    sTilesetDMA3TransferBufferSize = 0;
    CpuFill32(0, sTilesetDMA3TransferBuffer, sizeof sTilesetDMA3TransferBuffer);
}

static void AppendTilesetAnimToBuffer(const u16 *src, u16 *dest, u16 size)
{
    if (sTilesetDMA3TransferBufferSize < 20)
    {
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].src = src;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].dest = dest;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].size = size;
        sTilesetDMA3TransferBufferSize++;
    }
}

void TransferTilesetAnimsBuffer(void)
{
    int i;

    for (i = 0; i < sTilesetDMA3TransferBufferSize; i++)
        DmaCopy16(3, sTilesetDMA3TransferBuffer[i].src, sTilesetDMA3TransferBuffer[i].dest, sTilesetDMA3TransferBuffer[i].size);

    sTilesetDMA3TransferBufferSize = 0;
}

void InitTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    _InitPrimaryTilesetAnimation();
    _InitSecondaryTilesetAnimation();
}

void InitSecondaryTilesetAnimation(void)
{
    _InitSecondaryTilesetAnimation();
}

void UpdateTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    if (++sPrimaryTilesetAnimCounter >= sPrimaryTilesetAnimCounterMax)
        sPrimaryTilesetAnimCounter = 0;
    if (++sSecondaryTilesetAnimCounter >= sSecondaryTilesetAnimCounterMax)
        sSecondaryTilesetAnimCounter = 0;

    if (sPrimaryTilesetAnimCallback)
        sPrimaryTilesetAnimCallback(sPrimaryTilesetAnimCounter);
    if (sSecondaryTilesetAnimCallback)
        sSecondaryTilesetAnimCallback(sSecondaryTilesetAnimCounter);
}

static void _InitPrimaryTilesetAnimation(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 0;
    sPrimaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->primaryTileset && gMapHeader.mapLayout->primaryTileset->callback)
        gMapHeader.mapLayout->primaryTileset->callback();
}

static void _InitSecondaryTilesetAnimation(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 0;
    sSecondaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->secondaryTileset && gMapHeader.mapLayout->secondaryTileset->callback)
        gMapHeader.mapLayout->secondaryTileset->callback();
}

static void sub_80700A4(u16 timer)
{
    AppendTilesetAnimToBuffer(gUnknown_83A7660[timer % NELEMS(gUnknown_83A7660)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(508)), 0x80);
}

static void sub_80700D0(u16 timer)
{
    AppendTilesetAnimToBuffer(gUnknown_83AA654[timer % NELEMS(gUnknown_83AA654)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(416)), 0x600);
    AppendTilesetAnimToBuffer(gTilesetAnims_Mossdeep_Tree_Base[timer % NELEMS(gTilesetAnims_Mossdeep_Tree_Base)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x1EC)), 0x80);
}

static void sub_80700F8(u16 timer)
{
    AppendTilesetAnimToBuffer(gUnknown_83AB874[timer % NELEMS(gUnknown_83AB874)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(464)), 0x240);
}

static void sub_8070120(u16 timer)
{
    if (timer % 8 == 0)
        sub_80700F8(timer >> 3);
    if (timer % 16 == 1)
        sub_80700D0(timer >> 4);
    if (timer % 16 == 2)
        sub_80700A4(timer >> 4);
}

void InitTilesetAnim_General(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 640;
    sPrimaryTilesetAnimCallback = sub_8070120;
}

static void sub_807017C(u16 timer)
{
    AppendTilesetAnimToBuffer(gUnknown_83ABDB4[timer % NELEMS(gUnknown_83ABDB4)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(744)), 0x100);
}

static void sub_80701AC(u16 timer)
{
    if (timer % 12 == 0)
        sub_807017C(timer / 12);
}

void InitTilesetAnim_CeladonCity(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 120;
    sSecondaryTilesetAnimCallback = sub_80701AC;
}

static void sub_80701FC(u16 timer)
{
    AppendTilesetAnimToBuffer(gUnknown_83AC1E8[timer % NELEMS(gUnknown_83AC1E8)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(976)), 0x100);
}

static void sub_8070224(u16 timer)
{
    if (timer % 10 == 0)
        sub_80701FC(timer / 10);
}

void InitTilesetAnim_SilphCo(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 160;
    sSecondaryTilesetAnimCallback = sub_8070224;
}

static void sub_8070274(u16 timer)
{
    AppendTilesetAnimToBuffer(gUnknown_83AC5F8[timer % NELEMS(gUnknown_83AC5F8)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(896)), 0x100);
}

static void sub_807029C(u16 timer)
{
    if (timer % 16 == 0)
        sub_8070274(timer >> 4);
}

void InitTilesetAnim_MtEmber(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = sub_807029C;
}

static void sub_80702DC(u16 timer)
{
    u16 i = timer % NELEMS(gUnknown_83AC7C8);

    AppendTilesetAnimToBuffer(gUnknown_83AC7C8[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(880)), 0xE0);
}

static void sub_8070304(u16 timer)
{
    if (timer % 2 == 0)
        sub_80702DC(timer >> 1);
}

void InitTilesetAnim_VermilionGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 240;
    sSecondaryTilesetAnimCallback = sub_8070304;
}

static void sub_8070340(u16 timer)
{
    u16 i = timer % NELEMS(gUnknown_83AC950);
    
    AppendTilesetAnimToBuffer(gUnknown_83AC950[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(739)), 0x80);
}

static void sub_8070368(u16 timer)
{
    if (timer % 16 == 0)
        sub_8070340(timer >> 4);
}

void InitTilesetAnim_CeladonGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = sub_8070368;
}

static void QueueAnimTiles_Underwater_Seaweed(u8 timer)
{
    u8 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_Underwater_Seaweed[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x2B5)), 0x80);
}

static void TilesetAnim_Underwater(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Underwater_Seaweed(timer >> 4);
}

void InitTilesetAnim_Underwater(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 128;
    sSecondaryTilesetAnimCallback = TilesetAnim_Underwater;
}

static void QueueAnimTiles_BattleFrontierOutsideWest_Flag(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideWest_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x300)), 0xC0);
}

static void QueueAnimTiles_BattleFrontierOutsideEast_Flag(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideEast_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x300)), 0xC0);
}

static void QueueAnimTiles_BattleFrontierOutsideWest_Flower(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideWest_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x312)), 0x80);
}

static void QueueAnimTiles_BattleFrontierOutsideEast_Flower(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideEast_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x312)), 0x80);
}

static void TilesetAnim_BattleFrontierOutsideWest(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_BattleFrontierOutsideWest_Flower(timer >> 4);
    if (timer % 8 == 0)
        QueueAnimTiles_BattleFrontierOutsideWest_Flag(timer >> 3);
}

static void TilesetAnim_BattleFrontierOutsideEast(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_BattleFrontierOutsideEast_Flower(timer >> 4);
    if (timer % 8 == 0)
        QueueAnimTiles_BattleFrontierOutsideEast_Flag(timer >> 3);
}

void InitTilesetAnim_BattleFrontierOutsideWest(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleFrontierOutsideWest;
}

void InitTilesetAnim_BattleFrontierOutsideEast(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleFrontierOutsideEast;
}

static void QueueAnimTiles_SeviiIslands67_Flower(u16 timer)
{
    u16 i = timer % 4;
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideEast_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x377)), 0x80);
}

static void TilesetAnim_SeviiIslands67(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_SeviiIslands67_Flower(timer >> 4);
}

void InitTilesetAnim_SeviiIslands67(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_SeviiIslands67;
}

static void QueueAnimTiles_SeviiIslands5_ShortGrassFlower(u16 timer)
{
    AppendTilesetAnimToBuffer(gUnknown_83A7660[timer % NELEMS(gUnknown_83A7660)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x324)), 0x80);
}

static void TilesetAnim_SeviiIslands5(u16 timer)
{
    if (timer % 16 == 2)
        QueueAnimTiles_SeviiIslands5_ShortGrassFlower(timer >> 4);
}

void InitTilesetAnim_SeviiIslands5(void)
{
    sSecondaryTilesetAnimCounter = sPrimaryTilesetAnimCounter;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_SeviiIslands5;
}