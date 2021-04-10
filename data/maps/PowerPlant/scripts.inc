.set LOCALID_VOLTORB_MASTER, 9
.set LOCALID_ZAPDOS_MASTER, 10
.set TRAINER, VAR_0x8009

PowerPlant_MapScripts:: @ 8163764
	map_script MAP_SCRIPT_ON_RESUME, PowerPlant_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_OnTransition
	.byte 0

PowerPlant_OnResume:: @ 816376F
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, PowerPlant_EventScript_TryRemoveStaticMon
	end

PowerPlant_EventScript_TryRemoveStaticMon:: @ 8163779
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

PowerPlant_OnTransition:: @ 816378D
	setworldmapflag FLAG_WORLD_MAP_POWER_PLANT
	call_if_set FLAG_FOUGHT_ZAPDOS, PowerPlant_EventScript_HideZapdos
	call_if_unset FLAG_FOUGHT_ZAPDOS, PowerPlant_EventScript_TryShowZapdos
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1, PowerPlant_EventScript_ShowElectrode1
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2, PowerPlant_EventScript_ShowElectrode2
	goto PowerPlant_MapScript_SetMasterTrainerMovementTypes
	end

PowerPlant_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_VOLTORB
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq PowerPlant_MapScript_VoltorbMasterMovementType
	setvar TRAINER, MASTER_ZAPDOS
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq PowerPlant_MapScript_ZapdosMasterMovementType
	end

PowerPlant_MapScript_VoltorbMasterMovementType::
	setobjectmovementtype LOCALID_VOLTORB_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

PowerPlant_MapScript_ZapdosMasterMovementType::
	setobjectmovementtype LOCALID_ZAPDOS_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

PowerPlant_EventScript_TryShowZapdos:: @ 81637AC
	goto_if_set FLAG_ZAPDOS_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_ZAPDOS
	return

PowerPlant_EventScript_HideZapdos::
	setflag FLAG_HIDE_ZAPDOS
	return

PowerPlant_EventScript_ShowElectrode1:: @ 81637B0
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_1
	return

PowerPlant_EventScript_ShowElectrode2:: @ 81637B4
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_2
	return

PowerPlant_EventScript_Zapdos:: @ 81637B8
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_ZAPDOS, 50, ITEM_NONE
	waitse
	playmoncry SPECIES_ZAPDOS, 2
	message Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PowerPlant_EventScript_DefeatedZapdos
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq PowerPlant_EventScript_RanFromZapdos
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq PowerPlant_EventScript_RanFromZapdos
	setflag FLAG_FOUGHT_ZAPDOS
	release
	end

PowerPlant_EventScript_DefeatedZapdos:: @ 816381B
	setflag FLAG_ZAPDOS_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto EventScript_MonFlewAway
	end

PowerPlant_EventScript_RanFromZapdos:: @ 8163824
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto EventScript_MonFlewAway
	end

PowerPlant_EventScript_Electrode1:: @ 816382F
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special QuestLog_CutRecording
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PowerPlant_EventScript_FoughtElectrode1
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq PowerPlant_EventScript_FoughtElectrode1
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq PowerPlant_EventScript_FoughtElectrode1
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	release
	end

PowerPlant_EventScript_FoughtElectrode1:: @ 8163884
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Electrode2:: @ 816388D
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special QuestLog_CutRecording
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PowerPlant_EventScript_FoughtElectrode2
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq PowerPlant_EventScript_FoughtElectrode2
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq PowerPlant_EventScript_FoughtElectrode2
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	release
	end

PowerPlant_EventScript_FoughtElectrode2:: @ 81638E2
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	goto EventScript_RemoveStaticMon
	end
