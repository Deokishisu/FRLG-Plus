CeruleanCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_1F_OnTransition
	.byte 0

CeruleanCave_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CAVE_1F
	setescapewarp MAP_CERULEAN_CITY, 255, 1, 13
	end
