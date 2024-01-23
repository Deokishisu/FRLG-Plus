.set LOCALID_PIDGEY_MASTER, 8
.set LOCALID_PARASECT_MASTER, 9
.set TRAINER, VAR_0x8009

Route2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route2_MapScript_FixLedgeForMasterTrainer
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route2_MapScript_FixLedgeForMasterTrainer::
	goto_if_set FLAG_HIDE_MASTER_TRAINERS, EventScript_ReleaseEnd
	setmetatile 2, 70, 0x2D7, 1
	end

Route2_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_PIDGEY
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route2_MapScript_PidgeyMasterMovementType
	setvar TRAINER, MASTER_PARASECT
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route2_MapScript_ParasectMasterMovementType
	end

Route2_MapScript_PidgeyMasterMovementType::
	setobjectmovementtype LOCALID_PIDGEY_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route2_MapScript_ParasectMasterMovementType::
	setobjectmovementtype LOCALID_PARASECT_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route2_EventScript_RouteSign::
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end

Route2_EventScript_DiglettsCaveSign::
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
	end
