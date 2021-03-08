.equ LOCALID_RIVAL, 3

FourIsland_Base_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_Base_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FourIsland_Base_OnFrame
	.byte 0

FourIsland_Base_OnTransition:: @ 8167CB9
	compare VAR_MAP_SCENE_FOUR_ISLAND, 0
	call_if_eq FourIsland_Base_EventScript_ShowRival
	end

FourIsland_Base_EventScript_ShowRival:: @ 8167CCD
	clearflag FLAG_HIDE_FOUR_ISLAND_RIVAL
	return

FourIsland_Base_OnFrame:: @ 8167CE2
	map_script_2 VAR_MAP_SCENE_FOUR_ISLAND, 0, FourIsland_Base_EventScript_RivalScene
	.2byte 0

FourIsland_Base_EventScript_RivalScene:: @ 8167CEC
	lockall
	textcolor 0
	applymovement LOCALID_RIVAL, Movement_WalkInPlaceFastestDown
	waitmovement 0
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_RIVAL, Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Movement_Delay48
	waitmovement 0
	delay 25
	applymovement LOCALID_RIVAL, FourIsland_Base_Movement_RivalApproach
	waitmovement 0
	msgbox FourIsland_Text_RivalAlreadyGotEggBeSmellingYa
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FourIsland_Base_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL, FourIsland_Base_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	playse SE_EXIT
	delay 35
	removeobject LOCALID_RIVAL
	setvar VAR_MAP_SCENE_FOUR_ISLAND, 1
	releaseall
	end

FourIsland_Base_Movement_RivalApproach:: @ 8167D49
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

FourIsland_Base_Movement_RivalExit:: @ 8167D4E
	delay_16
	delay_4
	walk_down
	step_end

FourIsland_Base_Movement_PlayerWatchRivalExit:: @ 8167D52
	walk_left
	walk_in_place_fastest_right
	step_end

FourIsland_Base_EventScript_CableCarStationSign::
	msgbox FourIsland_Base_Text_CableCarStationSign, MSGBOX_SIGN
	end

FourIsland_Base_Text_CableCarStationSign::
	.string "FOUR ISLAND CABLE CAR\n"
	.string "Express trips up the mountain!$"