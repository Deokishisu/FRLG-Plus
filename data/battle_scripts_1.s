#include "constants/moves.h"
#include "constants/battle.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_anim.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "constants/species.h"
#include "constants/pokemon.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/game_stat.h"
#include "battle_string_ids.h"
	.include "asm/macros/battle_script.inc"
@ Define these here since misc_constants.inc conflicts with the C headers
	.set NULL, 0
	.set FALSE, 0
	.set TRUE, 1
	.section script_data, "aw", %progbits
	.align 2

gBattleScriptsForMoveEffects::
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectSleep
	.4byte BattleScript_EffectPoisonHit
	.4byte BattleScript_EffectAbsorb
	.4byte BattleScript_EffectBurnHit
	.4byte BattleScript_EffectFreezeHit
	.4byte BattleScript_EffectParalyzeHit
	.4byte BattleScript_EffectExplosion
	.4byte BattleScript_EffectDreamEater
	.4byte BattleScript_EffectMirrorMove
	.4byte BattleScript_EffectAttackUp
	.4byte BattleScript_EffectDefenseUp
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectSpecialAttackUp
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectEvasionUp
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectAttackDown
	.4byte BattleScript_EffectDefenseDown
	.4byte BattleScript_EffectSpeedDown
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectAccuracyDown
	.4byte BattleScript_EffectEvasionDown
	.4byte BattleScript_EffectHaze
	.4byte BattleScript_EffectBide
	.4byte BattleScript_EffectRampage
	.4byte BattleScript_EffectRoar
	.4byte BattleScript_EffectMultiHit
	.4byte BattleScript_EffectConversion
	.4byte BattleScript_EffectFlinchHit
	.4byte BattleScript_EffectRestoreHp
	.4byte BattleScript_EffectToxic
	.4byte BattleScript_EffectPayDay
	.4byte BattleScript_EffectLightScreen
	.4byte BattleScript_EffectTriAttack
	.4byte BattleScript_EffectRest
	.4byte BattleScript_EffectOHKO
	.4byte BattleScript_EffectRazorWind
	.4byte BattleScript_EffectSuperFang
	.4byte BattleScript_EffectDragonRage
	.4byte BattleScript_EffectTrap
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectDoubleHit
	.4byte BattleScript_EffectRecoilIfMiss
	.4byte BattleScript_EffectMist
	.4byte BattleScript_EffectFocusEnergy
	.4byte BattleScript_EffectRecoil
	.4byte BattleScript_EffectConfuse
	.4byte BattleScript_EffectAttackUp2
	.4byte BattleScript_EffectDefenseUp2
	.4byte BattleScript_EffectSpeedUp2
	.4byte BattleScript_EffectSpecialAttackUp2
	.4byte BattleScript_EffectSpecialDefenseUp2
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectTransform
	.4byte BattleScript_EffectAttackDown2
	.4byte BattleScript_EffectDefenseDown2
	.4byte BattleScript_EffectSpeedDown2
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectSpecialDefenseDown2
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectReflect
	.4byte BattleScript_EffectPoison
	.4byte BattleScript_EffectParalyze
	.4byte BattleScript_EffectAttackDownHit
	.4byte BattleScript_EffectDefenseDownHit
	.4byte BattleScript_EffectSpeedDownHit
	.4byte BattleScript_EffectSpecialAttackDownHit
	.4byte BattleScript_EffectSpecialDefenseDownHit
	.4byte BattleScript_EffectAccuracyDownHit
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectSkyAttack
	.4byte BattleScript_EffectConfuseHit
	.4byte BattleScript_EffectTwineedle
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectSubstitute
	.4byte BattleScript_EffectRecharge
	.4byte BattleScript_EffectRage
	.4byte BattleScript_EffectMimic
	.4byte BattleScript_EffectMetronome
	.4byte BattleScript_EffectLeechSeed
	.4byte BattleScript_EffectSplash
	.4byte BattleScript_EffectDisable
	.4byte BattleScript_EffectLevelDamage
	.4byte BattleScript_EffectPsywave
	.4byte BattleScript_EffectCounter
	.4byte BattleScript_EffectEncore
	.4byte BattleScript_EffectPainSplit
	.4byte BattleScript_EffectSnore
	.4byte BattleScript_EffectConversion2
	.4byte BattleScript_EffectLockOn
	.4byte BattleScript_EffectSketch
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectSleepTalk
	.4byte BattleScript_EffectDestinyBond
	.4byte BattleScript_EffectFlail
	.4byte BattleScript_EffectSpite
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectHealBell
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectTripleKick
	.4byte BattleScript_EffectThief
	.4byte BattleScript_EffectMeanLook
	.4byte BattleScript_EffectNightmare
	.4byte BattleScript_EffectMinimize
	.4byte BattleScript_EffectCurse
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectProtect
	.4byte BattleScript_EffectSpikes
	.4byte BattleScript_EffectForesight
	.4byte BattleScript_EffectPerishSong
	.4byte BattleScript_EffectSandstorm
	.4byte BattleScript_EffectProtect
	.4byte BattleScript_EffectRollout
	.4byte BattleScript_EffectSwagger
	.4byte BattleScript_EffectFuryCutter
	.4byte BattleScript_EffectAttract
	.4byte BattleScript_EffectReturn
	.4byte BattleScript_EffectPresent
	.4byte BattleScript_EffectReturn
	.4byte BattleScript_EffectSafeguard
	.4byte BattleScript_EffectThawHit
	.4byte BattleScript_EffectMagnitude
	.4byte BattleScript_EffectBatonPass
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectRapidSpin
	.4byte BattleScript_EffectSonicboom
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectMorningSun
	.4byte BattleScript_EffectMorningSun
	.4byte BattleScript_EffectMorningSun
	.4byte BattleScript_EffectHiddenPower
	.4byte BattleScript_EffectRainDance
	.4byte BattleScript_EffectSunnyDay
	.4byte BattleScript_EffectDefenseUpHit
	.4byte BattleScript_EffectAttackUpHit
	.4byte BattleScript_EffectAllStatsUpHit
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectBellyDrum
	.4byte BattleScript_EffectPsychUp
	.4byte BattleScript_EffectMirrorCoat
	.4byte BattleScript_EffectSkullBash
	.4byte BattleScript_EffectTwister
	.4byte BattleScript_EffectEarthquake
	.4byte BattleScript_EffectFutureSight
	.4byte BattleScript_EffectGust
	.4byte BattleScript_EffectFlinchMinimizeHit
	.4byte BattleScript_EffectSolarbeam
	.4byte BattleScript_EffectThunder
	.4byte BattleScript_EffectTeleport
	.4byte BattleScript_EffectBeatUp
	.4byte BattleScript_EffectSemiInvulnerable
	.4byte BattleScript_EffectDefenseCurl
	.4byte BattleScript_EffectSoftboiled
	.4byte BattleScript_EffectFakeOut
	.4byte BattleScript_EffectUproar
	.4byte BattleScript_EffectStockpile
	.4byte BattleScript_EffectSpitUp
	.4byte BattleScript_EffectSwallow
	.4byte BattleScript_EffectHit
	.4byte BattleScript_EffectHail
	.4byte BattleScript_EffectTorment
	.4byte BattleScript_EffectFlatter
	.4byte BattleScript_EffectWillOWisp
	.4byte BattleScript_EffectMemento
	.4byte BattleScript_EffectFacade
	.4byte BattleScript_EffectFocusPunch
	.4byte BattleScript_EffectSmellingsalt
	.4byte BattleScript_EffectFollowMe
	.4byte BattleScript_EffectNaturePower
	.4byte BattleScript_EffectCharge
	.4byte BattleScript_EffectTaunt
	.4byte BattleScript_EffectHelpingHand
	.4byte BattleScript_EffectTrick
	.4byte BattleScript_EffectRolePlay
	.4byte BattleScript_EffectWish
	.4byte BattleScript_EffectAssist
	.4byte BattleScript_EffectIngrain
	.4byte BattleScript_EffectSuperpower
	.4byte BattleScript_EffectMagicCoat
	.4byte BattleScript_EffectRecycle
	.4byte BattleScript_EffectRevenge
	.4byte BattleScript_EffectBrickBreak
	.4byte BattleScript_EffectYawn
	.4byte BattleScript_EffectKnockOff
	.4byte BattleScript_EffectEndeavor
	.4byte BattleScript_EffectEruption
	.4byte BattleScript_EffectSkillSwap
	.4byte BattleScript_EffectImprison
	.4byte BattleScript_EffectRefresh
	.4byte BattleScript_EffectGrudge
	.4byte BattleScript_EffectSnatch
	.4byte BattleScript_EffectLowKick
	.4byte BattleScript_EffectSecretPower
	.4byte BattleScript_EffectDoubleEdge
	.4byte BattleScript_EffectTeeterDance
	.4byte BattleScript_EffectBurnHit
	.4byte BattleScript_EffectMudSport
	.4byte BattleScript_EffectPoisonFang
	.4byte BattleScript_EffectWeatherBall
	.4byte BattleScript_EffectOverheat
	.4byte BattleScript_EffectTickle
	.4byte BattleScript_EffectCosmicPower
	.4byte BattleScript_EffectSkyUppercut
	.4byte BattleScript_EffectBulkUp
	.4byte BattleScript_EffectPoisonHit
	.4byte BattleScript_EffectMudSport
	.4byte BattleScript_EffectCalmMind
	.4byte BattleScript_EffectDragonDance
	.4byte BattleScript_EffectCamouflage

BattleScript_EffectHit::
	jumpifnotmove MOVE_SURF, BattleScript_HitFromAtkCanceler
	jumpifnostatus3 BS_TARGET, STATUS3_UNDERWATER, BattleScript_HitFromAtkCanceler
	orword gHitMarker, HITMARKER_IGNORE_UNDERWATER
	setbyte sDMG_MULTIPLIER, 2
BattleScript_HitFromAtkCanceler::
	attackcanceler
BattleScript_HitFromAccCheck::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
BattleScript_HitFromAtkString::
	attackstring
	ppreduce
BattleScript_HitFromCritCalc::
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
BattleScript_HitFromAtkAnimation::
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	resultmessage
	waitmessage 0x40
	seteffectwithchance
	tryfaintmon BS_TARGET, 0, NULL
BattleScript_MoveEnd::
	moveendall
	end

BattleScript_MakeMoveMissed::
	orbyte gMoveResultFlags, MOVE_RESULT_MISSED
BattleScript_PrintMoveMissed::
	attackstring
	ppreduce
BattleScript_MoveMissedPause::
	pause 0x20
BattleScript_MoveMissed::
	effectivenesssound
	resultmessage
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSleep::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_AlreadyAsleep
	jumpifcantmakeasleep BattleScript_CantMakeAsleep
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_SLEEP
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_AlreadyAsleep::
	pause 0x20
	printstring STRINGID_PKMNALREADYASLEEP
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_WasntAffected::
	pause 0x20
	printstring STRINGID_PKMNWASNTAFFECTED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_CantMakeAsleep::
	pause 0x20
	printfromtable gUproarAwakeStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectPoisonHit::
	setmoveeffect MOVE_EFFECT_POISON
	goto BattleScript_EffectHit

BattleScript_EffectAbsorb::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	resultmessage
	waitmessage 0x40
	negativedamage
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	jumpifability BS_TARGET, ABILITY_LIQUID_OOZE, BattleScript_AbsorbLiquidOoze
	setbyte cMULTISTRING_CHOOSER, 0
	goto BattleScript_AbsorbUpdateHp

BattleScript_AbsorbLiquidOoze::
	manipulatedamage 0
	setbyte cMULTISTRING_CHOOSER, 1
BattleScript_AbsorbUpdateHp::
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	jumpifmovehadnoeffect BattleScript_AbsorbTryFainting
	printfromtable gLeechSeedDrainStringIds
	waitmessage 0x40
BattleScript_AbsorbTryFainting::
	tryfaintmon BS_ATTACKER, 0, NULL
	tryfaintmon BS_TARGET, 0, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectBurnHit::
	setmoveeffect MOVE_EFFECT_BURN
	goto BattleScript_EffectHit

BattleScript_EffectFreezeHit::
	setmoveeffect MOVE_EFFECT_FREEZE
	goto BattleScript_EffectHit

BattleScript_EffectParalyzeHit::
	setmoveeffect MOVE_EFFECT_PARALYSIS
	goto BattleScript_EffectHit

BattleScript_EffectExplosion::
	attackcanceler
	attackstring
	ppreduce
	faintifabilitynotdamp
	setatkhptozero
	waitstate
	jumpifbyte CMP_NO_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_MISSED, BattleScript_ExplosionDoAnimStartLoop
	call BattleScript_PreserveMissedBitDoMoveAnim
	goto BattleScript_ExplosionLoop

BattleScript_ExplosionDoAnimStartLoop::
	attackanimation
	waitanimation
BattleScript_ExplosionLoop::
	movevaluescleanup
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	accuracycheck BattleScript_ExplosionMissed, ACC_CURR_MOVE
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	resultmessage
	waitmessage 0x40
	tryfaintmon BS_TARGET, 0, NULL
	moveendto 16
	jumpifnexttargetvalid BattleScript_ExplosionLoop
	tryfaintmon BS_ATTACKER, 0, NULL
	end

BattleScript_ExplosionMissed::
	effectivenesssound
	resultmessage
	waitmessage 0x40
	moveendto 16
	jumpifnexttargetvalid BattleScript_ExplosionLoop
	tryfaintmon BS_ATTACKER, 0, NULL
	end

BattleScript_PreserveMissedBitDoMoveAnim::
	bicbyte gMoveResultFlags, MOVE_RESULT_MISSED
	attackanimation
	waitanimation
	orbyte gMoveResultFlags, MOVE_RESULT_MISSED
	return

BattleScript_EffectDreamEater::
	attackcanceler
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_DreamEaterNoEffect
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_DreamEaterWorked
BattleScript_DreamEaterNoEffect::
	attackstring
	ppreduce
	waitmessage 0x40
	goto BattleScript_WasntAffected

BattleScript_DreamEaterWorked::
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	resultmessage
	waitmessage 0x40
	negativedamage
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	jumpifmovehadnoeffect BattleScript_DreamEaterTryFaintEnd
	printstring STRINGID_PKMNDREAMEATEN
	waitmessage 0x40
BattleScript_DreamEaterTryFaintEnd::
	tryfaintmon BS_TARGET, 0, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectMirrorMove::
	attackcanceler
	attackstring
	pause 0x40
	trymirrormove
	ppreduce
	orbyte gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_MIRRORMOVEFAILED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp::
	setstatchanger STAT_ATK, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp::
	setstatchanger STAT_DEF, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp::
	setstatchanger STAT_SPATK, 1, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectEvasionUp::
	setstatchanger STAT_EVASION, 1, FALSE
BattleScript_EffectStatUp::
	attackcanceler
BattleScript_EffectStatUpAfterAtkCanceler::
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_StatUpEnd
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_StatUpAttackAnim
	pause 0x20
	goto BattleScript_StatUpPrintString

BattleScript_StatUpAttackAnim::
	attackanimation
	waitanimation
BattleScript_StatUpDoAnim::
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StatUpPrintString::
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_StatUpEnd::
	goto BattleScript_MoveEnd

BattleScript_StatUp::
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage 0x40
	return

BattleScript_EffectAttackDown::
	setstatchanger STAT_ATK, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown::
	setstatchanger STAT_DEF, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown::
	setstatchanger STAT_SPEED, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectAccuracyDown::
	setstatchanger STAT_ACC, 1, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectEvasionDown::
	setstatchanger STAT_EVASION, 1, TRUE
BattleScript_EffectStatDown::
	attackcanceler
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailedAtkStringPpReduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	statbuffchange STAT_CHANGE_BS_PTR, BattleScript_StatDownEnd
	jumpifbyte CMP_LESS_THAN, cMULTISTRING_CHOOSER, 2, BattleScript_StatDownDoAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 3, BattleScript_StatDownEnd
	pause 0x20
	goto BattleScript_StatDownPrintString

BattleScript_StatDownDoAnim::
	attackanimation
	waitanimation
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
BattleScript_StatDownPrintString::
	printfromtable gStatDownStringIds
	waitmessage 0x40
BattleScript_StatDownEnd::
	goto BattleScript_MoveEnd

BattleScript_StatDown::
	playanimation BS_EFFECT_BATTLER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatDownStringIds
	waitmessage 0x40
	return

BattleScript_EffectHaze::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	normalisebuffs
	printstring STRINGID_STATCHANGESGONE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectBide::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_CHARGING
	setbide
	goto BattleScript_MoveEnd

BattleScript_EffectRampage::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_EffectRampage2
	ppreduce
BattleScript_EffectRampage2::
	confuseifrepeatingattackends
	goto BattleScript_HitFromCritCalc

BattleScript_EffectRoar::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_SUCTION_CUPS, BattleScript_AbilityPreventsPhasingOut
	jumpifstatus3 BS_TARGET, STATUS3_ROOTED, BattleScript_PrintMonIsRooted
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	forcerandomswitch BattleScript_ButItFailed

BattleScript_EffectMultiHit::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 0
	initmultihitstring
	setbyte sMULTIHIT_EFFECT, 0
BattleScript_MultiHitLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_MultiHitEnd
	jumpifhasnohp BS_TARGET, BattleScript_MultiHitPrintStrings
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoMultiHit
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_MultiHitPrintStrings
BattleScript_DoMultiHit::
	movevaluescleanup
	copybyte cEFFECT_CHOOSER, sMULTIHIT_EFFECT
	critcalc
	damagecalc
	typecalc
	jumpifmovehadnoeffect BattleScript_MultiHitNoMoreHits
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	addbyte gBattleScripting + 12, 1
	moveendto 16
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_MultiHitPrintStrings
	decrementmultihit BattleScript_MultiHitLoop
	goto BattleScript_MultiHitPrintStrings

BattleScript_MultiHitNoMoreHits::
	pause 0x20
BattleScript_MultiHitPrintStrings::
	resultmessage
	waitmessage 0x40
	jumpifmovehadnoeffect BattleScript_MultiHitEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage 0x40
BattleScript_MultiHitEnd::
	seteffectwithchance
	tryfaintmon BS_TARGET, 0, NULL
	moveendcase 2
	moveendfrom 4
	end

BattleScript_EffectConversion::
	attackcanceler
	attackstring
	ppreduce
	tryconversiontypechange BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectFlinchHit::
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_EffectHit

BattleScript_EffectRestoreHp::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_ATTACKER
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectToxic::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	jumpiftype BS_TARGET, TYPE_POISON, BattleScript_NotAffected
	jumpiftype BS_TARGET, TYPE_STEEL, BattleScript_NotAffected
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_TOXIC
	seteffectprimary
	resultmessage
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_AlreadyPoisoned::
	pause 0x40
	printstring STRINGID_PKMNALREADYPOISONED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_ImmunityProtected::
	copybyte gEffectBattler, gBattlerTarget
	setbyte cMULTISTRING_CHOOSER, 0
	call BattleScript_PSNPrevention
	goto BattleScript_MoveEnd

BattleScript_EffectPayDay::
	setmoveeffect MOVE_EFFECT_PAYDAY
	goto BattleScript_EffectHit

BattleScript_EffectLightScreen::
	attackcanceler
	attackstring
	ppreduce
	setlightscreen
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectTriAttack::
	setmoveeffect MOVE_EFFECT_TRI_ATTACK
	goto BattleScript_EffectHit

BattleScript_EffectRest::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_RestIsAlreadyAsleep
	jumpifcantmakeasleep BattleScript_RestCantSleep
	trysetrest BattleScript_AlreadyAtFullHp
	pause 0x20
	printfromtable gRestUsedStringIds
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	waitstate
	goto BattleScript_PresentHealTarget

BattleScript_RestCantSleep::
	pause 0x40
	printfromtable gUproarAwakeStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_RestIsAlreadyAsleep::
	pause 0x20
	printstring STRINGID_PKMNALREADYASLEEP2
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectOHKO::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	typecalc
	jumpifmovehadnoeffect BattleScript_HitFromAtkAnimation
	tryKO BattleScript_KOFail
	trysetdestinybondtohappen
	goto BattleScript_HitFromAtkAnimation

BattleScript_KOFail::
	pause 0x40
	printfromtable gKOFailedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectRazorWind::
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	setbyte sTWOTURN_STRINGID, 0
	call BattleScriptFirstChargingTurn
	goto BattleScript_MoveEnd

BattleScript_TwoTurnMovesSecondTurn::
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	setbyte sB_ANIM_TURN, 1
	clearstatusfromeffect BS_ATTACKER
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	jumpifnotmove MOVE_SKY_ATTACK, BattleScript_HitFromAccCheck
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_HitFromAccCheck

BattleScriptFirstChargingTurn::
	attackcanceler
	printstring STRINGID_EMPTYSTRING3
	ppreduce
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_CHARGING
	setmoveeffect MOVE_EFFECT_CHARGING | MOVE_EFFECT_AFFECTS_USER
	seteffectprimary
	copybyte cMULTISTRING_CHOOSER, sTWOTURN_STRINGID
	printfromtable gFirstTurnOfTwoStringIds
	waitmessage 0x40
	return

BattleScript_EffectSuperFang::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	damagetohalftargethp
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectDragonRage::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	setword gBattleMoveDamage, 40
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectTrap::
	jumpifnotmove MOVE_WHIRLPOOL, BattleScript_DoWrapEffect
	jumpifnostatus3 BS_TARGET, STATUS3_UNDERWATER, BattleScript_DoWrapEffect
	orword gHitMarker, HITMARKER_IGNORE_UNDERWATER
	setbyte sDMG_MULTIPLIER, 2
BattleScript_DoWrapEffect::
	setmoveeffect MOVE_EFFECT_WRAP
	goto BattleScript_EffectHit

BattleScript_EffectDoubleHit::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setmultihitcounter 2
	initmultihitstring
	setbyte sMULTIHIT_EFFECT, 0
	goto BattleScript_MultiHitLoop

BattleScript_EffectRecoilIfMiss::
	attackcanceler
	accuracycheck BattleScript_MoveMissedDoDamage, ACC_CURR_MOVE
	goto BattleScript_HitFromAtkString

BattleScript_MoveMissedDoDamage::
	attackstring
	ppreduce
	pause 0x40
	resultmessage
	waitmessage 0x40
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_MoveEnd
	printstring STRINGID_PKMNCRASHED
	waitmessage 0x40
	damagecalc
	typecalc
	adjustnormaldamage
	manipulatedamage 1
	bicbyte gMoveResultFlags, MOVE_RESULT_MISSED
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, 0, NULL
	orbyte gMoveResultFlags, MOVE_RESULT_MISSED
	goto BattleScript_MoveEnd

BattleScript_EffectMist::
	attackcanceler
	attackstring
	ppreduce
	setmist
	attackanimation
	waitanimation
	printfromtable gMistUsedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectFocusEnergy::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_ATTACKER, STATUS2_FOCUS_ENERGY, BattleScript_ButItFailed
	setfocusenergy
	attackanimation
	waitanimation
	printfromtable gFocusEnergyUsedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectRecoil::
	setmoveeffect MOVE_EFFECT_RECOIL_25 | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	jumpifnotmove MOVE_STRUGGLE, BattleScript_EffectHit
	incrementgamestat GAME_STAT_USED_STRUGGLE
	goto BattleScript_EffectHit

BattleScript_EffectConfuse::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_AlreadyConfused
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_CONFUSION
	seteffectprimary
	resultmessage
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_AlreadyConfused::
	pause 0x20
	printstring STRINGID_PKMNALREADYCONFUSED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectAttackUp2::
	setstatchanger STAT_ATK, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectDefenseUp2::
	setstatchanger STAT_DEF, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpeedUp2::
	setstatchanger STAT_SPEED, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialAttackUp2::
	setstatchanger STAT_SPATK, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectSpecialDefenseUp2::
	setstatchanger STAT_SPDEF, 2, FALSE
	goto BattleScript_EffectStatUp

BattleScript_EffectTransform::
	attackcanceler
	attackstring
	ppreduce
	transformdataexecution
	attackanimation
	waitanimation
	printfromtable gTransformUsedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectAttackDown2::
	setstatchanger STAT_ATK, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectDefenseDown2::
	setstatchanger STAT_DEF, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpeedDown2::
	setstatchanger STAT_SPEED, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectSpecialDefenseDown2::
	setstatchanger STAT_SPDEF, 2, TRUE
	goto BattleScript_EffectStatDown

BattleScript_EffectReflect::
	attackcanceler
	attackstring
	ppreduce
	setreflect
BattleScript_PrintReflectLightScreenSafeguardString::
	attackanimation
	waitanimation
	printfromtable gReflectLightScreenSafeguardStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectPoison::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_IMMUNITY, BattleScript_ImmunityProtected
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_POISON, BattleScript_AlreadyPoisoned
	jumpifstatus BS_TARGET, STATUS1_TOXIC_POISON, BattleScript_AlreadyPoisoned
	jumpiftype BS_TARGET, TYPE_POISON, BattleScript_NotAffected
	jumpiftype BS_TARGET, TYPE_STEEL, BattleScript_NotAffected
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_POISON
	seteffectprimary
	resultmessage
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectParalyze::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_LIMBER, BattleScript_LimberProtected
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	typecalc
	jumpifmovehadnoeffect BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_PARALYSIS, BattleScript_AlreadyParalyzed
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_PARALYSIS
	seteffectprimary
	resultmessage
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_AlreadyParalyzed::
	pause 0x20
	printstring STRINGID_PKMNISALREADYPARALYZED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_LimberProtected::
	copybyte gEffectBattler, gBattlerTarget
	setbyte cMULTISTRING_CHOOSER, 0
	call BattleScript_PRLZPrevention
	goto BattleScript_MoveEnd

BattleScript_EffectAttackDownHit::
	setmoveeffect MOVE_EFFECT_ATK_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectDefenseDownHit::
	setmoveeffect MOVE_EFFECT_DEF_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpeedDownHit::
	setmoveeffect MOVE_EFFECT_SPD_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpecialAttackDownHit::
	setmoveeffect MOVE_EFFECT_SP_ATK_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSpecialDefenseDownHit::
	setmoveeffect MOVE_EFFECT_SP_DEF_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectAccuracyDownHit::
	setmoveeffect MOVE_EFFECT_ACC_MINUS_1
	goto BattleScript_EffectHit

BattleScript_EffectSkyAttack::
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	setbyte sTWOTURN_STRINGID, 3
	call BattleScriptFirstChargingTurn
	goto BattleScript_MoveEnd

BattleScript_EffectConfuseHit::
	setmoveeffect MOVE_EFFECT_CONFUSION
	goto BattleScript_EffectHit

BattleScript_EffectTwineedle::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setbyte sMULTIHIT_EFFECT, MOVE_EFFECT_POISON
	attackstring
	ppreduce
	setmultihitcounter 2
	initmultihitstring
	goto BattleScript_MultiHitLoop

BattleScript_EffectSubstitute::
	attackcanceler
	ppreduce
	attackstring
	waitstate
	jumpifstatus2 BS_ATTACKER, STATUS2_SUBSTITUTE, BattleScript_AlreadyHasSubstitute
	setsubstitute
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, 1, BattleScript_SubstituteAnim
	pause 0x20
	goto BattleScript_SubstituteString

BattleScript_SubstituteAnim::
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
BattleScript_SubstituteString::
	printfromtable gSubsituteUsedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_AlreadyHasSubstitute::
	pause 0x20
	printstring STRINGID_PKMNHASSUBSTITUTE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectRecharge::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_RECHARGE | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_HitFromAtkString

BattleScript_MoveUsedMustRecharge::
	printstring STRINGID_PKMNMUSTRECHARGE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectRage::
	attackcanceler
	accuracycheck BattleScript_RageMiss, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_RAGE
	seteffectprimary
	setmoveeffect 0
	goto BattleScript_HitFromAtkString

BattleScript_RageMiss::
	setmoveeffect MOVE_EFFECT_RAGE
	clearstatusfromeffect BS_ATTACKER
	goto BattleScript_PrintMoveMissed

BattleScript_EffectMimic::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	mimicattackcopy BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNLEARNEDMOVE2
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectMetronome::
	attackcanceler
	attackstring
	pause 0x20
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	metronome
BattleScript_EffectLeechSeed::
	attackcanceler
	attackstring
	pause 0x20
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck .+6, ACC_CURR_MOVE
	setseeded
	attackanimation
	waitanimation
	printfromtable gLeechSeedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSplash::
	attackcanceler
	attackstring
	ppreduce
	attackanimation
	waitanimation
	incrementgamestat GAME_STAT_USED_SPLASH
	printstring STRINGID_BUTNOTHINGHAPPENED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectDisable::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	disablelastusedattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNMOVEWASDISABLED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectLevelDamage::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	dmgtolevel
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectPsywave::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	psywavedamageeffect
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectCounter::
	attackcanceler
	counterdamagecalculator BattleScript_ButItFailedAtkStringPpReduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc2
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectEncore::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	trysetencore BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNGOTENCORE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectPainSplit::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	painsplitdmgcalc BattleScript_ButItFailed
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, sPAINSPLIT_HP
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_SHAREDPAIN
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSnore::
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SnoreIsAsleep
	attackstring
	ppreduce
	goto BattleScript_ButItFailed

BattleScript_SnoreIsAsleep::
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoSnore
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage 0x40
	statusanimation BS_ATTACKER
BattleScript_DoSnore::
	attackstring
	ppreduce
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_HitFromCritCalc

BattleScript_EffectConversion2::
	attackcanceler
	attackstring
	ppreduce
	settypetorandomresistance BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectLockOn::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	setalwayshitflag
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTOOKAIM
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSketch::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	copymovepermanently BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSKETCHEDMOVE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSleepTalk::
	attackcanceler
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_SleepTalkIsAsleep
	attackstring
	ppreduce
	goto BattleScript_ButItFailed

BattleScript_SleepTalkIsAsleep::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage 0x40
	statusanimation BS_ATTACKER
	attackstring
	ppreduce
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	trychoosesleeptalkmove BattleScript_SleepTalkUsingMove
	pause 0x40
	goto BattleScript_ButItFailed

BattleScript_SleepTalkUsingMove::
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove 1
BattleScript_EffectDestinyBond::
	attackcanceler
	attackstring
	ppreduce
	setdestinybond
	attackanimation
	waitanimation
	printstring STRINGID_PKMNTRYINGTOTAKEFOE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectFlail::
	remaininghptopower
	goto BattleScript_EffectHit

BattleScript_EffectSpite::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryspiteppreduce BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREDUCEDPP
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectHealBell::
	attackcanceler
	attackstring
	ppreduce
	healpartystatus
	waitstate
	attackanimation
	waitanimation
	printfromtable gPartyStatusHealStringIds
	waitmessage 0x40
	jumpifnotmove MOVE_HEAL_BELL, BattleScript_PartyHealEnd
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, 1, BattleScript_CheckHealBellMon2Unaffected
	printstring STRINGID_PKMNSXBLOCKSY
	waitmessage 0x40
BattleScript_CheckHealBellMon2Unaffected::
	jumpifbyte CMP_NO_COMMON_BITS, cMULTISTRING_CHOOSER, 2, BattleScript_PartyHealEnd
	printstring STRINGID_PKMNSXBLOCKSY2
	waitmessage 0x40
BattleScript_PartyHealEnd::
	updatestatusicon BS_ATTACKER_WITH_PARTNER
	waitstate
	goto BattleScript_MoveEnd

BattleScript_EffectTripleKick::
	attackcanceler
	attackstring
	ppreduce
	setbyte sTRIPLE_KICK_POWER, 0
	setbyte gBattleScripting + 19, 0
	initmultihitstring
	setmultihit 3
BattleScript_TripleKickLoop::
	jumpifhasnohp BS_ATTACKER, BattleScript_TripleKickEnd
	jumpifhasnohp BS_TARGET, BattleScript_TripleKickNoMoreHits
	jumpifhalfword CMP_EQUAL, gChosenMove, MOVE_SLEEP_TALK, BattleScript_DoTripleKickAttack
	jumpifstatus BS_ATTACKER, STATUS1_SLEEP, BattleScript_TripleKickNoMoreHits
BattleScript_DoTripleKickAttack::
	accuracycheck BattleScript_TripleKickNoMoreHits, ACC_CURR_MOVE
	movevaluescleanup
	addbyte sTRIPLE_KICK_POWER, 10
	addbyte gBattleScripting + 12, 1
	copyhword gDynamicBasePower, sTRIPLE_KICK_POWER
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	jumpifmovehadnoeffect BattleScript_TripleKickNoMoreHits
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	moveendto 16
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_FOE_ENDURED, BattleScript_TripleKickPrintStrings
	decrementmultihit BattleScript_TripleKickLoop
	goto BattleScript_TripleKickPrintStrings

BattleScript_TripleKickNoMoreHits::
	pause 0x20
	jumpifbyte CMP_EQUAL, gBattleScripting + 12, 0, BattleScript_TripleKickPrintStrings
	bicbyte gMoveResultFlags, MOVE_RESULT_MISSED
BattleScript_TripleKickPrintStrings::
	resultmessage
	waitmessage 0x40
	jumpifbyte CMP_EQUAL, gBattleScripting + 12, 0, BattleScript_TripleKickEnd
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE, BattleScript_TripleKickEnd
	copyarray gBattleTextBuff1, sMULTIHIT_STRING, 6
	printstring STRINGID_HITXTIMES
	waitmessage 0x40
BattleScript_TripleKickEnd::
	seteffectwithchance
	tryfaintmon BS_TARGET, 0, NULL
	moveendfrom 14
	end

BattleScript_EffectThief::
	setmoveeffect MOVE_EFFECT_STEAL_ITEM
	goto BattleScript_EffectHit

BattleScript_EffectMeanLook::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC
	jumpifstatus2 BS_TARGET, STATUS2_ESCAPE_PREVENTION, BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_PREVENT_ESCAPE
	seteffectprimary
	printstring STRINGID_TARGETCANTESCAPENOW
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectNightmare::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus2 BS_TARGET, STATUS2_NIGHTMARE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_SLEEP, BattleScript_NightmareWorked
	goto BattleScript_ButItFailed

BattleScript_NightmareWorked::
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_NIGHTMARE
	seteffectprimary
	printstring STRINGID_PKMNFELLINTONIGHTMARE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectMinimize::
	attackcanceler
	setminimize
	setstatchanger STAT_EVASION, 1, FALSE
	goto BattleScript_EffectStatUpAfterAtkCanceler

BattleScript_EffectCurse::
	jumpiftype2 BS_ATTACKER, TYPE_GHOST, BattleScript_GhostCurse
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_GREATER_THAN, STAT_SPEED, 0, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, CMP_NOT_EQUAL, STAT_ATK, 12, BattleScript_CurseTrySpeed
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_DEF, 12, BattleScript_ButItFailed
BattleScript_CurseTrySpeed::
	copybyte gBattlerTarget, gBattlerAttacker
	setbyte sB_ANIM_TURN, 1
	attackanimation
	waitanimation
	setstatchanger STAT_SPEED, 1, TRUE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_CurseTryAttack
	printfromtable gStatDownStringIds
	waitmessage 0x40
BattleScript_CurseTryAttack::
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_CurseTryDefence
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_CurseTryDefence::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_CurseEnd
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_CurseEnd::
	goto BattleScript_MoveEnd

BattleScript_GhostCurse::
	jumpifbytenotequal gBattlerAttacker, gBattlerTarget, BattleScript_DoGhostCurse
	getmovetarget BS_ATTACKER
BattleScript_DoGhostCurse::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	cursetarget BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	setbyte sB_ANIM_TURN, 0
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNLAIDCURSE
	waitmessage 0x40
	tryfaintmon BS_ATTACKER, 0, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectProtect::
	attackcanceler
	attackstring
	ppreduce
	setprotectlike
	attackanimation
	waitanimation
	printfromtable gProtectLikeUsedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSpikes::
	attackcanceler
	trysetspikes BattleScript_ButItFailedAtkStringPpReduce
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_SPIKESSCATTERED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectForesight::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	setforesight
	attackanimation
	waitanimation
	printstring STRINGID_PKMNIDENTIFIED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectPerishSong::
	attackcanceler
	attackstring
	ppreduce
	trysetperishsong BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_FAINTINTHREE
	waitmessage 0x40
	setbyte sBATTLER, 0
BattleScript_PerishSongLoop::
	jumpifability BS_SCRIPTING, ABILITY_SOUNDPROOF, BattleScript_PerishSongNotAffected
BattleScript_PerishSongLoopIncrement::
	addbyte sBATTLER, 1
	jumpifbytenotequal sBATTLER, gBattlersCount, BattleScript_PerishSongLoop
	goto BattleScript_MoveEnd

BattleScript_PerishSongNotAffected::
	printstring STRINGID_PKMNSXBLOCKSY2
	waitmessage 0x40
	goto BattleScript_PerishSongLoopIncrement

BattleScript_EffectSandstorm::
	attackcanceler
	attackstring
	ppreduce
	setsandstorm
	goto BattleScript_MoveWeatherChange

BattleScript_EffectRollout::
	attackcanceler
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_RolloutHit
	ppreduce
BattleScript_RolloutHit::
	accuracycheck .+6, ACC_CURR_MOVE
	typecalc2
	rolloutdamagecalculation
	goto BattleScript_HitFromCritCalc

BattleScript_EffectSwagger::
	attackcanceler
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed 1, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger STAT_ATK, 2, FALSE
	statbuffchange STAT_CHANGE_BS_PTR, BattleScript_SwaggerTryConfuse
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_SwaggerTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_SwaggerTryConfuse::
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	setmoveeffect MOVE_EFFECT_CONFUSION
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_EffectFuryCutter::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck .+6, ACC_CURR_MOVE
BattleScript_FuryCutterHit::
	furycuttercalc
	critcalc
	damagecalc
	typecalc
	jumpifmovehadnoeffect BattleScript_FuryCutterHit
	adjustnormaldamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectAttract::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryinfatuating BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLINLOVE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectReturn::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	happinesstodamagecalculation
	goto BattleScript_HitFromAtkString

BattleScript_EffectPresent::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	presentdamagecalculation
BattleScript_EffectSafeguard::
	attackcanceler
	attackstring
	ppreduce
	setsafeguard
	goto BattleScript_PrintReflectLightScreenSafeguardString

BattleScript_EffectThawHit::
	setmoveeffect MOVE_EFFECT_BURN
	goto BattleScript_EffectHit

BattleScript_EffectMagnitude::
	attackcanceler
	attackstring
	ppreduce
	selectfirstvalidtarget
	magnitudedamagecalculation
	pause 0x20
	printstring STRINGID_MAGNITUDESTRENGTH
	waitmessage 0x40
	goto BattleScript_HitsAllWithUndergroundBonusLoop

BattleScript_EffectBatonPass::
	attackcanceler
	attackstring
	ppreduce
	jumpifcantswitch BS_ATTACKER | ATK4F_DONT_CHECK_STATUSES, BattleScript_ButItFailed
	attackanimation
	waitanimation
	openpartyscreen BS_ATTACKER, BattleScript_ButItFailed
	switchoutabilities BS_ATTACKER
	waitstate
	switchhandleorder BS_ATTACKER, 2
	returntoball BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	switchinanim BS_ATTACKER, 1
	waitstate
	switchineffects BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectRapidSpin::
	setmoveeffect MOVE_EFFECT_RAPIDSPIN | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectSonicboom::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	setword gBattleMoveDamage, 20
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectMorningSun::
	attackcanceler
	attackstring
	ppreduce
	recoverbasedonsunlight BattleScript_AlreadyAtFullHp
	goto BattleScript_PresentHealTarget

BattleScript_EffectHiddenPower::
	attackcanceler
	hiddenpowercalc
	goto BattleScript_HitFromAccCheck

BattleScript_EffectRainDance::
	attackcanceler
	attackstring
	ppreduce
	setrain
BattleScript_MoveWeatherChange::
	attackanimation
	waitanimation
	printfromtable gMoveWeatherChangeStringIds
	waitmessage 0x40
	call BattleScript_HandleWeatherFormChanges
	goto BattleScript_MoveEnd

BattleScript_EffectSunnyDay::
	attackcanceler
	attackstring
	ppreduce
	setsunny
	goto BattleScript_MoveWeatherChange

BattleScript_EffectDefenseUpHit::
	setmoveeffect MOVE_EFFECT_DEF_PLUS_1 | MOVE_EFFECT_AFFECTS_USER
	goto BattleScript_EffectHit

BattleScript_EffectAttackUpHit::
	setmoveeffect MOVE_EFFECT_ATK_PLUS_1 | MOVE_EFFECT_AFFECTS_USER
	goto BattleScript_EffectHit

BattleScript_EffectAllStatsUpHit::
	setmoveeffect MOVE_EFFECT_ALL_STATS_UP | MOVE_EFFECT_AFFECTS_USER
	goto BattleScript_EffectHit

BattleScript_EffectBellyDrum::
	attackcanceler
	attackstring
	ppreduce
	maxattackhalvehp BattleScript_ButItFailed
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	attackanimation
	waitanimation
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNCUTHPMAXEDATTACK
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectPsychUp::
	attackcanceler
	attackstring
	ppreduce
	copyfoestats BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCOPIEDSTATCHANGES
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectMirrorCoat::
	attackcanceler
	mirrorcoatdamagecalculator BattleScript_ButItFailedAtkStringPpReduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	typecalc2
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectSkullBash::
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	setbyte sTWOTURN_STRINGID, 2
	call BattleScriptFirstChargingTurn
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_SkullBashEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_SkullBashEnd
	setgraphicalstatchangevalues
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_SkullBashEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectTwister::
	jumpifnostatus3 BS_TARGET, STATUS3_ON_AIR, BattleScript_FlinchEffect
	orword gHitMarker, HITMARKER_IGNORE_ON_AIR
	setbyte sDMG_MULTIPLIER, 2
BattleScript_FlinchEffect::
	setmoveeffect MOVE_EFFECT_FLINCH
	goto BattleScript_EffectHit

BattleScript_EffectEarthquake::
	attackcanceler
	attackstring
	ppreduce
	selectfirstvalidtarget
BattleScript_HitsAllWithUndergroundBonusLoop::
	movevaluescleanup
	jumpifnostatus3 BS_TARGET, STATUS3_UNDERGROUND, BattleScript_HitsAllNoUndergroundBonus
	orword gHitMarker, HITMARKER_IGNORE_UNDERGROUND
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_DoHitAllWithUndergroundBonus

BattleScript_HitsAllNoUndergroundBonus::
	bicword gHitMarker, HITMARKER_IGNORE_UNDERGROUND
	setbyte sDMG_MULTIPLIER, 1
BattleScript_DoHitAllWithUndergroundBonus::
	accuracycheck BattleScript_HitAllWithUndergroundBonusMissed, ACC_CURR_MOVE
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	resultmessage
	waitmessage 0x40
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	tryfaintmon BS_TARGET, 0, NULL
	moveendto 16
	jumpifnexttargetvalid BattleScript_HitsAllWithUndergroundBonusLoop
	end

BattleScript_HitAllWithUndergroundBonusMissed::
	pause 0x20
	typecalc
	effectivenesssound
	resultmessage
	waitmessage 0x40
	moveendto 16
	jumpifnexttargetvalid BattleScript_HitsAllWithUndergroundBonusLoop
	end

BattleScript_EffectFutureSight::
	attackcanceler
	attackstring
	ppreduce
	trysetfutureattack BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gFutureMoveUsedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectGust::
	jumpifnostatus3 BS_TARGET, STATUS3_ON_AIR, BattleScript_EffectHit
	orword gHitMarker, HITMARKER_IGNORE_ON_AIR
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_EffectHit

BattleScript_EffectFlinchMinimizeHit::
	jumpifnostatus3 BS_TARGET, STATUS3_MINIMIZED, BattleScript_FlinchEffect
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_FlinchEffect

BattleScript_EffectSolarbeam::
	jumpifabilitypresent ABILITY_CLOUD_NINE, BattleScript_SolarbeamDecideTurn
	jumpifabilitypresent ABILITY_AIR_LOCK, BattleScript_SolarbeamDecideTurn
	jumpifhalfword CMP_COMMON_BITS, gBattleWeather, 96, BattleScript_SolarbeamOnFirstTurn
BattleScript_SolarbeamDecideTurn::
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_TwoTurnMovesSecondTurn
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_TwoTurnMovesSecondTurn
	setbyte sTWOTURN_STRINGID, 1
	call BattleScriptFirstChargingTurn
	goto BattleScript_MoveEnd

BattleScript_SolarbeamOnFirstTurn::
	orword gHitMarker, HITMARKER_CHARGING
	setmoveeffect MOVE_EFFECT_CHARGING | MOVE_EFFECT_AFFECTS_USER
	seteffectprimary
	ppreduce
	goto BattleScript_TwoTurnMovesSecondTurn

BattleScript_EffectThunder::
	setmoveeffect MOVE_EFFECT_PARALYSIS
	orword gHitMarker, HITMARKER_IGNORE_ON_AIR
	goto BattleScript_EffectHit

BattleScript_EffectTeleport::
	attackcanceler
	attackstring
	ppreduce
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_ButItFailed
	getifcantrunfrombattle BS_ATTACKER
	jumpifbyte CMP_EQUAL, gBattleCommunication, 1, BattleScript_ButItFailed
	jumpifbyte CMP_EQUAL, gBattleCommunication, 2, BattleScript_PrintAbilityMadeIneffective
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFLEDFROMBATTLE
	waitmessage 0x40
	setbyte gBattleOutcome, B_OUTCOME_PLAYER_TELEPORTED
	goto BattleScript_MoveEnd

BattleScript_EffectBeatUp::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	pause 0x20
	ppreduce
	setbyte gBattleCommunication, 0
BattleScript_BeatUpLoop::
	movevaluescleanup
	trydobeatup BattleScript_BeatUpEnd, BattleScript_ButItFailed
	printstring STRINGID_PKMNATTACK
	critcalc
	jumpifbyte CMP_NOT_EQUAL, gCritMultiplier, 2, BattleScript_BeatUpAttack
	manipulatedamage 2
BattleScript_BeatUpAttack::
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	resultmessage
	waitmessage 0x40
	tryfaintmon BS_TARGET, 0, NULL
	moveendto 16
	goto BattleScript_BeatUpLoop

BattleScript_BeatUpEnd::
	end

BattleScript_EffectSemiInvulnerable::
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_SecondTurnSemiInvulnerable
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_NO_ATTACKSTRING, BattleScript_SecondTurnSemiInvulnerable
	jumpifmove MOVE_FLY, BattleScript_FlyFirstTurn
	jumpifmove MOVE_DIVE, BattleScript_DiveFirstTurn
	jumpifmove MOVE_BOUNCE, BattleScript_BounceFirstTurn
	@ MOVE_DIG
	setbyte sTWOTURN_STRINGID, 5
	goto BattleScript_FirstTurnSemiInvulnerable

BattleScript_BounceFirstTurn::
	setbyte sTWOTURN_STRINGID, 7
	goto BattleScript_FirstTurnSemiInvulnerable

BattleScript_DiveFirstTurn::
	setbyte sTWOTURN_STRINGID, 6
	goto BattleScript_FirstTurnSemiInvulnerable

BattleScript_FlyFirstTurn::
	setbyte sTWOTURN_STRINGID, 4
BattleScript_FirstTurnSemiInvulnerable::
	call BattleScriptFirstChargingTurn
	setsemiinvulnerablebit
	goto BattleScript_MoveEnd

BattleScript_SecondTurnSemiInvulnerable::
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	setbyte sB_ANIM_TURN, 1
	clearstatusfromeffect BS_ATTACKER
	orword gHitMarker, HITMARKER_NO_PPDEDUCT
	jumpifnotmove MOVE_BOUNCE, BattleScript_SemiInvulnerableTryHit
	setmoveeffect MOVE_EFFECT_PARALYSIS
BattleScript_SemiInvulnerableTryHit::
	accuracycheck BattleScript_SemiInvulnerableMiss, ACC_CURR_MOVE
	clearsemiinvulnerablebit
	goto BattleScript_HitFromAtkString

BattleScript_SemiInvulnerableMiss::
	clearsemiinvulnerablebit
	goto BattleScript_PrintMoveMissed

BattleScript_EffectDefenseCurl::
	attackcanceler
	attackstring
	ppreduce
	setdefensecurlbit
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_DefenseCurlDoStatUpAnim
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_StatUpPrintString
	attackanimation
	waitanimation
BattleScript_DefenseCurlDoStatUpAnim::
	goto BattleScript_StatUpDoAnim

BattleScript_EffectSoftboiled::
	attackcanceler
	attackstring
	ppreduce
	tryhealhalfhealth BattleScript_AlreadyAtFullHp, BS_TARGET
BattleScript_PresentHealTarget::
	attackanimation
	waitanimation
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_AlreadyAtFullHp::
	pause 0x20
	printstring STRINGID_PKMNHPFULL
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectFakeOut::
	attackcanceler
	jumpifnotfirstturn BattleScript_ButItFailedAtkStringPpReduce
	setmoveeffect MOVE_EFFECT_FLINCH | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_ButItFailedAtkStringPpReduce::
	attackstring
BattleScript_ButItFailedPpReduce::
	ppreduce
BattleScript_ButItFailed::
	pause 0x20
	orbyte gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_NotAffected::
	pause 0x20
	orbyte gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	resultmessage
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectUproar::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	setmoveeffect MOVE_EFFECT_UPROAR | MOVE_EFFECT_AFFECTS_USER
	attackstring
	jumpifstatus2 BS_ATTACKER, STATUS2_MULTIPLETURNS, BattleScript_UproarHit
	ppreduce
BattleScript_UproarHit::
	nop
	goto BattleScript_HitFromCritCalc

BattleScript_EffectStockpile::
	attackcanceler
	attackstring
	ppreduce
	stockpile
	attackanimation
	waitanimation
	printfromtable gStockpileUsedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSpitUp::
	attackcanceler
	jumpifbyte CMP_EQUAL, gBattleCommunication + 6, 1, BattleScript_SpitUpNoDamage
	attackstring
	ppreduce
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	stockpiletobasedamage BattleScript_SpitUpFail
	typecalc
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_SpitUpFail::
	pause 0x20
	printstring STRINGID_FAILEDTOSPITUP
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_SpitUpNoDamage::
	attackstring
	ppreduce
	pause 0x40
	stockpiletobasedamage BattleScript_SpitUpFail
	resultmessage
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSwallow::
	attackcanceler
	attackstring
	ppreduce
	stockpiletohpheal BattleScript_SwallowFail
	goto BattleScript_PresentHealTarget

BattleScript_SwallowFail::
	pause 0x20
	printfromtable gSwallowFailStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectHail::
	attackcanceler
	attackstring
	ppreduce
	sethail
	goto BattleScript_MoveWeatherChange

BattleScript_EffectTorment::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	settorment BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSUBJECTEDTOTORMENT
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectFlatter::
	attackcanceler
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_MakeMoveMissed
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	jumpifconfusedandstatmaxed 4, BattleScript_ButItFailed
	attackanimation
	waitanimation
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR, BattleScript_FlatterTryConfuse
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_FlatterTryConfuse
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_FlatterTryConfuse::
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	setmoveeffect MOVE_EFFECT_CONFUSION
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_EffectWillOWisp::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifstatus BS_TARGET, STATUS1_BURN, BattleScript_AlreadyBurned
	jumpiftype BS_TARGET, TYPE_FIRE, BattleScript_NotAffected
	jumpifability BS_TARGET, ABILITY_WATER_VEIL, BattleScript_WaterVeilPrevents
	jumpifstatus BS_TARGET, STATUS1_ANY, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	attackanimation
	waitanimation
	setmoveeffect MOVE_EFFECT_BURN
	seteffectprimary
	goto BattleScript_MoveEnd

BattleScript_WaterVeilPrevents::
	copybyte gEffectBattler, gBattlerTarget
	setbyte cMULTISTRING_CHOOSER, 0
	call BattleScript_BRNPrevention
	goto BattleScript_MoveEnd

BattleScript_AlreadyBurned::
	pause 0x20
	printstring STRINGID_PKMNALREADYHASBURN
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectMemento::
	attackcanceler
	jumpifbyte CMP_EQUAL, gBattleCommunication + 6, 1, BattleScript_MementoNoReduceStats
	attackstring
	ppreduce
	jumpifattackandspecialattackcannotfall BattleScript_ButItFailed
	setatkhptozero
	attackanimation
	waitanimation
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_MementoSubstituteInvulnerable
	setbyte sSTAT_ANIM_PLAYED, 0
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_SPATK, ATK48_STAT_NEGATIVE | ATK48_STAT_BY_TWO | ATK48_ONLY_MULTIPLE
	playstatchangeanimation BS_TARGET, BIT_ATK, ATK48_STAT_NEGATIVE | ATK48_STAT_BY_TWO
	setstatchanger STAT_ATK, 2, TRUE
	statbuffchange STAT_CHANGE_BS_PTR, BattleScript_MementoSkipStatDown1
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, 1, BattleScript_MementoSkipStatDown1
	printfromtable gStatDownStringIds
	waitmessage 0x40
BattleScript_MementoSkipStatDown1::
	playstatchangeanimation BS_TARGET, BIT_SPATK, ATK48_STAT_NEGATIVE | ATK48_STAT_BY_TWO
	setstatchanger STAT_SPATK, 2, TRUE
	statbuffchange STAT_CHANGE_BS_PTR, BattleScript_MementoSkipStatDown2
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, 1, BattleScript_MementoSkipStatDown2
	printfromtable gStatDownStringIds
	waitmessage 0x40
BattleScript_MementoSkipStatDown2::
	tryfaintmon BS_ATTACKER, 0, NULL
	goto BattleScript_MoveEnd

BattleScript_MementoSubstituteInvulnerable::
	printstring STRINGID_BUTNOEFFECT
	waitmessage 0x40
	goto BattleScript_MementoSkipStatDown2

BattleScript_MementoNoReduceStats::
	attackstring
	ppreduce
	jumpifattackandspecialattackcannotfall .+4
	setatkhptozero
	pause 0x40
	effectivenesssound
	resultmessage
	waitmessage 0x40
	tryfaintmon BS_ATTACKER, 0, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectFacade::
	jumpifstatus BS_ATTACKER, STATUS1_POISON | STATUS1_PARALYSIS | STATUS1_BURN | STATUS1_TOXIC_POISON, BattleScript_FacadeDoubleDmg
	goto BattleScript_EffectHit

BattleScript_FacadeDoubleDmg::
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_EffectHit

BattleScript_EffectFocusPunch::
	attackcanceler
	jumpifnodamage BattleScript_HitFromAccCheck
	ppreduce
	printstring STRINGID_PKMNLOSTFOCUS
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSmellingsalt::
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_EffectHit
	setmoveeffect MOVE_EFFECT_REMOVE_PARALYSIS | MOVE_EFFECT_CERTAIN
	jumpifstatus BS_TARGET, STATUS1_PARALYSIS, BattleScript_SmellingSaltBuff
	goto BattleScript_EffectHit

BattleScript_SmellingSaltBuff::
	setbyte sDMG_MULTIPLIER, 2
	goto BattleScript_EffectHit

BattleScript_EffectFollowMe::
	attackcanceler
	attackstring
	ppreduce
	setforcedtarget
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCENTERATTENTION
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectNaturePower::
	attackcanceler
	attackstring
	pause 0x20
	callterrainattack
	printstring STRINGID_NATUREPOWERTURNEDINTO
	waitmessage 0x40
	return

BattleScript_EffectCharge::
	attackcanceler
	attackstring
	ppreduce
	setcharge
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHARGINGPOWER
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectTaunt::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	settaunt BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNFELLFORTAUNT
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectHelpingHand::
	attackcanceler
	attackstring
	ppreduce
	trysethelpinghand BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNREADYTOHELP
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectTrick::
	attackcanceler
	attackstring
	ppreduce
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	tryswapitems BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWITCHEDITEMS
	waitmessage 0x40
	printfromtable gItemSwapStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectRolePlay::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	trycopyability BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCOPIEDFOE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectWish::
	attackcanceler
	attackstring
	ppreduce
	trywish 0, BattleScript_ButItFailed
	attackanimation
	waitanimation
	goto BattleScript_MoveEnd

BattleScript_EffectAssist::
	attackcanceler
	attackstring
	assistattackselect BattleScript_ButItFailedPpReduce
	attackanimation
	waitanimation
	setbyte sB_ANIM_TURN, 0
	setbyte sB_ANIM_TARGETS_HIT, 0
	jumptocalledmove 1
BattleScript_EffectIngrain::
	attackcanceler
	attackstring
	ppreduce
	trysetroots BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNPLANTEDROOTS
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSuperpower::
	setmoveeffect MOVE_EFFECT_ATK_DEF_DOWN | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectMagicCoat::
	attackcanceler
	trysetmagiccoat BattleScript_ButItFailedAtkStringPpReduce
	attackstring
	ppreduce
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSHROUDEDITSELF
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectRecycle::
	attackcanceler
	attackstring
	ppreduce
	tryrecycleitem BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_XFOUNDONEY
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectRevenge::
	doubledamagedealtifdamaged
	goto BattleScript_EffectHit

BattleScript_EffectBrickBreak::
	attackcanceler
	accuracycheck BattleScript_PrintMoveMissed, ACC_CURR_MOVE
	attackstring
	ppreduce
	removelightscreenreflect
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	jumpifbyte CMP_EQUAL, sB_ANIM_TURN, 0, BattleScript_BrickBreakAnim
	bicbyte gMoveResultFlags, MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE
BattleScript_BrickBreakAnim::
	attackanimation
	waitanimation
	jumpifbyte CMP_LESS_THAN, sB_ANIM_TURN, 2, BattleScript_BrickBreakDoHit
	printstring STRINGID_THEWALLSHATTERED
	waitmessage 0x40
BattleScript_BrickBreakDoHit::
	typecalc2
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	resultmessage
	waitmessage 0x40
	seteffectwithchance
	tryfaintmon BS_TARGET, 0, NULL
	goto BattleScript_MoveEnd

BattleScript_EffectYawn::
	attackcanceler
	attackstring
	ppreduce
	jumpifability BS_TARGET, ABILITY_VITAL_SPIRIT, BattleScript_PrintBankAbilityMadeIneffective
	jumpifability BS_TARGET, ABILITY_INSOMNIA, BattleScript_PrintBankAbilityMadeIneffective
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_ButItFailed
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_SafeguardProtected
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	jumpifcantmakeasleep BattleScript_ButItFailed
	setyawn BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWASMADEDROWSY
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_PrintBankAbilityMadeIneffective::
	copybyte sBATTLER, sBATTLER_WITH_ABILITY
BattleScript_PrintAbilityMadeIneffective::
	pause 0x20
	printstring STRINGID_PKMNSXMADEITINEFFECTIVE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectKnockOff::
	setmoveeffect MOVE_EFFECT_KNOCK_OFF
	goto BattleScript_EffectHit

BattleScript_EffectEndeavor::
	attackcanceler
	attackstring
	ppreduce
	setdamagetohealthdifference BattleScript_ButItFailed
	copyword gHpDealt, gBattleMoveDamage
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	typecalc
	jumpifmovehadnoeffect BattleScript_HitFromAtkAnimation
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	copyword gBattleMoveDamage, gHpDealt
	adjustsetdamage
	goto BattleScript_HitFromAtkAnimation

BattleScript_EffectEruption::
	scaledamagebyhealthratio
	goto BattleScript_EffectHit

BattleScript_EffectSkillSwap::
	attackcanceler
	attackstring
	ppreduce
	accuracycheck BattleScript_ButItFailed, NO_ACC_CALC_CHECK_LOCK_ON
	tryswapabilities BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSWAPPEDABILITIES
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectImprison::
	attackcanceler
	attackstring
	ppreduce
	tryimprison BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSEALEDOPPONENTMOVE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectRefresh::
	attackcanceler
	attackstring
	ppreduce
	cureifburnedparalysedorpoisoned BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNSTATUSNORMAL
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_EffectGrudge::
	attackcanceler
	attackstring
	ppreduce
	trysetgrudge BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNWANTSGRUDGE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectSnatch::
	attackcanceler
	trysetsnatch BattleScript_ButItFailedAtkStringPpReduce
	attackstring
	ppreduce
	attackanimation
	waitanimation
	pause 0x20
	printstring STRINGID_PKMNWAITSFORTARGET
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectLowKick::
	attackcanceler
	attackstring
	ppreduce
	weightdamagecalculation
	accuracycheck BattleScript_MoveMissedPause, ACC_CURR_MOVE
	goto BattleScript_HitFromCritCalc

BattleScript_EffectSecretPower::
	getsecretpowereffect
	goto BattleScript_EffectHit

BattleScript_EffectDoubleEdge::
	setmoveeffect MOVE_EFFECT_RECOIL_33 | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectTeeterDance::
	attackcanceler
	attackstring
	ppreduce
	setbyte gBattlerTarget, 0
BattleScript_TeeterDanceLoop::
	movevaluescleanup
	setmoveeffect MOVE_EFFECT_CONFUSION
	jumpifbyteequal gBattlerAttacker, gBattlerTarget, BattleScript_TeeterDanceLoopIncrement
	jumpifability BS_TARGET, ABILITY_OWN_TEMPO, BattleScript_TeeterDanceOwnTempoPrevents
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_TeeterDanceSubstitutePrevents
	jumpifstatus2 BS_TARGET, STATUS2_CONFUSION, BattleScript_TeeterDanceAlreadyConfused
	accuracycheck BattleScript_TeeterDanceMissed, ACC_CURR_MOVE
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, BattleScript_TeeterDanceSafeguardProtected
	attackanimation
	waitanimation
	seteffectprimary
	resultmessage
	waitmessage 0x40
BattleScript_TeeterDanceLoopIncrement::
	moveendto 16
	addbyte gBattlerTarget, 1
	jumpifbytenotequal gBattlerTarget, gBattlersCount, BattleScript_TeeterDanceLoop
	end

BattleScript_TeeterDanceOwnTempoPrevents::
	pause 0x20
	printstring STRINGID_PKMNPREVENTSCONFUSIONWITH
	waitmessage 0x40
	goto BattleScript_TeeterDanceLoopIncrement

BattleScript_TeeterDanceSafeguardProtected::
	pause 0x20
	printstring STRINGID_PKMNUSEDSAFEGUARD
	waitmessage 0x40
	goto BattleScript_TeeterDanceLoopIncrement

BattleScript_TeeterDanceSubstitutePrevents::
	pause 0x20
	printstring STRINGID_BUTITFAILED
	waitmessage 0x40
	goto BattleScript_TeeterDanceLoopIncrement

BattleScript_TeeterDanceAlreadyConfused::
	pause 0x20
	printstring STRINGID_PKMNALREADYCONFUSED
	waitmessage 0x40
	goto BattleScript_TeeterDanceLoopIncrement

BattleScript_TeeterDanceMissed::
	resultmessage
	waitmessage 0x40
	goto BattleScript_TeeterDanceLoopIncrement

BattleScript_EffectMudSport::
	attackcanceler
	attackstring
	ppreduce
	settypebasedhalvers BattleScript_ButItFailed
	attackanimation
	waitanimation
	printfromtable gSportsUsedStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectPoisonFang::
	setmoveeffect MOVE_EFFECT_TOXIC
	goto BattleScript_EffectHit

BattleScript_EffectWeatherBall::
	setweatherballtype
	goto BattleScript_EffectHit

BattleScript_EffectOverheat::
	setmoveeffect MOVE_EFFECT_SP_ATK_TWO_DOWN | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN
	goto BattleScript_EffectHit

BattleScript_EffectTickle::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_TARGET, CMP_GREATER_THAN, STAT_ATK, 0, BattleScript_TickleDoMoveAnim
	jumpifstat BS_TARGET, CMP_EQUAL, STAT_DEF, 0, BattleScript_CantLowerMultipleStats
BattleScript_TickleDoMoveAnim::
	accuracycheck BattleScript_ButItFailed, ACC_CURR_MOVE
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, 0
	playstatchangeanimation BS_TARGET, BIT_ATK | BIT_DEF, ATK48_STAT_NEGATIVE | ATK48_ONLY_MULTIPLE
	playstatchangeanimation BS_TARGET, BIT_ATK, ATK48_STAT_NEGATIVE
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_BS_PTR, BattleScript_TickleTryLowerDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_TickleTryLowerDef
	printfromtable gStatDownStringIds
	waitmessage 0x40
BattleScript_TickleTryLowerDef::
	playstatchangeanimation BS_TARGET, BIT_DEF, ATK48_STAT_NEGATIVE
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange STAT_CHANGE_BS_PTR, BattleScript_TickleEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_TickleEnd
	printfromtable gStatDownStringIds
	waitmessage 0x40
BattleScript_TickleEnd::
	goto BattleScript_MoveEnd

BattleScript_CantLowerMultipleStats::
	pause 0x20
	orbyte gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTDECREASE2
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectCosmicPower::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, 12, BattleScript_CosmicPowerDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, 12, BattleScript_CantRaiseMultipleStats
BattleScript_CosmicPowerDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, 0
	playstatchangeanimation BS_ATTACKER, BIT_DEF | BIT_SPDEF, 0
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_CosmicPowerTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_CosmicPowerTrySpDef
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_CosmicPowerTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_CosmicPowerEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_CosmicPowerEnd
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_CosmicPowerEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectSkyUppercut::
	orword gHitMarker, HITMARKER_IGNORE_ON_AIR
	goto BattleScript_EffectHit

BattleScript_EffectBulkUp::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, 12, BattleScript_BulkUpDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_DEF, 12, BattleScript_CantRaiseMultipleStats
BattleScript_BulkUpDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, 0
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_BulkUpTryDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_BulkUpTryDef
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_BulkUpTryDef::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_BulkUpEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_BulkUpEnd
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_BulkUpEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectCalmMind::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, 12, BattleScript_CalmMindDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, 12, BattleScript_CantRaiseMultipleStats
BattleScript_CalmMindDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, 0
	playstatchangeanimation BS_ATTACKER, BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_CalmMindTrySpDef
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_CalmMindTrySpDef
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_CalmMindTrySpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_CalmMindEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_CalmMindEnd
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_CalmMindEnd::
	goto BattleScript_MoveEnd

BattleScript_CantRaiseMultipleStats::
	pause 0x20
	orbyte gMoveResultFlags, MOVE_RESULT_FAILED
	printstring STRINGID_STATSWONTINCREASE2
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_EffectDragonDance::
	attackcanceler
	attackstring
	ppreduce
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, 12, BattleScript_DragonDanceDoMoveAnim
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPEED, 12, BattleScript_CantRaiseMultipleStats
BattleScript_DragonDanceDoMoveAnim::
	attackanimation
	waitanimation
	setbyte sSTAT_ANIM_PLAYED, 0
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_SPEED, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_DragonDanceTrySpeed
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_DragonDanceTrySpeed
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_DragonDanceTrySpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_DragonDanceEnd
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_DragonDanceEnd
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_DragonDanceEnd::
	goto BattleScript_MoveEnd

BattleScript_EffectCamouflage::
	attackcanceler
	attackstring
	ppreduce
	settypetoterrain BattleScript_ButItFailed
	attackanimation
	waitanimation
	printstring STRINGID_PKMNCHANGEDTYPE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_FaintAttacker::
	playfaintcry BS_ATTACKER
	pause 0x40
	dofaintanimation BS_ATTACKER
	cleareffectsonfaint BS_ATTACKER
	printstring STRINGID_ATTACKERFAINTED
	printstring STRINGID_EMPTYSTRING3
	return

BattleScript_FaintTarget::
	playfaintcry BS_TARGET
	pause 0x40
	dofaintanimation BS_TARGET
	cleareffectsonfaint BS_TARGET
	printstring STRINGID_TARGETFAINTED
	printstring STRINGID_EMPTYSTRING3
	return

BattleScript_GiveExp::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	end2

BattleScript_HandleFaintedMon::
	atk24 BattleScript_LinkBattleHandleFaint
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_FaintedMonEnd
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_FaintedMonTryChooseAnother
	jumpifword CMP_NO_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonTryChooseAnother
	printstring STRINGID_USENEXTPKMN
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 0, BattleScript_FaintedMonTryChooseAnother
	jumpifplayerran BattleScript_FaintedMonEnd
	printstring STRINGID_CANTESCAPE2
BattleScript_FaintedMonTryChooseAnother::
	openpartyscreen BS_FAINTED, BattleScript_FaintedMonEnd
	switchhandleorder BS_FAINTED, 2
	jumpifnotbattletype BATTLE_TYPE_TRAINER, BattleScript_FaintedMonChooseAnother
	jumpifbattletype BATTLE_TYPE_LINK, BattleScript_FaintedMonChooseAnother
	jumpifbattletype BATTLE_TYPE_BATTLE_TOWER, BattleScript_FaintedMonChooseAnother
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonChooseAnother
	jumpifword CMP_COMMON_BITS, gHitMarker, HITMARKER_PLAYER_FAINTED, BattleScript_FaintedMonChooseAnother
	jumpifbyte CMP_EQUAL, sBATTLE_STYLE, 2, BattleScript_FaintedMonChooseAnother
	jumpifcantswitch BS_PLAYER1, BattleScript_FaintedMonChooseAnother
	jumpifbyte CMP_EQUAL, sBATTLE_STYLE, 1, BattleScript_SwitchBattleStylePrintString
	printstring STRINGID_ENEMYABOUTTOSWITCHPKMN
BattleScript_HandleSwitchAfterFaintingEnemyInput::
	setbyte gBattleCommunication, 0
	yesnobox
	jumpifbyte CMP_EQUAL, gBattleCommunication + 1, 1, BattleScript_FaintedMonChooseAnother
	setatktoplayer0
	openpartyscreen BS_ATTACKER | OPEN_PARTY_ALLOW_CANCEL, BattleScript_FaintedMonChooseAnother
	switchhandleorder BS_ATTACKER, 2
	jumpifbyte CMP_EQUAL, gBattleCommunication, 6, BattleScript_FaintedMonChooseAnother
	atknameinbuff1
	resetintimidatetracebits BS_ATTACKER
	hpthresholds2 BS_ATTACKER
	printstring STRINGID_RETURNMON
	switchoutabilities BS_ATTACKER
	waitstate
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, 0
	waitstate
	switchineffects BS_ATTACKER
	resetsentmonsvalue
BattleScript_FaintedMonChooseAnother::
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, 0
	waitstate
	various7 BS_ATTACKER
	switchineffects BS_FAINTED
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_FaintedMonEnd
	cancelallactions
BattleScript_FaintedMonEnd::
	end2

BattleScript_SwitchBattleStylePrintString::
	printstring STRINGID_ENEMYABOUTTOSWITCHPKMNNOPREDICT
	jumpifbyte CMP_EQUAL, sBATTLE_STYLE, 1, BattleScript_HandleSwitchAfterFaintingEnemyInput

BattleScript_LinkBattleHandleFaint::
	openpartyscreen BS_UNKNOWN_5, .+4
	switchhandleorder BS_FAINTED, 0
	openpartyscreen BS_UNKNOWN_6, BattleScript_LinkBattleFaintedMonEnd
	switchhandleorder BS_FAINTED, 0
BattleScript_LinkBattleFaintedMonLoop::
	switchhandleorder BS_FAINTED, 2
	drawpartystatussummary BS_FAINTED
	getswitchedmondata BS_FAINTED
	switchindataupdate BS_FAINTED
	hpthresholds BS_FAINTED
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_FAINTED
	switchinanim BS_FAINTED, 0
	waitstate
	switchineffects 5
	jumpifbytenotequal gBattlerFainted, gBattlersCount, BattleScript_LinkBattleFaintedMonLoop
BattleScript_LinkBattleFaintedMonEnd::
	end2

BattleScript_LocalTrainerBattleWon::
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	getmoneyreward .+4
	printstring STRINGID_PLAYERGOTMONEY
	waitmessage 0x40
BattleScript_PayDayMoneyAndPickUpItems::
	givepaydaymoney
	pickup
	end2

BattleScript_PickedUpItem::
	printstring STRINGID_PICKUP
	waitmessage 0x40
	return

BattleScript_PickedUpItemSolo::
	printstring STRINGID_PICKUPSOLO
	waitmessage 0x40
	return

BattleScript_LocalBattleLost::
	jumpifbattletype BATTLE_TYPE_BATTLE_TOWER, BattleScript_EReaderOrSecretBaseTrainerEnd
	jumpifbattletype BATTLE_TYPE_TRAINER_TOWER, BattleScript_BattleTowerLost
	jumpifbattletype BATTLE_TYPE_EREADER_TRAINER, BattleScript_EReaderOrSecretBaseTrainerEnd
	jumpifhalfword CMP_EQUAL, gTrainerBattleOpponent_A, TRAINER_SECRET_BASE, BattleScript_EReaderOrSecretBaseTrainerEnd
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, 0, BattleScript_RivalBattleLost
BattleScript_LocalBattleLostPrintWhiteOut::
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_LocalBattleLostEnd
	printstring STRINGID_PLAYERWHITEOUT
	waitmessage 0x40
	getmoneyreward BattleScript_LocalBattleLostPrintTrainersWinText
	printstring STRINGID_PLAYERWHITEOUT2
	waitmessage 0x40
	goto BattleScript_EReaderOrSecretBaseTrainerEnd

BattleScript_LocalBattleLostEnd::
	printstring STRINGID_PLAYERLOSTAGAINSTENEMYTRAINER
	waitmessage 0x40
	getmoneyreward BattleScript_LocalBattleLostPrintTrainersWinText
	printstring STRINGID_PLAYERPAIDPRIZEMONEY
	waitmessage 0x40
BattleScript_EReaderOrSecretBaseTrainerEnd::
	end2

BattleScript_LocalBattleLostPrintTrainersWinText::
	printstring STRINGID_PLAYERWHITEDOUT
	waitmessage 0x40
	end2

BattleScript_RivalBattleLost::
	jumpifhasnohp BS_ATTACKER, BattleScript_RivalBattleLostSkipMonRecall
	printstring STRINGID_TRAINER1MON1COMEBACK
	waitmessage 0x40
	returnatktoball
	waitstate
BattleScript_RivalBattleLostSkipMonRecall::
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_LocalBattleLostPrintWhiteOut
	end2

BattleScript_BattleTowerLost::
	various8 BS_ATTACKER
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0, BattleScript_BattleTowerLostLostSkipMonRecall
	printfromtable gDoubleBattleRecallStrings
	waitmessage 0x40
	returnopponentmon1toball BS_ATTACKER
	waitstate
	returnopponentmon2toball BS_ATTACKER
	waitstate
BattleScript_BattleTowerLostLostSkipMonRecall::
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1WINTEXT
	jumpifnotbattletype BATTLE_TYPE_DOUBLE, BattleScript_BattleTowerLostLostSkipDouble
	printstring STRINGID_TRAINER2NAME
BattleScript_BattleTowerLostLostSkipDouble::
	end2

BattleScript_LinkBattleWonOrLost::
	printstring STRINGID_BATTLEEND
	waitmessage 0x40
	atk57
	waitmessage 0x40
	end2

BattleScript_BattleTowerTrainerBattleWon::
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	trainerslidein BS_ATTACKER
	waitstate
	jumpifnotbattletype BATTLE_TYPE_TRAINER_TOWER, BattleScript_BattleTowerEtcTrainerBattleWonSkipText
	printstring STRINGID_TRAINER1LOSETEXT
	jumpifnotbattletype BATTLE_TYPE_DOUBLE, BattleScript_BattleTowerEtcTrainerBattleWonSkipText
	printstring STRINGID_TRAINER2CLASS
BattleScript_BattleTowerEtcTrainerBattleWonSkipText::
	//pickup
	end2

BattleScript_MasterTrainerBattleWon::
	printstring STRINGID_PLAYERDEFEATEDTRAINER1
	trainerslidein BS_ATTACKER
	waitstate
	printstring STRINGID_TRAINER1LOSETEXT
	waitmessage 0x40
	//pickup
	end2

BattleScript_SmokeBallEscape::
	playanimation BS_ATTACKER, B_ANIM_SMOKEBALL_ESCAPE, NULL
	printstring STRINGID_PKMNFLEDUSINGITS
	waitmessage 0x40
	end2

BattleScript_RanAwayUsingMonAbility::
	printstring STRINGID_PKMNFLEDUSING
	waitmessage 0x40
	end2

BattleScript_GotAwaySafely::
	printstring STRINGID_GOTAWAYSAFELY
	waitmessage 0x40
	end2

BattleScript_WildMonFled::
	printstring STRINGID_WILDPKMNFLED
	waitmessage 0x40
	end2

BattleScript_PrintCantRunFromTrainer::
	jumpifbattletype BATTLE_TYPE_FIRST_BATTLE, BattleScript_LeftoverBirchString
	printstring STRINGID_NORUNNINGFROMTRAINERS
	end2

BattleScript_LeftoverBirchString::
	printstring STRINGID_DONTLEAVEBIRCH
	end2

BattleScript_PrintFailedToRunString::
	printfromtable gNoEscapeStringIds
	waitmessage 0x40
	end2

BattleScript_PrintCantEscapeFromBattle::
	printselectionstringfromtable gNoEscapeStringIds
	endselectionscript

BattleScript_PrintFullBox::
	printselectionstring STRINGID_BOXISFULL
	endselectionscript

BattleScript_ActionSwitch::
	hpthresholds2 BS_ATTACKER
	printstring STRINGID_RETURNMON
	setbyte sDMG_MULTIPLIER, 2
	jumpifbattletype BATTLE_TYPE_DOUBLE, BattleScript_PursuitSwitchCheckTwice
	setmultihit 1
	goto BattleScript_PursuitSwitchLoop

BattleScript_PursuitSwitchCheckTwice::
	setmultihit 2
BattleScript_PursuitSwitchLoop::
	jumpifnopursuitswitchdmg BattleScript_DoSwitchOut
	swapattackerwithtarget
	trysetdestinybondtohappen
	call BattleScript_PursuitDmgOnSwitchOut
	swapattackerwithtarget
BattleScript_DoSwitchOut::
	decrementmultihit BattleScript_PursuitSwitchLoop
	switchoutabilities BS_ATTACKER
	waitstate
	returnatktoball
	waitstate
	drawpartystatussummary BS_ATTACKER
	switchhandleorder BS_ATTACKER, 1
	getswitchedmondata BS_ATTACKER
	switchindataupdate BS_ATTACKER
	hpthresholds BS_ATTACKER
	printstring STRINGID_SWITCHINMON
	hidepartystatussummary BS_ATTACKER
	switchinanim BS_ATTACKER, 0
	waitstate
	switchineffects BS_ATTACKER
	moveendcase 4
	moveendcase 15
	end2

BattleScript_PursuitDmgOnSwitchOut::
	pause 0x20
	attackstring
	ppreduce
	critcalc
	damagecalc
	typecalc
	adjustnormaldamage
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	critmessage
	waitmessage 0x40
	resultmessage
	waitmessage 0x40
	tryfaintmon BS_TARGET, 0, NULL
	moveendfromto 3, 6
	various4 BS_TARGET
	jumpifbyte CMP_EQUAL, gBattleCommunication, 0, BattleScript_PursuitSwitchRivalSkip
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
BattleScript_PursuitSwitchRivalSkip::
	return

BattleScript_Pausex20::
	pause 0x20
	return

BattleScript_LevelUp::
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNGREWTOLV
	setbyte sLVLBOX_STATE, 0
	drawlvlupbox
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, 1
	goto BattleScript_AskToLearnMove

BattleScript_LearnMoveLoop::
	handlelearnnewmove BattleScript_LearnedNewMove, BattleScript_LearnMoveReturn, 0
BattleScript_AskToLearnMove::
	buffermovetolearn
	printstring STRINGID_TRYTOLEARNMOVE1
	printstring STRINGID_TRYTOLEARNMOVE2
	printstring STRINGID_TRYTOLEARNMOVE3
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxlearnmove BattleScript_ForgotAndLearnedNewMove
	printstring STRINGID_STOPLEARNINGMOVE
	waitstate
	setbyte sLEARNMOVE_STATE, 0
	yesnoboxstoplearningmove BattleScript_AskToLearnMove
	printstring STRINGID_DIDNOTLEARNMOVE
	goto BattleScript_LearnMoveLoop

BattleScript_ForgotAndLearnedNewMove::
	printstring STRINGID_123POOF
	printstring STRINGID_PKMNFORGOTMOVE
	printstring STRINGID_ANDELLIPSIS
BattleScript_LearnedNewMove::
	buffermovetolearn
	fanfare MUS_LEVEL_UP
	printstring STRINGID_PKMNLEARNEDMOVE
	waitmessage 0x40
	updatechoicemoveonlvlup BS_ATTACKER
	goto BattleScript_LearnMoveLoop

BattleScript_LearnMoveReturn::
	return

BattleScript_RainContinuesOrEnds::
	printfromtable gRainContinuesStringIds
	waitmessage 0x40
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_RainContinuesOrEndsEnd
	playanimation BS_ATTACKER, B_ANIM_RAIN_CONTINUES, NULL
BattleScript_RainContinuesOrEndsEnd::
	end2

BattleScript_DamagingWeatherContinues::
	printfromtable gSandstormHailContinuesStringIds
	waitmessage 0x40
	playanimation2 BS_ATTACKER, sB_ANIM_ARG1, NULL
	setbyte gBattleCommunication, 0
BattleScript_DamagingWeatherLoop::
	copyarraywithindex gBattlerAttacker, gBattlerByTurnOrder, gBattleCommunication, 1
	weatherdamage
	jumpifword CMP_EQUAL, gBattleMoveDamage, NULL, BattleScript_DamagingWeatherContinuesEnd
	printfromtable gSandstormHailDmgStringIds
	waitmessage 0x40
	orword gHitMarker, HITMARKER_x20 | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000 | HITMARKER_GRUDGE
	effectivenesssound
	hitanimation BS_ATTACKER
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, 0, NULL
	atk24 .+4
BattleScript_DamagingWeatherContinuesEnd::
	jumpifbyte CMP_NOT_EQUAL, gBattleOutcome, 0, BattleScript_WeatherDamageEndedBattle
	addbyte gBattleCommunication, 1
	jumpifbytenotequal gBattleCommunication, gBattlersCount, BattleScript_DamagingWeatherLoop
BattleScript_WeatherDamageEndedBattle::
	bicword gHitMarker, HITMARKER_x20 | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000 | HITMARKER_GRUDGE
	end2

BattleScript_SandStormHailEnds::
	printfromtable gSandstormHailEndStringIds
	waitmessage 0x40
	end2

BattleScript_SunlightContinues::
	printstring STRINGID_SUNLIGHTSTRONG
	waitmessage 0x40
	playanimation BS_ATTACKER, B_ANIM_SUN_CONTINUES, NULL
	end2

BattleScript_SunlightFaded::
	printstring STRINGID_SUNLIGHTFADED
	waitmessage 0x40
	end2

BattleScript_OverworldWeatherStarts::
	printfromtable gWeatherContinuesStringIds
	waitmessage 0x40
	playanimation2 BS_ATTACKER, sB_ANIM_ARG1, NULL
	end3

BattleScript_SideStatusWoreOff::
	printstring STRINGID_PKMNSXWOREOFF
	waitmessage 0x40
	end2

BattleScript_SafeguardProtected::
	pause 0x20
	printstring STRINGID_PKMNUSEDSAFEGUARD
	waitmessage 0x40
	end2

BattleScript_SafeguardEnds::
	pause 0x20
	printstring STRINGID_PKMNSAFEGUARDEXPIRED
	waitmessage 0x40
	end2

BattleScript_LeechSeedTurnDrain::
	playanimation BS_ATTACKER, B_ANIM_LEECH_SEED_DRAIN, sB_ANIM_ARG1
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	copyword gBattleMoveDamage, gHpDealt
	jumpifability BS_ATTACKER, ABILITY_LIQUID_OOZE, BattleScript_LeechSeedLiquidOoze
	manipulatedamage 0
	setbyte cMULTISTRING_CHOOSER, 3
	goto BattleScript_LeechSeedTurnPrintAndUpdateHp

BattleScript_LeechSeedLiquidOoze::
	setbyte cMULTISTRING_CHOOSER, 4
BattleScript_LeechSeedTurnPrintAndUpdateHp::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printfromtable gLeechSeedStringIds
	waitmessage 0x40
	tryfaintmon BS_ATTACKER, 0, NULL
	tryfaintmon BS_TARGET, 0, NULL
	end2

BattleScript_BideStoringEnergy::
	printstring STRINGID_PKMNSTORINGENERGY
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_BideAttack::
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	clearstatusfromeffect BS_ATTACKER
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage 0x40
	accuracycheck BattleScript_MoveMissed, ACC_CURR_MOVE
	typecalc
	bicbyte gMoveResultFlags, MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE
	copyword gBattleMoveDamage, sBIDE_DMG
	adjustsetdamage
	setbyte sB_ANIM_TURN, 1
	attackanimation
	waitanimation
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	resultmessage
	waitmessage 0x40
	tryfaintmon BS_TARGET, 0, NULL
	goto BattleScript_MoveEnd

BattleScript_BideNoEnergyToAttack::
	attackcanceler
	setmoveeffect MOVE_EFFECT_CHARGING
	clearstatusfromeffect BS_ATTACKER
	printstring STRINGID_PKMNUNLEASHEDENERGY
	waitmessage 0x40
	goto BattleScript_ButItFailed

BattleScript_SuccessForceOut::
	attackanimation
	waitanimation
	switchoutabilities BS_TARGET
	returntoball BS_TARGET
	waitstate
	jumpifbattletype BATTLE_TYPE_TRAINER, BattleScript_TrainerBattleForceOut
	setbyte gBattleOutcome, B_OUTCOME_PLAYER_TELEPORTED
	finishaction
BattleScript_TrainerBattleForceOut::
	getswitchedmondata BS_TARGET
	switchindataupdate BS_TARGET
	switchinanim BS_TARGET, 0
	waitstate
	printstring STRINGID_PKMNWASDRAGGEDOUT
	switchineffects BS_TARGET
	goto BattleScript_MoveEnd

BattleScript_MistProtected::
	pause 0x20
	printstring STRINGID_PKMNPROTECTEDBYMIST
	waitmessage 0x40
	return

BattleScript_RageIsBuilding::
	printstring STRINGID_PKMNRAGEBUILDING
	waitmessage 0x40
	return

BattleScript_MoveUsedIsDisabled::
	printstring STRINGID_PKMNMOVEISDISABLED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_SelectingDisabledMove::
	printselectionstring STRINGID_PKMNMOVEISDISABLED
	endselectionscript

BattleScript_DisabledNoMore::
	printstring STRINGID_PKMNMOVEDISABLEDNOMORE
	waitmessage 0x40
	end2

BattleScript_EncoredNoMore::
	printstring STRINGID_PKMNENCOREENDED
	waitmessage 0x40
	end2

BattleScript_DestinyBondTakesLife::
	printstring STRINGID_PKMNTOOKFOE
	waitmessage 0x40
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, 0, NULL
	return

BattleScript_SpikesOnAttacker::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	call BattleScript_PrintHurtBySpikes
	tryfaintmon BS_ATTACKER, 0, NULL
	tryfaintmon BS_ATTACKER, 1, BattleScript_SpikesOnAttackerFainted
	return

BattleScript_SpikesOnAttackerFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_ATTACKER
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_SpikesOnTarget::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	call BattleScript_PrintHurtBySpikes
	tryfaintmon BS_TARGET, 0, NULL
	tryfaintmon BS_TARGET, 1, BattleScript_SpikesOnTargetFainted
	return

BattleScript_SpikesOnTargetFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_TARGET
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_SpikesOnFaintedBattler::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_FAINTED
	datahpupdate BS_FAINTED
	call BattleScript_PrintHurtBySpikes
	tryfaintmon BS_FAINTED, 0, NULL
	tryfaintmon BS_FAINTED, 1, BattleScript_SpikesOnFaintedBattlerFainted
	return

BattleScript_SpikesOnFaintedBattlerFainted::
	setbyte sGIVEEXP_STATE, 0
	getexp BS_FAINTED
	moveendall
	goto BattleScript_HandleFaintedMon

BattleScript_PrintHurtBySpikes::
	printstring STRINGID_PKMNHURTBYSPIKES
	waitmessage 0x40
	return

BattleScript_PerishSongTakesLife::
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage 0x40
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, 0, NULL
	end2

BattleScript_PerishSongCountGoesDown::
	printstring STRINGID_PKMNPERISHCOUNTFELL
	waitmessage 0x40
	end2

BattleScript_AllStatsUp::
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_ATK, 12, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_DEF, 12, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPEED, 12, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_LESS_THAN, STAT_SPATK, 12, BattleScript_AllStatsUpAtk
	jumpifstat BS_ATTACKER, CMP_EQUAL, STAT_SPDEF, 12, BattleScript_AllStatsUpRet
BattleScript_AllStatsUpAtk::
	setbyte sSTAT_ANIM_PLAYED, 0
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF | BIT_SPEED | BIT_SPATK | BIT_SPDEF, 0
	setstatchanger STAT_ATK, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_AllStatsUpDef
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_AllStatsUpDef::
	setstatchanger STAT_DEF, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_AllStatsUpSpeed
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_AllStatsUpSpeed::
	setstatchanger STAT_SPEED, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_AllStatsUpSpAtk
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_AllStatsUpSpAtk::
	setstatchanger STAT_SPATK, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_AllStatsUpSpDef
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_AllStatsUpSpDef::
	setstatchanger STAT_SPDEF, 1, FALSE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, BattleScript_AllStatsUpRet
	printfromtable gStatUpStringIds
	waitmessage 0x40
BattleScript_AllStatsUpRet::
	return

BattleScript_RapidSpinAway::
	rapidspinfree
	return

BattleScript_WrapFree::
	printstring STRINGID_PKMNGOTFREE
	waitmessage 0x40
	copybyte gBattlerTarget, sBATTLER
	return

BattleScript_LeechSeedFree::
	printstring STRINGID_PKMNSHEDLEECHSEED
	waitmessage 0x40
	return

BattleScript_SpikesFree::
	printstring STRINGID_PKMNBLEWAWAYSPIKES
	waitmessage 0x40
	return

BattleScript_MonTookFutureAttack::
	printstring STRINGID_PKMNTOOKATTACK
	waitmessage 0x40
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, 0, BattleScript_CheckDoomDesireMiss
	accuracycheck BattleScript_FutureAttackMiss, MOVE_FUTURE_SIGHT
	goto BattleScript_FutureAttackAnimate

BattleScript_CheckDoomDesireMiss::
	accuracycheck BattleScript_FutureAttackMiss, MOVE_DOOM_DESIRE
BattleScript_FutureAttackAnimate::
	adjustnormaldamage2
	jumpifbyte CMP_NOT_EQUAL, cMULTISTRING_CHOOSER, 0, BattleScript_FutureHitAnimDoomDesire
	playanimation BS_ATTACKER, B_ANIM_FUTURE_SIGHT_HIT, NULL
	goto BattleScript_DoFutureAttackHit

BattleScript_FutureHitAnimDoomDesire::
	playanimation BS_ATTACKER, B_ANIM_DOOM_DESIRE_HIT, NULL
BattleScript_DoFutureAttackHit::
	effectivenesssound
	hitanimation BS_TARGET
	waitstate
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	resultmessage
	waitmessage 0x40
	tryfaintmon BS_TARGET, 0, NULL
	atk24 .+4
	moveendcase 0
	moveendfromto 11, 14
	setbyte gMoveResultFlags, 0
	end2

BattleScript_FutureAttackMiss::
	pause 0x20
	setbyte gMoveResultFlags, 0
	orbyte gMoveResultFlags, MOVE_RESULT_FAILED
	resultmessage
	waitmessage 0x40
	setbyte gMoveResultFlags, 0
	end2

BattleScript_NoMovesLeft::
	printselectionstring STRINGID_PKMNHASNOMOVESLEFT
	endselectionscript

BattleScript_SelectingMoveWithNoPP::
	printselectionstring STRINGID_NOPPLEFT
	endselectionscript

BattleScript_NoPPForMove::
	attackstring
	pause 0x20
	printstring STRINGID_BUTNOPPLEFT
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_SelectingTormentedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVETORMENT
	endselectionscript

	printstring STRINGID_PKMNCANTUSEMOVETORMENT
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_SelectingNotAllowedMoveTaunt::
	printselectionstring STRINGID_PKMNCANTUSEMOVETAUNT
	endselectionscript

BattleScript_MoveUsedIsTaunted::
	printstring STRINGID_PKMNCANTUSEMOVETAUNT
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_WishComesTrue::
	trywish 1, BattleScript_WishButFullHp
	playanimation BS_TARGET, B_ANIM_WISH_HEAL, NULL
	printstring STRINGID_PKMNWISHCAMETRUE
	waitmessage 0x40
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNREGAINEDHEALTH
	waitmessage 0x40
	end2

BattleScript_WishButFullHp::
	printstring STRINGID_PKMNWISHCAMETRUE
	waitmessage 0x40
	pause 0x20
	printstring STRINGID_PKMNHPFULL
	waitmessage 0x40
	end2

BattleScript_IngrainTurnHeal::
	playanimation BS_ATTACKER, B_ANIM_INGRAIN_HEAL, NULL
	printstring STRINGID_PKMNABSORBEDNUTRIENTS
	waitmessage 0x40
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end2

BattleScript_PrintMonIsRooted::
	pause 0x20
	printstring STRINGID_PKMNANCHOREDITSELF
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_AtkDefDown::
	setbyte sSTAT_ANIM_PLAYED, 0
	playstatchangeanimation BS_ATTACKER, BIT_ATK | BIT_DEF, ATK48_STAT_NEGATIVE | ATK48_ONLY_MULTIPLE | ATK48_DONT_CHECK_LOWER
	playstatchangeanimation BS_ATTACKER, BIT_ATK, ATK48_STAT_NEGATIVE | ATK48_DONT_CHECK_LOWER
	setstatchanger STAT_ATK, 1, TRUE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN, BattleScript_AtkDefDownAtkFail
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_AtkDefDownAtkFail
	printfromtable gStatDownStringIds
	waitmessage 0x40
BattleScript_AtkDefDownAtkFail::
	playstatchangeanimation BS_ATTACKER, BIT_DEF, ATK48_STAT_NEGATIVE | ATK48_DONT_CHECK_LOWER
	setstatchanger STAT_DEF, 1, TRUE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN, BattleScript_AtkDefDownDefFail
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_AtkDefDownDefFail
	printfromtable gStatDownStringIds
	waitmessage 0x40
BattleScript_AtkDefDownDefFail::
	return

BattleScript_KnockedOff::
	playanimation BS_TARGET, B_ANIM_ITEM_KNOCKOFF, NULL
	printstring STRINGID_PKMNKNOCKEDOFF
	waitmessage 0x40
	return

BattleScript_MoveUsedIsImprisoned::
	printstring STRINGID_PKMNCANTUSEMOVESEALED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_SelectingImprisonedMove::
	printselectionstring STRINGID_PKMNCANTUSEMOVESEALED
	endselectionscript

BattleScript_GrudgeTakesPp::
	printstring STRINGID_PKMNLOSTPPGRUDGE
	waitmessage 0x40
	return

BattleScript_MagicCoatBounce::
	attackstring
	ppreduce
	pause 0x20
	printstring STRINGID_PKMNMOVEBOUNCED
	waitmessage 0x40
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_x800000
	setmagiccoattarget BS_ATTACKER
	return

BattleScript_SnatchedMove::
	attackstring
	ppreduce
	snatchsetbattlers
	playanimation BS_TARGET, B_ANIM_SNATCH_MOVE, NULL
	printstring STRINGID_PKMNSNATCHEDMOVE
	waitmessage 0x40
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_x800000
	swapattackerwithtarget
	return

BattleScript_EnduredMsg::
	printstring STRINGID_PKMNENDUREDHIT
	waitmessage 0x40
	return

BattleScript_OneHitKOMsg::
	printstring STRINGID_ONEHITKO
	waitmessage 0x40
	return

BattleScript_SAtkDown2::
	setbyte sSTAT_ANIM_PLAYED, 0
	playstatchangeanimation BS_ATTACKER, BIT_SPATK, ATK48_STAT_NEGATIVE | ATK48_STAT_BY_TWO | ATK48_DONT_CHECK_LOWER
	setstatchanger STAT_SPATK, 2, TRUE
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN, BattleScript_SAtkDown2End
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 2, BattleScript_SAtkDown2End
	printfromtable gStatDownStringIds
	waitmessage 0x40
BattleScript_SAtkDown2End::
	return

BattleScript_FocusPunchSetUp::
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	playanimation BS_ATTACKER, B_ANIM_FOCUS_PUNCH_SETUP, NULL
	printstring STRINGID_PKMNTIGHTENINGFOCUS
	waitmessage 0x40
	end2

BattleScript_MoveUsedIsAsleep::
	printstring STRINGID_PKMNFASTASLEEP
	waitmessage 0x40
	statusanimation BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedWokeUp::
	bicword gHitMarker, HITMARKER_x10
	printfromtable gWokeUpStringIds
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	return

BattleScript_MonWokeUpInUproar::
	printstring STRINGID_PKMNWOKEUPINUPROAR
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	end2

BattleScript_PoisonTurnDmg::
	printstring STRINGID_PKMNHURTBYPOISON
	waitmessage 0x40
BattleScript_DoStatusTurnDmg::
	statusanimation BS_ATTACKER
BattleScript_DoTurnDmg::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	tryfaintmon BS_ATTACKER, 0, NULL
	atk24 .+4
	end2

BattleScript_BurnTurnDmg::
	printstring STRINGID_PKMNHURTBYBURN
	waitmessage 0x40
	goto BattleScript_DoStatusTurnDmg

BattleScript_MoveUsedIsFrozen::
	printstring STRINGID_PKMNISFROZEN
	waitmessage 0x40
	statusanimation BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedUnfroze::
	printfromtable gGotDefrostedStringIds
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	return

BattleScript_DefrostedViaFireMove::
	printstring STRINGID_PKMNWASDEFROSTED
	waitmessage 0x40
	updatestatusicon BS_TARGET
	return

BattleScript_MoveUsedIsParalyzed::
	printstring STRINGID_PKMNISPARALYZED
	waitmessage 0x40
	statusanimation BS_ATTACKER
	cancelmultiturnmoves BS_ATTACKER
	goto BattleScript_MoveEnd

BattleScript_MoveUsedFlinched::
	printstring STRINGID_PKMNFLINCHED
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_PrintUproarOverTurns::
	printfromtable gUproarOverTurnStringIds
	waitmessage 0x40
	end2

BattleScript_ThrashConfuses::
	chosenstatusanimation BS_ATTACKER, 1, STATUS2_CONFUSION
	printstring STRINGID_PKMNFATIGUECONFUSION
	waitmessage 0x40
	end2

BattleScript_MoveUsedIsConfused::
	printstring STRINGID_PKMNISCONFUSED
	waitmessage 0x40
	status2animation BS_ATTACKER, STATUS2_CONFUSION
	jumpifbyte CMP_EQUAL, cMULTISTRING_CHOOSER, 0, BattleScript_MoveUsedIsConfusedRet
BattleScript_DoSelfConfusionDmg::
	cancelmultiturnmoves BS_ATTACKER
	adjustnormaldamage2
	printstring STRINGID_ITHURTCONFUSION
	waitmessage 0x40
	effectivenesssound
	hitanimation BS_ATTACKER
	waitstate
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	resultmessage
	waitmessage 0x40
	tryfaintmon BS_ATTACKER, 0, NULL
	goto BattleScript_MoveEnd

BattleScript_MoveUsedIsConfusedRet::
	return

BattleScript_MoveUsedIsConfusedNoMore::
	printstring STRINGID_PKMNHEALEDCONFUSION
	waitmessage 0x40
	return

BattleScript_PrintPayDayMoneyString::
	printstring STRINGID_PKMNPICKEDUPITEM
	waitmessage 0x40
	return

BattleScript_WrapTurnDmg::
	playanimation BS_ATTACKER, B_ANIM_TURN_TRAP, sB_ANIM_ARG1
	printstring STRINGID_PKMNHURTBY
	waitmessage 0x40
	goto BattleScript_DoTurnDmg

BattleScript_WrapEnds::
	printstring STRINGID_PKMNFREEDFROM
	waitmessage 0x40
	end2

BattleScript_MoveUsedIsInLove::
	printstring STRINGID_PKMNINLOVE
	waitmessage 0x40
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	return

BattleScript_MoveUsedIsInLoveCantAttack::
	printstring STRINGID_PKMNIMMOBILIZEDBYLOVE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_NightmareTurnDmg::
	printstring STRINGID_PKMNLOCKEDINNIGHTMARE
	waitmessage 0x40
	status2animation BS_ATTACKER, STATUS2_NIGHTMARE
	goto BattleScript_DoTurnDmg

BattleScript_CurseTurnDmg::
	printstring STRINGID_PKMNAFFLICTEDBYCURSE
	waitmessage 0x40
	status2animation BS_ATTACKER, STATUS2_CURSED
	goto BattleScript_DoTurnDmg

BattleScript_TargetPRLZHeal::
	printstring STRINGID_PKMNHEALEDPARALYSIS
	waitmessage 0x40
	updatestatusicon BS_TARGET
	return

BattleScript_TooScaredToMove::
	printstring STRINGID_MONTOOSCAREDTOMOVE
	waitmessage 0x40
	playanimation BS_ATTACKER, B_ANIM_MON_SCARED, NULL
	goto BattleScript_MoveEnd

BattleScript_GhostGetOutGetOut::
	printstring STRINGID_GHOSTGETOUTGETOUT
	playanimation BS_ATTACKER, B_ANIM_GHOST_GET_OUT, NULL
	goto BattleScript_MoveEnd

BattleScript_SilphScopeUnveiled::
	pause 0x20
	printstring STRINGID_SILPHSCOPEUNVEILED
	waitstate
	playanimation BS_OPPONENT1, B_ANIM_SILPH_SCOPED, NULL
	pause 0x20
	printstring STRINGID_GHOSTWASMAROWAK
	waitmessage 0x40
	end2

BattleScript_MoveEffectSleep::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gFellAsleepStringIds
	waitmessage 0x40
BattleScript_UpdateEffectStatusIconRet::
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	return

BattleScript_YawnMakesAsleep::
	statusanimation BS_EFFECT_BATTLER
	printstring STRINGID_PKMNFELLASLEEP
	waitmessage 0x40
	updatestatusicon BS_EFFECT_BATTLER
	waitstate
	makevisible BS_EFFECT_BATTLER
	end2

BattleScript_MoveEffectPoison::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotPoisonedStringIds
	waitmessage 0x40
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectBurn::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotBurnedStringIds
	waitmessage 0x40
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectFreeze::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotFrozenStringIds
	waitmessage 0x40
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectParalysis::
	statusanimation BS_EFFECT_BATTLER
	printfromtable gGotParalyzedStringIds
	waitmessage 0x40
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectUproar::
	printstring STRINGID_PKMNCAUSEDUPROAR
	waitmessage 0x40
	return

BattleScript_MoveEffectToxic::
	statusanimation BS_EFFECT_BATTLER
	printstring STRINGID_PKMNBADLYPOISONED
	waitmessage 0x40
	goto BattleScript_UpdateEffectStatusIconRet

BattleScript_MoveEffectPayDay::
	printstring STRINGID_COINSSCATTERED
	waitmessage 0x40
	return

BattleScript_MoveEffectWrap::
	printfromtable gWrappedStringIds
	waitmessage 0x40
	return

BattleScript_MoveEffectConfusion::
	chosenstatusanimation BS_EFFECT_BATTLER, 1, STATUS2_CONFUSION
	printstring STRINGID_PKMNWASCONFUSED
	waitmessage 0x40
	return

BattleScript_MoveEffectRecoil::
	jumpifmove MOVE_STRUGGLE, BattleScript_DoRecoil
	jumpifability BS_ATTACKER, ABILITY_ROCK_HEAD, BattleScript_RecoilEnd
BattleScript_DoRecoil::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNHITWITHRECOIL
	waitmessage 0x40
	tryfaintmon BS_ATTACKER, 0, NULL
BattleScript_RecoilEnd::
	return

BattleScript_ItemSteal::
	playanimation BS_TARGET, B_ANIM_ITEM_STEAL, NULL
	printstring STRINGID_PKMNSTOLEITEM
	waitmessage 0x40
	return

BattleScript_DrizzleActivates::
	pause 0x20
	printstring STRINGID_PKMNMADEITRAIN
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_RAIN_CONTINUES, NULL
	call BattleScript_HandleWeatherFormChanges
	end3

BattleScript_SpeedBoostActivates::
	playanimation BS_ATTACKER, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNRAISEDSPEED
	waitmessage 0x40
	end3

BattleScript_TraceActivates::
	pause 0x20
	printstring STRINGID_PKMNTRACED
	waitmessage 0x40
	end3

BattleScript_RainDishActivates::
	printstring STRINGID_PKMNSXRESTOREDHPALITTLE2
	waitmessage 0x40
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	end3

BattleScript_SandstreamActivates::
	pause 0x20
	printstring STRINGID_PKMNSXWHIPPEDUPSANDSTORM
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SANDSTORM_CONTINUES, NULL
	call BattleScript_HandleWeatherFormChanges
	end3

BattleScript_ShedSkinActivates::
	printstring STRINGID_PKMNSXCUREDYPROBLEM
	waitmessage 0x40
	updatestatusicon BS_ATTACKER
	end3

BattleScript_HandleWeatherFormChanges::
	setbyte sBATTLER, 0
BattleScript_WeatherFormChangesLoop::
	trycastformdatachange
	addbyte sBATTLER, 1
	jumpifbytenotequal sBATTLER, gBattlersCount, BattleScript_WeatherFormChangesLoop
	return

BattleScript_CastformChange::
	call BattleScript_DoCastformChangeAnim
	end3

BattleScript_DoCastformChangeAnim::
	docastformchangeanimation
	waitstate
	printstring STRINGID_PKMNTRANSFORMED
	waitmessage 0x40
	return

BattleScript_IntimidateActivatesEnd3::
	call BattleScript_DoIntimidateActivationAnim
	end3

BattleScript_DoIntimidateActivationAnim::
	pause 0x20
BattleScript_IntimidateActivates::
	setbyte gBattlerTarget, 0
	setstatchanger STAT_ATK, 1, TRUE
BattleScript_IntimidateActivationAnimLoop::
	trygetintimidatetarget BattleScript_IntimidateEnd
	jumpifstatus2 BS_TARGET, STATUS2_SUBSTITUTE, BattleScript_IntimidateFail
	jumpifability BS_TARGET, ABILITY_CLEAR_BODY, BattleScript_IntimidateAbilityFail
	jumpifability BS_TARGET, ABILITY_HYPER_CUTTER, BattleScript_IntimidateAbilityFail
	jumpifability BS_TARGET, ABILITY_WHITE_SMOKE, BattleScript_IntimidateAbilityFail
	statbuffchange STAT_CHANGE_BS_PTR | STAT_CHANGE_NOT_PROTECT_AFFECTED, BattleScript_IntimidateFail
	jumpifbyte CMP_GREATER_THAN, cMULTISTRING_CHOOSER, 1, BattleScript_IntimidateFail
	setgraphicalstatchangevalues
	playanimation BS_TARGET, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	printstring STRINGID_PKMNCUTSATTACKWITH
	waitmessage 0x40
BattleScript_IntimidateFail::
	addbyte gBattlerTarget, 1
	goto BattleScript_IntimidateActivationAnimLoop

BattleScript_IntimidateEnd::
	return

BattleScript_IntimidateAbilityFail::
	pause 0x20
	printstring STRINGID_PREVENTEDFROMWORKING
	waitmessage 0x40
	goto BattleScript_IntimidateFail

BattleScript_DroughtActivates::
	pause 0x20
	printstring STRINGID_PKMNSXINTENSIFIEDSUN
	waitstate
	playanimation BS_BATTLER_0, B_ANIM_SUN_CONTINUES, NULL
	call BattleScript_HandleWeatherFormChanges
	end3

BattleScript_TookAttack::
	attackstring
	pause 0x20
	printstring STRINGID_PKMNSXTOOKATTACK
	waitmessage 0x40
	orword gHitMarker, HITMARKER_ATTACKSTRING_PRINTED
	return

BattleScript_SturdyPreventsOHKO::
	pause 0x20
	printstring STRINGID_PKMNPROTECTEDBY
	pause 0x40
	goto BattleScript_MoveEnd

BattleScript_DampStopsExplosion::
	pause 0x20
	printstring STRINGID_PKMNPREVENTSUSAGE
	pause 0x40
	goto BattleScript_MoveEnd

BattleScript_MoveHPDrain_PPLoss::
	ppreduce
BattleScript_MoveHPDrain::
	attackstring
	pause 0x20
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_TARGET
	datahpupdate BS_TARGET
	printstring STRINGID_PKMNRESTOREDHPUSING
	waitmessage 0x40
	orbyte gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_MonMadeMoveUseless_PPLoss::
	ppreduce
BattleScript_MonMadeMoveUseless::
	attackstring
	pause 0x20
	printstring STRINGID_PKMNSXMADEYUSELESS
	waitmessage 0x40
	orbyte gMoveResultFlags, MOVE_RESULT_DOESNT_AFFECT_FOE
	goto BattleScript_MoveEnd

BattleScript_FlashFireBoost_PPLoss::
	ppreduce
BattleScript_FlashFireBoost::
	attackstring
	pause 0x20
	printfromtable gFlashFireStringIds
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_AbilityPreventsPhasingOut::
	pause 0x20
	printstring STRINGID_PKMNANCHORSITSELFWITH
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_AbilityNoStatLoss::
	pause 0x20
	printstring STRINGID_PKMNPREVENTSSTATLOSSWITH
	waitmessage 0x40
	return

BattleScript_BRNPrevention::
	pause 0x20
	printfromtable gBRNPreventionStringIds
	waitmessage 0x40
	return

BattleScript_PRLZPrevention::
	pause 0x20
	printfromtable gPRLZPreventionStringIds
	waitmessage 0x40
	return

BattleScript_PSNPrevention::
	pause 0x20
	printfromtable gPSNPreventionStringIds
	waitmessage 0x40
	return

BattleScript_ObliviousPreventsAttraction::
	pause 0x20
	printstring STRINGID_PKMNPREVENTSROMANCEWITH
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_FlinchPrevention::
	pause 0x20
	printstring STRINGID_PKMNSXPREVENTSFLINCHING
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_OwnTempoPrevents::
	pause 0x20
	printstring STRINGID_PKMNPREVENTSCONFUSIONWITH
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_SoundproofProtected::
	attackstring
	ppreduce
	pause 0x20
	printstring STRINGID_PKMNSXBLOCKSY
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_AbilityNoSpecificStatLoss::
	pause 0x20
	printstring STRINGID_PKMNSXPREVENTSYLOSS
	waitmessage 0x40
	setbyte cMULTISTRING_CHOOSER, 3
	return

BattleScript_StickyHoldActivates::
	pause 0x20
	printstring STRINGID_PKMNSXMADEYINEFFECTIVE
	waitmessage 0x40
	goto BattleScript_MoveEnd

BattleScript_ColorChangeActivates::
	printstring STRINGID_PKMNCHANGEDTYPEWITH
	waitmessage 0x40
	return

BattleScript_RoughSkinActivates::
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_x100000
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_PKMNHURTSWITH
	waitmessage 0x40
	tryfaintmon BS_ATTACKER, 0, NULL
	return

BattleScript_CuteCharmActivates::
	status2animation BS_ATTACKER, STATUS2_INFATUATION
	printstring STRINGID_PKMNSXINFATUATEDY
	waitmessage 0x40
	return

BattleScript_ApplySecondaryEffect::
	waitstate
	seteffectsecondary
	return

BattleScript_SynchronizeActivates::
	waitstate
	seteffectprimary
	return

BattleScript_AbilityCuredStatus::
	printstring STRINGID_PKMNSXCUREDITSYPROBLEM
	waitmessage 0x40
	updatestatusicon BS_SCRIPTING
	return

BattleScript_IgnoresWhileAsleep::
	printstring STRINGID_PKMNIGNORESASLEEP
	waitmessage 0x40
	moveendto 16
	end

BattleScript_IgnoresAndUsesRandomMove::
	printstring STRINGID_PKMNIGNOREDORDERS
	waitmessage 0x40
	jumptocalledmove 0
BattleScript_MoveUsedLoafingAround::
	printfromtable gInobedientStringIds
	waitmessage 0x40
	moveendto 16
	end

BattleScript_IgnoresAndFallsAsleep::
	printstring STRINGID_PKMNBEGANTONAP
	waitmessage 0x40
	setmoveeffect MOVE_EFFECT_SLEEP | MOVE_EFFECT_AFFECTS_USER
	seteffectprimary
	moveendto 16
	end

BattleScript_IgnoresAndHitsItself::
	printstring STRINGID_PKMNWONTOBEY
	waitmessage 0x40
	goto BattleScript_DoSelfConfusionDmg

BattleScript_SubstituteFade::
	playanimation BS_TARGET, B_ANIM_SUBSTITUTE_FADE, NULL
	printstring STRINGID_PKMNSUBSTITUTEFADED
	return

BattleScript_BerryCurePrlzEnd2::
	call BattleScript_BerryCureParRet
	end2

BattleScript_BerryCureParRet::
	playanimation BS_SCRIPTING, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMCUREDPARALYSIS
	waitmessage 0x40
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCurePsnEnd2::
	call BattleScript_BerryCurePsnRet
	end2

BattleScript_BerryCurePsnRet::
	playanimation BS_SCRIPTING, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMCUREDPOISON
	waitmessage 0x40
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureBrnEnd2::
	call BattleScript_BerryCureBrnRet
	end2

BattleScript_BerryCureBrnRet::
	playanimation BS_SCRIPTING, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMHEALEDBURN
	waitmessage 0x40
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureFrzEnd2::
	call BattleScript_BerryCureFrzRet
	end2

BattleScript_BerryCureFrzRet::
	playanimation BS_SCRIPTING, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMDEFROSTEDIT
	waitmessage 0x40
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureSlpEnd2::
	call BattleScript_BerryCureSlpRet
	end2

BattleScript_BerryCureSlpRet::
	playanimation BS_SCRIPTING, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMWOKEIT
	waitmessage 0x40
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureConfusionEnd2::
	call BattleScript_BerryCureConfusionRet
	end2

BattleScript_BerryCureConfusionRet::
	playanimation BS_SCRIPTING, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMSNAPPEDOUT
	waitmessage 0x40
	removeitem BS_SCRIPTING
	return

BattleScript_BerryCureChosenStatusEnd2::
	call BattleScript_BerryCureChosenStatusRet
	end2

BattleScript_BerryCureChosenStatusRet::
	playanimation BS_SCRIPTING, B_ANIM_ITEM_EFFECT, NULL
	printfromtable gBerryEffectStringIds
	waitmessage 0x40
	updatestatusicon BS_SCRIPTING
	removeitem BS_SCRIPTING
	return

BattleScript_WhiteHerbEnd2::
	call BattleScript_WhiteHerbRet
	end2

BattleScript_WhiteHerbRet::
	playanimation BS_SCRIPTING, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDSTATUS
	waitmessage 0x40
	removeitem BS_SCRIPTING
	return

BattleScript_ItemHealHP_RemoveItem::
	playanimation BS_ATTACKER, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage 0x40
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	removeitem BS_ATTACKER
	end2

BattleScript_BerryPPHealEnd2::
	playanimation BS_ATTACKER, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDPP
	waitmessage 0x40
	removeitem BS_ATTACKER
	end2

BattleScript_ItemHealHP_End2::
	call BattleScript_ItemHealHP_Ret
	end2

BattleScript_ItemHealHP_Ret::
	playanimation BS_ATTACKER, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDHPALITTLE
	waitmessage 0x40
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	return

BattleScript_SelectingNotAllowedMoveChoiceItem::
	printselectionstring STRINGID_ITEMALLOWSONLYYMOVE
	endselectionscript

BattleScript_HangedOnMsg::
	playanimation BS_TARGET, B_ANIM_HANGED_ON, NULL
	printstring STRINGID_PKMNHUNGONWITHX
	waitmessage 0x40
	return

BattleScript_BerryConfuseHealEnd2::
	playanimation BS_ATTACKER, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNSITEMRESTOREDHEALTH
	waitmessage 0x40
	orword gHitMarker, HITMARKER_IGNORE_SUBSTITUTE
	healthbarupdate BS_ATTACKER
	datahpupdate BS_ATTACKER
	printstring STRINGID_FORXCOMMAYZ
	waitmessage 0x40
	setmoveeffect MOVE_EFFECT_CONFUSION | MOVE_EFFECT_AFFECTS_USER
	seteffectprimary
	removeitem BS_ATTACKER
	end2

BattleScript_BerryStatRaiseEnd2::
	playanimation BS_ATTACKER, B_ANIM_ITEM_EFFECT, NULL
	statbuffchange STAT_CHANGE_BS_PTR | MOVE_EFFECT_AFFECTS_USER, .+4
	setbyte cMULTISTRING_CHOOSER, 4
	call BattleScript_StatUp
	removeitem BS_ATTACKER
	end2

BattleScript_BerryFocusEnergyEnd2::
	playanimation BS_ATTACKER, B_ANIM_ITEM_EFFECT, NULL
	printstring STRINGID_PKMNUSEDXTOGETPUMPED
	waitmessage 0x40
	removeitem BS_ATTACKER
	end2

BattleScript_ActionSelectionItemsCantBeUsed::
	printselectionstring STRINGID_ITEMSCANTBEUSEDNOW
	endselectionscript

BattleScript_FlushMessageBox::
	printstring STRINGID_EMPTYSTRING3
	return
