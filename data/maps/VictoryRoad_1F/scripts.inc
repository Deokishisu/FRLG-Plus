.set LOCALID_GRAVELER_MASTER, 8
.set TRAINER, VAR_0x8009

VictoryRoad_1F_MapScripts:: @ 8160F05
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnLoad:: @ 8160F10
	compare VAR_MAP_SCENE_VICTORY_ROAD_1F, 100
	call_if_ne VictoryRoad_1F_EventScript_SetRockBarrier
	call_if_eq VictoryRoad_1F_EventScript_MoveSwitchBoulder
	end

VictoryRoad_1F_EventScript_SetRockBarrier:: @ 8160F1C
	setmetatile 12, 14, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 15, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_1F_EventScript_MoveSwitchBoulder::
	setobjectxyperm 5, 20, 16
	end

VictoryRoad_1F_OnTransition:: @ 8160F2F
	setworldmapflag FLAG_WORLD_MAP_VICTORY_ROAD_1F
	goto VictoryRoad_1F_MapScript_SetMasterTrainerMovementTypes
	end

VictoryRoad_1F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_GRAVELER
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq VictoryRoad_1F_MapScript_GravelerMasterMovementType
	end

VictoryRoad_1F_MapScript_GravelerMasterMovementType::
	setobjectmovementtype LOCALID_GRAVELER_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

VictoryRoad_1F_EventScript_FloorSwitch:: @ 8160F33
	lockall
	compare VAR_MAP_SCENE_VICTORY_ROAD_1F, 100
	goto_if_eq VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 14, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 15, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	moveobjectoffscreen 5
	setvar VAR_MAP_SCENE_VICTORY_ROAD_1F, 100
	releaseall
	end

VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed:: @ 8160F62
	releaseall
	end

VictoryRoad_1F_EventScript_Naomi:: @ 8160F64
	trainerbattle_single TRAINER_COOLTRAINER_NAOMI, VictoryRoad_1F_Text_NaomiIntro, VictoryRoad_1F_Text_NaomiDefeat
	msgbox VictoryRoad_1F_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Rolando:: @ 8160F7B
	trainerbattle_single TRAINER_COOLTRAINER_ROLANDO, VictoryRoad_1F_Text_RolandoIntro, VictoryRoad_1F_Text_RolandoDefeat
	msgbox VictoryRoad_1F_Text_RolandoPostBattle, MSGBOX_AUTOCLOSE
	end
