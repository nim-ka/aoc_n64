#ifndef _SHADOW_H
#define _SHADOW_H

#include "types.h"

/**
 * Shadow types. Shadows are circles, squares, or hardcoded rectangles, and
 * can be composed of either 4 or 9 vertices.
 */
#define SHADOW_CIRCLE_UNK0      0x00
#define SHADOW_CIRCLE_UNK1      0x01
#define SHADOW_CIRCLE_UNK2      0x02  // unused shadow type
#define SHADOW_SQUARE_PERMANENT 0x0A  // square shadow that never disappears
#define SHADOW_SQUARE_SCALABLE  0x0B  // square shadow, shrinks with distance
#define SHADOW_SQUARE_TOGGLABLE 0x0C  // square shadow, disappears with distance
#define SHADOW_CIRCLE_UNK_0x63  0x63  // maybe Mario?
/**
 * Shadows with types greater than this and less than 0x63 are hardcoded in the
 * "shadowRectangle" struct (see shadow.c).
 */
#define SHADOW_RECTANGLE_HARDCODED_OFFSET 0x32

/**
 * Global variables:
 */

/* Unknown: */
extern s8 D_8035FF40;
/* Describes the type of surface onto which a shadow is being drawn. */
extern s16 gSurfaceTypeBelowShadow;
extern s8 gShadowAboveWaterOrLava;
extern s8 D_8035FF45;

/* Remnant of a potential second player. */
extern struct Object *gLuigiObject;


/**
 * Given the (x, y, z) location of an object, create a shadow below that object
 * with the given initial solidity and "shadowType" (described above).
 */
extern Gfx *create_shadow_below_xyz(
    f32 xPos, f32 yPos, f32 zPos, s16 shadowScale, u8 shadowSolidity, s8 shadowType);

#endif /* _SHADOW_H */
