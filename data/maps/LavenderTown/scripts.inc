.set LOCALID_GASTLY_MASTER, 5
.set LOCALID_HAUNTER_MASTER, 6
.set LOCALID_GENGAR_MASTER, 7
.set TRAINER, VAR_0x8009

LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	goto LavenderTown_MapScript_SetMasterTrainerMovementTypes
	end

LavenderTown_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_GASTLY
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, LavenderTown_MapScript_GastlyMasterMovementType
	setvar TRAINER, MASTER_HAUNTER
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, LavenderTown_MapScript_HaunterMasterMovementType
	setvar TRAINER, MASTER_GENGAR
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, LavenderTown_MapScript_GengarMasterMovementType
	end

LavenderTown_MapScript_GastlyMasterMovementType::
	setobjectmovementtype LOCALID_GASTLY_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

LavenderTown_MapScript_HaunterMasterMovementType::
	setobjectmovementtype LOCALID_HAUNTER_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

LavenderTown_MapScript_GengarMasterMovementType::
	setobjectmovementtype LOCALID_GENGAR_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end
