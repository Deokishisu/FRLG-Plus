SilphCo_9F_MapScripts:: @ 8161CDE
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_9F_OnLoad
	.byte 0

SilphCo_9F_OnLoad:: @ 8161CE4
	call_if_unset FLAG_SILPH_9F_DOOR_1, EventScript_Close9FDoor1
	call_if_unset FLAG_SILPH_9F_DOOR_2, EventScript_Close9FDoor2
	call_if_unset FLAG_SILPH_9F_DOOR_3, EventScript_Close9FDoor3
	call_if_unset FLAG_SILPH_9F_DOOR_4, EventScript_Close9FDoor4
	end

SilphCo_9F_EventScript_HealWoman:: @ 8161D09
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge SilphCo_9F_EventScript_HealWomanRocketsGone
	msgbox SilphCo_9F_Text_YouShouldTakeQuickNap
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox SilphCo_9F_Text_DontGiveUp
	release
	end

SilphCo_9F_EventScript_HealWomanRocketsGone:: @ 8161D2E
	msgbox SilphCo_9F_Text_ThankYouSoMuch
	release
	end

SilphCo_9F_EventScript_FloorSign:: @ 8161D38
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_9F_EventScript_Ed:: @ 8161D41
	trainerbattle_single TRAINER_SCIENTIST_ED, SilphCo_9F_Text_EdIntro, SilphCo_9F_Text_EdDefeat
	msgbox SilphCo_9F_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt1:: @ 8161D58
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_37, SilphCo_9F_Text_Grunt1Intro, SilphCo_9F_Text_Grunt1Defeat
	msgbox SilphCo_9F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt2:: @ 8161D6F
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_38, SilphCo_9F_Text_Grunt2Intro, SilphCo_9F_Text_Grunt2Defeat
	msgbox SilphCo_9F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Woman:: @ 8161770
	msgbox SilphCo_9F_Text_Woman, MSGBOX_NPC
	end

SilphCo_9F_Text_Woman:
	.string "Oh, hello.\n"
	.string "Do your parents work here?\p"
	.string "SILPH CO. provides childcare\n"
	.string "for workers who need it.\p"
	.string "Fortunately, we were out on\n"
	.string "a trip when the ROCKETS came.$"

SilphCo_9F_EventScript_GBAKid:: @ 8161770
	msgbox SilphCo_9F_Text_GBAKid, MSGBOX_NPC
	end

SilphCo_9F_Text_GBAKid:
	.string "Hey, aren't you the TRAINER\n"
	.string "that stopped TEAM ROCKET?\l"
	.string "What are you doing back here?\p"
	.string "Did you miss some of the stuff\n"
	.string "the ROCKETS dropped?$"

SilphCo_9F_EventScript_LittleGirl:: @ 8161770
	msgbox SilphCo_9F_Text_LittleGirl, MSGBOX_NPC
	end

SilphCo_9F_Text_LittleGirl:
	.string "If a mean guy took over this room,\n"
	.string "you know what I'd do?\p"
	.string "I tell him to go home, but I'd\n"
	.string "be really loud!\l"
	.string "He'd have to listen after that!$"

SilphCo_9F_EventScript_LittleBoy:: @ 8161770
	msgbox SilphCo_9F_Text_LittleBoy, MSGBOX_NPC
	end

SilphCo_9F_Text_LittleBoy:
	.string "What's your favorite POKéMON?\p"
	.string "I don't have one, but I do have\n"
	.string "a least favorite.\p"
	.string "…\n"
	.string "It's SEEL…$"

SilphCo_9F_EventScript_SeelGirl:: @ 8161770
	msgbox SilphCo_9F_Text_SeelGirl, MSGBOX_NPC
	end

SilphCo_9F_Text_SeelGirl:
	.string "My SEEL gets jealous when I spend\n"
	.string "time with other kids.\p"
	.string "My friend gets jealous when I spend\n"
	.string "time with SEEL.\p"
	.string "I just can't win!$"

SilphCo_9F_EventScript_Newbie:: @ 8161770
	msgbox SilphCo_9F_Text_Newbie, MSGBOX_NPC
	end

SilphCo_9F_Text_Newbie:
	.string "I'm new a brand new hire.\n"
	.string "It's hard learning my way around.\p"
	.string "And who decided these pads were\n"
	.string "a good idea, anyway?\p"
	.string "I try to go to the water cooler\n"
	.string "and suddenly I'm four floors up\l"
	.string "and totally lost.$"

SilphCo_9F_EventScript_WorkerF:: @ 8161770
	msgbox SilphCo_9F_Text_WorkerF
	release
	end

SilphCo_9F_Text_WorkerF:
	.string "I can't believe you fought\n"
	.string "all those ROCKETS.\p"
	.string "You're so brave!$"

SilphCo_9F_EventScript_BragWorkerM:: @ 8161770
	msgbox SilphCo_9F_Text_BragWorkerM
	release
	end

SilphCo_9F_Text_BragWorkerM:
	.string "PIDGEY and I took on two\n"
	.string "of those ROCKET GRUNTS solo!\p"
	.string "They had two big RHYDON and four\n"
	.string "humongous GYARADOS between them!\p"
	.string "It was no use, though, PIDGEY\n"
	.string "and I wiped the floor with them.\p"
	.string "I doubt they'll be back any time\n"
	.string "soon after the thrashing they got.$"

SilphCo_9F_EventScript_Scientist:: @ 8161770
	msgbox SilphCo_9F_Text_Scientist, MSGBOX_NPC
	end

SilphCo_9F_Text_Scientist:
	.string "I remember this story differently.\p"
	.string "It was one ROCKET GRUNT with a\n"
	.string "RATTATA and a ZUBAT.\p"
	.string "PIDGEY lost so badly that the\n"
	.string "GRUNT said it wasn't worth stealing.\p"
	.string "Then he shoved them both\n"
	.string "in a utility closet.$"
