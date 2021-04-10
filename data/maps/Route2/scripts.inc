.set LOCALID_PIDGEY_MASTER, 8
.set LOCALID_PARASECT_MASTER, 9
.set TRAINER, VAR_0x8009

Route2_MapScripts:: @ 8167F64
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
	compare VAR_RESULT, FALSE
	call_if_eq Route2_MapScript_PidgeyMasterMovementType
	setvar TRAINER, MASTER_PARASECT
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route2_MapScript_ParasectMasterMovementType
	end

Route2_MapScript_PidgeyMasterMovementType::
	setobjectmovementtype LOCALID_PIDGEY_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route2_MapScript_ParasectMasterMovementType::
	setobjectmovementtype LOCALID_PARASECT_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route2_EventScript_RouteSign:: @ 8167F65
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end

Route2_EventScript_DiglettsCaveSign:: @ 8167F6E
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
	end
