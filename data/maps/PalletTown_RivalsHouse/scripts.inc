.equ LOCALID_DAISY,    1
.equ LOCALID_TOWN_MAP, 2

.equ RECEIVED_TOWN_MAP, VAR_TEMP_1

PalletTown_RivalsHouse_MapScripts:: @ 8168D27
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PalletTown_RivalsHouse_EventScript_SetStarterGfx
	.byte 0

PalletTown_RivalsHouse_OnTransition:: @ 8168D2D
	compare VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	call_if_lt PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	compare VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	call_if_ge PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
	goto_if_unset FLAG_GOT_DAISY_STARTER, PalletTown_RivalsHouse_EventScript_CheckRemoveStarter
	setflag FLAG_TEMP_1
	end

PalletTown_RivalsHouse_EventScript_CheckRemoveStarter::
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, PalletTown_RivalsHouse_EventScript_PositionForStarterGiveaway
	goto_if_set FLAG_BADGE01_GET, EventScript_ReleaseEnd
	setflag FLAG_TEMP_1
	end

PalletTown_RivalsHouse_EventScript_PositionForStarterGiveaway::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_DAISY, 8, 5
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm 3, 8, 4
	end

PalletTown_RivalsHouse_EventScript_SetStarterGfx::
	compare VAR_STARTER_MON, 0
	call_if_eq PalletTown_RivalsHouse_EventScript_SetSquirtleGfx
	compare VAR_STARTER_MON, 1
	call_if_eq PalletTown_RivalsHouse_EventScript_SetCharmanderGfx
	compare VAR_STARTER_MON, 2
	call_if_ge PalletTown_RivalsHouse_EventScript_SetBulbasaurGfx
	return

PalletTown_RivalsHouse_EventScript_SetSquirtleGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SQUIRTLE
	return

PalletTown_RivalsHouse_EventScript_SetCharmanderGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CHARMANDER
	return

PalletTown_RivalsHouse_EventScript_SetBulbasaurGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BULBASAUR
	return

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable:: @ 8168D44
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap:: @ 8168D50
	setvar RECEIVED_TOWN_MAP, TRUE
	return

PalletTown_RivalsHouse_EventScript_Starter::
	lock
	faceplayer
	compare VAR_STARTER_MON, 0
	goto_if_eq PalletTown_RivalsHouse_EventScript_Squirtle
	compare VAR_STARTER_MON, 1
	goto_if_eq PalletTown_RivalsHouse_EventScript_Charmander
	compare VAR_STARTER_MON, 2
	goto_if_ge PalletTown_RivalsHouse_EventScript_Bulbasaur
	end

PalletTown_RivalsHouse_EventScript_Squirtle::
	waitse
	playmoncry SPECIES_SQUIRTLE, 0
	msgbox PalletTown_RivalsHouse_Text_Squirtle
	waitmoncry
	release
	end

PalletTown_RivalsHouse_Text_Squirtle:
	.string "SQUIRTLE: Squirtle squirt!$"

PalletTown_RivalsHouse_EventScript_Charmander::
	waitse
	playmoncry SPECIES_CHARMANDER, 0
	msgbox PalletTown_RivalsHouse_Text_Charmander
	waitmoncry
	release
	end

PalletTown_RivalsHouse_Text_Charmander:
	.string "CHARMANDER: Char char!$"

PalletTown_RivalsHouse_EventScript_Bulbasaur::
	waitse
	playmoncry SPECIES_BULBASAUR, 0
	msgbox PalletTown_RivalsHouse_Text_Bulbasaur
	waitmoncry
	release
	end

PalletTown_RivalsHouse_Text_Bulbasaur:
	.string "BULBASAUR: Bubba! Zoar!$"

PalletTown_RivalsHouse_EventScript_Daisy:: @ 8168D56
	lock
	faceplayer
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, PalletTown_RivalsHouse_EventScript_GiveFinalStarter
PalletTown_RivalsHouse_EventScript_DaisyRegular::
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	compare RECEIVED_TOWN_MAP, TRUE
	goto_if_eq PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	compare VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	goto_if_eq PalletTown_RivalsHouse_EventScript_ExplainTownMap
	compare VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveTownMap
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
	goto_if_ge PalletTown_RivalsHouse_EventScript_HeardBattledRival
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
	closemessage
	applymovement LOCALID_DAISY, Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_RivalsHouse_EventScript_HeardBattledRival:: @ 8168DAF
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
	release
	end

PalletTown_RivalsHouse_EventScript_GroomMon:: @ 8168DB9
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	compare VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500
	goto_if_lt PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, GetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_RS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
	release
	end

PalletTown_RivalsHouse_EventScript_CantGroomEgg:: @ 8168E32
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming:: @ 8168E3C
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_EventScript_RateMonFriendship:: @ 8168E46
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest:: @ 8168EA6
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLower:: @ 8168EB0
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLow:: @ 8168EBA
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipMid:: @ 8168EC4
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh:: @ 8168ECE
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher:: @ 8168ED8
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest:: @ 8168EE2
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
	release
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest:: @ 8168EEC
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
	release
	end

PalletTown_RivalsHouse_EventScript_GiveTownMap:: @ 8168EF6
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
	closemessage
	checkitemspace ITEM_TOWN_MAP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
	applymovement LOCALID_DAISY, Movement_WalkInPlaceFastestRight
	waitmovement 0
	removeobject LOCALID_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	delay 15
	applymovement LOCALID_DAISY, Movement_FacePlayer
	waitmovement 0
	delay 12
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
	release
	end

PalletTown_RivalsHouse_EventScript_NoRoomForTownMap:: @ 8168F4F
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
	release
	end

PalletTown_RivalsHouse_EventScript_ExplainTownMap:: @ 8168F59
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
	release
	end

PalletTown_RivalsHouse_EventScript_TownMap:: @ 8168F63
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
	end

PalletTown_RivalsHouse_EventScript_Bookshelf:: @ 8168F6C
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_Picture:: @ 8168F75
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter::
	goto_if_set FLAG_GOT_DAISY_STARTER, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_2
PalletTown_RivalsHouse_EventScript_GiveFinalStarter_1:
	switch VAR_STARTER_MON
	case 0, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_6
	case 1, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_7
	case 2, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_8
PalletTown_RivalsHouse_EventScript_GiveFinalStarter_4:
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveFinalStarter_10
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveFinalStarter_13
	textcolor 3
	waitse
	playmoncry VAR_TEMP_2, 0
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_6
	waitmoncry
	release
	turnobject 3, DIR_SOUTH
	applymovement LOCALID_DAISY, PalletTown_RivalsHouse_Movement_FaceUp
	waitmovement 0
	removeobject 3
	delay 16
	faceplayer
	givemon VAR_TEMP_2, 5, ITEM_NONE
	playfanfare MUS_LEVEL_UP
	message PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_7
	waitmessage
	waitfanfare
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveFinalStarter_16
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveFinalStarter_16
PalletTown_RivalsHouse_EventScript_GiveFinalStarter_15:
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_DAISY_STARTER
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_8
	release
	end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_2:
	goto PalletTown_RivalsHouse_EventScript_DaisyRegular
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_1

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_6:
	getspeciesname 0, SPECIES_SQUIRTLE
	getstring 1, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_0
	setvar VAR_TEMP_2, SPECIES_SQUIRTLE
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_4

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_7:
	getspeciesname 0, SPECIES_CHARMANDER
	getstring 1, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_1
	setvar VAR_TEMP_2, SPECIES_CHARMANDER
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_4

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_8:
	getspeciesname 0, SPECIES_BULBASAUR
	getstring 1, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_2
	setvar VAR_TEMP_2, SPECIES_BULBASAUR
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_4

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_10:
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_4
	release
	end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_13:
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_5
	release
	end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_16:
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_15


PalletTown_RivalsHouse_Movement_FaceUp:
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_up
	step_end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_0:
	.string "SQUIRTLE: Squirt! Squirtle!$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_1:
	.string "CHARMANDER: Charmander! Char!$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_2:
	.string "BULBASAUR: Zoar! Bubba!$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_3:
	.string "DAISY: Grandpa gave me this\n{STR_VAR_1} to look after, but…\p{STR_VAR_1}'s gotten terribly bored \ncooped up here at home.\p{PLAYER}, I think it would be much\nhappier traveling with you.\pWill you please take {STR_VAR_1}\nwith you on your adventures?$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_4:
	.string "I understand, though {STR_VAR_1}\nlooks disappointed.\pPlease come back if you change\nyour mind.$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_5:
	.string "Oh, you have no room to take\n{STR_VAR_1} with you.\pWe'll wait here until you've\nmade some space.$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_6:
	.string "{STR_VAR_2}$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_7:
	.string "{PLAYER} received a {STR_VAR_1}\nfrom DAISY!$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_8:
	.string "DAISY: Thank you, {PLAYER}!\pTake good care of\n{STR_VAR_1}!$"
