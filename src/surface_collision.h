#ifndef _SURFACE_COLLISION_H
#define _SURFACE_COLLISION_H

#include "types.h"

struct SurfaceNode
{
    struct SurfaceNode *next;
    struct Surface *surface;
};

struct WallCollisionData {
    /*0x00*/ float x, y, z;           
    /*0x0C*/ float offsetY;           
    /*0x10*/ float radius;            
    /*0x14*/ s16 unk14;               
    /*0x16*/ s16 numWalls;            
    /*0x18*/ struct Surface *walls[4];
};

typedef struct SurfaceNode SpatialPartitionCell[3];

enum
{
    SPATIAL_PARTITION_FLOORS,
    SPATIAL_PARTITION_CEILS,
    SPATIAL_PARTITION_WALLS
};

extern s16 D_8033BF04, D_8033BF06, D_8033BF08;
extern s32 D_8038BE30;
extern float D_8038BE40, D_8038BE44, D_8038BE48;
extern float D_8038BE4C;
extern s16 D_8035FE12;
extern s32 D_8033BEF4;
extern s16 *gWaterRegions;
extern s32 gSurfaceNodesAllocated;
extern s32 gNumStaticSurfaceNodes;
extern s32 gNumStaticSurfaces;
extern s32 gSurfacesAllocated;

extern f32 func_80381264(float, float, float, struct Surface **);
extern void func_802C9A3C(s32, s32);
extern void func_8029D62C(struct Object *, Mat4, Mat4);
extern void func_8029DA34(struct Object *, u32 *);
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
extern void func_80381F08(f32 sp40, f32 sp44);
// extern ? Unknown80382294(?);

#endif /* _SURFACE_COLLISION_H */
