.set LOCALID_SEAKING_MASTER, 12
.set LOCALID_KAKUNA_MASTER, 13
.set TRAINER, VAR_0x8009

Route13_MapScripts:: @ 81680B5
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route13_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_SEAKING
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route13_MapScript_SeakingMasterMovementType
	setvar TRAINER, MASTER_KAKUNA
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route13_MapScript_KakunaMasterMovementType
	end

Route13_MapScript_SeakingMasterMovementType::
	setobjectmovementtype LOCALID_SEAKING_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route13_MapScript_KakunaMasterMovementType::
	setobjectmovementtype LOCALID_KAKUNA_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route13_EventScript_TrainerTips1:: @ 81680B6
	msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
	end

Route13_EventScript_TrainerTips2:: @ 81680BF
	msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign:: @ 81680C8
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end
