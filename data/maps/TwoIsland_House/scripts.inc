.equ CHECKED_MUSHROOMS,  FLAG_TEMP_1
.equ HAS_BIG_MUSHROOM,   FLAG_TEMP_2
.equ HAS_TINY_MUSHROOMS, FLAG_TEMP_3
.equ HAS_BOTH_MUSHROOMS, FLAG_TEMP_4

TwoIsland_House_MapScripts::
	.byte 0

TwoIsland_House_EventScript_MoveManiac::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	clearflag HAS_BIG_MUSHROOM
	clearflag HAS_TINY_MUSHROOMS
	clearflag HAS_BOTH_MUSHROOMS
	goto_if_set CHECKED_MUSHROOMS, TwoIsland_House_EventScript_CheckPlayerHasMushrooms
	msgbox TwoIsland_House_Text_TeachMonMoveForMushroom
	setflag CHECKED_MUSHROOMS
	goto TwoIsland_House_EventScript_CheckPlayerHasMushrooms
	end

TwoIsland_House_EventScript_CheckPlayerHasMushrooms::
	checkitem ITEM_BIG_MUSHROOM
	call_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_SetHasBigMushroom
	checkitem ITEM_TINY_MUSHROOM, 2
	call_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_SetHasTinyMushrooms
	goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms
	goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_CheckAlsoHasBigMushroom
	goto TwoIsland_House_EventScript_EndTutorMove
	end

TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms::
	call_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_SetHasBothMushrooms
	goto TwoIsland_House_EventScript_AskTutorMon
	end

TwoIsland_House_EventScript_CheckAlsoHasBigMushroom::
	call_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_SetHasBothMushrooms
	goto TwoIsland_House_EventScript_AskTutorMon
	end

TwoIsland_House_EventScript_AskTutorMon::
	msgbox TwoIsland_House_Text_WantMeToTeachMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TwoIsland_House_EventScript_EndTutorMove
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_ChooseMonToTutor::
	setvar VAR_TEMP_0, 1
	msgbox TwoIsland_House_Text_TutorWhichMon
	special SelectMoveTutorMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, TwoIsland_House_EventScript_EndTutorMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_CantTutorEgg
	goto_if_eq VAR_0x8005, 0, TwoIsland_House_EventScript_NoMoveToTutorMon
	goto TwoIsland_House_EventScript_ChooseMoveToTeach
	end

TwoIsland_House_EventScript_ChooseMoveToTeach::
	msgbox TwoIsland_House_Text_TeachWhichMove
	special DisplayMoveTutorMenu
	waitstate
	goto_if_eq VAR_0x8004, 0, TwoIsland_House_EventScript_ChooseMonToTutor
	goto_if_set HAS_BOTH_MUSHROOMS, TwoIsland_House_EventScript_ChooseMushroom
	goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_GiveBigMushroom
	goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_GiveTinyMushrooms
	end

TwoIsland_House_EventScript_GiveBigMushroom::
	removeitem ITEM_BIG_MUSHROOM
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox TwoIsland_House_Text_HandedOverOneBigMushroom
	call EventScript_RestorePrevTextColor
	goto TwoIsland_House_EventScript_EndTutorMove
	end

TwoIsland_House_EventScript_GiveTinyMushrooms::
	removeitem ITEM_TINY_MUSHROOM, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox TwoIsland_House_Text_HandedOverTwoTinyMushrooms
	call EventScript_RestorePrevTextColor
	goto TwoIsland_House_EventScript_EndTutorMove
	end

TwoIsland_House_EventScript_ChooseMushroom::
	message TwoIsland_House_Text_IllNeedMushroomOrTwo
	waitmessage
	multichoice 0, 0, MULTICHOICE_MUSHROOMS, TRUE
	switch VAR_RESULT
	case 0, TwoIsland_House_EventScript_GiveTinyMushrooms
	case 1, TwoIsland_House_EventScript_GiveBigMushroom
	end

TwoIsland_House_EventScript_NoMoveToTutorMon::
	msgbox TwoIsland_House_Text_NoMoveICanTeachThatMon
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_CantTutorEgg::
	msgbox TwoIsland_House_Text_CantTeachAnEgg
	goto TwoIsland_House_EventScript_ChooseMonToTutor
	end

TwoIsland_House_EventScript_EndTutorMove::
	setvar VAR_TEMP_0, 0
	msgbox TwoIsland_House_Text_NeedMushroomOrTwoToLearnMove
	release
	end

TwoIsland_House_EventScript_SetHasBigMushroom::
	setflag HAS_BIG_MUSHROOM
	return

TwoIsland_House_EventScript_SetHasTinyMushrooms::
	setflag HAS_TINY_MUSHROOMS
	return

TwoIsland_House_EventScript_SetHasBothMushrooms::
	setflag HAS_BOTH_MUSHROOMS
	return

TwoIsland_House_EventScript_EffortWoman::
	lock
	faceplayer
	bufferleadmonspeciesname 0
	msgbox TwoIsland_House_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	compare VAR_RESULT, TRUE
	call_if_eq TwoIsland_House_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, AreLeadMonEVsMaxedOut
	compare VAR_RESULT, FALSE
	call_if_eq TwoIsland_House_EventScript_MonEVsNotMaxed
	msgbox TwoIsland_House_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message TwoIsland_House_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox TwoIsland_House_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

TwoIsland_House_EventScript_MonEVsNotMaxed::
	msgbox TwoIsland_House_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

TwoIsland_House_EventScript_MonHasEffortRibbon::
	msgbox TwoIsland_House_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

TwoIsland_House_Text_OhYourPokemon:
	.string "Oh?\n"
	.string "Your {STR_VAR_1}…$"

TwoIsland_House_Text_PleaseGiveItThisEffortRibbon:
	.string "Went for it stupendously!\p"
	.string "As its reward, please give it this\n"
	.string "EFFORT RIBBON.$"

TwoIsland_House_Text_ReceivedEffortRibbon:
	.string "{COLOR DARK_GRAY}{PLAYER} received the EFFORT RIBBON.$"

TwoIsland_House_Text_PutEffortRibbonOnMon:
	.string "{COLOR DARK_GRAY}{PLAYER} put the EFFORT RIBBON\n"
	.string "on {STR_VAR_1}.$"

TwoIsland_House_Text_GoForItLittleHarder:
	.string "You have to go for it a\n"
	.string "little harder.\p"
	.string "If you do, I'll give your POKéMON\n"
	.string "something nice.$"

TwoIsland_House_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
	.string "RIBBON looks good on it!$"
