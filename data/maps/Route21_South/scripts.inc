.set LOCALID_SLOWPOKE_MASTER, 6
.set LOCALID_PSYDUCK_MASTER, 7
.set TRAINER, VAR_0x8009

Route21_South_MapScripts:: @ 816828A
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_South_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route21_South_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_SLOWPOKE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route21_South_MapScript_SlowpokeMasterMovementType
	setvar TRAINER, MASTER_PSYDUCK
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route21_South_MapScript_PsyduckMasterMovementType
	end

Route21_South_MapScript_SlowpokeMasterMovementType::
	setobjectmovementtype LOCALID_SLOWPOKE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route21_South_MapScript_PsyduckMasterMovementType::
	setobjectmovementtype LOCALID_PSYDUCK_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return
