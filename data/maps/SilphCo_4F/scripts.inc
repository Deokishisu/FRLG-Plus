.set LOCALID_MACHOP_MASTER, 13
.set TRAINER, VAR_0x8009

SilphCo_4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_4F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_4F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

SilphCo_4F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MACHOP
	callnative ShouldChangeMasterTrainerMovementType
	end

SilphCo_4F_MapScript_MachopMasterMovementType::
	setobjectmovementtype LOCALID_MACHOP_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

SilphCo_4F_OnLoad::
	call_if_unset FLAG_SILPH_4F_DOOR_1, EventScript_Close4FDoor1
SilphCo_4F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_4F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_4F_Text_CantYouSeeImHiding
	release
	end

SilphCo_4F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_4F_Text_TeamRocketIsGone
	release
	end

SilphCo_4F_EventScript_FloorSign::
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_EventScript_Rodney::
	trainerbattle_single TRAINER_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneyIntro, SilphCo_4F_Text_RodneyDefeat
	msgbox SilphCo_4F_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_26, SilphCo_4F_Text_Grunt1Intro, SilphCo_4F_Text_Grunt1Defeat
	msgbox SilphCo_4F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_27, SilphCo_4F_Text_Grunt2Intro, SilphCo_4F_Text_Grunt2Defeat
	msgbox SilphCo_4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_BaldingMan::
	msgbox SilphCo_4F_Text_BaldingMan, MSGBOX_NPC
	end

SilphCo_4F_Text_BaldingMan:
	.string "My office mate brings the most\n"
	.string "disgusting-smelling food.\p"
	.string "I wish she would take her lunch\n"
	.string "break somewhere else.$"

SilphCo_4F_EventScript_WorkerF::
	msgbox SilphCo_4F_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_4F_Text_WorkerF:
	.string "Between you and me, I'm trying\n"
	.string "to impress my office mate.\p"
	.string "He's due for a promotion, and I\n"
	.string "want to be the first one he thinks\l"
	.string "to promote!$"

SilphCo_4F_EventScript_WorkerM2::
	msgbox SilphCo_4F_Text_WorkerM2, MSGBOX_NPC
	end

SilphCo_4F_Text_WorkerM2:
	.string "I'm on my break, kid.\n"
	.string "I can't give you a tour now.$"

SilphCo_4F_EventScript_Scientist::
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
