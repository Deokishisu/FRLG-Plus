EventScript_PkmnCenterNurse::
	goto_if_questlog EventScript_ReleaseEnd
	callnative CheckTrainerCardStars
	compare VAR_RESULT, 2
	goto_if_ge EventScript_PkmnCenterNurseTrainerCard
	message Text_WelcomeWantToHealPkmn
	waitmessage
	multichoice 19, 8, MULTICHOICE_YES_NO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case SCR_MENU_CANCEL, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	message Text_TakeYourPkmnForFewSeconds
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	special SetUsedPkmnCenterQuestLogEvent
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	end

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	return

EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom::
	specialvar VAR_RESULT, IsPlayerNotInTrainerTowerLobby
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUionRoom
	end

EventScript_PkmnCenterNurse_ReturnPkmn::
	message Text_RestoredPkmnToFullHealth
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUionRoom::
	goto_if_set FLAG_SYS_INFORMED_OF_LOCAL_WIRELESS_PLAYER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox Text_RestoredPkmnToFullHealth
	setflag FLAG_SYS_INFORMED_OF_LOCAL_WIRELESS_PLAYER
	message Text_PlayerIsPlayingRightNowGoForIt
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_Goodbye::
	msgbox Text_WeHopeToSeeYouAgain
	return

Movement_Bow::
	nurse_joy_bow
	delay_4
	step_end

EventScript_PkmnCenterNurseTrainerCard::
	goto_if_unset FLAG_SHOWN_COPPER_CARD_TO_NURSE, EventScript_PkmnCenterNurseTrainerCardFirst
	message Text_WelcomeTrainerCard
	waitmessage
	multichoice 19, 8, MULTICHOICE_YES_NO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmnTrainerCard
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case SCR_MENU_CANCEL, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurseTrainerCardFirst::
	message Text_WelcomeTrainerCardFirst
	waitmessage
	setflag FLAG_SHOWN_COPPER_CARD_TO_NURSE
	multichoice 19, 8, MULTICHOICE_YES_NO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmnTrainerCard
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case SCR_MENU_CANCEL, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_HealPkmnTrainerCard::
	incrementgamestat GAME_STAT_USED_POKECENTER
	message Text_TakeYourPkmnForFewSecondsTrainerCard
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	special SetUsedPkmnCenterQuestLogEvent
	goto EventScript_PkmnCenterNurse_ReturnPkmnTrainerCard
	end

EventScript_PkmnCenterNurse_ReturnPkmnTrainerCard::
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain
	return

Text_WelcomeTrainerCardFirst::
	.string "Welcome to our POKéMON CENTER!\p"
	.string "Would you like me to…\n"
	.string "Th-that TRAINER CARD!\p"
	.string "That wonderful shade!\n"
	.string "And all those stars!\p"
	.string "I've seen several TRAINERS\n"
	.string "with BRONZE CARDS up to now…\p"
	.string "But you're the first to top them\n"
	.string "with that TRAINER CARD.\p"
	.string "Please, {PLAYER}, may I have the\n"
	.string "honor of healing your POKéMON?$"

Text_TakeYourPkmnForFewSecondsTrainerCard::
	.string "I will be pleased to take your\n"
	.string "POKéMON for a few seconds.$"

Text_WelcomeTrainerCard::
	.string "Great to see you, {PLAYER}!\n"
	.string "You want the usual, right?$"

EventScript_SoftlockClerk::
	goto_if_set FLAG_TEMP_7, EventScript_SoftlockClerk_GaveAlready
	msgbox Text_SoftlockClerk_Initial, MSGBOX_NPC
	textcolor 3
	checkitemspace ITEM_POKE_BALL, 5
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_SoftlockClerk_NoRoom
	giveitem_msg PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
	setflag FLAG_TEMP_7
	release
	end

EventScript_SoftlockClerk_GaveAlready::
	msgbox Text_SoftlockClerk_GaveAlready, MSGBOX_NPC
	end

EventScript_SoftlockClerk_NoRoom::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis, MSGBOX_NPC
	end

Text_SoftlockClerk_Initial::
	.string "Hello, TRAINER!\p"
	.string "We've partnered with the POKéMON\n"
	.string "CENTER to do a special giveaway!\p"
	.string "Congratulations, you're the lucky\n"
	.string "winner! Enjoy your prize!$"

Text_SoftlockClerk_GaveAlready::
	.string "Hello, TRAINER!\n"
	.string "Put those POKé BALLS to good use!$"
