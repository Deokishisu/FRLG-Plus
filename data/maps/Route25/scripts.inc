.set LOCALID_STARMIE_MASTER, 14
.set TRAINER, VAR_0x8009

Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route25_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_STARMIE
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route25_MapScript_StarmieMasterMovementType
	end

Route25_MapScript_StarmieMasterMovementType::
	setobjectmovementtype LOCALID_STARMIE_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_EventScript_Man::
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end
