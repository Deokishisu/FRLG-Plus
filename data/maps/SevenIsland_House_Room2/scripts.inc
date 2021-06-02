.equ LOCALID_BROCK, 1
.equ LOCALID_MISTY, 2
.equ LOCALID_LT_SURGE, 3
.equ LOCALID_ERIKA, 4
.equ LOCALID_KOGA, 5
.equ LOCALID_SABRINA, 6
.equ LOCALID_BLAINE, 7

.equ SET_SPEAROW_STATE, 0
.equ SET_TOLD_FAMECHECKER, 1
.equ SET_VISITOR_STATE, 2
.equ SET_LEVEL_GROWTH, 3
.equ CHECK_SPEAROW_STATE, 4
.equ CHECK_TOLD_FAMECHECKER, 5
.equ CHECK_VISITOR_STATE, 6
.equ CHECK_LEVEL_GROWTH, 7
.equ SET_BOXES_MOVED, 8
.equ CHECK_BOXES_MOVED, 9

.equ TYPE, VAR_0x8003
.equ ARGUMENT, VAR_0x8004
.equ LEADER_READY, VAR_0x8006
.equ X_COORD, VAR_0x8007
.equ Y_COORD, VAR_0x8008

SevenIsland_House_Room2_MapScripts:: @ 8170A7E
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_House_Room2_OnTransition
	.byte 0

SevenIsland_House_Room2_OnTransition:: @ 8170A89
	setvar TYPE, CHECK_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_BROCK
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideBrock
	setvar ARGUMENT, FAMECHECKER_MISTY
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideMisty
	setvar ARGUMENT, FAMECHECKER_LTSURGE
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideLtSurge
	setvar ARGUMENT, FAMECHECKER_ERIKA
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideErika
	setvar ARGUMENT, FAMECHECKER_KOGA
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideKoga
	setvar ARGUMENT, FAMECHECKER_SABRINA
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideSabrina
	setvar ARGUMENT, FAMECHECKER_BLAINE
	callnative UseBattleHouseVar
	compare VAR_RESULT, 0
	call_if_eq SevenIsland_House_Room2_HideBlaine
	end

SevenIsland_House_Room2_HideBrock::
	setflag FLAG_TEMP_1
	return

SevenIsland_House_Room2_HideMisty::
	setflag FLAG_TEMP_2
	return

SevenIsland_House_Room2_HideLtSurge::
	setflag FLAG_TEMP_3
	return

SevenIsland_House_Room2_HideErika::
	setflag FLAG_TEMP_4
	return

SevenIsland_House_Room2_HideKoga::
	setflag FLAG_TEMP_5
	return

SevenIsland_House_Room2_HideSabrina::
	setflag FLAG_TEMP_6
	return

SevenIsland_House_Room2_HideBlaine::
	setflag FLAG_TEMP_7
	return	
	
SevenIsland_House_Room2_EventScript_LeftPainting::
	msgbox SevenIsland_House_Room2_Text_LeftPainting, MSGBOX_SIGN
	end

SevenIsland_House_Room2_Text_LeftPainting::
	.string "It's a photo of a young woman.\n"
	.string "She's surrounded by happy,\l"
	.string "strong-looking POKéMON.$"

SevenIsland_House_Room2_EventScript_MiddlePainting::
	msgbox SevenIsland_House_Room2_Text_MiddlePainting, MSGBOX_SIGN
	end

SevenIsland_House_Room2_Text_MiddlePainting::
	.string "It's a photo of a young woman.\n"
	.string "A SPEAROW perches on her arm.$"

SevenIsland_House_Room2_EventScript_RightPainting::
	compare VAR_STARTER_MON, 0
	call_if_eq SevenIsland_House_Room2_EventScript_BufferBulbasaur
	compare VAR_STARTER_MON, 1
	call_if_eq SevenIsland_House_Room2_EventScript_BufferSquirtle
	compare VAR_STARTER_MON, 2
	call_if_ge SevenIsland_House_Room2_EventScript_BufferCharmander
	msgbox SevenIsland_House_Room2_Text_RightPainting, MSGBOX_SIGN
	end

SevenIsland_House_Room2_Text_RightPainting::
	.string "It's a photo of a TRAINER battle.\p"
	.string "A young woman is ordering her\n"
	.string "{STR_VAR_1} to attack an opposing\l"
	.string "{STR_VAR_2}.\p"
	.string "A SPEAROW hovers above the battle,\n"
	.string "watching intently.$"

SevenIsland_House_Room2_EventScript_BufferBulbasaur::
	getspeciesname 0, SPECIES_VENUSAUR
	getspeciesname 1, SPECIES_CHARIZARD
	return

SevenIsland_House_Room2_EventScript_BufferSquirtle::
	getspeciesname 0, SPECIES_BLASTOISE
	getspeciesname 1, SPECIES_VENUSAUR
	return

SevenIsland_House_Room2_EventScript_BufferCharmander::
	getspeciesname 0, SPECIES_CHARIZARD
	getspeciesname 1, SPECIES_BLASTOISE
	return

SevenIsland_House_Room2_EventScript_HealingMachine::
	msgbox SevenIsland_House_Room2_Text_HealPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SevenIsland_House_Room2_EventScript_HealPokemon
	release
	end

SevenIsland_House_Room2_Text_HealPokemon::
	.string "Use the machine to heal\n"
	.string "your POKéMON?$"

SevenIsland_House_Room2_EventScript_HealPokemon::
	release
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 24
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	special HealPlayerParty
	release
	end

SevenIsland_House_Room2_Eventscript_Trigger::
	compare LEADER_READY, 0
	goto_if_eq EventScript_ReleaseEnd
	applymovement OBJ_EVENT_ID_PLAYER, SevenIsland_House_Room2_Movement_StepFastestRight
	waitmovement 0
	switch LEADER_READY
	case LOCALID_BROCK, SevenIsland_House_Room2_Eventscript_BrockBattle
	case LOCALID_MISTY, SevenIsland_House_Room2_Eventscript_MistyBattle
	case LOCALID_LT_SURGE, SevenIsland_House_Room2_Eventscript_LtSurgeBattle
	case LOCALID_ERIKA, SevenIsland_House_Room2_Eventscript_ErikaBattle
	case LOCALID_KOGA, SevenIsland_House_Room2_Eventscript_KogaBattle
	case LOCALID_SABRINA, SevenIsland_House_Room2_Eventscript_SabrinaBattle
	case LOCALID_BLAINE, SevenIsland_House_Room2_Eventscript_BlaineBattle
	release
	end

@ LEADER BROCK
SevenIsland_House_Room2_Eventscript_Brock::
	lock
	faceplayer
	compare LEADER_READY, 1
	goto_if_eq SevenIsland_House_Room2_Eventscript_BrockReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_BrockOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_Brock_Intro, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_BrockDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveBrockDown
	compare Y_COORD, 6
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveBrockLeft
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_BrockToMat
	waitmovement 0
	setobjectmovementtypeinstant LOCALID_BROCK, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_BROCK
	msgbox SevenIsland_House_Room2_Text_BrockSquareUp, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Text_Brock_Intro:
	.string "BROCK: …You sure look different\n"
	.string "from when we first met!\p"
	.string "I have a request for you, since\n"
	.string "you're now the CHAMPION.\p"
	.string "The truth is, GYM LEADERS have a\n"
	.string "right to challenge the CHAMPION!\p"
	.string "…Please allow me the privilege of\n"
	.string "facing you in battle once again!\p"
	.string "Allow me to show you the true\n"
	.string "rock-hard strength of my POKéMON!$"

SevenIsland_House_Room2_Text_BrockSquareUp:
	.string "BROCK: Take your place and we'll\n"
	.string "start our battle!$"

SevenIsland_House_Room2_Eventscript_BrockReady:
	msgbox SevenIsland_House_Room2_Text_BrockSquareUp, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_BrockOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_BrockOtherLeader, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_BrockOtherLeader:
	.string "BROCK: Don't underestimate the other\n"
	.string "GYM LEADERS, {PLAYER}.\p"
	.string "We'll use our best POKéMON against\n"
	.string "the POKéMON LEAGUE CHAMPION!$"

SevenIsland_House_Room2_Eventscript_BrockDeclined::
	msgbox SevenIsland_House_Room2_Text_Brock_Declined, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_Brock_Declined:
	.string "I guess my POKéMON and I will keep\n"
	.string "training to stay rock-hard and tough!$"

SevenIsland_House_Room2_Eventscript_MoveBrockDown:
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_BrockAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveBrockLeft:
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_BrockRight
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_BrockAroundPlayer:
	walk_down
	walk_right
	walk_right
	walk_up
	step_end

SevenIsland_House_Room2_Movement_BrockRight:
	walk_right
	walk_right
	step_end

SevenIsland_House_Room2_Movement_BrockToMat:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_BrockBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_BROCK
	callnative UseBattleHouseVar
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_BrockBeforeBattle, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeBrockBattle
	trainerbattle_no_intro TRAINER_BROCK_REMATCH, SevenIsland_House_Room2_Text_BrockLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_BrockExit
	release
	end

SevenIsland_House_Room2_Text_BrockBeforeBattle:
	.string "BROCK: No matter what kind of\n"
	.string "opponent you may be, my ROCK-type\l"
	.string "POKéMON will take you on!\p"
	.string "That's the promise of my\n"
	.string "rock-hard will!$"

SevenIsland_House_Room2_Text_BrockLoss:
	.string "BROCK: I knew you were strong,\n"
	.string "but this…$"

SevenIsland_House_Room2_Eventscript_ChallengeBrockBattle:
	trainerbattle_no_intro TRAINER_BROCK_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_BrockLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_BrockExit
	release
	end

SevenIsland_House_Room2_Eventscript_BrockExit:
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_BrockExit, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BROCK, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_BROCK
	release
	end

SevenIsland_House_Room2_Text_BrockExit:
	.string "BROCK: I have other ambitions that\n"
	.string "I've chosen to postpone for a bit.\p"
	.string "Right now I'm more interested in\n"
	.string "training to grow strong enough to\l"
	.string "one day face and defeat you!\p"
	.string "I should be getting back to my GYM.\n"
	.string "I look forward to our next battle.$"

@ LEADER MISTY
SevenIsland_House_Room2_Eventscript_Misty::
	lock
	faceplayer
	compare LEADER_READY, 2
	goto_if_eq SevenIsland_House_Room2_Eventscript_MistyReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_MistyOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_Misty_Intro, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_MistyDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 3
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveMistyRight
	compare Y_COORD, 3
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveMistyDown
	setobjectmovementtypeinstant LOCALID_MISTY, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_MISTY
	msgbox SevenIsland_House_Room2_Text_MistySquareUp, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Text_Misty_Intro:
	.string "MISTY: I heard an interesting\n"
	.string "rumor!\p"
	.string "Not only did you defeat those\n"
	.string "TEAM ROCKET guys, but you battled\l"
	.string "that other kid from PALLET TOWN\l"
	.string "to become the CHAMPION!\p"
	.string "Argh!\n"
	.string "I just can't take it any more!\p"
	.string "I just absolutely have to battle\n"
	.string "you again!\l"
	.string "You got that? No refusing!$"

SevenIsland_House_Room2_Text_MistySquareUp:
	.string "MISTY: Stand opposite me and\n"
	.string "we'll get started!$"

SevenIsland_House_Room2_Eventscript_MistyReady:
	msgbox SevenIsland_House_Room2_Text_MistySquareUp, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_MistyOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_MistyOtherLeader, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_MistyOtherLeader:
	.string "MISTY: The lady upstairs isn't the\n"
	.string "only one who likes seeing battles.\p"
	.string "I hope you'll use a WATER-type\n"
	.string "so I can see how you handle them!$"

SevenIsland_House_Room2_Eventscript_MistyDeclined::
	msgbox SevenIsland_House_Room2_Text_Misty_Declined, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_Misty_Declined:
	.string "But I said no refusing!\n"
	.string "Argh, fine…\p"
	.string "My new policy on POKéMON is to\n"
	.string "train hard to defeat you!\p"
	.string "When we finally have our rematch,\n"
	.string "we'll overwhelm you!$"

SevenIsland_House_Room2_Eventscript_MoveMistyRight:
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_MistyAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveMistyDown:
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_MistyDownToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_MistyAroundPlayer:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_MistyDownToMat:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_MistyBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_MISTY
	callnative UseBattleHouseVar
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_MistyBeforeBattle, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeMistyBattle
	trainerbattle_no_intro TRAINER_MISTY_REMATCH, SevenIsland_House_Room2_Text_MistyLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_MistyExit
	release
	end

SevenIsland_House_Room2_Text_MistyBeforeBattle:
	.string "MISTY: My adorable POKéMON are\n"
	.string "ready to take you on!\p"
	.string "The ultimate offense of WATER-type\n"
	.string "POKéMON! I hope you're ready!$"

SevenIsland_House_Room2_Text_MistyLoss:
	.string "MISTY: Hmph!\nHow annoying!$"

SevenIsland_House_Room2_Eventscript_ChallengeMistyBattle:
	trainerbattle_no_intro TRAINER_MISTY_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_MistyLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_MistyExit
	release
	end

SevenIsland_House_Room2_Eventscript_MistyExit:
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_MistyExit, MSGBOX_DEFAULT
	release
	applymovement LOCALID_MISTY, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_MISTY
	release
	end

SevenIsland_House_Room2_Text_MistyExit:
	.string "MISTY: I lost…\p"
	.string "I need to try swimming around in my\n"
	.string "GYM for a bit so that I can clear\l"
	.string "my head of these feelings.\p"
	.string "…I definitely won't lose next time!$"

@ LEADER LTSURGE
SevenIsland_House_Room2_Eventscript_LtSurge::
	lock
	faceplayer
	compare LEADER_READY, 3
	goto_if_eq SevenIsland_House_Room2_Eventscript_LtSurgeReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_LtSurgeOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_LtSurge_Intro, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_LtSurgeDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 5
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveLtSurgeLeft
	compare Y_COORD, 5
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveLtSurgeDown
	setobjectmovementtypeinstant LOCALID_LT_SURGE, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_LT_SURGE
	msgbox SevenIsland_House_Room2_Text_LtSurgeSquareUp, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Text_LtSurge_Intro:
	.string "LT. SURGE: Hey there, kid!\p"
	.string "Pretty shocking you made it through\n"
	.string "the POKéMON LEAGUE!\p"
	.string "No doubt some ELECTRIC-types\n"
	.string "had a hand in that, right?\p"
	.string "All right, then.\p"
	.string "How about you show me what kind\n"
	.string "of POKéMON you've raised?$"

SevenIsland_House_Room2_Text_LtSurgeSquareUp:
	.string "LT. SURGE: Fall in, soldier!\n"
	.string "We'll short your POKéMON out!$"

SevenIsland_House_Room2_Eventscript_LtSurgeReady:
	msgbox SevenIsland_House_Room2_Text_LtSurgeSquareUp, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_LtSurgeOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_LtSurgeOtherLeader, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_LtSurgeOtherLeader:
	.string "LT. SURGE: The other GYM LEADERS\n"
	.string "may not have the discipline that\l"
	.string "I do, but they train just as hard.$"

SevenIsland_House_Room2_Eventscript_LtSurgeDeclined::
	msgbox SevenIsland_House_Room2_Text_LtSurge_Declined, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_LtSurge_Declined:
	.string "Hahaha!\n"
	.string "Afraid we'd fry you?\p"
	.string "If you let me keep training my\n"
	.string "team, we'll be even harder to beat!$" 

SevenIsland_House_Room2_Eventscript_MoveLtSurgeLeft:
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_LtSurgeAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveLtSurgeDown:
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_LtSurgeToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_LtSurgeAroundPlayer:
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_LtSurgeToMat:
	walk_down
	walk_left
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_LtSurgeBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_LTSURGE
	callnative UseBattleHouseVar
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_LtSurgeBeforeBattle, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeLtSurgeBattle
	trainerbattle_no_intro TRAINER_LT_SURGE_REMATCH, SevenIsland_House_Room2_Text_LtSurgeLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_LtSurgeExit
	release
	end

SevenIsland_House_Room2_Text_LtSurgeBeforeBattle:
	.string "LT. SURGE: Trainers like us have\n"
	.string "no need for words!\p"
	.string "Let's go, kid!$"

SevenIsland_House_Room2_Text_LtSurgeLoss:
	.string "LT. SURGE: Absolutely shocking!$"

SevenIsland_House_Room2_Eventscript_ChallengeLtSurgeBattle:
	trainerbattle_no_intro TRAINER_LT_SURGE_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_LtSurgeLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_LtSurgeExit
	release
	end

SevenIsland_House_Room2_Eventscript_LtSurgeExit:
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_LtSurgeExit, MSGBOX_DEFAULT
	release
	applymovement LOCALID_LT_SURGE, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_LT_SURGE
	release
	end

SevenIsland_House_Room2_Text_LtSurgeExit:
	.string "LT. SURGE: Looks like there's still\n"
	.string "a gap between our skill levels that\l"
	.string "I need to close, kid!\p"
	.string "This is the first time I've felt\n"
	.string "like this since I left home!\p"
	.string "I have to return to base.\n"
	.string "I can't leave my troops without\l"
	.string "their CO for long!$"

@ LEADER ERIKA
SevenIsland_House_Room2_Eventscript_Erika::
	lock
	faceplayer
	compare LEADER_READY, 4
	goto_if_eq SevenIsland_House_Room2_Eventscript_ErikaReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_ErikaOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_Erika_Intro, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ErikaDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 3
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveErikaRight
	compare Y_COORD, 3
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveErikaDown
	setobjectmovementtypeinstant LOCALID_ERIKA, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_ERIKA
	msgbox SevenIsland_House_Room2_Text_ErikaSquareUp, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Text_Erika_Intro:
	.string "ERIKA: Oh, if it isn't the one who's\n"
	.string "been trying to fill the POKéDEX.\p"
	.string "I hope things have been going well\n"
	.string "for you since our last encounter.\p"
	.string "…I see. You've certainly been busy.\n"
	.string "I'm not particularly fond of those\l"
	.string "kinds of public things…\p"
	.string "However, battles are different.\n"
	.string "That's what you came for, isn't it?$"

SevenIsland_House_Room2_Text_ErikaSquareUp:
	.string "ERIKA: Plant yourself over there\n"
	.string "and we'll begin.$"

SevenIsland_House_Room2_Eventscript_ErikaReady:
	msgbox SevenIsland_House_Room2_Text_ErikaSquareUp, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_ErikaOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_ErikaOtherLeader, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_ErikaOtherLeader:
	.string "ERIKA: …Zzz…zzz…\n"
	.string "Oh, you're preparing for a battle?$"

SevenIsland_House_Room2_Eventscript_ErikaDeclined::
	msgbox SevenIsland_House_Room2_Text_Erika_Declined, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_Erika_Declined:
	.string "… … … …$"

SevenIsland_House_Room2_Eventscript_MoveErikaRight:
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_ErikaAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveErikaDown:
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_ErikaDownToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_ErikaAroundPlayer:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_ErikaDownToMat:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_ErikaBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_ERIKA
	callnative UseBattleHouseVar
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeErikaBattle
	trainerbattle_no_intro TRAINER_ERIKA_REMATCH, SevenIsland_House_Room2_Text_ErikaLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_ErikaExit
	release
	end

SevenIsland_House_Room2_Text_ErikaBeforeBattle:
	.string "ERIKA: I graciously accept your\n"
	.string "challenge. I shall not lose!$"

SevenIsland_House_Room2_Text_ErikaLoss:
	.string "ERIKA: Oh!\n"
	.string "It appears it is my loss… … … …$"

SevenIsland_House_Room2_Eventscript_ChallengeErikaBattle:
	trainerbattle_no_intro TRAINER_ERIKA_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_ErikaLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_ErikaExit
	release
	end

SevenIsland_House_Room2_Eventscript_ErikaExit:
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_ErikaExit, MSGBOX_DEFAULT
	release
	applymovement LOCALID_ERIKA, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_ERIKA
	release
	end

SevenIsland_House_Room2_Text_ErikaExit:
	.string "ERIKA: Simply marvelous.\p"
	.string "That was an effort worthy of\n"
	.string "at least ten RAINBOWBADGES.\p"
	.string "I feel inspired by our rematch.\n"
	.string "I should return to CELADON and\l"
	.string "tend to my flowers.\p"
	.string "…Until next time, {PLAYER}.$"

@ LEADER KOGA
SevenIsland_House_Room2_Eventscript_Koga::
	lock
	faceplayer
	compare LEADER_READY, 5
	goto_if_eq SevenIsland_House_Room2_Eventscript_KogaReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_KogaOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_Koga_Intro, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_KogaDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 7
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveKogaRight
	compare Y_COORD, 7
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveKogaUp
	setobjectmovementtypeinstant LOCALID_KOGA, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_KOGA
	msgbox SevenIsland_House_Room2_Text_KogaSquareUp, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Text_Koga_Intro:
	.string "KOGA: Fwahahaha!\n"
	.string "If it isn't the child.\p"
	.string "It seems we are fated to meet\n"
	.string "again and again.\p"
	.string "You have come at a truly opportune\n"
	.string "time; I was just thinking that I\l"
	.string "wanted to test my newly-refined\l"
	.string "sinister techniques… in a battle\l"
	.string "that will end in your utter defeat!\p"
	.string "Fwahahaha!\n"
	.string "What do you say?$"

SevenIsland_House_Room2_Text_KogaSquareUp:
	.string "KOGA: Ready yourself, child!$"

SevenIsland_House_Room2_Eventscript_KogaReady:
	msgbox SevenIsland_House_Room2_Text_KogaSquareUp, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_KogaOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_KogaOtherLeader, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_KogaOtherLeader:
	.string "KOGA: I should bring my daughter\n"
	.string "here to learn from the battle\l"
	.string "styles of the other GYM LEADERS.$"

SevenIsland_House_Room2_Eventscript_KogaDeclined::
	msgbox SevenIsland_House_Room2_Text_Koga_Declined, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_Koga_Declined:
	.string "What? Hmph.\p"
	.string "How did you beat the POKéMON\n"
	.string "LEAGUE with such little resolve?$"

SevenIsland_House_Room2_Eventscript_MoveKogaRight:
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_KogaAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveKogaUp:
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_KogaToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_KogaAroundPlayer:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_KogaToMat:
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_KogaBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_KOGA
	callnative UseBattleHouseVar
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_KogaBeforeBattle, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeKogaBattle
	trainerbattle_no_intro TRAINER_KOGA_REMATCH, SevenIsland_House_Room2_Text_KogaLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_KogaExit
	release
	end

SevenIsland_House_Room2_Text_KogaBeforeBattle:
	.string "KOGA: Fwahahaha!\p"
	.string "Today I'll not only defeat you,\n"
	.string "but I will also demonstrate my\l"
	.string "fatherly dignity to my daughter!$"

SevenIsland_House_Room2_Text_KogaLoss:
	.string "KOGA: …If I am not strong enough\n"
	.string "to defeat you now, there is but\l"
	.string "one thing to do.\p"
	.string "I must hone my skills.$"

SevenIsland_House_Room2_Eventscript_ChallengeKogaBattle:
	trainerbattle_no_intro TRAINER_KOGA_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_KogaLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_KogaExit
	release
	end

SevenIsland_House_Room2_Eventscript_KogaExit:
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_KogaExit, MSGBOX_DEFAULT
	release
	applymovement LOCALID_KOGA, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_KOGA
	release
	end

SevenIsland_House_Room2_Text_KogaExit:
	.string "KOGA: With TRAINERS like you and\n"
	.string "{RIVAL}, the POKéMON LEAGUE must\l"
	.string "be a place of formidable strength!\l"
	.string "It's truly a thing to be proud of!\p"
	.string "As it so happens, I have been\n"
	.string "thinking of aiming to join the\l"
	.string "ELITE FOUR myself…\p"
	.string "…But I'll never get there if I\n"
	.string "neglect my duties as a GYM LEADER!\p"
	.string "I must travel back to FUCHSIA CITY.\n"
	.string "Farewell, child.$"

@ LEADER SABRINA
SevenIsland_House_Room2_Eventscript_Sabrina::
	lock
	faceplayer
	compare LEADER_READY, 6
	goto_if_eq SevenIsland_House_Room2_Eventscript_SabrinaReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_SabrinaOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_Sabrina_Intro, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_SabrinaDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveSabrinaRight
	compare Y_COORD, 6
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveSabrinaUp
	setobjectmovementtypeinstant LOCALID_SABRINA, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_SABRINA
	msgbox SevenIsland_House_Room2_Text_SabrinaSquareUp, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Text_Sabrina_Intro:
	.string "SABRINA: …It's true that psychic\n"
	.string "power is a potent ability.\p"
	.string "However, some things cannot be\n"
	.string "overcome with that power alone.\p"
	.string "I finally understand that now, after\n"
	.string "losing to you in our last battle.\p"
	.string "I won't be relying on just psychic\n"
	.string "power this time.\p"
	.string "My true strength… my true self…\n"
	.string "Allow me to test them against you!$"

SevenIsland_House_Room2_Text_SabrinaSquareUp:
	.string "SABRINA: You are fated to stand\n"
	.string "over there for this battle.$"

SevenIsland_House_Room2_Eventscript_SabrinaReady:
	msgbox SevenIsland_House_Room2_Text_SabrinaSquareUp, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_SabrinaOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_SabrinaOtherLeader, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_SabrinaOtherLeader:
	.string "SABRINA: I don't need to peer into\n"
	.string "the future to know who will win\l"
	.string "this match.$"

SevenIsland_House_Room2_Eventscript_SabrinaDeclined::
	msgbox SevenIsland_House_Room2_Text_Sabrina_Declined, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_Sabrina_Declined:
	.string "I foresaw that you would decline,\n"
	.string "but we will battle again eventually.$"

SevenIsland_House_Room2_Eventscript_MoveSabrinaRight:
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_SabrinaAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveSabrinaUp:
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_SabrinaUpToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_SabrinaAroundPlayer:
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_SabrinaUpToMat:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_SabrinaBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_SABRINA
	callnative UseBattleHouseVar
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_SabrinaBeforeBattle, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeSabrinaBattle
	trainerbattle_no_intro TRAINER_SABRINA_REMATCH, SevenIsland_House_Room2_Text_SabrinaLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_SabrinaExit
	release
	end

SevenIsland_House_Room2_Text_SabrinaBeforeBattle:
	.string "SABRINA: I foresaw that we would\n"
	.string "be here by looking into the future.\p"
	.string "But I intentionally didn't look to\n"
	.string "see who will win our battle.\p"
	.string "Let's find out together!$"

SevenIsland_House_Room2_Text_SabrinaLoss:
	.string "SABRINA: I won't encounter another\n"
	.string "TRAINER like you for around another\l"
	.string "three years.$"

SevenIsland_House_Room2_Eventscript_ChallengeSabrinaBattle:
	trainerbattle_no_intro TRAINER_SABRINA_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_SabrinaLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_SabrinaExit
	release
	end

SevenIsland_House_Room2_Eventscript_SabrinaExit:
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 1
	msgbox SevenIsland_House_Room2_Text_SabrinaExit, MSGBOX_DEFAULT
	release
	applymovement LOCALID_SABRINA, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_SABRINA
	release
	end

SevenIsland_House_Room2_Text_SabrinaExit:
	.string "SABRINA: There was once a time\n"
	.string "when I was shocked to lose to you.\l"
	.string "That feeling is gone now.\p"
	.string "It's been replaced with a desire\n"
	.string "to grow strong and live freely,\l"
	.string "as you do.\p"
	.string "If I don't make it back to my GYM\n"
	.string "in the near future, I will miss\l"
	.string "a challenger.\p"
	.string "Don't worry, {PLAYER}.\n"
	.string "We will battle again soon.$"

@ LEADER BLAINE
SevenIsland_House_Room2_Eventscript_Blaine::
	lock
	faceplayer
	compare LEADER_READY, 7
	goto_if_eq SevenIsland_House_Room2_Eventscript_BlaineReady
	compare LEADER_READY, 0
	goto_if_ne SevenIsland_House_Room2_Eventscript_BlaineOtherLeaderReady
	msgbox SevenIsland_House_Room2_Text_Blaine_Intro, MSGBOX_YESNO
	compare VAR_RESULT, FALSE
	goto_if_eq SevenIsland_House_Room2_Eventscript_BlaineDeclined
	closemessage
	getplayerxy X_COORD, Y_COORD
	compare Y_COORD, 5
	call_if_eq SevenIsland_House_Room2_Eventscript_MoveBlaineLeft
	compare Y_COORD, 5
	call_if_ne SevenIsland_House_Room2_Eventscript_MoveBlaineUp
	setobjectmovementtypeinstant LOCALID_BLAINE, MOVEMENT_TYPE_FACE_LEFT
	setvar LEADER_READY, LOCALID_BLAINE
	msgbox SevenIsland_House_Room2_Text_BlaineSquareUp, MSGBOX_DEFAULT 
	release
	end

SevenIsland_House_Room2_Text_Blaine_Intro:
	.string "BLAINE: Hah!\n"
	.string "Well done, becoming CHAMPION!\p"
	.string "I'm taking the opportunity to train\n"
	.string "with the other LEADERS here, but\l"
	.string "I can't stay away from CINNABAR\l"
	.string "for too long.\p"
	.string "The volcano beneath my GYM is\n"
	.string "showing signs of waking up!\p"
	.string "But since you came all this way,\n"
	.string "we should have a red-hot battle!$"

SevenIsland_House_Room2_Text_BlaineSquareUp:
	.string "BLAINE: Square up, challenger!$"

SevenIsland_House_Room2_Eventscript_BlaineReady:
	msgbox SevenIsland_House_Room2_Text_BlaineSquareUp, MSGBOX_DEFAULT
	release
	getplayerxy X_COORD, Y_COORD
	compare X_COORD, 6
	call_if_eq SevenIsland_House_Room2_Eventscript_CheckInFront
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	release
	end

SevenIsland_House_Room2_Eventscript_BlaineOtherLeaderReady:
	msgbox SevenIsland_House_Room2_Text_BlaineOtherLeader, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_BlaineOtherLeader:
	.string "BLAINE: We GYM LEADERS battle\n"
	.string "each other all the time, but it's\l"
	.string "nice to have a dedicated space\l"
	.string "now that we can practice in.$"

SevenIsland_House_Room2_Eventscript_BlaineDeclined::
	msgbox SevenIsland_House_Room2_Text_Blaine_Declined, MSGBOX_DEFAULT
	release
	end

SevenIsland_House_Room2_Text_Blaine_Declined:
	.string "No?\n"
	.string "But I'm all fired up!$"

SevenIsland_House_Room2_Eventscript_MoveBlaineLeft:
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_BlaineAroundPlayer
	waitmovement 0
	return

SevenIsland_House_Room2_Eventscript_MoveBlaineUp:
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_BlaineUpToMat
	waitmovement 0
	return

SevenIsland_House_Room2_Movement_BlaineAroundPlayer:
	walk_left
	walk_up
	walk_left
	walk_left
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_BlaineUpToMat:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Eventscript_BlaineBattle:
	setvar TYPE, SET_VISITOR_STATE
	setvar ARGUMENT, FAMECHECKER_BLAINE
	callnative UseBattleHouseVar
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_BlaineBeforeBattle, MSGBOX_DEFAULT
	release
	callnative IsChallengeModeToVarResult
	compare VAR_RESULT, TRUE
	goto_if_eq SevenIsland_House_Room2_Eventscript_ChallengeBlaineBattle
	trainerbattle_no_intro TRAINER_BLAINE_REMATCH, SevenIsland_House_Room2_Text_BlaineLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_BlaineExit
	release
	end

SevenIsland_House_Room2_Text_BlaineBeforeBattle:
	.string "BLAINE: Here's a quiz for you!\n"
	.string "Whose POKéMON are about to be\l"
	.string "reduced to ashes?$"

SevenIsland_House_Room2_Text_BlaineLoss:
	.string "BLAINE: …Apparently mine, hah!$"

SevenIsland_House_Room2_Eventscript_ChallengeBlaineBattle:
	trainerbattle_no_intro TRAINER_BLAINE_REMATCH_CHALLENGE, SevenIsland_House_Room2_Text_BlaineLoss
	setvar TYPE, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	goto SevenIsland_House_Room2_Eventscript_BlaineExit
	release
	end

SevenIsland_House_Room2_Eventscript_BlaineExit:
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_StepFastestLeft
	waitmovement 0
	textcolor 0
	msgbox SevenIsland_House_Room2_Text_BlaineExit, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BLAINE, SevenIsland_House_Room2_Movement_LeaderExits
	waitmovement 0
	playse SE_EXIT
	setvar LEADER_READY, 0
	removeobject LOCALID_BLAINE
	release
	end

SevenIsland_House_Room2_Text_BlaineExit:
	.string "BLAINE: Hah!\n"
	.string "What a rematch!\p"
	.string "I feel a fire burning within me,\n"
	.string "the need to keep getting stronger!\p"
	.string "CINNABAR ISLAND's volcano is getting\n"
	.string "more and more active everyday…\p"
	.string "I should head back and keep an\n"
	.string "eye on it.$"

SevenIsland_House_Room2_Eventscript_CheckInFront:
	compare Y_COORD, 5
	goto_if_eq EventScript_ReleaseEnd
	return

SevenIsland_House_Room2_Movement_LeaderExits:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_4
	set_invisible
	step_end

SevenIsland_House_Room2_Movement_StepFastestLeft:
	walk_in_place_fastest_left
	step_end

SevenIsland_House_Room2_Movement_StepFastestRight:
	walk_in_place_fastest_Right
	step_end
