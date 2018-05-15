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

struct WallCollisionData {
    /*0x00*/ float x, y, z;           
    /*0x0C*/ float offsetY;           
    /*0x10*/ float radius;            
    /*0x14*/ s16 unk14;               
    /*0x16*/ s16 numWalls;            
    /*0x18*/ struct Surface *walls[4];
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
extern void func_8029D62C(struct Object *, Mat4p, Mat4p);
extern void func_8029DA34(struct Object *, u8 *);
// extern ? func_80380690(?);
extern s32 func_80380DE8(f32 *x, f32 *y, f32 *z, f32 offsetY, f32 radius);
// extern ? func_80380E8C(?);
// extern ? func_80381038(?);
// extern ? Unknown80381470(?);
// extern ? func_803814B8(?);
// extern ? func_8038156C(?);
extern f32 func_80381794(f32, f32, f32);
// extern ? Unknown803817E0(?);
extern f32 func_80381900(f32, f32, f32, struct Surface **);
extern float func_80381BA0(float, float);
extern float func_80381D3C(float, float);
// extern ? func_80381EC8(?);
// extern ? func_80381F08(?);
// extern ? Unknown80382294(?);
// extern ? func_80382490(?);
// extern ? func_803824F8(?);
// extern ? func_80382590(?);
// extern void func_803825D0(void);
// extern ? func_803825FC(?);
// extern ? func_8038283C(?);
// extern ? func_8038289C(?);
// extern ? func_803828FC(?);
// extern ? func_80382990(?);
// extern ? func_80382A2C(?);
// extern ? func_80382B7C(?);
// extern ? func_80382F84(?);
// extern ? func_80382FEC(?);
// extern ? func_80383068(?);
// extern ? func_803831D0(?);
// extern ? func_80383228(?);
// extern ? func_80383340(?);
 void func_803833B8(s16 arg0, s16 *arg1, s8 *arg2, s16 *arg3);
// extern ? func_803835A4(?);
// extern ? func_80383614(?);
// extern ? func_80383828(?);
// extern ? ProcessCollision(?);

#endif /* _SURFACE_COLLISION1_H */
