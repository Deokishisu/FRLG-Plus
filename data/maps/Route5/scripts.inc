.set LOCALID_MANKEY_MASTER, 1
.set TRAINER, VAR_0x8009

Route5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route5_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route5_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MANKEY
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route5_MapScript_MankeyMasterMovementType
	end

Route5_MapScript_MankeyMasterMovementType::
	setobjectmovementtype LOCALID_MANKEY_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route5_EventScript_UndergroundPathSign::
	msgbox Route5_Text_UndergroundPathSign, MSGBOX_SIGN
	end
