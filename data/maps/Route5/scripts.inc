.set LOCALID_MANKEY_MASTER, 1
.set LOCALID_BURGLAR, 2
.set TRAINER, VAR_0x8009

Route5_MapScripts:: @ 8167FA7
	map_script MAP_SCRIPT_ON_TRANSITION, Route5_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route5_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MANKEY
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route5_MapScript_MankeyMasterMovementType
	end

Route5_MapScript_MankeyMasterMovementType::
	setobjectmovementtype LOCALID_MANKEY_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

Route5_EventScript_UndergroundPathSign:: @ 8167FA8
	msgbox Route5_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route5_EventScript_Burglar::
	lock
	faceplayer
	message Route5_Text_Burglar
	waitmessage
	playbgm MUS_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_BURGLAR_HECKEL, Route5_Text_BurglarDefeat
	msgbox Route5_Text_BurglarHaveChikorita
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 15, ITEM_MIRACLE_SEED
	compare VAR_RESULT, 0
	goto_if_eq Route5_EventScript_ReceiveChikoritaParty
	compare VAR_RESULT, 1
	goto_if_eq Route5_EventScript_ReceiveChikoritaPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

Route5_EventScript_ReceiveChikoritaParty::
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message Route5_Text_ObtainedChikorita
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_CHIKORITA
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq Route5_EventScript_NicknameChikoritaParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route5_EventScript_EndReceiveChikorita
	Route5_EventScript_NicknameChikoritaParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto Route5_EventScript_EndReceiveChikorita
	end

Route5_EventScript_ReceiveChikoritaPC::
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message Route5_Text_ObtainedChikorita
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_CHIKORITA
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq Route5_EventScript_NicknameChikoritaPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route5_EventScript_ChikoritaTransferredToPC
	Route5_EventScript_NicknameChikoritaPC::
	call EventScript_NameReceivedBoxMon
	goto Route5_EventScript_ChikoritaTransferredToPC
	end

Route5_EventScript_ChikoritaTransferredToPC::
	call EventScript_TransferredToPC
	goto Route5_EventScript_EndReceiveChikorita
	end

Route5_EventScript_EndReceiveChikorita::
	textcolor 0 
	msgbox Route5_Text_BurglarGottaGo
	closeonkeypress
	setflag FLAG_GOT_CHIKORITA
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_BURGLAR
	fadescreen FADE_FROM_BLACK
	release
	end