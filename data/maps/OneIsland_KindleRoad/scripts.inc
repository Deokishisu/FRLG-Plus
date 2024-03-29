OneIsland_KindleRoad_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, OneIsland_KindleRoad_OnResume
	map_script MAP_SCRIPT_ON_LOAD, OneIsland_KindleRoad_AshWeatherLoad
	.byte 0

OneIsland_KindleRoad_OnResume:
	setstepcallback STEP_CB_ASH
	end

OneIsland_KindleRoad_AshWeatherLoad:
	getplayerxy VAR_TEMP_1, VAR_RESULT
	goto_if_le VAR_RESULT, 60, OneIsland_KindleRoad_AshWeatherTrigger
	release
	end

OneIsland_KindleRoad_AshWeatherTrigger::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	release
	end

OneIsland_KindleRoad_DefaultWeatherTrigger::
	resetweather
	doweather
	release
	end

OneIsland_KindleRoad_EventScript_RouteSign::
	msgbox OneIsland_KindleRoad_Text_RouteSign, MSGBOX_SIGN
	end

OneIsland_KindleRoad_EventScript_EmberSpaSign::
	msgbox OneIsland_KindleRoad_Text_EmberSpaSign, MSGBOX_SIGN
	end

OneIsland_KindleRoad_EventScript_GlassWorkshopSign::
	msgbox OneIsland_KindleRoad_Text_GlassWorkshopSign, MSGBOX_SIGN
	end

OneIsland_KindleRoad_Text_GlassWorkshopSign:
	.string "GLASS WORKSHOP\n“Making Glass Items from Fallen Ash”$"
