.set LOCALID_BULBASAUR_MASTER, 8
.set TRAINER, VAR_0x8009

Route4_MapScripts:: @ 8167F8A
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route4_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_BULBASAUR
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route4_MapScript_BulbasaurMasterMovementType
	end

Route4_MapScript_BulbasaurMasterMovementType::
	setobjectmovementtype LOCALID_BULBASAUR_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route4_EventScript_Unused:: @ 8167F8B
	end

Route4_EventScript_Woman:: @ 8167F8C
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_EventScript_MtMoonSign:: @ 8167F95
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign:: @ 8167F9E
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end
