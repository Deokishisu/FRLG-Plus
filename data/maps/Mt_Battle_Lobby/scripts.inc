Mt_Battle_Lobby_MapScripts::
	.byte 0

Mt_Battle_Lobby_EventScript_CooltrainerM::
	msgbox Mt_Battle_Lobby_Text_CooltrainerM, MSGBOX_NPC
	end

Mt_Battle_Lobby_Text_CooltrainerM:
	.string "I'm going to collect POKé COUPONS\n"
	.string "so I can get some new moves for my\l"
	.string "POKéMON.\p"
	.string "See that man in white sitting on the\n"
	.string "bench? He teaches POKéMON moves in\l"
	.string "exchange for POKé COUPONS.$"

Mt_Battle_Lobby_EventScript_CooltrainerF::
	msgbox Mt_Battle_Lobby_Text_CooltrainerF, MSGBOX_NPC
	end

Mt_Battle_Lobby_Text_CooltrainerF:
	.string "You can earn POKé COUPONS even\n"
	.string "while you're training.\l"
	.string "MT. BATTLE is a cool place!$"

Mt_Battle_Lobby_EventScript_PokeCouponExchange::
	lock
	faceplayer
	message Mt_Battle_Lobby_Text_PokeCouponExchangeIntro
	waitmessage
	multichoice 0, 0, MULTICHOICE_POKECOUPON_EXCHANGE, FALSE
	switch VAR_RESULT
	case 0, Mt_Battle_Lobby_EventScript_PokeCouponPrizes
	case 1, Mt_Battle_Lobby_EventScript_PokeCouponInfo
	case 2, Mt_Battle_Lobby_EventScript_ExitPokeCouponExchange
	case 127, Mt_Battle_Lobby_EventScript_ExitPokeCouponExchange 
	end

Mt_Battle_Lobby_EventScript_PokeCouponPrizes:
	showcoinsbox 19, 0
Mt_Battle_Lobby_EventScript_SkipShowCoinsBox:
	setvar VAR_0x8004, LISTMENU_POKECOUPON_PRIZES
	special ListMenu
	waitstate
	switch VAR_RESULT
	case 0, Mt_Battle_Lobby_EventScript_BufferMentalHerb
	case 1, Mt_Battle_Lobby_EventScript_BufferWhiteHerb
	case 2, Mt_Battle_Lobby_EventScript_BufferQuickClaw
	case 3, Mt_Battle_Lobby_EventScript_BufferFocusBand
	case 4, Mt_Battle_Lobby_EventScript_BufferBrightpowder
	case 5, Mt_Battle_Lobby_EventScript_BufferKingsRock
	case 6, Mt_Battle_Lobby_EventScript_BufferScopeLens
	case 7, Mt_Battle_Lobby_EventScript_BufferChoiceBand
	case 8, Mt_Battle_Lobby_EventScript_BufferShellBell
	case 9, Mt_Battle_Lobby_EventScript_BufferLeftovers
	case 10, Mt_Battle_Lobby_EventScript_BufferLuckyEgg
	case 11, Mt_Battle_Lobby_EventScript_BufferLiechiBerry
	case 12, Mt_Battle_Lobby_EventScript_BufferGanlonBerry
	case 13, Mt_Battle_Lobby_EventScript_BufferSalacBerry
	case 14, Mt_Battle_Lobby_EventScript_BufferPetayaBerry
	case 15, Mt_Battle_Lobby_EventScript_BufferApicotBerry
	case 16, Mt_Battle_Lobby_EventScript_BufferLansatBerry
	case 17, Mt_Battle_Lobby_EventScript_BufferStarfBerry
	case 18, Mt_Battle_Lobby_EventScript_BufferMoonStone
	case 19, Mt_Battle_Lobby_EventScript_BufferSunStone
	case 20, Mt_Battle_Lobby_EventScript_PokeCouponExchange2
	case 127, Mt_Battle_Lobby_EventScript_PokeCouponExchange2
	end

Mt_Battle_Lobby_EventScript_BufferMentalHerb:
	setvar VAR_TEMP_1, ITEM_MENTAL_HERB
	setvar VAR_TEMP_2, 6000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferWhiteHerb:
	setvar VAR_TEMP_1, ITEM_WHITE_HERB
	setvar VAR_TEMP_2, 6000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferQuickClaw:
	setvar VAR_TEMP_1, ITEM_QUICK_CLAW
	setvar VAR_TEMP_2, 8000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferFocusBand:
	setvar VAR_TEMP_1, ITEM_FOCUS_BAND
	setvar VAR_TEMP_2, 8000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferBrightpowder:
	setvar VAR_TEMP_1, ITEM_BRIGHT_POWDER
	setvar VAR_TEMP_2, 8000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferKingsRock:
	setvar VAR_TEMP_1, ITEM_KINGS_ROCK
	setvar VAR_TEMP_2, 8000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferScopeLens:
	setvar VAR_TEMP_1, ITEM_SCOPE_LENS
	setvar VAR_TEMP_2, 8000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferChoiceBand:
	setvar VAR_TEMP_1, ITEM_CHOICE_BAND
	setvar VAR_TEMP_2, 8000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferShellBell:
	setvar VAR_TEMP_1, ITEM_SHELL_BELL
	setvar VAR_TEMP_2, 8000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferLeftovers:
	setvar VAR_TEMP_1, ITEM_LEFTOVERS
	setvar VAR_TEMP_2, 8000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferLuckyEgg:
	setvar VAR_TEMP_1, ITEM_LUCKY_EGG
	setvar VAR_TEMP_2, 10000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferLiechiBerry:
	setvar VAR_TEMP_1, ITEM_LIECHI_BERRY
	setvar VAR_TEMP_2, 2500
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferGanlonBerry:
	setvar VAR_TEMP_1, ITEM_GANLON_BERRY
	setvar VAR_TEMP_2, 2500
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferSalacBerry:
	setvar VAR_TEMP_1, ITEM_SALAC_BERRY
	setvar VAR_TEMP_2, 2500
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferPetayaBerry:
	setvar VAR_TEMP_1, ITEM_PETAYA_BERRY
	setvar VAR_TEMP_2, 2500
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferApicotBerry:
	setvar VAR_TEMP_1, ITEM_APICOT_BERRY
	setvar VAR_TEMP_2, 2500
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferLansatBerry:
	setvar VAR_TEMP_1, ITEM_LANSAT_BERRY
	setvar VAR_TEMP_2, 2500
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferStarfBerry:
	setvar VAR_TEMP_1, ITEM_STARF_BERRY
	setvar VAR_TEMP_2, 2500
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferMoonStone:
	setvar VAR_TEMP_1, ITEM_MOON_STONE
	setvar VAR_TEMP_2, 1000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_BufferSunStone:
	setvar VAR_TEMP_1, ITEM_SUN_STONE
	setvar VAR_TEMP_2, 1000
	goto Mt_Battle_Lobby_EventScript_ConfirmSelection

Mt_Battle_Lobby_EventScript_ConfirmSelection:
	callnative CheckPokeCoupons
	compare VAR_RESULT, FALSE
	goto_if_eq Mt_Battle_Lobby_EventScript_NotEnoughPokeCoupons
	getitemname 0, VAR_TEMP_1
	msgbox Mt_Battle_Lobby_Text_ConfirmSelection, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Mt_Battle_Lobby_EventScript_SkipShowCoinsBox
	additem VAR_TEMP_1, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Mt_Battle_Lobby_EventScript_BagFull
	callnative RemovePokeCoupons
	msgbox Mt_Battle_Lobby_Text_GivePrize, MSGBOX_DEFAULT
	updatecoinsbox 19, 0
	//play brrrring! fanfare
	msgbox Mt_Battle_Lobby_Text_AnythingElse, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Mt_Battle_Lobby_EventScript_SkipShowCoinsBox
	goto Mt_Battle_Lobby_EventScript_PokeCouponExchange2
	end

Mt_Battle_Lobby_EventScript_BagFull:
	hidecoinsbox 19, 0
	msgbox Mt_Battle_Lobby_Text_YourBagIsFull, MSGBOX_DEFAULT
	release
	end

Mt_Battle_Lobby_EventScript_NotEnoughPokeCoupons:
	hidecoinsbox 19, 0
	msgbox Mt_Battle_Lobby_Text_NotEnoughPokeCoupons, MSGBOX_DEFAULT
	goto Mt_Battle_Lobby_EventScript_PokeCouponPrizes

Mt_Battle_Lobby_EventScript_ExitPokeCouponExchange::
	msgbox Mt_Battle_Lobby_Text_VisitAgain, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	release
	end

Mt_Battle_Lobby_EventScript_PokeCouponExchange2:
	hidecoinsbox 19, 0
	lock
	faceplayer
	message Mt_Battle_Lobby_Text_PokeCouponExchangeReturnToOuterMenu
	waitmessage
	multichoice 0, 0, MULTICHOICE_POKECOUPON_EXCHANGE, FALSE
	switch VAR_RESULT
	case 0, Mt_Battle_Lobby_EventScript_PokeCouponPrizes
	case 1, Mt_Battle_Lobby_EventScript_PokeCouponInfo
	case 2, Mt_Battle_Lobby_EventScript_ExitPokeCouponExchange
	case 127, Mt_Battle_Lobby_EventScript_ExitPokeCouponExchange 
	end

Mt_Battle_Lobby_EventScript_PokeCouponInfo:
	msgbox Mt_Battle_Lobby_Text_PokeCouponExchangeInfo, MSGBOX_DEFAULT
	goto Mt_Battle_Lobby_EventScript_PokeCouponExchange2

Mt_Battle_Lobby_Text_PokeCouponExchangeIntro:
	.string "This is the COUPON EXCHANGE.\nHow may I help you?$"

Mt_Battle_Lobby_Text_PokeCouponExchangeInfo:
	.string "By training at MT. BATTLE, you may\nbe rewarded with POKé COUPONS.\pYou get some for every ten\nTRAINERS you defeat.\pPick up your POKé COUPONS from\nthe AREA LEADERS.\pPOKé COUPONS can be exchanged for\nsuper prizes.\lCollect them and win big!\pRemember, if you quit your MT.\nBATTLE challenge before defeating\lten TRAINERS, you won't earn any\lPOKé COUPONS.$"

Mt_Battle_Lobby_Text_PokeCouponExchangeReturnToOuterMenu:
	.string "May I help you with anything else?$"

TEST_BufferChoiceCoupons:
	.string "{STR_VAR_1} selected.$"

Mt_Battle_Lobby_Text_VisitAgain:
	.string "I hope you'll visit us again.$"

Mt_Battle_Lobby_Text_ConfirmSelection:
	.string "Fine, {STR_VAR_1}.\nIs that correct?$"

Mt_Battle_Lobby_Text_GivePrize:
	.string "Okay, here's your\n{STR_VAR_1} prize.\p{PLAYER} received the prize.$"

Mt_Battle_Lobby_Text_AnythingElse:
	.string "Would you like to exchange POKé\nCOUPONS for anything else?$"

Mt_Battle_Lobby_Text_NotEnoughPokeCoupons:
	.string "I'm sorry, but you don't have enough\nPOKé COUPONS for that prize.$"

Mt_Battle_Lobby_Text_YourBagIsFull:
	.string "You don't have room for this prize!\pI hope you'll visit us again.$"