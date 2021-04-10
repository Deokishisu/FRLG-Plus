.set LOCALID_VULPIX_MASTER, 7
.set TRAINER, VAR_0x8009

Route6_MapScripts:: @ 8167FB1
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route6_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_VULPIX
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route6_MapScript_VulpixMasterMovementType
	end

Route6_MapScript_VulpixMasterMovementType::
	setobjectmovementtype LOCALID_VULPIX_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route6_EventScript_UndergroundPathSign:: @ 8167FB2
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end
