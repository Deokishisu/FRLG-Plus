FarawayIsland_Exterior_MapScripts::
	.byte 0

FarawayIsland_Exterior_EventScript_Sailor::
	lock
	faceplayer
	msgbox FarawayIsland_Exterior_Text_SailorReturn, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FarawayIsland_Exterior_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat 1, MAP_FARAWAY_ISLAND_EXTERIOR
	setvar VAR_0x8004, 2
	call EventScript_SailToVermilionCity
	waitstate
	release
	end

FarawayIsland_Exterior_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Exterior_EventScript_Sign::
	msgbox FarawayIsland_Exterior_Text_Sign, MSGBOX_SIGN
	end
	
FarawayIsland_Exterior_Text_Sign:
    .string "The writing is fading as if it was\n"
    .string "written a long time ago…\p"
    .string "“…ber, 6th day\n"
    .string "If any human…sets foot here…\l"
    .string "again…et it be a kindhearted pers…\l"
    .string "…ith that hope, I depar…”$"
	
EventTicket_Text_SailHome:
	.string "Aye, right, then!\n"
	.string "Sail home we will!$"

EventTicket_Text_AsYouLike:
	.string "Aye, right, as you like, then.$"
	
FarawayIsland_Exterior_Text_SailorReturn:
    .string "Do you want to return to VERMILION?$"
