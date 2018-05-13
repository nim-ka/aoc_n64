#ifndef _SURFACE_COLLISION1_H
#define _SURFACE_COLLISION1_H

#include "types.h"

struct SurfaceNode
{
    struct SurfaceNode * next;
    struct Surface * tri;
};

struct SpatialPartitionCell {
    struct SurfaceNode floors;
    struct SurfaceNode ceils;
    struct SurfaceNode walls;
};

extern s16 D_8033BF04, D_8033BF06, D_8033BF08;
extern s32 D_8038BE30;
extern struct SurfaceNode *D_8038D6A8;
extern struct SpatialPartitionCell D_8038D6A0[16 * 16];
extern struct SpatialPartitionCell D_8038BEA0[16 * 16];
extern float D_8038BE40, D_8038BE44, D_8038BE48;
extern float D_8038BE4C;
extern s16 D_8035FE12;
extern s32 D_8033BEF4;
extern s16 *D_8035FE14;
extern s32 D_8035FDFC;
extern s32 D_8035FE08;
extern s32 D_8035FE00;
extern struct SurfaceNode *D_8038EE98;
extern struct Surface *D_8038EE9C;
extern s16 D_8038EEA0;
extern struct SpatialPartitionCell D_8038D698[16 * 16];
extern struct SurfaceNode *D_8038BEA8;
extern struct SpatialPartitionCell D_8038BE98[16 * 16];

extern f32 func_80381264(float, float, float, struct Surface **);
extern void func_802C9A3C(s32, s32);
extern void func_8029D62C(struct Object *, Mtxfp, Mtxfp);
extern void func_8029DA34(struct Object *, u8 *);

#endif /* _SURFACE_COLLISION1_H */