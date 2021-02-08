SafariZone_North_MapScripts:: @ 8162398
	map_script MAP_SCRIPT_ON_LOAD, SafariZone_North_EventScript_MakeExtension
	.byte 0

SafariZone_North_EventScript_MakeExtension::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_ReleaseEnd
	setmetatile 12, 2, 0x0DB, 1
	setmetatile 12, 3, 0x0DB, 1
	setmetatile 12, 4, 0x0DB, 1
	setmetatile 12, 5, 0x0DB, 1
	setmetatile 12, 6, 0x2EA, 0
	setmetatile 13, 2, 0x0DD, 1
	setmetatile 13, 3, 0x0DD, 1
	setmetatile 13, 4, 0x0DD, 1
	setmetatile 13, 5, 0x0DD, 1
	setmetatile 13, 6, 0x2EB, 0
	setmetatile 14, 2, 0x0E6, 1
	setmetatile 14, 3, 0x0E6, 1
	setmetatile 14, 4, 0x0E6, 1
	setmetatile 14, 5, 0x0E6, 1
	setmetatile 14, 6, 0x358, 1
	setmetatile 11, 2, 0x304, 1
	setmetatile 11, 3, 0x2FC, 1
	setmetatile 11, 4, 0x304, 1
	setmetatile 11, 5, 0x30C, 1
	setmetatile 15, 2, 0x303, 1
	setmetatile 15, 3, 0x2FB, 1
	setmetatile 15, 4, 0x303, 1
	setmetatile 15, 5, 0x30B, 1
	end

SafariZone_North_EventScript_RestHouseSign:: @ 8162399
	msgbox SafariZone_North_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_North_EventScript_TrainerTips1:: @ 81623A2
	msgbox SafariZone_North_Text_SecretHouseStillAhead, MSGBOX_SIGN
	end

SafariZone_North_EventScript_AreaSign:: @ 81623AB
	msgbox SafariZone_North_Text_Area2, MSGBOX_SIGN
	end

SafariZone_North_EventScript_TrainerTips2:: @ 81623B4
	msgbox SafariZone_North_Text_ZigzagThroughTallGrass, MSGBOX_SIGN
	end

SafariZone_North_EventScript_TrainerTips3:: @ 81623BD
	msgbox SafariZone_North_Text_WinFreeHMFindSecretHouse, MSGBOX_SIGN
	end

SafariZone_North_EventScript_Worker1:: @ 81623BD
	msgbox SafariZone_North_Text_Worker1, MSGBOX_NPC
	turnobject 5, DIR_NORTH
	end

SafariZone_North_Text_Worker1::
	.string "Are you enjoying the SAFARI GAME?\p"
	.string "We're working, so please go on with\n"
	.string "your excursion and leave us be.$"

SafariZone_North_EventScript_Worker2:: @ 81623BD
	msgbox SafariZone_North_Text_Worker2, MSGBOX_DEFAULT
	release
	end

SafariZone_North_Text_Worker2::
	.string "…If we cut through here…\n"
	.string "…Hmm…$"
