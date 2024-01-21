SilphCo_8F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_8F_OnLoad
	.byte 0

SilphCo_8F_OnLoad::
	call_if_unset FLAG_SILPH_8F_DOOR, EventScript_Close8FDoor
	call_if_unset FLAG_HIDE_SAFFRON_CIVILIANS, SilphCo_8F_EventScript_ScientistPosition
	end

SilphCo_8F_EventScript_ScientistPosition::
	setobjectmovementtype 6, MOVEMENT_TYPE_WANDER_AROUND
	setobjectxyperm 6, 26, 11
	return

SilphCo_8F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_8F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_8F_Text_WonderIfSilphIsFinished
	release
	end

SilphCo_8F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_8F_Text_ThanksForSavingUs
	release
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerIntro, SilphCo_8F_Text_ParkerDefeat
	msgbox SilphCo_8F_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_32, SilphCo_8F_Text_Grunt1Intro, SilphCo_8F_Text_Grunt1Defeat
	msgbox SilphCo_8F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_36, SilphCo_8F_Text_Grunt2Intro, SilphCo_8F_Text_Grunt2Defeat
	msgbox SilphCo_8F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_ScientistBro::
	msgbox SilphCo_8F_Text_ScientistBro, MSGBOX_NPC
	end

SilphCo_8F_Text_ScientistBro:
	.string "I am one of the four SILPH\n"
    .string "BROTHERS!\p"
	.string "I'm not actually sure what I do\n"
	.string "for the company…\p"
	.string "Nobody has come to give me\n"
	.string "work to do in a while…\p"
	.string "Have they forgotten about me?\n"
	.string "Do I just come in and do nothing?\p"
	.string "At least I'm still getting paid.$"

SilphCo_8F_EventScript_WorkerF::
	msgbox SilphCo_8F_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_8F_Text_WorkerF:
	.string "Can't talk, I've gotta eat fast!\n"
	.string "My lunch break is almost over!\p"
	.string "Hurry up, WIGGLYTUFF!\n"
	.string "Don't make me late again!$"