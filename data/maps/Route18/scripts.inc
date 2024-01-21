.set LOCALID_CATERPIE_MASTER, 4
.set LOCALID_FEAROW_MASTER, 5
.set LOCALID_RHYHORN_MASTER, 6
.set TRAINER, VAR_0x8009

Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition::
	compare VAR_MAP_SCENE_ROUTE16, 1
	call_if_eq Route18_OnTransitionCyclingRoad
	goto Route18_MapScript_SetMasterTrainerMovementTypes
	end

Route18_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_CATERPIE
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route18_MapScript_CaterpieMasterMovementType
	setvar TRAINER, MASTER_FEAROW
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route18_MapScript_FearowMasterMovementType
	setvar TRAINER, MASTER_RHYHORN
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route18_MapScript_RhyhornMasterMovementType
	end

Route18_MapScript_CaterpieMasterMovementType::
	setobjectmovementtype LOCALID_CATERPIE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return
	
Route18_MapScript_FearowMasterMovementType::
	setobjectmovementtype LOCALID_FEAROW_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route18_MapScript_RhyhornMasterMovementType::
	setobjectmovementtype LOCALID_RHYHORN_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route18_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route18_OnWarpCyclingRoad
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end
