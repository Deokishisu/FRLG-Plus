#ifndef GUARD_PLUS_CFG_H
#define GUARD_PLUS_CFG_H

// PICHU learns VOLT TACKLE if either parent is holding a LIGHT BALL
#define VOLT_TACKLE_BY_BREEDING

// 1/16 chance of SHUCKLE making BERRY JUICE at end of battle if holding an ORAN BERRY
#define SHUCKLE_MAKES_ORAN_BERRY_JUICE

// Show move types and categories as icons in battle
#define BATTLE_MOVE_ICONS

// Expose type of WEATHER BALL and NATURE POWER in battle (requires BATTLE_MOVE_ICONS)
#define EXPOSE_WEATHER_BALL
#define EXPOSE_NATURE_POWER

// Celadon GAME CORNER Easter Egg
#define GAME_CORNER_EASTER_EGG

// Better player reflection in overworld
#define BETTER_PLAYER_REFLECTION

// Better animation for opponent throwing a pokeball
#define NEW_OPPONENT_SEND_MON_ANIM

// Skip intro copyright screen by pressing A/B/START
#define SKIP_INTRO_BUTTON

// Show item description on first obtain
#define SHOW_OBTAIN_ITEM_DESCRIPTION

// Allow choosing a mon which is already out in battle
//#define BATTLE_CAN_CHOOSE_CURRENT_MON

// Allow moving held items between mons in party
#define MOVE_HELD_ITEMS_BETWEEN_MONS

// Show which mons in party can learn selected TM
#define TM_CASE_MON_SPRITES

// Battle Tower ignores EV/IV key setting
#define BATTLE_TOWER_IGNORES_EV_IV_SETTING

// If there is no save, show random FR/LG intro
#define RANDOM_INTRO_VERSION

// Auto swap to lowercase when naming a character
#define AUTO_CASE_SWAP

// ALTERING CAVE will alter as if Mystery Event was active
#define ALTERING_CAVE_ALTERS

// Learning TM/HM does not replenish PP
#define DONT_REPLENISH_PP

// Daycare ignores Level Cap key setting
#define DAYCARE_IGNORES_LEVEL_CAP_SETTING

#endif // GUARD_PLUS_CFG_H
