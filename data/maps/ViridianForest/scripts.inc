.set LOCALID_PIKACHU_MASTER, 12
.set LOCALID_WEEDLE_MASTER, 13
.set LOCALID_GRUNT, 14
.set LOCALID_TORCHIC, 15
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

ViridianForest_EventScript_Torchic::
	lock
	faceplayer
	call_if_set FLAG_BEAT_VIRIDIAN_GRUNT, ViridianForest_EventScript_ObtainTorchic
	waitse
	playmoncry SPECIES_TORCHIC, 2
	msgbox ViridianForest_Text_TorchicNoise
	waitmoncry
	msgbox ViridianForest_Text_TorchicScared
	release
	end
	
ViridianForest_EventScript_ObtainTorchic::
	waitse
	playmoncry SPECIES_TORCHIC, 0
	waitmoncry
	msgbox ViridianForest_Text_TorchicSaved, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ViridianForest_EventScript_GiveTorchic
	msgbox ViridianForest_Text_TorchicSad
	release
	end
	
ViridianForest_EventScript_GiveTorchic::
	setvar VAR_TEMP_1, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 5, ITEM_SITRUS_BERRY
	compare VAR_RESULT, 0
	goto_if_eq ViridianForest_EventScript_ReceiveTorchicParty
	compare VAR_RESULT, 1
	goto_if_eq ViridianForest_EventScript_ReceiveTorchicPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

ViridianForest_EventScript_ReceiveTorchicParty::
	removeobject LOCALID_TORCHIC
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message ViridianForest_Text_ObtainedTorchic
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_TORCHIC
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq ViridianForest_EventScript_NicknameTorchicParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ViridianForest_EventScript_EndReceiveTorchic
	ViridianForest_EventScript_NicknameTorchicParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto ViridianForest_EventScript_EndReceiveTorchic
	end

ViridianForest_EventScript_ReceiveTorchicPC::
	removeobject LOCALID_TORCHIC
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message ViridianForest_Text_ObtainedTorchic
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_TORCHIC
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq ViridianForest_EventScript_NicknameTorchicPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ViridianForest_EventScript_TorchicTransferredToPC
	ViridianForest_EventScript_NicknameTorchicPC::
	call EventScript_NameReceivedBoxMon
	goto ViridianForest_EventScript_TorchicTransferredToPC
	end

ViridianForest_EventScript_TorchicTransferredToPC::
	call EventScript_TransferredToPC
	goto ViridianForest_EventScript_EndReceiveTorchic
	end
	
ViridianForest_EventScript_EndReceiveTorchic::
	setflag FLAG_GOT_TORCHIC
	release
	end
	
	ViridianForest_EventScript_Grunt::
	lock
	faceplayer
	message ViridianForest_Text_Grunt
	waitmessage
	playbgm MUS_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNTILDA, ViridianForest_Text_GruntDefeat
	msgbox ViridianForest_Text_GruntLeave
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GRUNT
	fadescreen FADE_FROM_BLACK
	setflag FLAG_BEAT_VIRIDIAN_GRUNT
	release
	end