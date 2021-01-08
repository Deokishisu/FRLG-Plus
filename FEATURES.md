## Features

###### [] indicates NYI

#### Mechanical Additions:
- A Key System has been implemented, similar to Black2 and White2. Press the L Button while on the Key System Menu to access the Help System, which has detailed information on each key. Use the keys to change various settings about your game. Those settings are:
	*  __Version__: Switch between FireRed and LeafGreen to catch version exclusive Pokémon.
	* __Difficulty__: Like in Black2 and White2, there is a Challenge and an Easy Mode difficulty. These difficulties scale trainer levels up or down, and in Challenge Mode important trainers will have an extra Pokémon.
	* __Nuzlocke Toggle__: Can toggle on a Nuzlocke mode. Press the L Button on the Key System menu to read the special ruleset for this mode.
	* __IV Calculation__: Can make the game treat your Pokémon's IVs as all perfect (31), all zero, or use their actual IVs as is standard for the purposes of stat calculation. This does not affect your Pokémon's actual IVs or Hidden Power, just how thier stats are calculated. If set to all perfect, enemy Pokémon will also be treated as if they have all perfect IVs.
	* __EV Calculation__: Can make the game treat your Pokémon's EVs as all zero, or use their actual EVs as is standard for the purposes of stat calculation. This does not affect your Pokémon's actual EVs, (they will still gain/lose EVs as normal), just how their stats are calculated.
	* __No Free Heals__: Can disable free party heals, most notably the Pokémon Center heals and the Lavender Tower purified zone, but also many others. This also prevents PC Boxes from healing Pokémon deposited into them.

- Nuzlocke Info: This is a special implementation of the Nuzlocke ruleset. While the Nuzlocke toggle is on, fainted Pokémon cannot be healed by any means (including depositing them in a PC Box). Like under a standard Nuzlocke ruleset, only the first Pokémon caught or received from NPCs in an area is usable, but under this implementation Pokémon other than the first may be caught, they will just be automatically fainted after capture. Pokémon captured in this way will not count for the dupe clause (A Rattata will count as a first encounter on Route 2 if you caught a fainted Rattata on Route 1). Pokémon that are already owned, or evolutionary relatives of already owned Pokémon, will not count if they are the first encounter in an area and not caught. There is a UI element drawn to the enemy's healthbar to indicate if it counts as the first encounter in an area. If a white out occurs, the player will be prompted to grab a usable Pokémon from their PC Box. If there are no usable Pokémon left, they will be given a choice of soft-resetting or turning off the Nuzlocke toggle and healing their party normally. These rules do not come into effect until after the first Rival battle. Encounters are not tracked while the Nuzlocke toggle is off and are not retroactive (starting a Nuzlocke midway through a regular playthrough will allow new "first" encounters). Additionally, encounters are not tracked before the player obtains the Pokédex, to prevent losing the opportunity to catch Route 1 Pokémon before catching Pokémon is possible.

#### Story Changes:
- The National Pokédex is available as soon as the player becomes the Champion without first registering 60 Pokémon in the Pokédex or first visiting the Sevii Islands.
- Event tickets are given away through gameplay milestones, allowing the player access to Birth Island and Navel Rock to catch Deoxys and Ho-oh/Lugia, respectively. []
	* Faraway Island has been ported from Emerald, allowing players to catch Mew. The Old Sea Map is given away similarly to the other event tickets.
		* This Mew counts as an Emerald Faraway Island Mew for legality purposes.
- Expanded postgame, focusing on giving the Sevii Islands more content. []
	* The Sevii Islands are now exclusively a postgame area and cannot be accessed until becoming the Champion. []
	* Expanded Sevii Islands story and new routes added. []

#### Quality of Life Changes:
- No link restrictions
	* Trade with Ruby, Sapphire, Emerald, Colosseum, and XD the moment that the player catches a second Pokémon.
		* Unmodified Emerald may need the National Dex before it allows trading.
- No evolution restrictions; Pokémon will evolve regardless of whether or not their evolution is in the Kanto Dex.
- Cut Trees stay cut permanently.
- Infinite TM usage. TM prices have been modified to reflect this.
- Expanded item pockets. The player can hold one stack of every legally obtainable item at once.
- Two new pockets, the Medicine and Held Items pockets, have been introduced to ease bag navigation.
- Move Tutors will charge after the first time they teach a move, allowing infinite tutor uses at a cost. Frenzy Plant, Blast Burn, and Hydro Cannon can be tutored infinitely for free, and no longer have a friendship requirement to learn.
- Hold B while surfing to go faster.
- Running indoors.
- Toggle auto running with the R button.
- Health bar drains faster at higher HP levels.
- Instant text option.
- Battle animation speed setting in the options menu. When set to fast, the slide-in animation at the start of every battle is skipped, and healthbars drop much faster.
- Indicators for which stats are affected by natures on summary screen.
- EV-reducing berries ported from Emerald (the Pomeg glitch was fixed during the port).
- The EV cap for an individual stat is 252, like in later generations.
- Pokémon that evolve by trade can evolve by using an unmissable Key Item on them that is obtained during the story. Pokémon like Scyther also need to be holding their evolution items to evolve in this way.
- Game Corner coins can be bought in increments of 1000 in addition to the other two options.
- Press the select button in the party menu to switch Pokémon without having to use the menu option.

#### Miscellaneous Changes
- The Pokémon Summary Screen can accurately show the met location of any Pokémon obtained in Gen 3, including Pokémon from Orre.
- All Deoxys formes are included, and are implemented in the way that the GBA games did it for link compatibility purposes. Switch Deoxys' forme by examining the meteorite exhibit in the Pewter Museum of Science.
- All Kanto Pokémon, along with select Johto Pokémon (in the Sevii Islands), will be available in one playthrough. Most Hoenn Pokémon will still need to be traded for. []
- Abilities have effects in the overworld ported from Emerald.
- LGPE-style bonus Premier Balls in shops. Buying multiples of ten of any Poké Ball type will give bonus Premier Balls.