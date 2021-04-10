.set LOCALID_GOLEM_MASTER, 6
.set TRAINER, VAR_0x8009

PewterCity_Museum_2F_MapScripts:: @ 816A552
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_Museum_2F_MapScript_SetMasterTrainerMovementTypes
	.byte 0

PewterCity_Museum_2F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_GOLEM
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq PewterCity_Museum_2F_MapScript_GolemMasterMovementType
	end

PewterCity_Museum_2F_MapScript_GolemMasterMovementType::
	setobjectmovementtype LOCALID_GOLEM_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

PewterCity_Museum_2F_EventScript_Man:: @ 816A553
	msgbox PewterCity_Museum_1F_Text_WhatsSpecialAboutMoonStone, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_OldMan:: @ 816A55C
	msgbox PewterCity_Museum_1F_Text_BoughtColorTVForMoonLanding, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Scientist:: @ 816A565
	msgbox PewterCity_Museum_1F_Text_RunningSpaceExhibitThisMonth, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_LittleGirl:: @ 816A56E
	msgbox PewterCity_Museum_1F_Text_AskedDaddyToCatchPikachu, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_BaldingMan:: @ 816A577
	msgbox PewterCity_Museum_1F_Text_PikachuSoonIPromise, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_SpaceShuttle:: @ 816A580
	msgbox PewterCity_Museum_1F_Text_SpaceShuttle, MSGBOX_SIGN
	end

PewterCity_Museum_2F_EventScript_MoonStone:: @ 816A589
	callnative(SetFirstDeoxysForm)
	msgbox PewterCity_Museum_1F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end
