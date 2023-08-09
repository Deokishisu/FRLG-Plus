Fiery_Passage_MapScripts::
	.byte 0

Fiery_Passage_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Fiery_Passage_EventScript_TryRemoveCyndaquil
	end

Fiery_Passage_EventScript_TryRemoveCyndaquil::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

Fiery_Passage_OnTransition::
	call_if_set FLAG_FOUGHT_CYNDAQUIL, Fiery_Passage_EventScript_HideCyndaquil
	call_if_unset FLAG_FOUGHT_CYNDAQUIL, Fiery_Passage_EventScript_TryShowCyndaquil
	end

Fiery_Passage_EventScript_TryShowCyndaquil::
	goto_if_set FLAG_CYNDAQUIL_FLED, EventScript_Return
	clearflag FLAG_HIDE_CYNDAQUIL
	return

Fiery_Passage_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUIL
	return

Fiery_Passage_EventScript_Cyndaquil::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_CYNDAQUIL, 15, ITEM_NONE
	waitse
	playmoncry SPECIES_CYNDAQUIL, 2
	Fiery_Passage_Text_Cyndaquil
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Fiery_Passage_EventScript_DefeatedCyndaquil
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Fiery_Passage_EventScript_RanFromCyndaquil
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Fiery_Passage_EventScript_RanFromCyndaquil
	setflag FLAG_FOUGHT_CYNDAQUIL
	release
	end

Fiery_Passage_EventScript_DefeatedCyndaquil::
	setflag FLAG_CYNDAQUIL_FLED
	setvar VAR_0x8004, SPECIES_CYNDAQUIL
	goto EventScript_MonFlewAway
	end

Fiery_Passage_EventScript_RanFromCyndaquil::
	setvar VAR_0x8004, SPECIES_CYNDAQUIL
	goto EventScript_MonFlewAway
	end