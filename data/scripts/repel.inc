EventScript_RepelWoreOff::
	checkitem VAR_LAST_REPEL_USED, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_UseAnother
	lock
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	release
	end

EventScript_UseAnother:
	lock
	msgbox Text_UseAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_UsedRepel
	release
	end

EventScript_UsedRepel:
	bufferitemname STR_VAR_1, VAR_LAST_REPEL_USED
	playse SE_REPEL
	lock
	msgbox Text_UsedNewRepel, MSGBOX_SIGN
	removeitem VAR_LAST_REPEL_USED, 1
	waitse
	callnative HandleUseExpiredRepel
	release
	end

Text_RepelWoreOff::
	.string "REPEL's effect wore off…$"

Text_UseAnother::
	.string "REPEL's effect wore off!\n"
	.string "Use another?$"

Text_UsedNewRepel::
	.string "{PLAYER} used the\n"
	.string "{STR_VAR_1}.$"
