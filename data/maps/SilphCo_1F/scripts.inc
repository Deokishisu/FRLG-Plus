.set LOCALID_KINGLER_MASTER, 7
.set TRAINER, VAR_0x8009

SilphCo_1F_MapScripts:: @ 8161625
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_1F_OnTransition
	.byte 0

SilphCo_1F_OnTransition:: @ 816162B
	setworldmapflag FLAG_WORLD_MAP_SILPH_CO_1F
	goto SilphCo_1F_MapScript_SetMasterTrainerMovementTypes
	end

SilphCo_1F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_KINGLER
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq SilphCo_1F_MapScript_KinglerMasterMovementType
	end

SilphCo_1F_MapScript_KinglerMasterMovementType::
	setobjectmovementtype LOCALID_KINGLER_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

SilphCo_1F_EventScript_Receptionist:: @ 816162F
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign:: @ 8161638
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_1F_EventScript_CouchWoman::
	msgbox SilphCo_1F_Text_CouchWoman, MSGBOX_NPC
	end

SilphCo_1F_Text_CouchWoman:
	.string "I was captured by TEAM ROCKET.\p"
	.string "I wonder if our insurance plan\n"
	.string "covers that kind of thing…?$"

SilphCo_1F_EventScript_CouchMan::
	msgbox SilphCo_1F_Text_CouchMan, MSGBOX_NPC
	end

SilphCo_1F_Text_CouchMan:
	.string "I heard that the one who took on\n"
	.string "TEAM ROCKET was actually some kid!\p"
	.string "Wait, could it be you…?\n"
	.string "No, no, couldn't be…$"

SilphCo_1F_EventScript_FountainMan::
	msgbox SilphCo_1F_Text_FountainMan, MSGBOX_NPC
	end

SilphCo_1F_Text_FountainMan:
	.string "Any tool can be used for good\n"
	.string "or evil, depending on the user.\p"
	.string "I shudder to think what would've\n"
	.string "happened if TEAM ROCKET had gotten\l"
	.string "their hands on SILPH technology…$"

SilphCo_1F_EventScript_CushionMan::
	msgbox SilphCo_1F_Text_CushionMan, MSGBOX_NPC
	end

SilphCo_1F_Text_CushionMan:
	.string "I came back from playing hooky only\n"
	.string "to find out the company had been\l"
	.string "taken over!\l"
	.string "That was quite a surprise, for sure.$"

SilphCo_1F_EventScript_WalkingWoman::
	msgbox SilphCo_1F_Text_WalkingWoman, MSGBOX_NPC
	end

SilphCo_1F_Text_WalkingWoman:
	.string "A lot of work's piled up, so we\n"
	.string "need to get cracking!$"

SilphCo_1F_EventScript_Painting::
	goto_if_unset FLAG_HIDE_SAFFRON_CIVILIANS, SilphCo_1F_EventScript_NewPainting
	msgbox Text_Painting, MSGBOX_SIGN
	end

SilphCo_1F_EventScript_NewPainting::
	msgbox SilphCo_1F_Text_NewPainting, MSGBOX_SIGN
	end

SilphCo_1F_Text_NewPainting:
	.string "It's a gorgeous painting of a cabin\n"
	.string "surrounded by a field of flowers.$"