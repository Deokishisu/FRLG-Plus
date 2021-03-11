#include "global.h"
#include "gflib.h"
#include "scanline_effect.h"
#include "task.h"
#include "save.h"
#include "event_data.h"
#include "menu.h"
#include "link.h"
#include "oak_speech.h"
#include "overworld.h"
#include "quest_log.h"
#include "mystery_gift_menu.h"
#include "strings.h"
#include "title_screen.h"
#include "help_system.h"
#include "pokedex.h"
#include "text_window.h"
#include "text_window_graphics.h"
#include "constants/songs.h"

enum MainMenuType
{
    MAIN_MENU_NEWGAME = 0,
    MAIN_MENU_CONTINUE,
    MAIN_MENU_MYSTERYGIFT,
    MAIN_MENU_KEYSYSTEM
};

enum MainMenuWindow
{
    MAIN_MENU_WINDOW_NEWGAME_ONLY = 0,
    MAIN_MENU_WINDOW_CONTINUE,
    MAIN_MENU_WINDOW_NEWGAME,
    MAIN_MENU_WINDOW_MYSTERYGIFT,
    MAIN_MENU_WINDOW_KEYSYSTEM,
    MAIN_MENU_WINDOW_KEYSYSTEM_MYSTERYGIFT_ENABLED,
    MAIN_MENU_WINDOW_KEYSYSTEM_NEWGAME_ONLY,
    MAIN_MENU_WINDOW_ERROR,
    MAIN_MENU_WINDOW_FRLG_CHOICE,
    MAIN_MENU_WINDOW_COUNT
};

#define tMenuType  data[0]
#define tCursorPos data[1]

#define tUnused8         data[8]
#define tMGErrorMsgState data[9]
#define tMGErrorType     data[10]

extern void CB2_KeySystemMenuFromContinueScreen(void);

static bool32 MainMenuGpuInit(u8 a0);
static void Task_SetWin0BldRegsAndCheckSaveFile(u8 taskId);
static void PrintSaveErrorStatus(u8 taskId, const u8 *str);
static void Task_SaveErrorStatus_RunPrinterThenWaitButton(u8 taskId);
static void Task_SetWin0BldRegsNoSaveFileCheck(u8 taskId);
static void Task_WaitFadeAndPrintMainMenuText(u8 taskId);
static void Task_PrintMainMenuText(u8 taskId);
static void Task_WaitDma3AndFadeIn(u8 taskId);
static void Task_UpdateVisualSelection(u8 taskId);
static void Task_HandleMenuInput(u8 taskId);
static void Task_ExecuteMainMenuSelection(u8 taskId);
static void Task_MysteryGiftError(u8 taskId);
static void Task_ReturnToTileScreen(u8 taskId);
static void MoveWindowByMenuTypeAndCursorPos(u8 menuType, u8 cursorPos);
static bool8 HandleMenuInput(u8 taskId);
static void PrintMessageOnWindow4(const u8 *str);
static void PrintContinueStats(void);
static void PrintPlayerName(void);
static void PrintPlayTime(void);
static void PrintDexCount(void);
static void PrintBadgeCount(void);
static void LoadUserFrameToBg(u8 bgId);
static void SetStdFrame0OnBg(u8 bgId);
static void MainMenu_DrawWindow(const struct WindowTemplate * template);
static void MainMenu_EraseWindow(const struct WindowTemplate * template);
static void Task_DoFireredOrLeafgreenMultichoice(u8 taskId);
static void Task_ChooseVersionOnNewGame(u8 taskId);
static void Task_StartNewGame(u8 taskId);
static void CreateFRLGChoiceMenu(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
static void MainMenu_DrawWindow_WindowFunction(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum);
static void DrawFRLGChoiceFrame(u8 windowId, bool8 copyToVram, u16 baseTileNum, u8 paletteNum);


static const u8 sString_Dummy[] = _("");
static const u8 sString_Newline[] = _("\n");

static const struct WindowTemplate sWindowTemplate[] = {
    [MAIN_MENU_WINDOW_NEWGAME_ONLY] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 1,
        .width = 24,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x001
    }, 
    [MAIN_MENU_WINDOW_CONTINUE] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 1,
        .width = 24,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x001
    }, 
    [MAIN_MENU_WINDOW_NEWGAME] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 9,
        .width = 24,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x091
    }, 
    [MAIN_MENU_WINDOW_MYSTERYGIFT] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 13,
        .width = 24,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0C1
    }, 
    [MAIN_MENU_WINDOW_KEYSYSTEM] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 13,
        .width = 24,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x0C1
    },
    [MAIN_MENU_WINDOW_KEYSYSTEM_MYSTERYGIFT_ENABLED] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 17,
        .width = 24,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0xF1
    },
    [MAIN_MENU_WINDOW_KEYSYSTEM_NEWGAME_ONLY] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 5,
        .width = 24,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x31
    }, 
    [MAIN_MENU_WINDOW_ERROR] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x001
    }, 
    [MAIN_MENU_WINDOW_FRLG_CHOICE] = {
        .bg = 0x00,
        .tilemapLeft = 0x13,
        .tilemapTop = 0x0f,
        .width = 0x08,
        .height = 0x04,
        .paletteNum = 2,
        .baseBlock = 0x0155
    },
    [MAIN_MENU_WINDOW_COUNT] = DUMMY_WIN_TEMPLATE
};

static const u16 sBgPal00[] = INCBIN_U16("graphics/main_menu/unk_8234648.gbapal");
static const u16 sBgPal15[] = INCBIN_U16("graphics/main_menu/unk_8234668.gbapal");

static const u8 sTextColor1[] = { 10, 11, 12 };

static const u8 sTextColor2[] = { 10,  1, 12 };

static const struct BgTemplate sBgTemplate[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .priority = 0
    }
};

static const u8 sMenuCursorYMax[] = { 1, 2, 3 };

static void CB2_MainMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_MainMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitMainMenu(void)
{
    MainMenuGpuInit(1);
}

static void CB2_InitMainMenu_2(void)
{
    MainMenuGpuInit(1);
}

static bool32 MainMenuGpuInit(u8 a0)
{
    u8 taskId;

    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetBgsAndClearDma3BusyFlags(FALSE);
    InitBgsFromTemplates(0, sBgTemplate, NELEMS(sBgTemplate));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    InitWindows(sWindowTemplate);
    DeactivateAllTextPrinters();
    LoadPalette(sBgPal00, 0x00, 0x20);
    LoadPalette(sBgPal15, 0xF0, 0x20);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetMainCallback2(CB2_MainMenu);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
    taskId = CreateTask(Task_SetWin0BldRegsAndCheckSaveFile, 0);
    gTasks[taskId].tCursorPos = 0;
    gTasks[taskId].tUnused8 = 0;
    return FALSE;
}

/*
 * The entire screen is darkened slightly except at WIN0 to indicate
 * the player cursor position.
 */

static void Task_SetWin0BldRegsAndCheckSaveFile(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0x0001);
        SetGpuReg(REG_OFFSET_WINOUT, 0x0021);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
        SetGpuReg(REG_OFFSET_BLDY, 7);
        switch (gSaveFileStatus)
        {
        case SAVE_STATUS_OK:
            LoadUserFrameToBg(0);
            if (IsMysteryGiftEnabled() == TRUE)
            {
                gTasks[taskId].tMenuType = MAIN_MENU_MYSTERYGIFT;
            }
            else
            {
                gTasks[taskId].tMenuType = MAIN_MENU_CONTINUE;
            }
            gTasks[taskId].func = Task_SetWin0BldRegsNoSaveFileCheck;
            break;
        case SAVE_STATUS_INVALID:
            SetStdFrame0OnBg(0);
            gTasks[taskId].tMenuType = MAIN_MENU_NEWGAME;
            PrintSaveErrorStatus(taskId, gText_SaveFileHasBeenDeleted);
            break;
        case SAVE_STATUS_ERROR:
            SetStdFrame0OnBg(0);
            gTasks[taskId].tMenuType = MAIN_MENU_CONTINUE;
            PrintSaveErrorStatus(taskId, gText_SaveFileCorruptedPrevWillBeLoaded);
            if (IsMysteryGiftEnabled() == TRUE)
            {
                gTasks[taskId].tMenuType = MAIN_MENU_MYSTERYGIFT;
            }
            else
            {
                gTasks[taskId].tMenuType = MAIN_MENU_CONTINUE;
            }
            break;
        case SAVE_STATUS_EMPTY:
            SetStdFrame0OnBg(0);
            gTasks[taskId].tMenuType = MAIN_MENU_NEWGAME;
            gTasks[taskId].tUnused8 = 3;
            PrintSaveErrorStatus(taskId, gChooseVersionNewGame);
            break;
        default:
            LoadUserFrameToBg(0);
            gTasks[taskId].tMenuType = MAIN_MENU_NEWGAME;
            gTasks[taskId].func = Task_SetWin0BldRegsNoSaveFileCheck;
            break;
        case SAVE_STATUS_NO_FLASH:
            SetStdFrame0OnBg(0);
            gTasks[taskId].tMenuType = MAIN_MENU_NEWGAME;
            PrintSaveErrorStatus(taskId, gText_1MSubCircuitBoardNotInstalled);
            break;
        }
    }
}

static void PrintSaveErrorStatus(u8 taskId, const u8 *str)
{
    PrintMessageOnWindow4(str);
    gTasks[taskId].func = Task_SaveErrorStatus_RunPrinterThenWaitButton;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0xFFFF);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
    SetGpuReg(REG_OFFSET_WIN0V, ((0x0 << 8) + (2 << 8)) | ((0xA0) - 2));
    ShowBg(0);
    SetVBlankCallback(VBlankCB_MainMenu);
}

static void Task_SaveErrorStatus_RunPrinterThenWaitButton(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        RunTextPrinters();
        if(gTasks[taskId].tUnused8 == 3)
        {
            if(!IsTextPrinterActive(MAIN_MENU_WINDOW_ERROR))
            {
                gTasks[taskId].func = Task_DoFireredOrLeafgreenMultichoice;
            }
        }
        else
        {
            if (!IsTextPrinterActive(MAIN_MENU_WINDOW_ERROR) && JOY_NEW(A_BUTTON))
            {
                ClearWindowTilemap(MAIN_MENU_WINDOW_ERROR);
                MainMenu_EraseWindow(&sWindowTemplate[MAIN_MENU_WINDOW_ERROR]);
                LoadUserFrameToBg(0);

                if (gTasks[taskId].tMenuType == MAIN_MENU_NEWGAME)
                    gTasks[taskId].func = Task_SetWin0BldRegsNoSaveFileCheck;
                else
                    gTasks[taskId].func = Task_PrintMainMenuText;
            }
        }
    }
}

static void Task_SetWin0BldRegsNoSaveFileCheck(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0x0001);
        SetGpuReg(REG_OFFSET_WINOUT, 0x0021);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
        SetGpuReg(REG_OFFSET_BLDY, 7);
        if (gTasks[taskId].tMenuType == MAIN_MENU_NEWGAME)
            gTasks[taskId].func = Task_ExecuteMainMenuSelection;
        else
            gTasks[taskId].func = Task_WaitFadeAndPrintMainMenuText;
    }
}

static void Task_WaitFadeAndPrintMainMenuText(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Task_PrintMainMenuText(taskId);
    }
}

static void Task_PrintMainMenuText(u8 taskId)
{
    u16 pal;
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0x0001);
    SetGpuReg(REG_OFFSET_WINOUT, 0x0021);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
    SetGpuReg(REG_OFFSET_BLDY, 7);
    if (gSaveBlock2Ptr->playerGender == MALE)
        pal = RGB(4, 16, 31);
    else
        pal = RGB(31, 3, 21);
    LoadPalette(&pal, 0xF1, 2);
    switch (gTasks[taskId].tMenuType)
    {
    case MAIN_MENU_NEWGAME:
    default:
        FillWindowPixelBuffer(MAIN_MENU_WINDOW_NEWGAME_ONLY, PIXEL_FILL(10));
        FillWindowPixelBuffer(MAIN_MENU_WINDOW_KEYSYSTEM_NEWGAME_ONLY, PIXEL_FILL(10));
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_NEWGAME_ONLY, 2, 2, 2, sTextColor1, -1, gText_NewGame);
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_KEYSYSTEM_NEWGAME_ONLY, 2, 2, 2, sTextColor1, -1, gText_KeySystemSettings);
        MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_NEWGAME_ONLY]);
        MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_KEYSYSTEM_NEWGAME_ONLY]);
        PutWindowTilemap(MAIN_MENU_WINDOW_NEWGAME_ONLY);
        PutWindowTilemap(MAIN_MENU_WINDOW_KEYSYSTEM_NEWGAME_ONLY);
        CopyWindowToVram(MAIN_MENU_WINDOW_NEWGAME_ONLY, COPYWIN_GFX);
        CopyWindowToVram(MAIN_MENU_WINDOW_KEYSYSTEM_NEWGAME_ONLY, COPYWIN_BOTH);
        break;
    case MAIN_MENU_CONTINUE:
        FillWindowPixelBuffer(MAIN_MENU_WINDOW_CONTINUE, PIXEL_FILL(10));
        FillWindowPixelBuffer(MAIN_MENU_WINDOW_NEWGAME, PIXEL_FILL(10));
        FillWindowPixelBuffer(MAIN_MENU_WINDOW_KEYSYSTEM, PIXEL_FILL(10));
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 2, 2, sTextColor1, -1, gText_Continue);
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_NEWGAME, 2, 2, 2, sTextColor1, -1, gText_NewGame);
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_KEYSYSTEM, 2, 2, 2, sTextColor1, -1, gText_KeySystemSettings);
        PrintContinueStats();
        MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_CONTINUE]);
        MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_NEWGAME]);
        MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_KEYSYSTEM]);
        PutWindowTilemap(MAIN_MENU_WINDOW_CONTINUE);
        PutWindowTilemap(MAIN_MENU_WINDOW_NEWGAME);
        PutWindowTilemap(MAIN_MENU_WINDOW_KEYSYSTEM);
        CopyWindowToVram(MAIN_MENU_WINDOW_CONTINUE, COPYWIN_GFX);
        CopyWindowToVram(MAIN_MENU_WINDOW_NEWGAME, COPYWIN_GFX);
        CopyWindowToVram(MAIN_MENU_WINDOW_KEYSYSTEM, COPYWIN_BOTH);
        break;
    case MAIN_MENU_MYSTERYGIFT:
        FillWindowPixelBuffer(MAIN_MENU_WINDOW_CONTINUE, PIXEL_FILL(10));
        FillWindowPixelBuffer(MAIN_MENU_WINDOW_NEWGAME, PIXEL_FILL(10));
        FillWindowPixelBuffer(MAIN_MENU_WINDOW_MYSTERYGIFT, PIXEL_FILL(10));
        FillWindowPixelBuffer(MAIN_MENU_WINDOW_KEYSYSTEM_MYSTERYGIFT_ENABLED, PIXEL_FILL(10));
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 2, 2, sTextColor1, -1, gText_Continue);
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_NEWGAME, 2, 2, 2, sTextColor1, -1, gText_NewGame);
        gTasks[taskId].tMGErrorType = 1;
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_MYSTERYGIFT, 2, 2, 2, sTextColor1, -1, gText_MysteryGift);
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_KEYSYSTEM_MYSTERYGIFT_ENABLED, 2, 2, 2, sTextColor1, -1, gText_KeySystemSettings);
        PrintContinueStats();
        MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_CONTINUE]);
        MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_NEWGAME]);
        MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_MYSTERYGIFT]);
        MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_KEYSYSTEM_MYSTERYGIFT_ENABLED]);
        PutWindowTilemap(MAIN_MENU_WINDOW_CONTINUE);
        PutWindowTilemap(MAIN_MENU_WINDOW_NEWGAME);
        PutWindowTilemap(MAIN_MENU_WINDOW_MYSTERYGIFT);
        PutWindowTilemap(MAIN_MENU_WINDOW_KEYSYSTEM_MYSTERYGIFT_ENABLED);
        CopyWindowToVram(MAIN_MENU_WINDOW_CONTINUE, COPYWIN_GFX);
        CopyWindowToVram(MAIN_MENU_WINDOW_NEWGAME, COPYWIN_GFX);
        CopyWindowToVram(MAIN_MENU_WINDOW_MYSTERYGIFT, COPYWIN_GFX);
        CopyWindowToVram(MAIN_MENU_WINDOW_KEYSYSTEM_MYSTERYGIFT_ENABLED, COPYWIN_BOTH);
        break;
    }
    gTasks[taskId].func = Task_WaitDma3AndFadeIn;
}

static void Task_WaitDma3AndFadeIn(u8 taskId)
{
    if (WaitDma3Request(-1) != -1)
    {
        gTasks[taskId].func = Task_UpdateVisualSelection;
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0xFFFF);
        ShowBg(0);
        SetVBlankCallback(VBlankCB_MainMenu);
    }
}

static void Task_UpdateVisualSelection(u8 taskId)
{
    MoveWindowByMenuTypeAndCursorPos(gTasks[taskId].tMenuType, gTasks[taskId].tCursorPos);
    gTasks[taskId].func = Task_HandleMenuInput;
}

static void Task_HandleMenuInput(u8 taskId)
{
    if (!gPaletteFade.active && HandleMenuInput(taskId))
    {
        gTasks[taskId].func = Task_UpdateVisualSelection;
    }
}

static void Task_ExecuteMainMenuSelection(u8 taskId)
{
    s32 menuAction;
    if (!gPaletteFade.active)
    {
        switch (gTasks[taskId].tMenuType)
        {
        default:
        case MAIN_MENU_NEWGAME:
            switch (gTasks[taskId].tCursorPos)
            {
            default:
            case 0:
                menuAction = MAIN_MENU_NEWGAME;
                break;
            case 1:
                menuAction = MAIN_MENU_KEYSYSTEM;
                break;
            }
            break;
        case MAIN_MENU_CONTINUE:
            switch (gTasks[taskId].tCursorPos)
            {
            default:
            case 0:
                menuAction = MAIN_MENU_CONTINUE;
                break;
            case 1:
                menuAction = MAIN_MENU_NEWGAME;
                break;
            case 2:
                menuAction = MAIN_MENU_KEYSYSTEM;
                break;
            }
            break;
        case MAIN_MENU_MYSTERYGIFT:
            switch (gTasks[taskId].tCursorPos)
            {
            default:
            case 0:
                menuAction = MAIN_MENU_CONTINUE;
                break;
            case 1:
                menuAction = MAIN_MENU_NEWGAME;
                break;
            case 2:
                if (!IsWirelessAdapterConnected())
                {
                    SetStdFrame0OnBg(0);
                    gTasks[taskId].func = Task_MysteryGiftError;
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
                    return;
                }
                else
                {
                    menuAction = MAIN_MENU_MYSTERYGIFT;
                }
                break;
            case 3:
                menuAction = MAIN_MENU_KEYSYSTEM;
                break;
            }
            break;
        }
        switch (menuAction)
        {
        default:
        case MAIN_MENU_NEWGAME:
            SetStdFrame0OnBg(0);
            gTasks[taskId].func = Task_ChooseVersionOnNewGame;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            return;
        case MAIN_MENU_CONTINUE:
            gPlttBufferUnfaded[0] = RGB_BLACK;
            gPlttBufferFaded[0] = RGB_BLACK;
            gUnknown_2031DE0 = 0;
            FreeAllWindowBuffers();
            TrySetUpQuestLogScenes_ElseContinueFromSave(taskId);
            break;
        case MAIN_MENU_MYSTERYGIFT:
            SetMainCallback2(c2_mystery_gift);
            HelpSystem_Disable();
            FreeAllWindowBuffers();
            DestroyTask(taskId);
            break;
        case MAIN_MENU_KEYSYSTEM:
            SetMainCallback2(CB2_KeySystemMenuFromContinueScreen);
            //HelpSystem_Disable();
            FreeAllWindowBuffers();
            DestroyTask(taskId);
            break;
        }
    }
}

static void Task_DoFireredOrLeafgreenMultichoice(u8 taskId)
{
    struct WindowTemplate windowTemplate;
    s8 input;

    switch (gTasks[taskId].tUnused8)
    {
    case 3:
        //StringExpandPlaceholders(gStringVar4, gChooseVersionNewGame);
        //MAIN_MENU_WINDOW_ERROR = AddWindow(&sWindowTemplate_Prompt_FRLG);
        //FillWindowPixelBuffer(MAIN_MENU_WINDOW_ERROR, 0x11);
        //AddTextPrinterParameterized4(MAIN_MENU_WINDOW_ERROR, 2, 0, 2, 0, 2, sMG_Ereader_TextColor_2, 0, gStringVar4);
        //DrawTextBorderOuter(MAIN_MENU_WINDOW_ERROR, 0x001, 0x0F);
        //CopyWindowToVram(MAIN_MENU_WINDOW_ERROR, COPYWIN_GFX);
        //PutWindowTilemap(MAIN_MENU_WINDOW_ERROR);
        gTasks[taskId].tUnused8++;
        break;
    case 4:
        windowTemplate = sWindowTemplate[MAIN_MENU_WINDOW_FRLG_CHOICE];
        windowTemplate.tilemapTop = 9;
        CreateFRLGChoiceMenu(&windowTemplate, 2, 0, 2, 0x0155, 2, 0);
        gTasks[taskId].tUnused8++;
        break;
    case 5:
        input = Menu_ProcessInputNoWrapAround();
        if (input == 0 || input == 1)
        {
            if(input == 0)
            {
                gSaveBlock1Ptr->keyFlags.version = 0;
            }
            else
            {
                gSaveBlock1Ptr->keyFlags.version = 1;
            }
            PlaySE(SE_SELECT);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].tUnused8 = 3;
            rbox_fill_rectangle(MAIN_MENU_WINDOW_ERROR);
            ClearWindowTilemap(MAIN_MENU_WINDOW_ERROR);
            CopyWindowToVram(MAIN_MENU_WINDOW_ERROR, COPYWIN_MAP);
            RemoveWindow(MAIN_MENU_WINDOW_ERROR);
            gTasks[taskId].func = Task_StartNewGame;
            break;
        }
        break;
    /*case 0xFF:
        if(input == 0)
        {
            gSaveBlock1Ptr->keyFlags.version = 0;
        }
        else
        {
            gSaveBlock1Ptr->keyFlags.version = 1;
        }
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].tUnused8 = 3;
        rbox_fill_rectangle(MAIN_MENU_WINDOW_ERROR);
        ClearWindowTilemap(MAIN_MENU_WINDOW_ERROR);
        CopyWindowToVram(MAIN_MENU_WINDOW_ERROR, COPYWIN_MAP);
        RemoveWindow(MAIN_MENU_WINDOW_ERROR);
        gTasks[taskId].func = Task_StartNewGame;
        break;*/
    }
}

void CreateFRLGChoiceMenu(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos)
{
    struct TextPrinterTemplate textSubPrinter;
    u8 YesNoWindowId;

    YesNoWindowId = AddWindow(window);
    DrawFRLGChoiceFrame(YesNoWindowId, 1, baseTileNum, paletteNum);
    textSubPrinter.currentChar = gFRLG_Multichoice;
    textSubPrinter.windowId = YesNoWindowId;
    textSubPrinter.fontId = fontId;
    textSubPrinter.x = GetMenuCursorDimensionByFont(fontId, 0) + left;
    textSubPrinter.y = top;
    textSubPrinter.currentX = textSubPrinter.x;
    textSubPrinter.currentY = textSubPrinter.y;
    textSubPrinter.fgColor = GetFontAttribute(fontId, FONTATTR_COLOR_FOREGROUND);
    textSubPrinter.bgColor = GetFontAttribute(fontId, FONTATTR_COLOR_BACKGROUND);
    textSubPrinter.shadowColor = GetFontAttribute(fontId, FONTATTR_COLOR_SHADOW);
    textSubPrinter.unk = GetFontAttribute(fontId, FONTATTR_UNKNOWN);
    textSubPrinter.letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    textSubPrinter.lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    AddTextPrinter(&textSubPrinter, 0xFF, NULL);
    Menu_InitCursor(YesNoWindowId, fontId, left, top, GetFontAttribute(fontId, FONTATTR_MAX_LETTER_HEIGHT) + textSubPrinter.lineSpacing, 2, initialCursorPos);
}

static void DrawFRLGChoiceFrame(u8 windowId, bool8 copyToVram, u16 baseTileNum, u8 paletteNum)
{
    u16 TileNum;
    u8 PaletteNum;

    TileNum = baseTileNum;
    PaletteNum = paletteNum;
    CallWindowFunction(windowId, MainMenu_DrawWindow_WindowFunction);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_BOTH);
}

static void Task_ChooseVersionOnNewGame(u8 taskId)
{
    s8 state = 0;

    //undarken screen
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
    SetGpuReg(REG_OFFSET_WIN0V, ((0x0 << 8) + (2 << 8)) | ((0xA0) - 2));
    switch (gTasks[taskId].tUnused8)
    {
    case 0:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        PrintMessageOnWindow4(gChooseVersionNewGame);
        gTasks[taskId].tUnused8++;
        break;
    case 1:
        if (!gPaletteFade.active)
            gTasks[taskId].tUnused8++;
        break;
    case 2:
        RunTextPrinters();
        if (!IsTextPrinterActive(MAIN_MENU_WINDOW_ERROR))
            gTasks[taskId].tUnused8++;
        break;
    case 3: //yesno here
        gTasks[taskId].func = Task_DoFireredOrLeafgreenMultichoice;
        //PlaySE(SE_SELECT);
        //BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        //gTasks[taskId].func = Task_StartNewGame;
        break;
    }
}

static void Task_StartNewGame(u8 taskId)
{
    gUnknown_2031DE0 = 0;
    FreeAllWindowBuffers();
    DestroyTask(taskId);
    StartNewGameScene();
}

static void Task_MysteryGiftError(u8 taskId)
{
    switch (gTasks[taskId].tMGErrorMsgState)
    {
    case 0:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        if (gTasks[taskId].tMGErrorType == 1)
            PrintMessageOnWindow4(gText_WirelessAdapterIsNotConnected);
        else
            PrintMessageOnWindow4(gText_MysteryGiftCantBeUsedWhileWirelessAdapterIsAttached);
        gTasks[taskId].tMGErrorMsgState++;
        break;
    case 1:
        if (!gPaletteFade.active)
            gTasks[taskId].tMGErrorMsgState++;
        break;
    case 2:
        RunTextPrinters();
        if (!IsTextPrinterActive(MAIN_MENU_WINDOW_ERROR))
            gTasks[taskId].tMGErrorMsgState++;
        break;
    case 3:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            PlaySE(SE_SELECT);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_ReturnToTileScreen;
        }
        break;
    }
}

static void Task_ReturnToTileScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_InitTitleScreen);
        DestroyTask(taskId);
    }
}

static void MoveWindowByMenuTypeAndCursorPos(u8 menuType, u8 cursorPos)
{
    u16 win0vTop, win0vBot;
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(18, 222));
    switch (menuType)
    {
    default:
    case MAIN_MENU_NEWGAME:
        switch (cursorPos)
        {
            default:
            case 0: // NEW GAME
                win0vTop = 0x00 << 8;
                win0vBot = 0x20;
                break;
            case 1: // KEY SYSTEM SETTINGS
                win0vTop = 0x20 << 8;
                win0vBot = 0x40;
                break;
        }
    case MAIN_MENU_CONTINUE:
        switch (cursorPos)
        {
        default:
        case 0: // CONTINUE
            win0vTop = 0x00 << 8;
            win0vBot = 0x40;
            break;
        case 1: // NEW GAME
            win0vTop = 0x40 << 8;
            win0vBot = 0x60;
            break;
        case 2: // KEY SYSTEM SETTINGS
            win0vTop = 0x60 << 8;
            win0vBot = 0x80;
            break;
        }
    case MAIN_MENU_MYSTERYGIFT:
        switch (cursorPos)
        {
        default:
        case 0: // CONTINUE
            win0vTop = 0x00 << 8;
            win0vBot = 0x40;
            break;
        case 1: // NEW GAME
            win0vTop = 0x40 << 8;
            win0vBot = 0x60;
            break;
        case 2: // MYSTERY GIFT
            win0vTop = 0x60 << 8;
            win0vBot = 0x80;
            break;
        case 3: // KEY SYSTEM SETTINGS
            win0vTop = 0x80 << 8;
            win0vBot = 0xA0;
            break;
        }
        break;
    }
    SetGpuReg(REG_OFFSET_WIN0V, (win0vTop + (2 << 8)) | (win0vBot - 2));
}

static bool8 HandleMenuInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        IsWirelessAdapterConnected(); // called for its side effects only
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ExecuteMainMenuSelection;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, 240));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 160));
        gTasks[taskId].func = Task_ReturnToTileScreen;
    }
    else if (JOY_NEW(DPAD_UP) && gTasks[taskId].tCursorPos > 0)
    {
        gTasks[taskId].tCursorPos--;
        return TRUE;
    }
    else if (JOY_NEW(DPAD_DOWN) && gTasks[taskId].tCursorPos < sMenuCursorYMax[gTasks[taskId].tMenuType])
    {
        gTasks[taskId].tCursorPos++;
        return TRUE;
    }

    return FALSE;
}

static void PrintMessageOnWindow4(const u8 *str)
{
    FillWindowPixelBuffer(MAIN_MENU_WINDOW_ERROR, PIXEL_FILL(10));
    MainMenu_DrawWindow(&sWindowTemplate[MAIN_MENU_WINDOW_ERROR]);
    AddTextPrinterParameterized3(MAIN_MENU_WINDOW_ERROR, 2, 0, 2, sTextColor1, 2, str);
    PutWindowTilemap(MAIN_MENU_WINDOW_ERROR);
    CopyWindowToVram(MAIN_MENU_WINDOW_ERROR, COPYWIN_GFX);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE( 19, 221));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(115, 157));
}

static void PrintContinueStats(void)
{
    PrintPlayerName();
    PrintDexCount();
    PrintPlayTime();
    PrintBadgeCount();
}

static void PrintPlayerName(void)
{
    s32 i;
    u8 name[OT_NAME_LENGTH + 1];
    u8 *ptr;
    AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 2, 18, sTextColor2, -1, gText_Player);
    ptr = name;
    for (i = 0; i < OT_NAME_LENGTH; i++)
        *ptr++ = gSaveBlock2Ptr->playerName[i];
    *ptr = EOS;
    AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 52, 18, sTextColor2, -1, name);
}

static void PrintPlayTime(void)
{
    u8 strbuf[30];
    u8 *ptr;

    AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 2, 34, sTextColor2, -1, gText_Time);
    ptr = ConvertIntToDecimalStringN(strbuf, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    *ptr++ = CHAR_COLON;
    ConvertIntToDecimalStringN(ptr, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 52, 34, sTextColor2, -1, strbuf);
}

static void PrintDexCount(void)
{
    u8 strbuf[30];
    u8 *ptr;
    u16 dexcount;
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        if (IsNationalPokedexEnabled())
            dexcount = GetNationalPokedexCount(FLAG_GET_CAUGHT);
        else if(FlagGet(FLAG_SYS_RECEIVED_EXTENDED_DEX) && !IsNationalPokedexEnabled())
            dexcount = GetExtendedPokedexCount(FLAG_GET_CAUGHT);
        else
            dexcount = GetKantoPokedexCount(FLAG_GET_CAUGHT);
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 112, 18, sTextColor2, -1, gText_Pokedex);
        ptr = ConvertIntToDecimalStringN(strbuf, dexcount, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringAppend(ptr, gTextJPDummy_Hiki);
        AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 162, 18, sTextColor2, -1, strbuf);
    }
}

static void PrintBadgeCount(void)
{
    u8 strbuf[30];
    u8 *ptr;
    u32 flagId;
    u8 nbadges = 0;
    for (flagId = FLAG_BADGE01_GET; flagId < FLAG_BADGE01_GET + 8; flagId++)
    {
        if (FlagGet(flagId))
            nbadges++;
    }
    AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 112, 34, sTextColor2, -1, gText_Badges);
    ptr = ConvertIntToDecimalStringN(strbuf, nbadges, STR_CONV_MODE_LEADING_ZEROS, 1);
    StringAppend(ptr, gTextJPDummy_Ko);
    AddTextPrinterParameterized3(MAIN_MENU_WINDOW_CONTINUE, 2, 162, 34, sTextColor2, -1, strbuf);
}

static void LoadUserFrameToBg(u8 bgId)
{
    LoadBgTiles(bgId, GetUserFrameGraphicsInfo(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1B1);
    LoadPalette(GetUserFrameGraphicsInfo(gSaveBlock2Ptr->optionsWindowFrameType)->palette, 0x20, 0x20);
    MainMenu_EraseWindow(&sWindowTemplate[MAIN_MENU_WINDOW_ERROR]);
}

static void SetStdFrame0OnBg(u8 bgId)
{
    TextWindow_SetStdFrame0_WithPal(MAIN_MENU_WINDOW_NEWGAME_ONLY, 0x1B1, 0x20);
    MainMenu_EraseWindow(&sWindowTemplate[MAIN_MENU_WINDOW_ERROR]);
}

static void MainMenu_DrawWindow_WindowFunction(u8 bg, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 paletteNum)
{
    FillBgTilemapBufferRect(
        bg, 
        0x1B1, 
        tilemapLeft - 1, 
        tilemapTop - 1,
        1,
        1,
        2
    );
    FillBgTilemapBufferRect(
        bg, 
        0x1B2, 
        tilemapLeft, 
        tilemapTop - 1, 
        width, 
        height, 
        2
    );
    FillBgTilemapBufferRect(
        bg, 
        0x1B3, 
        tilemapLeft + 
        width, 
        tilemapTop - 1,
        1,
        1,
        2
    );
    FillBgTilemapBufferRect(
        bg, 
        0x1B4, 
        tilemapLeft - 1, 
        tilemapTop,
        1, 
        height,
        2
    );
    FillBgTilemapBufferRect(
        bg, 
        0x1B6, 
        tilemapLeft + 
        width, 
        tilemapTop,
        1, 
        height,
        2
    );
    FillBgTilemapBufferRect(
        bg, 
        0x1B7, 
        tilemapLeft - 1, 
        tilemapTop + 
        height,
        1,
        1,
        2
    );
    FillBgTilemapBufferRect(
        bg, 
        0x1B8, 
        tilemapLeft, 
        tilemapTop + 
        height, 
        width,
        1,
        2
    );
    FillBgTilemapBufferRect(
        bg, 
        0x1B9, 
        tilemapLeft + 
        width, 
        tilemapTop + 
        height,
        1,
        1,
        2
    );
    CopyBgTilemapBufferToVram(bg);
}

static void MainMenu_DrawWindow(const struct WindowTemplate * windowTemplate)
{
    FillBgTilemapBufferRect(
        windowTemplate->bg, 
        0x1B1, 
        windowTemplate->tilemapLeft - 1, 
        windowTemplate->tilemapTop - 1,
        1,
        1,
        2
    );
    FillBgTilemapBufferRect(
        windowTemplate->bg, 
        0x1B2, 
        windowTemplate->tilemapLeft, 
        windowTemplate->tilemapTop - 1, 
        windowTemplate->width, 
        windowTemplate->height, 
        2
    );
    FillBgTilemapBufferRect(
        windowTemplate->bg, 
        0x1B3, 
        windowTemplate->tilemapLeft + 
        windowTemplate->width, 
        windowTemplate->tilemapTop - 1,
        1,
        1,
        2
    );
    FillBgTilemapBufferRect(
        windowTemplate->bg, 
        0x1B4, 
        windowTemplate->tilemapLeft - 1, 
        windowTemplate->tilemapTop,
        1, 
        windowTemplate->height,
        2
    );
    FillBgTilemapBufferRect(
        windowTemplate->bg, 
        0x1B6, 
        windowTemplate->tilemapLeft + 
        windowTemplate->width, 
        windowTemplate->tilemapTop,
        1, 
        windowTemplate->height,
        2
    );
    FillBgTilemapBufferRect(
        windowTemplate->bg, 
        0x1B7, 
        windowTemplate->tilemapLeft - 1, 
        windowTemplate->tilemapTop + 
        windowTemplate->height,
        1,
        1,
        2
    );
    FillBgTilemapBufferRect(
        windowTemplate->bg, 
        0x1B8, 
        windowTemplate->tilemapLeft, 
        windowTemplate->tilemapTop + 
        windowTemplate->height, 
        windowTemplate->width,
        1,
        2
    );
    FillBgTilemapBufferRect(
        windowTemplate->bg, 
        0x1B9, 
        windowTemplate->tilemapLeft + 
        windowTemplate->width, 
        windowTemplate->tilemapTop + 
        windowTemplate->height,
        1,
        1,
        2
    );
    CopyBgTilemapBufferToVram(windowTemplate->bg);
}

static void MainMenu_EraseWindow(const struct WindowTemplate * windowTemplate)
{
    FillBgTilemapBufferRect(
        windowTemplate->bg, 
        0x000, 
        windowTemplate->tilemapLeft - 1, 
        windowTemplate->tilemapTop - 1,  
        windowTemplate->tilemapLeft + 
        windowTemplate->width + 1, 
        windowTemplate->tilemapTop + 
        windowTemplate->height + 1,
        2
    );
    CopyBgTilemapBufferToVram(windowTemplate->bg);
}
