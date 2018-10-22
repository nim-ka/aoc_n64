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

#include "object_helpers.h"
#include "object_helpers2.h"

struct Waypoint {
    s16 flags;
    Vec3s pos;
};

struct Struct802A272C {
    Vec3f vecF;
    Vec3s vecS;
};

s8 D_8032F0A0[] = { 0xF8, 0x08, 0xFC, 0x04};
s16 D_8032F0A4[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
s8 D_8032F0B4[] = { 0x04, 0x06, 0x07, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

extern s32 D_80330440;
extern s32 D_8035FF00;

// These can be static:
extern void func_8029D704(Mat4, Mat4, Mat4);
extern void func_8029EA0C(struct Object *);
extern void func_802A205C(struct Object *, s16, s16);
extern void CopyObjPosition(struct Object *, struct Object *);
extern void CopyObjRotation(struct Object *, struct Object *);
extern struct Object *func_8029F270(void *, f32 *);
extern void func_802A06EC(f32, f32, f32);
extern s32 func_802A0974(u32 *, s32);
extern void func_802AA618(s32, s32, f32);
extern void func_802AD82C(s32, s32, f32, s32);

s32 Geo18_8029D890(s32 sp60, UNUSED s32 sp64, void *sp68) {
    Mat4 sp20; 
    struct Object *sp1C;

    if (sp60 == 1) {
        sp1C = (struct Object *)D_8032CFA0; // TODO: change global type to Object pointer
        if (sp1C->prevObj) {
            func_8029D704(sp20, sp68, D_8032CF9C->unk34);
            func_8029D558(sp20, sp1C->prevObj);
            func_8029EA0C(sp1C->prevObj);
        }
    }
    return 0;
}

struct struct8029D924 {
    /*0x00*/ s16 unk00;
    /*0x02*/ s16 unk02;
    /*0x04*/ s8 filler04[0x18-0x04];
    /*0x18*/ s32 unk18;
};

struct struct8029D924_2 {
    /*0x00*/ s32 unk00;
    /*0x04*/ s32 unk04;
};

struct struct802A1230 {
    /*0x00*/ s16 unk00;
    /*0x02*/ s16 unk02;
};

struct struct8029D924_2 *Geo18_8029D924(s32 sp40, struct struct8029D924 *sp44, UNUSED s32 sp48) {
    struct struct8029D924_2 *sp3C, *sp38;
    struct Object *sp34;
    struct struct8029D924 *sp30;
    UNUSED struct struct8029D924 *sp2C;
    s32 sp28;
    UNUSED struct struct8029D924_2 *sp24, *sp20, *sp1C, *sp18; // sp24 is unused in non-JP versions.

    sp3C = NULL;

    if (sp40 == 1) {
        sp34 = (struct Object *) D_8032CFA0; // TODO: change this to object pointer?
        sp30 = sp44;
        sp2C = sp44;

        if (D_8032CFA4) 
            sp34 = (struct Object *) D_8032CFA4->unk1C; // TODO: change this to object pointer?
            
        sp28 = sp34->oOpacity;
        sp3C = alloc_display_list(24); // likely sizeof(struct struct8029D924_2) * 3

        sp38 = sp3C;

        if (sp28 == 0xFF) {
            if (sp30->unk18 == 20)
                sp30->unk02 = 0x600 | (sp30->unk02 & 0xFF);
            else
                sp30->unk02 = 0x100 | (sp30->unk02 & 0xFF);

            sp34->oAnimState = 0;
        }
        else {
            if (sp30->unk18 == 20)
                sp30->unk02 = 0x600 | (sp30->unk02 & 0xFF);
            else
                sp30->unk02 = 0x500 | (sp30->unk02 & 0xFF);
            
            sp34->oAnimState = 1;

#ifdef VERSION_JP
            if (sp30->unk18 == 10)
            {
                if (gDebugInfo[DEBUG_PAGE_ENEMYINFO][3]) {
                    sp24 = sp38++;
                    sp24->unk00 = 0xB9000002;
                    sp24->unk04 = 3;
                } 
            }
            else {
                if (sp34->active & 0x80) {
                    sp20 = sp38++;
                    sp20->unk00 = 0xB9000002;
                    sp20->unk04 = 3;
                } 
            }
#else // gDebugInfo accesses were removed in all non-JP versions.
            if(sp28 == 0 && segmented_to_virtual(beh_bowser) == sp34->behavior)
            {
                sp34->oAnimState = 2;
            }
            // the debug info check was removed in US. so we need to
            // perform the only necessary check instead of the debuginfo
            // one.
            if (sp30->unk18 != 10) {
                if (sp34->active & 0x80) {
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

s32 GeoSwitchCase8029DB48(s32 a0, struct Object *a1) {
    struct Object *sp4; 
    struct Object *sp0;

    if (a0 == 1) {
        sp4 = (struct Object *)D_8032CFA0; // TODO: change global type to Object pointer
        sp0 = a1;

        if (D_8032CFA4 != 0)
            sp4 = (struct Object *)D_8032CFA4->unk1C;

        if (sp4->oAnimState >= sp0->header.gfx.angle[1])
            sp4->oAnimState = 0;

        sp0->header.gfx.angle[2] = sp4->oAnimState;
    }

    return 0;
}

s32 GeoSwitchCaseBlinking(s32 sp28, struct GraphNodeObject *sp2C) {
    s16 sp26;
    struct Surface *sp20;
    UNUSED struct Object *sp1C;
    struct GraphNodeObject *sp18;

    sp1C = (struct Object *)D_8032CFA0; // TODO: change global type to Object pointer

    sp18 = sp2C;

    if (sp28 == 1) {
        if (gMarioObject == NULL) {
            sp18->angle[2] = 0;
        }
        else {
            gFindFloorIncludeSurface0012 = 1;

            find_floor(gMarioObject->oPosX, gMarioObject->oPosY, gMarioObject->oPosZ, &sp20);

            if (sp20) {
                D_8035FEE0 = sp20->room;
                sp26 = sp20->room - 1;
                print_debug_top_down_objectinfo("areainfo %d", sp20->room);

                if (sp26 >= 0) 
                    sp18->angle[2] = sp26;
            }
        }
    }
    else {
        sp18->angle[2] = 0;
    }
    
    return 0;
}

void func_8029D558(Mat4 a0, struct Object *a1) {
    f32 spC, sp8, sp4;

    spC = a1->oUnk138;
    sp8 = a1->oUnk13C;
    sp4 = a1->oUnk140;

    a1->oPosX = spC * a0[0][0] + sp8 * a0[1][0] + sp4 * a0[2][0] + a0[3][0];
    a1->oPosY = spC * a0[0][1] + sp8 * a0[1][1] + sp4 * a0[2][1] + a0[3][1];
    a1->oPosZ = spC * a0[0][2] + sp8 * a0[1][2] + sp4 * a0[2][2] + a0[3][2];
}

void func_8029D62C(struct Object *a0, Mat4 a1, Mat4 a2) {
    a1[0][0] = a2[0][0] * a0->header.gfx.scale[0];
    a1[1][0] = a2[1][0] * a0->header.gfx.scale[1];
    a1[2][0] = a2[2][0] * a0->header.gfx.scale[2];
    a1[3][0] = a2[3][0];

    a1[0][1] = a2[0][1] * a0->header.gfx.scale[0];
    a1[1][1] = a2[1][1] * a0->header.gfx.scale[1];
    a1[2][1] = a2[2][1] * a0->header.gfx.scale[2];
    a1[3][1] = a2[3][1];

    a1[0][2] = a2[0][2] * a0->header.gfx.scale[0];
    a1[1][2] = a2[1][2] * a0->header.gfx.scale[1];
    a1[2][2] = a2[2][2] * a0->header.gfx.scale[2];
    a1[3][2] = a2[3][2];

    a1[0][3] = a2[0][3];
    a1[1][3] = a2[1][3];
    a1[2][3] = a2[2][3];
    a1[3][3] = a2[3][3];
}

void func_8029D704(Mat4 a0, Mat4 a1, Mat4 a2) {
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

void func_8029DA34(struct Object * sp18, void * sp1C) {
    sp18->parentObj = gCurrentObject;

    if (sp18->oFlags & 0x400) {
        if (beh_carry_something3 == sp1C)
            sp18->oHeldState = 1;

        if (beh_carry_something5 == sp1C)
            sp18->oHeldState = 2;

        if (beh_carry_something4 == sp1C)
            sp18->oHeldState = 3;
    }
    else {
        sp18->behScript = segmented_to_virtual(sp1C);
        sp18->stackIndex = 0;
    }
}

f32 DistanceFromObject(struct Object *sp20, struct Object *sp24) {
    f32 dx = sp20->oPosX - sp24->oPosX;
    f32 dz = sp20->oPosZ - sp24->oPosZ;

    return sqrtf(dx * dx + dz * dz);
}

f32 objects_calc_distance(struct Object *sp28, struct Object *sp2C) {
    f32 dx = sp28->oPosX - sp2C->oPosX;
    f32 dy = sp28->oPosY - sp2C->oPosY;
    f32 dz = sp28->oPosZ - sp2C->oPosZ;

    return sqrtf(dx * dx + + dy * dy + dz * dz);
}

void func_8029DC1C(f32 increment, f32 target) {
    if (gCurrentObject->oForwardVel >= increment)
        gCurrentObject->oForwardVel = increment;
    else 
        gCurrentObject->oForwardVel += target;
}

s32 func_8029DC6C(f32 *a0, f32 spC, f32 sp10) {
    s32 sp4 = 0;

    *a0 += sp10;

    if (sp10 >= 0.0f) {
        if (*a0 > spC) {
            *a0 = spC;
            sp4 = 1;
        }
    }
    else {
        if (*a0 < spC) {
            *a0 = spC;
            sp4 = 1;
        }
    }

    return sp4;
}

f32 func_8029DD18(f32 f12, f32 f14, f32 sp10) {
    f32 sp4;

    if ((sp4 = f14 - f12) >= 0.0f) {
        if (sp4 > sp10)
            f12 += sp10;
        else 
            f12 = f14;
    }
    else {
        if (sp4 < -sp10)
            f12 -= sp10;
        else 
            f12 = f14;
    }

    return f12;
}
 
s16 approach_target_angle(s16 a0, s16 a1, s16 a2) {
    s16 sp6 = a1 - a0;

    if (sp6 >= 0) {

        if (sp6 > a2)
            a0 += a2;
        else
            a0 = a1;
    }
    else {
        if (sp6 < -a2)
            a0 -= a2;
        else
            a0 = a1;
    }

    return a0;
}

s32 func_8029DE70(s16 sp28, s16 sp2C) {
    s16 sp26;

    sp26 = (s16)gCurrentObject->oAngleYaw;
    gCurrentObject->oAngleYaw = approach_target_angle(gCurrentObject->oAngleYaw, sp28, sp2C);

    if ((gCurrentObject->oAngleVelYaw = (s16)((s16)gCurrentObject->oAngleYaw - sp26)) == 0)
        return 1;
    else
        return 0;
}

s16 func_8029DF18(struct Object *sp30, struct Object *sp34) {
    f32 sp2C, sp28, sp24, sp20;
    s16 sp1E;

    sp2C = sp30->oPosZ;
    sp24 = sp34->oPosZ;
    sp28 = sp30->oPosX;
    sp20 = sp34->oPosX;

    sp1E = atan2s(sp24 - sp2C, sp20 - sp28);

    return sp1E;
}

s16 UnknownMove(struct Object *sp40, struct Object *sp44, s16 sp4A, s16 sp4E) {

    f32 sp3C, sp38, sp34, sp30;
    UNUSED s32 sp2C;
    s16 sp2A, sp28;

    switch (sp4A) {
        case 15:
        case 18:
            sp3C = sp44->oPosX - sp40->oPosX;
            sp34 = sp44->oPosZ - sp40->oPosZ;

            sp3C = sqrtf(sp3C * sp3C + sp34 * sp34);

            sp38 = -sp40->oPosY;
            sp30 = -sp44->oPosY;    

            sp2A = atan2s(sp3C, sp30 - sp38);
            break;

        case 16:
        case 19:
            sp3C = sp40->oPosZ;
            sp34 = sp44->oPosZ;
            sp38 = sp40->oPosX;
            sp30 = sp44->oPosX;

            sp2A = atan2s(sp34 - sp3C, sp30 - sp38);
            break;
    }

    sp28 = gCurrentObject->rawData.asU32[sp4A];

    gCurrentObject->rawData.asU32[sp4A] = approach_target_angle(sp28, sp2A, sp4E);

    return sp2A;
}


void func_8029E140(struct Object *a0, s16 a1, s16 a2, s16 a3) {
    a0->oUnk138 = a1;
    a0->oUnk13C = a2;
    a0->oUnk140 = a3;
}

void func_8029E198(struct Object *a0, s16 a1, s16 a2, s16 a3) {
    a0->oPosX = a1;
    a0->oPosY = a2;
    a0->oPosZ = a3;
}

void func_8029E1F0(struct Object *a0, s16 a1, s16 a2, s16 a3) {
    a0->oFaceAnglePitch = a1;
    a0->oFaceAngleYaw = a2;
    a0->oFaceAngleRoll = a3;

    a0->oAnglePitch = a1;
    a0->oAngleYaw = a2;
    a0->oAngleRoll = a3;
}

struct Object *func_8029E230(struct Object *sp20, s16 sp26, u32 sp28, void *sp2C, s16 sp32, s16 sp36, s16 sp3A, s16 sp3E, s16 sp42, s16 sp46) {
    struct Object *sp1C = func_8029E5A4(sp20, sp26, sp28, sp2C);
    func_8029E198(sp1C, sp32, sp36, sp3A);
    func_8029E1F0(sp1C, sp3E, sp42, sp46);

    return sp1C;
}

struct Object *func_8029E2A8(struct Object *sp20, u32 sp24, void *sp28, s16 sp2E, s16 sp32, s16 sp36, s16 sp3A, s16 sp3E, UNUSED s16 sp42) {
    struct Object *sp1C = func_8029E5A4(sp20, 0, sp24, sp28);
    sp1C->oFlags |= 0x200;
    func_8029E140(sp1C, sp2E, sp32, sp36);
    func_8029E1F0(sp1C, sp3A, sp3E, sp36);

    return sp1C;
}

struct Object *Unknown8029E330(struct Object *sp20, s32 sp24, void *sp28) {
    struct Object *sp1C = SpawnObj(sp20, sp24, sp28);
    sp1C->oFlags |= 0x820;
    return sp1C;
}

struct Object *func_8029E388(struct Object *sp20, struct struct8029E388 *sp24) {
    f32 sp1C;
    struct Object *sp18 = SpawnObj(sp20, sp24->unk02, sp24->unk04);
    if (sp24->unk00 & 0x02) 
        sp18->oAngleYaw = RandomU16();

    if (sp24->unk00 & 0x40) 
        sp18->oAngleYaw = (s16)(sp18->oAngleYaw + 0x8000) + (s16)func_802A276C(sp24->unk08);

    if (sp24->unk00 & 0x80) 
        sp18->oAngleYaw = (s16)sp18->oAngleYaw + (s16)func_802A276C(sp24->unk08);
        
    if (sp24->unk00 & 0x20)
        sp18->oPosY = find_water_level(sp18->oPosX, sp18->oPosZ);

    if (sp24->unk00 & 0x04)
        func_802A28E4(sp18, sp24->unk0A);

    if (sp24->unk00 & 0x08)
        func_802A2818(sp18, sp24->unk0A);

    sp18->oForwardVel = RandomFloat() * sp24->unk10 + sp24->unk0C; 
    sp18->oVelY = RandomFloat() * sp24->unk18 + sp24->unk14; 
    sp1C = RandomFloat() * sp24->unk20 + sp24->unk1C; 
    func_8029EC88(sp18, sp1C);

    return sp18;
}

struct Object *func_8029E5A4(struct Object *sp20, UNUSED u32 sp24, u32 sp28, void *sp2C) {
    struct Object *sp1C;
    struct Object *sp18;

    sp18 = segmented_to_virtual(sp2C);
    sp1C = create_object((u32 *)sp18);

    sp1C->parentObj = sp20;
    sp1C->header.gfx.unk18 = sp20->header.gfx.unk18;
    sp1C->header.gfx.unk19 = sp20->header.gfx.unk18;

    func_8037C448((struct GraphNodeObject *) &sp1C->header.gfx, gLoadedGraphNodes[sp28], D_80385FD0, D_80385FDC);

    return sp1C;
}

struct Object *SpawnObj(struct Object *sp20, s32 sp24, void *sp28) {
    struct Object *sp1C;

    sp1C = func_8029E5A4(sp20, 0, sp24, sp28);
    CopyObjParams(sp1C, sp20);

    return sp1C;
}

struct Object *func_8029E6A8(s16 sp22, f32 sp24, void *sp28, s32 sp2C, void *sp30) {
    struct Object *sp1C;

    if (D_8035FD80.next != NULL)
    {
        sp1C = SpawnObj(sp28, sp2C, sp30);
        sp1C->oPosY = sp1C->oPosY + sp22;
        func_8029EC88(sp1C, sp24);
        return sp1C;
    }
    else {
        return NULL; 
    }
}  

struct Object *func_8029E73C(struct Object *sp20, s32 sp24, void *sp28, f32 sp2C) {
    struct Object *sp1C;

    sp1C = func_8029E5A4(sp20, 0, sp24, sp28);
    CopyObjParams(sp1C, sp20);
    func_8029EC88(sp1C, sp2C);

    return sp1C;
}

void func_8029E7A4(struct Object *sp18) {
    func_802A2188(sp18, 44, 18);
    func_802A205C(sp18, 6, 44);
}

struct Object* spawn_obj_adv(s16 sp22, s16 sp26, s16 sp2A, s16 sp2E, struct Object *sp30, s32 sp34, void *sp38) {
    struct Object *sp1C;
    
    sp1C = func_8029E5A4(sp30, 0, sp34, sp38);
    CopyObjParams(sp1C, sp30);
    func_8029E140(sp1C, sp26, sp2A, sp2E);
    func_8029E7A4(sp1C);
    sp1C->oBehParam = sp22;
    sp1C->oUnk188 = (sp22 & 0xFF) << 16;

    return sp1C;
}

struct Object *func_8029E880(s16 sp32, s16 sp36, s16 sp3A, s16 sp3E, f32 sp40, struct Object *sp44, s32 sp48, void *sp4C) {
    struct Object *sp2C;

    sp2C = spawn_obj_adv(sp32, sp36, sp3A, sp3E, sp44, sp48, sp4C);
    func_8029EC88(sp2C, sp40);

    return sp2C;
}

void Unknown8029E8F4(void) {
    gCurrentObject->oPosX += gCurrentObject->oVelX;
    gCurrentObject->oPosY += gCurrentObject->oVelY;
    gCurrentObject->oPosZ += gCurrentObject->oVelZ;
}

void func_8029E94C(struct Object *a0, struct Object *a1) {
    a0->oGraphYOffset = a1->oGraphYOffset;
}

void CopyObjParams(struct Object *sp18, struct Object *sp1C) {
    CopyObjPosition(sp18, sp1C);
    CopyObjRotation(sp18, sp1C);
}

void CopyObjPosition(struct Object *a0, struct Object *a1) {
    a0->oPosX = a1->oPosX;
    a0->oPosY = a1->oPosY;
    a0->oPosZ = a1->oPosZ;
}

void CopyObjRotation(struct Object *a0, struct Object *a1) {
    a0->oAnglePitch = a1->oAnglePitch;
    a0->oAngleYaw = a1->oAngleYaw;
    a0->oAngleRoll = a1->oAngleRoll;

    a0->oFaceAnglePitch = a1->oFaceAnglePitch;
    a0->oFaceAngleYaw = a1->oFaceAngleYaw;
    a0->oFaceAngleRoll = a1->oFaceAngleRoll;
}

void func_8029EA0C(struct Object *a0) {
    a0->header.gfx.pos[0] = a0->oPosX;
    a0->header.gfx.pos[1] = a0->oPosY;
    a0->header.gfx.pos[2] = a0->oPosZ;
}

void Unknown8029EA34(struct Object *sp20, u32 sp24) {
    u32 *sp1C;
    
    sp1C = gCurrentObject->oAnimations;
    func_8037C658(&sp20->header.gfx, sp24 + sp1C);
}

void func_8029EA84(Mat4 a0, Vec3f a1, Vec3f a2) {
    s32 sp4 = 0;
    do {
        a1[sp4] = a0[0][sp4] * a2[0] + a0[1][sp4] * a2[1] + a0[2][sp4] * a2[2];
    }
    while (++sp4 < 3);
}

void func_8029EAF8(Mat4 a0, Vec3f a1, Vec3f a2) {
    s32 sp4 = 0;
    do {
        a1[sp4] = a0[sp4][0] * a2[0] + a0[sp4][1] * a2[1] + a0[sp4][2] * a2[2];
    }
    while (++sp4 < 3);
}

void func_8029EB70(struct Object *a0) {
    float scaleX, scaleY, scaleZ;

    scaleX = a0->header.gfx.scale[0];
    scaleY = a0->header.gfx.scale[1];
    scaleZ = a0->header.gfx.scale[2];

    a0->unk21C[0][0] *= scaleX;
    a0->unk21C[0][1] *= scaleX;
    a0->unk21C[0][2] *= scaleX;

    a0->unk21C[1][0] *= scaleY;
    a0->unk21C[1][1] *= scaleY;
    a0->unk21C[1][2] *= scaleY;

    a0->unk21C[2][0] *= scaleZ;
    a0->unk21C[2][1] *= scaleZ;
    a0->unk21C[2][2] *= scaleZ;
}

void CopyObjScaling(struct Object *toObj, struct Object *fromObj) {
    toObj->header.gfx.scale[0] = fromObj->header.gfx.scale[0];
    toObj->header.gfx.scale[1] = fromObj->header.gfx.scale[1];
    toObj->header.gfx.scale[2] = fromObj->header.gfx.scale[2];
}

void ScaleXYZ(struct Object* obj, f32 xScale, f32 yScale, f32 zScale){
    obj->header.gfx.scale[0] = xScale;
    obj->header.gfx.scale[1] = yScale;
    obj->header.gfx.scale[2] = zScale;
}

void func_8029EC88(struct Object* obj, f32 scale) {
    obj->header.gfx.scale[0] = scale;
    obj->header.gfx.scale[1] = scale;
    obj->header.gfx.scale[2] = scale;
}

void ScaleObject(f32 scale) {
    gCurrentObject->header.gfx.scale[0] = scale;
    gCurrentObject->header.gfx.scale[1] = scale;
    gCurrentObject->header.gfx.scale[2] = scale;
}

void SetObjAnimation(s32 arg0) {
    u32 *sp1C = gCurrentObject->oAnimations;   
    func_8037C658(&gCurrentObject->header.gfx, sp1C + arg0);
}

void func_8029ED38(s32 arg0) {
    u32 *sp1C = gCurrentObject->oAnimations;   
    func_8037C658(&gCurrentObject->header.gfx, sp1C + arg0);
    gCurrentObject->oSoundStateID = arg0;
}

void func_8029ED98(u32 a0, f32 a1) {
    u32 *sp1C = gCurrentObject->oAnimations;  
    s32 sp18 = (s32) (a1 * 65536.0f);
    func_8037C708(&gCurrentObject->header.gfx, sp1C + a0, sp18);
    gCurrentObject->oSoundStateID = a0;    
}

void func_8029EE20(struct Object *a0, u32 *a1, u32 a2) {
    u32 *sp1C = a1;  
    a0->oAnimations = a1;
    func_8037C658(&a0->header.gfx, sp1C + a2);
    a0->oSoundStateID = a2;    
}

void Unknown8029EE84(struct Object *a0) {
    a0->header.gfx.node.flags |= 1;
    a0->oCollectable = 0;
}

void HideObject(void) {
    gCurrentObject->header.gfx.node.flags |= 1;
}

void Unknown8029EEC8(struct Object *a0) {
    a0->header.gfx.node.flags &= ~1;
    a0->oCollectable = -1;
}

void func_8029EEF0(void) {
    gCurrentObject->header.gfx.node.flags &= ~1;
}

void func_8029EF18(void) {
    gCurrentObject->header.gfx.node.flags &= ~0x10;
}

void UnHideObject(void) {
    gCurrentObject->header.gfx.node.flags |= 0x10;
}

void func_8029EF64(struct Object *MarioObj, f32 a1, f32 a2, f32 a3) {
    f32 spC = coss(MarioObj->oAngleYaw);
    f32 sp8 = sins(MarioObj->oAngleYaw);

    f32 sp4 = a3 * spC - a1 * sp8;
    f32 sp0 = a3 * sp8 + a1 * spC;

    gCurrentObject->oAngleYaw = MarioObj->oAngleYaw;
    gCurrentObject->oPosX = MarioObj->oPosX + sp0;
    gCurrentObject->oPosY = MarioObj->oPosY + a2;
    gCurrentObject->oPosZ = MarioObj->oPosZ + sp4;
}

void func_8029F05C(f32 sp18, f32 sp1C, f32 sp20) {
    func_8029EF64(gCurrentObject->parentObj, sp18, sp1C, sp20);
}

void func_8029F0A4(void) {
    HideObject();
}

void Unknown8029F0CC(void) {
    HideObject();
    gCurrentObject->oPosY = find_floor_height(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ);
    
    if (gCurrentObject->oPosY < -10000.0f) {
        func_8029F05C(0, 0, -70);
        gCurrentObject->oPosY = find_floor_height(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ);
    }
}

void func_8029F170(struct Object *a0) {
    a0->oFaceAnglePitch = a0->oAnglePitch;
    a0->oFaceAngleYaw = a0->oAngleYaw;
    a0->oFaceAngleRoll = a0->oAngleRoll;
}

u32 func_8029F198(u32 *a0) {
    u32 sp4;

    if (((*a0) >> 0x18) == 0) {
        sp4 = (*a0 >> 16) & 0xFFFF;
    } 
    else {
        sp4 = 0x08;
    }

    return sp4;
}

struct Object *func_8029F1E0(void *a0) {
    struct Object *sp1C;
    f32 sp18;

    sp1C = func_8029F270(a0, &sp18);

    return sp1C;
}

f32 func_8029F21C(void *a0) {
    struct Object *sp1C;
    f32 sp18;

    sp1C = func_8029F270(a0, &sp18);
    if (sp1C == NULL) {
        sp18 = 15000.0f;
    }

    return sp18;
}

struct Object *func_8029F270(void *a0, f32 *a1) {
    u32 *sp2C = (u32 *)segmented_to_virtual(a0);
    struct Object *sp28 = NULL;
    struct Object *sp24;
    struct ObjectNode *sp20;
    f32 sp1C = 131072.0f;
    f32 sp18;

    sp20 = &gObjectLists[func_8029F198(sp2C)];
    sp24 = (struct Object *) sp20->next;

    while (sp24 != (struct Object *)sp20) {
        if (sp24->behavior == sp2C) {
            if (sp24->active && sp24 != gCurrentObject) {
                sp18 = objects_calc_distance(gCurrentObject, sp24);
                if (sp18 < sp1C) {
                    sp28 = sp24;
                    sp1C = sp18;
                }
            }
        }
        sp24 = (struct Object *) sp24->header.next;
    }

    *a1 = sp1C;
    return sp28;
}

struct Object *get_next_unimportant_obj(void) {
    struct ObjectNode *sp4, *sp0;

    sp4 = &gObjectLists[12];
    sp0 = sp4->next;

    if (sp4 == sp0)
        sp0 = NULL;

    return (struct Object *) sp0;
}

s32 Unknown8029F3EC(void) {
    struct ObjectNode *spC, *sp8;
    s32 sp4;

    spC = &gObjectLists[12];
    sp8 = spC->next;
    sp4 = 0;

    while (spC != sp8) {
        sp4++;
        sp8 = sp8->next;
    }

    return sp4;
}

s32 func_8029F460(void *sp28) {
    u32 *sp24 = (u32 *)segmented_to_virtual(sp28);
    struct ObjectNode *sp20;
    struct Object *sp1C;
    s32 sp18;

    sp20 = &gObjectLists[func_8029F198(sp24)];
    sp1C = (struct Object *)sp20->next;
    sp18 = 0;

    while ((struct Object *)sp20 != sp1C) {
        if (sp1C->behavior == sp24) {
            sp18++;
        }

        sp1C = (struct Object *) sp1C->header.next;
    }

    return sp18;
}

struct Object *func_8029F520(void *sp28, f32 sp2C) {
    u32 *sp24 = (u32 *)segmented_to_virtual(sp28);
    struct ObjectNode *sp20;
    struct Object *sp1C;
    struct Object *sp18;
    
    sp20 = &gObjectLists[4];
    sp1C = (struct Object *)sp20->next;
    sp18 = NULL;

    while ((struct Object *)sp20 != sp1C) {
        if (sp1C->behavior == sp24) {
            if (sp1C->active) {
                if (sp1C->oHeldState) {
                    if (objects_calc_distance(gCurrentObject, sp1C) < sp2C) {
                        sp18 = sp1C;
                        break;
                    }
                }
            }
        }
        sp1C = (struct Object *) sp1C->header.next;
    }

    return sp18;
}

void func_8029F610(void) {
    gCurrentObject->oTimer = 0;
    gCurrentObject->oUnk150 = 0;
}

void func_8029F638(s32 sp24) {
    //s32 sp24 = action;
    gCurrentObject->oAction = sp24;
    gCurrentObject->oPrevAction = sp24;   
    func_8029F610();
}

void func_8029F684(f32 f12, f32 f14) {
    f32 sp4 = gMarioStates[0].forwardVel;
    f32 sp0 = f12 * f14;

    if (sp4 < sp0) {
        gCurrentObject->oForwardVel = sp0; 
    } else {
        gCurrentObject->oForwardVel = sp4 * f14; 
    }
}

void func_8029F6F0() {
    if (gCurrentObject->header.gfx.unk38.animFrame >= 0) {
        gCurrentObject->header.gfx.unk38.animFrame--;
    }
}

void func_8029F728() {
    s32 sp4 = gCurrentObject->header.gfx.unk38.animFrame;
    s32 sp0 = gCurrentObject->header.gfx.unk38.curAnim->unk08 - 2;

    if (sp4 == sp0) {
        gCurrentObject->header.gfx.unk38.animFrame--;
    }
}

s32 func_8029F788() {
    u32 spC = (s32) gCurrentObject->header.gfx.unk38.curAnim->flags;
    s32 sp8 = gCurrentObject->header.gfx.unk38.animFrame;
    s32 sp4 = gCurrentObject->header.gfx.unk38.curAnim->unk08 - 2;
    s32 sp0 = 0;

    if (spC & 0x01) {
        if (sp4 + 1 == sp8) {
            sp0 = 1;
        }
    }

    if (sp8 == sp4) {
        sp0 = 1;
    }

    return sp0;
}

s32 func_8029F828(void) {
    s32 sp4 = gCurrentObject->header.gfx.unk38.animFrame;
    s32 sp0 = gCurrentObject->header.gfx.unk38.curAnim->unk08 - 1;

    if (sp4 == sp0)
        return 1;
    else 
        return 0;
}

s32 check_anim_frame(s32 a0) {
    s32 sp4 = gCurrentObject->header.gfx.unk38.animFrame;

    if (sp4 == a0)
        return 1;
    else
        return 0;
}

s32 func_8029F8D4(s32 a0, s32 a1) {
    s32 sp4 = gCurrentObject->header.gfx.unk38.animFrame;

    if (sp4 >= a0 && sp4 < a0 + a1)
        return 1;
    else
        return 0;
}

s32 Unknown8029F930(s16 *a0) {
    s16 sp6 = gCurrentObject->header.gfx.unk38.animFrame;

    while (*a0 != -1) {
        if (*a0 == sp6) {
            return 1;
        } 

        a0++;
    } 

    return 0;
}

s32 func_8029F998(void) {
    if (gMarioStates[0].action & 0x0800)
        return 1;
    else
        return 0;
}

s32 func_8029F9D8(void) {
    if (gMarioStates[0].action == ACT_DIVE_SLIDE)
        return 1;
    else
        return 0;
}

void func_8029FA1C(f32 sp18, s32 sp1C) {
    gCurrentObject->oVelY = sp18;
    func_8029ED38(sp1C);
}

void func_8029FA5C(s32 sp18, s32 sp1C) {
    func_8029FE38();
    func_8029EEF0();

    if (sp18 >= 0)
        func_8029ED38(sp18);

    gCurrentObject->oAction = sp1C;
}

void func_8029FAB8(f32 sp18, f32 sp1C) {
    gCurrentObject->oMoveFlags = 0;
    gCurrentObject->oFloorHeight = find_floor_height(gCurrentObject->oPosX, gCurrentObject->oPosY + 160.0f, gCurrentObject->oPosZ);
    
    if (gCurrentObject->oFloorHeight > gCurrentObject->oPosY) {
        gCurrentObject->oPosY = gCurrentObject->oFloorHeight;
    }
    else {
        if (gCurrentObject->oFloorHeight < -10000.0f) {
            CopyObjPosition(gCurrentObject, gMarioObject);
            gCurrentObject->oFloorHeight = find_floor_height(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ);
        }
    }
    gCurrentObject->oForwardVel = sp18;
    gCurrentObject->oVelY = sp1C;
    if (gCurrentObject->oForwardVel != 0)
        func_802A06EC(-4.0f, -0.1f, 2.0f);
}

void func_8029FC04(f32 sp18, f32 sp1C, s32 sp20) {
    if (segmented_to_virtual(beh_bowser) == gCurrentObject->behavior) {
        func_8029F05C(-41.684f, 85.859f, 321.577f);
    }
    else { }

    func_8029FE58();
    HideObject();

    gCurrentObject->oHeldState = 0;
    if ((gCurrentObject->oUnk190 & 0x10) != 0 || sp18 == 0.0f) {
        func_8029FAB8(0.0f, 0.0f);
    }
    else {
        gCurrentObject->oAction = sp20;
        func_8029FAB8(sp18, sp1C);
    }
}

void func_8029FCF8(void) {
    func_8029FE58();
    HideObject();
    gCurrentObject->oHeldState = 0;
    func_8029FAB8(0.0f, 0.0f);
}

void SetModel(s32 a0) {
    gCurrentObject->header.gfx.asGraphNode = gLoadedGraphNodes[a0];
}

void Unknown8029FD74(s32 a0) {
    gMarioStates[0].flags |= a0;
}

s32 func_8029FD98(s32 a0) {
    if (gCurrentObject->oInteractStatus & a0) {
        gCurrentObject->oInteractStatus &= a0 ^ 0xFFFFFFFF;
        return 1;
    } 
    return 0;
}

void DeactivateObject(struct Object *a0) {
    a0->active = 0;
}

void func_8029FE00(void) {
    func_8029EEF0();
    UnHideObject();
    func_8029FE38();
}

void func_8029FE38(void) {
    gCurrentObject->oCollectable = -1;
}

void func_8029FE58(void) {
    gCurrentObject->oCollectable = 0;
}

void func_8029FE74(struct Object *a0) {
    a0->oCollectable = 0;
}

void func_8029FE88(void) {
    struct Surface *sp1C;
    gCurrentObject->oFloorHeight = find_floor(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, &sp1C);
}

struct Surface *func_8029FED0(void) {
    struct Surface *sp1C;
    gCurrentObject->oFloorHeight = find_floor(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, &sp1C);
    return sp1C;
}

void func_8029FF20(f32 *a0, f32 spC) {
    f32 sp4;

    if (*a0 != 0.0f) {
        sp4 = (*a0) * (*a0) * (spC * 0.0001L);
        
        if (*a0 > 0) {
            *a0 -= sp4;

            if (*a0 < 0.001L)
                *a0 = 0.0f;
        }
        else {
            *a0 += sp4;

            if (*a0 > -0.001L)
                *a0 = 0.0f;
        }
    }
}

void func_802A0020(f32 sp18) {
    func_8029FF20(&gCurrentObject->oVelX, sp18);
    func_8029FF20(&gCurrentObject->oVelZ, sp18);
}

s32 func_802A006C(f32 sp38, s32 sp3C) {
    struct Surface *sp34;
    f32 sp30 = gCurrentObject->oPosX + gCurrentObject->oVelX;
    f32 sp2C = gCurrentObject->oPosZ + gCurrentObject->oVelZ;
    f32 sp28 = find_floor(sp30, gCurrentObject->oPosY, sp2C, &sp34);
    f32 sp24 = sp28 - gCurrentObject->oFloorHeight;
    UNUSED f32 sp20;
    f32 sp1C;
    
    gCurrentObject->oMoveFlags &= ~0x0400;

    if (gCurrentObject->oUnk1A0 != -1) {
        if (sp34 != NULL) {
            if (sp34->room != 0 && gCurrentObject->oUnk1A0 != sp34->room && sp34->room != 18) {
                return 0;
            }
        }
    }

    if (sp28 < -10000.0f) {
        gCurrentObject->oMoveFlags |= 0x0400;
        return 0;
    } 
    else if (sp24 < 5.0f) {
        if (sp3C == 0) {
            gCurrentObject->oPosX = sp30;
            gCurrentObject->oPosZ = sp2C;
            return 1;
        }
        else if (sp24 < -50.0f && (gCurrentObject->oMoveFlags & 0x0002)) {
            gCurrentObject->oMoveFlags |= 0x0400;
            return 0;
        }
        else if (sp34->normal[1] > sp38) {
            gCurrentObject->oPosX = sp30;
            gCurrentObject->oPosZ = sp2C;
            return 1;
        } else {
            gCurrentObject->oMoveFlags |= 0x0400;
            return 0;
        }
    }
    else if (sp38 < (sp1C = sp34->normal[1]) || gCurrentObject->oPosY > sp28) {
        gCurrentObject->oPosX = sp30;
        gCurrentObject->oPosZ = sp2C;
    }

    return 0;
}

void func_802A0334(void) {
    f32 sp24 = (f32) (sqrtf(gCurrentObject->oVelY * gCurrentObject->oVelY) * (gCurrentObject->oUnk12C * 7.0f)) / 100.0L;
    
    if (gCurrentObject->oVelY > 0) {
        gCurrentObject->oVelY -= sp24;
    } 
    else {
        gCurrentObject->oVelY += sp24;
    }

    if (gCurrentObject->oPosY < gCurrentObject->oFloorHeight) {
        gCurrentObject->oPosY = gCurrentObject->oFloorHeight;
        gCurrentObject->oMoveFlags |= 0x40;
    }
    else {
        gCurrentObject->oMoveFlags |= 0x20;
    }
}

s32 func_802A0460(UNUSED f32 sp18, f32 sp1C) {
    gCurrentObject->oMoveFlags &= ~0x2000;

    if (gCurrentObject->oPosY < gCurrentObject->oFloorHeight) {
        if ((gCurrentObject->oMoveFlags & 0x02) == 0) {
            if (func_802A0974(&gCurrentObject->oMoveFlags, 1))
                gCurrentObject->oMoveFlags |= 0x02;
            else 
                gCurrentObject->oMoveFlags |= 0x01;
        }

        gCurrentObject->oPosY = gCurrentObject->oFloorHeight;

        if (gCurrentObject->oVelY < 0.0f)
            gCurrentObject->oVelY *= sp1C;

        if (gCurrentObject->oVelY > 5.0f)
            gCurrentObject->oMoveFlags |= 0x2000;
    }
    else {
        gCurrentObject->oMoveFlags &= ~0x01;    
        if (func_802A0974(&gCurrentObject->oMoveFlags, 2))
            gCurrentObject->oMoveFlags |= 0x04;
    }

    gCurrentObject->oMoveFlags &= ~0x78; 
}

f32 func_802A0608(f32 sp20, f32 sp24) {
    f32 sp1C;
    gCurrentObject->oVelY += sp20 + sp24;
    if (gCurrentObject->oVelY < -78.0f) {
        gCurrentObject->oVelY = -78.0f;
    }

    gCurrentObject->oPosY += gCurrentObject->oVelY;
    if (gCurrentObject->active & 0x0400) {
        sp1C = -11000.0f;
    }
    else {
        sp1C = find_water_level(gCurrentObject->oPosX, gCurrentObject->oPosZ);
    }

    return sp1C;
}

void func_802A06EC(f32 sp20, f32 sp24, f32 sp28) {
    f32 sp1C;

    gCurrentObject->oMoveFlags &= ~0x04;

    if (gCurrentObject->oMoveFlags & 0x10) {
        if (gCurrentObject->oVelY > 5.0f) {
            gCurrentObject->oMoveFlags &= ~0x78;
            gCurrentObject->oMoveFlags |= 0x1000;
        }
    }

    if ((gCurrentObject->oMoveFlags & 0x78) == 0) {
        sp1C = func_802A0608(sp20, 0.0f);
        if (gCurrentObject->oPosY > sp1C) {
            func_802A0460(sp20, sp24);
        }
        else {
            gCurrentObject->oMoveFlags |= 0x08;
            gCurrentObject->oMoveFlags &= ~0x03;
        }
    }
    else {
        gCurrentObject->oMoveFlags &= ~0x08;
        sp1C = func_802A0608(sp20, sp28);
        if (gCurrentObject->oPosY < sp1C) {
            func_802A0334();
        }
        else {
            if (gCurrentObject->oPosY < gCurrentObject->oFloorHeight) {
                gCurrentObject->oPosY = gCurrentObject->oFloorHeight;
                gCurrentObject->oMoveFlags &= ~0x78;
            }
            else {
                gCurrentObject->oPosY = sp1C;
                gCurrentObject->oVelY = 0.0f;
                gCurrentObject->oMoveFlags &= ~0x60;
                gCurrentObject->oMoveFlags |= 0x10;
            }
        }
    }

    if (gCurrentObject->oMoveFlags & 0x33) {
        gCurrentObject->oMoveFlags &= ~0x80;
    }
    else {
        gCurrentObject->oMoveFlags |= 0x80;
    }
}

void func_802A0964(void) { }

s32 func_802A0974(u32 *a0, s32 a1) {
    if (*a0 & a1) {
        *a0 &= a1 ^ 0xFFFFFFFF;
        return 1;
    }
    else {
        return 0;
    }
}

void Unknown802A09C0(f32 sp20, f32 sp24) {
    if (sp24 > 0.1L) {
        resolve_wall_collisions(&gCurrentObject->oPosX, &gCurrentObject->oPosY, &gCurrentObject->oPosZ, sp20, sp24);
    }
}

s16 func_802A0A2C(s16 a0, s16 a1) {
    s16 sp6 = a1 - a0;
    if (sp6 == -32768) {
        sp6 = -32767;
    }

    if (sp6 < 0) {
        sp6 = -sp6;
    }

    return sp6;
}

void func_802A0A90(void) {
    gCurrentObject->oVelX = gCurrentObject->oForwardVel * sins(gCurrentObject->oAngleYaw);
    gCurrentObject->oVelZ = gCurrentObject->oForwardVel * coss(gCurrentObject->oAngleYaw);

    gCurrentObject->oPosX += gCurrentObject->oVelX;
    gCurrentObject->oPosZ += gCurrentObject->oVelZ;
}

void func_802A0B28() {
    if (gCurrentObject->oVelY < -70.0f)
        gCurrentObject->oVelY = -70.0f;
    
    gCurrentObject->oPosY += gCurrentObject->oVelY;
}

void PreMoveObj() {
    gCurrentObject->oVelX = gCurrentObject->oForwardVel * sins(gCurrentObject->oAngleYaw);
    gCurrentObject->oVelZ = gCurrentObject->oForwardVel * coss(gCurrentObject->oAngleYaw);
}

f32 func_802A0BF4(f32 f12, f32 f14, f32 sp10, f32 sp14) {
    f32 sp4;
    if ((sp4 = f12 - f14) > 0)
        if (sp4 < sp10)
            return 0.0f;
        else
            return -sp14;
    else
        if (sp4 > -sp10)
            return 0.0f;
        else
            return sp14;
}

s32 func_802A0CA8(struct Object *obj, struct Object *marioObj) {
    s32 sp4 = 0;
    if (obj->numCollidedObjs > 0 ) {
        do {
            if (obj->collidedObjs[sp4] == marioObj) {
                return 1;
            }
        }
        while (++sp4 < obj->numCollidedObjs);
    }

    return 0;
}

void func_802A0D10(void *a0) {
    gCurrentObject->behavior = segmented_to_virtual(a0);
}

void SetObjBehavior(struct Object *obj, void *beh) {
    obj->behavior = segmented_to_virtual(beh);
}

s32 CheckObjBehavior(u32 *beh) {
    if (segmented_to_virtual(beh) == gCurrentObject->behavior)
        return 1;
    else
        return 0;
}

s32 CheckObjBehavior2(struct Object *obj, u32 *beh) {
    if (segmented_to_virtual(beh) == obj->behavior)
        return 1;
    else
        return 0;
}

f32 func_802A0E30(void) {
    f32 sp24;
    f32 sp20 = gCurrentObject->oHomeX - gMarioObject->oPosX;
    f32 sp1C = gCurrentObject->oHomeZ - gMarioObject->oPosZ;

    sp24 = sqrtf(sp20 * sp20 + sp1C * sp1C);

    return sp24;
}

f32 func_802A0EB8() {
    f32 sp24;
    f32 sp20 = gCurrentObject->oHomeX - gCurrentObject->oPosX;
    f32 sp1C = gCurrentObject->oHomeZ - gCurrentObject->oPosZ;

    sp24 = sqrtf(sp20 * sp20 + sp1C * sp1C);

    return sp24;
}

s32 Unknown802A0F30(f32 f12) {
    if (gCurrentObject->oHomeX - f12 > gCurrentObject->oPosX)
        return 1;
        
    if (gCurrentObject->oHomeX + f12 < gCurrentObject->oPosX)
        return 1;

    if (gCurrentObject->oHomeZ - f12 > gCurrentObject->oPosZ)
        return 1;
        
    if (gCurrentObject->oHomeZ + f12 < gCurrentObject->oPosZ)
        return 1; 

    return 0;
}

s32 Unknown802A0FF8(f32 f12, f32 f14, f32 sp8, f32 spC) {
    if (gCurrentObject->oHomeX + f12 > gCurrentObject->oPosX)
        return 1;
        
    if (gCurrentObject->oHomeX + f14 < gCurrentObject->oPosX)
        return 1;

    if (gCurrentObject->oHomeZ + sp8 > gCurrentObject->oPosZ)
        return 1;
        
    if (gCurrentObject->oHomeZ + spC < gCurrentObject->oPosZ)
        return 1; 

    return 0;
}

void func_802A10D0(void) {
    gCurrentObject->oPosX = gCurrentObject->oHomeX;
    gCurrentObject->oPosY = gCurrentObject->oHomeY;
    gCurrentObject->oPosZ = gCurrentObject->oHomeZ;
}

void func_802A1110(void) {
    func_802A10D0();

    gCurrentObject->oForwardVel = 0;
    gCurrentObject->oVelY = 0;
}

void func_802A1160(f32 f12) {
    if ((gCurrentObject->oTimer & 0x01) == 0) {
        gCurrentObject->oPosY += f12;
    } else {
        gCurrentObject->oPosY -= f12;
    }
}

void func_802A11B4(UNUSED s32 a0, s32 a1) {
    D_8033B1B0.unk1C[1] = (s16)a1;
    D_8032CFD0 = gCurrentObject;
}

void Unknown802A11E4(UNUSED s32 sp0, UNUSED s32 sp4, f32 sp8) {
    if (gCurrentObject->oDistanceToMario < sp8) {
        gMarioObject->oInteractStatus = 1;
    }
}

void func_802A1230(struct struct802A1230 *a0) {
    a0->unk02 |= 0x04;
}

void func_802A124C(f32 f12, f32 f14) {
    gCurrentObject->hitboxRadius = f12;
    gCurrentObject->hitboxHeight = f14;
}

void func_802A1274(f32 f12, f32 f14) {
    gCurrentObject->unk200 = f12;
    gCurrentObject->unk204 = f14;
}

void func_802A129C(struct Object *sp28, s32 sp2C, f32 sp30, void *sp34, s16 sp3A, s16 sp3E) {
    s32 sp24;
    f32 sp20;
    struct Surface *sp1C;
    struct Object *sp18;

    sp20 = find_floor(sp28->oPosX, sp28->oPosY, sp28->oPosZ, &sp1C);

    if (sp28->oPosY - sp20 > 100.0f ) {
        sp20 = sp28->oPosY;
    }

    for (sp24 = 0; sp2C > sp24; sp24++) {
        if (sp28->oUnk198 <= 0)
            break;

        sp28->oUnk198--;
        sp18 = SpawnObj(sp28, sp3E, sp34);
        func_802A28E4(sp18, sp3A);
        sp18->oPosY = sp20;
        sp18->oUnknownUnk110_F32 = sp30;
    }
}

void func_802A13B8(struct Object *sp20, s32 sp24, f32 sp28, s16 sp2E) {
    func_802A129C(sp20, sp24, sp28, beh_blue_coin_jumping, sp2E, 118);
}

void func_802A1410(struct Object *sp20, s32 sp24, f32 sp28) {
    func_802A129C(sp20, sp24, sp28, beh_single_coin_gets_spawned, 0, 116);
}

void func_802A1460(void) {
    struct Object *sp1C;
    if (gCurrentObject->oUnk198 <= 0)
        return;

    gCurrentObject->oUnk198--;
    sp1C = SpawnObj(gCurrentObject, 116, beh_single_coin_gets_spawned);
    sp1C->oVelY = 30.0f;

    CopyObjPosition(sp1C, gMarioObject);
}

f32 Unknown802A14EC(void) {
    f32 sp4 = gCurrentObject->oHomeY - gCurrentObject->oPosY;

    if (sp4 < 0)
        sp4 = -sp4;

    return sp4;
}

s32 Unknown802A1548() {
    s32 spC = gCurrentObject->header.gfx.unk38.animFrame;
    s32 sp8 = gCurrentObject->header.gfx.unk38.curAnim->unk08;
    s32 sp4;

    if (spC < 0)
        spC = 0;
    else if (sp8 - 1 == spC)
        spC = 0;
    else 
        spC++;

    sp4 = (spC << 16) / sp8;

    return sp4;
}

s32 func_802A1600(s16 sp32) {
    struct Surface *sp2C;
    f32 sp28, sp24, sp20;
    f32 sp1C;
    f32 sp18 = coss((s16)(sp32 * 182));

    if (gCurrentObject->oForwardVel != 0) {
        sp28 = gCurrentObject->oPosX + gCurrentObject->oVelX;
        sp20 = gCurrentObject->oPosZ + gCurrentObject->oVelZ;
        sp24 = find_floor(sp28, gCurrentObject->oPosY, sp20, &sp2C);
        sp1C = sp24 - gCurrentObject->oFloorHeight;

        if (sp24 < -10000.0f) {
            gCurrentObject->oUnk1B4 = gCurrentObject->oAngleYaw + 32768;
            return 2;
        } else {
            if (sp2C->normal[1] < sp18 && sp1C > 0
                    && sp24 > gCurrentObject->oPosY) {
                        gCurrentObject->oUnk1B4 = atan2s(sp2C->normal[2], sp2C->normal[0]);
                        return 1;
                    }
            else {
                return 0;
            }
        }
    }
    return 0;
}

s32 func_802A17C0(void) {
    s32 sp4C;
    struct Surface *sp48;
    struct WallCollisionData sp20;
    f32 sp1C = 10.0f;
    f32 sp18 = gCurrentObject->oUnk128;

    if (sp18 > 0.1L) {
        sp20.offsetY = sp1C;
        sp20.radius = sp18;
        sp20.x = (s16) gCurrentObject->oPosX;
        sp20.y = (s16) gCurrentObject->oPosY;
        sp20.z = (s16) gCurrentObject->oPosZ;
        sp4C = find_wall_collisions(&sp20);

        if (sp4C != 0) {
            gCurrentObject->oPosX = sp20.x;
            gCurrentObject->oPosY = sp20.y;
            gCurrentObject->oPosZ = sp20.z;
            sp48 = sp20.walls[sp20.numWalls - 1];
            gCurrentObject->oUnk1B4 = atan2s(sp48->normal[2], sp48->normal[0]);
            if (func_802A0A2C(gCurrentObject->oUnk1B4, gCurrentObject->oAngleYaw) > 0x4000)
                return 1;
            else 
                return 0;
        } 
    }

    return 0;
}

void func_802A1978() {
    struct Surface *sp1C = func_8029FED0();
    gCurrentObject->oUnk1C0 = sp1C;

    if (sp1C != NULL) {
        if (sp1C->type == 1) {
            gCurrentObject->oMoveFlags |= 0x0800;
        }
#ifdef VERSION_US
        else if (sp1C->type == 10) {
            gCurrentObject->oMoveFlags |= 0x4000;
        }
#endif
        gCurrentObject->oUnk1B8 = sp1C->type;
        gCurrentObject->oUnk1BA = sp1C->room;
    }
    else {
        gCurrentObject->oUnk1B8 = 0;
        gCurrentObject->oUnk1BA = 0;
    }
}

void func_802A1A2C(s16 sp1A) {
    gCurrentObject->oMoveFlags &= ~0x0800;
    if (gCurrentObject->active & 0x0A) {
        func_802A1978();
        gCurrentObject->oMoveFlags &= ~0x278;

        if (gCurrentObject->oPosY > gCurrentObject->oFloorHeight)
            gCurrentObject->oMoveFlags |= 0x80;
    }
    else {
        gCurrentObject->oMoveFlags &= ~0x200;
        if (func_802A17C0())
            gCurrentObject->oMoveFlags |= 0x200;

        func_802A1978();

        if (gCurrentObject->oPosY > gCurrentObject->oFloorHeight)
            gCurrentObject->oMoveFlags |= 0x80;

        if (func_802A1600(sp1A))
            gCurrentObject->oMoveFlags |= 0x200;

    }
}

void MoveRelated(void) {
    func_802A1A2C(60);
}

void MoveObj(s16 sp3A) {
    f32 sp34 = gCurrentObject->oGravity;
    f32 sp30 = gCurrentObject->oUnk158;
    f32 sp2C = gCurrentObject->oBuoyancy;
    f32 sp28 = gCurrentObject->oUnk12C;
    f32 sp24;
    s32 sp20 = 0;
    s32 sp1C = 0;

    if ((gCurrentObject->active & 0x0A) == 0) {
        if (sp3A < 0) {
            sp20 = 1;
            sp3A = -sp3A;
        }

        sp24 = coss(sp3A * 182);
        PreMoveObj();
        func_802A0020(sp28);
        func_802A006C(sp24, sp20);
        func_802A06EC(sp34, sp30, sp2C);
        if (gCurrentObject->oForwardVel < 0) 
            sp1C = 1;

        gCurrentObject->oForwardVel = sqrtf(sqr(gCurrentObject->oVelX) + sqr(gCurrentObject->oVelZ));
        if (sp1C == 1) {
            gCurrentObject->oForwardVel = -gCurrentObject->oForwardVel;
        }
    }
}

s32 func_802A1D28(void) {
    if (gCurrentObject->oPosX < -12000.0f || 12000.0f < gCurrentObject->oPosX)
        return 0;

    if (gCurrentObject->oPosY < -12000.0f || 12000.0f < gCurrentObject->oPosY)
        return 0;

    if (gCurrentObject->oPosZ < -12000.0f || 12000.0f < gCurrentObject->oPosZ)
        return 0;

    return 1;
}

void func_802A1E0C(void) {
    if (func_802A1D28()) {
        gCurrentObject->oPosX += gCurrentObject->oVelX;
        gCurrentObject->oPosZ += gCurrentObject->oVelZ;
        gCurrentObject->oVelY += gCurrentObject->oGravity;
        gCurrentObject->oPosY += gCurrentObject->oVelY;
    }
}

void MoveObj2(void) {
    PreMoveObj();
    func_802A1E0C();
}

void Unknown802A1ECC(struct Object *a0, struct Object *a1, f32 sp18, f32 sp1C, f32 sp20) {
    f32 spC = coss(a1->oAngleYaw);
    f32 sp8 = sins(a1->oAngleYaw);
    f32 sp4 = sp20 * spC - sp18 * sp8;
    f32 sp0 = sp20 * sp8 + sp18 * spC;

    a0->oAngleYaw = a1->oAngleYaw;
    a0->oPosX = a1->oPosX + sp0;
    a0->oPosY = a1->oPosY + sp1C;
    a0->oPosZ = a1->oPosZ + sp4;
}

s16 func_802A1FA0(void) {
    s16 sp26;
    f32 sp20 = gCurrentObject->oHomeX - gCurrentObject->oPosX;
    f32 sp1C = gCurrentObject->oHomeZ - gCurrentObject->oPosZ;
    
    sp26 = atan2s(sp1C, sp20);

    return sp26;   
}

void func_802A2008(struct Object *a0, struct Object *a1) {
    a0->header.gfx.pos[0] = a1->oPosX;
    a0->header.gfx.pos[1] = a1->oPosY + a1->oGraphYOffset ;
    a0->header.gfx.pos[2] = a1->oPosZ;

    a0->header.gfx.angle[0] = a1->oAnglePitch & 0xFFFF;
    a0->header.gfx.angle[1] = a1->oAngleYaw & 0xFFFF;
    a0->header.gfx.angle[2] = a1->oAngleRoll & 0xFFFF;
}

void func_802A205C(struct Object *a0, s16 a1, s16 a2) {
    f32 spC = a0->rawData.asF32[a2];
    f32 sp8 = a0->rawData.asF32[a2 + 1];
    f32 sp4 = a0->rawData.asF32[a2 + 2];

    a0->rawData.asF32[a1 + 0] += a0->unk21C[0][0] * spC + a0->unk21C[1][0] * sp8 + a0->unk21C[2][0] * sp4;
    a0->rawData.asF32[a1 + 1] += a0->unk21C[0][1] * spC + a0->unk21C[1][1] * sp8 + a0->unk21C[2][1] * sp4;
    a0->rawData.asF32[a1 + 2] += a0->unk21C[0][2] * spC + a0->unk21C[1][2] * sp8 + a0->unk21C[2][2] * sp4;
}

void func_802A2188(struct Object *sp30, s16 sp36, s16 sp3A) {
    f32 sp24[3];
    s16 sp1C[3];

    sp24[0] = sp30->rawData.asF32[sp36];
    sp24[1] = sp30->rawData.asF32[sp36 + 1];
    sp24[2] = sp30->rawData.asF32[sp36 + 2];

    sp1C[0] = sp30->rawData.asS32[sp3A];
    sp1C[1] = sp30->rawData.asS32[sp3A + 1];
    sp1C[2] = sp30->rawData.asS32[sp3A + 2];

    mtxf_rotate_zxy_and_translate(sp30->unk21C, sp24, sp1C);
}

void func_802A2270(struct Object *sp18) {
    if (sp18->oFlags & 0x20) {
        func_802A2188(sp18, 6, 18);
        func_8029EB70(sp18);
    }

    sp18->header.gfx.throwMatrix = sp18->unk21C;
    ScaleObject(1.0f);
}

void func_802A22DC(struct Object *sp20) {
    struct Object *sp1C = sp20->parentObj;

    func_802A2188(sp20, 44, 18);
    func_8029EB70(sp20);
    mtxf_mul(sp20->unk21C, sp20->unk21C, sp1C->unk21C);

    sp20->oPosX = sp20->unk21C[3][0];
    sp20->oPosY = sp20->unk21C[3][1];
    sp20->oPosZ = sp20->unk21C[3][2];

    sp20->header.gfx.throwMatrix = sp20->unk21C;
    ScaleObject(1.0f);
}

void Unknown802A2380(struct Object *a0) {
    a0->oFlags &= ~0x200;
    a0->oFlags |= 0x800;

    a0->unk21C[3][0] = a0->oPosX;
    a0->unk21C[3][1] = a0->oPosY;
    a0->unk21C[3][2] = a0->oPosZ;
}

void Unknown802A23C4(void) {
    gCurrentObject->oAnglePitch += gCurrentObject->oAngleVelPitch;
    gCurrentObject->oAngleYaw += gCurrentObject->oAngleVelYaw;
    gCurrentObject->oAngleRoll += gCurrentObject->oAngleVelRoll;
}

void BehBreakBoxTriangleLoop(void) {
    gCurrentObject->oFaceAnglePitch += gCurrentObject->oAngleVelPitch;
    gCurrentObject->oFaceAngleYaw += gCurrentObject->oAngleVelYaw;
    gCurrentObject->oFaceAngleRoll += gCurrentObject->oAngleVelRoll;
}

void Unknown802A2474(void) {
    gCurrentObject->oFaceAnglePitch = gCurrentObject->oAnglePitch;
    gCurrentObject->oFaceAngleYaw   = gCurrentObject->oAngleYaw;
    gCurrentObject->oFaceAngleRoll  = gCurrentObject->oAngleRoll;
}

s32 func_802A24B4(UNUSED s32 sp48) {
    struct Waypoint *sp44;
    struct Waypoint *sp40;
    struct Waypoint *sp3C;
    f32 sp38, sp34, sp30;
    UNUSED s32 sp2C;
    f32 sp28;
    f32 sp24, sp20, sp1C;

    if (gCurrentObject->oUnknownUnk104_S32 == 0) {
        gCurrentObject->oUnknownUnk100_VPtr = (struct Waypoint *)gCurrentObject->oUnknownUnkFC_VPtr;
        gCurrentObject->oUnknownUnk104_S32 = 0x8000;
    }

    sp44 = (struct Waypoint *)gCurrentObject->oUnknownUnkFC_VPtr;
    sp40 = (struct Waypoint *)gCurrentObject->oUnknownUnk100_VPtr;

    if (LIST_NEXT_ITEM(sp40, struct Waypoint)->flags != WAYPOINT_FLAGS_END) {
        sp3C = LIST_NEXT_ITEM(sp40, struct Waypoint);
    }
    else {
        sp3C = sp44;
    }

    gCurrentObject->oUnknownUnk104_S32 = sp40->flags | 0x8000;
    sp38 = sp3C->pos[0] - sp40->pos[0];
    sp34 = sp3C->pos[1] - sp40->pos[1];
    sp30 = sp3C->pos[2] - sp40->pos[2];

    sp24 = sp3C->pos[0] - gCurrentObject->oPosX;
    sp20 = sp3C->pos[1] - gCurrentObject->oPosY;
    sp1C = sp3C->pos[2] - gCurrentObject->oPosZ;

    sp28 = sqrtf(sqr(sp24) + sqr(sp1C));
    gCurrentObject->oUnknownUnk10C_S32 = atan2s(sp1C, sp24);
    gCurrentObject->oUnknownUnk108_S32 = atan2s(sp28, -sp20);

    if (sp38 * sp24 + sp34 * sp20 + sp30 * sp1C <= 0.0f) {
        gCurrentObject->oUnknownUnk100_VPtr = sp3C;
        if (LIST_NEXT_ITEM(sp3C, struct Waypoint)->flags == WAYPOINT_FLAGS_END) 
            return -1;
        else
            return 1;
    }

    return 0;
}

void func_802A272C(struct Struct802A272C *a0) {
    a0->vecF[0] = 0.0f;
    a0->vecF[1] = 0.0f;
    a0->vecF[2] = 0.0f;

    a0->vecS[0] = 0;
    a0->vecS[1] = 0;
    a0->vecS[2] = 0;
}

f32 func_802A276C(f32 sp18) {
    return RandomFloat() * sp18 - sp18 / 2.0f;
}

f32 func_802A27B4(struct Object *sp20, f32 sp24, f32 sp28) {
    f32 sp1C = RandomFloat() * sp24 + sp28;
    ScaleXYZ(sp20, sp1C, sp1C, sp1C);
}

void func_802A2818(struct Object *sp28, f32 sp2C) {
    sp28->oPosX += RandomFloat() * sp2C - sp2C * 0.5f;
    sp28->oPosY += RandomFloat() * sp2C - sp2C * 0.5f;
    sp28->oPosZ += RandomFloat() * sp2C - sp2C * 0.5f;
}

void func_802A28E4(struct Object *sp28, f32 sp2C) {
    sp28->oPosX += RandomFloat() * sp2C - sp2C * 0.5f;
    sp28->oPosZ += RandomFloat() * sp2C - sp2C * 0.5f;
}

void func_802A297C(struct Object *a0) {
    f32 spC = a0->oUnkC0;
    f32 sp8 = a0->oUnkBC;
    f32 sp4 = a0->oForwardVel;

    a0->oVelX = a0->unk21C[0][0] * spC + a0->unk21C[1][0] * sp8 + a0->unk21C[2][0] * sp4;
    a0->oVelY = a0->unk21C[0][1] * spC + a0->unk21C[1][1] * sp8 + a0->unk21C[2][1] * sp4;
    a0->oVelZ = a0->unk21C[0][2] * spC + a0->unk21C[1][2] * sp8 + a0->unk21C[2][2] * sp4;
}

void func_802A2A38() {
    func_802A2188(gCurrentObject, 44, 15);
    func_802A297C(gCurrentObject);
    gCurrentObject->oPosX += gCurrentObject->oVelX;
    gCurrentObject->oPosY += gCurrentObject->oVelY;
    gCurrentObject->oPosZ += gCurrentObject->oVelZ;
}

s16 func_802A2AC0(void) {
    s16 sp6 = gCurrentObject->oUnk1B4 - ((s16)gCurrentObject->oAngleYaw - (s16)gCurrentObject->oUnk1B4) + 32768;
    return sp6;
}

struct Struct802A2B04 {
    s8 unk0;
    s8 unk1;
    u8 unk2;
    s8 unk3;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s8 unk8;
    s8 unk9;
    f32 unkC;
    f32 unk10;
};

void func_802A2B04(struct Struct802A2B04 *sp28) {
    struct Object *sp24;
    s32 sp20;
    f32 sp1C;
    s32 sp18 = sp28->unk1; // TODO: pass in proper struct

    if (gPostUpdateObjCount >= 0x97 && sp18 >= 0x0b)
        sp18 = 10;

    if (gPostUpdateObjCount >= 0xd3)
        sp18 = 0;

    for (sp20 = 0; sp18 > sp20; sp20++) {
        sp1C = RandomFloat() * (sp28->unk10 * 0.1f) + sp28->unkC * 0.1f;
        sp24 = SpawnObj(gCurrentObject, sp28->unk2, beh_white_puff_explosion);
        sp24->oBehParam = sp28->unk0;
        sp24->oAngleYaw = RandomU16();
        sp24->oGravity = sp28->unk8;
        sp24->oUnk12C = sp28->unk9;
        sp24->oPosY += sp28->unk3;
        sp24->oForwardVel = RandomFloat() * sp28->unk5 + sp28->unk4;
        sp24->oVelY = RandomFloat() * sp28->unk7 + sp28->unk6;
        ScaleXYZ(sp24, sp1C, sp1C, sp1C);
    }
}

void func_802A2CFC(struct Object *sp18, struct Struct802A2CFC *sp1C) {
    if ((sp18->oFlags & 0x40000000) == 0) {
        sp18->oFlags |= 0x40000000;
        sp18->oInteractType = sp1C->unk0;
        sp18->oUnk180 = sp1C->unk5;
        sp18->oUnk184 = sp1C->unk6;
        sp18->oUnk198 = sp1C->unk7;
        func_8029FE58();
    }

    sp18->hitboxRadius = sp18->header.gfx.scale[0] * sp1C->unk8;
    sp18->hitboxHeight = sp18->header.gfx.scale[1] * sp1C->unkA;
    sp18->unk200 = sp18->header.gfx.scale[0] * sp1C->unkC;
    sp18->unk204 = sp18->header.gfx.scale[1] * sp1C->unkE;
    sp18->unk208 = sp18->header.gfx.scale[1] * sp1C->unk4;
}   

s32 func_802A2E5C(s32 a0) {
    if (a0 >= 0)
        return 1;
    else 
        return -1;
}

f32 func_802A2E8C(f32 f12) {
    if (f12 >= 0)
        return f12;
    else
        return -f12;
}

s32 func_802A2ECC(s32 a0) {
    if (a0 >= 0)
        return a0;
    else
        return -a0;
}

s32 func_802A2EFC(s32 a0, s32 a1) {
    s32 sp4 = 0;
    s32 sp0;

    if (gCurrentObject->oTimer >= a0) {
        if ((sp0 = gCurrentObject->oTimer - a0) & 1) {
            gCurrentObject->header.gfx.node.flags |= 0x10;
            if (a1 < sp0 / 2) {
                sp4 = 1;
            }
        } 
        else {
            gCurrentObject->header.gfx.node.flags &= ~0x10;
        }
    }

    return sp4;
}

s32 IsMarioGroundPounding(void) {
    if (gMarioObject->platform == gCurrentObject)
        if (gMarioStates[0].action == ACT_GROUND_POUND_LAND)
            return 1;

    return 0;
}

void func_802A3004(void) {
    func_802AA618(0, 0, 46.0f);
}

void func_802A3034(s32 sp18) {
    func_802AA618(0, 0, 46.0f);
    create_sound_spawner(sp18);   
}

void func_802A3070(f32 sp28) {
    f32 sp24 = gMarioObject->oPosX - gCurrentObject->oPosX;
    f32 sp20 = gMarioObject->oPosZ - gCurrentObject->oPosZ;
    f32 sp1C = sqrtf(sqr(sp24) + sqr(sp20));
    
    if (sp1C < sp28) {
        gMarioStates[0].pos[0] += (sp28 - sp1C) / sp28 * sp24;
        gMarioStates[0].pos[2] += (sp28 - sp1C) / sp28 * sp20;
    }
}

void func_802A3164(f32 sp20, f32 sp24) {
    f32 sp1C = gMarioObject->oPosY - gCurrentObject->oPosY;

    if (sp1C < 0) 
        sp1C = -sp1C;

    if (sp1C < sp24)
        func_802A3070(sp20);
}

void BehDustSmokeLoop(void) {
    gCurrentObject->oPosX += gCurrentObject->oVelX;
    gCurrentObject->oPosY += gCurrentObject->oVelY;    
    gCurrentObject->oPosZ += gCurrentObject->oVelZ;   

    if (gCurrentObject->oUnknownUnkF4_S32 == 10)
        DeactivateObject(gCurrentObject);

    gCurrentObject->oUnknownUnkF4_S32++;
}

void func_802A3294(void) { }

s32 func_802A32A4(s8 *a0) {
    gCurrentObject->oUnk1AC = a0;
    gCurrentObject->oUnk1B0 = 0;

    return *(s8 *)gCurrentObject->oUnk1AC;
}

s32 func_802A32E0(void) {
    s8 spF;
    s8 *sp8 = gCurrentObject->oUnk1AC;
    s32 sp4 = gCurrentObject->oUnk1B0 + 1;

    if (sp8[sp4] != -1) {
        spF = sp8[sp4];
        gCurrentObject->oUnk1B0++;
    }
    else {
        spF = sp8[0];
        gCurrentObject->oUnk1B0 = 0;
    }

    return spF;
}

void Unknown802A3380(UNUSED s32 sp0, UNUSED s32 sp4) { }

void func_802A3398(s32 a0, s32 a1, f32 sp10, f32 sp14) {
    f32 sp4 = sp14 - sp10;
    f32 sp0 = (f32)gCurrentObject->oTimer / a1;

    if (a0 & 0x01)
        gCurrentObject->header.gfx.scale[0] = sp4 * sp0 + sp10;
    
    if (a0 & 0x02)
        gCurrentObject->header.gfx.scale[1] = sp4 * sp0 + sp10;

    if (a0 & 0x04)
        gCurrentObject->header.gfx.scale[2] = sp4 * sp0 + sp10;
}

void func_802A3470(void) {
    gCurrentObject->oPosX = gCurrentObject->oHomeX + gDebugInfo[5][0];
    gCurrentObject->oPosY = gCurrentObject->oHomeY + gDebugInfo[5][1];
    gCurrentObject->oPosZ = gCurrentObject->oHomeZ + gDebugInfo[5][2];
    ScaleObject(gDebugInfo[5][3] / 100.0f + 1.0l);
}

void func_802A3544(void) { }

s32 IsMarioStepping(void) {
    if (gMarioObject->platform == gCurrentObject)
        return 1;
    else
        return 0;
}

s32 Unknown802A3598(s32 a0, s32 a1) {
    if (gCurrentObject->oTimer & 1) 
        gCurrentObject->oPosY -= a1;
    else 
        gCurrentObject->oPosY += a1;

    if (gCurrentObject->oTimer == a0 * 2)
        return 1;
    else 
        return 0;
}

s32 func_802A362C(s32 a0) {
    if (a0 >= 4 || a0 < 0)
        return 1;
    
    gCurrentObject->oPosY += D_8032F0A0[a0];
    return 0;
}

s32 func_802A3688(void (*sp20[])(void)) {
    void (*sp1C)(void) = sp20[gCurrentObject->oAction];
    sp1C();
}

struct Object *func_802A36D8(s32 sp20, s32 sp24) {
    struct Object *sp1C = SpawnObj(gCurrentObject, 122, beh_unused_080C);
    sp1C->oUnk1B0 = sp24;
    sp1C->oUnk188 = gCurrentObject->oUnk188;
    sp1C->oBehParam = sp20;

    return sp1C;
}

void Unknown802A3750(void) {
    func_802A36D8(0, 0);
}

s16 func_802A377C(s32 a0) {
    return D_8032F0A4[a0];
}

s32 func_802A37A0(void) {
    f32 sp24 = gCurrentObject->oHomeX - gMarioObject->oPosX;
    f32 sp20 = gCurrentObject->oHomeY - gMarioObject->oPosY;
    f32 sp1C = gCurrentObject->oHomeZ - gMarioObject->oPosZ;
    f32 sp18 = sqrtf(sqr(sp24) + sqr(sp20) + sqr(sp1C));

    if (gCurrentObject->oDistanceToMario > 2000.0f
        && sp18 > 2000.0f) 
        return 1;
    else 
        return 0;
}

s32 func_802A38A4(s32 a0) {
    if (gMarioStates[0].forwardVel > a0)
        return 1;

    if (gMarioStates[0].action & 0x0800)
        return 1;
    else
        return 0; 
}

s32 func_802A3910(s8 a0, s8 *a1) {
    while (*a1 != -1) {
        if (*a1 == a0)
            return 1;

        a1++;
    }

    return 0;
}

void func_802A3968(void) { }

void BehCommonInit(void) {
    struct Surface *sp1C;
    f32 sp18;

    if (func_802A3910(gCurrLevelNum, D_8032F0B4)) {
        sp18 = find_floor(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, &sp1C);
        
        if (sp1C) {
            if (sp1C->room != 0) {
                gCurrentObject->oUnk1A0 = sp1C->room;
            } else {
                find_floor(gCurrentObject->oPosX, sp18 - 100.0f, gCurrentObject->oPosZ, &sp1C);

                if (sp1C) {
                    gCurrentObject->oUnk1A0 = sp1C->room;
                }
            }
        }
    }
        else {
            gCurrentObject->oUnk1A0 = -1;
        }
}

void func_802A3A68(void) {
    register s32 s0;

    if (gCurrentObject->oUnk1A0 != -1 && D_8035FEE0) {
        if (D_8035FEE0 == gCurrentObject->oUnk1A0)
            s0 = 1;
        else if (D_8035FE68[D_8035FEE0][0] == gCurrentObject->oUnk1A0)
            s0 = 1;
        else if (D_8035FE68[D_8035FEE0][1] == gCurrentObject->oUnk1A0) 
            s0 = 1;
        else 
            s0 = 0;

        if (s0) {
            HideObject();
            gCurrentObject->active &= ~0x08;
            D_8035FEEE++;
        }
        else {
            func_8029EEF0();
            gCurrentObject->active |= 0x08;
            D_8035FEF0++;
        }
    }
}

s32 func_802A3BB8(struct Struct802A2CFC *sp20, s32 sp24, s32 sp28) {
    s32 sp1C = 0;

    func_802A2CFC(gCurrentObject, sp20);
    
    if (sp28) 
        gCurrentObject->oUnk198 = 0;

    if (gCurrentObject->oInteractStatus & 0x8000) {
        if (gCurrentObject->oInteractStatus & 0x4000) {
            func_802A3004();
            func_802A1410(gCurrentObject, gCurrentObject->oUnk198, 20.0f);
            DeactivateObject(gCurrentObject);
            create_sound_spawner(sp24);
        }
        else {
            sp1C = 1;
        }

    }
    
    gCurrentObject->oInteractStatus = 0;

    return sp1C;
}

void func_802A3C98(f32 sp18, s32 sp1C) {
    func_802AA618(0, 0, sp18);
    func_802AD82C(30, 138, 3.0f, 4);
    DeactivateObject(gCurrentObject);

    if (sp1C == 1)
        func_802A1410(gCurrentObject, gCurrentObject->oUnk198, 20.0f);
    else if (sp1C == 2)
        func_802A13B8(gCurrentObject, gCurrentObject->oUnk198, 20.0f, 150);
}

void func_802A3D4C(struct Object *sp18, void *sp1C) {
    sp18->collisionData = segmented_to_virtual(sp1C);
}

void func_802A3D84(void) {
    if (gCurrentObject->oMoveFlags & 0x200)
        gCurrentObject->oAngleYaw = gCurrentObject->oUnk1B4;
}

s32 func_802A3DBC(f32 sp18) {
    if (sp18 > func_802A2E8C(gCurrentObject->oPosY - gMarioObject->oPosY)) {
        func_8029EF18();
        return 0;
    } else {
        UnHideObject();
        return 1;
    }
}

s32 Geo18_802A45E4(s32 a0, struct GraphNode *node, UNUSED void *a3) {
    if (a0 == 1) {
        // TODO: what is the right type?
        ((struct GraphNode_802A45E4*)node->next)->unk18 = 300;
        ((struct GraphNode_802A45E4*)node->next)->unk1A = 300;
        ((struct GraphNode_802A45E4*)node->next)->unk1C = 0;
    }

    return 0;
}

s32 Unknown802A3E84(s32 a0, struct GraphNode *a1, UNUSED s32 sp8) {
    if (a0 == 1) {
        ((struct GraphNode_802A45E4*)a1->next)->unk18 = gDebugInfo[4][0];
        ((struct GraphNode_802A45E4*)a1->next)->unk1A = gDebugInfo[4][1];
        ((struct GraphNode_802A45E4*)a1->next)->unk1C = gDebugInfo[4][2];
        ((struct GraphNode_802A45E4*)a1->next)->unk1E = gDebugInfo[4][3];
        ((struct GraphNode_802A45E4*)a1->next)->unk20 = gDebugInfo[4][4];
        ((struct GraphNode_802A45E4*)a1->next)->unk22 = gDebugInfo[4][5];
    }

    return 0;
}

s32 func_802A3F24(struct Object *a0) {
    if (a0->header.gfx.node.flags & 0x10)
        return 1;
    else 
        return 0;
}

void func_802A3F5C(void) {
    gTimeStopState |= 0x02;
}

void func_802A3F80(void) {
    gTimeStopState &= ~0x02;
}

void func_802A3FA8(s32 a0) {
    gTimeStopState |= a0;
}

void func_802A3FCC(s32 a0) {
    gTimeStopState = gTimeStopState & (a0 ^ -1);
}

s32 func_802A3FF8(f32 sp20, f32 sp24, UNUSED s32 sp28) {
    f32 sp1C;
    UNUSED s16 sp1A;

    if (gCurrentObject->oDistanceToMario < 1500.0f) {
        sp1C = DistanceFromObject(gCurrentObject, gMarioObject);
        sp1A = func_8029DF18(gMarioObject, gCurrentObject);

        if (sp1C < sp20 && gCurrentObject->oPosY < gMarioObject->oPosY + 160.0f
            && gMarioObject->oPosY < gCurrentObject->oPosY + sp24) {
            if ((gMarioStates[0].action & 0x0800) == 0) {
                if (func_80257330())
                    return 1;
            }
        }
    }

    return 0;
}

void func_802A4114(f32 sp18, f32 sp1C) {
    func_802A3FF8(sp18, sp1C, 0x1000);
    return;
}

void func_802A4154(s32 sp18, s32 sp1C) {
    gCurrentObject->oUnk90 = sp1C;
    gCurrentObject->oUnk92++;

    if ((sp18 & 0x10) == 0)
        func_802573C8(0);
}

s32 func_802A41B8(s32 sp20, s32 sp24, s32 sp28, UNUSED s32 sp2C) {
    s32 sp1C = 0;
    UNUSED s32 sp18 = 1;

    switch (gCurrentObject->oUnk92) {
#ifdef VERSION_US
        case 0:
            if (func_80257330() || gMarioState->action == ACT_UNKNOWN_106) {
                gTimeStopState |= 2;
                gCurrentObject->active |= 0x20;
                gCurrentObject->oUnk92++;
            }
            else
                break;
            // fallthrough to case 1

#else
        case 0:
            if (gMarioState->health >= 0x0100) {
                gTimeStopState |= 2;
                gCurrentObject->active |= 0x20;
                gCurrentObject->oUnk92++;
            }
            break;

#endif
        case 1:
            if (func_802573C8(sp20) == 2)
                gCurrentObject->oUnk92++;
            break;

        case 2:
            if (sp24 & 0x04)
                func_802D8050(sp28);
            else if (sp24 & 0x02)
                func_802D7F90(sp28);
            gCurrentObject->oUnk92++;
            break;

        case 3:
            if (sp24 & 0x04) {
                if (D_80330440 != 0) 
                    func_802A4154(sp24, D_80330440);
            }
            else if (sp24 & 0x02) {
                if (get_dialog_id() == -1)
                    func_802A4154(sp24, 3);
            } 
            else {
                func_802A4154(sp24, 3);
            }
            break;

        case 4:
            if (gMarioState->action != ACT_UNKNOWN_106
                || (sp24 & 0x10) ) {
                gTimeStopState &= ~0x02;
                gCurrentObject->active &= ~0x20;
                sp1C = gCurrentObject->oUnk90;
                gCurrentObject->oUnk92 = 0;
            }
            break;

        default:
            gCurrentObject->oUnk92 = 0;
            break;
    }

    return sp1C;
}

s32 CreateMessageBox(s32 sp30, s32 sp34, s32 sp38, s32 sp3C) {
    s32 sp2C = 0;
    s32 sp28 = 1;

    switch (gCurrentObject->oUnk92) {
#ifdef VERSION_US
        case 0:
            if (func_80257330() || gMarioState->action == ACT_UNKNOWN_106) {
                gTimeStopState |= 2;
                gCurrentObject->active |= 0x20;
                gCurrentObject->oUnk92++;
                gCurrentObject->oUnk90 = 0;
            }
            else
                break;
#else
        case 0:
            if (gMarioState->health >= 0x0100) {
                gTimeStopState |= 2;
                gCurrentObject->active |= 0x20;
                gCurrentObject->oUnk92++;
                gCurrentObject->oUnk90 = 0;
            }
            break;

#endif
        case 1:
            if (sp34 & 0x01) {
                sp28 = func_8029DE70(func_8029DF18(gCurrentObject, gMarioObject), 0x800);
                if (gCurrentObject->oUnk90 >= 0x21)
                    sp28 = 1;
            }
            
            if (func_802573C8(sp30) == 2 && sp28) {
                gCurrentObject->oUnk90 = 0;
                gCurrentObject->oUnk92++;
            }
            else {
                gCurrentObject->oUnk90++;
            }

            break;

        case 2:
            if (sp38 == 161) {
                if ((gCurrentObject->oUnk90 = func_8028F9A4(sp38, gCurrentObject)))
                    gCurrentObject->oUnk92++;
            }
            else {
                if ((gCurrentObject->oUnk90 = func_8028F8E0(sp38, gCurrentObject, sp3C)))
                    gCurrentObject->oUnk92++;
            }
            break;

        case 3:
            if (sp34 & 0x10) {
                sp2C = gCurrentObject->oUnk90;
                gCurrentObject->oUnk92 = 0;
            }
            else if (gMarioState->action != ACT_UNKNOWN_106) {
                gTimeStopState &= ~0x02;
                gCurrentObject->active &= ~0x20;
                sp2C = gCurrentObject->oUnk90;
                gCurrentObject->oUnk92 = 0;
            }
            else {
                func_802573C8(0);
            }
            break;
    }

    return sp2C;
}

s32 func_802A472C(u16 a0) {
    if (gLoadedGraphNodes[a0] == gCurrentObject->header.gfx.asGraphNode)
        return 1;
    else
        return 0;
}

void func_802A4780(void) {
    struct Surface *sp34;
    Vec3f sp28;
    Vec3f sp1C;

    sp1C[0] = gCurrentObject->oPosX;
    sp1C[1] = gCurrentObject->oPosY;
    sp1C[2] = gCurrentObject->oPosZ;

    find_floor(sp1C[0], sp1C[1], sp1C[2], &sp34);
    if (sp34) {
        sp28[0] = sp34->normal[0];
        sp28[1] = sp34->normal[1];
        sp28[2] = sp34->normal[2];

        mtxf_from_up_direction(gCurrentObject->unk21C, sp28, sp1C, gCurrentObject->oFaceAngleYaw);
        gCurrentObject->header.gfx.throwMatrix = gCurrentObject->unk21C;
    }
}

s32 Unknown802A485C(s16 a0, s16 a1, s16 a2, s16 a3) {
    if (gMarioObject->oPosX < a0 || a1 < gMarioObject->oPosX)
        return 0;

    if (gMarioObject->oPosZ < a2 || a3 < gMarioObject->oPosZ)
        return 0;

    return 1;
}

s32 ShakeScreen(s32 sp18) {
    func_8027F440(sp18, gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ);
}

s32 func_802A4964(struct Object *a0) {
    s32 spC;
    struct Object *sp8;
    s32 sp4 = 0;
    
    spC = a0->numCollidedObjs;
    if (spC != 0) {
        sp8 = a0->collidedObjs[0];

        if (sp8 != gMarioObject) {
            sp8->oInteractStatus |= 0x0080C001;
            sp4 = 1;
        }
    }

    return sp4;
}

s32 func_802A49D4(void) {
    s32 sp1C = 0;

    if ((gCurrentObject->oInteractStatus & 0x8000)
        && (gCurrentObject->oInteractStatus & 0x4000))
        sp1C = 1;
    
    if (IsMarioGroundPounding())
        sp1C = 1;

    gCurrentObject->oInteractStatus = 0;

    return sp1C;
}

void func_802A4A50(struct Object *dstObj, struct Object *srcObj) {
    dstObj->oUnk188 = srcObj->oUnk188;
    dstObj->oBehParam = srcObj->oBehParam;
}

void func_802A4A70(s32 sp18, s32 sp1C) {
    func_8029ED38(sp18);
    gCurrentObject->header.gfx.unk38.animFrame = sp1C;

}

void func_802A4AB0(s32 sp18) {
    func_8029ED38(sp18);
    func_8029F788();
    return;
}

void func_802A4AEC(s32 sp18) {
    func_8029ED38(sp18);
    func_8029F728();
}

s32 func_802A4B20(void) {
    if (gCurrentObject->oInteractStatus & 0x0800) {
        gCurrentObject->oUnk88 = 1;
        func_8029FE38();
        return 1;
    }
    
    return 0;
}

s32 func_802A4B80(void) {
    s32 sp4 = 0;

    if (gPlayer1Controller->stickMag < 30.0f)
        D_8035FF00 = 0;

    if (D_8035FF00 == 0) {
        if (gPlayer1Controller->stickMag > 40.0f) {
            D_8035FF00 = 1;
            sp4 = 1;
        }
    }

    if (gPlayer1Controller->buttonPressed & A_BUTTON)
        sp4 = 1;

    return sp4;
}

void Unknown802A4C34(s32 sp18, s32 sp1C, s32 sp20) {
    if (check_anim_frame(sp18) || check_anim_frame(sp1C)) 
        PlaySound2(sp20);
}

void Unknown802A4C88(void) {
    gTimeStopState |= 0x0A;
    gCurrentObject->active |= 0x20;
}

void func_802A4CC0(void) {
    gTimeStopState &= ~0x0A;
    gCurrentObject->active &= ~0x20;
}

s32 func_802A4D00(void) {
    if (gCurrentObject->oInteractStatus & 0x8000) {
        gCurrentObject->oInteractStatus = 0;
        return 1;
    }
    else {
        return 0;
    }
}

void func_802A4D4C(void) {
    if (gCurrentObject->oUnk198 >= 5) {
        SpawnObj(gCurrentObject, 118, beh_mr_i_blue_coin);
        gCurrentObject->oUnk198 -= 5;
    }
}

#ifdef VERSION_US
void func_u_802A5588(float f12, float f14, float a2, float a3) {
    float sp1C = gCurrentObject->oPosY;
    gCurrentObject->oPosY += a3 + gDebugInfo[5][0];
    CreateStar(f12, f14, a2);
    gCurrentObject->oPosY = sp1C;
}
#endif
