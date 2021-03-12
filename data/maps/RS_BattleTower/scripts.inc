.set LOCALID_SUDOWOODO, 7

RS_BattleTower_MapScripts:: @ 8160156
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume: @ 8242C0F
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo:: @ 8242C19
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition: @ 8242C2D
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo:: @ 8242C3F
	goto_if_set FLAG_CAUGHT_SUDOWOODO, EventScript_Return
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleTower_Outside_EventScript_16025A:: @ 816025A
	msgbox BattleTower_Outside_Text_199C6F, MSGBOX_SIGN
	end

BattleTower_Outside_EventScript_160263:: @ 8160263
	msgbox BattleTower_Outside_Text_199CA4, MSGBOX_NPC
	end

BattleTower_Outside_EventScript_16026C:: @ 816026C
	msgbox BattleTower_Outside_Text_199E9C, MSGBOX_NPC
	end

BattleTower_Outside_EventScript_160275:: @ 8160275
	msgbox BattleTower_Outside_Text_199ED4, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman:: @ 8242DE9
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	goto_if_set FLAG_CAUGHT_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	goto_if_set FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	turnobject 6, DIR_SOUTH //remove later
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone:: @ 8242DFE
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	turnobject 6, DIR_SOUTH //remove later
	release
	end

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle: //change text to match EM later
	.string "Excuse me, young one.\n"
	.string "Have you good eyesight?\p"
	.string "There is an odd tree here, and to\n"
	.string "my tired eyes it seems to wiggle.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere: //change text to match EM later
	.string "Excuse me, young one.\n"
	.string "Have you a good memory?\p"
	.string "I have this feeling there once was\n"
	.string "an odd tree here.$"

BattleFrontier_OutsideEast_EventScript_Sudowoodo:: @ 8242CEA
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	checkitem ITEM_FRESH_WATER, 1
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_OutsideEast_EventScript_AskWaterSudowoodo
	release
	end

BattleFrontier_OutsideEast_EventScript_AskWaterSudowoodo::
	msgbox BattleFrontier_OutsideEast_Text_UseFreshWater MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_OutsideEast_EventScript_WaterSudowoodo
	release
	end

BattleFrontier_OutsideEast_Text_UseFreshWater::
	.string "It's a weird tree.\n"
	.string "Water it with a FRESH WATER?$"

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo:: @ 8242CFC
	lock
	faceplayer
	removeitem ITEM_FRESH_WATER, 1
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShakeAngry
	waitmovement 0
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShakeAngry
	waitmovement 0
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShakeAngry
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq BattleFrontier_OutsideEast_EventScript_RanFromSudowoodo
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq BattleFrontier_OutsideEast_EventScript_RanFromSudowoodo
	setflag FLAG_CAUGHT_SUDOWOODO
	release
	end

gText_Sudowoodo_Attacked:: @ 82731BD
	.string "The weird tree doesn't like the\n"
	.string "FRESH WATER!\p"
	.string "The weird tree attacked!$"

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo:: @ 8242D60
	setflag FLAG_DEFEATED_SUDOWOODO
	goto BattleFrontier_OutsideEast_EventScript_RanFromSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_RanFromSudowoodo::
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox Text_WeirdTreeFledSomewhere
    release
    end

Text_WeirdTreeFledSomewhere::
	.string "The weird tree fled elsewhere…$"

BattleFrontier_OutsideEast_Movement_SudowoodoShake: @ 8242D69
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_Movement_SudowoodoShakeAngry: @ 8242D69
	face_right
	delay_2
	face_down
	delay_2
	face_left
	delay_2
	face_down
	delay_2
	face_right
	delay_2
	face_down
	delay_2
	face_left
	delay_2
	face_down
	step_end