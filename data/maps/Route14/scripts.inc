.set LOCALID_VILEPLUME_MASTER, 16
.set LOCALID_IVYSAUR_MASTER, 17
.set TRAINER, VAR_0x8009

Route14_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route14_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_VILEPLUME
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route14_MapScript_VileplumeMasterMovementType
	setvar TRAINER, MASTER_IVYSAUR
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route14_MapScript_IvysaurMasterMovementType
	end

Route14_MapScript_VileplumeMasterMovementType::
	setobjectmovementtype LOCALID_VILEPLUME_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route14_MapScript_IvysaurMasterMovementType::
	setobjectmovementtype LOCALID_IVYSAUR_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route14_EventScript_RouteSign::
	msgbox Route14_Text_RouteSign, MSGBOX_SIGN
	end
