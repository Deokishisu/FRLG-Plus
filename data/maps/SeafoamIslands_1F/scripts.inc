.set LOCALID_SEEL_MASTER, 4
.set TRAINER, VAR_0x8009

SeafoamIslands_1F_MapScripts:: @ 8162F43
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_1F_OnTransition
	.byte 0

SeafoamIslands_1F_OnTransition:: @ 8162F49
	setworldmapflag FLAG_WORLD_MAP_SEAFOAM_ISLANDS_1F
	goto SeafoamIslands_1F_MapScript_SetMasterTrainerMovementTypes
	end

SeafoamIslands_1F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_SEEL
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq SeafoamIslands_1F_MapScript_SeelMasterMovementType
	end

SeafoamIslands_1F_MapScript_SeelMasterMovementType::
	setobjectmovementtype LOCALID_SEEL_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return
