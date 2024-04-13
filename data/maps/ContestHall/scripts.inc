ContestHall_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ContestHall_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ContestHall_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, ContestHall_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ContestHall_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, ContestHall_OnReturn
	.byte 0

ContestHall_OnReturn:
	special LoadLinkContestPlayerPalettes
	end

ContestHall_OnTransition:
	call ContestHall_EventScript_ReadyContestMusic
	setvar VAR_TEMP_0, 1
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	call_if_eq ContestHall_EventScript_AddRandomAudienceMembersLink
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	call_if_ne ContestHall_EventScript_AddRandomAudienceMembers
	end

ContestHall_EventScript_SetCategoryTiles:
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, ContestHall_EventScript_EventScript_SetCoolTiles
	case CONTEST_CATEGORY_BEAUTY, ContestHall_EventScript_EventScript_SetBeautyTiles
	case CONTEST_CATEGORY_CUTE, ContestHall_EventScript_EventScript_SetCuteTiles
	case CONTEST_CATEGORY_SMART, ContestHall_EventScript_EventScript_SetSmartTiles
	case CONTEST_CATEGORY_TOUGH, ContestHall_EventScript_EventScript_SetToughTiles
	return

ContestHall_EventScript_EventScript_SetCoolTiles:
	@ floor decoration
	setmetatile 7, 5, 0x322, 0
	setmetatile 7, 6, 0x32A, 0
	@top stair
	setmetatile 6, 8, 0x33B, 0
	setmetatile 7, 8, 0x33C, 0
	setmetatile 8, 8, 0x33D, 0
	@bottom stairs
	setmetatile 6, 9, 0x343, 0
	setmetatile 6, 10, 0x343, 0
	setmetatile 7, 9, 0x344, 0
	setmetatile 7, 10, 0x344, 0
	setmetatile 8, 9, 0x345, 0
	setmetatile 8, 10, 0x345, 0
	return

ContestHall_EventScript_EventScript_SetBeautyTiles:
	@ floor decoration
	setmetatile 7, 5, 0x311, 0
	setmetatile 7, 6, 0x319, 0
	@top stair
	setmetatile 6, 8, 0x2FB, 0
	setmetatile 7, 8, 0x2FC, 0
	setmetatile 8, 8, 0x2FD, 0
	@bottom stairs
	setmetatile 6, 9, 0x303, 0
	setmetatile 6, 10, 0x303, 0
	setmetatile 7, 9, 0x304, 0
	setmetatile 7, 10, 0x304, 0
	setmetatile 8, 9, 0x305, 0
	setmetatile 8, 10, 0x305, 0
	return

ContestHall_EventScript_EventScript_SetCuteTiles:
	@ floor decoration
	setmetatile 7, 5, 0x312, 0
	setmetatile 7, 6, 0x31A, 0
	@top stair
	setmetatile 6, 8, 0x32B, 0
	setmetatile 7, 8, 0x32C, 0
	setmetatile 8, 8, 0x32D, 0
	@bottom stairs
	setmetatile 6, 9, 0x333, 0
	setmetatile 6, 10, 0x333, 0
	setmetatile 7, 9, 0x334, 0
	setmetatile 7, 10, 0x334, 0
	setmetatile 8, 9, 0x335, 0
	setmetatile 8, 10, 0x335, 0
	return

ContestHall_EventScript_EventScript_SetSmartTiles:
	@ floor decoration
	setmetatile 7, 5, 0x321, 0
	setmetatile 7, 6, 0x329, 0
	@top stair
	setmetatile 6, 8, 0x30B, 0
	setmetatile 7, 8, 0x30C, 0
	setmetatile 8, 8, 0x30D, 0
	@bottom stairs
	setmetatile 6, 9, 0x313, 0
	setmetatile 6, 10, 0x313, 0
	setmetatile 7, 9, 0x314, 0
	setmetatile 7, 10, 0x314, 0
	setmetatile 8, 9, 0x315, 0
	setmetatile 8, 10, 0x315, 0
	return

ContestHall_EventScript_EventScript_SetToughTiles:
	@ floor decoration
	setmetatile 7, 5, 0x331, 0
	setmetatile 7, 6, 0x339, 0
	@top stair
	setmetatile 6, 8, 0x31B, 0
	setmetatile 7, 8, 0x31C, 0
	setmetatile 8, 8, 0x31D, 0
	@bottom stairs
	setmetatile 6, 9, 0x323, 0
	setmetatile 6, 10, 0x323, 0
	setmetatile 7, 9, 0x324, 0
	setmetatile 7, 10, 0x324, 0
	setmetatile 8, 9, 0x325, 0
	setmetatile 8, 10, 0x325, 0
	return

ContestHall_EventScript_ReadyContestMusic::
	call ContestHall_EventScript_TryWaitForLink
	special GetContestMultiplayerId
	call_if_eq VAR_RESULT, 0, ContestHall_EventScript_SaveContestMusicPlayer1
	call_if_eq VAR_RESULT, 1, ContestHall_EventScript_SaveContestMusicPlayer2
	call_if_eq VAR_RESULT, 2, ContestHall_EventScript_SaveContestMusicPlayer3
	call_if_eq VAR_RESULT, 3, ContestHall_EventScript_SaveContestMusicPlayer4
	call_if_eq VAR_RESULT, 4, ContestHall_EventScript_SaveContestMusic
	return

ContestHall_EventScript_SaveContestMusicPlayer1::
	savebgm MUS_LINK_CONTEST_P1
	return

ContestHall_EventScript_SaveContestMusicPlayer2::
	savebgm MUS_LINK_CONTEST_P2
	return

ContestHall_EventScript_SaveContestMusicPlayer3::
	savebgm MUS_LINK_CONTEST_P3
	return

ContestHall_EventScript_SaveContestMusicPlayer4::
	savebgm MUS_LINK_CONTEST_P4
	return

ContestHall_EventScript_SaveContestMusic::
	savebgm MUS_CONTEST
	return

ContestHall_OnResume:
	call_if_eq VAR_TEMP_9, 1, ContestHall_EventScript_ReShowAudience
	end

ContestHall_EventScript_ReShowAudience::
	call ContestHall_EventScript_CreateAudience
	return

ContestHall_OnFrame:
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_Contest
	.2byte 0

ContestHall_OnWarp:
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_SetContestObjects
	.2byte 0

ContestHall_EventScript_Contest::
	call ContestHall_EventScript_DoContest
	call ContestHall_EventScript_SetExitWarp
	end

ContestHall_EventScript_SetContestObjects::
	special LoadLinkContestPlayerPalettes
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	goto_if_eq ContestHall_EventScript_SetContestObjectsLink
	call ContestHall_EventScript_CreateAudience
	call ContestHall_EventScript_SetCategoryTiles
	end

ContestHall_EventScript_SetContestObjectsLink::
	call ContestHall_EventScript_CreateAudienceLink
	call ContestHall_EventScript_SetCategoryTiles
	end

ContestHall_EventScript_CreateAudienceLink::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_CreateWirelessContestAudienceLink
	switch VAR_CONTEST_TYPE
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_CreateNormalContestAudienceLink
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_CreateSuperContestAudienceLink
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_CreateHyperContestAudienceLink
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_CreateMasterContestAudienceLink
	case CONTEST_TYPE_LINK, ContestHall_EventScript_CreateMasterContestAudienceLink
	return

ContestHall_EventScript_CreateNormalContestAudienceLink::
	createvobject OBJ_EVENT_GFX_Z_RS_NINJA_BOY, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_CreateSuperContestAudienceLink::
	createvobject OBJ_EVENT_GFX_Z_RS_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_SCIENTIST_1, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_LITTLE_GIRL, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_LASS, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_CreateHyperContestAudienceLink::
	createvobject OBJ_EVENT_GFX_Z_RS_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_GENTLEMAN, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_EXPERT_F, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_MAN_2, 20, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_5, 20, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_SCIENTIST_1, 24, 8, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_GENTLEMAN, 24, 11, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_LITTLE_BOY, 25, 3, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_FAT_MAN, 27, 5, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
	return

ContestHall_EventScript_CreateMasterContestAudienceLink::
	createvobject OBJ_EVENT_GFX_Z_RS_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_MANIAC, 4, 1, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_5, 6, 1, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_4, 7, 1, 6, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_FISHERMAN, 14, 13, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_MAN_4, 17, 13, 6, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_CAMPER, 21, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_MAN_3, 22, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_SAILOR, 25, 3, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_GENTLEMAN, 27, 5, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_Z_RS_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
	return

ContestHall_EventScript_CreateWirelessContestAudienceLink::
	createvobject OBJ_EVENT_GFX_Z_RS_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_MANIAC, 4, 1, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_5, 6, 1, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_4, 7, 1, 6, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_Z_RS_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_FISHERMAN, 14, 13, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_MAN_4, 17, 13, 6, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_Z_RS_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_CAMPER, 21, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_MAN_3, 22, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_Z_RS_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_AddRandomAudienceMembersLink::
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_Z_RS_ARTIST
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_Z_RS_RUNNING_TRIATHLETE_F
	setvar VAR_OBJ_GFX_ID_D, OBJ_EVENT_GFX_Z_RS_CONTEST_JUDGE
	call ContestHall_EventScript_GetRandomAudienceGfxIdLink
	call ContestHall_EventScript_SetRandomAudienceGfx
	goto_if_lt VAR_TEMP_0, 8, ContestHall_EventScript_AddRandomAudienceMembersLink
	return

ContestHall_EventScript_GetRandomAudienceGfxIdLink::
	setvar VAR_RESULT, 32
	special GenerateContestRand
	addvar VAR_RESULT, 1
	switch VAR_RESULT
	case 1, ContestHall_EventScript_RandomAudienceNinjaBoyLink
	case 2, ContestHall_EventScript_RandomAudienceTwinLink
	case 3, ContestHall_EventScript_RandomAudienceBoy1Link
	case 4, ContestHall_EventScript_RandomAudienceGirl1Link
	case 5, ContestHall_EventScript_RandomAudienceGirl2Link
	case 6, ContestHall_EventScript_RandomAudienceLittleBoyLink
	case 7, ContestHall_EventScript_RandomAudienceGirlLink
	case 8, ContestHall_EventScript_RandomAudienceBoy3Link
	case 9, ContestHall_EventScript_RandomAudienceGirl3Link
	case 10, ContestHall_EventScript_RandomAudienceRichBoyLink
	case 11, ContestHall_EventScript_RandomAudienceFatManLink
	case 12, ContestHall_EventScript_RandomAudiencePokefanFLink
	case 13, ContestHall_EventScript_RandomAudienceMan1Link
	case 14, ContestHall_EventScript_RandomAudienceWoman2Link
	case 15, ContestHall_EventScript_RandomAudienceExpertMLink
	case 16, ContestHall_EventScript_RandomAudienceExpertFLink
	case 17, ContestHall_EventScript_RandomAudiencePokefanMLink
	case 18, ContestHall_EventScript_RandomAudienceWoman4Link
	case 19, ContestHall_EventScript_RandomAudienceCookLink
	case 20, ContestHall_EventScript_RandomAudienceLassLink
	case 21, ContestHall_EventScript_RandomAudienceOldWomanLink
	case 22, ContestHall_EventScript_RandomAudienceCamperLink
	case 23, ContestHall_EventScript_RandomAudiencePicnickerLink
	case 24, ContestHall_EventScript_RandomAudienceMan3Link
	case 25, ContestHall_EventScript_RandomAudienceWoman5Link
	case 26, ContestHall_EventScript_RandomAudienceYoungsterLink
	case 27, ContestHall_EventScript_RandomAudienceBugCatcherLink
	case 28, ContestHall_EventScript_RandomAudiencePsychicMLink
	case 29, ContestHall_EventScript_RandomAudienceSchoolKidMLink
	case 30, ContestHall_EventScript_RandomAudienceBlackBeltLink
	case 31, ContestHall_EventScript_RandomAudienceBeautyLink
	case 32, ContestHall_EventScript_RandomAudienceScientist1Link
	end

ContestHall_EventScript_RandomAudienceNinjaBoyLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_NINJA_BOY
	return

ContestHall_EventScript_RandomAudienceTwinLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_TWIN
	return

ContestHall_EventScript_RandomAudienceBoy1Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_BOY_1
	return

ContestHall_EventScript_RandomAudienceGirl1Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_GIRL_1
	return

ContestHall_EventScript_RandomAudienceGirl2Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_GIRL_2
	return

ContestHall_EventScript_RandomAudienceLittleBoyLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_LITTLE_BOY
	return

ContestHall_EventScript_RandomAudienceGirlLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_LITTLE_GIRL
	return

ContestHall_EventScript_RandomAudienceBoy3Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_BOY_3
	return

ContestHall_EventScript_RandomAudienceGirl3Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_GIRL_3
	return

ContestHall_EventScript_RandomAudienceRichBoyLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_RICH_BOY
	return

ContestHall_EventScript_RandomAudienceFatManLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_FAT_MAN
	return

ContestHall_EventScript_RandomAudiencePokefanFLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_POKEFAN_F
	return

ContestHall_EventScript_RandomAudienceMan1Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_MAN_1
	return

ContestHall_EventScript_RandomAudienceWoman2Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_WOMAN_2
	return

ContestHall_EventScript_RandomAudienceExpertMLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_EXPERT_M
	return

ContestHall_EventScript_RandomAudienceExpertFLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_EXPERT_F
	return

ContestHall_EventScript_RandomAudiencePokefanMLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_POKEFAN_M
	return

ContestHall_EventScript_RandomAudienceWoman4Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_WOMAN_4
	return

ContestHall_EventScript_RandomAudienceCookLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_COOK
	return

ContestHall_EventScript_RandomAudienceLassLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_LASS
	return

ContestHall_EventScript_RandomAudienceOldWomanLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_OLD_WOMAN
	return

ContestHall_EventScript_RandomAudienceCamperLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_CAMPER
	return

ContestHall_EventScript_RandomAudiencePicnickerLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_PICNICKER
	return

ContestHall_EventScript_RandomAudienceMan3Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_MAN_3
	return

ContestHall_EventScript_RandomAudienceWoman5Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_WOMAN_5
	return

ContestHall_EventScript_RandomAudienceYoungsterLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_YOUNGSTER
	return

ContestHall_EventScript_RandomAudienceBugCatcherLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_BUG_CATCHER
	return

ContestHall_EventScript_RandomAudiencePsychicMLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_PSYCHIC_M
	return

ContestHall_EventScript_RandomAudienceSchoolKidMLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_SCHOOL_KID_M
	return

ContestHall_EventScript_RandomAudienceBlackBeltLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_BLACK_BELT
	return

ContestHall_EventScript_RandomAudienceBeautyLink::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_BEAUTY
	return

ContestHall_EventScript_RandomAudienceScientist1Link::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_Z_RS_SCIENTIST_1
	return

@ There are 8 audience member object events, 7 of which are given random gfx below (the 8th is the Artist)
@ The rest of the audience is created statically by ContestHall_EventScript_CreateAudience
ContestHall_EventScript_AddRandomAudienceMembers::
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_PAINTER
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_WORKER_F
	setvar VAR_OBJ_GFX_ID_D, OBJ_EVENT_GFX_CONTEST_JUDGE
	call ContestHall_EventScript_GetRandomAudienceGfxId
	call ContestHall_EventScript_SetRandomAudienceGfx
	goto_if_lt VAR_TEMP_0, 8, ContestHall_EventScript_AddRandomAudienceMembers
	return

ContestHall_EventScript_SetRandomAudienceGfx::
	switch VAR_TEMP_0
	case 1, ContestHall_EventScript_SetRandomAudience1
	case 2, ContestHall_EventScript_SetRandomAudience2
	case 3, ContestHall_EventScript_SetRandomAudience3
	case 4, ContestHall_EventScript_SetRandomAudience4
	case 5, ContestHall_EventScript_SetRandomAudience5
	case 6, ContestHall_EventScript_SetRandomAudience6
	case 7, ContestHall_EventScript_SetRandomAudience7
	end

ContestHall_EventScript_SetRandomAudience1::
	copyvar VAR_OBJ_GFX_ID_4, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience2::
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience3::
	copyvar VAR_OBJ_GFX_ID_6, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience4::
	copyvar VAR_OBJ_GFX_ID_7, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience5::
	copyvar VAR_OBJ_GFX_ID_8, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience6::
	copyvar VAR_OBJ_GFX_ID_9, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience7::
	copyvar VAR_OBJ_GFX_ID_A, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_GetRandomAudienceGfxId::
	setvar VAR_RESULT, 32
	special GenerateContestRand
	addvar VAR_RESULT, 1
	switch VAR_RESULT
	case 1, ContestHall_EventScript_RandomAudienceNinjaBoy
	case 2, ContestHall_EventScript_RandomAudienceTwin
	case 3, ContestHall_EventScript_RandomAudienceBoy1
	case 4, ContestHall_EventScript_RandomAudienceGirl1
	case 5, ContestHall_EventScript_RandomAudienceGirl2
	case 6, ContestHall_EventScript_RandomAudienceLittleBoy
	case 7, ContestHall_EventScript_RandomAudienceGirl
	case 8, ContestHall_EventScript_RandomAudienceBoy3
	case 9, ContestHall_EventScript_RandomAudienceGirl3
	case 10, ContestHall_EventScript_RandomAudienceRichBoy
	case 11, ContestHall_EventScript_RandomAudienceFatMan
	case 12, ContestHall_EventScript_RandomAudiencePokefanF
	case 13, ContestHall_EventScript_RandomAudienceMan1
	case 14, ContestHall_EventScript_RandomAudienceWoman2
	case 15, ContestHall_EventScript_RandomAudienceExpertM
	case 16, ContestHall_EventScript_RandomAudienceExpertF
	case 17, ContestHall_EventScript_RandomAudiencePokefanM
	case 18, ContestHall_EventScript_RandomAudienceWoman4
	case 19, ContestHall_EventScript_RandomAudienceCook
	case 20, ContestHall_EventScript_RandomAudienceLass
	case 21, ContestHall_EventScript_RandomAudienceOldWoman
	case 22, ContestHall_EventScript_RandomAudienceCamper
	case 23, ContestHall_EventScript_RandomAudiencePicnicker
	case 24, ContestHall_EventScript_RandomAudienceMan3
	case 25, ContestHall_EventScript_RandomAudienceWoman5
	case 26, ContestHall_EventScript_RandomAudienceYoungster
	case 27, ContestHall_EventScript_RandomAudienceBugCatcher
	case 28, ContestHall_EventScript_RandomAudiencePsychicM
	case 29, ContestHall_EventScript_RandomAudienceSchoolKidM
	case 30, ContestHall_EventScript_RandomAudienceBlackBelt
	case 31, ContestHall_EventScript_RandomAudienceBeauty
	case 32, ContestHall_EventScript_RandomAudienceScientist1
	end

ContestHall_EventScript_RandomAudienceNinjaBoy::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_JUGGLER
	return

ContestHall_EventScript_RandomAudienceTwin::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_TWIN
	return

ContestHall_EventScript_RandomAudienceBoy1::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_TAMER
	return

ContestHall_EventScript_RandomAudienceGirl1::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_1
	return

ContestHall_EventScript_RandomAudienceGirl2::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_2
	return

ContestHall_EventScript_RandomAudienceLittleBoy::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_BOY
	return

ContestHall_EventScript_RandomAudienceGirl::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_GIRL
	return

ContestHall_EventScript_RandomAudienceBoy3::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN
	return

ContestHall_EventScript_RandomAudienceGirl3::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BATTLE_GIRL
	return

ContestHall_EventScript_RandomAudienceRichBoy::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BIRD_KEEPER
	return

ContestHall_EventScript_RandomAudienceFatMan::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_FAT_MAN
	return

ContestHall_EventScript_RandomAudiencePokefanF::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_3
	return

ContestHall_EventScript_RandomAudienceMan1::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BALDING_MAN
	return

ContestHall_EventScript_RandomAudienceWoman2::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_AROMA_LADY
	return

ContestHall_EventScript_RandomAudienceExpertM::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_OLD_MAN_1
	return

ContestHall_EventScript_RandomAudienceExpertF::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_OLD_WOMAN
	return

ContestHall_EventScript_RandomAudiencePokefanM::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BALDING_MAN
	return

ContestHall_EventScript_RandomAudienceWoman4::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEMON_BREEDER
	return

ContestHall_EventScript_RandomAudienceCook::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_CHEF
	return

ContestHall_EventScript_RandomAudienceLass::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LASS
	return

ContestHall_EventScript_RandomAudienceOldWoman::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_YOUNG_COUPLE_F
	return

ContestHall_EventScript_RandomAudienceCamper::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_CAMPER
	return

ContestHall_EventScript_RandomAudiencePicnicker::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PICNICKER
	return

ContestHall_EventScript_RandomAudienceMan3::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_COOLTRAINER_M
	return

ContestHall_EventScript_RandomAudienceWoman5::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_COOLTRAINER_F
	return

ContestHall_EventScript_RandomAudienceYoungster::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_YOUNGSTER
	return

ContestHall_EventScript_RandomAudienceBugCatcher::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BUG_CATCHER
	return

ContestHall_EventScript_RandomAudiencePsychicM::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PSYCHIC_M
	return

ContestHall_EventScript_RandomAudienceSchoolKidM::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_ENGINEER
	return

ContestHall_EventScript_RandomAudienceBlackBelt::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BLACKBELT
	return

ContestHall_EventScript_RandomAudienceBeauty::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BEAUTY
	return

ContestHall_EventScript_RandomAudienceScientist1::
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCIENTIST
	return

ContestHall_EventScript_CreateAudience::
	specialvar VAR_RESULT, IsWirelessContest
	goto_if_eq VAR_RESULT, TRUE, ContestHall_EventScript_CreateWirelessContestAudience
	switch VAR_CONTEST_TYPE
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_CreateNormalContestAudience
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_CreateSuperContestAudience
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_CreateHyperContestAudience
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_CreateMasterContestAudience
	case CONTEST_TYPE_LINK, ContestHall_EventScript_CreateMasterContestAudience
	return

ContestHall_EventScript_CreateNormalContestAudience::
	createvobject OBJ_EVENT_GFX_JUGGLER, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_CreateSuperContestAudience::
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_ROCKER, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_SCIENTIST, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_JUGGLER, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_AROMA_LADY, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_LASS, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_CreateHyperContestAudience::
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_ROCKER, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_JUGGLER, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_AROMA_LADY, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_OLD_WOMAN, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WORKER_M, 20, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_COOLTRAINER_F, 20, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST, 24, 8, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 11, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 3, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 5, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_CHANNELER, 28, 9, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_ENGINEER, 29, 10, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_CLERK, 30, 11, 9, 3, DIR_NORTH
	return

ContestHall_EventScript_CreateMasterContestAudience::
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_ROCKER, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_SUPER_NERD, 4, 1, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_COOLTRAINER_F, 6, 1, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_POKEMON_BREEDER, 7, 1, 6, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_JUGGLER, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_AROMA_LADY, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_FISHER, 14, 13, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BATTLE_GIRL, 15, 13, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_ROCKER_2, 17, 13, 6, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_CLERK, 18, 13, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WORKER_M, 19, 13, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BALDING_MAN, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_COOLTRAINER_M, 22, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST, 24, 11, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SAILOR, 25, 3, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 27, 5, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_CHANNELER, 28, 9, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_POKEMON_RANGER_M, 29, 10, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_CLERK, 30, 11, 9, 3, DIR_NORTH
	return

ContestHall_EventScript_CreateWirelessContestAudience::
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_ROCKER, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_SUPER_NERD, 4, 1, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_COOLTRAINER_F, 6, 1, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 1, 6, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_POKEMON_BREEDER, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BATTLE_GIRL, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_FISHER, 14, 13, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BATTLE_GIRL, 15, 13, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_POKE_MANIAC, 17, 13, 6, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_CLERK, 18, 13, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WORKER_M, 19, 13, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BALDING_MAN, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_COOLTRAINER_M, 22, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_SetExitWarp::
	special ClearLinkContestFlags
	switch VAR_CONTEST_TYPE
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_SetExitWarpNormalContest
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_SetExitWarpSuperContest
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_SetExitWarpHyperContest
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_SetExitWarpMasterContest
	case CONTEST_TYPE_LINK, ContestHall_EventScript_SetExitWarpLinkContest
	return

ContestHall_EventScript_SetExitWarpNormalContest::
	warp MAP_SIX_ISLAND_CONTEST_LOBBY, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpSuperContest::
	warp MAP_SIX_ISLAND_CONTEST_LOBBY, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpHyperContest::
	warp MAP_SIX_ISLAND_CONTEST_LOBBY, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpMasterContest::
	warp MAP_SIX_ISLAND_CONTEST_LOBBY, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpLinkContest::
	warp MAP_SIX_ISLAND_CONTEST_LOBBY, 15, 4
	waitstate
	end

SixIsland_ContestLobby_EventScript_SetPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SixIsland_ContestLobby_EventScript_SetPlayerGfxBrendan
	goto_if_eq VAR_RESULT, FEMALE, SixIsland_ContestLobby_EventScript_SetPlayerGfxMay
	return

SixIsland_ContestLobby_EventScript_SetPlayerGfxBrendan::
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RED_NORMAL
	return

SixIsland_ContestLobby_EventScript_SetPlayerGfxMay::
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_GREEN_NORMAL
	return

