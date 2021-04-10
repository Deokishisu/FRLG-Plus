.set LOCALID_SANDSHREW_MASTER, 15
.set LOCALID_METAPOD_MASTER, 14
.set TRAINER, VAR_0x8009

Route11_MapScripts:: @ 8167FF6
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route11_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_SANDSHREW
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route11_MapScript_SandshrewMasterMovementType
	setvar TRAINER, MASTER_METAPOD
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route11_MapScript_MetapodMasterMovementType
	end

Route11_MapScript_SandshrewMasterMovementType::
	setobjectmovementtype LOCALID_SANDSHREW_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route11_MapScript_MetapodMasterMovementType::
	setobjectmovementtype LOCALID_METAPOD_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route11_EventScript_DiglettsCaveSign:: @ 8167FF7
	msgbox Route11_Text_DiglettsCave, MSGBOX_SIGN
	end
