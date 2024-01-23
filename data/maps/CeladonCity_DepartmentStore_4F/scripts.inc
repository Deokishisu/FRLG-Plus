.set LOCALID_FLAREON_MASTER, 4
.set TRAINER, VAR_0x8009

CeladonCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_4F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

CeladonCity_DepartmentStore_4F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_FLAREON
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_4F_MapScript_FlareonMasterMovementType
	end

CeladonCity_DepartmentStore_4F_MapScript_FlareonMasterMovementType::
	setobjectmovementtype LOCALID_FLAREON_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

CeladonCity_DepartmentStore_4F_EventScript_Man::
	msgbox CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_4F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_4F_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_4F_Items::
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_NONE
	release
	end
