SilphCo_5F_MapScripts:: @ 81617BE
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad:: @ 81617C4
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	call_if_unset FLAG_HIDE_SAFFRON_CIVILIANS, SilphCo_5F_EventScript_ScientistMovementType
	end

SilphCo_5F_EventScript_ScientistMovementType::
	setobjectmovementtype 9, MOVEMENT_TYPE_WANDER_AROUND
	return

SilphCo_5F_EventScript_WorkerM:: @ 81617E0
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge SilphCo_5F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_5F_Text_RocketsInUproarAboutIntruder
	release
	end

SilphCo_5F_EventScript_WorkerMRocketsGone:: @ 81617F7
	msgbox SilphCo_5F_Text_YoureOurHeroThankYou
	release
	end

SilphCo_5F_EventScript_PokemonReport1:: @ 8161801
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2:: @ 816180A
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport3:: @ 8161813
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign:: @ 816181C
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_Beau:: @ 8161825
	trainerbattle_single TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt1:: @ 816183C
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat
	msgbox SilphCo_5F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt2:: @ 8161853
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat
	msgbox SilphCo_5F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Dalton:: @ 816186A
	trainerbattle_single TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_WorkerM2:: @ 8161770
	msgbox SilphCo_5F_Text_WorkerM2, MSGBOX_NPC
	end

SilphCo_5F_Text_WorkerM2:
	.string "Synergy!\n"
	.string "Disruption!\l"
	.string "Paradigm shift!$"

SilphCo_5F_EventScript_WorkerF:: @ 8161770
	msgbox SilphCo_5F_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_5F_Text_WorkerF:
	.string "Is it just me or is this guy\n"
	.string "not actually saying anything?$"

SilphCo_5F_EventScript_Scientist2:: @ 8161770
	msgbox SilphCo_5F_Text_Scientist2, MSGBOX_NPC
	end

SilphCo_5F_Text_Scientist2:
	.string "He-he's a visionary!\n"
	.string "I've got to take notes!$"