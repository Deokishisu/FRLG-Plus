VermilionCity_House1_MapScripts:: @ 816B3A6
	.byte 0

VermilionCity_House1_EventScript_FishingGurusBrother:: @ 816D817
	lock
	faceplayer
	goto_if_set FLAG_GOT_GOOD_ROD, VermilionCity_House1_EventScript_AlreadyGotGoodRod
	msgbox VermilionCity_House1_Text_DoYouLikeToFish, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermilionCity_House1_EventScript_GiveGoodRod
	msgbox VermilionCity_House1_Text_OhThatsDisappointing
	release
	end

VermilionCity_House1_EventScript_AlreadyGotGoodRod:: @ 816D83F
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_EventScript_GiveGoodRod:: @ 816D849
	msgbox VermilionCity_House1_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD, 1
	compare VAR_RESULT, FALSE
	goto_if_eq VermilionCity_House1_EventScript_NoRoomForGoodRod
	giveitem_msg VermilionCity_House1_Text_ReceivedGoodRod, ITEM_GOOD_ROD
	msgbox VermilionCity_House1_Text_GoodRodCanCatchBetterMons
	setflag FLAG_GOT_GOOD_ROD
	release
	end

VermilionCity_House1_EventScript_NoRoomForGoodRod:: @ 816D88A
	msgbox VermilionCity_House1_Text_YouHaveNoRoomForGift
	release
	end
