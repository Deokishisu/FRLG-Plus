RS_BattleTower_Corridor_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BattleTower_Corridor_MapScript1_160850
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_Corridor_MapScript2_160881
	.byte 0

BattleTower_Corridor_MapScript1_160850::
	compare VAR_0x8006, 1
	goto_if_eq BattleTower_Corridor_EventScript_16086E
	setmetatile 12, 0, 0x287, 0
	setmetatile 12, 1, 0x28F, 0
	end

BattleTower_Corridor_EventScript_16086E::
	setmetatile 15, 0, 0x287, 0
	setmetatile 15, 1, 0x28F, 0
	end

BattleTower_Corridor_MapScript2_160881::
	map_script_2 VAR_TEMP_0, 0, BattleTower_Corridor_EventScript_16088B
	.2byte 0

BattleTower_Corridor_EventScript_16088B::
	setvar VAR_TEMP_0, 1
	compare VAR_0x8006, 1
	goto_if_eq BattleTower_Corridor_EventScript_1608B1
	applymovement 1, BattleTower_Corridor_Movement_1608D5
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Corridor_Movement_1608D4
	waitmovement 0
	goto BattleTower_Corridor_EventScript_1608C2

BattleTower_Corridor_EventScript_1608B1::
	applymovement 1, BattleTower_Corridor_Movement_1608D2
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Corridor_Movement_1608D1
	waitmovement 0

BattleTower_Corridor_EventScript_1608C2::
	setvar VAR_TEMP_0, 0
	warp MAP_RS_BATTLE_TOWER_BATTLE_ROOM, 255, 4, 8
	waitstate
	end

BattleTower_Corridor_Movement_1608D1::
	walk_right

BattleTower_Corridor_Movement_1608D2::
	walk_right
	walk_right

BattleTower_Corridor_Movement_1608D4::
	walk_right

BattleTower_Corridor_Movement_1608D5::
	walk_right
	walk_right
	walk_right
	walk_up
	set_invisible
	step_end
