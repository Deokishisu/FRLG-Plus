FarawayIsland_Exterior_MapScripts::
	.byte 0

FarawayIsland_Exterior_EventScript_Sailor:: @ 8267CA2
	lock
	faceplayer
	msgbox FarawayIsland_Exterior_Text_SailorReturn, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FarawayIsland_Exterior_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	hideobject 1, MAP_FARAWAY_ISLAND_EXTERIOR
	setvar VAR_0x8004, 2
	call EventScript_SailToVermilionCity
	waitstate
	release
	end

FarawayIsland_Exterior_EventScript_AsYouLike:: @ 8267CE7
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Exterior_EventScript_Sign:: @ 8267CF1
	msgbox FarawayIsland_Exterior_Text_Sign, MSGBOX_SIGN
	end
	
FarawayIsland_Exterior_Text_Sign: @ 82C6D5A
    .string "The writing is fading as if it was\n"
    .string "written a long time ago…\p"
    .string "“…ber, 6th day\n"
    .string "If any human…sets foot here…\l"
    .string "again…et it be a kindhearted pers…\l"
    .string "…ith that hope, I depar…”$"
	
EventTicket_Text_SailHome: @ 82A6A5D
	.string "Aye, right, then!\n"
	.string "Sail home we will!$"

EventTicket_Text_AsYouLike: @ 82A6A82
	.string "Aye, right, as you like, then.$"
	
FarawayIsland_Exterior_Text_SailorReturn: @ 82C6B42
    .string "Do you want to return to VERMILION?$"
	
Common_Movement_WalkInPlaceFastestDown:
	walk_in_place_fastest_down
	step_end