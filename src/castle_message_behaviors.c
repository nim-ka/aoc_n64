#include <ultra64.h>

#include "sm64.h"
#include "area.h"
#include "audio_interface_2.h"
#include "camera.h"
#include "castle_message_behaviors.h"
#include "behavior_actions.h"
#include "behavior_data.h"
#include "behavior_script.h"
#include "game.h"
#include "graph_node.h"
#include "ingame_menu_2.h"
#include "level_update.h"
#include "math_util.h"
#include "memory.h"
#include "object_helpers.h"
#include "mario_head_6.h"
//#include "rendering.h"
#include "rendering_graph_node.h"
#include "save_file.h"
#include "sound_init.h"
#include "skybox.h"

struct Struct802761D0
{
    u16 unk0;
    s16 unk2;
    u8 filler4[0x18-0x4];
};

Gfx *Geo18_802761D0(int a, struct GraphNode *b, float c[4][4])
{
    Vec3s sp50;
    Vec3s sp48;
    Vec3s sp40;
    void *sp3C;
    Gfx *sp38 = NULL;

    if (a == 1 && D_8032CF9C != NULL)
    {
        struct Struct802761D0 *sp34 = (struct Struct802761D0 *)b;
        struct Struct802761D0 *sp30 = sp34 + 1;

        if (sp30->unk0 != gAreaUpdateCounter)
        {
            UNUSED int sp2C = D_8032CF9C->unk18;
            int sp28 = (u16)sp30->unk2;

            vec3f_to_vec3s(sp40, D_8032CF9C->unk28);
            vec3f_to_vec3s(sp48, D_8032CF9C->unk1C);
            vec3f_to_vec3s(sp50, D_8033B1B0.unk4);
            sp3C = func_802DECB8(sp28, sp50, sp40, sp48);
            if (sp3C != NULL)
            {
                Mtx *mtx = alloc_display_list(sizeof(*mtx));

                sp38 = alloc_display_list(2 * sizeof(*sp38));
                mtxf_to_mtx(mtx, c);
                gSPMatrix(&sp38[0], VIRTUAL_TO_PHYSICAL(mtx), G_MTX_MODELVIEW | G_MTX_LOAD);
                gSPBranchList(&sp38[1], VIRTUAL_TO_PHYSICAL(sp3C));
                sp34->unk2 = (sp34->unk2 & 0xFF) | 0x400;
            }
            sp30->unk0 = gAreaUpdateCounter;
        }
    }
    else if (a == 4)
    {
        vec3s_copy(sp40, D_80385FDC);
        vec3s_copy(sp48, D_80385FDC);
        vec3s_copy(sp50, D_80385FDC);
        func_802DECB8(0, sp50, sp40, sp48);
    }
    return sp38;
}

struct Struct802763D4
{
    u8 filler0[0x18];
    s32 unk18;
    s32 unk1C;
};

struct Struct802763D4_Unknown
{
    u8 filler0[0x1C];
    float unk1C;
};

Gfx *Geo19_802763D4(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    Gfx *sp3C = NULL;
    struct Struct802763D4 *sp38 = (struct Struct802763D4 *)b;

    if (a == 3)
    {
        sp38->unk18 = 0;
    }
    else if (a == 1)
    {
        struct GraphNode *sp34 = D_8032CF90->unk20[0];
        struct Struct802763D4_Unknown *sp30 = (struct Struct802763D4_Unknown *)sp34->parent;

        sp3C = func_802CF414(0, sp38->unk1C, sp30->unk1C,
            D_8033B328.unk8C[0], D_8033B328.unk8C[1], D_8033B328.unk8C[2],
            D_8033B328.unk80[0], D_8033B328.unk80[1], D_8033B328.unk80[2]);
    }
    return sp3C;
}

Gfx *Geo18_802764B0(int a, struct GraphNode *b, Mat4 *c)
{
    Gfx *sp24 = NULL;
    s16 sp22 = 0;
    struct Struct802763D4 *sp1C = (struct Struct802763D4 *)b;
    UNUSED Mat4 *sp18 = c;

    if (a == 1)
    {
        if (gPlayer1Controller->controllerData != NULL && D_8033A740 == 0)
            func_8019C7F0(gPlayer1Controller->controllerData);
        sp24 = (Gfx *)PHYSICAL_TO_VIRTUAL(gdm_gettestdl(sp1C->unk18));
        D_8032C6A0 = Proc8019C734;
        sp22 = func_8019C888();
        func_80248E24(sp22);
    }
    return sp24;
}

void func_80275FCC(void)
{
    if (gCurrentObject->oDistanceToMario > 700.0f)
        gCurrentObject->oToadMessageUnk10C = 0;
    if (gCurrentObject->oToadMessageUnk10C == 0 && gCurrentObject->oDistanceToMario < 600.0f)
        gCurrentObject->oToadMessageUnk110 = 2;
}

void func_8027604C(void)
{
    if (gCurrentObject->oDistanceToMario > 700.0f)
    {
        gCurrentObject->oToadMessageUnk110 = 3;
    }
    else
    {
        if (gCurrentObject->oToadMessageUnk10C == 0)
        {
            gCurrentObject->oUnk190 = 0x4000;
            if (gCurrentObject->oInteractStatus & 0x8000)
            {
                gCurrentObject->oInteractStatus = 0;
                gCurrentObject->oToadMessageUnk110 = 4;
                func_8032132C();
            }
        }
    }
}

void func_80276104(void)
{
    if (CreateMessageBox(3, 1, 162, gCurrentObject->oToadMessageUnk108) != 0)
    {
        gCurrentObject->oToadMessageUnk10C = 1;
        gCurrentObject->oToadMessageUnk110 = 3;
        switch (gCurrentObject->oToadMessageUnk108)
        {
        case 82:
            gCurrentObject->oToadMessageUnk108 = 154;
            func_802AACE4(0);
            break;
        case 76:
            gCurrentObject->oToadMessageUnk108 = 155;
            func_802AACE4(1);
            break;
        case 83:
            gCurrentObject->oToadMessageUnk108 = 156;
            func_802AACE4(2);
            break;
        }
    }
}

void func_80276208(void)
{
    if ((gCurrentObject->oUnk17C += 6) == 255)
        gCurrentObject->oToadMessageUnk110 = 1;
}

void func_80276254(void)
{
    if ((gCurrentObject->oUnk17C -= 6) == 81)
        gCurrentObject->oToadMessageUnk110 = 0;
}

void BehToadMessageLoop(void)
{
    if (gCurrentObject->header.gfx.node.flags & 1)
    {
        gCurrentObject->oUnk190 = 0;
        switch (gCurrentObject->oToadMessageUnk110)
        {
        case 0:
            func_80275FCC();
            break;
        case 1:
            func_8027604C();
            break;
        case 2:
            func_80276208();
            break;
        case 3:
            func_80276254();
            break;
        case 4:
            func_80276104();
            break;
        }
    }
}

void BehToadMessageInit(void)
{
    int sp34 = save_file_get_flags();
    int sp30 = save_file_get_total_star_count(gCurrSaveFileNum - 1, 0, 24);
    int sp2C = (gCurrentObject->oUnk188 >> 24) & 0xFF;
    int sp28 = TRUE;

    switch (sp2C)
    {
    case 82:
        sp28 = (sp30 >= 12);
        if (sp34 & 0x1000000)
            sp2C = 154;
        break;
    case 76:
        sp28 = (sp30 >= 25);
        if (sp34 & 0x2000000)
            sp2C = 155;
        break;
    case 83:
        sp28 = (sp30 >= 35);
        if (sp34 & 0x4000000)
            sp2C = 156;
        break;
    }
    if (sp28)
    {
        gCurrentObject->oToadMessageUnk108 = sp2C;
        gCurrentObject->oToadMessageUnk10C = 0;
        gCurrentObject->oToadMessageUnk110 = 0;
        gCurrentObject->oUnk17C = 81;
    }
    else
    {
        DeactivateObject(gCurrentObject);
    }
}

void func_802764F0(s16 a)
{
    struct Object *sp1C = SpawnObj(gCurrentObject, 0, beh_powerup_sparkles2);

    sp1C->oPosX += 100.0f * sins((gCurrentObject->oSealedDoorStarUnk10C * 0x2800) + a);
    sp1C->oPosZ += 100.0f * coss((gCurrentObject->oSealedDoorStarUnk10C * 0x2800) + a);
    sp1C->oPosY -= gCurrentObject->oSealedDoorStarUnk10C * 10.0f;
}

void BehSealedDoorStarInit(void)
{
    gCurrentObject->oSealedDoorStarUnk108 = 0;
    gCurrentObject->oSealedDoorStarUnk10C = 0;
    gCurrentObject->oSealedDoorStarUnk110 = 4096;
    gCurrentObject->oPosX += 30.0f * sins(gMarioState->faceAngle[1] - 0x4000);
    gCurrentObject->oPosY += 160.0f;
    gCurrentObject->oPosZ += 30.0f * coss(gMarioState->faceAngle[1] - 0x4000);
    gCurrentObject->oAngleYaw = 0x7800;
    func_8029EC88(gCurrentObject, 0.5f);
}

void BehSealedDoorStarLoop(void)
{
    UNUSED u8 unused1[4];
    s16 sp2A = gCurrentObject->oAngleYaw;
    UNUSED u8 unused2[4];

    if (gCurrentObject->oSealedDoorStarUnk110 < 0x2400)
        gCurrentObject->oSealedDoorStarUnk110 += 0x60;
    switch (gCurrentObject->oSealedDoorStarUnk108)
    {
    case 0:
        gCurrentObject->oPosY += 3.4f;
        gCurrentObject->oAngleYaw += gCurrentObject->oSealedDoorStarUnk110;
        func_8029EC88(gCurrentObject, gCurrentObject->oSealedDoorStarUnk10C / 50.0f + 0.5f);
        if (++gCurrentObject->oSealedDoorStarUnk10C == 30)
        {
            gCurrentObject->oSealedDoorStarUnk10C = 0;
            gCurrentObject->oSealedDoorStarUnk108++;
        }
        break;
    case 1:
        gCurrentObject->oAngleYaw += gCurrentObject->oSealedDoorStarUnk110;
        if (++gCurrentObject->oSealedDoorStarUnk10C == 30)
        {
            SetSound(SOUND_MENU_STARSOUND, &gCurrentObject->header.gfx.unk54);
            UnHideObject();
            gCurrentObject->oSealedDoorStarUnk10C = 0;
            gCurrentObject->oSealedDoorStarUnk108++;
        }
        break;
    case 2:
        func_802764F0(0);
        func_802764F0(-0x8000);
        if (gCurrentObject->oSealedDoorStarUnk10C++ == 20)
        {
            gCurrentObject->oSealedDoorStarUnk10C = 0;
            gCurrentObject->oSealedDoorStarUnk108++;
        }
        break;
    case 3:
        if (gCurrentObject->oSealedDoorStarUnk10C++ == 50)
            DeactivateObject(gCurrentObject);
        break;
    }
    if (sp2A > (s16)gCurrentObject->oAngleYaw)
        SetSound(SOUND_GENERAL_SHORTSTAR, &gCurrentObject->header.gfx.unk54);
}

struct Struct802769E0
{
    u8 filler0[2];
    s16 unk2;
    u8 filler4[0x18-0x4];
    s32 unk18;
};

Gfx *func_802769E0(struct Struct802769E0 *a, s16 b)
{
    Gfx *sp2C;
    Gfx *sp28 = NULL;

    if (b == 255)
    {
        a->unk2 = (a->unk2 & 0xFF) | 0x100;
        sp28 = alloc_display_list(2 * sizeof(*sp28));
        sp2C = sp28;
    }
    else
    {
        a->unk2 = (a->unk2 & 0xFF) | 0x500;
        sp28 = alloc_display_list(3 * sizeof(*sp28));
        sp2C = sp28;
        gDPSetAlphaCompare(sp2C++, G_AC_DITHER);
    }
    gDPSetEnvColor(sp2C++, 255, 255, 255, b);
    gSPEndDisplayList(sp2C);
    return sp28;
}

struct Struct8033A040
{
    u32 unk0;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    u8 fillerA[1];
    u8 unkB;
    Vec3s unkC;
    Vec3s unk12;
    u8 filler18[0x28-0x18];
};

extern struct Struct8033A040 D_8033A040[];

Gfx *Geo18_802770A4(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    UNUSED u8 unused1[4];
    Gfx *sp28 = NULL;
    struct Struct802769E0 *sp24 = (struct Struct802769E0 *)b;
    struct Struct8033A040 *sp20 = &D_8033A040[sp24->unk18];
    s16 sp1E;
    UNUSED u8 unused2[4];

    if (a == 1)
    {
        sp1E = (sp20->unk8 & 0x100) ? (sp20->unk8 & 0xFF) : 255;
        sp28 = func_802769E0(sp24, sp1E);
    }
    return sp28;
}

struct Struct80277150
{
    struct GraphNode node;
    u8 filler14[0x4];
    float unk18;
    s16 unk1C;
    s16 unk1E;
};

Gfx *GeoSwitchCase80277150(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277150 *sp4 = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp0 = &D_8033A040[sp4->unk1C];

    if (a == 1)
        sp4->unk1E = ((sp0->unk0 & 0x200) == 0);
    return NULL;
}

s8 D_8032CDF0[7] = {0x01, 0x02, 0x01, 0x00, 0x01, 0x02, 0x01};

Gfx *GeoSwitchCase802771BC(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277150 *spC = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp8 = &D_8033A040[spC->unk1C];
    s16 sp6;

    if (a == 1)
    {
        if (sp8->unk5 == 0)
        {
            sp6 = ((spC->unk1C * 32 + gAreaUpdateCounter) >> 1) & 0x1F;
            if (sp6 < 7)
                spC->unk1E = D_8032CDF0[sp6];
            else
                spC->unk1E = 0;
        }
        else
        {
            spC->unk1E = sp8->unk5 - 1;
        }
    }
    return NULL;
}

struct Struct80277294
{
    struct GraphNode node;
    u8 filler14[0x4];
    s32 unk18;
};

struct Struct80277294_2
{
    struct GraphNode node;
    u8 filler14[4];
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
};

Gfx *Geo18_80277294(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277294 *sp24 = (struct Struct80277294 *)b;
    struct Struct8033A040 *sp20 = &D_8033A040[sp24->unk18];
    int sp1C = sp20->unk0;

    if (a == 1)
    {
        struct Struct80277294_2 *sp18 = (struct Struct80277294_2 *)b->next;

        if (sp1C != 0x00840452 && sp1C != 0x00840454 && sp1C != 0x04000440 && sp1C != 0x20810446)
            vec3s_copy(sp20->unkC, D_80385FDC);
        sp18->unk18 = sp20->unkC[1];
        sp18->unk1A = sp20->unkC[2];
        sp18->unk1C = sp20->unkC[0];
    }
    return NULL;
}

struct Struct802773A4
{
    struct GraphNode node;
    u8 filler14[0x4];
    s32 unk18;
};

struct Struct802773A4_2
{
    struct GraphNode node;
    u8 filler14[0x4];
    Vec3s unk18;
};

Gfx *Geo18_802773A4(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct802773A4 *sp2C = (struct Struct802773A4 *)b;
    struct Struct8033A040 *sp28 = &D_8033A040[sp2C->unk18];
    int sp24 = sp28->unk0;

    if (a == 1)
    {
        struct Struct802773A4_2 *sp20 = (struct Struct802773A4_2 *)b->next;
        u8 *sp1C = (u8 *)D_8032CF9C->unk18;

        if (*sp1C == 6)
        {
            sp20->unk18[0] = D_8033B1B0.unk16[1];
            sp20->unk18[2] = D_8033B1B0.unk16[0];
        }
        else if (sp24 & 0x20000000)
        {
            sp20->unk18[0] = sp28->unk12[1];
            sp20->unk18[1] = sp28->unk12[2];
            sp20->unk18[2] = sp28->unk12[0];
        }
        else
        {
            vec3s_set(sp28->unk12, 0, 0, 0);
            vec3s_set(sp20->unk18, 0, 0, 0);
        }
    }
    return NULL;
}

Gfx *GeoSwitchCase802774F4(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277150 *sp4 = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp0 = &D_8033A040[0];

    if (a == 1)
    {
        if (sp0->unk6 == 0)
        {
            sp4->unk1E = ((sp0->unk0 & 0x10000000) != 0);
        }
        else
        {
            if (sp4->unk1C == 0)
                sp4->unk1E = (sp0->unk6 < 5) ? sp0->unk6 : 1;
            else
                sp4->unk1E = (sp0->unk6 < 2) ? sp0->unk6 : 0;
        }
    }
    return NULL;
}

struct Struct802775CC
{
    struct GraphNode node;
    u8 filler14[4];
    s32 unk18;
};

s8 D_8032CDF8[] = {0x0a, 0x0c, 0x10, 0x18, 0x0a, 0x0a, 0x0a, 0x0e, 0x14, 0x1e, 0x0a, 0x0a, 0x0a, 0x10, 0x14, 0x1a, 0x1a, 0x14, 0x00, 0x00};
s16 D_8032CE0C = 0;

Gfx *Geo18_802775CC(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct802775CC *spC = (struct Struct802775CC *)b;
    struct Struct80277150 *sp8 = (struct Struct80277150 *)b->next;
    struct Struct8033A040 *sp4 = &D_8033A040[0];

    if (a == 1)
    {
        sp8->unk18 = 1.0f;
        if (spC->unk18 == sp4->unkB >> 6)
        {
            if (D_8032CE0C != gAreaUpdateCounter && (sp4->unkB & 0x3F) > 0)
            {
                sp4->unkB--;
                D_8032CE0C = gAreaUpdateCounter;
            }
            sp8->unk18 = D_8032CDF8[spC->unk18 * 6 + (sp4->unkB & 0x3F)] / 10.0f;
        }
    }
    return NULL;
}

Gfx *GeoSwitchCase802776D8(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277150 *sp4 = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp0 = &D_8033A040[sp4->unk1C];

    if (a == 1)
        sp4->unk1E = sp0->unk8 >> 8;
    return NULL;
}

Gfx *GeoSwitchCase80277740(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct GraphNode *spC = b->next;
    struct Struct80277150 *sp8 = (struct Struct80277150 *)b;
    struct Struct8033A040 *sp4 = &D_8033A040[sp8->unk1C];

    if (a == 1)
    {
        sp8->unk1E = sp4->unk4 & 1;
        while (spC != b)
        {
            if (spC->type == 21)
            {
                if (sp4->unk4 & 2)
                    spC->flags |= 1;
                else
                    spC->flags &= ~1;
            }
            spC = spC->next;
        }
    }
    return NULL;
}

struct Struct80277824
{
    struct GraphNode node;
    u8 filler14[4];
    u32 unk18;
};

struct Struct80277824_2
{
    struct GraphNode node;
    u8 filler14[4];
    s16 unk18;
};

Gfx *Geo18_80277824(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    s16 spE;
    struct Struct80277824 *sp8 = (struct Struct80277824 *)b;

    if (a == 1)
    {
        struct Struct80277824_2 *sp4 = (struct Struct80277824_2 *)b->next;

        if (D_8033A040[sp8->unk18 >> 1].unk7 == 0)
            spE = (coss((gAreaUpdateCounter & 0xF) << 12) + 1.0f) * 4096.0f;
        else
            spE = (coss((gAreaUpdateCounter & 7) << 13) + 1.0f) * 6144.0f;
        if (!(sp8->unk18 & 1))
            sp4->unk18 = -spE;
        else
            sp4->unk18 = spE;
    }
    return NULL;
}

struct Struct8027795C
{
    struct GraphNode node;
    u8 filler14[4];
    s32 unk18;
    struct Object *unk1C;
    Vec3s unk20;
};

Gfx *Geo1C_8027795C(int a, struct GraphNode *b, Mat4 *c)
{
    struct Struct8027795C *sp2C = (struct Struct8027795C *)b;
    Mat4 *sp28 = c;
    struct MarioState *sp24 = &gMarioStates[sp2C->unk18];

    if (a == 1)
    {
        sp2C->unk1C = 0;
        if (sp24->heldObj != NULL)
        {
            sp2C->unk1C = sp24->heldObj;
            switch (sp24->unk98->unk0A)
            {
            case 1:
                if (sp24->action & 0x80000000)
                    vec3s_set(sp2C->unk20, 50, 0, 0);
                else
                    vec3s_set(sp2C->unk20, 50, 0, 110);
                break;
            case 2:
                vec3s_set(sp2C->unk20, 145, -173, 180);
                break;
            case 3:
                vec3s_set(sp2C->unk20, 80, -270, 1260);
                break;
            }
        }
    }
    else if (a == 5)
    {
        func_8037A550(sp24->unk98->unk18, *sp28, D_8032CF9C->unk34);
    }
    return NULL;
}

extern struct GraphNodeObject D_80339FE0;

Gfx *Geo18_80277B14(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    float sp34;
    struct Object *sp30 = gMarioStates->marioObj;

    switch (a)
    {
    case 0:
        init_graph_node_object(NULL, &D_80339FE0, NULL, D_80385FD0, D_80385FDC, D_80385FE4);
        break;
    case 3:
        func_8037C044(b, &D_80339FE0.node);
        break;
    case 2:
        func_8037C0BC(&D_80339FE0.node);
        break;
    case 1:
        if (sp30->header.gfx.pos[0] > 1700.0f)
        {
            // TODO: Is this a geo layout copy or a graph node copy?
            D_80339FE0.asGraphNode = sp30->header.gfx.asGraphNode;
            D_80339FE0.unk18 = sp30->header.gfx.unk18;
            vec3s_copy(D_80339FE0.angle, sp30->header.gfx.angle);
            vec3f_copy(D_80339FE0.pos, sp30->header.gfx.pos);
            vec3f_copy(D_80339FE0.scale, sp30->header.gfx.scale);
            // FIXME: why does this set unk38, an inline struct, to a ptr to another one? wrong
            // GraphNode types again?
            D_80339FE0.unk38 = *(struct GraphNodeObject_sub *)&sp30->header.gfx.unk38.animID;
            sp34 = 4331.53 - D_80339FE0.pos[0];
            D_80339FE0.pos[0] = sp34 + 4331.53;
            D_80339FE0.angle[1] = -D_80339FE0.angle[1];
            D_80339FE0.scale[0] *= -1.0f;
            // FIXME: Why doesn't this match?
            //D_80339FE0.node.flags |= 1;
            ((s16 *)&D_80339FE0)[1] |= 1;
        }
        else
        {
            // FIXME: Why doesn't this match?
            //D_80339FE0.node.flags &= ~1;
            ((s16 *)&D_80339FE0)[1] &= ~1;
        }
        break;
    }
    return NULL;
}

struct Struct80277D6C
{
    struct GraphNode node;
    u8 filler14[4];
    s32 unk18;
};

Gfx *Geo18_80277D6C(int a, struct GraphNode *b, UNUSED Mat4 *c)
{
    struct Struct80277D6C *sp34 = (struct Struct80277D6C *)b;
    Gfx *sp30 = NULL;

    if (a == 1 && D_8032CFA0 == &D_80339FE0)
    {
        sp30 = alloc_display_list(3 * sizeof(*sp30));

        if (sp34->unk18 == 0)
        {
            gSPClearGeometryMode(&sp30[0], G_CULL_BACK);
            gSPSetGeometryMode(&sp30[1], G_CULL_FRONT);
            gSPEndDisplayList(&sp30[2]);
        }
        else
        {
            gSPClearGeometryMode(&sp30[0], G_CULL_FRONT);
            gSPSetGeometryMode(&sp30[1], G_CULL_BACK);
            gSPEndDisplayList(&sp30[2]);
        }
        sp34->node.flags = (sp34->node.flags & 0xFF) | 0x100;
    }
    return sp30;
}
