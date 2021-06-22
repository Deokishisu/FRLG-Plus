#include "global.h"
#include "item.h"
#include "field_effect_helpers.h"
#include "field_specials.h"
#include "event_object_movement.h"
#include "item.h"
#include "overworld.h"
#include "pokedex.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "event_data.h"
#include "party_menu.h"
#include "pokemon_storage_system.h"
#include "quest_log.h"
#include "script_pokemon_util.h"
#include "constants/items.h"
#include "constants/map_scripts.h"
#include "constants/moves.h"
#include "constants/region_map_sections.h"

#define RAM_SCRIPT_MAGIC 51
#define SCRIPT_STACK_SIZE 20


extern void ResetContextNpcTextColor(void); // field_specials
extern u16 CalcCRC16WithTable(u8 *data, int length); // util
extern bool32 ValidateReceivedWonderCard(void); // mevent

enum
{
    SCRIPT_MODE_STOPPED,
    SCRIPT_MODE_BYTECODE,
    SCRIPT_MODE_NATIVE,
};

EWRAM_DATA u8 gWalkAwayFromSignInhibitTimer = 0;
EWRAM_DATA const u8 *gRAMScriptPtr = NULL;

// iwram bss
static u8 sScriptContext1Status;
static u32 sUnusedVariable1;
static struct ScriptContext sScriptContext1;
static u32 sUnusedVariable2;
static struct ScriptContext sScriptContext2;
static bool8 sScriptContext2Enabled;
static u8 sMsgBoxWalkawayDisabled;
static u8 sMsgBoxIsCancelable;
static u8 sQuestLogInput;
static u8 sQuestLogInputIsDpad;
static u8 sMsgIsSignPost;

extern ScrCmdFunc gScriptCmdTable[];
extern ScrCmdFunc gScriptCmdTableEnd[];
extern void *gNullScriptPtr;

void InitScriptContext(struct ScriptContext *ctx, void *cmdTable, void *cmdTableEnd)
{
    s32 i;

    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
    ctx->stackDepth = 0;
    ctx->nativePtr = NULL;
    ctx->cmdTable = cmdTable;
    ctx->cmdTableEnd = cmdTableEnd;

    for (i = 0; i < 4; i++)
        ctx->data[i] = 0;

    for (i = 0; i < SCRIPT_STACK_SIZE; i++)
        ctx->stack[i] = 0;
}

u8 SetupBytecodeScript(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
    ctx->mode = SCRIPT_MODE_BYTECODE;
    return 1;
}

void SetupNativeScript(struct ScriptContext *ctx, bool8 (*ptr)(void))
{
    ctx->mode = SCRIPT_MODE_NATIVE;
    ctx->nativePtr = ptr;
}

void StopScript(struct ScriptContext *ctx)
{
    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
}

bool8 RunScriptCommand(struct ScriptContext *ctx)
{
    // FRLG disabled this check, where-as it is present
    // in Ruby/Sapphire and Emerald. Why did the programmers
    // bother to remove a redundant check when it still
    // exists in Emerald?
    //if (ctx->mode == SCRIPT_MODE_STOPPED)
    //    return FALSE;

    switch (ctx->mode)
    {
    case SCRIPT_MODE_STOPPED:
        return FALSE;
    case SCRIPT_MODE_NATIVE:
        if (ctx->nativePtr)
        {
            if (ctx->nativePtr() == TRUE)
                ctx->mode = SCRIPT_MODE_BYTECODE;
            return TRUE;
        }
        ctx->mode = SCRIPT_MODE_BYTECODE;
    case SCRIPT_MODE_BYTECODE:
        while (1)
        {
            u8 cmdCode;
            ScrCmdFunc *cmdFunc;

            if (ctx->scriptPtr == NULL)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            if (ctx->scriptPtr == gNullScriptPtr)
            {
                while (1)
                    asm("svc 2"); // HALT
            }

            cmdCode = *(ctx->scriptPtr);
            ctx->scriptPtr++;
            cmdFunc = &ctx->cmdTable[cmdCode];

            if (cmdFunc >= ctx->cmdTableEnd)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            if ((*cmdFunc)(ctx) == TRUE)
                return TRUE;
        }
    }

    return TRUE;
}

u8 ScriptPush(struct ScriptContext *ctx, const u8 *ptr)
{
    if (ctx->stackDepth + 1 >= SCRIPT_STACK_SIZE)
    {
        return 1;
    }
    else
    {
        ctx->stack[ctx->stackDepth] = ptr;
        ctx->stackDepth++;
        return 0;
    }
}

const u8 *ScriptPop(struct ScriptContext *ctx)
{
    if (ctx->stackDepth == 0)
        return NULL;

    ctx->stackDepth--;
    return ctx->stack[ctx->stackDepth];
}

void ScriptJump(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
}

void ScriptCall(struct ScriptContext *ctx, const u8 *ptr)
{
    ScriptPush(ctx, ctx->scriptPtr);
    ctx->scriptPtr = ptr;
}

void ScriptReturn(struct ScriptContext *ctx)
{
    ctx->scriptPtr = ScriptPop(ctx);
}

u16 ScriptReadHalfword(struct ScriptContext *ctx)
{
    u16 value = *(ctx->scriptPtr++);
    value |= *(ctx->scriptPtr++) << 8;
    return value;
}

u32 ScriptReadWord(struct ScriptContext *ctx)
{
    u32 value0 = *(ctx->scriptPtr++);
    u32 value1 = *(ctx->scriptPtr++);
    u32 value2 = *(ctx->scriptPtr++);
    u32 value3 = *(ctx->scriptPtr++);
    return (((((value3 << 8) + value2) << 8) + value1) << 8) + value0;
}

void ScriptContext2_Enable(void)
{
    sScriptContext2Enabled = TRUE;
}

void ScriptContext2_Disable(void)
{
    sScriptContext2Enabled = FALSE;
}

bool8 ScriptContext2_IsEnabled(void)
{
    return sScriptContext2Enabled;
}

void SetQuestLogInputIsDpadFlag(void)
{
    sQuestLogInputIsDpad = TRUE;
}

void ClearQuestLogInputIsDpadFlag(void)
{
    sQuestLogInputIsDpad = FALSE;
}

bool8 IsQuestLogInputDpad(void)
{
    if(sQuestLogInputIsDpad == TRUE)
        return TRUE;
    else
        return FALSE;
}

void RegisterQuestLogInput(u8 var)
{
    sQuestLogInput = var;
}

void ClearQuestLogInput(void)
{
    sQuestLogInput = 0;
}

u8 GetRegisteredQuestLogInput(void)
{
    return sQuestLogInput;
}

void DisableMsgBoxWalkaway(void)
{
    sMsgBoxWalkawayDisabled = TRUE;
}

void EnableMsgBoxWalkaway(void)
{
    sMsgBoxWalkawayDisabled = FALSE;
}

bool8 IsMsgBoxWalkawayDisabled(void)
{
    return sMsgBoxWalkawayDisabled;
}

void SetWalkingIntoSignVars(void)
{
    gWalkAwayFromSignInhibitTimer = 6;
    sMsgBoxIsCancelable = TRUE;
}

void ClearMsgBoxCancelableState(void)
{
    sMsgBoxIsCancelable = FALSE;
}

bool8 CanWalkAwayToCancelMsgBox(void)
{
    if(sMsgBoxIsCancelable == TRUE)
        return TRUE;
    else
        return FALSE;
}

void MsgSetSignPost(void)
{
    sMsgIsSignPost = TRUE;
}

void MsgSetNotSignPost(void)
{
    sMsgIsSignPost = FALSE;
}

bool8 IsMsgSignPost(void)
{
    if(sMsgIsSignPost == TRUE)
        return TRUE;
    else
        return FALSE;
}

void ResetFacingNpcOrSignPostVars(void)
{
    ResetContextNpcTextColor();
    MsgSetNotSignPost();
}

bool8 ScriptContext1_IsScriptSetUp(void)
{
    if (sScriptContext1Status == 0)
        return TRUE;
    else
        return FALSE;
}

void ScriptContext1_Init(void)
{
    InitScriptContext(&sScriptContext1, gScriptCmdTable, gScriptCmdTableEnd);
    sScriptContext1Status = 2;
}

bool8 ScriptContext2_RunScript(void)
{
    if (sScriptContext1Status == 2)
        return 0;

    if (sScriptContext1Status == 1)
        return 0;

    ScriptContext2_Enable();

    if (!RunScriptCommand(&sScriptContext1))
    {
        sScriptContext1Status = 2;
        ScriptContext2_Disable();
        return 0;
    }

    return 1;
}

void ScriptContext1_SetupScript(const u8 *ptr)
{
    ClearMsgBoxCancelableState();
    EnableMsgBoxWalkaway();
    ClearQuestLogInputIsDpadFlag();
    InitScriptContext(&sScriptContext1, gScriptCmdTable, gScriptCmdTableEnd);
    SetupBytecodeScript(&sScriptContext1, ptr);
    ScriptContext2_Enable();
    sScriptContext1Status = 0;
}

void ScriptContext1_Stop(void)
{
    sScriptContext1Status = 1;
}

void EnableBothScriptContexts(void)
{
    sScriptContext1Status = 0;
    ScriptContext2_Enable();
}

void ScriptContext2_RunNewScript(const u8 *ptr)
{
    InitScriptContext(&sScriptContext2, &gScriptCmdTable, &gScriptCmdTableEnd);
    SetupBytecodeScript(&sScriptContext2, ptr);
    while (RunScriptCommand(&sScriptContext2) == TRUE);
}

u8 *mapheader_get_tagged_pointer(u8 tag)
{
    const u8 *mapScripts = gMapHeader.mapScripts;

    if (mapScripts == NULL)
        return NULL;

    while (1)
    {
        if (*mapScripts == 0)
            return NULL;
        if (*mapScripts == tag)
        {
            mapScripts++;
            return T2_READ_PTR(mapScripts);
        }
        mapScripts += 5;
    }
}

void mapheader_run_script_by_tag(u8 tag)
{
    u8 *ptr = mapheader_get_tagged_pointer(tag);
    if (ptr != NULL)
        ScriptContext2_RunNewScript(ptr);
}

u8 *mapheader_get_first_match_from_tagged_ptr_list(u8 tag)
{
    u8 *ptr = mapheader_get_tagged_pointer(tag);

    if (ptr == NULL)
        return NULL;

    while (1)
    {
        u16 varIndex1;
        u16 varIndex2;
        varIndex1 = ptr[0] | (ptr[1] << 8);
        if (!varIndex1)
            return NULL;
        ptr += 2;
        varIndex2 = ptr[0] | (ptr[1] << 8);
        ptr += 2;
        if (VarGet(varIndex1) == VarGet(varIndex2))
            return (u8 *)(ptr[0] + (ptr[1] << 8) + (ptr[2] << 16) + (ptr[3] << 24));
        ptr += 4;
    }
}

void RunOnLoadMapScript(void)
{
    mapheader_run_script_by_tag(1);
}

void RunOnTransitionMapScript(void)
{
    mapheader_run_script_by_tag(3);
}

void RunOnResumeMapScript(void)
{
    mapheader_run_script_by_tag(5);
}

void RunOnReturnToFieldMapScript(void)
{
    mapheader_run_script_by_tag(7);
}

void RunOnDiveWarpMapScript(void)
{
    mapheader_run_script_by_tag(MAP_SCRIPT_ON_DIVE_WARP);
}

bool8 TryRunOnFrameMapScript(void)
{
    u8 *ptr;

    if(gQuestLogState == QL_STATE_PLAYBACK_LAST)
        return 0;

    ptr = mapheader_get_first_match_from_tagged_ptr_list(2);

    if (!ptr)
        return 0;

    ScriptContext1_SetupScript(ptr);
    return 1;
}

void TryRunOnWarpIntoMapScript(void)
{
    u8 *ptr = mapheader_get_first_match_from_tagged_ptr_list(4);
    if (ptr)
        ScriptContext2_RunNewScript(ptr);
}

u32 CalculateRamScriptChecksum(void)
{
    return CalcCRC16WithTable((u8*)(&gSaveBlock1Ptr->ramScript.data), sizeof(gSaveBlock1Ptr->ramScript.data));
}

void ClearRamScript(void)
{
    CpuFill32(0, &gSaveBlock1Ptr->ramScript, sizeof(struct RamScript));
}

bool8 InitRamScript(u8 *script, u16 scriptSize, u8 mapGroup, u8 mapNum, u8 objectId)
{
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;

    ClearRamScript();

    if (scriptSize > sizeof(scriptData->script))
        return FALSE;

    scriptData->magic = RAM_SCRIPT_MAGIC;
    scriptData->mapGroup = mapGroup;
    scriptData->mapNum = mapNum;
    scriptData->objectId = objectId;
    memcpy(scriptData->script, script, scriptSize);
    gSaveBlock1Ptr->ramScript.checksum = CalculateRamScriptChecksum();
    return TRUE;
}

const u8 *GetRamScript(u8 objectId, const u8 *script)
{
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    gRAMScriptPtr = NULL;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return script;
    if (scriptData->mapGroup != gSaveBlock1Ptr->location.mapGroup)
        return script;
    if (scriptData->mapNum != gSaveBlock1Ptr->location.mapNum)
        return script;
    if (scriptData->objectId != objectId)
        return script;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
    {
        ClearRamScript();
        return script;
    }
    else
    {
        gRAMScriptPtr = script;
        return scriptData->script;
    }
}

bool32 ValidateRamScript(void)
{
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return FALSE;
    if (scriptData->mapGroup != 0xFF)
        return FALSE;
    if (scriptData->mapNum != 0xFF)
        return FALSE;
    if (scriptData->objectId != 0xFF)
        return FALSE;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
        return FALSE;
    return TRUE;
}

u8 *sub_8069E48(void)
{
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    if (!ValidateReceivedWonderCard())
        return NULL;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return NULL;
    if (scriptData->mapGroup != 0xFF)
        return NULL;
    if (scriptData->mapNum != 0xFF)
        return NULL;
    if (scriptData->objectId != 0xFF)
        return NULL;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
    {
        ClearRamScript();
        return NULL;
    }
    else
    {
        return scriptData->script;
    }
}

void MEventSetRamScript(u8 *script, u16 scriptSize)
{
    if (scriptSize > sizeof(gSaveBlock1Ptr->ramScript.data.script))
        scriptSize = sizeof(gSaveBlock1Ptr->ramScript.data.script);
    InitRamScript(script, scriptSize, 0xFF, 0xFF, 0xFF);
}

void GetStartingLevelOfRoute5DaycareMon(void)
{
    ConvertIntToDecimalStringN(gStringVar3, GetLevelFromBoxMonExp(&gSaveBlock1Ptr->route5DayCareMon.mon), STR_CONV_MODE_LEFT_ALIGN, 2);
}

void CheckCurrentMasterTitle(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->masterTrainerTitle;
}

void SetCurrentMasterTitle(void)
{
    gSaveBlock1Ptr->masterTrainerTitle = gSpecialVar_Result;
}

void CheckHasAnyMasterTitle(void)
{
    u32 i;
    bool8 flag = TRUE;

    if(gSaveBlock1Ptr->masterTrainerTitle != 0)
    {
        gSpecialVar_Result = TRUE;
        return;
    }

    for(i = 1; i < 152; i++) //flags start at 1, which is SPECIES_BULBASAUR
    {
        flag = CheckMasterTrainerFlag(i);
        if(flag)
        {
            gSpecialVar_Result = TRUE;
            return;
        }
    }
    gSpecialVar_Result = FALSE;
}

void CheckAllMasterTrainerFlags(void)
{
    u32 i;
    bool8 flag = TRUE;

    for(i = 1; i < 152; i++) //flags start at 1, which is SPECIES_BULBASAUR
    {
        flag = CheckMasterTrainerFlag(i);
        if(!flag)
        {
            gSpecialVar_Result = FALSE;
            return;
        }
    }
    gSpecialVar_Result = TRUE;
}

void ShouldChangeMasterTrainerMovementType(void)
{
    gSpecialVar_Result = CheckMasterTrainerFlag(gSpecialVar_0x8009);
}

void ClearAllButFirstPokemon(void)
{
    u32 i;
    for (i = 1; i < PARTY_SIZE; i++)
        ZeroMonData(&gPlayerParty[i]);
}

void CheckSlot1EVTotal(void)
{
    u8 evs[NUM_STATS];
    u16 totalEVs = 0;
    u32 i;

    for (i = 0; i < NUM_STATS; i++)
    {
        evs[i] = GetMonData(&gPlayerParty[0], MON_DATA_HP_EV + i, NULL);
        totalEVs += evs[i];
    }

    if(totalEVs >= 100)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

void CheckMasterPokemonInSlot1(void)
{
    if(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES2, NULL) == gSpecialVar_0x8009)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;

    //loading a or an into STR_VAR_3 for certain Pokemon...
    switch(gSpecialVar_0x8009)
    {
        case SPECIES_IVYSAUR:
        case SPECIES_ODDISH:
        case SPECIES_ARCANINE:
        case SPECIES_EXEGGCUTE:
        case SPECIES_EXEGGUTOR:
        case SPECIES_EEVEE:
            StringCopy(gStringVar3, gText_An);
            break;
        default:
            StringCopy(gStringVar3, gText_A);
            break;
    }
}

void ShouldSpawnSoftlockClerk(void)
{
    gSpecialVar_Result = CheckAssetsForSoftlock();
}

void HideWarpArrowSprite(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    SetSpriteInvisible(playerObjEvent->warpArrowSpriteId);
}

void CoordsOfPMCExitWarpTo80068007(void)
{
    switch(gMapHeader.regionMapSectionId)
    {
        case MAPSEC_INDIGO_PLATEAU:
            gSpecialVar_0x8006 = 11;
            gSpecialVar_0x8007 = 16;
            return;
        case MAPSEC_ONE_ISLAND:
            gSpecialVar_0x8006 = 9;
            gSpecialVar_0x8007 = 9;
            return;
        default:
            gSpecialVar_0x8006 = 7;
            gSpecialVar_0x8007 = 8;
            return;
    }
}

void HasNationalMonToVarResult(void)
{
    gSpecialVar_Result = HasNationalMon();
}

void TeachTrappedTentacoolSurf(void)
{
    u32 i;
    u32 move = MOVE_SURF;
    u32 pp = 15;
    if(gSpecialVar_0x8007 == 0) //party
    {
        i = CalculatePlayerPartyCount() - 1;
        SetMonData(&gPlayerParty[i], MON_DATA_MOVE4, &move);
        SetMonData(&gPlayerParty[i], MON_DATA_PP1 + 3, &pp);
        return;
    }
    else //box
    {
        SetBoxMonDataAt(gSpecialVar_MonBoxId, gSpecialVar_MonBoxPos, MON_DATA_MOVE4, &move);
        SetBoxMonDataAt(gSpecialVar_MonBoxId, gSpecialVar_MonBoxPos, MON_DATA_PP1 + 3, &pp);
        return;
    }
}

void CheckPlayerTrappedOnCinnabar(void)
{   //gSpecialVar_Result set to 0 if not trapped, 1 if trapped with HM03, and 2 if trapped without HM03
    bool8 haveHM03 = CheckBagHasItem(ITEM_HM03, 1);
    u32 canLearnHM03 = FALSE;
    u32 i, j, k;
    struct Pokemon tempMon;

    //checking party for mon that can learn Surf
    for(i = 0; i < PARTY_SIZE && !canLearnHM03; i++)
    {
        if(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;
        else
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) && MonKnowsMove(&gPlayerParty[i], MOVE_SURF) == TRUE)
            {   //party mon knows Surf, not trapped
                gSpecialVar_Result = 0;
                return;
            }
            canLearnHM03 = CanMonLearnTMHM(&gPlayerParty[i], ITEM_HM03 - ITEM_TM01_FOCUS_PUNCH);
            if(canLearnHM03 && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            {   //check if it already knows 4 HM moves, can't learn Surf
                for(k = 0; k < 4; k++)
                {
                    if(!IsHMMove2(GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + k, NULL)))
                    {   //has free moveslot for Surf
                        canLearnHM03 = TRUE;
                        break;
                    }
                    else
                    {
                        canLearnHM03 = FALSE;
                        continue;
                    }
                }
            }
        }   
    }
    if(haveHM03 && canLearnHM03)
    {   //have party mon that can learn Surf && have HM03
        gSpecialVar_Result = 0;
        return;
    }
    //no party Pokemon that can learn Surf && have HM03, check boxes
    for (i = 0; i < TOTAL_BOXES_COUNT && !canLearnHM03; i++)
    {
        for (j = 0; j < IN_BOX_COUNT && !canLearnHM03; j++)
        {
            if (GetBoxMonDataAt(i, j, MON_DATA_SPECIES) == SPECIES_NONE)
            {
                continue;
            }
            else
            {
                BoxMonToMon(GetBoxedMonPtr(i, j), &tempMon);
                if(MonKnowsMove(&tempMon, MOVE_SURF) == TRUE)
                {   //box mon knows Surf, not trapped
                    gSpecialVar_Result = 0;
                    return;
                }
                canLearnHM03 = CanMonLearnTMHM(&tempMon, ITEM_HM03 - ITEM_TM01_FOCUS_PUNCH);
                if(canLearnHM03 && !GetMonData(&tempMon, MON_DATA_IS_EGG))
                {   //check if it already knows 4 HM moves, can't learn Surf
                    for(k = 0; k < 4; k++)
                    {
                        if(!IsHMMove2(GetMonData(&tempMon, MON_DATA_MOVE1 + k, NULL)))
                        {   //has free moveslot for Surf
                            canLearnHM03 = TRUE;
                            break;
                        }
                        else
                        {
                            canLearnHM03 = FALSE;
                            continue;
                        }
                    }
                }
            }
        }
    }
    if(haveHM03 && canLearnHM03)
    {   //have box mon that can learn Surf && have HM03
        gSpecialVar_Result = 0;
        return;
    }
    if(haveHM03)
    {
        gSpecialVar_Result = 1; //trapped with HM03, give regular Tentacool.
        return;
    }
    //trapped without HM03, give Tentacool with Surf
    gSpecialVar_Result = 2;
    return;
}

void CheckNuzlockeMode(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->keyFlags.nuzlocke;
}

#define SET_SPEAROW_STATE 0
#define SET_TOLD_FAMECHECKER 1
#define SET_VISITOR_STATE 2
#define SET_LEVEL_GROWTH 3
#define CHECK_SPEAROW_STATE 4
#define CHECK_TOLD_FAMECHECKER 5
#define CHECK_VISITOR_STATE 6
#define CHECK_LEVEL_GROWTH 7
#define SET_BOXES_MOVED 8
#define CHECK_BOXES_MOVED 9
#define CHECK_ANY_VISITORS 10
#define CHECK_ALL_TOLD 11
#define CREATE_VISITOR_STRING 12

struct BattleHouse
{
    u16 spearowState:1;     //whether Spearow is gone. 0 for no, 1 for yes
    u16 toldBrock:1;
    u16 toldMisty:1;
    u16 toldLtSurge:1;
    u16 toldErika:1;
    u16 toldKoga:1;
    u16 toldSabrina:1;
    u16 toldBlaine:1;       // ^^ filled out Fame Checker and told lady for person
    // 1 byte
    u16 boxesMoved:1;       // controls setting the layout. Happens when Spearow returns for the first time.
    u16 visitorBrock:1;
    u16 visitorMisty:1;
    u16 visitorLtSurge:1;
    u16 visitorErika:1;
    u16 visitorKoga:1;
    u16 visitorSabrina:1;
    u16 visitorBlaine:1;    // ^^ visitors currently in house
    // 1 byte, overflows into next scripting var
    u16 spawnFails:3;       // after a Gym Leader fails to visit 6 times, this starts forcing visits
    u16 levelGrowth:5;      // adds levels to rematch Pokemon up to level 80. Maxes at +12.
    // 1 byte
    u16 steps:8;            // used to bring back Spearow and bring in visitors
};

static bool8 AllPossibleGymLeadersPresent(void)
{
    struct BattleHouse* BattleHouseVar;
    u16 *varPtr = GetVarPointer(VAR_BATTLE_HOUSE);
    (void*) BattleHouseVar = varPtr;

    if(BattleHouseVar->toldBrock && !BattleHouseVar->visitorBrock)
    {
        return FALSE;
    }
    if(BattleHouseVar->toldMisty && !BattleHouseVar->visitorMisty)
    {
        return FALSE;
    }
    if(BattleHouseVar->toldLtSurge && !BattleHouseVar->visitorLtSurge)
    {
        return FALSE;
    }
    if(BattleHouseVar->toldErika && !BattleHouseVar->visitorErika)
    {
        return FALSE;
    }
    if(BattleHouseVar->toldKoga && !BattleHouseVar->visitorKoga)
    {
        return FALSE;
    }
    if(BattleHouseVar->toldSabrina && !BattleHouseVar->visitorSabrina)
    {
        return FALSE;
    }
    if(BattleHouseVar->toldBlaine && !BattleHouseVar->visitorBlaine)
    {
        return FALSE;
    }
    return TRUE;
}

u8 ReturnBattleHouseLevel(void)
{
    struct BattleHouse* BattleHouseVar;
    u16 *varPtr = GetVarPointer(VAR_BATTLE_HOUSE);
    u8 levelGrowth;
    (void*) BattleHouseVar = varPtr;

    levelGrowth = BattleHouseVar->levelGrowth;

    return levelGrowth;
}

void UpdateBattleHouseStepCounter(void)
{
    struct BattleHouse* BattleHouseVar;
    u16 *varPtr = GetVarPointer(VAR_BATTLE_HOUSE);
    u8 chanceOfVisit = 46;
    (void*) BattleHouseVar = varPtr;

    if(VarGet(VAR_BATTLE_HOUSE) && gMapHeader.regionMapSectionId != MAPSEC_SEVEN_ISLAND)
    {
        if(BattleHouseVar->steps != 255)
            BattleHouseVar->steps++;
        else
        {
            BattleHouseVar->steps++;
            if(BattleHouseVar->spearowState && !BattleHouseVar->boxesMoved)
            {   //Spearow left for the first time, bring it back, open basement, force first leader visit
                BattleHouseVar->spearowState = 0;
                BattleHouseVar->boxesMoved = 1;
                if(BattleHouseVar->toldBrock)
                    BattleHouseVar->visitorBrock = 1;
                if(BattleHouseVar->toldMisty)
                    BattleHouseVar->visitorMisty = 1;
                if(BattleHouseVar->toldLtSurge)
                    BattleHouseVar->visitorLtSurge = 1;
                if(BattleHouseVar->toldErika)
                    BattleHouseVar->visitorErika = 1;
                if(BattleHouseVar->toldKoga)
                    BattleHouseVar->visitorKoga = 1;
                if(BattleHouseVar->toldSabrina)
                    BattleHouseVar->visitorSabrina = 1;
                if(BattleHouseVar->toldBlaine)
                    BattleHouseVar->visitorBlaine = 1;
                return;
            }
            if(BattleHouseVar->spearowState)
            {   //Spearow left, check if it returns
                if(Random() % 2 == 0) //50% chance
                {
                    BattleHouseVar->spearowState = 0;
                }
                return; //no new visitors while Spearow is out
            }
            if(!AllPossibleGymLeadersPresent() && (BattleHouseVar->spawnFails == 6 || Random() % 256 < chanceOfVisit))
            {   //Gym Leader visiting, ~18% chance; will start forcing visits after 6 misses
                u8 counter = 0;
                do{
                    u8 leader = Random() % 7;
                    switch(leader)
                    {
                        case 0:
                            if(BattleHouseVar->toldBrock && !BattleHouseVar->visitorBrock)
                            {
                                BattleHouseVar->visitorBrock = 1;
                                BattleHouseVar->spawnFails = 0;
                                return;
                            }
                            break;
                        case 1:
                            if(BattleHouseVar->toldMisty && !BattleHouseVar->visitorMisty)
                            {
                                BattleHouseVar->visitorMisty = 1;
                                BattleHouseVar->spawnFails = 0;
                                return;
                            }
                            break;
                        case 2:
                            if(BattleHouseVar->toldLtSurge && !BattleHouseVar->visitorLtSurge)
                            {
                                BattleHouseVar->visitorLtSurge = 1;
                                BattleHouseVar->spawnFails = 0;
                                return;
                            }
                            break;
                        case 3:
                            if(BattleHouseVar->toldErika && !BattleHouseVar->visitorErika)
                            {
                                BattleHouseVar->visitorErika = 1;
                                BattleHouseVar->spawnFails = 0;
                                return;
                            }
                            break;
                        case 4:
                            if(BattleHouseVar->toldKoga && !BattleHouseVar->visitorKoga)
                            {
                                BattleHouseVar->visitorKoga = 1;
                                BattleHouseVar->spawnFails = 0;
                                return;
                            }
                            break;
                        case 5:
                            if(BattleHouseVar->toldSabrina && !BattleHouseVar->visitorSabrina)
                            {
                                BattleHouseVar->visitorSabrina = 1;
                                BattleHouseVar->spawnFails = 0;
                                return;
                            }
                            break;
                        case 6:
                            if(BattleHouseVar->toldBlaine && !BattleHouseVar->visitorBlaine)
                            {
                                BattleHouseVar->visitorBlaine = 1;
                                BattleHouseVar->spawnFails = 0;
                                return;
                            }
                            break;
                    }
                    counter++;
                }while(counter < 3 || BattleHouseVar->spawnFails >= 6); //rerolls up to 3 times if doesn't hit; forces a spawn if failed 6 times
                if(counter == 3) //failed 3 rerolls, increment spawnFails
                    if(BattleHouseVar->spawnFails != 7 && !AllPossibleGymLeadersPresent())
                        BattleHouseVar->spawnFails++;
            }
            else
            {
                if(BattleHouseVar->spawnFails != 7 && !AllPossibleGymLeadersPresent())
                    BattleHouseVar->spawnFails++;
            }
        }
    }
}

void UseBattleHouseVar(void)
{
    u8 type = gSpecialVar_0x8003;
    u8 argument = gSpecialVar_0x8004;
    struct BattleHouse* BattleHouseVar;
    u16 *varPtr = GetVarPointer(VAR_BATTLE_HOUSE);
    u8 totalCount = 0;
    u8 runningCount = 0;
    (void*) BattleHouseVar = varPtr;

    switch(type)
    {
        case SET_SPEAROW_STATE:
            BattleHouseVar->spearowState ^= 1; //toggle state
            break;
        case SET_TOLD_FAMECHECKER:
            switch(argument)
            {
                case FAMECHECKER_BROCK:
                    BattleHouseVar->toldBrock = 1;
                    break;
                case FAMECHECKER_MISTY:
                    BattleHouseVar->toldMisty = 1;
                    break;
                case FAMECHECKER_LTSURGE:
                    BattleHouseVar->toldLtSurge = 1;
                    break;
                case FAMECHECKER_ERIKA:
                    BattleHouseVar->toldErika = 1;
                    break;
                case FAMECHECKER_KOGA:
                    BattleHouseVar->toldKoga = 1;
                    break;
                case FAMECHECKER_SABRINA:
                    BattleHouseVar->toldSabrina = 1;
                    break;
                case FAMECHECKER_BLAINE:
                    BattleHouseVar->toldBlaine = 1;
                    break;
            }
            break;
        case SET_VISITOR_STATE:
            switch(argument)
            {
                case FAMECHECKER_BROCK:
                    BattleHouseVar->visitorBrock ^= 1; //toggle state
                    break;
                case FAMECHECKER_MISTY:
                    BattleHouseVar->visitorMisty ^= 1;
                    break;
                case FAMECHECKER_LTSURGE:
                    BattleHouseVar->visitorLtSurge ^= 1;
                    break;
                case FAMECHECKER_ERIKA:
                    BattleHouseVar->visitorErika ^= 1;
                    break;
                case FAMECHECKER_KOGA:
                    BattleHouseVar->visitorKoga ^= 1;
                    break;
                case FAMECHECKER_SABRINA:
                    BattleHouseVar->visitorSabrina ^= 1;
                    break;
                case FAMECHECKER_BLAINE:
                    BattleHouseVar->visitorBlaine ^= 1;
                    break;
            }
            break;
        case SET_LEVEL_GROWTH:
            if(BattleHouseVar->levelGrowth < 12)
                BattleHouseVar->levelGrowth++;
            break;
        case CHECK_SPEAROW_STATE:
            gSpecialVar_Result = BattleHouseVar->spearowState;
            break;
        case CHECK_TOLD_FAMECHECKER:
            switch(argument)
            {
                case FAMECHECKER_BROCK:
                    gSpecialVar_Result = BattleHouseVar->toldBrock;
                    break;
                case FAMECHECKER_MISTY:
                    gSpecialVar_Result = BattleHouseVar->toldMisty;
                    break;
                case FAMECHECKER_LTSURGE:
                    gSpecialVar_Result = BattleHouseVar->toldLtSurge;
                    break;
                case FAMECHECKER_ERIKA:
                    gSpecialVar_Result = BattleHouseVar->toldErika;
                    break;
                case FAMECHECKER_KOGA:
                    gSpecialVar_Result = BattleHouseVar->toldKoga;
                    break;
                case FAMECHECKER_SABRINA:
                    gSpecialVar_Result = BattleHouseVar->toldSabrina;
                    break;
                case FAMECHECKER_BLAINE:
                    gSpecialVar_Result = BattleHouseVar->toldBlaine;
                    break;
            }
            break;
        case CHECK_VISITOR_STATE:
            switch(argument)
            {
                case FAMECHECKER_BROCK:
                    gSpecialVar_Result = BattleHouseVar->visitorBrock;
                    break;
                case FAMECHECKER_MISTY:
                    gSpecialVar_Result = BattleHouseVar->visitorMisty;
                    break;
                case FAMECHECKER_LTSURGE:
                    gSpecialVar_Result = BattleHouseVar->visitorLtSurge;
                    break;
                case FAMECHECKER_ERIKA:
                    gSpecialVar_Result = BattleHouseVar->visitorErika;
                    break;
                case FAMECHECKER_KOGA:
                    gSpecialVar_Result = BattleHouseVar->visitorKoga;
                    break;
                case FAMECHECKER_SABRINA:
                    gSpecialVar_Result = BattleHouseVar->visitorSabrina;
                    break;
                case FAMECHECKER_BLAINE:
                    gSpecialVar_Result = BattleHouseVar->visitorBlaine;
                    break;
            }
            break;
        case CHECK_LEVEL_GROWTH:
            if(BattleHouseVar->levelGrowth > 12)
                gSpecialVar_Result = 12;
            else 
                gSpecialVar_Result = BattleHouseVar->levelGrowth;
            break;
        case SET_BOXES_MOVED:
            BattleHouseVar->boxesMoved = 1;
            break;
        case CHECK_BOXES_MOVED:
            gSpecialVar_Result = BattleHouseVar->boxesMoved;
            break;
        case CHECK_ANY_VISITORS:
            gSpecialVar_Result = 0;
            if(BattleHouseVar->visitorBrock)
            {
                gSpecialVar_Result++;
                StringCopy(gStringVar1, gText_Brock);
            }
            if(BattleHouseVar->visitorMisty)
            {
                gSpecialVar_Result++;
                StringCopy(gStringVar1, gText_Misty);
            }
            if(BattleHouseVar->visitorLtSurge)
            {
                gSpecialVar_Result++;
                StringCopy(gStringVar1, gText_LtSurge);
            }
            if(BattleHouseVar->visitorErika)
            {
                gSpecialVar_Result++;
                StringCopy(gStringVar1, gText_Erika);
            }
            if(BattleHouseVar->visitorKoga)
            {
                gSpecialVar_Result++;
                StringCopy(gStringVar1, gText_Koga);
            }
            if(BattleHouseVar->visitorSabrina)
            {
                gSpecialVar_Result++;
                StringCopy(gStringVar1, gText_Sabrina);
            }
            if(BattleHouseVar->visitorBlaine)
            {
                gSpecialVar_Result++;
                StringCopy(gStringVar1, gText_Blaine);
            }
            break;
        case CHECK_ALL_TOLD:
            gSpecialVar_Result = 0;
            if(BattleHouseVar->toldBrock)
                gSpecialVar_Result++;
            if(BattleHouseVar->toldMisty)
                gSpecialVar_Result++;
            if(BattleHouseVar->toldLtSurge)
                gSpecialVar_Result++;
            if(BattleHouseVar->toldErika)
                gSpecialVar_Result++;
            if(BattleHouseVar->toldKoga)
                gSpecialVar_Result++;
            if(BattleHouseVar->toldSabrina)
                gSpecialVar_Result++;
            if(BattleHouseVar->toldBlaine)
                gSpecialVar_Result++;
            break;
        case CREATE_VISITOR_STRING: //used for mailbox outside
            if(BattleHouseVar->visitorBrock)
                totalCount++;
            if(BattleHouseVar->visitorMisty)
                totalCount++;
            if(BattleHouseVar->visitorLtSurge)
                totalCount++;
            if(BattleHouseVar->visitorErika)
                totalCount++;
            if(BattleHouseVar->visitorKoga)
                totalCount++;
            if(BattleHouseVar->visitorSabrina)
                totalCount++;
            if(BattleHouseVar->visitorBlaine)
                totalCount++;
            StringCopy(gStringVar1, gExpandedPlaceholder_Empty);
            gSpecialVar_Result = 0;
            if(BattleHouseVar->visitorBrock)
            {
                gSpecialVar_Result++;
                runningCount++;
                StringAppend(gStringVar1, gText_Brock);
                if(totalCount != runningCount && totalCount != 2)
                {
                    StringAppend(gStringVar1, gText_CommaSpace);
                    if(runningCount == (totalCount - 1))
                    {
                        StringAppend(gStringVar1, gText_AndSpace);
                    }
                }
                if(totalCount == 2 && runningCount != 2)
                {
                    StringAppend(gStringVar1, gText_RegionMap_Space);
                    StringAppend(gStringVar1, gText_AndSpace);
                }
            }
            if(BattleHouseVar->visitorMisty)
            {
                gSpecialVar_Result++;
                runningCount++;
                StringAppend(gStringVar1, gText_Misty);
                if(totalCount != runningCount && totalCount != 2)
                {
                    StringAppend(gStringVar1, gText_CommaSpace);
                    if(runningCount == (totalCount - 1))
                    {
                        StringAppend(gStringVar1, gText_AndSpace);
                    }
                }
                if(totalCount == 2 && runningCount != 2)
                {
                    StringAppend(gStringVar1, gText_RegionMap_Space);
                    StringAppend(gStringVar1, gText_AndSpace);
                }
            }
            if(BattleHouseVar->visitorLtSurge)
            {
                gSpecialVar_Result++;
                runningCount++;
                StringAppend(gStringVar1, gText_LtSurge);
                if(totalCount != runningCount && totalCount != 2)
                {
                    StringAppend(gStringVar1, gText_CommaSpace);
                    if(runningCount == (totalCount - 1))
                    {
                        StringAppend(gStringVar1, gText_AndSpace);
                    }
                }
                if(totalCount == 2 && runningCount != 2)
                {
                    StringAppend(gStringVar1, gText_RegionMap_Space);
                    StringAppend(gStringVar1, gText_AndSpace);
                }
            }
            if(BattleHouseVar->visitorErika)
            {
                gSpecialVar_Result++;
                runningCount++;
                StringAppend(gStringVar1, gText_Erika);
                if(totalCount != runningCount && totalCount != 2)
                {
                    StringAppend(gStringVar1, gText_CommaSpace);
                    if(runningCount == (totalCount - 1))
                    {
                        StringAppend(gStringVar1, gText_AndSpace);
                    }
                }
                if(totalCount == 2 && runningCount != 2)
                {
                    StringAppend(gStringVar1, gText_RegionMap_Space);
                    StringAppend(gStringVar1, gText_AndSpace);
                }
            }
            if(BattleHouseVar->visitorKoga)
            {
                runningCount++;
                if(gSpecialVar_Result == 4 && totalCount != runningCount)
                {
                    StringAppend(gStringVar1, gText_NewLine);
                    gSpecialVar_Result = 0;
                }
                gSpecialVar_Result++;
                StringAppend(gStringVar1, gText_Koga);
                if(totalCount != runningCount && totalCount != 2)
                {
                    StringAppend(gStringVar1, gText_CommaSpace);
                    if(runningCount == (totalCount - 1))
                    {
                        StringAppend(gStringVar1, gText_AndSpace);
                    }
                }
                if(totalCount == 2 && runningCount != 2)
                {
                    StringAppend(gStringVar1, gText_RegionMap_Space);
                    StringAppend(gStringVar1, gText_AndSpace);
                }
            }
            if(BattleHouseVar->visitorSabrina)
            {
                runningCount++;
                if(gSpecialVar_Result == 4)
                {
                    StringAppend(gStringVar1, gText_NewLine);
                    gSpecialVar_Result = 0;
                }
                gSpecialVar_Result++;
                StringAppend(gStringVar1, gText_Sabrina);
                if(totalCount != runningCount && totalCount != 2)
                {
                    StringAppend(gStringVar1, gText_CommaSpace);
                    if(runningCount == (totalCount - 1))
                    {
                        StringAppend(gStringVar1, gText_AndSpace);
                    }
                }
                if(totalCount == 2 && runningCount != 2)
                {
                    StringAppend(gStringVar1, gText_RegionMap_Space);
                    StringAppend(gStringVar1, gText_AndSpace);
                }
            }
            if(BattleHouseVar->visitorBlaine)
            {
                runningCount++;
                if(gSpecialVar_Result == 4)
                {
                    StringAppend(gStringVar1, gText_NewLine);
                    gSpecialVar_Result = 0;
                }
                gSpecialVar_Result++;
                StringAppend(gStringVar1, gText_Blaine);
            }
            break;

    }
}

#undef SET_SPEAROW_STATE
#undef SET_TOLD_FAMECHECKER
#undef SET_VISITOR_STATE
#undef SET_LEVEL_GROWTH
#undef CHECK_SPEAROW_STATE
#undef CHECK_TOLD_FAMECHECKER
#undef CHECK_VISITOR_STATE
#undef CHECK_LEVEL_GROWTH
#undef SET_BOXES_MOVED
#undef CHECK_BOXES_MOVED
#undef CHECK_ANY_VISITORS
#undef CHECK_ALL_TOLD
#undef CREATE_VISITOR_STRING

void HandleUseExpiredRepel(void)
{
    VarSet(VAR_REPEL_STEP_COUNT, ItemId_GetHoldEffectParam(VarGet(VAR_LAST_REPEL_USED)));
}

void DetermineCeruleanCaveLayout(void)
{
    u32 trainerId = GetPlayerTrainerId();
    u8 result = trainerId % 3;
    gSpecialVar_Result = result;
}

void CheckTrainerCardStars(void)
{
    u8 stars = 0;

    if(FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        stars++;
    }
    if(HasAllKantoMonsNew())
    {
        stars++;
    }
    if(HasAllMonsNew())
    {
        stars++;
    }
    if((gSaveBlock2Ptr->berryPick.berriesPicked >= 200 && gSaveBlock2Ptr->pokeJump.jumpsInRow >= 200) || gSaveBlock2Ptr->battleTower.bestBattleTowerWinStreak > 49)
    {
        stars++;
    }
    gSpecialVar_Result = stars;
}

#define HAS_TICKETS 16
#define NEEDS_SHOW_EON 17
#define NEEDS_SHOW_AURORA 18
#define NEEDS_SHOW_MYSTIC 19
#define NEEDS_SHOW_OLD_SEA_MAP 20
#define HAS_NO_TICKETS 21

void CheckEventTickets(void)
{
    bool8 haveEonTicket     = CheckBagHasItem(ITEM_EON_TICKET, 1);
    bool8 haveAuroraTicket  = CheckBagHasItem(ITEM_AURORA_TICKET, 1);
    bool8 haveMysticTicket  = CheckBagHasItem(ITEM_MYSTIC_TICKET, 1);
    bool8 haveOldSeaMap     = CheckBagHasItem(ITEM_OLD_SEA_MAP, 1);

    bool8 shownEonTicket    = FlagGet(FLAG_SHOWN_EON_TICKET);
    bool8 shownAuroraTicket = FlagGet(FLAG_SHOWN_AURORA_TICKET);
    bool8 shownMysticTicket = FlagGet(FLAG_SHOWN_MYSTIC_TICKET);
    bool8 shownOldSeaMap    = FlagGet(FLAG_SHOWN_OLD_SEA_MAP);

    u8 multichoiceCase = 0;

    if(gSpecialVar_Result == 0) //checking for showing tickets for the first time
    {
        if(shownEonTicket && shownAuroraTicket && shownMysticTicket && shownOldSeaMap)
        {
            gSpecialVar_Result = HAS_TICKETS;
            return;
        }
        if(haveEonTicket && !shownEonTicket)
        {
            gSpecialVar_Result = NEEDS_SHOW_EON;
            return;
        }
        if(haveAuroraTicket && !shownAuroraTicket)
        {
            gSpecialVar_Result = NEEDS_SHOW_AURORA;
            return;
        }
        if(haveMysticTicket && !shownMysticTicket)
        {
            gSpecialVar_Result = NEEDS_SHOW_MYSTIC;
            return;
        }
        if(haveOldSeaMap && !shownOldSeaMap)
        {
            gSpecialVar_Result = NEEDS_SHOW_OLD_SEA_MAP;
            return;
        }
        if(shownEonTicket || shownAuroraTicket || shownMysticTicket || shownOldSeaMap)
        {
            gSpecialVar_Result = HAS_TICKETS;
            return;
        }
        gSpecialVar_Result = HAS_NO_TICKETS;
        return;
    }
    if(gSpecialVar_Result == 1) //checking which multichoice combo to display
    {
        if(haveEonTicket && shownEonTicket)
        {
            multichoiceCase |= 1 << 3; //setting Eon bit
        }
        if(haveAuroraTicket && shownAuroraTicket)
        {
            multichoiceCase |= 1 << 2; //setting Aurora bit
        }
        if(haveMysticTicket && shownMysticTicket)
        {
            multichoiceCase |= 1 << 1; //setting Mystic bit
        }
        if(haveOldSeaMap && shownOldSeaMap)
        {
            multichoiceCase |= 1 << 0; //setting Old Sea Map bit
        }
        gSpecialVar_Result = multichoiceCase;
        return;
    }
    return;
}

#undef HAS_TICKETS
#undef NEEDS_SHOW_EON
#undef NEEDS_SHOW_AURORA
#undef NEEDS_SHOW_MYSTIC
#undef NEEDS_SHOW_OLD_SEA_MAP
#undef HAS_NO_TICKETS

void RecalculatePartyStats(void)
{
    u32 i;
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        CalculateMonStats(&gPlayerParty[i], FALSE);
    }
}

void ResetTintFilter(void)
{
    u8 val = 0;
    gGlobalFieldTintMode = 0;
    SetInitialPlayerAvatarStateWithDirection(DIR_NORTH);
    StopMapMusic();
    do_load_map_stuff_loop(&val);
}

void SetLastViewedPokedexEntry(void)
{
    gSaveBlock1Ptr->lastViewedPokedexEntry = GetStarterSpecies();
}

void TurnOffNuzlockeMode(void)
{
    if(gSaveBlock1Ptr->keyFlags.nuzlocke == 1)
    {
        gSaveBlock1Ptr->keyFlags.nuzlocke = 0;
    }
}

void TurnOffNoPMC(void)
{
    if(gSaveBlock1Ptr->keyFlags.noPMC == 1)
    {
        gSaveBlock1Ptr->keyFlags.noPMC = 0;
    }
}

void SetNoPMCTest(void)
{
    u8 noPMC = gSaveBlock1Ptr->keyFlags.noPMC;

    switch(noPMC)
    {
        case 0:
        default:
            gSaveBlock1Ptr->keyFlags.noPMC = 1;
            return;
        case 1:
            gSaveBlock1Ptr->keyFlags.noPMC = 0;
            return;
    }
}

void IsVersionFireRedToVarResult(void)
{
    if(gSaveBlock1Ptr->keyFlags.version == 0)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

void IsChallengeModeToVarResult(void)
{
    u8 difficulty = gSaveBlock1Ptr->keyFlags.difficulty;
    if(difficulty == DIFFICULTY_CHALLENGE)
    {
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void MoveDaycareMan(void)
{
    if(!FlagGet(FLAG_GOT_RIVAL_STARTER_EGG))
    {
        VarSet(VAR_DAYCARE_MAN_TRIGGERS, 1);
        return;
    }
    if(FlagGet(FLAG_PENDING_DAYCARE_EGG))
    {
        Overworld_SetMapObjTemplateCoords(1, 16, 14);
        TryMoveObjectEventToMapCoords(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 16, 14);
        VarSet(VAR_DAYCARE_MAN_TRIGGERS, 1);
        return;
    }
    /*else
    {
        Overworld_SetMapObjTemplateCoords(1, 16, 13);
        TryMoveObjectEventToMapCoords(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, 16, 13);
        VarSet(VAR_DAYCARE_MAN_TRIGGERS, 1);
        return;
    }*/
}

void FillBagsTest(void)
{
    u32 i;
    //pokeballs
    for(i = 1; i < 13; i++)
    {
        AddBagItem(i, 999);
    }

    //regular items starting with Potion
    for(i = 13; i < 52; i++)
    {
        AddBagItem(i, 999);
    }

    //regular items starting with HP UP, skipping ??????????s
    for(i = 63; i < 87; i++)
    {
        if(i == 72 || i == 82) //skipping random ??????????s
        {
            continue;
        }
        AddBagItem(i, 999);
    }

    //regular items starting with Sun Stone, skipping ??????????s
    for(i = 93; i < 99; i++)
    {
        AddBagItem(i, 999);
    }

    //regular items starting with TinyMushroom, skipping ??????????s
    for(i = 103; i < 112; i++)
    {
        if(i == 105) //skipping random ??????????
        {
            continue;
        }
        AddBagItem(i, 999);
    }

    //regular items starting with Orange Mail
    for(i = 121; i < 133; i++)
    {
        AddBagItem(i, 999);
    }

    //hold items starting with Brightpowder
    for(i = 179; i < 226; i++)
    {
        AddBagItem(i, 999);
    }

    //Contest Scarves (skipping a bunch of ??????????s)
    for(i = 254; i < 259; i++)
    {
        AddBagItem(i, 999);
    }

    //RSE key items that get used in FRLG, starting with Coin Case
    for(i = 260; i < 266; i++)
    {
        AddBagItem(i, 1);
    }

    //FRLG key items starting with Oak's Parcel
    for(i = 349; i < 375; i++)
    {
        AddBagItem(i, 1);
    }

    //berries
    for(i = 133; i < 176; i++)
    {
        AddBagItem(i, 999);
    }

    //TMs and HMs
    for(i = 289; i < 347; i++)
    {
        AddBagItem(i, 999);
    }

    //Old Sea Map
    AddBagItem(376, 1);

    //Link Bracelet
    AddBagItem(112, 1);
}
