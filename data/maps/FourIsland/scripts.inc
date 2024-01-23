.equ LOCALID_DAYCARE_MAN, 1

FourIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FourIsland_OnFrame
	.byte 0

FourIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FOUR_ISLAND
	call FourIsland_EventScript_TrySetDayCareManPos
	end

FourIsland_EventScript_TrySetDayCareManPos::
	goto_if_unset FLAG_GOT_RIVAL_STARTER_EGG, FourIsland_EventScript_SetDayCareManPos
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, FourIsland_EventScript_EndSetDayCareManPos
	setobjectmovementtype LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
FourIsland_EventScript_EndSetDayCareManPos::
	return

FourIsland_EventScript_SetDayCareManPos::
	setobjectmovementtype LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

FourIsland_OnFrame::
	map_script_2 VAR_DAYCARE_MAN_TRIGGERS, 0, FourIsland_EventScript_RepositionDaycareMan
	.2byte 0

FourIsland_EventScript_DaycareMan::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_unset FLAG_GOT_RIVAL_STARTER_EGG, FourIsland_EventScript_StarterEggDaycareMan
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, FourIsland_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, FourIsland_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, FourIsland_EventScript_CheckOnTwoMons
	msgbox DayCare_Text_ImDaycareManSpeakToMyWife
	release
	end

FourIsland_EventScript_DaycareEggWaiting::
	msgbox DayCare_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FourIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FourIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IllKeepIt
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	setvar VAR_DAYCARE_MAN_TRIGGERS, 0
	release
	setobjectmovementtype LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtypeinstant LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_FACE_DOWN
	end

FourIsland_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, FourIsland_EventScript_DaycareReceivedEgg
	msgbox DayCare_Text_YouHaveNoRoomForIt
	release
	end

FourIsland_EventScript_DaycareReceivedEgg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message DayCare_Text_ReceivedEgg
	call EventScript_RestorePrevTextColor
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox DayCare_Text_TakeGoodCareOfIt
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	setvar VAR_DAYCARE_MAN_TRIGGERS, 0
	release
	setobjectmovementtype LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtypeinstant LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_FACE_DOWN
	end

FourIsland_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonIsDoingFine
	release
	end

FourIsland_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonsAreDoingFine
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	release
	end

FourIsland_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, FourIsland_EventScript_OldWomanLoreleiLeft
	msgbox FourIsland_Text_LoreleiHasReturned
	release
	end

FourIsland_EventScript_OldWomanLoreleiLeft::
	famechecker FAMECHECKER_LORELEI, 5
	msgbox FourIsland_Text_LoreleiMetLaprasAsChild
	release
	end

FourIsland_EventScript_LittleGirl::
	lock
	faceplayer
	famechecker FAMECHECKER_LORELEI, 4
	msgbox FourIsland_Text_LoreleiHasLotsOfStuffedDolls
	release
	end

FourIsland_EventScript_FatMan::
	msgbox FourIsland_Text_MadeSlushieUsingIcefallCaveIce, MSGBOX_NPC
	end

FourIsland_EventScript_IslandSign::
	msgbox FourIsland_Text_IslandSign, MSGBOX_SIGN
	end

FourIsland_EventScript_LoreleisHouseSign::
	msgbox FourIsland_Text_LoreleisHouse, MSGBOX_SIGN
	end

FourIsland_EventScript_StarterEggDaycareMan::
	msgbox FourIsland_EventScript_StarterEggDaycareMan_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_ne FourIsland_EventScript_StarterEggDaycareMan_2
	msgbox FourIsland_EventScript_StarterEggDaycareMan_Text_1
	release
	end

FourIsland_EventScript_StarterEggDaycareMan_2:
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq FourIsland_EventScript_StarterEggDaycareMan_5
	textcolor 3
	message DayCare_Text_ReceivedEgg
	call EventScript_RestorePrevTextColor
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox DayCare_Text_TakeGoodCareOfIt
	callnative GiveRivalStarterEgg
FourIsland_EventScript_StarterEggDaycareMan_7:
	setflag FLAG_GOT_RIVAL_STARTER_EGG
	setvar VAR_DAYCARE_MAN_TRIGGERS, 0
	release
	setobjectmovementtype LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtypeinstant LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_FACE_DOWN
	end

FourIsland_EventScript_StarterEggDaycareMan_5:
	msgbox DayCare_Text_YouHaveNoRoomForIt
	release
	end

FourIsland_EventScript_StarterEggDaycareMan_Text_0:
	.string "Ah, hello!\nI'm the DAY-CARE MAN.\pI help take care of the precious\nPOKéMON of TRAINERS.\pWe were raising a TRAINER's POKéMON\nand were surprised to find an EGG!\pHe didn't want it, but you look\nlike a TRAINER.\pWould you like to take care\nof this EGG instead?$"

FourIsland_EventScript_StarterEggDaycareMan_Text_1:
	.string "I guess I'll keep this EGG until a\nTRAINER comes along who wants it.$"

FourIsland_EventScript_RepositionDaycareMan::
	goto_if_unset FLAG_GOT_RIVAL_STARTER_EGG, FourIsland_EventScript_RepositionDaycareMan_2
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, FourIsland_EventScript_RepositionDaycareMan_3
FourIsland_EventScript_RepositionDaycareMan_2:
	setobjectmovementtype LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	setobjectmovementtypeinstant LOCALID_DAYCARE_MAN, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
FourIsland_EventScript_RepositionDaycareMan_3:
	setvar VAR_DAYCARE_MAN_TRIGGERS, 1
	end
	

