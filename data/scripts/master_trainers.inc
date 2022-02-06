.equ BEAUTY, 0
.equ LASS, 0
.equ SWIMMER, 0
.equ BIRD_KEEPER, 1
.equ COOLTRAINER, 1
.equ BLACK_BELT, 2
.equ HIKER, 2
.equ BUG_CATCHER, 3
.equ YOUNGSTER, 3
.equ PSYCHIC, 4
.equ SCIENTIST, 4
.equ TRAINER, VAR_0x8009
.equ CLASS, VAR_0x8006
.equ HAVE_TITLE, VAR_0x8007

MasterTrainer_EventScript_Bulbasaur::
    getspeciesname 0, SPECIES_BULBASAUR
    setvar TRAINER, SPECIES_BULBASAUR
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
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
	setvar HAVE_TITLE, FALSE
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
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_VENUSAUR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_VENUSAUR, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_VENUSAUR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Charmander::
    getspeciesname 0, SPECIES_CHARMANDER
    setvar TRAINER, SPECIES_CHARMANDER
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_CHARMANDER, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_CHARMANDER, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_CHARMANDER
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Charmeleon::
    getspeciesname 0, SPECIES_CHARMELEON
    setvar TRAINER, SPECIES_CHARMELEON
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_CHARMELEON, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_CHARMELEON, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_CHARMELEON
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Charizard::
    getspeciesname 0, SPECIES_CHARIZARD
    setvar TRAINER, SPECIES_CHARIZARD
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_CHARIZARD, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_CHARIZARD, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_CHARIZARD
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Squirtle::
    getspeciesname 0, SPECIES_SQUIRTLE
    setvar TRAINER, SPECIES_SQUIRTLE
    setvar CLASS, BEAUTY
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SQUIRTLE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SQUIRTLE, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_SQUIRTLE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Wartortle::
    getspeciesname 0, SPECIES_WARTORTLE
    setvar TRAINER, SPECIES_WARTORTLE
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_WARTORTLE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_WARTORTLE, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_WARTORTLE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Blastoise::
    getspeciesname 0, SPECIES_BLASTOISE
    setvar TRAINER, SPECIES_BLASTOISE
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_BLASTOISE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_BLASTOISE, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_BLASTOISE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Caterpie::
    getspeciesname 0, SPECIES_CATERPIE
    setvar TRAINER, SPECIES_CATERPIE
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_CATERPIE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_CATERPIE, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_CATERPIE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Metapod::
    getspeciesname 0, SPECIES_METAPOD
    setvar TRAINER, SPECIES_METAPOD
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_METAPOD, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_METAPOD, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_METAPOD
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Butterfree::
    getspeciesname 0, SPECIES_BUTTERFREE
    setvar TRAINER, SPECIES_BUTTERFREE
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_BUTTERFREE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_BUTTERFREE, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_BUTTERFREE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Weedle::
    getspeciesname 0, SPECIES_WEEDLE
    setvar TRAINER, SPECIES_WEEDLE
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_WEEDLE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_WEEDLE, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_WEEDLE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Kakuna::
    getspeciesname 0, SPECIES_KAKUNA
    setvar TRAINER, SPECIES_KAKUNA
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_KAKUNA, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_KAKUNA, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_KAKUNA
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Beedrill::
    getspeciesname 0, SPECIES_BEEDRILL
    setvar TRAINER, SPECIES_BEEDRILL
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_BEEDRILL, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_BEEDRILL, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_BEEDRILL
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Pidgey::
    getspeciesname 0, SPECIES_PIDGEY
    setvar TRAINER, SPECIES_PIDGEY
    setvar CLASS, BIRD_KEEPER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PIDGEY, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PIDGEY, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_PIDGEY
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Pidgeotto::
    getspeciesname 0, SPECIES_PIDGEOTTO
    setvar TRAINER, SPECIES_PIDGEOTTO
    setvar CLASS, BIRD_KEEPER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PIDGEOTTO, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PIDGEOTTO, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_PIDGEOTTO
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Pidgeot::
    getspeciesname 0, SPECIES_PIDGEOT
    setvar TRAINER, SPECIES_PIDGEOT
    setvar CLASS, BIRD_KEEPER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PIDGEOT, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PIDGEOT, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_PIDGEOT
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Rattata::
    getspeciesname 0, SPECIES_RATTATA
    setvar TRAINER, SPECIES_RATTATA
    setvar CLASS, YOUNGSTER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_RATTATA, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_RATTATA, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_RATTATA
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Raticate::
    getspeciesname 0, SPECIES_RATICATE
    setvar TRAINER, SPECIES_RATICATE
    setvar CLASS, YOUNGSTER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_RATICATE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_RATICATE, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_RATICATE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Spearow::
    getspeciesname 0, SPECIES_SPEAROW
    setvar TRAINER, SPECIES_SPEAROW
    setvar CLASS, BIRD_KEEPER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SPEAROW, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SPEAROW, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_SPEAROW
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Fearow::
    getspeciesname 0, SPECIES_FEAROW
    setvar TRAINER, SPECIES_FEAROW
    setvar CLASS, BIRD_KEEPER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_FEAROW, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_FEAROW, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_FEAROW
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Ekans::
    getspeciesname 0, SPECIES_EKANS
    setvar TRAINER, SPECIES_EKANS
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_EKANS, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_EKANS, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_EKANS
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Arbok::
    getspeciesname 0, SPECIES_ARBOK
    setvar TRAINER, SPECIES_ARBOK
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ARBOK, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_ARBOK, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_ARBOK
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Pikachu::
    getspeciesname 0, SPECIES_PIKACHU
    setvar TRAINER, SPECIES_PIKACHU
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PIKACHU, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PIKACHU, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_PIKACHU
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Raichu::
    getspeciesname 0, SPECIES_RAICHU
    setvar TRAINER, SPECIES_RAICHU
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_RAICHU, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_RAICHU, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_RAICHU
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Sandshrew::
    getspeciesname 0, SPECIES_SANDSHREW
    setvar TRAINER, SPECIES_SANDSHREW
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SANDSHREW, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SANDSHREW, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_SANDSHREW
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Sandslash::
    getspeciesname 0, SPECIES_SANDSLASH
    setvar TRAINER, SPECIES_SANDSLASH
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SANDSLASH, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SANDSLASH, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_SANDSLASH
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_NidoranF::
    getspeciesname 0, SPECIES_NIDORAN_F
    setvar TRAINER, SPECIES_NIDORAN_F
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_NIDORAN_F, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_NIDORAN_F, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_NIDORAN_F
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Nidorina::
    getspeciesname 0, SPECIES_NIDORINA
    setvar TRAINER, SPECIES_NIDORINA
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_NIDORINA, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_NIDORINA, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_NIDORINA
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Nidoqueen::
    getspeciesname 0, SPECIES_NIDOQUEEN
    setvar TRAINER, SPECIES_NIDOQUEEN
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_NIDOQUEEN, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_NIDOQUEEN, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_NIDOQUEEN
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_NidoranM::
    getspeciesname 0, SPECIES_NIDORAN_M
    setvar TRAINER, SPECIES_NIDORAN_M
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_NIDORAN_M, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_NIDORAN_M, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_NIDORAN_M
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Nidorino::
    getspeciesname 0, SPECIES_NIDORINO
    setvar TRAINER, SPECIES_NIDORINO
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_NIDORINO, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_NIDORINO, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_NIDORINO
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Nidoking::
    getspeciesname 0, SPECIES_NIDOKING
    setvar TRAINER, SPECIES_NIDOKING
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_NIDOKING, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_NIDOKING, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_NIDOKING
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Clefairy::
    getspeciesname 0, SPECIES_CLEFAIRY
    setvar TRAINER, SPECIES_CLEFAIRY
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_CLEFAIRY, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_CLEFAIRY, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_CLEFAIRY
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Clefable::
    getspeciesname 0, SPECIES_CLEFABLE
    setvar TRAINER, SPECIES_CLEFABLE
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_CLEFABLE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_CLEFABLE, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_CLEFABLE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Vulpix::
    getspeciesname 0, SPECIES_VULPIX
    setvar TRAINER, SPECIES_VULPIX
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_VULPIX, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_VULPIX, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_VULPIX
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Ninetales::
    getspeciesname 0, SPECIES_NINETALES
    setvar TRAINER, SPECIES_NINETALES
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_NINETALES, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_NINETALES, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_NINETALES
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Jigglypuff::
    getspeciesname 0, SPECIES_JIGGLYPUFF
    setvar TRAINER, SPECIES_JIGGLYPUFF
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_JIGGLYPUFF, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_JIGGLYPUFF, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_JIGGLYPUFF
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Wigglytuff::
    getspeciesname 0, SPECIES_WIGGLYTUFF
    setvar TRAINER, SPECIES_WIGGLYTUFF
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_WIGGLYTUFF, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_WIGGLYTUFF, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_WIGGLYTUFF
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Zubat::
    getspeciesname 0, SPECIES_ZUBAT
    setvar TRAINER, SPECIES_ZUBAT
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ZUBAT, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_ZUBAT, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_ZUBAT
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Golbat::
    getspeciesname 0, SPECIES_GOLBAT
    setvar TRAINER, SPECIES_GOLBAT
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GOLBAT, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GOLBAT, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_GOLBAT
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Oddish::
    getspeciesname 0, SPECIES_ODDISH
    setvar TRAINER, SPECIES_ODDISH
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ODDISH, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_ODDISH, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_ODDISH
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Gloom::
    getspeciesname 0, SPECIES_GLOOM
    setvar TRAINER, SPECIES_GLOOM
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GLOOM, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GLOOM, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_GLOOM
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Vileplume::
    getspeciesname 0, SPECIES_VILEPLUME
    setvar TRAINER, SPECIES_VILEPLUME
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_VILEPLUME, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_VILEPLUME, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_VILEPLUME
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Paras::
    getspeciesname 0, SPECIES_PARAS
    setvar TRAINER, SPECIES_PARAS
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PARAS, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PARAS, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_PARAS
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Parasect::
    getspeciesname 0, SPECIES_PARASECT
    setvar TRAINER, SPECIES_PARASECT
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PARASECT, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PARASECT, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_PARASECT
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Venonat::
    getspeciesname 0, SPECIES_VENONAT
    setvar TRAINER, SPECIES_VENONAT
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_VENONAT, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_VENONAT, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_VENONAT
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Venomoth::
    getspeciesname 0, SPECIES_VENOMOTH
    setvar TRAINER, SPECIES_VENOMOTH
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_VENOMOTH, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_VENOMOTH, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_VENOMOTH
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Diglett::
    getspeciesname 0, SPECIES_DIGLETT
    setvar TRAINER, SPECIES_DIGLETT
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DIGLETT, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_DIGLETT, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_DIGLETT
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Dugtrio::
    getspeciesname 0, SPECIES_DUGTRIO
    setvar TRAINER, SPECIES_DUGTRIO
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DUGTRIO, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_DUGTRIO, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_DUGTRIO
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Meowth::
    getspeciesname 0, SPECIES_MEOWTH
    setvar TRAINER, SPECIES_MEOWTH
    setvar CLASS, YOUNGSTER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MEOWTH, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MEOWTH, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_MEOWTH
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Persian::
    getspeciesname 0, SPECIES_PERSIAN
    setvar TRAINER, SPECIES_PERSIAN
    setvar CLASS, YOUNGSTER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PERSIAN, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PERSIAN, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_PERSIAN
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Psyduck::
    getspeciesname 0, SPECIES_PSYDUCK
    setvar TRAINER, SPECIES_PSYDUCK
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PSYDUCK, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PSYDUCK, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_PSYDUCK
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Golduck::
    getspeciesname 0, SPECIES_GOLDUCK
    setvar TRAINER, SPECIES_GOLDUCK
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GOLDUCK, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GOLDUCK, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_GOLDUCK
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Mankey::
    getspeciesname 0, SPECIES_MANKEY
    setvar TRAINER, SPECIES_MANKEY
    setvar CLASS, BLACK_BELT
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MANKEY, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MANKEY, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_MANKEY
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Primeape::
    getspeciesname 0, SPECIES_PRIMEAPE
    setvar TRAINER, SPECIES_PRIMEAPE
    setvar CLASS, BLACK_BELT
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PRIMEAPE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PRIMEAPE, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_PRIMEAPE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Growlithe::
    getspeciesname 0, SPECIES_GROWLITHE
    setvar TRAINER, SPECIES_GROWLITHE
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GROWLITHE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GROWLITHE, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_GROWLITHE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Arcanine::
    getspeciesname 0, SPECIES_ARCANINE
    setvar TRAINER, SPECIES_ARCANINE
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ARCANINE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_ARCANINE, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_ARCANINE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Poliwag::
    getspeciesname 0, SPECIES_POLIWAG
    setvar TRAINER, SPECIES_POLIWAG
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_POLIWAG, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_POLIWAG, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_POLIWAG
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Poliwhirl::
    getspeciesname 0, SPECIES_POLIWHIRL
    setvar TRAINER, SPECIES_POLIWHIRL
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_POLIWHIRL, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_POLIWHIRL, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_POLIWHIRL
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Poliwrath::
    getspeciesname 0, SPECIES_POLIWRATH
    setvar TRAINER, SPECIES_POLIWRATH
    setvar CLASS, BLACK_BELT
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_POLIWRATH, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_POLIWRATH, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_POLIWRATH
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Abra::
    getspeciesname 0, SPECIES_ABRA
    setvar TRAINER, SPECIES_ABRA
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ABRA, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_ABRA, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_ABRA
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Kadabra::
    getspeciesname 0, SPECIES_KADABRA
    setvar TRAINER, SPECIES_KADABRA
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_KADABRA, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_KADABRA, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_KADABRA
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Alakazam::
    getspeciesname 0, SPECIES_ALAKAZAM
    setvar TRAINER, SPECIES_ALAKAZAM
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ALAKAZAM, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_ALAKAZAM, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_ALAKAZAM
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Machop::
    getspeciesname 0, SPECIES_MACHOP
    setvar TRAINER, SPECIES_MACHOP
    setvar CLASS, BLACK_BELT
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MACHOP, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MACHOP, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_MACHOP
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Machoke::
    getspeciesname 0, SPECIES_MACHOKE
    setvar TRAINER, SPECIES_MACHOKE
    setvar CLASS, BLACK_BELT
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MACHOKE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MACHOKE, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_MACHOKE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Machamp::
    getspeciesname 0, SPECIES_MACHAMP
    setvar TRAINER, SPECIES_MACHAMP
    setvar CLASS, BLACK_BELT
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MACHAMP, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MACHAMP, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_MACHAMP
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Bellsprout::
    getspeciesname 0, SPECIES_BELLSPROUT
    setvar TRAINER, SPECIES_BELLSPROUT
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_BELLSPROUT, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_BELLSPROUT, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_BELLSPROUT
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Weepinbell::
    getspeciesname 0, SPECIES_WEEPINBELL
    setvar TRAINER, SPECIES_WEEPINBELL
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_WEEPINBELL, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_WEEPINBELL, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_WEEPINBELL
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Victreebel::
    getspeciesname 0, SPECIES_VICTREEBEL
    setvar TRAINER, SPECIES_VICTREEBEL
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_VICTREEBEL, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_VICTREEBEL, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_VICTREEBEL
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Tentacool::
    getspeciesname 0, SPECIES_TENTACOOL
    setvar TRAINER, SPECIES_TENTACOOL
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_TENTACOOL, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_TENTACOOL, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_TENTACOOL
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Tentacruel::
    getspeciesname 0, SPECIES_TENTACRUEL
    setvar TRAINER, SPECIES_TENTACRUEL
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_TENTACRUEL, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_TENTACRUEL, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_TENTACRUEL
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Geodude::
    getspeciesname 0, SPECIES_GEODUDE
    setvar TRAINER, SPECIES_GEODUDE
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GEODUDE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GEODUDE, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_GEODUDE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Graveler::
    getspeciesname 0, SPECIES_GRAVELER
    setvar TRAINER, SPECIES_GRAVELER
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GRAVELER, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GRAVELER, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_GRAVELER
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Golem::
    getspeciesname 0, SPECIES_GOLEM
    setvar TRAINER, SPECIES_GOLEM
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GOLEM, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GOLEM, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_GOLEM
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Ponyta::
    getspeciesname 0, SPECIES_PONYTA
    setvar TRAINER, SPECIES_PONYTA
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PONYTA, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PONYTA, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_PONYTA
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Rapidash::
    getspeciesname 0, SPECIES_RAPIDASH
    setvar TRAINER, SPECIES_RAPIDASH
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_RAPIDASH, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_RAPIDASH, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_RAPIDASH
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Slowpoke::
    getspeciesname 0, SPECIES_SLOWPOKE
    setvar TRAINER, SPECIES_SLOWPOKE
    setvar CLASS, BEAUTY
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SLOWPOKE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SLOWPOKE, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_SLOWPOKE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Slowbro::
    getspeciesname 0, SPECIES_SLOWBRO
    setvar TRAINER, SPECIES_SLOWBRO
    setvar CLASS, BEAUTY
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SLOWBRO, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SLOWBRO, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_SLOWBRO
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Magnemite::
    getspeciesname 0, SPECIES_MAGNEMITE
    setvar TRAINER, SPECIES_MAGNEMITE
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MAGNEMITE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MAGNEMITE, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_MAGNEMITE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Magneton::
    getspeciesname 0, SPECIES_MAGNETON
    setvar TRAINER, SPECIES_MAGNETON
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MAGNETON, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MAGNETON, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_MAGNETON
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Farfetchd::
    getspeciesname 0, SPECIES_FARFETCHD
    setvar TRAINER, SPECIES_FARFETCHD
    setvar CLASS, BIRD_KEEPER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_FARFETCHD, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_FARFETCHD, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_FARFETCHD
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Doduo::
    getspeciesname 0, SPECIES_DODUO
    setvar TRAINER, SPECIES_DODUO
    setvar CLASS, BIRD_KEEPER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DODUO, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_DODUO, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_DODUO
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Dodrio::
    getspeciesname 0, SPECIES_DODRIO
    setvar TRAINER, SPECIES_DODRIO
    setvar CLASS, BIRD_KEEPER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DODRIO, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_DODRIO, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_DODRIO
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Seel::
    getspeciesname 0, SPECIES_SEEL
    setvar TRAINER, SPECIES_SEEL
    setvar CLASS, BEAUTY
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SEEL, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SEEL, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_SEEL
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Dewgong::
    getspeciesname 0, SPECIES_DEWGONG
    setvar TRAINER, SPECIES_DEWGONG
    setvar CLASS, BEAUTY
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DEWGONG, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_DEWGONG, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_DEWGONG
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Grimer::
    getspeciesname 0, SPECIES_GRIMER
    setvar TRAINER, SPECIES_GRIMER
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GRIMER, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GRIMER, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_GRIMER
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Muk::
    getspeciesname 0, SPECIES_MUK
    setvar TRAINER, SPECIES_MUK
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MUK, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MUK, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_MUK
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Shellder::
    getspeciesname 0, SPECIES_SHELLDER
    setvar TRAINER, SPECIES_SHELLDER
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SHELLDER, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SHELLDER, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_SHELLDER
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Cloyster::
    getspeciesname 0, SPECIES_CLOYSTER
    setvar TRAINER, SPECIES_CLOYSTER
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_CLOYSTER, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_CLOYSTER, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_CLOYSTER
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Gastly::
    getspeciesname 0, SPECIES_GASTLY
    setvar TRAINER, SPECIES_GASTLY
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GASTLY, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GASTLY, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_GASTLY
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Haunter::
    getspeciesname 0, SPECIES_HAUNTER
    setvar TRAINER, SPECIES_HAUNTER
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_HAUNTER, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_HAUNTER, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_HAUNTER
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Gengar::
    getspeciesname 0, SPECIES_GENGAR
    setvar TRAINER, SPECIES_GENGAR
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GENGAR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GENGAR, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_GENGAR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Onix::
    getspeciesname 0, SPECIES_ONIX
    setvar TRAINER, SPECIES_ONIX
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ONIX, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_ONIX, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_ONIX
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Drowzee::
    getspeciesname 0, SPECIES_DROWZEE
    setvar TRAINER, SPECIES_DROWZEE
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DROWZEE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_DROWZEE, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_DROWZEE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Hypno::
    getspeciesname 0, SPECIES_HYPNO
    setvar TRAINER, SPECIES_HYPNO
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_HYPNO, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_HYPNO, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_HYPNO
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Krabby::
    getspeciesname 0, SPECIES_KRABBY
    setvar TRAINER, SPECIES_KRABBY
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_KRABBY, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_KRABBY, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_KRABBY
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Kingler::
    getspeciesname 0, SPECIES_KINGLER
    setvar TRAINER, SPECIES_KINGLER
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_KINGLER, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_KINGLER, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_KINGLER
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Voltorb::
    getspeciesname 0, SPECIES_VOLTORB
    setvar TRAINER, SPECIES_VOLTORB
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_VOLTORB, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_VOLTORB, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_VOLTORB
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Electrode::
    getspeciesname 0, SPECIES_ELECTRODE
    setvar TRAINER, SPECIES_ELECTRODE
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ELECTRODE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_ELECTRODE, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_ELECTRODE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Exeggcute::
    getspeciesname 0, SPECIES_EXEGGCUTE
    setvar TRAINER, SPECIES_EXEGGCUTE
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_EXEGGCUTE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_EXEGGCUTE, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_EXEGGCUTE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Exeggutor::
    getspeciesname 0, SPECIES_EXEGGUTOR
    setvar TRAINER, SPECIES_EXEGGUTOR
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_EXEGGUTOR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_EXEGGUTOR, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_EXEGGUTOR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Cubone::
    getspeciesname 0, SPECIES_CUBONE
    setvar TRAINER, SPECIES_CUBONE
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_CUBONE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_CUBONE, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_CUBONE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Marowak::
    getspeciesname 0, SPECIES_MAROWAK
    setvar TRAINER, SPECIES_MAROWAK
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MAROWAK, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MAROWAK, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_MAROWAK
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Hitmonlee::
    getspeciesname 0, SPECIES_HITMONLEE
    setvar TRAINER, SPECIES_HITMONLEE
    setvar CLASS, BLACK_BELT
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_HITMONLEE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_HITMONLEE, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_HITMONLEE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Hitmonchan::
    getspeciesname 0, SPECIES_HITMONCHAN
    setvar TRAINER, SPECIES_HITMONCHAN
    setvar CLASS, BLACK_BELT
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_HITMONCHAN, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_HITMONCHAN, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_HITMONCHAN
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Lickitung::
    getspeciesname 0, SPECIES_LICKITUNG
    setvar TRAINER, SPECIES_LICKITUNG
    setvar CLASS, YOUNGSTER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_LICKITUNG, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_LICKITUNG, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_LICKITUNG
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Koffing::
    getspeciesname 0, SPECIES_KOFFING
    setvar TRAINER, SPECIES_KOFFING
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_KOFFING, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_KOFFING, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_KOFFING
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Weezing::
    getspeciesname 0, SPECIES_WEEZING
    setvar TRAINER, SPECIES_WEEZING
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_WEEZING, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_WEEZING, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_WEEZING
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Rhyhorn::
    getspeciesname 0, SPECIES_RHYHORN
    setvar TRAINER, SPECIES_RHYHORN
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_RHYHORN, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_RHYHORN, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_RHYHORN
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Rhydon::
    getspeciesname 0, SPECIES_RHYDON
    setvar TRAINER, SPECIES_RHYDON
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_RHYDON, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_RHYDON, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_RHYDON
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Chansey::
    getspeciesname 0, SPECIES_CHANSEY
    setvar TRAINER, SPECIES_CHANSEY
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_CHANSEY, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_CHANSEY, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_CHANSEY
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Tangela::
    getspeciesname 0, SPECIES_TANGELA
    setvar TRAINER, SPECIES_TANGELA
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_TANGELA, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_TANGELA, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_TANGELA
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Kangaskhan::
    getspeciesname 0, SPECIES_KANGASKHAN
    setvar TRAINER, SPECIES_KANGASKHAN
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_KANGASKHAN, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_KANGASKHAN, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_KANGASKHAN
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Horsea::
    getspeciesname 0, SPECIES_HORSEA
    setvar TRAINER, SPECIES_HORSEA
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_HORSEA, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_HORSEA, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_HORSEA
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Seadra::
    getspeciesname 0, SPECIES_SEADRA
    setvar TRAINER, SPECIES_SEADRA
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SEADRA, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SEADRA, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_SEADRA
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Goldeen::
    getspeciesname 0, SPECIES_GOLDEEN
    setvar TRAINER, SPECIES_GOLDEEN
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GOLDEEN, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GOLDEEN, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_GOLDEEN
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Seaking::
    getspeciesname 0, SPECIES_SEAKING
    setvar TRAINER, SPECIES_SEAKING
    setvar CLASS, SWIMMER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SEAKING, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SEAKING, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_SEAKING
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Staryu::
    getspeciesname 0, SPECIES_STARYU
    setvar TRAINER, SPECIES_STARYU
    setvar CLASS, BEAUTY
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_STARYU, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_STARYU, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_STARYU
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Starmie::
    getspeciesname 0, SPECIES_STARMIE
    setvar TRAINER, SPECIES_STARMIE
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_STARMIE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_STARMIE, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_STARMIE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_MrMime::
    getspeciesname 0, SPECIES_MR_MIME
    setvar TRAINER, SPECIES_MR_MIME
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MR_MIME, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MR_MIME, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_MR_MIME
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Scyther::
    getspeciesname 0, SPECIES_SCYTHER
    setvar TRAINER, SPECIES_SCYTHER
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SCYTHER, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SCYTHER, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_SCYTHER
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Jynx::
    getspeciesname 0, SPECIES_JYNX
    setvar TRAINER, SPECIES_JYNX
    setvar CLASS, PSYCHIC
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_JYNX, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_JYNX, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_JYNX
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Electabuzz::
    getspeciesname 0, SPECIES_ELECTABUZZ
    setvar TRAINER, SPECIES_ELECTABUZZ
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ELECTABUZZ, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_ELECTABUZZ, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_ELECTABUZZ
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Magmar::
    getspeciesname 0, SPECIES_MAGMAR
    setvar TRAINER, SPECIES_MAGMAR
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MAGMAR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MAGMAR, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_MAGMAR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Pinsir::
    getspeciesname 0, SPECIES_PINSIR
    setvar TRAINER, SPECIES_PINSIR
    setvar CLASS, BUG_CATCHER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PINSIR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PINSIR, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_PINSIR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Tauros::
    getspeciesname 0, SPECIES_TAUROS
    setvar TRAINER, SPECIES_TAUROS
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_TAUROS, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_TAUROS, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_TAUROS
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Magikarp::
    getspeciesname 0, SPECIES_MAGIKARP
    setvar TRAINER, SPECIES_MAGIKARP
    setvar CLASS, YOUNGSTER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MAGIKARP, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_MAGIKARP, Text_BugCatcherYoungster_BattleLoss
    getspeciesname 0, SPECIES_MAGIKARP
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Gyarados::
    getspeciesname 0, SPECIES_GYARADOS
    setvar TRAINER, SPECIES_GYARADOS
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_GYARADOS, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_GYARADOS, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_GYARADOS
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Lapras::
    getspeciesname 0, SPECIES_LAPRAS
    setvar TRAINER, SPECIES_LAPRAS
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_LAPRAS, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_LAPRAS, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_LAPRAS
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Ditto::
    getspeciesname 0, SPECIES_DITTO
    setvar TRAINER, SPECIES_DITTO
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DITTO, MasterTrainer_EventScript_HaveTitleNoBattle
    call MasterTrainer_EventScript_NoBattleContinue
    settrainerflag MASTER_DITTO
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_Eevee::
    getspeciesname 0, SPECIES_EEVEE
    setvar TRAINER, SPECIES_EEVEE
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_EEVEE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_EEVEE, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_EEVEE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Vaporeon::
    getspeciesname 0, SPECIES_VAPOREON
    setvar TRAINER, SPECIES_VAPOREON
    setvar CLASS, LASS
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_VAPOREON, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_VAPOREON, Text_BeautyLass_BattleLoss
    getspeciesname 0, SPECIES_VAPOREON
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Jolteon::
    getspeciesname 0, SPECIES_JOLTEON
    setvar TRAINER, SPECIES_JOLTEON
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_JOLTEON, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_JOLTEON, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_JOLTEON
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Flareon::
    getspeciesname 0, SPECIES_FLAREON
    setvar TRAINER, SPECIES_FLAREON
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_FLAREON, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_FLAREON, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_FLAREON
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Porygon::
    getspeciesname 0, SPECIES_PORYGON
    setvar TRAINER, SPECIES_PORYGON
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_PORYGON, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_PORYGON, Text_PsychicScientist_BattleLoss
    getspeciesname 0, SPECIES_PORYGON
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Omanyte::
    getspeciesname 0, SPECIES_OMANYTE
    setvar TRAINER, SPECIES_OMANYTE
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_OMANYTE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_OMANYTE, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_OMANYTE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Omastar::
    getspeciesname 0, SPECIES_OMASTAR
    setvar TRAINER, SPECIES_OMASTAR
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_OMASTAR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_OMASTAR, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_OMASTAR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Kabuto::
    getspeciesname 0, SPECIES_KABUTO
    setvar TRAINER, SPECIES_KABUTO
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_KABUTO, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_KABUTO, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_KABUTO
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Kabutops::
    getspeciesname 0, SPECIES_KABUTOPS
    setvar TRAINER, SPECIES_KABUTOPS
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_KABUTOPS, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_KABUTOPS, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_KABUTOPS
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Aerodactyl::
    getspeciesname 0, SPECIES_AERODACTYL
    setvar TRAINER, SPECIES_AERODACTYL
    setvar CLASS, HIKER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_AERODACTYL, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_AERODACTYL, Text_BlackBeltHiker_BattleLoss
    getspeciesname 0, SPECIES_AERODACTYL
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Snorlax::
    getspeciesname 0, SPECIES_SNORLAX
    setvar TRAINER, SPECIES_SNORLAX
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_SNORLAX, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_SNORLAX, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_SNORLAX
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Articuno::
    getspeciesname 0, SPECIES_ARTICUNO
    setvar TRAINER, SPECIES_ARTICUNO
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ARTICUNO, MasterTrainer_EventScript_HaveTitleNoBattle
    call MasterTrainer_EventScript_NoBattleContinue
    settrainerflag MASTER_ARTICUNO
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_Zapdos::
    getspeciesname 0, SPECIES_ZAPDOS
    setvar TRAINER, SPECIES_ZAPDOS
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_ZAPDOS, MasterTrainer_EventScript_HaveTitleNoBattle
    call MasterTrainer_EventScript_NoBattleContinue
    settrainerflag MASTER_ZAPDOS
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_Moltres::
    getspeciesname 0, SPECIES_MOLTRES
    setvar TRAINER, SPECIES_MOLTRES
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MOLTRES, MasterTrainer_EventScript_HaveTitleNoBattle
    call MasterTrainer_EventScript_NoBattleContinue
    settrainerflag MASTER_MOLTRES
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_Dratini::
    getspeciesname 0, SPECIES_DRATINI
    setvar TRAINER, SPECIES_DRATINI
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DRATINI, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_DRATINI, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_DRATINI
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Dragonair::
    getspeciesname 0, SPECIES_DRAGONAIR
    setvar TRAINER, SPECIES_DRAGONAIR
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DRAGONAIR, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_DRAGONAIR, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_DRAGONAIR
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Dragonite::
    getspeciesname 0, SPECIES_DRAGONITE
    setvar TRAINER, SPECIES_DRAGONITE
    setvar CLASS, COOLTRAINER
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_DRAGONITE, MasterTrainer_EventScript_HaveTitle
    call MasterTrainer_EventScript_DetermineScript
    trainerbattle_no_intro MASTER_DRAGONITE, Text_BirdKeeperCooltrainer_BattleLoss
    getspeciesname 0, SPECIES_DRAGONITE
    goto MasterTrainer_EventScript_DetermineContinueScript

MasterTrainer_EventScript_Mewtwo::
    getspeciesname 0, SPECIES_MEWTWO
    setvar TRAINER, SPECIES_MEWTWO
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MEWTWO, MasterTrainer_EventScript_HaveTitleNoBattle
    call MasterTrainer_EventScript_NoBattleContinue
    settrainerflag MASTER_MEWTWO
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_Mew::
    getspeciesname 0, SPECIES_MEW
    setvar TRAINER, SPECIES_MEW
    setvar CLASS, SCIENTIST
    setflag FLAG_MASTER_TRAINER_BATTLE
	setvar HAVE_TITLE, FALSE
    call_if_defeated MASTER_MEW, MasterTrainer_EventScript_HaveTitleNoBattle
    call MasterTrainer_EventScript_NoBattleContinue
    settrainerflag MASTER_MEW
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_HaveTitle:
    setvar HAVE_TITLE, TRUE
    return

MasterTrainer_EventScript_HaveTitleNoBattle:
    msgbox Text_Scientist_HaveTitleNoBattle MSGBOX_NPC
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

Text_Scientist_HaveTitleNoBattle:
    .string "Oh, good to see you again.\n"
    .string "How's your {STR_VAR_1} doing?$"

MasterTrainer_EventScript_DetermineScript:
    lock
    switch CLASS
    case BEAUTY, MasterTrainer_EventScript_BeautyLass
	case BIRD_KEEPER, MasterTrainer_EventScript_BirdKeeperCooltrainer
	case BLACK_BELT, MasterTrainer_EventScript_BlackBeltHiker
	case BUG_CATCHER, MasterTrainer_EventScript_BugCatcherYoungster
    case PSYCHIC, MasterTrainer_EventScript_PsychicScientist
    return

MasterTrainer_EventScript_DetermineContinueScript:
    switch CLASS
    case BEAUTY, MasterTrainer_EventScript_BeautyLassContinue
	case BIRD_KEEPER, MasterTrainer_EventScript_BirdKeeperCooltrainerContinue
	case BLACK_BELT, MasterTrainer_EventScript_BlackBeltHikerContinue
	case BUG_CATCHER, MasterTrainer_EventScript_BugCatcherYoungsterContinue
    case PSYCHIC, MasterTrainer_EventScript_PsychicScientistContinue
    end

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

MasterTrainer_EventScript_BirdKeeperCooltrainer:
    faceplayer
    msgbox Text_BirdKeeperCooltrainer_Intro, MSGBOX_DEFAULT
    callnative CheckMasterPokemonInSlot1
    compare VAR_RESULT, TRUE
    goto_if_ne MasterTrainer_EventScript_BirdKeeperCooltrainer_NoMon
    compare HAVE_TITLE, TRUE
    call_if_eq MasterTrainer_EventScript_BirdKeeperCooltrainer_HaveTitleAskBattle
    compare HAVE_TITLE, FALSE
    call_if_eq MasterTrainer_EventScript_BirdKeeperCooltrainer_AskBattle
    return

MasterTrainer_EventScript_BugCatcherYoungster:
    faceplayer
    msgbox Text_BugCatcherYoungster_Intro, MSGBOX_DEFAULT
    callnative CheckMasterPokemonInSlot1
    compare VAR_RESULT, TRUE
    goto_if_ne MasterTrainer_EventScript_BugCatcherYoungster_NoMon
    compare HAVE_TITLE, TRUE
    call_if_eq MasterTrainer_EventScript_BugCatcherYoungster_HaveTitleAskBattle
    compare HAVE_TITLE, FALSE
    call_if_eq MasterTrainer_EventScript_BugCatcherYoungster_AskBattle
    return

MasterTrainer_EventScript_PsychicScientist:
    faceplayer
    msgbox Text_PsychicScientist_Intro, MSGBOX_DEFAULT
    callnative CheckMasterPokemonInSlot1
    compare VAR_RESULT, TRUE
    goto_if_ne MasterTrainer_EventScript_PsychicScientist_NoMon
    compare HAVE_TITLE, TRUE
    call_if_eq MasterTrainer_EventScript_PsychicScientist_HaveTitleAskBattle
    compare HAVE_TITLE, FALSE
    call_if_eq MasterTrainer_EventScript_PsychicScientist_AskBattle
    return

MasterTrainer_EventScript_BlackBeltHiker:
    faceplayer
    msgbox Text_BlackBeltHiker_Intro, MSGBOX_DEFAULT
    callnative CheckMasterPokemonInSlot1
    compare VAR_RESULT, TRUE
    goto_if_ne MasterTrainer_EventScript_BlackBeltHiker_NoMon
    compare HAVE_TITLE, TRUE
    call_if_eq MasterTrainer_EventScript_BlackBeltHiker_HaveTitleAskBattle
    compare HAVE_TITLE, FALSE
    call_if_eq MasterTrainer_EventScript_BlackBeltHiker_AskBattle
    return

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

MasterTrainer_EventScript_BirdKeeperCooltrainerContinue:
    special LoadPlayerParty
    specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
    goto_if_eq MasterTrainer_EventScript_BirdKeeperCooltrainer_LostBattle
    compare HAVE_TITLE, TRUE
    goto_if_ne MasterTrainer_EventScript_BirdKeeperCooltrainer_ConferTitle
    msgbox Text_BirdKeeperCooltrainer_AfterBattleWon, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_BugCatcherYoungsterContinue:
    special LoadPlayerParty
    specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
    goto_if_eq MasterTrainer_EventScript_BugCatcherYoungster_LostBattle
    compare HAVE_TITLE, TRUE
    goto_if_ne MasterTrainer_EventScript_BugCatcherYoungster_ConferTitle
    msgbox Text_BugCatcherYoungster_AfterBattleWon, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_PsychicScientistContinue:
    special LoadPlayerParty
    specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
    goto_if_eq MasterTrainer_EventScript_PsychicScientist_LostBattle
    compare HAVE_TITLE, TRUE
    goto_if_ne MasterTrainer_EventScript_PsychicScientist_ConferTitle
    msgbox Text_PsychicScientist_AfterBattleWon, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_BlackBeltHikerContinue:
    special LoadPlayerParty
    specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
    goto_if_eq MasterTrainer_EventScript_BlackBeltHiker_LostBattle
    compare HAVE_TITLE, TRUE
    goto_if_ne MasterTrainer_EventScript_BlackBeltHiker_ConferTitle
    msgbox Text_BlackBeltHiker_AfterBattleWon, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end

MasterTrainer_EventScript_BeautyLass_NoMon:
    msgbox Text_BeautyLass_NoMon, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BirdKeeperCooltrainer_NoMon:
    msgbox Text_BirdKeeperCooltrainer_NoMon, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BugCatcherYoungster_NoMon:
    msgbox Text_BugCatcherYoungster_NoMon, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_PsychicScientist_NoMon:
    msgbox Text_PsychicScientist_NoMon, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BlackBeltHiker_NoMon:
    msgbox Text_BlackBeltHiker_NoMon, MSGBOX_DEFAULT
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

MasterTrainer_EventScript_BirdKeeperCooltrainer_HaveTitleAskBattle:
    msgbox Text_BirdKeeperCooltrainer_HaveTitleAskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_BirdKeeperCooltrainer_DeclinedBattle
    msgbox Text_BirdKeeperCooltrainer_AcceptedBattle, MSGBOX_DEFAULT
    special SavePlayerParty
    callnative ClearAllButFirstPokemon
    callnative HealPlayerPartyOak
    return

MasterTrainer_EventScript_BugCatcherYoungster_HaveTitleAskBattle:
    msgbox Text_BugCatcherYoungster_HaveTitleAskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_BugCatcherYoungster_DeclinedBattle
    msgbox Text_BugCatcherYoungster_AcceptedBattle, MSGBOX_DEFAULT
    special SavePlayerParty
    callnative ClearAllButFirstPokemon
    callnative HealPlayerPartyOak
    return

MasterTrainer_EventScript_PsychicScientist_HaveTitleAskBattle:
    msgbox Text_PsychicScientist_HaveTitleAskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_PsychicScientist_DeclinedBattle
    msgbox Text_PsychicScientist_AcceptedBattle, MSGBOX_DEFAULT
    special SavePlayerParty
    callnative ClearAllButFirstPokemon
    callnative HealPlayerPartyOak
    return

MasterTrainer_EventScript_BlackBeltHiker_HaveTitleAskBattle:
    msgbox Text_BlackBeltHiker_HaveTitleAskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_BlackBeltHiker_DeclinedBattle
    msgbox Text_BlackBeltHiker_AcceptedBattle, MSGBOX_DEFAULT
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

MasterTrainer_EventScript_BirdKeeperCooltrainer_AskBattle:
    msgbox Text_BirdKeeperCooltrainer_AskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_BirdKeeperCooltrainer_DeclinedBattle
    msgbox Text_BirdKeeperCooltrainer_AcceptedBattle, MSGBOX_DEFAULT
    special SavePlayerParty
    callnative ClearAllButFirstPokemon
    callnative HealPlayerPartyOak
    return

MasterTrainer_EventScript_BugCatcherYoungster_AskBattle:
    msgbox Text_BugCatcherYoungster_AskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_BugCatcherYoungster_DeclinedBattle
    msgbox Text_BugCatcherYoungster_AcceptedBattle, MSGBOX_DEFAULT
    special SavePlayerParty
    callnative ClearAllButFirstPokemon
    callnative HealPlayerPartyOak
    return

MasterTrainer_EventScript_PsychicScientist_AskBattle:
    msgbox Text_PsychicScientist_AskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_PsychicScientist_DeclinedBattle
    msgbox Text_PsychicScientist_AcceptedBattle, MSGBOX_DEFAULT
    special SavePlayerParty
    callnative ClearAllButFirstPokemon
    callnative HealPlayerPartyOak
    return

MasterTrainer_EventScript_BlackBeltHiker_AskBattle:
    msgbox Text_BlackBeltHiker_AskBattle, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_ne MasterTrainer_EventScript_BlackBeltHiker_DeclinedBattle
    msgbox Text_BlackBeltHiker_AcceptedBattle, MSGBOX_DEFAULT
    special SavePlayerParty
    callnative ClearAllButFirstPokemon
    callnative HealPlayerPartyOak
    return

MasterTrainer_EventScript_BeautyLass_DeclinedBattle:
    msgbox Text_BeautyLass_DeclinedBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BirdKeeperCooltrainer_DeclinedBattle:
    msgbox Text_BirdKeeperCooltrainer_DeclinedBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BugCatcherYoungster_DeclinedBattle:
    msgbox Text_BugCatcherYoungster_DeclinedBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_PsychicScientist_DeclinedBattle:
    msgbox Text_PsychicScientist_DeclinedBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BlackBeltHiker_DeclinedBattle:
    msgbox Text_BlackBeltHiker_DeclinedBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BeautyLass_LostBattle:
    msgbox Text_BeautyLass_LostBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BirdKeeperCooltrainer_LostBattle:
    msgbox Text_BirdKeeperCooltrainer_LostBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BugCatcherYoungster_LostBattle:
    msgbox Text_BugCatcherYoungster_LostBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_PsychicScientist_LostBattle:
    msgbox Text_PsychicScientist_LostBattle, MSGBOX_DEFAULT
    release
    clearflag FLAG_MASTER_TRAINER_BATTLE
    end

MasterTrainer_EventScript_BlackBeltHiker_LostBattle:
    msgbox Text_BlackBeltHiker_LostBattle, MSGBOX_DEFAULT
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
    resetobjectmovementtype VAR_LAST_TALKED
    release
    end

MasterTrainer_EventScript_BirdKeeperCooltrainer_ConferTitle:
    msgbox Text_BirdKeeperCooltrainer_GiveTitle, MSGBOX_DEFAULT
    message Text_MasterTrainer_EarnTitle
    waitmessage
    playfanfare MUS_LEVEL_UP
    waitfanfare
    waitbuttonpress
    msgbox Text_BirdKeeperCooltrainer_AnotherBattleSometime, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    resetobjectmovementtype VAR_LAST_TALKED
    release
    end

MasterTrainer_EventScript_BugCatcherYoungster_ConferTitle:
    msgbox Text_BugCatcherYoungster_GiveTitle, MSGBOX_DEFAULT
    message Text_MasterTrainer_EarnTitle
    waitmessage
    playfanfare MUS_LEVEL_UP
    waitfanfare
    waitbuttonpress
    msgbox Text_BugCatcherYoungster_AnotherBattleSometime, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    resetobjectmovementtype VAR_LAST_TALKED
    release
    end

MasterTrainer_EventScript_PsychicScientist_ConferTitle:
    msgbox Text_PsychicScientist_GiveTitle, MSGBOX_DEFAULT
    message Text_MasterTrainer_EarnTitle
    waitmessage
    playfanfare MUS_LEVEL_UP
    waitfanfare
    waitbuttonpress
    msgbox Text_PsychicScientist_AnotherBattleSometime, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    resetobjectmovementtype VAR_LAST_TALKED
    release
    end

MasterTrainer_EventScript_BlackBeltHiker_ConferTitle:
    msgbox Text_BlackBeltHiker_GiveTitle, MSGBOX_DEFAULT
    message Text_MasterTrainer_EarnTitle
    waitmessage
    playfanfare MUS_LEVEL_UP
    waitfanfare
    waitbuttonpress
    msgbox Text_BlackBeltHiker_AnotherBattleSometime, MSGBOX_DEFAULT
    clearflag FLAG_MASTER_TRAINER_BATTLE
    resetobjectmovementtype VAR_LAST_TALKED
    release
    end

MasterTrainer_EventScript_NoBattleContinue:
    faceplayer
    msgbox Text_PsychicScientist_Intro, MSGBOX_DEFAULT
    msgbox Text_Scientist_SeePowerfulMon, MSGBOX_DEFAULT
    callnative CheckMasterPokemonInSlot1
    compare VAR_RESULT, FALSE
    goto_if_eq MasterTrainer_EventScript_ReleaseEndClearFlag
    callnative CheckSlot1EVTotal
    compare VAR_RESULT, FALSE
    goto_if_eq MasterTrainer_EventScript_ReleaseEndClearFlag
    msgbox Text_Scientist_ShowPowerfulMon, MSGBOX_DEFAULT
    message Text_MasterTrainer_EarnTitle
    waitmessage
    playfanfare MUS_LEVEL_UP
    waitfanfare
    waitbuttonpress
    resetobjectmovementtype VAR_LAST_TALKED
    return

MasterTrainer_EventScript_ReleaseEndClearFlag:
    clearflag FLAG_MASTER_TRAINER_BATTLE
    release
    end


Text_Scientist_SeePowerfulMon:
    .string "It would be wonderful to see a truly\n"
    .string "powerful {STR_VAR_1}, even just once.$"

Text_Scientist_ShowPowerfulMon:
    .string "What do we have here?\p"
    .string "That {STR_VAR_1}!\n"
    .string "It's got a special vibe to it!\p"
    .string "The way it holds itself, it just\n"
    .string "radiates strength…\l"
    .string "Wonderful!\p"
    .string "I thank you… You showed me a\n"
    .string "a truly amazing POKéMON.\p"
    .string "I think you deserve the title of\n"
    .string "{STR_VAR_1} MASTER!$"

Text_BeautyLass_Intro:
    .string "I'm the {STR_VAR_1} MASTER!\p"
    .string "My goal is to find the ultimate\n"
    .string "{STR_VAR_1}!$"

Text_BirdKeeperCooltrainer_Intro:
    .string "I'm the {STR_VAR_1} MASTER!\p"
    .string "I aim to find the ultimate\n"
    .string "{STR_VAR_1}!$"

Text_BugCatcherYoungster_Intro:
    .string "I'm the {STR_VAR_1} MASTER!\n"
    .string "I seek the ultimate {STR_VAR_1}!$"

Text_PsychicScientist_Intro:
    .string "I am the {STR_VAR_1} MASTER!\n"
    .string "I seek the ultimate {STR_VAR_1}.$"

Text_BlackBeltHiker_Intro:
    .string "I am the {STR_VAR_1} MASTER!\p"
    .string "My only desire is to find the\n"
    .string "ultimate {STR_VAR_1}!$"

Text_BeautyLass_NoMon:
    .string "Don't forget to put your {STR_VAR_1}\n"
    .string "in the top-left position of your\l"
    .string "party if you want to battle me!$"

Text_BirdKeeperCooltrainer_NoMon:
    .string "If you want to battle me, you've\n"
    .string "got to put your {STR_VAR_1} in the\l"
    .string "top-left position of your party!$"

Text_BugCatcherYoungster_NoMon:
    .string "If you're interested in battling me,\n"
    .string "you gotta put your {STR_VAR_1} in\l"
    .string "the top-left position of your party!$"

Text_PsychicScientist_NoMon:
    .string "If you wish to battle me, you\n"
    .string "must put your {STR_VAR_1} in the\l"
    .string "top-left position of your party!$"

Text_BlackBeltHiker_NoMon:
    .string "Set your {STR_VAR_1} in the top\n"
    .string "left of your party if you wish\l"
    .string "to face me in battle!$"

Text_BeautyLass_AskBattle:
    .string "Hey, your {STR_VAR_1} looks pretty\n"
    .string "strong!\p"
    .string "Can I battle it with my {STR_VAR_1}?\n"
    .string "Pleeeease?$"

Text_BirdKeeperCooltrainer_AskBattle:
    .string "What's this? I see you have a\n"
    .string "strong-looking {STR_VAR_1}!\p"
    .string "Why don't you have it battle my\n"
    .string "{STR_VAR_1}?$"

Text_BugCatcherYoungster_AskBattle:
    .string "Heeey, you have a powerful\n"
    .string "{STR_VAR_1}, don't you?\p"
    .string "C'mon, you should have it battle\n"
    .string "my own {STR_VAR_1}!$"

Text_PsychicScientist_AskBattle:
    .string "Oh? I see you have a very\n"
    .string "potent-looking {STR_VAR_1}…\p"
    .string "Would you be interested in battling\n"
    .string "my {STR_VAR_1}?$"

Text_BlackBeltHiker_AskBattle:
    .string "Hmm? Your {STR_VAR_1} seems very\n"
    .string "strong!\p"
    .string "Why not have it face off against\n"
    .string "my {STR_VAR_1}?$"

Text_BeautyLass_HaveTitleAskBattle:
    .string "Hey there! Has your {STR_VAR_1}\n"
    .string "gotten any stronger?\p"
    .string "Can I battle it with my {STR_VAR_1}?\n"
    .string "Pleeeease?$"

Text_BirdKeeperCooltrainer_HaveTitleAskBattle:
    .string "Oh, hey there! Has your\n"
    .string "{STR_VAR_1} gotten any stronger?\p"
    .string "Why don't you have it battle my\n"
    .string "{STR_VAR_1}?$"

Text_BugCatcherYoungster_HaveTitleAskBattle:
    .string "Hey, how's it going? Still training\n"
    .string "your {STR_VAR_1}, I bet!\p"
    .string "C'mon, you should have it battle\n"
    .string "my own {STR_VAR_1}!$"

Text_PsychicScientist_HaveTitleAskBattle:
    .string "Oh, good to see you again.\n"
    .string "How's your {STR_VAR_1} doing?\p"
    .string "Would you be interested in battling\n"
    .string "my {STR_VAR_1}?$"

Text_BlackBeltHiker_HaveTitleAskBattle:
    .string "Ahoy, you there! How is your\n"
    .string "{STR_VAR_1} doing these days?\p"
    .string "Why not have it face off against\n"
    .string "my {STR_VAR_1}?$"

Text_BeautyLass_DeclinedBattle:
    .string "Boo!\n"
    .string "I wanted to show off my {STR_VAR_1}!$"

Text_BirdKeeperCooltrainer_DeclinedBattle:
    .string "Too bad! That means I can't show\n"
    .string "you how amazing my {STR_VAR_1} is!$"

Text_BugCatcherYoungster_DeclinedBattle:
    .string "Tsk! I really would have liked to\n"
    .string "see your {STR_VAR_1} in action…$"

Text_PsychicScientist_DeclinedBattle:
    .string "It is unfortunate I can't show you\n"
    .string "the power of my {STR_VAR_1}.$"

Text_BlackBeltHiker_DeclinedBattle:
    .string "Hmm, perhaps my {STR_VAR_1} is\n"
    .string "frightening you?$"

Text_BeautyLass_AcceptedBattle:
    .string "Let's see which is the stronger\n"
    .string "{STR_VAR_1}!$"

Text_BirdKeeperCooltrainer_AcceptedBattle: // a/an
    .string "All right!\n"
    .string "It's time for {STR_VAR_3} {STR_VAR_1} battle!$"

Text_BugCatcherYoungster_AcceptedBattle:
    .string "Let's find out whose {STR_VAR_1}\n"
    .string "is the most powerful!$"

Text_PsychicScientist_AcceptedBattle:
    .string "Well then, I hope you're ready!\n"
    .string "Come on, {STR_VAR_1}!$"

Text_BlackBeltHiker_AcceptedBattle:
    .string "Let's do this, {STR_VAR_1}!\n"
    .string "Let's have an honorable battle!$"

Text_BeautyLass_LostBattle:
    .string "Hee hee! I knew my {STR_VAR_1}\n"
    .string "was the best of the best!$"

Text_BirdKeeperCooltrainer_LostBattle:
    .string "Hahaha! I knew my {STR_VAR_1}\n"
    .string "was the best of them all!$"

Text_BugCatcherYoungster_LostBattle:
    .string "We did it! I knew my\n"
    .string "{STR_VAR_1} was the best there is!$"

Text_PsychicScientist_LostBattle:
    .string "Heh heh heh… I knew my {STR_VAR_1}\n"
    .string "was the best, most powerful\l"
    .string "of them all.$"

Text_BlackBeltHiker_LostBattle:
    .string "Bahaha! Of course my {STR_VAR_1}\n"
    .string "is the best of them all!$"

Text_BeautyLass_BattleLoss:
    .string "That strength is the real deal!$"

Text_BirdKeeperCooltrainer_BattleLoss:
    .string "That strength is the real thing.$"

Text_BugCatcherYoungster_BattleLoss:
    .string "That strength is no joke!$"

Text_PsychicScientist_BattleLoss:
    .string "That seems like true strength.$"

Text_BlackBeltHiker_BattleLoss:
    .string "That's some real strength!$"

Text_BeautyLass_AfterBattleWon: //already have title
    .string "Oh wow… Your {STR_VAR_1} is way\n"
    .string "stronger than I thought!\p"
    .string "We should have another battle\n"
    .string "sometime, since we both love\l"
    .string "{STR_VAR_1} so much!$"

Text_BirdKeeperCooltrainer_AfterBattleWon: //already have title
    .string "I can't believe it… Your\n"
    .string "{STR_VAR_1}… It's too powerful!\p"
    .string "We both seem to love {STR_VAR_1},\n"
    .string "so let's battle again sometime!$"

Text_BugCatcherYoungster_AfterBattleWon: //already have title
    .string "Aw, c'mon! Your {STR_VAR_1}\n"
    .string "is way too strong!\p"
    .string "I'd love to battle again sometime,\n"
    .string "as a fellow {STR_VAR_1} fan!$"

Text_PsychicScientist_AfterBattleWon: //already have title
    .string "I can't believe this… Your\n"
    .string "{STR_VAR_1} is too strong!\p"
    .string "As two {STR_VAR_1} fanatics,\n"
    .string "we should definitely battle again\l"
    .string "sometime!$"

Text_BlackBeltHiker_AfterBattleWon: //already have title
    .string "B-but how…? Your {STR_VAR_1} is\n"
    .string "more powerful than any I've seen\l"
    .string "before!\p"
    .string "As two {STR_VAR_1} fanatics,\n"
    .string "we are almost family!\l"
    .string "We must battle again sometime!$"

Text_BeautyLass_GiveTitle: // a/an
    .string "Oh wow… Your {STR_VAR_1} is way\n"
    .string "stronger than I thought!\p"
    .string "I think you deserve to be called\n"
    .string "{STR_VAR_3} {STR_VAR_1} MASTER!$"

Text_BirdKeeperCooltrainer_GiveTitle:
    .string "I can't believe it… Your\n"
    .string "{STR_VAR_1}… It's too powerful!\p"
    .string "You are the one who deserves the\n"
    .string "title of {STR_VAR_1} MASTER!$"

Text_BugCatcherYoungster_GiveTitle:
    .string "Aw, c'mon! Your {STR_VAR_1}\n"
    .string "is way too strong!\p"
    .string "You definitely deserve the title\n"
    .string "of {STR_VAR_1} MASTER!$"

Text_PsychicScientist_GiveTitle:
    .string "I can't believe this… Your\n"
    .string "{STR_VAR_1} is too strong!\p"
    .string "I think you deserve the title of\n"
    .string "{STR_VAR_1} MASTER!$"

Text_BlackBeltHiker_GiveTitle:
    .string "B-but how…? Your {STR_VAR_1} is\n"
    .string "more powerful than any I've seen\l"
    .string "before!\p"
    .string "You are truly worthy of the title\n"
    .string "{STR_VAR_1} MASTER!$"

Text_MasterTrainer_EarnTitle:
    .string "{COLOR DARK_GRAY}You have earned the title of\n"
    .string "{STR_VAR_1} MASTER!$"

Text_BeautyLass_AnotherBattleSometime:
    .string "We should have another battle\n"
    .string "sometime, since we both love\l"
    .string "{STR_VAR_1} so much!$"

Text_BirdKeeperCooltrainer_AnotherBattleSometime:
    .string "We both seem to love {STR_VAR_1},\n"
    .string "so let's battle again sometime!$"

Text_BugCatcherYoungster_AnotherBattleSometime:
    .string "I'd love to battle again sometime,\n"
    .string "as a fellow {STR_VAR_1} fan!$"

Text_PsychicScientist_AnotherBattleSometime:
    .string "As two {STR_VAR_1} fanatics,\n"
    .string "we should definitely battle again\l"
    .string "sometime!$"

Text_BlackBeltHiker_AnotherBattleSometime:
    .string "As two {STR_VAR_1} fanatics,\n"
    .string "we are almost family!\l"
    .string "We must battle again sometime!$"
