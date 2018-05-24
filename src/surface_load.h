#ifndef _SURFACE_LOAD_H
#define _SURFACE_LOAD_H

extern s32 D_8038BE90;
extern SpatialPartitionCell gStaticSurfacePartition[16][16];
extern SpatialPartitionCell gDynamicSurfacePartition[16][16];

void alloc_surface_pools(void);
void load_area_terrain(s16 arg0, s16 *data, s8 *surfaceRooms, s16 *arg3);
void clear_dynamic_surfaces(void);
void load_object_collision_model(void);

#endif
