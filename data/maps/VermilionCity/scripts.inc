.equ LOCALID_FERRY_SAILOR, 6
.set LOCALID_MACHAMP_MASTER, 9
.set LOCALID_FARFETCHD_MASTER, 10
.set TRAINER, VAR_0x8009

.equ HAS_TICKETS, 16
.equ NEEDS_SHOW_EON, 17
.equ NEEDS_SHOW_AURORA, 18
.equ NEEDS_SHOW_MYSTIC, 19
.equ NEEDS_SHOW_OLD_SEA_MAP, 20
.equ HAS_NO_TICKETS, 21
.equ F, 1
.equ N, 2
.equ NF, 3
.equ B, 4
.equ BF, 5
.equ BN, 6
.equ BNF, 7
.equ S, 8
.equ SF, 9
.equ SN, 10
.equ SNF, 11
.equ SB, 12
.equ SBF, 13
.equ SBN, 14
.equ SBNF, 15

VermilionCity_MapScripts:: @ 81668DC
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

VermilionCity_OnFrame:: @ 81668E7
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
	.2byte 0

VermilionCity_EventScript_ExitSSAnne:: @ 81668F1
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_ExitSSAnne
	waitmovement 0
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	releaseall
	end

VermilionCity_Movement_ExitSSAnne:: @ 8166903
	walk_up
	walk_up
	step_end

VermilionCity_OnTransition:: @ 8166906
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
	goto VermilionCity_MapScript_SetMasterTrainerMovementTypes
	end

VermilionCity_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MACHAMP
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq VermilionCity_MapScript_MachampMasterMovementType
	setvar TRAINER, MASTER_FARFETCHD
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq VermilionCity_MapScript_FarfetchdMasterMovementType
	end

VermilionCity_MapScript_MachampMasterMovementType::
	setobjectmovementtype LOCALID_MACHAMP_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return
	
VermilionCity_MapScript_FarfetchdMasterMovementType::
	setobjectmovementtype LOCALID_FARFETCHD_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

VermilionCity_EventScript_HideOaksAide:: @ 8166913
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_EventScript_Woman:: @ 8166917
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_EventScript_OldMan1:: @ 8166920
	lock
	faceplayer
	compare VAR_MAP_SCENE_VERMILION_CITY, 3
	goto_if_eq VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_EventScript_OldMan1SSAnneLeft:: @ 8166937
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_EventScript_FerrySailor:: @ 8166941
	lock
	faceplayer
	compare VAR_MAP_SCENE_VERMILION_CITY, 3
	goto_if_eq VermilionCity_EventScript_CheckSeagallopPresent
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
	release
	end

VermilionCity_EventScript_CheckSeagallopPresent:: @ 8166996
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
	goto_if_ge VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
	goto_if_ge VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	release
	end

VermilionCity_EventScript_SetSailToBattleTower::
	msgbox VermilionCity_Text_Seagallop13Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BATTLE_TOWER
	goto EventScript_SetSail
	end

VermilionCity_EventScript_SetSailToSouthernIsland::
	msgbox VermilionCity_Text_Seagallop13Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_SOUTHERN_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_SetSailToFarawayIsland::
	msgbox VermilionCity_Text_Seagallop14Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_FARAWAY_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_ChooseSeagallopDestRainbowPass:: @ 81669BB
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	setvar VAR_RESULT, 0
	callnative CheckEventTickets
	switch VAR_RESULT
	case NEEDS_SHOW_EON, VermilionCity_EventScript_ShowEonTicket
	case NEEDS_SHOW_AURORA, VermilionCity_EventScript_ShowAuroraTicket
	case NEEDS_SHOW_MYSTIC, VermilionCity_EventScript_ShowMysticTicket
	case NEEDS_SHOW_OLD_SEA_MAP, VermilionCity_EventScript_ShowOldSeaMap
	case HAS_TICKETS, VermilionCity_EventScript_HasTicketsRainbowPass
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	multichoice 13, 6, MULTICHOICE_SEVII_BATTLE_TOWER, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, VermilionCity_EventScript_SetSailToBattleTower
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_HasTicketsRainbowPass::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	multichoice 13, 5, MULTICHOICE_SEVII_BATTLE_TOWER_OTHER, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, VermilionCity_EventScript_SetSailToBattleTower
	case 2, VermilionCity_EventScript_EventIslandsMultichoice
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_ShowOldSeaMap::
	setflag FLAG_SHOWN_OLD_SEA_MAP
	msgbox VermilionCity_Text_OldSeaMapTakeYouToFarawayIsland
	goto VermilionCity_EventScript_CheckSeagallopPresentTrigger

VermilionCity_EventScript_ShowMysticTicket:: @ 8166A53
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
	goto VermilionCity_EventScript_CheckSeagallopPresentTrigger

VermilionCity_EventScript_ShowAuroraTicket:: @ 8166AA5
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
	goto VermilionCity_EventScript_CheckSeagallopPresentTrigger

EventScript_SailToNavelRock:: @ 8166B0B
	msgbox VermilionCity_Text_Seagallop10Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
	goto EventScript_SetSail
	end

EventScript_SailToBirthIsland:: @ 8166B23
	msgbox VermilionCity_Text_Seagallop12Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_ChooseSeagallopDestTriPass:: @ 8166B3B
	setvar VAR_RESULT, 0
	callnative CheckEventTickets
	switch VAR_RESULT
	case NEEDS_SHOW_EON, VermilionCity_EventScript_ShowEonTicket
	case NEEDS_SHOW_AURORA, VermilionCity_EventScript_ShowAuroraTicket
	case NEEDS_SHOW_MYSTIC, VermilionCity_EventScript_ShowMysticTicket
	case NEEDS_SHOW_OLD_SEA_MAP, VermilionCity_EventScript_ShowOldSeaMap
	case HAS_TICKETS, VermilionCity_EventScript_HasTicketsTriPass
	message VermilionCity_Text_BoardSeagallopTriPass
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
VermilionCity_EventScript_TriPassOriginalMultichoice:
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToOneIsland2
	case 1, EventScript_SailToTwoIsland2
	case 2, EventScript_SailToThreeIsland2
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowEonTicket::
	setflag FLAG_SHOWN_EON_TICKET
	msgbox VermilionCity_Text_OhEonTicketTakeYouToSouthernIsland
	goto VermilionCity_EventScript_CheckSeagallopPresentTrigger

VermilionCity_EventScript_HasTicketsTriPass::
	message VermilionCity_Text_BoardSeagallopTriPass
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	multichoice 13, 6, MULTICHOICE_SEVII_OTHER, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_TriPassOriginalMultichoice
	case 1, VermilionCity_EventScript_EventIslandsMultichoice
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_EventIslandsMultichoice::
	setvar VAR_RESULT, 1
	callnative CheckEventTickets
	getnumberstring 0, VAR_RESULT
	switch VAR_RESULT
	case F, VermilionCity_EventScript_Faraway
	case N, VermilionCity_EventScript_Navel
	case NF, VermilionCity_EventScript_NavelFaraway
	case B, VermilionCity_EventScript_Birth
	case BF, VermilionCity_EventScript_BirthFaraway
	case BN, VermilionCity_EventScript_BirthNavel
	case BNF, VermilionCity_EventScript_BirthNavelFaraway
	case S, VermilionCity_EventScript_Southern
	case SF, VermilionCity_EventScript_SouthernFaraway
	case SN, VermilionCity_EventScript_SouthernNavel
	case SNF, VermilionCity_EventScript_SouthernNavelFaraway
	case SB, VermilionCity_EventScript_SouthernBirth
	case SBF, VermilionCity_EventScript_SouthernBirthFaraway
	case SBN, VermilionCity_EventScript_SouthernBirthNavel
	case SBNF, VermilionCity_EventScript_SouthernBirthNavelFaraway
	end

VermilionCity_EventScript_Faraway::
	multichoice 13, 8, MULTICHOICE_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToFarawayIsland
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_Navel::
	multichoice 13, 8, MULTICHOICE_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToNavelRock
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_NavelFaraway::
	multichoice 13, 6, MULTICHOICE_NAVEL_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToNavelRock
	case 1, VermilionCity_EventScript_SetSailToFarawayIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_Birth::
	multichoice 13, 8, MULTICHOICE_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToBirthIsland
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_BirthFaraway::
	multichoice 13, 6, MULTICHOICE_BIRTH_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToBirthIsland
	case 1, VermilionCity_EventScript_SetSailToFarawayIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_BirthNavel::
	multichoice 13, 6, MULTICHOICE_BIRTH_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToBirthIsland
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_BirthNavelFaraway::
	multichoice 13, 5, MULTICHOICE_BIRTH_NAVEL_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToBirthIsland
	case 1, EventScript_SailToNavelRock
	case 2, VermilionCity_EventScript_SetSailToFarawayIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_Southern::
	multichoice 13, 8, MULTICHOICE_SOUTHERN, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernFaraway::
	multichoice 13, 6, MULTICHOICE_SOUTHERN_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, VermilionCity_EventScript_SetSailToFarawayIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernNavel::
	multichoice 13, 6, MULTICHOICE_SOUTHERN_NAVEL, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernNavelFaraway::
	multichoice 13, 5, MULTICHOICE_SOUTHERN_NAVEL_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToNavelRock
	case 2, VermilionCity_EventScript_SetSailToFarawayIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernBirth::
	multichoice 13, 6, MULTICHOICE_SOUTHERN_BIRTH, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernBirthFaraway::
	multichoice 13, 5, MULTICHOICE_SOUTHERN_BIRTH_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToBirthIsland
	case 2, VermilionCity_EventScript_SetSailToFarawayIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernBirthNavel::
	multichoice 13, 5, MULTICHOICE_SOUTHERN_BIRTH_NAVEL, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_SailToNavelRock
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernBirthNavelFaraway::
	multichoice 13, 3, MULTICHOICE_SOUTHERN_BIRTH_NAVEL_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_SailToNavelRock
	case 3, VermilionCity_EventScript_SetSailToFarawayIsland
	case 4, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_CheckTicketLeft:: @ 8166B8A
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_CheckTicketRight:: @ 8166B91
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_ExitedTicketCheck:: @ 8166B98
	lockall
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
	releaseall
	end

VermilionCity_EventScript_CheckTicket:: @ 8166BA0
	textcolor 0
	applymovement LOCALID_FERRY_SAILOR, Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestRight
	waitmovement 0
	compare VAR_MAP_SCENE_VERMILION_CITY, 3
	goto_if_eq VermilionCity_EventScript_CheckSeagallopPresentTrigger
	msgbox VermilionCity_Text_DoYouHaveATicket
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
	msgbox VermilionCity_Text_FlashedSSTicket
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
	releaseall
	end

VermilionCity_EventScript_DontHaveSSTicket:: @ 8166BDE
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_CheckSeagallopPresentTrigger:: @ 8166BED
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
	goto_if_ge VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	compare VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
	goto_if_ge VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_Sailor:: @ 8166C17
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_EventScript_OaksAide:: @ 8166C20
	lock
	faceplayer
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
	release
	end

VermilionCity_EventScript_OldMan2:: @ 8166C2F
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop:: @ 8166C38
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, 0
	msgbox VermilionCity_Text_Machop
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat
	release
	end

VermilionCity_EventScript_CitySign:: @ 8166C53
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_EventScript_SnorlaxNotice:: @ 8166C5C
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_EventScript_PokemonFanClubSign:: @ 8166C65
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign:: @ 8166C6E
	lockall
	famechecker FAMECHECKER_LTSURGE, 0
	msgbox VermilionCity_Text_GymSign
	releaseall
	end

VermilionCity_EventScript_HarborSign:: @ 8166C86
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end
