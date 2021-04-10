.set LOCALID_MACHOP_MASTER, 13
.set TRAINER, VAR_0x8009

SilphCo_4F_MapScripts:: @ 8161736
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_4F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_4F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

SilphCo_4F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MACHOP
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq SilphCo_4F_MapScript_MachopMasterMovementType
	end

SilphCo_4F_MapScript_MachopMasterMovementType::
	setobjectmovementtype LOCALID_MACHOP_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

SilphCo_4F_OnLoad:: @ 816173C
	call_if_unset FLAG_SILPH_4F_DOOR_1, EventScript_Close4FDoor1
	call_if_unset FLAG_SILPH_4F_DOOR_2, EventScript_Close4FDoor2
	end

SilphCo_4F_EventScript_WorkerM:: @ 816174F
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge SilphCo_4F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_4F_Text_CantYouSeeImHiding
	release
	end

SilphCo_4F_EventScript_WorkerMRocketsGone:: @ 8161766
	msgbox SilphCo_4F_Text_TeamRocketIsGone
	release
	end

SilphCo_4F_EventScript_FloorSign:: @ 8161770
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_EventScript_Rodney:: @ 8161779
	trainerbattle_single TRAINER_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneyIntro, SilphCo_4F_Text_RodneyDefeat
	msgbox SilphCo_4F_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt1:: @ 8161790
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_26, SilphCo_4F_Text_Grunt1Intro, SilphCo_4F_Text_Grunt1Defeat
	msgbox SilphCo_4F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt2:: @ 81617A7
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_27, SilphCo_4F_Text_Grunt2Intro, SilphCo_4F_Text_Grunt2Defeat
	msgbox SilphCo_4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_BaldingMan:: @ 8161770
	msgbox SilphCo_4F_Text_BaldingMan, MSGBOX_NPC
	end

SilphCo_4F_Text_BaldingMan:
	.string "My office mate brings the most\n"
	.string "disgusting-smelling food.\p"
	.string "I wish she would take her lunch\n"
	.string "break somewhere else.$"

SilphCo_4F_EventScript_WorkerF:: @ 8161770
	msgbox SilphCo_4F_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_4F_Text_WorkerF:
	.string "Between you and me, I'm trying\n"
	.string "to impress my office mate.\p"
	.string "He's due for a promotion, and I\n"
	.string "want to be the first one he thinks\l"
	.string "to promote!$"

SilphCo_4F_EventScript_WorkerM2:: @ 8161770
	msgbox SilphCo_4F_Text_WorkerM2, MSGBOX_NPC
	end

SilphCo_4F_Text_WorkerM2:
	.string "I'm on my break, kid.\n"
	.string "I can't give you a tour now.$"

SilphCo_4F_EventScript_Scientist:: @ 8161770
	msgbox SilphCo_4F_Text_Scientist, MSGBOX_NPC
	end

SilphCo_4F_Text_Scientist:
	.string "What? Why are you looking at\n"
	.string "me like that?\p"
	.string "There was a TEAM ROCKET SCIENTIST\n"
	.string "in here during the takeover?\p"
	.string "Well, I'm obviously not him.\n"
	.string "We must look completely different.$"

SilphCo_4F_EventScript_Painting::
	goto_if_unset FLAG_HIDE_SAFFRON_CIVILIANS, SilphCo_4F_EventScript_NewPainting
	msgbox Text_Painting, MSGBOX_SIGN
	end

SilphCo_4F_EventScript_NewPainting::
	msgbox SilphCo_4F_Text_NewPainting, MSGBOX_SIGN
	end

SilphCo_4F_Text_NewPainting:
	.string "It's a gorgeous painting of a POKéMON\n"
	.string "swimming in an underwater paradise.$"
