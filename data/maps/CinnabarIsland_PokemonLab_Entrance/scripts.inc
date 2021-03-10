CinnabarIsland_PokemonLab_Entrance_MapScripts:: @ 816E273
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonLab_Entrance_OnTransition
	.byte 0

CinnabarIsland_PokemonLab_Entrance_OnTransition:: @ 816E279
	compare VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	call_if_eq CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil:: @ 816E285
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2
	return

CinnabarIsland_PokemonLab_Entrance_EventScript_Scientist:: @ 816E28B
	callnative CheckPlayerTrappedOnCinnabar
	compare VAR_RESULT, 0
	goto_if_ne CinnabarIsland_PokemonLab_Entrance_EventScript_Trapped
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_Trapped::
	lock
	faceplayer
	copyvar VAR_0x8005, VAR_RESULT
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_Trapped, MSGBOX_DEFAULT
	givemon SPECIES_TENTACOOL, 15, ITEM_NONE
	copyvar VAR_0x8007, VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq CinnabarIsland_PokemonLab_Entrance_EventScript_GetTentacoolParty
	compare VAR_RESULT, 1
	goto_if_eq CinnabarIsland_PokemonLab_Entrance_EventScript_GetTentacoolPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_GetTentacoolParty::
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message CinnabarIsland_PokemonLab_Entrance_Text_ObtainedATentacool
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_TENTACOOL
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq CinnabarIsland_PokemonLab_Entrance_EventScript_NicknameTentacoolParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CinnabarIsland_PokemonLab_Entrance_EventScript_CheckHaveHM03
CinnabarIsland_PokemonLab_Entrance_EventScript_NicknameTentacoolParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto CinnabarIsland_PokemonLab_Entrance_EventScript_CheckHaveHM03
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_GetTentacoolPC:: @ 816C4DA
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message CinnabarIsland_PokemonLab_Entrance_Text_ObtainedATentacool
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_TENTACOOL
	setvar VAR_TEMP_1, SPECIES_TENTACOOL
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq CinnabarIsland_PokemonLab_Entrance_EventScript_NicknameTentacoolPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	call_if_eq CinnabarIsland_PokemonLab_Entrance_EventScript_TransferTentacoolToPC
CinnabarIsland_PokemonLab_Entrance_EventScript_NicknameTentacoolPC::
	call EventScript_NameReceivedBoxMon
	call EventScript_TransferredToPC
	goto CinnabarIsland_PokemonLab_Entrance_EventScript_CheckHaveHM03
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_CheckHaveHM03::
	compare VAR_0x8005, 1
	goto_if_ne CinnabarIsland_PokemonLab_Entrance_EventScript_TeachSurf
	release
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_TeachSurf::
	callnative TeachTrappedTentacoolSurf
	release
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_TransferTentacoolToPC::
	call EventScript_TransferredToPC
	goto CinnabarIsland_PokemonLab_Entrance_EventScript_CheckHaveHM03
	end

CinnabarIsland_PokemonLab_Entrance_Text_Trapped::
	.string "Huh? Do you happen to…\n"
	.string "not have a POKéMON that can SURF?\p"
	.string "That must be hard on you.\n"
	.string "…\p"
	.string "Don't worry about it!\n"
	.string "I'll give you a TENTACOOL!\p"
	.string "I just caught a little too many.\n"
	.string "I was going to release it,\l"
	.string "so take it. Go ahead!$"

CinnabarIsland_PokemonLab_Entrance_Text_ObtainedATentacool::
	.string "{PLAYER} received\n"
	.string "the TENTACOOL!$"

CinnabarIsland_PokemonLab_Entrance_EventScript_DrFujiPhoto:: @ 816E294
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_MeetingRoomSign:: @ 816E29D
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_RAndDRoomSign:: @ 816E2A6
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_TestingRoomSign:: @ 816E2AF
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign, MSGBOX_SIGN
	end
