.set LOCALID_STARMIE_MASTER, 14
.set TRAINER, VAR_0x8009

Route25_MapScripts:: @ 8168745
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route25_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_STARMIE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route25_MapScript_StarmieMasterMovementType
	end

Route25_MapScript_StarmieMasterMovementType::
	setobjectmovementtype LOCALID_STARMIE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route25_EventScript_SeaCottageSign:: @ 8168746
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_EventScript_Man:: @ 816874F
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end
