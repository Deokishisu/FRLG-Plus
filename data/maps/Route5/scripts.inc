.set LOCALID_MANKEY_MASTER, 1
.set TRAINER, VAR_0x8009

Route5_MapScripts:: @ 8167FA7
	map_script MAP_SCRIPT_ON_TRANSITION, Route5_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route5_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MANKEY
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route5_MapScript_MankeyMasterMovementType
	end

Route5_MapScript_MankeyMasterMovementType::
	setobjectmovementtype LOCALID_MANKEY_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route5_EventScript_UndergroundPathSign:: @ 8167FA8
	msgbox Route5_Text_UndergroundPathSign, MSGBOX_SIGN
	end
