.set LOCALID_NINETALES_MASTER, 13
.set TRAINER, VAR_0x8009

Route9_MapScripts:: @ 8167FCF
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route9_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_NINETALES
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route9_MapScript_NinetalesMasterMovementType
	end

Route9_MapScript_NinetalesMasterMovementType::
	setobjectmovementtype LOCALID_NINETALES_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route9_EventScript_RouteSign:: @ 8167FD0
	msgbox Route9_Text_RouteSign, MSGBOX_SIGN
	end
