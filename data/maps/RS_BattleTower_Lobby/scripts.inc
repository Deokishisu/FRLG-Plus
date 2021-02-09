RS_BattleTower_Lobby_MapScripts:: @ 816027E
	map_script MAP_SCRIPT_ON_RESUME, BattleTower_Lobby_MapScript1_160293
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_Lobby_MapScript2_160302
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleTower_Lobby_MapScript2_1602EE
	.byte 0

BattleTower_Lobby_MapScript1_160293:: @ 8160293
	call BattleTower_Lobby_EventScript_16029C
	end

BattleTower_Lobby_EventScript_16029C:: @ 816029C
	setvar VAR_0x8004, 10
	special SetBattleTowerProperty
	goto_if_set FLAG_TEMP_1, BattleTower_Lobby_EventScript_160662
	checkitem ITEM_EON_TICKET, 1
	compare VAR_RESULT, TRUE
	goto_if_eq BattleTower_Lobby_EventScript_HideScott
	checkitem ITEM_AURORA_TICKET, 1
	compare VAR_RESULT, TRUE
	goto_if_eq BattleTower_Lobby_EventScript_CheckShouldGiveEonTicket
	callnative GetBestBattleTowerStreakToVar0x8007
	compare VAR_0x8007, 28
	goto_if_lt BattleTower_Lobby_EventScript_HideScott
	clearflag FLAG_HIDE_AWARD_SCOTT_BATTLE_TOWER
	callnative TryInitBattleTowerAwardManObjectEvent
	return

BattleTower_Lobby_EventScript_CheckShouldGiveEonTicket::
	callnative GetBestBattleTowerStreakToVar0x8007
	compare VAR_0x8007, 56
	goto_if_lt BattleTower_Lobby_EventScript_HideScott
	clearflag FLAG_HIDE_AWARD_SCOTT_BATTLE_TOWER
	callnative TryInitBattleTowerAwardManObjectEvent
	return

BattleTower_Lobby_EventScript_HideScott::
	setflag FLAG_HIDE_AWARD_SCOTT_BATTLE_TOWER
	return

BattleTower_Lobby_MapScript2_1602EE:: @ 81602EE
	map_script_2 VAR_TEMP_1, 0, BattleTower_Lobby_EventScript_1602F8
	.2byte 0

BattleTower_Lobby_EventScript_1602F8:: @ 81602F8
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, 2
	end

BattleTower_Lobby_MapScript2_160302:: @ 8160302
	map_script_2 VAR_TEMP_0, 0, BattleTower_Lobby_EventScript_16032C
	map_script_2 VAR_TEMP_0, 1, BattleTower_Lobby_EventScript_160330
	map_script_2 VAR_TEMP_0, 2, BattleTower_Lobby_EventScript_160342
	map_script_2 VAR_TEMP_0, 3, BattleTower_Lobby_EventScript_160419
	map_script_2 VAR_TEMP_0, 4, BattleTower_Lobby_EventScript_16044B
	.2byte 0

BattleTower_Lobby_EventScript_16032C:: @ 816032C
	special BattleTowerMapScript2
	end

BattleTower_Lobby_EventScript_160330:: @ 8160330
	lock
	faceplayer
	textcolor 0x1
	clearflag FLAG_SYS_IS_LINKING
	msgbox BattleTower_Lobby_Text_19A3FD, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 5
	release
	end

BattleTower_Lobby_EventScript_160342:: @ 8160342
	lock
	faceplayer
	clearflag FLAG_SYS_IS_LINKING
	textcolor 0x1
	message BattleTower_Lobby_Text_19A487
	waitmessage
	setvar VAR_0x8004, 0
	special BattleTowerUtil
	compare VAR_RESULT, 6
	goto_if_eq BattleTower_Lobby_EventScript_16037D
	special AwardBattleTowerRibbons
	compare VAR_RESULT, 0
	goto_if_eq BattleTower_Lobby_EventScript_16037D
	message BattleTower_Lobby_Text_19A6BE
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BattleTower_Lobby_Text_19A719, MSGBOX_DEFAULT

BattleTower_Lobby_EventScript_16037D:: @ 816037D
	setvar VAR_0x8004, 8
	special BattleTowerUtil
	compare VAR_RESULT, 1
	goto_if_eq BattleTower_Lobby_EventScript_1603AD
	message BattleTower_Lobby_Text_19A589
	waitmessage
	setvar VAR_0x8004, 13
	special SetBattleTowerProperty
	special DetermineBattleTowerPrize
	setvar VAR_0x8004, 3
	special SaveBattleTowerProgress
	playse SE_SAVE
	waitse

BattleTower_Lobby_EventScript_1603AD:: @ 81603AD
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 3
	special SetBattleTowerProperty
	message BattleTower_Lobby_Text_19A4BB
	waitmessage
	special GiveBattleTowerPrize
	switch VAR_RESULT
	case 0, BattleTower_Lobby_EventScript_160408
	textcolor 0x3
	message BattleTower_Lobby_Text_19A506
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	setvar VAR_0x8004, 9
	textcolor 0x1
	special BattleTowerUtil
	compare VAR_RESULT, 49
	goto_if_ne BattleTower_Lobby_EventScript_1603F8
	msgbox BattleTower_Lobby_Text_19A617, MSGBOX_DEFAULT

BattleTower_Lobby_EventScript_1603F8:: @ 81603F8
	msgbox BattleTower_Lobby_Text_199FA9, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 5
	release
	end

BattleTower_Lobby_EventScript_160408:: @ 8160408
	msgbox BattleTower_Lobby_Text_19A520, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_0, 5
	release
	end

BattleTower_Lobby_EventScript_160419:: @ 8160419
	lock
	faceplayer
	textcolor 0x1
	clearflag FLAG_SYS_IS_LINKING
	message BattleTower_Lobby_Text_19A571
	waitmessage
	message BattleTower_Lobby_Text_19A589
	waitmessage
	setvar VAR_0x8004, 13
	special SetBattleTowerProperty
	setvar VAR_0x8004, 0
	special SaveBattleTowerProgress
	playse SE_SAVE
	waitse
	msgbox BattleTower_Lobby_Text_199FA9, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 5
	release
	end

BattleTower_Lobby_EventScript_16044B:: @ 816044B
	lock
	faceplayer
	textcolor 0x1
	message BattleTower_Lobby_Text_19A5B1
	waitmessage
	message BattleTower_Lobby_Text_19A5CE
	waitmessage
	setvar VAR_0x8004, 1
	special SaveBattleTowerProgress
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	special SetBattleTowerProperty
	setvar VAR_TEMP_0, 5
	special SavePlayerParty
	setflag FLAG_SYS_IS_LINKING
	callnative RecalculatePartyStats
	special SetBattleTowerParty
	msgbox BattleTower_Lobby_Text_19A0A8, MSGBOX_DEFAULT
	closemessage
	call BattleTower_Lobby_EventScript_160664
	warp MAP_RS_BATTLE_TOWER_ELEVATOR, 255, 2, 6
	setvar VAR_TEMP_0, 0
	waitstate

BattleTower_Lobby_EventScript_16049E:: @ 816049E
	lock
	faceplayer
	setvar VAR_0x8004, 0
	special BattleTowerUtil
	compare VAR_RESULT, 6
	goto_if_eq BattleTower_Lobby_EventScript_160342
	special SavePlayerParty
	msgbox BattleTower_Lobby_Text_199F2C, MSGBOX_DEFAULT

BattleTower_Lobby_EventScript_1604BE:: @ 81604BE
	message BattleTower_Lobby_Text_199F79
	waitmessage
	multichoice 18, 6, MULTICHOICE_CHALLENGE_INFO_EXIT, 0
	switch VAR_RESULT
	case 0, BattleTower_Lobby_EventScript_1604FA
	case 1, BattleTower_Lobby_EventScript_160600
	case 2, BattleTower_Lobby_EventScript_160652
	case 127, BattleTower_Lobby_EventScript_160652

BattleTower_Lobby_EventScript_1604FA:: @ 81604FA
	message BattleTower_Lobby_Text_19A024
	waitmessage
	multichoice 18, 6, MULTICHOICE_BATTLE_TOWER_LEVELS, 0
	switch VAR_RESULT
	case 2, BattleTower_Lobby_EventScript_160652
	case 127, BattleTower_Lobby_EventScript_160652
	special CheckPartyBattleTowerBanlist
	compare VAR_0x8004, 1
	goto_if_eq BattleTower_Lobby_EventScript_16060D
	setvar VAR_0x8004, 1
	copyvar VAR_0x8005, VAR_RESULT
	copyvar VAR_0x8006, VAR_RESULT
	special SetBattleTowerProperty
	msgbox BattleTower_Lobby_Text_19A07B, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	fadescreen FADE_TO_BLACK
	special ChooseBattleTowerPlayerParty
	waitstate
	clearflag FLAG_TEMP_1
	compare VAR_RESULT, 0
	goto_if_eq BattleTower_Lobby_EventScript_16064F
	msgbox BattleTower_Lobby_Text_199FDA, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_Lobby_EventScript_16064F
	case YES, BattleTower_Lobby_EventScript_160587
	case 127, BattleTower_Lobby_EventScript_16064F

BattleTower_Lobby_EventScript_160587:: @ 8160587
	setvar VAR_0x8004, 5
	special SetBattleTowerProperty
	setvar VAR_TEMP_0, 0
	setvar VAR_0x8004, 11
	special SetBattleTowerProperty
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 1
	special SetBattleTowerProperty
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	special SetBattleTowerProperty
	setdynamicwarp MAP_RS_BATTLE_TOWER_LOBBY, 255, 6, 6
	special LoadPlayerParty
	closemessage
	delay 2
	call EventScript_AskSaveGame
	setvar VAR_TEMP_0, 5
	//erasebox 0, 0, 15, 10
	compare VAR_RESULT, 0
	goto_if_eq BattleTower_Lobby_EventScript_160642
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	special SavePlayerParty
	setflag FLAG_SYS_IS_LINKING
	callnative RecalculatePartyStats
	special SetBattleTowerParty
	msgbox BattleTower_Lobby_Text_19A0A8, MSGBOX_DEFAULT
	closemessage
	call BattleTower_Lobby_EventScript_160664
	warp MAP_RS_BATTLE_TOWER_ELEVATOR, 255, 2, 6
	setvar VAR_TEMP_0, 0
	waitstate

BattleTower_Lobby_EventScript_160600:: @ 8160600
	msgbox BattleTower_Lobby_Text_19A0D1, MSGBOX_DEFAULT
	goto BattleTower_Lobby_EventScript_1604BE

BattleTower_Lobby_EventScript_16060D:: @ 816060D
	switch VAR_RESULT
	case 0, BattleTower_Lobby_EventScript_160628
	case 1, BattleTower_Lobby_EventScript_160635

BattleTower_Lobby_EventScript_160628:: @ 8160628
	textcolor 0x1
	msgbox BattleTower_Lobby_Text_19A249, MSGBOX_DEFAULT
	goto BattleTower_Lobby_EventScript_160662

BattleTower_Lobby_EventScript_160635:: @ 8160635
	msgbox BattleTower_Lobby_Text_19A32D, MSGBOX_DEFAULT
	goto BattleTower_Lobby_EventScript_160662

BattleTower_Lobby_EventScript_160642:: @ 8160642
	setvar VAR_0x8004, 12
	special SetBattleTowerProperty
	goto BattleTower_Lobby_EventScript_160652

BattleTower_Lobby_EventScript_16064F:: @ 816064F
	special LoadPlayerParty

BattleTower_Lobby_EventScript_160652:: @ 8160652
	msgbox BattleTower_Lobby_Text_199FA9, MSGBOX_DEFAULT
	setvar VAR_0x8004, 11
	special SetBattleTowerProperty

BattleTower_Lobby_EventScript_160662:: @ 8160662
	release
	end

BattleTower_Lobby_EventScript_160664:: @ 8160664
	applymovement 1, BattleTower_Lobby_Movement_160693
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Lobby_Movement_160693
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement 1, BattleTower_Lobby_Movement_160697
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Lobby_Movement_16069A
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

BattleTower_Lobby_Movement_160693:: @ 8160693
	walk_up
	walk_up
	walk_up
	step_end

BattleTower_Lobby_Movement_160697:: @ 8160697
	walk_up
	set_invisible
	step_end

BattleTower_Lobby_Movement_16069A:: @ 816069A
	walk_up
	walk_up
	set_invisible
	step_end

@ 816069E
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end

BattleTower_Lobby_EventScript_1606A5:: @ 81606A5
	msgbox BattleTower_Lobby_Text_19A747, MSGBOX_NPC
	end

BattleTower_Lobby_EventScript_160715:: @ 8160715
	msgbox BattleTower_Lobby_Text_19A8AE, MSGBOX_NPC
	end

BattleTower_Lobby_EventScript_16071E:: @ 816071E
	msgbox BattleTower_Lobby_Text_19A946, MSGBOX_NPC
	end

BattleTower_Lobby_EventScript_160727:: @ 8160727
	lockall
	callnative ShowBattleTowerRecords
	waitbuttonpress
	callnative RemoveRecordsWindow
	releaseall
	end
	
BattleTower_Lobby_EventScript_Scott::
	lock
	faceplayer
	checkitem ITEM_EON_TICKET, 1
	compare VAR_RESULT, TRUE
	goto_if_eq BattleTower_Lobby_EventScript_Scott_GaveEonTicket
	checkitem ITEM_AURORA_TICKET, 1
	compare VAR_RESULT, TRUE
	goto_if_eq BattleTower_Lobby_EventScript_Scott_TryGiveEonTicket
	msgbox BattleTower_Lobby_Text_Scott28Wins, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET, 1
	setflag FLAG_GOT_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	msgbox BattleTower_Lobby_Text_ScottExplainAuroraTicket, MSGBOX_DEFAULT
	release
	end

BattleTower_Lobby_EventScript_Scott_TryGiveEonTicket::
	callnative GetBestBattleTowerStreakToVar0x8007
	compare VAR_0x8007, 56
	goto_if_lt BattleTower_Lobby_EventScript_Scott_GaveAuroraTicket
	msgbox BattleTower_Lobby_Text_Scott56Wins, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET, 1
	msgbox BattleTower_Lobby_Text_ScottExplainEonTicket, MSGBOX_DEFAULT
	release
	end

BattleTower_Lobby_EventScript_Scott_GaveAuroraTicket::
	msgbox BattleTower_Lobby_Text_ScottGaveAuroraTicket, MSGBOX_DEFAULT
	release
	end

BattleTower_Lobby_EventScript_Scott_GaveEonTicket::
	msgbox BattleTower_Lobby_Text_ScottGaveEonTicket, MSGBOX_DEFAULT
	release
	end