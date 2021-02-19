.equ CHECK_BOXES_MOVED, 9
.equ CHECK_ANY_VISITORS, 10
.equ CREATE_VISITOR_STRING, 12

.equ TYPE, VAR_0x8003

SevenIsland_MapScripts:: @ 8167EB3
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_OnTransition
	.byte 0

SevenIsland_OnTransition:: @ 8167EB9
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND
	end

SevenIsland_EventScript_IslandSign:: @ 8167EBD
	msgbox SevenIsland_Text_IslandSign, MSGBOX_SIGN
	end

SevenIsland_EventScript_OldWoman:: @ 8167EC6
	msgbox SevenIsland_Text_IslandsMadeInSevenDays, MSGBOX_NPC
	end

SevenIsland_EventScript_Scientist:: @ 8167ECF
	msgbox SevenIsland_Text_IslandVirtuallyUntouched, MSGBOX_NPC
	end

SevenIsland_EventScript_IslandMailbox::
	setvar TYPE, CHECK_BOXES_MOVED
	callnative UseBattleHouseVar
	compare VAR_RESULT, 1
	goto_if_eq SevenIsland_EventScript_BattleHouse
	msgbox SevenIsland_Text_FadedWriting, MSGBOX_SIGN
	end

SevenIsland_EventScript_BattleHouse::
	setvar TYPE, CHECK_ANY_VISITORS
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	goto_if_eq SevenIsland_EventScript_BattleHouseNoVisitors
	switch VAR_RESULT
	case 1, SevenIsland_EventScript_Buffer1
	case 2, SevenIsland_EventScript_Buffer2
	case 3, SevenIsland_EventScript_Buffer3
	case 4, SevenIsland_EventScript_Buffer4
	case 5, SevenIsland_EventScript_Buffer5
	case 6, SevenIsland_EventScript_Buffer6
	case 7, SevenIsland_EventScript_Buffer7
	end

SevenIsland_EventScript_BattleHouseNoVisitors::
	msgbox SevenIsland_Text_BattleHouseWithNoVisitors, MSGBOX_SIGN
	end

SevenIsland_EventScript_Buffer1::
	setvar TYPE, CREATE_VISITOR_STRING
	callnative UseBattleHouseVar
	msgbox SevenIsland_Text_BattleHouseOneVisitor, MSGBOX_SIGN
	end

SevenIsland_EventScript_Buffer2::
	setvar TYPE, CREATE_VISITOR_STRING
	callnative UseBattleHouseVar
	msgbox SevenIsland_Text_BattleHouseTwoVisitors, MSGBOX_SIGN
	end

SevenIsland_EventScript_Buffer3::
	setvar TYPE, CREATE_VISITOR_STRING
	callnative UseBattleHouseVar
	msgbox SevenIsland_Text_BattleHouseThreeVisitors, MSGBOX_SIGN
	end

SevenIsland_EventScript_Buffer4::
	setvar TYPE, CREATE_VISITOR_STRING
	callnative UseBattleHouseVar
	msgbox SevenIsland_Text_BattleHouseFourVisitors, MSGBOX_SIGN
	end

SevenIsland_EventScript_Buffer5::
	setvar TYPE, CREATE_VISITOR_STRING
	callnative UseBattleHouseVar
	msgbox SevenIsland_Text_BattleHouseFiveVisitors, MSGBOX_SIGN
	end

SevenIsland_EventScript_Buffer6::
	setvar TYPE, CREATE_VISITOR_STRING
	callnative UseBattleHouseVar
	msgbox SevenIsland_Text_BattleHouseSixVisitors, MSGBOX_SIGN
	end

SevenIsland_EventScript_Buffer7::
	setvar TYPE, CREATE_VISITOR_STRING
	callnative UseBattleHouseVar
	msgbox SevenIsland_Text_BattleHouseSevenVisitors, MSGBOX_SIGN
	end
