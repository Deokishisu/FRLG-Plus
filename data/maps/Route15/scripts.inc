.set LOCALID_TANGELA_MASTER, 15
.set LOCALID_VENOMOTH_MASTER, 16
.set LOCALID_DODRIO_MASTER, 17
.set TRAINER, VAR_0x8009

Route15_MapScripts:: @ 81680DB
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route15_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_TANGELA
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route15_MapScript_TangelaMasterMovementType
	setvar TRAINER, MASTER_VENOMOTH
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route15_MapScript_VenomothMasterMovementType
	setvar TRAINER, MASTER_DODRIO
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route15_MapScript_DodrioMasterMovementType
	end

Route15_MapScript_TangelaMasterMovementType::
	setobjectmovementtype LOCALID_TANGELA_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return
	
Route15_MapScript_VenomothMasterMovementType::
	setobjectmovementtype LOCALID_VENOMOTH_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route15_MapScript_DodrioMasterMovementType::
	setobjectmovementtype LOCALID_DODRIO_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return


Route15_EventScript_RouteSign:: @ 81680DC
	msgbox Route15_Text_RouteSign, MSGBOX_SIGN
	end
