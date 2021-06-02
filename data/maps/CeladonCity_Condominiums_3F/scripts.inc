CeladonCity_Condominiums_3F_MapScripts:: @ 816C3DA
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonCity_Condominiums_3F_OnFrame
	.byte 0

CeladonCity_Condominiums_3F_OnFrame::
	map_script_2 VAR_TEMP_0, 2, CeladonCity_Condominiums_3F_EventScript_CheckMysticTicket
	.2byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer:: @ 816C3DB
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_GraphicArtist:: @ 816C3E4
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Writer:: @ 816C3ED
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Designer:: @ 816C3F6
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	compare VAR_RESULT, TRUE
	goto_if_eq CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex:: @ 816C412
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma:: @ 816C418
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	goto_if_questlog EventScript_ReleaseEnd
	setvar VAR_TEMP_0, 2
	special ShowDiploma
	waitstate
CeladonCity_Condominiums_3F_EventScript_CheckMysticTicket::
	setvar VAR_TEMP_0, 0
	checkitem ITEM_MYSTIC_TICKET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq CeladonCity_Condominiums_3F_EventScript_GiveMysticTicket
	release
	end

CeladonCity_Condominiums_3F_EventScript_GiveMysticTicket::
	goto_if_unset FLAG_SYS_RECEIVED_EXTENDED_DEX, CeladonCity_Condominiums_3F_EventScript_CantGiveMysticTicket
	textcolor 0
	msgbox CeladonCity_Condominiums_3F_Text_GiveMysticTicket
	textcolor 3
	giveitem ITEM_MYSTIC_TICKET, 1
	setflag FLAG_GOT_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	textcolor 0
	msgbox CeladonCity_Condominiums_3F_Text_ExplainMysticTicket
	release
	end

CeladonCity_Condominiums_3F_EventScript_CantGiveMysticTicket::
	textcolor 0
	msgbox CeladonCity_Condominiums_3F_Text_CantGiveMysticTicket
	release
	end

CeladonCity_Condominiums_3F_Text_CantGiveMysticTicket:
	.string "I have a gift for filling up your\n"
	.string "POKéDEX, but it's probably best to\l"
	.string "wait until it's been upgraded first.\p"
	.string "Come see me when your POKéDEX\n"
	.string "can handle registering more POKéMON.$"

CeladonCity_Condominiums_3F_Text_GiveMysticTicket:
	.string "Here's a little gift for filling up\n"
	.string "your POKéDEX.$"

CeladonCity_Condominiums_3F_Text_ExplainMysticTicket:
	.string "Bring that ticket to the docks in\n"
	.string "VERMILION CITY.\p"
	.string "With it, you can go to NAVEL ROCK\n"
	.string "between FOUR and FIVE ISLAND.\p"
	.string "Since you like catching POKéMON,\n"
	.string "you'll want to see what's there.\p"
	.string "Good luck!$"

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign:: @ 816C435
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer1:: @ 816C43E
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer2:: @ 816C447
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer3:: @ 816C450
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end
