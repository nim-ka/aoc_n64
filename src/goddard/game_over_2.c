#include <ultra64.h>

#include "sm64.h"
#include "gd_main.h"
#include "game_over_2.h"
#include "mario_head_1.h"
#include "../mario_head_4.h"
#include "../mario_head_5.h"
#include "half_6.h"
#include "../mario_head_6.h"

struct Struct801781DC_6
{
    u8 filler0[0x20];
    struct MyVec3f unk20;
    float unk2C;
    float unk30;
    float unk34;
};

struct Struct801781DC_5
{
    u8 filler0[0x24];
    Vec3f unk24;
};

struct Struct801781DC_4
{
    u8 unk0[0x30];
    struct Struct801781DC_6 *unk30;
    struct Struct801781DC_5 *unk34;
    u8 filler38[0x5C-0x38];
    float unk5C;
    float unk60;
    float unk64;
    u8 filler68[0x74-0x68];
    Vec3f unk74;
};

struct Struct801781DC_3
{
    u8 filler0[0x4];
    struct Struct801781DC_3 *unk4;
    struct Struct801781DC_4 *unk8;
};

struct Struct801781DC_2
{
    u8 filler0[0x1C];
    struct Struct801781DC_3 *unk1C;
};

struct Struct801781DC
{
    u8 filler0[0x30];
    struct Struct801781DC_2 *unk30;
};

struct UnknownGameOverStruct5
{
    u8 filler0[0x5C];
    s32 unk5C;
};

struct UnknownGameOverStruct6
{
    u8 filler0[0x20];
    float unk20;
    float unk24;
    float unk28;
    u8 unk2C[0x40-0x2C];  // unknown type
    float unk40;
    float unk44;
    float unk48;
};

struct UnknownGameOverStruct4
{
    u8 filler0[0x24];
    u8 unk24[0x30-0x24];  // unknown type
    s32 unk30;
    struct UnknownGameOverStruct6 *unk34[4];
    s32 unk44;
    struct UnknownGameOverStruct5 *unk48;
};

struct UnknownGameOverStruct1
{
    u8 filler0[0x30];
    float unk30;
    float unk34;
    float unk38;
};

struct UnknownGameOverStruct2
{
    u8 filler0[0x1C];
    s32 unk1C;
    u8 filler20[0x2C-0x20];
    void *unk2C;
    u8 filler30[0x44-0x30];
    s32 unk44;
    s32 unk48[2];
    s32 unk50;
    u8 filler54[4];
    float unk58;
};

struct Struct80178900_2
{
    u8 filler0[0x14];
    void *unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

struct Struct80178900
{
    u8 filler0[0x12];
    u16 unk12;
    float unk14;
    float unk18;
    float unk1C;
    char *unk20;
    u8 filler24[4];
    struct Struct80178900_2 *unk28;
    s32 unk2C;
    s32 unk30;
    u8 filler34[0x38-0x34];
    float unk38;
    u8 filler3C[0x40-0x3C];
    s32 unk40;
    u8 filler44[0x50-0x44];
    s32 unk50;
    u8 filler54[0x8];
    struct MyVec3f unk5C;
    u8 filler68[0x74-0x68];
    float unk74;
    float unk78;
    float unk7C;
    struct MyVec3f unk80;
    u8 filler8C[0x9C-0x8C];
    struct UnknownGameOverStruct2 *unk9C;
    u8 fillerA0[0x168-0xA0];
    struct UnknownGameOverStruct1 unk168;
    u8 filler[0x1A8-(0x168+sizeof(struct UnknownGameOverStruct1))];
    struct UnknownGameOverStruct2 *unk1A8;
    u8 filler1AC[0x1C8-0x1AC];
    s32 unk1C8;
};

static u8 sUnused[0x88];
struct Struct801781DC_2 *D_801B9BB8;  // assumed type

static u8 sUnused0[0x40];
static s32 D_801B9C00;
static s32 D_801B9C04;
static s16 D_801B9C08[100];
static s32 D_801B9CD0;
static float D_801B9CD4;
static struct Struct8017B514 *D_801B9CD8;

static struct {
    // This needs to be within a struct, otherwise unk4 would become 8-byte
    // aligned. The struct might be larger, it's hard to say.
    u8 filler0[4];
    struct UnknownGameOverStruct9 *unk4;
} D_801B9CE0;

static s32 D_801B9CE8;
static s32 D_801B9CEC;
static s32 D_801B9CF0;
static s32 D_801B9CF4;
static struct Struct801B9CF8 *D_801B9CF8;
static struct MyVec3f D_801B9D00;
static struct MyVec3f D_801B9D10;
static struct MyVec3f D_801B9D20[8];
static s32 D_801B9D80;
static struct MyVec3f D_801B9D88;

extern void *D_801A80F4;

void func_80178140(void)
{
    func_801A033C(2);
    gd_setproperty(12, 0.5f, 0.5f, 0.5f);
    gd_setproperty(16, 1.0f, 0.0f, 0.0f);
    return;

    //! dead code
    gd_setproperty(17, 2.0f, 0.0f, 0.0f);
    gd_setproperty(22, 24.0f, 0.0f, 0.0f);
    gd_setproperty(16, 1.0f, 0.0f, 0.0f);
    return;
}

void func_80179B64(struct ObjGroup*);

void Unknown801781DC(struct Struct801781DC *a)
{
    struct MyVec3f sp3C;

    struct Struct801781DC_4 *sp38;
    float sp34;
    float sp30;
    float sp2C;
    struct Struct801781DC_4 *sp28;
    register struct Struct801781DC_3 *s0 = a->unk30->unk1C;
    struct Struct801781DC_4 *sp20;

    while (s0 != NULL)
    {
        sp20 = s0->unk8;
        sp28 = D_801B9BB8->unk1C->unk8;
        sp3C.x = sp28->unk74[0];
        sp3C.y = sp28->unk74[1];
        sp3C.z = sp28->unk74[2];
        sp38 = sp20;
        sp34 = func_80194DB8(sp38->unk34->unk24, &sp38->unk30->unk20);
        sp30 = func_80194DB8(sp38->unk34->unk24, &sp3C);
        sp3C.x -= sp38->unk34->unk24[0] * (sp30 - sp34);
        sp3C.y -= sp38->unk34->unk24[1] * (sp30 - sp34);
        sp3C.z -= sp38->unk34->unk24[2] * (sp30 - sp34);
        sp38->unk30->unk20.x = sp3C.x;
        sp38->unk30->unk20.y = sp3C.y;
        sp38->unk30->unk20.z = sp3C.z;
        sp2C = (sp30 - sp34 < 0.0f) ? -(sp30 - sp34) : (sp30 - sp34);
        if (sp2C > 600.0f)
            sp2C = 600.0f;
        sp2C = 1.0 - sp2C / 600.0;
        sp38->unk30->unk2C = sp2C * sp28->unk5C;
        sp38->unk30->unk30 = sp2C * sp28->unk60;
        sp38->unk30->unk34 = sp2C * sp28->unk64;
        s0 = s0->unk4;
    }
}

extern void func_8019EF14(struct UnknownGameOverStruct1 *);
extern void func_8017AD98(struct UnknownGameOverStruct2 *, struct MyVec3f *);
extern void func_8017A218(struct UnknownGameOverStruct2 *);

void Draw_shape(struct UnknownGameOverStruct2 *a, int b, float c, float d,
    float e, float f, float g, float h, float i, float j, float k, float l,
    float m, float n, int o, struct UnknownGameOverStruct1 *p)
{
    UNUSED u8 unused[8];
    struct MyVec3f sp1C;

    restart_timer("drawshape");
    D_801B9CF0++;
    if (a == NULL)
        return;
    sp1C.x = sp1C.y = sp1C.z = 0.0f;
    if (b & 2)
    {
        func_8019F19C(f, g, h);
        sp1C.x += f;
        sp1C.y += g;
        sp1C.z += h;
    }
    if ((b & 0x10) && p != NULL)
    {
        func_8019EF14(p);
        sp1C.x += p->unk30;
        sp1C.y += p->unk34;
        sp1C.z += p->unk38;
    }
    if (b & 8)
    {
        if (m != 0.0f)
            func_8019F2C4(m, 121);
        if (l != 0.0f)
            func_8019F2C4(l, 120);
        if (n != 0.0f)
            func_8019F2C4(n, 122);
    }
    if (o != 0)
    {
        D_801B9C04 = 1;
        D_801A80F4 = func_80178D98(o);
        if (D_801A80F4 != NULL)
            func_801A086C(-1, D_801A80F4, 64);
        else
            myPrint1("Draw_shape(): Bad colour");
    }
    else
    {
        D_801B9C04 = 0;
        D_801A80F4 = NULL;
    }
    if (D_801B9D80 != 0 && a->unk2C != 0)
    {
        if (p != NULL)
        {
            sp1C.x = p->unk30;
            sp1C.y = p->unk34;
            sp1C.z = p->unk38;
        }
        else
        {
            sp1C.x = sp1C.y = sp1C.z = 0.0f;
        }
        func_8017AD98(a, &sp1C);
    }
    if (b & 4)
        func_8019F0E4(i, j, k);
    if (b & 1)
        func_8019F258(c, d, e);
    func_8017A218(a);
    D_801B9C04 = 0;
    func_8018CEEC("drawshape");
}

void func_8017880C(struct UnknownGameOverStruct2 *a, int b,
    UNUSED float c, UNUSED float d, UNUSED float e,
    float f, float g, float h,
    UNUSED float i, UNUSED float j, UNUSED float k,
    UNUSED float l, UNUSED float m, UNUSED float n,
    UNUSED int o, UNUSED int p)
{
    UNUSED u8 unused[8];
    struct MyVec3f sp1C;

    restart_timer("drawshape2d");
    D_801B9CF0++;

    if (a == NULL)
        return;
    if (b & 2)
    {
        sp1C.x = f;
        sp1C.y = g;
        sp1C.z = h;
        if (D_801A80F8 != NULL)
            func_80196430(&sp1C, D_801A80F8->unkE8);
        func_8019F19C(sp1C.x, sp1C.y, sp1C.z);
    }
    func_8017A218(a);
    func_8018CEEC("drawshape2d");
}

extern Vec3f D_801A80E8;
extern struct UnknownGameOverStruct2 *D_801A82E4;
extern s32 D_801A81A0;

void Proc80178900(struct Struct80178900 *a)
{
    struct MyVec3f sp94;
    u8 sp54[0x94-0x54];  // unknown type
    UNUSED void *sp50;
    UNUSED float sp4C;
    struct UnknownGameOverStruct2 *sp48;

    if (D_801B9C00 == 27)
        return;
    D_801A80E8[0] = a->unk5C.x;
    D_801A80E8[1] = a->unk5C.y;
    D_801A80E8[2] = a->unk5C.z;
    if (a->unk2C & 2)
    {
        func_80196280(sp54);
        sp94.x = -a->unk80.x;
        sp94.y = -a->unk80.y;
        sp94.z = -a->unk80.z;
        func_80194358(sp54, &sp94, 0.0f);
        sp4C = a->unk38 / 45.0;
        sp48 = D_801A82E4;
        sp50 = &sp54;
    }
    else
    {
        sp4C = 1.0f;
        sp48 = a->unk9C;
        sp50 = NULL;
        if (++D_801A81A0 >= 17)
            D_801A81A0 = 1;
        sp48->unk50 = D_801A81A0;
    }
    func_8017880C(sp48, 2, 1.0f, 1.0f, 1.0f, a->unk74, a->unk78, a->unk7C,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1, 0);
}

struct UnknownGameOverStruct3
{
    u8 filler0[0x28];
    s32 unk28;
    u8 filler2C[0x3C-0x2C];
    u8 unk3C[0x5C-0x3C];  // unknown type
    s32 unk5C;
};

struct Struct801B9CF8
{
    u8 filler0[0x30];
    float unk30;
    u8 filler34[0x5C-0x34];
    u8 unk5C[0x74-0x5C]; // unknown type
    u8 unk74[1]; // unknown type
};

extern void func_801A0478(int, struct ObjCamera *, void *, void *, void *, void *);

void draw_material(struct UnknownGameOverStruct3 *a)
{
    int sp24 = a->unk28;

    if (sp24 == 16)
    {
        if (D_801B9CF8 != NULL && D_801B9CF8->unk30 > 0.0f)
        {
            if (D_801A80F8 != NULL)
            {
                func_801A0478(a->unk5C, D_801A80F8, D_801B9CF8->unk74, &D_801B9D10,
                    &D_801B9D00, D_801B9CF8->unk5C);
            }
            else
            {
                myPrintf("draw_material() no active camera for phong");
            }
        }
        else
        {
            sp24 = 4;
        }
    }
    if (D_801B9C04 == 0)
        func_801A086C(a->unk5C, a->unk3C, sp24);
    else
        func_801A086C(a->unk5C, D_801A80F4, 64);
}

// probably UnknownGameOverStruct3
struct Struct80178C50
{
    u8 filler0[0x28];
    s32 unk28;
    u8 filler2C[0x5C-0x2C];
    s32 unk5C;
};

extern const char D_801B54F8[];

void Unknown80178C50(struct Struct80178C50 *a)
{
    if (a->unk5C == 0)
        a->unk5C = func_801A0354(a->unk28);
}

struct Struct80178CAC_2
{
    u8 filler0[0xC];
    s32 unkC;
    u8 filler10[0x38-0x10];
    s16 unk38;
    u8 filler3A[2];
    float unk3C;
    u8 filler40[4];
    s32 unk44;
};

struct Struct80178CAC
{
    u8 filler0[0x30];
    s32 unk30;
    struct Struct80178CAC_2 *unk34[1];  // unknown length
};

void Unknown80178CAC(struct Struct80178CAC *a)
{
    int sp24;
    struct Struct80178CAC_2 *sp20;

    for (sp24 = 0; sp24 < a->unk30; sp24++)
    {
        sp20 = a->unk34[sp24];
        if ((int)sp20 == 39)
        {
            printf("bad1\n");
            return;
        }
        if (sp20->unk44 == 0x3F800000)  // maybe a float (1.0f)?
            myPrintf("bad2 %x,%d,%d,%d\n", sp20, sp20->unk3C, sp20->unk38, sp20->unkC);
    }
}

extern u8 D_801A80B8[];
extern u8 D_801A8070[];
extern u8 D_801A807C[];
extern u8 D_801A8088[];
extern u8 D_801A8094[];
extern u8 D_801A80C4[];
extern u8 D_801A80D0[];
extern u8 D_801A80A0[];
extern u8 D_801A80DC[];
extern u8 D_801A80AC[];

void *func_80178D98(int a)
{
    switch (a + 1)
    {
    case 1:
        return D_801A80B8;
        break;
    case 2:
        return D_801A8070;
        break;
    case 3:
        return D_801A807C;
        break;
    case 4:
        return D_801A8088;
        break;
    case 5:
        return D_801A8094;
        break;
    case 6:
        return D_801A80C4;
        break;
    case 7:
        return D_801A80D0;
        break;
    case 8:
        return D_801A80A0;
        break;
    case 11:
        return D_801A80B8;
        break;
    case 9:
        return D_801A80DC;
        break;
    case 10:
        return D_801A80AC;
        break;
    case 0:
        return D_801A80E8;
        break;
    default:
        return NULL;
    }
}

void Unknown80178ECC(float a, float b, float c, float d, float e, float f)
{
    float sp3C = e - b;
    float sp38 = d - a;
    float sp34 = f - c;

    func_8019FF54(a, b, c, d, e, f,
        a + sp3C * 0.1, b + sp38 * 0.1, c + sp34 * 0.1);
}

extern u8 D_801B5514[];  // unknown type
extern s32 D_801A805C;

void draw_face(struct UnknownGameOverStruct4 *a)
{
    struct UnknownGameOverStruct6 *sp3C;
    float sp38;
    float sp34;
    float sp30;
    UNUSED u8 unused[12];
    int sp20;
    int sp1C;
    int sp18;

    func_8018D420("draw_face");
    sp1C = 0;
    if (D_801B9C04 == 0 && a->unk44 >= 0)
    {
        if (a->unk48 != NULL)
        {
            if ((sp20 = a->unk48->unk5C) != 0)
            {
                if (sp20 != D_801B9CEC)
                {
                    func_801A0070();
                    func_801A0448(sp20);
                    D_801B9CEC = sp20;
                }
            }
        }
        if (0)
        {
        }
    }
    func_8019F9D8(a->unk30);
    if (D_801A805C == 0)
        func_801A15E8(a->unk24);
    for (sp20 = 0; sp20 < a->unk30; sp20++)
    {
        sp3C = a->unk34[sp20];
        sp30 = sp3C->unk20;
        sp34 = sp3C->unk24;
        sp38 = sp3C->unk28;
        if (D_801A805C != 0)
            func_801A16C4(sp3C->unk2C);
        if (sp1C != 0)
            func_801A5B58(sp3C->unk44, sp3C->unk48);
        sp18 = func_8019FA60(sp30, sp34, sp38, sp3C->unk40);
        // WTF???
        if (sp18 != 0)
            *(int *)&sp3C->unk44 = (int)make_link_2(*(void **)&sp3C->unk44, sp18);
    }
    func_8019FEF0();
    imout();
}

void func_80179228(int a, float b, float c, float d, float e)
{
    func_8019E2F8(func_80178D98(a));
    func_8019D360(b, c, d, e);
}

void func_8017928C(int a, float b, float c, float d, float e)
{
    func_8019E2F8(func_80178D98(a));
    func_8019D708(b, c, d, e);
}

void Unknown801792F0(struct ObjHeader* a)
{
    char sp28[32];
    struct MyVec3f sp1C;

    sprint_obj_id(sp28, a);
    func_80186B44(a);
    func_80188A3C(&sp1C);
    func_801A4438(sp1C.x, sp1C.y, sp1C.z);
    func_801A48D8(sp28);
}

union SomeUnion
{
    float f;
    s32 i;
    u64 l;
};

typedef void (*SomeFunc)(union SomeUnion *, union SomeUnion);

extern int sprintf(char *, const char *, ...);

void Proc80179350(struct Struct80178900 *a)
{
    struct MyVec3f sp144;
    char sp44[0x100];
    UNUSED u8 unused[16];
    struct Struct80178900_2 *sp30;
    union SomeUnion sp28;
    SomeFunc sp24 = (SomeFunc)a->unk2C;

    if ((sp30 = a->unk28) != NULL)
    {
        if (sp30->unk20 == 0x40000)
        {
            func_80186B44(sp30->unk14);
            func_80188A3C(&sp144);
        }
        else
        {
            sp144.x = sp144.y = sp144.z = 0.0f;
        }
        switch (sp30->unk1C)
        {
        case 2:
            get_objvalue(&sp28, 2, sp30->unk14, sp30->unk18);
            if (sp24 != NULL)
                sp24(&sp28, sp28);
            sprintf(sp44, a->unk20, sp28.f);
            break;
        case 1:
            get_objvalue(&sp28, 1, sp30->unk14, sp30->unk18);
            if (sp24 != NULL)
                sp24(&sp28, sp28);
            sprintf(sp44, a->unk20, sp28.i);
            break;
        default:
            if (a->unk20 != NULL)
                func_8018DC98(sp44, a->unk20);
            else
                func_8018DC98(sp44, "NONAME");
            break;
        }
    }
    else
    {
        sp144.x = sp144.y = sp144.z = 0.0f;
        if (a->unk20 != NULL)
            func_8018DC98(sp44, a->unk20);
        else
            func_8018DC98(sp44, "NONAME");
    }
    sp144.x += a->unk14;
    sp144.y += a->unk18;
    sp144.z += a->unk1C;
    func_801A4438(sp144.x, sp144.y, sp144.z);
    func_801A48C4(a->unk30);
    func_801A48D8(sp44);
}

void Proc80179628(struct Struct80178900 *a)
{
    struct Struct80178900 *sp9C = a;
    int sp98;
    UNUSED u8 unused[80];

    if (D_801B9C00 == 27)
        return;
    if (sp9C->unk12 & 0x10)
        sp98 = 8;
    else
        sp98 = sp9C->unk40;
    if (sp9C->unk1A8 != 0)
    {
        Draw_shape(sp9C->unk1A8, 16, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, sp98, &sp9C->unk168);
    }
    if (sp9C->unk1C8 != 0)
        Draw_group(sp9C->unk1C8);
}

struct Struct80179628
{
    u8 filler0[0x12];
    u16 unk12;
    float unk14;
    float unk18;
    u8 filler1C[0x28-0x1C];
    float unk28;
    u8 filler2C[0x40-0x2C];
    float unk40;
    float unk44;
    u8 filler48[0x5C-0x48];
    s32 unk5C;
};

void Proc8017976C(struct Struct80179628 *a)
{
    int sp24 = 0;

    if (a->unk5C != 0)
        sp24 = a->unk5C;
    func_80179228(sp24, a->unk14, a->unk18,
        a->unk14 + a->unk28 * a->unk40, a->unk18 + a->unk44);
    if (a->unk12 & 0x10)
    {
        func_8017928C(8, a->unk14, a->unk18,
            a->unk14 + a->unk28 * a->unk40, a->unk18 + a->unk44);
    }
    a->unk12 &= ~0x10;
}

#define ABS(x) ((x) < 0.0f ? -(x) : (x))

extern void func_8019F318(struct ObjCamera *a, float, float, float,
    float, float, float, float);

void Draw_Camera(struct ObjCamera *a)
{
    struct MyVec3f sp44;
    UNUSED float sp40 = 0.0f;

    sp44.x = 0.0f;
    sp44.y = 0.0f;
    sp44.z = 0.0f;
    if (a->unk30 != 0)
    {
        func_80186B44(a->unk30);
        func_80188A3C(&sp44);
        sp44.x += a->unk34.x;
        sp44.y += a->unk34.y;
        sp44.z += a->unk34.z;
        ;  // needed to match
    }
    else
    {
        sp44.x = a->unk34.x;
        sp44.y = a->unk34.y;
        sp44.z = a->unk34.z;
    }

    if (0)
    {
        //! dead code
        printf("%f,%f,%f\n", a->unk14.x, a->unk14.y, a->unk14.z);
    }

    if (ABS(a->unk14.x - sp44.x) + ABS(a->unk14.z - sp44.z) == 0.0f)
    {
        printf("Draw_Camera(): Zero view distance\n");
        return;
    }
    func_8019F318(a, a->unk14.x, a->unk14.y, a->unk14.z,
        sp44.x, sp44.y, sp44.z, a->unkA4);
}

struct Struct80179ACC
{
    u8 filler0[0x8];
    void (*unk8)(struct Struct80179ACC *);
    s32 unkC;
    u8 filler10[2];
    u16 unk12;
    u8 filler14[0x1C-0x14];
    s32 unk1C;
    u8 filler20[0x2C-0x20];
    u32 unk2C;
    u8 filler30[0x1C8-0x30];
    void *unk1C8;
};

void Unknown80179ACC(struct Struct80179ACC *a)
{
    if (a->unkC == 32)
    {
        if (0)
        {
        }
        if (a->unk1C8 != 0)
            func_80179B64(a->unk1C8);
    }
    else
    {
        if (0)
        {
        }
    }
    a->unk12 &= ~1;
}

void func_80179B64(struct ObjGroup* group)
{
    apply_to_obj_types_in_group(
        OBJ_TYPE_LABELS | OBJ_TYPE_GADGETS | OBJ_TYPE_CAMERAS \
        | OBJ_TYPE_NETS | OBJ_TYPE_JOINTS | OBJ_TYPE_BONES, 
        Unknown80179ACC, 
        group
    );
}

struct UnknownGameOverStruct9_2
{
    u8 filler0[0x12];
    u16 unk12;
};

struct UnknownGameOverStruct9
{
    u8 filler0[0x24];
    struct ObjCamera *unk24;
    void *unk28;
    void *unk2C;
    struct UnknownGameOverStruct9_2 *unk30;
    s32 unk34;
    s32 unk38;
    u8 filler3C[0x54-0x3C];
    struct MyVec3f unk54;
    struct MyVec3f unk60;
    u8 filler6C[4];
    s32 unk70;
    u8 filler74[0x98-0x74];
    void (*unk98)(struct UnknownGameOverStruct9 *);
};

void func_80179B9C(struct MyVec3f *a, struct ObjCamera *b, struct UnknownGameOverStruct9 *c)
{
    func_80196430(a, b->unkE8);
    if (a->z > -256.0f)
        return;
    a->x *= 256.0 / -a->z;
    a->y *= 256.0 / a->z;
    a->x += c->unk54.x / 2.0f;
    a->y += c->unk54.y / 2.0f;
}

struct Struct80179CC8
{
    u8 filler0[0xC];
    s32 unkC;
    s16 unk10;
    u16 unk12;
};

void Unknown80179CC8(struct Struct80179CC8 *a)
{
    struct MyVec3f sp3C;
    UNUSED u8 unused[12];
    struct Struct80179CC8 *sp2C;
    Mat4 *sp28;

    if (D_801A80F8 == NULL)
        return;
    sp2C = a;
    if (!(sp2C->unk12 & 8))
        return;
    func_80186B44(sp2C);
    sp28 = dGetRMatrixPtr();
    sp3C.x = (*sp28)[3][0];
    sp3C.y = (*sp28)[3][1];
    sp3C.z = (*sp28)[3][2];
    func_80179B9C(&sp3C, D_801A80F8, D_801B9CE0.unk4);
    if (ABS(D_801B9920.unkD0 - sp3C.x) < 20.0f)
    {
        if (ABS(D_801B9920.unkD4 - sp3C.y) < 20.0f)
        {
            func_801A5A04(2);
            func_801A5A04(sp2C->unkC);
            func_801A5A04(sp2C->unk10);
            D_801B9D88.x = sp3C.x;
            D_801B9D88.y = sp3C.y;
        }
    }
}

extern s32 D_801A8100;

extern void func_8017A8A0(struct Struct80179ACC *a);
extern void Proc8017A91C(struct Struct80179ACC *a);

void drawscene(int a, void *b, struct ObjGroup* group)
{
    UNUSED u8 unused[16];

    restart_timer("drawscene");
    func_8018D420("draw_scene()");
    D_801A8100 = 0;
    D_801B9CE8 = 0;
    restart_timer("draw1");
    func_801A17B0(5);
    if (D_801B9CE0.unk4->unk38 == 1)
    {
        func_801A3C8C(D_801B9CE0.unk4->unk60.z, D_801B9CE0.unk4->unk54.x / D_801B9CE0.unk4->unk54.y,
            D_801B9CE0.unk4->unk60.x, D_801B9CE0.unk4->unk60.y);
    }
    else
    {
        func_801A3AF0(-D_801B9CE0.unk4->unk54.x / 2.0, D_801B9CE0.unk4->unk54.x / 2.0,
            -D_801B9CE0.unk4->unk54.y / 2.0, D_801B9CE0.unk4->unk54.y / 2.0,
            D_801B9CE0.unk4->unk60.x, D_801B9CE0.unk4->unk60.y);
    }

    if (group != NULL)
    {
        func_801A17B0(6);
        apply_to_obj_types_in_group(
            OBJ_TYPE_LIGHTS | OBJ_TYPE_PARTICLES, 
            func_8017A8A0, 
            group
        );
        func_801A17B0(5);
    }

    if (D_801A80F8 != NULL)
        Draw_Camera(D_801A80F8);
    else
        func_8019F0E4(0.0f, 0.0f, -1000.0f);
    func_80178140();
    func_801A17B0(6);
    func_8019F02C();
    D_801B9C00 = a;
    if ((D_801B9D80 = D_801B9CE0.unk4->unk34 & 0x200000) != 0)
        D_801B9CE0.unk4->unk34 &= 0xFFDFFFFF;
    D_801B9D80 = 1;
    apply_to_obj_types_in_group(OBJ_TYPE_LIGHTS, Proc8017A91C, D_801B9BB8);
    func_8018CEEC("draw1");
    restart_timer("drawobj");
    func_8018D420("process_group");
    if (D_801B9C00 == 27)
        apply_to_obj_types_in_group(0x00FFFFFF, Unknown80179CC8, b);
    else
        apply_to_obj_types_in_group(
            OBJ_TYPE_LIGHTS | OBJ_TYPE_GADGETS | OBJ_TYPE_NETS | OBJ_TYPE_PARTICLES, 
            func_8017A8A0, 
            b
        );
    imout();
    func_8018CEEC("drawobj");
    gd_setproperty(11, 0.0f, 0.0f, 0.0f);
    apply_to_obj_types_in_group(OBJ_TYPE_LABELS, func_8017A8A0, b);
    gd_setproperty(11, 1.0f, 0.0f, 0.0f);
    func_8019F098();
    imout();
    func_8018CEEC("drawscene");
    return;
}

void Proc8017A204(UNUSED int a)
{
}

extern s32 D_801A86B0;

void func_8017A218(struct UnknownGameOverStruct2 *a)
{
    D_801B9CEC = 0;
    D_801B9CE8 = 0;
    func_801A2374(0);
    D_801A8100 = a->unk44 & 1;
    func_801A02B8(a->unk58);
    if (a->unk48[D_801A86B0] != 0)
    {
        func_8019BD0C(a->unk48[D_801A86B0], a->unk50);
    }
    else if (a->unk1C != 0)
    {
        func_801A0038();
        Draw_group(a->unk1C);
        func_801A0070();
    }
}

struct Struct8017A30C
{
    u8 filler0[0x1C];
    struct UnknownGameOverStruct2 *unk1C;
    float unk20;
    float unk24;
    float unk28;
    u8 filler2C[0x5C-0x2C];
    s32 unk5C;
    s32 unk60;
    u8 filler64[8];
    s32 unk6C;
};

extern struct MyVec3f *D_801A8104[];
extern struct MyVec3f *D_801A8118[];

void Proc8017A30C(struct Struct8017A30C *a)
{
    struct Struct8017A30C *sp74 = a;
    UNUSED u8 unused1[16];
    struct MyVec3f *sp60;
    struct MyVec3f *sp5C;
    float sp58;
    UNUSED u8 unused2[16];

    if (sp74->unk5C > 0)
    {
        sp60 = D_801A8104[0];
        sp5C = D_801A8118[1];
        sp58 = sp74->unk5C / 10.0;
        D_801A80E8[0] = (sp60->x - sp5C->x) * sp58 + sp5C->x;
        D_801A80E8[1] = (sp60->y - sp5C->y) * sp58 + sp5C->y;
        D_801A80E8[2] = (sp60->z - sp5C->z) * sp58 + sp5C->z;
        ;  // needed to match
    }
    else
    {
        D_801A80E8[0] = 0.0f;
        D_801A80E8[1] = 0.0f;
        D_801A80E8[2] = 0.0f;
    }

    if (sp74->unk5C > 0)
    {
        sp74->unk1C->unk50 = sp74->unk5C;
        func_8017880C(sp74->unk1C, 2, 1.0f, 1.0f, 1.0f,
            sp74->unk20, sp74->unk24, sp74->unk28,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            -1, 0);
    }
    if (sp74->unk60 == 3)
    {
        if (sp74->unk6C != 0)
            Draw_group(sp74->unk6C);
    }
}

struct Struct8017A550
{
    u8 filler0[0x12];
    u16 unk12;
    float unk14;
    float unk18;
    float unk1C;
    u8 filler20[0x28-0x20];
    float unk28;
    float unk2C;
    float unk30;
    u8 filler34[0x70-0x34];
    u8 unk70[0xF0-0x70];  // TODO: struct UnknownGameOverStruct1
    struct UnknownGameOverStruct2 *unkF0;
    u8 fillerF4[4];
    float unkF8;
    u8 fillerFC[4];
    s32 unk100;
};

void Proc8017A550(struct Struct8017A550 *a)
{
    struct Struct8017A550 *sp64 = a;
    UNUSED u8 unused1[4];
    int sp5C;
    UNUSED u8 unused2[4];
    struct MyVec3f sp4C;

    return;

    //! dead code
    sp4C.x = 1.0f;
    sp4C.y = 1.0f;
    sp4C.z = sp64->unkF8 / 50.0f;
    if (sp64->unk12 & 0x10)
        sp5C = 8;
    else
        sp5C = sp64->unk100;
    sp64->unk12 &= ~0x10;
    if (D_801B9C00 != 27)
    {
        Draw_shape(sp64->unkF0, 27, sp4C.x, sp4C.y, sp4C.z,
            sp64->unk14, sp64->unk18, sp64->unk1C,
            0.0f, 0.0f, 0.0f,
            sp64->unk28, sp64->unk2C, sp64->unk30,
            sp5C, (struct UnknownGameOverStruct1 *)sp64->unk70);
    }
}

struct Struct8017A6A4
{
    u8 filler0[0x12];
    u16 unk12;
    u8 filler14[0x20-0x14];
    struct UnknownGameOverStruct2 *unk20;
    u8 filler24[0x128-0x24];
    u8 unk128[0x1C8-0x128];  // TODO: struct UnknownGameOverStruct1
    s32 unk1C8;
};

void Proc8017A6A4(struct Struct8017A6A4 *a)
{
    struct Struct8017A6A4 *sp84 = a;
    UNUSED u8 unused1[4];
    UNUSED float sp7C = 70.0f;
    UNUSED u8 unused2[4];
    UNUSED int sp74 = 1;
    int sp70;
    UNUSED u8 unused[8];
    struct UnknownGameOverStruct2 *sp64;
    UNUSED u8 unused3[28];

    if ((sp64 = sp84->unk20) == NULL)
        return;
    if (sp84->unk12 & 0x10)
        sp70 = 8;
    else
        sp70 = sp84->unk1C8;
    Draw_shape(sp64, 16, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, sp70, (struct UnknownGameOverStruct1 *)sp84->unk128);
}

void Draw_group(void *a)
{
    if (a == 0)
        myPrint1("Draw_Group: Bad group definition!");
    apply_to_obj_types_in_group(0x00FFFFFF, func_8017A8A0, a);
}

struct Struct8017A818
{
    u8 filler0[0x12];
    u16 unk12;
    u8 filler14[0x40-0x14];
    struct UnknownGameOverStruct4 *unk40;
};

void Proc8017A818(struct Struct8017A818 *a)
{
    struct Struct8017A818 *sp1C = a;

    if (a->unk12 & 0x10)
    {
        a->unk12 &= ~0x10;
        ;  // needed to match
    }
    else
    {
        D_801B9C04 = 0;
    }
    draw_face(sp1C->unk40);
}

void func_8017A8A0(struct Struct80179ACC *a)
{
    if (a == NULL)
        myPrint1("Bad object!");
    if (a->unk12 & 2)
        return;
    a->unk8(a);
}

void Proc8017A91C(struct Struct80179ACC *a)
{
    func_801A0324(a->unk1C);
    gd_setproperty(11, 2.0f, 0.0f, 0.0f);
    if (a->unk2C & 0x10)
        D_801B9D80++;
    a->unk2C &= ~0x10;
}

struct Struct8017A980
{
    u8 filler0[0x1C];
    s32 unk1C;
    u8 filler20[0x2C-0x20];
    u32 unk2C;
    float unk30;
    u8 filler34[4];
    float unk38;
    u8 filler3C[0x50-0x3C];
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    u8 filler68[0x74-0x68];
    float unk74;
    float unk78;
    float unk7C;
    struct MyVec3f unk80;
};

void Proc8017A980(struct Struct8017A980 *a)
{
    float sp24;
    float sp20;
    float sp1C;

    a->unk5C = a->unk50 * a->unk30;
    a->unk60 = a->unk54 * a->unk30;
    a->unk64 = a->unk58 * a->unk30;
    D_801B9D20[a->unk1C].x = a->unk74 - D_801B9D10.x;
    D_801B9D20[a->unk1C].y = a->unk78 - D_801B9D10.y;
    D_801B9D20[a->unk1C].z = a->unk7C - D_801B9D10.z;
    func_80194BF4(&D_801B9D20[a->unk1C]);
    if (a->unk2C & 0x20)
    {
        D_801B9D00.x = D_801B9D20[a->unk1C].x;
        D_801B9D00.y = D_801B9D20[a->unk1C].y;
        D_801B9D00.z = D_801B9D20[a->unk1C].z;
        D_801B9CF8 = (struct Struct801B9CF8 *)a;  // FIXME: find the correct type
    }
    sp24 = a->unk30;
    if (a->unk2C & 2)
    {
        sp20 = -func_80194DB8(&D_801B9D20[a->unk1C], &a->unk80);
        sp1C = 1.0 - a->unk38 / 90.0;
        if (sp20 > sp1C)
        {
            sp20 = (sp20 - sp1C) * (1.0 / (1.0 - sp1C));
            if (sp20 > 1.0)
                sp20 = 1.0;
            else if (sp20 < 0.0f)
                sp20 = 0.0f;
        }
        else
        {
            sp20 = 0.0f;
        }
        sp24 *= sp20;
    }
    func_801A0324(a->unk1C);
    gd_setproperty(13, a->unk50 * sp24, a->unk54 * sp24, a->unk58 * sp24);
    gd_setproperty(15, D_801B9D20[a->unk1C].x, D_801B9D20[a->unk1C].y, D_801B9D20[a->unk1C].z);
    gd_setproperty(11, 2.0f, 0.0f, 0.0f);
}

void func_8017AD98(struct UnknownGameOverStruct2 *a, struct MyVec3f *b)
{
    restart_timer("updateshaders");
    func_8019E874();
    D_801B9D10.x = b->x;
    D_801B9D10.y = b->y;
    D_801B9D10.z = b->z;
    D_801B9CF8 = NULL;
    if (D_801B9BB8 != NULL)
        apply_to_obj_types_in_group(OBJ_TYPE_LIGHTS, Proc8017A980, D_801B9BB8);
    if (a->unk2C != NULL)
        apply_to_obj_types_in_group(OBJ_TYPE_MATERIALS, func_8017A8A0, a->unk2C);
    func_8019E894();
    func_8018CEEC("updateshaders");
}

struct Struct8017AE88
{
    u8 filler0[0x2C];
    void *unk2C;
    u8 filler30[0x3C-0x30];
    s32 unk3C;
    u8 filler40[0x48-0x40];
    s32 unk48;
    s32 unk4C;
    u8 filler50[0x5C-0x50];
    s8 unk5C;
};

void func_8017AE88(struct Struct8017AE88 *a)
{
    if (a->unk2C != NULL)
        apply_to_obj_types_in_group(OBJ_TYPE_MATERIALS, Unknown80178C50, a->unk2C);
}

struct Struct8017AEDC_2
{
    u8 filler0[4];
    struct Struct8017AEDC_2 *unk4;
    s32 unk8;
};

struct Struct8017AEDC
{
    u8 filler0[0x1C];
    struct Struct8017AEDC_2 *unk1C;
};

void Unknown8017AEDC(struct Struct8017AEDC *a)
{
    register struct Struct8017AEDC_2 *s0 = a->unk1C;

    while (s0 != NULL)
    {
        int sp20 = s0->unk8;

        func_8017BED0(a, sp20);
        s0 = s0->unk4;
    }
}

int Unknown8017AF48(struct Struct8017AE88 *a)
{
    struct Struct8017AE88 *sp24 = a;
    int sp20;
    UNUSED int sp1C;

    func_8017AE88(sp24);
    sp20 = gd_startdisplist(7);
    if (sp20 == 0)
        return -1;
    func_80178140();
    D_801B9C04 = 0;
    if (sp24->unk3C == 0)
        func_8017A218((struct UnknownGameOverStruct2 *)sp24);  // FIXME: find correct type
    sp1C = func_8019EA6C();
    sp24->unk48 = sp20;
    sp24->unk4C = sp20;
    if (sp24->unk5C != 0)
    {
        if (0)
        {
        }
    }
    //! no return value
}

void func_8017B028(void *a)
{
    // FIXME: What type is this function pointer?
    UNUSED int sp1C = apply_to_obj_types_in_group(OBJ_TYPE_SHAPES, (void (*)())Unknown8017AF48, a);
}

struct Struct8017B064_3
{
    u8 filler1C[0x1C];
    s32 unk1C;
    u8 filler20[0x44-0x20];
    s32 unk44;
    struct Struct8017B064_3 *unk48;
};

struct Struct8017B064_2
{
    u8 filler0[4];
    struct Struct8017B064_2 *unk4;
    struct Struct8017B064_3 *unk8;
    s32 unkC;
    s32 unk14;
};

struct Struct8017B064
{
    u8 filler0[0x1C];
    struct Struct8017B064_2 *unk1C;
};

void func_8017B064(struct Struct8017B064 *a, struct Struct8017B064 *b)
{
    struct Struct8017B064_3 *sp14;
    register struct Struct8017B064_2 *a2;
    struct Struct8017B064_3 *spC;
    register struct Struct8017B064_2 *a3;
    struct Struct8017B064_3 *sp4;

    a2 = a->unk1C;
    while (a2 != NULL)
    {
        spC = a2->unk8;
        sp14 = spC;
        a3 = b->unk1C;
        while (a3 != NULL)
        {
            sp4 = a3->unk8;
            if (sp4->unk1C == sp14->unk44)
                break;
            a3 = a3->unk4;
        }
        if (a3 != NULL)
            sp14->unk48 = sp4;
        a2 = a2->unk4;
    }
}

struct Struct8017B118
{
    u8 filler0[0xC];
    s32 unkC;
    u8 filler10[0x2C-0x10];
    float unk2C;
    float unk30;
    float unk34;
};

struct Struct8017B118_4
{
    u8 filler0[0xC];
    s32 unkC;
    u8 filler10[0x24-0x10];
    float unk24;
    float unk28;
    float unk2C;
    s32 unk30;
    void *unk34[1];  // unknown length
};

struct Struct8017B118_3  // maybe the same as Struct8017B064_2?
{
    u8 filler0[4];
    struct Struct8017B118_3 *unk4;
    struct Struct8017B118_4 *unk8;
};

struct Struct8017B118_2
{
    u8 filler0[0x1C];
    struct Struct8017B118_3 *unk1C;
};

void func_8017B118(struct Struct8017B118 *a, struct Struct8017B118_2 *b)
{
    int sp14;
    int sp10;
    register struct Struct8017B118_3 *a2;
    struct Struct8017B118_4 *sp8;

    a->unk2C = a->unk30 = a->unk34 = 0.0f;
    sp10 = 0;
    a2 = b->unk1C;
    while (a2 != NULL)
    {
        sp8 = a2->unk8;
        for (sp14 = 0; sp14 < sp8->unk30; sp14++)
        {
            if (sp8->unk34[sp14] == a)
            {
                a->unk2C += sp8->unk24;
                a->unk30 += sp8->unk28;
                a->unk34 += sp8->unk2C;
                sp10++;
            }
        }
        a2 = a2->unk4;
    }
    if (sp10 != 0)
    {
        a->unk2C /= sp10;
        a->unk30 /= sp10;
        a->unk34 /= sp10;
    }
}

struct UnknownGameOverStruct8
{
    u8 filler0[0x30];
    s32 unk30;
    void *unk34[1];  // unknown length
};

static const char unusedString1[] = "Generated '%s' (%d) display list ok.(%d)\n";
static const char unusedString2[] = "Generated 'UNKNOWN' (%d) display list ok.(%d)\n";
static const char unusedString3[] = "made %d display lists\n";

void find_thisface_verts(struct ObjFace *face, struct Struct8017B118_2 *b)
{
    int sp2C;
    u8 *sp28;
    struct Struct8017B118_3 *sp24;

    for (sp2C = 0; sp2C < face->vtxCount; sp2C++)
    {
        sp24 = b->unk1C;
        sp28 = 0;
        while (sp24 != NULL)
        {
            if (sp24->unk8->unkC == 256 || sp24->unk8->unkC == 8)
            {
                //! wut?
                if (sp28++ == (u8 *)face->vertices[sp2C])
                    break;
            }
            sp24 = sp24->unk4;
        }
        if (sp24 == NULL)
            myPrintf("find_thisface_verts(): Vertex not found");
        face->vertices[sp2C] = (struct ObjVertex*) sp24->unk8;
    }
    calc_face_normal(face);
}

struct Struct8017B3F8_2
{
    u8 filler0[4];
    struct Struct8017B3F8_2 *unk4;
    struct UnknownGameOverStruct8 *unk8;
};

struct Struct8017B3F8
{
    u8 filler0[0x1C];
    struct Struct8017B3F8_2 *unk1C;
};

extern u8 D_801B56A4[];

void func_8017B3F8(struct Struct8017B3F8 *a, struct Struct8017B118_2 *b)
{
    register struct Struct8017B3F8_2 *s0;
    struct UnknownGameOverStruct8 *sp28;
    register struct Struct8017B118_3 *s1;
    struct Struct8017B118_4 *sp20;

    func_8018D420("map_vertices");

    s0 = a->unk1C;
    while (s0 != NULL)
    {
        sp28 = s0->unk8;
        find_thisface_verts((struct ObjFace*) sp28, b);
        s0 = s0->unk4;
    }

    s1 = b->unk1C;
    while (s1 != NULL)
    {
        sp20 = s1->unk8;
        // FIXME: find correct types
        func_8017B118((void *)sp20, (void *)a);
        s1 = s1->unk4;
    }

    imout();
}

struct Struct8017B4C8
{
    u8 filler0[0x12];
    u16 unk12;
};

void Unknown8017B4C8(struct Struct8017B4C8 *a)
{
    struct Struct8017B4C8 *sp4 = a;
    if (sp4->unk12 & 8)
        sp4->unk12 &= ~0x14;
}

struct Struct8017B514
{
    u8 filler0[0x10];
    s16 unk10;
    u16 unk12;
};

void Unknown8017B514(struct Struct8017B514 *a)
{
    struct Struct8017B514 *sp2C = a;
    UNUSED u8 unused[12];
    float sp1C;

    if (sp2C->unk12 & 8)
    {
        if (sp2C->unk10 == D_801B9CD0)
        {
            if (D_801A80F8 != NULL)
                sp1C = func_8018B57C(D_801A80F8, sp2C);
            else
                sp1C = 0.0f;
            if (sp1C < D_801B9CD4)
            {
                D_801B9CD4 = sp1C;
                D_801B9CD8 = sp2C;
            }
        }
    }
}

void Unknown8017B5F0(struct ObjCamera *a)
{
    if (D_801A80F8 != NULL)
        return;
    D_801A80F8 = a;
}

void UpdateView(struct UnknownGameOverStruct9 *a)
{
    int sp13C;
    int sp138;
    int sp134;
    int sp130;
    int sp12C;
    int sp128;
    char sp28[0x100];

    D_801B9CF0 = 0;
    D_801B9CF4 = 0;
    if (!(a->unk34 & 0x800))
    {
        a->unk34 &= 0xFFEFFFFF;
        return;
    }
    func_8018D420("UpdateView()");
    if (a->unk98 != NULL)
        a->unk98(a);
    if (!(a->unk34 & 0x100000))
        a->unk34 |= 0x100000;
    D_801A80F8 = NULL;
    if (a->unk28 != NULL)
    {
        apply_to_obj_types_in_group(OBJ_TYPE_CAMERAS, Unknown8017B5F0, a->unk28);
        a->unk24 = D_801A80F8;
        if (a->unk24 != NULL)
            D_801A80F8->unk18C = a;
    }
    if (a->unk34 & 0x40000)
    {
        func_8018CEEC("dlgen");
        restart_timer("dynamics");
        func_8018145C(a);
        func_8018CEEC("dynamics");
        restart_timer("dlgen");
        D_801A80F8 = a->unk24;
    }
    if (!(a->unk34 & 0x80000))
    {
        imout();
        return;
    }
    D_801B9CE0.unk4 = a;
    func_801A48F0(a);
    a->unk70 = gd_startdisplist(8);
    func_801A2448(D_801B9CE0.unk4);
    gd_shading(9);
    if (a->unk34 & 0x6000)
        func_801A2310();
    if (a->unk28 != NULL)
    {
        if (D_801B9920.unkD8 >> 31 != 0)
        {
            if (gd_getproperty(3, 0) != 0 && (D_801B9920.unkD8 * 8) >> 31 != 0)
            {
                func_801A59D4(D_801B9C08, 100);
                drawscene(27, D_801B9CE0.unk4->unk28, NULL);
                sp138 = func_801A5A4C(D_801B9C08);
                D_801B9CD0 = 0;
                D_801B9CD8 = NULL;
                D_801B9CD4 = 10000000.0f;
                if (sp138 < 0)
                {
                    myPrintf("UpdateView(): Pick buffer too small");
                }
                else if (sp138 > 0)
                {
                    sp12C = 0;
                    for (sp13C = 0; sp13C < sp138; sp13C++)
                    {
                        sp134 = D_801B9C08[sp12C++];
                        if (sp134 != 0)
                        {
                            switch ((sp128 = D_801B9C08[sp12C++]))
                            {
                            case 4:
                                func_8018DC98(sp28, "J");
                                break;
                            case 32:
                                func_8018DC98(sp28, "N");
                                break;
                            case 8:
                                func_8018DC98(sp28, "P");
                                break;
                            default:
                                func_8018DC98(sp28, "?");
                                break;
                            }
                        }
                        if (sp134 >= 2)
                        {
                            for (sp130 = 0; sp130 < sp134 - 1; sp130++)
                            {
                                D_801B9CD0 = D_801B9C08[sp12C++];
                                apply_to_obj_types_in_group(sp128, Unknown8017B514, D_801B9CE0.unk4->unk28);
                            }
                        }
                    }
                }
                if (D_801B9CD8 != NULL)
                {
                    D_801B9CD8->unk12 |= 4;
                    D_801B9CD8->unk12 |= 0x10;
                    // FIXME: find correct types
                    D_801B9CE0.unk4->unk30 = (void *)D_801B9CD8;
                    D_801B9920.unkB8 = D_801B9920.unkD0 = D_801B9D88.x;
                    D_801B9920.unkBC = D_801B9920.unkD4 = D_801B9D88.y;
                }
            }
            func_80180974(D_801B9CE0.unk4->unk28);
        }
        else
        {
            if (D_801B9CE0.unk4->unk30 != NULL)
            {
                D_801B9CE0.unk4->unk30->unk12 &= ~4;
                D_801B9CE0.unk4->unk30->unk12 &= ~0x10;
                D_801B9CE0.unk4->unk30 = NULL;
            }
        }
        drawscene(26, D_801B9CE0.unk4->unk28, D_801B9CE0.unk4->unk2C);
    }
    func_801A34E0();
    func_8019EA6C();
    imout();
    return;
}

void unref_8017BC94(void)
{
}

/* Comment needed to prevent compiler from crashing */
/* Comment needed to prevent compiler from crashing */
/* Comment needed to prevent compiler from crashing */
