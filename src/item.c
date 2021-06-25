#include "global.h"
#include "gflib.h"
#include "berry.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "item.h"
#include "party_menu.h"
#include "item_use.h"
#include "load_save.h"
#include "money.h"
#include "quest_log.h"
#include "strings.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/maps.h"

EWRAM_DATA struct BagPocket gBagPockets[NUM_BAG_POCKETS] = {};
EWRAM_DATA struct ItemSlot gTmHmItemSlots[BAG_TMHM_COUNT] = {0};
EWRAM_DATA struct ItemSlot gKeyItemSlots[BAG_KEYITEMS_COUNT] = {0};

void SortAndCompactBagPocket(struct BagPocket * pocket);
static void RemoveTMItemBall(u16 itemId);

// Item descriptions and data
#include "data/items.h"

u16 GetBagItemQuantity(u16 * ptr)
{
    return gSaveBlock2Ptr->encryptionKey ^ *ptr;
}

void SetBagItemQuantity(u16 * ptr, u16 value)
{
    *ptr = value ^ gSaveBlock2Ptr->encryptionKey;
}

u16 GetPcItemQuantity(u16 * ptr)
{
    return 0 ^ *ptr;
}

void SetPcItemQuantity(u16 * ptr, u16 value)
{
    *ptr = value ^ 0;
}

void ApplyNewEncryptionKeyToBagItems(u32 key)
{
    u32 i, j;

    for (i = 0; i < NUM_BAG_POCKETS; i++)
    {
        for (j = 0; j < gBagPockets[i].capacity; j++)
        {
            ApplyNewEncryptionKeyToHword(&gBagPockets[i].itemSlots[j].quantity, key);
        }
    }
}

void ApplyNewEncryptionKeyToBagItems_(u32 key)
{
    ApplyNewEncryptionKeyToBagItems(key);
}

void DeserializeTmHmItemSlots(void)
{
    int i;

    for (i = 0; i < BAG_TMHM_COUNT; ++i)
    {
        gTmHmItemSlots[i].itemId = 0;
        SetBagItemQuantity(&(gTmHmItemSlots[i].quantity), 0);
    }
    for (i = 0; i < TMHM_COUNT; ++i)
    {
        u8 bit = i % 8;
        if (gSaveBlock1Ptr->bagPocket_TMHM[i / 8] & (1<<bit))
            AddBagItem(i + ITEM_TM01, 1);
    }
}

void DeserializeKeyItemSlots(void)
{
    int i;

    for (i = 0; i < BAG_KEYITEMS_COUNT; ++i)
    {
        gKeyItemSlots[i].itemId = 0;
        SetBagItemQuantity(&(gKeyItemSlots[i].quantity), 0);
    }
    for (i = 0; i < BAG_KEYITEMS_COUNT; ++i)
    {
        if (gSaveBlock1Ptr->bagPocket_KeyItems[i] != 0 && gSaveBlock1Ptr->bagPocket_KeyItems[i] <= 30)
            AddBagItem(gSaveBlock1Ptr->bagPocket_KeyItems[i] + 258, 1);
        if (gSaveBlock1Ptr->bagPocket_KeyItems[i] != 0 && gSaveBlock1Ptr->bagPocket_KeyItems[i] > 30 && gSaveBlock1Ptr->bagPocket_KeyItems[i] < 59)
            AddBagItem(gSaveBlock1Ptr->bagPocket_KeyItems[i] + 348 - 30, 1);
        if (gSaveBlock1Ptr->bagPocket_KeyItems[i] == 59)
            AddBagItem(ITEM_LINK_BRACELET, 1);
    }
}

void SetBagPocketsPointers(void)
{
    gBagPockets[POCKET_ITEMS - 1].itemSlots = gSaveBlock1Ptr->bagPocket_Items;
    gBagPockets[POCKET_ITEMS - 1].capacity = BAG_ITEMS_COUNT;
    gBagPockets[POCKET_KEY_ITEMS - 1].itemSlots = &gKeyItemSlots[0];
    gBagPockets[POCKET_KEY_ITEMS - 1].capacity = BAG_KEYITEMS_COUNT;
    gBagPockets[POCKET_POKE_BALLS - 1].itemSlots = gSaveBlock1Ptr->bagPocket_PokeBalls;
    gBagPockets[POCKET_POKE_BALLS - 1].capacity = BAG_POKEBALLS_COUNT;
    gBagPockets[POCKET_TM_CASE - 1].itemSlots = &gTmHmItemSlots[0];
    gBagPockets[POCKET_TM_CASE - 1].capacity = BAG_TMHM_COUNT;
    gBagPockets[POCKET_BERRY_POUCH - 1].itemSlots = gSaveBlock1Ptr->bagPocket_Berries;
    gBagPockets[POCKET_BERRY_POUCH - 1].capacity = BAG_BERRIES_COUNT;
    gBagPockets[POCKET_MEDICINE - 1].itemSlots = gSaveBlock1Ptr->bagPocket_Medicine;
    gBagPockets[POCKET_MEDICINE - 1].capacity = BAG_MEDICINE_COUNT;
    gBagPockets[POCKET_HELD_ITEMS - 1].itemSlots = gSaveBlock1Ptr->bagPocket_HoldItems;
    gBagPockets[POCKET_HELD_ITEMS - 1].capacity = BAG_HELD_ITEMS_COUNT;
}

void CopyItemName(u16 itemId, u8 * dest)
{
    if (itemId == ITEM_ENIGMA_BERRY)
    {
        StringCopy(dest, GetBerryInfo(ITEM_TO_BERRY(ITEM_ENIGMA_BERRY))->name);
        StringAppend(dest, gUnknown_84162BD);
    }
    else
    {
        StringCopy(dest, ItemId_GetName(itemId));
    }
}

s16 BagPocketGetFirstEmptySlot(u8 pocketId)
{
    u32 i;

    for (i = 0; i < gBagPockets[pocketId].capacity; i++)
    {
        if (gBagPockets[pocketId].itemSlots[i].itemId == ITEM_NONE)
            return i;
    }

    return -1;
}

bool8 IsPocketNotEmpty(u8 pocketId)
{
    u32 i;

    for (i = 0; i < gBagPockets[pocketId - 1].capacity; i++)
    {
        if (gBagPockets[pocketId - 1].itemSlots[i].itemId != ITEM_NONE)
            return TRUE;
    }

    return FALSE;
}

bool8 CheckBagHasItem(u16 itemId, u16 count)
{
    u32 i;
    u8 pocket;

    if (ItemId_GetPocket(itemId) == 0)
        return FALSE;

    pocket = ItemId_GetPocket(itemId) - 1;
    // Check for item slots that contain the item
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            u16 quantity;
            // Does this item slot contain enough of the item?
            quantity = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            if (quantity >= count)
                return TRUE;
                // RS and Emerald check whether there is enough of the
                // item across all stacks.
                // For whatever reason, FR/LG assume there's only one
                // stack of the item.
            else
                return FALSE;
        }
    }
    return FALSE;
}

bool8 HasAtLeastOneBerry(void)
{
    u8 itemId;
    bool8 exists;

    exists = CheckBagHasItem(ITEM_BERRY_POUCH, 1);
    if (!exists)
    {
        gSpecialVar_Result = FALSE;
        return FALSE;
    }
    for (itemId = FIRST_BERRY_INDEX; itemId <= LAST_BERRY_INDEX; itemId++)
    {
        exists = CheckBagHasItem(itemId, 1);
        if (exists)
        {
            gSpecialVar_Result = TRUE;
            return TRUE;
        }
    }

    gSpecialVar_Result = FALSE;
    return FALSE;
}

bool8 CheckBagHasSpace(u16 itemId, u16 count)
{
    u32 i;
    u8 pocket;

    if (ItemId_GetPocket(itemId) == 0)
        return FALSE;

    pocket = ItemId_GetPocket(itemId) - 1;
    // Check for item slots that contain the item
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            u16 quantity;
            // Does this stack have room for more??
            quantity = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            if (quantity + count <= 999)
                return TRUE;
            // RS and Emerald check whether there is enough of the
            // item across all stacks.
            // For whatever reason, FR/LG assume there's only one
            // stack of the item.
            else
                return FALSE;
        }
    }

    if (BagPocketGetFirstEmptySlot(pocket) != -1)
        return TRUE;

    return FALSE;
}

static void SetTmHmOwned(u16 itemId)
{
    u8* flagByte = &gSaveBlock1Ptr->bagPocket_TMHM[(itemId - ITEM_TM01) / 8];
    *flagByte = (*flagByte) | (1 << ((itemId - ITEM_TM01) % 8));
}

bool8 AddBagItem(u16 itemId, u16 count)
{
    u32 i;
    u8 pocket;
    s16 idx;

    if (ItemId_GetPocket(itemId) == 0)
        return FALSE;

    pocket = ItemId_GetPocket(itemId) - 1;
    if (pocket == POCKET_TM_CASE - 1)
    {
        if (pocket == POCKET_TM_CASE - 1 && !CheckBagHasItem(ITEM_TM_CASE, 1))
        {
            idx = BagPocketGetFirstEmptySlot(POCKET_KEY_ITEMS - 1);
            if (idx == -1)
                return FALSE;
            gBagPockets[POCKET_KEY_ITEMS - 1].itemSlots[idx].itemId = ITEM_TM_CASE;
            SetBagItemQuantity(&gBagPockets[POCKET_KEY_ITEMS - 1].itemSlots[idx].quantity, 1);
        }
        if(!FlagGet(FLAG_DONT_ADD_TMS)) //don't add if Teachy TV
            SetTmHmOwned(itemId);
    }
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            u16 quantity;
            // Does this stack have room for more??
            quantity = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            if (quantity + count <= 999)
            {
                quantity += count;
                SetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity, quantity);
                return TRUE;
            }
            // RS and Emerald check whether there is enough of the
            // item across all stacks.
            // For whatever reason, FR/LG assume there's only one
            // stack of the item.
            else
                return FALSE;
        }
    }

    if (pocket == POCKET_BERRY_POUCH - 1 && !CheckBagHasItem(ITEM_BERRY_POUCH, 1))
    {
        idx = BagPocketGetFirstEmptySlot(POCKET_KEY_ITEMS - 1);
        if (idx == -1)
            return FALSE;
        gBagPockets[POCKET_KEY_ITEMS - 1].itemSlots[idx].itemId = ITEM_BERRY_POUCH;
        SetBagItemQuantity(&gBagPockets[POCKET_KEY_ITEMS - 1].itemSlots[idx].quantity, 1);
        FlagSet(FLAG_SYS_GOT_BERRY_POUCH);
    }

    if (itemId == ITEM_BERRY_POUCH)
        FlagSet(FLAG_SYS_GOT_BERRY_POUCH);

    idx = BagPocketGetFirstEmptySlot(pocket);
    if (idx == -1)
        return FALSE;

    gBagPockets[pocket].itemSlots[idx].itemId = itemId;
    SetBagItemQuantity(&gBagPockets[pocket].itemSlots[idx].quantity, count);
    RemoveTMItemBall(itemId);
    return TRUE;
}

static void RemoveTMItemBall(u16 itemId)
{
    if ((ItemId_GetPocket(itemId) - 1) != POCKET_TM_CASE - 1) //not TM
    {
        return;
    }
    switch(itemId)
    {
        case ITEM_TM01:
            FlagSet(FLAG_HIDE_SILPH_CO_5F_TM01);
            RemoveObjectEventByLocalIdAndMap(7, MAP_NUM(SILPH_CO_5F), MAP_GROUP(SILPH_CO_5F));
            return;
        case ITEM_TM02:
            FlagSet(FLAG_HIDE_VICTORY_ROAD_1F_TM02);
            RemoveObjectEventByLocalIdAndMap(4, MAP_NUM(VICTORY_ROAD_1F), MAP_GROUP(VICTORY_ROAD_1F));
            return;
        case ITEM_TM05:
            FlagSet(FLAG_HIDE_ROUTE4_TM05);
            RemoveObjectEventByLocalIdAndMap(3, MAP_NUM(ROUTE4), MAP_GROUP(ROUTE4));
            return;
        case ITEM_TM07:
            FlagSet(FLAG_HIDE_VICTORY_ROAD_2F_TM07);
            RemoveObjectEventByLocalIdAndMap(7, MAP_NUM(VICTORY_ROAD_2F), MAP_GROUP(VICTORY_ROAD_2F));
            return;
        case ITEM_TM08:
            FlagSet(FLAG_HIDE_SILPH_CO_7F_TM08);
            RemoveObjectEventByLocalIdAndMap(11, MAP_NUM(SILPH_CO_7F), MAP_GROUP(SILPH_CO_7F));
            return;
        case ITEM_TM09:
            FlagSet(FLAG_HIDE_MT_MOON_1F_TM09);
            RemoveObjectEventByLocalIdAndMap(9, MAP_NUM(MT_MOON_1F), MAP_GROUP(MT_MOON_1F));
            return;
        case ITEM_TM11:
            FlagSet(FLAG_HIDE_SAFARI_ZONE_EAST_TM11);
            RemoveObjectEventByLocalIdAndMap(3, MAP_NUM(SAFARI_ZONE_EAST), MAP_GROUP(SAFARI_ZONE_EAST));
            return;
        case ITEM_TM12:
            FlagSet(FLAG_HIDE_ROCKET_HIDEOUT_B2F_TM12);
            RemoveObjectEventByLocalIdAndMap(4, MAP_NUM(ROCKET_HIDEOUT_B2F), MAP_GROUP(ROCKET_HIDEOUT_B2F));
            return;
        case ITEM_TM14:
            FlagSet(FLAG_HIDE_POKEMON_MANSION_B1F_TM14);
            RemoveObjectEventByLocalIdAndMap(4, MAP_NUM(POKEMON_MANSION_B1F), MAP_GROUP(POKEMON_MANSION_B1F));
            return;
        case ITEM_TM17:
            FlagSet(FLAG_HIDE_POWER_PLANT_TM17);
            RemoveObjectEventByLocalIdAndMap(2, MAP_NUM(POWER_PLANT), MAP_GROUP(POWER_PLANT));
            return;
        case ITEM_TM18:
            FlagSet(FLAG_HIDE_ROUTE15_TM18);
            RemoveObjectEventByLocalIdAndMap(11, MAP_NUM(ROUTE15), MAP_GROUP(ROUTE15));
            return;
        case ITEM_TM21:
            FlagSet(FLAG_HIDE_ROCKET_HIDEOUT_B3F_TM21);
            RemoveObjectEventByLocalIdAndMap(4, MAP_NUM(ROCKET_HIDEOUT_B3F), MAP_GROUP(ROCKET_HIDEOUT_B3F));
            return;
        case ITEM_TM22:
            FlagSet(FLAG_HIDE_POKEMON_MANSION_B1F_TM22);
            RemoveObjectEventByLocalIdAndMap(1, MAP_NUM(POKEMON_MANSION_B1F), MAP_GROUP(POKEMON_MANSION_B1F));
            return;
        case ITEM_TM25:
            FlagSet(FLAG_HIDE_POWER_PLANT_TM25);
            RemoveObjectEventByLocalIdAndMap(3, MAP_NUM(POWER_PLANT), MAP_GROUP(POWER_PLANT));
            return;
        case ITEM_TM31:
            FlagSet(FLAG_HIDE_SSANNE_1F_ROOM2_TM31);
            RemoveObjectEventByLocalIdAndMap(4, MAP_NUM(SSANNE_1F_ROOM2), MAP_GROUP(SSANNE_1F_ROOM2));
            return;
        case ITEM_TM32:
            FlagSet(FLAG_HIDE_SAFARI_ZONE_WEST_TM32);
            RemoveObjectEventByLocalIdAndMap(2, MAP_NUM(SAFARI_ZONE_WEST), MAP_GROUP(SAFARI_ZONE_WEST));
            return;
        case ITEM_TM36:
            FlagSet(FLAG_HIDE_FIVE_ISLAND_ROCKET_WAREHOUSE_TM36);
            RemoveObjectEventByLocalIdAndMap(8, MAP_NUM(FIVE_ISLAND_ROCKET_WAREHOUSE), MAP_GROUP(FIVE_ISLAND_ROCKET_WAREHOUSE));
            return;
        case ITEM_TM37:
            FlagSet(FLAG_HIDE_VICTORY_ROAD_2F_TM37);
            RemoveObjectEventByLocalIdAndMap(9, MAP_NUM(VICTORY_ROAD_2F), MAP_GROUP(VICTORY_ROAD_2F));
            return;
        case ITEM_TM40:
            FlagSet(FLAG_HIDE_ROUTE9_TM40);
            RemoveObjectEventByLocalIdAndMap(11, MAP_NUM(ROUTE9), MAP_GROUP(ROUTE9));
            return;
        case ITEM_TM41:
            FlagSet(FLAG_HIDE_SILPH_CO_4F_TM41);
            RemoveObjectEventByLocalIdAndMap(8, MAP_NUM(SILPH_CO_4F), MAP_GROUP(SILPH_CO_4F));
            return;
        case ITEM_TM43:
            FlagSet(FLAG_HIDE_ROUTE25_TM43);
            RemoveObjectEventByLocalIdAndMap(10, MAP_NUM(ROUTE25), MAP_GROUP(ROUTE25));
            return;
        case ITEM_TM44:
            FlagSet(FLAG_HIDE_SSANNE_B1F_ROOM2_TM44);
            RemoveObjectEventByLocalIdAndMap(2, MAP_NUM(SSANNE_B1F_ROOM2), MAP_GROUP(SSANNE_B1F_ROOM2));
            return;
        case ITEM_TM45:
            FlagSet(FLAG_HIDE_ROUTE24_TM45);
            RemoveObjectEventByLocalIdAndMap(8, MAP_NUM(ROUTE24), MAP_GROUP(ROUTE24));
            return;
        case ITEM_TM46:
            FlagSet(FLAG_HIDE_MT_MOON_B2F_TM46);
            RemoveObjectEventByLocalIdAndMap(9, MAP_NUM(MT_MOON_B2F), MAP_GROUP(MT_MOON_B2F));
            return;
        case ITEM_TM47:
            FlagSet(FLAG_HIDE_SAFARI_ZONE_NORTH_TM47);
            RemoveObjectEventByLocalIdAndMap(2, MAP_NUM(SAFARI_ZONE_NORTH), MAP_GROUP(SAFARI_ZONE_NORTH));
            return;
        case ITEM_TM48:
            FlagSet(FLAG_HIDE_ROUTE12_TM48);
            RemoveObjectEventByLocalIdAndMap(10, MAP_NUM(ROUTE12), MAP_GROUP(ROUTE12));
            return;
        case ITEM_TM49:
            FlagSet(FLAG_HIDE_ROCKET_HIDEOUT_B4F_TM49);
            RemoveObjectEventByLocalIdAndMap(7, MAP_NUM(ROCKET_HIDEOUT_B4F), MAP_GROUP(ROCKET_HIDEOUT_B4F));
            return;
        case ITEM_TM50:
            FlagSet(FLAG_HIDE_VICTORY_ROAD_3F_TM50);
            RemoveObjectEventByLocalIdAndMap(6, MAP_NUM(VICTORY_ROAD_3F), MAP_GROUP(VICTORY_ROAD_3F));
            return;
    }
}

bool8 RemoveBagItem(u16 itemId, u16 count)
{
    u32 i;
    u8 pocket;

    if (ItemId_GetPocket(itemId) == 0)
        return FALSE;

    if (itemId == ITEM_NONE)
        return FALSE;

    pocket = ItemId_GetPocket(itemId) - 1;
    // Check for item slots that contain the item
    for (i = 0; i < gBagPockets[pocket].capacity; i++)
    {
        if (gBagPockets[pocket].itemSlots[i].itemId == itemId)
        {
            u16 quantity;
            // Does this item slot contain enough of the item?
            quantity = GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity);
            if (quantity >= count)
            {
                quantity -= count;
                SetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity, quantity);
                if (quantity == 0)
                    gBagPockets[pocket].itemSlots[i].itemId = ITEM_NONE;
                return TRUE;
            }
            // RS and Emerald check whether there is enough of the
            // item across all stacks.
            // For whatever reason, FR/LG assume there's only one
            // stack of the item.
            else
                return FALSE;
        }
    }
    return FALSE;
}

u8 GetPocketByItemId(u16 itemId)
{
    return ItemId_GetPocket(itemId); // wow such important
}

void ClearItemSlots(struct ItemSlot * slots, u8 capacity)
{
    u32 i;

    for (i = 0; i < capacity; i++)
    {
        slots[i].itemId = ITEM_NONE;
        SetBagItemQuantity(&slots[i].quantity, 0);
    }
}

void ClearPCItemSlots(void)
{
    u32 i;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        gSaveBlock1Ptr->pcItems[i].itemId = ITEM_NONE;
        SetPcItemQuantity(&gSaveBlock1Ptr->pcItems[i].quantity, 0);
    }
}

void ClearBag(void)
{
    u32 i;

    for (i = 0; i < 7; i++)
    {
        ClearItemSlots(gBagPockets[i].itemSlots, gBagPockets[i].capacity);
    }
}

s8 PCItemsGetFirstEmptySlot(void)
{
    s32 i;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (gSaveBlock1Ptr->pcItems[i].itemId == ITEM_NONE)
            return i;
    }

    return -1;
}

u8 CountItemsInPC(void)
{
    u8 count = 0;
    u32 i;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (gSaveBlock1Ptr->pcItems[i].itemId != ITEM_NONE)
            count++;
    }

    return count;
}

bool8 CheckPCHasItem(u16 itemId, u16 count)
{
    u32 i;
    u16 quantity;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (gSaveBlock1Ptr->pcItems[i].itemId == itemId)
        {
            quantity = GetPcItemQuantity(&gSaveBlock1Ptr->pcItems[i].quantity);
            if (quantity >= count)
                return TRUE;
        }
    }

    return FALSE;
}

bool8 AddPCItem(u16 itemId, u16 count)
{
    u32 i;
    u16 quantity;
    s8 idx;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (gSaveBlock1Ptr->pcItems[i].itemId == itemId)
        {
            quantity = GetPcItemQuantity(&gSaveBlock1Ptr->pcItems[i].quantity);
            if (quantity + count <= 999)
            {
                quantity += count;
                SetPcItemQuantity(&gSaveBlock1Ptr->pcItems[i].quantity, quantity);
                return TRUE;
            }
            else
                return FALSE;
        }
    }

    idx = PCItemsGetFirstEmptySlot();
    if (idx == -1)
        return FALSE;

    gSaveBlock1Ptr->pcItems[idx].itemId = itemId;
    SetPcItemQuantity(&gSaveBlock1Ptr->pcItems[idx].quantity, count);
    return TRUE;
}

void RemovePCItem(u16 itemId, u16 count)
{
    u32 i;
    u16 quantity;

    if (itemId == ITEM_NONE)
        return;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (gSaveBlock1Ptr->pcItems[i].itemId == itemId)
            break;
    }

    if (i != PC_ITEMS_COUNT)
    {
        quantity = GetPcItemQuantity(&gSaveBlock1Ptr->pcItems[i].quantity) - count;
        SetPcItemQuantity(&gSaveBlock1Ptr->pcItems[i].quantity, quantity);
        if (quantity == 0)
            gSaveBlock1Ptr->pcItems[i].itemId = ITEM_NONE;
    }
}

void ItemPcCompaction(void)
{
    u16 i, j;
    struct ItemSlot tmp;

    for (i = 0; i < PC_ITEMS_COUNT - 1; i++)
    {
        for (j = i + 1; j < PC_ITEMS_COUNT; j++)
        {
            if (gSaveBlock1Ptr->pcItems[i].itemId == ITEM_NONE)
            {
                tmp = gSaveBlock1Ptr->pcItems[i];
                gSaveBlock1Ptr->pcItems[i] = gSaveBlock1Ptr->pcItems[j];
                gSaveBlock1Ptr->pcItems[j] = tmp;
            }
        }
    }
}

void RegisteredItemHandleBikeSwap(void)
{
    switch (gSaveBlock1Ptr->registeredItem)
    {
    case ITEM_MACH_BIKE:
        gSaveBlock1Ptr->registeredItem = ITEM_ACRO_BIKE;
        break;
    case ITEM_ACRO_BIKE:
        gSaveBlock1Ptr->registeredItem = ITEM_MACH_BIKE;
        break;
    }
}

void SwapItemSlots(struct ItemSlot * a, struct ItemSlot * b)
{
    struct ItemSlot c;
    c = *a;
    *a = *b;
    *b = c;
}

void BagPocketCompaction(struct ItemSlot * slots, u8 capacity)
{
    u16 i, j;

    for (i = 0; i < capacity - 1; i++)
    {
        for (j = i + 1; j < capacity; j++)
        {
            if (GetBagItemQuantity(&slots[i].quantity) == 0)
            {
                SwapItemSlots(&slots[i], &slots[j]);
            }
        }
    }
}

void SortPocketAndPlaceHMsFirst(struct BagPocket * pocket)
{
    u32 i;
    u16 j = 0;
    u32 k;
    struct ItemSlot * buff;

    SortAndCompactBagPocket(pocket);

    for (i = 0; i < pocket->capacity; i++)
    {
        if (pocket->itemSlots[i].itemId == ITEM_NONE && GetBagItemQuantity(&pocket->itemSlots[i].quantity) == 0)
            return;
        if (pocket->itemSlots[i].itemId >= ITEM_HM01 && GetBagItemQuantity(&pocket->itemSlots[i].quantity) != 0)
        {
            for (j = i + 1; j < pocket->capacity; j++)
            {
                if (pocket->itemSlots[j].itemId == ITEM_NONE && GetBagItemQuantity(&pocket->itemSlots[j].quantity) == 0)
                    break;
            }
            break;
        }
    }

    for (k = 0; k < pocket->capacity; k++)
        pocket->itemSlots[k].quantity = GetBagItemQuantity(&pocket->itemSlots[k].quantity);
    buff = AllocZeroed(pocket->capacity * sizeof(struct ItemSlot));
    CpuCopy16(pocket->itemSlots + i, buff, (j - i) * sizeof(struct ItemSlot));
    CpuCopy16(pocket->itemSlots, buff + (j - i), i * sizeof(struct ItemSlot));
    CpuCopy16(buff, pocket->itemSlots, pocket->capacity * sizeof(struct ItemSlot));
    for (k = 0; k < pocket->capacity; k++)
        SetBagItemQuantity(&pocket->itemSlots[k].quantity, pocket->itemSlots[k].quantity);
    Free(buff);
}

void SortAndCompactBagPocket(struct BagPocket * pocket)
{
    u16 i, j;

    for (i = 0; i < pocket->capacity; i++)
    {
        for (j = i + 1; j < pocket->capacity; j++)
        {
            if (GetBagItemQuantity(&pocket->itemSlots[i].quantity) == 0 || (GetBagItemQuantity(&pocket->itemSlots[j].quantity) != 0 && pocket->itemSlots[i].itemId > pocket->itemSlots[j].itemId))
                SwapItemSlots(&pocket->itemSlots[i], &pocket->itemSlots[j]);
        }
    }
}

u16 BagGetItemIdByPocketPosition(u8 pocketId, u16 slotId)
{
    return gBagPockets[pocketId - 1].itemSlots[slotId].itemId;
}

u16 BagGetQuantityByPocketPosition(u8 pocketId, u16 slotId)
{
    return GetBagItemQuantity(&gBagPockets[pocketId - 1].itemSlots[slotId].quantity);
}

u16 BagGetQuantityByItemId(u16 itemId)
{
    u32 i;
    struct BagPocket * pocket = &gBagPockets[ItemId_GetPocket(itemId) - 1];

    for (i = 0; i < pocket->capacity; i++)
    {
        if (pocket->itemSlots[i].itemId == itemId)
            return GetBagItemQuantity(&pocket->itemSlots[i].quantity);
    }

    return 0;
}

void TrySetObtainedItemQuestLogEvent(u16 itemId)
{
    struct QuestLogStruct_809A824
    {
        u16 itemId;
        u8 mapSectionId;
    } * ptr;

    // Only some key items trigger this event
    if
    (
        itemId == ITEM_OAKS_PARCEL
     || itemId == ITEM_POKE_FLUTE
     || itemId == ITEM_SECRET_KEY
     || itemId == ITEM_BIKE_VOUCHER
     || itemId == ITEM_GOLD_TEETH
     || itemId == ITEM_OLD_AMBER
     || itemId == ITEM_CARD_KEY
     || itemId == ITEM_LIFT_KEY
     || itemId == ITEM_HELIX_FOSSIL
     || itemId == ITEM_DOME_FOSSIL
     || itemId == ITEM_SILPH_SCOPE
     || itemId == ITEM_BICYCLE
     || itemId == ITEM_TOWN_MAP
     || itemId == ITEM_VS_SEEKER
     || itemId == ITEM_TEACHY_TV
     || itemId == ITEM_RAINBOW_PASS
     || itemId == ITEM_TEA
     || itemId == ITEM_POWDER_JAR
     || itemId == ITEM_RUBY
     || itemId == ITEM_SAPPHIRE
    )
    {
        if (itemId != ITEM_TOWN_MAP || (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PALLET_TOWN_RIVALS_HOUSE) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(PALLET_TOWN_RIVALS_HOUSE)))
        {
            ptr = malloc(sizeof(*ptr));
            ptr->itemId = itemId;
            ptr->mapSectionId = gMapHeader.regionMapSectionId;
            SetQuestLogEvent(QL_EVENT_OBTAINED_ITEM, (void *)ptr);
            free(ptr);
        }
    }
}

u16 SanitizeItemId(u16 itemId)
{
    if (itemId >= ITEM_N_A)
        return ITEM_NONE;
    return itemId;
}

const u8 * ItemId_GetName(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].name;
}

u16 itemid_get_number(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].itemId;
}

u16 itemid_get_market_price(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].price;
}

u8 ItemId_GetHoldEffect(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].holdEffect;
}

u8 ItemId_GetHoldEffectParam(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].holdEffectParam;
}

const u8 * ItemId_GetDescription(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].description;
}

bool8 itemid_is_unique(u16 itemId)
{
    if(SanitizeItemId(itemId) >= ITEM_TM01 && SanitizeItemId(itemId) <= ITEM_TM50)
        return TRUE;
    return gItems[SanitizeItemId(itemId)].importance;
}

u8 itemid_get_x19(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].exitsBagOnUse;
}

u8 ItemId_GetPocket(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].pocket;
}

u8 ItemId_GetType(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].type;
}

ItemUseFunc ItemId_GetFieldFunc(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].fieldUseFunc;
}

bool8 ItemId_GetBattleUsage(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].battleUsage;
}

ItemUseFunc ItemId_GetBattleFunc(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].battleUseFunc;
}

u8 ItemId_GetSecondaryId(u16 itemId)
{
    return gItems[SanitizeItemId(itemId)].secondaryId;
}

bool8 CheckAssetsForSoftlock(void)
{
    u32 money = GetMoney(&gSaveBlock1Ptr->money);
    u32 i;
    u32 pocket;
    u32 itemWorth;
    u32 maxU32 = 4294967295U;
    if(money >= 200)
        return FALSE;

    for(pocket = POCKET_ITEMS - 1; pocket < POCKET_BERRY_POUCH; pocket++)
    {
        if(pocket == (POCKET_KEY_ITEMS - 1) || pocket == (POCKET_TM_CASE - 1)) //skip KEY_ITEMS and TM_CASE
            continue;
        for(i = 0; i < gBagPockets[pocket].capacity && gBagPockets[pocket].itemSlots[i].itemId != ITEM_NONE; i++)
        {
            itemWorth = ((itemid_get_market_price(gBagPockets[pocket].itemSlots[i].itemId) / 2) * GetBagItemQuantity(&gBagPockets[pocket].itemSlots[i].quantity));
            if(money > 0)
            {
                if(itemWorth > (maxU32 - money)) //checking for overflow
                    return FALSE;   //overflowed, so have enough money    
            }
            money = money + itemWorth;
            if(money >= 200)
                return FALSE;
        }
    }
    return TRUE;
}