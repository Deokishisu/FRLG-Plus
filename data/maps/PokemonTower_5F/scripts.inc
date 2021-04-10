.set LOCALID_HYPNO_MASTER, 8
.set TRAINER, VAR_0x8009

PokemonTower_5F_MapScripts:: @ 8163432
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_5F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

PokemonTower_5F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_HYPNO
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq PokemonTower_5F_MapScript_HypnoMasterMovementType
	end

PokemonTower_5F_MapScript_HypnoMasterMovementType::
	setobjectmovementtype LOCALID_HYPNO_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

PokemonTower_5F_EventScript_Channeler:: @ 8163433
	msgbox PokemonTower_5F_Text_RestHereInPurifiedSpace, MSGBOX_NPC
	end

PokemonTower_5F_EventScript_PurifiedZone:: @ 816343C
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed
	setvar VAR_TEMP_1, 1
	releaseall
	end

PokemonTower_5F_EventScript_ExitPurifiedZone:: @ 8163453
	lockall
	setvar VAR_TEMP_1, 0
	releaseall
	end

PokemonTower_5F_EventScript_Tammy:: @ 816345B
	trainerbattle_single TRAINER_CHANNELER_TAMMY, PokemonTower_5F_Text_TammyIntro, PokemonTower_5F_Text_TammyDefeat
	msgbox PokemonTower_5F_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Ruth:: @ 8163472
	trainerbattle_single TRAINER_CHANNELER_RUTH, PokemonTower_5F_Text_RuthIntro, PokemonTower_5F_Text_RuthDefeat
	msgbox PokemonTower_5F_Text_RuthPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Karina:: @ 8163489
	trainerbattle_single TRAINER_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaIntro, PokemonTower_5F_Text_KarinaDefeat
	msgbox PokemonTower_5F_Text_KarinaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Janae:: @ 81634A0
	trainerbattle_single TRAINER_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeIntro, PokemonTower_5F_Text_JanaeDefeat
	msgbox PokemonTower_5F_Text_JanaePostBattle, MSGBOX_AUTOCLOSE
	end
