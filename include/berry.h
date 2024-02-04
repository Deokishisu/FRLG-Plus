#ifndef GUARD_BERRY_H
#define GUARD_BERRY_H

#include "global.h"

#define NUM_BERRIES 44

void ClearEnigmaBerries(void);
void SetEnigmaBerry(u8 *src);
bool32 IsEnigmaBerryValid(void);
const struct Berry *GetBerryInfo(u8 berry);
u8 ItemIdToBerryType(u16 item);
void GetBerryNameByBerryType(u8 berry, u8 *string);

extern const struct Berry gBerries[];

struct BerryCrushStats {
    u8 difficulty;
    u16 powder;
};

extern const struct BerryCrushStats gBerryCrush_BerryData[];

#endif // GUARD_BERRY_H
