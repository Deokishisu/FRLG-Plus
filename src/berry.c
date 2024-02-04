#include "global.h"
#include "berry.h"
#include "text.h"
#include "constants/items.h"

static const u8 sBerryDescriptionPart1_Cheri[] = _("Blooms with delicate pretty flowers.");
static const u8 sBerryDescriptionPart2_Cheri[] = _("The bright red BERRY is very spicy.");
static const u8 sBerryDescriptionPart1_Chesto[] = _("The BERRY's thick skin and fruit are");
static const u8 sBerryDescriptionPart2_Chesto[] = _("very tough. It is dry-tasting all over.");
static const u8 sBerryDescriptionPart1_Pecha[] = _("Very sweet and delicious.");
static const u8 sBerryDescriptionPart2_Pecha[] = _("Also very tender - handle with care.");
static const u8 sBerryDescriptionPart1_Rawst[] = _("If the leaves grow long and curly,");
static const u8 sBerryDescriptionPart2_Rawst[] = _("the BERRY seems to grow very bitter.");
static const u8 sBerryDescriptionPart1_Aspear[] = _("The hard BERRY is dense with a rich");
static const u8 sBerryDescriptionPart2_Aspear[] = _("juice. It is quite sour.");
static const u8 sBerryDescriptionPart1_Leppa[] = _("Grows slower than CHERI and others.");
static const u8 sBerryDescriptionPart2_Leppa[] = _("The smaller the BERRY, the tastier.");
static const u8 sBerryDescriptionPart1_Oran[] = _("A peculiar BERRY with a mix of flavors.");
static const u8 sBerryDescriptionPart2_Oran[] = _("BERRIES grow in half a day.");
static const u8 sBerryDescriptionPart1_Persim[] = _("Loves sunlight. The BERRY's color");
static const u8 sBerryDescriptionPart2_Persim[] = _("grows vivid when exposed to the sun.");
static const u8 sBerryDescriptionPart1_Lum[] = _("Slow to grow. If raised with loving");
static const u8 sBerryDescriptionPart2_Lum[] = _("care, it may grow two BERRIES.");
static const u8 sBerryDescriptionPart1_Sitrus[] = _("Closely related to ORAN. The large");
static const u8 sBerryDescriptionPart2_Sitrus[] = _("BERRY has a well-rounded flavor.");
static const u8 sBerryDescriptionPart1_Figy[] = _("The BERRY, which looks chewed up,");
static const u8 sBerryDescriptionPart2_Figy[] = _("brims with spicy substances.");
static const u8 sBerryDescriptionPart1_Wiki[] = _("The BERRY is said to have grown lumpy");
static const u8 sBerryDescriptionPart2_Wiki[] = _("to help POKéMON grip it.");
static const u8 sBerryDescriptionPart1_Mago[] = _("The BERRY turns curvy as it grows.");
static const u8 sBerryDescriptionPart2_Mago[] = _("The curvier, the sweeter and tastier.");
static const u8 sBerryDescriptionPart1_Aguav[] = _("The flower is dainty. It is rare in its");
static const u8 sBerryDescriptionPart2_Aguav[] = _("ability to grow without light.");
static const u8 sBerryDescriptionPart1_Iapapa[] = _("The BERRY is very big and sour.");
static const u8 sBerryDescriptionPart2_Iapapa[] = _("It takes at least a day to grow.");
static const u8 sBerryDescriptionPart1_Razz[] = _("The red BERRY tastes slightly spicy.");
static const u8 sBerryDescriptionPart2_Razz[] = _("It grows quickly in just four hours.");
static const u8 sBerryDescriptionPart1_Bluk[] = _("The BERRY is blue on the outside, but");
static const u8 sBerryDescriptionPart2_Bluk[] = _("it blackens the mouth when eaten.");
static const u8 sBerryDescriptionPart1_Nanab[] = _("This BERRY was the seventh");
static const u8 sBerryDescriptionPart2_Nanab[] = _("discovered in the world. It is sweet.");
static const u8 sBerryDescriptionPart1_Wepear[] = _("The flower is small and white. It has a");
static const u8 sBerryDescriptionPart2_Wepear[] = _("delicate balance of bitter and sour.");
static const u8 sBerryDescriptionPart1_Pinap[] = _("Weak against wind and cold.");
static const u8 sBerryDescriptionPart2_Pinap[] = _("The fruit is spicy and the skin, sour.");
static const u8 sBerryDescriptionPart1_Pomeg[] = _("However much it is watered,");
static const u8 sBerryDescriptionPart2_Pomeg[] = _("it only grows up to six BERRIES.");
static const u8 sBerryDescriptionPart1_Kelpsy[] = _("A rare variety shaped like a root.");
static const u8 sBerryDescriptionPart2_Kelpsy[] = _("Grows a very large flower.");
static const u8 sBerryDescriptionPart1_Qualot[] = _("Loves water. Grows strong even in");
static const u8 sBerryDescriptionPart2_Qualot[] = _("locations with constant rainfall.");
static const u8 sBerryDescriptionPart1_Hondew[] = _("A BERRY that is very valuable and");
static const u8 sBerryDescriptionPart2_Hondew[] = _("rarely seen. It is very delicious.");
static const u8 sBerryDescriptionPart1_Grepa[] = _("Despite its tenderness and round");
static const u8 sBerryDescriptionPart2_Grepa[] = _("shape, the BERRY is unimaginably sour.");
static const u8 sBerryDescriptionPart1_Tamato[] = _("The BERRY is lip-bendingly spicy.");
static const u8 sBerryDescriptionPart2_Tamato[] = _("It takes time to grow.");
static const u8 sBerryDescriptionPart1_Cornn[] = _("A BERRY from an ancient era. May not");
static const u8 sBerryDescriptionPart2_Cornn[] = _("grow unless planted in quantity.");
static const u8 sBerryDescriptionPart1_Magost[] = _("A BERRY that is widely said to have");
static const u8 sBerryDescriptionPart2_Magost[] = _("a finely balanced flavor.");
static const u8 sBerryDescriptionPart1_Rabuta[] = _("A rare variety that is overgrown with");
static const u8 sBerryDescriptionPart2_Rabuta[] = _("hair. It is quite bitter.");
static const u8 sBerryDescriptionPart1_Nomel[] = _("Quite sour. Just one bite makes it");
static const u8 sBerryDescriptionPart2_Nomel[] = _("impossible to taste for three days.");
static const u8 sBerryDescriptionPart1_Spelon[] = _("The vividly red BERRY is very spicy.");
static const u8 sBerryDescriptionPart2_Spelon[] = _("Its warts secrete a spicy substance.");
static const u8 sBerryDescriptionPart1_Pamtre[] = _("Drifts on the sea from somewhere.");
static const u8 sBerryDescriptionPart2_Pamtre[] = _("It is thought to grow elsewhere.");
static const u8 sBerryDescriptionPart1_Watmel[] = _("A huge BERRY, with some over 20");
static const u8 sBerryDescriptionPart2_Watmel[] = _("inches discovered. Exceedingly sweet.");
static const u8 sBerryDescriptionPart1_Durin[] = _("Bitter to even look at. It is so");
static const u8 sBerryDescriptionPart2_Durin[] = _("bitter, no one has ever eaten it as is.");
static const u8 sBerryDescriptionPart1_Belue[] = _("It is glossy and looks delicious, but");
static const u8 sBerryDescriptionPart2_Belue[] = _("it is awfully sour. Takes time to grow.");
static const u8 sBerryDescriptionPart1_Liechi[] = _("A mysterious BERRY. It is rumored to");
static const u8 sBerryDescriptionPart2_Liechi[] = _("contain the power of the sea.");
static const u8 sBerryDescriptionPart1_Ganlon[] = _("A mysterious BERRY. It is rumored to");
static const u8 sBerryDescriptionPart2_Ganlon[] = _("contain the power of the land.");
static const u8 sBerryDescriptionPart1_Salac[] = _("A mysterious BERRY. It is rumored to");
static const u8 sBerryDescriptionPart2_Salac[] = _("contain the power of the sky.");
static const u8 sBerryDescriptionPart1_Petaya[] = _("A mysterious BERRY. It is rumored to");
static const u8 sBerryDescriptionPart2_Petaya[] = _("contain the power of all living things.");
static const u8 sBerryDescriptionPart1_Apicot[] = _("A very mystifying BERRY. No telling");
static const u8 sBerryDescriptionPart2_Apicot[] = _("what may happen or how it can be used.");
static const u8 sBerryDescriptionPart1_Lansat[] = _("Said to be a legendary BERRY.");
static const u8 sBerryDescriptionPart2_Lansat[] = _("Holding it supposedly brings joy.");
static const u8 sBerryDescriptionPart1_Starf[] = _("So strong, it was abandoned at the");
static const u8 sBerryDescriptionPart2_Starf[] = _("world's edge. Considered a mirage.");
static const u8 sBerryDescriptionPart1_Enigma[] = _("A completely enigmatic BERRY.");
static const u8 sBerryDescriptionPart2_Enigma[] = _("Appears to have the power of stars.");

const struct Berry gBerries[] = {
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("CHERI"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 20,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Cheri,
            .description2 = sBerryDescriptionPart2_Cheri,
            .stageDuration = 3,
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25
        },

    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("CHESTO"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .size = 80,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Chesto,
            .description2 = sBerryDescriptionPart2_Chesto,
            .stageDuration = 3,
            .spicy = 0,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25
        },

    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("PECHA"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .size = 40,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Pecha,
            .description2 = sBerryDescriptionPart2_Pecha,
            .stageDuration = 3,
            .spicy = 0,
            .dry = 0,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25
        },

    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("RAWST"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 32,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Rawst,
            .description2 = sBerryDescriptionPart2_Rawst,
            .stageDuration = 3,
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 10,
            .sour = 0,
            .smoothness = 25
        },

    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("ASPEAR"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .size = 50,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Aspear,
            .description2 = sBerryDescriptionPart2_Aspear,
            .stageDuration = 3,
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 10,
            .smoothness = 25
        },

    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("LEPPA"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .size = 28,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Leppa,
            .description2 = sBerryDescriptionPart2_Leppa,
            .stageDuration = 4,
            .spicy = 10,
            .dry = 0,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("ORAN"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .size = 35,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Oran,
            .description2 = sBerryDescriptionPart2_Oran,
            .stageDuration = 3,
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("PERSIM"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 47,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Persim,
            .description2 = sBerryDescriptionPart2_Persim,
            .stageDuration = 3,
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("LUM"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .size = 34,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Lum,
            .description2 = sBerryDescriptionPart2_Lum,
            .stageDuration = 12,
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("SITRUS"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .size = 95,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Sitrus,
            .description2 = sBerryDescriptionPart2_Sitrus,
            .stageDuration = 6,
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("FIGY"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 100,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Figy,
            .description2 = sBerryDescriptionPart2_Figy,
            .stageDuration = 6,
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25
        },

    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("WIKI"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 115,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Wiki,
            .description2 = sBerryDescriptionPart2_Wiki,
            .stageDuration = 6,
            .spicy = 0,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25
        },

    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("MAGO"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 126,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Mago,
            .description2 = sBerryDescriptionPart2_Mago,
            .stageDuration = 6,
            .spicy = 0,
            .dry = 0,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 25
        },

    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("AGUAV"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .size = 64,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Aguav,
            .description2 = sBerryDescriptionPart2_Aguav,
            .stageDuration = 6,
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 10,
            .sour = 0,
            .smoothness = 25
        },

    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("IAPAPA"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 223,
            .maxYield = 3,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Iapapa,
            .description2 = sBerryDescriptionPart2_Iapapa,
            .stageDuration = 6,
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 10,
            .smoothness = 25
        },

    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("RAZZ"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .size = 120,
            .maxYield = 6,
            .minYield = 3,
            .description1 = sBerryDescriptionPart1_Razz,
            .description2 = sBerryDescriptionPart2_Razz,
            .stageDuration = 1,
            .spicy = 10,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 20
        },

    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("BLUK"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 108,
            .maxYield = 6,
            .minYield = 3,
            .description1 = sBerryDescriptionPart1_Bluk,
            .description2 = sBerryDescriptionPart2_Bluk,
            .stageDuration = 1,
            .spicy = 0,
            .dry = 10,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 20
        },

    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("NANAB"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .size = 77,
            .maxYield = 6,
            .minYield = 3,
            .description1 = sBerryDescriptionPart1_Nanab,
            .description2 = sBerryDescriptionPart2_Nanab,
            .stageDuration = 1,
            .spicy = 0,
            .dry = 0,
            .sweet = 10,
            .bitter = 10,
            .sour = 0,
            .smoothness = 20
        },

    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("WEPEAR"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .size = 74,
            .maxYield = 6,
            .minYield = 3,
            .description1 = sBerryDescriptionPart1_Wepear,
            .description2 = sBerryDescriptionPart2_Wepear,
            .stageDuration = 1,
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("PINAP"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 80,
            .maxYield = 6,
            .minYield = 3,
            .description1 = sBerryDescriptionPart1_Pinap,
            .description2 = sBerryDescriptionPart2_Pinap,
            .stageDuration = 1,
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("POMEG"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .size = 135,
            .maxYield = 6,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Pomeg,
            .description2 = sBerryDescriptionPart2_Pomeg,
            .stageDuration = 3,
            .spicy = 10,
            .dry = 0,
            .sweet = 10,
            .bitter = 10,
            .sour = 0,
            .smoothness = 20
        },

    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("KELPSY"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 150,
            .maxYield = 6,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Kelpsy,
            .description2 = sBerryDescriptionPart2_Kelpsy,
            .stageDuration = 3,
            .spicy = 0,
            .dry = 10,
            .sweet = 0,
            .bitter = 10,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("QUALOT"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 110,
            .maxYield = 6,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Qualot,
            .description2 = sBerryDescriptionPart2_Qualot,
            .stageDuration = 3,
            .spicy = 10,
            .dry = 0,
            .sweet = 10,
            .bitter = 0,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("HONDEW"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 162,
            .maxYield = 6,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Hondew,
            .description2 = sBerryDescriptionPart2_Hondew,
            .stageDuration = 3,
            .spicy = 10,
            .dry = 10,
            .sweet = 0,
            .bitter = 10,
            .sour = 0,
            .smoothness = 20
        },

    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("GREPA"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 149,
            .maxYield = 6,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Grepa,
            .description2 = sBerryDescriptionPart2_Grepa,
            .stageDuration = 3,
            .spicy = 0,
            .dry = 10,
            .sweet = 10,
            .bitter = 0,
            .sour = 10,
            .smoothness = 20
        },

    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("TAMATO"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 200,
            .maxYield = 4,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Tamato,
            .description2 = sBerryDescriptionPart2_Tamato,
            .stageDuration = 6,
            .spicy = 20,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 30
        },

    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("CORNN"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 75,
            .maxYield = 4,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Cornn,
            .description2 = sBerryDescriptionPart2_Cornn,
            .stageDuration = 6,
            .spicy = 0,
            .dry = 20,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 30
        },

    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("MAGOST"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 140,
            .maxYield = 4,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Magost,
            .description2 = sBerryDescriptionPart2_Magost,
            .stageDuration = 6,
            .spicy = 0,
            .dry = 0,
            .sweet = 20,
            .bitter = 10,
            .sour = 0,
            .smoothness = 30
        },

    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("RABUTA"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 226,
            .maxYield = 4,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Rabuta,
            .description2 = sBerryDescriptionPart2_Rabuta,
            .stageDuration = 6,
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 20,
            .sour = 10,
            .smoothness = 30
        },

    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("NOMEL"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .size = 285,
            .maxYield = 4,
            .minYield = 2,
            .description1 = sBerryDescriptionPart1_Nomel,
            .description2 = sBerryDescriptionPart2_Nomel,
            .stageDuration = 6,
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 20,
            .smoothness = 30
        },

    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("SPELON"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 133,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Spelon,
            .description2 = sBerryDescriptionPart2_Spelon,
            .stageDuration = 18,
            .spicy = 40,
            .dry = 10,
            .sweet = 0,
            .bitter = 0,
            .sour = 0,
            .smoothness = 70
        },

    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("PAMTRE"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .size = 244,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Pamtre,
            .description2 = sBerryDescriptionPart2_Pamtre,
            .stageDuration = 18,
            .spicy = 0,
            .dry = 40,
            .sweet = 10,
            .bitter = 0,
            .sour = 0,
            .smoothness = 70
        },

    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("WATMEL"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 250,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Watmel,
            .description2 = sBerryDescriptionPart2_Watmel,
            .stageDuration = 18,
            .spicy = 0,
            .dry = 0,
            .sweet = 40,
            .bitter = 10,
            .sour = 0,
            .smoothness = 70
        },

    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("DURIN"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 280,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Durin,
            .description2 = sBerryDescriptionPart2_Durin,
            .stageDuration = 18,
            .spicy = 0,
            .dry = 0,
            .sweet = 0,
            .bitter = 40,
            .sour = 10,
            .smoothness = 70
        },

    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("BELUE"),
            .firmness = BERRY_FIRMNESS_VERY_SOFT,
            .size = 300,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Belue,
            .description2 = sBerryDescriptionPart2_Belue,
            .stageDuration = 18,
            .spicy = 10,
            .dry = 0,
            .sweet = 0,
            .bitter = 0,
            .sour = 40,
            .smoothness = 70
        },

    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("LIECHI"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .size = 111,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Liechi,
            .description2 = sBerryDescriptionPart2_Liechi,
            .stageDuration = 24,
            .spicy = 40,
            .dry = 0,
            .sweet = 40,
            .bitter = 0,
            .sour = 10,
            .smoothness = 80
        },

    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("GANLON"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .size = 33,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Ganlon,
            .description2 = sBerryDescriptionPart2_Ganlon,
            .stageDuration = 24,
            .spicy = 0,
            .dry = 40,
            .sweet = 0,
            .bitter = 40,
            .sour = 0,
            .smoothness = 80
        },

    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("SALAC"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .size = 95,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Salac,
            .description2 = sBerryDescriptionPart2_Salac,
            .stageDuration = 24,
            .spicy = 0,
            .dry = 0,
            .sweet = 40,
            .bitter = 0,
            .sour = 40,
            .smoothness = 80
        },

    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("PETAYA"),
            .firmness = BERRY_FIRMNESS_VERY_HARD,
            .size = 237,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Petaya,
            .description2 = sBerryDescriptionPart2_Petaya,
            .stageDuration = 24,
            .spicy = 40,
            .dry = 0,
            .sweet = 0,
            .bitter = 40,
            .sour = 0,
            .smoothness = 80
        },

    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("APICOT"),
            .firmness = BERRY_FIRMNESS_HARD,
            .size = 75,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Apicot,
            .description2 = sBerryDescriptionPart2_Apicot,
            .stageDuration = 24,
            .spicy = 0,
            .dry = 40,
            .sweet = 0,
            .bitter = 0,
            .sour = 40,
            .smoothness = 80
        },

    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("LANSAT"),
            .firmness = BERRY_FIRMNESS_SOFT,
            .size = 97,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Lansat,
            .description2 = sBerryDescriptionPart2_Lansat,
            .stageDuration = 24,
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 30
        },

    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("STARF"),
            .firmness = BERRY_FIRMNESS_SUPER_HARD,
            .size = 153,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Starf,
            .description2 = sBerryDescriptionPart2_Starf,
            .stageDuration = 24,
            .spicy = 10,
            .dry = 10,
            .sweet = 10,
            .bitter = 10,
            .sour = 10,
            .smoothness = 30
        },

    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] =
        {
            .name = _("ENIGMA"),
            .firmness = BERRY_FIRMNESS_UNKNOWN,
            .size = 0,
            .maxYield = 2,
            .minYield = 1,
            .description1 = sBerryDescriptionPart1_Enigma,
            .description2 = sBerryDescriptionPart2_Enigma,
            .stageDuration = 24,
            .spicy = 40,
            .dry = 40,
            .sweet = 40,
            .bitter = 40,
            .sour = 40,
            .smoothness = 40
        },

};

const struct BerryCrushStats gBerryCrush_BerryData[] = {
    [ITEM_CHERI_BERRY  - FIRST_BERRY_INDEX] = { 50,  20},
    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] = { 50,  20},
    [ITEM_PECHA_BERRY  - FIRST_BERRY_INDEX] = { 50,  20},
    [ITEM_RAWST_BERRY  - FIRST_BERRY_INDEX] = { 50,  20},
    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] = { 50,  20},
    [ITEM_LEPPA_BERRY  - FIRST_BERRY_INDEX] = { 50,  30},
    [ITEM_ORAN_BERRY   - FIRST_BERRY_INDEX] = { 50,  30},
    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] = { 50,  30},
    [ITEM_LUM_BERRY    - FIRST_BERRY_INDEX] = { 50,  30},
    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] = { 50,  30},
    [ITEM_FIGY_BERRY   - FIRST_BERRY_INDEX] = { 60,  50},
    [ITEM_WIKI_BERRY   - FIRST_BERRY_INDEX] = { 60,  50},
    [ITEM_MAGO_BERRY   - FIRST_BERRY_INDEX] = { 60,  50},
    [ITEM_AGUAV_BERRY  - FIRST_BERRY_INDEX] = { 60,  50},
    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] = { 60,  50},
    [ITEM_RAZZ_BERRY   - FIRST_BERRY_INDEX] = { 80,  70},
    [ITEM_BLUK_BERRY   - FIRST_BERRY_INDEX] = { 80,  70},
    [ITEM_NANAB_BERRY  - FIRST_BERRY_INDEX] = { 80,  70},
    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] = { 80,  70},
    [ITEM_PINAP_BERRY  - FIRST_BERRY_INDEX] = { 80,  70},
    [ITEM_POMEG_BERRY  - FIRST_BERRY_INDEX] = {100, 100},
    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] = {100, 100},
    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] = {100, 100},
    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] = {100, 100},
    [ITEM_GREPA_BERRY  - FIRST_BERRY_INDEX] = {100, 100},
    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] = {130, 150},
    [ITEM_CORNN_BERRY  - FIRST_BERRY_INDEX] = {130, 150},
    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] = {130, 150},
    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] = {130, 150},
    [ITEM_NOMEL_BERRY  - FIRST_BERRY_INDEX] = {130, 150},
    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] = {160, 250},
    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] = {160, 250},
    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] = {160, 250},
    [ITEM_DURIN_BERRY  - FIRST_BERRY_INDEX] = {160, 250},
    [ITEM_BELUE_BERRY  - FIRST_BERRY_INDEX] = {160, 250},
    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] = {180, 500},
    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] = {180, 500},
    [ITEM_SALAC_BERRY  - FIRST_BERRY_INDEX] = {180, 500},
    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] = {180, 500},
    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] = {180, 500},
    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] = {200, 750},
    [ITEM_STARF_BERRY  - FIRST_BERRY_INDEX] = {200, 750},
    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] = {150, 200}
};

// Leftover from R/S
const struct BerryTree gBlankBerryTree = {};

#define ENIGMA_BERRY_STRUCT ({ \
    const struct Berry2 * berries = (const struct Berry2 *)gBerries; \
    berries[ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX]; \
})

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *);

void InitEnigmaBerry(void)
{
    s32 i;

    gSaveBlock1Ptr->enigmaBerry.berry = ENIGMA_BERRY_STRUCT;
    for (i = 0; i < 18; i++)
        gSaveBlock1Ptr->enigmaBerry.itemEffect[i] = 0;
    gSaveBlock1Ptr->enigmaBerry.holdEffect = 0;
    gSaveBlock1Ptr->enigmaBerry.holdEffectParam = 0;
    gSaveBlock1Ptr->enigmaBerry.checksum = GetEnigmaBerryChecksum(&gSaveBlock1Ptr->enigmaBerry);
}

void ClearEnigmaBerries(void)
{
    CpuFill16(0, &gSaveBlock1Ptr->enigmaBerry, sizeof(gSaveBlock1Ptr->enigmaBerry));
    InitEnigmaBerry();
}

struct ReceivedEnigmaBerry
{
    struct Berry2 berry;
    u8 unk_001C[0x4FA];
    u8 itemEffect[18];
    u8 holdEffect;
    u8 holdEffectParam;
};

void SetEnigmaBerry(u8 * berry)
{
    struct EnigmaBerry * enigmaBerry;
    struct ReceivedEnigmaBerry * src2;
    s32 i;

    ClearEnigmaBerries();

    src2 = (struct ReceivedEnigmaBerry *)berry;
    enigmaBerry = &gSaveBlock1Ptr->enigmaBerry;

    enigmaBerry->berry = src2->berry;
    for (i = 0; i < 18; i++)
        enigmaBerry->itemEffect[i] = src2->itemEffect[i];
    enigmaBerry->holdEffect = src2->holdEffect;
    enigmaBerry->holdEffectParam = src2->holdEffectParam;
    enigmaBerry->checksum = GetEnigmaBerryChecksum(enigmaBerry);
}

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry * enigmaBerry)
{
    const u8 * src = (const u8 *)enigmaBerry;
    u32 result = 0;
    u32 i;

    for (i = 0; i < offsetof(struct EnigmaBerry, checksum); i++)
        result += src[i];

    return result;
}

bool32 IsEnigmaBerryValid(void)
{
    if (gSaveBlock1Ptr->enigmaBerry.berry.stageDuration == 0)
        return FALSE;
    if (gSaveBlock1Ptr->enigmaBerry.berry.maxYield == 0)
        return FALSE;
    if (GetEnigmaBerryChecksum(&gSaveBlock1Ptr->enigmaBerry) != gSaveBlock1Ptr->enigmaBerry.checksum)
        return FALSE;

    return TRUE;
}

const struct Berry * GetBerryInfo(u8 berryIdx)
{
    if (berryIdx == ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) && IsEnigmaBerryValid())
        return (struct Berry *)&gSaveBlock1Ptr->enigmaBerry.berry;

    if (berryIdx == 0 || berryIdx > ITEM_TO_BERRY(ITEM_ENIGMA_BERRY))
        berryIdx = 1;

    return &gBerries[berryIdx - 1];
}

u8 ItemIdToBerryType(u16 itemId)
{
    if (itemId - FIRST_BERRY_INDEX < 0 || itemId - FIRST_BERRY_INDEX > ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX)
        return 1;

    return ITEM_TO_BERRY(itemId);
}

u16 BerryTypeToItemId(u16 berryType)
{
    if (berryType - 1 < 0 || berryType - 1 > ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX)
        return FIRST_BERRY_INDEX;

    return berryType + FIRST_BERRY_INDEX - 1;
}

void GetBerryNameByBerryType(u8 berryType, u8 * dest)
{
    const struct Berry * berry = GetBerryInfo(berryType);
    memcpy(dest, berry->name, 6);
    dest[6] = EOS;
}
