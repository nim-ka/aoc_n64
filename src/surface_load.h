#ifndef _SURFACE_LOAD_H
#define _SURFACE_LOAD_H

struct SurfaceNode
{
    struct SurfaceNode *next;
    struct Surface *surface;
};

enum
{
    SPATIAL_PARTITION_FLOORS,
    SPATIAL_PARTITION_CEILS,
    SPATIAL_PARTITION_WALLS
};

typedef struct SurfaceNode SpatialPartitionCell[3];

extern s32 D_8038BE90;
extern SpatialPartitionCell gStaticSurfacePartition[16][16];
extern SpatialPartitionCell gDynamicSurfacePartition[16][16];

void alloc_surface_pools(void);
void load_area_terrain(s16 index, s16 *data, s8 *surfaceRooms, s16 *arg3);
void clear_dynamic_surfaces(void);
void load_object_collision_model(void);

#endif
