#include <ultra64.h>

#include "sm64.h"
#include "behavior_data.h"
#include "memory.h"
#include "object_helpers.h"
#include "ingame_menu.h"
#include "hud.h"
#include "mario.h"
#include "behavior_script.h"
#include "surface_collision.h"
#include "surface_load.h"


s32 D_8038BE90;

SpatialPartitionCell gStaticSurfacePartition[16][16];
SpatialPartitionCell gDynamicSurfacePartition[16][16];

static struct SurfaceNode *sSurfaceNodePool;
static struct Surface *sSurfacePool;
static s16 sSurfacePoolSize;

static u8 unused8038EEA8[0x30];


static struct SurfaceNode *alloc_surface_node(void)
{
    //! No bounds check (space for 7000)
    struct SurfaceNode *node = &sSurfaceNodePool[gSurfaceNodesAllocated];
    gSurfaceNodesAllocated++;

    node->next = NULL;
    if (gSurfaceNodesAllocated >= 7000) { }

    return node;
}

static struct Surface *alloc_surface(void)
{
    //! No bounds check (space for 2300)
    struct Surface *surface = &sSurfacePool[gSurfacesAllocated];
    gSurfacesAllocated++;

    if (gSurfacesAllocated >= sSurfacePoolSize) { }

    surface->type = 0;
    surface->force = 0;
    surface->flags = 0;
    surface->room = 0;
    surface->object = NULL;

    return surface;
}

static void clear_spatial_partition(SpatialPartitionCell *cells)
{
    register s32 i = 16 * 16;

    while (i--)
    {
        (*cells)[SPATIAL_PARTITION_FLOORS].next = NULL;
        (*cells)[SPATIAL_PARTITION_CEILS].next = NULL;
        (*cells)[SPATIAL_PARTITION_WALLS].next = NULL;

        cells++;
    }
}

static void clear_static_surfaces(void)
{
    clear_spatial_partition(&gStaticSurfacePartition[0][0]);
}

static void add_surface_to_cell(s16 dynamic, s16 cellX, s16 cellZ, struct Surface *surface)
{
    struct SurfaceNode *newNode = alloc_surface_node();
    struct SurfaceNode *list;
    s16 surfacePriority;
    s16 priority;
    s16 sortDir;
    s16 listIndex;

    if (surface->normal[1] > 0.01)
    {
        listIndex = SPATIAL_PARTITION_FLOORS;
        sortDir = 1; // highest to lowest, then insertion order
    }
    else if (surface->normal[1] < -0.01)
    {
        listIndex = SPATIAL_PARTITION_CEILS;
        sortDir = -1; // lowest to highest, then insertion order
    }
    else
    {
        listIndex = SPATIAL_PARTITION_WALLS;
        sortDir = 0; // insertion order

        if (surface->normal[0] < -0.707 || surface->normal[0] > 0.707)
            surface->flags |= SURFACE_FLAG_X_PROJECTION;
    }

    //! Sorting by vertex1.y - lots of cases where this is incorrect
    surfacePriority = surface->vertex1[1] * sortDir;

    newNode->surface = surface;

    if (dynamic)
        list = &gDynamicSurfacePartition[cellZ][cellX][listIndex];
    else
        list = &gStaticSurfacePartition[cellZ][cellX][listIndex];

    while (list->next != NULL)
    {
        priority = list->next->surface->vertex1[1] * sortDir;
        if (surfacePriority > priority)
            break;
        
        list = list->next;
    }

    newNode->next = list->next;
    list->next = newNode;
}

static s16 min3(s16 a0, s16 a1, s16 a2)
{
    if (a1 < a0)
        a0 = a1;

    if (a2 < a0)
        a0 = a2;

    return a0;
}

static s16 max3(s16 a0, s16 a1, s16 a2)
{
    if (a1 > a0)
        a0 = a1;

    if (a2 > a0)
        a0 = a2;

    return a0;
}

static s16 lower_cell_index(s16 t)
{
    s16 index;

    // Move from range [-0x2000, 0x2000) to [0, 0x4000)
    t += 0x2000;
    if (t < 0)
        t = 0;

    // [0, 16)
    index = t / 0x400;

    // Include extra cell if close to boundary
    if (t % 0x400 < 50)
        index -= 1;

    if (index < 0)
        index = 0;

    // Potentially > 15, but since the upper index is <= 15, not exploitable
    return index;
}


static s16 upper_cell_index(s16 t)
{
    s16 index;

    // Move from range [-0x2000, 0x2000) to [0, 0x4000)
    t += 0x2000;
    if (t < 0)
        t = 0;

    // [0, 16)
    index = t / 0x400;

    // Include extra cell if close to boundary
    if (t % 0x400 > 0x400 - 50)
        index += 1;

    if (index > 15)
        index = 15;

    // Potentially < 0, but since lower index is >= 0, not exploitable
    return index;
}

static void add_surface(struct Surface *surface, s32 dynamic)
{
    UNUSED s32 unused1, unused2;
    s16 minX, minZ, maxX, maxZ;
    s16 minCellX, minCellZ, maxCellX, maxCellZ;
    s16 cellZ, cellX;
    UNUSED s32 unused3 = 0;

    minX = min3(surface->vertex1[0], surface->vertex2[0], surface->vertex3[0]);
    minZ = min3(surface->vertex1[2], surface->vertex2[2], surface->vertex3[2]);
    maxX = max3(surface->vertex1[0], surface->vertex2[0], surface->vertex3[0]);
    maxZ = max3(surface->vertex1[2], surface->vertex2[2], surface->vertex3[2]);

    minCellX = lower_cell_index(minX);
    maxCellX = upper_cell_index(maxX);
    minCellZ = lower_cell_index(minZ);
    maxCellZ = upper_cell_index(maxZ);

    for (cellZ = minCellZ; cellZ <= maxCellZ; cellZ++)
        for (cellX = minCellX; cellX <= maxCellX; cellX++)
            add_surface_to_cell(dynamic, cellX, cellZ, surface);
}

static void unused_80382B6C(void) { }

static struct Surface *read_surface_data(s16 *vertexData, s16 **vertexIndices)
{
    struct Surface *surface;
    register s32 x1, y1, z1;
    register s32 x2, y2, z2;
    register s32 x3, y3, z3;
    s32 maxY, minY;
    f32 nx, ny, nz;
    f32 mag;
    s16 offset1, offset2, offset3;

    offset1 = 3 * (*vertexIndices)[0];
    offset2 = 3 * (*vertexIndices)[1];
    offset3 = 3 * (*vertexIndices)[2];

    x1 = *(vertexData + offset1 + 0);
    y1 = *(vertexData + offset1 + 1);
    z1 = *(vertexData + offset1 + 2);

    x2 = *(vertexData + offset2 + 0);
    y2 = *(vertexData + offset2 + 1);
    z2 = *(vertexData + offset2 + 2);

    x3 = *(vertexData + offset3 + 0);
    y3 = *(vertexData + offset3 + 1);
    z3 = *(vertexData + offset3 + 2);

    // (v2 - v1) x (v3 - v2)
    nx = (y2 - y1) * (z3 - z2) - (z2 - z1) * (y3 - y2);
    ny = (z2 - z1) * (x3 - x2) - (x2 - x1) * (z3 - z2);
    nz = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
    mag = sqrtf(nx*nx + ny*ny + nz*nz);

    minY = y1;
    if (y2 < minY) minY = y2;
    if (y3 < minY) minY = y3;

    maxY = y1;
    if (y2 > maxY) maxY = y2;
    if (y3 > maxY) maxY = y3;

    if (mag < 0.0001) return NULL;
    mag = (f32) (1.0 / mag);
    nx *= mag;
    ny *= mag;
    nz *= mag;

    surface = alloc_surface();

    surface->vertex1[0] = x1;
    surface->vertex2[0] = x2;
    surface->vertex3[0] = x3;

    surface->vertex1[1] = y1;
    surface->vertex2[1] = y2;
    surface->vertex3[1] = y3;

    surface->vertex1[2] = z1;
    surface->vertex2[2] = z2;
    surface->vertex3[2] = z3;

    surface->normal[0] = nx;
    surface->normal[1] = ny;
    surface->normal[2] = nz;

    surface->originOffset = -(nx*x1 + ny*y1 + nz*z1);

    surface->lowerY = minY - 5;
    surface->upperY = maxY + 5;

    return surface;
}

static s32 surface_has_force(s16 surfaceType)
{
    s32 hasForce = FALSE;

    switch (surfaceType)
    {
        case SURFACE_0004:
        case SURFACE_000E:
        case SURFACE_0024:
        case SURFACE_0025:
        case SURFACE_0027:
        case SURFACE_002C:
        case SURFACE_002D:
            hasForce = TRUE;
            break;
        default:
            break;
    }
    return hasForce;
}

static s32 get_surface_flags(s16 surfaceType)
{
    s32 flags = 0;

    switch (surfaceType)
    {
        case SURFACE_0076:
        case SURFACE_0077:
        case SURFACE_0078:
        case SURFACE_007A:
            flags = SURFACE_FLAG_1;
            break;

        default:
            break;
    }

    return flags;
}

static void load_static_surfaces(s16 **data, s16 *vertexData, s16 surfaceType, s8 **surfaceRooms)
{
    s32 i;
    s32 numSurfaces;
    struct Surface *surface;
    s8 room = 0;
    s16 hasForce = surface_has_force(surfaceType);
    s16 flags = get_surface_flags(surfaceType);

    numSurfaces = *(*data);
    *data += 1;

    for (i = 0; i < numSurfaces; i++)
    {
        if (*surfaceRooms != NULL)
        {
            room = *(*surfaceRooms);
            *surfaceRooms += 1;
        }

        surface = read_surface_data(vertexData, data);
        if (surface != NULL)
        {
            surface->room = room;
            surface->type = surfaceType;
            surface->flags = (s8) flags;

            if (hasForce)
                surface->force = *(*data + 3);
            else
                surface->force = 0;

            add_surface(surface, FALSE);
        }

        *data += 3;
        if (hasForce)
            *data += 1;
    }
}

static s16 *read_vertex_data(s16 **data)
{
    s32 numVertices;
    UNUSED s16 unused1[3];
    UNUSED s16 unused2[3];
    s16 *vertexData;

    numVertices = *(*data);
    (*data)++;

    vertexData = *data;
    *data += 3 * numVertices;

    return vertexData;
}

static void load_water_regions(s16 **data)
{
    s32 numRegions;
    s32 i;

    gWaterRegions = *data;
    numRegions = *(*data)++;

    if (numRegions > 20) {}

    for (i = 0; i < numRegions; i++)
    {
        UNUSED s16 val, loX, loZ, hiX, hiZ;
        s16 height;

        val = *(*data)++;
        loX = *(*data)++;
        hiX = *(*data)++;
        loZ = *(*data)++;
        hiZ = *(*data)++;
        height = *(*data)++;

        D_8035FE18[i] = height;
    }
}

void alloc_surface_pools(void)
{
    sSurfacePoolSize = 2300;
    sSurfaceNodePool = _pool_alloc(7000 * sizeof(struct SurfaceNode), MEMORY_POOL_LEFT);
    sSurfacePool = _pool_alloc(sSurfacePoolSize * sizeof(struct Surface), MEMORY_POOL_LEFT);
    D_8035FEEC = 0;
    func_802DA4DC();
}

void load_area_terrain(s16 arg0, s16 *data, s8 *surfaceRooms, s16 *arg3)
{
    s16 terrainType;
    s16 *vertexData;
    UNUSED s32 unused;

    gWaterRegions = NULL;
    D_8038BE90 = 0;
    gSurfaceNodesAllocated = 0;
    gSurfacesAllocated = 0;

    clear_static_surfaces();

    while (TRUE)
    {
        terrainType = *data;
        data++;

        if (terrainType < 0x40)
        {
            load_static_surfaces(&data, vertexData, terrainType, &surfaceRooms);
        }
        else if (terrainType == 0x40)
        {
            vertexData = read_vertex_data(&data);
        }
        else if (terrainType == 0x43)
        {
            func_802E19DC(arg0, &data);
        }
        else if (terrainType == 0x44)
        {
            load_water_regions(&data);
        }
        else if (terrainType == 0x41)
        {
            continue;
        }
        else if (terrainType == 0x42)
        {
            break;
        }
        else if (terrainType > 0x64)
        {
            load_static_surfaces(&data, vertexData, terrainType, &surfaceRooms);
            continue;
        }
    }

    if (arg3 != NULL && *arg3 != -1)
    {
        if (0 <= *arg3 && *arg3 < 30)
            func_802E1780(arg0, arg3);
        else
            func_802E1504(arg0, arg3);
    }

    gNumStaticSurfaceNodes = gSurfaceNodesAllocated;
    gNumStaticSurfaces = gSurfacesAllocated;
}

void clear_dynamic_surfaces(void)
{
    if (!(gTimeStopState & TIME_STOP_ACTIVE))
    {
        gSurfacesAllocated = gNumStaticSurfaces;
        gSurfaceNodesAllocated = gNumStaticSurfaceNodes;

        clear_spatial_partition(&gDynamicSurfacePartition[0][0]);
    }
}

static void unused_80383604(void) { }

static void transform_object_vertices(s16 **data, s16 *vertexData)
{
    register s16 *vertices;
    register s32 numVertices;
    register f32 vx;
    register f32 vy;
    register f32 vz;
    Mat4 *objectTransform;
    Mat4 m;
    UNUSED s16 unused;

    objectTransform = &gCurrentObject->unk21C;

    numVertices = *(*data);
    (*data)++;

    vertices = *data;

    if (gCurrentObject->gfx.unk50 == NULL)
    {
        gCurrentObject->gfx.unk50 = objectTransform;
        func_802A2188(gCurrentObject, 0x06, 0x12);
    }

    func_8029D62C(gCurrentObject, m, *objectTransform);

    while (numVertices--)
    {
        vx = *(vertices++);
        vy = *(vertices++);
        vz = *(vertices++);

        //! No bounds check on vertex data
        *vertexData++ = (s16) (vx * m[0][0] + vy*m[1][0] + vz*m[2][0] + m[3][0]);
        *vertexData++ = (s16) (vx * m[0][1] + vy*m[1][1] + vz*m[2][1] + m[3][1]);
        *vertexData++ = (s16) (vx * m[0][2] + vy*m[1][2] + vz*m[2][2] + m[3][2]);
    }

    *data = vertices;
}

static void load_object_surfaces(s16 **data, s16 *vertexData)
{
    s32 surfaceType;
    s32 i;
    s32 numSurfaces;
    s16 hasForce;
    s16 flags;
    s16 room;

    surfaceType = *(*data);
    (*data)++;

    numSurfaces = *(*data);
    (*data)++;

    hasForce = surface_has_force(surfaceType);
    flags = get_surface_flags(surfaceType);
    flags |= SURFACE_FLAG_DYNAMIC;

    if (gCurrentObject->behavior == segmented_to_virtual(beh_ddd_warp))
        room = 5;
    else
        room = 0;

    for (i = 0; i < numSurfaces; i++)
    {
        struct Surface *surface = read_surface_data(vertexData, data);

        if (surface != NULL)
        {
            surface->object = gCurrentObject;
            surface->type = surfaceType;

            if (hasForce)
                surface->force = *(*data + 3);
            else
                surface->force = 0;

            surface->flags |= flags;
            surface->room = (s8) room;
            add_surface(surface, TRUE);
        }

        if (hasForce)
            *data += 4;
        else
            *data += 3;
    }
}

void load_object_collision_model(void)
{
    UNUSED s32 unused;
    s16 vertexData[600];
    s16 *collisionData = gCurrentObject->collisionData;
    f32 marioDist = gCurrentObject->distanceFromMario;
    f32 tangibleDist = gCurrentObject->collisionDistance;

    if (gCurrentObject->distanceFromMario == 19000.0f)
        marioDist = objects_calc_distance(gCurrentObject, gMarioObject);

    if (gCurrentObject->collisionDistance > 4000.0f)
        gCurrentObject->drawingDistance = gCurrentObject->collisionDistance;

    if (!(gTimeStopState & TIME_STOP_ACTIVE) && marioDist < tangibleDist &&
        !(gCurrentObject->active & 0x0008))
    {
        collisionData++;
        transform_object_vertices(&collisionData, vertexData);

        while (*collisionData != 0x41)
            load_object_surfaces(&collisionData, vertexData);
    }

    if (marioDist < gCurrentObject->drawingDistance)
        gCurrentObject->gfx.graphFlags |= 0x0001;
    else
        gCurrentObject->gfx.graphFlags &= ~0x0001;
}
