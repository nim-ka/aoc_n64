#include <ultra64.h>

#include "sm64.h"
#include "input.h"
#include "main.h"
#include "math_util.h"

struct Struct8032CF90
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0x10-0x4];
    void *unk10;
    u8 unk14;
    u8 filler15[1];
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
};

struct Struct8027B4E8
{
    u8 filler0[0x10];
    void *unk10;
    float unk14;
};

struct Struct8027B110_sub
{
    void *unk0;
    u32 unk4;
    struct Struct8027B110_sub *unk8;
};

struct Struct8027B110
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0xC];
    void *unk10;
    struct Struct8027B110_sub *unk14[8];
    struct Struct8027B110_sub *unk34[1];  // unknown length
};

struct Struct8027D8B8
{
    u8 filler0[0x10];
    void *unk10;
};

struct Struct8027D8F8_sub
{
    s16 unk0;
};

struct Struct8027D8F8
{
    s16 unk0;
    s16 unk2;
    u8 filler4[4];
    struct Struct8027D8F8 *unk8;
    struct Struct8027D8F8_sub *unkC;
    u8 filler10[0x50-0x10];
    u32 unk50;
};

struct Struct8032CF10
{
    u32 unk0[8];
};

struct Struct8027B9A8
{
    u8 filler0[0x10];
    void *unk10;
    void (*unk14)(int, struct Struct8027B9A8 *, void *);
    u8 filler18[4];
    Vec3f unk1C;
    Vec3f unk28;
    void *unk34;
    s16 unk38;
    s16 unk3A;
};

struct Struct8027B6C4
{
    u8 filler0[0x10];
    void *unk10;
    void (*unk14)(int, struct Struct8027B6C4 *, void *);
    u8 filler18[4];
    float unk1C;
    s16 unk20;
    s16 unk22;
};

struct Struct8027B8D4_sub
{
    u8 filler0[8];
    struct Struct8027B8D4_sub *unk8;
};

struct Struct8027B8D4
{
    u8 filler0[0x10];
    struct Struct8027B8D4_sub *unk10;
    void (*unk14)(int, struct Struct8027B8D4 *, void *);
    u8 filler18[6];
    s16 unk1E;
};

struct Struct8027B840
{
    u8 filler0[0x10];
    void *unk10;
    s16 unk14;
    s16 unk16;
};

struct Struct8027BB64
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0xC];
    void *unk10;
    u32 unk14;
    Vec3s unk18;
    Vec3s unk1E;
};

struct Struct8027C18C
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0xC];
    void *unk10;
    u32 unk14;
};

struct Struct8027BEC4
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0xC];
    void *unk10;
    u32 unk14;
    float unk18;
};

struct Struct8032CFA4_sub
{
    u8 filler0[0x2C];
    Vec3f unk2C;
};

struct Struct8032CFA4
{
    u8 filler0[0x1C];
    struct Struct8032CFA4_sub *unk1C;
};

struct Struct8027C2A8
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0xC];
    void *unk10;
    int (*unk14)(int, struct Struct8027C2A8 *, void *);
    u8 filler18[4];
    u32 unk1C;
};

struct Struct8027C1F4
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0xC];
    void *unk10;
    int (*unk14)(int, struct Struct8027C1F4 *, void *);
};

struct Struct8027C4C0
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0xC];
    void *unk10;
    u32 unk14;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
};

struct Struct8027C988_sub
{
    s16 unk0;
    s16 unk2;
    u32 unk4;
    u8 filler8[4];
    void *unkC;
    void *unk10;
};

struct Struct8027C988
{
    u8 filler0[2];
    s16 unk2;
    struct Struct8027C988_sub *unk4;
    s16 unk8;
    s16 unkA;
    u8 unkC;  // unknown type
};

struct Struct8027D14C;

struct Struct8027D14C_sub
{
    s16 unk0;
    u8 filler2[0xA];
    struct Struct8027D14C *unkC;
    u8 filler10[4];
    s16 unk14;
};

struct Struct8027D14C
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0xC];
    void *unk10;
    struct Struct8027D14C_sub *unk14;
    s8 unk18;
    u8 filler19[1];
    Vec3s unk1A;
    Vec3f unk20;
    Vec3f unk2C;
    struct Struct8027C988 unk38;
    u8 filler48[0x8];
    void *unk50;
    float unk54;
    float unk58;
    float unk5C;
};

struct Struct8027CB08_sub
{
    s16 unk0;
    u8 filler2[0x16];
    float unk18;
};

struct Struct8027CB08
{
    u8 filler0[0x10];
    struct Struct8027CB08_sub *unk10;
    s16 unk14;
    u8 unk16;
    u8 unk17;
};

struct Struct8027D460;

struct Struct8027D460_sub
{
    u8 filler0[0xC];
    struct Struct8027D460 *unkC;
};

struct Struct8027D460
{
    u8 filler0[0x10];
    void *unk10;
    struct Struct8027D460_sub *unk14;
};

struct Struct8027D4D4_sub
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0x10];
    void *unk14;
    u8 unk18[0x2C-0x18];
    Vec3f unk2C;
    struct Struct8027C988 unk38;
};

struct Struct8027D4D4
{
    u8 filler0[0x10];
    void *unk10;
    void (*unk14)(int, struct Struct8027D4D4 *, void *);
    u8 filler18[4];
    struct Struct8027D4D4_sub *unk1C;
    /*
    s16 unk20;
    s16 unk22;
    s16 unk24;
    */
    Vec3s unk20;
};

extern struct Struct8027B110 *D_8032CF94;  // possibly?
extern float D_8033B00C;

extern struct Struct8032CFA4 *D_8032CFA4;

extern struct Struct8027B6C4 *D_8032CF98;

extern Mtx4x4f D_8033A778[];

extern struct Struct8027B9A8 *D_8032CF9C;


extern u8 D_8033A741;
extern u8 D_8033A742;
extern s8 D_8033A744;
extern s8 D_8033A745;
extern s8 D_8033A746;
extern s16 D_8033A74C;
extern s16 D_8033A748;
extern s16 D_8033A74A;
extern s16 D_8033A74E;
extern s16 D_8033A750;
extern s16 D_8033A752;
extern s16 D_8033A754;

extern struct Struct8032CF10 D_8032CF10[];
extern struct Struct8032CF10 D_8032CF50[];

extern void *D_8033A160;
extern struct Struct8032CF90 *D_8032CF90;

//Struct8033A140?
struct Struct8032CE60 *D_8032CE60 = (struct Struct8032CE60 *)&D_8033A140;
void **gLoadedGeoLayouts = &D_8033A160;
struct Area *D_8032CE68 = D_8033A560;
struct Area *D_8032CE6C = NULL;

extern void *D_8032CE9C[];
extern u8 D_8032CEEC[];
extern void *D_8033AF78[];

void func_8027A220(Vp *a, Vp *b, u8 c, u8 d, u8 e)
{
    u16 sp6 = ((c >> 3) << 11) | ((d >> 3) << 6) | ((e >> 3) << 1) | 1;

    D_8032CE80 = (sp6 << 16) | sp6;
    D_8032CE74 = a;
    D_8032CE78 = b;
}

void func_8027A28C(u8 a, u8 b, u8 c)
{
    u16 sp6 = ((a >> 3) << 11) | ((b >> 3) << 6) | ((c >> 3) << 1) | 1;

    D_8032CE84 = (sp6 << 16) | sp6;
    D_8032CE88 = a;
    D_8032CE8C = b;
    D_8032CE90 = c;
}

void IntroPrintText(void)
{
    if ((D_8032C694 & 0x1F) < 20)
    {
        if (gControllerBits == 0)
        {
            PrintXY(160, 20, "NO CONTROLLER");
        }
        else
        {
            PrintXY(60, 38, "PRESS");
            PrintXY(60, 20, "START");
        }
    }
}

u32 func_8027A38C(struct Object *o)
{
    int sp1C;
    void *sp18 = virtual_to_segmented(0x13, o->unk20C);

    for (sp1C = 0; sp1C < 20; sp1C++)
    {
        if (D_8032CE9C[sp1C] == sp18)
            return D_8032CEEC[sp1C];
    }
    return 0;
}

struct ObjectWarpNode *func_8027A418(u8 a)
{
    struct ObjectWarpNode *sp4 = NULL;

    for (sp4 = D_8032CE6C->unk14; sp4 != NULL; sp4 = sp4->unk8)
    {
        if (sp4->node.id == a)
            break;
    }
    return sp4;
}

struct ObjectWarpNode *func_8027A478(struct Object *o)
{
    u8 sp1F = (o->unk188 & 0xFF0000) >> 16;

    return func_8027A418(sp1F);
}

void func_8027A4C4(void)
{
    struct ObjectWarpNode *sp24;
    struct Object *sp20 = D_8038BD98;

    do
    {
        struct Object *sp1C = sp20;

        if (sp1C->active && func_8027A38C(sp1C) != 0)
        {
            sp24 = func_8027A478(sp1C);
            if (sp24 != NULL)
                sp24->object = sp1C;
        }
    } while ((sp20 = sp20->gfx.unk8) != D_8038BD98);
}

void func_8027A554(void)
{
    int sp4;

    D_8032CE6C = NULL;
    D_8033A740 = 0;
    D_8033A743 = 0;
    D_8032CE60->unkC = -1;
    for (sp4 = 0; sp4 < 8; sp4++)
    {
        D_8033A560[sp4].index = sp4;
        D_8033A560[sp4].unk01 = 0;
        D_8033A560[sp4].unk02 = 0;
        D_8033A560[sp4].unk04 = 0;
        D_8033A560[sp4].unk08 = 0;
        D_8033A560[sp4].unk0C = 0;
        D_8033A560[sp4].unk10 = 0;
        D_8033A560[sp4].unk14 = 0;
        D_8033A560[sp4].paintingWarpNodes = NULL;
        D_8033A560[sp4].unk1C = 0;
        D_8033A560[sp4].unk20 = 0;
        D_8033A560[sp4].unk24 = 0;
        D_8033A560[sp4].unk28 = 0;
        D_8033A560[sp4].unk2C = 0;
        D_8033A560[sp4].unk30 = 0;
        D_8033A560[sp4].unk34[0] = 255;
        D_8033A560[sp4].unk35 = 255;
        D_8033A560[sp4].unk36 = 0;
        D_8033A560[sp4].unk38 = 0;
    }
}

void func_8027A7C4(void)
{
    int sp1C;

    if (D_8032CE6C != NULL)
    {
        func_8037C360(D_8032CE6C->unk04, 2);
        D_8032CE6C = NULL;
        D_8033A740 = 0;
    }
    for (sp1C = 0; sp1C < 8; sp1C++)
    {
        if (D_8033A560[sp1C].unk04 != 0)
        {
            func_8037C360(D_8033A560[sp1C].unk04, 4);
            D_8033A560[sp1C].unk04 = 0;
        }
    }
}

void func_8027A894(int a)
{
    if (D_8032CE6C == NULL && D_8033A560[a].unk04 != 0)
    {
        D_8032CE6C = &D_8033A560[a];
        D_8033A75A = D_8032CE6C->index;
        if (D_8032CE6C->unk08 != 0)
            func_803833B8(a, D_8032CE6C->unk08, D_8032CE6C->unk0C, D_8032CE6C->unk10);
        if (D_8032CE6C->unk20 != 0)
            func_8029C830(0, D_8032CE6C->unk20);
        func_8027A4C4();
        func_8037C360(D_8032CE6C->unk04, 3);
    }
}

void func_8027A998(void)
{
    if (D_8032CE6C != NULL)
    {
        func_8029C75C(0, D_8032CE6C->index);
        func_8037C360(D_8032CE6C->unk04, 2);
        D_8032CE6C->unk01 = 0;
        D_8032CE6C = NULL;
        D_8033A740 = 0;
    }
}

void func_8027AA0C(void)
{
    func_80320890();
    func_8027A894(D_8032CE60->unkC);
    if (D_8032CE6C->index == D_8032CE60->unkC)
    {
        D_8032CE6C->unk01 |= 1;
        func_8029C830(0, D_8032CE60);
    }
}

void func_8027AA88(void)
{
    if (D_8032CE6C != NULL && (D_8032CE6C->unk01 & 1))
    {
        func_8029C75C(0, D_8032CE60->unkD);
        D_8032CE6C->unk01 &= ~1;
        if (D_8032CE6C->unk01 == 0)
            func_8027A998();
    }
}

void func_8027AB10(int a)
{
    int sp1C = D_8032CE6C->unk01;

    if (D_8033A75A != a)
    {
        func_8027A998();
        func_8027A894(a);
        D_8032CE6C->unk01 = sp1C;
        gMarioObject->unkE0 = 0;
    }
    if (sp1C & 1)
    {
        gMarioObject->gfx.unk18 = a, D_8032CE60->unkC = a;
    }
}

void func_8027ABB4(void)
{
    D_8032CFA8++;
    func_8029CF08(0);
}

void func_8027ABF0(s16 a, s16 b, u8 c, u8 d, u8 e)
{
    D_8033A740 = 1;
    D_8033A741 = a;
    D_8033A742 = b;
    D_8033A743 = 0;

    if (a & 1)
    {
        func_8027A28C(c, d, e);
    }
    else
    {
        c = D_8032CE88, d = D_8032CE8C, e = D_8032CE90;
    }

    if (a < 8)
    {
        D_8033A744 = c;
        D_8033A745 = d;
        D_8033A746 = e;
    }
    else
    {
        D_8033A744 = c;
        D_8033A745 = d;
        D_8033A746 = e;
        D_8033A74C = 160;
        D_8033A74E = 120;
        D_8033A750 = 160;
        D_8033A752 = 120;
        D_8033A754 = 0;
        if (a & 1)
        {
            D_8033A748 = 320;
            if (a >= 15)
                D_8033A74A = 16;
            else
                D_8033A74A = 0;
        }
        //L8027AD60
        else
        {
            if (a >= 14)
                D_8033A748 = 16;
            else
                D_8033A748 = 0;
            D_8033A74A = 320;
        }
    }
    //L8027AD94
}

void func_8027ADAC(s16 a, s16 b, u8 c, u8 d, u8 e, s16 f)
{
    D_8032CE7C = f;
    func_8027ABF0(a, b, c, d, e);
}

void func_8027AE04(void)
{
    if (D_8032CE6C != NULL && D_8033A743 == 0)
    {
        func_8027DB80(D_8032CE6C->unk04, D_8032CE74, D_8032CE78, D_8032CE80);
        {
            Gfx *g = gDisplayListHead++;
            g->words.w0 = 0x03800010;
            g->words.w1 = VIRTUAL_TO_PHYSICAL(D_8032CF00);
        }
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
        RenderHud();
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        func_802D61A8();
        func_802D9D5C();
        func_80256CA8();
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
        D_8033A75E = func_802DCD98();
        if (D_8033A75E != 0)
            D_8033A760 = D_8033A75E;
        //L8027AF90
        if (D_8032CE78 != NULL)
            func_8024798C(D_8032CE78);
        else
            gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
        //L8027AFEC
        if (D_8033A740 != 0)
        {
            if (D_8032CE7C == 0)
            {
                D_8033A740 = !func_802CC108(0, D_8033A741, D_8033A742, (u8 *)&D_8033A740 + 4);
                if (D_8033A740 == 0)
                {
                    if (D_8033A741 & 1)
                        D_8033A743 = 1;
                    else
                        func_8027A28C(0, 0, 0);
                }
                //L8027B080
            }
            //L8027B088
            else
            {
                D_8032CE7C--;
            }
        }
        //L8027B09C
    }
    //L8027B0A4
    else
    {
        func_802D61A8();
        if (D_8032CE78 != 0)
            DisplayInit(D_8032CE78, D_8032CE84);
        else
            ClearFrameBuffer(D_8032CE84);
    }
    //L8027B0E4
    D_8032CE74 = NULL;
    D_8032CE78 = 0;
}

void func_8027B110(struct Struct8027B110 *a)
{
    struct Struct8027B110_sub *sp2C;
    int i;
    int sp24 = (a->unk2 & 8) != 0;
    struct Struct8032CF10 *sp20 = &D_8032CF10[sp24];
    struct Struct8032CF10 *sp1C = &D_8032CF50[sp24];

    if (sp24 != 0)
    {
        gDPPipeSync(gDisplayListHead++);
        gSPSetGeometryMode(gDisplayListHead++, G_ZBUFFER);
    }
    //L8027B1BC
    for (i = 0; i < 8; i++)
    {
        if ((sp2C = a->unk14[i]) != NULL)
        {
            gDPSetRenderMode(gDisplayListHead++, sp20->unk0[i], sp1C->unk0[i]);
            while (sp2C != NULL)
            {
                gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(sp2C->unk0), G_MTX_MODELVIEW | G_MTX_LOAD);
                gSPDisplayList(gDisplayListHead++, sp2C->unk4);
                sp2C = sp2C->unk8;
            }
        }
        //L8027B2C8
    }
    if (sp24 != 0)
    {
        gDPPipeSync(gDisplayListHead++);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER);
    }
}

void func_8027B354(int a, s16 b)
{
    if (D_8032CF94 != 0)
    {
        struct Struct8027B110_sub *sp1C = SimpleAllocate(D_8033B018, 12);

        sp1C->unk0 = D_8033AF78[D_8033A770];
        sp1C->unk4 = a;
        sp1C->unk8 = 0;
        if (D_8032CF94->unk14[b] == 0)
            D_8032CF94->unk14[b] = sp1C;
        else
            D_8032CF94->unk34[b]->unk8 = sp1C;
        D_8032CF94->unk34[b] = sp1C;
    }
    //L8027B438
}

void func_8027B450(struct Struct8027B110 *a)
{
    int sp1C;

    if (D_8032CF94 == NULL && a->unk10 != 0)
    {
        D_8032CF94 = a;
        for (sp1C = 0; sp1C < 8; sp1C++)
            a->unk14[sp1C] = NULL;
        func_8027D8F8(a->unk10);
        func_8027B110(a);
        D_8032CF94 = NULL;
    }
}

void func_8027B4E8(struct Struct8027B4E8 *a)
{
    if (a->unk10 != 0)
    {
        Mtx *mtx = alloc_display_list(sizeof(*mtx));
        float left   = (D_8032CF90->unk16 - D_8032CF90->unk1A) / 2.0f * a->unk14;
        float right  = (D_8032CF90->unk16 + D_8032CF90->unk1A) / 2.0f * a->unk14;
        float top    = (D_8032CF90->unk18 - D_8032CF90->unk1C) / 2.0f * a->unk14;
        float bottom = (D_8032CF90->unk18 + D_8032CF90->unk1C) / 2.0f * a->unk14;

        guFrustum(mtx, left, right, bottom, top, -2.0f, 2.0f, 1.0f);

        // FIXME: What command is this?
        {
            Gfx *g = gDisplayListHead++;
            g->words.w0 = 0xB4000000;
            g->words.w1 = 0xFFFF;
        }

        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_LOAD);

        func_8027D8F8(a->unk10);

    }
}

void func_8027B6C4(struct Struct8027B6C4 *a)
{
    if (a->unk14 != NULL)
        a->unk14(1, a, D_8033A778[D_8033A770]);
    if (a->unk10 != NULL)
    {
        u16 perspNorm;
        Mtx *mtx = alloc_display_list(sizeof(*mtx));
        float aspect = (float)D_8032CF90->unk1A / (float)D_8032CF90->unk1C;

        guPerspective(mtx, &perspNorm, a->unk1C, aspect, a->unk20, a->unk22, 1.0f);

        // FIXME: What command is this?
        {
            Gfx *g = gDisplayListHead++;
            g->words.w0 = 0xB4000000;
            g->words.w1 = perspNorm;
        }

        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_LOAD);

        D_8032CF98 = a;
        func_8027D8F8(a->unk10);
        D_8032CF98 = NULL;
    }
}

void func_8027B840(struct Struct8027B840 *a)
{
    // Dunno what type this is
    struct Struct8032CF90 *sp1C = D_8033AF78[D_8033A770];
    s16 sp1A = -sp1C->unk1C;

    if (a->unk14 <= sp1A && sp1A < a->unk16)
    {
        if (a->unk10 != 0)
            func_8027D8F8(a->unk10);
    }
}

void func_8027B8D4(struct Struct8027B8D4 *a)
{
    struct Struct8027B8D4_sub *sp1C = a->unk10;
    int sp18;

    if (a->unk14 != NULL)
        a->unk14(1, a, D_8033A778[D_8033A770]);
    for (sp18 = 0; sp1C != NULL && a->unk1E > sp18; sp18++)
        sp1C = sp1C->unk8;
    if (sp1C != NULL)
        func_8027D8F8(sp1C);
}

void func_8027B9A8(struct Struct8027B9A8 *a)
{
    float sp28[4][4];
    s16 *sp24 = alloc_display_list(64);
    s16 *sp20 = alloc_display_list(64);

    if (a->unk14 != NULL)
        a->unk14(1, a, D_8033A778[D_8033A770]);
    func_8037A4B8(sp24, a->unk3A);
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0x01010040;
        g->words.w1 = VIRTUAL_TO_PHYSICAL(sp24);
    }
    func_80378F84(sp28, a->unk1C, a->unk28, a->unk38);
    mtxf_mul(D_8033A778[D_8033A770 + 1], sp28, D_8033A778[D_8033A770]);
    D_8033A770++;
    func_8037A434(sp20, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp20;
    if (a->unk10 != 0)
    {
        D_8032CF9C = a;
        a->unk34 = D_8033A778[D_8033A770];
        func_8027D8F8(a->unk10);
        D_8032CF9C = NULL;
    }
    D_8033A770--;
}

void func_8027BB64(struct Struct8027BB64 *a)
{
    float sp28[4][4];
    Vec3f sp1C;
    s16 *sp18 = alloc_display_list(64);

    vec3s_to_vec3f(sp1C, a->unk18);
    mtxf_rotate_zxy_and_translate(sp28, sp1C, a->unk1E);
    mtxf_mul(D_8033A778[D_8033A770 + 1], sp28, D_8033A778[D_8033A770]);
    D_8033A770++;
    func_8037A434(sp18, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp18;
    if (a->unk14 != 0)
        func_8027B354(a->unk14, a->unk2 >> 8);
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
    D_8033A770--;
}

void func_8027BC88(struct Struct8027BB64 *a)
{
    float sp28[4][4];
    Vec3f sp1C;
    s16 *sp18 = alloc_display_list(64);

    vec3s_to_vec3f(sp1C, a->unk18);
    mtxf_rotate_zxy_and_translate(sp28, sp1C, D_80385FDC);
    mtxf_mul(D_8033A778[D_8033A770 + 1], sp28, D_8033A778[D_8033A770]);
    D_8033A770++;
    func_8037A434(sp18, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp18;
    if (a->unk14 != 0)
        func_8027B354(a->unk14, a->unk2 >> 8);
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
    D_8033A770--;
}

void func_8027BDAC(struct Struct8027BB64 *a)
{
    float sp20[4][4];
    s16 *sp1C = alloc_display_list(64);

    mtxf_rotate_zxy_and_translate(sp20, D_80385FD0, a->unk18);
    mtxf_mul(D_8033A778[D_8033A770 + 1], sp20, D_8033A778[D_8033A770]);
    D_8033A770++;
    func_8037A434(sp1C, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp1C;
    if (a->unk14 != 0)
        func_8027B354(a->unk14, a->unk2 >> 8);
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
    D_8033A770--;
}

void func_8027BEC4(struct Struct8027BEC4 *a)
{
    UNUSED float sp28[4][4];
    Vec3f sp1C;
    s16 *sp18 = alloc_display_list(64);

    vec3f_set(sp1C, a->unk18, a->unk18, a->unk18);
    func_8037A29C(D_8033A778[D_8033A770 + 1], D_8033A778[D_8033A770], sp1C);
    D_8033A770++;
    func_8037A434(sp18, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp18;
    if (a->unk14 != 0)
        func_8027B354(a->unk14, a->unk2 >> 8);
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
    D_8033A770--;
}

void func_8027BFE4(struct Struct8027BB64 *a)
{
    Vec3f sp1C;
    s16 *sp18 = alloc_display_list(64);

    D_8033A770++;
    vec3s_to_vec3f(sp1C, a->unk18);
    func_80379798(D_8033A778[D_8033A770], D_8033A778[D_8033A770 - 1], sp1C, D_8032CF9C->unk38);
    if (D_8032CFA4 != NULL)
        func_8037A29C(D_8033A778[D_8033A770], D_8033A778[D_8033A770], D_8032CFA4->unk1C->unk2C);
    else if (D_8032CFA0 != NULL)
        func_8037A29C(D_8033A778[D_8033A770], D_8033A778[D_8033A770], D_8032CFA0->gfx.scale);

    func_8037A434(sp18, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp18;
    if (a->unk14 != 0)
        func_8027B354(a->unk14, a->unk2 >> 8);
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
    D_8033A770--;
}

void func_8027C18C(struct Struct8027C18C *a)
{
    if (a->unk14 != 0)
        func_8027B354(a->unk14, a->unk2 >> 8);
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
}

void func_8027C1F4(struct Struct8027C1F4 *a)
{
    if (a->unk14 != NULL)
    {
        int sp1C = a->unk14(1, a, D_8033A778[D_8033A770]);

        if (sp1C != 0)
        {
            func_8027B354(VIRTUAL_TO_PHYSICAL(sp1C), a->unk2 >> 8);
        }
    }
    //L8027C274
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
}

void func_8027C2A8(struct Struct8027C2A8 *a)
{
    int sp3C = 0;

    if (a->unk14 != NULL)
        sp3C = a->unk14(1, a, D_8033A778[D_8033A770]);
    if (sp3C != 0)
    {
        func_8027B354(VIRTUAL_TO_PHYSICAL(sp3C), a->unk2 >> 8);
    }
    else if (D_8032CF94 != NULL)
    {
        Gfx *sp38 = alloc_display_list(56);
        Gfx *sp34 = sp38;

        gDPPipeSync(sp34++);
        gDPSetCycleType(sp34++, G_CYC_FILL);
        gDPSetFillColor(sp34++, a->unk1C);
        gDPFillRectangle(sp34++, 0, 8, 319, 231);
        gDPPipeSync(sp34++);
        gDPSetCycleType(sp34++, G_CYC_1CYCLE);
        gSPEndDisplayList(sp34++);

        func_8027B354(VIRTUAL_TO_PHYSICAL(sp38), 0);
    }
    //L8027C48C
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
}

void func_8027C4C0(struct Struct8027C4C0 *a)
{
    float sp40[4][4];
    Vec3s sp38;
    Vec3f sp2C;
    s16 *sp28 = alloc_display_list(64);

    vec3s_copy(sp38, D_80385FDC);
    vec3f_set(sp2C, a->unk18, a->unk1A, a->unk1C);
    if (D_8033B008 == 1)
    {
        sp2C[0] += D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C;
        sp2C[1] += D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C;
        sp2C[2] += D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C;
        D_8033B008 = 5;
    }
    //L8027C640
    else
    {
        if (D_8033B008 == 3)
        {
            sp2C[0] += D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C;
            D_8033B010 += 4;
            sp2C[2] += D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C;
            D_8033B008 = 5;
        }
        //L8027C718
        else
        {
            if (D_8033B008 == 2)
            {
                D_8033B010 += 4;
                sp2C[1] += D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C;
                D_8033B010 += 4;
                D_8033B008 = 5;
            }
            //L8027C7B4
            else if (D_8033B008 == 4)
            {
                D_8033B010 += 12;
                D_8033B008 = 5;
            }
        }
        //L8027C7E8
    }
    //L8027C7E8
    if (D_8033B008 == 5)
    {
        sp38[0] = D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)];
        sp38[1] = D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)];
        sp38[2] = D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)];
    }
    //L8027C88C
    mtxf_rotate_xyz_and_translate(sp40, sp2C, sp38);
    mtxf_mul(D_8033A778[D_8033A770 + 1], sp40, D_8033A778[D_8033A770]);
    D_8033A770++;
    func_8037A434(sp28, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp28;
    if (a->unk14 != 0)
        func_8027B354(a->unk14, a->unk2 >> 8);
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
    D_8033A770--;
}

void func_8027C988(struct Struct8027C988 *a, int b)
{
    struct Struct8027C988_sub *sp1C = a->unk4;

    if (b != 0)
        a->unk8 = func_8037C844(a, &a->unkC);
    a->unkA = D_8032CFA8;
    if (sp1C->unk0 & 8)
        D_8033B008 = 2;
    else if (sp1C->unk0 & 0x10)
        D_8033B008 = 3;
    else if (sp1C->unk0 & 0x40)
        D_8033B008 = 4;
    else
        D_8033B008 = 1;
    //L8027CA50
    D_8033B00A = a->unk8;
    D_8033B009 = (sp1C->unk0 & 0x20) == 0;
    D_8033B010 = segmented_to_virtual(sp1C->unk10);
    D_8033B014 = segmented_to_virtual(sp1C->unkC);

    if (sp1C->unk2 == 0)
        D_8033B00C = 1.0f;
    else
        D_8033B00C = (float)a->unk2 / (float)sp1C->unk2;
}

void func_8027CB08(struct Struct8027CB08 *a)
{
    int sp94;
    float sp54[4][4];
    Vec3f sp48;
    Vec3f sp3C;
    float sp38;
    float sp34;
    float sp30;
    float sp2C;
    struct Struct8027CB08_sub *sp28;
    s16 *sp24;

    if (D_8032CF9C != NULL && D_8032CFA0 != NULL)
    {
        if (D_8032CFA4 != NULL)
        {
            func_8037A550(sp48, D_8033A778[D_8033A770], D_8032CF9C->unk34);
            sp34 = a->unk14;
        }
        else
        {
            vec3f_copy(sp48, D_8032CFA0->gfx.unk20);
            sp34 = a->unk14 * D_8032CFA0->gfx.scale[0];
        }
        //L8027CBC8
        sp38 = 1.0f;
        if (D_8033B009 != 0)
        {
            if (D_8033B008 == 1 || D_8033B008 == 3)
            {
                sp28 = a->unk10;
                if (sp28 != NULL && sp28->unk0 == 28)
                    sp38 = sp28->unk18;
                //L8027CC3C
                sp3C[0] = D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C * sp38;
                sp3C[1] = 0.0f;
                D_8033B010 += 4;
                sp3C[2] = D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C * sp38;
                D_8033B010 -= 12;
                sp30 = sins(D_8032CFA0->gfx.unk1A[1]);
                sp2C = coss(D_8032CFA0->gfx.unk1A[1]);

                sp48[0] += sp3C[0] * sp2C + sp3C[2] * sp30;
                sp48[2] += -sp3C[0] * sp30 + sp3C[2] * sp2C;
            }
        }
        //L8027CDBC
        sp94 = func_802CE86C(sp48[0], sp48[1], sp48[2], sp34, a->unk16, a->unk17);
        if (sp94 != 0)
        {
            sp24 = alloc_display_list(64);
            D_8033A770++;
            mtxf_translate(sp54, sp48);
            mtxf_mul(D_8033A778[D_8033A770], sp54, D_8032CF9C->unk34);
            func_8037A434(sp24, D_8033A778[D_8033A770]);
            D_8033AF78[D_8033A770] = sp24;
            if (D_8035FF44 == 1)
                func_8027B354(VIRTUAL_TO_PHYSICAL(sp94), 4);
            else if (D_8035FF45 == 1)
                func_8027B354(VIRTUAL_TO_PHYSICAL(sp94), 5);
            else
                func_8027B354(VIRTUAL_TO_PHYSICAL(sp94), 6);
            D_8033A770--;
        }
        //L8027CF34
    }
    //L8027CF34
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
}

extern float D_80335DF8;

int func_8027CF68(struct Struct8027D14C *a, Mtx4x4f b)
{
    s16 spE;
    s16 spC;
    struct Struct8027D14C_sub *sp8;
    float sp4;

    if (a->unk2 & 0x10)
        return 0;
    sp8 = a->unk14;
    spC = (D_8032CF98->unk1C / 2.0f + 1.0f) * 32768.0f / 180.0f + 0.5f;
    sp4 = -b[3][2] * sins(spC) / coss(spC);
    if (sp8 != NULL && sp8->unk0 == 47)
        spE = (float)sp8->unk14;  //! Why is there a float cast?
    else
        spE = 300;
    if (b[3][2] > -100.0f + spE)
        return 0;
    if (b[3][2] < -20000.0f - spE)
        return 0;
    if (b[3][0] > sp4 + spE)
        return 0;
    if (b[3][0] < -sp4 - spE)
        return 0;
    return 1;
}

void func_8027D14C(struct Struct8027D14C *a)
{
    Mtx4x4f sp30;
    int sp2C = (a->unk2 & 0x20) != 0;

    if (a->unk18 == D_8032CF90->unk14)
    {
        if (a->unk50 != NULL)
        {
            mtxf_mul(D_8033A778[D_8033A770 + 1], (void *)a->unk50, D_8033A778[D_8033A770]);
        }
        else if (a->unk2 & 4)
        {
            func_80379798(D_8033A778[D_8033A770 + 1], D_8033A778[D_8033A770], a->unk20, D_8032CF9C->unk38);
        }
        else
        {
            mtxf_rotate_zxy_and_translate(sp30, a->unk20, a->unk1A);
            mtxf_mul(D_8033A778[D_8033A770 + 1], sp30, D_8033A778[D_8033A770]);
        }

        func_8037A29C(D_8033A778[D_8033A770 + 1], D_8033A778[D_8033A770 + 1], a->unk2C);
        a->unk50 = D_8033A778[++D_8033A770];
        a->unk54 = D_8033A778[D_8033A770][3][0];
        a->unk58 = D_8033A778[D_8033A770][3][1];
        a->unk5C = D_8033A778[D_8033A770][3][2];
        // FIXME: correct types
        if (a->unk38.unk4 != 0)
            func_8027C988(&a->unk38, sp2C);
        if (func_8027CF68(a, D_8033A778[D_8033A770]))
        {
            s16 *sp28 = alloc_display_list(64);

            func_8037A434(sp28, D_8033A778[D_8033A770]);
            D_8033AF78[D_8033A770] = sp28;
            if (a->unk14 != NULL)
            {
                D_8032CFA0 = (struct Object *)a;
                a->unk14->unkC = a;
                func_8027D8F8(a->unk14);
                a->unk14->unkC = NULL;
                D_8032CFA0 = NULL;
            }
            if (a->unk10 != NULL)
                func_8027D8F8(a->unk10);
        }
        //L8027D420
        D_8033A770--;
        D_8033B008 = 0;
        a->unk50 = NULL;
    }
}

void func_8027D460(struct Struct8027D460 *a)
{
    if (a->unk14 != NULL)
    {
        a->unk14->unkC = a;
        func_8027D8F8(a->unk14);
        a->unk14->unkC = NULL;
    }
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
}

void func_8027D4D4(struct Struct8027D4D4 *a)
{
    Mtx4x4f sp30;
    Vec3f sp24;
    UNUSED s16 *sp20 = alloc_display_list(64);

    if (a->unk14 != NULL)
        a->unk14(1, a, D_8033A778[D_8033A770]);
    if (a->unk1C != NULL && a->unk1C->unk14 != NULL)
    {
        UNUSED int sp1C = (a->unk1C->unk2 & 0x20) != 0;

        sp24[0] = a->unk20[0] / 4.0f;
        sp24[1] = a->unk20[1] / 4.0f;
        sp24[2] = a->unk20[2] / 4.0f;
        /*
        sp24[0] = a->unk20 / 4.0f;
        sp24[1] = a->unk22 / 4.0f;
        sp24[2] = a->unk24 / 4.0f;
        */
        mtxf_translate(sp30, sp24);
        mtxf_copy(D_8033A778[D_8033A770 + 1], (void *)D_8032CFA0->gfx.unk50);
        D_8033A778[D_8033A770 + 1][3][0] = D_8033A778[D_8033A770][3][0];
        D_8033A778[D_8033A770 + 1][3][1] = D_8033A778[D_8033A770][3][1];
        D_8033A778[D_8033A770 + 1][3][2] = D_8033A778[D_8033A770][3][2];
        mtxf_mul(D_8033A778[D_8033A770 + 1], sp30, D_8033A778[D_8033A770 + 1]);
        func_8037A29C(D_8033A778[D_8033A770 + 1], D_8033A778[D_8033A770 + 1], a->unk1C->unk2C);
        if (a->unk14 != NULL)
            a->unk14(5, a, D_8033A778[D_8033A770 + 1]);
        D_8033A770++;
        func_8037A434(sp20, D_8033A778[D_8033A770]);
        D_8033AF78[D_8033A770] = sp20;
        D_8033AFF8 = D_8033B008;
        D_8033AFF9 = D_8033B009;
        D_8033AFFA = D_8033B00A;
        D_8033AFFC = D_8033B00C;
        D_8033B000 = D_8033B010;
        D_8033B004 = D_8033B014;
        D_8033B008 = 0;
        D_8032CFA4 = (void *)a;
        if (a->unk1C->unk38.unk4 != 0)
            func_8027C988(&a->unk1C->unk38, sp1C);
        //L8027D7F8
        func_8027D8F8(a->unk1C->unk14);
        D_8032CFA4 = NULL;
        D_8033B008 = D_8033AFF8;
        D_8033B009 = D_8033AFF9;
        D_8033B00A = D_8033AFFA;
        D_8033B00C = D_8033AFFC;
        D_8033B010 = D_8033B000;
        D_8033B014 = D_8033B004;
        D_8033A770--;
    }
    //L8027D884
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
}

void func_8027D8B8(struct Struct8027D8B8 *a)
{
    if (a->unk10 != NULL)
        func_8027D8F8(a->unk10);
}

void func_8027D8F8(void *a)
{
    s16 sp2E = TRUE;
    struct Struct8027D8F8 *sp28 = a;
    struct Struct8027D8F8_sub *sp24 = sp28->unkC;

    if (sp24 != NULL)
        sp2E = (sp24->unk0 != 0x10C);
    //L8027D944
    do
    {
        if (sp28->unk2 & 1)
        {
            if (sp28->unk2 & 2)
            {
                func_8027D8B8((void *)sp28);
            }
            //L8027D97C
            else
            {
                switch (sp28->unk0)
                {
                case 2:
                    func_8027B4E8((void *)sp28);
                    break;
                case 259:
                    func_8027B6C4((void *)sp28);
                    break;
                case 4:
                    func_8027B450((void *)sp28);
                    break;
                case 11:
                    func_8027B840((void *)sp28);
                    break;
                case 268:
                    func_8027B8D4((void *)sp28);
                    break;
                case 276:
                    func_8027B9A8((void *)sp28);
                    break;
                case 21:
                    func_8027BB64((void *)sp28);
                    break;
                case 22:
                    func_8027BC88((void *)sp28);
                    break;
                case 23:
                    func_8027BDAC((void *)sp28);
                    break;
                case 24:
                    func_8027D14C((void *)sp28);
                    break;
                case 25:
                    func_8027C4C0((void *)sp28);
                    break;
                case 26:
                    func_8027BFE4((void *)sp28);
                    break;
                case 27:
                    func_8027C18C((void *)sp28);
                    break;
                case 28:
                    func_8027BEC4((void *)sp28);
                    break;
                case 40:
                    func_8027CB08((void *)sp28);
                    break;
                case 41:
                    func_8027D460((void *)sp28);
                    break;
                case 298:
                    func_8027C1F4((void *)sp28);
                    break;
                case 300:
                    func_8027C2A8((void *)sp28);
                    break;
                case 302:
                    func_8027D4D4((void *)sp28);
                    break;
                default:
                    func_8027D8B8((void *)sp28);
                    break;
                }
            }
            //L8027DB20
        }
        //L8027DB28
        else
        {
            if (sp28->unk0 == 24)
                sp28->unk50 = 0;
        }
        //L8027DB44
    } while (sp2E && (sp28 = sp28->unk8) != a);
}

void func_8027DB80(struct Struct8032CF90 *a, Vp *b, Vp *c, int d)
{
    UNUSED int unused;

    if (a->unk2 & 1)
    {
        s16 *sp30;
        Vp *viewport = alloc_display_list(sizeof(*viewport));

        D_8033B018 = func_80278464(PoolAvailable() - 16, 0);
        sp30 = alloc_display_list(64);
        D_8033A770 = 0;
        D_8033B008 = 0;
        vec3s_set(viewport->vp.vtrans, a->unk16 * 4, a->unk18 * 4, 511);
        vec3s_set(viewport->vp.vscale, a->unk1A * 4, a->unk1C * 4, 511);
        if (b != NULL)
        {
            ClearFrameBuffer(d);
            func_8024798C(b);
            *viewport = *b;
        }
        //L8027DC94
        else if (c != NULL)
        {
            ClearFrameBuffer(d);
            func_8024798C(c);
        }
        //L8027DCB0
        mtxf_identity(D_8033A778[D_8033A770]);
        func_8037A434(sp30, D_8033A778[D_8033A770]);
        D_8033AF78[D_8033A770] = sp30;
        gSPViewport(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(viewport));
        gSPMatrix(gDisplayListHead++,
            VIRTUAL_TO_PHYSICAL(D_8033AF78[D_8033A770]),
            G_MTX_MODELVIEW | G_MTX_LOAD);
        D_8032CF90 = a;
        if (a->unk10 != NULL)
            func_8027D8F8(a->unk10);
        D_8032CF90 = NULL;
        if (gShowDebugText)
            PrintInt(180, 36, "MEM %d", D_8033B018->unk0 - D_8033B018->unk4);
        _pool_free(D_8033B018);
    }
    //L8027DE10
}
