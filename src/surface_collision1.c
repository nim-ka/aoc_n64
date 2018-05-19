#include <ultra64.h>

#include "level_update.h"
#include "sm64.h"
#include "map_info.h"
#include "camera.h"
#include "mario.h"
#include "behavior_script.h"
#include "surface_collision.h"

s32 func_80380E8C(struct WallCollisionData *collision);

//* 80380690(J) */
s32 func_80380690(struct SurfaceNode * triNode, struct WallCollisionData * data) {
    register f32 offset;
    register f32 radius = data->radius; 
    register f32 x = data->x; 
    register f32 y = data->y + data->offsetY; 
    register struct Surface *tri; 
    register f32 z = data->z;
    register f32 xP, zP;
    register f32 w1, w2, w3; 
    register f32 y1, y2, y3; 
    s32 numCols = 0; 

    // Max collision radius = 200
    if (radius > 200.0f) radius = 200.0f;   

    // Look for collisions in triangle list
    while (triNode) {
        // Get next triangle
        tri = triNode->tri;
        triNode = triNode->next;

        if (y < tri->lowerY || y > tri->upperY) continue;

        offset = tri->normal[2] * z + (tri->normal[1] * y + tri->normal[0] * x) + tri->originOffset;

        if (offset < -radius || offset > radius) continue;

        xP = x;
        zP = z;

        if (tri->flags & 0x08) {
            w1 = -tri->vertex1[2];
            w2 = -tri->vertex2[2];
            w3 = -tri->vertex3[2];
            y1 = tri->vertex1[1];
            y2 = tri->vertex2[1];
            y3 = tri->vertex3[1];

            if (tri->normal[0] > 0.0f) {
                if ((y1 - y) * (w2 - w1) - (w1 - -zP) * (y2 - y1) > 0.0f) continue;
                if ((y2 - y) * (w3 - w2) - (w2 - -zP) * (y3 - y2) > 0.0f) continue;
                if ((y3 - y) * (w1 - w3) - (w3 - -zP) * (y1 - y3) > 0.0f) continue;
            }
            else {
                if ((y1 - y) * (w2 - w1) - (w1 - -zP) * (y2 - y1) < 0.0f) continue;
                if ((y2 - y) * (w3 - w2) - (w2 - -zP) * (y3 - y2) < 0.0f) continue;
                if ((y3 - y) * (w1 - w3) - (w3 - -zP) * (y1 - y3) < 0.0f) continue;
            }
        }
        else {
            w1 = tri->vertex1[0];
            w2 = tri->vertex2[0];
            w3 = tri->vertex3[0];
            y1 = tri->vertex1[1];
            y2 = tri->vertex2[1];
            y3 = tri->vertex3[1];

            if (tri->normal[2] > 0.0f) {
                if ((y1 - y) * (w2 - w1) - (w1 - xP) * (y2 - y1) > 0.0f) continue;
                if ((y2 - y) * (w3 - w2) - (w2 - xP) * (y3 - y2) > 0.0f) continue;
                if ((y3 - y) * (w1 - w3) - (w3 - xP) * (y1 - y3) > 0.0f) continue;
            }
            else {
                if ((y1 - y) * (w2 - w1) - (w1 - xP) * (y2 - y1) < 0.0f) continue;
                if ((y2 - y) * (w3 - w2) - (w2 - xP) * (y3 - y2) < 0.0f) continue;
                if ((y3 - y) * (w1 - w3) - (w3 - xP) * (y1 - y3) < 0.0f) continue;
            }
        }

        if (D_8035FE10) {
            if (tri->flags & 0x02) continue;
        }
        else 
        {
            if (tri->type == SURFACE_0072) {
                continue;
            }
            
            if (tri->type == SURFACE_007B) {
                if (gCurrentObject && (gCurrentObject->active & 0x0040) != 0)
                        continue;
                    
                if (gCurrentObject && gCurrentObject == gMarioObject && (gMarioState->flags & 02) != 0)
                    continue;
            }
        }
        
        data->x += tri->normal[0] * (radius - offset);
        data->z += tri->normal[2] * (radius - offset);

        if (data->numWalls < 4) {
            data->walls[data->numWalls++] = tri;
        }

        numCols++;
    }

    return numCols;
}

s32 func_80380DE8(f32 *xPtr, f32 *yPtr, f32 *zPtr, f32 offsetY, f32 radius) {
    struct WallCollisionData collision;
    s32 numCollisions = 0;

    collision.offsetY = offsetY;
    collision.radius = radius;
    
    collision.x = *xPtr;
    collision.y = *yPtr;
    collision.z = *zPtr;

    collision.numWalls = 0;

    numCollisions = func_80380E8C(&collision);
    *xPtr = collision.x;
    *yPtr = collision.y;
    *zPtr = collision.z;

    return numCollisions;
}

s32 func_80380E8C(struct WallCollisionData *collision)
{
    struct SurfaceNode *node;
    s16 xGrid, zGrid;
    s32 numCollisions = 0;
    s16 x = collision->x; 
    s16 z = collision->z;    

    collision->numWalls = 0;

    if (x < -0x1fff || x >= 0x2000) return numCollisions; 
    if (z < -0x1fff || z >= 0x2000) return numCollisions;  

    // World (level) consists of a 16x16 grid. Find where the collision is on 
    // the grid (round toward -inf)
    xGrid = ((x + 0x2000) / 0x400) & 0x0F;
    zGrid = ((z + 0x2000) / 0x400) & 0x0F;

    node = *(struct SurfaceNode **)((u32)&D_8038D6A8 + zGrid * 0x180 + xGrid * 0x18);
    numCollisions += func_80380690(node, collision);

    node = *(struct SurfaceNode **)((u32)&D_8038BEA8 + zGrid * 0x180 + xGrid * 0x18);
    numCollisions += func_80380690(node, collision);

    D_8033BF08++;
 
    return numCollisions;
}

struct Surface *func_80381038(struct SurfaceNode *triangles, s32 x, s32 y, s32 z, f32 *pheight) {
    register struct Surface *tri;
    register s32 x1, z1, x2, z2, x3, z3;
    struct Surface * sp24 = NULL;

    sp24 = NULL;
    while (triangles != NULL) {
        tri = triangles->tri;
        triangles = triangles->next;

        x1 = tri->vertex1[0];
        z1 = tri->vertex1[2];
        z2 = tri->vertex2[2];
        x2 = tri->vertex2[0];


        if ((z1 - z) * (x2 - x1) - (x1 - x) * (z2 - z1) > 0) continue;
        x3 = tri->vertex3[0];
        z3 = tri->vertex3[2];
        if ((z2 - z) * (x3 - x2) - (x2 - x) * (z3 - z2) > 0) continue;
        if ((z3 - z) * (x1 - x3) - (x3 - x) * (z1 - z3) > 0) continue;

        if (D_8035FE10 != 0)
        {
            if (tri->flags & 0x02)
                continue;
        }
        else if (tri->type == SURFACE_0072) {
            continue;
        }

        {   
            f32 nx = tri->normal[0];
            f32 ny = tri->normal[1];
            f32 nz = tri->normal[2];
            f32 oo = tri->originOffset;
            f32 height;

            if (ny == 0.0f) continue;

            height = -(x * nx + nz * z + oo) / ny;
            if (y - (height - -78.0f) > 0.0f) continue;

            *pheight = height;
            sp24 = tri;
            break;
        }
    }

  return sp24;
}

f32 func_80381264(float posX, float posY, float posZ, struct Surface **pceil) {
    s16 zidx, xidx;
    struct Surface *ceil, *dynCeil;
    struct SurfaceNode *node;
    f32 height = 20000.0f;
    f32 dynHeight = 20000.0f;
    s16 x, y, z;

    //! PUs
    x = (s16) posX; 
    y = (s16) posY;
    z = (s16) posZ;
    *pceil = NULL;

    if (x <= -0x2000 || x >= 0x2000) return height;
    if (z <= -0x2000 || z >= 0x2000) return height;

    xidx = ((x + 0x2000) / 0x400) & 0xF;
    zidx = ((z + 0x2000) / 0x400) & 0xF;

    node = &(*(struct SpatialPartitionCell **)((u32)&D_8038D6A0 + zidx * 0x180 + xidx * 0x18))->floors;
    dynCeil = func_80381038(node, x, y, z, &dynHeight);

    node = &(*(struct SpatialPartitionCell **)((u32)&D_8038BEA0 + zidx * 0x180 + xidx * 0x18))->floors;
    ceil = func_80381038(node, x, y, z, &height);

    if (dynHeight < height) {
        ceil = dynCeil;
        height = dynHeight;
    }

    *pceil = ceil;
    D_8033BF06 += 1;
    return height;
}

f32 func_80381470(struct Object *a0) {
    struct Surface *sp1C;
    f32 sp18;

    sp18 = func_80381900(a0->pos[0], a0->pos[1], a0->pos[2], &sp1C);

    return sp18;
}

f32 func_803814B8(f32 sp20, f32 sp24, f32 sp28, s32 **sp2C) {
    struct Surface *tri;
    f32 sp18;
    sp18 = func_80381900(sp20, sp24, sp28, &tri);

    *sp2C = NULL;

    if (tri != NULL) { 
        D_8038BE40 = tri->normal[0];
        D_8038BE44 = tri->normal[1];
        D_8038BE48 = tri->normal[2];
        D_8038BE4C = tri->originOffset;

        *sp2C = &D_8038BE30;
    }
    return sp18;
}

struct Surface *func_8038156C(struct SurfaceNode *triangles, s32 x, s32 y, s32 z, f32 *pheight) {
    register struct Surface *tri;
    register s32 x1, z1, x2, z2, x3, z3;
    f32 nx, ny, nz;
    f32 oo;
    f32 height;
    struct Surface *sp4 = NULL;

    while (triangles != NULL) {
        tri = triangles->tri;
        triangles = triangles->next;

        x1 = tri->vertex1[0];
        z1 = tri->vertex1[2];
        x2 = tri->vertex2[0];
        z2 = tri->vertex2[2];


        if ((z1 - z) * (x2 - x1) - (x1 - x) * (z2 - z1) < 0) continue;
        x3 = tri->vertex3[0];
        z3 = tri->vertex3[2];
        if ((z2 - z) * (x3 - x2) - (x2 - x) * (z3 - z2) < 0) continue;
        if ((z3 - z) * (x1 - x3) - (x3 - x) * (z1 - z3) < 0) continue;

        if (D_8035FE10 != 0)
        {
            if (tri->flags & 0x02)
                continue;
        }
        else if (tri->type == SURFACE_0072) {
            continue;
        }
        nx = tri->normal[0];
        ny = tri->normal[1];
        nz = tri->normal[2];
        oo = tri->originOffset;

        if (ny == 0.0f) continue;

        height = -(x * nx + nz * z + oo) / ny;
        if (y - (height + -78.0f) < 0.0f) continue;

        *pheight = height;
        sp4 = tri;
        break;
    }

    return sp4;
}

f32 func_80381794(f32 x, f32 y, f32 z) {
    struct Surface *floor;
    f32 sp18;
    sp18 = func_80381900(x, y, z, &floor);
    return sp18;
}

f32 func_803817E0(f32 sp38, f32 sp3C, f32 sp40, struct Surface **sp44) {
    struct SurfaceNode *sp34;
    struct Surface *sp30;
    f32 sp2C = -11000.0f;
    s16 sp2A = (s16) sp38;
    s16 sp28 = (s16) sp3C;
    s16 sp26 = (s16) sp40;

    s16 xidx = ((sp2A + 0x2000) / 0x400) & 0x0F;
    s16 zidx = ((sp26 + 0x2000) / 0x400) & 0x0F;

    sp34 = &(*(struct SpatialPartitionCell **)((u32)&D_8038D698 + zidx * 0x180 + xidx * 0x18))->floors;

    sp30 = func_8038156C(sp34, sp2A, sp28, sp26, &sp2C);
    *sp44 = sp30;
    return sp2C;
}

f32 func_80381900(f32 xPos, f32 yPos, f32 zPos, struct Surface **pfloor) {
    s16 zGrid, xGrid;
    struct Surface *floor, *dynFloor;
    struct SurfaceNode *node;
    f32 height = -11000.0f;
    f32 dynHeight = -11000.0f;

    //! PUs
    s16 x = (s16) xPos;
    s16 y = (s16) yPos;
    s16 z = (s16) zPos;

    *pfloor = NULL;

    if (x <= -0x2000 || x >= 0x2000) return height;
    if (z <= -0x2000 || z >= 0x2000) return height;

    xGrid = ((x + 0x2000) / 0x400) & 0xF;
    zGrid = ((z + 0x2000) / 0x400) & 0xF;

    node = *(struct SurfaceNode **)((u32)&D_8038D698 + zGrid * 0x180 + xGrid * 0x18);
    dynFloor = func_8038156C(node, x, y, z, &dynHeight);

    node = *(struct SurfaceNode **)((u32)&D_8038BE98 + zGrid * 0x180 + xGrid * 0x18);
    floor = func_8038156C(node, x, y, z, &height);

    if (D_8035FE12 == 0) {
        if (floor != NULL && floor->type == SURFACE_0012) {
            floor = func_8038156C(node, x, (s32) (height - 200.0f), z, &height);
        }
    }
    else {
        D_8035FE12 = 0;
    }
   

    if (floor == NULL)
        D_8033BEF4++;

    if (dynHeight > height) {
        floor = dynFloor;
        height = dynHeight;
    }

    *pfloor = floor;
    D_8033BF04++;
    return height;
}

f32 func_80381BA0(f32 x, f32 z) {
    s32 i; 
    s32 numRegions;
    s16 val;
    f32 loX, hiX, loZ, hiZ; 
    float sp8 = -11000.0f;
    s16 *p = D_8035FE14;

    if (p != NULL) {
        numRegions = *p++;

        for (i = 0; i < numRegions; i++) {
            val = *p++;
            loX = *p++;
            loZ = *p++;
            hiX = *p++;
            hiZ = *p++;

            if (loX < x && x < hiX && loZ < z && z < hiZ && val < 50)
            {
                sp8 = *p;
                break;
            }
            p++;
        }
    }

    return sp8;
}

f32 func_80381D3C(f32 x, f32 z) {
    s32 i; 
    s32 numRegions;
    UNUSED s32 unk;
    s16 val;
    f32 loX, hiX, loZ, hiZ; 
    float sp4 = -11000.0f;
    s16 *p = D_8035FE14;

    if (p != NULL) {
        numRegions = *p++;

        for (i = 0; i < numRegions; i++) {
            val = *p;

            if (val >= 50) {
                loX = *(p + 1);
                loZ = *(p + 2);
                hiX = *(p + 3);
                hiZ = *(p + 4);

                if (loX < x && x < hiX && loZ < z && z < hiZ && val % 10 == 0) {
                    sp4 = *(p + 5);
                    break;
                }
            }

            p += 6;
        }
    }

    return sp4;
}

s32 func_80381EC8(struct SurfaceNode *node) {
    s32 count = 0;

    while (node != NULL) {
        node = node->next;
        count++;
    }

    return count;
}

void func_80381F08(f32 sp40, f32 sp44) {
    struct SurfaceNode *sp3C;
    UNUSED s32 sp38 = 0;
    UNUSED s32 sp34 = 0;
    UNUSED s32 sp30 = 0;

    s32 sp2C = (sp40 + 0x2000) / 0x400;
    s32 sp28 = (sp44 + 0x2000) / 0x400;


    sp3C = &(*(struct SpatialPartitionCell **)((u32)&D_8038BE98 + (sp28 & 0x0F) * 0x180 + (sp2C & 0x0F) * 0x18))->floors;
    sp38 += func_80381EC8(sp3C);

    sp3C = &(*(struct SpatialPartitionCell **)((u32)&D_8038D698 + (sp28 & 0x0F) * 0x180 + (sp2C & 0x0F) * 0x18))->floors;
    sp38 += func_80381EC8(sp3C);


    sp3C = &(*(struct SpatialPartitionCell **)((u32)&D_8038BEA8 + (sp28 & 0x0F) * 0x180 + (sp2C & 0x0F) * 0x18))->floors;
    sp34 += func_80381EC8(sp3C);

    sp3C = &(*(struct SpatialPartitionCell **)((u32)&D_8038D6A8 + (sp28 & 0x0F) * 0x180 + (sp2C & 0x0F) * 0x18))->floors;
    sp34 += func_80381EC8(sp3C);


    sp3C = &(*(struct SpatialPartitionCell **)((u32)&D_8038BEA0 + (sp28 & 0x0F) * 0x180 + (sp2C & 0x0F) * 0x18))->floors;
    sp30 += func_80381EC8(sp3C);

    sp3C = &(*(struct SpatialPartitionCell **)((u32)&D_8038D6A0 + (sp28 & 0x0F) * 0x180 + (sp2C & 0x0F) * 0x18))->floors;
    sp30 += func_80381EC8(sp3C);


    AnotherPrint("area   %x", sp28 * 16 + sp2C);

    AnotherPrint("dg %d", sp38);
    AnotherPrint("dw %d", sp34);
    AnotherPrint("dr %d", sp30);

    func_802C9A3C(80, -3);

    AnotherPrint("%d", D_8033BF04);
    AnotherPrint("%d", D_8033BF08);
    AnotherPrint("%d", D_8033BF06);

    func_802C9A3C(-80, 0);

    AnotherPrint("listal %d", D_8035FDFC);  
    AnotherPrint("statbg %d", D_8035FE08);
    AnotherPrint("movebg %d", D_8035FE00 - D_8035FE08);

    D_8033BF04 = 0;
    D_8033BF06 = 0;
    D_8033BF08 = 0;
}

s32 func_80382294(s32 sp40, f32 *sp44, f32 *sp48, f32 *sp4C, f32 sp50, struct Surface **sp54, f32 *sp58) {
    f32 sp3C, sp38, sp34, sp30;
    f32 sp2C = *sp44, sp28 = *sp48, sp24 = *sp4C;
    f32 sp20, sp1C;

    *sp54 = 0;

    if (sp40 != 0)
        *sp58 = func_80381264(sp2C, sp28, sp24, sp54);
    else
        *sp58 = func_80381900(sp2C, sp28, sp24, sp54);

    if (*sp54 == NULL)
        return -1;

    sp3C = (*sp54)->normal[0];
    sp38 = (*sp54)->normal[1];
    sp34 = (*sp54)->normal[2];
    sp30 = (*sp54)->originOffset;

    sp20 = (sp3C * sp2C) + (sp38 * sp28) + (sp34 * sp24) + sp30;
    sp1C = sp20 >= 0 ? sp20 : -sp20;

    if (sp1C < sp50) {

        *sp44 += sp3C * (sp50 - sp20);
        *sp48 += sp38 * (sp50 - sp20);
        *sp4C += sp34 * (sp50 - sp20);

        return 1;
    }

    return 0;
}
