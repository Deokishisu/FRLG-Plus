.set LOCALID_BULBASAUR_MASTER, 8
.set LOCALID_NIDORAN_M_MASTER, 9
.set LOCALID_EKANS_MASTER, 10
.set LOCALID_GOLDUCK_MASTER, 11
.set TRAINER, VAR_0x8009

Route4_MapScripts:: @ 8167F8A
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route4_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_BULBASAUR
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route4_MapScript_BulbasaurMasterMovementType
	setvar TRAINER, MASTER_NIDORAN_M
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route4_MapScript_NidoranMMasterMovementType
	setvar TRAINER, MASTER_EKANS
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route4_MapScript_EkansMasterMovementType
	setvar TRAINER, MASTER_GOLDUCK
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route4_MapScript_GolduckMasterMovementType
	end

Route4_MapScript_BulbasaurMasterMovementType::
	setobjectmovementtype LOCALID_BULBASAUR_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route4_MapScript_NidoranMMasterMovementType::
	setobjectmovementtype LOCALID_NIDORAN_M_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route4_MapScript_EkansMasterMovementType::
	setobjectmovementtype LOCALID_EKANS_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route4_MapScript_GolduckMasterMovementType::
	setobjectmovementtype LOCALID_GOLDUCK_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route4_EventScript_Woman:: @ 8167F8C
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_EventScript_MtMoonSign:: @ 8167F95
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign:: @ 8167F9E
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end
