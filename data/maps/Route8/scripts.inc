.set LOCALID_BEEDRILL_MASTER, 16
.set TRAINER, VAR_0x8009

Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route8_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_BEEDRILL
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route8_MapScript_BeedrillMasterMovementType
	end

Route8_MapScript_BeedrillMasterMovementType::
	setobjectmovementtype LOCALID_BEEDRILL_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route8_EventScript_UndergroundPathSign::
	msgbox Route8_Text_UndergroundPathSign, MSGBOX_SIGN
	end
