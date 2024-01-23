.set LOCALID_SQUIRTLE_MASTER, 15
.set LOCALID_SEADRA_MASTER, 16
.set LOCALID_GOLDEEN_MASTER, 17
.set LOCALID_POLIWAG_MASTER, 18
.set TRAINER, VAR_0x8009

Route12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnTransition::
	call_if_set FLAG_WOKE_UP_ROUTE_12_SNORLAX, Route12_EventScript_HideSnorlax
	call_if_unset FLAG_WOKE_UP_ROUTE_12_SNORLAX, Route12_EventScript_TryShowSnorlax
	goto Route12_MapScript_SetMasterTrainerMovementTypes
	end

Route12_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_SQUIRTLE
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route12_MapScript_SquirtleMasterMovementType
	setvar TRAINER, MASTER_SEADRA
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route12_MapScript_SeadraMasterMovementType
	setvar TRAINER, MASTER_GOLDEEN
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route12_MapScript_GoldeenMasterMovementType
	setvar TRAINER, MASTER_POLIWAG
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route12_MapScript_PoliwagMasterMovementType
	end

Route12_MapScript_SquirtleMasterMovementType::
	setobjectmovementtype LOCALID_SQUIRTLE_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route12_MapScript_SeadraMasterMovementType::
	setobjectmovementtype LOCALID_SEADRA_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route12_MapScript_GoldeenMasterMovementType::
	setobjectmovementtype LOCALID_GOLDEEN_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route12_MapScript_PoliwagMasterMovementType::
	setobjectmovementtype LOCALID_POLIWAG_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route12_EventScript_HideSnorlax::
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	return

Route12_EventScript_TryShowSnorlax::
	goto_if_set FLAG_ROUTE_12_SNORLAX_RETURNED_TO_MOUNTAINS, EventScript_Return
	clearflag FLAG_HIDE_ROUTE_12_SNORLAX
	return

Route12_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_EventScript_TryRemoveSnorlax::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	setflag FLAG_ROUTE_12_SNORLAX_RETURNED_TO_MOUNTAINS
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end
