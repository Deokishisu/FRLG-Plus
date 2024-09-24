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

// palette: general 00
static const u16 sTilesetAnims_General_Flower_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/0.4bpp");
static const u16 sTilesetAnims_General_Flower_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/1.4bpp");
static const u16 sTilesetAnims_General_Flower_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/2.4bpp");
static const u16 sTilesetAnims_General_Flower_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/3.4bpp");
static const u16 sTilesetAnims_General_Flower_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/4.4bpp");

static const u16 *const sTilesetAnims_General_Flower[] = {
    sTilesetAnims_General_Flower_Frame0,
    sTilesetAnims_General_Flower_Frame1,
    sTilesetAnims_General_Flower_Frame2,
    sTilesetAnims_General_Flower_Frame3,
    sTilesetAnims_General_Flower_Frame4
};

// palette: general 04
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/0.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/1.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/2.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/3.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/4.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/5.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/6.4bpp");
static const u16 sTilesetAnims_General_Water_Current_LandWatersEdge_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/water_current_landwatersedge/7.4bpp");

static const u16 *const sTilesetAnims_General_Water_Current_LandWatersEdge[] = {
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame0,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame1,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame2,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame3,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame4,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame5,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame6,
    sTilesetAnims_General_Water_Current_LandWatersEdge_Frame7
};

// palette: general 04
static const u16 sTilesetAnims_General_SandWatersEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/0.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/1.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/2.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/3.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/4.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/5.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/6.4bpp");
static const u16 sTilesetAnims_General_SandWatersEdge_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/sandwatersedge/7.4bpp");

static const u16 *const sTilesetAnims_General_SandWatersEdge[] = {
    sTilesetAnims_General_SandWatersEdge_Frame0,
    sTilesetAnims_General_SandWatersEdge_Frame1,
    sTilesetAnims_General_SandWatersEdge_Frame2,
    sTilesetAnims_General_SandWatersEdge_Frame3,
    sTilesetAnims_General_SandWatersEdge_Frame4,
    sTilesetAnims_General_SandWatersEdge_Frame5,
    sTilesetAnims_General_SandWatersEdge_Frame6,
    sTilesetAnims_General_SandWatersEdge_Frame7
};

// palette: general 00
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/0.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/1.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame2[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/2.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame3[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/3.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Frame4[] = INCBIN_U16("data/tilesets/secondary/celadon_city/anim/fountain/4.4bpp");
static const u16 sTilesetAnims_CeladonCity_Fountain_Empty[16] = {};

static const u16 *const sTilesetAnims_CeladonCity_Fountain[] = {
    sTilesetAnims_CeladonCity_Fountain_Frame0,
    sTilesetAnims_CeladonCity_Fountain_Frame1,
    sTilesetAnims_CeladonCity_Fountain_Frame2,
    sTilesetAnims_CeladonCity_Fountain_Frame3,
    sTilesetAnims_CeladonCity_Fountain_Frame4
};

static const u16 sTilesetAnims_SilphCo_Fountain_Frame0[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/0.4bpp");
static const u16 sTilesetAnims_SilphCo_Fountain_Frame1[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/1.4bpp");
static const u16 sTilesetAnims_SilphCo_Fountain_Frame2[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/2.4bpp");
static const u16 sTilesetAnims_SilphCo_Fountain_Frame3[] = INCBIN_U16("data/tilesets/secondary/silph_co/anim/fountain/3.4bpp");
static const u16 sTilesetAnims_SilphCo_Fountain_Empty[16] = {};

static const u16 *const sTilesetAnims_SilphCo_Fountain[] = {
    sTilesetAnims_SilphCo_Fountain_Frame0,
    sTilesetAnims_SilphCo_Fountain_Frame1,
    sTilesetAnims_SilphCo_Fountain_Frame2,
    sTilesetAnims_SilphCo_Fountain_Frame3
};

static const u16 sTilesetAnims_MtEmber_Steam_Frame0[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/0.4bpp");
static const u16 sTilesetAnims_MtEmber_Steam_Frame1[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/1.4bpp");
static const u16 sTilesetAnims_MtEmber_Steam_Frame2[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/2.4bpp");
static const u16 sTilesetAnims_MtEmber_Steam_Frame3[] = INCBIN_U16("data/tilesets/secondary/mt_ember/anim/steam/3.4bpp");

static const u16 *const sTilesetAnims_MtEmber_Steam[] = {
    sTilesetAnims_MtEmber_Steam_Frame0,
    sTilesetAnims_MtEmber_Steam_Frame1,
    sTilesetAnims_MtEmber_Steam_Frame2,
    sTilesetAnims_MtEmber_Steam_Frame3
};

static const u16 sTilesetAnims_VermilionGym_MotorizedDoor_Frame0[] = INCBIN_U16("data/tilesets/secondary/vermilion_gym/anim/motorizeddoor/0.4bpp");
static const u16 sTilesetAnims_VermilionGym_MotorizedDoor_Frame1[] = INCBIN_U16("data/tilesets/secondary/vermilion_gym/anim/motorizeddoor/1.4bpp");

static const u16 *const sTilesetAnims_VermilionGym_MotorizedDoor[] = {
    sTilesetAnims_VermilionGym_MotorizedDoor_Frame0,
    sTilesetAnims_VermilionGym_MotorizedDoor_Frame1
};

static const u16 sTilesetAnims_CeladonGym_Flowers_Frame0[] = INCBIN_U16("data/tilesets/secondary/celadon_gym/anim/flowers/0.4bpp");
static const u16 sTilesetAnims_CeladonGym_Flowers_Frame1[] = INCBIN_U16("data/tilesets/secondary/celadon_gym/anim/flowers/1.4bpp");
static const u16 sTilesetAnims_CeladonGym_Flowers_Frame2[] = INCBIN_U16("data/tilesets/secondary/celadon_gym/anim/flowers/2.4bpp");

static const u16 *const sTilesetAnims_CeladonGym_Flowers[] = {
    sTilesetAnims_CeladonGym_Flowers_Frame0,
    sTilesetAnims_CeladonGym_Flowers_Frame1,
    sTilesetAnims_CeladonGym_Flowers_Frame2,
    sTilesetAnims_CeladonGym_Flowers_Frame1
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

static void QueueAnimTiles_General_Flower(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_General_Flower[timer % ARRAY_COUNT(sTilesetAnims_General_Flower)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(508)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_Water_Current_LandWatersEdge(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_General_Water_Current_LandWatersEdge[timer % ARRAY_COUNT(sTilesetAnims_General_Water_Current_LandWatersEdge)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(416)), 48 * TILE_SIZE_4BPP);
    AppendTilesetAnimToBuffer(gTilesetAnims_Mossdeep_Tree_Base[timer % ARRAY_COUNT(gTilesetAnims_Mossdeep_Tree_Base)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(492)), 0x80);
}

static void QueueAnimTiles_General_SandWatersEdge(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_General_SandWatersEdge[timer % ARRAY_COUNT(sTilesetAnims_General_SandWatersEdge)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(464)), 18 * TILE_SIZE_4BPP);
}

static void TilesetAnim_General(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_General_SandWatersEdge(timer / 8);
    if (timer % 16 == 1)
        QueueAnimTiles_General_Water_Current_LandWatersEdge(timer / 16);
    if (timer % 16 == 2)
        QueueAnimTiles_General_Flower(timer / 16);
}

void InitTilesetAnim_General(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 640;
    sPrimaryTilesetAnimCallback = TilesetAnim_General;
}

static void QueueAnimTiles_CeladonCity_Fountain(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_CeladonCity_Fountain[timer % ARRAY_COUNT(sTilesetAnims_CeladonCity_Fountain)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(744)), 8 * TILE_SIZE_4BPP);
}

static void TilesetAnim_CeladonCity(u16 timer)
{
    if (timer % 12 == 0)
        QueueAnimTiles_CeladonCity_Fountain(timer / 12);
}

void InitTilesetAnim_CeladonCity(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 120;
    sSecondaryTilesetAnimCallback = TilesetAnim_CeladonCity;
}

static void QueueAnimTiles_SilphCo_Fountain(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_SilphCo_Fountain[timer % ARRAY_COUNT(sTilesetAnims_SilphCo_Fountain)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(976)), 8 * TILE_SIZE_4BPP);
}

static void TilesetAnim_SilphCo(u16 timer)
{
    if (timer % 10 == 0)
        QueueAnimTiles_SilphCo_Fountain(timer / 10);
}

void InitTilesetAnim_SilphCo(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 160;
    sSecondaryTilesetAnimCallback = TilesetAnim_SilphCo;
}

static void QueueAnimTiles_MtEmber_Steam(u16 timer)
{
    AppendTilesetAnimToBuffer(sTilesetAnims_MtEmber_Steam[timer % ARRAY_COUNT(sTilesetAnims_MtEmber_Steam)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(896)), 8 * TILE_SIZE_4BPP);
}

static void TilesetAnim_MtEmber(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_MtEmber_Steam(timer / 16);
}

void InitTilesetAnim_MtEmber(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_MtEmber;
}

static void QueueAnimTiles_VermilionGym_MotorizedDoor(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(sTilesetAnims_VermilionGym_MotorizedDoor);

    AppendTilesetAnimToBuffer(sTilesetAnims_VermilionGym_MotorizedDoor[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(880)), 7 * TILE_SIZE_4BPP);
}

static void TilesetAnim_VermilionGym(u16 timer)
{
    if (timer % 2 == 0)
        QueueAnimTiles_VermilionGym_MotorizedDoor(timer / 2);
}

void InitTilesetAnim_VermilionGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 240;
    sSecondaryTilesetAnimCallback = TilesetAnim_VermilionGym;
}

static void QueueAnimTiles_CeladonGym_Flowers(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(sTilesetAnims_CeladonGym_Flowers);
    
    AppendTilesetAnimToBuffer(sTilesetAnims_CeladonGym_Flowers[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(739)), 4 * TILE_SIZE_4BPP);
}

static void TilesetAnim_CeladonGym(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_CeladonGym_Flowers(timer / 16);
}

void InitTilesetAnim_CeladonGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 256;
    sSecondaryTilesetAnimCallback = TilesetAnim_CeladonGym;
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
    AppendTilesetAnimToBuffer(sTilesetAnims_General_Flower[timer % NELEMS(sTilesetAnims_General_Flower)], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(0x324)), 0x80);
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