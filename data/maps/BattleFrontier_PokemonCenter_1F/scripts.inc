BattleFrontier_PokemonCenter_1F_MapScripts:: @ 816C5EC
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PokemonCenter_1F_OnLoad
	//map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:: @ 816C5F7
	setrespawn SPAWN_BATTLE_FRONTIER
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse:: @ 816C5FB
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end