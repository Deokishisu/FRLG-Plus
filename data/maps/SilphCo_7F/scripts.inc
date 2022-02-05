.set LOCALID_RIVAL,     1
.set LOCALID_WORKER_M2, 8

SilphCo_7F_MapScripts:: @ 8161984
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad:: @ 816198F
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition:: @ 81619AB
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	call_if_ge SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_SetObjRocketsGone:: @ 81619B7
	setobjectmovementtype LOCALID_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_RivalTriggerTop:: @ 81619BC
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom:: @ 81619C8
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene:: @ 81619D4
	textcolor 0
	playbgm MUS_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_RIVAL, Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	applymovement LOCALID_RIVAL, Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	compare VAR_TEMP_1, 0
	call_if_eq SilphCo_7F_EventScript_RivalApproachTop
	compare VAR_TEMP_1, 1
	call_if_eq SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
	compare VAR_STARTER_MON, 2
	call_if_eq SilphCo_7F_EventScript_RivalSquirtle
	compare VAR_STARTER_MON, 1
	call_if_eq SilphCo_7F_EventScript_RivalBulbasaur
	compare VAR_STARTER_MON, 0
	call_if_eq SilphCo_7F_EventScript_RivalCharmander
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RIVAL_EXIT, 0
	compare VAR_TEMP_1, 0
	call_if_eq SilphCo_7F_EventScript_RivalExitTop
	compare VAR_TEMP_1, 1
	call_if_eq SilphCo_7F_EventScript_RivalExitBottom
	call SilphCo_7F_EventScript_RivalGivesLinkBracelet
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	waitse
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop:: @ 8161A73
	closemessage
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalApproachBottom:: @ 8161A7F
	return

SilphCo_7F_EventScript_RivalSquirtle:: @ 8161A80
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalBulbasaur:: @ 8161A8B
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalCharmander:: @ 8161A96
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop:: @ 8161AA1
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestRight
    waitmovement 0
	return

SilphCo_7F_EventScript_RivalExitBottom:: @ 8161AAC
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestUp
    waitmovement 0
	return

SilphCo_7F_Movement_RivalApproachTop:: @ 8161AB7
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop:: @ 8161AB9
	walk_right
	walk_right
	walk_right
	delay_16
	face_left
	delay_16
	walk_left
	walk_up
	walk_left
	step_end

SilphCo_7F_Movement_RivalExitBottom:: @ 8161ABF
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	delay_16
	face_left
	delay_16
	walk_left
	walk_left
	face_down
	step_end

SilphCo_7F_EventScript_LaprasGuy:: @ 8161AC8
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq SilphCo_7F_EventScript_ReceiveLaprasParty
	compare VAR_RESULT, 1
	goto_if_eq SilphCo_7F_EventScript_ReceiveLaprasPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

SilphCo_7F_EventScript_ReceiveLaprasParty:: @ 8161B12
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_LAPRAS
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_NicknameLaprasParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SilphCo_7F_EventScript_EndReceiveLapras
CeladonCity_Condominiums_RoofRoom_EventScript_NicknameLaprasParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_ReceiveLaprasPC:: @ 8161B45
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_LAPRAS
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_NicknameLaprasPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SilphCo_7F_EventScript_LaprasTransferredToPC
CeladonCity_Condominiums_RoofRoom_EventScript_NicknameLaprasPC::
	call EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
	end

SilphCo_7F_EventScript_LaprasTransferredToPC:: @ 8161B73
	call EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_EndReceiveLapras:: @ 8161B7E
	textcolor 0
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_AlreadyGotLapras:: @ 8161B8D
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_WorkerM1:: @ 8161B97
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone:: @ 8161BAE
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2:: @ 8161BB8
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone:: @ 8161BCF
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF:: @ 8161BD9
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone:: @ 8161BF0
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign:: @ 8161BFA
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua:: @ 8161C03
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1:: @ 8161C1A
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2:: @ 8161C31
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3:: @ 8161C48
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_RivalGivesLinkBracelet::
	msgbox SilphCo_7F_EventScript_RivalGivesLinkBracelet_Text_0
	giveitem_msg SilphCo_7F_EventScript_RivalGivesLinkBracelet_Text_1, ITEM_LINK_BRACELET, 1, MUS_OBTAIN_KEY_ITEM
	msgbox SilphCo_7F_EventScript_RivalGivesLinkBracelet_Text_2
	closemessage
	compare VAR_TEMP_1, 0
	call_if_eq SilphCo_7F_EventScript_RivalToWarpTileTop
	compare VAR_TEMP_1, 1
	call_if_eq SilphCo_7F_EventScript_RivalToWarpTileBottom
	return

SilphCo_7F_EventScript_RivalToWarpTileTop:
	applymovement 1, Movement_RivalToWarpTileTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalToWarpTileBottom:
	applymovement 1, Movement_RivalToWarpTileBottom
	waitmovement 0
	return

Movement_RivalToWarpTileTop:
	walk_right
	walk_right
	delay_16
	step_end

Movement_RivalToWarpTileBottom:
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

SilphCo_7F_EventScript_RivalGivesLinkBracelet_Text_0:
	.string "Oh, yeah, right.\pYou're so far behind me now that\nthis probably won't matter but…\pI found a pair of bracelets that\ncan evolve certain POKéMON, but\lthey barely work unless you give\lone to someone else.\pHere, {PLAYER}. I feel sorry for\nyou, so you can have this.$"

SilphCo_7F_EventScript_RivalGivesLinkBracelet_Text_1:
	.string "{PLAYER} received a LINK BRACELET\nfrom {RIVAL}!$"

SilphCo_7F_EventScript_RivalGivesLinkBracelet_Text_2:
	.string "All right, I'm really going this\ntime. Smell ya!$"

SilphCo_7F_EventScript_WorkerBro:: @ 8161770
	msgbox SilphCo_7F_Text_WorkerBro, MSGBOX_NPC
	end

SilphCo_7F_Text_WorkerBro:
	.string "I am one of the four SILPH\n"
    .string "BROTHERS!\p"
	.string "I make sure the company servers\n"
	.string "are working properly!$"

SilphCo_7F_EventScript_WorkerFPhone:: @ 8161770
	lock
	msgbox SilphCo_7F_Text_WorkerFPhone
	release
	msgbox SilphCo_7F_Text_WorkerFPhone2, MSGBOX_NPC
	turnobject 13, DIR_NORTH
	end

SilphCo_7F_Text_WorkerFPhone:
	.string "Have you tried doing what I\n"
    .string "suggested earlier?\p"
	.string "I'm telling you it'd work.\n"
	.string "Okay, call me back.$"

SilphCo_7F_Text_WorkerFPhone2:
	.string "My coworker downstairs asks\n"
	.string "me for help all the time.\p"
	.string "I usually figure out the\n"
	.string "solution pretty quickly…\p"
	.string "But does he ever listen to\n"
	.string "me the first time?\p"
	.string "No!\n"
	.string "Of course not!$"

SilphCo_7F_EventScript_Painting::
	goto_if_unset FLAG_HIDE_SAFFRON_CIVILIANS, SilphCo_7F_EventScript_NewPainting
	msgbox Text_Painting, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_NewPainting::
	msgbox SilphCo_7F_Text_NewPainting, MSGBOX_SIGN
	end

SilphCo_7F_Text_NewPainting:
	.string "It's a gorgeous painting of a bird\n"
	.string "POKéMON darting between the trees.$"