.set LOCALID_MUDKIP, 1

MtMoon_Square_MapScripts::
	.byte 0

MtMoon_Square_EventScript_WelcomeSign::
	msgbox MtMoon_Square_Text_Sign, MSGBOX_SIGN
	end

MtMoon_Square_EventScript_MudkipStand::
	lock
	faceplayer
	playmoncry SPECIES_MUDKIP, 2
	textcolor 2
	msgbox MtMoon_Square_Text_MudkipNoise
	waitmoncry
	release
	end

MtMoon_Square_EventScript_Mudkip::
	lockall
	applymovement LOCALID_MUDKIP, MtMoon_Square_Movement_MudkipExclamation
	waitmovement 0
	applymovement LOCALID_MUDKIP, MtMoon_Square_Movement_MudkipJump3times
	waitmovement 0
	waitse
	playmoncry SPECIES_MUDKIP, 2
	textcolor 2
	msgbox MtMoon_Square_Text_MudkipNoise
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipAngryFood, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MtMoon_Square_EventScript_MudkipGiveBerry
	waitse
	playmoncry SPECIES_MUDKIP, 2
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipStillAngry
	releaseall
	end
	
MtMoon_Square_EventScript_MudkipGiveBerry::
	checkitem ITEM_SITRUS_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MtMoon_Square_EventScript_MudkipHappy
	waitse
	playmoncry SPECIES_MUDKIP, 2
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipStillAngry
	releaseall
	end

MtMoon_Square_EventScript_MudkipHappy::
	removeitem ITEM_SITRUS_BERRY, 1
	applymovement LOCALID_MUDKIP, MtMoon_Square_Movement_MudkipJump2times
	waitse
	playmoncry SPECIES_MUDKIP, 2
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipHappyJoin, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MtMoon_Square_EventScript_GiveMudkip
	waitse
	playmoncry SPECIES_MUDKIP, 11
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipSad
	releaseall
	end
	
MtMoon_Square_EventScript_GiveMudkip::
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 5, ITEM_SOFT_SAND
	compare VAR_RESULT, 0
	goto_if_eq MtMoon_Square_EventScript_ReceiveMudkipParty
	compare VAR_RESULT, 1
	goto_if_eq MtMoon_Square_EventScript_ReceiveMudkipPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

MtMoon_Square_EventScript_ReceiveMudkipParty::
	removeobject LOCALID_MUDKIP
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message MtMoon_Square_Text_ObtainedMudkip
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_MUDKIP
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq MtMoon_Square_EventScript_NicknameMudkipParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtMoon_Square_EventScript_EndReceiveMudkip
	MtMoon_Square_EventScript_NicknameMudkipParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto MtMoon_Square_EventScript_EndReceiveMudkip
	end

MtMoon_Square_EventScript_ReceiveMudkipPC::
	removeobject LOCALID_MUDKIP
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message MtMoon_Square_Text_ObtainedMudkip
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_MUDKIP
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq MtMoon_Square_EventScript_NicknameMudkipPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtMoon_Square_EventScript_MudkipTransferredToPC
	MtMoon_Square_EventScript_NicknameMudkipPC::
	call EventScript_NameReceivedBoxMon
	goto MtMoon_Square_EventScript_MudkipTransferredToPC
	end

MtMoon_Square_EventScript_MudkipTransferredToPC::
	call EventScript_TransferredToPC
	goto MtMoon_Square_EventScript_EndReceiveMudkip
	end
	
MtMoon_Square_EventScript_EndReceiveMudkip::
	setflag FLAG_GOT_MUDKIP
	release
	end
	
MtMoon_Square_Movement_MudkipExclamation::
	emote_exclamation_mark
	step_end
	
MtMoon_Square_Movement_MudkipJump3times::
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	step_end
	
MtMoon_Square_Movement_MudkipJump2times::
	jump_in_place_down
	jump_in_place_down
	step_end