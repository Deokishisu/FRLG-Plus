SilphCo_2F_MapScripts:: @ 8161641
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad:: @ 8161647
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_ThunderWaveTutor:: @ 816165A
	goto EventScript_ThunderWaveTutor
	end

SilphCo_2F_EventScript_FloorSign:: @ 8161660
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_EventScript_Connor:: @ 8161669
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Jerry:: @ 8161680
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt1:: @ 8161697
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt2:: @ 81616AE
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Scientist::
	msgbox SilphCo_2F_Text_Scientist, MSGBOX_NPC
	end

SilphCo_2F_Text_Scientist:
	.string "Now that we're not working on the\n"
	.string "MASTER BALL anymore, we're pivoting\l"
	.string "to other projects.$"

SilphCo_2F_EventScript_WorkerF1::
	msgbox SilphCo_2F_Text_WorkerF1, MSGBOX_NPC
	end

SilphCo_2F_Text_WorkerF1:
	.string "Maybe our next product can be a\n"
	.string "security system to keep people\l"
	.string "like TEAM ROCKET out!$"

SilphCo_2F_EventScript_WorkerF2::
	msgbox SilphCo_2F_Text_WorkerF2, MSGBOX_NPC
	end

SilphCo_2F_Text_WorkerF2:
	.string "Programming is hard work!\p"
	.string "Can you imagine how difficult\n"
	.string "coding a PORYGON would be?\p"
	.string "To create a POKéMON out of\n"
	.string "code like that…\l"
	.string "It's unbelievable!$"

SilphCo_2F_EventScript_Woman::
	msgbox SilphCo_2F_Text_Woman, MSGBOX_NPC
	end

SilphCo_2F_Text_Woman:
	.string "We're constantly in and out of\n"
	.string "meetings all day long.\p"
	.string "I wish they would just let me\n"
	.string "work in peace…$"

SilphCo_2F_EventScript_WorkerM::
	textcolor 3
	msgbox SilphCo_2F_Text_WorkerM
	release
	end

SilphCo_2F_Text_WorkerM:
	.string "…\p"
	.string "He's asleep on the job!$"
