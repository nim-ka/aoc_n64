#include <ultra64.h>

#include "sm64.h"
#include "memory.h"
#include "level_functions.h"
#include "ingame_menu.h"
#include "hud.h"
#include "mario.h"
#include "behavior_script.h"
#include "surface_collision.h"


extern s32 D_8038BE90;
extern s32 D_8035FE04;
extern s32 D_13001C34;

struct SurfaceNode *func_80382490(void) {
    struct SurfaceNode *sp4 = &D_8038EE98[D_8035FDFC];
    D_8035FDFC++;

    sp4->next = NULL;
    if (D_8035FDFC >= 0x1b58) { }

    return sp4;
}

struct Surface *func_803824F8(void) {
    //! No bounds check (space for 2300)
    struct Surface *tri = &D_8038EE9C[D_8035FE00];
    D_8035FE00++;

    if (D_8035FE00 >= D_8038EEA0) { }

    tri->type = 0;
    tri->unk02 = 0;
    tri->flags = 0;
    tri->unk05 = 0;
    tri->object = NULL;
    return tri;
}

void func_80382590(struct SpatialPartitionCell *partition) {
    register s32 i = 256;
    while(i--) {
        partition->floors.next = NULL;
        partition->ceils.next = NULL;
        partition->walls.next = NULL;
        partition++;
    }
}

void func_803825D0(void) {
    func_80382590(D_8038BE98);
}

void func_803825FC(s16 dynamic, s16 xidx, s16 zidx, struct Surface *tri) {
    struct SurfaceNode *newNode = func_80382490();
    struct SurfaceNode *list;
    s16 triPriority;
    s16 priority;
    s16 sortDir;
    s16 listIdx;

    if (tri->normal[1] > 0.01) {
        listIdx = 0; // floors
        sortDir = 1; // highest to lowest, then insertion order
    }
    else if (tri->normal[1] < -0.01) {
        listIdx = 1; // ceils
        sortDir = -1; // lowest to highest, then insertion order
    }
    else {
        listIdx = 2; // walls
        sortDir = 0; // insertion order

        if (tri->normal[0] < -0.707 || tri->normal[0] > 0.707)
            tri->flags |= 0x08;
    }

    //! Sorting by vertex1.y - lots of cases where this is incorrect
    triPriority = tri->vertex1[1] * sortDir;
    newNode->tri = tri;

    if (dynamic) 
        list = (struct SurfaceNode *)((u32)&D_8038D698 + zidx * 0x180 + xidx * 0x18) + listIdx;
    else
        list = (struct SurfaceNode *)((u32)&D_8038BE98 + zidx * 0x180 + xidx * 0x18) + listIdx;

    while (list->next != NULL) {
        priority = list->next->tri->vertex1[1] * sortDir;
        if (triPriority > priority) break;
        list = list->next;
    }

    newNode->next = list->next;
    list->next = newNode;
}

s16 func_8038283C(s16 a0, s16 a1, s16 a2) {
    if (a1 < a0) 
        a0 = a1;

    if (a2 < a0)
        a0 = a2;

    return a0;
}

s16 func_8038289C(s16 a0, s16 a1, s16 a2) {
    if (a1 > a0) 
        a0 = a1;

    if (a2 > a0)
        a0 = a2;

    return a0;
}

s16 func_803828FC(s16 t) {
    s16 idx;
    t += 0x2000;
    if (t < 0) t = 0;

    idx = t / 0x400;

    // Include extra cell if close to boundary
    if (t % 0x400 < 50) idx--;

    if (idx < 0) idx = 0;

    // Potentially > 15, but since the upper index is <= 15, not exploitable
    return idx;
}


/** 80382990(J) */
s16 func_80382990(s16 t) {
    s16 idx;

    t += 0x2000;
    if (t < 0) t = 0;

    idx = t / 0x400;

    // Include extra cell if close to boundary
    if (t % 0x400 >= 975) idx++;

    if (idx > 15) idx = 15;

    // Potentially < 0, but since lower index is >= 0, not exploitable
    return idx;
}

void func_80382A2C(struct Surface *tri, s32 dynamic) {
    UNUSED s32 s46, s48;
    s16 minX, minZ, maxX, maxZ;
    s16 xidx0, zidx0, xidx1, zidx1;
    s16 zidx, xidx;
    UNUSED s32 sp24 = 0;


    minX = func_8038283C(tri->vertex1[0], tri->vertex2[0], tri->vertex3[0]);
    minZ = func_8038283C(tri->vertex1[2], tri->vertex2[2], tri->vertex3[2]);
    maxX = func_8038289C(tri->vertex1[0], tri->vertex2[0], tri->vertex3[0]);
    maxZ = func_8038289C(tri->vertex1[2], tri->vertex2[2], tri->vertex3[2]);

    xidx0 = func_803828FC(minX);
    xidx1 = func_80382990(maxX);
    zidx0 = func_803828FC(minZ);
    zidx1 = func_80382990(maxZ);

    for (zidx = zidx0; zidx <= zidx1; zidx++) {
        for (xidx = xidx0; xidx <= xidx1; xidx++) {
            func_803825FC(dynamic, xidx, zidx, tri);
        }
    }
}

void func_80382B6C(void) { }

struct Surface *func_80382B7C(s16 *vertexData, s16 **arg1) {
    struct Surface *tri;
    register s32 x1, y1, z1;
    register s32 x2, y2, z2;
    register s32 x3, y3, z3;
    s32 maxY, minY; // 84, 80
    f32 nx, ny, nz; // 76, 72, 68
    f32 mag; // 64
    s16 offset1, offset2, offset3; // 62, 60, 58

    offset1 = 3 * *(*arg1 + 0);
    offset2 = 3 * *(*arg1 + 1);
    offset3 = 3 * *(*arg1 + 2);

    x1 = *(vertexData + offset1 + 0);
    y1 = *(vertexData + offset1 + 1);
    z1 = *(vertexData + offset1 + 2);

    x2 = *(vertexData + offset2 + 0);
    y2 = *(vertexData + offset2 + 1);
    z2 = *(vertexData + offset2 + 2);

    x3 = *(vertexData + offset3 + 0);
    y3 = *(vertexData + offset3 + 1);
    z3 = *(vertexData + offset3 + 2);

    // clockwise
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

    tri = func_803824F8();

    tri->vertex1[0] = x1;
    tri->vertex2[0] = x2;
    tri->vertex3[0] = x3;

    tri->vertex1[1] = y1;
    tri->vertex2[1] = y2;
    tri->vertex3[1] = y3;

    tri->vertex1[2] = z1;
    tri->vertex2[2] = z2;
    tri->vertex3[2] = z3;

    tri->normal[0] = nx;
    tri->normal[1] = ny;
    tri->normal[2] = nz;

    tri->originOffset = -(nx*x1 + ny*y1 + nz*z1);

    tri->lowerY = minY - 5;
    tri->upperY = maxY + 5;

    return tri;
}

s32 func_80382F84(s16 surfaceType) {
    s32 sp4 = 0;

    switch (surfaceType) {
        case SURFACE_0004:
        case SURFACE_000E:
        case SURFACE_0024:
        case SURFACE_0025:
        case SURFACE_0027:
        case SURFACE_002C:
        case SURFACE_002D:
            sp4 = 1;
            break;
        default:
            break;
    }
    return sp4;
}

s32 func_80382FEC(s16 surfaceType) {
    s32 sp4 = 0;

    switch (surfaceType) {
        case 118:
        case 119:
        case 120:
        case 122:
            sp4 = 2;
            break;

        default:
            break;
    }

    return sp4;
}

void func_80383068(s16 **data, s16 *vertexData, s16 surfaceType, s8 **arg3) {
    s32 i;
    s32 numTris;
    struct Surface *tri;
    s8 valB = 0;
    s16 val8 = func_80382F84(surfaceType);
    s16 val6 = func_80382FEC(surfaceType);

    numTris = *(*data);
    *data += 1;

    for (i = 0; i < numTris; i++) {
        if (*arg3 != NULL) {
            valB = *(*arg3);
            *arg3 += 1;
        }

        tri = func_80382B7C(vertexData, data);
        if (tri != NULL) {
            tri->unk05 = valB;
            tri->type = surfaceType;
            tri->flags = (s8) val6;

            if (val8 != 0)
                tri->unk02 = *(*data + 3);
            else
                tri->unk02 = 0;

            func_80382A2C(tri, FALSE);
        }

        *data += 3;
        if (val8 != 0) *data += 1;
    }
}

s16 *func_803831D0(s16 **data) {
    s32 numVerts;
    UNUSED s16 unk2[3];
    UNUSED s16 unk[3];
    s16 *vertexData;

    numVerts = *(*data);
    (*data)++;
    vertexData = *data;
    *data += 3 * numVerts;

    return vertexData;
}

void func_80383228(s16 **data) {
    s32 numRegions; 
    s32 i;

    D_8035FE14 = *data;
    numRegions = *(*data)++;

    if (numRegions >= 21) {}

    for (i = 0; i < numRegions; i++) {
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


void func_80383340(void) {
    D_8038EEA0 = 2300;
    D_8038EE98 = _pool_alloc(7000 * sizeof(struct SurfaceNode), FALSE);
    D_8038EE9C = _pool_alloc(D_8038EEA0 * sizeof(struct Surface), FALSE);
    D_8035FEEC = 0;
    func_802DA4DC(); 
}

void func_803833B8(s16 arg0, s16 *arg1, s8 *arg2, s16 *arg3) {
    s16 val;
    s16 *vertexData;
    UNUSED s32 unk;

    D_8035FE14 = NULL;
    D_8038BE90 = 0;
    D_8035FDFC = 0;
    D_8035FE00 = 0;

    func_803825D0();

    while(TRUE) {
        val = *arg1;
        arg1++;

        if (val < 0x40)
            func_80383068(&arg1, vertexData, val, &arg2);
        else if (val == 0x40)
            vertexData = func_803831D0(&arg1);
        else if (val == 0x43)
            func_802E19DC(arg0, &arg1);
        else if (val == 0x44)
            func_80383228(&arg1);
        else if (val == 0x41)
            continue;
        else if (val == 0x42) 
            break;
        else if (val > 100) {
            func_80383068(&arg1, vertexData, val, &arg2);
            continue;
        }
    }

    if (arg3 != NULL && *arg3 != -1) {
        if (0 <= *arg3 && *arg3 < 30)
            func_802E1780(arg0, arg3);
        else
            func_802E1504(arg0, arg3);
    }

    D_8035FE04 = D_8035FDFC;
    D_8035FE08 = D_8035FE00;
}

void func_803835A4(void) {
    if ((D_8033C110 & 0x40) == 0) {
        D_8035FE00 = D_8035FE08;
        D_8035FDFC = D_8035FE04;

        func_80382590(D_8038D698);
    }
}

void func_80383604(void) { }

void func_80383614(s16 **data, s16 *vertexData) {
    register s16 *s0;
    register s32 s1;
    register f32 vx;
    register f32 vy;
    register f32 vz;
    Mat4p transform; 
    Mat4 m;
    UNUSED s16 numVerts;

    transform = &gCurrentObject->unk21C[0];
    

    s1 = (*data)[0];
    (*data)++;
    s0 = *data;

    if (gCurrentObject->gfx.unk50 == NULL) {
        gCurrentObject->gfx.unk50 = transform;
        func_802A2188(gCurrentObject, 0x06, 0x12);
    }


    func_8029D62C(gCurrentObject, &m[0], transform);
    //s2 = s1;
    while (s1--) {
        vx = *(s0++);
        vy = *(s0++);
        vz = *(s0++);

        *vertexData++ = (s16) (vx * m[0][0] + vy*m[1][0] + vz*m[2][0] + m[3][0]);
        *vertexData++ = (s16) (vx * m[0][1] + vy*m[1][1] + vz*m[2][1] + m[3][1]);
        *vertexData++ = (s16) (vx * m[0][2] + vy*m[1][2] + vz*m[2][2] + m[3][2]);
    }

    *data = s0;
}

void func_80383828(s16 **data, s16 *vertexData) {
    s32 surfaceType;
    s32 i;
    s32 numTris;
    s16 sp20, sp1E;
    s16 sp1C;

    surfaceType = (*data)[0];
    (*data)++;
    numTris = *(*data);
    (*data)++;

    sp20 = func_80382F84(surfaceType);
    sp1E = func_80382FEC(surfaceType);
    sp1E |= 0x0001;


    if (gCurrentObject->unk20C == segmented_to_virtual(&D_13001C34))
        sp1C = 5;
    else
        sp1C = 0;

    for (i = 0; i < numTris; i++) {
        struct Surface *tri = func_80382B7C(vertexData, data);

        if (tri != NULL) {
            tri->object = gCurrentObject;
            tri->type = surfaceType;

            if (sp20 != 0)
                tri->unk02 = *(*data + 3);
            else
                tri->unk02 = 0;

            tri->flags |= sp1E;
            tri->unk05 = (s8) sp1C;
            func_80382A2C(tri, TRUE);
        }

        if (sp20 != 0)
            *data += 4;
        else
            *data += 3;
    }
}

void ProcessCollision(void) {
    UNUSED s32 unk;
    s16 vertexData[600];
    s16 *val8 = gCurrentObject->collisionData;
    f32 marioDist = gCurrentObject->distanceFromMario;
    f32 tangibleDist = gCurrentObject->collisionDistance;

    if (gCurrentObject->distanceFromMario == 19000.0f)
        marioDist = objects_calc_distance(gCurrentObject, gMarioObject);

    if (gCurrentObject->collisionDistance > 4000.0f)
        gCurrentObject->drawingDistance = gCurrentObject->collisionDistance;

    if (!(D_8033C110 & 0x00000040) && marioDist < tangibleDist &&
        !(gCurrentObject->active & 0x0008)) {
        val8++;
        func_80383614(&val8, vertexData);

        while (*val8 != 0x41) {
            func_80383828(&val8, vertexData);
        }
    }

    if (marioDist < gCurrentObject->drawingDistance)
        gCurrentObject->gfx.graphFlags |= 0x0001;
    else
        gCurrentObject->gfx.graphFlags &= ~0x0001;
}
