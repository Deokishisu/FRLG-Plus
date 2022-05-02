## Features

#### Mechanical Additions:
- A Key System has been implemented, similar to Black 2 and White 2. Press the L Button while on the Key System Menu to access the Help System, which has detailed information on each key. Use the keys to change various settings about your game. Those settings are:
	*  __Version__: Switch between FireRed and LeafGreen to catch version-exclusive Pokémon.
	* __Difficulty__: Like in Black 2 and White 2, there is a Challenge and an Easy Mode difficulty. These difficulties scale trainer levels up or down, and in Challenge Mode important trainers will have an extra Pokémon and badge boosts are disabled.
	* __Nuzlocke Toggle__: Can toggle on a Nuzlocke mode. Press the L Button on the Key System menu to read the special ruleset for this mode.
	* __IV Calculation__: Can make the game treat your Pokémon's IVs as all perfect (31), all zero, or use their actual IVs as is standard for the purposes of stat calculation. This does not affect your Pokémon's actual IVs or Hidden Power, just how their stats are calculated. If set to all perfect, enemy Pokémon will also be treated as if they have all perfect IVs.
	* __EV Calculation__: Can make the game treat your Pokémon's EVs as all zero, or use their actual EVs as is standard for the purposes of stat calculation. This does not affect your Pokémon's actual EVs, (they will still gain/lose EVs as normal), just how their stats are calculated.
	* __No Free Heals__: Can disable free party heals, most notably the Pokémon Center heals and the Lavender Tower purified zone, but also many others. This also prevents PC Boxes from healing Pokémon deposited into them.
	* __Exp. Modifier__: Can alter experience gains using a multiplier. The possible options are 0×, 1/2×, 1×, and 2×.

- Nuzlocke Info: This is a special implementation of the Nuzlocke ruleset. While the Nuzlocke toggle is on, fainted Pokémon cannot be healed by any means (including depositing them in a PC Box). Like under a standard Nuzlocke ruleset, only the first Pokémon caught or received from NPCs in an area is usable, but under this implementation Pokémon other than the first may be caught, they will just be automatically fainted after capture. Pokémon captured in this way will not count for the dupe clause (A Rattata will count as a first encounter on Route 2 if you caught a fainted Rattata on Route 1). Pokémon that are already owned, or evolutionary relatives of already owned Pokémon, will not count if they are the first encounter in an area and not caught. There is a UI element drawn to the enemy's healthbar to indicate if it counts as the first encounter in an area. If a white out occurs, the player will be prompted to grab a usable Pokémon from their PC Box. If there are no usable Pokémon left, they will be given a choice of soft-resetting or turning off the Nuzlocke toggle and healing their party normally. These rules do not come into effect until after the first Rival battle. Encounters are not tracked while the Nuzlocke toggle is off and are not retroactive (starting a Nuzlocke midway through a regular playthrough will allow new "first" encounters). Additionally, encounters are not tracked before the player obtains the Pokédex, to prevent losing the opportunity to catch Route 1 Pokémon before catching Pokémon is possible. Each outdoor Safari Zone map counts as a separate area for the purposes of catching Pokémon. The player is not asked whether or not they want to give a nickname to obtained Pokémon while Nuzlocke Mode is on. In-game trades will be fainted if the Pokémon traded for them was fainted but will be usable if not, and otherwise do not count as a first encounter. In-game trades do invoke the dupe clause for additional Pokémon of that species. Eggs, when hatched, will set the encounter flag of the place the egg was first obtained. If that place already had a first encounter, then the egg will hatch fainted.

#### Story Changes:
- The player may progress to the Sevii Islands postgame content immediately after becoming the Champion; the National Dex is no longer required to do so.
	- After the player becomes the Champion, Oak will upgrade their Pokédex with a new Extended Mode which lists all Pokémon available without trading.
	- The National Pokédex is now obtained by trading in a Pokémon that is not in the Extended Dex.
- A legendary beast will begin roaming when the player first enters the Hall of Fame, instead of upon delivering the Sapphire.
- Event tickets are given away through gameplay milestones, allowing the player access to Birth Island and Navel Rock to catch Deoxys and Ho-oh/Lugia, respectively.
	* Faraway Island has been ported from Emerald, allowing players to catch Mew. The Old Sea Map is given away similarly to the other event tickets.
	* Southern Island has been ported from Emerald, allowing players to catch Latias and Latios. The Eon Ticket is given away similarly to the other event tickets.
- Expanded postgame, focusing on organically fleshing out the available content.
	* HM08 Dive is now available and usable in the field. New underwater areas found on Route 20 and Bond Bridge.
	* A Safari Zone expansion adds two more areas, making more Pokémon obtainable.
	* The Hoenn Battle Tower has been ported from RS. The player will be invited to challenge the Battle Tower upon delivering the Ruby to Celio.
		* The Level 100 mode has been replaced with the Open Level mode like in Emerald.
		* Artisan Cave can be accessed from the Battle Tower's dock.
	* A new area in Berry Forest makes the pinch berries available.
	* A new area west of Cape Brink has rematchable trainers for the purposes of EV training.
	* Gym Leader rematches can be unlocked on Seven Island.
	* Master Trainers appear around Kanto after becoming the Champion, filling a similar role to their appearance in the Let's Go games with some differences.
		* Master Trainers can be rematched immediately.
		* Master Trainer Pokémon will scale to the level of the Pokémon used to challenge them, making them more accessible.
		* Master Trainer Pokémon hold items and have better movesets than in the Let's Go games, making them significantly more challenging.
		* The Master Trainers for Ditto, Articuno, Zapdos, Moltres, Mewtwo, and Mew want to see Pokémon with 100 total Effort Values.
		* Master Trainers that would have been on Cycling Road have been moved to Routes 16 and 18.
			* Additionally, some Master Trainers have been repositioned on their maps to account for FRLG area design.
		* Clearing a Master Trainer confers a title that can be used in link battles with other FRLG+ players.
		* Clearing all 151 Master Trainers unlocks a secret superboss Trainer.

#### Quality of Life Changes:

##### Travel-related:
- Running indoors.
- Toggle auto running with the R button.
- Cut trees stay cut permanently.
- Hold B while surfing to go faster. If autorun is enabled, hold B to go slower, as the faster speed becomes default.
- The bike now has two gears, one for the default speed, and one for Mach Bike speed. Press B while biking to switch between them.
- The Victory Road boulder puzzles no longer reset.
- The two boulders that block access to Mt. Ember's exterior will no longer block the way once the player moves past them.
- Steps taken aren't counted while inside Safari Zone Rest Houses.
- The player travels at running speed while diving.

##### Inventory and Item-related:
- Expanded item pockets. The player can hold one stack of every legally obtainable item at once.
- Two new pockets, the Medicine and Held Items pockets, have been introduced to ease bag navigation.
- Press Start in the bag to sort items by several criteria.
- The bag pockets wrap around when switching between them.
- Left and Right in the TM Case and Berry Pouch scrolls faster.
- Infinite TM usage. TM prices have been modified to reflect this. TMs do not restore PP when learned, like in BW/B2W2.
- EV-reducing berries ported from Emerald (the Pomeg glitch was fixed during the port). Otherwise worthless berries obtainable as hidden items or through Pickup have been changed to these.
- When a repel expires, the player will be asked whether they want to use another immediately, like in Black 2 and White 2.
- The Generation III Poké Ball varieties can be purchased in Silph Co. after it has been liberated from Team Rocket.
- The Light Ball is held rarely by Pikachu outside of Viridian Forest, making it obtainable without trading.
- LGPE-style bonus Premier Balls in shops. Buying multiples of ten of any Poké Ball type will give bonus Premier Balls.
- Trade evolution items are now available before the postgame.
	* Up-grade can be found in Silph Co.
	* Metal Coats can be found rarely on wild Magnemite and Magneton.
	* Dragon Scales can be found rarely on wild Dratini and Dragonair.
	* King's Rocks can be found rarely on wild Poliwhirl and Slowbro.
	* Deep Sea Scales can be found rarely on wild Chinchou underwater.
	* Deep Sea Teeth can be found rarely on wild Gyarados underwater.

##### Battle-related:
- New options available in the options menu to speed up battles:
	* Battle Transitions setting turns off the transition animation between the field and a battle.
	* Battle Intro Animation setting turns off the sliding animation that occurs at the start of every battle.
	* Battle Scene has been renamed to Move Animations and now also skips in-battle text delays when it is off.
	* HP Bar Animation Speed gives four options for how fast the HP bar animates, including instant.
	* Exp. Bar Animation Speed gives the player the choice to make experience bars animate instantly.
- New battle style option, switch, which is like shift but doesn't tell what the opponent is switching in. Shift has been renamed to predict.
- Press B on the "What will Pokémon do?" menu during wild battles to move the cursor to run.
- A message is now printed at the end of a battle if a Pokémon has gained an item through the Pickup ability.

##### Move Tutor-related:
- There are eight new Move Tutors scattered throughout the world that teach Fury Cutter, Rollout, Dynamic Punch, Sleep Talk, Nightmare, Self-Destruct, Sky Attack, and Swagger respectively.
- Move Tutors will charge after the first time they teach a move, allowing infinite tutor uses at a cost. Frenzy Plant, Blast Burn, and Hydro Cannon can be tutored infinitely for free, and no longer have a friendship requirement to learn.
- The Move Reminder can overwrite HM moves with relearned moves.
- The Move Reminder can teach moves from a Pokémon's pre-evolutions, with some caveats.
	* If the Pokémon has a baby form, it can only relearn moves exclusive to that form if it was hatched itself. Wobbuffet from Mirage Island are the sole exception, as they were caught as Wynaut and therefore can also relearn Wynaut's exclusive moves.
	* If a Pokémon is not at a high enough level to learn a move from its own learnset, then it cannot relearn that move regardless of its presence in a pre-evolution's learnset.

##### User Interface-related:
- Indicators have been added for which stats are affected by natures on summary screen.
- Press the select button in the party menu to switch Pokémon without having to use the menu option.
- Press the select button on the initial Pokédex screen to open the last viewed entry.
- Hidden Power's true type and power are shown on the summary screen, and its type is shown in battle.
- The summary screen now wraps around when cycling through the party Pokémon instead of stopping at the first and last.
- Game Corner coins can be bought in increments of 1000 in addition to the other two options.

##### Pokémon-related:
- All Deoxys formes are included, and are implemented in the way that the GBA games did it for link compatibility purposes. Switch Deoxys' forme by examining the meteorite exhibit in the Pewter Museum of Science.
- No evolution restrictions; Pokémon will evolve regardless of whether or not their evolution is in the Kanto Dex.
	* Eevee evolves into Espeon by happiness outdoors and Umbreon by happiness indoors.
- The EV cap for an individual stat is 252, like in later generations.
- Pokémon that evolve by trade can evolve by using an unmissable Key Item on them that is obtained during the story. Pokémon like Scyther also need to be holding their evolution items to evolve in this way.
- Uncaptured legendary Pokémon, roaming Pokémon, and Snorlax will be regenerated upon entering the Hall of Fame, keeping them from being missable.
- If upon entering the Hall of Fame a legendary beast is not currently roaming, an uncaught one will begin to roam. This allows the player to capture all three legendary beasts in one playthrough.
- A woman in the Move Reminder's House on Two Island can check if a Pokémon is fully EV trained. If it is, she'll give it the Effort Ribbon.

##### Day Care-related:
- The Day-Care Man will adjust his position immediately if a Pokémon Egg is ready without having to transition to another map.
- The Day Care will send a retrieved Pokémon to a box as long as it's not holding mail if the player's party is full.
- Eggs have a 50% chance of inheriting the nature of their mother or Ditto parent if that parent holds an Everstone, ported from Emerald.
- The Route 5 Day-Care Man tells the player what level a Pokémon was when it was first deposited.

##### Miscellaneous Quality of Life Additions:
- Instant text option.
- No link restrictions
	* Trade with Ruby, Sapphire, Emerald, Colosseum, and XD the moment that the player catches a second Pokémon.
		* Unmodified Emerald may need the National Dex before it allows trading.
- The Old Man tutorial battle is skipped if you have more than one Pokémon with you.
- The Trainer Card star gained from doing Wireless minigames on Two Island can also be earned by achieving a 50-win streak at the Battle Tower.
- The Pokémon Center nurses abbreviate their dialogue after getting two Trainer Card stars, similar to Generation IV and up.
- Softlock prevention mechanisms are present. The player can no longer trap themselves on Cinnabar Island and the Indigo Plateau, and free Poké Balls are available in potential softlock situations.
- There is now a PC in the S.S. Anne in the room where the player can rest.

#### Vanilla Bug Fixes:
- All Revision 1 fixes are included here. This includes the missing "Presents" graphic in the intro, and several Pokédex errors and oversights.
- The Nugget Bridge Rocket can no longer give the player infinite Nuggets.
- Assist, Block, Camouflage, Charge, Conversion 2, Follow Me, Grudge, Helping Hand, Imprison, Ingrain, Magic Coat, Mean Look, Memento, Mimic, Mud Sport, Nightmare, Pain Split, Recycle, Refresh, Role Play, Skill Swap, Slack Off, Snatch, Softboiled, Spider Web, Tail Glow, Vital Throw, Water Sport, Wish and Yawn display as --- accuracy instead of 100 accuracy.
- The misspelling of "Pokcet" in the Teachy TV program has been fixed.
- Raikou and Entei will not disappear if they Roar the player out of their battles.
	* The roaming IV glitch will __not__ be fixed, as it affects the legality of the legendary beasts.
- Fixed Karate King Koichi and Charine localization oversights. These characters are now named Kiyo and Janine as they are in GSC/HGSS.
- Fixed bug where the AI would decide to use Foresight based on the user's type and stats instead of the target's.
- Fixed bug where the AI would incorrectly decide to try to stall with semi-invulnerable moves while a weather effect is damaging them.
- Fixed bug where the AI would decide to use Facade based on the target's status instead of its own.
- Fixed an oversight where Icefall Cave's cracked ice tiles could spawn wild encounters. If a wild encounter is generated on one, it does not crack, allowing the player to cheat the puzzle.
- Many vanilla tile errors have been fixed. Too many.

#### Miscellaneous Changes:
- All Kanto Pokémon, along with 90% of Johto Pokémon, will be available in one playthrough. All Hoenn Pokémon (except for Azurill, Wynaut, Latias, Latios, and Deoxys) will still need to be traded for.
- Abilities have effects in the overworld ported from Emerald.
	* As Lightningrod's Emerald overworld effect is inapplicable, it has been changed. Lightningrod now charges the Vs. Seeker twice as fast.
- The Pokémon Summary Screen can accurately show the met location of any Pokémon obtained in Gen 3, including Pokémon from Orre.
- Silph Co. is populated by workers once it is liberated from Team Rocket.
- Some aesthetic and music changes which are mostly confined to the Sevii Islands to make each island more distinct.
- Cycling Road forces the bike theme, like in RGBY.
- Emerald's player character designs show in the link rooms if linking with Emerald.
- The original RGBY textbox is available as frame type 11 in the options menu.
- The Gambler trainer class has been decensored.
