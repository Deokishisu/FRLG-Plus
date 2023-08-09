.set LOCALID_TREECKO, 1

ViridianForestDepths_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForestDepths_OnTransition
	.byte 0	
	
	ViridianForestDepths_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end
	
ViridianForestDepths_EventScript_WelcomeSign1::
	msgbox ViridianForestDepths_Text_WelcomeSign1, MSGBOX_SIGN
	end

ViridianForestDepths_EventScript_WelcomeSign2::
	msgbox ViridianForestDepths_Text_WelcomeSign2, MSGBOX_SIGN
	end

ViridianForestDepths_EventScript_GraveSign::
	msgbox ViridianForestDepths_Text_GraveSign, MSGBOX_SIGN
	end
	
ViridianForestDepths_EventScript_GraveTextSign::
	msgbox ViridianForestDepths_Text_GraveTextSign, MSGBOX_SIGN
	end

ViridianForestDepths_EventScript_Treecko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TREECKO, 11
	msgbox ViridianForestDepths_Text_TreeckoNoise
	waitmoncry
	msgbox ViridianForestDepths_Text_TreeckoStuck, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ViridianForestDepths_EventScript_TreeckoHappy
	waitse
	playmoncry SPECIES_TREECKO, 5
	waitmoncry
	msgbox ViridianForestDepths_Text_TreeckoSad
	release
	end
	
ViridianForestDepths_EventScript_TreeckoHappy::
	delay 120
	applymovement LOCALID_TREECKO, ViridianForestDepths_Movement_TreeckoJump
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	waitse
	playmoncry SPECIES_TREECKO, 0
	waitmoncry
	msgbox ViridianForestDepths_Text_TreeckoHappy
	goto_if_eq ViridianForestDepths_EventScript_GiveTreecko
	release
	end	
	
ViridianForestDepths_EventScript_GiveTreecko::
	setvar VAR_TEMP_1, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 5, ITEM_SITRUS_BERRY
	compare VAR_RESULT, 0
	goto_if_eq ViridianForestDepths_EventScript_ReceiveTreeckoParty
	compare VAR_RESULT, 1
	goto_if_eq ViridianForestDepths_EventScript_ReceiveTreeckoPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

ViridianForestDepths_EventScript_ReceiveTreeckoParty::
	removeobject LOCALID_TREECKO
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message ViridianForestDepths_Text_ObtainedTreecko
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_TREECKO
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq ViridianForestDepths_EventScript_NicknameTreeckoParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ViridianForestDepths_EventScript_EndReceiveTreecko
	ViridianForestDepths_EventScript_NicknameTreeckoParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto ViridianForestDepths_EventScript_EndReceiveTreecko
	end

ViridianForestDepths_EventScript_ReceiveTreeckoPC::
	removeobject LOCALID_TREECKO
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message ViridianForestDepths_Text_ObtainedTreecko
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_TREECKO
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq ViridianForestDepths_EventScript_NicknameTreeckoPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ViridianForestDepths_EventScript_TreeckoTransferredToPC
	ViridianForestDepths_EventScript_NicknameTreeckoPC::
	call EventScript_NameReceivedBoxMon
	goto ViridianForestDepths_EventScript_TreeckoTransferredToPC
	end

ViridianForestDepths_EventScript_TreeckoTransferredToPC::
	call EventScript_TransferredToPC
	goto ViridianForestDepths_EventScript_EndReceiveTreecko
	end
	
ViridianForestDepths_EventScript_EndReceiveTreecko::
	setflag FLAG_GOT_TREECKO
	release
	end
	
ViridianForestDepths_Movement_TreeckoJump::
	jump_in_place_down
	jump_in_place_down
	step_end