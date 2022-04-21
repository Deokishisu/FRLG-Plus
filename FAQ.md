 # **Frequently Asked Questions**

### How can I support development?
[I have a Ko-fi link](https://ko-fi.com/deokishisu), tips are appreciated!

# Table of Contents:
* Mechanics:
  * [Will later-generation battle mechanics be implemented? What about the physical/special split?](#will-later-generation-battle-mechanics-be-implemented-what-about-the-physicalspecial-split)
  * [Will new moves be implemented? New held items?](#will-new-moves-be-implemented-new-held-items)
  * [Will the Gen 6+ Experience Share be implemented?](#will-the-gen-6-experience-share-be-implemented)
  * [Will you improve breeding mechanics?](#will-you-improve-breeding-mechanics)
  * [What are the shiny chances? Will they be improved?](#what-are-the-shiny-chances-will-they-be-improved)
  * [Will you add something to change my Pokémon's IVs/Hidden Power/Nature/etc.?](#will-you-add-something-to-change-my-pokémons-ivshidden-powernatureetc)
* Pokémon Availability:
  * [Will you add later-generation Pokémon?](#will-you-add-later-generation-pokémon)
  * [How many Pokémon are available? Will *all* Pokémon be catchable?](#how-many-pokémon-are-available-will-all-pokémon-be-catchable)
  * [Can you change wild Pokémon availability/levels? Can you put *x* Pokémon in *y* map? Will you add more Pokémon in the future?](#can-you-change-wild-pokémon-availabilitylevels-can-you-put-x-pokémon-in-y-map-will-you-add-more-pokémon-in-the-future)
  * [Is there a list of wild encounter tables?](#is-there-a-list-of-wild-encounter-tables)
  * [Can I obtain the other Kanto starters? Can I obtain the unchosen fossil?](#can-i-obtain-the-other-kanto-starters-can-i-obtain-the-unchosen-fossil)
  * [Can I evolve my Kanto Pokémon into their Johto evolutions without the National Dex?](#can-i-evolve-my-kanto-pokémon-into-their-johto-evolutions-without-the-national-dex)
  * [How do I evolve Eevee into Espeon and Umbreon?](#how-do-i-evolve-eevee-into-espeon-and-umbreon)
  * [Can I evolve trade evolutions without trading?](#can-i-evolve-trade-evolutions-without-trading)
  * [Are trade evolution items available before the postgame?](#are-trade-evolution-items-available-before-the-postgame)
  * [Where do I get the event tickets so I can obtain Mew, Lugia and Ho-oh, Deoxys, and Latias and Latias?](#where-do-i-get-the-event-tickets-so-i-can-obtain-mew-lugia-and-ho-oh-deoxys-and-latias-and-latias)
  * [How do I get Sudowoodo to battle me?](#how-do-i-get-sudowoodo-to-battle-me)
* Troubleshooting Savefiles, Emulators, and Flashcarts:
  * [Is my vanilla FireRed or LeafGreen save compatible with FRLG+?](#is-my-vanilla-firered-or-leafgreen-save-compatible-with-frlg)
  * [My emulator/flashcart doesn't work with FRLG+! The game won't save!](#my-emulatorflashcart-doesnt-work-with-frlg-the-game-wont-save)
* Modifying FRLG+:
  * [Can I use FRLG+ as a ROM Base?](#can-i-use-frlg-as-a-rom-base)
  * [How did you implement *x* feature? Can I use *y* feature for my hack?](#how-did-you-implement-x-feature-can-i-use-y-feature-for-my-hack)
* Miscellaneous:
  * [Will text be decapitalized?](#will-text-be-decapitalized)
  * [How do I link to other games? When is the earliest I can link?](#how-do-i-link-to-other-games-when-is-the-earliest-i-can-link)
  * [Where are the new Move Tutors and what moves do they teach?](#where-are-the-new-move-tutors-and-what-moves-do-they-teach)
  * [Is there a location list for all the Master Trainers?](#is-there-a-location-list-for-all-the-master-trainers)

## Mechanics:

### Will later-generation battle mechanics be implemented? What about the physical/special split?
No. This hack aims to preserve the original battle mechanics and maintain link compatibility with the vanilla games. Changing the battle mechanics runs contrary to those goals.

### Will new moves be implemented? New held items?
No. This hack aims to preserve the original battle mechanics and maintain link compatibility with the vanilla games. Adding new moves or held items runs contrary to those goals.

### Will the Gen 6+ Experience Share be implemented?
No.

### Will you improve breeding mechanics?
Breeding mechanics have been ported from Emerald, but no further improvements will be made. This hack is not meant to supplant the vanilla games when it comes to obtaining good Pokémon.

### What are the shiny chances? Will they be improved?
The shiny chance is 1/8192, as it was in Gen 3. The odds of encountering a shiny Pokémon will not be increased.

### Will you add something to change my Pokémon's IVs/Hidden Power/Nature/etc.?
No. This hack is not meant to supplant the vanilla games when it comes to obtaining good Pokémon. For IVs specifically, players can make the game behave as if all Pokémon IVs are perfect by toggling an option in the Key System Menu. This option does not affect a Pokémon's actual IVs or Hidden Power.

## Pokémon Availability:

### Will you add later-generation Pokémon?
No. This hack aims to maintain link compatibility with the vanilla games and keep all obtainable Pokémon legal in Generation III.

### How many Pokémon are available? Will *all* Pokémon be catchable?
There are 246 Pokémon available in the hack without trading. This hack does not add any new Pokémon that were not available in Generation III. To complete the National Dex, trade with the vanilla games. This is not a 386 hack, and not all Pokémon will be obtainable without trading.

### Can you change wild Pokémon availability/levels? Can you put *x* Pokémon in *y* map? Will you add more Pokémon in the future?
One of the goals of this hack is to make every Pokémon available to the player legal in Gen 3. This means that modifying existing Pokémon encounters or adding new Pokémon to existing encounter tables would make illegal Pokémon obtainable. There are new Pokémon available that were not in FireRed and LeafGreen originally, but they have been painstakingly implemented in such a way as to maintain their Gen 3 legality.

Adding more Pokémon in the future would require finding ways to make them legal in Gen 3, and for the remaining roster of Pokémon there aren't ways to do that while still having it make sense. If you want more Pokémon, trade with vanilla.

### Is there a list of wild encounter tables?
Yes, however it is not well-organized. [The link is here](https://github.com/Deokishisu/FRLG-Plus/blob/master/src/data/wild_encounters.h).

### Can I obtain the other Kanto starters? Can I obtain the unchosen fossil?
Yes, both in the postgame.
<details>
  <summary>The other Kanto starters:</summary>
  The Rival's starter can be obtained as an Egg on Four Island from the Day Care Man.
  The unchosen starter can be obtained from Daisy after fixing the Network Machine on One Island.
</details>
<details>
  <summary>The unchosen fossil:</summary>
  The unchosen fossil can be obtained in Three Isle Path from the prospector in the cave after becoming Champion.
</details>

### Can I evolve my Kanto Pokémon into their Johto evolutions without the National Dex?
Yes. The game will no longer prevent Pokémon from evolving into a Pokémon that is not in the Kanto Pokédex.

### How do I evolve Eevee into Espeon and Umbreon?
Eevee evolves into Espeon when leveled up outdoors with high friendship. Eevee evolves into Umbreon when leveled up indoors with high friendship.

### Can I evolve trade evolutions without trading?
Yes. A new key item, the Link Bracelet, is available. It is an unmissable key item that is obtained during the story and can be used like an evolution stone. To evolve Pokémon that need to hold an item while trading to evolve, have them hold the item before using the Link Bracelet on them.

<details>
  <summary>Exact location of the Link Bracelet:</summary>
  It is received from the Rival after defeating him in Silph Co.
</details>

### Are trade evolution items available before the postgame?
Yes. Most are available as wild held items. Items like the Up-grade have been moved to be available before becoming the Champion.
<details>
  <summary>Pokemon that hold trade evolution items:</summary>
  
  • Metal Coats can be found rarely on wild Magnemite and Magneton.
  
  • Dragon Scales can be found rarely on wild Dratini and Dragonair.
  
  • King's Rocks can be found rarely on wild Poliwhirl and Slowbro.
  
  • Deep Sea Scales can be found rarely on wild Chinchou underwater.
  
  • Deep Sea Teeth can be found rarely on wild Gyarados underwater.
</details>

### Where do I get the event tickets so I can obtain Mew, Lugia and Ho-oh, Deoxys, and Latias and Latias?
<details>
  <summary>The Old Sea Map for Mew on Faraway Island:</summary>
  Become the Champion, then talk to Mr. Fuji in his home in Lavender Town.
</details>

<details>
  <summary>The MysticTicket for Lugia and Ho-oh on Navel Rock:</summary>
  Obtain the Extended Dex, then get the diploma for completing the Kanto Pokédex in Celadon Mansion.
</details>

<details>
  <summary>The AuroraTicket for Deoxys on Birth Island:</summary>
  Get a 28-win streak at the Battle Tower.
</details>

<details>
  <summary>The Eon Ticket for Latias and Latios on Southern Island:</summary>
  Get a 56-win streak at the Battle Tower. These Pokémon are version exclusive, so switch versions in the Key System Menu to obtain both of them.
</details>

### How do I get Sudowoodo to battle me?
<details>
  <summary>To get Sudowoodo to battle,</summary>
  have a Fresh Water in your bag and talk to it.
</details>

## Troubleshooting Savefiles, Emulators, and Flashcarts:

### Is my vanilla FireRed or LeafGreen save compatible with FRLG+?
No. The save needed to be edited to add certain features, and therefore vanilla saves are incompatible with FRLG+. Similarly, FRLG+ saves cannot be used in vanilla.

### My emulator/flashcart doesn't work with FRLG+! The game won't save!
The recommended emulator for desktop is [mGBA](https://mgba.io/downloads.html).

If your emulator or flashcart isn't working properly with FRLG+, follow instructions for that particular emulator or flashcart for playing vanilla FireRed or LeafGreen and apply them to getting FRLG+ to work. If a patch is required to get vanilla FireRed or LeafGreen to save properly, then FRLG+ is incompatible with that emulator or flashcart.

## Modifying FRLG+:

### Can I use FRLG+ as a ROM Base?
My official stance is that all mods of FRLG+ are unauthorized and unsupported. If you choose to use FRLG+ as a ROM Base, I will not offer any support nor answer questions regarding developing a mod of this hack.

### How did you implement *x* feature? Can I use *y* feature for my hack?
My commits are descriptively labeled. If you want to grab something from FRLG+, go back through my commits and find where I implemented it. I don't offer support or answer questions for lifting things from FRLG+, but since the project is open source anyone can take from it.

## Miscellaneous:

### Will text be decapitalized?
No.

### How do I link to other games? When is the earliest I can link?
FRLG+ is fully compatible with everything that the vanilla international FireRed and LeafGreen games were compatible with. If your emulator supports linking, refer to its documentation for how to initiate a link.

The player may link with all Gen 3 GBA and GCN games the moment they receive the Pokédex. Finishing the Net Center on One Island is no longer a prerequisite for trading with the Hoenn games, trading with the Orre games, using Pokémon Box: Ruby and Sapphire, or receiving Eggs or Pokémon that are not in the Kanto Pokédex.

### Where are the new Move Tutors and what moves do they teach?
<details>
    <summary>New move tutor locations:</summary>
    
• Fury Cutter - Vermilion City

• Rollout - Route 24

• Swagger - Route 10

• Dynamic Punch - Saffron City

• Sleep Talk - Silph Co.

• Nightmare - Silph Co.

• Self-Destruct - Cinnabar Island

• Sky Attack - Mt. Ember

The tutors in Saffron City and Silph Co. will not appear until Team Rocket has been driven from the city.
</details>

### Is there a location list for all the Master Trainers?
The Master Trainers are all in the same locations as they were in LGPE, with the exception of Master Trainers who would have been on Cycling Road. Those that would have been on Cycling Road have been moved to Routes 16 and 18. Keeping that in mind, [refer to this list from Bulbapedia](https://bulbapedia.bulbagarden.net/wiki/Master_Trainer#Trainer_list) for the Master Trainer locations.
&nbsp;
&nbsp;
&nbsp;
&nbsp;
&nbsp;
&nbsp;
