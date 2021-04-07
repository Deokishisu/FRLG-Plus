.equ BEAUTY, 0
.equ BIRD_KEEPER, 1
.equ BLACK_BELT, 2
.equ BUG_CATCHER, 3
.equ COOLTRAINER, 4
.equ HIKER, 5
.equ LASS, 6
.equ PSYCHIC, 7
.equ SCIENTIST, 8
.equ YOUNGSTER, 9
.equ TRAINER, VAR_0x8009
.equ CLASS, VAR_0x8006
.equ HAVE_TITLE, VAR_0x8007

MasterTrainer_EventScript_Bulbasaur::
    getspeciesname 0, SPECIES_BULBASAUR
    setvar TRAINER, SPECIES_BULBASAUR
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
    call_if_defeated MASTER_BULBASAUR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_BULBASAUR, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_BULBASAUR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Ivysaur::
    getspeciesname 0, SPECIES_IVYSAUR
    setvar TRAINER, SPECIES_IVYSAUR
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
    call_if_defeated MASTER_IVYSAUR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_IVYSAUR, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_IVYSAUR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Venusaur::
    getspeciesname 0, SPECIES_VENUSAUR
    setvar TRAINER, SPECIES_VENUSAUR
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
    call_if_defeated MASTER_VENUSAUR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_VENUSAUR, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_VENUSAUR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_HaveTitle:
    setvar HAVE_TITLE, TRUE
    return

MasterTrainer_EventScript_DetermineScript:
    switch CLASS
    case BEAUTY, MasterTrainer_EventScript_BeautyLass
	case BIRD_KEEPER, MasterTrainer_EventScript_BirdKeeperCooltrainer
	case BLACK_BELT, MasterTrainer_EventScript_BirdKeeperCooltrainer
	case BUG_CATCHER, MasterTrainer_EventScript_BugCatcherYoungster
    case COOLTRAINER, MasterTrainer_EventScript_BirdKeeperCooltrainer
	case HIKER, MasterTrainer_EventScript_BlackBeltHiker
	case LASS, MasterTrainer_EventScript_BeautyLass
    case PSYCHIC, MasterTrainer_EventScript_PsychicScientist
	case SCIENTIST, MasterTrainer_EventScript_PsychicScientist
	case YOUNGSTER, MasterTrainer_EventScript_BugCatcherYoungster
    return

MasterTrainer_EventScript_DetermineContinueScript:
    switch CLASS
    case BEAUTY, MasterTrainer_EventScript_BeautyLassContinue
	case BIRD_KEEPER, MasterTrainer_EventScript_BirdKeeperCooltrainerContinue
	case BLACK_BELT, MasterTrainer_EventScript_BirdKeeperCooltrainerContinue
	case BUG_CATCHER, MasterTrainer_EventScript_BugCatcherYoungsterContinue
    case COOLTRAINER, MasterTrainer_EventScript_BirdKeeperCooltrainerContinue
	case HIKER, MasterTrainer_EventScript_BlackBeltHikerContinue
	case LASS, MasterTrainer_EventScript_BeautyLassContinue
    case PSYCHIC, MasterTrainer_EventScript_PsychicScientistContinue
	case SCIENTIST, MasterTrainer_EventScript_PsychicScientistContinue
	case YOUNGSTER, MasterTrainer_EventScript_BugCatcherYoungsterContinue
    end

MasterTrainer_EventScript_BlackBeltHiker:
MasterTrainer_EventScript_PsychicScientist:
MasterTrainer_EventScript_BugCatcherYoungster:
MasterTrainer_EventScript_BirdKeeperCooltrainer:
MasterTrainer_EventScript_BirdKeeperCooltrainer:
MasterTrainer_EventScript_BeautyLass:
    faceplayer
    msgbox Text_BeautyLass_Intro, MSGBOX_DEFAULT
    callnative CheckMasterPokemonInSlot1
    compare VAR_RESULT, TRUE
    goto_if_ne MasterTrainer_EventScript_BeautyLass_NoMon
    compare HAVE_TITLE, TRUE
    call_if_eq MasterTrainer_EventScript_BeautyLass_HaveTitleAskBattle
    compare HAVE_TITLE, FALSE
    call_if_eq MasterTrainer_EventScript_BeautyLass_AskBattle
    return

MasterTrainer_EventScript_BlackBeltHikerContinue:
MasterTrainer_EventScript_PsychicScientistContinue:
MasterTrainer_EventScript_BugCatcherYoungsterContinue:
MasterTrainer_EventScript_BirdKeeperCooltrainerContinue:
MasterTrainer_EventScript_BirdKeeperCooltrainerContinue:
MasterTrainer_EventScript_BeautyLassContinue:
    special LoadPlayerParty
    specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
    goto_if_eq MasterTrainer_EventScript_BeautyLass_LostBattle
    compare HAVE_TITLE, TRUE
    goto_if_ne MasterTrainer_EventScript_BeautyLass_ConferTitle
    msgbox Text_BeautyLass_AfterBattleWon, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_BeautyLass_NoMon:
    msgbox Text_BeautyLass_NoMon, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BeautyLass_HaveTitleAskBattle:
    msgbox Text_BeautyLass_HaveTitleAskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_BeautyLass_DeclinedBattle
    msgbox Text_BeautyLass_AcceptedBattle, MSGBOX_DEFAULT
    special SavePlayerParty
    callnative ClearAllButFirstPokemon
    callnative HealPlayerPartyOak
    return

MasterTrainer_EventScript_BeautyLass_AskBattle:
    msgbox Text_BeautyLass_AskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_BeautyLass_DeclinedBattle
    msgbox Text_BeautyLass_AcceptedBattle, MSGBOX_DEFAULT
    special SavePlayerParty
    callnative ClearAllButFirstPokemon
    callnative HealPlayerPartyOak
    return

MasterTrainer_EventScript_BeautyLass_DeclinedBattle:
    msgbox Text_BeautyLass_DeclinedBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BeautyLass_LostBattle:
    msgbox Text_BeautyLass_LostBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BeautyLass_ConferTitle:
    msgbox Text_BeautyLass_GiveTitle, MSGBOX_DEFAULT
    message Text_MasterTrainer_EarnTitle
    waitmessage
    playfanfare MUS_LEVEL_UP
    waitfanfare
    waitbuttonpress
    msgbox Text_BeautyLass_AnotherBattleSometime, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    setobjectmovementtypeinstant VAR_LAST_TALKED, MOVEMENT_TYPE_FACE_DOWN
    release
    end

Text_BeautyLass_Intro:
    .string "I'm the {STR_VAR_1} MASTER!\p"
    .string "My goal is to find the ulimate\n"
    .string "{STR_VAR_1}!$"

Text_BeautyLass_NoMon:
    .string "Don't forget to put your {STR_VAR_1}\n"
    .string "in the top-left position of your\l"
    .string "party if you want to battle me!$"

Text_BeautyLass_AskBattle:
    .string "Hey, your {STR_VAR_1} looks pretty\n"
    .string "strong!\p"
    .string "Can I battle it with my {STR_VAR_1}?\n"
    .string "Pleeeease?$"

Text_BeautyLass_HaveTitleAskBattle:
    .string "Hey there! Has your {STR_VAR_1}\n"
    .string "gotten any stronger?\p"
    .string "Can I battle it with my {STR_VAR_1}?\n"
    .string "Pleeeease?$"

Text_BeautyLass_DeclinedBattle:
    .string "Boo!\n"
    .string "I wanted to show off my {STR_VAR_1}!$"

Text_BeautyLass_AcceptedBattle:
    .string "Let's see which is the stronger\n"
    .string "{STR_VAR_1}!$"

Text_BeautyLass_LostBattle:
    .string "Hee hee! I knew my {STR_VAR_1}\n"
    .string "was the best of the best!$"

Text_BeautyLass_BattleLoss:
    .string "That strength is the real deal!$"

Text_BeautyLass_AfterBattleWon: //already have title
    .string "Oh wow… Your {STR_VAR_1} is way\n"
    .string "stronger than I thought!\p"
    .string "We should have another battle\n"
    .string "sometime, since we both love\l"
    .string "{STR_VAR_1} so much!$"

Text_BeautyLass_GiveTitle:
    .string "Oh wow… Your {STR_VAR_1} is way\n"
    .string "stronger than I thought!\p"
    .string "I think you deserve to be called\n"
    .string "a {STR_VAR_1} MASTER!$"

Text_MasterTrainer_EarnTitle:
    .string "{COLOR RED}You have earned the title of\n"
    .string "{STR_VAR_1} MASTER!$"

Text_BeautyLass_AnotherBattleSometime:
    .string "We should have another battle\n"
    .string "sometime, since we both love\l"
    .string "{STR_VAR_1} so much!$"
