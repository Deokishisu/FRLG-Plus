SSAnne_1F_Room6_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD SSAnne_1F_Room6_MapScript_MakePc
	.byte 0

SSAnne_1F_Room6_MapScript_MakePc:
	setmetatile 0, 0, 0x3D0, 1
	setmetatile 0, 1, 0x062, 1
	setmetatile 0, 2, 0x3D1, 0
	setmetatile 1, 2, 0x31D, 0
	end

SSAnne_1F_Room6_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHeal::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHealMale::
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
	release
	end
