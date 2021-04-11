.set LOCALID_GYARADOS_MASTER, 5
.set LOCALID_ARCANINE_MASTER, 6
.set TRAINER, VAR_0x8009

CeladonCity_Hotel_MapScripts:: @ 816D283
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_Hotel_MapScript_SetMasterTrainerMovementTypes
	.byte 0

CeladonCity_Hotel_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_GYARADOS
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq CeladonCity_Hotel_MapScript_GyaradosMasterMovementType
	setvar TRAINER, MASTER_ARCANINE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq CeladonCity_Hotel_MapScript_ArcanineMasterMovementType
	end

CeladonCity_Hotel_MapScript_GyaradosMasterMovementType::
	setobjectmovementtype LOCALID_GYARADOS_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

CeladonCity_Hotel_MapScript_ArcanineMasterMovementType::
	setobjectmovementtype LOCALID_ARCANINE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

CeladonCity_Hotel_EventScript_Receptionist:: @ 816D284
	msgbox CeladonCity_Hotel_Text_ThisHotelIsForPeople, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_Beauty:: @ 816D28D
	msgbox CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBoyfriend:: @ 816D296
	msgbox CeladonCity_Hotel_Text_WhyDidSheBringBrother, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBrother:: @ 816D29F
	msgbox CeladonCity_Hotel_Text_SisBroughtMeOnVacation, MSGBOX_NPC
	end
