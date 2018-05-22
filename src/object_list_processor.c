#include <ultra64.h>
#include "libultra.h"

#include "sm64.h"
#include "behavior_data.h"
#include "behavior_script.h"
#include "camera.h"
#include "graph_node.h"
#include "mario.h"
#include "map_info.h"
#include "memory.h"
#include "level_functions.h"
#include "level_update.h"
#include "object_collision.h"
#include "platform_displacement.h"
#include "resource_meter.h"
#include "spawn_object.h"
#include "surface_collision.h"

struct SEF60 {
  u32 unk0;
  u32 unk4;
  u8 unk8;
  u8 unk9;
  u16 unkA;
  void *unkC;
};

extern f64 D_80336600, D_80336608;

extern struct Object D_8033C18C[];
extern s8 D_8035FE68[][2];

static s8 D_8032EF60[] = { 0x0B, 0x09, 0x0A, 0x00, 0x05, 0x04, 0x02, 0x06, 0x08, 0x0C, -1 };

extern struct GfxNode D_8033B870;
extern struct GfxNode *D_8035FD78;

static struct SEF60 D_8032EF6C[] = {
    { 0x00000001, 0x00000001, 0x8E, 0x00, 0x0000, beh_mario_dust_generator              },
    { 0x00000002, 0x00040000, 0x00, 0x00, 0x0000, beh_wall_tiny_star_particle_spawn     },
    { 0x00000010, 0x00000010, 0x00, 0x00, 0x0000, beh_pound_tiny_star_particle_spawn    },
    { 0x00000008, 0x00000008, 0x95, 0x00, 0x0000, beh_special_triple_jump_sparkles      },
    { 0x00000020, 0x00000020, 0xA8, 0x00, 0x0000, beh_bubble_mario                      },
    { 0x00000040, 0x00000040, 0xA7, 0x00, 0x0000, beh_water_splash                      },
    { 0x00000080, 0x00000080, 0xA6, 0x00, 0x0000, beh_surface_waves                     },
    { 0x00000200, 0x00000200, 0xA4, 0x00, 0x0000, beh_water_waves                       },
    { 0x00000400, 0x00000400, 0xA3, 0x00, 0x0000, beh_wave_trail_on_surface             },
    { 0x00000800, 0x00000800, 0x90, 0x00, 0x0000, beh_flame_mario                       },
    { 0x00000100, 0x00000100, 0x00, 0x00, 0x0000, beh_waves_generator                   },
    { 0x00001000, 0x00001000, 0x00, 0x00, 0x0000, beh_surface_wave_shrinking            },
    { 0x00002000, 0x00002000, 0x00, 0x00, 0x0000, beh_snow_leaf_particle_spawn          },
    { 0x00004000, 0x00010000, 0x00, 0x00, 0x0000, beh_ground_snow                       },
    { 0x00020000, 0x00020000, 0x00, 0x00, 0x0000, beh_water_mist_spawn                  },
    { 0x00008000, 0x00004000, 0x00, 0x00, 0x0000, beh_ground_sand                       },
    { 0x00010000, 0x00008000, 0x00, 0x00, 0x0000, beh_pound_white_puffs                 },
    { 0x00040000, 0x00080000, 0x00, 0x00, 0x0000, beh_punch_tiny_triangle_spawn         },
    { 0x00000000, 0x00000000, 0x00, 0x00, 0x0000, NULL                                  },
};

void func_8029C6D8(struct Object *, u8);

void func_8029BFF0() { }

void func_8029C000(void) {
    s32 i = 0;
    if (gCurrentObject != gMarioObject)
        i += 1;

    gCurrentObject->vel[0] = gMarioStates[i].vel[0];
    gCurrentObject->vel[1] = gMarioStates[i].vel[1];
    gCurrentObject->vel[2] = gMarioStates[i].vel[2];

    gCurrentObject->pos[0] = gMarioStates[i].pos[0];
    gCurrentObject->pos[1] = gMarioStates[i].pos[1];
    gCurrentObject->pos[2] = gMarioStates[i].pos[2];

    gCurrentObject->angle[0] = gCurrentObject->gfx.unk1A[0];
    gCurrentObject->angle[1] = gCurrentObject->gfx.unk1A[1];
    gCurrentObject->angle[2] = gCurrentObject->gfx.unk1A[2];

    gCurrentObject->faceAngle[0] = gCurrentObject->gfx.unk1A[0];
    gCurrentObject->faceAngle[1] = gCurrentObject->gfx.unk1A[1];
    gCurrentObject->faceAngle[2] = gCurrentObject->gfx.unk1A[2];

    gCurrentObject->platformRotation[0] = gMarioStates[i].angleVel[0];
    gCurrentObject->platformRotation[1] = gMarioStates[i].angleVel[1];
    gCurrentObject->platformRotation[2] = gMarioStates[i].angleVel[2];
}

void func_8029C24C(u32 flags, s16 seg, void *scriptAddr) {
    if (!(gCurrentObject->unkE0 & flags)) {
        struct Object *obj;
        gCurrentObject->unkE0 |= flags;
        obj = func_8029E5A4(gCurrentObject, 0, seg, (u32)scriptAddr);
        CopyObjParams(obj, gCurrentObject);
    }
}

void BehMarioLoop2(void) {
    u32 flags = 0; 
    s32 i;

    flags = func_80254604(gCurrentObject);
    gCurrentObject->unkF4 = flags;
    func_8029C000();

    i = 0;
    while (D_8032EF6C[i].unk0 != 0) {
        if (D_8032EF6C[i].unk0 & flags) {
            func_8029C24C(D_8032EF6C[i].unk4, D_8032EF6C[i].unk8, D_8032EF6C[i].unkC);
        }
        i++;
    }
}

u32 func_8029C3B4(struct GfxNode *end, struct GfxNode *obj) {
    u32 count = 0;
    while (end != obj) {
        gCurrentObject = (struct Object *) obj;

        gCurrentObject->gfx.graphFlags |= 0x0020;
        cur_object_exec_behavior();

        obj = obj->prev;
        count += 1;
    }
    return count;
}

u32 func_8029C448(struct GfxNode *end, struct GfxNode *obj) {
    s32 count = 0; // 1C
    s32 executeBehavior; // 18

    while (end !=  obj) {
        gCurrentObject = (struct Object *) obj;

        executeBehavior = FALSE;
        if ((D_8033C110 & 0x10) == 0) { 
            if (gCurrentObject == gMarioObject && (D_8033C110 & 0x08) == 0)
                executeBehavior = TRUE;
            
            if ((gCurrentObject->interactType & 0x804) != 0 && (D_8033C110 & 0x08) == 0)
                executeBehavior = TRUE;

            if ((gCurrentObject->active & 0x30) != 0)
                executeBehavior = TRUE;
        }

        if (executeBehavior) {
            gCurrentObject->gfx.graphFlags |= 0x20;
            cur_object_exec_behavior();
        }
        else {
            gCurrentObject->gfx.graphFlags &= ~0x20;
        }

        obj = obj->prev;

        count++;
    }

    return count;
}

u32 func_8029C5A8(struct GfxNode *head) {
    s32 count;
    struct GfxNode *nextObj = head->prev;
    if (!(D_8033C110 & 0x00000040))
        count = func_8029C3B4(head, nextObj);
    else
        count = func_8029C448(head, nextObj);

    return count;
}

u32 func_8029C618(struct GfxNode *head) { // sp20
    struct GfxNode *nextObj = head->prev; // sp1C

    while (head != nextObj) {
        gCurrentObject = (struct Object *) nextObj;

        nextObj = nextObj->prev;

        if ((gCurrentObject->active & 0x01) != 1) {
            if ((gCurrentObject->objFlags & 0x4000) == 0)
                func_8029C6D8(gCurrentObject, 0xFF);

            func_802C9088(gCurrentObject);
        }
    }

    return 0;
}

void func_8029C6D8(struct Object *a0, u8 a1) {  
    s32 *spC;
    u16 *sp8;

    switch(a0->unk1F6) {
    case 1:
        spC = a0->unk25C;
        *spC |= a1 << 8; 
        break;
    case 2:
        sp8 = a0->unk25C;
        *sp8 |= a1 << 8; 
        break;
    }
}

void func_8029C75C(UNUSED s32 sp28, s32 sp2C) {
    struct GfxNode *sp24, *sp20, *sp1C;
    s32 sp18;
    D_8035FD78 = &D_8033B870;
    
    for (sp18 = 0; sp18 < 13; sp18++) {
        sp1C = D_8035FD78 + sp18;
        sp20 = sp1C->prev;

        while (sp20 != sp1C) {
            sp24 = sp20;
            sp20 = sp20->prev;
            if (sp24->unk19 == sp2C)
                func_802C9088((struct Object *) sp24);
        }
    }
}

void func_8029C830(UNUSED s32 sp28, struct Struct8037C51C *sp2C) {
    struct Object *sp24;
    UNUSED s32 sp20;
    void *sp1C;
    UNUSED s16 sp1A;

    D_8035FD78 = &D_8033B870;
    D_8033C110 = 0;

    D_8035FEF2 = 0;
    D_8035FEF4 = 0;

    if (D_8033A75A == 2) 
        D_8035FEEC |= 1;

    while (sp2C)
    {
        sp1A = (s16)(sp2C->unk10 & 0xFFFF);
        sp1C = segmented_to_virtual(sp2C->unk14);

        if ((sp2C->unk10 & 0xff00) != 65280)
        {
            sp24 = func_802C9424(sp1C);
 
            sp24->unk188 = sp2C->unk10;
            sp24->behParam = ((sp2C->unk10) >> 16) & 0xff;
            sp24->behavior = sp1C;
            sp24->unk1C8 = 0;
            sp24->unk1F6 = 1;
            sp24->unk25C = &sp2C->unk10; 

            if (sp2C->unk10 & 0x01) {
                gMarioObject = sp24;
                func_8037C138((struct GraphNode *) sp24);
            }

            func_8037C51C((struct GraphNode018 *) sp24, sp2C);
            
            sp24->pos[0] = sp2C->posX;
            sp24->pos[1] = sp2C->posY;
            sp24->pos[2] = sp2C->posZ;
            sp24->faceAngle[0] = sp2C->angle[0];
            sp24->faceAngle[1] = sp2C->angle[1];
            sp24->faceAngle[2] = sp2C->angle[2];
            sp24->angle[0] = sp2C->angle[0];
            sp24->angle[1] = sp2C->angle[1];
            sp24->angle[2] = sp2C->angle[2];

        }
        
        sp2C = sp2C->next;
    }
}

void func_8029CA50() { }

void func_8029CA60(void) { 
    s32 sp1C;

    D_8035FEE6 = 0;
    D_8033C110 = 0;
    gMarioObject = NULL;
    D_8035FEE0 = 0;

    sp1C = 0;
    do {
        D_8035FE68[sp1C][0] = 0;
        D_8035FE68[sp1C][1] = 0;
    }
    while (++sp1C < 0x3c);

    func_802CA0CC();
    func_802C8ED8();
    func_802C8F5C(&D_8033B870);
    func_80385BF0();
    func_8029CA50();
    sp1C = 0;

    do {
        D_8033C18C[sp1C].gfx.unk00 = 0;
        func_8037C3D0((struct GraphNode018 *) &D_8033C118[sp1C]);
    } 
    while (++sp1C < 0xf0);

    D_8035FE0C = func_802785E8(0x800, 0);
    D_8035FD78 = &D_8033B870; 
    func_803835A4();
}

void func_8029CB9C() {
    D_8033BF00 = func_8029C5A8(D_8035FD78 + 0x0B);
    D_8033BF00 = func_8029C5A8(D_8035FD78 + 0x09);
} 


void func_8029CBEC(void) {
    UNUSED s32 sp2C; 
    s32 sp28;
    s32 sp24 = 2;

    while ((sp28 = D_8032EF60[sp24]) != -1) {
        D_8033BF00 += func_8029C5A8(&D_8035FD78[sp28]);
        sp24 += 1;
    }
}

void func_8029CCA0(void) {
    UNUSED s32 sp24; 
    s32 sp20;
    s32 sp1C = 0;

    while ((sp20 = D_8032EF60[sp1C]) != -1) {
        func_8029C618(&D_8035FD78[sp20]);
        sp1C += 1;
    }

    D_8033C110 &= ~0x01;
}

u16 func_8029CD48(s64 *sp40, s32 sp44) {
    u16 sp3E;
    f64 sp30;

    sp30 = func_80324374((sp40 + sp44)[0] - (sp40 + sp44)[-1]);

    if (sp30 < 0)
        sp30 = 0;
    
    sp3E = (u16)(func_80324374(func_80324208(sp30) * 0x000F4240U / osClockRate) / D_80336600 * D_80336608);

    if (sp3E >= 0x3e8) 
        sp3E = 999;
    
    return sp3E;
}

void func_8029CF08(UNUSED s32 sp108) {
    s64 sp18[30];

    sp18[0] = func_802C98D0();

    D_8033C110 &= ~0x0020;

    D_8035FEEE = 0;
    D_8035FEF0 = 0;
    D_8035FE10 = 0;

    func_802CA140();
    func_802CA5D0();
    
    D_8035FD78 = &D_8033B870;
    
    sp18[1] = func_802C9900(sp18[0]);
    func_803835A4();
    sp18[2] = func_802C9900(sp18[0]);
    func_8029CB9C();
    apply_mario_platform_displacement();
    sp18[3] = func_802C9900(sp18[0]);
    func_802C8C44();
    sp18[4] = func_802C9900(sp18[0]);
    func_8029CBEC();
    sp18[5] = func_802C9900(sp18[0]);
    func_8029CCA0();
    sp18[6] = func_802C9900(sp18[0]);
    update_mario_platform();
    sp18[7] = func_802C9900(sp18[0]);  

    sp18[0] = 0;
    func_802CA5E0();

    if (D_8033C110 & 0x02)
        D_8033C110 |= 0x40;
    else 
        D_8033C110 &= ~0x40;
    
    D_8035FDF8 = D_8033BF00;
}
