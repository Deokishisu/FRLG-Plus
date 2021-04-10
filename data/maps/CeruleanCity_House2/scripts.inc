.set LOCALID_RATICATE_MASTER, 3
.set TRAINER, VAR_0x8009

CeruleanCity_House2_MapScripts:: @ 816A975
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_House2_MapScript_SetMasterTrainerMovementTypes
	.byte 0

CeruleanCity_House2_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_RATICATE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq CeruleanCity_House2_MapScript_RaticateMasterMovementType
	end

CeruleanCity_House2_MapScript_RaticateMasterMovementType::
	setobjectmovementtype LOCALID_RATICATE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

CeruleanCity_House2_EventScript_Hiker:: @ 816A976
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM28_FROM_ROCKET, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_EventScript_HikerGotTM28:: @ 816A98B
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_EventScript_Lass:: @ 816A995
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_WallHole:: @ 816A99E
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end
