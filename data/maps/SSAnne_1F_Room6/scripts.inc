SSAnne_1F_Room6_MapScripts:: @ 8160DF2
	map_script MAP_SCRIPT_ON_LOAD SSAnne_1F_Room6_MapScript_MakePc
	.byte 0

SSAnne_1F_Room6_MapScript_MakePc:
	setmetatile 0, 0, 0x3D0, 1
	setmetatile 0, 1, 0x062, 1
	setmetatile 0, 2, 0x3D1, 0
	setmetatile 1, 2, 0x31D, 0
	end

SSAnne_1F_Room6_EventScript_Woman:: @ 8160DF3
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHeal:: @ 8160E18
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SSAnne_1F_Room6_EventScript_DeclineHealMale
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHealMale:: @ 8160E2E
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
	release
	end
