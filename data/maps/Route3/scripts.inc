.set LOCALID_NIDORAN_F_MASTER, 10
.set TRAINER, VAR_0x8009

Route3_MapScripts:: @ 8167F77
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route3_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_NIDORAN_F
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route3_MapScript_NidoranFMasterMovementType
	end

Route3_MapScript_NidoranFMasterMovementType::
	setobjectmovementtype LOCALID_NIDORAN_F_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route3_EventScript_Youngster:: @ 8167F78
	msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
	end

Route3_EventScript_RouteSign:: @ 8167F81
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end
