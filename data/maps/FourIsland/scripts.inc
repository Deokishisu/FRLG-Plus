.equ LOCALID_DAYCARE_MAN, 1

FourIsland_MapScripts:: @ 8167CAE
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FourIsland_OnFrame
	.byte 0

FourIsland_OnTransition:: @ 8167CB9
	setworldmapflag FLAG_WORLD_MAP_FOUR_ISLAND
	call FourIsland_EventScript_TrySetDayCareManPos
	end

FourIsland_EventScript_TrySetDayCareManPos:: @ 8167CD1
	goto_if_unset FLAG_GOT_RIVAL_STARTER_EGG, FourIsland_EventScript_SetDayCareManPos
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, FourIsland_EventScript_EndSetDayCareManPos
	setobjectxyperm LOCALID_DAYCARE_MAN, 16, 14
FourIsland_EventScript_EndSetDayCareManPos:: @ 8167CE1
	return

FourIsland_EventScript_SetDayCareManPos::
	setobjectxyperm LOCALID_DAYCARE_MAN, 16, 14
	return

FourIsland_OnFrame:: @ 8167CE2
	map_script_2 VAR_DAYCARE_MAN_TRIGGERS, 0, FourIsland_EventScript_RepositionDaycareMan
	.2byte 0

FourIsland_EventScript_DaycareMan:: @ 8167D55
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_unset FLAG_GOT_RIVAL_STARTER_EGG, FourIsland_EventScript_StarterEggDaycareMan
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	compare VAR_RESULT, DAYCARE_EGG_WAITING
	goto_if_eq FourIsland_EventScript_DaycareEggWaiting
	compare VAR_RESULT, DAYCARE_ONE_MON
	goto_if_eq FourIsland_EventScript_CheckOnOneMon
	compare VAR_RESULT, DAYCARE_TWO_MONS
	goto_if_eq FourIsland_EventScript_CheckOnTwoMons
	msgbox DayCare_Text_ImDaycareManSpeakToMyWife
	release
	end

FourIsland_EventScript_DaycareEggWaiting:: @ 8167D9B
	msgbox DayCare_Text_DoYouWantEgg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FourIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FourIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IllKeepIt
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	setvar VAR_DAYCARE_MAN_TRIGGERS, 0
	release
	turnobject LOCALID_DAYCARE_MAN DIR_SOUTH
	applymovement LOCALID_DAYCARE_MAN FourIsland_Movement_DaycareManReturnToSpot
	waitmovement 0
	end

FourIsland_Movement_DaycareManReturnToSpot::
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end	

FourIsland_EventScript_DaycareAcceptEgg:: @ 8167DD1
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne FourIsland_EventScript_DaycareReceivedEgg
	msgbox DayCare_Text_YouHaveNoRoomForIt
	release
	end

FourIsland_EventScript_DaycareReceivedEgg:: @ 8167DEB
	textcolor 3
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
	turnobject LOCALID_DAYCARE_MAN DIR_SOUTH
	applymovement LOCALID_DAYCARE_MAN FourIsland_Movement_DaycareManReturnToSpot
	waitmovement 0
	end

FourIsland_EventScript_CheckOnOneMon:: @ 8167E0C
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonIsDoingFine
	release
	end

FourIsland_EventScript_CheckOnTwoMons:: @ 8167E19
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonsAreDoingFine
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	release
	end

FourIsland_EventScript_OldWoman:: @ 8167E2E
	lock
	faceplayer
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, FourIsland_EventScript_OldWomanLoreleiLeft
	msgbox FourIsland_Text_LoreleiHasReturned
	release
	end

FourIsland_EventScript_OldWomanLoreleiLeft:: @ 8167E43
	famechecker FAMECHECKER_LORELEI, 5
	msgbox FourIsland_Text_LoreleiMetLaprasAsChild
	release
	end

FourIsland_EventScript_LittleGirl:: @ 8167E5A
	lock
	faceplayer
	famechecker FAMECHECKER_LORELEI, 4
	msgbox FourIsland_Text_LoreleiHasLotsOfStuffedDolls
	release
	end

FourIsland_EventScript_FatMan:: @ 8167E73
	msgbox FourIsland_Text_MadeSlushieUsingIcefallCaveIce, MSGBOX_NPC
	end

FourIsland_EventScript_IslandSign:: @ 8167E7C
	msgbox FourIsland_Text_IslandSign, MSGBOX_SIGN
	end

FourIsland_EventScript_LoreleisHouseSign:: @ 8167E85
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
	turnobject LOCALID_DAYCARE_MAN DIR_SOUTH
	applymovement LOCALID_DAYCARE_MAN FourIsland_Movement_DaycareManReturnToSpot
	waitmovement 0
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
	goto_if_unset FLAG_GOT_RIVAL_STARTER_EGG, FourIsland_EventScript_RepositionDaycareMan_4
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, FourIsland_EventScript_RepositionDaycareMan_2
	getplayerxy VAR_TEMP_1, VAR_RESULT
	compare VAR_TEMP_1, 9
	goto_if_ge FourIsland_EventScript_RepositionDaycareMan_7
FourIsland_EventScript_RepositionDaycareMan_4:
	callnative MoveDaycareMan
	return

FourIsland_EventScript_RepositionDaycareMan_2:
	setobjectxyperm LOCALID_DAYCARE_MAN, 16, 13
	setvar VAR_DAYCARE_MAN_TRIGGERS, 1
	release
	end

FourIsland_EventScript_RepositionDaycareMan_5:
	compare VAR_TEMP_1, 16
	goto_if_eq FourIsland_EventScript_RepositionDaycareMan_15
FourIsland_EventScript_RepositionDaycareMan_13:
	applymovement LOCALID_DAYCARE_MAN, FourIsland_Movement_DaycareManWalkDown
	waitmovement 0
	callnative MoveDaycareMan
	setvar VAR_DAYCARE_MAN_TRIGGERS, 1
	release
	end

FourIsland_EventScript_RepositionDaycareMan_6:
	compare VAR_RESULT, 12
	goto_if_ge FourIsland_EventScript_RepositionDaycareMan_10
	goto FourIsland_EventScript_RepositionDaycareMan_4

FourIsland_EventScript_RepositionDaycareMan_7:
	compare VAR_TEMP_1, 24
	goto_if_le FourIsland_EventScript_RepositionDaycareMan_6
	goto FourIsland_EventScript_RepositionDaycareMan_4

FourIsland_EventScript_RepositionDaycareMan_10:
	compare VAR_RESULT, 20
	goto_if_le FourIsland_EventScript_RepositionDaycareMan_5
	goto FourIsland_EventScript_RepositionDaycareMan_4

FourIsland_EventScript_RepositionDaycareMan_14:
	applymovement OBJ_EVENT_ID_PLAYER, FourIsland_Base_Movement_PlayerWatchRivalExit
	applymovement LOCALID_DAYCARE_MAN, FourIsland_Movement_DaycareManWalkDown
	callnative MoveDaycareMan
	waitmovement 0
	setvar VAR_DAYCARE_MAN_TRIGGERS, 1
	release
	end

FourIsland_EventScript_RepositionDaycareMan_15:
	compare VAR_RESULT, 14
	goto_if_eq FourIsland_EventScript_RepositionDaycareMan_14
	goto FourIsland_EventScript_RepositionDaycareMan_13

FourIsland_Movement_DaycareManWalkDown:
	walk_down
	step_end
