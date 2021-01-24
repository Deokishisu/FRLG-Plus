#include "global.h"
#include "gflib.h"
#include "event_data.h"
#include "pokedex.h"
#include "region_map.h"
#include "save_menu_util.h"
#include "strings.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "constants/map_types.h"
#include "constants/region_map_sections.h"

void SaveStatToString(u8 gameStatId, u8 *dest0, u8 color)
{
    int nBadges;
    int flagId;

    u8 *dest = dest0;
    *dest++ = EXT_CTRL_CODE_BEGIN;
    *dest++ = EXT_CTRL_CODE_COLOR;
    *dest++ = color;
    *dest++ = EXT_CTRL_CODE_BEGIN;
    *dest++ = EXT_CTRL_CODE_SHADOW;
    *dest++ = color + 1;
    switch (gameStatId)
    {
    case SAVE_STAT_NAME:
        dest = StringCopy(dest, gSaveBlock2Ptr->playerName);
        break;
    case SAVE_STAT_POKEDEX:
        if (IsNationalPokedexEnabled())
            dest = ConvertIntToDecimalStringN(dest, GetNationalPokedexCount(1), STR_CONV_MODE_LEFT_ALIGN, 3);
        else
            dest = ConvertIntToDecimalStringN(dest, GetKantoPokedexCount(1), STR_CONV_MODE_LEFT_ALIGN, 3);
        break;
    case SAVE_STAT_TIME:
        dest = ConvertIntToDecimalStringN(dest, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
        *dest++ = CHAR_COLON;
        dest = ConvertIntToDecimalStringN(dest, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
        break;
    case SAVE_STAT_TIME_HR_RT_ALIGN:
        dest = ConvertIntToDecimalStringN(dest, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_RIGHT_ALIGN, 3);
        *dest++ = CHAR_COLON;
        dest = ConvertIntToDecimalStringN(dest, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
        break;
    case SAVE_STAT_LOCATION:
        GetMapNameGeneric(dest, gMapHeader.regionMapSectionId);
        if(gMapHeader.mapType == MAP_TYPE_UNDERWATER)
        {
            GetMapNameGeneric(dest, MAPSEC_UNDERWATER_124);
        }
        else if(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(RS_BATTLE_TOWER) && (gSaveBlock1Ptr->location.mapNum >= MAP_NUM(RS_BATTLE_TOWER)
        && gSaveBlock1Ptr->location.mapNum <= MAP_NUM(RS_BATTLE_TOWER_BATTLE_ROOM))) //overwrite Battle Frontier name
        {
            dest = StringCopy(dest, gText_BattleTower);
        }
        break;
    case SAVE_STAT_BADGES:
        for (flagId = FLAG_BADGE01_GET, nBadges = 0; flagId < FLAG_BADGE01_GET + 8; flagId++)
        {
            if (FlagGet(flagId))
                nBadges++;
        }
        *dest++ = nBadges + CHAR_0;
        *dest++ = 10; // 'こ'
        *dest++ = EOS;
        break;
    }
}

