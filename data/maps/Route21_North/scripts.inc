.set LOCALID_SLOWBRO_MASTER, 7
.set TRAINER, VAR_0x8009

Route21_North_MapScripts:: @ 8168289
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_North_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route21_North_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_SLOWBRO
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route21_North_MapScript_SlowbroMasterMovementType
	end

Route21_North_MapScript_SlowbroMasterMovementType::
	setobjectmovementtype LOCALID_SLOWBRO_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return
