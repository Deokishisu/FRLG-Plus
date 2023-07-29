.set LOCALID_GEODUDE_MASTER, 11
.set TRAINER, VAR_0x8009

RockTunnel_1F_MapScripts:: @ 8162DD6
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition
	.byte 0

RockTunnel_1F_OnTransition:: @ 8162DDC
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	goto RockTunnel_1F_MapScript_SetMasterTrainerMovementTypes
	end

RockTunnel_1F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_GEODUDE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq RockTunnel_1F_MapScript_GeodudeMasterMovementType
	end

RockTunnel_1F_MapScript_GeodudeMasterMovementType::
	setobjectmovementtype LOCALID_GEODUDE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

RockTunnel_1F_EventScript_RouteSign:: @ 8162DE0
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny:: @ 8162DE9
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver:: @ 8162E00
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas:: @ 8162E17
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton:: @ 8162E2E
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah:: @ 8162E45
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana:: @ 8162E5C
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Dana:: @ 8162E73
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Guy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_CHARMANDER_FROM_GUY, RockTunnel_1F_EventScript_AlreadyGotCharmander
	release
	end

RockTunnel_1F_EventScript_WantCharmander::
	msgbox RockTunnel_1F_Text_WantThisCharmander, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RockTunnel_1F_EventScript_GiveCharmander
	msgbox RockTunnel_1F_Text_Oh
	release
	end

RockTunnel_1F_EventScript_GiveCharmander::
	setvar VAR_TEMP_1, SPECIES_CHARMANDER
	givemon SPECIES_CHARMANDER, 20, ITEM_FIRE_STONE
	compare VAR_RESULT, 0
	goto_if_eq RockTunnel_1F_EventScript_ReceiveCharmanderParty
	compare VAR_RESULT, 1
	goto_if_eq RockTunnel_1F_EventScript_ReceiveCharmanderPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

RockTunnel_1F_EventScript_ReceiveCharmanderParty::
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message RockTunnel_1F_Text_ObtainedCharmanderFromGuy
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_CHARMANDER
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq RockTunnel_1F_EventScript_NicknameCharmanderParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RockTunnel_1F_EventScript_EndReceiveCharmander
	RockTunnel_1F_EventScript_NicknameCharmanderParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto RockTunnel_1F_EventScript_EndReceiveCharmander
	end

RockTunnel_1F_EventScript_ReceiveCharmanderPC::
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message RockTunnel_1F_Text_ObtainedCharmanderFromGuy
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_CHARMANDER
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq RockTunnel_1F_EventScript_NicknameCharmanderPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RockTunnel_1F_EventScript_CharmanderTransferredToPC
	RockTunnel_1F_EventScript_NicknameCharmanderPC::
	call EventScript_NameReceivedBoxMon
	goto RockTunnel_1F_EventScript_CharmanderTransferredToPC
	end

RockTunnel_1F_EventScript_CharmanderTransferredToPC::
	call EventScript_TransferredToPC
	goto RockTunnel_1F_EventScript_EndReceiveCharmander
	end

RockTunnel_1F_EventScript_EndReceiveCharmander::
	textcolor 0
	msgbox RockTunnel_1F_Text_TreatHimRight
	setflag FLAG_GOT_CHARMANDER_FROM_GUY
	release
	end

RockTunnel_1F_EventScript_AlreadyGotCharmander::
	msgbox RockTunnel_1F_Text_HowIsCharmander
	release
	end