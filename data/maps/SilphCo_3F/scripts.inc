SilphCo_3F_MapScripts:: @ 81616C5
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_OnLoad
	.byte 0

SilphCo_3F_OnLoad:: @ 81616CB
	call_if_unset FLAG_SILPH_3F_DOOR_1, EventScript_Close3FDoor1
	call_if_unset FLAG_SILPH_3F_DOOR_2, EventScript_Close3FDoor2
	end

SilphCo_3F_EventScript_WorkerM:: @ 81616DE
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge SilphCo_3F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_3F_Text_WhatAmIToDo
	release
	end

SilphCo_3F_EventScript_WorkerMRocketsGone:: @ 81616F5
	msgbox SilphCo_3F_Text_YouAndYourMonsSavedUs
	release
	end

SilphCo_3F_EventScript_FloorSign:: @ 81616FF
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_EventScript_Jose:: @ 8161708
	trainerbattle_single TRAINER_SCIENTIST_JOSE, SilphCo_3F_Text_JoseIntro, SilphCo_3F_Text_JoseDefeat
	msgbox SilphCo_3F_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_Grunt:: @ 816171F
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_25, SilphCo_3F_Text_GruntIntro, SilphCo_3F_Text_GruntDefeat
	msgbox SilphCo_3F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_WorkerMWalking:: @ 81616F5
	msgbox SilphCo_3F_Text_WorkerMWalking, MSGBOX_NPC
	end

SilphCo_3F_Text_WorkerMWalking:
	.string "Sometimes, when I get stuck on\n"
	.string "a problem, I stroll the office.\p"
	.string "If you put on a serious face and\n"
	.string "walk fast, people think you're\l"
	.string "doing something important!$"

SilphCo_3F_EventScript_WorkerF:: @ 81616F5
	msgbox SilphCo_3F_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_3F_Text_WorkerF:
	.string "To be honest, I kind of miss\n"
	.string "TEAM ROCKET.\p"
	.string "It was scary, but at least I\n"
	.string "had an excuse to not work.$"

SilphCo_3F_EventScript_Scientist::
	lock
	msgbox SilphCo_3F_Text_Scientist
	release
	msgbox SilphCo_3F_Text_Scientist2, MSGBOX_NPC
	turnobject 7, DIR_NORTH
	end

SilphCo_3F_Text_Scientist:
	.string "Uh huh…\n"
	.string "No, of course not!\l"
	.string "There's no way that'd work…\p"
	.string "…Unless…\p"
	.string "I have to run this by the team.\n"
	.string "I'll call you back.$"

SilphCo_3F_Text_Scientist2::
	.string "Excuse me, I have to make\n"
	.string "another phone call.$"