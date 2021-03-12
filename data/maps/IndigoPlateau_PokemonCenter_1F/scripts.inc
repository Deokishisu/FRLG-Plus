.set LOCALID_DOOR_GUARD, 4

IndigoPlateau_PokemonCenter_1F_MapScripts:: @ 816EA5A
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PokemonCenter_1F_OnLoad
	//map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition:: @ 816EA65
	setrespawn SPAWN_INDIGO_PLATEAU
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	compare VAR_RESULT, TRUE
	call_if_eq IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor:: @ 816EA79
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, EventScript_Return
	setobjectxyperm LOCALID_DOOR_GUARD, 4, 2
	return

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard:: @ 816EA8A
	lock
	faceplayer
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	compare VAR_RESULT, TRUE
	goto_if_eq IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete:: @ 816EAA6
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete:: @ 816EAB9
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy:: @ 816EAC3
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk:: @ 816EACC
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Items:: @ 816EAF4
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse:: @ 816EB06
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Abra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ABRA, 0
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Abra
	waitmoncry
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_Abra::
	.string "ABRA: Aabra…$"


IndigoPlateau_PokemonCenter_1F_EventScript_TeleportGuy::
	lock
	faceplayer
	msgbox IndigoPlateau_PokemonCenter_1F_Text_TeleportGuyAsks, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq IndigoPlateau_PokemonCenter_1F_EventScript_TeleportGuyDeclined
	msgbox IndigoPlateau_PokemonCenter_1F_Text_TeleportGuyYes, MSGBOX_DEFAULT
	closemessage
	delay 30
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	warpteleport MAP_PALLET_TOWN, 255, 6, 8
	waitstate
	end

IndigoPlateau_PokemonCenter_1F_EventScript_TeleportGuyDeclined::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_TeleportGuyDeclined, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_Text_TeleportGuyAsks::
	.string "Ah! You're challenging the\n"
	.string "ELITE FOUR?\p"
	.string "Are you sure you're ready?\n"
	.string "If you need to train some more,\l"
	.string "my ABRA can help you.\p"
	.string "It can TELEPORT you home.\n"
	.string "Would you like to go home now?$"

IndigoPlateau_PokemonCenter_1F_Text_TeleportGuyYes::
	.string "Okay, okay.\n"
	.string "Picture your house in your mind…$"

IndigoPlateau_PokemonCenter_1F_Text_TeleportGuyDeclined::
	.string "Okay, okay.\n"
	.string "The best of luck to you!$"
