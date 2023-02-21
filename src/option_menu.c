#include "global.h"
#include "gflib.h"
#include "scanline_effect.h"
#include "text_window_graphics.h"
#include "menu.h"
#include "task.h"
#include "overworld.h"
#include "help_system.h"
#include "text_window.h"
#include "strings.h"
#include "event_data.h"
#include "field_fadetransition.h"
#include "gba/m4a_internal.h"

// can't include the one in menu_helpers.h since Task_OptionMenu needs bool32 for matching
bool32 MenuHelpers_CallLinkSomething(void);

// Menu items
enum
{
    MENUITEM_TEXTSPEED = 0,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_BUTTONMODE,
    MENUITEM_FRAMETYPE,
    MENUITEM_CANCEL,
    MENUITEM_COUNT
};

enum
{
    MENUITEM_BATTLETRANSITIONS = 0,
    MENUITEM_BATTLEINTROANIM,
    MENUITEM_MOVEANIMATIONS,
    MENUITEM_HPBARANIMSPEED,
    MENUITEM_EXPBARANIMSPEED,
    MENUITEM_THROWANIM,
    MENUITEM_BACK,
    MENUITEM_COUNT2
};

// Window Ids
enum
{
    WIN_TEXT_OPTION,
    WIN_OPTIONS
};

// RAM symbols
struct OptionMenu
{
    /*0x00*/ u16 option[MENUITEM_COUNT];
    /*0x0E*/ u8 cursorPos;
             u16 subOption[MENUITEM_COUNT2];
    /*0x10*/ u8 loadState;
    /*0x11*/ u8 state;
    /*0x12*/ u8 loadPaletteState;
             bool8 inSubMenu;
};

static EWRAM_DATA struct OptionMenu *sOptionMenuPtr = NULL;

//Function Declarataions
static void CB2_InitOptionMenu(void);
static void VBlankCB_OptionMenu(void);
static void OptionMenu_InitCallbacks(void);
static void OptionMenu_SetVBlankCallback(void);
static void CB2_OptionMenu(void);
static void SetOptionMenuTask(void);
static void InitOptionMenuBg(void);
static void OptionMenu_PickSwitchCancel(void);
static void OptionMenu_ResetSpriteData(void);
static bool8 LoadOptionMenuPalette(void);
static void Task_OptionMenu(u8 taskId);
static u8 OptionMenu_ProcessInput(void);
static void BufferOptionMenuString(u8 selection);
static void CloseAndSaveOptionMenu(u8 taskId);
static void PrintOptionMenuHeader(void);
static void DrawOptionMenuBg(void);
static void LoadOptionMenuItemNames(void);
static void UpdateSettingSelectionDisplay(u16 selection);

// Data Definitions
static const struct WindowTemplate sOptionMenuWinTemplates[] =
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

static const struct BgTemplate sOptionMenuBgTemplates[] =
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

static const u16 sOptionMenuPalette[] = INCBIN_U16("graphics/misc/unk_83cc2e4.gbapal");
static const u16 sOptionMenuItemCounts[MENUITEM_COUNT]     = {4, 1, 3, 2, 3, 11, 0};
static const u16 sOptionSubMenuItemCounts[MENUITEM_COUNT2] = {2, 2, 2, 4, 2, 2, 0};

static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_BATTLESCENE] = gText_BattleScene,
    [MENUITEM_BATTLESTYLE] = gText_BattleStyle,
    [MENUITEM_SOUND]       = gText_Sound,
    [MENUITEM_BUTTONMODE]  = gText_ButtonMode,
    [MENUITEM_FRAMETYPE]   = gText_Frame,
    [MENUITEM_CANCEL]      = gText_OptionMenuSaveAndExit,
};

static const u8 *const sOptionSubmenuItemsNames[MENUITEM_COUNT2] =
{
    [MENUITEM_BATTLETRANSITIONS] = gText_BattleTransitions,
    [MENUITEM_BATTLEINTROANIM] = gText_BattleIntroAnimation,
    [MENUITEM_MOVEANIMATIONS] = gText_MoveAnims,
    [MENUITEM_HPBARANIMSPEED] = gText_HpBarAnimSpeed,
    [MENUITEM_EXPBARANIMSPEED] = gText_ExpBarAnimSpeed,
    [MENUITEM_THROWANIM] = gText_ThrowAnim,
    [MENUITEM_BACK] = gText_Back,
};


static const u8 *const sTextSpeedOptions[] =
{
    gText_TextSpeedSlow, 
    gText_TextSpeedMid, 
    gText_TextSpeedFast,
    gText_TextSpeedInstant
};

static const u8 *const sBattleSceneOptions[] =
{
    gText_BattleScenePressA
};

static const u8 *const sBattleStyleOptions[] =
{
    gText_BattleStylePredict,
    gText_BattleStyleShift,
    gText_BattleStyleSet
};

static const u8 *const sSoundOptions[] =
{
    gText_SoundMono, 
    gText_SoundStereo
};

static const u8 *const sButtonTypeOptions[] =
{
    gText_ButtonTypeHelp,
    gText_ButtonTypeLR,
    gText_ButtonTypeLEqualsA
};

static const u8 *const sBattleTransitionOptions[] = 
{
    gText_BattleSceneOn, 
    gText_BattleSceneOff
};

static const u8 *const sBattleIntroAnimOptions[] = 
{
    gText_BattleSceneOn, 
    gText_BattleSceneOff
};

static const u8 *const sMoveAnimOptions[] = 
{
    gText_BattleSceneOn, 
    gText_BattleSceneOff
};

static const u8 *const sHpBarAnimSpeedOptions[] = 
{
    gText_IVCalcStandard, 
    gText_TextSpeedFast,
    gText_TextSpeedFaster,
    gText_TextSpeedInstant
};

static const u8 *const sExpBarAnimSpeedOptions[] = 
{
    gText_IVCalcStandard, 
    gText_TextSpeedInstant
};

static const u8 *const sThrowAnimOptions[] =
{
    gText_BattleSceneOn,
    gText_BattleSceneOff
};

static const u8 sOptionMenuPickSwitchCancelTextColor[] = {TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
static const u8 sOptionMenuTextColor[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED};

// Functions
static void CB2_InitOptionMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_OptionMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_OptionsMenuFromStartMenu(void)
{
    u32 i;
    
    if (gMain.savedCallback == NULL)
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sOptionMenuPtr = AllocZeroed(sizeof(struct OptionMenu));
    sOptionMenuPtr->loadState = 0;
    sOptionMenuPtr->loadPaletteState = 0;
    sOptionMenuPtr->state = 0;
    sOptionMenuPtr->cursorPos = 0;
    sOptionMenuPtr->inSubMenu = 0;
    sOptionMenuPtr->option[MENUITEM_TEXTSPEED] = gSaveBlock2Ptr->optionsTextSpeed;
    sOptionMenuPtr->option[MENUITEM_BATTLESCENE] = 0;
    sOptionMenuPtr->option[MENUITEM_BATTLESTYLE] = gSaveBlock2Ptr->optionsBattleStyle;
    sOptionMenuPtr->option[MENUITEM_SOUND] = gSaveBlock2Ptr->optionsSound;
    sOptionMenuPtr->option[MENUITEM_BUTTONMODE] = gSaveBlock2Ptr->optionsButtonMode;
    sOptionMenuPtr->option[MENUITEM_FRAMETYPE] = gSaveBlock2Ptr->optionsWindowFrameType;
    sOptionMenuPtr->subOption[MENUITEM_BATTLETRANSITIONS] = gSaveBlock2Ptr->optionsBattleTransitions;
    sOptionMenuPtr->subOption[MENUITEM_BATTLEINTROANIM] = gSaveBlock2Ptr->optionsBattleIntroAnim;
    sOptionMenuPtr->subOption[MENUITEM_MOVEANIMATIONS] = gSaveBlock2Ptr->optionsBattleSceneOff;
    sOptionMenuPtr->subOption[MENUITEM_HPBARANIMSPEED] = gSaveBlock2Ptr->optionsHpBarAnimSpeed;
    sOptionMenuPtr->subOption[MENUITEM_EXPBARANIMSPEED] = gSaveBlock2Ptr->optionsExpBarAnimSpeed;
    sOptionMenuPtr->subOption[MENUITEM_THROWANIM] = gSaveBlock2Ptr->optionsThrowAnim;
    
    for (i = 0; i < MENUITEM_COUNT - 1; i++)
    {
        if (sOptionMenuPtr->option[i] > (sOptionMenuItemCounts[i]) - 1)
            sOptionMenuPtr->option[i] = 0;
    }
    for (i = 0; i < MENUITEM_COUNT2 - 1; i++)
    {
        if (sOptionMenuPtr->subOption[i] > (sOptionSubMenuItemCounts[i]) - 1)
            sOptionMenuPtr->subOption[i] = 0;
    }
    FlagSet(FLAG_SYS_IN_OPTIONS_MENU);
    SetHelpContext(HELPCONTEXT_OPTIONS);
    SetMainCallback2(CB2_OptionMenu);
}

static void OptionMenu_InitCallbacks(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void OptionMenu_SetVBlankCallback(void)
{
    SetVBlankCallback(VBlankCB_OptionMenu);
}

static void CB2_OptionMenu(void)
{
    u8 i, state;
    state = sOptionMenuPtr->state;
    switch (state)
    {
    case 0:
        OptionMenu_InitCallbacks();
        break;
    case 1:
        InitOptionMenuBg();
        break;
    case 2:
        OptionMenu_ResetSpriteData();
        break;
    case 3:
        if (LoadOptionMenuPalette() != TRUE)
            return;
        break;
    case 4:
        PrintOptionMenuHeader();
        break;
    case 5:
        DrawOptionMenuBg();
        break;
    case 6:
        LoadOptionMenuItemNames();
        break;
    case 7:
        if(!sOptionMenuPtr->inSubMenu)
        {
            for (i = 0; i < MENUITEM_COUNT; i++)
                BufferOptionMenuString(i);
        }
        else
        {
            for (i = 0; i < MENUITEM_COUNT2; i++)
                BufferOptionMenuString(i);
        }
        break;
    case 8:
        UpdateSettingSelectionDisplay(sOptionMenuPtr->cursorPos);
        break;
    case 9:
        OptionMenu_PickSwitchCancel();
        break;
    default:
        SetOptionMenuTask();
        break;
    }
    sOptionMenuPtr->state++;
}

static void SetOptionMenuTask(void)
{
    CreateTask(Task_OptionMenu, 0);
    SetMainCallback2(CB2_InitOptionMenu);
}

static void InitOptionMenuBg(void)
{
    void * dest = (void *)VRAM;
    DmaClearLarge16(3, dest, VRAM_SIZE, 0x1000);    
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);    
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sOptionMenuBgTemplates, NELEMS(sOptionMenuBgTemplates));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    InitWindows(sOptionMenuWinTemplates);
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

static void OptionMenu_PickSwitchCancel(void)
{
    s32 x;
    FillWindowPixelBuffer(2, PIXEL_FILL(15)); 
    if(!sOptionMenuPtr->inSubMenu)
    {
        if(sOptionMenuPtr->cursorPos == MENUITEM_BATTLESCENE)
        {
            x = 0xE4 - GetStringWidth(0, gText_PickSwitchCancelA, 0);
            AddTextPrinterParameterized3(2, 0, x, 0, sOptionMenuPickSwitchCancelTextColor, 0, gText_PickSwitchCancelA);
        }
        else if(sOptionMenuPtr->cursorPos == MENUITEM_CANCEL)
        {
            x = 0xE4 - GetStringWidth(0, gText_PickSwitchExit, 0);
            AddTextPrinterParameterized3(2, 0, x, 0, sOptionMenuPickSwitchCancelTextColor, 0, gText_PickSwitchExit);
        }
        else
        {
            x = 0xE4 - GetStringWidth(0, gText_PickSwitchCancel, 0);
            AddTextPrinterParameterized3(2, 0, x, 0, sOptionMenuPickSwitchCancelTextColor, 0, gText_PickSwitchCancel);
        }
    }
    else
    {
        x = 0xE4 - GetStringWidth(0, gText_PickSwitchBack, 0);
        AddTextPrinterParameterized3(2, 0, x, 0, sOptionMenuPickSwitchCancelTextColor, 0, gText_PickSwitchBack);
    }
    PutWindowTilemap(2);
    CopyWindowToVram(2, COPYWIN_BOTH);
}

static void OptionMenu_ResetSpriteData(void)
{
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetTasks();
    ScanlineEffect_Stop();
}

static bool8 LoadOptionMenuPalette(void)
{
    switch (sOptionMenuPtr->loadPaletteState)
    {
    case 0:
        LoadBgTiles(1, GetUserFrameGraphicsInfo(sOptionMenuPtr->option[MENUITEM_FRAMETYPE])->tiles, 0x120, 0x1AA);
        break;
    case 1:
        LoadPalette(GetUserFrameGraphicsInfo(sOptionMenuPtr->option[MENUITEM_FRAMETYPE])->palette, 0x20, 0x20);
        break;
    case 2:
        LoadPalette(sOptionMenuPalette, 0x10, 0x20);
        LoadPalette(stdpal_get(2), 0xF0, 0x20);
        break;
    case 3:
        DrawWindowBorderWithStdpal3(1, 0x1B3, 0x30);
        break;
    default:
        return TRUE;
    }
    sOptionMenuPtr->loadPaletteState++;
    return FALSE;
}

static void Task_OptionMenu(u8 taskId)
{
    switch (sOptionMenuPtr->loadState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        OptionMenu_SetVBlankCallback();
        sOptionMenuPtr->loadState++;
        break;
    case 1:
        if (gPaletteFade.active)
            return;
        sOptionMenuPtr->loadState++;
        break;
    case 2:
        if (((bool32)MenuHelpers_CallLinkSomething()) == TRUE)
            break;
        switch (OptionMenu_ProcessInput())
        {
        case 0:
            break;
        case 1:
            sOptionMenuPtr->loadState++;
            break;
        case 2:
            LoadBgTiles(1, GetUserFrameGraphicsInfo(sOptionMenuPtr->option[MENUITEM_FRAMETYPE])->tiles, 0x120, 0x1AA);
            LoadPalette(GetUserFrameGraphicsInfo(sOptionMenuPtr->option[MENUITEM_FRAMETYPE])->palette, 0x20, 0x20);
            BufferOptionMenuString(sOptionMenuPtr->cursorPos);
            break;
        case 3:
            UpdateSettingSelectionDisplay(sOptionMenuPtr->cursorPos);
            break;
        case 4:
            BufferOptionMenuString(sOptionMenuPtr->cursorPos);
            break;
        case 6:
            if(!sOptionMenuPtr->inSubMenu)
            {
                sOptionMenuPtr->inSubMenu = TRUE;
                PrintOptionMenuHeader();
                sOptionMenuPtr->state = 6;
                sOptionMenuPtr->loadState = 1;
                sOptionMenuPtr->cursorPos = 0;
                SetHelpContext(HELPCONTEXT_OPTIONS_SUBMENU);
                DestroyTask(taskId);
                SetMainCallback2(CB2_OptionMenu);
                break;
            }
            else
            {
                sOptionMenuPtr->inSubMenu = FALSE;
                PrintOptionMenuHeader();
                sOptionMenuPtr->state = 6;
                sOptionMenuPtr->loadState = 1;
                sOptionMenuPtr->cursorPos = 1;
                SetHelpContext(HELPCONTEXT_OPTIONS);
                DestroyTask(taskId);
                SetMainCallback2(CB2_OptionMenu);
                break;
            }
        }
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        sOptionMenuPtr->loadState++;
        break;
    case 4:
        if (gPaletteFade.active)
            return;
        sOptionMenuPtr->loadState++;
        break;
    case 5:
        CloseAndSaveOptionMenu(taskId);
        break;
    }
}

static u8 OptionMenu_ProcessInput(void)
{ 
    u16 current;
    u16* curr;
    if (JOY_REPT(DPAD_RIGHT))
    {
        if(!sOptionMenuPtr->inSubMenu)
        {        
            current = sOptionMenuPtr->option[(sOptionMenuPtr->cursorPos)];
            if (current == (sOptionMenuItemCounts[sOptionMenuPtr->cursorPos] - 1))
                sOptionMenuPtr->option[sOptionMenuPtr->cursorPos] = 0;
            else
                sOptionMenuPtr->option[sOptionMenuPtr->cursorPos] = current + 1;
            if (sOptionMenuPtr->cursorPos == MENUITEM_FRAMETYPE)
                return 2;
            else
                return 4;
        }
        else
        {
            current = sOptionMenuPtr->subOption[(sOptionMenuPtr->cursorPos)];
            if (current == (sOptionSubMenuItemCounts[sOptionMenuPtr->cursorPos] - 1))
                sOptionMenuPtr->subOption[sOptionMenuPtr->cursorPos] = 0;
            else
                sOptionMenuPtr->subOption[sOptionMenuPtr->cursorPos] = current + 1;
            return 4;
        }
    }
    else if (JOY_REPT(DPAD_LEFT))
    {
        if(!sOptionMenuPtr->inSubMenu)
        {
            curr = &sOptionMenuPtr->option[sOptionMenuPtr->cursorPos];
            if (*curr == 0)
                *curr = sOptionMenuItemCounts[sOptionMenuPtr->cursorPos] - 1;
            else
                --*curr;
            
            if (sOptionMenuPtr->cursorPos == MENUITEM_FRAMETYPE)
                return 2;
            else
                return 4;
        }
        else
        {
            curr = &sOptionMenuPtr->subOption[sOptionMenuPtr->cursorPos];
            if (*curr == 0)
                *curr = sOptionSubMenuItemCounts[sOptionMenuPtr->cursorPos] - 1;
            else
                --*curr;
            return 4;
        }
    }
    else if (JOY_REPT(DPAD_UP))
    {
        if(!sOptionMenuPtr->inSubMenu)
        {
            if (sOptionMenuPtr->cursorPos == MENUITEM_TEXTSPEED)
                sOptionMenuPtr->cursorPos = MENUITEM_CANCEL;
            else
                sOptionMenuPtr->cursorPos = sOptionMenuPtr->cursorPos - 1;
        }
        else
        {
            if (sOptionMenuPtr->cursorPos == MENUITEM_BATTLETRANSITIONS)
                sOptionMenuPtr->cursorPos = MENUITEM_BACK;
            else
                sOptionMenuPtr->cursorPos = sOptionMenuPtr->cursorPos - 1;
        }
        OptionMenu_PickSwitchCancel();
        return 3;        
    }
    else if (JOY_REPT(DPAD_DOWN))
    {
        if(!sOptionMenuPtr->inSubMenu)
        {
            if (sOptionMenuPtr->cursorPos == MENUITEM_CANCEL)
                sOptionMenuPtr->cursorPos = MENUITEM_TEXTSPEED;
            else
                sOptionMenuPtr->cursorPos = sOptionMenuPtr->cursorPos + 1;
        }
        else
        {
            if (sOptionMenuPtr->cursorPos == MENUITEM_BACK)
                sOptionMenuPtr->cursorPos = MENUITEM_BATTLETRANSITIONS;
            else
                sOptionMenuPtr->cursorPos = sOptionMenuPtr->cursorPos + 1;
        }
        OptionMenu_PickSwitchCancel();
        return 3;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if(!sOptionMenuPtr->inSubMenu)
        {
            if(sOptionMenuPtr->cursorPos == MENUITEM_BATTLESCENE)
                return 6;
            if(sOptionMenuPtr->cursorPos == MENUITEM_CANCEL)
                return 1;
        }
        else
            return 6;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if(sOptionMenuPtr->inSubMenu)
            return 6;
        else
            return 1;
    }
    else
    {
        return 0;
    }
}

static void BufferOptionMenuString(u8 selection)
{
    u8 str[20];
    u8 buf[12];
    u8 dst[3];
    u8 x, y;
    
    memcpy(dst, sOptionMenuTextColor, 3);
    x = 0x82;
    y = ((GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT) - 1) * selection) + 2;
    FillWindowPixelRect(1, 1, x, y, 0x46, GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT));

    if(!sOptionMenuPtr->inSubMenu)
    {
        switch (selection)
        {
            case MENUITEM_TEXTSPEED:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sTextSpeedOptions[sOptionMenuPtr->option[selection]]);
                break;
            case MENUITEM_BATTLESCENE:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sBattleSceneOptions[sOptionMenuPtr->option[selection]]);
                break;
            case MENUITEM_BATTLESTYLE:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sBattleStyleOptions[sOptionMenuPtr->option[selection]]);
                break;
            case MENUITEM_SOUND:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sSoundOptions[sOptionMenuPtr->option[selection]]);
                break;
            case MENUITEM_BUTTONMODE:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sButtonTypeOptions[sOptionMenuPtr->option[selection]]);
                break;
            case MENUITEM_FRAMETYPE:
                StringCopy(str, gText_FrameType);
                ConvertIntToDecimalStringN(buf, sOptionMenuPtr->option[selection] + 1, 1, 2);
                StringAppendN(str, buf, 3);
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, str);
                break;
            default:
                break;
        }
    }
    else
    {
        switch (selection)
        {
            case MENUITEM_BATTLETRANSITIONS:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sBattleTransitionOptions[sOptionMenuPtr->subOption[selection]]);
                break;
            case MENUITEM_BATTLEINTROANIM:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sBattleIntroAnimOptions[sOptionMenuPtr->subOption[selection]]);
                break;
            case MENUITEM_MOVEANIMATIONS:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sMoveAnimOptions[sOptionMenuPtr->subOption[selection]]);
                break;
            case MENUITEM_HPBARANIMSPEED:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sHpBarAnimSpeedOptions[sOptionMenuPtr->subOption[selection]]);
                break;
            case MENUITEM_EXPBARANIMSPEED:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sExpBarAnimSpeedOptions[sOptionMenuPtr->subOption[selection]]);
                break;
            case MENUITEM_THROWANIM:
                AddTextPrinterParameterized3(1, 2, x, y, dst, -1, sThrowAnimOptions[sOptionMenuPtr->subOption[selection]]);
                break;
            default:
                break;
        }
    }
    
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_BOTH);
}

static void CloseAndSaveOptionMenu(u8 taskId)
{
    gFieldCallback = FieldCB_DefaultWarpExit;
    SetMainCallback2(gMain.savedCallback);
    FreeAllWindowBuffers();
    gSaveBlock2Ptr->optionsTextSpeed = sOptionMenuPtr->option[MENUITEM_TEXTSPEED];
    gSaveBlock2Ptr->optionsBattleStyle = sOptionMenuPtr->option[MENUITEM_BATTLESTYLE];
    gSaveBlock2Ptr->optionsSound = sOptionMenuPtr->option[MENUITEM_SOUND];
    gSaveBlock2Ptr->optionsButtonMode = sOptionMenuPtr->option[MENUITEM_BUTTONMODE];
    gSaveBlock2Ptr->optionsWindowFrameType = sOptionMenuPtr->option[MENUITEM_FRAMETYPE];

    gSaveBlock2Ptr->optionsBattleTransitions = sOptionMenuPtr->subOption[MENUITEM_BATTLETRANSITIONS];
    gSaveBlock2Ptr->optionsBattleIntroAnim = sOptionMenuPtr->subOption[MENUITEM_BATTLEINTROANIM];
    gSaveBlock2Ptr->optionsBattleSceneOff = sOptionMenuPtr->subOption[MENUITEM_MOVEANIMATIONS];
    gSaveBlock2Ptr->optionsHpBarAnimSpeed = sOptionMenuPtr->subOption[MENUITEM_HPBARANIMSPEED];
    gSaveBlock2Ptr->optionsExpBarAnimSpeed = sOptionMenuPtr->subOption[MENUITEM_EXPBARANIMSPEED];
    gSaveBlock2Ptr->optionsThrowAnim = sOptionMenuPtr->subOption[MENUITEM_THROWANIM];
    SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
    FREE_AND_SET_NULL(sOptionMenuPtr);
    FlagClear(FLAG_SYS_IN_OPTIONS_MENU);
    DestroyTask(taskId);
}

static void PrintOptionMenuHeader(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    if(!sOptionMenuPtr->inSubMenu)
        AddTextPrinterParameterized(WIN_TEXT_OPTION, 2, gText_MenuOption, 8, 1, TEXT_SPEED_FF, NULL);
    else
        AddTextPrinterParameterized(WIN_TEXT_OPTION, 2, gText_BattleScene, 8, 1, TEXT_SPEED_FF, NULL);
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_BOTH);
}

static void DrawOptionMenuBg(void)
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

static void LoadOptionMenuItemNames(void)
{
    u32 i;
    
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    if(!sOptionMenuPtr->inSubMenu)
    {
        for (i = 0; i < MENUITEM_COUNT; i++)
        {
            AddTextPrinterParameterized(WIN_OPTIONS, 2, sOptionMenuItemsNames[i], 8, (u8)((i * (GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT))) + 2) - i, TEXT_SPEED_FF, NULL);    
        }
    }
    else
    {
        for (i = 0; i < MENUITEM_COUNT2; i++)
        {
            AddTextPrinterParameterized(WIN_OPTIONS, 2, sOptionMenuItemsNames[i + MENUITEM_COUNT], 8, (u8)((i * (GetFontAttribute(2, FONTATTR_MAX_LETTER_HEIGHT))) + 2) - i, TEXT_SPEED_FF, NULL);    
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
