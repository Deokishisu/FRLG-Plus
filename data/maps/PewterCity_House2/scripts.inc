.set LOCALID_KABUTOPS_MASTER, 3
.set TRAINER, VAR_0x8009

PewterCity_House2_MapScripts:: @ 816A7DC
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_House2_MapScript_SetMasterTrainerMovementTypes
	.byte 0

PewterCity_House2_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_KABUTOPS
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq PewterCity_House2_MapScript_KabutopsMasterMovementType
	end

PewterCity_House2_MapScript_KabutopsMasterMovementType::
	setobjectmovementtype LOCALID_KABUTOPS_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

PewterCity_House2_EventScript_OldMan:: @ 816A7DD
	msgbox PewterCity_House2_Text_MonsLearnTechniquesAsTheyGrow, MSGBOX_NPC
	end

PewterCity_House2_EventScript_LittleBoy:: @ 816A7E6
	msgbox PewterCity_House2_Text_MonsEasierCatchIfStatused, MSGBOX_NPC
	end
