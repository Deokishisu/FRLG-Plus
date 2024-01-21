VictoryRoad_2F_EventScript_DoubleEdgeTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_DOUBLE_EDGE, EventScript_DoubleEdgeReteach
	msgbox Text_DoubleEdgeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DoubleEdgeDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_DoubleEdgeDeclined
	msgbox Text_DoubleEdgeWhichMon
	setvar VAR_0x8005, MOVETUTOR_DOUBLE_EDGE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_DoubleEdgeDeclined
	setflag FLAG_TUTOR_DOUBLE_EDGE
	goto EventScript_DoubleEdgeTaught
	end

EventScript_DoubleEdgeDeclined::
	msgbox Text_DoubleEdgeDeclined
	release
	end

EventScript_DoubleEdgeTaught::
	msgbox Text_DoubleEdgeTaught
	release
	end

EventScript_DoubleEdgeReteach::
	lock
	faceplayer
	msgbox Text_DoubleEdgeReteach
	showmoneybox 0, 0
	msgbox Text_DoubleEdgeReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DoubleEdgeDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_DoubleEdgeNotEnoughMoney
	msgbox Text_DoubleEdgeWhichMon
	setvar VAR_0x8005, MOVETUTOR_DOUBLE_EDGE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_DoubleEdgeDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_DoubleEdgeTaught
	hidemoneybox
	release
	end

EventScript_DoubleEdgeNotEnoughMoney::
	msgbox Text_DoubleEdgeNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_DoubleEdgeDeclined2::
	msgbox Text_DoubleEdgeDeclined
	hidemoneybox
	release
	end

EventScript_ThunderWaveTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_THUNDER_WAVE, EventScript_ThunderWaveReteach
	msgbox Text_ThunderWaveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ThunderWaveDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_ThunderWaveDeclined
	msgbox Text_ThunderWaveWhichMon
	setvar VAR_0x8005, MOVETUTOR_THUNDER_WAVE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_ThunderWaveDeclined
	setflag FLAG_TUTOR_THUNDER_WAVE
	goto EventScript_ThunderWaveTaught
	end

EventScript_ThunderWaveDeclined::
	msgbox Text_ThunderWaveDeclined
	release
	end

EventScript_ThunderWaveTaught::
	msgbox Text_ThunderWaveTaught
	release
	end

EventScript_ThunderWaveReteach::
	lock
	faceplayer
	msgbox Text_ThunderWaveReteach
	showmoneybox 0, 0
	msgbox Text_ThunderWaveReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ThunderWaveDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_ThunderWaveNotEnoughMoney
	msgbox Text_ThunderWaveWhichMon
	setvar VAR_0x8005, MOVETUTOR_THUNDER_WAVE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_ThunderWaveDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_ThunderWaveTaught
	hidemoneybox
	release
	end

EventScript_ThunderWaveNotEnoughMoney::
	msgbox Text_ThunderWaveNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_ThunderWaveDeclined2::
	msgbox Text_ThunderWaveDeclined
	hidemoneybox
	release
	end

RockTunnel_B1F_EventScript_RockSlideTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_ROCK_SLIDE, EventScript_RockSlideReteach
	msgbox Text_RockSlideTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RockSlideDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_RockSlideDeclined
	msgbox Text_RockSlideWhichMon
	setvar VAR_0x8005, MOVETUTOR_ROCK_SLIDE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_RockSlideDeclined
	setflag FLAG_TUTOR_ROCK_SLIDE
	goto EventScript_RockSlideTaught
	end

EventScript_RockSlideDeclined::
	msgbox Text_RockSlideDeclined
	release
	end

EventScript_RockSlideTaught::
	msgbox Text_RockSlideTaught
	release
	end

EventScript_RockSlideReteach::
	lock
	faceplayer
	msgbox Text_RockSlideReteach
	showmoneybox 0, 0
	msgbox Text_RockSlideReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RockSlideDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_RockSlideNotEnoughMoney
	msgbox Text_RockSlideWhichMon
	setvar VAR_0x8005, MOVETUTOR_ROCK_SLIDE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_RockSlideDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_RockSlideTaught
	hidemoneybox
	release
	end

EventScript_RockSlideNotEnoughMoney::
	msgbox Text_RockSlideNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_RockSlideDeclined2::
	msgbox Text_RockSlideDeclined
	hidemoneybox
	release
	end

MtEmber_Exterior_EventScript_ExplosionTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_EXPLOSION, EventScript_ExplosionReteach
	msgbox Text_ExplosionTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ExplosionDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_ExplosionDeclined
	msgbox Text_ExplosionWhichMon
	setvar VAR_0x8005, MOVETUTOR_EXPLOSION
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_ExplosionDeclined
	setflag FLAG_TUTOR_EXPLOSION
	goto EventScript_ExplosionTaught
	end

EventScript_ExplosionDeclined::
	msgbox Text_ExplosionDeclined
	release
	end

EventScript_ExplosionTaught::
	msgbox Text_ExplosionTaught
	release
	end

EventScript_ExplosionReteach::
	lock
	faceplayer
	msgbox Text_ExplosionReteach
	showmoneybox 0, 0
	msgbox Text_ExplosionReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ExplosionDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_ExplosionNotEnoughMoney
	msgbox Text_ExplosionWhichMon
	setvar VAR_0x8005, MOVETUTOR_EXPLOSION
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_ExplosionDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_ExplosionTaught
	hidemoneybox
	release
	end

EventScript_ExplosionDeclined2::
	msgbox Text_ExplosionDeclined
	hidemoneybox
	release
	end

EventScript_ExplosionNotEnoughMoney::
	msgbox Text_ExplosionNotEnoughMoney
	hidemoneybox
	release
	end

Route4_EventScript_MegaPunchTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_MEGA_PUNCH, EventScript_MegaPunchReteach
	msgbox Text_MegaPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_MegaPunchDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_MegaPunchDeclined
	msgbox Text_MegaPunchWhichMon
	setvar VAR_0x8005, MOVETUTOR_MEGA_PUNCH
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_MegaPunchDeclined
	setflag FLAG_TUTOR_MEGA_PUNCH
	goto EventScript_MegaPunchTaught
	end

EventScript_MegaPunchDeclined::
	msgbox Text_MegaPunchDeclined
	release
	end

EventScript_MegaPunchTaught::
	msgbox Text_MegaPunchTaught
	release
	end

EventScript_MegaPunchReteach::
	lock
	faceplayer
	msgbox Text_MegaPunchReteach
	showmoneybox 0, 0
	msgbox Text_MegaPunchReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_MegaPunchDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_MegaPunchNotEnoughMoney
	msgbox Text_MegaPunchWhichMon
	setvar VAR_0x8005, MOVETUTOR_MEGA_PUNCH
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_MegaPunchDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_MegaPunchTaught
	hidemoneybox
	release
	end

EventScript_MegaPunchDeclined2::
	msgbox Text_MegaPunchDeclined
	hidemoneybox
	release
	end

EventScript_MegaPunchNotEnoughMoney::
	msgbox Text_MegaPunchNotEnoughMoney
	hidemoneybox
	release
	end

Route4_EventScript_MegaKickTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_MEGA_KICK, EventScript_MegaKickReteach
	msgbox Text_MegaKickTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_MegaKickDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_MegaKickDeclined
	msgbox Text_MegaKickWhichMon
	setvar VAR_0x8005, MOVETUTOR_MEGA_KICK
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_MegaKickDeclined
	setflag FLAG_TUTOR_MEGA_KICK
	goto EventScript_MegaKickTaught
	end

EventScript_MegaKickDeclined::
	msgbox Text_MegaKickDeclined
	release
	end

EventScript_MegaKickTaught::
	msgbox Text_MegaKickTaught
	release
	end

EventScript_MegaKickReteach::
	lock
	faceplayer
	msgbox Text_MegaKickReteach
	showmoneybox 0, 0
	msgbox Text_MegaKickReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_MegaKickDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_MegaKickNotEnoughMoney
	msgbox Text_MegaKickWhichMon
	setvar VAR_0x8005, MOVETUTOR_MEGA_KICK
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_MegaKickDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_MegaKickTaught
	hidemoneybox
	release
	end

EventScript_MegaKickDeclined2::
	msgbox Text_MegaKickDeclined
	hidemoneybox
	release
	end

EventScript_MegaKickNotEnoughMoney::
	msgbox Text_MegaKickNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_DreamEaterTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_DREAM_EATER, EventScript_DreamEaterReteach
	msgbox Text_DreamEaterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DreamEaterDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_DreamEaterDeclined
	msgbox Text_DreamEaterWhichMon
	setvar VAR_0x8005, MOVETUTOR_DREAM_EATER
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_DreamEaterDeclined
	setflag FLAG_TUTOR_DREAM_EATER
	goto EventScript_DreamEaterTaught
	end

EventScript_DreamEaterDeclined::
	msgbox Text_DreamEaterDeclined
	release
	end

EventScript_DreamEaterTaught::
	msgbox Text_DreamEaterTaught
	release
	end

EventScript_DreamEaterReteach::
	lock
	faceplayer
	msgbox Text_DreamEaterReteach
	showmoneybox 0, 0
	msgbox Text_DreamEaterReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DreamEaterDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_DreamEaterNotEnoughMoney
	msgbox Text_DreamEaterWhichMon
	setvar VAR_0x8005, MOVETUTOR_DREAM_EATER
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_DreamEaterDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_DreamEaterTaught
	hidemoneybox
	release
	end

EventScript_DreamEaterDeclined2::
	msgbox Text_DreamEaterDeclined
	hidemoneybox
	release
	end

EventScript_DreamEaterNotEnoughMoney::
	msgbox Text_DreamEaterNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_SoftboiledTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SOFT_BOILED, EventScript_SoftboiledReteach
	msgbox Text_SoftboiledTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SoftboiledDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_SoftboiledDeclined
	msgbox Text_SoftboiledWhichMon
	setvar VAR_0x8005, MOVETUTOR_SOFT_BOILED
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_SoftboiledDeclined
	setflag FLAG_TUTOR_SOFT_BOILED
	goto EventScript_SoftboiledTaught
	end

EventScript_SoftboiledDeclined::
	msgbox Text_SoftboiledDeclined
	release
	end

EventScript_SoftboiledTaught::
	msgbox Text_SoftboiledTaught
	release
	end

EventScript_SoftboiledReteach::
	lock
	faceplayer
	msgbox Text_SoftboiledReteach
	showmoneybox 0, 0
	msgbox Text_SoftboiledReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SoftboiledDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_SoftboiledNotEnoughMoney
	msgbox Text_SoftboiledWhichMon
	setvar VAR_0x8005, MOVETUTOR_SOFT_BOILED
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_SoftboiledDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_SoftboiledTaught
	hidemoneybox
	release
	end

EventScript_SoftboiledDeclined2::
	msgbox Text_SoftboiledDeclined
	hidemoneybox
	release
	end

EventScript_SoftboiledNotEnoughMoney::
	msgbox Text_SoftboiledNotEnoughMoney
	hidemoneybox
	release
	end

FuchsiaCity_EventScript_SubstituteTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SUBSTITUTE, EventScript_SubstituteReteach
	msgbox Text_SubstituteTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SubstituteDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_SubstituteDeclined
	msgbox Text_SubstituteWhichMon
	setvar VAR_0x8005, MOVETUTOR_SUBSTITUTE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_SubstituteDeclined
	setflag FLAG_TUTOR_SUBSTITUTE
	goto EventScript_SubstituteTaught
	end

EventScript_SubstituteDeclined::
	msgbox Text_SubstituteDeclined
	release
	end

EventScript_SubstituteTaught::
	msgbox Text_SubstituteTaught
	release
	end

EventScript_SubstituteReteach::
	lock
	faceplayer
	msgbox Text_SubstituteReteach
	showmoneybox 0, 0
	msgbox Text_SubstituteReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SubstituteDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_SubstituteNotEnoughMoney
	msgbox Text_SubstituteWhichMon
	setvar VAR_0x8005, MOVETUTOR_SUBSTITUTE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_SubstituteDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_SubstituteTaught
	hidemoneybox
	release
	end

EventScript_SubstituteDeclined2::
	msgbox Text_SubstituteDeclined
	hidemoneybox
	release
	end

EventScript_SubstituteNotEnoughMoney::
	msgbox Text_SubstituteNotEnoughMoney
	hidemoneybox
	release
	end

SevenIsland_EventScript_SwordsDanceTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SWORDS_DANCE, EventScript_SwordsDanceReteach
	msgbox Text_SwordsDanceTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SwordsDanceDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_SwordsDanceDeclined
	msgbox Text_SwordsDanceWhichMon
	setvar VAR_0x8005, MOVETUTOR_SWORDS_DANCE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_SwordsDanceDeclined
	setflag FLAG_TUTOR_SWORDS_DANCE
	goto EventScript_SwordsDanceTaught
	end

EventScript_SwordsDanceDeclined::
	msgbox Text_SwordsDanceDeclined
	release
	end

EventScript_SwordsDanceTaught::
	msgbox Text_SwordsDanceTaught
	release
	end

EventScript_SwordsDanceReteach::
	lock
	faceplayer
	msgbox Text_SwordsDanceReteach
	showmoneybox 0, 0
	msgbox Text_SwordsDanceReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SwordsDanceDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_SwordsDanceNotEnoughMoney
	msgbox Text_SwordsDanceWhichMon
	setvar VAR_0x8005, MOVETUTOR_SWORDS_DANCE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_SwordsDanceDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_SwordsDanceTaught
	hidemoneybox
	release
	end

EventScript_SwordsDanceDeclined2::
	msgbox Text_SwordsDanceDeclined
	hidemoneybox
	release
	end

EventScript_SwordsDanceNotEnoughMoney::
	msgbox Text_SwordsDanceNotEnoughMoney
	hidemoneybox
	release
	end

PewterCity_Museum_1F_EventScript_SeismicTossTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_SEISMIC_TOSS, EventScript_SeismicTossReteach
	msgbox Text_SeismicTossTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SeismicTossDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_SeismicTossDeclined
	msgbox Text_SeismicTossWhichMon
	setvar VAR_0x8005, MOVETUTOR_SEISMIC_TOSS
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_SeismicTossDeclined
	setflag FLAG_TUTOR_SEISMIC_TOSS
	goto EventScript_SeismicTossTaught
	end

EventScript_SeismicTossDeclined::
	msgbox Text_SeismicTossDeclined
	release
	end

EventScript_SeismicTossTaught::
	msgbox Text_SeismicTossTaught
	release
	end

EventScript_SeismicTossReteach::
	lock
	faceplayer
	msgbox Text_SeismicTossReteach
	showmoneybox 0, 0
	msgbox Text_SeismicTossReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SeismicTossDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_SeismicTossNotEnoughMoney
	msgbox Text_SeismicTossWhichMon
	setvar VAR_0x8005, MOVETUTOR_SEISMIC_TOSS
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_SeismicTossDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_SeismicTossTaught
	hidemoneybox
	release
	end

EventScript_SeismicTossDeclined2::
	msgbox Text_SeismicTossDeclined
	hidemoneybox
	release
	end

EventScript_SeismicTossNotEnoughMoney::
	msgbox Text_SeismicTossNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_CounterTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_COUNTER, EventScript_CounterReteach
	msgbox Text_CounterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CounterDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_CounterDeclined
	msgbox Text_CounterWhichMon
	setvar VAR_0x8005, MOVETUTOR_COUNTER
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_CounterDeclined
	setflag FLAG_TUTOR_COUNTER
	goto EventScript_CounterTaught
	end

EventScript_CounterDeclined::
	msgbox Text_CounterDeclined
	release
	end

EventScript_CounterTaught::
	msgbox Text_CounterTaught
	release
	end

EventScript_CounterReteach::
	lock
	faceplayer
	msgbox Text_CounterReteach
	showmoneybox 0, 0
	msgbox Text_CounterReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CounterDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_CounterNotEnoughMoney
	msgbox Text_CounterWhichMon
	setvar VAR_0x8005, MOVETUTOR_COUNTER
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_CounterDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_CounterTaught
	hidemoneybox
	release
	end

EventScript_CounterDeclined2::
	msgbox Text_CounterDeclined
	hidemoneybox
	release
	end

EventScript_CounterNotEnoughMoney::
	msgbox Text_CounterNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_MetronomeTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_METRONOME, EventScript_MetronomeReteach
	msgbox Text_MetronomeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_MetronomeDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_MetronomeDeclined
	msgbox Text_MetronomeWhichMon
	setvar VAR_0x8005, MOVETUTOR_METRONOME
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_MetronomeDeclined
	setflag FLAG_TUTOR_METRONOME
	goto EventScript_MetronomeTaught
	end

EventScript_MetronomeDeclined::
	msgbox Text_MetronomeDeclined
	release
	end

EventScript_MetronomeTaught::
	msgbox Text_MetronomeTaught
	release
	end

EventScript_MetronomeReteach::
	lock
	faceplayer
	msgbox Text_MetronomeReteach
	showmoneybox 0, 0
	msgbox Text_MetronomeReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_MetronomeDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_MetronomeNotEnoughMoney
	msgbox Text_MetronomeWhichMon
	setvar VAR_0x8005, MOVETUTOR_METRONOME
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_MetronomeDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_MetronomeTaught
	hidemoneybox
	release
	end

EventScript_MetronomeDeclined2::
	msgbox Text_MetronomeDeclined
	hidemoneybox
	release
	end

EventScript_MetronomeNotEnoughMoney::
	msgbox Text_MetronomeNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_MimicTutor::
	goto_if_set FLAG_TUTOR_MIMIC, EventScript_MimicReteach
	msgbox Text_MimicTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_MimicDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_MimicDeclined
	msgbox Text_MimicWhichMon
	setvar VAR_0x8005, MOVETUTOR_MIMIC
	call EventScript_ChooseMoveTutorMon
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, EventScript_MimicDeclined
	removeitem ITEM_POKE_DOLL, 1
	setflag FLAG_TUTOR_MIMIC
	goto EventScript_MimicTaught
	end

EventScript_MimicDeclined::
	msgbox Text_MimicDeclined
	release
	end

EventScript_MimicTaught::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EventScript_MimicTaughtMale
	call_if_eq VAR_RESULT, FEMALE, EventScript_MimicTaughtFemale
	release
	end

EventScript_MimicTaughtMale::
	msgbox Text_MimicTaughtMale
	return

EventScript_MimicTaughtFemale::
	msgbox Text_MimicTaughtFemale
	return

EventScript_MimicReteach::
	lock
	faceplayer
	msgbox Text_MimicReteach
	showmoneybox 0, 0
	msgbox Text_MimicReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_MimicDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_MimicNotEnoughMoney
	msgbox Text_MimicWhichMon
	setvar VAR_0x8005, MOVETUTOR_MIMIC
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_MimicDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	goto EventScript_MimicTaught2
	end

EventScript_MimicDeclined2::
	msgbox Text_MimicDeclined
	hidemoneybox
	release
	end

EventScript_MimicNotEnoughMoney::
	msgbox Text_MimicNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_MimicTaught2::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EventScript_MimicTaughtMale2
	call_if_eq VAR_RESULT, FEMALE, EventScript_MimicTaughtFemale2
	hidemoneybox
	release
	end

EventScript_MimicTaughtMale2::
	msgbox Text_MimicTaughtMale2
	return

EventScript_MimicTaughtFemale2::
	msgbox Text_MimicTaughtFemale2
	return

FourIsland_House1_EventScript_BodySlamTutor::
	lock
	faceplayer
	goto_if_set FLAG_TUTOR_BODY_SLAM, EventScript_BodySlamReteach
	msgbox Text_BodySlamTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_BodySlamDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, EventScript_BodySlamDeclined
	msgbox Text_BodySlamWhichMon
	setvar VAR_0x8005, MOVETUTOR_BODY_SLAM
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_BodySlamDeclined
	setflag FLAG_TUTOR_BODY_SLAM
	goto EventScript_BodySlamTaught
	end

EventScript_BodySlamDeclined::
	msgbox Text_BodySlamDeclined
	release
	end

EventScript_BodySlamTaught::
	msgbox Text_BodySlamTaught
	release
	end

EventScript_BodySlamReteach::
	lock
	faceplayer
	msgbox Text_BodySlamReteach
	showmoneybox 0, 0
	msgbox Text_BodySlamReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_BodySlamDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_BodySlamNotEnoughMoney
	msgbox Text_BodySlamWhichMon
	setvar VAR_0x8005, MOVETUTOR_BODY_SLAM
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, EventScript_BodySlamDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox Text_BodySlamTaught
	hidemoneybox
	release
	end

EventScript_BodySlamDeclined2::
	msgbox Text_BodySlamDeclined
	hidemoneybox
	release
	end

EventScript_BodySlamNotEnoughMoney::
	msgbox Text_BodySlamNotEnoughMoney
	hidemoneybox
	release
	end
	
.set LOCALID_CAPE_BRINK_TUTOR, 1

TwoIsland_CapeBrink_House_EventScript_StarterTutor::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_set FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK, CapeBrinkTutor_EventScript_TaughtAllMoves
	goto_if_set FLAG_TEMP_2, CapeBrinkTutor_EventScript_MoveJustTaught
	bufferleadmonspeciesname STR_VAR_1
	msgbox Text_UltimateMoveThatMon
	specialvar VAR_RESULT, CapeBrinkGetMoveToTeachLeadPokemon
	goto_if_eq VAR_RESULT, FALSE, CapeBrinkTutor_EventScript_NoLeadStarter
	copyvar VAR_0x8009, VAR_0x8005
	call_if_eq VAR_FACING, DIR_NORTH, CapeBrinkTutor_EventScript_JumpInPlaceDown
	call_if_eq VAR_FACING, DIR_SOUTH, CapeBrinkTutor_EventScript_JumpInPlaceUp
	call_if_eq VAR_FACING, DIR_EAST, CapeBrinkTutor_EventScript_JumpInPlaceLeft
	call_if_eq VAR_FACING, DIR_WEST, CapeBrinkTutor_EventScript_JumpInPlaceRight
	msgbox Text_AllowMeToTeachMonUltimateMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CapeBrinkTutor_EventScript_DeclineMove
	msgbox Text_LetMeConferUltimateMove
	closemessage
	fadescreen FADE_TO_BLACK
	goto CapeBrinkTutor_EventScript_ChooseMon

@ Unused
CapeBrinkTutor_EventScript_FadeTaughtMove::
	fadescreen FADE_FROM_BLACK
	goto CapeBrinkTutor_EventScript_TaughtMove
	end

CapeBrinkTutor_EventScript_MoveJustTaught::
	msgbox Text_MakeBestUseOfMove
	release
	end

CapeBrinkTutor_EventScript_TaughtAllMoves::
	msgbox Text_FeelRejuvenated
	bufferleadmonspeciesname 0
	specialvar VAR_RESULT, CapeBrinkGetMoveToTeachLeadPokemon
	goto_if_eq VAR_RESULT, FALSE, CapeBrinkTutor_EventScript_NoLeadStarter2
	copyvar VAR_0x8009, VAR_0x8005
	call_if_eq VAR_FACING, DIR_NORTH, CapeBrinkTutor_EventScript_JumpInPlaceDown
	call_if_eq VAR_FACING, DIR_SOUTH, CapeBrinkTutor_EventScript_JumpInPlaceUp
	call_if_eq VAR_FACING, DIR_EAST, CapeBrinkTutor_EventScript_JumpInPlaceLeft
	call_if_eq VAR_FACING, DIR_WEST, CapeBrinkTutor_EventScript_JumpInPlaceRight
	msgbox Text_RightPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CapeBrinkTutor_EventScript_DeclineMove
	msgbox Text_LetMeConferUltimateMove
	closemessage
	fadescreen FADE_TO_BLACK
	goto CapeBrinkTutor_EventScript_ChooseMon
	release
	end

CapeBrinkTutor_EventScript_NoLeadStarter2::
	msgbox Text_NotTheRightPokemon
	release
	end

CapeBrinkTutor_EventScript_TaughtMove::
	copyvar VAR_0x8005, VAR_0x8009
	specialvar VAR_RESULT, HasLearnedAllMovesFromCapeBrinkTutor
	goto_if_eq VAR_RESULT, TRUE, CapeBrinkTutor_EventScript_LearnedAllMoves
	msgbox Text_TaughtMove
	setflag FLAG_TEMP_2
	release
	end

CapeBrinkTutor_EventScript_LearnedAllMoves::
	msgbox Text_PassedOnEverythingIKnow
	setflag FLAG_LEARNED_ALL_MOVES_AT_CAPE_BRINK
	release
	end

CapeBrinkTutor_EventScript_ChooseMon::
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, CapeBrinkTutor_EventScript_DeclineMove
	goto CapeBrinkTutor_EventScript_TaughtMove
	end

CapeBrinkTutor_EventScript_JumpInPlaceDown::
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceDown
	waitmovement 0
	return

CapeBrinkTutor_EventScript_JumpInPlaceUp::
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceUp
	waitmovement 0
	return

CapeBrinkTutor_EventScript_JumpInPlaceLeft::
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceLeft
	waitmovement 0
	return

CapeBrinkTutor_EventScript_JumpInPlaceRight::
	applymovement LOCALID_CAPE_BRINK_TUTOR, Movement_JumpInPlaceRight
	waitmovement 0
	return

CapeBrinkTutor_EventScript_DeclineMove::
	msgbox Text_YouRejectIt
	release
	end

CapeBrinkTutor_EventScript_NoLeadStarter::
	msgbox Text_JustMistaken
	release
	end

EventScript_ChooseMoveTutorMon::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

EventScript_CanOnlyBeLearnedOnce::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special DisableMsgBoxWalkaway
	signmsg
	msgbox Text_MoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	normalmsg
	call EventScript_RestorePrevTextColor
	return

Movement_JumpInPlaceDown:
	jump_in_place_down
	step_end

Movement_JumpInPlaceUp:
	jump_in_place_up
	step_end

Movement_JumpInPlaceLeft:
	jump_in_place_left
	step_end

Movement_JumpInPlaceRight:
	jump_in_place_right
	step_end

VermilionCity_House2_EventScript_FuryCutterTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER, EventScript_FuryCutterReteach
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVETUTOR_FURY_CUTTER
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, MoveTutor_EventScript_FuryCutterDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER
	goto MoveTutor_EventScript_FuryCutterTaught
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught::
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

EventScript_FuryCutterReteach::
	lock
	faceplayer
	msgbox Text_FuryCutterReteach
	showmoneybox 0, 0
	msgbox Text_FuryCutterReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_FuryCutterDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_FuryCutterNotEnoughMoney
	msgbox MoveTutor_Text_FuryCutterWhichMon
	setvar VAR_0x8005, MOVETUTOR_FURY_CUTTER
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, MoveTutor_EventScript_FuryCutterDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox MoveTutor_Text_FuryCutterTaught
	hidemoneybox
	release
	end

EventScript_FuryCutterNotEnoughMoney::
	msgbox Text_FuryCutterNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_FuryCutterDeclined2::
	msgbox MoveTutor_Text_FuryCutterDeclined
	hidemoneybox
	release
	end

MoveTutor_Text_FuryCutterTeach:
	.string "There's a move that gets stronger\n"
	.string "when you keep using it in a row.\p"
	.string "It's a BUG-type move, and it is\n"
	.string "wickedly cool.\p"
	.string "It's called FURY CUTTER.\n"
	.string "Want me to teach it to a POKéMON?$"

MoveTutor_Text_FuryCutterDeclined:
	.string "We're not on the same wavelength.$"

MoveTutor_Text_FuryCutterWhichMon:
	.string "Yay!\n"
	.string "Show me the POKéMON I should teach.$"

MoveTutor_Text_FuryCutterTaught:
	.string "I get a thrill watching to see if\n"
	.string "the move keeps hitting in succession!$"

Text_FuryCutterReteach::
	.string "You want your POKéMON to learn\n"
	.string "FURY CUTTER over and over so they\l"
	.string "can keep using it over and over?\p"
	.string "I can teach you FURY CUTTER\n"
	.string "again if you give me ¥5000.$"

Text_FuryCutterReteach2::
    .string "Want me to teach FURY CUTTER\n"
    .string "to a POKéMON?$"

Text_FuryCutterNotEnoughMoney::
	.string "I can't teach FURY CUTTER over\n"
	.string "and over if you can't pay!\p"
	.string "Come back with ¥5000 next\n"
	.string "time and I'll teach it again.$"

Route24_EventScript_RolloutTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT, EventScript_RolloutReteach
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVETUTOR_ROLLOUT
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_RolloutDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT
	goto MoveTutor_EventScript_RolloutTaught
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught::
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

EventScript_RolloutReteach::
	lock
	faceplayer
	msgbox Text_RolloutReteach
	showmoneybox 0, 0
	msgbox Text_RolloutReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RolloutDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_RolloutNotEnoughMoney
	msgbox MoveTutor_Text_RolloutWhichMon
	setvar VAR_0x8005, MOVETUTOR_ROLLOUT
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, MoveTutor_EventScript_RolloutDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox MoveTutor_Text_RolloutTaught
	hidemoneybox
	release
	end

EventScript_RolloutNotEnoughMoney::
	msgbox Text_RolloutNotEnoughMoney
	hidemoneybox
	release
	end

EventScript_RolloutDeclined2::
	msgbox MoveTutor_Text_RolloutDeclined
	hidemoneybox
	release
	end

MoveTutor_Text_RolloutTeach:
	.string "Did you know that you can go from\n"
	.string "here a long way in that direction\l"
	.string "without changing direction?\p"
	.string "I might even be able to roll\n"
	.string "that way.\p"
	.string "Do you think your POKéMON will\n"
	.string "want to roll, too?\p"
	.string "I can teach one the move ROLLOUT\n"
	.string "if you'd like.$"

MoveTutor_Text_RolloutDeclined:
	.string "You don't need to be shy about it.\n"
	.string "Let's roll!$"

MoveTutor_Text_RolloutWhichMon:
	.string "Ehehe, sure thing! It'd be great if\n"
	.string "the POKéMON looked like me.$"

MoveTutor_Text_RolloutTaught:
	.string "Rolling around in the grass makes me\n"
	.string "happy. Come on, let's roll!$"

Text_RolloutReteach::
	.string "I wonder if I could roll down\n"
	.string "NUGGET BRIDGE to CERULEAN…\p"
	.string "Oh, do you want me to teach\n"
	.string "ROLLOUT to your POKéMON again?\p"
	.string "I can do it, but I have to charge\n"
	.string "¥5000 for my services!$"

Text_RolloutReteach2::
    .string "Want me to teach ROLLOUT\n"
    .string "to one of your POKéMON?$"

Text_RolloutNotEnoughMoney::
	.string "Whoa!\n"
	.string "Hold on a minute!\p"
	.string "How can I teach you ROLLOUT if\n"
	.string "you don't have a bankroll to pay\l"
	.string "me with?\p"
	.string "Come back to me with ¥5000 and\n"
	.string "we'll get your POKéMON rolling!$"

SaffronCity_EventScript_DynamicPunchTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH, EventScript_DynamicPunchReteach
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVETUTOR_DYNAMIC_PUNCH
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DynamicPunchDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
	goto MoveTutor_EventScript_DynamicPunchTaught
	turnobject 19, DIR_NORTH
	end

MoveTutor_EventScript_DynamicPunchDeclined::
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	turnobject 19, DIR_NORTH
	end

MoveTutor_EventScript_DynamicPunchTaught::
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	turnobject 19, DIR_NORTH
	end

EventScript_DynamicPunchReteach::
	lock
	faceplayer
	msgbox Text_DynamicPunchReteach
	showmoneybox 0, 0
	msgbox Text_DynamicPunchReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DynamicPunchDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_DynamicPunchNotEnoughMoney
	msgbox MoveTutor_Text_DynamicPunchWhichMon
	setvar VAR_0x8005, MOVETUTOR_DYNAMIC_PUNCH
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, MoveTutor_EventScript_DynamicPunchDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox MoveTutor_Text_DynamicPunchTaught
	hidemoneybox
	release
	turnobject 19, DIR_NORTH
	end

EventScript_DynamicPunchNotEnoughMoney::
	msgbox Text_DynamicPunchNotEnoughMoney
	hidemoneybox
	release
	turnobject 19, DIR_NORTH
	end

EventScript_DynamicPunchDeclined2::
	msgbox MoveTutor_Text_DynamicPunchDeclined
	hidemoneybox
	release
	turnobject 19, DIR_NORTH
	end

MoveTutor_Text_DynamicPunchTeach:
	.string "I can't do this anymore!\p"
	.string "It's utterly hopeless!\p"
	.string "I'm a FIGHTING-type TRAINER,\n"
	.string "so I can't win at the SAFFRON GYM\l"
	.string "no matter how hard I try!\p"
	.string "Argh! Punch! Punch! Punch!\n"
	.string "Punch! Punch! Punch!\p"
	.string "What, don't look at me that way!\n"
	.string "I'm only hitting the wall!\p"
	.string "Or do you want me to teach your\n"
	.string "POKéMON DYNAMICPUNCH?$"

MoveTutor_Text_DynamicPunchDeclined:
	.string "Darn! You're even making fun of me?\n"
	.string "Punch! Punch! Punch!$"

MoveTutor_Text_DynamicPunchWhichMon:
	.string "What? You do? You're a good person!\n"
	.string "Which POKéMON should I teach?$"

MoveTutor_Text_DynamicPunchTaught:
	.string "I want you to win at the SAFFRON\n"
	.string "GYM using that DYNAMICPUNCH!$"

Text_DynamicPunchReteach::
	.string "Argh! Punch! Punch! Punch!\n"
	.string "Punch! Punch! Punch!\p"
	.string "I'm still so frustrated about\n"
	.string "losing in the GYM!\p"
	.string "Do you want me to teach your\n"
	.string "POKéMON DYNAMICPUNCH again?\p"
	.string "I'll do it for ¥5000!\n"
	.string "I need to buy REVIVES!$"

Text_DynamicPunchReteach2::
    .string "Do you want me to teach your\n"
	.string "POKéMON DYNAMICPUNCH?$"

Text_DynamicPunchNotEnoughMoney::
	.string "Are you mocking me for needing\n"
	.string "money for POKéMON medicine?\p"
	.string "Using items in battle is the only\n"
	.string "possible way I can win here!\p"
	.string "Let me know when you have ¥5000.\n"
	.string "Until then…\p"
	.string "Argh! Punch! Punch! Punch!\n"
	.string "Punch! Punch! Punch!$"

SilphCo_9F_EventScript_SleepTalkTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK, EventScript_SleepTalkReteach
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVETUTOR_SLEEP_TALK
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SleepTalkDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK
	goto MoveTutor_EventScript_SleepTalkTaught
	turnobject 16, DIR_EAST
	end

MoveTutor_EventScript_SleepTalkDeclined::
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	turnobject 16, DIR_EAST
	end

MoveTutor_EventScript_SleepTalkTaught::
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
	release
	turnobject 16, DIR_EAST
	end

EventScript_SleepTalkReteach::
	lock
	faceplayer
	msgbox Text_SleepTalkReteach
	showmoneybox 0, 0
	msgbox Text_SleepTalkReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SleepTalkDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_SleepTalkNotEnoughMoney
	msgbox MoveTutor_Text_SleepTalkWhichMon
	setvar VAR_0x8005, MOVETUTOR_SLEEP_TALK
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, MoveTutor_EventScript_SleepTalkDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox MoveTutor_Text_SleepTalkTaught
	hidemoneybox
	release
	turnobject 16, DIR_EAST
	end

EventScript_SleepTalkNotEnoughMoney::
	msgbox Text_SleepTalkNotEnoughMoney
	hidemoneybox
	release
	turnobject 16, DIR_EAST
	end

EventScript_SleepTalkDeclined2::
	msgbox MoveTutor_Text_SleepTalkDeclined
	hidemoneybox
	release
	turnobject 16, DIR_EAST
	end

MoveTutor_Text_SleepTalkTeach:
	.string "…ZZZ…\n"
	.string "…Zzz…zzz…\p"
	.string "Mrr… mhm…\n"
	.string "use… mmm…\p"
	.string "Oh!\n"
	.string "Was I talking in my sleep?\p"
	.string "I was dreaming that I wanted\n"
	.string "my POKéMON to use a move,\l"
	.string "but it was asleep!\p"
	.string "I can teach your POKéMON how\n"
	.string "to SLEEP TALK so they can attack\l"
	.string "while sleeping if you want.\p"
	.string "Are you interested in teaching\n"
	.string "your POKéMON SLEEP TALK?$"

MoveTutor_Text_SleepTalkDeclined:
	.string "Oh, fine, fine.\p"
	.string "Then back to my nap, I still have\n"
	.string "some time left on my break!$"

MoveTutor_Text_SleepTalkWhichMon:
	.string "Okay!\n"
	.string "Which POKéMON should I teach?$"

MoveTutor_Text_SleepTalkTaught:
	.string "Now that POKéMON can attack\n"
	.string "while sleeping with SLEEP TALK!\p"
	.string "I wonder if humans can SLEEP TALK\n"
	.string "to nap while working?\p"
	.string "Yawn…\n"
	.string "…Zzz…zzz…$"

Text_SleepTalkReteach::
	.string "…ZZZ…\n"
	.string "…Huh?\l"
	.string "…Oh, you're back.\p"
	.string "Yawn… Do you want me to teach\n"
	.string "your POKéMON SLEEP TALK again?\p"
	.string "I lost my bonus by always\n"
	.string "oversleeping on my breaks…\p"
	.string "I'll do it for some extra money.\n"
	.string "How does ¥5000 sound?$"

Text_SleepTalkReteach2::
    .string "Are you interested in teaching\n"
	.string "your POKéMON SLEEP TALK?$"

Text_SleepTalkNotEnoughMoney::
	.string "Oh, you don't have enough money.\n"
	.string "Why don't you think up some way\l"
	.string "to make some and come back later?\p"
	.string "Now, if you'll excuse me…\n"
	.string "…Zzz…zzz…$"

SilphCo_9F_EventScript_NightmareTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_NIGHTMARE, EventScript_NightmareReteach
	msgbox MoveTutor_Text_NightmareTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_NightmareDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_NightmareDeclined
	msgbox MoveTutor_Text_NightmareWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVETUTOR_NIGHTMARE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_NightmareDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_NIGHTMARE
	goto MoveTutor_EventScript_NightmareTaught
	turnobject 17, DIR_SOUTH
	end

MoveTutor_EventScript_NightmareDeclined::
	msgbox MoveTutor_Text_NightmareDeclined, MSGBOX_DEFAULT
	release
	turnobject 17, DIR_SOUTH
	end

MoveTutor_EventScript_NightmareTaught::
	msgbox MoveTutor_Text_NightmareTaught, MSGBOX_DEFAULT
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_NightmareReteach::
	lock
	faceplayer
	msgbox Text_NightmareReteach
	showmoneybox 0, 0
	msgbox Text_NightmareReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_NightmareDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_NightmareNotEnoughMoney
	msgbox MoveTutor_Text_NightmareWhichMon
	setvar VAR_0x8005, MOVETUTOR_NIGHTMARE
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, MoveTutor_EventScript_NightmareDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox MoveTutor_Text_NightmareTaught
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_NightmareNotEnoughMoney::
	msgbox Text_NightmareNotEnoughMoney
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_NightmareDeclined2::
	msgbox MoveTutor_Text_NightmareDeclined
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

MoveTutor_Text_NightmareTeach:
	.string "Waaah!\n"
	.string "Oh no, not another one…\p"
	.string "I keep having nightmares that\n"
	.string "TEAM ROCKET comes back and locks\l"
	.string "me up again.\p"
	.string "I haven't had a good night's sleep\n"
	.string "since they took over.\p"
	.string "I can teach your POKéMON to give\n"
	.string "nightmares just like TEAM ROCKET.$"
	.string "Do you want your POKéMON\n"
	.string "to learn NIGHTMARE?$"

MoveTutor_Text_NightmareDeclined:
	.string "You don't want to risk it\n"
	.string "giving you nightmares too?$"

MoveTutor_Text_NightmareWhichMon:
	.string "Alright.\n"
	.string "Which POKéMON should learn it?$"

MoveTutor_Text_NightmareTaught:
	.string "Now that POKéMON can inflict\n"
	.string "nightmares on sleeping foes.\p"
	.string "Now if only I could find some\n"
	.string "way of getting rid of my nightmares…$"

Text_NightmareReteach::
	.string "Ahh!\n"
	.string "Ugh, again?\p"
	.string "I thought that napping at work\n"
	.string "where it all happened might cure\l"
	.string "my nightmares, but…\p"
	.string "Are you back to teach your\n"
	.string "POKéMON NIGHTMARE again?\p"
	.string "If you have ¥5000, I'll show\n"
	.string "one of them how to use it.$"

Text_NightmareReteach2::
    .string "Do you want your POKéMON\n"
	.string "to learn NIGHTMARE?$"

Text_NightmareNotEnoughMoney::
	.string "You don't have ¥5000?\p"
	.string "I don't want to keep reliving\n"
	.string "these nightmares for nothing.\p"
	.string "Come back when you can pay me\n"
	.string "the full amount, okay?$"

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SelfdestructTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SELFDESTRUCT, EventScript_SelfdestructReteach
	msgbox MoveTutor_Text_SelfdestructTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SelfdestructDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SelfdestructDeclined
	msgbox MoveTutor_Text_SelfdestructWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVETUTOR_SELF_DESTRUCT
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SelfdestructDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SELFDESTRUCT
	goto MoveTutor_EventScript_SelfdestructTaught
	turnobject 17, DIR_SOUTH
	end

MoveTutor_EventScript_SelfdestructDeclined::
	msgbox MoveTutor_Text_SelfdestructDeclined, MSGBOX_DEFAULT
	release
	turnobject 17, DIR_SOUTH
	end

MoveTutor_EventScript_SelfdestructTaught::
	msgbox MoveTutor_Text_SelfdestructTaught, MSGBOX_DEFAULT
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_SelfdestructReteach::
	lock
	faceplayer
	msgbox Text_SelfdestructReteach
	showmoneybox 0, 0
	msgbox Text_SelfdestructReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SelfdestructDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_SelfdestructNotEnoughMoney
	msgbox MoveTutor_Text_SelfdestructWhichMon
	setvar VAR_0x8005, MOVETUTOR_SELF_DESTRUCT
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, MoveTutor_EventScript_SelfdestructDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox MoveTutor_Text_SelfdestructTaught
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_SelfdestructNotEnoughMoney::
	msgbox Text_SelfdestructNotEnoughMoney
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_SelfdestructDeclined2::
	msgbox MoveTutor_Text_SelfdestructDeclined
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

MoveTutor_Text_SelfdestructTeach:
	.string "There's no doubt about it.\n"
	.string "I've run the tests a hundred times.\p"
	.string "The volcano that sleeps beneath us\n"
	.string "isn't asleep at all!\p"
	.string "It'll erupt and destroy this entire\n"
	.string "town within three years for sure!\p"
	.string "It'll be like the whole island\n"
	.string "self-destructed in a fiery inferno!\p"
	.string "POKéMON can use a similar move to\n"
	.string "explode and deal damage, actually.\p"
	.string "Do you want me to teach your\n"
	.string "POKéMON how to use SELFDESTRUCT?$"

MoveTutor_Text_SelfdestructDeclined:
	.string "Is SELFDESTRUCT too risky for\n"
	.string "you to use in battle?$"

MoveTutor_Text_SelfdestructWhichMon:
	.string "So which POKéMON should learn\n"
	.string "this high-risk move?$"

MoveTutor_Text_SelfdestructTaught:
	.string "Now the terrifying power of\n"
	.string "SELFDESTRUCT is yours to command!\p"
	.string "We won't be able to control the\n"
	.string "volcano in the same way, though…\p"
	.string "The only thing to do now is start\n"
	.string "making evacuation plans.\p"
	.string "Let's hope you're standing on some\n"
	.string "other rock in three years' time!$"

Text_SelfdestructReteach::
	.string "When the volcano goes, we'll\n"
	.string "have to save our equipment…\l"
	.string "Oh, hello again!\p"
	.string "I'm just planning for the imminent\n"
	.string "destruction of everything here.\p"
	.string "Do you want to learn SELFDESTRUCT\n"
	.string "again before the inevitable occurs?\p"
	.string "I'm taking donations for the\n"
	.string "evacuation plans.\p"
	.string "Donate ¥5000 and I'll teach one of\n"
	.string "your POKéMON SELFDESTRUCT.$"

Text_SelfdestructReteach2::
    .string "Do you want me to teach your\n"
	.string "POKéMON how to use SELFDESTRUCT?$"

Text_SelfdestructNotEnoughMoney::
	.string "We need every bit of financial\n"
	.string "support we can get to prepare\l"
	.string "for the eruption.\p"
	.string "I can't offer you my services\n"
	.string "for less than a ¥5000 donation.$"

MtEmber_Exterior_EventScript_SkyAttackTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SKY_ATTACK, EventScript_SkyAttackReteach
	msgbox MoveTutor_Text_SkyAttackTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SkyAttackDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SkyAttackDeclined
	msgbox MoveTutor_Text_SkyAttackWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVETUTOR_SKY_ATTACK
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SkyAttackDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SKY_ATTACK
	goto MoveTutor_EventScript_SkyAttackTaught
	turnobject 17, DIR_SOUTH
	end

MoveTutor_EventScript_SkyAttackDeclined::
	msgbox MoveTutor_Text_SkyAttackDeclined, MSGBOX_DEFAULT
	release
	turnobject 17, DIR_SOUTH
	end

MoveTutor_EventScript_SkyAttackTaught::
	msgbox MoveTutor_Text_SkyAttackTaught, MSGBOX_DEFAULT
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_SkyAttackReteach::
	lock
	faceplayer
	msgbox Text_SkyAttackReteach
	showmoneybox 0, 0
	msgbox Text_SkyAttackReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SkyAttackDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_SkyAttackNotEnoughMoney
	msgbox MoveTutor_Text_SkyAttackWhichMon
	setvar VAR_0x8005, MOVETUTOR_SKY_ATTACK
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, MoveTutor_EventScript_SkyAttackDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox MoveTutor_Text_SkyAttackTaught
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_SkyAttackNotEnoughMoney::
	msgbox Text_SkyAttackNotEnoughMoney
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_SkyAttackDeclined2::
	msgbox MoveTutor_Text_SkyAttackDeclined
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

MoveTutor_Text_SkyAttackTeach:
	.string "We're so high up, it's like we can\n"
	.string "touch the sky.\p"
	.string "Bird POKéMON must feel like\n"
	.string "this all the time…\p"
	.string "How, you ask?\n"
	.string "Do you not know?\p"
	.string "They can learn a move that brings\n"
	.string "the sky crashing down on others!\p"
	.string "Would you like me to teach your\n"
	.string "POKéMON SKY ATTACK?$"

MoveTutor_Text_SkyAttackDeclined:
	.string "I suppose not everyone wants\n"
	.string "to touch the sky.$"

MoveTutor_Text_SkyAttackWhichMon:
	.string "Who should learn SKY ATTACK?$"

MoveTutor_Text_SkyAttackTaught:
	.string "SKY ATTACK is the ultimate\n"
	.string "FLYING-type move.\p"
	.string "Your POKéMON will make good\n"
	.string "use of its power, I'm sure.$"

Text_SkyAttackReteach::
	.string "Did you climb all the way back up\n"
	.string "here again for the thrill?\p"
	.string "Being this close to the sky\n"
	.string "feels amazing, right?\p"
	.string "If you're interested, I can\n"
	.string "teach your POKéMON SKY ATTACK.\p"
	.string "This time, though, I'll need ¥5000\n"
	.string "to do it!$"

Text_SkyAttackReteach2::
	.string "Would you like me to teach your\n"
	.string "POKéMON SKY ATTACK?$"

Text_SkyAttackNotEnoughMoney::
	.string "You don't have enough money,\n"
	.string "what a shame.\p"
	.string "You'll have to climb back up here\n"
	.string "again once you have ¥5000!$"

Route10_EventScript_SwaggerTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SWAGGER, EventScript_SwaggerReteach
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	call EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVETUTOR_SWAGGER
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SwaggerDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SWAGGER
	goto MoveTutor_EventScript_SwaggerTaught
	turnobject 17, DIR_SOUTH
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	turnobject 17, DIR_SOUTH
	end

MoveTutor_EventScript_SwaggerTaught::
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_SwaggerReteach::
	lock
	faceplayer
	msgbox Text_SwaggerReteach
	showmoneybox 0, 0
	msgbox Text_SwaggerReteach2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SwaggerDeclined2
	checkmoney 5000, 0
	goto_if_eq VAR_RESULT, FALSE, EventScript_SwaggerNotEnoughMoney
	msgbox MoveTutor_Text_SwaggerWhichMon
	setvar VAR_0x8005, MOVETUTOR_SWAGGER
	call EventScript_ChooseMoveTutorMon
	goto_if_eq VAR_RESULT, FALSE, MoveTutor_EventScript_SwaggerDeclined
	showmoneybox 0, 0
	removemoney 5000
	updatemoneybox
	msgbox MoveTutor_Text_SwaggerTaught
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_SwaggerNotEnoughMoney::
	msgbox Text_SwaggerNotEnoughMoney
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

EventScript_SwaggerDeclined2::
	msgbox MoveTutor_Text_SwaggerDeclined
	hidemoneybox
	release
	turnobject 17, DIR_SOUTH
	end

MoveTutor_Text_SwaggerTeach:
	.string "Heh! My POKéMON totally rules!\n"
	.string "It's cooler than any POKéMON!\p"
	.string "I was lipping off with a swagger in\n"
	.string "my step like that when some guy\l"
	.string "named {RIVAL} challenged me.\p"
	.string "He beat us without any effort and\n"
	.string "took the swagger out of my step.\p"
	.string "If you'd like, I'll teach the move\n"
	.string "SWAGGER to a POKéMON of yours.$"

MoveTutor_Text_SwaggerDeclined:
	.string "What, no? Can't you get into\n"
	.string "the spirit of things?$"

MoveTutor_Text_SwaggerWhichMon:
	.string "All right, which POKéMON wants to\n"
	.string "learn how to SWAGGER?$"

MoveTutor_Text_SwaggerTaught:
	.string "I'll just praise my POKéMON from\n"
	.string "now on without the swagger.$"

Text_SwaggerReteach::
	.string "I've been humbled by losing\n"
	.string "so badly to that {RIVAL} guy.\p"
	.string "But I still know how to walk\n"
	.string "with a swagger in my step!\p"
	.string "I can teach your POKéMON how\n"
	.string "to use SWAGGER again.\p"
	.string "However, the price of learning how\n"
	.string "to swagger like me is a cool ¥5000.$"

Text_SwaggerReteach2::
	.string "Do you want me to teach the move\n"
	.string "SWAGGER to a POKéMON of yours?$"

Text_SwaggerNotEnoughMoney::
	.string "No money, no SWAGGER!\n"
	.string "Come back with ¥5000 next time!$"
