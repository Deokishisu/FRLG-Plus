OneIsland_KindleRoad_GlassWorkshop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_KindleRoad_GlassWorkshop_OnTransition
	.byte 0

	.set BLUE_FLUTE_PRICE,   250
	.set YELLOW_FLUTE_PRICE, 500
	.set RED_FLUTE_PRICE,    500
	.set WHITE_FLUTE_PRICE,  1000
	.set BLACK_FLUTE_PRICE,  1000
	.set LOWEST_ASH_PRICE,   BLUE_FLUTE_PRICE

OneIsland_KindleRoad_GlassWorkshop_OnTransition:
	compare VAR_GLASS_WORKSHOP_STATE, 1
	call_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack::
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_GlassWorker::
	lock
	faceplayer
	compare VAR_GLASS_WORKSHOP_STATE, 10
	goto_if_ge OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveItemAfterNoRoom
	compare VAR_GLASS_WORKSHOP_STATE, 2
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_CheckCollectedAsh
	compare VAR_GLASS_WORKSHOP_STATE, 1
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ExplainSootSack
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_GoCollectAshWithThis, MSGBOX_DEFAULT
	giveitem ITEM_SOOT_SACK
	setvar VAR_GLASS_WORKSHOP_STATE, 1
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_ExplainSootSack::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_CheckCollectedAsh::
	checkitem ITEM_SOOT_SACK, 1
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_SootSackNotInBag
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_LetsSeeCollectedAshes, MSGBOX_DEFAULT
	compare VAR_ASH_GATHER_COUNT, LOWEST_ASH_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAsh
	message OneIsland_KindleRoad_GlassWorkshop_Text_WhichGlassItemWoudYouLike
	waitmessage
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_SootSackNotInBag::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_HaventGotYourSootSack, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseGlassItem::
	multichoice 13, 0, MULTICHOICE_GLASS_WORKSHOP_VENDOR, FALSE
	copyvar VAR_0x8009, VAR_RESULT
	switch VAR_RESULT
	case 0, OneIsland_KindleRoad_GlassWorkshop_EventScript_BlueFlute
	case 1, OneIsland_KindleRoad_GlassWorkshop_EventScript_YellowFlute
	case 2, OneIsland_KindleRoad_GlassWorkshop_EventScript_RedFlute
	case 3, OneIsland_KindleRoad_GlassWorkshop_EventScript_WhiteFlute
	case 4, OneIsland_KindleRoad_GlassWorkshop_EventScript_BlackFlute
	case 5, OneIsland_KindleRoad_GlassWorkshop_EventScript_CancelGlassItemSelect
	case 127, OneIsland_KindleRoad_GlassWorkshop_EventScript_CancelGlassItemSelect
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_BlueFlute::
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLUE_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 10
	subvar VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_YellowFlute::
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, YELLOW_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 11
	subvar VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_RedFlute::
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, RED_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 12
	subvar VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_WhiteFlute::
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, WHITE_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 13
	subvar VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_BlackFlute::
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLACK_FLUTE_PRICE
	compare VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
	goto_if_lt OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 14
	subvar VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_CancelGlassItemSelect::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_AllThatAshButDontWantAnything, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAsh::
	setvar VAR_0x800A, LOWEST_ASH_PRICE
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_1, VAR_0x800A
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_NotEnoughAshNeedX, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_NotEnoughAshForItem::
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_2, VAR_0x800A
	message OneIsland_KindleRoad_GlassWorkshop_Text_NotEnoughAshToMakeItem
	waitmessage
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseDifferentItem::
	message OneIsland_KindleRoad_GlassWorkshop_Text_WhichWouldYouLike
	waitmessage
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_ChooseGlassItem
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_MakeGlassItem::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IllMakeItemForYou, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_GLASS_FLUTE
	delay 30
	fadescreen FADE_FROM_BLACK
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveGlassFlute
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveGlassFlute::
	switch VAR_0x8008
	case ITEM_BLUE_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveBlueFlute
	case ITEM_YELLOW_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveYellowFlute
	case ITEM_RED_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveRedFlute
	case ITEM_WHITE_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveWhiteFlute
	case ITEM_BLACK_FLUTE, OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveBlackFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveBlueFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_BLUE_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveYellowFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_YELLOW_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveRedFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_RED_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveWhiteFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_WHITE_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_ActuallyGiveBlackFlute:
	giveitem_msg OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute, ITEM_BLACK_FLUTE
	compare VAR_RESULT, FALSE
	goto_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute
	return

OneIsland_KindleRoad_GlassWorkshop_EventScript_NoRoomForFlute::
	call EventScript_BagIsFull
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_NoRoomInBag, MSGBOX_DEFAULT
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveItemAfterNoRoom::
	switch VAR_GLASS_WORKSHOP_STATE
	case 10, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveBlueFlute
	case 11, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveYellowFlute
	case 12, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveRedFlute
	case 13, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveWhiteFlute
	case 14, OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveBlackFlute
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveBlueFlute::
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveYellowFlute::
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveRedFlute::
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveWhiteFlute::
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveBlackFlute::
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_TryGiveItemAgain::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq OneIsland_KindleRoad_GlassWorkshop_EventScript_GiveGlassFlute
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_NinjaBoy::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_FunToBlowGlassFlute, MSGBOX_NPC
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_Girl::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_Girl, MSGBOX_NPC
	end

OneIsland_KindleRoad_GlassWorkshop_EventScript_Sign::
	msgbox OneIsland_KindleRoad_GlassWorkshop_Text_Sign, MSGBOX_SIGN
	end

OneIsland_KindleRoad_GlassWorkshop_Text_GoCollectAshWithThis:
	.string "This area is covered in volcanic ash,\n"
	.string "huff-puff!\p"
	.string "I'm specially gifted, huff-puff.\p"
	.string "I make glass out of volcanic ash\n"
	.string "and make items, huff-puff.\p"
	.string "Go collect ashes with this,\nhuff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_ExplainSootSack:
	.string "Just take that SOOT SACK and walk\n"
	.string "through piles of ash, huff-puff.\p"
	.string "And it will fill up with the\nvolcanic ash,"
	.string " huff-puff.\p"
	.string "Once you think you've collected a\ngood"
	.string " amount, come back, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_LetsSeeCollectedAshes:
	.string "Have you collected ashes, huff-puff?\n"
	.string "Let me see, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_NotEnoughAshNeedX:
	.string "Hmmm…\n"
	.string "There's not enough here, huff-puff.\l"
	.string "I can't craft with this, huff-puff.\p"
	.string "Let's see… {STR_VAR_1} is the number of\nsteps"
	.string " you'll need to walk for me\lto make you"
	.string " a BLUE FLUTE, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_WhichGlassItemWoudYouLike:
	.string "Oh! You've got a lot of ashes,\n"
	.string "huff-puff!\p"
	.string "I'll make you something, huff-puff!\n"
	.string "Which one would you like, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_IsThatTheItemForYou:
	.string "A {STR_VAR_1}, huff-puff?\n"
	.string "Is that the one for you, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_WhichWouldYouLike:
	.string "Which one would you like, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_IllMakeItemForYou:
	.string "A {STR_VAR_1} it is, then,\nhuff-puff!\p"
	.string "Okay! I'll make it now, huff-puff.\n"
	.string "Just wait a little while, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_NotEnoughAshToMakeItem:
	.string "A {STR_VAR_1}, huff-puff?\p"
	.string "There's not enough ash here to make\n"
	.string "that, though, huff-puff.\p"
	.string "Let's see… {STR_VAR_2} is the number of\nsteps "
	.string "you'll need to walk through\lvolcanic ash "
	.string "for me to make that,\lhuff-puff.\p"
	.string "Which item would you rather have\n"
	.string "me make instead, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_AllThatAshButDontWantAnything:
	.string "You've collected all that ash, but\nyou "
	.string "don't want anything, huff-puff?$"

OneIsland_KindleRoad_GlassWorkshop_Text_IveFinishedGlassItem:
	.string "Ah, I've finished your {STR_VAR_1}.\n"
	.string "Take it, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_NoRoomInBag:
	.string "Oh?\n"
	.string "You've no room in your BAG, huff-puff.\p"
	.string "I'll hold on to it, so come back later,\n"
	.string "huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_HaventGotYourSootSack:
	.string "Hah? You haven't got your SOOT SACK\n"
	.string "with you, huff-puff.\p"
	.string "You have to keep it with you to collect\n"
	.string "volcanic ash, huff-puff.$"

OneIsland_KindleRoad_GlassWorkshop_Text_FunToBlowGlassFlute:
	.string "I'm an apprentice learning how to\n"
	.string "make glass items from ash.\p"
	.string "Did you know that the BLUE FLUTE\n"
	.string "wakes up POKéMON who hear it?\p"
	.string "But, to me, the nicest-sounding\n"
	.string "flute that wakes up sleeping\l"
	.string "POKéMON is the POKé FLUTE!\p"
	.string "…I wonder if I'll ever learn to make\n"
	.string "one of those.$"

OneIsland_KindleRoad_GlassWorkshop_Text_Girl:
	.string "My uncle makes glass stuff too!\n"
	.string "He lives far away, huff-puff.\p"
	.string "I saw a dizzy, spotted POKéMON when\n"
	.string "we went to visit him, huff-puff!$"

OneIsland_KindleRoad_GlassWorkshop_Text_Sign:
	.string "“Available Glass Items,”\n"
	.string "the sign says.\p"
	.string "BLUE FLUTE: Awakens a sleeping\n"
	.string "POKéMON.\p"
	.string "YELLOW FLUTE: Snaps a POKéMON\nout "
	.string "of confusion.\p"
	.string "RED FLUTE: Snaps a POKéMON\nout "
	.string "of infatuation.\p"
	.string "WHITE FLUTE: Makes wild POKéMON\n"
	.string "appear more frequently.\p"
	.string "BLACK FLUTE: Makes wild POKéMON\n"
	.string "appear less frequently.$"

OneIsland_KindleRoad_GlassWorkshop_Text_ReceivedFlute:
	.string "{PLAYER} received the\n{STR_VAR_1}!$"

