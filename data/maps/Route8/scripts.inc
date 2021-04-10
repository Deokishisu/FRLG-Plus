.set LOCALID_BEEDRILL_MASTER, 16
.set TRAINER, VAR_0x8009

Route8_MapScripts:: @ 8167FC5
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route8_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_BEEDRILL
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route8_MapScript_BeedrillMasterMovementType
	end

Route8_MapScript_BeedrillMasterMovementType::
	setobjectmovementtype LOCALID_BEEDRILL_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route8_EventScript_UndergroundPathSign:: @ 8167FC6
	msgbox Route8_Text_UndergroundPathSign, MSGBOX_SIGN
	end
