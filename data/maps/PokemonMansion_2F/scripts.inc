.set LOCALID_MUK_MASTER, 5
.set TRAINER, VAR_0x8009

PokemonMansion_2F_MapScripts:: @ 8162254
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonMansion_2F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

PokemonMansion_2F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MUK
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq PokemonMansion_2F_MapScript_MukMasterMovementType
	end

PokemonMansion_2F_MapScript_MukMasterMovementType::
	setobjectmovementtype LOCALID_MUK_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

PokemonMansion_2F_OnLoad:: @ 816225A
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_2F
	end

PokemonMansion_2F_EventScript_Statue:: @ 8162264
	lockall
	setvar VAR_0x8004, 1
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_2F_EventScript_DiaryJuly5th:: @ 8162278
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th:: @ 8162281
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_Arnie:: @ 816228A
	trainerbattle_single TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat
	msgbox PokemonMansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end
