.set LOCALID_PIKACHU_MASTER, 12
.set LOCALID_WEEDLE_MASTER, 13
.set TRAINER, VAR_0x8009

ViridianForest_MapScripts:: @ 816051F
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition:: @ 8160525
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	goto ViridianForest_MapScript_SetMasterTrainerMovementTypes
	end

ViridianForest_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_PIKACHU
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq ViridianForest_MapScript_PikachuMasterMovementType
	setvar TRAINER, MASTER_WEEDLE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq ViridianForest_MapScript_WeedleMasterMovementType
	end

ViridianForest_MapScript_PikachuMasterMovementType::
	setobjectmovementtype LOCALID_PIKACHU_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

ViridianForest_MapScript_WeedleMasterMovementType::
	setobjectmovementtype LOCALID_WEEDLE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

ViridianForest_EventScript_Youngster:: @ 8160529
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy:: @ 8160532
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1:: @ 816053B
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2:: @ 8160544
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3:: @ 816054D
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4:: @ 8160556
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5:: @ 816055F
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign:: @ 8160568
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick:: @ 8160571
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug:: @ 8160588
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy:: @ 816059F
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony:: @ 81605B6
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie:: @ 81605CD
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end
