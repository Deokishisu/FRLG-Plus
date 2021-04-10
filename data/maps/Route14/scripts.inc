.set LOCALID_VILEPLUME_MASTER, 16
.set LOCALID_IVYSAUR_MASTER, 17
.set TRAINER, VAR_0x8009

Route14_MapScripts:: @ 81680D1
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route14_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_VILEPLUME
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route14_MapScript_VileplumeMasterMovementType
	setvar TRAINER, MASTER_IVYSAUR
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route14_MapScript_IvysaurMasterMovementType
	end

Route14_MapScript_VileplumeMasterMovementType::
	setobjectmovementtype LOCALID_VILEPLUME_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route14_MapScript_IvysaurMasterMovementType::
	setobjectmovementtype LOCALID_IVYSAUR_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route14_EventScript_RouteSign:: @ 81680D2
	msgbox Route14_Text_RouteSign, MSGBOX_SIGN
	end
