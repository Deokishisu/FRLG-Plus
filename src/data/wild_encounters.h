#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 20  
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 + 20 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 + 10 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 + 10 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 + 10 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 + 10 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 + 5 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 + 5 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 + 4 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 + 4 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 + 1 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_11 ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 + 1 
#define ENCOUNTER_CHANCE_LAND_MONS_TOTAL (ENCOUNTER_CHANCE_LAND_MONS_SLOT_11)

#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 60  
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 + 30 
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 + 5 
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 + 4 
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_4 ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 + 1 
#define ENCOUNTER_CHANCE_WATER_MONS_TOTAL (ENCOUNTER_CHANCE_WATER_MONS_SLOT_4)

#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 60  
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 + 30 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 + 5 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 + 4 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 + 1 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_TOTAL (ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4)

#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 60 
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)

#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 70 
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1 ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 + 30
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1)

#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 40 
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 + 40
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 + 15
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 + 4
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 + 1
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)

const struct WildPokemon sSevenIslandTanobyRuinsMoneanChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsMoneanChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsMoneanChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsLiptooChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsLiptooChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsLiptooChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsWeepthChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsWeepthChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsWeepthChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsDilfordChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsDilfordChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsDilfordChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsScufibChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsScufibChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsScufibChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsRixyChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsRixyChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsRixyChamber_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsViapoisChamber_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsViapoisChamber_FireRed_LandMonsInfo = { 7, sSevenIslandTanobyRuinsViapoisChamber_FireRed_LandMons };

const struct WildPokemon sViridianForest_FireRed_LandMons[] =
{
    { 4, 4, SPECIES_CATERPIE },
    { 4, 4, SPECIES_WEEDLE },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_WEEDLE },
    { 3, 3, SPECIES_CATERPIE },
    { 3, 3, SPECIES_WEEDLE },
    { 5, 5, SPECIES_METAPOD },
    { 5, 5, SPECIES_KAKUNA },
    { 4, 4, SPECIES_KAKUNA },
    { 3, 3, SPECIES_PIKACHU },
    { 6, 6, SPECIES_KAKUNA },
    { 5, 5, SPECIES_PIKACHU },
};

const struct WildPokemonInfo sViridianForest_FireRed_LandMonsInfo = { 14, sViridianForest_FireRed_LandMons };

const struct WildPokemon sMtMoon1F_FireRed_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 7, 7, SPECIES_GEODUDE },
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 8, 8, SPECIES_GEODUDE },
    { 9, 9, SPECIES_GEODUDE },
    { 8, 8, SPECIES_PARAS },
    { 7, 7, SPECIES_ZUBAT },
    { 7, 7, SPECIES_ZUBAT },
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_CLEFAIRY },
};

const struct WildPokemonInfo sMtMoon1F_FireRed_LandMonsInfo = { 7, sMtMoon1F_FireRed_LandMons };

const struct WildPokemon sMtMoonB1F_FireRed_LandMons[] =
{
    { 7, 7, SPECIES_PARAS },
    { 8, 8, SPECIES_PARAS },
    { 5, 5, SPECIES_PARAS },
    { 6, 6, SPECIES_PARAS },
    { 9, 9, SPECIES_PARAS },
    { 10, 10, SPECIES_PARAS },
    { 7, 7, SPECIES_PARAS },
    { 8, 8, SPECIES_PARAS },
    { 5, 5, SPECIES_PARAS },
    { 6, 6, SPECIES_PARAS },
    { 9, 9, SPECIES_PARAS },
    { 10, 10, SPECIES_PARAS },
};

const struct WildPokemonInfo sMtMoonB1F_FireRed_LandMonsInfo = { 5, sMtMoonB1F_FireRed_LandMons };

const struct WildPokemon sMtMoonB2F_FireRed_LandMons[] =
{
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_GEODUDE },
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 10, 10, SPECIES_GEODUDE },
    { 10, 10, SPECIES_PARAS },
    { 12, 12, SPECIES_PARAS },
    { 10, 10, SPECIES_CLEFAIRY },
    { 11, 11, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ZUBAT },
    { 12, 12, SPECIES_CLEFAIRY },
};

const struct WildPokemonInfo sMtMoonB2F_FireRed_LandMonsInfo = { 7, sMtMoonB2F_FireRed_LandMons };

const struct WildPokemon sSSAnneExterior_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sSSAnneExterior_FireRed_WaterMonsInfo = { 1, sSSAnneExterior_FireRed_WaterMons };

const struct WildPokemon sSSAnneExterior_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSSAnneExterior_FireRed_FishingMonsInfo = { 10, sSSAnneExterior_FireRed_FishingMons };

const struct WildPokemon sDiglettsCaveB1F_FireRed_LandMons[] =
{
    { 18, 18, SPECIES_DIGLETT },
    { 19, 19, SPECIES_DIGLETT },
    { 17, 17, SPECIES_DIGLETT },
    { 15, 15, SPECIES_DIGLETT },
    { 16, 16, SPECIES_DIGLETT },
    { 20, 20, SPECIES_DIGLETT },
    { 21, 21, SPECIES_DIGLETT },
    { 22, 22, SPECIES_DIGLETT },
    { 17, 17, SPECIES_DIGLETT },
    { 29, 29, SPECIES_DUGTRIO },
    { 17, 17, SPECIES_DIGLETT },
    { 31, 31, SPECIES_DUGTRIO },
};

const struct WildPokemonInfo sDiglettsCaveB1F_FireRed_LandMonsInfo = { 5, sDiglettsCaveB1F_FireRed_LandMons };

const struct WildPokemon sVictoryRoad1F_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 40, 40, SPECIES_ONIX },
    { 43, 43, SPECIES_ONIX },
    { 46, 46, SPECIES_ONIX },
    { 32, 32, SPECIES_ZUBAT },
    { 44, 44, SPECIES_ARBOK },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_MAROWAK },
    { 44, 44, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad1F_FireRed_LandMonsInfo = { 7, sVictoryRoad1F_FireRed_LandMons };

const struct WildPokemon sVictoryRoad2F_FireRed_LandMons[] =
{
    { 34, 34, SPECIES_MACHOP },
    { 34, 34, SPECIES_GEODUDE },
    { 42, 42, SPECIES_PRIMEAPE },
    { 45, 45, SPECIES_ONIX },
    { 48, 48, SPECIES_ONIX },
    { 34, 34, SPECIES_ZUBAT },
    { 46, 46, SPECIES_ARBOK },
    { 46, 46, SPECIES_GOLBAT },
    { 46, 46, SPECIES_MAROWAK },
    { 46, 46, SPECIES_MACHOKE },
    { 48, 48, SPECIES_MACHOKE },
    { 48, 48, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad2F_FireRed_LandMonsInfo = { 7, sVictoryRoad2F_FireRed_LandMons };

const struct WildPokemon sVictoryRoad3F_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 40, 40, SPECIES_ONIX },
    { 43, 43, SPECIES_ONIX },
    { 46, 46, SPECIES_ONIX },
    { 32, 32, SPECIES_ZUBAT },
    { 44, 44, SPECIES_ARBOK },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_MAROWAK },
    { 44, 44, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad3F_FireRed_LandMonsInfo = { 7, sVictoryRoad3F_FireRed_LandMons };

const struct WildPokemon sPokemonMansion1F_FireRed_LandMons[] =
{
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_KOFFING },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_GROWLITHE },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_WEEZING },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion1F_FireRed_LandMonsInfo = { 7, sPokemonMansion1F_FireRed_LandMons };

const struct WildPokemon sPokemonMansion2F_FireRed_LandMons[] =
{
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_KOFFING },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_GROWLITHE },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_WEEZING },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion2F_FireRed_LandMonsInfo = { 7, sPokemonMansion2F_FireRed_LandMons };

const struct WildPokemon sPokemonMansion3F_FireRed_LandMons[] =
{
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_KOFFING },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_GROWLITHE },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_WEEZING },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion3F_FireRed_LandMonsInfo = { 7, sPokemonMansion3F_FireRed_LandMons };

const struct WildPokemon sPokemonMansionB1F_FireRed_LandMons[] =
{
    { 28, 28, SPECIES_KOFFING },
    { 34, 34, SPECIES_RATICATE },
    { 30, 30, SPECIES_KOFFING },
    { 30, 30, SPECIES_DITTO },
    { 30, 30, SPECIES_GROWLITHE },
    { 38, 38, SPECIES_RATICATE },
    { 28, 28, SPECIES_GRIMER },
    { 34, 34, SPECIES_WEEZING },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_GROWLITHE },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansionB1F_FireRed_LandMonsInfo = { 5, sPokemonMansionB1F_FireRed_LandMons };

const struct WildPokemon sSafariZoneCenter_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_RHYHORN },
    { 22, 22, SPECIES_NIDORAN_M },
    { 24, 24, SPECIES_EXEGGCUTE },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 22, 22, SPECIES_VENONAT },
    { 31, 31, SPECIES_NIDORINO },
    { 31, 31, SPECIES_NIDORINA },
    { 30, 30, SPECIES_PARASECT },
    { 22, 22, SPECIES_VENONAT },
    { 23, 23, SPECIES_SCYTHER },
    { 22, 22, SPECIES_VENONAT },
    { 23, 23, SPECIES_CHANSEY },
};

const struct WildPokemonInfo sSafariZoneCenter_FireRed_LandMonsInfo = { 21, sSafariZoneCenter_FireRed_LandMons };

const struct WildPokemon sSafariZoneCenter_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSafariZoneCenter_FireRed_WaterMonsInfo = { 2, sSafariZoneCenter_FireRed_WaterMons };

const struct WildPokemon sSafariZoneCenter_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneCenter_FireRed_FishingMonsInfo = { 20, sSafariZoneCenter_FireRed_FishingMons };

const struct WildPokemon sSafariZoneEast_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_NIDORAN_M },
    { 26, 26, SPECIES_DODUO },
    { 23, 23, SPECIES_EXEGGCUTE },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 22, 22, SPECIES_PARAS },
    { 33, 33, SPECIES_NIDORINO },
    { 24, 24, SPECIES_NIDORAN_F },
    { 25, 25, SPECIES_PARASECT },
    { 22, 22, SPECIES_PARAS },
    { 25, 25, SPECIES_KANGASKHAN },
    { 22, 22, SPECIES_PARAS },
    { 28, 28, SPECIES_SCYTHER },
};

const struct WildPokemonInfo sSafariZoneEast_FireRed_LandMonsInfo = { 21, sSafariZoneEast_FireRed_LandMons };

const struct WildPokemon sSafariZoneEast_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSafariZoneEast_FireRed_WaterMonsInfo = { 2, sSafariZoneEast_FireRed_WaterMons };

const struct WildPokemon sSafariZoneEast_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneEast_FireRed_FishingMonsInfo = { 20, sSafariZoneEast_FireRed_FishingMons };

const struct WildPokemon sSafariZoneNorth_FireRed_LandMons[] =
{
    { 26, 26, SPECIES_RHYHORN },
    { 30, 30, SPECIES_NIDORAN_M },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 27, 27, SPECIES_EXEGGCUTE },
    { 23, 23, SPECIES_PARAS },
    { 30, 30, SPECIES_NIDORINO },
    { 30, 30, SPECIES_NIDORINA },
    { 32, 32, SPECIES_VENOMOTH },
    { 23, 23, SPECIES_PARAS },
    { 26, 26, SPECIES_CHANSEY },
    { 23, 23, SPECIES_PARAS },
    { 28, 28, SPECIES_TAUROS },
};

const struct WildPokemonInfo sSafariZoneNorth_FireRed_LandMonsInfo = { 21, sSafariZoneNorth_FireRed_LandMons };

const struct WildPokemon sSafariZoneNorth_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSafariZoneNorth_FireRed_WaterMonsInfo = { 2, sSafariZoneNorth_FireRed_WaterMons };

const struct WildPokemon sSafariZoneNorth_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneNorth_FireRed_FishingMonsInfo = { 20, sSafariZoneNorth_FireRed_FishingMons };

const struct WildPokemon sSafariZoneWest_FireRed_LandMons[] =
{
    { 26, 26, SPECIES_DODUO },
    { 22, 22, SPECIES_NIDORAN_M },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 27, 27, SPECIES_EXEGGCUTE },
    { 23, 23, SPECIES_VENONAT },
    { 30, 30, SPECIES_NIDORINO },
    { 30, 30, SPECIES_NIDORAN_F },
    { 32, 32, SPECIES_VENOMOTH },
    { 23, 23, SPECIES_VENONAT },
    { 25, 25, SPECIES_TAUROS },
    { 23, 23, SPECIES_VENONAT },
    { 28, 28, SPECIES_KANGASKHAN },
};

const struct WildPokemonInfo sSafariZoneWest_FireRed_LandMonsInfo = { 21, sSafariZoneWest_FireRed_LandMons };

const struct WildPokemon sSafariZoneWest_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSafariZoneWest_FireRed_WaterMonsInfo = { 2, sSafariZoneWest_FireRed_WaterMons };

const struct WildPokemon sSafariZoneWest_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneWest_FireRed_FishingMonsInfo = { 20, sSafariZoneWest_FireRed_FishingMons };

const struct WildPokemon sCeruleanCave1F_FireRed_LandMons[] =
{
    { 49, 49, SPECIES_MAGNETON },
    { 49, 49, SPECIES_PARASECT },
    { 46, 46, SPECIES_GOLBAT },
    { 46, 46, SPECIES_MACHOKE },
    { 52, 52, SPECIES_PRIMEAPE },
    { 52, 52, SPECIES_DITTO },
    { 58, 58, SPECIES_ELECTRODE },
    { 58, 58, SPECIES_PARASECT },
    { 55, 55, SPECIES_GOLBAT },
    { 55, 55, SPECIES_WOBBUFFET },
    { 61, 61, SPECIES_PRIMEAPE },
    { 61, 61, SPECIES_DITTO },
};

const struct WildPokemonInfo sCeruleanCave1F_FireRed_LandMonsInfo = { 7, sCeruleanCave1F_FireRed_LandMons };

const struct WildPokemon sCeruleanCave1F_FireRed_WaterMons[] =
{
    { 30, 40, SPECIES_PSYDUCK },
    { 40, 50, SPECIES_GOLDUCK },
    { 45, 55, SPECIES_GOLDUCK },
    { 40, 50, SPECIES_PSYDUCK },
    { 40, 50, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCeruleanCave1F_FireRed_WaterMonsInfo = { 2, sCeruleanCave1F_FireRed_WaterMons };

const struct WildPokemon sCeruleanCave1F_FireRed_RockSmashMons[] =
{
    { 30, 40, SPECIES_GEODUDE },
    { 40, 50, SPECIES_GRAVELER },
    { 45, 55, SPECIES_GRAVELER },
    { 40, 50, SPECIES_GEODUDE },
    { 40, 50, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCave1F_FireRed_RockSmashMonsInfo = { 50, sCeruleanCave1F_FireRed_RockSmashMons };

const struct WildPokemon sCeruleanCave1F_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCeruleanCave1F_FireRed_FishingMonsInfo = { 20, sCeruleanCave1F_FireRed_FishingMons };

const struct WildPokemon sCeruleanCave2F_FireRed_LandMons[] =
{
    { 49, 49, SPECIES_GOLBAT },
    { 49, 49, SPECIES_MACHOKE },
    { 52, 52, SPECIES_MAGNETON },
    { 52, 52, SPECIES_PARASECT },
    { 55, 55, SPECIES_KADABRA },
    { 55, 55, SPECIES_DITTO },
    { 58, 58, SPECIES_GOLBAT },
    { 58, 58, SPECIES_WOBBUFFET },
    { 61, 61, SPECIES_ELECTRODE },
    { 61, 61, SPECIES_PARASECT },
    { 64, 64, SPECIES_KADABRA },
    { 64, 64, SPECIES_DITTO },
};

const struct WildPokemonInfo sCeruleanCave2F_FireRed_LandMonsInfo = { 7, sCeruleanCave2F_FireRed_LandMons };

const struct WildPokemon sCeruleanCave2F_FireRed_RockSmashMons[] =
{
    { 35, 45, SPECIES_GEODUDE },
    { 45, 55, SPECIES_GRAVELER },
    { 50, 60, SPECIES_GRAVELER },
    { 45, 55, SPECIES_GEODUDE },
    { 45, 55, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCave2F_FireRed_RockSmashMonsInfo = { 50, sCeruleanCave2F_FireRed_RockSmashMons };

const struct WildPokemon sCeruleanCaveB1F_FireRed_LandMons[] =
{
    { 58, 58, SPECIES_KADABRA },
    { 58, 58, SPECIES_DITTO },
    { 55, 55, SPECIES_MAGNETON },
    { 55, 55, SPECIES_PARASECT },
    { 52, 52, SPECIES_GOLBAT },
    { 52, 52, SPECIES_MACHOKE },
    { 67, 67, SPECIES_KADABRA },
    { 67, 67, SPECIES_DITTO },
    { 64, 64, SPECIES_ELECTRODE },
    { 64, 64, SPECIES_PARASECT },
    { 61, 61, SPECIES_GOLBAT },
    { 61, 61, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo sCeruleanCaveB1F_FireRed_LandMonsInfo = { 7, sCeruleanCaveB1F_FireRed_LandMons };

const struct WildPokemon sCeruleanCaveB1F_FireRed_WaterMons[] =
{
    { 40, 50, SPECIES_PSYDUCK },
    { 50, 60, SPECIES_GOLDUCK },
    { 55, 65, SPECIES_GOLDUCK },
    { 50, 60, SPECIES_PSYDUCK },
    { 50, 60, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCeruleanCaveB1F_FireRed_WaterMonsInfo = { 2, sCeruleanCaveB1F_FireRed_WaterMons };

const struct WildPokemon sCeruleanCaveB1F_FireRed_RockSmashMons[] =
{
    { 40, 50, SPECIES_GEODUDE },
    { 50, 60, SPECIES_GRAVELER },
    { 55, 65, SPECIES_GRAVELER },
    { 50, 60, SPECIES_GEODUDE },
    { 50, 60, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCaveB1F_FireRed_RockSmashMonsInfo = { 50, sCeruleanCaveB1F_FireRed_RockSmashMons };

const struct WildPokemon sCeruleanCaveB1F_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sCeruleanCaveB1F_FireRed_FishingMonsInfo = { 20, sCeruleanCaveB1F_FireRed_FishingMons };

const struct WildPokemon sRockTunnel1F_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_ZUBAT },
    { 16, 16, SPECIES_GEODUDE },
    { 16, 16, SPECIES_MANKEY },
    { 17, 17, SPECIES_GEODUDE },
    { 16, 16, SPECIES_ZUBAT },
    { 16, 16, SPECIES_MACHOP },
    { 17, 17, SPECIES_MANKEY },
    { 17, 17, SPECIES_MACHOP },
    { 15, 15, SPECIES_GEODUDE },
    { 13, 13, SPECIES_ONIX },
    { 15, 15, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ONIX },
};

const struct WildPokemonInfo sRockTunnel1F_FireRed_LandMonsInfo = { 7, sRockTunnel1F_FireRed_LandMons };

const struct WildPokemon sRockTunnelB1F_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_ZUBAT },
    { 17, 17, SPECIES_GEODUDE },
    { 17, 17, SPECIES_MANKEY },
    { 16, 16, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ZUBAT },
    { 17, 17, SPECIES_MACHOP },
    { 16, 16, SPECIES_MANKEY },
    { 13, 13, SPECIES_ONIX },
    { 15, 15, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ONIX },
    { 15, 15, SPECIES_GEODUDE },
    { 17, 17, SPECIES_ONIX },
};

const struct WildPokemonInfo sRockTunnelB1F_FireRed_LandMonsInfo = { 7, sRockTunnelB1F_FireRed_LandMons };

const struct WildPokemon sRockTunnelB1F_FireRed_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sRockTunnelB1F_FireRed_RockSmashMonsInfo = { 50, sRockTunnelB1F_FireRed_RockSmashMons };

const struct WildPokemon sSeafoamIslands1F_FireRed_LandMons[] =
{
    { 27, 27, SPECIES_PSYDUCK },
    { 29, 29, SPECIES_PSYDUCK },
    { 31, 31, SPECIES_PSYDUCK },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 28, 28, SPECIES_GOLBAT },
    { 33, 33, SPECIES_PSYDUCK },
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_PSYDUCK },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslands1F_FireRed_LandMonsInfo = { 7, sSeafoamIslands1F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB1F_FireRed_LandMons[] =
{
    { 29, 29, SPECIES_PSYDUCK },
    { 31, 31, SPECIES_PSYDUCK },
    { 28, 28, SPECIES_SEEL },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 28, 28, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLDUCK },
    { 26, 26, SPECIES_ZUBAT },
    { 35, 35, SPECIES_GOLDUCK },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB1F_FireRed_LandMonsInfo = { 7, sSeafoamIslandsB1F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB2F_FireRed_LandMons[] =
{
    { 30, 30, SPECIES_PSYDUCK },
    { 32, 32, SPECIES_PSYDUCK },
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_GOLDUCK },
    { 32, 32, SPECIES_GOLDUCK },
    { 28, 28, SPECIES_GOLBAT },
    { 32, 32, SPECIES_GOLDUCK },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB2F_FireRed_LandMonsInfo = { 7, sSeafoamIslandsB2F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB3F_FireRed_LandMons[] =
{
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 32, 32, SPECIES_PSYDUCK },
    { 30, 30, SPECIES_PSYDUCK },
    { 32, 32, SPECIES_GOLDUCK },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_GOLDUCK },
    { 32, 32, SPECIES_DEWGONG },
    { 28, 28, SPECIES_GOLBAT },
    { 34, 34, SPECIES_DEWGONG },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_FireRed_LandMonsInfo = { 7, sSeafoamIslandsB3F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB3F_FireRed_WaterMons[] =
{
    { 25, 35, SPECIES_SEEL },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_DEWGONG },
    { 30, 40, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_FireRed_WaterMonsInfo = { 2, sSeafoamIslandsB3F_FireRed_WaterMons };

const struct WildPokemon sSeafoamIslandsB3F_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 20, 30, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_FireRed_FishingMonsInfo = { 20, sSeafoamIslandsB3F_FireRed_FishingMons };

const struct WildPokemon sSeafoamIslandsB4F_FireRed_LandMons[] =
{
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 32, 32, SPECIES_PSYDUCK },
    { 34, 34, SPECIES_SEEL },
    { 32, 32, SPECIES_GOLDUCK },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_DEWGONG },
    { 34, 34, SPECIES_GOLDUCK },
    { 36, 36, SPECIES_DEWGONG },
    { 28, 28, SPECIES_GOLBAT },
    { 36, 36, SPECIES_DEWGONG },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_FireRed_LandMonsInfo = { 7, sSeafoamIslandsB4F_FireRed_LandMons };

const struct WildPokemon sSeafoamIslandsB4F_FireRed_WaterMons[] =
{
    { 25, 35, SPECIES_SEEL },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_DEWGONG },
    { 30, 40, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_FireRed_WaterMonsInfo = { 2, sSeafoamIslandsB4F_FireRed_WaterMons };

const struct WildPokemon sSeafoamIslandsB4F_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 20, 30, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_FireRed_FishingMonsInfo = { 20, sSeafoamIslandsB4F_FireRed_FishingMons };

const struct WildPokemon sPokemonTower3F_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower3F_FireRed_LandMonsInfo = { 2, sPokemonTower3F_FireRed_LandMons };

const struct WildPokemon sPokemonTower4F_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
};

const struct WildPokemonInfo sPokemonTower4F_FireRed_LandMonsInfo = { 4, sPokemonTower4F_FireRed_LandMons };

const struct WildPokemon sPokemonTower5F_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
};

const struct WildPokemonInfo sPokemonTower5F_FireRed_LandMonsInfo = { 6, sPokemonTower5F_FireRed_LandMons };

const struct WildPokemon sPokemonTower6F_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 15, 15, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 21, 21, SPECIES_HAUNTER },
    { 17, 17, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 19, 19, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower6F_FireRed_LandMonsInfo = { 8, sPokemonTower6F_FireRed_LandMons };

const struct WildPokemon sPokemonTower7F_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 15, 15, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
    { 17, 17, SPECIES_CUBONE },
    { 19, 19, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
    { 18, 18, SPECIES_GASTLY },
    { 25, 25, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower7F_FireRed_LandMonsInfo = { 10, sPokemonTower7F_FireRed_LandMons };

const struct WildPokemon sPowerPlant_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_PIKACHU },
    { 24, 24, SPECIES_PIKACHU },
    { 31, 31, SPECIES_MAGNETON },
    { 34, 34, SPECIES_MAGNETON },
    { 26, 26, SPECIES_PIKACHU },
    { 32, 32, SPECIES_ELECTABUZZ },
    { 26, 26, SPECIES_PIKACHU },
    { 35, 35, SPECIES_ELECTABUZZ },
};

const struct WildPokemonInfo sPowerPlant_FireRed_LandMonsInfo = { 7, sPowerPlant_FireRed_LandMons };

const struct WildPokemon sMtEmberExterior_FireRed_LandMons[] =
{
    { 30, 30, SPECIES_PONYTA },
    { 38, 38, SPECIES_FEAROW },
    { 33, 33, SPECIES_PONYTA },
    { 32, 32, SPECIES_SPEAROW },
    { 35, 35, SPECIES_MACHOP },
    { 33, 33, SPECIES_GEODUDE },
    { 36, 36, SPECIES_PONYTA },
    { 40, 40, SPECIES_FEAROW },
    { 30, 30, SPECIES_SPEAROW },
    { 39, 39, SPECIES_RAPIDASH },
    { 30, 30, SPECIES_SPEAROW },
    { 42, 42, SPECIES_RAPIDASH },
};

const struct WildPokemonInfo sMtEmberExterior_FireRed_LandMonsInfo = { 21, sMtEmberExterior_FireRed_LandMons };

const struct WildPokemon sMtEmberExterior_FireRed_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sMtEmberExterior_FireRed_RockSmashMonsInfo = { 50, sMtEmberExterior_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberSummitPath1F_FireRed_LandMons[] =
{
    { 33, 33, SPECIES_GEODUDE },
    { 35, 35, SPECIES_MACHOP },
    { 29, 29, SPECIES_GEODUDE },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MACHOP },
    { 33, 33, SPECIES_MACHOP },
    { 35, 35, SPECIES_GEODUDE },
    { 37, 37, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
};

const struct WildPokemonInfo sMtEmberSummitPath1F_FireRed_LandMonsInfo = { 7, sMtEmberSummitPath1F_FireRed_LandMons };

const struct WildPokemon sMtEmberSummitPath2F_FireRed_LandMons[] =
{
    { 34, 34, SPECIES_GEODUDE },
    { 36, 36, SPECIES_MACHOP },
    { 30, 30, SPECIES_GEODUDE },
    { 32, 32, SPECIES_GEODUDE },
    { 32, 32, SPECIES_MACHOP },
    { 34, 34, SPECIES_MACHOP },
    { 38, 38, SPECIES_MACHOKE },
    { 38, 38, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
};

const struct WildPokemonInfo sMtEmberSummitPath2F_FireRed_LandMonsInfo = { 7, sMtEmberSummitPath2F_FireRed_LandMons };

const struct WildPokemon sMtEmberSummitPath2F_FireRed_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sMtEmberSummitPath2F_FireRed_RockSmashMonsInfo = { 50, sMtEmberSummitPath2F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberSummitPath3F_FireRed_LandMons[] =
{
    { 33, 33, SPECIES_GEODUDE },
    { 35, 35, SPECIES_MACHOP },
    { 29, 29, SPECIES_GEODUDE },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MACHOP },
    { 33, 33, SPECIES_MACHOP },
    { 35, 35, SPECIES_GEODUDE },
    { 37, 37, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
};

const struct WildPokemonInfo sMtEmberSummitPath3F_FireRed_LandMonsInfo = { 7, sMtEmberSummitPath3F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPath1F_FireRed_LandMons[] =
{
    { 36, 36, SPECIES_GEODUDE },
    { 38, 38, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 34, 34, SPECIES_MACHOP },
    { 36, 36, SPECIES_MACHOP },
    { 38, 38, SPECIES_GEODUDE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_GEODUDE },
    { 42, 42, SPECIES_MACHOKE },
    { 40, 40, SPECIES_GEODUDE },
    { 42, 42, SPECIES_MACHOKE },
};

const struct WildPokemonInfo sMtEmberRubyPath1F_FireRed_LandMonsInfo = { 7, sMtEmberRubyPath1F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPath1F_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPath1F_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPath1F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB1F_FireRed_LandMons[] =
{
    { 38, 38, SPECIES_GEODUDE },
    { 36, 36, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 40, 40, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 28, 28, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB1F_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB1F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB1F_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB1F_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB1F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB2F_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GEODUDE },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 32, 32, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB2F_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB2F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB2F_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB2F_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB2F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB3F_FireRed_LandMons[] =
{
    { 26, 26, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 32, 32, SPECIES_SLUGMA },
    { 24, 24, SPECIES_SLUGMA },
    { 22, 22, SPECIES_SLUGMA },
    { 20, 20, SPECIES_SLUGMA },
    { 34, 34, SPECIES_SLUGMA },
    { 36, 36, SPECIES_SLUGMA },
    { 18, 18, SPECIES_SLUGMA },
    { 36, 36, SPECIES_SLUGMA },
    { 18, 18, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB3F_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB3F_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB3F_FireRed_RockSmashMons[] =
{
    { 15, 25, SPECIES_SLUGMA },
    { 25, 35, SPECIES_SLUGMA },
    { 40, 45, SPECIES_MAGCARGO },
    { 35, 45, SPECIES_MAGCARGO },
    { 25, 35, SPECIES_MAGCARGO },
};

const struct WildPokemonInfo sMtEmberRubyPathB3F_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB3F_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB1FStairs_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GEODUDE },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 32, 32, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB1FStairs_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB1FStairs_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB1FStairs_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB1FStairs_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB1FStairs_FireRed_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB2FStairs_FireRed_LandMons[] =
{
    { 38, 38, SPECIES_GEODUDE },
    { 36, 36, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 40, 40, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 28, 28, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB2FStairs_FireRed_LandMonsInfo = { 7, sMtEmberRubyPathB2FStairs_FireRed_LandMons };

const struct WildPokemon sMtEmberRubyPathB2FStairs_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB2FStairs_FireRed_RockSmashMonsInfo = { 50, sMtEmberRubyPathB2FStairs_FireRed_RockSmashMons };

const struct WildPokemon sThreeIslandBerryForest_FireRed_LandMons[] =
{
    { 37, 37, SPECIES_PIDGEOTTO },
    { 35, 35, SPECIES_GLOOM },
    { 32, 32, SPECIES_PIDGEY },
    { 30, 30, SPECIES_ODDISH },
    { 34, 34, SPECIES_VENONAT },
    { 34, 34, SPECIES_DROWZEE },
    { 35, 35, SPECIES_EXEGGCUTE },
    { 31, 31, SPECIES_PSYDUCK },
    { 37, 37, SPECIES_VENOMOTH },
    { 37, 37, SPECIES_HYPNO },
    { 40, 40, SPECIES_VENOMOTH },
    { 40, 40, SPECIES_HYPNO },
};

const struct WildPokemonInfo sThreeIslandBerryForest_FireRed_LandMonsInfo = { 21, sThreeIslandBerryForest_FireRed_LandMons };

const struct WildPokemon sThreeIslandBerryForest_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_PSYDUCK },
    { 20, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_GOLDUCK },
    { 35, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo sThreeIslandBerryForest_FireRed_WaterMonsInfo = { 2, sThreeIslandBerryForest_FireRed_WaterMons };

const struct WildPokemon sThreeIslandBerryForest_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sThreeIslandBerryForest_FireRed_FishingMonsInfo = { 20, sThreeIslandBerryForest_FireRed_FishingMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_FireRed_LandMons[] =
{
    { 43, 43, SPECIES_SEEL },
    { 45, 45, SPECIES_GOLBAT },
    { 45, 45, SPECIES_SEEL },
    { 47, 47, SPECIES_SEEL },
    { 40, 40, SPECIES_ZUBAT },
    { 49, 49, SPECIES_DEWGONG },
    { 51, 51, SPECIES_DEWGONG },
    { 41, 41, SPECIES_PSYDUCK },
    { 48, 48, SPECIES_GOLBAT },
    { 53, 53, SPECIES_DEWGONG },
    { 48, 48, SPECIES_GOLBAT },
    { 53, 53, SPECIES_DEWGONG },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_FireRed_LandMonsInfo = { 7, sFourIslandIcefallCaveEntrance_FireRed_LandMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_SEEL },
    { 5, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_DEWGONG },
    { 5, 15, SPECIES_WOOPER },
    { 5, 15, SPECIES_WOOPER },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_FireRed_WaterMonsInfo = { 2, sFourIslandIcefallCaveEntrance_FireRed_WaterMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_FireRed_FishingMonsInfo = { 20, sFourIslandIcefallCaveEntrance_FireRed_FishingMons };

const struct WildPokemon sFourIslandIcefallCave1F_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_SWINUB },
    { 45, 45, SPECIES_GOLBAT },
    { 45, 45, SPECIES_SEEL },
    { 27, 27, SPECIES_SWINUB },
    { 40, 40, SPECIES_ZUBAT },
    { 29, 29, SPECIES_SWINUB },
    { 30, 30, SPECIES_DELIBIRD },
    { 31, 31, SPECIES_SWINUB },
    { 48, 48, SPECIES_GOLBAT },
    { 23, 23, SPECIES_SWINUB },
    { 48, 48, SPECIES_GOLBAT },
    { 23, 23, SPECIES_SWINUB },
};

const struct WildPokemonInfo sFourIslandIcefallCave1F_FireRed_LandMonsInfo = { 7, sFourIslandIcefallCave1F_FireRed_LandMons };

const struct WildPokemon sFourIslandIcefallCaveB1F_FireRed_LandMons[] =
{
    { 25, 25, SPECIES_SWINUB },
    { 45, 45, SPECIES_GOLBAT },
    { 45, 45, SPECIES_SEEL },
    { 27, 27, SPECIES_SWINUB },
    { 40, 40, SPECIES_ZUBAT },
    { 29, 29, SPECIES_SWINUB },
    { 30, 30, SPECIES_DELIBIRD },
    { 31, 31, SPECIES_SWINUB },
    { 48, 48, SPECIES_GOLBAT },
    { 23, 23, SPECIES_SWINUB },
    { 48, 48, SPECIES_GOLBAT },
    { 23, 23, SPECIES_SWINUB },
};

const struct WildPokemonInfo sFourIslandIcefallCaveB1F_FireRed_LandMonsInfo = { 7, sFourIslandIcefallCaveB1F_FireRed_LandMons };

const struct WildPokemon sFourIslandIcefallCaveBack_FireRed_LandMons[] =
{
    { 43, 43, SPECIES_SEEL },
    { 45, 45, SPECIES_GOLBAT },
    { 45, 45, SPECIES_SEEL },
    { 47, 47, SPECIES_SEEL },
    { 40, 40, SPECIES_ZUBAT },
    { 49, 49, SPECIES_DEWGONG },
    { 51, 51, SPECIES_DEWGONG },
    { 41, 41, SPECIES_PSYDUCK },
    { 48, 48, SPECIES_GOLBAT },
    { 53, 53, SPECIES_DEWGONG },
    { 48, 48, SPECIES_GOLBAT },
    { 53, 53, SPECIES_DEWGONG },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_FireRed_LandMonsInfo = { 7, sFourIslandIcefallCaveBack_FireRed_LandMons };

const struct WildPokemon sFourIslandIcefallCaveBack_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 45, SPECIES_TENTACOOL },
    { 35, 45, SPECIES_TENTACRUEL },
    { 30, 45, SPECIES_LAPRAS },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_FireRed_WaterMonsInfo = { 2, sFourIslandIcefallCaveBack_FireRed_WaterMons };

const struct WildPokemon sFourIslandIcefallCaveBack_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_FireRed_FishingMonsInfo = { 20, sFourIslandIcefallCaveBack_FireRed_FishingMons };

const struct WildPokemon sSixIslandPatternBush_FireRed_LandMons[] =
{
    { 9, 9, SPECIES_SPINARAK },
    { 9, 9, SPECIES_KAKUNA },
    { 14, 14, SPECIES_SPINARAK },
    { 6, 6, SPECIES_CATERPIE },
    { 6, 6, SPECIES_WEEDLE },
    { 15, 15, SPECIES_HERACROSS },
    { 9, 9, SPECIES_METAPOD },
    { 20, 20, SPECIES_HERACROSS },
    { 9, 9, SPECIES_LEDYBA },
    { 25, 25, SPECIES_HERACROSS },
    { 14, 14, SPECIES_LEDYBA },
    { 30, 30, SPECIES_HERACROSS },
};

const struct WildPokemonInfo sSixIslandPatternBush_FireRed_LandMonsInfo = { 21, sSixIslandPatternBush_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom1_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom1_FireRed_LandMonsInfo = { 1, sFiveIslandLostCaveRoom1_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom2_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom2_FireRed_LandMonsInfo = { 2, sFiveIslandLostCaveRoom2_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom3_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom3_FireRed_LandMonsInfo = { 3, sFiveIslandLostCaveRoom3_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom4_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom4_FireRed_LandMonsInfo = { 4, sFiveIslandLostCaveRoom4_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom5_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom5_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom5_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom6_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom6_FireRed_LandMonsInfo = { 6, sFiveIslandLostCaveRoom6_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom7_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom7_FireRed_LandMonsInfo = { 7, sFiveIslandLostCaveRoom7_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom8_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom8_FireRed_LandMonsInfo = { 8, sFiveIslandLostCaveRoom8_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom9_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom9_FireRed_LandMonsInfo = { 9, sFiveIslandLostCaveRoom9_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom10_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom10_FireRed_LandMonsInfo = { 10, sFiveIslandLostCaveRoom10_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom11_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MURKROW },
    { 20, 20, SPECIES_MURKROW },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom11_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom11_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom12_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MURKROW },
    { 20, 20, SPECIES_MURKROW },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom12_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom12_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom13_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MURKROW },
    { 20, 20, SPECIES_MURKROW },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom13_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom13_FireRed_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom14_FireRed_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MURKROW },
    { 20, 20, SPECIES_MURKROW },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MURKROW },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom14_FireRed_LandMonsInfo = { 5, sFiveIslandLostCaveRoom14_FireRed_LandMons };

const struct WildPokemon sOneIslandKindleRoad_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_SPEAROW },
    { 34, 34, SPECIES_PONYTA },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_PONYTA },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MEOWTH },
    { 30, 30, SPECIES_SPEAROW },
    { 34, 34, SPECIES_PSYDUCK },
    { 37, 37, SPECIES_RAPIDASH },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_RAPIDASH },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sOneIslandKindleRoad_FireRed_LandMonsInfo = { 21, sOneIslandKindleRoad_FireRed_LandMons };

const struct WildPokemon sOneIslandKindleRoad_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIslandKindleRoad_FireRed_WaterMonsInfo = { 2, sOneIslandKindleRoad_FireRed_WaterMons };

const struct WildPokemon sOneIslandKindleRoad_FireRed_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sOneIslandKindleRoad_FireRed_RockSmashMonsInfo = { 25, sOneIslandKindleRoad_FireRed_RockSmashMons };

const struct WildPokemon sOneIslandKindleRoad_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sOneIslandKindleRoad_FireRed_FishingMonsInfo = { 20, sOneIslandKindleRoad_FireRed_FishingMons };

const struct WildPokemon sOneIslandTreasureBeach_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_SPEAROW },
    { 33, 33, SPECIES_TANGELA },
    { 31, 31, SPECIES_SPEAROW },
    { 35, 35, SPECIES_TANGELA },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_MEOWTH },
    { 38, 38, SPECIES_FEAROW },
    { 31, 31, SPECIES_PSYDUCK },
    { 40, 40, SPECIES_FEAROW },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_FEAROW },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_FireRed_LandMonsInfo = { 21, sOneIslandTreasureBeach_FireRed_LandMons };

const struct WildPokemon sOneIslandTreasureBeach_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_FireRed_WaterMonsInfo = { 2, sOneIslandTreasureBeach_FireRed_WaterMons };

const struct WildPokemon sOneIslandTreasureBeach_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_FireRed_FishingMonsInfo = { 20, sOneIslandTreasureBeach_FireRed_FishingMons };

const struct WildPokemon sTwoIslandCapeBrink_FireRed_LandMons[] =
{
    { 31, 31, SPECIES_SPEAROW },
    { 30, 30, SPECIES_ODDISH },
    { 32, 32, SPECIES_ODDISH },
    { 36, 36, SPECIES_GLOOM },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_MEOWTH },
    { 38, 38, SPECIES_GLOOM },
    { 31, 31, SPECIES_PSYDUCK },
    { 37, 37, SPECIES_GOLDUCK },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_GOLDUCK },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_FireRed_LandMonsInfo = { 21, sTwoIslandCapeBrink_FireRed_LandMons };

const struct WildPokemon sTwoIslandCapeBrink_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_PSYDUCK },
    { 20, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_GOLDUCK },
    { 35, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_FireRed_WaterMonsInfo = { 2, sTwoIslandCapeBrink_FireRed_WaterMons };

const struct WildPokemon sTwoIslandCapeBrink_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_FireRed_FishingMonsInfo = { 20, sTwoIslandCapeBrink_FireRed_FishingMons };

const struct WildPokemon sThreeIslandBondBridge_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_PIDGEY },
    { 31, 31, SPECIES_ODDISH },
    { 29, 29, SPECIES_PIDGEY },
    { 36, 36, SPECIES_GLOOM },
    { 34, 34, SPECIES_PIDGEOTTO },
    { 31, 31, SPECIES_MEOWTH },
    { 34, 34, SPECIES_VENONAT },
    { 31, 31, SPECIES_PSYDUCK },
    { 37, 37, SPECIES_PIDGEOTTO },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_PIDGEOTTO },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sThreeIslandBondBridge_FireRed_LandMonsInfo = { 21, sThreeIslandBondBridge_FireRed_LandMons };

const struct WildPokemon sThreeIslandBondBridge_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sThreeIslandBondBridge_FireRed_WaterMonsInfo = { 2, sThreeIslandBondBridge_FireRed_WaterMons };

const struct WildPokemon sThreeIslandBondBridge_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sThreeIslandBondBridge_FireRed_FishingMonsInfo = { 20, sThreeIslandBondBridge_FireRed_FishingMons };

const struct WildPokemon sThreeIslandPort_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_DUNSPARCE },
    { 15, 15, SPECIES_DUNSPARCE },
    { 10, 10, SPECIES_DUNSPARCE },
    { 10, 10, SPECIES_DUNSPARCE },
    { 20, 20, SPECIES_DUNSPARCE },
    { 20, 20, SPECIES_DUNSPARCE },
    { 25, 25, SPECIES_DUNSPARCE },
    { 30, 30, SPECIES_DUNSPARCE },
    { 25, 25, SPECIES_DUNSPARCE },
    { 30, 30, SPECIES_DUNSPARCE },
    { 5, 5, SPECIES_DUNSPARCE },
    { 35, 35, SPECIES_DUNSPARCE },
};

const struct WildPokemonInfo sThreeIslandPort_FireRed_LandMonsInfo = { 1, sThreeIslandPort_FireRed_LandMons };

const struct WildPokemon sFiveIslandResortGorgeous_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandResortGorgeous_FireRed_WaterMonsInfo = { 2, sFiveIslandResortGorgeous_FireRed_WaterMons };

const struct WildPokemon sFiveIslandResortGorgeous_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIslandResortGorgeous_FireRed_FishingMonsInfo = { 20, sFiveIslandResortGorgeous_FireRed_FishingMons };

const struct WildPokemon sFiveIslandWaterLabyrinth_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandWaterLabyrinth_FireRed_WaterMonsInfo = { 2, sFiveIslandWaterLabyrinth_FireRed_WaterMons };

const struct WildPokemon sFiveIslandWaterLabyrinth_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIslandWaterLabyrinth_FireRed_FishingMonsInfo = { 20, sFiveIslandWaterLabyrinth_FireRed_FishingMons };

const struct WildPokemon sFiveIslandMeadow_FireRed_LandMons[] =
{
    { 44, 44, SPECIES_PIDGEY },
    { 10, 10, SPECIES_SENTRET },
    { 48, 48, SPECIES_PIDGEOTTO },
    { 10, 10, SPECIES_HOPPIP },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 15, 15, SPECIES_HOPPIP },
    { 41, 41, SPECIES_PSYDUCK },
    { 50, 50, SPECIES_PIDGEOTTO },
    { 47, 47, SPECIES_PERSIAN },
    { 50, 50, SPECIES_PIDGEOTTO },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sFiveIslandMeadow_FireRed_LandMonsInfo = { 21, sFiveIslandMeadow_FireRed_LandMons };

const struct WildPokemon sFiveIslandMeadow_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandMeadow_FireRed_WaterMonsInfo = { 2, sFiveIslandMeadow_FireRed_WaterMons };

const struct WildPokemon sFiveIslandMeadow_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIslandMeadow_FireRed_FishingMonsInfo = { 20, sFiveIslandMeadow_FireRed_FishingMons };

const struct WildPokemon sFiveIslandMemorialPillar_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_HOPPIP },
    { 12, 12, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
    { 10, 10, SPECIES_HOPPIP },
    { 12, 12, SPECIES_HOPPIP },
    { 16, 16, SPECIES_HOPPIP },
    { 6, 6, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_FireRed_LandMonsInfo = { 21, sFiveIslandMemorialPillar_FireRed_LandMons };

const struct WildPokemon sFiveIslandMemorialPillar_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_FireRed_WaterMonsInfo = { 2, sFiveIslandMemorialPillar_FireRed_WaterMons };

const struct WildPokemon sFiveIslandMemorialPillar_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_FireRed_FishingMonsInfo = { 20, sFiveIslandMemorialPillar_FireRed_FishingMons };

const struct WildPokemon sSixIslandOutcastIsland_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandOutcastIsland_FireRed_WaterMonsInfo = { 2, sSixIslandOutcastIsland_FireRed_WaterMons };

const struct WildPokemon sSixIslandOutcastIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSixIslandOutcastIsland_FireRed_FishingMonsInfo = { 20, sSixIslandOutcastIsland_FireRed_FishingMons };

const struct WildPokemon sSixIslandGreenPath_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandGreenPath_FireRed_WaterMonsInfo = { 2, sSixIslandGreenPath_FireRed_WaterMons };

const struct WildPokemon sSixIslandGreenPath_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSixIslandGreenPath_FireRed_FishingMonsInfo = { 20, sSixIslandGreenPath_FireRed_FishingMons };

const struct WildPokemon sSixIslandWaterPath_FireRed_LandMons[] =
{
    { 44, 44, SPECIES_SPEAROW },
    { 10, 10, SPECIES_SENTRET },
    { 44, 44, SPECIES_ODDISH },
    { 48, 48, SPECIES_FEAROW },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 48, 48, SPECIES_GLOOM },
    { 41, 41, SPECIES_PSYDUCK },
    { 50, 50, SPECIES_FEAROW },
    { 47, 47, SPECIES_PERSIAN },
    { 50, 50, SPECIES_FEAROW },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSixIslandWaterPath_FireRed_LandMonsInfo = { 21, sSixIslandWaterPath_FireRed_LandMons };

const struct WildPokemon sSixIslandWaterPath_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandWaterPath_FireRed_WaterMonsInfo = { 2, sSixIslandWaterPath_FireRed_WaterMons };

const struct WildPokemon sSixIslandWaterPath_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSixIslandWaterPath_FireRed_FishingMonsInfo = { 20, sSixIslandWaterPath_FireRed_FishingMons };

const struct WildPokemon sSixIslandRuinValley_FireRed_LandMons[] =
{
    { 15, 15, SPECIES_NATU },
    { 44, 44, SPECIES_SPEAROW },
    { 18, 18, SPECIES_YANMA },
    { 15, 15, SPECIES_WOOPER },
    { 49, 49, SPECIES_FEAROW },
    { 43, 43, SPECIES_MEOWTH },
    { 25, 25, SPECIES_WOBBUFFET },
    { 41, 41, SPECIES_PSYDUCK },
    { 20, 20, SPECIES_NATU },
    { 49, 49, SPECIES_PERSIAN },
    { 20, 20, SPECIES_NATU },
    { 52, 52, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSixIslandRuinValley_FireRed_LandMonsInfo = { 21, sSixIslandRuinValley_FireRed_LandMons };

const struct WildPokemon sSixIslandRuinValley_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_WOOPER },
    { 10, 20, SPECIES_WOOPER },
    { 15, 25, SPECIES_WOOPER },
    { 20, 25, SPECIES_WOOPER },
    { 20, 25, SPECIES_WOOPER },
};

const struct WildPokemonInfo sSixIslandRuinValley_FireRed_WaterMonsInfo = { 2, sSixIslandRuinValley_FireRed_WaterMons };

const struct WildPokemon sSixIslandRuinValley_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSixIslandRuinValley_FireRed_FishingMonsInfo = { 20, sSixIslandRuinValley_FireRed_FishingMons };

const struct WildPokemon sSevenIslandTrainerTower_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSevenIslandTrainerTower_FireRed_WaterMonsInfo = { 2, sSevenIslandTrainerTower_FireRed_WaterMons };

const struct WildPokemon sSevenIslandTrainerTower_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSevenIslandTrainerTower_FireRed_FishingMonsInfo = { 20, sSevenIslandTrainerTower_FireRed_FishingMons };

const struct WildPokemon sSevenIslandSevaultCanyonEntrance_FireRed_LandMons[] =
{
    { 44, 44, SPECIES_SPEAROW },
    { 10, 10, SPECIES_SENTRET },
    { 10, 10, SPECIES_PHANPY },
    { 48, 48, SPECIES_FEAROW },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 50, 50, SPECIES_FEAROW },
    { 41, 41, SPECIES_PSYDUCK },
    { 15, 15, SPECIES_PHANPY },
    { 47, 47, SPECIES_PERSIAN },
    { 15, 15, SPECIES_PHANPY },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyonEntrance_FireRed_LandMonsInfo = { 21, sSevenIslandSevaultCanyonEntrance_FireRed_LandMons };

const struct WildPokemon sSevenIslandSevaultCanyon_FireRed_LandMons[] =
{
    { 46, 46, SPECIES_GEODUDE },
    { 15, 15, SPECIES_PHANPY },
    { 46, 46, SPECIES_CUBONE },
    { 50, 50, SPECIES_FEAROW },
    { 52, 52, SPECIES_MAROWAK },
    { 43, 43, SPECIES_MEOWTH },
    { 54, 54, SPECIES_ONIX },
    { 30, 30, SPECIES_SKARMORY },
    { 15, 15, SPECIES_LARVITAR },
    { 49, 49, SPECIES_PERSIAN },
    { 20, 20, SPECIES_LARVITAR },
    { 52, 52, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyon_FireRed_LandMonsInfo = { 21, sSevenIslandSevaultCanyon_FireRed_LandMons };

const struct WildPokemon sSevenIslandSevaultCanyon_FireRed_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyon_FireRed_RockSmashMonsInfo = { 25, sSevenIslandSevaultCanyon_FireRed_RockSmashMons };

const struct WildPokemon sSevenIslandTanobyRuins_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSevenIslandTanobyRuins_FireRed_WaterMonsInfo = { 2, sSevenIslandTanobyRuins_FireRed_WaterMons };

const struct WildPokemon sSevenIslandTanobyRuins_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_QWILFISH },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sSevenIslandTanobyRuins_FireRed_FishingMonsInfo = { 20, sSevenIslandTanobyRuins_FireRed_FishingMons };

const struct WildPokemon sRoute1_FireRed_LandMons[] =
{
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 2, 2, SPECIES_PIDGEY },
    { 2, 2, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 4, 4, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
    { 5, 5, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
};

const struct WildPokemonInfo sRoute1_FireRed_LandMonsInfo = { 21, sRoute1_FireRed_LandMons };

const struct WildPokemon sRoute2_FireRed_LandMons[] =
{
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
    { 4, 4, SPECIES_PIDGEY },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_PIDGEY },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_PIDGEY },
    { 4, 4, SPECIES_CATERPIE },
    { 4, 4, SPECIES_WEEDLE },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_WEEDLE },
};

const struct WildPokemonInfo sRoute2_FireRed_LandMonsInfo = { 21, sRoute2_FireRed_LandMons };

const struct WildPokemon sRoute3_FireRed_LandMons[] =
{
    { 6, 6, SPECIES_SPEAROW },
    { 6, 6, SPECIES_PIDGEY },
    { 7, 7, SPECIES_SPEAROW },
    { 7, 7, SPECIES_MANKEY },
    { 6, 6, SPECIES_NIDORAN_M },
    { 7, 7, SPECIES_PIDGEY },
    { 8, 8, SPECIES_SPEAROW },
    { 3, 3, SPECIES_JIGGLYPUFF },
    { 7, 7, SPECIES_NIDORAN_M },
    { 5, 5, SPECIES_JIGGLYPUFF },
    { 6, 6, SPECIES_NIDORAN_F },
    { 7, 7, SPECIES_JIGGLYPUFF },
};

const struct WildPokemonInfo sRoute3_FireRed_LandMonsInfo = { 21, sRoute3_FireRed_LandMons };

const struct WildPokemon sRoute4_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_SPEAROW },
    { 10, 10, SPECIES_RATTATA },
    { 6, 6, SPECIES_EKANS },
    { 10, 10, SPECIES_EKANS },
    { 8, 8, SPECIES_SPEAROW },
    { 8, 8, SPECIES_RATTATA },
    { 12, 12, SPECIES_SPEAROW },
    { 12, 12, SPECIES_RATTATA },
    { 10, 10, SPECIES_MANKEY },
    { 8, 8, SPECIES_EKANS },
    { 12, 12, SPECIES_MANKEY },
    { 12, 12, SPECIES_EKANS },
};

const struct WildPokemonInfo sRoute4_FireRed_LandMonsInfo = { 21, sRoute4_FireRed_LandMons };

const struct WildPokemon sRoute4_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute4_FireRed_WaterMonsInfo = { 2, sRoute4_FireRed_WaterMons };

const struct WildPokemon sRoute4_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute4_FireRed_FishingMonsInfo = { 20, sRoute4_FireRed_FishingMons };

const struct WildPokemon sRoute5_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_MEOWTH },
    { 13, 13, SPECIES_PIDGEY },
    { 13, 13, SPECIES_ODDISH },
    { 12, 12, SPECIES_MEOWTH },
    { 15, 15, SPECIES_ODDISH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_ODDISH },
    { 16, 16, SPECIES_PIDGEY },
    { 15, 15, SPECIES_PIDGEY },
    { 14, 14, SPECIES_MEOWTH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute5_FireRed_LandMonsInfo = { 21, sRoute5_FireRed_LandMons };

const struct WildPokemon sRoute6_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_MEOWTH },
    { 13, 13, SPECIES_PIDGEY },
    { 13, 13, SPECIES_ODDISH },
    { 12, 12, SPECIES_MEOWTH },
    { 15, 15, SPECIES_ODDISH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_ODDISH },
    { 16, 16, SPECIES_PIDGEY },
    { 15, 15, SPECIES_PIDGEY },
    { 14, 14, SPECIES_MEOWTH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute6_FireRed_LandMonsInfo = { 21, sRoute6_FireRed_LandMons };

const struct WildPokemon sRoute6_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute6_FireRed_WaterMonsInfo = { 2, sRoute6_FireRed_WaterMons };

const struct WildPokemon sRoute6_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute6_FireRed_FishingMonsInfo = { 20, sRoute6_FireRed_FishingMons };

const struct WildPokemon sRoute7_FireRed_LandMons[] =
{
    { 19, 19, SPECIES_PIDGEY },
    { 17, 17, SPECIES_MEOWTH },
    { 19, 19, SPECIES_ODDISH },
    { 18, 18, SPECIES_MEOWTH },
    { 22, 22, SPECIES_PIDGEY },
    { 22, 22, SPECIES_ODDISH },
    { 18, 18, SPECIES_GROWLITHE },
    { 20, 20, SPECIES_GROWLITHE },
    { 17, 17, SPECIES_MEOWTH },
    { 19, 19, SPECIES_MEOWTH },
    { 17, 17, SPECIES_MEOWTH },
    { 20, 20, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute7_FireRed_LandMonsInfo = { 21, sRoute7_FireRed_LandMons };

const struct WildPokemon sRoute8_FireRed_LandMons[] =
{
    { 18, 18, SPECIES_PIDGEY },
    { 18, 18, SPECIES_MEOWTH },
    { 16, 16, SPECIES_GROWLITHE },
    { 20, 20, SPECIES_PIDGEY },
    { 20, 20, SPECIES_MEOWTH },
    { 17, 17, SPECIES_EKANS },
    { 17, 17, SPECIES_GROWLITHE },
    { 19, 19, SPECIES_EKANS },
    { 17, 17, SPECIES_EKANS },
    { 15, 15, SPECIES_GROWLITHE },
    { 17, 17, SPECIES_EKANS },
    { 18, 18, SPECIES_GROWLITHE },
};

const struct WildPokemonInfo sRoute8_FireRed_LandMonsInfo = { 21, sRoute8_FireRed_LandMons };

const struct WildPokemon sRoute9_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_SPEAROW },
    { 16, 16, SPECIES_RATTATA },
    { 11, 11, SPECIES_EKANS },
    { 15, 15, SPECIES_EKANS },
    { 13, 13, SPECIES_SPEAROW },
    { 14, 14, SPECIES_RATTATA },
    { 17, 17, SPECIES_SPEAROW },
    { 17, 17, SPECIES_RATTATA },
    { 14, 14, SPECIES_RATTATA },
    { 13, 13, SPECIES_EKANS },
    { 14, 14, SPECIES_RATTATA },
    { 17, 17, SPECIES_EKANS },
};

const struct WildPokemonInfo sRoute9_FireRed_LandMonsInfo = { 21, sRoute9_FireRed_LandMons };

const struct WildPokemon sRoute10_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_SPEAROW },
    { 16, 16, SPECIES_VOLTORB },
    { 11, 11, SPECIES_EKANS },
    { 15, 15, SPECIES_EKANS },
    { 13, 13, SPECIES_SPEAROW },
    { 14, 14, SPECIES_VOLTORB },
    { 17, 17, SPECIES_SPEAROW },
    { 17, 17, SPECIES_VOLTORB },
    { 14, 14, SPECIES_VOLTORB },
    { 13, 13, SPECIES_EKANS },
    { 14, 14, SPECIES_VOLTORB },
    { 17, 17, SPECIES_EKANS },
};

const struct WildPokemonInfo sRoute10_FireRed_LandMonsInfo = { 21, sRoute10_FireRed_LandMons };

const struct WildPokemon sRoute10_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute10_FireRed_WaterMonsInfo = { 2, sRoute10_FireRed_WaterMons };

const struct WildPokemon sRoute10_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute10_FireRed_FishingMonsInfo = { 20, sRoute10_FireRed_FishingMons };

const struct WildPokemon sRoute11_FireRed_LandMons[] =
{
    { 14, 14, SPECIES_EKANS },
    { 15, 15, SPECIES_SPEAROW },
    { 12, 12, SPECIES_EKANS },
    { 13, 13, SPECIES_SPEAROW },
    { 11, 11, SPECIES_DROWZEE },
    { 13, 13, SPECIES_DROWZEE },
    { 15, 15, SPECIES_EKANS },
    { 17, 17, SPECIES_SPEAROW },
    { 12, 12, SPECIES_EKANS },
    { 15, 15, SPECIES_DROWZEE },
    { 12, 12, SPECIES_EKANS },
    { 15, 15, SPECIES_DROWZEE },
};

const struct WildPokemonInfo sRoute11_FireRed_LandMonsInfo = { 21, sRoute11_FireRed_LandMons };

const struct WildPokemon sRoute11_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute11_FireRed_WaterMonsInfo = { 2, sRoute11_FireRed_WaterMons };

const struct WildPokemon sRoute11_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute11_FireRed_FishingMonsInfo = { 20, sRoute11_FireRed_FishingMons };

const struct WildPokemon sRoute12_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_ODDISH },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_ODDISH },
    { 23, 23, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_ODDISH },
    { 27, 27, SPECIES_PIDGEY },
    { 23, 23, SPECIES_PIDGEY },
    { 28, 28, SPECIES_GLOOM },
    { 23, 23, SPECIES_PIDGEY },
    { 30, 30, SPECIES_GLOOM },
};

const struct WildPokemonInfo sRoute12_FireRed_LandMonsInfo = { 21, sRoute12_FireRed_LandMons };

const struct WildPokemon sRoute12_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute12_FireRed_WaterMonsInfo = { 2, sRoute12_FireRed_WaterMons };

const struct WildPokemon sRoute12_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute12_FireRed_FishingMonsInfo = { 60, sRoute12_FireRed_FishingMons };

const struct WildPokemon sRoute13_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_ODDISH },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_ODDISH },
    { 27, 27, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_ODDISH },
    { 25, 25, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 28, 28, SPECIES_GLOOM },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 30, 30, SPECIES_GLOOM },
};

const struct WildPokemonInfo sRoute13_FireRed_LandMonsInfo = { 21, sRoute13_FireRed_LandMons };

const struct WildPokemon sRoute13_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute13_FireRed_WaterMonsInfo = { 2, sRoute13_FireRed_WaterMons };

const struct WildPokemon sRoute13_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute13_FireRed_FishingMonsInfo = { 20, sRoute13_FireRed_FishingMons };

const struct WildPokemon sRoute14_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_ODDISH },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_ODDISH },
    { 23, 23, SPECIES_DITTO },
    { 27, 27, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_ODDISH },
    { 30, 30, SPECIES_GLOOM },
    { 23, 23, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 23, 23, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
};

const struct WildPokemonInfo sRoute14_FireRed_LandMonsInfo = { 21, sRoute14_FireRed_LandMons };

const struct WildPokemon sRoute15_FireRed_LandMons[] =
{
    { 24, 24, SPECIES_ODDISH },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_ODDISH },
    { 27, 27, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_ODDISH },
    { 25, 25, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 28, 28, SPECIES_GLOOM },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 30, 30, SPECIES_GLOOM },
};

const struct WildPokemonInfo sRoute15_FireRed_LandMonsInfo = { 21, sRoute15_FireRed_LandMons };

const struct WildPokemon sRoute16_FireRed_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 18, 18, SPECIES_DODUO },
    { 18, 18, SPECIES_RATTATA },
    { 20, 20, SPECIES_RATTATA },
    { 22, 22, SPECIES_SPEAROW },
    { 20, 20, SPECIES_DODUO },
    { 22, 22, SPECIES_RATTATA },
    { 22, 22, SPECIES_DODUO },
    { 18, 18, SPECIES_RATTATA },
    { 23, 23, SPECIES_RATICATE },
    { 18, 18, SPECIES_RATTATA },
    { 25, 25, SPECIES_RATICATE },
};

const struct WildPokemonInfo sRoute16_FireRed_LandMonsInfo = { 21, sRoute16_FireRed_LandMons };

const struct WildPokemon sRoute17_FireRed_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 24, 24, SPECIES_DODUO },
    { 22, 22, SPECIES_SPEAROW },
    { 26, 26, SPECIES_DODUO },
    { 25, 25, SPECIES_RATICATE },
    { 27, 27, SPECIES_RATICATE },
    { 28, 28, SPECIES_DODUO },
    { 29, 29, SPECIES_RATICATE },
    { 22, 22, SPECIES_RATTATA },
    { 25, 25, SPECIES_FEAROW },
    { 22, 22, SPECIES_RATTATA },
    { 27, 27, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute17_FireRed_LandMonsInfo = { 21, sRoute17_FireRed_LandMons };

const struct WildPokemon sRoute18_FireRed_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 24, 24, SPECIES_DODUO },
    { 22, 22, SPECIES_SPEAROW },
    { 26, 26, SPECIES_DODUO },
    { 25, 25, SPECIES_RATICATE },
    { 25, 25, SPECIES_FEAROW },
    { 28, 28, SPECIES_DODUO },
    { 29, 29, SPECIES_RATICATE },
    { 22, 22, SPECIES_RATTATA },
    { 27, 27, SPECIES_FEAROW },
    { 22, 22, SPECIES_RATTATA },
    { 29, 29, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute18_FireRed_LandMonsInfo = { 21, sRoute18_FireRed_LandMons };

const struct WildPokemon sRoute19_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute19_FireRed_WaterMonsInfo = { 2, sRoute19_FireRed_WaterMons };

const struct WildPokemon sRoute19_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute19_FireRed_FishingMonsInfo = { 20, sRoute19_FireRed_FishingMons };

const struct WildPokemon sRoute20_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute20_FireRed_WaterMonsInfo = { 2, sRoute20_FireRed_WaterMons };

const struct WildPokemon sRoute20_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute20_FireRed_FishingMonsInfo = { 20, sRoute20_FireRed_FishingMons };

const struct WildPokemon sRoute21North_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_TANGELA },
    { 23, 23, SPECIES_TANGELA },
    { 24, 24, SPECIES_TANGELA },
    { 21, 21, SPECIES_TANGELA },
    { 25, 25, SPECIES_TANGELA },
    { 20, 20, SPECIES_TANGELA },
    { 19, 19, SPECIES_TANGELA },
    { 26, 26, SPECIES_TANGELA },
    { 18, 18, SPECIES_TANGELA },
    { 27, 27, SPECIES_TANGELA },
    { 17, 17, SPECIES_TANGELA },
    { 28, 28, SPECIES_TANGELA },
};

const struct WildPokemonInfo sRoute21North_FireRed_LandMonsInfo = { 14, sRoute21North_FireRed_LandMons };

const struct WildPokemon sRoute21North_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute21North_FireRed_WaterMonsInfo = { 2, sRoute21North_FireRed_WaterMons };

const struct WildPokemon sRoute21North_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute21North_FireRed_FishingMonsInfo = { 20, sRoute21North_FireRed_FishingMons };

const struct WildPokemon sRoute21South_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_TANGELA },
    { 23, 23, SPECIES_TANGELA },
    { 24, 24, SPECIES_TANGELA },
    { 21, 21, SPECIES_TANGELA },
    { 25, 25, SPECIES_TANGELA },
    { 20, 20, SPECIES_TANGELA },
    { 19, 19, SPECIES_TANGELA },
    { 26, 26, SPECIES_TANGELA },
    { 18, 18, SPECIES_TANGELA },
    { 27, 27, SPECIES_TANGELA },
    { 17, 17, SPECIES_TANGELA },
    { 28, 28, SPECIES_TANGELA },
};

const struct WildPokemonInfo sRoute21South_FireRed_LandMonsInfo = { 14, sRoute21South_FireRed_LandMons };

const struct WildPokemon sRoute21South_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute21South_FireRed_WaterMonsInfo = { 2, sRoute21South_FireRed_WaterMons };

const struct WildPokemon sRoute21South_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute21South_FireRed_FishingMonsInfo = { 20, sRoute21South_FireRed_FishingMons };

const struct WildPokemon sRoute22_FireRed_LandMons[] =
{
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_MANKEY },
    { 4, 4, SPECIES_RATTATA },
    { 4, 4, SPECIES_MANKEY },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_MANKEY },
    { 3, 3, SPECIES_SPEAROW },
    { 5, 5, SPECIES_SPEAROW },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_MANKEY },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_MANKEY },
};

const struct WildPokemonInfo sRoute22_FireRed_LandMonsInfo = { 21, sRoute22_FireRed_LandMons };

const struct WildPokemon sRoute22_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute22_FireRed_WaterMonsInfo = { 2, sRoute22_FireRed_WaterMons };

const struct WildPokemon sRoute22_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute22_FireRed_FishingMonsInfo = { 20, sRoute22_FireRed_FishingMons };

const struct WildPokemon sRoute23_FireRed_LandMons[] =
{
    { 32, 32, SPECIES_MANKEY },
    { 40, 40, SPECIES_FEAROW },
    { 34, 34, SPECIES_MANKEY },
    { 34, 34, SPECIES_SPEAROW },
    { 32, 32, SPECIES_EKANS },
    { 34, 34, SPECIES_EKANS },
    { 42, 42, SPECIES_PRIMEAPE },
    { 44, 44, SPECIES_ARBOK },
    { 32, 32, SPECIES_SPEAROW },
    { 42, 42, SPECIES_FEAROW },
    { 32, 32, SPECIES_SPEAROW },
    { 44, 44, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute23_FireRed_LandMonsInfo = { 21, sRoute23_FireRed_LandMons };

const struct WildPokemon sRoute23_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute23_FireRed_WaterMonsInfo = { 2, sRoute23_FireRed_WaterMons };

const struct WildPokemon sRoute23_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute23_FireRed_FishingMonsInfo = { 20, sRoute23_FireRed_FishingMons };

const struct WildPokemon sRoute24_FireRed_LandMons[] =
{
    { 7, 7, SPECIES_WEEDLE },
    { 7, 7, SPECIES_CATERPIE },
    { 11, 11, SPECIES_PIDGEY },
    { 12, 12, SPECIES_ODDISH },
    { 13, 13, SPECIES_ODDISH },
    { 10, 10, SPECIES_ABRA },
    { 13, 13, SPECIES_PIDGEY },
    { 14, 14, SPECIES_ODDISH },
    { 8, 8, SPECIES_KAKUNA },
    { 8, 8, SPECIES_ABRA },
    { 8, 8, SPECIES_METAPOD },
    { 12, 12, SPECIES_ABRA },
};

const struct WildPokemonInfo sRoute24_FireRed_LandMonsInfo = { 21, sRoute24_FireRed_LandMons };

const struct WildPokemon sRoute24_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute24_FireRed_WaterMonsInfo = { 2, sRoute24_FireRed_WaterMons };

const struct WildPokemon sRoute24_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute24_FireRed_FishingMonsInfo = { 20, sRoute24_FireRed_FishingMons };

const struct WildPokemon sRoute25_FireRed_LandMons[] =
{
    { 8, 8, SPECIES_WEEDLE },
    { 8, 8, SPECIES_CATERPIE },
    { 13, 13, SPECIES_PIDGEY },
    { 14, 14, SPECIES_ODDISH },
    { 13, 13, SPECIES_ODDISH },
    { 11, 11, SPECIES_ABRA },
    { 11, 11, SPECIES_PIDGEY },
    { 12, 12, SPECIES_ODDISH },
    { 9, 9, SPECIES_KAKUNA },
    { 9, 9, SPECIES_ABRA },
    { 9, 9, SPECIES_METAPOD },
    { 13, 13, SPECIES_ABRA },
};

const struct WildPokemonInfo sRoute25_FireRed_LandMonsInfo = { 21, sRoute25_FireRed_LandMons };

const struct WildPokemon sRoute25_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute25_FireRed_WaterMonsInfo = { 2, sRoute25_FireRed_WaterMons };

const struct WildPokemon sRoute25_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute25_FireRed_FishingMonsInfo = { 20, sRoute25_FireRed_FishingMons };

const struct WildPokemon sPalletTown_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sPalletTown_FireRed_WaterMonsInfo = { 1, sPalletTown_FireRed_WaterMons };

const struct WildPokemon sPalletTown_FireRed_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sPalletTown_FireRed_FishingMonsInfo = { 10, sPalletTown_FireRed_FishingMons };

const struct WildPokemon sViridianCity_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sViridianCity_FireRed_WaterMonsInfo = { 1, sViridianCity_FireRed_WaterMons };

const struct WildPokemon sViridianCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sViridianCity_FireRed_FishingMonsInfo = { 10, sViridianCity_FireRed_FishingMons };

const struct WildPokemon sCeruleanCity_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sCeruleanCity_FireRed_WaterMonsInfo = { 1, sCeruleanCity_FireRed_WaterMons };

const struct WildPokemon sCeruleanCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCeruleanCity_FireRed_FishingMonsInfo = { 10, sCeruleanCity_FireRed_FishingMons };

const struct WildPokemon sVermilionCity_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sVermilionCity_FireRed_WaterMonsInfo = { 1, sVermilionCity_FireRed_WaterMons };

const struct WildPokemon sVermilionCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sVermilionCity_FireRed_FishingMonsInfo = { 10, sVermilionCity_FireRed_FishingMons };

const struct WildPokemon sCeladonCity_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_PSYDUCK },
    { 10, 20, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 40, SPECIES_PSYDUCK },
    { 30, 40, SPECIES_KOFFING },
};

const struct WildPokemonInfo sCeladonCity_FireRed_WaterMonsInfo = { 1, sCeladonCity_FireRed_WaterMons };

const struct WildPokemon sCeladonCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 25, 35, SPECIES_MAGIKARP },
    { 30, 40, SPECIES_GRIMER },
};

const struct WildPokemonInfo sCeladonCity_FireRed_FishingMonsInfo = { 10, sCeladonCity_FireRed_FishingMons };

const struct WildPokemon sFuchsiaCity_FireRed_WaterMons[] =
{
    { 20, 25, SPECIES_PSYDUCK },
    { 20, 25, SPECIES_PSYDUCK },
    { 25, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 35, 40, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFuchsiaCity_FireRed_WaterMonsInfo = { 1, sFuchsiaCity_FireRed_WaterMons };

const struct WildPokemon sFuchsiaCity_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFuchsiaCity_FireRed_FishingMonsInfo = { 10, sFuchsiaCity_FireRed_FishingMons };

const struct WildPokemon sCinnabarIsland_FireRed_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sCinnabarIsland_FireRed_WaterMonsInfo = { 1, sCinnabarIsland_FireRed_WaterMons };

const struct WildPokemon sCinnabarIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sCinnabarIsland_FireRed_FishingMonsInfo = { 10, sCinnabarIsland_FireRed_FishingMons };

const struct WildPokemon sOneIsland_FireRed_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIsland_FireRed_WaterMonsInfo = { 1, sOneIsland_FireRed_WaterMons };

const struct WildPokemon sOneIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sOneIsland_FireRed_FishingMonsInfo = { 10, sOneIsland_FireRed_FishingMons };

const struct WildPokemon sFourIsland_FireRed_WaterMons[] =
{
    { 5, 15, SPECIES_WOOPER },
    { 5, 35, SPECIES_PSYDUCK },
    { 15, 25, SPECIES_WOOPER },
    { 15, 25, SPECIES_WOOPER },
    { 15, 25, SPECIES_WOOPER },
};

const struct WildPokemonInfo sFourIsland_FireRed_WaterMonsInfo = { 2, sFourIsland_FireRed_WaterMons };

const struct WildPokemon sFourIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_PSYDUCK },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFourIsland_FireRed_FishingMonsInfo = { 20, sFourIsland_FireRed_FishingMons };

const struct WildPokemon sFiveIsland_FireRed_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIsland_FireRed_WaterMonsInfo = { 1, sFiveIsland_FireRed_WaterMons };

const struct WildPokemon sFiveIsland_FireRed_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_HORSEA },
    { 15, 25, SPECIES_SHELLDER },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SEADRA },
    { 25, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sFiveIsland_FireRed_FishingMonsInfo = { 10, sFiveIsland_FireRed_FishingMons };

const struct WildPokemon sSixIslandAlteringCave_FireRed_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 16, 16, SPECIES_ZUBAT },
    { 6, 6, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
};

const struct WildPokemonInfo sSixIslandAlteringCave_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_2_FireRed_LandMons[] =
{
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 13, 13, SPECIES_MAREEP },
    { 3, 3, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
};

const struct WildPokemonInfo sSixIslandAlteringCave_2_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_2_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_3_FireRed_LandMons[] =
{
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 22, 22, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 29, 29, SPECIES_PINECO },
    { 19, 19, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
};

const struct WildPokemonInfo sSixIslandAlteringCave_3_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_3_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_4_FireRed_LandMons[] =
{
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 22, 22, SPECIES_HOUNDOUR },
    { 12, 12, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
};

const struct WildPokemonInfo sSixIslandAlteringCave_4_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_4_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_5_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_TEDDIURSA },
    { 24, 24, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
    { 22, 22, SPECIES_TEDDIURSA },
    { 24, 24, SPECIES_TEDDIURSA },
    { 28, 28, SPECIES_TEDDIURSA },
    { 18, 18, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
};

const struct WildPokemonInfo sSixIslandAlteringCave_5_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_5_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_6_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 28, 28, SPECIES_AIPOM },
    { 18, 18, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
};

const struct WildPokemonInfo sSixIslandAlteringCave_6_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_6_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_7_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 28, 28, SPECIES_SHUCKLE },
    { 18, 18, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo sSixIslandAlteringCave_7_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_7_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_8_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 28, 28, SPECIES_STANTLER },
    { 18, 18, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
};

const struct WildPokemonInfo sSixIslandAlteringCave_8_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_8_FireRed_LandMons };

const struct WildPokemon sSixIslandAlteringCave_9_FireRed_LandMons[] =
{
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 28, 28, SPECIES_SMEARGLE },
    { 18, 18, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo sSixIslandAlteringCave_9_FireRed_LandMonsInfo = { 5, sSixIslandAlteringCave_9_FireRed_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsMoneanChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsMoneanChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsMoneanChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsLiptooChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsLiptooChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsLiptooChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsWeepthChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsWeepthChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsWeepthChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsDilfordChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsDilfordChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsDilfordChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsScufibChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsScufibChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsScufibChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsRixyChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsRixyChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsRixyChamber_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandTanobyRuinsViapoisChamber_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
    { 25, 25, SPECIES_UNOWN },
};

const struct WildPokemonInfo sSevenIslandTanobyRuinsViapoisChamber_LeafGreen_LandMonsInfo = { 7, sSevenIslandTanobyRuinsViapoisChamber_LeafGreen_LandMons };

const struct WildPokemon sViridianForest_LeafGreen_LandMons[] =
{
    { 4, 4, SPECIES_CATERPIE },
    { 4, 4, SPECIES_WEEDLE },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_WEEDLE },
    { 3, 3, SPECIES_CATERPIE },
    { 3, 3, SPECIES_WEEDLE },
    { 5, 5, SPECIES_KAKUNA },
    { 5, 5, SPECIES_METAPOD },
    { 4, 4, SPECIES_METAPOD },
    { 3, 3, SPECIES_PIKACHU },
    { 6, 6, SPECIES_METAPOD },
    { 5, 5, SPECIES_PIKACHU },
};

const struct WildPokemonInfo sViridianForest_LeafGreen_LandMonsInfo = { 14, sViridianForest_LeafGreen_LandMons };

const struct WildPokemon sMtMoon1F_LeafGreen_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 7, 7, SPECIES_GEODUDE },
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 8, 8, SPECIES_GEODUDE },
    { 9, 9, SPECIES_GEODUDE },
    { 8, 8, SPECIES_PARAS },
    { 7, 7, SPECIES_ZUBAT },
    { 7, 7, SPECIES_ZUBAT },
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_CLEFAIRY },
};

const struct WildPokemonInfo sMtMoon1F_LeafGreen_LandMonsInfo = { 7, sMtMoon1F_LeafGreen_LandMons };

const struct WildPokemon sMtMoonB1F_LeafGreen_LandMons[] =
{
    { 7, 7, SPECIES_PARAS },
    { 8, 8, SPECIES_PARAS },
    { 5, 5, SPECIES_PARAS },
    { 6, 6, SPECIES_PARAS },
    { 9, 9, SPECIES_PARAS },
    { 10, 10, SPECIES_PARAS },
    { 7, 7, SPECIES_PARAS },
    { 8, 8, SPECIES_PARAS },
    { 5, 5, SPECIES_PARAS },
    { 6, 6, SPECIES_PARAS },
    { 9, 9, SPECIES_PARAS },
    { 10, 10, SPECIES_PARAS },
};

const struct WildPokemonInfo sMtMoonB1F_LeafGreen_LandMonsInfo = { 5, sMtMoonB1F_LeafGreen_LandMons };

const struct WildPokemon sMtMoonB2F_LeafGreen_LandMons[] =
{
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_GEODUDE },
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 10, 10, SPECIES_GEODUDE },
    { 10, 10, SPECIES_PARAS },
    { 12, 12, SPECIES_PARAS },
    { 10, 10, SPECIES_CLEFAIRY },
    { 11, 11, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ZUBAT },
    { 12, 12, SPECIES_CLEFAIRY },
};

const struct WildPokemonInfo sMtMoonB2F_LeafGreen_LandMonsInfo = { 7, sMtMoonB2F_LeafGreen_LandMons };

const struct WildPokemon sSSAnneExterior_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sSSAnneExterior_LeafGreen_WaterMonsInfo = { 1, sSSAnneExterior_LeafGreen_WaterMons };

const struct WildPokemon sSSAnneExterior_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSSAnneExterior_LeafGreen_FishingMonsInfo = { 10, sSSAnneExterior_LeafGreen_FishingMons };

const struct WildPokemon sDiglettsCaveB1F_LeafGreen_LandMons[] =
{
    { 18, 18, SPECIES_DIGLETT },
    { 19, 19, SPECIES_DIGLETT },
    { 17, 17, SPECIES_DIGLETT },
    { 15, 15, SPECIES_DIGLETT },
    { 16, 16, SPECIES_DIGLETT },
    { 20, 20, SPECIES_DIGLETT },
    { 21, 21, SPECIES_DIGLETT },
    { 22, 22, SPECIES_DIGLETT },
    { 17, 17, SPECIES_DIGLETT },
    { 29, 29, SPECIES_DUGTRIO },
    { 17, 17, SPECIES_DIGLETT },
    { 31, 31, SPECIES_DUGTRIO },
};

const struct WildPokemonInfo sDiglettsCaveB1F_LeafGreen_LandMonsInfo = { 5, sDiglettsCaveB1F_LeafGreen_LandMons };

const struct WildPokemon sVictoryRoad1F_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 40, 40, SPECIES_ONIX },
    { 43, 43, SPECIES_ONIX },
    { 46, 46, SPECIES_ONIX },
    { 32, 32, SPECIES_ZUBAT },
    { 44, 44, SPECIES_SANDSLASH },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_MAROWAK },
    { 44, 44, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad1F_LeafGreen_LandMonsInfo = { 7, sVictoryRoad1F_LeafGreen_LandMons };

const struct WildPokemon sVictoryRoad2F_LeafGreen_LandMons[] =
{
    { 34, 34, SPECIES_MACHOP },
    { 34, 34, SPECIES_GEODUDE },
    { 42, 42, SPECIES_PRIMEAPE },
    { 45, 45, SPECIES_ONIX },
    { 48, 48, SPECIES_ONIX },
    { 34, 34, SPECIES_ZUBAT },
    { 46, 46, SPECIES_SANDSLASH },
    { 46, 46, SPECIES_GOLBAT },
    { 46, 46, SPECIES_MAROWAK },
    { 46, 46, SPECIES_MACHOKE },
    { 48, 48, SPECIES_MACHOKE },
    { 48, 48, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad2F_LeafGreen_LandMonsInfo = { 7, sVictoryRoad2F_LeafGreen_LandMons };

const struct WildPokemon sVictoryRoad3F_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 40, 40, SPECIES_ONIX },
    { 43, 43, SPECIES_ONIX },
    { 46, 46, SPECIES_ONIX },
    { 32, 32, SPECIES_ZUBAT },
    { 44, 44, SPECIES_SANDSLASH },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_MAROWAK },
    { 44, 44, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MACHOKE },
    { 46, 46, SPECIES_MAROWAK },
};

const struct WildPokemonInfo sVictoryRoad3F_LeafGreen_LandMonsInfo = { 7, sVictoryRoad3F_LeafGreen_LandMons };

const struct WildPokemon sPokemonMansion1F_LeafGreen_LandMons[] =
{
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_GRIMER },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_VULPIX },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_MUK },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion1F_LeafGreen_LandMonsInfo = { 7, sPokemonMansion1F_LeafGreen_LandMons };

const struct WildPokemon sPokemonMansion2F_LeafGreen_LandMons[] =
{
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_GRIMER },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_VULPIX },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_MUK },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion2F_LeafGreen_LandMonsInfo = { 7, sPokemonMansion2F_LeafGreen_LandMons };

const struct WildPokemon sPokemonMansion3F_LeafGreen_LandMons[] =
{
    { 28, 28, SPECIES_GRIMER },
    { 32, 32, SPECIES_RATICATE },
    { 30, 30, SPECIES_GRIMER },
    { 36, 36, SPECIES_RATICATE },
    { 30, 30, SPECIES_VULPIX },
    { 28, 28, SPECIES_RATTATA },
    { 28, 28, SPECIES_KOFFING },
    { 32, 32, SPECIES_MUK },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansion3F_LeafGreen_LandMonsInfo = { 7, sPokemonMansion3F_LeafGreen_LandMons };

const struct WildPokemon sPokemonMansionB1F_LeafGreen_LandMons[] =
{
    { 28, 28, SPECIES_GRIMER },
    { 34, 34, SPECIES_RATICATE },
    { 30, 30, SPECIES_GRIMER },
    { 30, 30, SPECIES_DITTO },
    { 30, 30, SPECIES_VULPIX },
    { 38, 38, SPECIES_RATICATE },
    { 28, 28, SPECIES_KOFFING },
    { 34, 34, SPECIES_MUK },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
    { 32, 32, SPECIES_VULPIX },
    { 26, 26, SPECIES_RATTATA },
};

const struct WildPokemonInfo sPokemonMansionB1F_LeafGreen_LandMonsInfo = { 5, sPokemonMansionB1F_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneCenter_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_RHYHORN },
    { 22, 22, SPECIES_NIDORAN_F },
    { 24, 24, SPECIES_EXEGGCUTE },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 22, 22, SPECIES_VENONAT },
    { 31, 31, SPECIES_NIDORINA },
    { 31, 31, SPECIES_NIDORINO },
    { 30, 30, SPECIES_PARASECT },
    { 22, 22, SPECIES_VENONAT },
    { 23, 23, SPECIES_PINSIR },
    { 22, 22, SPECIES_VENONAT },
    { 23, 23, SPECIES_CHANSEY },
};

const struct WildPokemonInfo sSafariZoneCenter_LeafGreen_LandMonsInfo = { 21, sSafariZoneCenter_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneCenter_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSafariZoneCenter_LeafGreen_WaterMonsInfo = { 2, sSafariZoneCenter_LeafGreen_WaterMons };

const struct WildPokemon sSafariZoneCenter_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneCenter_LeafGreen_FishingMonsInfo = { 20, sSafariZoneCenter_LeafGreen_FishingMons };

const struct WildPokemon sSafariZoneEast_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_NIDORAN_F },
    { 26, 26, SPECIES_DODUO },
    { 23, 23, SPECIES_EXEGGCUTE },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 22, 22, SPECIES_PARAS },
    { 33, 33, SPECIES_NIDORINA },
    { 24, 24, SPECIES_NIDORAN_M },
    { 25, 25, SPECIES_PARASECT },
    { 22, 22, SPECIES_PARAS },
    { 25, 25, SPECIES_KANGASKHAN },
    { 22, 22, SPECIES_PARAS },
    { 28, 28, SPECIES_PINSIR },
};

const struct WildPokemonInfo sSafariZoneEast_LeafGreen_LandMonsInfo = { 21, sSafariZoneEast_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneEast_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSafariZoneEast_LeafGreen_WaterMonsInfo = { 2, sSafariZoneEast_LeafGreen_WaterMons };

const struct WildPokemon sSafariZoneEast_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneEast_LeafGreen_FishingMonsInfo = { 20, sSafariZoneEast_LeafGreen_FishingMons };

const struct WildPokemon sSafariZoneNorth_LeafGreen_LandMons[] =
{
    { 26, 26, SPECIES_RHYHORN },
    { 30, 30, SPECIES_NIDORAN_F },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 27, 27, SPECIES_EXEGGCUTE },
    { 23, 23, SPECIES_PARAS },
    { 30, 30, SPECIES_NIDORINA },
    { 30, 30, SPECIES_NIDORINO },
    { 32, 32, SPECIES_VENOMOTH },
    { 23, 23, SPECIES_PARAS },
    { 26, 26, SPECIES_CHANSEY },
    { 23, 23, SPECIES_PARAS },
    { 28, 28, SPECIES_TAUROS },
};

const struct WildPokemonInfo sSafariZoneNorth_LeafGreen_LandMonsInfo = { 21, sSafariZoneNorth_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneNorth_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSafariZoneNorth_LeafGreen_WaterMonsInfo = { 2, sSafariZoneNorth_LeafGreen_WaterMons };

const struct WildPokemon sSafariZoneNorth_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneNorth_LeafGreen_FishingMonsInfo = { 20, sSafariZoneNorth_LeafGreen_FishingMons };

const struct WildPokemon sSafariZoneWest_LeafGreen_LandMons[] =
{
    { 26, 26, SPECIES_DODUO },
    { 22, 22, SPECIES_NIDORAN_F },
    { 25, 25, SPECIES_EXEGGCUTE },
    { 27, 27, SPECIES_EXEGGCUTE },
    { 23, 23, SPECIES_VENONAT },
    { 30, 30, SPECIES_NIDORINA },
    { 30, 30, SPECIES_NIDORAN_M },
    { 32, 32, SPECIES_VENOMOTH },
    { 23, 23, SPECIES_VENONAT },
    { 25, 25, SPECIES_TAUROS },
    { 23, 23, SPECIES_VENONAT },
    { 28, 28, SPECIES_KANGASKHAN },
};

const struct WildPokemonInfo sSafariZoneWest_LeafGreen_LandMonsInfo = { 21, sSafariZoneWest_LeafGreen_LandMons };

const struct WildPokemon sSafariZoneWest_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSafariZoneWest_LeafGreen_WaterMonsInfo = { 2, sSafariZoneWest_LeafGreen_WaterMons };

const struct WildPokemon sSafariZoneWest_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_DRATINI },
    { 15, 35, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_DRAGONAIR },
};

const struct WildPokemonInfo sSafariZoneWest_LeafGreen_FishingMonsInfo = { 20, sSafariZoneWest_LeafGreen_FishingMons };

const struct WildPokemon sCeruleanCave1F_LeafGreen_LandMons[] =
{
    { 49, 49, SPECIES_MAGNETON },
    { 49, 49, SPECIES_PARASECT },
    { 46, 46, SPECIES_GOLBAT },
    { 46, 46, SPECIES_MACHOKE },
    { 52, 52, SPECIES_PRIMEAPE },
    { 52, 52, SPECIES_DITTO },
    { 58, 58, SPECIES_ELECTRODE },
    { 58, 58, SPECIES_PARASECT },
    { 55, 55, SPECIES_GOLBAT },
    { 55, 55, SPECIES_WOBBUFFET },
    { 61, 61, SPECIES_PRIMEAPE },
    { 61, 61, SPECIES_DITTO },
};

const struct WildPokemonInfo sCeruleanCave1F_LeafGreen_LandMonsInfo = { 7, sCeruleanCave1F_LeafGreen_LandMons };

const struct WildPokemon sCeruleanCave1F_LeafGreen_WaterMons[] =
{
    { 30, 40, SPECIES_SLOWPOKE },
    { 40, 50, SPECIES_SLOWBRO },
    { 45, 55, SPECIES_SLOWBRO },
    { 40, 50, SPECIES_SLOWPOKE },
    { 40, 50, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCeruleanCave1F_LeafGreen_WaterMonsInfo = { 2, sCeruleanCave1F_LeafGreen_WaterMons };

const struct WildPokemon sCeruleanCave1F_LeafGreen_RockSmashMons[] =
{
    { 30, 40, SPECIES_GEODUDE },
    { 40, 50, SPECIES_GRAVELER },
    { 45, 55, SPECIES_GRAVELER },
    { 40, 50, SPECIES_GEODUDE },
    { 40, 50, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCave1F_LeafGreen_RockSmashMonsInfo = { 50, sCeruleanCave1F_LeafGreen_RockSmashMons };

const struct WildPokemon sCeruleanCave1F_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCeruleanCave1F_LeafGreen_FishingMonsInfo = { 20, sCeruleanCave1F_LeafGreen_FishingMons };

const struct WildPokemon sCeruleanCave2F_LeafGreen_LandMons[] =
{
    { 49, 49, SPECIES_GOLBAT },
    { 49, 49, SPECIES_MACHOKE },
    { 52, 52, SPECIES_MAGNETON },
    { 52, 52, SPECIES_PARASECT },
    { 55, 55, SPECIES_KADABRA },
    { 55, 55, SPECIES_DITTO },
    { 58, 58, SPECIES_GOLBAT },
    { 58, 58, SPECIES_WOBBUFFET },
    { 61, 61, SPECIES_ELECTRODE },
    { 61, 61, SPECIES_PARASECT },
    { 64, 64, SPECIES_KADABRA },
    { 64, 64, SPECIES_DITTO },
};

const struct WildPokemonInfo sCeruleanCave2F_LeafGreen_LandMonsInfo = { 7, sCeruleanCave2F_LeafGreen_LandMons };

const struct WildPokemon sCeruleanCave2F_LeafGreen_RockSmashMons[] =
{
    { 35, 45, SPECIES_GEODUDE },
    { 45, 55, SPECIES_GRAVELER },
    { 50, 60, SPECIES_GRAVELER },
    { 45, 55, SPECIES_GEODUDE },
    { 45, 55, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCave2F_LeafGreen_RockSmashMonsInfo = { 50, sCeruleanCave2F_LeafGreen_RockSmashMons };

const struct WildPokemon sCeruleanCaveB1F_LeafGreen_LandMons[] =
{
    { 58, 58, SPECIES_KADABRA },
    { 58, 58, SPECIES_DITTO },
    { 55, 55, SPECIES_MAGNETON },
    { 55, 55, SPECIES_PARASECT },
    { 52, 52, SPECIES_GOLBAT },
    { 52, 52, SPECIES_MACHOKE },
    { 67, 67, SPECIES_KADABRA },
    { 67, 67, SPECIES_DITTO },
    { 64, 64, SPECIES_ELECTRODE },
    { 64, 64, SPECIES_PARASECT },
    { 61, 61, SPECIES_GOLBAT },
    { 61, 61, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo sCeruleanCaveB1F_LeafGreen_LandMonsInfo = { 7, sCeruleanCaveB1F_LeafGreen_LandMons };

const struct WildPokemon sCeruleanCaveB1F_LeafGreen_WaterMons[] =
{
    { 40, 50, SPECIES_SLOWPOKE },
    { 50, 60, SPECIES_SLOWBRO },
    { 55, 65, SPECIES_SLOWBRO },
    { 50, 60, SPECIES_SLOWPOKE },
    { 50, 60, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCeruleanCaveB1F_LeafGreen_WaterMonsInfo = { 2, sCeruleanCaveB1F_LeafGreen_WaterMons };

const struct WildPokemon sCeruleanCaveB1F_LeafGreen_RockSmashMons[] =
{
    { 40, 50, SPECIES_GEODUDE },
    { 50, 60, SPECIES_GRAVELER },
    { 55, 65, SPECIES_GRAVELER },
    { 50, 60, SPECIES_GEODUDE },
    { 50, 60, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sCeruleanCaveB1F_LeafGreen_RockSmashMonsInfo = { 50, sCeruleanCaveB1F_LeafGreen_RockSmashMons };

const struct WildPokemon sCeruleanCaveB1F_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sCeruleanCaveB1F_LeafGreen_FishingMonsInfo = { 20, sCeruleanCaveB1F_LeafGreen_FishingMons };

const struct WildPokemon sRockTunnel1F_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_ZUBAT },
    { 16, 16, SPECIES_GEODUDE },
    { 16, 16, SPECIES_MANKEY },
    { 17, 17, SPECIES_GEODUDE },
    { 16, 16, SPECIES_ZUBAT },
    { 16, 16, SPECIES_MACHOP },
    { 17, 17, SPECIES_MANKEY },
    { 17, 17, SPECIES_MACHOP },
    { 15, 15, SPECIES_GEODUDE },
    { 13, 13, SPECIES_ONIX },
    { 15, 15, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ONIX },
};

const struct WildPokemonInfo sRockTunnel1F_LeafGreen_LandMonsInfo = { 7, sRockTunnel1F_LeafGreen_LandMons };

const struct WildPokemon sRockTunnelB1F_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_ZUBAT },
    { 17, 17, SPECIES_GEODUDE },
    { 17, 17, SPECIES_MANKEY },
    { 16, 16, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ZUBAT },
    { 17, 17, SPECIES_MACHOP },
    { 16, 16, SPECIES_MANKEY },
    { 13, 13, SPECIES_ONIX },
    { 15, 15, SPECIES_GEODUDE },
    { 15, 15, SPECIES_ONIX },
    { 15, 15, SPECIES_GEODUDE },
    { 17, 17, SPECIES_ONIX },
};

const struct WildPokemonInfo sRockTunnelB1F_LeafGreen_LandMonsInfo = { 7, sRockTunnelB1F_LeafGreen_LandMons };

const struct WildPokemon sRockTunnelB1F_LeafGreen_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sRockTunnelB1F_LeafGreen_RockSmashMonsInfo = { 50, sRockTunnelB1F_LeafGreen_RockSmashMons };

const struct WildPokemon sSeafoamIslands1F_LeafGreen_LandMons[] =
{
    { 27, 27, SPECIES_SLOWPOKE },
    { 29, 29, SPECIES_SLOWPOKE },
    { 31, 31, SPECIES_SLOWPOKE },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 28, 28, SPECIES_GOLBAT },
    { 33, 33, SPECIES_SLOWPOKE },
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SLOWPOKE },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslands1F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslands1F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB1F_LeafGreen_LandMons[] =
{
    { 29, 29, SPECIES_SLOWPOKE },
    { 31, 31, SPECIES_SLOWPOKE },
    { 28, 28, SPECIES_SEEL },
    { 22, 22, SPECIES_ZUBAT },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 28, 28, SPECIES_GOLBAT },
    { 33, 33, SPECIES_SLOWBRO },
    { 26, 26, SPECIES_ZUBAT },
    { 35, 35, SPECIES_SLOWBRO },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB1F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslandsB1F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB2F_LeafGreen_LandMons[] =
{
    { 30, 30, SPECIES_SLOWPOKE },
    { 32, 32, SPECIES_SLOWPOKE },
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 22, 22, SPECIES_ZUBAT },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SLOWBRO },
    { 32, 32, SPECIES_SLOWBRO },
    { 28, 28, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SLOWBRO },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB2F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslandsB2F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB3F_LeafGreen_LandMons[] =
{
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 32, 32, SPECIES_SLOWPOKE },
    { 30, 30, SPECIES_SLOWPOKE },
    { 32, 32, SPECIES_SLOWBRO },
    { 24, 24, SPECIES_ZUBAT },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SLOWBRO },
    { 32, 32, SPECIES_DEWGONG },
    { 28, 28, SPECIES_GOLBAT },
    { 34, 34, SPECIES_DEWGONG },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslandsB3F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB3F_LeafGreen_WaterMons[] =
{
    { 25, 35, SPECIES_SEEL },
    { 25, 30, SPECIES_KRABBY },
    { 35, 40, SPECIES_DEWGONG },
    { 30, 40, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_LeafGreen_WaterMonsInfo = { 2, sSeafoamIslandsB3F_LeafGreen_WaterMons };

const struct WildPokemon sSeafoamIslandsB3F_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 20, 30, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sSeafoamIslandsB3F_LeafGreen_FishingMonsInfo = { 20, sSeafoamIslandsB3F_LeafGreen_FishingMons };

const struct WildPokemon sSeafoamIslandsB4F_LeafGreen_LandMons[] =
{
    { 30, 30, SPECIES_SEEL },
    { 32, 32, SPECIES_SEEL },
    { 32, 32, SPECIES_SLOWPOKE },
    { 34, 34, SPECIES_SEEL },
    { 32, 32, SPECIES_SLOWBRO },
    { 26, 26, SPECIES_GOLBAT },
    { 34, 34, SPECIES_DEWGONG },
    { 34, 34, SPECIES_SLOWBRO },
    { 36, 36, SPECIES_DEWGONG },
    { 28, 28, SPECIES_GOLBAT },
    { 36, 36, SPECIES_DEWGONG },
    { 30, 30, SPECIES_GOLBAT },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_LeafGreen_LandMonsInfo = { 7, sSeafoamIslandsB4F_LeafGreen_LandMons };

const struct WildPokemon sSeafoamIslandsB4F_LeafGreen_WaterMons[] =
{
    { 25, 35, SPECIES_SEEL },
    { 25, 30, SPECIES_KRABBY },
    { 35, 40, SPECIES_DEWGONG },
    { 30, 40, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_LeafGreen_WaterMonsInfo = { 2, sSeafoamIslandsB4F_LeafGreen_WaterMons };

const struct WildPokemon sSeafoamIslandsB4F_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 20, 30, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_GYARADOS },
};

const struct WildPokemonInfo sSeafoamIslandsB4F_LeafGreen_FishingMonsInfo = { 20, sSeafoamIslandsB4F_LeafGreen_FishingMons };

const struct WildPokemon sPokemonTower3F_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower3F_LeafGreen_LandMonsInfo = { 2, sPokemonTower3F_LeafGreen_LandMons };

const struct WildPokemon sPokemonTower4F_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
};

const struct WildPokemonInfo sPokemonTower4F_LeafGreen_LandMonsInfo = { 4, sPokemonTower4F_LeafGreen_LandMons };

const struct WildPokemon sPokemonTower5F_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_GASTLY },
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 13, 13, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 20, 20, SPECIES_HAUNTER },
    { 15, 15, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 17, 17, SPECIES_CUBONE },
    { 17, 17, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
};

const struct WildPokemonInfo sPokemonTower5F_LeafGreen_LandMonsInfo = { 6, sPokemonTower5F_LeafGreen_LandMons };

const struct WildPokemon sPokemonTower6F_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 14, 14, SPECIES_GASTLY },
    { 15, 15, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 21, 21, SPECIES_HAUNTER },
    { 17, 17, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 19, 19, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower6F_LeafGreen_LandMonsInfo = { 8, sPokemonTower6F_LeafGreen_LandMons };

const struct WildPokemon sPokemonTower7F_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_GASTLY },
    { 17, 17, SPECIES_GASTLY },
    { 18, 18, SPECIES_GASTLY },
    { 15, 15, SPECIES_GASTLY },
    { 19, 19, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
    { 17, 17, SPECIES_CUBONE },
    { 19, 19, SPECIES_CUBONE },
    { 18, 18, SPECIES_GASTLY },
    { 23, 23, SPECIES_HAUNTER },
    { 18, 18, SPECIES_GASTLY },
    { 25, 25, SPECIES_HAUNTER },
};

const struct WildPokemonInfo sPokemonTower7F_LeafGreen_LandMonsInfo = { 10, sPokemonTower7F_LeafGreen_LandMons };

const struct WildPokemon sPowerPlant_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_PIKACHU },
    { 24, 24, SPECIES_PIKACHU },
    { 31, 31, SPECIES_MAGNETON },
    { 34, 34, SPECIES_MAGNETON },
    { 26, 26, SPECIES_PIKACHU },
    { 31, 31, SPECIES_MAGNETON },
    { 26, 26, SPECIES_PIKACHU },
    { 34, 34, SPECIES_MAGNETON },
};

const struct WildPokemonInfo sPowerPlant_LeafGreen_LandMonsInfo = { 7, sPowerPlant_LeafGreen_LandMons };

const struct WildPokemon sMtEmberExterior_LeafGreen_LandMons[] =
{
    { 30, 30, SPECIES_PONYTA },
    { 38, 38, SPECIES_FEAROW },
    { 33, 33, SPECIES_PONYTA },
    { 32, 32, SPECIES_SPEAROW },
    { 35, 35, SPECIES_MACHOP },
    { 33, 33, SPECIES_GEODUDE },
    { 36, 36, SPECIES_PONYTA },
    { 40, 40, SPECIES_FEAROW },
    { 38, 38, SPECIES_MAGMAR },
    { 39, 39, SPECIES_RAPIDASH },
    { 40, 40, SPECIES_MAGMAR },
    { 42, 42, SPECIES_RAPIDASH },
};

const struct WildPokemonInfo sMtEmberExterior_LeafGreen_LandMonsInfo = { 21, sMtEmberExterior_LeafGreen_LandMons };

const struct WildPokemon sMtEmberExterior_LeafGreen_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sMtEmberExterior_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberExterior_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberSummitPath1F_LeafGreen_LandMons[] =
{
    { 33, 33, SPECIES_GEODUDE },
    { 35, 35, SPECIES_MACHOP },
    { 29, 29, SPECIES_GEODUDE },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MACHOP },
    { 33, 33, SPECIES_MACHOP },
    { 35, 35, SPECIES_GEODUDE },
    { 37, 37, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
};

const struct WildPokemonInfo sMtEmberSummitPath1F_LeafGreen_LandMonsInfo = { 7, sMtEmberSummitPath1F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberSummitPath2F_LeafGreen_LandMons[] =
{
    { 34, 34, SPECIES_GEODUDE },
    { 36, 36, SPECIES_MACHOP },
    { 30, 30, SPECIES_GEODUDE },
    { 32, 32, SPECIES_GEODUDE },
    { 32, 32, SPECIES_MACHOP },
    { 34, 34, SPECIES_MACHOP },
    { 38, 38, SPECIES_MACHOKE },
    { 38, 38, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_MACHOKE },
};

const struct WildPokemonInfo sMtEmberSummitPath2F_LeafGreen_LandMonsInfo = { 7, sMtEmberSummitPath2F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberSummitPath2F_LeafGreen_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sMtEmberSummitPath2F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberSummitPath2F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberSummitPath3F_LeafGreen_LandMons[] =
{
    { 33, 33, SPECIES_GEODUDE },
    { 35, 35, SPECIES_MACHOP },
    { 29, 29, SPECIES_GEODUDE },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MACHOP },
    { 33, 33, SPECIES_MACHOP },
    { 35, 35, SPECIES_GEODUDE },
    { 37, 37, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
    { 37, 37, SPECIES_GEODUDE },
    { 39, 39, SPECIES_MACHOP },
};

const struct WildPokemonInfo sMtEmberSummitPath3F_LeafGreen_LandMonsInfo = { 7, sMtEmberSummitPath3F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPath1F_LeafGreen_LandMons[] =
{
    { 36, 36, SPECIES_GEODUDE },
    { 38, 38, SPECIES_MACHOP },
    { 32, 32, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 34, 34, SPECIES_MACHOP },
    { 36, 36, SPECIES_MACHOP },
    { 38, 38, SPECIES_GEODUDE },
    { 40, 40, SPECIES_MACHOKE },
    { 40, 40, SPECIES_GEODUDE },
    { 42, 42, SPECIES_MACHOKE },
    { 40, 40, SPECIES_GEODUDE },
    { 42, 42, SPECIES_MACHOKE },
};

const struct WildPokemonInfo sMtEmberRubyPath1F_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPath1F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPath1F_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPath1F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPath1F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB1F_LeafGreen_LandMons[] =
{
    { 38, 38, SPECIES_GEODUDE },
    { 36, 36, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 40, 40, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 28, 28, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB1F_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB1F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB1F_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB1F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB1F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB2F_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GEODUDE },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 32, 32, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB2F_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB2F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB2F_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB2F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB2F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB3F_LeafGreen_LandMons[] =
{
    { 26, 26, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 32, 32, SPECIES_SLUGMA },
    { 24, 24, SPECIES_SLUGMA },
    { 22, 22, SPECIES_SLUGMA },
    { 20, 20, SPECIES_SLUGMA },
    { 34, 34, SPECIES_SLUGMA },
    { 36, 36, SPECIES_SLUGMA },
    { 18, 18, SPECIES_SLUGMA },
    { 36, 36, SPECIES_SLUGMA },
    { 18, 18, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB3F_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB3F_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB3F_LeafGreen_RockSmashMons[] =
{
    { 15, 25, SPECIES_SLUGMA },
    { 25, 35, SPECIES_SLUGMA },
    { 40, 45, SPECIES_MAGCARGO },
    { 35, 45, SPECIES_MAGCARGO },
    { 25, 35, SPECIES_MAGCARGO },
};

const struct WildPokemonInfo sMtEmberRubyPathB3F_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB3F_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB1FStairs_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GEODUDE },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 28, 28, SPECIES_SLUGMA },
    { 30, 30, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 32, 32, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
    { 44, 44, SPECIES_GEODUDE },
    { 22, 22, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB1FStairs_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB1FStairs_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB1FStairs_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB1FStairs_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB1FStairs_LeafGreen_RockSmashMons };

const struct WildPokemon sMtEmberRubyPathB2FStairs_LeafGreen_LandMons[] =
{
    { 38, 38, SPECIES_GEODUDE },
    { 36, 36, SPECIES_GEODUDE },
    { 34, 34, SPECIES_GEODUDE },
    { 40, 40, SPECIES_GEODUDE },
    { 24, 24, SPECIES_SLUGMA },
    { 26, 26, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 28, 28, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
    { 42, 42, SPECIES_GEODUDE },
    { 30, 30, SPECIES_SLUGMA },
};

const struct WildPokemonInfo sMtEmberRubyPathB2FStairs_LeafGreen_LandMonsInfo = { 7, sMtEmberRubyPathB2FStairs_LeafGreen_LandMons };

const struct WildPokemon sMtEmberRubyPathB2FStairs_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sMtEmberRubyPathB2FStairs_LeafGreen_RockSmashMonsInfo = { 50, sMtEmberRubyPathB2FStairs_LeafGreen_RockSmashMons };

const struct WildPokemon sThreeIslandBerryForest_LeafGreen_LandMons[] =
{
    { 37, 37, SPECIES_PIDGEOTTO },
    { 35, 35, SPECIES_WEEPINBELL },
    { 32, 32, SPECIES_PIDGEY },
    { 30, 30, SPECIES_BELLSPROUT },
    { 34, 34, SPECIES_VENONAT },
    { 34, 34, SPECIES_DROWZEE },
    { 35, 35, SPECIES_EXEGGCUTE },
    { 31, 31, SPECIES_SLOWPOKE },
    { 37, 37, SPECIES_VENOMOTH },
    { 37, 37, SPECIES_HYPNO },
    { 40, 40, SPECIES_VENOMOTH },
    { 40, 40, SPECIES_HYPNO },
};

const struct WildPokemonInfo sThreeIslandBerryForest_LeafGreen_LandMonsInfo = { 21, sThreeIslandBerryForest_LeafGreen_LandMons };

const struct WildPokemon sThreeIslandBerryForest_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_SLOWPOKE },
    { 20, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWBRO },
    { 35, 40, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo sThreeIslandBerryForest_LeafGreen_WaterMonsInfo = { 2, sThreeIslandBerryForest_LeafGreen_WaterMons };

const struct WildPokemon sThreeIslandBerryForest_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sThreeIslandBerryForest_LeafGreen_FishingMonsInfo = { 20, sThreeIslandBerryForest_LeafGreen_FishingMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_LeafGreen_LandMons[] =
{
    { 43, 43, SPECIES_SEEL },
    { 45, 45, SPECIES_GOLBAT },
    { 45, 45, SPECIES_SEEL },
    { 47, 47, SPECIES_SEEL },
    { 40, 40, SPECIES_ZUBAT },
    { 49, 49, SPECIES_DEWGONG },
    { 51, 51, SPECIES_DEWGONG },
    { 41, 41, SPECIES_SLOWPOKE },
    { 48, 48, SPECIES_GOLBAT },
    { 53, 53, SPECIES_DEWGONG },
    { 48, 48, SPECIES_GOLBAT },
    { 53, 53, SPECIES_DEWGONG },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_LeafGreen_LandMonsInfo = { 7, sFourIslandIcefallCaveEntrance_LeafGreen_LandMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_SEEL },
    { 5, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_DEWGONG },
    { 5, 15, SPECIES_MARILL },
    { 5, 15, SPECIES_MARILL },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_LeafGreen_WaterMonsInfo = { 2, sFourIslandIcefallCaveEntrance_LeafGreen_WaterMons };

const struct WildPokemon sFourIslandIcefallCaveEntrance_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFourIslandIcefallCaveEntrance_LeafGreen_FishingMonsInfo = { 20, sFourIslandIcefallCaveEntrance_LeafGreen_FishingMons };

const struct WildPokemon sFourIslandIcefallCave1F_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_SWINUB },
    { 45, 45, SPECIES_GOLBAT },
    { 45, 45, SPECIES_SEEL },
    { 27, 27, SPECIES_SWINUB },
    { 40, 40, SPECIES_ZUBAT },
    { 29, 29, SPECIES_SWINUB },
    { 30, 30, SPECIES_SNEASEL },
    { 31, 31, SPECIES_SWINUB },
    { 48, 48, SPECIES_GOLBAT },
    { 23, 23, SPECIES_SWINUB },
    { 48, 48, SPECIES_GOLBAT },
    { 23, 23, SPECIES_SWINUB },
};

const struct WildPokemonInfo sFourIslandIcefallCave1F_LeafGreen_LandMonsInfo = { 7, sFourIslandIcefallCave1F_LeafGreen_LandMons };

const struct WildPokemon sFourIslandIcefallCaveB1F_LeafGreen_LandMons[] =
{
    { 25, 25, SPECIES_SWINUB },
    { 45, 45, SPECIES_GOLBAT },
    { 45, 45, SPECIES_SEEL },
    { 27, 27, SPECIES_SWINUB },
    { 40, 40, SPECIES_ZUBAT },
    { 29, 29, SPECIES_SWINUB },
    { 30, 30, SPECIES_SNEASEL },
    { 31, 31, SPECIES_SWINUB },
    { 48, 48, SPECIES_GOLBAT },
    { 23, 23, SPECIES_SWINUB },
    { 48, 48, SPECIES_GOLBAT },
    { 23, 23, SPECIES_SWINUB },
};

const struct WildPokemonInfo sFourIslandIcefallCaveB1F_LeafGreen_LandMonsInfo = { 7, sFourIslandIcefallCaveB1F_LeafGreen_LandMons };

const struct WildPokemon sFourIslandIcefallCaveBack_LeafGreen_LandMons[] =
{
    { 43, 43, SPECIES_SEEL },
    { 45, 45, SPECIES_GOLBAT },
    { 45, 45, SPECIES_SEEL },
    { 47, 47, SPECIES_SEEL },
    { 40, 40, SPECIES_ZUBAT },
    { 49, 49, SPECIES_DEWGONG },
    { 51, 51, SPECIES_DEWGONG },
    { 41, 41, SPECIES_SLOWPOKE },
    { 48, 48, SPECIES_GOLBAT },
    { 53, 53, SPECIES_DEWGONG },
    { 48, 48, SPECIES_GOLBAT },
    { 53, 53, SPECIES_DEWGONG },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_LeafGreen_LandMonsInfo = { 7, sFourIslandIcefallCaveBack_LeafGreen_LandMons };

const struct WildPokemon sFourIslandIcefallCaveBack_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 45, SPECIES_TENTACOOL },
    { 35, 45, SPECIES_TENTACRUEL },
    { 30, 45, SPECIES_LAPRAS },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_LeafGreen_WaterMonsInfo = { 2, sFourIslandIcefallCaveBack_LeafGreen_WaterMons };

const struct WildPokemon sFourIslandIcefallCaveBack_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFourIslandIcefallCaveBack_LeafGreen_FishingMonsInfo = { 20, sFourIslandIcefallCaveBack_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandPatternBush_LeafGreen_LandMons[] =
{
    { 9, 9, SPECIES_LEDYBA },
    { 9, 9, SPECIES_KAKUNA },
    { 14, 14, SPECIES_LEDYBA },
    { 6, 6, SPECIES_CATERPIE },
    { 6, 6, SPECIES_WEEDLE },
    { 15, 15, SPECIES_HERACROSS },
    { 9, 9, SPECIES_METAPOD },
    { 20, 20, SPECIES_HERACROSS },
    { 9, 9, SPECIES_SPINARAK },
    { 25, 25, SPECIES_HERACROSS },
    { 14, 14, SPECIES_SPINARAK },
    { 30, 30, SPECIES_HERACROSS },
};

const struct WildPokemonInfo sSixIslandPatternBush_LeafGreen_LandMonsInfo = { 21, sSixIslandPatternBush_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom1_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom1_LeafGreen_LandMonsInfo = { 1, sFiveIslandLostCaveRoom1_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom2_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom2_LeafGreen_LandMonsInfo = { 2, sFiveIslandLostCaveRoom2_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom3_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom3_LeafGreen_LandMonsInfo = { 3, sFiveIslandLostCaveRoom3_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom4_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom4_LeafGreen_LandMonsInfo = { 4, sFiveIslandLostCaveRoom4_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom5_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom5_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom5_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom6_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom6_LeafGreen_LandMonsInfo = { 6, sFiveIslandLostCaveRoom6_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom7_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom7_LeafGreen_LandMonsInfo = { 7, sFiveIslandLostCaveRoom7_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom8_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom8_LeafGreen_LandMonsInfo = { 8, sFiveIslandLostCaveRoom8_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom9_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom9_LeafGreen_LandMonsInfo = { 9, sFiveIslandLostCaveRoom9_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom10_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 43, 43, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GASTLY },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom10_LeafGreen_LandMonsInfo = { 10, sFiveIslandLostCaveRoom10_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom11_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MISDREAVUS },
    { 20, 20, SPECIES_MISDREAVUS },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom11_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom11_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom12_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MISDREAVUS },
    { 20, 20, SPECIES_MISDREAVUS },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom12_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom12_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom13_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MISDREAVUS },
    { 20, 20, SPECIES_MISDREAVUS },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom13_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom13_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandLostCaveRoom14_LeafGreen_LandMons[] =
{
    { 40, 40, SPECIES_GASTLY },
    { 37, 37, SPECIES_ZUBAT },
    { 44, 44, SPECIES_HAUNTER },
    { 46, 46, SPECIES_HAUNTER },
    { 41, 41, SPECIES_GOLBAT },
    { 15, 15, SPECIES_MISDREAVUS },
    { 20, 20, SPECIES_MISDREAVUS },
    { 48, 48, SPECIES_HAUNTER },
    { 50, 50, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
    { 52, 52, SPECIES_HAUNTER },
    { 22, 22, SPECIES_MISDREAVUS },
};

const struct WildPokemonInfo sFiveIslandLostCaveRoom14_LeafGreen_LandMonsInfo = { 5, sFiveIslandLostCaveRoom14_LeafGreen_LandMons };

const struct WildPokemon sOneIslandKindleRoad_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_SPEAROW },
    { 34, 34, SPECIES_PONYTA },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_PONYTA },
    { 31, 31, SPECIES_GEODUDE },
    { 31, 31, SPECIES_MEOWTH },
    { 30, 30, SPECIES_SPEAROW },
    { 34, 34, SPECIES_SLOWPOKE },
    { 37, 37, SPECIES_RAPIDASH },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_RAPIDASH },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sOneIslandKindleRoad_LeafGreen_LandMonsInfo = { 21, sOneIslandKindleRoad_LeafGreen_LandMons };

const struct WildPokemon sOneIslandKindleRoad_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIslandKindleRoad_LeafGreen_WaterMonsInfo = { 2, sOneIslandKindleRoad_LeafGreen_WaterMons };

const struct WildPokemon sOneIslandKindleRoad_LeafGreen_RockSmashMons[] =
{
    { 5, 20, SPECIES_GEODUDE },
    { 10, 20, SPECIES_GEODUDE },
    { 15, 30, SPECIES_GEODUDE },
    { 25, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo sOneIslandKindleRoad_LeafGreen_RockSmashMonsInfo = { 25, sOneIslandKindleRoad_LeafGreen_RockSmashMons };

const struct WildPokemon sOneIslandKindleRoad_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sOneIslandKindleRoad_LeafGreen_FishingMonsInfo = { 20, sOneIslandKindleRoad_LeafGreen_FishingMons };

const struct WildPokemon sOneIslandTreasureBeach_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_SPEAROW },
    { 33, 33, SPECIES_TANGELA },
    { 31, 31, SPECIES_SPEAROW },
    { 35, 35, SPECIES_TANGELA },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_MEOWTH },
    { 38, 38, SPECIES_FEAROW },
    { 31, 31, SPECIES_SLOWPOKE },
    { 40, 40, SPECIES_FEAROW },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_FEAROW },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_LeafGreen_LandMonsInfo = { 21, sOneIslandTreasureBeach_LeafGreen_LandMons };

const struct WildPokemon sOneIslandTreasureBeach_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_LeafGreen_WaterMonsInfo = { 2, sOneIslandTreasureBeach_LeafGreen_WaterMons };

const struct WildPokemon sOneIslandTreasureBeach_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sOneIslandTreasureBeach_LeafGreen_FishingMonsInfo = { 20, sOneIslandTreasureBeach_LeafGreen_FishingMons };

const struct WildPokemon sTwoIslandCapeBrink_LeafGreen_LandMons[] =
{
    { 31, 31, SPECIES_SPEAROW },
    { 30, 30, SPECIES_BELLSPROUT },
    { 32, 32, SPECIES_BELLSPROUT },
    { 36, 36, SPECIES_WEEPINBELL },
    { 36, 36, SPECIES_FEAROW },
    { 31, 31, SPECIES_MEOWTH },
    { 38, 38, SPECIES_WEEPINBELL },
    { 31, 31, SPECIES_SLOWPOKE },
    { 37, 37, SPECIES_SLOWBRO },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_SLOWBRO },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_LeafGreen_LandMonsInfo = { 21, sTwoIslandCapeBrink_LeafGreen_LandMons };

const struct WildPokemon sTwoIslandCapeBrink_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_SLOWPOKE },
    { 20, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWBRO },
    { 35, 40, SPECIES_SLOWBRO },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_LeafGreen_WaterMonsInfo = { 2, sTwoIslandCapeBrink_LeafGreen_WaterMons };

const struct WildPokemon sTwoIslandCapeBrink_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sTwoIslandCapeBrink_LeafGreen_FishingMonsInfo = { 20, sTwoIslandCapeBrink_LeafGreen_FishingMons };

const struct WildPokemon sThreeIslandBondBridge_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_PIDGEY },
    { 31, 31, SPECIES_BELLSPROUT },
    { 29, 29, SPECIES_PIDGEY },
    { 36, 36, SPECIES_WEEPINBELL },
    { 34, 34, SPECIES_PIDGEOTTO },
    { 31, 31, SPECIES_MEOWTH },
    { 34, 34, SPECIES_VENONAT },
    { 31, 31, SPECIES_SLOWPOKE },
    { 37, 37, SPECIES_PIDGEOTTO },
    { 37, 37, SPECIES_PERSIAN },
    { 40, 40, SPECIES_PIDGEOTTO },
    { 40, 40, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sThreeIslandBondBridge_LeafGreen_LandMonsInfo = { 21, sThreeIslandBondBridge_LeafGreen_LandMons };

const struct WildPokemon sThreeIslandBondBridge_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sThreeIslandBondBridge_LeafGreen_WaterMonsInfo = { 2, sThreeIslandBondBridge_LeafGreen_WaterMons };

const struct WildPokemon sThreeIslandBondBridge_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sThreeIslandBondBridge_LeafGreen_FishingMonsInfo = { 20, sThreeIslandBondBridge_LeafGreen_FishingMons };

const struct WildPokemon sThreeIslandPort_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_DUNSPARCE },
    { 15, 15, SPECIES_DUNSPARCE },
    { 10, 10, SPECIES_DUNSPARCE },
    { 10, 10, SPECIES_DUNSPARCE },
    { 20, 20, SPECIES_DUNSPARCE },
    { 20, 20, SPECIES_DUNSPARCE },
    { 25, 25, SPECIES_DUNSPARCE },
    { 30, 30, SPECIES_DUNSPARCE },
    { 25, 25, SPECIES_DUNSPARCE },
    { 30, 30, SPECIES_DUNSPARCE },
    { 5, 5, SPECIES_DUNSPARCE },
    { 35, 35, SPECIES_DUNSPARCE },
};

const struct WildPokemonInfo sThreeIslandPort_LeafGreen_LandMonsInfo = { 1, sThreeIslandPort_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandResortGorgeous_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandResortGorgeous_LeafGreen_WaterMonsInfo = { 2, sFiveIslandResortGorgeous_LeafGreen_WaterMons };

const struct WildPokemon sFiveIslandResortGorgeous_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIslandResortGorgeous_LeafGreen_FishingMonsInfo = { 20, sFiveIslandResortGorgeous_LeafGreen_FishingMons };

const struct WildPokemon sFiveIslandWaterLabyrinth_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandWaterLabyrinth_LeafGreen_WaterMonsInfo = { 2, sFiveIslandWaterLabyrinth_LeafGreen_WaterMons };

const struct WildPokemon sFiveIslandWaterLabyrinth_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIslandWaterLabyrinth_LeafGreen_FishingMonsInfo = { 20, sFiveIslandWaterLabyrinth_LeafGreen_FishingMons };

const struct WildPokemon sFiveIslandMeadow_LeafGreen_LandMons[] =
{
    { 44, 44, SPECIES_PIDGEY },
    { 10, 10, SPECIES_SENTRET },
    { 48, 48, SPECIES_PIDGEOTTO },
    { 10, 10, SPECIES_HOPPIP },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 15, 15, SPECIES_HOPPIP },
    { 41, 41, SPECIES_SLOWPOKE },
    { 50, 50, SPECIES_PIDGEOTTO },
    { 47, 47, SPECIES_PERSIAN },
    { 50, 50, SPECIES_PIDGEOTTO },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sFiveIslandMeadow_LeafGreen_LandMonsInfo = { 21, sFiveIslandMeadow_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandMeadow_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandMeadow_LeafGreen_WaterMonsInfo = { 2, sFiveIslandMeadow_LeafGreen_WaterMons };

const struct WildPokemon sFiveIslandMeadow_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIslandMeadow_LeafGreen_FishingMonsInfo = { 20, sFiveIslandMeadow_LeafGreen_FishingMons };

const struct WildPokemon sFiveIslandMemorialPillar_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_HOPPIP },
    { 12, 12, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
    { 10, 10, SPECIES_HOPPIP },
    { 12, 12, SPECIES_HOPPIP },
    { 16, 16, SPECIES_HOPPIP },
    { 6, 6, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
    { 8, 8, SPECIES_HOPPIP },
    { 14, 14, SPECIES_HOPPIP },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_LeafGreen_LandMonsInfo = { 21, sFiveIslandMemorialPillar_LeafGreen_LandMons };

const struct WildPokemon sFiveIslandMemorialPillar_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_LeafGreen_WaterMonsInfo = { 2, sFiveIslandMemorialPillar_LeafGreen_WaterMons };

const struct WildPokemon sFiveIslandMemorialPillar_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIslandMemorialPillar_LeafGreen_FishingMonsInfo = { 20, sFiveIslandMemorialPillar_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandOutcastIsland_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandOutcastIsland_LeafGreen_WaterMonsInfo = { 2, sSixIslandOutcastIsland_LeafGreen_WaterMons };

const struct WildPokemon sSixIslandOutcastIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSixIslandOutcastIsland_LeafGreen_FishingMonsInfo = { 20, sSixIslandOutcastIsland_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandGreenPath_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandGreenPath_LeafGreen_WaterMonsInfo = { 2, sSixIslandGreenPath_LeafGreen_WaterMons };

const struct WildPokemon sSixIslandGreenPath_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSixIslandGreenPath_LeafGreen_FishingMonsInfo = { 20, sSixIslandGreenPath_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandWaterPath_LeafGreen_LandMons[] =
{
    { 44, 44, SPECIES_SPEAROW },
    { 10, 10, SPECIES_SENTRET },
    { 44, 44, SPECIES_BELLSPROUT },
    { 48, 48, SPECIES_FEAROW },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 48, 48, SPECIES_WEEPINBELL },
    { 41, 41, SPECIES_SLOWPOKE },
    { 50, 50, SPECIES_FEAROW },
    { 47, 47, SPECIES_PERSIAN },
    { 50, 50, SPECIES_FEAROW },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSixIslandWaterPath_LeafGreen_LandMonsInfo = { 21, sSixIslandWaterPath_LeafGreen_LandMons };

const struct WildPokemon sSixIslandWaterPath_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSixIslandWaterPath_LeafGreen_WaterMonsInfo = { 2, sSixIslandWaterPath_LeafGreen_WaterMons };

const struct WildPokemon sSixIslandWaterPath_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSixIslandWaterPath_LeafGreen_FishingMonsInfo = { 20, sSixIslandWaterPath_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandRuinValley_LeafGreen_LandMons[] =
{
    { 15, 15, SPECIES_NATU },
    { 44, 44, SPECIES_SPEAROW },
    { 18, 18, SPECIES_YANMA },
    { 15, 15, SPECIES_MARILL },
    { 49, 49, SPECIES_FEAROW },
    { 43, 43, SPECIES_MEOWTH },
    { 25, 25, SPECIES_WOBBUFFET },
    { 41, 41, SPECIES_SLOWPOKE },
    { 20, 20, SPECIES_NATU },
    { 49, 49, SPECIES_PERSIAN },
    { 20, 20, SPECIES_NATU },
    { 52, 52, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSixIslandRuinValley_LeafGreen_LandMonsInfo = { 21, sSixIslandRuinValley_LeafGreen_LandMons };

const struct WildPokemon sSixIslandRuinValley_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 15, 25, SPECIES_MARILL },
    { 20, 25, SPECIES_MARILL },
    { 20, 25, SPECIES_MARILL },
};

const struct WildPokemonInfo sSixIslandRuinValley_LeafGreen_WaterMonsInfo = { 2, sSixIslandRuinValley_LeafGreen_WaterMons };

const struct WildPokemon sSixIslandRuinValley_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSixIslandRuinValley_LeafGreen_FishingMonsInfo = { 20, sSixIslandRuinValley_LeafGreen_FishingMons };

const struct WildPokemon sSevenIslandTrainerTower_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_MANTINE },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSevenIslandTrainerTower_LeafGreen_WaterMonsInfo = { 2, sSevenIslandTrainerTower_LeafGreen_WaterMons };

const struct WildPokemon sSevenIslandTrainerTower_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSevenIslandTrainerTower_LeafGreen_FishingMonsInfo = { 20, sSevenIslandTrainerTower_LeafGreen_FishingMons };

const struct WildPokemon sSevenIslandSevaultCanyonEntrance_LeafGreen_LandMons[] =
{
    { 44, 44, SPECIES_SPEAROW },
    { 10, 10, SPECIES_SENTRET },
    { 10, 10, SPECIES_PHANPY },
    { 48, 48, SPECIES_FEAROW },
    { 15, 15, SPECIES_SENTRET },
    { 41, 41, SPECIES_MEOWTH },
    { 50, 50, SPECIES_FEAROW },
    { 41, 41, SPECIES_SLOWPOKE },
    { 15, 15, SPECIES_PHANPY },
    { 47, 47, SPECIES_PERSIAN },
    { 15, 15, SPECIES_PHANPY },
    { 50, 50, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyonEntrance_LeafGreen_LandMonsInfo = { 21, sSevenIslandSevaultCanyonEntrance_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandSevaultCanyon_LeafGreen_LandMons[] =
{
    { 46, 46, SPECIES_GEODUDE },
    { 15, 15, SPECIES_PHANPY },
    { 46, 46, SPECIES_CUBONE },
    { 50, 50, SPECIES_FEAROW },
    { 52, 52, SPECIES_MAROWAK },
    { 43, 43, SPECIES_MEOWTH },
    { 54, 54, SPECIES_ONIX },
    { 50, 50, SPECIES_FEAROW },
    { 15, 15, SPECIES_LARVITAR },
    { 49, 49, SPECIES_PERSIAN },
    { 20, 20, SPECIES_LARVITAR },
    { 52, 52, SPECIES_PERSIAN },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyon_LeafGreen_LandMonsInfo = { 21, sSevenIslandSevaultCanyon_LeafGreen_LandMons };

const struct WildPokemon sSevenIslandSevaultCanyon_LeafGreen_RockSmashMons[] =
{
    { 25, 35, SPECIES_GEODUDE },
    { 30, 45, SPECIES_GRAVELER },
    { 35, 50, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 30, 40, SPECIES_GEODUDE },
};

const struct WildPokemonInfo sSevenIslandSevaultCanyon_LeafGreen_RockSmashMonsInfo = { 25, sSevenIslandSevaultCanyon_LeafGreen_RockSmashMons };

const struct WildPokemon sSevenIslandTanobyRuins_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_MANTINE },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sSevenIslandTanobyRuins_LeafGreen_WaterMonsInfo = { 2, sSevenIslandTanobyRuins_LeafGreen_WaterMons };

const struct WildPokemon sSevenIslandTanobyRuins_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_REMORAID },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sSevenIslandTanobyRuins_LeafGreen_FishingMonsInfo = { 20, sSevenIslandTanobyRuins_LeafGreen_FishingMons };

const struct WildPokemon sRoute1_LeafGreen_LandMons[] =
{
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 2, 2, SPECIES_PIDGEY },
    { 2, 2, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 3, 3, SPECIES_RATTATA },
    { 4, 4, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
    { 5, 5, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
};

const struct WildPokemonInfo sRoute1_LeafGreen_LandMonsInfo = { 21, sRoute1_LeafGreen_LandMons };

const struct WildPokemon sRoute2_LeafGreen_LandMons[] =
{
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_PIDGEY },
    { 4, 4, SPECIES_RATTATA },
    { 4, 4, SPECIES_PIDGEY },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_PIDGEY },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_PIDGEY },
    { 4, 4, SPECIES_CATERPIE },
    { 4, 4, SPECIES_WEEDLE },
    { 5, 5, SPECIES_CATERPIE },
    { 5, 5, SPECIES_WEEDLE },
};

const struct WildPokemonInfo sRoute2_LeafGreen_LandMonsInfo = { 21, sRoute2_LeafGreen_LandMons };

const struct WildPokemon sRoute3_LeafGreen_LandMons[] =
{
    { 6, 6, SPECIES_SPEAROW },
    { 6, 6, SPECIES_PIDGEY },
    { 7, 7, SPECIES_SPEAROW },
    { 7, 7, SPECIES_MANKEY },
    { 6, 6, SPECIES_NIDORAN_F },
    { 7, 7, SPECIES_PIDGEY },
    { 8, 8, SPECIES_SPEAROW },
    { 3, 3, SPECIES_JIGGLYPUFF },
    { 7, 7, SPECIES_NIDORAN_F },
    { 5, 5, SPECIES_JIGGLYPUFF },
    { 6, 6, SPECIES_NIDORAN_M },
    { 7, 7, SPECIES_JIGGLYPUFF },
};

const struct WildPokemonInfo sRoute3_LeafGreen_LandMonsInfo = { 21, sRoute3_LeafGreen_LandMons };

const struct WildPokemon sRoute4_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_SPEAROW },
    { 10, 10, SPECIES_RATTATA },
    { 6, 6, SPECIES_SANDSHREW },
    { 10, 10, SPECIES_SANDSHREW },
    { 8, 8, SPECIES_SPEAROW },
    { 8, 8, SPECIES_RATTATA },
    { 12, 12, SPECIES_SPEAROW },
    { 12, 12, SPECIES_RATTATA },
    { 10, 10, SPECIES_MANKEY },
    { 8, 8, SPECIES_SANDSHREW },
    { 12, 12, SPECIES_MANKEY },
    { 12, 12, SPECIES_SANDSHREW },
};

const struct WildPokemonInfo sRoute4_LeafGreen_LandMonsInfo = { 21, sRoute4_LeafGreen_LandMons };

const struct WildPokemon sRoute4_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute4_LeafGreen_WaterMonsInfo = { 2, sRoute4_LeafGreen_WaterMons };

const struct WildPokemon sRoute4_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute4_LeafGreen_FishingMonsInfo = { 20, sRoute4_LeafGreen_FishingMons };

const struct WildPokemon sRoute5_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_MEOWTH },
    { 13, 13, SPECIES_PIDGEY },
    { 13, 13, SPECIES_BELLSPROUT },
    { 12, 12, SPECIES_MEOWTH },
    { 15, 15, SPECIES_BELLSPROUT },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_BELLSPROUT },
    { 16, 16, SPECIES_PIDGEY },
    { 15, 15, SPECIES_PIDGEY },
    { 14, 14, SPECIES_MEOWTH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute5_LeafGreen_LandMonsInfo = { 21, sRoute5_LeafGreen_LandMons };

const struct WildPokemon sRoute6_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_MEOWTH },
    { 13, 13, SPECIES_PIDGEY },
    { 13, 13, SPECIES_BELLSPROUT },
    { 12, 12, SPECIES_MEOWTH },
    { 15, 15, SPECIES_BELLSPROUT },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_BELLSPROUT },
    { 16, 16, SPECIES_PIDGEY },
    { 15, 15, SPECIES_PIDGEY },
    { 14, 14, SPECIES_MEOWTH },
    { 15, 15, SPECIES_PIDGEY },
    { 16, 16, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute6_LeafGreen_LandMonsInfo = { 21, sRoute6_LeafGreen_LandMons };

const struct WildPokemon sRoute6_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute6_LeafGreen_WaterMonsInfo = { 2, sRoute6_LeafGreen_WaterMons };

const struct WildPokemon sRoute6_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute6_LeafGreen_FishingMonsInfo = { 20, sRoute6_LeafGreen_FishingMons };

const struct WildPokemon sRoute7_LeafGreen_LandMons[] =
{
    { 19, 19, SPECIES_PIDGEY },
    { 17, 17, SPECIES_MEOWTH },
    { 19, 19, SPECIES_BELLSPROUT },
    { 18, 18, SPECIES_MEOWTH },
    { 22, 22, SPECIES_PIDGEY },
    { 22, 22, SPECIES_BELLSPROUT },
    { 18, 18, SPECIES_VULPIX },
    { 20, 20, SPECIES_VULPIX },
    { 17, 17, SPECIES_MEOWTH },
    { 19, 19, SPECIES_MEOWTH },
    { 17, 17, SPECIES_MEOWTH },
    { 20, 20, SPECIES_MEOWTH },
};

const struct WildPokemonInfo sRoute7_LeafGreen_LandMonsInfo = { 21, sRoute7_LeafGreen_LandMons };

const struct WildPokemon sRoute8_LeafGreen_LandMons[] =
{
    { 18, 18, SPECIES_PIDGEY },
    { 18, 18, SPECIES_MEOWTH },
    { 16, 16, SPECIES_VULPIX },
    { 20, 20, SPECIES_PIDGEY },
    { 20, 20, SPECIES_MEOWTH },
    { 17, 17, SPECIES_SANDSHREW },
    { 17, 17, SPECIES_VULPIX },
    { 19, 19, SPECIES_SANDSHREW },
    { 17, 17, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_VULPIX },
    { 17, 17, SPECIES_SANDSHREW },
    { 18, 18, SPECIES_VULPIX },
};

const struct WildPokemonInfo sRoute8_LeafGreen_LandMonsInfo = { 21, sRoute8_LeafGreen_LandMons };

const struct WildPokemon sRoute9_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_SPEAROW },
    { 16, 16, SPECIES_RATTATA },
    { 11, 11, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_SANDSHREW },
    { 13, 13, SPECIES_SPEAROW },
    { 14, 14, SPECIES_RATTATA },
    { 17, 17, SPECIES_SPEAROW },
    { 17, 17, SPECIES_RATTATA },
    { 14, 14, SPECIES_RATTATA },
    { 13, 13, SPECIES_SANDSHREW },
    { 14, 14, SPECIES_RATTATA },
    { 17, 17, SPECIES_SANDSHREW },
};

const struct WildPokemonInfo sRoute9_LeafGreen_LandMonsInfo = { 21, sRoute9_LeafGreen_LandMons };

const struct WildPokemon sRoute10_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_SPEAROW },
    { 16, 16, SPECIES_VOLTORB },
    { 11, 11, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_SANDSHREW },
    { 13, 13, SPECIES_SPEAROW },
    { 14, 14, SPECIES_VOLTORB },
    { 17, 17, SPECIES_SPEAROW },
    { 17, 17, SPECIES_VOLTORB },
    { 14, 14, SPECIES_VOLTORB },
    { 13, 13, SPECIES_SANDSHREW },
    { 14, 14, SPECIES_VOLTORB },
    { 17, 17, SPECIES_SANDSHREW },
};

const struct WildPokemonInfo sRoute10_LeafGreen_LandMonsInfo = { 21, sRoute10_LeafGreen_LandMons };

const struct WildPokemon sRoute10_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute10_LeafGreen_WaterMonsInfo = { 2, sRoute10_LeafGreen_WaterMons };

const struct WildPokemon sRoute10_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute10_LeafGreen_FishingMonsInfo = { 20, sRoute10_LeafGreen_FishingMons };

const struct WildPokemon sRoute11_LeafGreen_LandMons[] =
{
    { 14, 14, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_SPEAROW },
    { 12, 12, SPECIES_SANDSHREW },
    { 13, 13, SPECIES_SPEAROW },
    { 11, 11, SPECIES_DROWZEE },
    { 13, 13, SPECIES_DROWZEE },
    { 15, 15, SPECIES_SANDSHREW },
    { 17, 17, SPECIES_SPEAROW },
    { 12, 12, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_DROWZEE },
    { 12, 12, SPECIES_SANDSHREW },
    { 15, 15, SPECIES_DROWZEE },
};

const struct WildPokemonInfo sRoute11_LeafGreen_LandMonsInfo = { 21, sRoute11_LeafGreen_LandMons };

const struct WildPokemon sRoute11_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute11_LeafGreen_WaterMonsInfo = { 2, sRoute11_LeafGreen_WaterMons };

const struct WildPokemon sRoute11_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute11_LeafGreen_FishingMonsInfo = { 20, sRoute11_LeafGreen_FishingMons };

const struct WildPokemon sRoute12_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_BELLSPROUT },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_BELLSPROUT },
    { 23, 23, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_BELLSPROUT },
    { 27, 27, SPECIES_PIDGEY },
    { 23, 23, SPECIES_PIDGEY },
    { 28, 28, SPECIES_WEEPINBELL },
    { 23, 23, SPECIES_PIDGEY },
    { 30, 30, SPECIES_WEEPINBELL },
};

const struct WildPokemonInfo sRoute12_LeafGreen_LandMonsInfo = { 21, sRoute12_LeafGreen_LandMons };

const struct WildPokemon sRoute12_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute12_LeafGreen_WaterMonsInfo = { 2, sRoute12_LeafGreen_WaterMons };

const struct WildPokemon sRoute12_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute12_LeafGreen_FishingMonsInfo = { 60, sRoute12_LeafGreen_FishingMons };

const struct WildPokemon sRoute13_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_BELLSPROUT },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_BELLSPROUT },
    { 27, 27, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_BELLSPROUT },
    { 25, 25, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 28, 28, SPECIES_WEEPINBELL },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 30, 30, SPECIES_WEEPINBELL },
};

const struct WildPokemonInfo sRoute13_LeafGreen_LandMonsInfo = { 21, sRoute13_LeafGreen_LandMons };

const struct WildPokemon sRoute13_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute13_LeafGreen_WaterMonsInfo = { 2, sRoute13_LeafGreen_WaterMons };

const struct WildPokemon sRoute13_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute13_LeafGreen_FishingMonsInfo = { 20, sRoute13_LeafGreen_FishingMons };

const struct WildPokemon sRoute14_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_BELLSPROUT },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_BELLSPROUT },
    { 23, 23, SPECIES_DITTO },
    { 27, 27, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_BELLSPROUT },
    { 30, 30, SPECIES_WEEPINBELL },
    { 23, 23, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 23, 23, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
};

const struct WildPokemonInfo sRoute14_LeafGreen_LandMonsInfo = { 21, sRoute14_LeafGreen_LandMons };

const struct WildPokemon sRoute15_LeafGreen_LandMons[] =
{
    { 24, 24, SPECIES_BELLSPROUT },
    { 24, 24, SPECIES_VENONAT },
    { 22, 22, SPECIES_BELLSPROUT },
    { 27, 27, SPECIES_PIDGEY },
    { 25, 25, SPECIES_PIDGEY },
    { 26, 26, SPECIES_VENONAT },
    { 26, 26, SPECIES_BELLSPROUT },
    { 25, 25, SPECIES_DITTO },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 28, 28, SPECIES_WEEPINBELL },
    { 29, 29, SPECIES_PIDGEOTTO },
    { 30, 30, SPECIES_WEEPINBELL },
};

const struct WildPokemonInfo sRoute15_LeafGreen_LandMonsInfo = { 21, sRoute15_LeafGreen_LandMons };

const struct WildPokemon sRoute16_LeafGreen_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 18, 18, SPECIES_DODUO },
    { 18, 18, SPECIES_RATTATA },
    { 20, 20, SPECIES_RATTATA },
    { 22, 22, SPECIES_SPEAROW },
    { 20, 20, SPECIES_DODUO },
    { 22, 22, SPECIES_RATTATA },
    { 22, 22, SPECIES_DODUO },
    { 18, 18, SPECIES_RATTATA },
    { 23, 23, SPECIES_RATICATE },
    { 18, 18, SPECIES_RATTATA },
    { 25, 25, SPECIES_RATICATE },
};

const struct WildPokemonInfo sRoute16_LeafGreen_LandMonsInfo = { 21, sRoute16_LeafGreen_LandMons };

const struct WildPokemon sRoute17_LeafGreen_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 24, 24, SPECIES_DODUO },
    { 22, 22, SPECIES_SPEAROW },
    { 26, 26, SPECIES_DODUO },
    { 25, 25, SPECIES_RATICATE },
    { 27, 27, SPECIES_RATICATE },
    { 28, 28, SPECIES_DODUO },
    { 29, 29, SPECIES_RATICATE },
    { 22, 22, SPECIES_RATTATA },
    { 25, 25, SPECIES_FEAROW },
    { 22, 22, SPECIES_RATTATA },
    { 27, 27, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute17_LeafGreen_LandMonsInfo = { 21, sRoute17_LeafGreen_LandMons };

const struct WildPokemon sRoute18_LeafGreen_LandMons[] =
{
    { 20, 20, SPECIES_SPEAROW },
    { 24, 24, SPECIES_DODUO },
    { 22, 22, SPECIES_SPEAROW },
    { 26, 26, SPECIES_DODUO },
    { 25, 25, SPECIES_RATICATE },
    { 25, 25, SPECIES_FEAROW },
    { 28, 28, SPECIES_DODUO },
    { 29, 29, SPECIES_RATICATE },
    { 22, 22, SPECIES_RATTATA },
    { 27, 27, SPECIES_FEAROW },
    { 22, 22, SPECIES_RATTATA },
    { 29, 29, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute18_LeafGreen_LandMonsInfo = { 21, sRoute18_LeafGreen_LandMons };

const struct WildPokemon sRoute19_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute19_LeafGreen_WaterMonsInfo = { 2, sRoute19_LeafGreen_WaterMons };

const struct WildPokemon sRoute19_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute19_LeafGreen_FishingMonsInfo = { 20, sRoute19_LeafGreen_FishingMons };

const struct WildPokemon sRoute20_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute20_LeafGreen_WaterMonsInfo = { 2, sRoute20_LeafGreen_WaterMons };

const struct WildPokemon sRoute20_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute20_LeafGreen_FishingMonsInfo = { 20, sRoute20_LeafGreen_FishingMons };

const struct WildPokemon sRoute21North_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_TANGELA },
    { 23, 23, SPECIES_TANGELA },
    { 24, 24, SPECIES_TANGELA },
    { 21, 21, SPECIES_TANGELA },
    { 25, 25, SPECIES_TANGELA },
    { 20, 20, SPECIES_TANGELA },
    { 19, 19, SPECIES_TANGELA },
    { 26, 26, SPECIES_TANGELA },
    { 18, 18, SPECIES_TANGELA },
    { 27, 27, SPECIES_TANGELA },
    { 17, 17, SPECIES_TANGELA },
    { 28, 28, SPECIES_TANGELA },
};

const struct WildPokemonInfo sRoute21North_LeafGreen_LandMonsInfo = { 14, sRoute21North_LeafGreen_LandMons };

const struct WildPokemon sRoute21North_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute21North_LeafGreen_WaterMonsInfo = { 2, sRoute21North_LeafGreen_WaterMons };

const struct WildPokemon sRoute21North_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute21North_LeafGreen_FishingMonsInfo = { 20, sRoute21North_LeafGreen_FishingMons };

const struct WildPokemon sRoute21South_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_TANGELA },
    { 23, 23, SPECIES_TANGELA },
    { 24, 24, SPECIES_TANGELA },
    { 21, 21, SPECIES_TANGELA },
    { 25, 25, SPECIES_TANGELA },
    { 20, 20, SPECIES_TANGELA },
    { 19, 19, SPECIES_TANGELA },
    { 26, 26, SPECIES_TANGELA },
    { 18, 18, SPECIES_TANGELA },
    { 27, 27, SPECIES_TANGELA },
    { 17, 17, SPECIES_TANGELA },
    { 28, 28, SPECIES_TANGELA },
};

const struct WildPokemonInfo sRoute21South_LeafGreen_LandMonsInfo = { 14, sRoute21South_LeafGreen_LandMons };

const struct WildPokemon sRoute21South_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute21South_LeafGreen_WaterMonsInfo = { 2, sRoute21South_LeafGreen_WaterMons };

const struct WildPokemon sRoute21South_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute21South_LeafGreen_FishingMonsInfo = { 20, sRoute21South_LeafGreen_FishingMons };

const struct WildPokemon sRoute22_LeafGreen_LandMons[] =
{
    { 3, 3, SPECIES_RATTATA },
    { 3, 3, SPECIES_MANKEY },
    { 4, 4, SPECIES_RATTATA },
    { 4, 4, SPECIES_MANKEY },
    { 2, 2, SPECIES_RATTATA },
    { 2, 2, SPECIES_MANKEY },
    { 3, 3, SPECIES_SPEAROW },
    { 5, 5, SPECIES_SPEAROW },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_MANKEY },
    { 5, 5, SPECIES_RATTATA },
    { 5, 5, SPECIES_MANKEY },
};

const struct WildPokemonInfo sRoute22_LeafGreen_LandMonsInfo = { 21, sRoute22_LeafGreen_LandMons };

const struct WildPokemon sRoute22_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute22_LeafGreen_WaterMonsInfo = { 2, sRoute22_LeafGreen_WaterMons };

const struct WildPokemon sRoute22_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute22_LeafGreen_FishingMonsInfo = { 20, sRoute22_LeafGreen_FishingMons };

const struct WildPokemon sRoute23_LeafGreen_LandMons[] =
{
    { 32, 32, SPECIES_MANKEY },
    { 40, 40, SPECIES_FEAROW },
    { 34, 34, SPECIES_MANKEY },
    { 34, 34, SPECIES_SPEAROW },
    { 32, 32, SPECIES_SANDSHREW },
    { 34, 34, SPECIES_SANDSHREW },
    { 42, 42, SPECIES_PRIMEAPE },
    { 44, 44, SPECIES_SANDSLASH },
    { 32, 32, SPECIES_SPEAROW },
    { 42, 42, SPECIES_FEAROW },
    { 32, 32, SPECIES_SPEAROW },
    { 44, 44, SPECIES_FEAROW },
};

const struct WildPokemonInfo sRoute23_LeafGreen_LandMonsInfo = { 21, sRoute23_LeafGreen_LandMons };

const struct WildPokemon sRoute23_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute23_LeafGreen_WaterMonsInfo = { 2, sRoute23_LeafGreen_WaterMons };

const struct WildPokemon sRoute23_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute23_LeafGreen_FishingMonsInfo = { 20, sRoute23_LeafGreen_FishingMons };

const struct WildPokemon sRoute24_LeafGreen_LandMons[] =
{
    { 7, 7, SPECIES_WEEDLE },
    { 7, 7, SPECIES_CATERPIE },
    { 11, 11, SPECIES_PIDGEY },
    { 12, 12, SPECIES_BELLSPROUT },
    { 13, 13, SPECIES_BELLSPROUT },
    { 10, 10, SPECIES_ABRA },
    { 13, 13, SPECIES_PIDGEY },
    { 14, 14, SPECIES_BELLSPROUT },
    { 8, 8, SPECIES_METAPOD },
    { 8, 8, SPECIES_ABRA },
    { 8, 8, SPECIES_KAKUNA },
    { 12, 12, SPECIES_ABRA },
};

const struct WildPokemonInfo sRoute24_LeafGreen_LandMonsInfo = { 21, sRoute24_LeafGreen_LandMons };

const struct WildPokemon sRoute24_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sRoute24_LeafGreen_WaterMonsInfo = { 2, sRoute24_LeafGreen_WaterMons };

const struct WildPokemon sRoute24_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute24_LeafGreen_FishingMonsInfo = { 20, sRoute24_LeafGreen_FishingMons };

const struct WildPokemon sRoute25_LeafGreen_LandMons[] =
{
    { 8, 8, SPECIES_WEEDLE },
    { 8, 8, SPECIES_CATERPIE },
    { 13, 13, SPECIES_PIDGEY },
    { 14, 14, SPECIES_BELLSPROUT },
    { 13, 13, SPECIES_BELLSPROUT },
    { 11, 11, SPECIES_ABRA },
    { 11, 11, SPECIES_PIDGEY },
    { 12, 12, SPECIES_BELLSPROUT },
    { 9, 9, SPECIES_METAPOD },
    { 9, 9, SPECIES_ABRA },
    { 9, 9, SPECIES_KAKUNA },
    { 13, 13, SPECIES_ABRA },
};

const struct WildPokemonInfo sRoute25_LeafGreen_LandMonsInfo = { 21, sRoute25_LeafGreen_LandMons };

const struct WildPokemon sRoute25_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute25_LeafGreen_WaterMonsInfo = { 2, sRoute25_LeafGreen_WaterMons };

const struct WildPokemon sRoute25_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute25_LeafGreen_FishingMonsInfo = { 20, sRoute25_LeafGreen_FishingMons };

const struct WildPokemon sPalletTown_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sPalletTown_LeafGreen_WaterMonsInfo = { 1, sPalletTown_LeafGreen_WaterMons };

const struct WildPokemon sPalletTown_LeafGreen_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sPalletTown_LeafGreen_FishingMonsInfo = { 10, sPalletTown_LeafGreen_FishingMons };

const struct WildPokemon sViridianCity_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sViridianCity_LeafGreen_WaterMonsInfo = { 1, sViridianCity_LeafGreen_WaterMons };

const struct WildPokemon sViridianCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sViridianCity_LeafGreen_FishingMonsInfo = { 10, sViridianCity_LeafGreen_FishingMons };

const struct WildPokemon sCeruleanCity_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sCeruleanCity_LeafGreen_WaterMonsInfo = { 1, sCeruleanCity_LeafGreen_WaterMons };

const struct WildPokemon sCeruleanCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KRABBY },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCeruleanCity_LeafGreen_FishingMonsInfo = { 10, sCeruleanCity_LeafGreen_FishingMons };

const struct WildPokemon sVermilionCity_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sVermilionCity_LeafGreen_WaterMonsInfo = { 1, sVermilionCity_LeafGreen_WaterMons };

const struct WildPokemon sVermilionCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_HORSEA },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sVermilionCity_LeafGreen_FishingMonsInfo = { 10, sVermilionCity_LeafGreen_FishingMons };

const struct WildPokemon sCeladonCity_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_SLOWPOKE },
    { 10, 20, SPECIES_SLOWPOKE },
    { 20, 30, SPECIES_SLOWPOKE },
    { 30, 40, SPECIES_SLOWPOKE },
    { 30, 40, SPECIES_KOFFING },
};

const struct WildPokemonInfo sCeladonCity_LeafGreen_WaterMonsInfo = { 1, sCeladonCity_LeafGreen_WaterMons };

const struct WildPokemon sCeladonCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 25, 35, SPECIES_MAGIKARP },
    { 30, 40, SPECIES_GRIMER },
};

const struct WildPokemonInfo sCeladonCity_LeafGreen_FishingMonsInfo = { 10, sCeladonCity_LeafGreen_FishingMons };

const struct WildPokemon sFuchsiaCity_LeafGreen_WaterMons[] =
{
    { 20, 25, SPECIES_SLOWPOKE },
    { 20, 25, SPECIES_SLOWPOKE },
    { 25, 30, SPECIES_SLOWPOKE },
    { 30, 35, SPECIES_SLOWPOKE },
    { 35, 40, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFuchsiaCity_LeafGreen_WaterMonsInfo = { 1, sFuchsiaCity_LeafGreen_WaterMons };

const struct WildPokemon sFuchsiaCity_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 15, 25, SPECIES_GOLDEEN },
    { 20, 30, SPECIES_SEAKING },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFuchsiaCity_LeafGreen_FishingMonsInfo = { 10, sFuchsiaCity_LeafGreen_FishingMons };

const struct WildPokemon sCinnabarIsland_LeafGreen_WaterMons[] =
{
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 20, SPECIES_TENTACOOL },
    { 20, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
};

const struct WildPokemonInfo sCinnabarIsland_LeafGreen_WaterMonsInfo = { 1, sCinnabarIsland_LeafGreen_WaterMons };

const struct WildPokemon sCinnabarIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_HORSEA },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_SLOWBRO },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sCinnabarIsland_LeafGreen_FishingMonsInfo = { 10, sCinnabarIsland_LeafGreen_FishingMons };

const struct WildPokemon sOneIsland_LeafGreen_WaterMons[] =
{
    { 5, 20, SPECIES_TENTACOOL },
    { 20, 35, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sOneIsland_LeafGreen_WaterMonsInfo = { 1, sOneIsland_LeafGreen_WaterMons };

const struct WildPokemon sOneIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sOneIsland_LeafGreen_FishingMonsInfo = { 10, sOneIsland_LeafGreen_FishingMons };

const struct WildPokemon sFourIsland_LeafGreen_WaterMons[] =
{
    { 5, 15, SPECIES_MARILL },
    { 5, 35, SPECIES_SLOWPOKE },
    { 15, 25, SPECIES_MARILL },
    { 15, 25, SPECIES_MARILL },
    { 15, 25, SPECIES_MARILL },
};

const struct WildPokemonInfo sFourIsland_LeafGreen_WaterMonsInfo = { 2, sFourIsland_LeafGreen_WaterMons };

const struct WildPokemon sFourIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_POLIWAG },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_GOLDEEN },
    { 15, 25, SPECIES_POLIWAG },
    { 20, 30, SPECIES_POLIWHIRL },
    { 15, 25, SPECIES_GYARADOS },
    { 15, 25, SPECIES_SLOWPOKE },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFourIsland_LeafGreen_FishingMonsInfo = { 20, sFourIsland_LeafGreen_FishingMons };

const struct WildPokemon sFiveIsland_LeafGreen_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 15, SPECIES_HOPPIP },
    { 35, 40, SPECIES_TENTACOOL },
    { 35, 40, SPECIES_TENTACRUEL },
    { 35, 40, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo sFiveIsland_LeafGreen_WaterMonsInfo = { 1, sFiveIsland_LeafGreen_WaterMons };

const struct WildPokemon sFiveIsland_LeafGreen_FishingMons[] =
{
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 5, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 5, 15, SPECIES_MAGIKARP },
    { 5, 15, SPECIES_KRABBY },
    { 15, 25, SPECIES_KRABBY },
    { 15, 25, SPECIES_STARYU },
    { 15, 25, SPECIES_GYARADOS },
    { 25, 35, SPECIES_KINGLER },
    { 25, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sFiveIsland_LeafGreen_FishingMonsInfo = { 10, sFiveIsland_LeafGreen_FishingMons };

const struct WildPokemon sSixIslandAlteringCave_LeafGreen_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 16, 16, SPECIES_ZUBAT },
    { 6, 6, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
};

const struct WildPokemonInfo sSixIslandAlteringCave_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_2_LeafGreen_LandMons[] =
{
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 13, 13, SPECIES_MAREEP },
    { 3, 3, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
};

const struct WildPokemonInfo sSixIslandAlteringCave_2_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_2_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_3_LeafGreen_LandMons[] =
{
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 22, 22, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 29, 29, SPECIES_PINECO },
    { 19, 19, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
};

const struct WildPokemonInfo sSixIslandAlteringCave_3_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_3_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_4_LeafGreen_LandMons[] =
{
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 22, 22, SPECIES_HOUNDOUR },
    { 12, 12, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
};

const struct WildPokemonInfo sSixIslandAlteringCave_4_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_4_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_5_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_TEDDIURSA },
    { 24, 24, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
    { 22, 22, SPECIES_TEDDIURSA },
    { 24, 24, SPECIES_TEDDIURSA },
    { 28, 28, SPECIES_TEDDIURSA },
    { 18, 18, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
    { 20, 20, SPECIES_TEDDIURSA },
    { 26, 26, SPECIES_TEDDIURSA },
};

const struct WildPokemonInfo sSixIslandAlteringCave_5_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_5_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_6_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 28, 28, SPECIES_AIPOM },
    { 18, 18, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
};

const struct WildPokemonInfo sSixIslandAlteringCave_6_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_6_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_7_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 28, 28, SPECIES_SHUCKLE },
    { 18, 18, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo sSixIslandAlteringCave_7_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_7_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_8_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 28, 28, SPECIES_STANTLER },
    { 18, 18, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
};

const struct WildPokemonInfo sSixIslandAlteringCave_8_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_8_LeafGreen_LandMons };

const struct WildPokemon sSixIslandAlteringCave_9_LeafGreen_LandMons[] =
{
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 28, 28, SPECIES_SMEARGLE },
    { 18, 18, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo sSixIslandAlteringCave_9_LeafGreen_LandMonsInfo = { 7, sSixIslandAlteringCave_9_LeafGreen_LandMons };

const struct WildPokemon sRoute20_Underwater_FireRed_LandMons[] =
{
    { 33, 36, SPECIES_TENTACOOL },
    { 25, 25, SPECIES_HORSEA },
    { 12, 14, SPECIES_KRABBY },
    { 15, 15, SPECIES_KRABBY },
    { 22, 23, SPECIES_HORSEA },
    { 36, 40, SPECIES_TENTACOOL },
    { 25, 25, SPECIES_GYARADOS },
    { 38, 40, SPECIES_TENTACOOL },
    { 33, 35, SPECIES_SEADRA },
    { 28, 30, SPECIES_SEADRA },
    { 31, 33, SPECIES_SEADRA },
    { 33, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo sRoute20_Underwater_FireRed_LandMonsInfo = { 7, sRoute20_Underwater_FireRed_LandMons };

const struct WildPokemon sRoute20_Underwater_LeafGreen_LandMons[] =
{
    { 33, 36, SPECIES_TENTACOOL },
    { 25, 25, SPECIES_KRABBY },
    { 12, 14, SPECIES_HORSEA },
    { 15, 15, SPECIES_HORSEA },
    { 22, 23, SPECIES_KRABBY },
    { 36, 40, SPECIES_TENTACOOL },
    { 25, 25, SPECIES_GYARADOS },
    { 38, 40, SPECIES_TENTACOOL },
    { 33, 35, SPECIES_KINGLER },
    { 28, 30, SPECIES_KINGLER },
    { 31, 33, SPECIES_KINGLER },
    { 33, 35, SPECIES_SLOWPOKE },
};

const struct WildPokemonInfo sRoute20_Underwater_LeafGreen_LandMonsInfo = { 7, sRoute20_Underwater_LeafGreen_LandMons };

const struct WildPokemon sSafariZone_NorthWest_LandMons[] =
{
    { 33, 33, SPECIES_SUNKERN },
    { 34, 34, SPECIES_MAREEP },
    { 35, 35, SPECIES_SUNKERN },
    { 36, 36, SPECIES_MAREEP },
    { 34, 34, SPECIES_AIPOM },
    { 27, 27, SPECIES_GIRAFARIG },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_SNUBBULL },
    { 36, 36, SPECIES_STANTLER },
    { 37, 37, SPECIES_MILTANK },
    { 39, 39, SPECIES_STANTLER },
    { 40, 40, SPECIES_MILTANK },
};

const struct WildPokemonInfo sSafariZone_NorthWest_LandMonsInfo = { 25, sSafariZone_NorthWest_LandMons };

const struct WildPokemon sSafariZone_NorthWest_FireRed_WaterMons[] = // Wooper/Marill are FR/LG exclusive
{
    { 25, 30, SPECIES_WOOPER },
    { 25, 30, SPECIES_WOOPER },
    { 25, 30, SPECIES_WOOPER },
    { 25, 30, SPECIES_WOOPER },
    { 35, 40, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo sSafariZone_NorthWest_FireRed_WaterMonsInfo = { 9, sSafariZone_NorthWest_FireRed_WaterMons };

const struct WildPokemon sSafariZone_NorthWest_LeafGreen_WaterMons[] = // Wooper/Marill are FR/LG exclusive
{
    { 25, 30, SPECIES_MARILL },
    { 25, 30, SPECIES_MARILL },
    { 25, 30, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 33, 35, SPECIES_MARILL },
};

const struct WildPokemonInfo sSafariZone_NorthWest_LeafGreen_WaterMonsInfo = { 9, sSafariZone_NorthWest_LeafGreen_WaterMons };

const struct WildPokemon sSafariZone_NorthWest_FireRed_FishingMons[] = // Qwilfish/Remoraid are FR/LG exclusive, but Qwilfish isn't obtainable at Hoenn Safari Zone
{
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_SEAKING },
    { 30, 35, SPECIES_SEAKING },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
};

const struct WildPokemonInfo sSafariZone_NorthWest_FireRed_FishingMonsInfo = { 35, sSafariZone_NorthWest_FireRed_FishingMons };

const struct WildPokemon sSafariZone_NorthWest_LeafGreen_FishingMons[] = // Qwilfish/Remoraid are FR/LG exclusive, but Qwilfish isn't obtainable at Hoenn Safari Zone
{
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_REMORAID },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 35, 40, SPECIES_OCTILLERY },
};

const struct WildPokemonInfo sSafariZone_NorthWest_LeafGreen_FishingMonsInfo = { 35, sSafariZone_NorthWest_LeafGreen_FishingMons };

const struct WildPokemon sSafariZone_NorthWest_RockSmashMons[] =
{
    { 25, 30, SPECIES_SHUCKLE },
    { 20, 25, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 35, 40, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo sSafariZone_NorthWest_RockSmashMonsInfo = { 25, sSafariZone_NorthWest_RockSmashMons };

const struct WildPokemon sSafariZone_NorthEast_LandMons[] =
{
    { 33, 33, SPECIES_AIPOM },
    { 34, 34, SPECIES_TEDDIURSA },
    { 35, 35, SPECIES_AIPOM },
    { 36, 36, SPECIES_TEDDIURSA },
    { 34, 34, SPECIES_SUNKERN },
    { 27, 27, SPECIES_GIRAFARIG },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_PINECO },
    { 36, 36, SPECIES_HOUNDOUR },
    { 37, 37, SPECIES_GLIGAR },
    { 39, 39, SPECIES_HOUNDOUR },
    { 40, 40, SPECIES_GLIGAR },
};

const struct WildPokemonInfo sSafariZone_NorthEast_LandMonsInfo = { 25, sSafariZone_NorthEast_LandMons };

const struct WildPokemon sThreeIslandBondBridge_Underwater_LandMons[] =
{
    { 20, 20, SPECIES_CHINCHOU },
    { 20, 20, SPECIES_CHINCHOU },
    { 21, 21, SPECIES_CHINCHOU },
    { 22, 22, SPECIES_CHINCHOU },
    { 23, 23, SPECIES_CHINCHOU },
    { 24, 24, SPECIES_CHINCHOU },
    { 25, 25, SPECIES_CHINCHOU },
    { 26, 26, SPECIES_CHINCHOU },
    { 27, 27, SPECIES_CHINCHOU },
    { 28, 28, SPECIES_CHINCHOU },
    { 29, 29, SPECIES_CHINCHOU },
    { 30, 30, SPECIES_CHINCHOU },
};

const struct WildPokemonInfo sThreeIslandBondBridge_Underwater_LandMonsInfo = { 7, sThreeIslandBondBridge_Underwater_LandMons };

const struct WildPokemon sArtisanCave_LandMons[] =
{
    { 40, 40, SPECIES_SMEARGLE },
    { 41, 41, SPECIES_SMEARGLE },
    { 42, 42, SPECIES_SMEARGLE },
    { 43, 43, SPECIES_SMEARGLE },
    { 44, 44, SPECIES_SMEARGLE },
    { 45, 45, SPECIES_SMEARGLE },
    { 46, 46, SPECIES_SMEARGLE },
    { 47, 47, SPECIES_SMEARGLE },
    { 48, 48, SPECIES_SMEARGLE },
    { 49, 49, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo sArtisanCave_LandMonsInfo = { 10, sArtisanCave_LandMons };

const struct WildPokemonHeader gWildMonHeaders[] =
{
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsMoneanChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsMoneanChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsLiptooChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsLiptooChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsWeepthChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsWeepthChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsDilfordChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsDilfordChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsScufibChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsScufibChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsRixyChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsRixyChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER),
        .landMonsInfo_FR = &sSevenIslandTanobyRuinsViapoisChamber_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandTanobyRuinsViapoisChamber_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VIRIDIAN_FOREST),
        .mapNum = MAP_NUM(VIRIDIAN_FOREST),
        .landMonsInfo_FR = &sViridianForest_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sViridianForest_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_MOON_1F),
        .mapNum = MAP_NUM(MT_MOON_1F),
        .landMonsInfo_FR = &sMtMoon1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtMoon1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_MOON_B1F),
        .mapNum = MAP_NUM(MT_MOON_B1F),
        .landMonsInfo_FR = &sMtMoonB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtMoonB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_MOON_B2F),
        .mapNum = MAP_NUM(MT_MOON_B2F),
        .landMonsInfo_FR = &sMtMoonB2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtMoonB2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SSANNE_EXTERIOR),
        .mapNum = MAP_NUM(SSANNE_EXTERIOR),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSSAnneExterior_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSSAnneExterior_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSSAnneExterior_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSSAnneExterior_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(DIGLETTS_CAVE_B1F),
        .mapNum = MAP_NUM(DIGLETTS_CAVE_B1F),
        .landMonsInfo_FR = &sDiglettsCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sDiglettsCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_1F),
        .landMonsInfo_FR = &sVictoryRoad1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sVictoryRoad1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_2F),
        .mapNum = MAP_NUM(VICTORY_ROAD_2F),
        .landMonsInfo_FR = &sVictoryRoad2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sVictoryRoad2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_3F),
        .mapNum = MAP_NUM(VICTORY_ROAD_3F),
        .landMonsInfo_FR = &sVictoryRoad3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sVictoryRoad3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_MANSION_1F),
        .mapNum = MAP_NUM(POKEMON_MANSION_1F),
        .landMonsInfo_FR = &sPokemonMansion1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonMansion1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_MANSION_2F),
        .mapNum = MAP_NUM(POKEMON_MANSION_2F),
        .landMonsInfo_FR = &sPokemonMansion2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonMansion2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_MANSION_3F),
        .mapNum = MAP_NUM(POKEMON_MANSION_3F),
        .landMonsInfo_FR = &sPokemonMansion3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonMansion3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_MANSION_B1F),
        .mapNum = MAP_NUM(POKEMON_MANSION_B1F),
        .landMonsInfo_FR = &sPokemonMansionB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonMansionB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_CENTER),
        .mapNum = MAP_NUM(SAFARI_ZONE_CENTER),
        .landMonsInfo_FR = &sSafariZoneCenter_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZoneCenter_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZoneCenter_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZoneCenter_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSafariZoneCenter_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZoneCenter_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_EAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_EAST),
        .landMonsInfo_FR = &sSafariZoneEast_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZoneEast_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZoneEast_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZoneEast_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSafariZoneEast_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZoneEast_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH),
        .landMonsInfo_FR = &sSafariZoneNorth_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZoneNorth_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZoneNorth_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZoneNorth_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSafariZoneNorth_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZoneNorth_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_WEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_WEST),
        .landMonsInfo_FR = &sSafariZoneWest_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZoneWest_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZoneWest_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZoneWest_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSafariZoneWest_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZoneWest_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_1F),
        .mapNum = MAP_NUM(CERULEAN_CAVE_1F),
        .landMonsInfo_FR = &sCeruleanCave1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCave1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCave1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCave1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCave1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCave1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_2F),
        .mapNum = MAP_NUM(CERULEAN_CAVE_2F),
        .landMonsInfo_FR = &sCeruleanCave2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sCeruleanCave2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_B1F),
        .mapNum = MAP_NUM(CERULEAN_CAVE_B1F),
        .landMonsInfo_FR = &sCeruleanCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCaveB1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCaveB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCaveB1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROCK_TUNNEL_1F),
        .mapNum = MAP_NUM(ROCK_TUNNEL_1F),
        .landMonsInfo_FR = &sRockTunnel1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRockTunnel1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROCK_TUNNEL_B1F),
        .mapNum = MAP_NUM(ROCK_TUNNEL_B1F),
        .landMonsInfo_FR = &sRockTunnelB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRockTunnelB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sRockTunnelB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sRockTunnelB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_1F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_1F),
        .landMonsInfo_FR = &sSeafoamIslands1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslands1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B1F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B1F),
        .landMonsInfo_FR = &sSeafoamIslandsB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslandsB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B2F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B2F),
        .landMonsInfo_FR = &sSeafoamIslandsB2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslandsB2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B3F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B3F),
        .landMonsInfo_FR = &sSeafoamIslandsB3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslandsB3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSeafoamIslandsB3F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSeafoamIslandsB3F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSeafoamIslandsB3F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSeafoamIslandsB3F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFOAM_ISLANDS_B4F),
        .mapNum = MAP_NUM(SEAFOAM_ISLANDS_B4F),
        .landMonsInfo_FR = &sSeafoamIslandsB4F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSeafoamIslandsB4F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSeafoamIslandsB4F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSeafoamIslandsB4F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSeafoamIslandsB4F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSeafoamIslandsB4F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_3F),
        .mapNum = MAP_NUM(POKEMON_TOWER_3F),
        .landMonsInfo_FR = &sPokemonTower3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_4F),
        .mapNum = MAP_NUM(POKEMON_TOWER_4F),
        .landMonsInfo_FR = &sPokemonTower4F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower4F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_5F),
        .mapNum = MAP_NUM(POKEMON_TOWER_5F),
        .landMonsInfo_FR = &sPokemonTower5F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower5F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_6F),
        .mapNum = MAP_NUM(POKEMON_TOWER_6F),
        .landMonsInfo_FR = &sPokemonTower6F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower6F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POKEMON_TOWER_7F),
        .mapNum = MAP_NUM(POKEMON_TOWER_7F),
        .landMonsInfo_FR = &sPokemonTower7F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPokemonTower7F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(POWER_PLANT),
        .mapNum = MAP_NUM(POWER_PLANT),
        .landMonsInfo_FR = &sPowerPlant_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sPowerPlant_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_EXTERIOR),
        .mapNum = MAP_NUM(MT_EMBER_EXTERIOR),
        .landMonsInfo_FR = &sMtEmberExterior_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberExterior_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberExterior_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberExterior_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_SUMMIT_PATH_1F),
        .mapNum = MAP_NUM(MT_EMBER_SUMMIT_PATH_1F),
        .landMonsInfo_FR = &sMtEmberSummitPath1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberSummitPath1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_SUMMIT_PATH_2F),
        .mapNum = MAP_NUM(MT_EMBER_SUMMIT_PATH_2F),
        .landMonsInfo_FR = &sMtEmberSummitPath2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberSummitPath2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberSummitPath2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberSummitPath2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_SUMMIT_PATH_3F),
        .mapNum = MAP_NUM(MT_EMBER_SUMMIT_PATH_3F),
        .landMonsInfo_FR = &sMtEmberSummitPath3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberSummitPath3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_1F),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_1F),
        .landMonsInfo_FR = &sMtEmberRubyPath1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPath1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPath1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPath1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B1F),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B1F),
        .landMonsInfo_FR = &sMtEmberRubyPathB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B2F),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B2F),
        .landMonsInfo_FR = &sMtEmberRubyPathB2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B3F),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B3F),
        .landMonsInfo_FR = &sMtEmberRubyPathB3F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB3F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB3F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB3F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B1F_STAIRS),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B1F_STAIRS),
        .landMonsInfo_FR = &sMtEmberRubyPathB1FStairs_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB1FStairs_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB1FStairs_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB1FStairs_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_EMBER_RUBY_PATH_B2F_STAIRS),
        .mapNum = MAP_NUM(MT_EMBER_RUBY_PATH_B2F_STAIRS),
        .landMonsInfo_FR = &sMtEmberRubyPathB2FStairs_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sMtEmberRubyPathB2FStairs_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sMtEmberRubyPathB2FStairs_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sMtEmberRubyPathB2FStairs_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(THREE_ISLAND_BERRY_FOREST),
        .mapNum = MAP_NUM(THREE_ISLAND_BERRY_FOREST),
        .landMonsInfo_FR = &sThreeIslandBerryForest_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sThreeIslandBerryForest_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sThreeIslandBerryForest_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sThreeIslandBerryForest_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sThreeIslandBerryForest_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sThreeIslandBerryForest_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE),
        .mapNum = MAP_NUM(FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE),
        .landMonsInfo_FR = &sFourIslandIcefallCaveEntrance_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFourIslandIcefallCaveEntrance_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sFourIslandIcefallCaveEntrance_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFourIslandIcefallCaveEntrance_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFourIslandIcefallCaveEntrance_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFourIslandIcefallCaveEntrance_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND_ICEFALL_CAVE_1F),
        .mapNum = MAP_NUM(FOUR_ISLAND_ICEFALL_CAVE_1F),
        .landMonsInfo_FR = &sFourIslandIcefallCave1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFourIslandIcefallCave1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND_ICEFALL_CAVE_B1F),
        .mapNum = MAP_NUM(FOUR_ISLAND_ICEFALL_CAVE_B1F),
        .landMonsInfo_FR = &sFourIslandIcefallCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFourIslandIcefallCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND_ICEFALL_CAVE_BACK),
        .mapNum = MAP_NUM(FOUR_ISLAND_ICEFALL_CAVE_BACK),
        .landMonsInfo_FR = &sFourIslandIcefallCaveBack_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFourIslandIcefallCaveBack_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sFourIslandIcefallCaveBack_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFourIslandIcefallCaveBack_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFourIslandIcefallCaveBack_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFourIslandIcefallCaveBack_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_PATTERN_BUSH),
        .mapNum = MAP_NUM(SIX_ISLAND_PATTERN_BUSH),
        .landMonsInfo_FR = &sSixIslandPatternBush_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandPatternBush_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM1),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM1),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom1_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom1_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM2),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM2),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom2_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom2_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM3),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM3),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom3_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom3_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM4),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM4),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom4_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom4_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM5),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM5),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom5_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom5_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM6),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM6),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom6_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom6_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM7),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM7),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom7_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom7_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM8),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM8),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom8_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom8_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM9),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM9),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom9_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom9_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM10),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM10),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom10_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom10_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM11),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM11),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom11_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom11_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM12),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM12),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom12_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom12_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM13),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM13),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom13_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom13_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_LOST_CAVE_ROOM14),
        .mapNum = MAP_NUM(FIVE_ISLAND_LOST_CAVE_ROOM14),
        .landMonsInfo_FR = &sFiveIslandLostCaveRoom14_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandLostCaveRoom14_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ONE_ISLAND_KINDLE_ROAD),
        .mapNum = MAP_NUM(ONE_ISLAND_KINDLE_ROAD),
        .landMonsInfo_FR = &sOneIslandKindleRoad_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sOneIslandKindleRoad_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sOneIslandKindleRoad_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sOneIslandKindleRoad_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sOneIslandKindleRoad_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sOneIslandKindleRoad_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sOneIslandKindleRoad_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sOneIslandKindleRoad_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ONE_ISLAND_TREASURE_BEACH),
        .mapNum = MAP_NUM(ONE_ISLAND_TREASURE_BEACH),
        .landMonsInfo_FR = &sOneIslandTreasureBeach_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sOneIslandTreasureBeach_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sOneIslandTreasureBeach_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sOneIslandTreasureBeach_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sOneIslandTreasureBeach_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sOneIslandTreasureBeach_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(TWO_ISLAND_CAPE_BRINK),
        .mapNum = MAP_NUM(TWO_ISLAND_CAPE_BRINK),
        .landMonsInfo_FR = &sTwoIslandCapeBrink_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sTwoIslandCapeBrink_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sTwoIslandCapeBrink_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sTwoIslandCapeBrink_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sTwoIslandCapeBrink_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sTwoIslandCapeBrink_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(THREE_ISLAND_BOND_BRIDGE),
        .mapNum = MAP_NUM(THREE_ISLAND_BOND_BRIDGE),
        .landMonsInfo_FR = &sThreeIslandBondBridge_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sThreeIslandBondBridge_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sThreeIslandBondBridge_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sThreeIslandBondBridge_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sThreeIslandBondBridge_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sThreeIslandBondBridge_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(THREE_ISLAND_PORT),
        .mapNum = MAP_NUM(THREE_ISLAND_PORT),
        .landMonsInfo_FR = &sThreeIslandPort_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sThreeIslandPort_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_RESORT_GORGEOUS),
        .mapNum = MAP_NUM(FIVE_ISLAND_RESORT_GORGEOUS),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFiveIslandResortGorgeous_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIslandResortGorgeous_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIslandResortGorgeous_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIslandResortGorgeous_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_WATER_LABYRINTH),
        .mapNum = MAP_NUM(FIVE_ISLAND_WATER_LABYRINTH),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFiveIslandWaterLabyrinth_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIslandWaterLabyrinth_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIslandWaterLabyrinth_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIslandWaterLabyrinth_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_MEADOW),
        .mapNum = MAP_NUM(FIVE_ISLAND_MEADOW),
        .landMonsInfo_FR = &sFiveIslandMeadow_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandMeadow_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sFiveIslandMeadow_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIslandMeadow_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIslandMeadow_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIslandMeadow_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND_MEMORIAL_PILLAR),
        .mapNum = MAP_NUM(FIVE_ISLAND_MEMORIAL_PILLAR),
        .landMonsInfo_FR = &sFiveIslandMemorialPillar_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sFiveIslandMemorialPillar_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sFiveIslandMemorialPillar_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIslandMemorialPillar_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIslandMemorialPillar_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIslandMemorialPillar_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_OUTCAST_ISLAND),
        .mapNum = MAP_NUM(SIX_ISLAND_OUTCAST_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSixIslandOutcastIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSixIslandOutcastIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSixIslandOutcastIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSixIslandOutcastIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_GREEN_PATH),
        .mapNum = MAP_NUM(SIX_ISLAND_GREEN_PATH),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSixIslandGreenPath_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSixIslandGreenPath_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSixIslandGreenPath_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSixIslandGreenPath_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_WATER_PATH),
        .mapNum = MAP_NUM(SIX_ISLAND_WATER_PATH),
        .landMonsInfo_FR = &sSixIslandWaterPath_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandWaterPath_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSixIslandWaterPath_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSixIslandWaterPath_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSixIslandWaterPath_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSixIslandWaterPath_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_RUIN_VALLEY),
        .mapNum = MAP_NUM(SIX_ISLAND_RUIN_VALLEY),
        .landMonsInfo_FR = &sSixIslandRuinValley_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandRuinValley_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sSixIslandRuinValley_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSixIslandRuinValley_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSixIslandRuinValley_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSixIslandRuinValley_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TRAINER_TOWER),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TRAINER_TOWER),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSevenIslandTrainerTower_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSevenIslandTrainerTower_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSevenIslandTrainerTower_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSevenIslandTrainerTower_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE),
        .mapNum = MAP_NUM(SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE),
        .landMonsInfo_FR = &sSevenIslandSevaultCanyonEntrance_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandSevaultCanyonEntrance_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_SEVAULT_CANYON),
        .mapNum = MAP_NUM(SEVEN_ISLAND_SEVAULT_CANYON),
        .landMonsInfo_FR = &sSevenIslandSevaultCanyon_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSevenIslandSevaultCanyon_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sSevenIslandSevaultCanyon_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sSevenIslandSevaultCanyon_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS),
        .mapNum = MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sSevenIslandTanobyRuins_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSevenIslandTanobyRuins_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sSevenIslandTanobyRuins_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSevenIslandTanobyRuins_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE1),
        .mapNum = MAP_NUM(ROUTE1),
        .landMonsInfo_FR = &sRoute1_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute1_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE2),
        .mapNum = MAP_NUM(ROUTE2),
        .landMonsInfo_FR = &sRoute2_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute2_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE3),
        .mapNum = MAP_NUM(ROUTE3),
        .landMonsInfo_FR = &sRoute3_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute3_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE4),
        .mapNum = MAP_NUM(ROUTE4),
        .landMonsInfo_FR = &sRoute4_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute4_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute4_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute4_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute4_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute4_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE5),
        .mapNum = MAP_NUM(ROUTE5),
        .landMonsInfo_FR = &sRoute5_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute5_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE6),
        .mapNum = MAP_NUM(ROUTE6),
        .landMonsInfo_FR = &sRoute6_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute6_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute6_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute6_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute6_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute6_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE7),
        .mapNum = MAP_NUM(ROUTE7),
        .landMonsInfo_FR = &sRoute7_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute7_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE8),
        .mapNum = MAP_NUM(ROUTE8),
        .landMonsInfo_FR = &sRoute8_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute8_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE9),
        .mapNum = MAP_NUM(ROUTE9),
        .landMonsInfo_FR = &sRoute9_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute9_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE10),
        .mapNum = MAP_NUM(ROUTE10),
        .landMonsInfo_FR = &sRoute10_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute10_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute10_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute10_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute10_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute10_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE11),
        .mapNum = MAP_NUM(ROUTE11),
        .landMonsInfo_FR = &sRoute11_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute11_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute11_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute11_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute11_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute11_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE12),
        .mapNum = MAP_NUM(ROUTE12),
        .landMonsInfo_FR = &sRoute12_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute12_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute12_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute12_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute12_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute12_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE13),
        .mapNum = MAP_NUM(ROUTE13),
        .landMonsInfo_FR = &sRoute13_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute13_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute13_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute13_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute13_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute13_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE14),
        .mapNum = MAP_NUM(ROUTE14),
        .landMonsInfo_FR = &sRoute14_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute14_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE15),
        .mapNum = MAP_NUM(ROUTE15),
        .landMonsInfo_FR = &sRoute15_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute15_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE16),
        .mapNum = MAP_NUM(ROUTE16),
        .landMonsInfo_FR = &sRoute16_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute16_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE17),
        .mapNum = MAP_NUM(ROUTE17),
        .landMonsInfo_FR = &sRoute17_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute17_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE18),
        .mapNum = MAP_NUM(ROUTE18),
        .landMonsInfo_FR = &sRoute18_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute18_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE19),
        .mapNum = MAP_NUM(ROUTE19),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sRoute19_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute19_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute19_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute19_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE20),
        .mapNum = MAP_NUM(ROUTE20),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sRoute20_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute20_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute20_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute20_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE21_NORTH),
        .mapNum = MAP_NUM(ROUTE21_NORTH),
        .landMonsInfo_FR = &sRoute21North_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute21North_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute21North_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute21North_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute21North_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute21North_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE21_SOUTH),
        .mapNum = MAP_NUM(ROUTE21_SOUTH),
        .landMonsInfo_FR = &sRoute21South_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute21South_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute21South_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute21South_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute21South_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute21South_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE22),
        .mapNum = MAP_NUM(ROUTE22),
        .landMonsInfo_FR = &sRoute22_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute22_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute22_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute22_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute22_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute22_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE23),
        .mapNum = MAP_NUM(ROUTE23),
        .landMonsInfo_FR = &sRoute23_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute23_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute23_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute23_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute23_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute23_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE24),
        .mapNum = MAP_NUM(ROUTE24),
        .landMonsInfo_FR = &sRoute24_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute24_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute24_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute24_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute24_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute24_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE25),
        .mapNum = MAP_NUM(ROUTE25),
        .landMonsInfo_FR = &sRoute25_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute25_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sRoute25_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sRoute25_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sRoute25_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sRoute25_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PALLET_TOWN),
        .mapNum = MAP_NUM(PALLET_TOWN),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sPalletTown_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sPalletTown_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sPalletTown_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sPalletTown_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(VIRIDIAN_CITY),
        .mapNum = MAP_NUM(VIRIDIAN_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sViridianCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sViridianCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sViridianCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sViridianCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CITY),
        .mapNum = MAP_NUM(CERULEAN_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sCeruleanCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sCeruleanCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(VERMILION_CITY),
        .mapNum = MAP_NUM(VERMILION_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sVermilionCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sVermilionCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sVermilionCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sVermilionCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CELADON_CITY),
        .mapNum = MAP_NUM(CELADON_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sCeladonCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeladonCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sCeladonCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeladonCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FUCHSIA_CITY),
        .mapNum = MAP_NUM(FUCHSIA_CITY),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFuchsiaCity_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFuchsiaCity_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFuchsiaCity_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFuchsiaCity_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CINNABAR_ISLAND),
        .mapNum = MAP_NUM(CINNABAR_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sCinnabarIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCinnabarIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sCinnabarIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCinnabarIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ONE_ISLAND),
        .mapNum = MAP_NUM(ONE_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sOneIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sOneIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sOneIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sOneIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FOUR_ISLAND),
        .mapNum = MAP_NUM(FOUR_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFourIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFourIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFourIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFourIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(FIVE_ISLAND),
        .mapNum = MAP_NUM(FIVE_ISLAND),
        .landMonsInfo_FR = NULL,
        .landMonsInfo_LG = NULL,
        .waterMonsInfo_FR = &sFiveIsland_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sFiveIsland_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = &sFiveIsland_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sFiveIsland_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_2_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_2_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_3_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_3_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_4_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_4_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_5_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_5_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_6_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_6_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_7_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_7_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_8_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_8_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SIX_ISLAND_ALTERING_CAVE),
        .mapNum = MAP_NUM(SIX_ISLAND_ALTERING_CAVE),
        .landMonsInfo_FR = &sSixIslandAlteringCave_9_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sSixIslandAlteringCave_9_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE20_UNDERWATER),
        .mapNum = MAP_NUM(ROUTE20_UNDERWATER),
        .landMonsInfo_FR = &sRoute20_Underwater_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sRoute20_Underwater_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH_WEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH_WEST),
        .landMonsInfo_FR = &sSafariZone_NorthWest_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZone_NorthWest_LandMonsInfo,
        .waterMonsInfo_FR = &sSafariZone_NorthWest_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sSafariZone_NorthWest_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sSafariZone_NorthWest_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sSafariZone_NorthWest_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sSafariZone_NorthWest_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sSafariZone_NorthWest_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH_EAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH_EAST),
        .landMonsInfo_FR = &sSafariZone_NorthEast_LandMonsInfo,
        .landMonsInfo_LG = &sSafariZone_NorthEast_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sSafariZone_NorthWest_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sSafariZone_NorthWest_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(THREE_ISLAND_BOND_BRIDGE_UNDERWATER),
        .mapNum = MAP_NUM(THREE_ISLAND_BOND_BRIDGE_UNDERWATER),
        .landMonsInfo_FR = &sThreeIslandBondBridge_Underwater_LandMonsInfo,
        .landMonsInfo_LG = &sThreeIslandBondBridge_Underwater_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_B1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_B1F),
        .landMonsInfo_FR = &sArtisanCave_LandMonsInfo,
        .landMonsInfo_LG = &sArtisanCave_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_1F),
        .landMonsInfo_FR = &sArtisanCave_LandMonsInfo,
        .landMonsInfo_LG = &sArtisanCave_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = NULL,
        .rockSmashMonsInfo_LG = NULL,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_1F_BLUE),
        .mapNum = MAP_NUM(CERULEAN_CAVE_1F_BLUE),
        .landMonsInfo_FR = &sCeruleanCave1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCave1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCave1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCave1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCave1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCave1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_2F_BLUE),
        .mapNum = MAP_NUM(CERULEAN_CAVE_2F_BLUE),
        .landMonsInfo_FR = &sCeruleanCave2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sCeruleanCave2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_B1F_BLUE),
        .mapNum = MAP_NUM(CERULEAN_CAVE_B1F_BLUE),
        .landMonsInfo_FR = &sCeruleanCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCaveB1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCaveB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCaveB1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_1F_YELLOW),
        .mapNum = MAP_NUM(CERULEAN_CAVE_1F_YELLOW),
        .landMonsInfo_FR = &sCeruleanCave1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCave1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCave1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCave1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCave1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCave1F_LeafGreen_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_2F_YELLOW),
        .mapNum = MAP_NUM(CERULEAN_CAVE_2F_YELLOW),
        .landMonsInfo_FR = &sCeruleanCave2F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCave2F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = NULL,
        .waterMonsInfo_LG = NULL,
        .rockSmashMonsInfo_FR = &sCeruleanCave2F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCave2F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = NULL,
        .fishingMonsInfo_LG = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CERULEAN_CAVE_B1F_YELLOW),
        .mapNum = MAP_NUM(CERULEAN_CAVE_B1F_YELLOW),
        .landMonsInfo_FR = &sCeruleanCaveB1F_FireRed_LandMonsInfo,
        .landMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_LandMonsInfo,
        .waterMonsInfo_FR = &sCeruleanCaveB1F_FireRed_WaterMonsInfo,
        .waterMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_WaterMonsInfo,
        .rockSmashMonsInfo_FR = &sCeruleanCaveB1F_FireRed_RockSmashMonsInfo,
        .rockSmashMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_RockSmashMonsInfo,
        .fishingMonsInfo_FR = &sCeruleanCaveB1F_FireRed_FishingMonsInfo,
        .fishingMonsInfo_LG = &sCeruleanCaveB1F_LeafGreen_FishingMonsInfo,
    },
};
