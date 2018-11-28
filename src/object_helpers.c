#include <ultra64.h>

#include "sm64.h"
#include "behavior_data.h"
#include "behavior_script.h"
#include "camera.h"
#include "debug.h"
#include "helper_macros.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "math_util.h"
#include "memory.h"
#include "level_update.h"
#include "object_list_processor.h"
#include "rendering_graph_node.h"
#include "spawn_object.h"
#include "spawn_sound.h"
#include "surface_collision.h"
#include "area.h"
#include "geo_layout.h"
#include "ingame_menu.h"
#include "game.h"
#include "obj_behaviors.h"
#include "interaction.h"

#include "object_helpers.h"
#include "object_helpers2.h"

s8 D_8032F0A0[] = { 0xF8, 0x08, 0xFC, 0x04};
s16 D_8032F0A4[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
static s8 sLevelsWithRooms[] = { LEVEL_BBH, LEVEL_CASTLE, LEVEL_HMC, -1 };

extern s32 gDialogueResponse;
extern s32 sGrabReleaseState;

// These can be static:
extern void func_8029D704(Mat4, Mat4, Mat4);
extern void func_8029EA0C(struct Object *);
extern void translate_object_local(struct Object *, s16, s16);
extern void copy_object_pos(struct Object *, struct Object *);
extern void copy_object_angle(struct Object *, struct Object *);
extern struct Object *obj_find_nearest_object_with_behavior(void *, f32 *);
extern void obj_move_y(f32, f32, f32);
static s32 clear_move_flag(u32 *, s32);
extern void func_802AA618(s32, s32, f32);
extern void func_802AD82C(s32, s32, f32, s32);

#define o gCurrentObject

s32 Geo18_8029D890(s32 sp60, UNUSED s32 sp64, void *sp68)
{
    Mat4 sp20;
    struct Object *sp1C;

    if (sp60 == 1)
    {
        sp1C = (struct Object *)D_8032CFA0; // TODO: change global type to Object pointer
        if (sp1C->prevObj)
        {
            func_8029D704(sp20, sp68, D_8032CF9C->unk34);
            func_8029D558(sp20, sp1C->prevObj);
            func_8029EA0C(sp1C->prevObj);
        }
    }
    return 0;
}

struct struct8029D924
{
    /*0x00*/ s16 unk00;
    /*0x02*/ s16 unk02;
    /*0x04*/ s8 filler04[0x18-0x04];
    /*0x18*/ s32 unk18;
};

struct struct8029D924_2
{
    /*0x00*/ s32 unk00;
    /*0x04*/ s32 unk04;
};

struct struct8029D924_2 *Geo18_8029D924(s32 sp40, struct struct8029D924 *sp44, UNUSED s32 sp48)
{
    struct struct8029D924_2 *sp3C, *sp38;
    struct Object *sp34;
    struct struct8029D924 *sp30;
    UNUSED struct struct8029D924 *sp2C;
    s32 sp28;
#ifdef VERSION_JP
    UNUSED struct struct8029D924_2 *sp24; // sp24 is unused in non-JP versions.
#endif
    struct struct8029D924_2 *sp20, *sp1C, *sp18;

    sp3C = NULL;

    if (sp40 == 1)
    {
        sp34 = (struct Object *) D_8032CFA0; // TODO: change this to object pointer?
        sp30 = sp44;
        sp2C = sp44;

        if (D_8032CFA4)
        {
            sp34 = (struct Object *) D_8032CFA4->unk1C; // TODO: change this to object pointer?
        }

        sp28 = sp34->oOpacity;
        sp3C = alloc_display_list(24); // likely sizeof(struct struct8029D924_2) * 3

        sp38 = sp3C;

        if (sp28 == 0xFF)
        {
            if (sp30->unk18 == 20)
            {
                sp30->unk02 = 0x600 | (sp30->unk02 & 0xFF);
            }
            else
            {
                sp30->unk02 = 0x100 | (sp30->unk02 & 0xFF);
            }

            sp34->oAnimState = 0;
        }
        else
        {
            if (sp30->unk18 == 20)
            {
                sp30->unk02 = 0x600 | (sp30->unk02 & 0xFF);
            }
            else
            {
                sp30->unk02 = 0x500 | (sp30->unk02 & 0xFF);
            }

            sp34->oAnimState = 1;

#ifdef VERSION_JP
            if (sp30->unk18 == 10)
            {
                if (gDebugInfo[DEBUG_PAGE_ENEMYINFO][3])
                {
                    sp24 = sp38++;
                    sp24->unk00 = 0xB9000002;
                    sp24->unk04 = 3;
                }
            }
            else
            {
                if (sp34->activeFlags & ACTIVE_FLAG_UNK7)
                {
                    sp20 = sp38++;
                    sp20->unk00 = 0xB9000002;
                    sp20->unk04 = 3;
                }
            }
#else // gDebugInfo accesses were removed in all non-JP versions.
            if (sp28 == 0 && segmented_to_virtual(beh_bowser) == sp34->behavior)
            {
                sp34->oAnimState = 2;
            }
            // the debug info check was removed in US. so we need to
            // perform the only necessary check instead of the debuginfo
            // one.
            if (sp30->unk18 != 10)
            {
                if (sp34->activeFlags & ACTIVE_FLAG_UNK7)
                {
                    sp20 = sp38++;
                    sp20->unk00 = 0xB9000002;
                    sp20->unk04 = 3;
                }
            }
#endif
        }

        sp1C = sp38++;
        sp1C->unk00 = 0xfb000000;
        sp1C->unk04 = (sp28 & 0xFF) | ~0xFF;

        sp18 = sp38;
        sp18->unk00 = 0xb8000000;
        sp18->unk04 = 0;
    }

    return sp3C;
}

s32 GeoSwitchCase8029DB48(s32 a0, struct Object *a1)
{
    struct Object *sp4;
    struct Object *sp0;

    if (a0 == 1)
    {
        sp4 = (struct Object *)D_8032CFA0; // TODO: change global type to Object pointer
        sp0 = a1;

        if (D_8032CFA4 != 0)
        {
            sp4 = (struct Object *)D_8032CFA4->unk1C;
        }

        if (sp4->oAnimState >= sp0->header.gfx.angle[1])
        {
            sp4->oAnimState = 0;
        }

        sp0->header.gfx.angle[2] = sp4->oAnimState;
    }

    return 0;
}

s32 GeoSwitchCaseBlinking(s32 sp28, struct GraphNodeObject *sp2C)
{
    s16 sp26;
    struct Surface *sp20;
    UNUSED struct Object *sp1C;
    struct GraphNodeObject *sp18;

    sp1C = (struct Object *)D_8032CFA0; // TODO: change global type to Object pointer

    sp18 = sp2C;

    if (sp28 == 1)
    {
        if (gMarioObject == NULL)
        {
            sp18->angle[2] = 0;
        }
        else
        {
            gFindFloorIncludeSurface0012 = 1;

            find_floor(gMarioObject->oPosX, gMarioObject->oPosY, gMarioObject->oPosZ, &sp20);

            if (sp20)
            {
                gMarioCurrentRoom = sp20->room;
                sp26 = sp20->room - 1;
                print_debug_top_down_objectinfo("areainfo %d", sp20->room);

                if (sp26 >= 0)
                {
                    sp18->angle[2] = sp26;
                }
            }
        }
    }
    else
    {
        sp18->angle[2] = 0;
    }

    return 0;
}

void func_8029D558(Mat4 a0, struct Object *a1)
{
    f32 spC, sp8, sp4;

    spC = a1->oParentRelativePosX;
    sp8 = a1->oParentRelativePosY;
    sp4 = a1->oParentRelativePosZ;

    a1->oPosX = spC * a0[0][0] + sp8 * a0[1][0] + sp4 * a0[2][0] + a0[3][0];
    a1->oPosY = spC * a0[0][1] + sp8 * a0[1][1] + sp4 * a0[2][1] + a0[3][1];
    a1->oPosZ = spC * a0[0][2] + sp8 * a0[1][2] + sp4 * a0[2][2] + a0[3][2];
}

void apply_object_scale_to_matrix(struct Object *obj, Mat4 dst, Mat4 src)
{
    dst[0][0] = src[0][0] * obj->header.gfx.scale[0];
    dst[1][0] = src[1][0] * obj->header.gfx.scale[1];
    dst[2][0] = src[2][0] * obj->header.gfx.scale[2];
    dst[3][0] = src[3][0];

    dst[0][1] = src[0][1] * obj->header.gfx.scale[0];
    dst[1][1] = src[1][1] * obj->header.gfx.scale[1];
    dst[2][1] = src[2][1] * obj->header.gfx.scale[2];
    dst[3][1] = src[3][1];

    dst[0][2] = src[0][2] * obj->header.gfx.scale[0];
    dst[1][2] = src[1][2] * obj->header.gfx.scale[1];
    dst[2][2] = src[2][2] * obj->header.gfx.scale[2];
    dst[3][2] = src[3][2];

    dst[0][3] = src[0][3];
    dst[1][3] = src[1][3];
    dst[2][3] = src[2][3];
    dst[3][3] = src[3][3];
}

void func_8029D704(Mat4 a0, Mat4 a1, Mat4 a2)
{
    f32 spC, sp8, sp4;

    spC = a2[3][0] * a2[0][0] + a2[3][1] * a2[0][1] + a2[3][2] * a2[0][2];
    sp8 = a2[3][0] * a2[1][0] + a2[3][1] * a2[1][1] + a2[3][2] * a2[1][2];
    sp4 = a2[3][0] * a2[2][0] + a2[3][1] * a2[2][1] + a2[3][2] * a2[2][2];

    a0[0][0] = a1[0][0] * a2[0][0] + a1[0][1] * a2[0][1] + a1[0][2] * a2[0][2];
    a0[0][1] = a1[0][0] * a2[1][0] + a1[0][1] * a2[1][1] + a1[0][2] * a2[1][2];
    a0[0][2] = a1[0][0] * a2[2][0] + a1[0][1] * a2[2][1] + a1[0][2] * a2[2][2];

    a0[1][0] = a1[1][0] * a2[0][0] + a1[1][1] * a2[0][1] + a1[1][2] * a2[0][2];
    a0[1][1] = a1[1][0] * a2[1][0] + a1[1][1] * a2[1][1] + a1[1][2] * a2[1][2];
    a0[1][2] = a1[1][0] * a2[2][0] + a1[1][1] * a2[2][1] + a1[1][2] * a2[2][2];

    a0[2][0] = a1[2][0] * a2[0][0] + a1[2][1] * a2[0][1] + a1[2][2] * a2[0][2];
    a0[2][1] = a1[2][0] * a2[1][0] + a1[2][1] * a2[1][1] + a1[2][2] * a2[1][2];
    a0[2][2] = a1[2][0] * a2[2][0] + a1[2][1] * a2[2][1] + a1[2][2] * a2[2][2];

    a0[3][0] = a1[3][0] * a2[0][0] + a1[3][1] * a2[0][1] + a1[3][2] * a2[0][2] - spC;
    a0[3][1] = a1[3][0] * a2[1][0] + a1[3][1] * a2[1][1] + a1[3][2] * a2[1][2] - sp8;
    a0[3][2] = a1[3][0] * a2[2][0] + a1[3][1] * a2[2][1] + a1[3][2] * a2[2][2] - sp4;

    a0[0][3] = 0;
    a0[1][3] = 0;
    a0[2][3] = 0;
    a0[3][3] = 1.0f;
}

void set_object_held_state(struct Object *obj, void *heldBehavior)
{
    obj->parentObj = o;

    if (obj->oFlags & OBJ_FLAG_HOLDABLE)
    {
        if (heldBehavior == beh_carry_something3)
        {
            obj->oHeldState = HELD_HELD;
        }

        if (heldBehavior == beh_carry_something5)
        {
            obj->oHeldState = HELD_THROWN;
        }

        if (heldBehavior == beh_carry_something4)
        {
            obj->oHeldState = HELD_DROPPED;
        }
    }
    else
    {
        obj->behScript = segmented_to_virtual(heldBehavior);
        obj->stackIndex = 0;
    }
}

f32 lateral_dist_between_objects(struct Object *obj1, struct Object *obj2)
{
    f32 dx = obj1->oPosX - obj2->oPosX;
    f32 dz = obj1->oPosZ - obj2->oPosZ;

    return sqrtf(dx*dx + dz*dz);
}

f32 dist_between_objects(struct Object *obj1, struct Object *obj2) {
    f32 dx = obj1->oPosX - obj2->oPosX;
    f32 dy = obj1->oPosY - obj2->oPosY;
    f32 dz = obj1->oPosZ - obj2->oPosZ;

    return sqrtf(dx*dx + dy*dy + dz*dz);
}

void obj_obj_forward_vel_approach_upward(f32 target, f32 increment)
{
    if (o->oForwardVel >= target)
    {
        o->oForwardVel = target;
    }
    else
    {
        o->oForwardVel += increment;
    }
}

s32 approach_f32_signed(f32 *value, f32 target, f32 increment)
{
    s32 reachedTarget = FALSE;

    *value += increment;

    if (increment >= 0.0f)
    {
        if (*value > target)
        {
            *value = target;
            reachedTarget = TRUE;
        }
    }
    else
    {
        if (*value < target)
        {
            *value = target;
            reachedTarget = TRUE;
        }
    }

    return reachedTarget;
}

f32 approach_f32_symmetric(f32 value, f32 target, f32 increment)
{
    f32 dist;

    if ((dist = target - value) >= 0.0f)
    {
        if (dist > increment)
        {
            value += increment;
        }
        else
        {
            value = target;
        }
    }
    else
    {
        if (dist < -increment)
        {
            value -= increment;
        }
        else
        {
            value = target;
        }
    }

    return value;
}

s16 approach_s16_symmetric(s16 value, s16 target, s16 increment)
{
    s16 dist = target - value;

    if (dist >= 0)
    {
        if (dist > increment)
        {
            value += increment;
        }
        else
        {
            value = target;
        }
    }
    else
    {
        if (dist < -increment)
        {
            value -= increment;
        }
        else
        {
            value = target;
        }
    }

    return value;
}

s32 obj_rotate_yaw_toward(s16 target, s16 increment)
{
    s16 startYaw;

    startYaw = (s16)o->oMoveAngleYaw;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, target, increment);

    if ((o->oAngleVelYaw = (s16)((s16)o->oMoveAngleYaw - startYaw)) == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

s16 angle_to_object(struct Object *obj1, struct Object *obj2)
{
    f32 z1, x1, z2, x2;
    s16 angle;

    z1 = obj1->oPosZ;
    z2 = obj2->oPosZ;
    x1 = obj1->oPosX;
    x2 = obj2->oPosX;

    angle = atan2s(z2 - z1, x2 - x1);
    return angle;
}

s16 obj_turn_toward_object(struct Object *obj, struct Object *target, s16 angleIndex, s16 turnAmount)
{
    f32 a, b, c, d;
    UNUSED s32 unused;
    s16 targetAngle, startAngle;

    switch (angleIndex)
    {
    case O_MOVE_ANGLE_PITCH_INDEX:
    case O_FACE_ANGLE_PITCH_INDEX:
        a = target->oPosX - obj->oPosX;
        c = target->oPosZ - obj->oPosZ;
        a = sqrtf(a*a + c*c);

        b = -obj->oPosY;
        d = -target->oPosY;

        targetAngle = atan2s(a, d - b);
        break;

    case O_MOVE_ANGLE_YAW_INDEX:
    case O_FACE_ANGLE_YAW_INDEX:
        a = obj->oPosZ;
        c = target->oPosZ;
        b = obj->oPosX;
        d = target->oPosX;

        targetAngle = atan2s(c - a, d - b);
        break;
    }

    startAngle = o->rawData.asU32[angleIndex];
    o->rawData.asU32[angleIndex] = approach_s16_symmetric(startAngle, targetAngle, turnAmount);
    return targetAngle;
}

void set_object_parent_relative_pos(struct Object *obj, s16 relX, s16 relY, s16 relZ)
{
    obj->oParentRelativePosX = relX;
    obj->oParentRelativePosY = relY;
    obj->oParentRelativePosZ = relZ;
}

void set_object_pos(struct Object *obj, s16 x, s16 y, s16 z)
{
    obj->oPosX = x;
    obj->oPosY = y;
    obj->oPosZ = z;
}

void set_object_angle(struct Object *a0, s16 pitch, s16 yaw, s16 roll)
{
    a0->oFaceAnglePitch = pitch;
    a0->oFaceAngleYaw = yaw;
    a0->oFaceAngleRoll = roll;

    a0->oMoveAnglePitch = pitch;
    a0->oMoveAngleYaw = yaw;
    a0->oMoveAngleRoll = roll;
}

struct Object *func_8029E230(struct Object *sp20, s16 sp26, u32 sp28, void *sp2C, s16 sp32, s16 sp36, s16 sp3A, s16 sp3E, s16 sp42, s16 sp46)
{
    struct Object *sp1C = spawn_object_at_origin(sp20, sp26, sp28, sp2C);
    set_object_pos(sp1C, sp32, sp36, sp3A);
    set_object_angle(sp1C, sp3E, sp42, sp46);

    return sp1C;
}

struct Object *func_8029E2A8(struct Object *sp20, u32 sp24, void *sp28, s16 sp2E, s16 sp32, s16 sp36, s16 sp3A, s16 sp3E, UNUSED s16 sp42)
{
    struct Object *sp1C = spawn_object_at_origin(sp20, 0, sp24, sp28);
    sp1C->oFlags |= OBJ_FLAG_TRANSFORM_RELATIVE_TO_PARENT;
    set_object_parent_relative_pos(sp1C, sp2E, sp32, sp36);
    set_object_angle(sp1C, sp3A, sp3E, sp36);

    return sp1C;
}

struct Object *Unknown8029E330(struct Object *sp20, s32 sp24, void *sp28)
{
    struct Object *sp1C = spawn_object(sp20, sp24, sp28);
    sp1C->oFlags |= OBJ_FLAG_0020 | OBJ_FLAG_0800;
    return sp1C;
}

struct Object *func_8029E388(struct Object *sp20, struct struct8029E388 *sp24)
{
    f32 sp1C;
    struct Object *sp18 = spawn_object(sp20, sp24->unk02, sp24->unk04);

    if (sp24->unk00 & 0x02)
    {
        sp18->oMoveAngleYaw = RandomU16();
    }

    if (sp24->unk00 & 0x40)
    {
        sp18->oMoveAngleYaw = (s16)(sp18->oMoveAngleYaw + 0x8000) + (s16)random_f32_around_zero(sp24->unk08);
    }

    if (sp24->unk00 & 0x80)
    {
        sp18->oMoveAngleYaw = (s16)sp18->oMoveAngleYaw + (s16)random_f32_around_zero(sp24->unk08);
    }

    if (sp24->unk00 & 0x20)
    {
        sp18->oPosY = find_water_level(sp18->oPosX, sp18->oPosZ);
    }

    if (sp24->unk00 & 0x04)
    {
        translate_object_xz_random(sp18, sp24->unk0A);
    }

    if (sp24->unk00 & 0x08)
    {
        translate_object_xyz_random(sp18, sp24->unk0A);
    }

    sp18->oForwardVel = RandomFloat() * sp24->unk10 + sp24->unk0C;
    sp18->oVelY = RandomFloat() * sp24->unk18 + sp24->unk14;
    sp1C = RandomFloat() * sp24->unk20 + sp24->unk1C;
    scale_object(sp18, sp1C);

    return sp18;
}

struct Object *spawn_object_at_origin(
    struct Object *parent,
    UNUSED u32 unusedArg,
    u32 model,
    void *behavior)
{
    struct Object *obj;
    u32 *behaviorAddr;

    behaviorAddr = (u32 *)segmented_to_virtual(behavior);
    obj = create_object(behaviorAddr);

    obj->parentObj = parent;
    obj->header.gfx.unk18 = parent->header.gfx.unk18;
    obj->header.gfx.unk19 = parent->header.gfx.unk18;

    func_8037C448(
        (struct GraphNodeObject *)&obj->header.gfx,
        gLoadedGraphNodes[model],
        D_80385FD0,
        D_80385FDC);

    return obj;
}

struct Object *spawn_object(
    struct Object *parent,
    s32 model,
    void *behavior)
{
    struct Object *obj;

    obj = spawn_object_at_origin(parent, 0, model, behavior);
    copy_object_pos_and_angle(obj, parent);

    return obj;
}

struct Object *try_to_spawn_object(
    s16 offsetY,
    f32 scale,
    void *parent,
    s32 model,
    void *behavior)
{
    struct Object *obj;

    if (gFreeObjectList.next != NULL)
    {
        obj = spawn_object(parent, model, behavior);
        obj->oPosY += offsetY;
        scale_object(obj, scale);
        return obj;
    }
    else
    {
        return NULL;
    }
}

struct Object *spawn_object_with_scale(
    struct Object *parent,
    s32 model,
    void *behavior,
    f32 scale)
{
    struct Object *obj;

    obj = spawn_object_at_origin(parent, 0, model, behavior);
    copy_object_pos_and_angle(obj, parent);
    scale_object(obj, scale);

    return obj;
}

static void build_relative_object_transform(struct Object *obj)
{
    build_object_transform_from_pos_and_angle(obj, O_PARENT_RELATIVE_POS_INDEX, O_FACE_ANGLE_INDEX);
    translate_object_local(obj, O_POS_INDEX, O_PARENT_RELATIVE_POS_INDEX);
}

struct Object* spawn_object_relative(
    s16 behaviorParam,
    s16 relativePosX, s16 relativePosY, s16 relativePosZ,
    struct Object *parent,
    s32 model,
    void *behavior)
{
    struct Object *obj = spawn_object_at_origin(parent, 0, model, behavior);

    copy_object_pos_and_angle(obj, parent);
    set_object_parent_relative_pos(obj, relativePosX, relativePosY, relativePosZ);
    build_relative_object_transform(obj);

    obj->oBehParams2ndByte = behaviorParam;
    obj->oBehParams = (behaviorParam & 0xFF) << 16;

    return obj;
}

struct Object *spawn_object_relative_with_scale(
    s16 behaviorParam,
    s16 relativePosX, s16 relativePosY, s16 relativePosZ,
    f32 scale,
    struct Object *parent,
    s32 model,
    void *behavior)
{
    struct Object *obj;

    obj = spawn_object_relative(
        behaviorParam,
        relativePosX, relativePosY, relativePosZ,
        parent,
        model,
        behavior);
    scale_object(obj, scale);

    return obj;
}

void obj_move_using_vel(void)
{
    o->oPosX += o->oVelX;
    o->oPosY += o->oVelY;
    o->oPosZ += o->oVelZ;
}

void func_8029E94C(struct Object *a0, struct Object *a1)
{
    a0->oGraphYOffset = a1->oGraphYOffset;
}

void copy_object_pos_and_angle(struct Object *dst, struct Object *src)
{
    copy_object_pos(dst, src);
    copy_object_angle(dst, src);
}

void copy_object_pos(struct Object *dst, struct Object *src)
{
    dst->oPosX = src->oPosX;
    dst->oPosY = src->oPosY;
    dst->oPosZ = src->oPosZ;
}

void copy_object_angle(struct Object *dst, struct Object *src)
{
    dst->oMoveAnglePitch = src->oMoveAnglePitch;
    dst->oMoveAngleYaw = src->oMoveAngleYaw;
    dst->oMoveAngleRoll = src->oMoveAngleRoll;

    dst->oFaceAnglePitch = src->oFaceAnglePitch;
    dst->oFaceAngleYaw = src->oFaceAngleYaw;
    dst->oFaceAngleRoll = src->oFaceAngleRoll;
}

void func_8029EA0C(struct Object *a0)
{
    a0->header.gfx.pos[0] = a0->oPosX;
    a0->header.gfx.pos[1] = a0->oPosY;
    a0->header.gfx.pos[2] = a0->oPosZ;
}

void Unknown8029EA34(struct Object *sp20, u32 sp24)
{
    u32 *sp1C;

    sp1C = o->oAnimations;
    func_8037C658(&sp20->header.gfx, sp24 + sp1C);
}

/**
 * Multiply a vector by a matrix of the form
 * | ? ? ? 0 |
 * | ? ? ? 0 |
 * | ? ? ? 0 |
 * | 0 0 0 1 |
 * i.e. a matrix representing a linear transformation over 3 space.
 */
void linear_mtxf_mul_vec3f(Mat4 m, Vec3f dst, Vec3f v)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        dst[i] = m[0][i] * v[0] + m[1][i] * v[1] + m[2][i] * v[2];
    }
}

/**
 * Multiply a vector by the transpose of a matrix of the form
 * | ? ? ? 0 |
 * | ? ? ? 0 |
 * | ? ? ? 0 |
 * | 0 0 0 1 |
 * i.e. a matrix representing a linear transformation over 3 space.
 */
void linear_mtxf_transpose_mul_vec3f(Mat4 m, Vec3f dst, Vec3f v)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        dst[i] = m[i][0] * v[0] + m[i][1] * v[1] + m[i][2] * v[2];
    }
}

void apply_scale_to_object_transform(struct Object *obj)
{
    float scaleX, scaleY, scaleZ;

    scaleX = obj->header.gfx.scale[0];
    scaleY = obj->header.gfx.scale[1];
    scaleZ = obj->header.gfx.scale[2];

    obj->transform[0][0] *= scaleX;
    obj->transform[0][1] *= scaleX;
    obj->transform[0][2] *= scaleX;

    obj->transform[1][0] *= scaleY;
    obj->transform[1][1] *= scaleY;
    obj->transform[1][2] *= scaleY;

    obj->transform[2][0] *= scaleZ;
    obj->transform[2][1] *= scaleZ;
    obj->transform[2][2] *= scaleZ;
}

void copy_object_scale(struct Object *dst, struct Object *src)
{
    dst->header.gfx.scale[0] = src->header.gfx.scale[0];
    dst->header.gfx.scale[1] = src->header.gfx.scale[1];
    dst->header.gfx.scale[2] = src->header.gfx.scale[2];
}

void scale_object_xyz(struct Object* obj, f32 xScale, f32 yScale, f32 zScale)
{
    obj->header.gfx.scale[0] = xScale;
    obj->header.gfx.scale[1] = yScale;
    obj->header.gfx.scale[2] = zScale;
}

void scale_object(struct Object* obj, f32 scale)
{
    obj->header.gfx.scale[0] = scale;
    obj->header.gfx.scale[1] = scale;
    obj->header.gfx.scale[2] = scale;
}

void obj_scale(f32 scale)
{
    o->header.gfx.scale[0] = scale;
    o->header.gfx.scale[1] = scale;
    o->header.gfx.scale[2] = scale;
}

void SetObjAnimation(s32 arg0)
{
    u32 *sp1C = o->oAnimations;
    func_8037C658(&o->header.gfx, sp1C + arg0);
}

void func_8029ED38(s32 arg0)
{
    u32 *sp1C = o->oAnimations;
    func_8037C658(&o->header.gfx, sp1C + arg0);
    o->oSoundStateID = arg0;
}

void func_8029ED98(u32 a0, f32 a1)
{
    u32 *sp1C = o->oAnimations;
    s32 sp18 = (s32) (a1 * 65536.0f);
    func_8037C708(&o->header.gfx, sp1C + a0, sp18);
    o->oSoundStateID = a0;
}

void func_8029EE20(struct Object *a0, u32 *a1, u32 a2)
{
    u32 *sp1C = a1;
    a0->oAnimations = a1;
    func_8037C658(&a0->header.gfx, sp1C + a2);
    a0->oSoundStateID = a2;
}

void obj_enable_rendering_and_become_tangible(struct Object *a0)
{
    a0->header.gfx.node.flags |= GRAPH_RENDER_01;
    a0->oIntangibleTimer = 0;
}

void obj_enable_rendering(void)
{
    o->header.gfx.node.flags |= GRAPH_RENDER_01;
}

void obj_disable_rendering_and_become_intangible(struct Object *a0)
{
    a0->header.gfx.node.flags &= ~GRAPH_RENDER_01;
    a0->oIntangibleTimer = -1;
}

void obj_disable_rendering(void)
{
    o->header.gfx.node.flags &= ~GRAPH_RENDER_01;
}

void obj_unhide(void)
{
    o->header.gfx.node.flags &= ~GRAPH_RENDER_10;
}

void obj_hide(void)
{
    o->header.gfx.node.flags |= GRAPH_RENDER_10;
}

void obj_set_pos_relative(struct Object *other, f32 dleft, f32 dy, f32 dforward)
{
    f32 facingZ = coss(other->oMoveAngleYaw);
    f32 facingX = sins(other->oMoveAngleYaw);

    f32 dz = dforward * facingZ - dleft * facingX;
    f32 dx = dforward * facingX + dleft * facingZ;

    o->oMoveAngleYaw = other->oMoveAngleYaw;

    o->oPosX = other->oPosX + dx;
    o->oPosY = other->oPosY + dy;
    o->oPosZ = other->oPosZ + dz;
}

void obj_set_pos_relative_to_parent(f32 dleft, f32 dy, f32 dforward)
{
    obj_set_pos_relative(o->parentObj, dleft, dy, dforward);
}

void obj_enable_rendering_2(void)
{
    obj_enable_rendering();
}

void obj_unused_init_on_floor(void)
{
    obj_enable_rendering();

    o->oPosY = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
    if (o->oPosY < -10000.0f)
    {
        obj_set_pos_relative_to_parent(0, 0, -70);
        o->oPosY = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
    }
}

void func_8029F170(struct Object *a0)
{
    a0->oFaceAnglePitch = a0->oMoveAnglePitch;
    a0->oFaceAngleYaw = a0->oMoveAngleYaw;
    a0->oFaceAngleRoll = a0->oMoveAngleRoll;
}

u32 get_object_list_from_behavior(u32 *behavior)
{
    u32 objectList;

    // If the first behavior command is "begin", then get the object list header
    // from there
    if ((behavior[0] >> 24) == 0)
    {
        objectList = (behavior[0] >> 16) & 0xFFFF;
    }
    else
    {
        objectList = OBJ_LIST_DEFAULT;
    }

    return objectList;
}

struct Object *obj_nearest_object_with_behavior(void *behavior)
{
    struct Object *obj;
    f32 dist;

    obj = obj_find_nearest_object_with_behavior(behavior, &dist);

    return obj;
}

f32 obj_dist_to_nearest_object_with_behavior(void *behavior)
{
    struct Object *obj;
    f32 dist;

    obj = obj_find_nearest_object_with_behavior(behavior, &dist);
    if (obj == NULL)
    {
        dist = 15000.0f;
    }

    return dist;
}

struct Object *obj_find_nearest_object_with_behavior(void *behavior, f32 *dist)
{
    u32 *behaviorAddr = (u32 *)segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *)listHead->next;

    while (obj != (struct Object *)listHead)
    {
        if (obj->behavior == behaviorAddr)
        {
            if (obj->activeFlags != ACTIVE_FLAGS_INACTIVE && obj != o)
            {
                f32 objDist = dist_between_objects(o, obj);
                if (objDist < minDist)
                {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *)obj->header.next;
    }

    *dist = minDist;
    return closestObj;
}

struct Object *find_unimportant_object(void)
{
    struct ObjectNode *listHead = &gObjectLists[OBJ_LIST_UNIMPORTANT];
    struct ObjectNode *obj = listHead->next;

    if (listHead == obj)
    {
        obj = NULL;
    }

    return (struct Object *)obj;
}

s32 count_unimportant_objects(void)
{
    struct ObjectNode *listHead = &gObjectLists[OBJ_LIST_UNIMPORTANT];
    struct ObjectNode *obj = listHead->next;
    s32 count = 0;

    while (listHead != obj)
    {
        count++;
        obj = obj->next;
    }

    return count;
}

s32 count_objects_with_behavior(void *behavior)
{
    u32 *behaviorAddr = (u32 *)segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct ObjectNode *obj = listHead->next;
    s32 count = 0;

    while (listHead != obj)
    {
        if (((struct Object *)obj)->behavior == behaviorAddr)
        {
            count++;
        }

        obj = obj->next;
    }

    return count;
}

struct Object *obj_find_nearby_held_actor(void *behavior, f32 maxDist)
{
    u32 *behaviorAddr = (u32 *)segmented_to_virtual(behavior);
    struct ObjectNode *listHead;
    struct Object *obj;
    struct Object *foundObj;

    listHead = &gObjectLists[OBJ_LIST_GENACTOR];
    obj = (struct Object *)listHead->next;
    foundObj = NULL;

    while ((struct Object *)listHead != obj)
    {
        if (obj->behavior == behaviorAddr)
        {
            if (obj->activeFlags != ACTIVE_FLAGS_INACTIVE)
            {
                // This includes the dropped and thrown states. By combining
                // instant release, this allows us to activate mama penguin
                // remotely
                if (obj->oHeldState != HELD_FREE)
                {
                    if (dist_between_objects(o, obj) < maxDist)
                    {
                        foundObj = obj;
                        break;
                    }
                }
            }
        }

        obj = (struct Object *)obj->header.next;
    }

    return foundObj;
}

static void obj_reset_timer_and_subaction(void)
{
    o->oTimer = 0;
    o->oSubAction = 0;
}

void obj_change_action(s32 action)
{
    o->oAction = action;
    o->oPrevAction = action;
    obj_reset_timer_and_subaction();
}

void func_8029F684(f32 f12, f32 f14)
{
    f32 sp4 = gMarioStates[0].forwardVel;
    f32 sp0 = f12 * f14;

    if (sp4 < sp0)
    {
        o->oForwardVel = sp0;
    }
    else
    {
        o->oForwardVel = sp4 * f14;
    }
}

void func_8029F6F0(void)
{
    if (o->header.gfx.unk38.animFrame >= 0)
    {
        o->header.gfx.unk38.animFrame--;
    }
}

void func_8029F728(void)
{
    s32 sp4 = o->header.gfx.unk38.animFrame;
    s32 sp0 = o->header.gfx.unk38.curAnim->unk08 - 2;

    if (sp4 == sp0)
    {
        o->header.gfx.unk38.animFrame--;
    }
}

s32 func_8029F788(void)
{
    u32 spC = (s32)o->header.gfx.unk38.curAnim->flags;
    s32 sp8 = o->header.gfx.unk38.animFrame;
    s32 sp4 = o->header.gfx.unk38.curAnim->unk08 - 2;
    s32 sp0 = 0;

    if (spC & 0x01)
    {
        if (sp4 + 1 == sp8)
        {
            sp0 = 1;
        }
    }

    if (sp8 == sp4)
    {
        sp0 = 1;
    }

    return sp0;
}

s32 func_8029F828(void)
{
    s32 sp4 = o->header.gfx.unk38.animFrame;
    s32 sp0 = o->header.gfx.unk38.curAnim->unk08 - 1;

    if (sp4 == sp0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

s32 obj_check_anim_frame(s32 frame)
{
    s32 animFrame = o->header.gfx.unk38.animFrame;

    if (animFrame == frame)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

s32 func_8029F8D4(s32 a0, s32 a1)
{
    s32 sp4 = o->header.gfx.unk38.animFrame;

    if (sp4 >= a0 && sp4 < a0 + a1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

s32 Unknown8029F930(s16 *a0)
{
    s16 sp6 = o->header.gfx.unk38.animFrame;

    while (*a0 != -1)
    {
        if (*a0 == sp6)
        {
            return 1;
        }

        a0++;
    }

    return 0;
}

s32 mario_is_in_air_action(void)
{
    if (gMarioStates[0].action & ACT_FLAG_AIR)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

s32 mario_is_dive_sliding(void)
{
    if (gMarioStates[0].action == ACT_DIVE_SLIDE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void func_8029FA1C(f32 sp18, s32 sp1C)
{
    o->oVelY = sp18;
    func_8029ED38(sp1C);
}

void func_8029FA5C(s32 sp18, s32 sp1C)
{
    obj_become_intangible();
    obj_disable_rendering();

    if (sp18 >= 0)
    {
        func_8029ED38(sp18);
    }

    o->oAction = sp1C;
}

static void obj_move_after_thrown_or_dropped(f32 forwardVel, f32 velY)
{
    o->oMoveFlags = 0;
    o->oFloorHeight = find_floor_height(o->oPosX, o->oPosY + 160.0f, o->oPosZ);

    if (o->oFloorHeight > o->oPosY)
    {
        o->oPosY = o->oFloorHeight;
    }
    else if (o->oFloorHeight < -10000.0f)
    {
        //! OoB failsafe
        copy_object_pos(o, gMarioObject);
        o->oFloorHeight = find_floor_height(o->oPosX, o->oPosY, o->oPosZ);
    }

    o->oForwardVel = forwardVel;
    o->oVelY = velY;

    if (o->oForwardVel != 0)
    {
        obj_move_y(/*gravity*/ -4.0f, /*bounce*/ -0.1f, /*buoyancy*/ 2.0f);
    }
}

void obj_get_thrown_or_placed(f32 forwardVel, f32 velY, s32 thrownAction)
{
    if (o->behavior == segmented_to_virtual(beh_bowser))
    {
        // Interestingly, when bowser is thrown, he is offset slightly to
        // mario's right
        obj_set_pos_relative_to_parent(-41.684f, 85.859f, 321.577f);
    }
    else { }

    obj_become_tangible();
    obj_enable_rendering();

    o->oHeldState = HELD_FREE;

    if ((o->oUnk190 & 0x10) || forwardVel == 0.0f)
    {
        obj_move_after_thrown_or_dropped(0.0f, 0.0f);
    }
    else
    {
        o->oAction = thrownAction;
        obj_move_after_thrown_or_dropped(forwardVel, velY);
    }
}

void obj_get_dropped(void)
{
    obj_become_tangible();
    obj_enable_rendering();

    o->oHeldState = HELD_FREE;
    obj_move_after_thrown_or_dropped(0.0f, 0.0f);
}

void obj_set_model(s32 a0)
{
    o->header.gfx.asGraphNode = gLoadedGraphNodes[a0];
}

void mario_set_flag(s32 flag)
{
    gMarioStates[0].flags |= flag;
}

s32 obj_clear_interact_status_flag(s32 flag)
{
    if (o->oInteractStatus & flag)
    {
        o->oInteractStatus &= flag ^ 0xFFFFFFFF;
        return TRUE;
    }
    return FALSE;
}

void mark_object_for_deletion(struct Object *obj)
{
    //! This clears all activeFlags. Since some of these flags disable behavior,
    //  setting it to 0 could potentially enable unexpected behavior. After an
    //  object is marked for deletion, it still updates on that frame (I think),
    //  so this is worth looking into.
    obj->activeFlags = ACTIVE_FLAGS_INACTIVE;
}

void func_8029FE00(void)
{
    obj_disable_rendering();
    obj_hide();
    obj_become_intangible();
}

void obj_become_intangible(void)
{
    // When the timer is negative, the object is intangible and the timer
    // doesn't count down
    o->oIntangibleTimer = -1;
}

void obj_become_tangible(void)
{
    o->oIntangibleTimer = 0;
}

void make_object_tangible(struct Object *obj)
{
    obj->oIntangibleTimer = 0;
}

void obj_update_floor_height(void)
{
    struct Surface *floor;
    o->oFloorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);
}

struct Surface *obj_update_floor_height_and_get_floor(void)
{
    struct Surface *floor;
    o->oFloorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);
    return floor;
}

static void apply_drag_to_value(f32 *value, f32 dragStrength)
{
    f32 decel;

    if (*value != 0.0f)
    {
        //! Can overshoot if |*value| > 1/(dragStrength * 0.0001)
        decel = (*value) * (*value) * (dragStrength * 0.0001L);

        if (*value > 0)
        {
            *value -= decel;
            if (*value < 0.001L)
            {
                *value = 0.0f;
            }
        }
        else
        {
            *value += decel;
            if (*value > -0.001L)
            {
                *value = 0.0f;
            }
        }
    }
}

void obj_apply_drag_xz(f32 dragStrength)
{
    apply_drag_to_value(&o->oVelX, dragStrength);
    apply_drag_to_value(&o->oVelZ, dragStrength);
}

static s32 obj_move_xz(f32 steepSlopeNormalY, s32 careAboutEdgesAndSteepSlopes)
{
    struct Surface *intendedFloor;

    f32 intendedX = o->oPosX + o->oVelX;
    f32 intendedZ = o->oPosZ + o->oVelZ;

    f32 intendedFloorHeight = find_floor(intendedX, o->oPosY, intendedZ, &intendedFloor);
    f32 deltaFloorHeight = intendedFloorHeight - o->oFloorHeight;

    UNUSED f32 unused;
    UNUSED f32 ny;

    o->oMoveFlags &= ~OBJ_MOVE_HIT_EDGE;

    if (o->oRoom != -1 && intendedFloor != NULL)
    {
        if (intendedFloor->room != 0 &&
            o->oRoom != intendedFloor->room &&
            intendedFloor->room != 18)
        {
            // Don't leave native room
            return FALSE;
        }
    }

    if (intendedFloorHeight < -10000.0f)
    {
        // Don't move into OoB
        o->oMoveFlags |= OBJ_MOVE_HIT_EDGE;
        return FALSE;
    }
    else if (deltaFloorHeight < 5.0f)
    {
        if (!careAboutEdgesAndSteepSlopes)
        {
            // If we don't care about edges or steep slopes, okay to move
            o->oPosX = intendedX;
            o->oPosZ = intendedZ;
            return TRUE;
        }
        else if (deltaFloorHeight < -50.0f && (o->oMoveFlags & OBJ_MOVE_ON_GROUND))
        {
            // Don't walk off an edge
            o->oMoveFlags |= OBJ_MOVE_HIT_EDGE;
            return FALSE;
        }
        else if (intendedFloor->normal[1] > steepSlopeNormalY)
        {
            // Allow movement onto a slope, provided it's not too steep
            o->oPosX = intendedX;
            o->oPosZ = intendedZ;
            return TRUE;
        }
        else
        {
            // We are likely trying to move onto a steep downward slope
            o->oMoveFlags |= OBJ_MOVE_HIT_EDGE;
            return FALSE;
        }
    }
    else if ((ny = intendedFloor->normal[1]) > steepSlopeNormalY ||
        o->oPosY > intendedFloorHeight)
    {
        // Allow movement upward, provided either:
        // - The target floor is flat enough (e.g. walking up stairs)
        // - We are above the target floor (most likely in the air)
        o->oPosX = intendedX;
        o->oPosZ = intendedZ;
        //! Returning FALSE but moving anyway (not exploitable; return value is
        //  never used)
    }

    // We are likely trying to move onto a steep upward slope
    return FALSE;
}

static void obj_move_update_underwater_flags(void)
{
    f32 decelY = (f32) (sqrtf(o->oVelY * o->oVelY) * (o->oDragStrength * 7.0f)) / 100.0L;

    if (o->oVelY > 0)
    {
        o->oVelY -= decelY;
    }
    else
    {
        o->oVelY += decelY;
    }

    if (o->oPosY < o->oFloorHeight)
    {
        o->oPosY = o->oFloorHeight;
        o->oMoveFlags |= OBJ_MOVE_UNDERWATER_ON_GROUND;
    }
    else
    {
        o->oMoveFlags |= OBJ_MOVE_UNDERWATER_OFF_GROUND;
    }
}

static void obj_move_update_ground_air_flags(UNUSED f32 gravity, f32 bounce)
{
    o->oMoveFlags &= ~OBJ_MOVE_13;

    if (o->oPosY < o->oFloorHeight)
    {
        // On the first frame that we touch the ground, set OBJ_MOVE_LANDED.
        // On subsequent frames, set OBJ_MOVE_ON_GROUND
        if (!(o->oMoveFlags & OBJ_MOVE_ON_GROUND))
        {
            if (clear_move_flag(&o->oMoveFlags, OBJ_MOVE_LANDED))
            {
                o->oMoveFlags |= OBJ_MOVE_ON_GROUND;
            }
            else
            {
                o->oMoveFlags |= OBJ_MOVE_LANDED;
            }
        }

        o->oPosY = o->oFloorHeight;

        if (o->oVelY < 0.0f)
        {
            o->oVelY *= bounce;
        }

        if (o->oVelY > 5.0f)
        {
            //! If OBJ_MOVE_13 tracks bouncing, it overestimates, since velY
            // could be > 5 here without bounce (e.g. jump into misa)
            o->oMoveFlags |= OBJ_MOVE_13;
        }
    }
    else
    {
        o->oMoveFlags &= ~OBJ_MOVE_LANDED;
        if (clear_move_flag(&o->oMoveFlags, OBJ_MOVE_ON_GROUND))
        {
            o->oMoveFlags |= OBJ_MOVE_LEFT_GROUND;
        }
    }

    o->oMoveFlags &= ~OBJ_MOVE_MASK_IN_WATER;
}

static f32 obj_move_y_and_get_water_level(f32 gravity, f32 buoyancy)
{
    f32 waterLevel;

    o->oVelY += gravity + buoyancy;
    if (o->oVelY < -78.0f)
    {
        o->oVelY = -78.0f;
    }

    o->oPosY += o->oVelY;
    if (o->activeFlags & ACTIVE_FLAG_UNK10)
    {
        waterLevel = -11000.0f;
    }
    else
    {
        waterLevel = find_water_level(o->oPosX, o->oPosZ);
    }

    return waterLevel;
}

void obj_move_y(f32 gravity, f32 bounce, f32 buoyancy)
{
    f32 waterLevel;

    o->oMoveFlags &= ~OBJ_MOVE_LEFT_GROUND;

    if (o->oMoveFlags & OBJ_MOVE_AT_WATER_SURFACE)
    {
        if (o->oVelY > 5.0f)
        {
            o->oMoveFlags &= ~OBJ_MOVE_MASK_IN_WATER;
            o->oMoveFlags |= OBJ_MOVE_12;
        }
    }

    if (!(o->oMoveFlags & OBJ_MOVE_MASK_IN_WATER))
    {
        waterLevel = obj_move_y_and_get_water_level(gravity, 0.0f);
        if (o->oPosY > waterLevel)
        {
            //! We only handle floor collision if the object does not enter
            //  water. This allows e.g. coins to clip through floors if they
            //  enter water on the same frame.
            obj_move_update_ground_air_flags(gravity, bounce);
        }
        else
        {
            o->oMoveFlags |= OBJ_MOVE_ENTERED_WATER;
            o->oMoveFlags &= ~OBJ_MOVE_MASK_ON_GROUND;
        }
    }
    else
    {
        o->oMoveFlags &= ~OBJ_MOVE_ENTERED_WATER;

        waterLevel = obj_move_y_and_get_water_level(gravity, buoyancy);
        if (o->oPosY < waterLevel)
        {
            obj_move_update_underwater_flags();
        }
        else
        {
            if (o->oPosY < o->oFloorHeight)
            {
                o->oPosY = o->oFloorHeight;
                o->oMoveFlags &= ~OBJ_MOVE_MASK_IN_WATER;
            }
            else
            {
                o->oPosY = waterLevel;
                o->oVelY = 0.0f;
                o->oMoveFlags &= ~(OBJ_MOVE_UNDERWATER_OFF_GROUND | OBJ_MOVE_UNDERWATER_ON_GROUND);
                o->oMoveFlags |= OBJ_MOVE_AT_WATER_SURFACE;
            }
        }
    }

    if (o->oMoveFlags & OBJ_MOVE_MASK_33)
    {
        o->oMoveFlags &= ~OBJ_MOVE_IN_AIR;
    }
    else
    {
        o->oMoveFlags |= OBJ_MOVE_IN_AIR;
    }
}

static void nop_802A0964(void) { }

static s32 clear_move_flag(u32 *bitSet, s32 flag)
{
    if (*bitSet & flag)
    {
        *bitSet &= flag ^ 0xFFFFFFFF;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void obj_unused_resolve_wall_collisions(f32 offsetY, f32 radius)
{
    if (radius > 0.1L)
    {
        resolve_wall_collisions(&o->oPosX, &o->oPosY, &o->oPosZ, offsetY, radius);
    }
}

s16 abs_angle_diff(s16 x0, s16 x1)
{
    s16 diff = x1 - x0;

    if (diff == -0x8000)
    {
        diff = -0x7FFF;
    }

    if (diff < 0)
    {
        diff = -diff;
    }

    return diff;
}

void obj_move_xz_using_fvel(void)
{
    o->oVelX = o->oForwardVel * sins(o->oMoveAngleYaw);
    o->oVelZ = o->oForwardVel * coss(o->oMoveAngleYaw);

    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
}

void obj_move_y_with_terminal_vel(void)
{
    if (o->oVelY < -70.0f)
    {
        o->oVelY = -70.0f;
    }

    o->oPosY += o->oVelY;
}

void obj_compute_vel_xz(void)
{
    o->oVelX = o->oForwardVel * sins(o->oMoveAngleYaw);
    o->oVelZ = o->oForwardVel * coss(o->oMoveAngleYaw);
}

f32 func_802A0BF4(f32 value, f32 center, f32 zeroThreshold, f32 increment)
{
    f32 relative;
    if ((relative = value - center) > 0)
    {
        if (relative < zeroThreshold)
        {
            return 0.0f;
        }
        else
        {
            return -increment;
        }
    }
    else
    {
        if (relative > -zeroThreshold)
        {
            return 0.0f;
        }
        else
        {
            return increment;
        }
    }
}

s32 are_objects_collided(struct Object *obj1, struct Object *obj2)
{
    s32 i = 0;

    if (obj1->numCollidedObjs > 0)
    {
        do
        {
            if (obj1->collidedObjs[i] == obj2)
            {
                return TRUE;
            }
        }
        while (++i < obj1->numCollidedObjs);
    }

    return FALSE;
}

void obj_set_behavior(void *behavior)
{
    o->behavior = segmented_to_virtual(behavior);
}

void set_object_behavior(struct Object *obj, void *behavior)
{
    obj->behavior = segmented_to_virtual(behavior);
}

s32 obj_has_behavior(u32 *behavior)
{
    if (o->behavior == segmented_to_virtual(behavior))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

s32 object_has_behavior(struct Object *obj, u32 *behavior)
{
    if (obj->behavior == segmented_to_virtual(behavior))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

f32 obj_lateral_dist_from_mario_to_home(void)
{
    f32 dist;
    f32 dx = o->oHomeX - gMarioObject->oPosX;
    f32 dz = o->oHomeZ - gMarioObject->oPosZ;

    dist = sqrtf(dx*dx + dz*dz);
    return dist;
}

f32 obj_lateral_dist_to_home(void)
{
    f32 dist;
    f32 dx = o->oHomeX - o->oPosX;
    f32 dz = o->oHomeZ - o->oPosZ;

    dist = sqrtf(dx*dx + dz*dz);
    return dist;
}

s32 obj_outside_home_square(f32 halfLength)
{
    if (o->oHomeX - halfLength > o->oPosX)
    {
        return TRUE;
    }

    if (o->oHomeX + halfLength < o->oPosX)
    {
        return TRUE;
    }

    if (o->oHomeZ - halfLength > o->oPosZ)
    {
        return TRUE;
    }

    if (o->oHomeZ + halfLength < o->oPosZ)
    {
        return TRUE;
    }

    return 0;
}

s32 obj_outside_home_rectangle(f32 minX, f32 maxX, f32 minZ, f32 maxZ)
{
    if (o->oHomeX + minX > o->oPosX)
    {
        return TRUE;
    }

    if (o->oHomeX + maxX < o->oPosX)
    {
        return TRUE;
    }

    if (o->oHomeZ + minZ > o->oPosZ)
    {
        return TRUE;
    }

    if (o->oHomeZ + maxZ < o->oPosZ)
    {
        return TRUE;
    }

    return FALSE;
}

void obj_set_pos_to_home(void)
{
    o->oPosX = o->oHomeX;
    o->oPosY = o->oHomeY;
    o->oPosZ = o->oHomeZ;
}

void obj_set_pos_to_home_and_stop(void)
{
    obj_set_pos_to_home();

    o->oForwardVel = 0;
    o->oVelY = 0;
}

void obj_shake_y(f32 amount)
{
    //! Technically could cause a bit of drift, but not much
    if (o->oTimer % 2 == 0)
    {
        o->oPosY += amount;
    }
    else
    {
        o->oPosY -= amount;
    }
}

void func_802A11B4(UNUSED s32 a0, s32 a1)
{
    D_8033B1B0.unk1C[1] = (s16)a1;
    D_8032CFD0 = o;
}

void Unknown802A11E4(UNUSED s32 sp0, UNUSED s32 sp4, f32 sp8)
{
    if (o->oDistanceToMario < sp8)
    {
        gMarioObject->oInteractStatus = 1;
    }
}

void func_802A1230(struct Object *a0)
{
    a0->header.gfx.node.flags |= 0x04;
}

void obj_set_hitbox_radius_and_height(f32 radius, f32 height)
{
    o->hitboxRadius = radius;
    o->hitboxHeight = height;
}

void func_802A1274(f32 f12, f32 f14)
{
    o->hurtboxRadius = f12;
    o->hurtboxHeight = f14;
}

static void spawn_object_loot_coins(
    struct Object *obj, s32 numCoins, f32 sp30, void *coinBehavior, s16 posJitter, s16 sp3E)
{
    s32 i;
    f32 spawnHeight;
    struct Surface *floor;
    struct Object *coin;

    spawnHeight = find_floor(obj->oPosX, obj->oPosY, obj->oPosZ, &floor);
    if (obj->oPosY - spawnHeight > 100.0f)
    {
        spawnHeight = obj->oPosY;
    }

    for (i = 0; i < numCoins; i++)
    {
        if (obj->oNumLootCoins <= 0)
        {
            break;
        }

        obj->oNumLootCoins--;

        coin = spawn_object(obj, sp3E, coinBehavior);
        translate_object_xz_random(coin, posJitter);
        coin->oPosY = spawnHeight;
        coin->oUnknownUnk110_F32 = sp30;
    }
}

void spawn_object_loot_blue_coins(struct Object *obj, s32 numCoins, f32 sp28, s16 posJitter)
{
    spawn_object_loot_coins(obj, numCoins, sp28, beh_blue_coin_jumping, posJitter, 118);
}

void spawn_object_loot_yellow_coins(struct Object *obj, s32 numCoins, f32 sp28)
{
    spawn_object_loot_coins(obj, numCoins, sp28, beh_single_coin_gets_spawned, 0, 116);
}

void obj_spawn_loot_coin_at_mario_pos(void)
{
    struct Object *coin;
    if (o->oNumLootCoins <= 0)
    {
        return;
    }

    o->oNumLootCoins--;

    coin = spawn_object(o, 116, beh_single_coin_gets_spawned);
    coin->oVelY = 30.0f;

    copy_object_pos(coin, gMarioObject);
}

f32 obj_abs_y_dist_to_home(void)
{
    f32 dist = o->oHomeY - o->oPosY;

    if (dist < 0)
    {
        dist = -dist;
    }

    return dist;
}

s32 Unknown802A1548()
{
    s32 spC = o->header.gfx.unk38.animFrame;
    s32 sp8 = o->header.gfx.unk38.curAnim->unk08;
    s32 sp4;

    if (spC < 0)
    {
        spC = 0;
    }
    else if (sp8 - 1 == spC)
    {
        spC = 0;
    }
    else
    {
        spC++;
    }

    sp4 = (spC << 16) / sp8;

    return sp4;
}

static s32 obj_detect_steep_floor(s16 steepAngleDegrees)
{
    struct Surface *intendedFloor;
    f32 intendedX, intendedFloorHeight, intendedZ;
    f32 deltaFloorHeight;
    f32 steepNormalY = coss((s16)(steepAngleDegrees * (0x10000 / 360)));

    if (o->oForwardVel != 0)
    {
        intendedX = o->oPosX + o->oVelX;
        intendedZ = o->oPosZ + o->oVelZ;
        intendedFloorHeight = find_floor(intendedX, o->oPosY, intendedZ, &intendedFloor);
        deltaFloorHeight = intendedFloorHeight - o->oFloorHeight;

        if (intendedFloorHeight < -10000.0f)
        {
            o->oWallAngle = o->oMoveAngleYaw + 0x8000;
            return 2;
        }
        else if (intendedFloor->normal[1] < steepNormalY &&
            deltaFloorHeight > 0 &&
            intendedFloorHeight > o->oPosY)
        {
            o->oWallAngle = atan2s(intendedFloor->normal[2], intendedFloor->normal[0]);
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

s32 obj_resolve_wall_collisions(void)
{
    s32 numCollisions;
    struct Surface *wall;
    struct WallCollisionData collisionData;

    f32 offsetY = 10.0f;
    f32 radius = o->oWallHitboxRadius;

    if (radius > 0.1L)
    {
        collisionData.offsetY = offsetY;
        collisionData.radius = radius;
        collisionData.x = (s16) o->oPosX;
        collisionData.y = (s16) o->oPosY;
        collisionData.z = (s16) o->oPosZ;

        numCollisions = find_wall_collisions(&collisionData);
        if (numCollisions != 0)
        {
            o->oPosX = collisionData.x;
            o->oPosY = collisionData.y;
            o->oPosZ = collisionData.z;
            wall = collisionData.walls[collisionData.numWalls - 1];

            o->oWallAngle = atan2s(wall->normal[2], wall->normal[0]);
            if (abs_angle_diff(o->oWallAngle, o->oMoveAngleYaw) > 0x4000)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

    return 0;
}

static void obj_update_floor(void)
{
    struct Surface *floor = obj_update_floor_height_and_get_floor();
    o->oFloor = floor;

    if (floor != NULL)
    {
        if (floor->type == SURFACE_LAVA)
        {
            o->oMoveFlags |= OBJ_MOVE_ABOVE_LAVA;
        }
#ifndef VERSION_JP
        else if (floor->type == SURFACE_000A)
        {
            //! This misses SURFACE_0038 (and maybe SURFACE_0032)
            o->oMoveFlags |= OBJ_MOVE_ABOVE_DEATH_BARRIER;
        }
#endif

        o->oFloorType = floor->type;
        o->oFloorRoom = floor->room;
    }
    else
    {
        o->oFloorType = 0;
        o->oFloorRoom = 0;
    }
}

static void obj_update_floor_and_resolve_wall_collisions(s16 steepSlopeDegrees)
{
#ifdef VERSION_JP
    o->oMoveFlags &= ~OBJ_MOVE_ABOVE_LAVA;
#else
    o->oMoveFlags &= ~(OBJ_MOVE_ABOVE_LAVA | OBJ_MOVE_ABOVE_DEATH_BARRIER);
#endif

    if (o->activeFlags & (ACTIVE_FLAG_FAR_AWAY | ACTIVE_FLAG_IN_DIFFERENT_ROOM))
    {
        obj_update_floor();
        o->oMoveFlags &= ~OBJ_MOVE_MASK_HIT_WALL_OR_IN_WATER;

        if (o->oPosY > o->oFloorHeight)
        {
            o->oMoveFlags |= OBJ_MOVE_IN_AIR;
        }
    }
    else
    {
        o->oMoveFlags &= ~OBJ_MOVE_HIT_WALL;
        if (obj_resolve_wall_collisions())
        {
            o->oMoveFlags |= OBJ_MOVE_HIT_WALL;
        }

        obj_update_floor();

        if (o->oPosY > o->oFloorHeight)
        {
            o->oMoveFlags |= OBJ_MOVE_IN_AIR;
        }

        if (obj_detect_steep_floor(steepSlopeDegrees))
        {
            o->oMoveFlags |= OBJ_MOVE_HIT_WALL;
        }

    }
}

void obj_update_floor_and_walls(void)
{
    obj_update_floor_and_resolve_wall_collisions(60);
}

void obj_move_standard(s16 steepSlopeAngleDegrees)
{
    f32 gravity = o->oGravity;
    f32 bounce = o->oBounce;
    f32 buoyancy = o->oBuoyancy;
    f32 dragStrength = o->oDragStrength;
    f32 steepSlopeNormalY;
    s32 careAboutEdgesAndSteepSlopes = FALSE;
    s32 negativeSpeed = FALSE;

    //! Because some objects allow these active flags to be set but don't
    //  avoid updating when they are, we end up with "partial" updates, where
    //  an object's internal state will be updated, but it doesn't move.
    //  This allows numerous glitches and is typically referred to as
    //  deactivation (though this term has a different meaning in the code).
    //  Objects that do this will be marked with //PARTIAL_UPDATE.
    if (!(o->activeFlags & (ACTIVE_FLAG_FAR_AWAY | ACTIVE_FLAG_IN_DIFFERENT_ROOM)))
    {
        if (steepSlopeAngleDegrees < 0)
        {
            careAboutEdgesAndSteepSlopes = TRUE;
            steepSlopeAngleDegrees = -steepSlopeAngleDegrees;
        }

        steepSlopeNormalY = coss(steepSlopeAngleDegrees * (0x10000 / 360));

        obj_compute_vel_xz();
        obj_apply_drag_xz(dragStrength);

        obj_move_xz(steepSlopeNormalY, careAboutEdgesAndSteepSlopes);
        obj_move_y(gravity, bounce, buoyancy);

        if (o->oForwardVel < 0)
        {
            negativeSpeed = TRUE;
        }
        o->oForwardVel = sqrtf(sqr(o->oVelX) + sqr(o->oVelZ));
        if (negativeSpeed == TRUE)
        {
            o->oForwardVel = -o->oForwardVel;
        }
    }
}

static s32 obj_within_12k_bounds(void)
{
    if (o->oPosX < -12000.0f || 12000.0f < o->oPosX)
    {
        return FALSE;
    }

    if (o->oPosY < -12000.0f || 12000.0f < o->oPosY)
    {
        return FALSE;
    }

    if (o->oPosZ < -12000.0f || 12000.0f < o->oPosZ)
    {
        return FALSE;
    }

    return TRUE;
}

void obj_move_using_vel_and_gravity(void)
{
    if (obj_within_12k_bounds())
    {
        o->oPosX += o->oVelX;
        o->oPosZ += o->oVelZ;
        o->oVelY += o->oGravity;
        o->oPosY += o->oVelY;
    }
}

void obj_move_xz_using_fvel_and_gravity(void)
{
    obj_compute_vel_xz();
    obj_move_using_vel_and_gravity();
}

void set_object_pos_relative(
    struct Object *obj, struct Object *other, f32 dleft, f32 dy, f32 dforward)
{
    f32 facingZ = coss(other->oMoveAngleYaw);
    f32 facingX = sins(other->oMoveAngleYaw);

    f32 dz = dforward * facingZ - dleft * facingX;
    f32 dx = dforward * facingX + dleft * facingZ;

    obj->oMoveAngleYaw = other->oMoveAngleYaw;

    obj->oPosX = other->oPosX + dx;
    obj->oPosY = other->oPosY + dy;
    obj->oPosZ = other->oPosZ + dz;
}

s16 obj_angle_to_home(void)
{
    s16 angle;
    f32 dx = o->oHomeX - o->oPosX;
    f32 dz = o->oHomeZ - o->oPosZ;

    angle = atan2s(dz, dx);
    return angle;
}

void func_802A2008(struct Object *a0, struct Object *a1)
{
    a0->header.gfx.pos[0] = a1->oPosX;
    a0->header.gfx.pos[1] = a1->oPosY + a1->oGraphYOffset;
    a0->header.gfx.pos[2] = a1->oPosZ;

    a0->header.gfx.angle[0] = a1->oMoveAnglePitch & 0xFFFF;
    a0->header.gfx.angle[1] = a1->oMoveAngleYaw & 0xFFFF;
    a0->header.gfx.angle[2] = a1->oMoveAngleRoll & 0xFFFF;
}

/**
 * Transform the vector at localTranslateIndex into the object's local
 * coordinates, and then add it to the vector at posIndex.
 */
void translate_object_local(
    struct Object *obj, s16 posIndex, s16 localTranslateIndex)
{
    f32 dx = obj->rawData.asF32[localTranslateIndex + 0];
    f32 dy = obj->rawData.asF32[localTranslateIndex + 1];
    f32 dz = obj->rawData.asF32[localTranslateIndex + 2];

    obj->rawData.asF32[posIndex + 0] += obj->transform[0][0] * dx + obj->transform[1][0] * dy + obj->transform[2][0] * dz;
    obj->rawData.asF32[posIndex + 1] += obj->transform[0][1] * dx + obj->transform[1][1] * dy + obj->transform[2][1] * dz;
    obj->rawData.asF32[posIndex + 2] += obj->transform[0][2] * dx + obj->transform[1][2] * dy + obj->transform[2][2] * dz;
}

void build_object_transform_from_pos_and_angle(
    struct Object *obj, s16 posIndex, s16 angleIndex)
{
    f32 translate[3];
    s16 rotation[3];

    translate[0] = obj->rawData.asF32[posIndex + 0];
    translate[1] = obj->rawData.asF32[posIndex + 1];
    translate[2] = obj->rawData.asF32[posIndex + 2];

    rotation[0] = obj->rawData.asS32[angleIndex + 0];
    rotation[1] = obj->rawData.asS32[angleIndex + 1];
    rotation[2] = obj->rawData.asS32[angleIndex + 2];

    mtxf_rotate_zxy_and_translate(obj->transform, translate, rotation);
}

void func_802A2270(struct Object *obj)
{
    if (obj->oFlags & OBJ_FLAG_0020)
    {
        build_object_transform_from_pos_and_angle(obj, O_POS_INDEX, O_FACE_ANGLE_INDEX);
        apply_scale_to_object_transform(obj);
    }

    obj->header.gfx.throwMatrix = obj->transform;

    //! Sets scale of gCurrentObject instead of obj. Not exploitable since this
    //  function is only called with obj = gCurrentObject
    obj_scale(1.0f);
}

void build_object_transform_relative_to_parent(struct Object *obj)
{
    struct Object *parent = obj->parentObj;

    build_object_transform_from_pos_and_angle(
        obj, O_PARENT_RELATIVE_POS_INDEX, O_FACE_ANGLE_INDEX);
    apply_scale_to_object_transform(obj);
    mtxf_mul(obj->transform, obj->transform, parent->transform);

    obj->oPosX = obj->transform[3][0];
    obj->oPosY = obj->transform[3][1];
    obj->oPosZ = obj->transform[3][2];

    obj->header.gfx.throwMatrix = obj->transform;

    //! Sets scale of gCurrentObject instead of obj. Not exploitable since this
    //  function is only called with obj = gCurrentObject
    obj_scale(1.0f);
}

void Unknown802A2380(struct Object *a0)
{
    a0->oFlags &= ~OBJ_FLAG_TRANSFORM_RELATIVE_TO_PARENT;
    a0->oFlags |= OBJ_FLAG_0800;

    a0->transform[3][0] = a0->oPosX;
    a0->transform[3][1] = a0->oPosY;
    a0->transform[3][2] = a0->oPosZ;
}

void obj_rotate_move_angle_using_vel(void)
{
    o->oMoveAnglePitch += o->oAngleVelPitch;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oMoveAngleRoll += o->oAngleVelRoll;
}

void obj_rotate_face_angle_using_vel(void)
{
    o->oFaceAnglePitch += o->oAngleVelPitch;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oFaceAngleRoll += o->oAngleVelRoll;
}

void obj_set_face_angle_to_move_angle(void)
{
    o->oFaceAnglePitch = o->oMoveAnglePitch;
    o->oFaceAngleYaw = o->oMoveAngleYaw;
    o->oFaceAngleRoll = o->oMoveAngleRoll;
}

s32 obj_follow_path(UNUSED s32 unusedArg)
{
    struct Waypoint *startWaypoint;
    struct Waypoint *lastWaypoint;
    struct Waypoint *targetWaypoint;
    f32 prevToNextX, prevToNextY, prevToNextZ;
    UNUSED s32 sp2C;
    f32 objToNextXZ;
    f32 objToNextX, objToNextY, objToNextZ;

    if (o->oPathedPrevWaypointFlags == 0)
    {
        o->oPathedPrevWaypoint = o->oPathedStartWaypoint;
        o->oPathedPrevWaypointFlags = WAYPOINT_FLAGS_INITIALIZED;
    }

    startWaypoint = o->oPathedStartWaypoint;
    lastWaypoint = o->oPathedPrevWaypoint;

    if ((lastWaypoint + 1)->flags != WAYPOINT_FLAGS_END)
    {
        targetWaypoint = lastWaypoint + 1;
    }
    else
    {
        targetWaypoint = startWaypoint;
    }

    o->oPathedPrevWaypointFlags = lastWaypoint->flags | WAYPOINT_FLAGS_INITIALIZED;

    prevToNextX = targetWaypoint->pos[0] - lastWaypoint->pos[0];
    prevToNextY = targetWaypoint->pos[1] - lastWaypoint->pos[1];
    prevToNextZ = targetWaypoint->pos[2] - lastWaypoint->pos[2];

    objToNextX = targetWaypoint->pos[0] - o->oPosX;
    objToNextY = targetWaypoint->pos[1] - o->oPosY;
    objToNextZ = targetWaypoint->pos[2] - o->oPosZ;
    objToNextXZ = sqrtf(sqr(objToNextX) + sqr(objToNextZ));

    o->oPathedTargetYaw = atan2s(objToNextZ, objToNextX);
    o->oPathedTargetPitch = atan2s(objToNextXZ, -objToNextY);

    // If dot(prevToNext, objToNext) <= 0 (i.e. reached other side of target waypoint)
    if (prevToNextX * objToNextX + prevToNextY * objToNextY + prevToNextZ * objToNextZ <= 0.0f)
    {
        o->oPathedPrevWaypoint = targetWaypoint;
        if ((targetWaypoint + 1)->flags == WAYPOINT_FLAGS_END)
        {
            return PATH_REACHED_END;
        }
        else
        {
            return PATH_REACHED_WAYPOINT;
        }
    }

    return PATH_NONE;
}

void chain_segment_init(struct ChainSegment *segment)
{
    segment->posX = 0.0f;
    segment->posY = 0.0f;
    segment->posZ = 0.0f;

    segment->pitch = 0;
    segment->yaw = 0;
    segment->roll = 0;
}

f32 random_f32_around_zero(f32 diameter)
{
    return RandomFloat() * diameter - diameter / 2.0f;
}

f32 scale_object_random(struct Object *obj, f32 rangeLength, f32 minScale)
{
    f32 scale = RandomFloat() * rangeLength + minScale;
    scale_object_xyz(obj, scale, scale, scale);
}

void translate_object_xyz_random(struct Object *obj, f32 rangeLength)
{
    obj->oPosX += RandomFloat() * rangeLength - rangeLength * 0.5f;
    obj->oPosY += RandomFloat() * rangeLength - rangeLength * 0.5f;
    obj->oPosZ += RandomFloat() * rangeLength - rangeLength * 0.5f;
}

void translate_object_xz_random(struct Object *obj, f32 rangeLength)
{
    obj->oPosX += RandomFloat() * rangeLength - rangeLength * 0.5f;
    obj->oPosZ += RandomFloat() * rangeLength - rangeLength * 0.5f;
}

static void func_802A297C(struct Object *a0)
{
    f32 spC = a0->oUnkC0;
    f32 sp8 = a0->oUnkBC;
    f32 sp4 = a0->oForwardVel;

    a0->oVelX = a0->transform[0][0] * spC + a0->transform[1][0] * sp8 + a0->transform[2][0] * sp4;
    a0->oVelY = a0->transform[0][1] * spC + a0->transform[1][1] * sp8 + a0->transform[2][1] * sp4;
    a0->oVelZ = a0->transform[0][2] * spC + a0->transform[1][2] * sp8 + a0->transform[2][2] * sp4;
}

void func_802A2A38(void)
{
    build_object_transform_from_pos_and_angle(o, O_PARENT_RELATIVE_POS_INDEX, O_MOVE_ANGLE_INDEX);
    func_802A297C(o);
    o->oPosX += o->oVelX;
    o->oPosY += o->oVelY;
    o->oPosZ += o->oVelZ;
}

s16 obj_reflect_move_angle_off_wall(void) {
    s16 angle = o->oWallAngle - ((s16)o->oMoveAngleYaw - (s16)o->oWallAngle) + 0x8000;
    return angle;
}

void func_802A2B04(struct Struct802A2B04 *sp28)
{
    struct Object *sp24;
    s32 sp20;
    f32 sp1C;
    s32 sp18 = sp28->unk1; // TODO: pass in proper struct

    if (gPostUpdateObjCount >= 0x97 && sp18 >= 0x0b)
    {
        sp18 = 10;
    }

    if (gPostUpdateObjCount >= 0xd3)
    {
        sp18 = 0;
    }

    for (sp20 = 0; sp18 > sp20; sp20++)
    {
        sp1C = RandomFloat() * (sp28->unk10 * 0.1f) + sp28->unkC * 0.1f;
        sp24 = spawn_object(o, sp28->unk2, beh_white_puff_explosion);
        sp24->oBehParams2ndByte = sp28->unk0;
        sp24->oMoveAngleYaw = RandomU16();
        sp24->oGravity = sp28->unk8;
        sp24->oDragStrength = sp28->unk9;
        sp24->oPosY += sp28->unk3;
        sp24->oForwardVel = RandomFloat() * sp28->unk5 + sp28->unk4;
        sp24->oVelY = RandomFloat() * sp28->unk7 + sp28->unk6;
        scale_object_xyz(sp24, sp1C, sp1C, sp1C);
    }
}

void set_object_hitbox(struct Object *obj, struct ObjectHitbox *hitbox)
{
    if (!(obj->oFlags & OBJ_FLAG_30))
    {
        obj->oFlags |= OBJ_FLAG_30;

        obj->oInteractType = hitbox->interactType;
        obj->oDamageOrCoinValue = hitbox->damageOrCoinValue;
        obj->oHealth = hitbox->health;
        obj->oNumLootCoins = hitbox->numLootCoins;

        obj_become_tangible();
    }

    obj->hitboxRadius = obj->header.gfx.scale[0] * hitbox->radius;
    obj->hitboxHeight = obj->header.gfx.scale[1] * hitbox->height;
    obj->hurtboxRadius = obj->header.gfx.scale[0] * hitbox->hurtboxRadius;
    obj->hurtboxHeight = obj->header.gfx.scale[1] * hitbox->hurtboxHeight;
    obj->hitboxDownOffset = obj->header.gfx.scale[1] * hitbox->downOffset;
}

s32 signum_positive(s32 x)
{
    if (x >= 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

f32 absf(f32 x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}

s32 absi(s32 a0)
{
    if (a0 >= 0)
    {
        return a0;
    }
    else
    {
        return -a0;
    }
}

s32 func_802A2EFC(s32 a0, s32 a1)
{
    s32 sp4 = 0;
    s32 sp0;

    if (o->oTimer >= a0)
    {
        if ((sp0 = o->oTimer - a0) & 1)
        {
            o->header.gfx.node.flags |= 0x10;
            if (a1 < sp0 / 2)
            {
                sp4 = 1;
            }
        }
        else
        {
            o->header.gfx.node.flags &= ~0x10;
        }
    }

    return sp4;
}

s32 obj_is_mario_ground_pounding_platform(void)
{
    if (gMarioObject->platform == o)
    {
        if (gMarioStates[0].action == ACT_GROUND_POUND_LAND)
        {
            return TRUE;
        }
    }

    return FALSE;
}

void func_802A3004(void)
{
    func_802AA618(0, 0, 46.0f);
}

void func_802A3034(s32 sp18)
{
    func_802AA618(0, 0, 46.0f);
    create_sound_spawner(sp18);
}

void obj_push_mario_away(f32 radius)
{
    f32 marioRelX = gMarioObject->oPosX - o->oPosX;
    f32 marioRelZ = gMarioObject->oPosZ - o->oPosZ;
    f32 marioDist = sqrtf(sqr(marioRelX) + sqr(marioRelZ));

    if (marioDist < radius)
    {
        //! If this function pushes mario out of bounds, it will trigger mario's
        //  oob failsafe
        gMarioStates[0].pos[0] += (radius - marioDist) / radius * marioRelX;
        gMarioStates[0].pos[2] += (radius - marioDist) / radius * marioRelZ;
    }
}

void obj_push_mario_away_from_cylinder(f32 radius, f32 extentY)
{
    f32 marioRelY = gMarioObject->oPosY - o->oPosY;

    if (marioRelY < 0)
    {
        marioRelY = -marioRelY;
    }

    if (marioRelY < extentY)
    {
        obj_push_mario_away(radius);
    }
}

void BehDustSmokeLoop(void)
{
    o->oPosX += o->oVelX;
    o->oPosY += o->oVelY;
    o->oPosZ += o->oVelZ;

    if (o->oUnknownUnkF4_S32 == 10)
    {
        mark_object_for_deletion(o);
    }

    o->oUnknownUnkF4_S32++;
}

static void nop_802A3294(void) { }

s32 func_802A32A4(s8 *a0)
{
    o->oUnk1AC = a0;
    o->oUnk1B0 = 0;

    return *(s8 *)o->oUnk1AC;
}

s32 func_802A32E0(void)
{
    s8 spF;
    s8 *sp8 = o->oUnk1AC;
    s32 sp4 = o->oUnk1B0 + 1;

    if (sp8[sp4] != -1)
    {
        spF = sp8[sp4];
        o->oUnk1B0++;
    }
    else
    {
        spF = sp8[0];
        o->oUnk1B0 = 0;
    }

    return spF;
}

static void nop_802A3380(UNUSED s32 sp0, UNUSED s32 sp4) { }

void func_802A3398(s32 a0, s32 a1, f32 sp10, f32 sp14)
{
    f32 sp4 = sp14 - sp10;
    f32 sp0 = (f32)o->oTimer / a1;

    if (a0 & 0x01)
    {
        o->header.gfx.scale[0] = sp4 * sp0 + sp10;
    }

    if (a0 & 0x02)
    {
        o->header.gfx.scale[1] = sp4 * sp0 + sp10;
    }

    if (a0 & 0x04)
    {
        o->header.gfx.scale[2] = sp4 * sp0 + sp10;
    }
}

void func_802A3470(void)
{
    o->oPosX = o->oHomeX + gDebugInfo[5][0];
    o->oPosY = o->oHomeY + gDebugInfo[5][1];
    o->oPosZ = o->oHomeZ + gDebugInfo[5][2];
    obj_scale(gDebugInfo[5][3] / 100.0f + 1.0l);
}

static void nop_802A3544(void) { }

s32 obj_is_mario_on_platform(void)
{
    if (gMarioObject->platform == o)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

s32 obj_shake_y_until(s32 cycles, s32 amount)
{
    if (o->oTimer % 2 != 0)
    {
        o->oPosY -= amount;
    }
    else
    {
        o->oPosY += amount;
    }

    if (o->oTimer == cycles * 2)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

s32 func_802A362C(s32 a0)
{
    if (a0 >= 4 || a0 < 0)
    {
        return 1;
    }

    o->oPosY += D_8032F0A0[a0];
    return 0;
}

s32 obj_call_action_function(void (*actionFunctions[])(void))
{
    void (*actionFunction)(void) = actionFunctions[o->oAction];
    actionFunction();
}

static struct Object *func_802A36D8(s32 sp20, s32 sp24)
{
    struct Object *sp1C = spawn_object(o, 122, beh_unused_080C);
    sp1C->oUnk1B0 = sp24;
    sp1C->oBehParams = o->oBehParams;
    sp1C->oBehParams2ndByte = sp20;

    return sp1C;
}

void Unknown802A3750(void)
{
    func_802A36D8(0, 0);
}

s16 func_802A377C(s32 a0)
{
    return D_8032F0A4[a0];
}

s32 obj_mario_far_away(void)
{
    f32 dx = o->oHomeX - gMarioObject->oPosX;
    f32 dy = o->oHomeY - gMarioObject->oPosY;
    f32 dz = o->oHomeZ - gMarioObject->oPosZ;
    f32 marioDistToHome = sqrtf(dx*dx + dy*dy + dz*dz);

    if (o->oDistanceToMario > 2000.0f && marioDistToHome > 2000.0f)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

s32 obj_is_mario_moving_fast_or_in_air(s32 speedThreshold)
{
    if (gMarioStates[0].forwardVel > speedThreshold)
    {
        return TRUE;
    }

    if (gMarioStates[0].action & ACT_FLAG_AIR)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

s32 item_in_array(s8 item, s8 *array)
{
    while (*array != -1)
    {
        if (*array == item)
        {
            return TRUE;
        }

        array++;
    }

    return FALSE;
}

static void nop_802A3968(void) { }

void bhv_init_room(void)
{
    struct Surface *floor;
    f32 floorHeight;

    if (item_in_array(gCurrLevelNum, sLevelsWithRooms))
    {
        floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &floor);

        if (floor != NULL)
        {
            if (floor->room != 0)
            {
                o->oRoom = floor->room;
            }
            else
            {
                // Floor probably belongs to a platform object. Try looking
                // underneath it
                find_floor(o->oPosX, floorHeight - 100.0f, o->oPosZ, &floor);
                if (floor != NULL)
                {
                    //! Technically possible that the room could still be 0 here
                    o->oRoom = floor->room;
                }
            }
        }
    }
    else
    {
        o->oRoom = -1;
    }
}

void obj_enable_rendering_if_mario_in_room(void)
{
    register s32 marioInRoom;

    if (o->oRoom != -1 && gMarioCurrentRoom != 0)
    {
        if (gMarioCurrentRoom == o->oRoom)
        {
            marioInRoom = TRUE;
        }
        else if (D_8035FE68[gMarioCurrentRoom][0] == o->oRoom)
        {
            marioInRoom = TRUE;
        }
        else if (D_8035FE68[gMarioCurrentRoom][1] == o->oRoom)
        {
            marioInRoom = TRUE;
        }
        else
        {
            marioInRoom = FALSE;
        }

        if (marioInRoom)
        {
            obj_enable_rendering();
            o->activeFlags &= ~ACTIVE_FLAG_IN_DIFFERENT_ROOM;
            gNumRoomedObjectsInMarioRoom++;
        }
        else
        {
            obj_disable_rendering();
            o->activeFlags |= ACTIVE_FLAG_IN_DIFFERENT_ROOM;
            gNumRoomedObjectsNotInMarioRoom++;
        }
    }
}

s32 obj_set_hitbox_and_die_if_attacked(
    struct ObjectHitbox *hitbox, s32 deathSound, s32 noLootCoins)
{
    s32 interacted = FALSE;

    set_object_hitbox(o, hitbox);

    if (noLootCoins)
    {
        o->oNumLootCoins = 0;
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED)
    {
        if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED)
        {
            func_802A3004();
            spawn_object_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
            mark_object_for_deletion(o);
            create_sound_spawner(deathSound);
        }
        else
        {
            interacted = TRUE;
        }

    }

    o->oInteractStatus = 0;
    return interacted;
}

void func_802A3C98(f32 sp18, s32 sp1C)
{
    func_802AA618(0, 0, sp18);
    func_802AD82C(30, 138, 3.0f, 4);
    mark_object_for_deletion(o);

    if (sp1C == 1)
    {
        spawn_object_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
    }
    else if (sp1C == 2)
    {
        spawn_object_loot_blue_coins(o, o->oNumLootCoins, 20.0f, 150);
    }
}

void set_object_collision_data(struct Object *obj, void *segAddr)
{
    obj->collisionData = segmented_to_virtual(segAddr);
}

void obj_if_hit_wall_bounce_away(void)
{
    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL)
    {
        o->oMoveAngleYaw = o->oWallAngle;
    }
}

s32 obj_hide_if_mario_far_away_y(f32 distY)
{
    if (absf(o->oPosY - gMarioObject->oPosY) < distY)
    {
        obj_unhide();
        return FALSE;
    }
    else
    {
        obj_hide();
        return TRUE;
    }
}

s32 Geo18_802A45E4(s32 a0, struct GraphNode *node, UNUSED void *a3)
{
    if (a0 == 1)
    {
        // TODO: what is the right type?
        ((struct GraphNode_802A45E4*)node->next)->unk18 = 300;
        ((struct GraphNode_802A45E4*)node->next)->unk1A = 300;
        ((struct GraphNode_802A45E4*)node->next)->unk1C = 0;
    }

    return 0;
}

s32 Unknown802A3E84(s32 a0, struct GraphNode *a1, UNUSED s32 sp8)
{
    if (a0 == 1)
    {
        ((struct GraphNode_802A45E4*)a1->next)->unk18 = gDebugInfo[4][0];
        ((struct GraphNode_802A45E4*)a1->next)->unk1A = gDebugInfo[4][1];
        ((struct GraphNode_802A45E4*)a1->next)->unk1C = gDebugInfo[4][2];
        ((struct GraphNode_802A45E4*)a1->next)->unk1E = gDebugInfo[4][3];
        ((struct GraphNode_802A45E4*)a1->next)->unk20 = gDebugInfo[4][4];
        ((struct GraphNode_802A45E4*)a1->next)->unk22 = gDebugInfo[4][5];
    }

    return 0;
}

s32 obj_is_hidden(struct Object *a0)
{
    if (a0->header.gfx.node.flags & GRAPH_RENDER_10)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void enable_time_stop(void)
{
    gTimeStopState |= TIME_STOP_ENABLED;
}

void disable_time_stop(void)
{
    gTimeStopState &= ~TIME_STOP_ENABLED;
}

void set_time_stop_flag(s32 flag)
{
    gTimeStopState |= flag;
}

void clear_time_stop_flag(s32 flag)
{
    gTimeStopState = gTimeStopState & (flag ^ 0xFFFFFFFF);
}

s32 func_802A3FF8(f32 radius, f32 height, UNUSED s32 unused)
{
    f32 latDistToMario;
    UNUSED s16 angleFromMario;

    if (o->oDistanceToMario < 1500.0f)
    {
        latDistToMario = lateral_dist_between_objects(o, gMarioObject);
        angleFromMario = angle_to_object(gMarioObject, o);

        if (latDistToMario < radius &&
            o->oPosY < gMarioObject->oPosY + 160.0f &&
            gMarioObject->oPosY < o->oPosY + height &&
            !(gMarioStates[0].action & ACT_FLAG_AIR) &&
            mario_ready_to_speak())
        {
            return TRUE;
        }
    }

    return FALSE;
}

s32 obj_is_mario_in_range_and_ready_to_speak(f32 radius, f32 height)
{
    return func_802A3FF8(radius, height, 0x1000);
}

static void obj_end_dialogue(s32 dialogueFlags, s32 dialogueResult)
{
    o->oDialogueResponse = dialogueResult;
    o->oDialogueState++;

    if (!(dialogueFlags & DIALOGUE_UNK1_FLAG_4))
    {
        func_802573C8(0);
    }
}

s32 obj_update_dialogue_unk1(s32 arg0, s32 dialogueFlags, s32 dialogID, UNUSED s32 unusedArg)
{
    s32 dialogueResponse = 0;
    UNUSED s32 doneTurning = TRUE;

    switch (o->oDialogueState)
    {
#ifdef VERSION_JP
    case DIALOGUE_UNK1_ENABLE_TIME_STOP:
        //! We enable time stop even if mario is not ready to speak. This
        //  allows us to move during time stop as long as mario never enters
        //  an action that can be interrupted with text.
        if (gMarioState->health >= 0x100)
        {
            gTimeStopState |= TIME_STOP_ENABLED;
            o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oDialogueState++;
        }
        break;
#else
    case DIALOGUE_UNK1_ENABLE_TIME_STOP:
        // Patched :(
        // Wait for mario to be ready to speak, and then enable time stop
        if (mario_ready_to_speak() || gMarioState->action == ACT_UNKNOWN_106)
        {
            gTimeStopState |= TIME_STOP_ENABLED;
            o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oDialogueState++;
        }
        else
        {
            break;
        }
        // Fall through so that mario's action is interrupted immediately
        // after time is stopped
#endif

    case DIALOGUE_UNK1_INTERRUPT_MARIO_ACTION:
        if (func_802573C8(arg0) == 2)
        {
            o->oDialogueState++;
        }
        break;

    case DIALOGUE_UNK1_BEGIN_DIALOGUE:
        if (dialogueFlags & DIALOGUE_UNK1_FLAG_2)
        {
            func_802D8050(dialogID);
        }
        else if (dialogueFlags & DIALOGUE_UNK1_FLAG_1)
        {
            func_802D7F90(dialogID);
        }
        o->oDialogueState++;
        break;

    case DIALOGUE_UNK1_AWAIT_DIALOGUE:
        if (dialogueFlags & DIALOGUE_UNK1_FLAG_2)
        {
            if (gDialogueResponse != 0)
            {
                obj_end_dialogue(dialogueFlags, gDialogueResponse);
            }
        }
        else if (dialogueFlags & DIALOGUE_UNK1_FLAG_1)
        {
            if (get_dialog_id() == -1)
            {
                obj_end_dialogue(dialogueFlags, 3);
            }
        }
        else
        {
            obj_end_dialogue(dialogueFlags, 3);
        }
        break;

    case DIALOGUE_UNK1_DISABLE_TIME_STOP:
        if (gMarioState->action != ACT_UNKNOWN_106 ||
            (dialogueFlags & DIALOGUE_UNK1_FLAG_4))
        {
            gTimeStopState &= ~TIME_STOP_ENABLED;
            o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            dialogueResponse = o->oDialogueResponse;
            o->oDialogueState = DIALOGUE_UNK1_ENABLE_TIME_STOP;
        }
        break;

    default:
        o->oDialogueState = DIALOGUE_UNK1_ENABLE_TIME_STOP;
        break;
    }

    return dialogueResponse;
}

s32 obj_update_dialogue_unk2(s32 arg0, s32 dialogueFlags, s32 dialogueID, s32 arg3)
{
    s32 dialogueResponse = 0;
    s32 doneTurning = TRUE;

    switch (o->oDialogueState)
    {
#ifdef VERSION_JP
    case DIALOGUE_UNK2_ENABLE_TIME_STOP:
        //! We enable time stop even if mario is not ready to speak. This
        //  allows us to move during time stop as long as mario never enters
        //  an action that can be interrupted with text.
        if (gMarioState->health >= 0x0100)
        {
            gTimeStopState |= TIME_STOP_ENABLED;
            o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oDialogueState++;
            o->oDialogueResponse = 0;
        }
        break;
#else
    case DIALOGUE_UNK2_ENABLE_TIME_STOP:
        // Wait for mario to be ready to speak, and then enable time stop
        if (mario_ready_to_speak() || gMarioState->action == ACT_UNKNOWN_106)
        {
            gTimeStopState |= TIME_STOP_ENABLED;
            o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oDialogueState++;
            o->oDialogueResponse = 0;
        }
        else
        {
            break;
        }
        // Fall through so that mario's action is interrupted immediately
        // after time is stopped
#endif

    case DIALOGUE_UNK2_TURN_AND_INTERRUPT_MARIO_ACTION:
        if (dialogueFlags & DIALOGUE_UNK2_FLAG_0)
        {
            doneTurning = obj_rotate_yaw_toward(angle_to_object(o, gMarioObject), 0x800);
            if (o->oDialogueResponse >= 0x21)
            {
                doneTurning = TRUE;
            }
        }

        if (func_802573C8(arg0) == 2 && doneTurning)
        {
            o->oDialogueResponse = 0;
            o->oDialogueState++;
        }
        else
        {
            o->oDialogueResponse++;
        }
        break;

    case DIALOGUE_UNK2_AWAIT_DIALOGUE:
        if (dialogueID == 0xA1)
        {
            if ((o->oDialogueResponse = func_8028F9A4(dialogueID, o)) != 0)
            {
                o->oDialogueState++;
            }
        }
        else
        {
            if ((o->oDialogueResponse = func_8028F8E0(dialogueID, o, arg3)) != 0)
            {
                o->oDialogueState++;
            }
        }
        break;

    case DIALOGUE_UNK2_END_DIALOGUE:
        if (dialogueFlags & DIALOGUE_UNK2_LEAVE_TIME_STOP_ENABLED)
        {
            dialogueResponse = o->oDialogueResponse;
            o->oDialogueState = DIALOGUE_UNK2_ENABLE_TIME_STOP;
        }
        else if (gMarioState->action != ACT_UNKNOWN_106)
        {
            gTimeStopState &= ~TIME_STOP_ENABLED;
            o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            dialogueResponse = o->oDialogueResponse;
            o->oDialogueState = DIALOGUE_UNK2_ENABLE_TIME_STOP;
        }
        else
        {
            func_802573C8(0);
        }
        break;
    }

    return dialogueResponse;
}

s32 obj_has_model(u16 a0)
{
    if (o->header.gfx.asGraphNode == gLoadedGraphNodes[a0])
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void obj_align_gfx_with_floor(void)
{
    struct Surface *floor;
    Vec3f floorNormal;
    Vec3f position;

    position[0] = o->oPosX;
    position[1] = o->oPosY;
    position[2] = o->oPosZ;

    find_floor(position[0], position[1], position[2], &floor);
    if (floor != NULL)
    {
        floorNormal[0] = floor->normal[0];
        floorNormal[1] = floor->normal[1];
        floorNormal[2] = floor->normal[2];

        mtxf_from_up_direction(o->transform, floorNormal, position, o->oFaceAngleYaw);
        o->header.gfx.throwMatrix = o->transform;
    }
}

s32 mario_is_within_rectangle(s16 minX, s16 maxX, s16 minZ, s16 maxZ)
{
    if (gMarioObject->oPosX < minX || maxX < gMarioObject->oPosX)
    {
        return FALSE;
    }

    if (gMarioObject->oPosZ < minZ || maxZ < gMarioObject->oPosZ)
    {
        return FALSE;
    }

    return TRUE;
}

s32 ShakeScreen(s32 sp18)
{
    func_8027F440(sp18, o->oPosX, o->oPosY, o->oPosZ);
}

s32 attack_collided_non_mario_object(struct Object *obj)
{
    s32 numCollidedObjs;
    struct Object *other;
    s32 touchedOtherObject = FALSE;

    numCollidedObjs = obj->numCollidedObjs;
    if (numCollidedObjs != 0)
    {
        other = obj->collidedObjs[0];

        if (other != gMarioObject)
        {
            other->oInteractStatus |=
                INT_STATUS_UNK0 |
                INT_STATUS_WAS_ATTACKED |
                INT_STATUS_INTERACTED |
                INT_STATUS_TOUCHED_BOB_OMB;
            touchedOtherObject = TRUE;
        }
    }

    return touchedOtherObject;
}

s32 obj_was_attacked_or_ground_pounded(void)
{
    s32 attacked = FALSE;

    if ((o->oInteractStatus & INT_STATUS_INTERACTED) &&
        (o->oInteractStatus & INT_STATUS_WAS_ATTACKED))
    {
        attacked = TRUE;
    }

    if (obj_is_mario_ground_pounding_platform())
    {
        attacked = TRUE;
    }

    o->oInteractStatus = 0;
    return attacked;
}

void copy_object_behavior_params(struct Object *dst, struct Object *src)
{
    dst->oBehParams = src->oBehParams;
    dst->oBehParams2ndByte = src->oBehParams2ndByte;
}

void func_802A4A70(s32 sp18, s32 sp1C)
{
    func_8029ED38(sp18);
    o->header.gfx.unk38.animFrame = sp1C;
}

s32 func_802A4AB0(s32 sp18)
{
    func_8029ED38(sp18);
    return func_8029F788();
}

void func_802A4AEC(s32 sp18)
{
    func_8029ED38(sp18);
    func_8029F728();
}

s32 obj_check_grabbed_mario(void)
{
    if (o->oInteractStatus & INT_STATUS_GRABBED_MARIO)
    {
        o->oUnk88 = 1;
        obj_become_intangible();
        return TRUE;
    }

    return FALSE;
}

s32 player_performed_grab_release_action(void)
{
    s32 result = 0;

    if (gPlayer1Controller->stickMag < 30.0f)
    {
        sGrabReleaseState = 0;
    }

    if (sGrabReleaseState == 0 && gPlayer1Controller->stickMag > 40.0f)
    {
        sGrabReleaseState = 1;
        result = TRUE;
    }

    if (gPlayer1Controller->buttonPressed & A_BUTTON)
    {
        result = TRUE;
    }

    return result;
}

void obj_unused_play_footstep_sound(s32 animFrame1, s32 animFrame2, s32 sound)
{
    if (obj_check_anim_frame(animFrame1) || obj_check_anim_frame(animFrame2))
    {
        PlaySound2(sound);
    }
}

void enable_time_stop_including_mario(void)
{
    gTimeStopState |= TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS;
    o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
}

void disable_time_stop_including_mario(void)
{
    gTimeStopState &= ~(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS);
    o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
}

s32 obj_check_interacted(void)
{
    if (o->oInteractStatus & INT_STATUS_INTERACTED)
    {
        o->oInteractStatus = 0;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void obj_spawn_loot_blue_coin(void)
{
    if (o->oNumLootCoins >= 5)
    {
        spawn_object(o, 118, beh_mr_i_blue_coin);
        o->oNumLootCoins -= 5;
    }
}

#ifdef VERSION_US
void obj_spawn_star_at_y_offset(f32 targetX, f32 targetY, f32 targetZ, f32 offsetY)
{
    f32 objectPosY = o->oPosY;
    o->oPosY += offsetY + gDebugInfo[5][0];
    CreateStar(targetX, targetY, targetZ);
    o->oPosY = objectPosY;
}
#endif
