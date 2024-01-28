.set LOCALID_STARYU_MASTER, 13
.set LOCALID_HORSEA_MASTER, 14
.set LOCALID_SHELLDER_MASTER, 15
.set TRAINER, VAR_0x8009

Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route19_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_STARYU
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route19_MapScript_StaryuMasterMovementType
	setvar TRAINER, MASTER_HORSEA
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route19_MapScript_HorseaMasterMovementType
	setvar TRAINER, MASTER_SHELLDER
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route19_MapScript_ShellderMasterMovementType
	end

Route19_MapScript_StaryuMasterMovementType::
	setobjectmovementtype LOCALID_STARYU_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return
	
Route19_MapScript_HorseaMasterMovementType::
	setobjectmovementtype LOCALID_HORSEA_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_SWIM
	return

Route19_MapScript_ShellderMasterMovementType::
	setobjectmovementtype LOCALID_SHELLDER_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_SWIM
	return

Route19_EventScript_RouteSign::
	msgbox Route19_Text_RouteSign, MSGBOX_SIGN
	end
