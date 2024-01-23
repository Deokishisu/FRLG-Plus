.set LOCALID_NIDORAN_F_MASTER, 10
.set TRAINER, VAR_0x8009

Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route3_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_NIDORAN_F
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route3_MapScript_NidoranFMasterMovementType
	end

Route3_MapScript_NidoranFMasterMovementType::
	setobjectmovementtype LOCALID_NIDORAN_F_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route3_EventScript_Youngster::
	msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
	end

Route3_EventScript_RouteSign::
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end
