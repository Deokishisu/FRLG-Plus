.set LOCALID_TANGELA_MASTER, 15
.set LOCALID_VENOMOTH_MASTER, 16
.set LOCALID_DODRIO_MASTER, 17
.set TRAINER, VAR_0x8009

Route15_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route15_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_TANGELA
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route15_MapScript_TangelaMasterMovementType
	setvar TRAINER, MASTER_VENOMOTH
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route15_MapScript_VenomothMasterMovementType
	setvar TRAINER, MASTER_DODRIO
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route15_MapScript_DodrioMasterMovementType
	end

Route15_MapScript_TangelaMasterMovementType::
	setobjectmovementtype LOCALID_TANGELA_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return
	
Route15_MapScript_VenomothMasterMovementType::
	setobjectmovementtype LOCALID_VENOMOTH_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route15_MapScript_DodrioMasterMovementType::
	setobjectmovementtype LOCALID_DODRIO_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return


Route15_EventScript_RouteSign::
	msgbox Route15_Text_RouteSign, MSGBOX_SIGN
	end
