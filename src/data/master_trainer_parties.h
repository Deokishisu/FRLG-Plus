static const struct TrainerMonItemCustomMovesEVs sTrainerMons_MasterBulbasaur[] = {
    {
        .iv = 255,
        .lvl = 60,
        .evs = { 4, 252, 252, 0, 0, 0},
        .nature = NATURE_IMPISH,
        .species = SPECIES_BULBASAUR,
        .heldItem = ITEM_LUM_BERRY,
        .abilityNum = 0,
        .moves = {MOVE_LIGHT_SCREEN, MOVE_ATTRACT, MOVE_BODY_SLAM, MOVE_SWORDS_DANCE},
    },
};

static const struct TrainerMonItemCustomMovesEVs sTrainerMons_MasterIvysaur[] = {
    {
        .iv = 3, //flying
        .lvl = 60,
        .evs = { 4, 252, 252, 0, 0, 0},
        .nature = NATURE_CAREFUL,
        .species = SPECIES_IVYSAUR,
        .heldItem = ITEM_CHESTO_BERRY,
        .abilityNum = 0,
        .moves = {MOVE_LIGHT_SCREEN, MOVE_HIDDEN_POWER, MOVE_REST, MOVE_CURSE},
    },
};

static const struct TrainerMonItemCustomMovesEVs sTrainerMons_MasterVenusaur[] = {
    {
        .iv = 9, //fire
        .lvl = 60,
        .evs = { 152, 0, 100, 0, 252, 0},
        .nature = NATURE_MODEST,
        .species = SPECIES_VENUSAUR,
        .heldItem = ITEM_LEFTOVERS,
        .abilityNum = 0,
        .moves = {MOVE_SUNNY_DAY, MOVE_HIDDEN_POWER, MOVE_SYNTHESIS, MOVE_LIGHT_SCREEN},
    },
};