.set LOCALID_SANDSHREW_MASTER, 15
.set LOCALID_METAPOD_MASTER, 14
.set TRAINER, VAR_0x8009

Route11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route11_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_SANDSHREW
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route11_MapScript_SandshrewMasterMovementType
	setvar TRAINER, MASTER_METAPOD
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route11_MapScript_MetapodMasterMovementType
	end

Route11_MapScript_SandshrewMasterMovementType::
	setobjectmovementtype LOCALID_SANDSHREW_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route11_MapScript_MetapodMasterMovementType::
	setobjectmovementtype LOCALID_METAPOD_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route11_EventScript_DiglettsCaveSign::
	msgbox Route11_Text_DiglettsCave, MSGBOX_SIGN
	end
