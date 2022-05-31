#ifndef GUARD_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_SCRIPT_COMMANDS_H

#include "global.h"

#define STAT_CHANGE_WORKED      0
#define STAT_CHANGE_DIDNT_WORK  1

#define WINDOW_CLEAR            0x1
#define WINDOW_x80              0x80

void SetMoveEffect(bool8 primary, u8 certain);
bool8 UproarWakeUpCheck(u8 battlerId);
u8 AI_TypeCalc(u16 move, u16 targetSpecies, u8 targetAbility);
u8 TypeCalc(u16 move, u8 attacker, u8 defender);
void AI_CalcDmg(u8 attacker, u8 defender);
bool32 IsMonGettingExpSentOut(void);
void BattleCreateYesNoCursorAt(void);
void BattleDestroyYesNoCursorAt(void);
void HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags);
u8 GetBattlerTurnOrderNum(u8 battlerId);
void BufferMoveToLearnIntoBattleTextBuff2(void);

extern void (* const gBattleScriptingCommandsTable[])(void);
extern const u16 gNaturePowerMoves[];

#endif // GUARD_BATTLE_SCRIPT_COMMANDS_H
