#ifndef GUARD_ITEM_MENU_ICONS
#define GUARD_ITEM_MENU_ICONS

#include "global.h"

#ifdef SHOW_OBTAIN_ITEM_DESCRIPTION
void CreateItemIconOnFindMessage(void);
void DestroyItemIconOnFindMessage(void);
#endif // SHOW_OBTAIN_ITEM_DESCRIPTION

extern const struct CompressedSpriteSheet gSpriteSheet_Backpack;
extern const struct CompressedSpriteSheet gSpriteSheet_Satchel;
extern const struct CompressedSpritePalette gSpritePalette_BagOrSatchel;

extern const struct CompressedSpriteSheet gBagSwapSpriteSheet;
extern const struct CompressedSpritePalette gBagSwapSpritePalette;

void ResetItemMenuIconState(void);
void ItemMenuIcons_CreateInsertIndicatorBarHidden(void);
void DestroyItemMenuIcon(bool8 a0);
void CreateItemMenuIcon(u16 itemId, bool8 a0);
void CopyItemIconPicTo4x4Buffer(const void *src, void *dest);
u8 AddItemIconObject(u16 tilesTag, u16 paletteTag, u16 itemId);
u8 AddItemIconObjectWithCustomObjectTemplate(const struct SpriteTemplate * origTemplate, u16 tilesTag, u16 paletteTag, u16 itemId);
void CreateBerryPouchItemIcon(u16 itemId, u8 idx);
void ItemMenuIcons_MoveInsertIndicatorBar(s16 x, u16 y);
void ItemMenuIcons_ToggleInsertIndicatorBarVisibility(bool8 invisible);
void sub_8098528(u8);
void sub_8098580(void);
const void * GetItemIconGfxPtr(u16 itemId, u8 ptrId);
void CreateBagOrSatchelSprite(u8 animNum);

#endif // GUARD_ITEM_MENU_ICONS
