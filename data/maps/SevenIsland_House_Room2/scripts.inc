.equ LOCALID_BROCK, 1
.equ LOCALID_MISTY, 2
.equ LOCALID_LT_SURGE, 3
.equ LOCALID_ERIKA, 4
.equ LOCALID_KOGA, 5
.equ LOCALID_SABRINA, 6
.equ LOCALID_BLAINE, 7

.equ SET_SPEAROW_STATE, 0
.equ SET_TOLD_FAMECHECKER, 1
.equ SET_VISITOR_STATE, 2
.equ SET_LEVEL_GROWTH, 3
.equ CHECK_SPEAROW_STATE, 4
.equ CHECK_TOLD_FAMECHECKER, 5
.equ CHECK_VISITOR_STATE, 6
.equ CHECK_LEVEL_GROWTH, 7
.equ SET_BOXES_MOVED, 8
.equ CHECK_BOXES_MOVED, 9

.equ TYPE, VAR_0x8003
.equ ARGUMENT, VAR_0x8004
.equ LEADER_READY, VAR_0x8006
.equ X_COORD, VAR_0x8007
.equ Y_COORD, VAR_0x8008

SevenIsland_House_Room2_MapScripts:: @ 8170A7E
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_House_Room2_OnTransition
	.byte 0

SevenIsland_House_Room2_OnTransition:: @ 8170A89
	setvar TYPE, CHECK_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_BROCK
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideBrock
	setvar ARGUMENT, FAMECHECKER_MISTY
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideMisty
	setvar ARGUMENT, FAMECHECKER_LTSURGE
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideLtSurge
	setvar ARGUMENT, FAMECHECKER_ERIKA
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideErika
	setvar ARGUMENT, FAMECHECKER_KOGA
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideKoga
	setvar ARGUMENT, FAMECHECKER_SABRINA
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideSabrina
	setvar ARGUMENT, FAMECHECKER_BLAINE
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideBlaine
	end

SevenIsland_House_Room2_HideBrock::
	setflag FLAG_TEMP_1
	return

SevenIsland_House_Room2_HideMisty::
	setflag FLAG_TEMP_2
	return

SevenIsland_House_Room2_HideLtSurge::
	setflag FLAG_TEMP_3
	return

SevenIsland_House_Room2_HideErika::
	setflag FLAG_TEMP_4
	return

SevenIsland_House_Room2_HideKoga::
	setflag FLAG_TEMP_5
	return

SevenIsland_House_Room2_HideSabrina::
	setflag FLAG_TEMP_6
	return

SevenIsland_House_Room2_HideBlaine::
	setflag FLAG_TEMP_7
	return	
	
SevenIsland_House_Room2_EventScript_LeftPainting::
	msgbox SevenIsland_House_Room2_Text_LeftPainting, MSGBOX_SIGN
	end

SevenIsland_House_Room2_Text_LeftPainting::
	.string "It's a photo of a young woman.\n"
	.string "She's surrounded by happy,\l"
	.string "strong-looking POKéMON.$"

SevenIsland_House_Room2_EventScript_MiddlePainting::
	msgbox SevenIsland_House_Room2_Text_MiddlePainting, MSGBOX_SIGN
	end

SevenIsland_House_Room2_Text_MiddlePainting::
	.string "It's a photo of a young woman.\n"
	.string "A SPEAROW perches on her arm.$"

SevenIsland_House_Room2_EventScript_RightPainting::
	compare VAR_STARTER_MON, 0
	call_if_eq SevenIsland_House_Room2_EventScript_BufferBulbasaur
	compare VAR_STARTER_MON, 1
	call_if_eq SevenIsland_House_Room2_EventScript_BufferSquirtle
	compare VAR_STARTER_MON, 2
	call_if_ge SevenIsland_House_Room2_EventScript_BufferCharmander
	msgbox SevenIsland_House_Room2_Text_RightPainting, MSGBOX_SIGN
	end

SevenIsland_House_Room2_Text_RightPainting::
	.string "It's a photo of a TRAINER battle.\p"
	.string "A young woman is ordering her\n"
	.string "{STR_VAR_1} to attack an opposing\l"
	.string "{STR_VAR_2}.\p"
	.string "A SPEAROW hovers above the battle,\n"
	.string "watching intently.$"

SevenIsland_House_Room2_EventScript_BufferBulbasaur::
	getspeciesname 0, SPECIES_VENUSAUR
	getspeciesname 1, SPECIES_CHARIZARD
	return

SevenIsland_House_Room2_EventScript_BufferSquirtle::
	getspeciesname 0, SPECIES_BLASTOISE
	getspeciesname 1, SPECIES_VENUSAUR
	return

SevenIsland_House_Room2_EventScript_BufferCharmander::
	getspeciesname 0, SPECIES_CHARIZARD
	getspeciesname 1, SPECIES_BLASTOISE
	return

SevenIsland_House_Room2_EventScript_HealingMachine::
	msgbox SevenIsland_House_Room2_Text_HealPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SevenIsland_House_Room2_EventScript_HealPokemon
	release
	end

SevenIsland_House_Room2_Text_HealPokemon::
	.string "Use the machine to heal\n"
	.string "your POKéMON?$"

SevenIsland_House_Room2_EventScript_HealPokemon::
	release
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 24
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	special HealPlayerParty
	release
	end

SevenIsland_House_Room2_Eventscript_Trigger::
	compare LEADER_READY, 0
	goto_if_eq EventScript_ReleaseEnd
	applymovement OBJ_EVENT_ID_PLAYER, SevenIsland_House_Room2_Movement_StepFastestRight
	waitmovement 0
	switch LEADER_READY
	case LOCALID_BROCK, SevenIsland_House_Room2_Eventscript_BrockBattle
	case LOCALID_MISTY, SevenIsland_House_Room2_Eventscript_MistyBattle
	case LOCALID_LT_SURGE, SevenIsland_House_Room2_Eventscript_LtSurgeBattle
	case LOCALID_ERIKA, SevenIsland_House_Room2_Eventscript_ErikaBattle
	case LOCALID_KOGA, SevenIsland_House_Room2_Eventscript_KogaBattle
	case LOCALID_SABRINA, SevenIsland_House_Room2_Eventscript_SabrinaBattle
	case LOCALID_BLAINE, SevenIsland_House_Room2_Eventscript_BlaineBattle
	release
	end

@ LEADER BROCK
SevenIsland_House_Room2_Eventscript_Brock::
	lock
	faceplayer
	compare LEADER_READY, 1
	goto_if_eq SevenIsland_House_Room2_Eventscript_BrockReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_BrockOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	msgbox SevenIsland_House_Room2_Text_Battle_NYI, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_BrockDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveBrockDown
	compare Y_COORD, 6
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveBrockLeft
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_BrockToMat
	waitmovement 0
	setobjectmovementtypeinstant LOCALID_BROCK, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_BROCK
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Eventscript_BrockReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_BrockOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_BrockDeclined::
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_MoveBrockDown:
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_BrockAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveBrockLeft:
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_BrockRight
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_BrockAroundPlayer:
	walk_down
	walk_right
	walk_right
	walk_up
	step_end

SevenIsland_House_Room2_Movement_BrockRight:
	walk_right
	walk_right
	step_end

SevenIsland_House_Room2_Movement_BrockToMat:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_BrockBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_BROCK
	callnative UseBattleHouseVar
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeBrockBattle
	trainerbattle_no_intro TRAINER_BROCK_REMATCH, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_BrockExit
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeBrockBattle:
	trainerbattle_no_intro TRAINER_BROCK_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_BrockExit
	release
	end

SevenIsland_House_Room2_Eventscript_BrockExit:
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_BROCK
	release
	end

@ LEADER MISTY
SevenIsland_House_Room2_Eventscript_Misty::
	lock
	faceplayer
	compare LEADER_READY, 2
	goto_if_eq SevenIsland_House_Room2_Eventscript_MistyReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_MistyOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	msgbox SevenIsland_House_Room2_Text_Battle_NYI, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_MistyDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 3
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveMistyRight
	compare Y_COORD, 3
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveMistyDown
	setobjectmovementtypeinstant LOCALID_MISTY, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_MISTY
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Eventscript_MistyReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_MistyOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_MistyDeclined::
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_MoveMistyRight:
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_MistyAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveMistyDown:
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_MistyDownToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_MistyAroundPlayer:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_MistyDownToMat:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_MistyBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_MISTY
	callnative UseBattleHouseVar
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeMistyBattle
	trainerbattle_no_intro TRAINER_MISTY_REMATCH, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_MistyExit
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeMistyBattle:
	trainerbattle_no_intro TRAINER_MISTY_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_MistyExit
	release
	end

SevenIsland_House_Room2_Eventscript_MistyExit:
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_MISTY
	release
	end

@ LEADER LTSURGE
SevenIsland_House_Room2_Eventscript_LtSurge::
	lock
	faceplayer
	compare LEADER_READY, 1
	goto_if_eq SevenIsland_House_Room2_Eventscript_LtSurgeReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_LtSurgeOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	msgbox SevenIsland_House_Room2_Text_Battle_NYI, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_LtSurgeDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 5
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveLtSurgeLeft
	compare Y_COORD, 5
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveLtSurgeDown
	setobjectmovementtypeinstant LOCALID_LT_SURGE, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_LT_SURGE
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Eventscript_LtSurgeReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_LtSurgeOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_LtSurgeDeclined::
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_MoveLtSurgeLeft:
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_LtSurgeAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveLtSurgeDown:
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_LtSurgeToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_LtSurgeAroundPlayer:
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_LtSurgeToMat:
	walk_down
	walk_left
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_LtSurgeBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_LTSURGE
	callnative UseBattleHouseVar
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeLtSurgeBattle
	trainerbattle_no_intro TRAINER_LT_SURGE_REMATCH, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_LtSurgeExit
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeLtSurgeBattle:
	trainerbattle_no_intro TRAINER_LT_SURGE_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_LtSurgeExit
	release
	end

SevenIsland_House_Room2_Eventscript_LtSurgeExit:
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_LT_SURGE
	release
	end

@ LEADER ERIKA
SevenIsland_House_Room2_Eventscript_Erika::
	lock
	faceplayer
	compare LEADER_READY, 2
	goto_if_eq SevenIsland_House_Room2_Eventscript_ErikaReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_ErikaOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	msgbox SevenIsland_House_Room2_Text_Battle_NYI, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ErikaDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 3
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveErikaRight
	compare Y_COORD, 3
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveErikaDown
	setobjectmovementtypeinstant LOCALID_ERIKA, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_ERIKA
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Eventscript_ErikaReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_ErikaOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_ErikaDeclined::
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_MoveErikaRight:
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_ErikaAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveErikaDown:
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_ErikaDownToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_ErikaAroundPlayer:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_ErikaDownToMat:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_ErikaBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_ERIKA
	callnative UseBattleHouseVar
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeErikaBattle
	trainerbattle_no_intro TRAINER_ERIKA_REMATCH, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_ErikaExit
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeErikaBattle:
	trainerbattle_no_intro TRAINER_ERIKA_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_ErikaExit
	release
	end

SevenIsland_House_Room2_Eventscript_ErikaExit:
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_ERIKA
	release
	end

@ LEADER KOGA
SevenIsland_House_Room2_Eventscript_Koga::
	lock
	faceplayer
	compare LEADER_READY, 1
	goto_if_eq SevenIsland_House_Room2_Eventscript_KogaReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_KogaOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	msgbox SevenIsland_House_Room2_Text_Battle_NYI, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_KogaDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 7
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveKogaRight
	compare Y_COORD, 7
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveKogaUp
	setobjectmovementtypeinstant LOCALID_KOGA, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_KOGA
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Eventscript_KogaReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_KogaOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_KogaDeclined::
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_MoveKogaRight:
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_KogaAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveKogaUp:
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_KogaToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_KogaAroundPlayer:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_KogaToMat:
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_KogaBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_KOGA
	callnative UseBattleHouseVar
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeKogaBattle
	trainerbattle_no_intro TRAINER_KOGA_REMATCH, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_KogaExit
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeKogaBattle:
	trainerbattle_no_intro TRAINER_KOGA_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_KogaExit
	release
	end

SevenIsland_House_Room2_Eventscript_KogaExit:
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_KOGA
	release
	end

@ LEADER SABRINA
SevenIsland_House_Room2_Eventscript_Sabrina::
	lock
	faceplayer
	compare LEADER_READY, 2
	goto_if_eq SevenIsland_House_Room2_Eventscript_SabrinaReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_SabrinaOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	msgbox SevenIsland_House_Room2_Text_Battle_NYI, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_SabrinaDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveSabrinaRight
	compare Y_COORD, 6
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveSabrinaUp
	setobjectmovementtypeinstant LOCALID_SABRINA, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_SABRINA
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Eventscript_SabrinaReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_SabrinaOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_SabrinaDeclined::
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_MoveSabrinaRight:
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_SabrinaAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveSabrinaUp:
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_SabrinaUpToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_SabrinaAroundPlayer:
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_SabrinaUpToMat:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_SabrinaBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_SABRINA
	callnative UseBattleHouseVar
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeSabrinaBattle
	trainerbattle_no_intro TRAINER_SABRINA_REMATCH, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_SabrinaExit
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeSabrinaBattle:
	trainerbattle_no_intro TRAINER_SABRINA_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_SabrinaExit
	release
	end

SevenIsland_House_Room2_Eventscript_SabrinaExit:
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_SABRINA
	release
	end

@ LEADER BLAINE
SevenIsland_House_Room2_Eventscript_Blaine::
	lock
	faceplayer
	compare LEADER_READY, 1
	goto_if_eq SevenIsland_House_Room2_Eventscript_BlaineReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_BlaineOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	msgbox SevenIsland_House_Room2_Text_Battle_NYI, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_BlaineDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 5
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveBlaineLeft
	compare Y_COORD, 5
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveBlaineUp
	setobjectmovementtypeinstant LOCALID_BLAINE, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_BLAINE
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Eventscript_BlaineReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_BlaineOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_BlaineDeclined::
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Eventscript_MoveBlaineLeft:
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_BlaineAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveBlaineUp:
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_BlaineUpToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_BlaineAroundPlayer:
	walk_left
	walk_up
	walk_left
	walk_left
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_BlaineUpToMat:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_BlaineBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_BLAINE
	callnative UseBattleHouseVar
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeBlaineBattle
	trainerbattle_no_intro TRAINER_BLAINE_REMATCH, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_BlaineExit
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeBlaineBattle:
	trainerbattle_no_intro TRAINER_BLAINE_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_BlaineExit
	release
	end

SevenIsland_House_Room2_Eventscript_BlaineExit:
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_BLAINE
	release
	end

SevenIsland_House_Room2_Eventscript_CheckInFront:
	compare Y_COORD, 5
	goto_if_eq EventScript_ReleaseEnd
	return

SevenIsland_House_Room2_Movement_LeaderExits:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_4
	set_invisible
	step_end

SevenIsland_House_Room2_Movement_StepFastestLeft:
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_StepFastestRight:
	walk_in_place_fastest_Right
	step_end

SevenIsland_House_Room2_Text_NYI:
	.string "This text is not\n"
	.string "yet implemented.$"

SevenIsland_House_Room2_Text_Battle_NYI:
	.string "Rematch this Gym Leader?\n"
	.string "(NYI text)$"