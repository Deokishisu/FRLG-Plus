.set LOCALID_GROWLITHE_MASTER, 2
.set TRAINER, VAR_0x8009

Route7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route7_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_GROWLITHE
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route7_MapScript_GrowlitheMasterMovementType
	end

Route7_MapScript_GrowlitheMasterMovementType::
	setobjectmovementtype LOCALID_GROWLITHE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route7_EventScript_UndergroundPathSign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end
