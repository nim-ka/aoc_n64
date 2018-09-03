#include <ultra64.h>

#include "sm64.h"
#include "game_over_2.h"
#include "mario_head_1.h"
#include "mario_head_2.h"
#include "../mario_head_4.h"
#include "../mario_head_5.h"
#include "../mario_head_6.h"

// FIXME: replace these with the Obj structs in gd_types.h

struct Struct80181D14_2;

struct Struct80181D14_4
{
    u8 filler0[0x1C];
    struct Links *unk1C;
};

struct Struct801BAAF0_4
{
    u8 filler0[0x1C];
    struct Struct80181D14_2 *unk1C;
    struct Struct80181D14_2 *unk20;
    float unk24;
    u32 unk28;
};

struct Struct8019BC18
{
    u8 filler0[0x1C];
    struct Struct80181D14_2 *unk1C;
    struct Struct80181D14_2 *unk20;
    float unk24;
    u32 unk28;
};

struct Struct801BAAF0_5
{
    u8 filler0[0x1C];
    void *unk1C;
    void *unk20;
};

struct Struct80182778_2
{
    u8 filler0[0x20];
    s32 unk20;
    u8 filler24[4];
    float unk28;
};

struct Struct80181D14_2
{
    u8 filler0[0xC];
    u32 unkC;
    u8 filler10[0x20-0x10];
    float unk20;
    float unk24;
    float unk28;
    u8 filler2C[0x38-0x2C];
    float unk38;
    float unk3C;
    float unk40;
    u8 filler44[0x54-0x44];
    u32 unk54;
};

struct Struct80182A08_4
{
    u8 filler0[0x12];
    u16 unk12;
    u8 filler14[0x20-0x14];
    float unk20;
    float unk24;
    float unk28;
    u8 filler2C[0x38-0x2C];
    struct MyVec3f unk38;
    u8 filler44[0x54-0x44];
    u32 unk54;
    u8 filler58[4];
    s32 unk5C;
};

struct Struct80181D14_6
{
    u8 filler0[0x12];
    u16 unk12;
    u8 filler14[0x20-0x14];
    float unk20;
    float unk24;
    float unk28;
    u8 filler2C[4];
    float unk30;
    u8 filler34[4];
    struct MyVec3f unk38;
    u8 filler44[0x54-0x44];
    u32 unk54;
    u8 filler58[4];
    s32 unk5C;
};

struct Struct80181D14
{
    u8 filler0[0x12];
    u16 unk12;
    u8 filler14[0x1C-0x14];
    s32 unk1C;
    float unk20;
    float unk24;
    float unk28;
    u8 filler2C[4];
    s32 unk30;
    struct Struct80181D14_2 *unk34[1];  // What is going on here? This has to be more than 1 element
    float unk38;
    float unk3C;
    float unk40;
    u8 filler44[0x54-0x44];
    u32 unk54;
    u8 filler58[4];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    u8 filler68[4];
    struct ObjGroup *unk6C;
    u8 filler70[4];
    s32 unk74;
    u8 filler78[4];
    struct Struct80182778_2 *unk7C;
    struct Struct80181D14_3 *unk80;
    u8 filler84[0xB0-0x84];
    s32 unkB0;
    u8 fillerB4[8];
    void *unkBC;
};

struct Struct80181D14_3
{
    u8 filler0[0x3C];
    u32 unk3C;
    u8 filler40[0x74-0x40];
    float unk74;
    float unk78;
    float unk7C;
};

struct Struct801BAAF0
{
    u8 filler0[0x3C];
    s32 unk3C;
    u8 filler40[0x1A8-0x40];
    struct Struct801BAAF0_5 *unk1A8;
    u8 filler1AC[0x1C0-0x1AC];
    struct Struct80181D14_4 *unk1C0;
    u8 filler1C4[4];
    void *unk1C8;
    void *unk1CC;
};

struct Struct80182C84_2
{
    u8 filler0[0x30];
    void *unk30;
};

struct Struct80182C84
{
    u8 filler0[0x18C];
    struct Struct80182C84_2 *unk18C;
};

static struct Struct80181D14 *D_801B9EF0;

struct Struct8019BC18 *func_801825FC(struct Struct80181D14_2 *, struct Struct80181D14_2 *);
extern float func_80194B98(struct MyVec3f *);

void func_80181C00(struct Struct80181D14_2 *a, struct Struct80181D14_2 *b)
{
    struct ObjHeader *sp2C;
    register struct Links *link;

    if (a == b)
        return;
    link = gGdSkinNet->unk1C0->link1C;
    while (link != NULL)
    {
        // FIXME: types
        struct Struct801BAAF0_4 *sp24 = (void *)link->obj;

        if ((sp24->unk1C == a || sp24->unk1C == b)
         && (sp24->unk20 == a || sp24->unk20 == b))
            break;
        link = link->next;
    }
    if (link == NULL)
    {
        // FIXME: types
        sp2C = (void *)func_801825FC(a, b);
        addto_group(gGdSkinNet->unk1C0, sp2C);
    }
}

void Unknown80181D14(struct Struct80181D14 *a)
{
    int sp24;
    int sp20;
    struct Struct80181D14_2 *sp1C;
    struct Struct80181D14_2 *sp18;

    for (sp24 = 0; sp24 < a->unk30 - 1; sp24++)
    {
        sp1C = a->unk34[sp24];
        sp18 = a->unk34[sp24 + 1];
        func_80181C00(sp1C, sp18);
    }
    if (D_801B9EF0 != NULL)
    {
        for (sp24 = 0; sp24 < a->unk30; sp24++)
        {
            sp1C = a->unk34[sp24];
            for (sp20 = 0; sp20 < D_801B9EF0->unk30; sp20++)
            {
                sp18 = D_801B9EF0->unk34[sp20];
                func_80181C00(sp1C, sp18);
            }
        }
    }
    D_801B9EF0 = a;
}

void func_80181EB0(struct Struct801BAAF0_4 *a)
{
    struct MyVec3f sp34;
    UNUSED u8 unused[0x2C];
    struct Struct80181D14_2 *sp4 = a->unk1C;
    struct Struct80181D14_2 *sp0 = a->unk20;

    sp34.x = 0.0f;
    sp34.y = sp4->unk24 - sp0->unk24;
    sp34.z = 0.0f;
    sp34.y *= 0.01;
    sp4->unk38 -= sp34.x;
    sp4->unk3C -= sp34.y;
    sp4->unk40 -= sp34.z;
    sp0->unk38 += sp34.x;
    sp0->unk3C += sp34.y;
    sp0->unk40 += sp34.z;
    if (!(sp4->unk54 & 2))
    {
        sp4->unk20 -= sp34.x;
        sp4->unk24 -= sp34.y;
        sp4->unk28 -= sp34.z;
    }
    if (!(sp0->unk54 & 2))
    {
        sp0->unk20 += sp34.x;
        sp0->unk24 += sp34.y;
        sp0->unk28 += sp34.z;
    }
}

void func_80182088(struct Struct801BAAF0_4 *a)
{
    struct MyVec3f sp4C;
    UNUSED u8 unused[0x24];
    float sp24;
    float sp20;
    struct Struct80181D14_2 *sp1C;
    struct Struct80181D14_2 *sp18;

    if (a->unk28 & 1)
    {
        func_80181EB0(a);
        return;
    }
    sp1C = a->unk1C;
    sp18 = a->unk20;
    sp4C.x = sp1C->unk20 - sp18->unk20;
    sp4C.y = sp1C->unk24 - sp18->unk24;
    sp4C.z = sp1C->unk28 - sp18->unk28;
    sp20 = func_80194B98(&sp4C);
    sp24 = sp20 - a->unk24;
    sp4C.x /= sp20;
    sp4C.y /= sp20;
    sp4C.z /= sp20;
    sp4C.x *= sp24 * 0.1;
    sp4C.y *= sp24 * 0.1;
    sp4C.z *= sp24 * 0.1;
    sp1C->unk38 -= sp4C.x;
    sp1C->unk3C -= sp4C.y;
    sp1C->unk40 -= sp4C.z;
    sp18->unk38 += sp4C.x;
    sp18->unk3C += sp4C.y;
    sp18->unk40 += sp4C.z;
    if (!(sp1C->unk54 & 2))
    {
        sp1C->unk20 -= sp4C.x;
        sp1C->unk24 -= sp4C.y;
        sp1C->unk28 -= sp4C.z;
    }
    if (!(sp18->unk54 & 2))
    {
        sp18->unk20 += sp4C.x;
        sp18->unk24 += sp4C.y;
        sp18->unk28 += sp4C.z;
    }
}

extern void Unknown80182C84(struct Struct80181D14 *);

void func_801823A0(struct ObjNet *a)
{
    register struct Links *link;
    struct Struct801BAAF0_4 *sp28;

    gGdSkinNet = a;
    switch (a->unk3C)
    {
    case 1:
        // FIXME: types
        a->unk1C8 = ((struct Struct801BAAF0_5 *)a->unk1A8)->unk20;
        a->unk1C0 = make_group(0);
        D_801B9EF0 = NULL;
        // FIXME: types
        apply_to_obj_types_in_group(128, Unknown80181D14, ((struct Struct801BAAF0_5 *)a->unk1A8)->unk1C);
        a->unk3C = 2;
        break;
    case 2:
        link = ((struct Struct80181D14_4 *)a->unk1C0)->unk1C;
        while (link != NULL)
        {
            // FIXME: types
            sp28 = (void *)link->obj;
            func_80182088(sp28);
            link = link->next;
        }
        apply_to_obj_types_in_group(8, Unknown80182C84, a->unk1C8);
        apply_to_obj_types_in_group(64, reset_plane, a->unk1CC);
        break;
    }
}

struct ObjParticle *make_particle(u32 a, int b, float c, float d, float e)
{
    struct ObjParticle *sp2C = (struct ObjParticle *)make_object(OBJ_TYPE_PARTICLES);
    UNUSED u8 unused[8];

    sp2C->unk20 = c;
    sp2C->unk24 = d;
    sp2C->unk28 = e;
    sp2C->unk38 = sp2C->unk3C = sp2C->unk40 = 0.0f;
    sp2C->unk58 = b;
    sp2C->unk54 = a | 8;
    sp2C->unk5C = -1;
    sp2C->id = D_801B9E40;
    sp2C->unk1C = 0;
    sp2C->unkB0 = 1;
    return sp2C;
}

struct Struct8019BC18 *func_801825FC(struct Struct80181D14_2 *a, struct Struct80181D14_2 *b)
{
    struct Struct8019BC18 *sp34 = func_8019BC18(44);
    struct MyVec3f sp28;
    struct MyVec3f sp1C;

    if (sp34 == NULL)
        myPrint1("Cant allocate connection memory!");
    sp34->unk1C = a;
    sp34->unk20 = b;
    func_80183910();
    func_80186B44(a);
    func_80188A3C(&sp28);
    func_80186B44(b);
    func_80188A3C(&sp1C);
    sp28.x -= sp1C.x;
    sp28.y -= sp1C.y;
    sp28.z -= sp1C.z;
    sp34->unk24 = func_80194B98(&sp28);
    //! Duplicate conditional. Maybe this should've been `if (a->unkC == 8 && b->unkC == 8)`
    if (a->unkC == 8 && a->unkC == 8)
    {
        if ((a->unk54 & 4) && (b->unk54 & 4))
            sp34->unk28 |= 1;
    }
    func_80183940();
    return sp34;
}

extern s32 D_801A81D4[];
extern s32 D_801A8238[];

int func_80182778(struct Struct80181D14 *a)
{
    int sp4 = 0;

    if (a->unk7C->unk20 == 2 && a->unk74 == 1)
    {
        while (D_801A81D4[sp4] != 0)
        {
            if (D_801A81D4[sp4] == a->unk7C->unk28)
            {
                a->unk20 = D_801A81D4[sp4 + 1] * 10.0f;
                a->unk24 = D_801A81D4[sp4 + 2] * 10.0f;
                a->unk28 = D_801A81D4[sp4 + 3] * 10.0f;
                return TRUE;
            }
            sp4 += 4;
        }
    }
    if (a->unk7C->unk20 == 1 && a->unk74 == 1)
    {
        while (D_801A8238[sp4] != 0)
        {
            if (D_801A8238[sp4] == a->unk7C->unk28)
            {
                a->unk20 = D_801A8238[sp4 + 1] * 10.0f;
                a->unk24 = D_801A8238[sp4 + 2] * 10.0f;
                a->unk28 = D_801A8238[sp4 + 3] * 10.0f;
                return TRUE;
            }
            sp4 += 4;
        }
    }
    return FALSE;
}

void func_80182A08(struct Struct80181D14 *a, struct MyVec3f *b)
{
    register struct Links *link;
    struct Struct80182A08_4 *sp20;

    if (a->unk6C != NULL)
    {
        link = a->unk6C->link1C;
        while (link != NULL)
        {
            // FIXME: types
            sp20 = (void *)link->obj;
            if (sp20->unk5C <= 0)
            {
                sp20->unk20 = a->unk20;
                sp20->unk24 = a->unk24;
                sp20->unk28 = a->unk28;
                sp20->unk5C = 12.0f - func_8018D560() * 5.0f;
                do
                {
                    sp20->unk38.x = func_8018D560() * 50.0 - 25.0;
                    sp20->unk38.y = func_8018D560() * 50.0 - 25.0;
                    sp20->unk38.z = func_8018D560() * 50.0 - 25.0;
                } while (func_80194B98(&sp20->unk38) > 30.0);
                sp20->unk38.x += b->x;
                sp20->unk38.y += b->y;
                sp20->unk38.z += b->z;
                sp20->unk12 &= ~2;
                sp20->unk54 |= 8;
            }
            link = link->next;
        }
    }
}

void func_801838D0(struct Struct80181D14 *);

void Unknown80182C84(struct Struct80181D14 *a)
{
    float sp7C;
    UNUSED u8 unused2[12];
    struct MyVec3f sp64;
    struct ObjParticle *sp60;
    UNUSED u8 unused1[4];
    int sp58;
    UNUSED u8 unused4[4];
    UNUSED u8 unused5[4];
    struct Struct80182C84 *sp4C;
    struct MyVec3f sp40;
    struct MyVec3f sp34;

    if (a->unk54 & 2)
        return;
    if (!(a->unk54 & 8))
        return;
    if (a->unk60 == 3)
    {
        sp40.x = -D_801A80F8->unkE8[2][0] * 50.0f;
        sp40.y = -D_801A80F8->unkE8[2][1] * 50.0f;
        sp40.z = D_801A80F8->unkE8[2][2] * 50.0f;
        sp34.x = D_801A80F8->unkE8[2][0] * -20.0f;
        sp34.y = D_801A80F8->unkE8[2][1] * -20.0f;
        sp34.z = D_801A80F8->unkE8[2][2] * -20.0f;
    }
    if (a->unkBC != NULL)
    {
        func_80186B44(a->unkBC);
        if (a->unk60 == 3)
        {
            if (a->unk64 == 3)
            {
                sp4C = a->unkBC;
                if (sp4C->unk18C->unk30 != NULL)
                {
                    func_80186B44(sp4C->unk18C->unk30);
                    a->unk54 |= 0x20;
                    ;  // needed to match
                }
                else
                {
                    a->unk54 &= ~0x10;
                    a->unk54 &= ~0x20;
                }
            }
        }
        func_80188A3C(&sp64);
        a->unk20 = sp64.x;
        a->unk24 = sp64.y;
        a->unk28 = sp64.z;
    }
    sp7C = -0.4f;
    a->unk20 += a->unk38;
    a->unk24 += a->unk3C;
    a->unk28 += a->unk40;
    if (a->unk54 & 1)
        a->unk3C += sp7C;
    func_801838D0(a);
    if (a->unkB0 == 1)
    {
        if (0)
        {
        }
        a->unkB0 = 2;
        if (a->unk60 == 3)
        {
            switch (a->unk64)
            {
            case 1:
                a->unk6C = make_group(0);
                for (sp58 = 0; sp58 < 50; sp58++)
                {
                    sp60 = make_particle(1, -1, a->unk20, a->unk24, a->unk28);
                    sp60->unk1C = (void*) a->unk1C;
                    addto_group(a->unk6C, &sp60->header);
                    sp60->unk54 &= ~8;
                }
                break;
            case 2:
            case 3:
                a->unk6C = make_group(0);
                for (sp58 = 0; sp58 < 30; sp58++)
                {
                    sp60 = make_particle(1, -1, a->unk20, a->unk24, a->unk28);
                    sp60->unk1C = (void*) a->unk1C;
                    addto_group(a->unk6C, &sp60->header);
                    sp60->unk54 &= ~8;
                }
                break;
            }
        }
    }
    else if (0)
    {
    }
    a->unk38 *= 0.9;
    a->unk3C *= 0.9;
    a->unk40 *= 0.9;
    if (a->unk60 == 3)
    {
        switch (a->unk64)
        {
        case 1:
            if (func_80182778(a) && a->unk6C != NULL)
            {
                register struct Links *link;

                if (a->unk80 != NULL)
                {
                    a->unk80->unk3C |= 1;
                    a->unk80->unk74 = a->unk20;
                    a->unk80->unk78 = a->unk24;
                    a->unk80->unk7C = a->unk28;
                }
                link = a->unk6C->link1C;
                while (link != NULL)
                {
                    // FIXME: types
                    struct Struct80181D14_6 *sp2C = (void *)link->obj;

                    sp2C->unk20 = a->unk20;
                    sp2C->unk24 = a->unk24;
                    sp2C->unk28 = a->unk28;
                    sp2C->unk5C = 20;
                    do
                    {
                        sp2C->unk38.x = func_8018D560() * 64.0 - 32.0;
                        sp2C->unk38.y = func_8018D560() * 64.0 - 32.0;
                        sp2C->unk38.z = func_8018D560() * 64.0 - 32.0;
                    } while (func_80194B98(&sp2C->unk38) > 32.0);
                    sp2C->unk30 = func_8018D560() * 180.0f;
                    sp2C->unk12 &= ~2;
                    sp2C->unk54 |= 8;
                    link = link->next;
                }
            }
            break;
        case 3:
            if ((a->unk54 & 0x20) && !(a->unk54 & 0x10))
            {
                func_80182A08(a, &sp40);
                a->unk54 |= 0x10;
            }
            break;
        case 2:
            func_80182A08(a, &sp34);
            break;
        }
        apply_to_obj_types_in_group(8, Unknown80182C84, a->unk6C);
    }
    if (a->unk5C >= 0)
    {
        if (a->unk5C-- <= 0)
        {
            a->unk12 |= 2;
            a->unk54 &= ~8;
        }
    }
}

void func_80183570(void *a)
{
    start_timer("particles");
    gGdSkinNet = NULL;
    apply_to_obj_types_in_group(8, Unknown80182C84, a);
    func_8018CF48("particles");
}

struct Struct801835C8_3
{
    u8 filler0[0x20];
    float unk20;
    float unk24;
    float unk28;
};

struct Struct801835C8_2
{
    u8 filler0[0x1C];
    struct Links *unk1C;
    u8 filler20[8];
    s32 unk28;
};

struct Struct801835C8
{
    u8 filler0[0x20];
    float unk20;
    float unk24;
    float unk28;
    u8 filler2C[0xB4-0x2C];
    struct Struct801835C8_2 *unkB4;
};

#define ABS(x) ((x) < 0.0f ? -(x) : (x))

void Unknown801835C8(struct Struct801835C8 *a)
{
    struct MyVec3f sp54;
    float sp50;
    register struct Links *link;

    printf("p(%d)=", a->unkB4->unk28);
    link = a->unkB4->unk1C;
    while (link != NULL)
    {
        // FIXME: types
        struct Struct801835C8_3 *sp48 = (void *)link->obj;

        sp54.x = sp48->unk20 - a->unk20;
        sp54.y = sp48->unk24 - a->unk24;
        sp54.z = sp48->unk28 - a->unk28;
        sp50 = 150.0f - (ABS(sp54.x) + ABS(sp54.y) + ABS(sp54.z));
        printf(",%f ", sp50);
        sp50 *= 0.00000005;
        a->unk20 += sp50 * sp54.x;
        a->unk24 += sp50 * sp54.y;
        a->unk28 += sp50 * sp54.z;
        sp48->unk20 -= sp50 * sp54.x;
        sp48->unk24 -= sp50 * sp54.y;
        sp48->unk28 -= sp50 * sp54.z;
        link = link->next;
    }
    printf("\n");
}

void Unknown80183870(UNUSED int a)
{
}

void Unknown80183884(UNUSED int a)
{
}

void Unknown80183898(UNUSED int a, UNUSED int b, UNUSED int c)
{
}

void Unknown801838B4(UNUSED int a, UNUSED int b, UNUSED int c)
{
}

void func_801838D0(struct Struct80181D14 *a)
{
    D_801B9E3C = a;
    if (a->unk24 < -15.0f)
    {
    }
}
