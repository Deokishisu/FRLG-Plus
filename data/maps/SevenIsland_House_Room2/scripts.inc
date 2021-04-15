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

SevenIsland_House_Room2_Eventscript_GymLeaderDummy::
	lock
	faceplayer
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	msgbox SevenIsland_House_Room2_Text_Battle_NYI, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_GymLeaderDeclined
	switch VAR_LAST_TALKED
	case LOCALID_BROCK, SevenIsland_House_Room2_Eventscript_BrockBattle
	case LOCALID_MISTY, SevenIsland_House_Room2_Eventscript_MistyBattle
	case LOCALID_LT_SURGE, SevenIsland_House_Room2_Eventscript_LtSurgeBattle
	case LOCALID_ERIKA, SevenIsland_House_Room2_Eventscript_ErikaBattle
	case LOCALID_KOGA, SevenIsland_House_Room2_Eventscript_KogaBattle
	case LOCALID_SABRINA, SevenIsland_House_Room2_Eventscript_SabrinaBattle
	case LOCALID_BLAINE, SevenIsland_House_Room2_Eventscript_BlaineBattle
	release
	end

SevenIsland_House_Room2_Eventscript_BrockBattle:
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeBrockBattle
	trainerbattle_no_intro TRAINER_BROCK_REMATCH, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeBrockBattle:
	trainerbattle_no_intro TRAINER_BROCK_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_MistyBattle:
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeMistyBattle
	trainerbattle_no_intro TRAINER_MISTY_REMATCH, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeMistyBattle:
	trainerbattle_no_intro TRAINER_MISTY_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_LtSurgeBattle:
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeLtSurgeBattle
	trainerbattle_no_intro TRAINER_LT_SURGE_REMATCH, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeLtSurgeBattle:
	trainerbattle_no_intro TRAINER_LT_SURGE_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_ErikaBattle:
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeErikaBattle
	trainerbattle_no_intro TRAINER_ERIKA_REMATCH, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeErikaBattle:
	trainerbattle_no_intro TRAINER_ERIKA_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_KogaBattle:
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeKogaBattle
	trainerbattle_no_intro TRAINER_KOGA_REMATCH, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeKogaBattle:
	trainerbattle_no_intro TRAINER_KOGA_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_SabrinaBattle:
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeSabrinaBattle
	trainerbattle_no_intro TRAINER_SABRINA_REMATCH, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeSabrinaBattle:
	trainerbattle_no_intro TRAINER_SABRINA_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_BlaineBattle:
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeBlaineBattle
	trainerbattle_no_intro TRAINER_BLAINE_REMATCH, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_ChallengeBlaineBattle:
	trainerbattle_no_intro TRAINER_BLAINE_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_NYI
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	release
	end

SevenIsland_House_Room2_Eventscript_GymLeaderDeclined::
	msgbox SevenIsland_House_Room2_Text_NYI, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_NYI:
	.string "This text is not\n"
	.string "yet implemented.$"

SevenIsland_House_Room2_Text_Battle_NYI:
	.string "Rematch this Gym Leader?\n"
	.string "(NYI text)$"