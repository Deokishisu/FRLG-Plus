.equ LOCALID_KARATE_MASTER, 5
.set LOCALID_HITMONLEE_MASTER, 8
.set LOCALID_HITMONCHAN_MASTER, 9
.set TRAINER, VAR_0x8009

SaffronCity_Dojo_MapScripts:: @ 816EBDB
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_Dojo_MapScript_SetMasterTrainerMovementTypes
	.byte 0

SaffronCity_Dojo_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_HITMONLEE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq SaffronCity_Dojo_MapScript_HitmonleeMasterMovementType
	setvar TRAINER, MASTER_HITMONCHAN
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq SaffronCity_Dojo_MapScript_HitmonchanMasterMovementType
	end

SaffronCity_Dojo_MapScript_HitmonleeMasterMovementType::
	setobjectmovementtype LOCALID_HITMONLEE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

SaffronCity_Dojo_MapScript_HitmonchanMasterMovementType::
	setobjectmovementtype LOCALID_HITMONCHAN_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft:: @ 816EBDC
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_TriggerMasterBattleRight:: @ 816EBEE
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Movement_WalkInPlaceFastestRight
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleeBall:: @ 816EC00
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	drawmonpic SPECIES_HITMONLEE, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	applymovement LOCALID_KARATE_MASTER, Movement_WalkInPlaceFastestUp
	waitmovement 0
	textcolor 0
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon
	erasemonpic
	release
	end

SaffronCity_Dojo_EventScript_AlreadyGotHitmon:: @ 816EC3C
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall:: @ 816EC46
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	drawmonpic SPECIES_HITMONCHAN, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	applymovement LOCALID_KARATE_MASTER, Movement_WalkInPlaceFastestUp
	waitmovement 0
	textcolor 0
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon
	erasemonpic
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon:: @ 816EC82
	erasemonpic
	givemon VAR_TEMP_1, 25, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	compare VAR_RESULT, 1
	goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty:: @ 816ECB5
	removeobject VAR_LAST_TALKED
	getspeciesname 0, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_NicknameHitmonParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_EndGiveMon
CeladonCity_Condominiums_RoofRoom_EventScript_NicknameHitmonParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC:: @ 816ECEC
	removeobject VAR_LAST_TALKED
	getspeciesname 0, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_NicknameHitmonPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_TransferredHitmonToPC
CeladonCity_Condominiums_RoofRoom_EventScript_NicknameHitmonPC::
	call EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_TransferredHitmonToPC:: @ 816ED1E
	call EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_EndGiveMon:: @ 816ED29
	release
	end

SaffronCity_Dojo_EventScript_Statue:: @ 816ED2B
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_LeftScroll:: @ 816ED34
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_RightScroll:: @ 816ED3D
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_Hitoshi:: @ 816ED46
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki:: @ 816ED5D
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron:: @ 816ED74
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike:: @ 816ED8B
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi:: @ 816EDA2
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon:: @ 816EDC6
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
	release
	end

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi:: @ 816EDD0
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	release
	end
