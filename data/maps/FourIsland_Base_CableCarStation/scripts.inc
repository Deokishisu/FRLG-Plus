.set LOCALID_ATTENDANT, 1

FourIsland_Base_CableCarStation_MapScripts:: @ 822AABE
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_Base_CableCarStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FourIsland_Base_CableCarStation_OnFrame
	.byte 0

FourIsland_Base_CableCarStation_OnTransition: @ 822AAC9
	compare VAR_CABLE_CAR_STATION_STATE, 2
	call_if_eq FourIsland_Base_CableCarStation_EventScript_MoveAttendantAside
	end

FourIsland_Base_CableCarStation_EventScript_MoveAttendantAside:: @ 822AADD
	setobjectxyperm LOCALID_ATTENDANT, 7, 4
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_LEFT
	return

FourIsland_Base_CableCarStation_OnFrame: @ 822AAE9
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 2, FourIsland_Base_CableCarStation_EventScript_ExitCableCar
	.2byte 0

FourIsland_Base_CableCarStation_EventScript_ExitCableCar:: @ 822AAF3
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FourIsland_Base_CableCarStation_Movement_ExitCableCar
	applymovement LOCALID_ATTENDANT, FourIsland_Base_CableCarStation_Movement_FollowPlayerOutFromCableCar
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm LOCALID_ATTENDANT, 6, 7
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

FourIsland_Base_CableCarStation_EventScript_Attendant:: @ 822AB17
	lock
	faceplayer
	msgbox FourIsland_Base_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FourIsland_Base_CableCarStation_EventScript_RideCableCar
	compare VAR_RESULT, NO
	goto_if_eq FourIsland_Base_CableCarStation_EventScript_DeclineRide
	end

FourIsland_Base_CableCarStation_EventScript_RideCableCar:: @ 822AB38
	msgbox FourIsland_Base_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, FourIsland_Base_CableCarStation_Movement_LeadPlayerToCableCar
	applymovement OBJ_EVENT_ID_PLAYER, FourIsland_Base_CableCarStation_Movement_BoardCableCar
	waitmovement 0
	setvar VAR_0x8004, FALSE  @ Going up
	setvar VAR_CABLE_CAR_STATION_STATE, 1
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	callnative CableCarWarp
	callnative CableCar
	waitstate
	release
	end

FourIsland_Base_CableCarStation_EventScript_DeclineRide:: @ 822AB67
	msgbox FourIsland_Base_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
	release
	end

FourIsland_Base_CableCarStation_Movement_LeadPlayerToCableCar: @ 822AB71
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_left
	step_end

FourIsland_Base_CableCarStation_Movement_FollowPlayerOutFromCableCar: @ 822AB76
	delay_16
	walk_left
	walk_down
	walk_down
	step_end

FourIsland_Base_CableCarStation_Movement_BoardCableCar: @ 822AB7B
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

FourIsland_Base_CableCarStation_Movement_ExitCableCar: @ 822AB80
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

FourIsland_Base_CableCarStation_Text_CableCarReadyGetOn: @ 822AB85
	.string "The CABLE CAR is ready to go up.\n"
	.string "Would you like to be on it?$"

FourIsland_Base_CableCarStation_Text_StepThisWay: @ 822ABC2
	.string "Please step this way.$"

FourIsland_Base_CableCarStation_Text_RideAnotherTime: @ 822ABD8
	.string "Please ride with us another time.$"

