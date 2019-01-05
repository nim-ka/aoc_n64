#include <ultra64.h>

#include "sm64.h"
#include "shadow.h"
#include "graph_node.h"
#include "math_util.h"
#include "surface_collision.h"
#include "transparent_texture.h"
#include "rendering_graph_node.h"
#include "segment2.h"
#include "mario.h"
#include "area.h"
#include "memory.h"
#include "save_file.h"
#include "room.h"

/**
 * Encapsulate information about a shadow at the time of its creation.
 */
struct Shadow {
    /* The (x, y, z) position of the object whose shadow this is. */
    f32 parentX;
    f32 parentY;
    f32 parentZ;
    /* The y-position of the floor (or water or lava) underneath the object. */
    f32 floorHeight;
    /* Initial (unmodified) size of the shadow. */
    f32 shadowScale;
    /* (nx, ny, nz) normal vector of the floor underneath the object. */
    f32 floorNormalX;
    f32 floorNormalY;
    f32 floorNormalZ;
    /* "originOffset" of the floor underneath the object. */
    f32 floorOriginOffset;
    /* Angle describing "which way a marble would roll," in degrees. */
    f32 floorDownwardAngle;
    /* Angle describing "how tilted the ground is" in degrees (-90 to 90). */
    f32 floorTilt;
    /* Initial solidity of the shadow, from 0 to 255 (just an alpha value). */
    u8 solidity;
};

/**
 * Function declarations.
 */
void rotate_rectangle(f32 *, f32 *, f32, f32);
f32  atan2_deg(f32, f32);
f32  scale_shadow_with_distance(f32, f32);
f32  disable_shadow_with_distance(f32, f32);
u8   dim_shadow_with_distance(u8, f32);
f32  get_water_level_below_shadow(struct Shadow *);
s8   init_shadow(struct Shadow *, f32, f32, f32, s16, u8);
void get_texture_coords_9_vertices(s8, s16 *, s16 *);
void get_texture_coords_4_vertices(s8, s16 *, s16 *);
void make_shadow_vertex_at_xyz(Vtx *, s8, f32, f32, f32, u8, s8);
f32  extrapolate_vertex_y_position(struct Shadow, f32, f32);
void get_vertex_coords(s8, s8, s8 *, s8 *);
void calculate_vertex_xyz(s8, struct Shadow, f32 *, f32 *, f32 *, s8);
s16  floor_local_tilt(struct Shadow, f32, f32, f32);
void make_shadow_vertex(Vtx *, s8, struct Shadow, s8);
void add_shadow_to_display_list(Gfx *, Vtx *, s8, s8);
void func_802CD7DC(struct Shadow *, u8, s16, s16, s16);
void func_802CD90C(struct Shadow *, u8, s16, s16, s16);
s8   func_802CDA44(s32, u8, struct Shadow *);
void correct_lava_shadow_height(struct Shadow *);
Gfx *func_802CDCBC(f32, f32, f32, s16, u8, s32);
Gfx *draw_shadow_circle_9_verts(f32, f32, f32, s16, u8);
Gfx *draw_shadow_circle_4_verts(f32, f32, f32, s16, u8);
Gfx *draw_shadow_circle_assuming_flat_ground(f32, f32, f32, s16, u8);
Gfx *draw_shadow_rectangle(f32, f32, f32, u8);
s32  get_shadow_height_solidity(f32, f32, f32, f32 *, u8 *);
Gfx *draw_shadow_square(f32, f32, f32, s16, u8, s8);
Gfx *draw_shadow_hardcoded_rectangle(f32, f32, f32, s32, u8, s8);
Gfx *create_shadow_below_xyz(f32, f32, f32, s16, u8, s8);

/**
 * In-file constants.
 */
#define SHADOW_SHAPE_CIRCLE 10
#define SHADOW_SHAPE_SQUARE 20

/**
 * Flag for if a shadow has 4 or 9 vertices.
 */
#define SHADOW_WITH_9_VERTS 0
#define SHADOW_WITH_4_VERTS 1

/**
 * A simple struct containing info about hardcoded rectangle shadows.
 */
typedef struct {
    /* These must be equal to 1/2 width and length, respectively. */
    f32 halfWidth;
    f32 halfLength;
    /* Flag: should this shadow be smaller when its object is further away? */
    s8 scaleWithDistance;
} shadowRectangle;

shadowRectangle rectangles[2] = {
    // Spindel shadow:
    {360.0f, 230.0f, TRUE},
    // TODO: Find out what this is. (In "koopa_log_piranha_whomp_chomp.geo",
    // it's the "0x16000033" word, indicating shadow type 0x33.)
    // My guess is that it's for the log, since it's long and thin.
    {200.0f, 180.0f, TRUE}
};

s8 D_8035FF40;
s16 gSurfaceTypeBelowShadow;
s8 gShadowAboveWaterOrLava;
s8 D_8035FF45;

/**
 * Let (oldZ, oldX) be the relative coordinates of a point on a rectangle,
 * assumed to be centered at the origin on the standard SM64 X-Z plane. This
 * function will update (newZ, newX) to equal the new coordinates of that point
 * after a rotation equal to the yaw of the current(?) object.
 */
void rotate_rectangle(f32 *newZ, f32 *newX, f32 oldZ, f32 oldX) {
    struct Object *obj = (struct Object *) D_8032CFA0;
    *newZ = oldZ * coss(obj->oFaceAngleYaw) - oldX * sins(obj->oFaceAngleYaw);
    *newX = oldZ * sins(obj->oFaceAngleYaw) + oldX * coss(obj->oFaceAngleYaw);
}

f32 atan2_deg(f32 a, f32 b) {
    return ((f32) atan2s(a, b) / 65535.0 * 360.0);
}

/**
 * Shrink a shadow when its parent object is further from the floor, given the
 * initial size of the shadow and the current distance.
 */
f32 scale_shadow_with_distance(f32 initial, f32 distFromFloor) {
    f32 newScale;
    if (distFromFloor <= 0.0) {
        newScale = initial;
    } else if (distFromFloor >= 600.0) {
        newScale = initial * 0.5;
    } else {
        newScale = initial * (1.0 - (0.5 * distFromFloor / 600.0));
    }

    return newScale;
}

/**
 * Disable a shadow when its parent object is more than 600 units from the ground.
 */
f32 disable_shadow_with_distance(f32 shadowScale, f32 distFromFloor) {
    if (distFromFloor >= 600.0) {
        return 0.0f;
    } else {
        return shadowScale;
    }
}

/**
 * Dim a shadow when its parent object is further from the ground.
 */
u8 dim_shadow_with_distance(u8 solidity, f32 distFromFloor) {
    f32 ret;

    if (solidity < 121) {
        return solidity;
    } else if (distFromFloor <= 0.0) {
        return solidity;
    } else if (distFromFloor >= 600.0) {
        return 120;
    } else {
        ret = ((120 - solidity) * distFromFloor) / 600.0 + (f32) solidity;
        return ret;
    }
}

f32 get_water_level_below_shadow(struct Shadow *s) {
    f32 waterLevel = find_water_level(s->parentX, s->parentZ);
    if (waterLevel < -10000.0) {
        return 0;
    } else if (s->parentY >= waterLevel && s->floorHeight <= waterLevel) {
        gShadowAboveWaterOrLava = TRUE;
        return waterLevel;
    }
    //! Missing return statement
}

s8 init_shadow(
    struct Shadow *s, f32 xPos, f32 yPos, f32 zPos, s16 shadowScale, u8 shadowSolidity
) {
    f32 waterLevel;
    f32 sp20;
    f32 *sp1c;

    s->parentX = xPos;
    s->parentY = yPos;
    s->parentZ = zPos;

    s->floorHeight = func_803814B8(s->parentX, s->parentY, s->parentZ, &sp1c);
    if (gWaterRegions != 0) {
        waterLevel = get_water_level_below_shadow(s);
    }
    if (gShadowAboveWaterOrLava) {
        //! Use of potentially undefined variable (waterLevel)
        s->floorHeight = waterLevel;
        s->floorNormalX = 0;
        s->floorNormalY = 1.0;
        s->floorNormalZ = 0;
        s->floorOriginOffset = -waterLevel;
    } else {
        if (s->floorHeight < -10000.0 || sp1c[5] <= 0.0) {
            return 1;
        }
        s->floorNormalX = sp1c[4];
        s->floorNormalY = sp1c[5];
        s->floorNormalZ = sp1c[6];
        s->floorOriginOffset = sp1c[7];
    }
    if (shadowSolidity != 0) {
        s->solidity = dim_shadow_with_distance(shadowSolidity, yPos - s->floorHeight);
    }
    s->shadowScale = scale_shadow_with_distance(shadowScale, yPos - s->floorHeight);
    s->floorDownwardAngle = atan2_deg(s->floorNormalZ, s->floorNormalX);
    sp20 = sqrtf(
        s->floorNormalX * s->floorNormalX +
        s->floorNormalZ * s->floorNormalZ);
    if (sp20 == 0.0) {
        s->floorTilt = 0;
    } else {
        s->floorTilt = 90.0 - (f64) atan2_deg(sp20, s->floorNormalY);
    }
    return 0;
}

/**
 * Given a vertex number from a shadow with nine vertices, return the
 * texture coordinates corresponding to that vertex. That is:
 *      0 = (-15, -15)         1 = (0, -15)         2 = (15, -15)
 *      3 = (-15,   0)         4 = (0,   0)         5 = (15,   0)
 *      6 = (-15,  15)         7 = (0,  15)         8 = (15,  15)
 */
void get_texture_coords_9_vertices(s8 vertexNum, s16 *textureX, s16 *textureY) {
    *textureX = vertexNum % 3 * 15 - 15;
    *textureY = vertexNum / 3 * 15 - 15;
}

/**
 * Given a vertex number from a shadow with four vertices, return the
 * texture coordinates corresponding to that vertex. That is:
 *      0 = (-15, -15)         1 = (15, -15)
 *      2 = (-15,  15)         3 = (15,  15)
 */
void get_texture_coords_4_vertices(s8 vertexNum, s16 *textureX, s16 *textureY) {
    *textureX = (vertexNum % 2) * 2 * 15 - 15;
    *textureY = (vertexNum / 2) * 2 * 15 - 15;
}

void make_shadow_vertex_at_xyz(
    Vtx *vertices, s8 index, f32 relX, f32 relY, f32 relZ, u8 alpha, s8 shadowVertexType
) {
    s16 vtxX = round_float(relX);
    s16 vtxY = round_float(relY);
    s16 vtxZ = round_float(relZ);
    s16 textureX, textureY;

    switch (shadowVertexType) {
        case SHADOW_WITH_9_VERTS:
            get_texture_coords_9_vertices(index, &textureX, &textureY);
            break;
        case SHADOW_WITH_4_VERTS:
            get_texture_coords_4_vertices(index, &textureX, &textureY);
            break;
    }
    if (D_8035FF40) {
        vtxX += 5;
        vtxY += 5;
        vtxZ += 5;
    }
    make_vertex(
        vertices,
        index,
        vtxX, vtxY, vtxZ,
        textureX << 5, textureY << 5,
        255, 255, 255, alpha  // RGBA
    );
}

/**
 * Given an (x, z) position close to a shadow (for example, a vertex position),
 * return the extrapolated y-position for that point given the floor's normal
 * vector.
 */
f32 extrapolate_vertex_y_position(struct Shadow s, f32 vtxX, f32 vtxZ) {
    return -(
        s.floorNormalX * vtxX +
        s.floorNormalZ * vtxZ +
        s.floorOriginOffset
    ) / s.floorNormalY;
}

/**
 * Given a vertex number from a shadow with either 4 or 9 vertices, return the
 * texture coordinates corresponding to that vertex, ranging in the square with
 * corners at (-1, -1), (1, -1), (-1, 1), and (1, 1) in the x-z plane. See
 * "get_texture_coords_9_vertices" and "get_texture_coords_4_vertices", which
 * have the same functionality, but return 15 times the values.
 */
void get_vertex_coords(s8 index, s8 shadowVertexType, s8 *xCoord, s8 *zCoord) {
    *xCoord = index % (3 - shadowVertexType) - 1;
    *zCoord = index / (3 - shadowVertexType) - 1;

    // This just corrects the 4-vertex case to have consistent results with the
    // 9-vertex case.
    if (shadowVertexType == SHADOW_WITH_4_VERTS) {
        if (*xCoord == 0) {
            *xCoord = 1;
        }
        if (*zCoord == 0) {
            *zCoord = 1;
        }
    }
}

void calculate_vertex_xyz(
    s8 index, struct Shadow s, f32 *xPosVtx, f32 *yPosVtx, f32 *zPosVtx,
    s8 shadowVertexType
) {
    f32 sp6c = cosf((f64) s.floorTilt * M_PI / 180.0) * s.shadowScale;
    f32 sp68 = (f64) s.floorDownwardAngle * M_PI / 180.0;
    f32 sp60;
    f32 sp64;
    s8 xCoordUnit;
    s8 zCoordUnit;
    f32 *dummy;

    get_vertex_coords(index, shadowVertexType, &xCoordUnit, &zCoordUnit);

    sp60 = (f64) (xCoordUnit * s.shadowScale) / 2.0;
    sp64 = (f64) (zCoordUnit * sp6c) / 2.0;

    *xPosVtx = (sp64 * sinf(sp68)) + (sp60 * cosf(sp68)) + s.parentX;
    *zPosVtx = (sp64 * cosf(sp68)) - (sp60 * sinf(sp68)) + s.parentZ;

    if (gShadowAboveWaterOrLava) {
        *yPosVtx = s.floorHeight;
    } else {
        switch (shadowVertexType) {
            case SHADOW_WITH_9_VERTS:
                *yPosVtx = func_803814B8(*xPosVtx, s.parentY, *zPosVtx, &dummy);
                break;
            case SHADOW_WITH_4_VERTS:
                *yPosVtx = extrapolate_vertex_y_position(s, *xPosVtx, *zPosVtx);
                break;
        }
    }
}

/**
 * Given a vertex's (x, y, z) location, return the dot product of the
 * position of that vertex (relative to the middle vertex, i.e. the point
 * right below the object) with the floor normal (at the middle vertex).
 * Since it is a dot product, this returns 0 if these two vectors are
 * perpendicular, meaning the ground is locally flat. It will return nonzero
 * in most cases where vtxY is on a different floor triangle from the
 * middle vertex, as in the case with SHADOW_WITH_9_VERTS, which sets
 * the y-value from func_803814B8().
 */
s16 floor_local_tilt(struct Shadow s, f32 vtxX, f32 vtxY, f32 vtxZ) {
    f32 relX = vtxX - s.parentX;
    f32 relY = vtxY - s.floorHeight;
    f32 relZ = vtxZ - s.parentZ;

    f32 ret = (relX * s.floorNormalX) +
              (relY * s.floorNormalY) +
              (relZ * s.floorNormalZ);
    return ret;
}

void make_shadow_vertex(Vtx *vertices, s8 index, struct Shadow s, s8 shadowVertexType) {
    f32 xPosVtx, yPosVtx, zPosVtx;
    f32 relX, relY, relZ;
    u8 solidity = s.solidity;

    if (gShadowAboveWaterOrLava != 0) {
        solidity = 200;
    }

    calculate_vertex_xyz(index, s, &xPosVtx, &yPosVtx, &zPosVtx, shadowVertexType);

    // I believe this is the hack that makes "SHADOW_WITH_9_VERTS" act
    // identically to the "SHADOW_WITH_4_VERTS" in the game; this same hack is
    // disabled by the gameshark code in this video:
    // https://www.youtube.com/watch?v=MSIh4rtNGF0.
    // The code in the video will make "extrapolate_vertex_y_position"
    // return the same value as the last float-returning function did; in this
    // case, that's func_803814B8, which this if-statement was designed to
    // overwrite in the first place.
    // The last condition here means the y-position calculated previously
    // was probably on a different floor triangle from the center vertex.
    if (shadowVertexType == SHADOW_WITH_9_VERTS &&
        !gShadowAboveWaterOrLava                &&
        floor_local_tilt(s, xPosVtx, yPosVtx, zPosVtx) != 0)
    {
        yPosVtx = extrapolate_vertex_y_position(s, xPosVtx, zPosVtx);
        solidity = 0;
    }
    relX = xPosVtx - s.parentX;
    relY = yPosVtx - s.parentY;
    relZ = zPosVtx - s.parentZ;

    make_shadow_vertex_at_xyz(
        vertices, index, relX, relY, relZ, solidity, shadowVertexType);
}


void add_shadow_to_display_list(
    Gfx *displayListHead, Vtx *verts, s8 shadowVertexType, s8 shadowShape
) {
    switch (shadowShape) {
        case SHADOW_SHAPE_CIRCLE:
            gSPDisplayList(displayListHead++, seg2_dl_02014548);
            break;
        case SHADOW_SHAPE_SQUARE:
            gSPDisplayList(displayListHead++, seg2_dl_02014590)
            break;
    }
    switch (shadowVertexType) {
        case SHADOW_WITH_9_VERTS:
            gSPVertex(displayListHead++, verts, 9, 0x80);
            gSPDisplayList(displayListHead++, seg2_dl_020145D8);
            break;
        case SHADOW_WITH_4_VERTS:
            gSPVertex(displayListHead++, verts, 4, 0x30);
            gSPDisplayList(displayListHead++, seg2_dl_02014620);
            break;
    }
    gSPDisplayList(displayListHead++, seg2_dl_02014638);
    gSPEndDisplayList(displayListHead);
}

// This function just dims all shadows in the midrange logistically, with
// the midrange being defined by arg4 - arg3 and "quickness" by arg2 - arg3.
// It doesn't make much sense to me at the moment. Probably related to
// specific Mario animations.
void func_802CD7DC(struct Shadow *s, u8 initial, s16 arg2, s16 arg3, s16 arg4) {
    if (arg2 >= 0 && arg2 < arg3) {
        s->solidity = 0;
    } else if (arg4 < arg2) {
        s->solidity = initial;
    } else {
        s->solidity = (f32) initial * (arg2 - arg3) / (arg4 - arg3);
    }
}

// Similar to above.
void func_802CD90C(struct Shadow *s, u8 initial, s16 arg2, s16 arg3, s16 arg4) {
    if (arg2 >= arg3 && arg4 >= arg2) {
        s->solidity = ((f32) initial * (1.0 - (f32) (arg2 - arg3) / (arg4 - arg3)));
    } else {
        s->solidity = 0;
    }
}

// Dims shadows according to some formula. Only done for "playable characters".
// Maybe "shadow addition"?
s8 func_802CDA44(s32 isLuigi, u8 initialSolidity, struct Shadow *shadow) {
    struct Object *sp34;
    s8 sp33;
    s16 animFrame;

    switch (isLuigi) {
        case 0:
            sp34 = gMarioObject;
            break;
        case 1:
            //! This is unironically probably Luigi. This variable is never
            // used anywhere else in the code, lies in memory just after the
            // Mario object, and appears to have the special "Mario shadows".
            sp34 = gLuigiObject;
            break;
    }
    animFrame = sp34->header.gfx.unk38.animFrame;
    switch (sp34->header.gfx.unk38.animID) {
        case 51:
            sp33 = 0;
            break;
        case 52:
            func_802CD7DC(shadow, initialSolidity, animFrame, 5, 14);
            sp33 = 1;
            break;
        case 0:
            func_802CD7DC(shadow, initialSolidity, animFrame, 21, 33);
            sp33 = 1;
            break;
        case 28:
            func_802CD90C(shadow, initialSolidity, animFrame, 0, 5);
            sp33 = 1;
            break;
        default:
            sp33 = 2;
            break;
    }
    return sp33;
}

void correct_lava_shadow_height(struct Shadow *s) {
    if (gCurrLevelNum == LEVEL_BITFS && gSurfaceTypeBelowShadow == SURFACE_LAVA) {
        if (s->floorHeight < -3000.0) {
            s->floorHeight = -3062.0;
            gShadowAboveWaterOrLava = TRUE;
        } else if (s->floorHeight > 3400.0) {
            s->floorHeight = 3492.0;
            gShadowAboveWaterOrLava = TRUE;
        }
    } else if (
        gCurrLevelNum == LEVEL_LLL &&
        gCurrAreaIndex == 1        &&
        gSurfaceTypeBelowShadow == SURFACE_LAVA
    ) {
        s->floorHeight = 5.0;
        gShadowAboveWaterOrLava = TRUE;
    }
}

Gfx *func_802CDCBC(
    f32 xPos, f32 yPos, f32 zPos, s16 shadowScale, u8 solidity, s32 isLuigi
) {
    Vtx *verts;
    Gfx *displayList;
    struct Shadow shadow;
    s8 ret;
    s32 i;

    if (gCurrLevelNum == LEVEL_RR && gSurfaceTypeBelowShadow != SURFACE_000A) {
        switch (D_8035FF80) {
            case 1:
                D_8035FF45 = 1;
                D_8035FF40 = 1;
                break;
            case 2:
                D_8035FF45 = 1;
                break;
        }
    }
    switch (func_802CDA44(isLuigi, solidity, &shadow)) {
        case 0:
            return 0;
            break;
        case 1:
            ret = init_shadow(&shadow, xPos, yPos, zPos, shadowScale, 0);
            break;
        case 2:
            ret = init_shadow(&shadow, xPos, yPos, zPos, shadowScale, solidity);
            break;
    }
    if (ret != 0) {
        return NULL;
    }
    verts = alloc_display_list(9 * sizeof(Vtx));
    displayList = alloc_display_list(5 * sizeof(Gfx));
    if (verts == NULL || displayList == NULL) {
        return NULL;
    }

    correct_lava_shadow_height(&shadow);
    for (i = 0; i < 9; i++) {
        make_shadow_vertex(verts, i, shadow, SHADOW_WITH_9_VERTS);
    }
    add_shadow_to_display_list(
        displayList, verts, SHADOW_WITH_9_VERTS, SHADOW_SHAPE_CIRCLE);
    return displayList;
}

Gfx *draw_shadow_circle_9_verts(f32 xPos, f32 yPos, f32 zPos, s16 shadowScale, u8 solidity) {
    Vtx *verts;
    Gfx *displayList;
    struct Shadow shadow;
    s32 i;

    if (init_shadow(&shadow, xPos, yPos, zPos, shadowScale, solidity) != 0) {
        return NULL;
    }

    verts = alloc_display_list(9 * sizeof(Vtx));
    displayList = alloc_display_list(5 * sizeof(Gfx));

    if (verts == NULL || displayList == NULL) {
        return 0;
    }
    for (i = 0; i < 9; i++) {
        make_shadow_vertex(verts, i, shadow, SHADOW_WITH_9_VERTS);
    }
    add_shadow_to_display_list(
        displayList, verts, SHADOW_WITH_9_VERTS, SHADOW_SHAPE_CIRCLE);
    return displayList;
}

Gfx *draw_shadow_circle_4_verts(f32 xPos, f32 yPos, f32 zPos, s16 shadowScale, u8 solidity) {
    Vtx *verts;
    Gfx *displayList;
    struct Shadow shadow;
    s32 i;

    if (init_shadow(&shadow, xPos, yPos, zPos, shadowScale, solidity) != 0) {
        return NULL;
    }

    verts = alloc_display_list(4 * sizeof(Vtx));
    displayList = alloc_display_list(5 * sizeof(Gfx));

    if (verts == NULL || displayList == NULL) {
        return 0;
    }

    for (i = 0; i < 4; i++) {
        make_shadow_vertex(verts, i, shadow, SHADOW_WITH_4_VERTS);
    }
    add_shadow_to_display_list(
        displayList, verts, SHADOW_WITH_4_VERTS, SHADOW_SHAPE_CIRCLE);
    return displayList;
}

Gfx *draw_shadow_circle_assuming_flat_ground(
    f32 xPos, f32 yPos, f32 zPos, s16 shadowScale, u8 solidity
) {
    Vtx *verts;
    Gfx *displayList;
    f32 *sp34;
    f32 distBelowFloor;
    f32 floorHeight = func_803814B8(xPos, yPos, zPos, &sp34);
    f32 radius = shadowScale / 2;

    if (floorHeight < -10000.0) {
        return NULL;
    } else {
        distBelowFloor = floorHeight - yPos;
    }

    verts = alloc_display_list(4 * sizeof(Vtx));
    displayList = alloc_display_list(5 * sizeof(Gfx));

    if (verts == NULL || displayList == NULL) {
        return 0;
    }

    make_shadow_vertex_at_xyz(verts, 0, -radius, distBelowFloor, -radius, solidity, 1);
    make_shadow_vertex_at_xyz(verts, 1,  radius, distBelowFloor, -radius, solidity, 1);
    make_shadow_vertex_at_xyz(verts, 2, -radius, distBelowFloor,  radius, solidity, 1);
    make_shadow_vertex_at_xyz(verts, 3,  radius, distBelowFloor,  radius, solidity, 1);

    add_shadow_to_display_list(
        displayList, verts, SHADOW_WITH_4_VERTS, SHADOW_SHAPE_CIRCLE);
    return displayList;
}

Gfx *draw_shadow_rectangle(f32 halfWidth, f32 halfLength, f32 relY, u8 solidity) {
    Vtx *verts = alloc_display_list(64);
    Gfx *displayList = alloc_display_list(40);
    f32 frontLeftX, frontLeftZ, frontRightX, frontRightZ,
         backLeftX,  backLeftZ,  backRightX,  backRightZ;

    if (verts == NULL || displayList == NULL) {
        return NULL;
    }

    // TODO: Check that these variables are named properly.
    rotate_rectangle( &frontLeftZ,  &frontLeftX, -halfLength, -halfWidth);
    rotate_rectangle(&frontRightZ, &frontRightX, -halfLength,  halfWidth);
    rotate_rectangle(  &backLeftZ,   &backLeftX,  halfLength, -halfWidth);
    rotate_rectangle( &backRightZ,  &backRightX,  halfLength,  halfWidth);

    make_shadow_vertex_at_xyz(verts, 0,  frontLeftX, relY,  frontLeftZ, solidity, 1);
    make_shadow_vertex_at_xyz(verts, 1, frontRightX, relY, frontRightZ, solidity, 1);
    make_shadow_vertex_at_xyz(verts, 2,   backLeftX, relY,   backLeftZ, solidity, 1);
    make_shadow_vertex_at_xyz(verts, 3,  backRightX, relY,  backRightZ, solidity, 1);

    add_shadow_to_display_list(
        displayList, verts, SHADOW_WITH_4_VERTS, SHADOW_SHAPE_SQUARE);
    return displayList;
}

s32 get_shadow_height_solidity(
    f32 xPos, f32 yPos, f32 zPos, f32 *shadowHeight, u8 *solidity
) {
    f32 *dummy;
    f32 waterLevel;
    *shadowHeight = func_803814B8(xPos, yPos, zPos, &dummy);

    if (*shadowHeight < -10000.0) {
        return 1;
    } else {
        waterLevel = find_water_level(xPos, zPos);

        if (waterLevel < -10000.0) {
            //! Dead if-statement. There may have been an assert here.
        } else if (yPos >= waterLevel && waterLevel >= *shadowHeight) {
            gShadowAboveWaterOrLava = TRUE;
            *shadowHeight = waterLevel;
            *solidity = 200;
        }
    }
    return 0;
}

Gfx *draw_shadow_square(
    f32 xPos, f32 yPos, f32 zPos, s16 shadowScale, u8 solidity, s8 shadowType
) {
    f32 shadowHeight;
    f32 distFromShadow;
    f32 shadowRadius;

    if (get_shadow_height_solidity(xPos, yPos, zPos, &shadowHeight, &solidity) != 0) {
        return NULL;
    }

    distFromShadow = yPos - shadowHeight;
    switch (shadowType) {
        case SHADOW_SQUARE_PERMANENT:
            shadowRadius = shadowScale / 2;
            break;
        case SHADOW_SQUARE_SCALABLE:
            shadowRadius = scale_shadow_with_distance(
                shadowScale, distFromShadow) / 2.0;
            break;
        case SHADOW_SQUARE_TOGGLABLE:
            shadowRadius = disable_shadow_with_distance(
                shadowScale, distFromShadow) / 2.0;
            break;
        default:
            return NULL;
    }

    return draw_shadow_rectangle(
        shadowRadius, shadowRadius, -distFromShadow, solidity);
}

Gfx *draw_shadow_hardcoded_rectangle(
    f32 xPos, f32 yPos, f32 zPos,
    UNUSED s32 shadowScale, u8 solidity, s8 shadowType
) {
    f32 shadowHeight;
    f32 distFromShadow;
    f32 halfWidth;
    f32 halfLength;
    s8 idx = shadowType - SHADOW_RECTANGLE_HARDCODED_OFFSET;

    if (get_shadow_height_solidity(xPos, yPos, zPos, &shadowHeight, &solidity) != 0) {
        return NULL;
    }

    distFromShadow = yPos - shadowHeight;
    //! idx could be negative or otherwise out of the bounds of "rectangles".
    // In practice, it never is, because the programmers only used this twice.
    if (rectangles[idx].scaleWithDistance == TRUE) {
        halfWidth  = scale_shadow_with_distance(
            rectangles[idx].halfWidth, distFromShadow);
        halfLength = scale_shadow_with_distance(
            rectangles[idx].halfLength, distFromShadow);
    } else {
        // This code is never used because the third element of the rectangle
        // struct is always 1.
        halfWidth  = rectangles[idx].halfWidth;
        halfLength = rectangles[idx].halfLength;
    }
    return draw_shadow_rectangle(
        halfWidth, halfLength, -distFromShadow, solidity);
}

Gfx *create_shadow_below_xyz(
    f32 xPos, f32 yPos, f32 zPos, s16 shadowScale, u8 shadowSolidity, s8 shadowType
) {
    Gfx *displayList = NULL;
    struct Surface *pfloor;
    find_floor(xPos, yPos, zPos, &pfloor);

    gShadowAboveWaterOrLava = FALSE;
    D_8035FF45 = 0;
    D_8035FF40 = 0;
    if (pfloor != NULL) {
        if (pfloor->type == SURFACE_002E) {
            D_8035FF45 = 1;
        }
        gSurfaceTypeBelowShadow = pfloor->type;
    }
    switch (shadowType) {
        case SHADOW_CIRCLE_UNK0:
            displayList = draw_shadow_circle_9_verts(
                xPos, yPos, zPos, shadowScale, shadowSolidity);
            break;
        case SHADOW_CIRCLE_UNK1:
            displayList = draw_shadow_circle_4_verts(
                xPos, yPos, zPos, shadowScale, shadowSolidity);
            break;
        case SHADOW_CIRCLE_UNK2:  // unused shadow type
            displayList = draw_shadow_circle_assuming_flat_ground(
                xPos, yPos, zPos, shadowScale, shadowSolidity);
            break;
        case SHADOW_SQUARE_PERMANENT:
            displayList = draw_shadow_square(
                xPos, yPos, zPos, shadowScale, shadowSolidity, shadowType);
            break;
        case SHADOW_SQUARE_SCALABLE:
            displayList = draw_shadow_square(
                xPos, yPos, zPos, shadowScale, shadowSolidity, shadowType);
            break;
        case SHADOW_SQUARE_TOGGLABLE:
            displayList = draw_shadow_square(
                xPos, yPos, zPos, shadowScale, shadowSolidity, shadowType);
            break;
        case SHADOW_CIRCLE_UNK_0x63:  // maybe Mario?
            displayList = func_802CDCBC(
                xPos, yPos, zPos, shadowScale, shadowSolidity, /* isLuigi */ 0);
            break;
        default:
            displayList = draw_shadow_hardcoded_rectangle(
                xPos, yPos, zPos, shadowScale, shadowSolidity, shadowType);
            break;
    }
    return displayList;
}

