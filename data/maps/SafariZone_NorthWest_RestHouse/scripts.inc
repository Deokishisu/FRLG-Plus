SafariZone_NorthWest_RestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD SafariZone_NorthWest_RestHouse_MapScript_MakePC
	.byte 0

SafariZone_NorthWest_RestHouse_MapScript_MakePC::
	setmetatile 2, 0, 0x300, 1
	setmetatile 2, 1, 0x062, 1
	setmetatile 2, 2, 0x301, 0
	setmetatile 4, 0, 0x2C8, 1
	setmetatile 4, 1, 0x2CA, 1
	setmetatile 5, 0, 0x2C9, 1
	setmetatile 5, 1, 0x2CB, 1
	end

SafariZone_NorthWest_RestHouse_EventScript_OldWoman::
	msgbox SafariZone_NorthWest_RestHouse_Text_OldWoman, MSGBOX_NPC
	end

SafariZone_NorthWest_RestHouse_Text_OldWoman::
	.string "My grandson has a lot of energy,\n"
	.string "but getting here has worn me out!$"

SafariZone_NorthWest_RestHouse_EventScript_LittleBoy::
	msgbox SafariZone_NorthWest_RestHouse_Text_LittleBoy, MSGBOX_NPC
	end

SafariZone_NorthWest_RestHouse_Text_LittleBoy::
	.string "Me and Grandma are here to see\n"
	.string "the new POKéMON!\p"
	.string "There are so many here I've never\n"
	.string "seen before!$"

SafariZone_NorthWest_RestHouse_EventScript_SuperNerd::
	msgbox SafariZone_NorthWest_RestHouse_Text_SuperNerd, MSGBOX_NPC
	end

SafariZone_NorthWest_RestHouse_Text_SuperNerd::
	.string "I saw a weird, noodley POKéMON\n"
	.string "hiding in the rocks on the\l"
	.string "ridge behind us.\p"
	.string "Too bad I don't have a POKéMON\n"
	.string "that can learn ROCK SMASH!$"

SafariZone_NorthWest_RestHouse_EventScript_Lass::
	msgbox SafariZone_NorthWest_RestHouse_Text_Lass, MSGBOX_NPC
	end

SafariZone_NorthWest_RestHouse_Text_Lass::
	.string "These REST HOUSES are so nice.\n"
	.string "I love sprawling out here.\p"
	.string "Our steps aren't counted while we're\n"
	.string "resting, so they're not wasted!$"

SafariZone_NorthWest_RestHouse_EventScript_Worker::
	msgbox SafariZone_NorthWest_RestHouse_Text_Worker, MSGBOX_NPC
	end

SafariZone_NorthWest_RestHouse_Text_Worker::
	.string "We thought we'd have to landscape\n"
	.string "this whole area to make it a\l"
	.string "suitable POKéMON habitat.\p"
	.string "But we cut through the trees and\n"
	.string "discovered a lovely natural vista.\p"
	.string "We imported rare POKéMON to fill it!\n"
	.string "I hope you're enjoying yourself!$"

SafariZone_NorthWest_RestHouse_EventScript_Clipboard::
	msgbox SafariZone_NorthWest_RestHouse_Text_Clipboard, MSGBOX_NPC
	end

SafariZone_NorthWest_RestHouse_Text_Clipboard::
	.string "It's a message from the SAFARI\n"
	.string "ZONE WARDEN.\p"
	.string "“I just heard that the SAFARI ZONE\n"
	.string "in HOENN has opened a new wing\l"
	.string "with exotic POKéMON!\p"
	.string "We can't allow our beloved SAFARI\n"
	.string "ZONE to become out of date!\p"
	.string "I'm putting a team together to\n"
	.string "scout for viable expansion sites.\p"
	.string "Interested employees please sign up\n"
	.string "at the office.”\p"
	.string "- WARDEN BAOBA$"

SafariZone_NorthWest_RestHouse_EventScript_Stepmonger::
	callnative(SafariZoneCheckSteps)
	compare VAR_RESULT, 600
	goto_if_eq SafariZone_NorthWest_RestHouse_EventScript_StepmongerFull
	msgbox SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_0
	showmoneybox 0, 0, 0
	msgbox SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_2
	checkmoney 750, 0
	compare VAR_RESULT, FALSE
	goto_if_eq SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_5
	removemoney 750, 0
	updatemoneybox 0, 0, 0
	textcolor 3
	playfanfare MUS_LEVEL_UP
	msgbox SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_3
	waitfanfare
	call EventScript_RestorePrevTextColor
	msgbox SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_4, MSGBOX_NPC
	hidemoneybox 0, 0
	callnative SafariZoneRefillSteps
	release
	end

SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_2:
	msgbox SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_2, MSGBOX_NPC
	hidemoneybox 0, 0
	end

SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_5:
	msgbox FuchsiaCity_SafariZone_Entrance_Text_OopsNotEnoughMoney
	hidemoneybox 0, 0
	release
	end

SafariZone_NorthWest_RestHouse_EventScript_StepmongerFull:
	msgbox SafariZone_NorthWest_RestHouse_Text_StepmongerFull, MSGBOX_NPC
	end

SafariZone_NorthWest_RestHouse_Text_StepmongerFull:
	.string "Welcome to AREA 4!\nYour step allowance is full.\pWe don't count time spent\ninside REST HOUSES.\pCome back when you run low\non steps!$"

SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_0:
	.string "Welcome to AREA 4!\nDo you need more steps?$"

SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_1:
	.string "I can refill your step allowance\nfor ¥750.\pDo you want to refill your steps?$"

SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_2:
	.string "Okay, I wish you the best of luck\non your SAFARI GAME!$"

SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_3:
	.string "{PLAYER}'s steps were refilled!$"

SafariZone_NorthWest_RestHouse_EventScript_Stepmonger_Text_4:
	.string "Your steps are topped up!\nGood luck on your wild excursion!$"