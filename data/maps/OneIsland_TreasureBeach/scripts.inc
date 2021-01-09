OneIsland_TreasureBeach_MapScripts:: @ 816876B
	map_script MAP_SCRIPT_ON_RESUME, OneIsland_TreasureBeach_OnResume
	.byte 0

OneIsland_TreasureBeach_OnResume:
	setstepcallback STEP_CB_ASH
	end

OneIsland_TreasureBeach_EventScript_Boy:: @ 816876C
	msgbox OneIsland_TreasureBeach_Text_GoodThingsWashUpOnBeach, MSGBOX_NPC
	end
