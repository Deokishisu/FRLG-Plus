.set LOCALID_DUGTRIO_MASTER, 1
.set TRAINER, VAR_0x8009

DiglettsCave_B1F_MapScripts:: @ 8160EF1
	map_script MAP_SCRIPT_ON_TRANSITION, DiglettsCave_B1F_OnTransition
	.byte 0

DiglettsCave_B1F_OnTransition:: @ 8160EF7
	setworldmapflag FLAG_WORLD_MAP_DIGLETTS_CAVE_B1F
	goto DiglettsCave_B1F_MapScript_SetMasterTrainerMovementTypes
	end

DiglettsCave_B1F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_DUGTRIO
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq DiglettsCave_B1F_MapScript_DugtrioMasterMovementType
	end

DiglettsCave_B1F_MapScript_DugtrioMasterMovementType::
	setobjectmovementtype LOCALID_DUGTRIO_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return