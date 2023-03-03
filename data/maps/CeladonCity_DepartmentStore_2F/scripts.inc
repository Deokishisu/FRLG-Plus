.set LOCALID_VAPOREON_MASTER, 5
.set TRAINER, VAR_0x8009

CeladonCity_DepartmentStore_2F_MapScripts:: @ 816BAF4
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_2F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

CeladonCity_DepartmentStore_2F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_VAPOREON
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq CeladonCity_DepartmentStore_2F_MapScript_VaporeonMasterMovementType
	end

CeladonCity_DepartmentStore_2F_MapScript_VaporeonMasterMovementType::
	setobjectmovementtype LOCALID_VAPOREON_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

CeladonCity_DepartmentStore_2F_EventScript_UnusedNPC:: @ 816BAF5
	msgbox CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_Lass:: @ 816BAFE
	msgbox CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_FloorSign:: @ 816BB07
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkItems:: @ 816BB10
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_Items:: @ 816BB38
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs:: @ 816BB4E
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_TMs
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_TMs:: @ 816BB74
	.2byte ITEM_TM05
	.2byte ITEM_TM15
	.2byte ITEM_TM28
	.2byte ITEM_TM31
	.2byte ITEM_TM43
	.2byte ITEM_TM45
	.2byte ITEM_TM10
	.2byte ITEM_TM44
	.2byte ITEM_NONE
	release
	end
