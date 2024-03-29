.set LOCALID_MEWTWO_MASTER, 7
.set LOCALID_MEW_MASTER, 8
.set TRAINER, VAR_0x8009

PokemonMansion_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonMansion_B1F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

PokemonMansion_B1F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MEWTWO
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, PokemonMansion_B1F_MapScript_MewtwoMasterMovementType
	setvar TRAINER, MASTER_MEW
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, PokemonMansion_B1F_MapScript_MewMasterMovementType
	end

PokemonMansion_B1F_MapScript_MewtwoMasterMovementType::
	setobjectmovementtype LOCALID_MEWTWO_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

PokemonMansion_B1F_MapScript_MewMasterMovementType::
	setobjectmovementtype LOCALID_MEW_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

PokemonMansion_B1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_B1F
	end

PokemonMansion_B1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 3
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_B1F_EventScript_DiarySep1st::
	msgbox PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful, MSGBOX_SIGN
	end

PokemonMansion_B1F_EventScript_Lewis::
	trainerbattle_single TRAINER_BURGLAR_LEWIS, PokemonMansion_B1F_Text_LewisIntro, PokemonMansion_B1F_Text_LewisDefeat
	msgbox PokemonMansion_B1F_Text_LewisPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_SCIENTIST_IVAN, PokemonMansion_B1F_Text_IvanIntro, PokemonMansion_B1F_Text_IvanDefeat
	msgbox PokemonMansion_B1F_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end
