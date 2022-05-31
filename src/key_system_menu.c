#include "global.h"
#include "gflib.h"
#include "scanline_effect.h"
#include "text_window_graphics.h"
#include "main_menu.h"
#include "menu.h"
#include "task.h"
#include "overworld.h"
#include "help_system.h"
#include "text_window.h"
#include "strings.h"
#include "field_fadetransition.h"
#include "gba/m4a_internal.h"

// can't include the one in menu_helpers.h since Task_KeySystemMenu needs bool32 for matching
bool32 MenuHelpers_CallLinkSomething(void);

// Menu items
enum
{
    MENUITEM_VERSION = 0,
    MENUITEM_DIFFICULTY,
    MENUITEM_ADVANCED,
    MENUITEM_CANCEL,
    MENUITEM_COUNT
};

enum
{
    MENUITEM_NUZLOCKE = 0,
    MENUITEM_IV,
    MENUITEM_EV,
    MENUITEM_NO_PMC,
    MENUITEM_EXP_MOD,
    MENUITEM_BACK,
    MENUITEM_COUNT2
};

// Window Ids
enum
{
    WIN_TEXT_KEY,
    WIN_KEYS
};

// RAM symbols
struct KeySystemMenu
{
    /*0x00*/ u16 option[MENUITEM_COUNT];
             u16 subOption[MENUITEM_COUNT2];
    /*0x0E*/ u8 cursorPos;
    /*0x10*/ u8 loadState;
    /*0x11*/ u8 state;
    /*0x12*/ u8 loadPaletteState;
             bool8 inSubMenu;

};

static EWRAM_DATA struct KeySystemMenu *sKeySystemMenuPtr = NULL;

//Function Declarations
static void CB2_InitKeySystemMenu(void);
static void VBlankCB_KeySystemMenu(void);
static void KeySystemMenu_InitCallbacks(void);
static void KeySystemMenu_SetVBlankCallback(void);
static void CB2_KeySystemMenu(void);
static void SetKeySystemMenuTask(void);
static void InitKeySystemMenuBg(void);
static void KeySystemMenu_PickSwitchCancel(void);
static void KeySystemMenu_ResetSpriteData(void);
static bool8 LoadKeySystemMenuPalette(void);
static void Task_KeySystemMenu(u8 taskId);
static u8 KeySystemMenu_ProcessInput(void);
static void BufferKeySystemMenuString(u8 selection);
static void CloseAndSaveKeySystemMenu(u8 taskId);
static void PrintKeySystemMenuHeader(void);
static void DrawKeySystemMenuBg(void);
static void LoadKeySystemMenuItemNames(void);
static void UpdateSettingSelectionDisplay(u16 selection);

// Data Definitions
static const struct WindowTemplate sKeySystemMenuWinTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 7,
        .width = 26,
        .height = 12,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 0x16e
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sKeySystemMenuBgTemplates[] =
{
   {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   },
   {
       .bg = 2,
       .charBaseIndex = 1,
       .mapBaseIndex = 29,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 2,
       .baseTile = 0
   },
};

static const u16 sKeySystemMenuPalette[] = INCBIN_U16("graphics/misc/unk_83cc2e4.gbapal");
static const u16 sKeySystemMenuItemCounts[MENUITEM_COUNT] = {2, 3, 1, 0};
static const u16 sKeySystemSubMenuItemCounts[MENUITEM_COUNT2] = {2, 3, 2, 2, 4, 0};

static const u8 *const sKeySystemMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_VERSION]    = gText_Version,
    [MENUITEM_DIFFICULTY] = gText_Difficulty,
    [MENUITEM_ADVANCED]   = gText_Advanced,
    [MENUITEM_CANCEL]     = gText_OptionMenuSaveAndExit,
};

static const u8 *const sKeySystemSubMenuItemsNames[MENUITEM_COUNT2] ={
    [MENUITEM_NUZLOCKE]   = gText_Nuzlocke,
    [MENUITEM_IV]         = gText_IVCalc,
    [MENUITEM_EV]         = gText_EVCalc,
    [MENUITEM_NO_PMC]     = gText_NoPMC,
    [MENUITEM_EXP_MOD]    = gText_ExpMod,
    [MENUITEM_BACK]       = gText_Back,
};

static const u8 *const sVersionOptions[] =
{
    gText_FireredVersion, 
    gText_LeafgreenVersion
};

static const u8 *const sDifficultyOptions[] =
{
    gText_NormalDifficulty,
    gText_ChallengeDifficulty,
    gText_EasyDifficulty
};

static const u8 *const sAdvancedOptions[] =
{
    gText_BattleScenePressA
};

static const u8 *const sNuzlockeOptions[] =
{
    gText_Nuzlocke_Off,
    gText_Nuzlocke_On
};

static const u8 *const sIVCalcOptions[] =
{
    gText_IVCalcStandard,
    gText_IVCalcPerfect,
    gText_IVCalcZero
};

static const u8 *const sEVCalcOptions[] =
{
    gText_EVCalcStandard,
	gText_EVCalcZero
};

static const u8 *const sExpModOptions[] = 
{
    gText_ExpModZero,
    gText_ExpModHalf,
    gText_ExpModNormal,
    gText_ExpModTwice
};

static const u8 sKeySystemMenuPickSwitchCancelTextColor[] = {TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
static const u8 sKeySystemMenuTextColor[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED};

// Functions
static void CB2_InitKeySystemMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_KeySystemMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_KeySystemMenuFromContinueScreen(void)
{
    u32 i;
    if (gMain.savedCallback == NULL)
        gMain.savedCallback = CB2_InitMainMenu; //changed to continue screen callback
    sKeySystemMenuPtr = AllocZeroed(sizeof(struct KeySystemMenu));
    sKeySystemMenuPtr->loadState = 0;
    sKeySystemMenuPtr->loadPaletteState = 0;
    sKeySystemMenuPtr->state = 0;
    sKeySystemMenuPtr->cursorPos = 0;
    sKeySystemMenuPtr->inSubMenu = 0;
    sKeySystemMenuPtr->option[MENUITEM_VERSION] = gSaveBlock1Ptr->keyFlags.version;
    sKeySystemMenuPtr->option[MENUITEM_DIFFICULTY] = gSaveBlock1Ptr->keyFlags.difficulty;
    sKeySystemMenuPtr->option[MENUITEM_ADVANCED] = 0;
    sKeySystemMenuPtr->subOption[MENUITEM_NUZLOCKE] = gSaveBlock1Ptr->keyFlags.nuzlocke;
    sKeySystemMenuPtr->subOption[MENUITEM_IV] = gSaveBlock1Ptr->keyFlags.ivCalcMode;
    sKeySystemMenuPtr->subOption[MENUITEM_EV] = gSaveBlock1Ptr->keyFlags.evCalcMode;
    sKeySystemMenuPtr->subOption[MENUITEM_NO_PMC] = gSaveBlock1Ptr->keyFlags.noPMC;
    sKeySystemMenuPtr->subOption[MENUITEM_EXP_MOD] = gSaveBlock1Ptr->keyFlags.expMod;
    if(gSaveBlock1Ptr->keyFlags.changedCalcMode != 1)
        gSaveBlock1Ptr->keyFlags.changedCalcMode = 0;
    gSaveBlock1Ptr->keyFlags.inKeySystemMenu = 1;

    for (i = 0; i < MENUITEM_COUNT - 1; i++)
    {
        if (sKeySystemMenuPtr->option[i] > (sKeySystemMenuItemCounts[i]) - 1)
            sKeySystemMenuPtr->option[i] = 0;
    }
    for (i = 0; i < MENUITEM_COUNT2 - 1; i++)
    {
        if (sKeySystemMenuPtr->subOption[i] > (sKeySystemSubMenuItemCounts[i]) - 1)
            sKeySystemMenuPtr->subOption[i] = 0;
    }
    SetHelpContext(HELPCONTEXT_KEY_SYSTEM);
    SetMainCallback2(CB2_KeySystemMenu);
}

static void KeySystemMenu_InitCallbacks(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void KeySystemMenu_SetVBlankCallback(void)
{
    SetVBlankCallback(VBlankCB_KeySystemMenu);
}

static void CB2_KeySystemMenu(void)
{
    u8 i, state;
    state = sKeySystemMenuPtr->state;
    switch (state)
    {
    case 0:
        KeySystemMenu_InitCallbacks();
        break;
    case 1:
        InitKeySystemMenuBg();
        break;
    case 2:
        KeySystemMenu_ResetSpriteData();
        break;
    case 3:
        if (LoadKeySystemMenuPalette() != TRUE)
            return;
        break;
    case 4:
        PrintKeySystemMenuHeader();
        break;
    case 5:
        DrawKeySystemMenuBg();
        break;
    case 6:
        LoadKeySystemMenuItemNames();
        break;
    case 7:
        if(!sKeySystemMenuPtr->inSubMenu)
        {
            for (i = 0; i < MENUITEM_COUNT; i++)
                BufferKeySystemMenuString(i);
        }
        else
        {
            for (i = 0; i < MENUITEM_COUNT2; i++)
                BufferKeySystemMenuString(i);
        }
        break;
    case 8:
        UpdateSettingSelectionDisplay(sKeySystemMenuPtr->cursorPos);
        break;
    case 9:
        KeySystemMenu_PickSwitchCancel();
        break;
    default:
        SetKeySystemMenuTask();
		break;
    }
    sKeySystemMenuPtr->state++;
}

static void SetKeySystemMenuTask(void)
{
    CreateTask(Task_KeySystemMenu, 0);
    SetMainCallback2(CB2_InitKeySystemMenu);
}

static void InitKeySystemMenuBg(void)
{
    void * dest = (void *)VRAM;
    DmaClearLarge16(3, dest, VRAM_SIZE, 0x1000);    
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);    
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sKeySystemMenuBgTemplates, NELEMS(sKeySystemMenuBgTemplates));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    InitWindows(sKeySystemMenuWinTemplates);
    DeactivateAllTextPrinters();
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_EFFECT_LIGHTEN);
    SetGpuReg(REG_OFFSET_BLDY, BLDCNT_TGT1_BG1);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
};

static void KeySystemMenu_PickSwitchCancel(void)
{
    s32 x;
    FillWindowPixelBuffer(2, PIXEL_FILL(15)); 
    if(!sKeySystemMenuPtr->inSubMenu)
    {
        if(sKeySystemMenuPtr->cursorPos == MENUITEM_ADVANCED)
        {
            x = 0xE4 - GetStringWidth(0, gText_PickSwitchCancelA, 0);
            AddTextPrinterParameterized3(2, 0, x, 0, sKeySystemMenuPickSwitchCancelTextColor, 0, gText_PickSwitchCancelA);
        }
        else if(sKeySystemMenuPtr->cursorPos == MENUITEM_CANCEL)
        {
            x = 0xE4 - GetStringWidth(0, gText_PickSwitchExit, 0);
            AddTextPrinterParameterized3(2, 0, x, 0, sKeySystemMenuPickSwitchCancelTextColor, 0, gText_PickSwitchExit);
        }
        else
        {
            x = 0xE4 - GetStringWidth(0, gText_PickSwitchCancel, 0);
            AddTextPrinterParameterized3(2, 0, x, 0, sKeySystemMenuPickSwitchCancelTextColor, 0, gText_PickSwitchCancel);
        }
    }
    else
    {
        x = 0xE4 - GetStringWidth(0, gText_PickSwitchBack, 0);
        AddTextPrinterParameterized3(2, 0, x, 0, sKeySystemMenuPickSwitchCancelTextColor, 0, gText_PickSwitchBack);
    }
    PutWindowTilemap(2);
    CopyWindowToVram(2, COPYWIN_BOTH);
}

static void KeySystemMenu_ResetSpriteData(void)
{
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetTasks();
    ScanlineEffect_Stop();
}

static bool8 LoadKeySystemMenuPalette(void)
{
    switch (sKeySystemMenuPtr->loadPaletteState)
    {
    case 0:
        LoadBgTiles(1, GetUserFrameGraphicsInfo(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1AA);
        break;
    case 1:
        LoadPalette(GetUserFrameGraphicsInfo(gSaveBlock2Ptr->optionsWindowFrameType)->palette, 0x20, 0x20);
        break;
    case 2:
        LoadPalette(sKeySystemMenuPalette, 0x10, 0x20);
        LoadPalette(stdpal_get(2), 0xF0, 0x20);
        break;
    case 3:
        DrawWindowBorderWithStdpal3(1, 0x1B3, 0x30);
        break;
    default:
        return TRUE;
    }
    sKeySystemMenuPtr->loadPaletteState++;
    return FALSE;
}

static void Task_KeySystemMenu(u8 taskId)
{
    switch (sKeySystemMenuPtr->loadState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        KeySystemMenu_SetVBlankCallback();
        sKeySystemMenuPtr->loadState++;
        break;
    case 1:
        if (gPaletteFade.active)
            return;
        sKeySystemMenuPtr->loadState++;
        break;
    case 2:
        if (((bool32)MenuHelpers_CallLinkSomething()) == TRUE)
            break;
        switch (KeySystemMenu_ProcessInput())
        {
        case 0:
            break;
        case 1:
            sKeySystemMenuPtr->loadState++;
            break;
        case 2:
            LoadBgTiles(1, GetUserFrameGraphicsInfo(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1AA);
            LoadPalette(GetUserFrameGraphicsInfo(gSaveBlock2Ptr->optionsWindowFrameType)->palette, 0x20, 0x20);
            BufferKeySystemMenuString(sKeySystemMenuPtr->cursorPos);
            break;
        case 3:
            UpdateSettingSelectionDisplay(sKeySystemMenuPtr->cursorPos);
            break;
        case 4:
            BufferKeySystemMenuString(sKeySystemMenuPtr->cursorPos);
            break;
        case 6:
            if(!sKeySystemMenuPtr->inSubMenu)
            {
                sKeySystemMenuPtr->inSubMenu = TRUE;
                PrintKeySystemMenuHeader();
                sKeySystemMenuPtr->state = 6;
                sKeySystemMenuPtr->loadState = 1;
                sKeySystemMenuPtr->cursorPos = 0;
                SetHelpContext(HELPCONTEXT_KEY_SYSTEM_SUBMENU);
                DestroyTask(taskId);
                SetMainCallback2(CB2_KeySystemMenu);
                break;
            }
            else
            {
                sKeySystemMenuPtr->inSubMenu = FALSE;
                PrintKeySystemMenuHeader();
                sKeySystemMenuPtr->state = 6;
                sKeySystemMenuPtr->loadState = 1;
                sKeySystemMenuPtr->cursorPos = MENUITEM_ADVANCED;
                SetHelpContext(HELPCONTEXT_KEY_SYSTEM);
                DestroyTask(taskId);
                SetMainCallback2(CB2_KeySystemMenu);
                break;
            }
        }
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        sKeySystemMenuPtr->loadState++;
        break;
    case 4:
        if (gPaletteFade.active)
            return;
        sKeySystemMenuPtr->loadState++;
        break;
    case 5:
        CloseAndSaveKeySystemMenu(taskId);
        break;
    }
}

static u8 KeySystemMenu_ProcessInput(void)
{ 
    u16 current;
    u16* curr;

    if (JOY_REPT(DPAD_RIGHT))
    {
        if(!sKeySystemMenuPtr->inSubMenu)
        {        
            current = sKeySystemMenuPtr->option[(sKeySystemMenuPtr->cursorPos)];
            if (current == (sKeySystemMenuItemCounts[sKeySystemMenuPtr->cursorPos] - 1))
                sKeySystemMenuPtr->option[sKeySystemMenuPtr->cursorPos] = 0;
            else
                sKeySystemMenuPtr->option[sKeySystemMenuPtr->cursorPos] = current + 1;
            return 4;
        }
        else
        {
            current = sKeySystemMenuPtr->subOption[(sKeySystemMenuPtr->cursorPos)];
            if (current == (sKeySystemSubMenuItemCounts[sKeySystemMenuPtr->cursorPos] - 1))
                sKeySystemMenuPtr->subOption[sKeySystemMenuPtr->cursorPos] = 0;
            else
                sKeySystemMenuPtr->subOption[sKeySystemMenuPtr->cursorPos] = current + 1;
            return 4;
        }
    }
    else if (JOY_REPT(DPAD_LEFT))
    {
        if(!sKeySystemMenuPtr->inSubMenu)
        {
            curr = &sKeySystemMenuPtr->option[sKeySystemMenuPtr->cursorPos];
            if (*curr == 0)
                *curr = sKeySystemMenuItemCounts[sKeySystemMenuPtr->cursorPos] - 1;
            else
                --*curr;
            return 4;
        }
        else
        {
            curr = &sKeySystemMenuPtr->subOption[sKeySystemMenuPtr->cursorPos];
            if (*curr == 0)
                *curr = sKeySystemSubMenuItemCounts[sKeySystemMenuPtr->cursorPos] - 1;
            else
                --*curr;
            return 4;
        }
    }
    else if (JOY_REPT(DPAD_UP))
    {
        if(!sKeySystemMenuPtr->inSubMenu)
        {
            if (sKeySystemMenuPtr->cursorPos == MENUITEM_VERSION)
                sKeySystemMenuPtr->cursorPos = MENUITEM_CANCEL;
            else
                sKeySystemMenuPtr->cursorPos = sKeySystemMenuPtr->cursorPos - 1;
        }
        else
        {
            if (sKeySystemMenuPtr->cursorPos == MENUITEM_NUZLOCKE)
                sKeySystemMenuPtr->cursorPos = MENUITEM_BACK;
            else
                sKeySystemMenuPtr->cursorPos = sKeySystemMenuPtr->cursorPos - 1;
        }
        KeySystemMenu_PickSwitchCancel();
        return 3;             
    }
    else if (JOY_REPT(DPAD_DOWN))
    {
        if(!sKeySystemMenuPtr->inSubMenu)
        {
            if (sKeySystemMenuPtr->cursorPos == MENUITEM_CANCEL)
                sKeySystemMenuPtr->cursorPos = MENUITEM_VERSION;
            else
                sKeySystemMenuPtr->cursorPos = sKeySystemMenuPtr->cursorPos + 1;
        }
        else
        {
            if (sKeySystemMenuPtr->cursorPos == MENUITEM_BACK)
                sKeySystemMenuPtr->cursorPos = MENUITEM_NUZLOCKE;
            else
                sKeySystemMenuPtr->cursorPos = sKeySystemMenuPtr->cursorPos + 1;
        }
        KeySystemMenu_PickSwitchCancel();
        return 3;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if(!sKeySystemMenuPtr->inSubMenu)
        {
            if(sKeySystemMenuPtr->cursorPos == MENUITEM_ADVANCED)
                return 6;
            if(sKeySystemMenuPtr->cursorPos == MENUITEM_CANCEL)
                return 1;
        }
        else
            return 6;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if(sKeySystemMenuPtr->inSubMenu)
            return 6;
        else
            return 1;
    }
    else
    {
        return 0;
    }
}

static void BufferKeySystemMenuString(u8 selection)
{
    u8 str[20];
    u8 buf[12];
    u8 dst[3];
    u8 x, y;
    
    memcpy(dst, sKeySystemMenuTextColor, 3);
    x = 0x69;
    y = ((GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) - 1) * selection) + 2;
    FillWindowPixelRect(1, 1, x, y, 0x6F, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT));

    if(!sKeySystemMenuPtr->inSubMenu)
    {
        switch (selection)
        {
            case MENUITEM_VERSION:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sVersionOptions[sKeySystemMenuPtr->option[selection]]);
                break;
            case MENUITEM_DIFFICULTY:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sDifficultyOptions[sKeySystemMenuPtr->option[selection]]);
                break;
            case MENUITEM_ADVANCED:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sAdvancedOptions[sKeySystemMenuPtr->option[selection]]);
                break;
            default:
                break;
        }
    }
    else
    {
        switch (selection)
        {
            case MENUITEM_NUZLOCKE:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sNuzlockeOptions[sKeySystemMenuPtr->subOption[selection]]);
                break;
            case MENUITEM_IV:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sIVCalcOptions[sKeySystemMenuPtr->subOption[selection]]);
                break;
            case MENUITEM_EV:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sEVCalcOptions[sKeySystemMenuPtr->subOption[selection]]);
                break;
            case MENUITEM_NO_PMC:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sNuzlockeOptions[sKeySystemMenuPtr->subOption[selection]]);
                break;
            case MENUITEM_EXP_MOD:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sExpModOptions[sKeySystemMenuPtr->subOption[selection]]);
                break;
            default:
                break;
        }
    }
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_BOTH);
}

static void CloseAndSaveKeySystemMenu(u8 taskId)
{
    gFieldCallback = FieldCB_DefaultWarpExit;
    SetMainCallback2(gMain.savedCallback);
    FreeAllWindowBuffers();
    gSaveBlock1Ptr->keyFlags.version = sKeySystemMenuPtr->option[MENUITEM_VERSION];
    gSaveBlock1Ptr->keyFlags.difficulty = sKeySystemMenuPtr->option[MENUITEM_DIFFICULTY];
    gSaveBlock1Ptr->keyFlags.nuzlocke = sKeySystemMenuPtr->subOption[MENUITEM_NUZLOCKE];
    if(gSaveBlock1Ptr->keyFlags.ivCalcMode != sKeySystemMenuPtr->subOption[MENUITEM_IV] || gSaveBlock1Ptr->keyFlags.evCalcMode != sKeySystemMenuPtr->subOption[MENUITEM_EV])
    {
        gSaveBlock1Ptr->keyFlags.changedCalcMode = 1; //iv or ev calc mode changed, recalculate party stats on saveload.
    }
    gSaveBlock1Ptr->keyFlags.ivCalcMode = sKeySystemMenuPtr->subOption[MENUITEM_IV];
    gSaveBlock1Ptr->keyFlags.evCalcMode = sKeySystemMenuPtr->subOption[MENUITEM_EV];
    gSaveBlock1Ptr->keyFlags.noPMC = sKeySystemMenuPtr->subOption[MENUITEM_NO_PMC];
    gSaveBlock1Ptr->keyFlags.expMod = sKeySystemMenuPtr->subOption[MENUITEM_EXP_MOD];
    gSaveBlock1Ptr->keyFlags.inKeySystemMenu = 0;
    FREE_AND_SET_NULL(sKeySystemMenuPtr);
    DestroyTask(taskId);
}

static void PrintKeySystemMenuHeader(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    if(!sKeySystemMenuPtr->inSubMenu)
        AddTextPrinterParameterized(WIN_TEXT_KEY, 2, gText_KeySystemSettings, 8, 1, TEXT_SPEED_FF, NULL);
    else
        AddTextPrinterParameterized(WIN_TEXT_KEY, 2, gText_Advanced, 8, 1, TEXT_SPEED_FF, NULL);
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_BOTH);
}

static void DrawKeySystemMenuBg(void)
{
    u8 h;
    h = 2;
    
    FillBgTilemapBufferRect(1, 0x1B3, 1, 2, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1B4, 2, 2, 0x1B, 1, 3);
    FillBgTilemapBufferRect(1, 0x1B5, 0x1C, 2, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1B6, 1, 3, 1, h, 3);
    FillBgTilemapBufferRect(1, 0x1B8, 0x1C, 3, 1, h, 3);
    FillBgTilemapBufferRect(1, 0x1B9, 1, 5, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1BA, 2, 5, 0x1B, 1, 3);
    FillBgTilemapBufferRect(1, 0x1BB, 0x1C, 5, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1AA, 1, 6, 1, 1, h);
    FillBgTilemapBufferRect(1, 0x1AB, 2, 6, 0x1A, 1, h);
    FillBgTilemapBufferRect(1, 0x1AC, 0x1C, 6, 1, 1, h);
    FillBgTilemapBufferRect(1, 0x1AD, 1, 7, 1, 0x10, h);
    FillBgTilemapBufferRect(1, 0x1AF, 0x1C, 7, 1, 0x10, h);
    FillBgTilemapBufferRect(1, 0x1B0, 1, 0x13, 1, 1, h);
    FillBgTilemapBufferRect(1, 0x1B1, 2, 0x13, 0x1A, 1, h);
    FillBgTilemapBufferRect(1, 0x1B2, 0x1C, 0x13, 1, 1, h);
    CopyBgTilemapBufferToVram(1);
}

static void LoadKeySystemMenuItemNames(void)
{
    u32 i;
    
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    if(!sKeySystemMenuPtr->inSubMenu)
    {
        for (i = 0; i < MENUITEM_COUNT; i++)
        {
            AddTextPrinterParameterized(WIN_KEYS, 2, sKeySystemMenuItemsNames[i], 8, (u8)((i * (GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT))) + 2) - i, TEXT_SPEED_FF, NULL);    
        }
    }
    else
    {
        for (i = 0; i < MENUITEM_COUNT2; i++)
        {
            AddTextPrinterParameterized(WIN_KEYS, 2, sKeySystemMenuItemsNames[i + MENUITEM_COUNT], 8, (u8)((i * (GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT))) + 2) - i, TEXT_SPEED_FF, NULL);    
        }
    }
}

static void UpdateSettingSelectionDisplay(u16 selection)
{
    u16 maxLetterHeight, y;
    
    maxLetterHeight = GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT);
    y = selection * (maxLetterHeight - 1) + 0x3A;
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(y, y + maxLetterHeight));
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0x10, 0xE0));
}
