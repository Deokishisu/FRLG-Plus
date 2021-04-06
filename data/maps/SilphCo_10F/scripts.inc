SilphCo_10F_MapScripts:: @ 8161D86
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_10F_OnLoad
	.byte 0

SilphCo_10F_OnLoad:: @ 8161D8C
	call_if_unset FLAG_SILPH_10F_DOOR, EventScript_Close10FDoor
	end

SilphCo_10F_EventScript_WorkerF:: @ 8161D96
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge SilphCo_10F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_10F_Text_WaaaImScared
	release
	end

SilphCo_10F_EventScript_WorkerFRocketsGone:: @ 8161DAD
	msgbox SilphCo_10F_Text_KeepMeCryingASecret
	release
	end

SilphCo_10F_EventScript_FloorSign:: @ 8161DB7
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_Travis:: @ 8161DC0
	trainerbattle_single TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_Grunt:: @ 8161DD7
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat
	msgbox SilphCo_10F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_WorkerBro:: @ 8161770
	msgbox SilphCo_10F_Text_WorkerBro, MSGBOX_NPC
	end

SilphCo_10F_Text_WorkerBro:
	.string "I am one of the four SILPH\n"
    .string "BROTHERS!\p"
	.string "I'm a janitor!\n"
	.string "I keep this whole place sparkling!$"

SilphCo_10F_EventScript_WorkerM:: @ 8161770
	msgbox SilphCo_10F_Text_WorkerM, MSGBOX_NPC
	end

SilphCo_10F_Text_WorkerM:
	.string "Ahh!\n"
	.string "You startled me!\p"
	.string "…\n"
	.string "What am I doing?\l"
	.string "…Okay, you caught me.\p"
	.string "I never wanted to be an office\n"
	.string "drone, I wanted to be an artist!\p"
	.string "I'm replacing some of the paintings\n"
	.string "around here with some of my own\l"
	.string "to see if people like them.\p"
	.string "Don't worry, I'm putting the old\n"
	.string "paintings in storage.\p"
	.string "I'd never take such derivative\n"
	.string "work home for myself.$"

SilphCo_10F_EventScript_Painting::
	goto_if_unset FLAG_HIDE_SAFFRON_CIVILIANS, SilphCo_10F_EventScript_NewPainting
	msgbox Text_Painting, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_NewPainting::
	msgbox SilphCo_10F_Text_NewPainting, MSGBOX_SIGN
	end

SilphCo_10F_Text_NewPainting:
	.string "It's a gorgeous painting of a lush,\n"
	.string "verdant landscape at sunset.$"