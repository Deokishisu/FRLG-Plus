.set LOCALID_CASCADE_BADGE_GUARD, 1
.set LOCALID_THUNDER_BADGE_GUARD, 2
.set LOCALID_RAINBOW_BADGE_GUARD, 3
.set LOCALID_SOUL_BADGE_GUARD,    4
.set LOCALID_MARSH_BADGE_GUARD,   5
.set LOCALID_VOLCANO_BADGE_GUARD, 6
.set LOCALID_EARTH_BADGE_GUARD,   7

.set LOCALID_DRATINI_MASTER, 8
.set LOCALID_NIDOQUEEN_MASTER, 9
.set LOCALID_NIDOKING_MASTER, 10
.set LOCALID_CHARIZARD_MASTER, 11
.set LOCALID_VENUSAUR_MASTER, 12
.set TRAINER, VAR_0x8009

Route23_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route23_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route23_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_DRATINI
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route23_MapScript_DratiniMasterMovementType
	setvar TRAINER, MASTER_NIDOQUEEN
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route23_MapScript_NidoqueenMMasterMovementType
	setvar TRAINER, MASTER_NIDOKING
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route23_MapScript_NidokingMasterMovementType
	setvar TRAINER, MASTER_CHARIZARD
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route23_MapScript_CharizardMasterMovementType
	setvar TRAINER, MASTER_VENUSAUR
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route23_MapScript_VenusaurMasterMovementType
	end

Route23_MapScript_DratiniMasterMovementType::
	setobjectmovementtype LOCALID_DRATINI_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route23_MapScript_NidoqueenMMasterMovementType::
	setobjectmovementtype LOCALID_NIDOQUEEN_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route23_MapScript_NidokingMasterMovementType::
	setobjectmovementtype LOCALID_NIDOKING_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route23_MapScript_CharizardMasterMovementType::
	setobjectmovementtype LOCALID_CHARIZARD_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route23_MapScript_VenusaurMasterMovementType::
	setobjectmovementtype LOCALID_VENUSAUR_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route23_EventScript_CascadeBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 2
	bufferstdstring STR_VAR_1, STDSTRING_CASCADE_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_ThunderBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 3
	bufferstdstring STR_VAR_1, STDSTRING_THUNDER_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_RainbowBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 4
	bufferstdstring STR_VAR_1, STDSTRING_RAINBOW_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_SoulBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 5
	bufferstdstring STR_VAR_1, STDSTRING_SOUL_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_MarshBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 6
	bufferstdstring STR_VAR_1, STDSTRING_MARSH_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_VolcanoBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 7
	bufferstdstring STR_VAR_1, STDSTRING_VOLCANO_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_EarthBadgeGuard::
	lock
	faceplayer
	setvar VAR_TEMP_1, 8
	bufferstdstring STR_VAR_1, STDSTRING_EARTH_BADGE
	goto Route23_EventScript_BadgeGuard
	end

Route23_EventScript_CascadeBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 2
	setvar VAR_0x8009, LOCALID_CASCADE_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_CASCADE_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_ThunderBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 3
	setvar VAR_0x8009, LOCALID_THUNDER_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_THUNDER_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_RainbowBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 4
	setvar VAR_0x8009, LOCALID_RAINBOW_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_RAINBOW_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_SoulBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 5
	setvar VAR_0x8009, LOCALID_SOUL_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_SOUL_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_MarshBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 6
	setvar VAR_0x8009, LOCALID_MARSH_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_MARSH_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_VolcanoBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 7
	setvar VAR_0x8009, LOCALID_VOLCANO_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_VOLCANO_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_EarthBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 8
	setvar VAR_0x8009, LOCALID_EARTH_BADGE_GUARD
	bufferstdstring STR_VAR_1, STDSTRING_EARTH_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end

Route23_EventScript_VictoryRoadGateSign::
	msgbox Route23_Text_VictoryRoadGateSign, MSGBOX_SIGN
	end
