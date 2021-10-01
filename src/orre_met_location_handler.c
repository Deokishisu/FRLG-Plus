#include "global.h"
#include "pokemon.h"
#include "strings.h"
#include "string_util.h"
#include "constants/species.h"
#include "orre_met_location_strings.h"

u8* DetermineOrreMetLocation(struct Pokemon *);
u8* GetOrreMetLocationString(struct Pokemon *);
u8* ResolveOrreMetLocationCollision(struct Pokemon *);

u8 *WriteOrreMapName(u8 *dst0, u8 *string, u16 fill)
{
    u8 *dst;
    dst = StringCopy(dst0, string);
    return dst;
}

u8* DetermineOrreMetLocation(struct Pokemon *mon)
{
	u8 *stringToUse;
	u8 locationMet = GetMonData(mon, MON_DATA_MET_LOCATION);
	if(locationMet == 76 || locationMet == 109 || locationMet == 110 || locationMet == 111 || locationMet == 67 || locationMet == 69 || locationMet == 0 || locationMet == 254)
	{
		stringToUse = ResolveOrreMetLocationCollision(mon);
	}
	else
	{
		stringToUse = GetOrreMetLocationString(mon);
	}
	return (u8 *)stringToUse;
}

u8* GetOrreMetLocationString(struct Pokemon *mon)
{
	u8 locationMet = GetMonData(mon, MON_DATA_MET_LOCATION);
	const u8 *locationString;
	switch (locationMet)
	{
			//valid Colosseum locations
			case 39: //only valid Agate Village location
				locationString = gAgate_Village;
				break;
			case 125: //only valid Deep Colosseum location
				locationString = gDeep_Colosseum;
				break;
			case 68: //only valid Laboratory location
				locationString = gLaboratory;
				break;
			case 5: //only valid Mayor's House location
				locationString = gMayors_House;
				break;
			case 30: //only valid Miror's Hideout location, Remoraid and Mantine 2nd chance here or Pyrite Cave?
				locationString = gMirors_Hideout;
				break;
			case 1: //only valid Outskirt Stand location
				locationString = gOutskirt_Stand;
				break;
			case 3: //only normally valid Phenac City location
			case 128: //eReader Pokemon are from here in Phenac City
				locationString = gPhenac_City;
				break;
			case 25:
			case 28: //only valid Pyrite Building locations
				locationString = gPyrite_Bldg;
				break;
			case 29:
			case 31:
			case 32: //only valid Pyrite Cave locations
				locationString = gPyrite_Cave;
				break;
			case 15: //only valid Pyrite Town location
				locationString = gPyrite_Town;
				break;
			case 115:
			case 117: //valid Realgam Tower locations; see below comment
				locationString = gRealgam_Tower;
				break;
			case 104:
			case 106: //Do these three display as Realgam Tower instead in game?
			case 113: //only valid RealgamTwr Dome locations
				locationString = gRealgamTwr_Dome;
				break;
			case 132:
			case 133:
			case 134: //only valid Snagem Hideout locations
				locationString = gSnagem_Hideout;
				break;
			case 47:
			case 55: //only valid The Under locations
				locationString = gThe_Under;
				break;
			case 58: //only valid The Under Subway location
				locationString = gThe_Under_Subway;
				break;
			case 118: //only valid Tower Colosseum location
				locationString = gTower_Colosseum;
				break;
			//valid XD locations
			case 92: //only valid Cave Poke Spot location
				locationString = gCave;
				break;
			case 64:
			case 65:
			case 66:
			case 70:
			case 71: //only valid Cipher Key Lair locations
				locationString = gCipher_Key_Lair;
				break;
			case 8:
			case 9:
			case 10:
			case 11: //only valid Cipher Lab locations
				locationString = gCipher_Lab;
				break;
			case 73:
			case 74:
			case 75:
			case 77:
			case 80:
			case 81:
			case 84:
			case 85:
			case 87:
			case 88: //only valid Citadark Isle locations
				locationString = gCitadark_Isle;
				break;
			case 153:
			case 162: //only valid Gateon Port locations
				locationString = gGateon_Port;
				break;
			case 16: //only valid Mt. Battle location; gift Johto Starters
				locationString = gMt_Battle;
				break;
			case 91: //only valid Oasis Poke Spot location
				locationString = gOasis;
				break;
			case 164: //only valid Outskirt Stand location
				locationString = gOutskirt_Stand;
				break;
			case 94:
			case 96:
			case 97:
			case 100:
			case 107: //only valid Phenac City locations
				locationString = gPhenac_City;
				break;
			case 143: //only valid Pokemon HQ Lab location
				locationString = gPokemon_HQ_Lab;
				break;
			case 116:
			case 119: //only valid Pyrite Town locations
				locationString = gPyrite_Town;
				break;
			case 59: //only valid Realgam Tower location
				locationString = gRealgam_Tower;
				break;
			case 90: //only valid Rock Poke Spot location
				locationString = gRock;
				break;
			default: //if any other location index is present, use generic distant land text.
				locationString = gOtherText_MetDistantLand;
				break;
	}
	return (u8 *)locationString;
}

u8* ResolveOrreMetLocationCollision(struct Pokemon *mon)
{
	u16 species;
	u8 locationMet;
	u8 language;
	const u8 *locationString;
    u8 obedient = GetMonData(mon, MON_DATA_EVENT_LEGAL); //all XD Pokemon have this bit set
	locationMet = GetMonData(mon, MON_DATA_MET_LOCATION);
	species = GetMonData(mon, MON_DATA_SPECIES);
	language = GetMonData(mon, MON_DATA_LANGUAGE);
	switch (locationMet)
	{
		case 67:
		case 69: //Colosseum: Laboratory; XD: Cipher Key Lair
			//if(species == SPECIES_PRIMEAPE || species == SPECIES_HYPNO || species == SPECIES_TANGELA || species == SPECIES_BUTTERFREE || species == SPECIES_MAGNETON)
            if(obedient)
				locationString = gCipher_Key_Lair;
			else
				locationString = gLaboratory;
			break;
		case 76: //Colosseum: Mt. Battle; XD: Citadark Isle
			//if(species == SPECIES_ENTEI)
            if(!obedient)
				locationString = gMt_Battle;
			else
				locationString = gCitadark_Isle;
			break;
		case 109:
		case 110:
		case 111: //Colosseum: RealgamTwr Dome; XD: Pyrite Town
			//if(species == SPECIES_SUNFLORA || species == SPECIES_DELIBIRD || species == SPECIES_SUICUNE || species == SPECIES_HERACROSS)
            if(!obedient)
				locationString = gRealgamTwr_Dome;
			else
				locationString = gPyrite_Town;
			break;
		case 0: //XD Starter Eevee
			if((species >= SPECIES_EEVEE && species <= SPECIES_FLAREON) || species == SPECIES_ESPEON || species == SPECIES_UMBREON)
			{
				if(language == LANGUAGE_JAPANESE)
					locationString = gXD_Eevee_Met_Location_JP;
				else
					locationString = gXD_Eevee_Met_Location;
			}
			break;
		case 254: //Colosseum Starter Espeon and Umbreon and Duking's Plusle
			if(species == SPECIES_ESPEON || species == SPECIES_UMBREON)
			{
				if(language == LANGUAGE_JAPANESE)
					locationString = gColosseum_Starter_Met_Location_JP;
				else
					locationString = gColosseum_Starter_Met_Location;
			}
			else
			{
				if(language == LANGUAGE_JAPANESE)
					locationString = gDukings_Plusle_JP;
				else
					locationString = gDukings_Plusle;
			}
			break;
		default: //error handler; default to generic distant land text
			locationString = gOtherText_MetDistantLand;
			break;
	}
	return (u8 *)locationString;
}