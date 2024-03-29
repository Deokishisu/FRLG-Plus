.set LOCALID_LAPRAS_MASTER, 7
.set TRAINER, VAR_0x8009

PokemonTower_4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_4F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

PokemonTower_4F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_LAPRAS
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, PokemonTower_4F_MapScript_LaprasMasterMovementType
	end

PokemonTower_4F_MapScript_LaprasMasterMovementType::
	setobjectmovementtype LOCALID_LAPRAS_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

PokemonTower_4F_EventScript_Paula::
	trainerbattle_single TRAINER_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaIntro, PokemonTower_4F_Text_PaulaDefeat
	msgbox PokemonTower_4F_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Laurel::
	trainerbattle_single TRAINER_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelIntro, PokemonTower_4F_Text_LaurelDefeat
	msgbox PokemonTower_4F_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Jody::
	trainerbattle_single TRAINER_CHANNELER_JODY, PokemonTower_4F_Text_JodyIntro, PokemonTower_4F_Text_JodyDefeat
	msgbox PokemonTower_4F_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end
