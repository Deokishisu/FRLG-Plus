.set LOCALID_LATI, 1

SouthernIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SouthernIsland_Interior_OnLoad
	.byte 0

SouthernIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveLati
	end

SouthernIsland_Interior_EventScript_TryRemoveLati::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject LOCALID_LATI
	return

SouthernIsland_Interior_OnLoad:
	callnative IsVersionFireRedToVarResult
	compare VAR_RESULT, TRUE
	call_if_eq SouthernIsland_Interior_EventScript_SetUpLatios
	compare VAR_RESULT, FALSE
	call_if_eq SouthernIsland_Interior_EventScript_SetUpLatias
	end

SouthernIsland_Interior_EventScript_SetUpLatios::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LATIOS
	setvar VAR_TEMP_4, SPECIES_LATIOS
	return

SouthernIsland_Interior_EventScript_SetUpLatias::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LATIAS
	setvar VAR_TEMP_4, SPECIES_LATIAS
	return

SouthernIsland_Interior_EventScript_TryLatiEncounter::
	lockall
	setvar VAR_0x8008, 12
	goto SouthernIsland_Interior_EventScript_Lati
	end

SouthernIsland_Interior_EventScript_Lati::
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_Sign
	callnative IsVersionFireRedToVarResult
	compare VAR_RESULT, TRUE
	call_if_eq SouthernIsland_Interior_EventScript_CheckDefeatedLatios
	compare VAR_RESULT, FALSE
	call_if_eq SouthernIsland_Interior_EventScript_CheckDefeatedLatias
	callnative IsVersionFireRedToVarResult
	compare VAR_RESULT, TRUE
	call_if_eq SouthernIsland_Interior_EventScript_CheckCaughtLatios
	compare VAR_RESULT, FALSE
	call_if_eq SouthernIsland_Interior_EventScript_CheckCaughtLatias
	setflag FLAG_TEMP_2
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, 0
	delay 30
	waitmoncry
	addobject LOCALID_LATI
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement LOCALID_LATI, SouthernIsland_Interior_Movement_LatiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, LOCALID_LATI
	callnative IsVersionFireRedToVarResult
	compare VAR_RESULT, TRUE
	call_if_eq SouthernIsland_Interior_EventScript_SetLatiosBattleVars
	compare VAR_RESULT, FALSE
	call_if_eq SouthernIsland_Interior_EventScript_SetLatiasBattleVars
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartSouthernIslandBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SouthernIsland_Interior_EventScript_LatiDefeated
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SouthernIsland_Interior_EventScript_RanFromLati
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SouthernIsland_Interior_EventScript_RanFromLati
	callnative IsVersionFireRedToVarResult
	compare VAR_RESULT, TRUE
	call_if_eq SouthernIsland_Interior_EventScript_SetCaughtLatios
	compare VAR_RESULT, FALSE
	call_if_eq SouthernIsland_Interior_EventScript_SetCaughtLatias
	releaseall
	end

SouthernIsland_Interior_EventScript_CheckDefeatedLatios::
	goto_if_set FLAG_DEFEATED_LATIOS, SouthernIsland_Interior_EventScript_Sign
	return

SouthernIsland_Interior_EventScript_CheckDefeatedLatias::
	goto_if_set FLAG_DEFEATED_LATIAS, SouthernIsland_Interior_EventScript_Sign
	return

SouthernIsland_Interior_EventScript_SetCaughtLatios::
	setflag FLAG_CAUGHT_LATIOS
	return

SouthernIsland_Interior_EventScript_SetCaughtLatias::
	setflag FLAG_CAUGHT_LATIAS
	return

SouthernIsland_Interior_EventScript_CheckCaughtLatios::
	goto_if_set FLAG_CAUGHT_LATIOS, SouthernIsland_Interior_EventScript_Sign
	return

SouthernIsland_Interior_EventScript_CheckCaughtLatias::
	goto_if_set FLAG_CAUGHT_LATIAS, SouthernIsland_Interior_EventScript_Sign
	return

SouthernIsland_Interior_EventScript_LatiDefeated::
	callnative IsVersionFireRedToVarResult
	compare VAR_RESULT, TRUE
	call_if_eq SouthernIsland_Interior_EventScript_SetDefeatedLatios
	compare VAR_RESULT, FALSE
	call_if_eq SouthernIsland_Interior_EventScript_SetDefeatedLatias
	copyvar VAR_0x8004, VAR_TEMP_4
	goto EventScript_MonFlewAway
	end

SouthernIsland_Interior_EventScript_SetDefeatedLatios::
	setflag FLAG_DEFEATED_LATIOS
	return

SouthernIsland_Interior_EventScript_SetDefeatedLatias::
	setflag FLAG_DEFEATED_LATIAS
	return

SouthernIsland_Interior_EventScript_RanFromLati::
	copyvar VAR_0x8004, VAR_TEMP_4
	goto EventScript_MonFlewAway
	end

SouthernIsland_Interior_EventScript_Sign::
	signmsg
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_SIGN
	normalmsg
	releaseall
	end

SouthernIsland_Interior_EventScript_SetLatiosBattleVars::
	setvar VAR_0x8004, SPECIES_LATIOS
	setvar VAR_0x8005, 50 @ level
	setvar VAR_0x8006, ITEM_SOUL_DEW
	special CreateEventLegalEnemyMon
	return

SouthernIsland_Interior_EventScript_SetLatiasBattleVars::
	setvar VAR_0x8004, SPECIES_LATIAS
	setvar VAR_0x8005, 50 @ level
	setvar VAR_0x8006, ITEM_SOUL_DEW
	special CreateEventLegalEnemyMon
	return

SouthernIsland_Interior_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_up
	step_end

SouthernIsland_Interior_Movement_LatiApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SouthernIsland_Interior_Text_Sign:
	.string "“All dreams are but another reality.\n"
	.string "Never forget…”$"