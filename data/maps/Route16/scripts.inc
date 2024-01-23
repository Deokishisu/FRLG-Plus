.set LOCALID_PIDGEOTTO_MASTER, 11
.set LOCALID_SNORLAX_MASTER, 12
.set LOCALID_EEVEE_MASTER, 13
.set TRAINER, VAR_0x8009

Route16_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route16_EventScript_RemoveSnorlax
	end

Route16_EventScript_RemoveSnorlax::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

Route16_OnTransition::
	call_if_set FLAG_WOKE_UP_ROUTE_16_SNORLAX, Route16_EventScript_HideSnorlax
	call_if_unset FLAG_WOKE_UP_ROUTE_16_SNORLAX, Route16_EventScript_TryShowSnorlax
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route16_OnTransitionCyclingRoad
	goto Route16_MapScript_SetMasterTrainerMovementTypes
	end

Route16_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route16_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_PIDGEOTTO
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route16_MapScript_PidgeottoMasterMovementType
	setvar TRAINER, MASTER_SNORLAX
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route16_MapScript_SnorlaxMasterMovementType
	setvar TRAINER, MASTER_EEVEE
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route16_MapScript_EeveeMasterMovementType
	end

Route16_MapScript_PidgeottoMasterMovementType::
	setobjectmovementtype LOCALID_PIDGEOTTO_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return
	
Route16_MapScript_SnorlaxMasterMovementType::
	setobjectmovementtype LOCALID_SNORLAX_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route16_MapScript_EeveeMasterMovementType::
	setobjectmovementtype LOCALID_EEVEE_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route16_EventScript_HideSnorlax::
	setflag FLAG_HIDE_ROUTE_16_SNORLAX
	return

Route16_EventScript_TryShowSnorlax::
	goto_if_set FLAG_ROUTE_16_SNORLAX_RETURNED_TO_MOUNTAINS, EventScript_Return
	clearflag FLAG_HIDE_ROUTE_16_SNORLAX
	return

Route16_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route16_OnWarpCyclingRoad
	.2byte 0

Route16_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route16_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route16_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_16_SNORLAX
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route16_EventScript_FoughtSnorlax
	setflag FLAG_WOKE_UP_ROUTE_16_SNORLAX
	release
	end

Route16_EventScript_DontUsePokeFlute::
	release
	end

Route16_EventScript_FoughtSnorlax::
	setflag FLAG_ROUTE_16_SNORLAX_RETURNED_TO_MOUNTAINS
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route16_EventScript_SnorlaxNoPokeFlute::
	msgbox Route16_Text_MonSprawledOutInSlumber
	release
	end

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end
