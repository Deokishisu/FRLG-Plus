PewterCity_Museum_B1F_MapScripts::
	.byte 0
	
PewterCity_Museum_B1F_EventScript_Hiker::
	msgbox PewterCity_Museum_B1F_Text_HikerExplains, MSGBOX_NPC
	end
	
PewterCity_Museum_B1F_EventScript_Scientist::
	msgbox PewterCity_Museum_B1F_Text_Scientist, MSGBOX_NPC
	end

PewterCity_Museum_B1F_EventScript_FlashScientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM05, PewterCity_Museum_B1F_EventScript_AlreadyGotHM05
	msgbox PewterCity_Museum_B1F_Text_YouEarnedFlash
	checkitemspace ITEM_HM05, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Aide_EventScript_NoRoomForItem
	giveitem_msg PewterCity_Museum_B1F_Text_ReceivedHM05FromScientist, ITEM_HM05
	setflag FLAG_GOT_HM05
	msgbox PewterCity_Museum_B1F_Text_ExplainHM05
	release
	end

PewterCity_Museum_B1F_EventScript_AlreadyGotHM05::
	msgbox PewterCity_Museum_B1F_Text_ExplainHM05
	release
	end