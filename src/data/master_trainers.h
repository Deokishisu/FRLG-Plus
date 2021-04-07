const struct Trainer gMasterTrainers[] = {
    [TRAINER_NONE] = {
        .partyFlags = 0,
        .trainerClass = CLASS_PKMN_TRAINER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = 0,
        .party = NULL
    },
    [MASTER_BULBASAUR] = {
        .partyFlags = F_TRAINER_PARTY_EVS,
        .trainerClass = CLASS_LASS_2,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_MASTER_LASS,
        .trainerName = _("RENA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = NELEMS(sTrainerMons_MasterBulbasaur),
        .party = {.ItemCustomMovesEVs = sTrainerMons_MasterBulbasaur}
    },
    [MASTER_IVYSAUR] = {
        .partyFlags = F_TRAINER_PARTY_EVS,
        .trainerClass = CLASS_LASS_2,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_MASTER_LASS,
        .trainerName = _("KATRINA"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = NELEMS(sTrainerMons_MasterIvysaur),
        .party = {.ItemCustomMovesEVs = sTrainerMons_MasterIvysaur}
    },
    [MASTER_VENUSAUR] = {
        .partyFlags = F_TRAINER_PARTY_EVS,
        .trainerClass = CLASS_LASS_2,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_MASTER_LASS,
        .trainerName = _("SAL"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY,
        .partySize = NELEMS(sTrainerMons_MasterVenusaur),
        .party = {.ItemCustomMovesEVs = sTrainerMons_MasterVenusaur}
    },
};