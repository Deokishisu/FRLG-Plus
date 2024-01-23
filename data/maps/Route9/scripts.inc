.set LOCALID_NINETALES_MASTER, 13
.set TRAINER, VAR_0x8009

Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route9_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_NINETALES
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route9_MapScript_NinetalesMasterMovementType
	end

Route9_MapScript_NinetalesMasterMovementType::
	setobjectmovementtype LOCALID_NINETALES_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route9_EventScript_RouteSign::
	msgbox Route9_Text_RouteSign, MSGBOX_SIGN
	end
