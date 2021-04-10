.set LOCALID_RATTATA_MASTER, 11
.set LOCALID_ELECTABUZZ_MASTER, 12
.set LOCALID_CHARMELEON_MASTER, 13
.set LOCALID_ALAKAZAM_MASTER, 14
.set TRAINER, VAR_0x8009

Route10_MapScripts:: @ 8167FD9
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route10_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_RATTATA
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route10_MapScript_RattataMasterMovementType
	setvar TRAINER, MASTER_ELECTABUZZ
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route10_MapScript_ElectabuzzMasterMovementType
	setvar TRAINER, MASTER_CHARMELEON
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route10_MapScript_CharmeleonMasterMovementType
	setvar TRAINER, MASTER_ALAKAZAM
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route10_MapScript_AlakazamMasterMovementType
	end

Route10_MapScript_RattataMasterMovementType::
	setobjectmovementtype LOCALID_RATTATA_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route10_MapScript_ElectabuzzMasterMovementType::
	setobjectmovementtype LOCALID_ELECTABUZZ_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route10_MapScript_CharmeleonMasterMovementType::
	setobjectmovementtype LOCALID_CHARMELEON_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route10_MapScript_AlakazamMasterMovementType::
	setobjectmovementtype LOCALID_ALAKAZAM_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route10_EventScript_NorthRockTunnelSign:: @ 8167FDB
	msgbox Route10_Text_RockTunnelDetourToLavender, MSGBOX_SIGN
	end

Route10_EventScript_SouthRockTunnelSign:: @ 8167FE4
	msgbox Route10_Text_RockTunnel, MSGBOX_SIGN
	end

Route10_EventScript_PowerPlantSign:: @ 8167FED
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end
