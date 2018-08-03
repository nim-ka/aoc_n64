#include <ultra64.h>

#include "sm64.h"
#include "behavior_data.h"
#include "behavior_script.h"
#include "debug.h"
#include "mario.h"
#include "math_util.h"
#include "memory.h"
#include "object_helpers.h"
#include "rendering_graph_node.h"
#include "spawn_object.h"
#include "surface_collision.h"

extern s16 D_8033BF10[][8];
extern const char D_80336610[];

// These can be static:
extern void func_8029D704(Mat4, Mat4, Mat4);
extern void func_8029EA0C(struct Object *);

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

struct struct8029D924_2 *Geo18_8029D924(s32 sp40, struct struct8029D924 *sp44, UNUSED s32 sp48) {
    struct struct8029D924_2 *sp3C, *sp38;
    struct Object *sp34;
    struct struct8029D924 *sp30;
    UNUSED struct struct8029D924 *sp2C;
    s32 sp28;
    struct struct8029D924_2 *sp24, *sp20, *sp1C, *sp18;

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
 
            if (sp30->unk18 == 10)
            {
                if (D_8033BF10[5][3]) {
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
                print_debug_top_down_objectinfo(D_80336610, sp20->room);

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

u32 func_8029DF18(struct Object *sp30, struct Object *sp34) {
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
