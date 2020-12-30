EventScript_FujiOutside::
	lock
	faceplayer
	msgbox EventScript_FujiOutside_Text_0, MSGBOX_YESNO
EventScript_FujiOutside_2:
	compare VAR_RESULT, NO
	goto_if_eq EventScript_FujiOutside_3
	msgbox EventScript_FujiOutside_Text_2, MSGBOX_DEFAULT
	checkitemspace ITEM_OLD_SEA_MAP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_FujiOutside_6
	giveitem_msg EventScript_FujiOutside_Text_3, ITEM_OLD_SEA_MAP, 1, MUS_OBTAIN_KEY_ITEM
	setflag FLAG_GOT_OLD_SEA_MAP
	msgbox EventScript_FujiOutside_Text_4, MSGBOX_NPC
	getplayerxy VAR_RESULT, VAR_0x8003
	compare VAR_RESULT, 9
	goto_if_ne EventScript_FujiOutside_9
	applymovement 4, Movement_FujiToHouseAroundPlayer
	waitmovement 0
EventScript_FujiOutside_8:
	opendoor 10, 11
	waitdooranim
	applymovement 4, PalletTown_Movement_OakEnterLab
	waitmovement 0
	closedoor 10, 11
	waitdooranim
	setflag FLAG_HIDE_LAVENDER_OUTSIDE_FUJI
	clearflag FLAG_HIDE_POKEHOUSE_FUJI
	release
	end

EventScript_FujiOutside_3:
	msgbox EventScript_FujiOutside_Text_1, MSGBOX_YESNO
	goto EventScript_FujiOutside_2

EventScript_FujiOutside_6:
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis, MSGBOX_DEFAULT
	release
	end

EventScript_FujiOutside_9:
	applymovement 4, Movement_FujiToHouse
	waitmovement 0
	goto EventScript_FujiOutside_8


Movement_FujiToHouse:
	walk_right
	walk_right
	face_up
	step_end

Movement_FujiToHouseAroundPlayer:
	walk_down
	walk_right
	walk_right
	walk_up
	step_end

EventScript_FujiOutside_Text_0:
	.string "MR. FUJI: {PLAYER}!\nHow is your quest going?\pAh, you and your POKéMON are\nthe POKéMON LEAGUE CHAMPIONS!\pCongratulations!\nYour deep love for your POKéMON\lis obvious to anyone.\pI have a favor to ask.\pThere is an island far from KANTO\nwhere a certain POKéMON lives.\pThat POKéMON was mistreated by\nhumans in the past.\pI was hoping you would befriend\nthat POKéMON and show it that\lhumans can be kind and gentle.\pWill you do this for me?$"

EventScript_FujiOutside_Text_1:
	.string "Helping this POKéMON is very\nimportant to me, {PLAYER}.\pPlease tell me you'll help.$"

EventScript_FujiOutside_Text_2:
	.string "MR. FUJI: Thank you, {PLAYER}.\pI have an old map to the island.\nI'm sure you've befriended a sailor\lor two during your quest.\pThey will be able to read this\nmap and take you there.$"

EventScript_FujiOutside_Text_3:
	.string "{PLAYER} received an OLD SEA MAP\nfrom MR. FUJI.$"

EventScript_FujiOutside_Text_4:
	.string "MR. FUJI: I know you will treat that\nPOKéMON with love and kindness.\pThank you, {PLAYER}.$"
