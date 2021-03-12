PokemonCenter_1F_OnLoad::
	callnative ShouldSpawnSoftlockClerk
	goto_if_unset FLAG_SYS_POKEDEX_GET, PokemonCenter_1F_OnLoad_2
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenter_1F_OnLoad_2
PokemonCenter_1F_OnLoad_1:
	goto_if_set FLAG_SYS_NATIONAL_DEX, PokemonCenter_1F_OnLoad_7
	goto_if_unset FLAG_SYS_RECEIVED_EXTENDED_DEX, PokemonCenter_1F_OnLoad_7
	callnative HasNationalMonToVarResult
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenter_1F_OnLoad_12
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne PokemonCenter_1F_OnLoad_15
	release
	end

PokemonCenter_1F_OnLoad_2:
	setflag FLAG_TEMP_8
	goto PokemonCenter_1F_OnLoad_1

PokemonCenter_1F_OnLoad_7:
	setvar VAR_TEMP_0, 1
	release
	end

PokemonCenter_1F_OnLoad_12:
	setvar VAR_TEMP_0, 1
	release
	end

PokemonCenter_1F_OnLoad_15:
	callnative CoordsOfPMCExitWarpTo80068007
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, VAR_0x8006
	goto_if_eq PokemonCenter_1F_OnLoad_19
PokemonCenter_1F_OnLoad_17:
	release
	end

PokemonCenter_1F_OnLoad_18:
	goto PokemonCenter_1F_OnLoad_17

PokemonCenter_1F_OnLoad_19:
	compare VAR_0x8009, VAR_0x8007
	goto_if_eq PokemonCenter_1F_OnLoad_18
	goto PokemonCenter_1F_OnLoad_17

NationalDexAideEvent::
	callnative HasNationalMonToVarResult
	compare VAR_RESULT, 0
	goto_if_eq NationalDexAideEvent_2
	goto_if_set FLAG_SYS_NATIONAL_DEX, NationalDexAideEvent_5
	goto_if_unset FLAG_SYS_RECEIVED_EXTENDED_DEX, NationalDexAideEvent_5
	callnative HideWarpArrowSprite
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, NationalDexAideEvent_Movement_BackStep
	waitmovement 0
	playse SE_EXIT
	getplayerxy VAR_0x8008, VAR_0x8009
	addvar VAR_0x8009, 1
	setobjectxyperm 2, VAR_0x8008, VAR_0x8009
	addobject 2
	applymovement 2, Movement_WalkInPlaceFastestUp
	waitmovement 0
	textcolor 0
	msgbox NationalDexAideEvent_Text_0
	closemessage
	textcolor 3
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox NationalDexAideEvent_Text_1
	closemessage
	applymovement 2, Movement_WalkInPlaceFastestDown
	waitmovement 0
	textcolor 0
	msgbox NationalDexAideEvent_Text_2
	applymovement 2, Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox NationalDexAideEvent_Text_3
	closemessage
	applymovement 2, Movement_WalkInPlaceFastestUp
	waitmovement 0
	playfanfare MUS_OBTAIN_KEY_ITEM
	textcolor 3
	message PalletTown_ProfessorOaksLab_Text_PlayersPokedexWasUpgraded
	waitmessage
	waitfanfare
	closemessage
	textcolor 0
	special EnableNationalPokedex
	msgbox NationalDexAideEvent_Text_4
	closemessage
	delay 20
	playse SE_EXIT
	applymovement 2, Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 5
	removeobject 2
	setvar VAR_TEMP_0, 1
	releaseall
	end

NationalDexAideEvent_2:
	setvar VAR_TEMP_0, 1
	release
	end

NationalDexAideEvent_5:
	setvar VAR_TEMP_0, 1
	release
	end

NationalDexAideEvent_Movement_BackStep:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

NationalDexAideEvent_Text_0:
	.string "{PLAYER}! Hi!\nI've been looking for you!\pRemember me?\nI'm one of PROF. OAK'S AIDES.\pPROF. OAK has improved the\nPOKéDEX again and I'm supposed\lto upgrade yours.\pCan I see your POKéDEX?$"

NationalDexAideEvent_Text_1:
	.string "The AIDE took your POKéDEX\nunit.$"

NationalDexAideEvent_Text_2:
	.string "… … …  … … …\p… … …  … … …$"

NationalDexAideEvent_Text_3:
	.string "…And that's done!\pNow this unit can record data on\na lot more POKéMON.\pHere you go!$"

NationalDexAideEvent_Text_4:
	.string "Keep catching POKéMON to fill up\nyour improved POKéDEX!\pI better get back to the LAB.\nSee you, {PLAYER}!$"
