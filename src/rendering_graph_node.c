#include <ultra64.h>

#include "sm64.h"
#include "main.h"
#include "display.h"
#include "print.h"
#include "math_util.h"
#include "rendering.h"
#include "rotate.h"
#include "memory.h"
#include "game.h"
#include "rendering_graph_node.h"

struct Struct8032CF10
{
    u32 unk0[8];
};

extern struct Struct8032CF10 D_8032CF10[];
extern struct Struct8032CF10 D_8032CF50[];

extern Vec3s D_80385FDC;

extern float D_8033B00C;

extern Mat4 D_8033A778[];

extern void *D_8033AF78[];

void func_8027B110(struct GraphNode004 *a)
{
    struct GraphNode004_sub *sp2C;
    int i;
    int sp24 = (a->node.flags & GRAPH_RENDER_08) != 0;
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

void func_8027B354(void *dlist, s16 b)
{
    if (D_8032CF94 != 0)
    {
        struct GraphNode004_sub *sp1C = SimpleAllocate(D_8033B018, 12);

        sp1C->unk0 = D_8033AF78[D_8033A770];
        sp1C->unk4 = dlist;
        sp1C->unk8 = 0;
        if (D_8032CF94->unk14[b] == 0)
            D_8032CF94->unk14[b] = sp1C;
        else
            D_8032CF94->unk34[b]->unk8 = sp1C;
        D_8032CF94->unk34[b] = sp1C;
    }
    //L8027B438
}

void func_8027B450(struct GraphNode004 *a) // 004
{
    int sp1C;

    if (D_8032CF94 == NULL && a->node.children != NULL)
    {
        D_8032CF94 = a;
        for (sp1C = 0; sp1C < 8; sp1C++)
            a->unk14[sp1C] = NULL;
        func_8027D8F8(a->node.children);
        func_8027B110(a);
        D_8032CF94 = NULL;
    }
}

void func_8027B4E8(struct GraphNode002 *a)
{
    if (a->node.children != NULL)
    {
        Mtx *mtx = alloc_display_list(sizeof(*mtx));
        float left   = (D_8032CF90->x - D_8032CF90->width) / 2.0f * a->unk14;
        float right  = (D_8032CF90->x + D_8032CF90->width) / 2.0f * a->unk14;
        float top    = (D_8032CF90->y - D_8032CF90->height) / 2.0f * a->unk14;
        float bottom = (D_8032CF90->y + D_8032CF90->height) / 2.0f * a->unk14;

        guOrtho(mtx, left, right, bottom, top, -2.0f, 2.0f, 1.0f);

        // FIXME: What command is this?
        {
            Gfx *g = gDisplayListHead++;
            g->words.w0 = 0xB4000000;
            g->words.w1 = 0xFFFF;
        }

        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_LOAD);

        func_8027D8F8(a->node.children);

    }
}

void func_8027B6C4(struct GraphNodeCamFrustum *a)
{
    if (a->fnNode.func != NULL)
        a->fnNode.func(1, &a->fnNode.node, D_8033A778[D_8033A770]);
    if (a->fnNode.node.children != NULL)
    {
        u16 perspNorm;
        Mtx *mtx = alloc_display_list(sizeof(*mtx));
        float aspect = (float)D_8032CF90->width / (float)D_8032CF90->height;

        guPerspective(mtx, &perspNorm, a->fov, aspect, a->near, a->far, 1.0f);

        // FIXME: What command is this?
        {
            Gfx *g = gDisplayListHead++;
            g->words.w0 = 0xB4000000;
            g->words.w1 = perspNorm;
        }

        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_LOAD);

        D_8032CF98 = a;
        func_8027D8F8(a->fnNode.node.children);
        D_8032CF98 = NULL;
    }
}

void func_8027B840(struct GraphNode00B *a)
{
    // Dunno what type this is
    struct GraphNodeScreenArea *sp1C = D_8033AF78[D_8033A770];
    s16 sp1A = -sp1C->height;

    if (a->unk14 <= sp1A && sp1A < a->unk16)
    {
        if (a->node.children != 0)
            func_8027D8F8(a->node.children);
    }
}

void func_8027B8D4(struct GraphNode10C *a)
{
    struct GraphNode *sp1C = a->fnNode.node.children;
    int sp18;

    if (a->fnNode.func != NULL)
        a->fnNode.func(1, &a->fnNode.node, D_8033A778[D_8033A770]);
    for (sp18 = 0; sp1C != NULL && a->unk1E > sp18; sp18++)
        sp1C = sp1C->next;
    if (sp1C != NULL)
        func_8027D8F8(sp1C);
}

void func_8027B9A8(struct GraphNode114 *a) // 114
{
    float sp28[4][4];
    s16 *sp24 = alloc_display_list(64);
    s16 *sp20 = alloc_display_list(64);

    if (a->fnNode.func != NULL)
        a->fnNode.func(1, &a->fnNode.node, D_8033A778[D_8033A770]);
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
    if (a->fnNode.node.children != 0)
    {
        D_8032CF9C = a;
        a->unk34 = D_8033A778[D_8033A770];
        func_8027D8F8(a->fnNode.node.children);
        D_8032CF9C = NULL;
    }
    D_8033A770--;
}

void func_8027BB64(struct GraphNode015 *a)
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
    if (a->dlist != NULL)
        func_8027B354(a->dlist, a->node.flags >> 8);
    if (a->node.children != NULL)
        func_8027D8F8(a->node.children);
    D_8033A770--;
}

void func_8027BC88(struct GraphNode016 *a)
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
    if (a->dlist != NULL)
        func_8027B354(a->dlist, a->node.flags >> 8);
    if (a->node.children != NULL)
        func_8027D8F8(a->node.children);
    D_8033A770--;
}

void func_8027BDAC(struct GraphNode017 *a)
{
    float sp20[4][4];
    s16 *sp1C = alloc_display_list(64);

    mtxf_rotate_zxy_and_translate(sp20, D_80385FD0, a->unk18);
    mtxf_mul(D_8033A778[D_8033A770 + 1], sp20, D_8033A778[D_8033A770]);
    D_8033A770++;
    func_8037A434(sp1C, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp1C;
    if (a->dlist != NULL)
        func_8027B354(a->dlist, a->node.flags >> 8);
    if (a->node.children != NULL)
        func_8027D8F8(a->node.children);
    D_8033A770--;
}

void func_8027BEC4(struct GraphNode01C *a)
{
    UNUSED float sp28[4][4];
    Vec3f sp1C;
    s16 *sp18 = alloc_display_list(64);

    vec3f_set(sp1C, a->unk18, a->unk18, a->unk18);
    func_8037A29C(D_8033A778[D_8033A770 + 1], D_8033A778[D_8033A770], sp1C);
    D_8033A770++;
    func_8037A434(sp18, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp18;
    if (a->dlist != NULL)
        func_8027B354(a->dlist, a->node.flags >> 8);
    if (a->node.children != NULL)
        func_8027D8F8(a->node.children);
    D_8033A770--;
}

void func_8027BFE4(struct GraphNode01A *a)
{
    Vec3f sp1C;
    s16 *sp18 = alloc_display_list(64);

    D_8033A770++;
    vec3s_to_vec3f(sp1C, a->unk18);
    func_80379798(D_8033A778[D_8033A770], D_8033A778[D_8033A770 - 1], sp1C, D_8032CF9C->unk38);
    if (D_8032CFA4 != NULL)
        func_8037A29C(D_8033A778[D_8033A770], D_8033A778[D_8033A770], D_8032CFA4->unk1C->scale);
    else if (D_8032CFA0 != NULL)
        func_8037A29C(D_8033A778[D_8033A770], D_8033A778[D_8033A770], D_8032CFA0->scale);

    func_8037A434(sp18, D_8033A778[D_8033A770]);
    D_8033AF78[D_8033A770] = sp18;
    if (a->dlist != NULL)
        func_8027B354(a->dlist, a->node.flags >> 8);
    if (a->node.children != NULL)
        func_8027D8F8(a->node.children);
    D_8033A770--;
}

void func_8027C18C(struct GraphNode01B *a)
{
    if (a->dlist != NULL)
        func_8027B354(a->dlist, a->node.flags >> 8);
    if (a->node.children != NULL)
        func_8027D8F8(a->node.children);
}

void func_8027C1F4(struct GraphNode12A *a)
{
    if (a->fnNode.func != NULL)
    {
        int sp1C = a->fnNode.func(1, &a->fnNode.node, (struct Struct80278464 *) D_8033A778[D_8033A770]);

        if (sp1C != 0)
        {
            func_8027B354((void *)VIRTUAL_TO_PHYSICAL(sp1C), a->fnNode.node.flags >> 8);
        }
    }
    //L8027C274
    if (a->fnNode.node.children != NULL)
        func_8027D8F8(a->fnNode.node.children);
}

void func_8027C2A8(struct GraphNode12C *a)
{
    int sp3C = 0;

    if (a->fnNode.func != NULL)
        sp3C = a->fnNode.func(1, &a->fnNode.node, (struct Struct80278464 *) D_8033A778[D_8033A770]);
    if (sp3C != 0)
    {
        func_8027B354((void *)VIRTUAL_TO_PHYSICAL(sp3C), a->fnNode.node.flags >> 8);
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

        func_8027B354((void *)VIRTUAL_TO_PHYSICAL(sp38), 0);
    }
    //L8027C48C
    if (a->fnNode.node.children != NULL)
        func_8027D8F8(a->fnNode.node.children);
}

void func_8027C4C0(struct GraphNode019 *a)
{
    float sp40[4][4];
    Vec3s sp38;
    Vec3f sp2C;
    s16 *sp28 = alloc_display_list(64);

    vec3s_copy(sp38, D_80385FDC);
    vec3f_set(sp2C, a->relativePos[0], a->relativePos[1], a->relativePos[2]);
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
            D_8033B010 += 2;
            sp2C[2] += D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C;
            D_8033B008 = 5;
        }
        //L8027C718
        else
        {
            if (D_8033B008 == 2)
            {
                D_8033B010 += 2;
                sp2C[1] += D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C;
                D_8033B010 += 2;
                D_8033B008 = 5;
            }
            //L8027C7B4
            else if (D_8033B008 == 4)
            {
                D_8033B010 += 6;
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
    if (a->dlist != NULL)
        func_8027B354(a->dlist, a->node.flags >> 8);
    if (a->node.children != NULL)
        func_8027D8F8(a->node.children);
    D_8033A770--;
}

void func_8027C988(struct GraphNode018_sub *a, int b)
{
    struct UnknownStruct5 *sp1C = a->unk04;

    if (b != 0)
        a->animFrame = func_8037C844(a, &a->unk0C);
    a->animTimer = D_8032CFA8;
    if (sp1C->unk00 & 8)
        D_8033B008 = 2;
    else if (sp1C->unk00 & 0x10)
        D_8033B008 = 3;
    else if (sp1C->unk00 & 0x40)
        D_8033B008 = 4;
    else
        D_8033B008 = 1;
    //L8027CA50
    D_8033B00A = a->animFrame;
    D_8033B009 = (sp1C->unk00 & 0x20) == 0;
    D_8033B010 = segmented_to_virtual(sp1C->unk10);
    D_8033B014 = segmented_to_virtual(sp1C->unk0C);

    if (sp1C->unk02 == 0)
        D_8033B00C = 1.0f;
    else
        D_8033B00C = (float)a->unk02 / (float)sp1C->unk02;
}

void func_8027CB08(struct GraphNode028 *a)
{
    int sp94;
    float sp54[4][4];
    Vec3f sp48;
    Vec3f sp3C;
    float sp38;
    float sp34;
    float sp30;
    float sp2C;
    struct GraphNode *sp28;
    s16 *sp24;

    if (D_8032CF9C != NULL && D_8032CFA0 != NULL)
    {
        if (D_8032CFA4 != NULL)
        {
            func_8037A550(sp48, D_8033A778[D_8033A770], D_8032CF9C->unk34);
            sp34 = a->shadowScale;
        }
        else
        {
            vec3f_copy(sp48, D_8032CFA0->pos);
            sp34 = a->shadowScale * D_8032CFA0->scale[0];
        }
        //L8027CBC8
        sp38 = 1.0f;
        if (D_8033B009 != 0)
        {
            if (D_8033B008 == 1 || D_8033B008 == 3)
            {
                sp28 = a->node.children;
                if (sp28 != NULL && sp28->type == GRAPH_NODE_TYPE_01C)
                    sp38 = ((struct GraphNode01C *)sp28)->unk18;
                //L8027CC3C
                sp3C[0] = D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C * sp38;
                sp3C[1] = 0.0f;
                D_8033B010 += 2;
                sp3C[2] = D_8033B014[func_8037C7D8(D_8033B00A, &D_8033B010)] * D_8033B00C * sp38;
                D_8033B010 -= 6;
                sp30 = sins(D_8032CFA0->angle[1]);
                sp2C = coss(D_8032CFA0->angle[1]);

                sp48[0] += sp3C[0] * sp2C + sp3C[2] * sp30;
                sp48[2] += -sp3C[0] * sp30 + sp3C[2] * sp2C;
            }
        }
        //L8027CDBC
        sp94 = func_802CE86C(sp48[0], sp48[1], sp48[2], sp34, a->shadowSolidity, a->shadowType);
        if (sp94 != 0)
        {
            sp24 = alloc_display_list(64);
            D_8033A770++;
            mtxf_translate(sp54, sp48);
            mtxf_mul(D_8033A778[D_8033A770], sp54, D_8032CF9C->unk34);
            func_8037A434(sp24, D_8033A778[D_8033A770]);
            D_8033AF78[D_8033A770] = sp24;
            if (D_8035FF44 == 1)
                func_8027B354((void *)VIRTUAL_TO_PHYSICAL(sp94), 4);
            else if (D_8035FF45 == 1)
                func_8027B354((void *)VIRTUAL_TO_PHYSICAL(sp94), 5);
            else
                func_8027B354((void *)VIRTUAL_TO_PHYSICAL(sp94), 6);
            D_8033A770--;
        }
        //L8027CF34
    }
    //L8027CF34
    if (a->node.children != NULL)
        func_8027D8F8(a->node.children);
}

extern float D_80335DF8;

int func_8027CF68(struct GraphNode018 *a, Mat4 b)
{
    s16 spE;
    s16 spC;
    struct GraphNode *sp8;
    float sp4;

    if (a->node.flags & 0x10)
        return 0;
    sp8 = a->unk14;
    spC = (D_8032CF98->fov / 2.0f + 1.0f) * 32768.0f / 180.0f + 0.5f;
    sp4 = -b[3][2] * sins(spC) / coss(spC);
    if (sp8 != NULL && sp8->type == GRAPH_NODE_TYPE_02F)
        spE = (float)((struct GraphNode02F *)sp8)->unk14;  //! Why is there a float cast?
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

void func_8027D14C(struct GraphNode018 *a)
{
    Mat4 sp30;
    int sp2C = (a->node.flags & GRAPH_RENDER_20) != 0;

    if (a->unk18 == D_8032CF90->unk14)
    {
        if (a->unk50 != NULL)
        {
            mtxf_mul(D_8033A778[D_8033A770 + 1], (void *)a->unk50, D_8033A778[D_8033A770]);
        }
        else if (a->node.flags & 4)
        {
            func_80379798(D_8033A778[D_8033A770 + 1], D_8033A778[D_8033A770], a->pos, D_8032CF9C->unk38);
        }
        else
        {
            mtxf_rotate_zxy_and_translate(sp30, a->pos, a->angle);
            mtxf_mul(D_8033A778[D_8033A770 + 1], sp30, D_8033A778[D_8033A770]);
        }

        func_8037A29C(D_8033A778[D_8033A770 + 1], D_8033A778[D_8033A770 + 1], a->scale);
        a->unk50 = D_8033A778[++D_8033A770];
        a->unk54 = D_8033A778[D_8033A770][3][0];
        a->unk58 = D_8033A778[D_8033A770][3][1];
        a->unk5C = D_8033A778[D_8033A770][3][2];
        // FIXME: correct types
        if (a->unk38.unk04 != 0)
            func_8027C988(&a->unk38, sp2C);
        if (func_8027CF68(a, D_8033A778[D_8033A770]))
        {
            s16 *sp28 = alloc_display_list(64);

            func_8037A434(sp28, D_8033A778[D_8033A770]);
            D_8033AF78[D_8033A770] = sp28;
            if (a->unk14 != NULL)
            {
                D_8032CFA0 = a;
                a->unk14->parent = &a->node;
                func_8027D8F8(a->unk14);
                a->unk14->parent = NULL;
                D_8032CFA0 = NULL;
            }
            if (a->node.children != NULL)
                func_8027D8F8(a->node.children);
        }
        //L8027D420
        D_8033A770--;
        D_8033B008 = 0;
        a->unk50 = NULL;
    }
}

void func_8027D460(struct GraphNode029 *a)
{
    if (a->unk14 != NULL)
    {
        a->unk14->parent = (struct GraphNode *) a;
        func_8027D8F8(a->unk14);
        a->unk14->parent = NULL;
    }
    if (a->node.children != NULL)
        func_8027D8F8(a->node.children);
}

void func_8027D4D4(struct GraphNode12E *a)
{
    Mat4 sp30;
    Vec3f sp24;
    UNUSED s16 *sp20 = alloc_display_list(64);

    if (a->fnNode.func != NULL)
        a->fnNode.func(1, &a->fnNode.node, D_8033A778[D_8033A770]);
    if (a->unk1C != NULL && a->unk1C->unk14 != NULL)
    {
        UNUSED int sp1C = (a->unk1C->node.flags & GRAPH_RENDER_20) != 0;

        sp24[0] = a->unk20[0] / 4.0f;
        sp24[1] = a->unk20[1] / 4.0f;
        sp24[2] = a->unk20[2] / 4.0f;
        /*
        sp24[0] = a->unk20 / 4.0f;
        sp24[1] = a->unk22 / 4.0f;
        sp24[2] = a->unk24 / 4.0f;
        */
        mtxf_translate(sp30, sp24);
        mtxf_copy(D_8033A778[D_8033A770 + 1], (void *)D_8032CFA0->unk50);
        D_8033A778[D_8033A770 + 1][3][0] = D_8033A778[D_8033A770][3][0];
        D_8033A778[D_8033A770 + 1][3][1] = D_8033A778[D_8033A770][3][1];
        D_8033A778[D_8033A770 + 1][3][2] = D_8033A778[D_8033A770][3][2];
        mtxf_mul(D_8033A778[D_8033A770 + 1], sp30, D_8033A778[D_8033A770 + 1]);
        func_8037A29C(D_8033A778[D_8033A770 + 1], D_8033A778[D_8033A770 + 1], a->unk1C->scale);
        if (a->fnNode.func != NULL)
            a->fnNode.func(5, &a->fnNode.node, (struct Struct80278464 *) D_8033A778[D_8033A770 + 1]);
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
        if (a->unk1C->unk38.unk04 != 0)
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
    if (a->fnNode.node.children != NULL)
        func_8027D8F8(a->fnNode.node.children);
}

void func_8027D8B8(struct GraphNode *a)
{
    if (a->children != NULL)
        func_8027D8F8(a->children);
}

void func_8027D8F8(struct GraphNode *rootGraphNode)
{
    s16 sp2E = TRUE;
    struct GraphNode *curGraphNode = rootGraphNode;
    struct GraphNode *sp24 = curGraphNode->parent;

    if (sp24 != NULL)
        sp2E = (sp24->type != GRAPH_NODE_TYPE_10C);
    //L8027D944
    do
    {
        if (curGraphNode->flags & GRAPH_RENDER_01)
        {
            if (curGraphNode->flags & GRAPH_RENDER_02)
            {
                func_8027D8B8(curGraphNode);
            }
            //L8027D97C
            else
            {
                switch (curGraphNode->type)
                {
                case GRAPH_NODE_TYPE_002:
                    func_8027B4E8((struct GraphNode002 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_103:
                    func_8027B6C4((struct GraphNodeCamFrustum *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_004:
                    func_8027B450((struct GraphNode004 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_00B:
                    func_8027B840((struct GraphNode00B *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_10C:
                    func_8027B8D4((struct GraphNode10C *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_114:
                    func_8027B9A8((struct GraphNode114 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_015:
                    func_8027BB64((struct GraphNode015 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_016:
                    func_8027BC88((struct GraphNode016 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_017:
                    func_8027BDAC((struct GraphNode017 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_018:
                    func_8027D14C((struct GraphNode018 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_019:
                    func_8027C4C0((struct GraphNode019 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_01A:
                    func_8027BFE4((struct GraphNode01A *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_01B:
                    func_8027C18C((struct GraphNode01B *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_01C:
                    func_8027BEC4((struct GraphNode01C *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_028:
                    func_8027CB08((struct GraphNode028 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_029:
                    func_8027D460((struct GraphNode029 *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_12A:
                    func_8027C1F4((struct GraphNode12A *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_12C:
                    func_8027C2A8((struct GraphNode12C *) curGraphNode);
                    break;
                case GRAPH_NODE_TYPE_12E:
                    func_8027D4D4((struct GraphNode12E *) curGraphNode);
                    break;
                default:
                    func_8027D8B8((struct GraphNode *) curGraphNode);
                    break;
                }
            }
            //L8027DB20
        }
        //L8027DB28
        else
        {
            if (curGraphNode->type == GRAPH_NODE_TYPE_018)
                ((struct GraphNode018 *)curGraphNode)->unk50 = 0;
        }
        //L8027DB44
    } while (sp2E && (curGraphNode = curGraphNode->next) != rootGraphNode);
}

void func_8027DB80(struct GraphNodeScreenArea *a, Vp *b, Vp *c, int d)
{
    UNUSED int unused;

    if (a->node.flags & GRAPH_RENDER_01)
    {
        s16 *sp30;
        Vp *viewport = alloc_display_list(sizeof(*viewport));

        D_8033B018 = func_80278464(PoolAvailable() - 16, 0);
        sp30 = alloc_display_list(64);
        D_8033A770 = 0;
        D_8033B008 = 0;
        vec3s_set(viewport->vp.vtrans, a->x * 4, a->y * 4, 511);
        vec3s_set(viewport->vp.vscale, a->width * 4, a->height * 4, 511);
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
        if (a->node.children != NULL)
            func_8027D8F8(a->node.children);
        D_8032CF90 = NULL;
        if (gShowDebugText)
            print_text_fmt_int(180, 36, "MEM %d", D_8033B018->unk0 - D_8033B018->unk4);
        _pool_free(D_8033B018);
    }
    //L8027DE10
}
