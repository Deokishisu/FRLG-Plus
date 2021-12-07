Mt_Battle_Exterior_MapScripts::
	.byte 0

Mt_Battle_Exterior_EventScript_Blonde::
	msgbox Mt_Battle_Exterior_Text_Blonde, MSGBOX_NPC
	end

Mt_Battle_Exterior_Text_Blonde:
	.string "They finished the rookie training\n"
	.string "session so MT. BATTLE has reopened\l"
	.string "to everyone.\p"
	.string "But I still can't decide whether I\n"
	.string "should take the challenge or not.\l"
	.string "What should I do?$"

Mt_Battle_Exterior_EventScript_OldMan::
	lock
	faceplayer
	msgbox Mt_Battle_Exterior_Text_OldManQuestion, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Mt_Battle_Exterior_EventScript_OldManYes
	msgbox Mt_Battle_Exterior_Text_OldManNo, MSGBOX_DEFAULT
	release
	end

Mt_Battle_Exterior_EventScript_OldManYes::
	msgbox Mt_Battle_Exterior_Text_OldManYes, MSGBOX_DEFAULT
	release
	end

Mt_Battle_Exterior_Text_OldManQuestion:
	.string "Hm?\n"
	.string "You've come to MT. BATTLE.\p"
	.string "Are you here to train as a TRAINER\n"
	.string "of POKéMON?$"

Mt_Battle_Exterior_Text_OldManYes:
	.string "Ah, very well!\p"
	.string "If you train at your young age\n"
	.string "you will certainly become a fine\l"
	.string "POKéMON TRAINER one day!$"

Mt_Battle_Exterior_Text_OldManNo:
	.string "If you begin training in earnest\n"
	.string "now, you will most certainly\l"
	.string "become tougher as a TRAINER.\p"
	.string "You should mount a challenge!$"

Mt_Battle_Exterior_EventScript_Delcatty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DELCATTY, 0
	msgbox Mt_Battle_Exterior_Text_Delcatty
	waitmoncry
	release
	end

Mt_Battle_Exterior_Text_Delcatty:
	.string "DELCATTY: Delcaaaat!$"

Mt_Battle_Exterior_EventScript_Triggers::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox Mt_Battle_Exterior_Text_TooDangerous, MSGBOX_DEFAULT
	release
	applymovement OBJ_EVENT_ID_PLAYER, Route16_NorthEntrance_1F_Movement_WalkUp
	waitmovement 0
	release
	end

Mt_Battle_Exterior_Text_TooDangerous:
	.string "The region that stretches out before\n"
	.string "you is barren and desolate.\p"
	.string "It's too dangerous to leave.$"

Mt_Battle_Exterior_EventScript_TeleportMan::
	lock
	faceplayer
	msgbox Mt_Battle_Exterior_Text_TeleportMan, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Mt_Battle_Exterior_EventScript_TeleportWarp
	release
	end

Mt_Battle_Exterior_EventScript_TeleportWarp::
	release
	warpteleport MAP_RS_BATTLE_TOWER, 255, 14, 9
	waitstate
	end

Mt_Battle_Exterior_Text_TeleportMan::
	.string "PLACEHOLDER\n"
	.string "Teleport to the BATTLE TOWER?$"
