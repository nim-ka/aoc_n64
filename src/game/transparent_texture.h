#ifndef _TRANSPARENT_TEXTURE_H
#define _TRANSPARENT_TEXTURE_H

#include "types.h"

#define FLYING_CARPET_IDLE                 0
#define FLYING_CARPET_MOVING_WITHOUT_MARIO 1
#define FLYING_CARPET_MOVING_WITH_MARIO    2
extern s8 gFlyingCarpetState;

extern void make_vertex(Vtx *vtx, s32 n, s16 x, s16 y, s16 z, s16 tx, s16 ty, u8 r, u8 g, u8 b, u8 a);
extern s32 round_float(f32);
// extern ? Geo18_802D2360(?);
// extern ? Geo18_802D2470(?);
// extern ? Geo18_802D2520(?);
// extern ? Geo18_802D28CC(?);

#endif /* _TRANSPARENT_TEXTURE_H */
