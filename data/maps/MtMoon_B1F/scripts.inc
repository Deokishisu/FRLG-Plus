.set LOCALID_CLEFABLE_MASTER, 1
.set TRAINER, VAR_0x8009

MtMoon_B1F_MapScripts:: @ 8160698
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B1F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

MtMoon_B1F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_CLEFABLE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq MtMoon_B1F_MapScript_ClefableMasterMovementType
	end

MtMoon_B1F_MapScript_ClefableMasterMovementType::
	setobjectmovementtype LOCALID_CLEFABLE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return