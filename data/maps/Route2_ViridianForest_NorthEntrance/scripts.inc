.set LOCALID_BUTTERFREE_MASTER, 4
.set TRAINER, VAR_0x8009

Route2_ViridianForest_NorthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_ViridianForest_NorthEntrance_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route2_ViridianForest_NorthEntrance_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_BUTTERFREE
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route2_ViridianForest_NorthEntrance_MapScript_ButterfreeMasterMovementType
	end

Route2_ViridianForest_NorthEntrance_MapScript_ButterfreeMasterMovementType::
	setobjectmovementtype LOCALID_BUTTERFREE_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route2_ViridianForest_NorthEntrance_EventScript_Youngster::
	msgbox Route2_ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests, MSGBOX_NPC
	end

Route2_ViridianForest_NorthEntrance_EventScript_OldMan::
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees, MSGBOX_NPC
	end

Route2_ViridianForest_NorthEntrance_EventScript_CooltrainerF::
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCancelEvolution, MSGBOX_NPC
	end
