#include <ultra64.h>
#include "../libultra.h"

#include "sm64.h"
#include "data801A8050.h"
#include "gd_main.h"
#include "game_over_2.h"
#include "mario_head_1.h"
#include "mario_head_4.h"
#include "old_obj_fn.h"
#include "../mario_head_5.h"
#include "half_6.h"
#include "../mario_head_6.h"

/* forward declarations */
void func_80179B64(struct ObjGroup *);
void update_shaders(struct ObjShape *, struct MyVec3f *);
void func_8017A218(struct ObjShape *);
void Proc8017A91C(struct ObjLight *a);

/* BSS */
u8 gdUnused801B9B30[0x88];
struct ObjGroup *D_801B9BB8;  // ObjGroup* of ObjLights

static u8 sUnused801B9BBC[0x40];
static s32 D_801B9C00;
static s32 D_801B9C04;
static s16 D_801B9C08[100];
static s32 D_801B9CD0;
static float D_801B9CD4;
static struct ObjJoint *D_801B9CD8;
static struct {
    // This needs to be within a struct, otherwise unk4 would become 8-byte
    // aligned. The struct might be larger, it's hard to say.
    u8 filler0[4];
    struct ObjView *view;   //D_801B9CE4
} D_801B9CE0;
static s32 D_801B9CE8;
static s32 D_801B9CEC;
static s32 D_801B9CF0;  // drawn shape count?
static s32 D_801B9CF4;
static struct ObjLight *D_801B9CF8;
static struct MyVec3f D_801B9D00;
static struct MyVec3f D_801B9D10;
static struct MyVec3f D_801B9D20[8];
static s32 D_801B9D80;
static struct MyVec3f D_801B9D88;

/* 226910 -> 2269AC */
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

/* 2269AC -> 226C6C */
void Unknown801781DC(struct ObjZone *a)
{
    struct MyVec3f sp3C;

    struct ObjUnk200000 *sp38;
    float sp34;
    float sp30;
    float sp2C;
    struct ObjLight *sp28;
    register struct Links *s0 = a->unk30->link1C;
    struct ObjHeader *sp20;

    while (s0 != NULL)
    {
        sp20 = s0->obj;
        sp28 = (struct ObjLight *)D_801B9BB8->link1C->obj;
        sp3C.x = sp28->unk74.x;
        sp3C.y = sp28->unk74.y;
        sp3C.z = sp28->unk74.z;
        sp38 = (struct ObjUnk200000 *) sp20;
        sp34 = func_80194DB8(&sp38->unk34->vec24, &sp38->unk30->vec20);
        sp30 = func_80194DB8(&sp38->unk34->vec24, &sp3C);
        sp3C.x -= sp38->unk34->vec24.x * (sp30 - sp34);
        sp3C.y -= sp38->unk34->vec24.y * (sp30 - sp34);
        sp3C.z -= sp38->unk34->vec24.z * (sp30 - sp34);
        sp38->unk30->vec20.x = sp3C.x;
        sp38->unk30->vec20.y = sp3C.y;
        sp38->unk30->vec20.z = sp3C.z;
        sp2C = (sp30 - sp34 < 0.0f) ? -(sp30 - sp34) : (sp30 - sp34);
        if (sp2C > 600.0f)
            sp2C = 600.0f;
        sp2C = 1.0 - sp2C / 600.0;
        sp38->unk30->vec2C.x = sp2C * sp28->unk5C.x;
        sp38->unk30->vec2C.y = sp2C * sp28->unk5C.y;
        sp38->unk30->vec2C.z = sp2C * sp28->unk5C.z;
        s0 = s0->next;
    }
}

/* 226C6C -> 226FDC */
// o is color pallet?
void draw_shape(struct ObjShape *shape, int b, float c, float d,
    float e, float f, float g, float h, float i, float j, float k, float l,
    float m, float n, int o, Mat4 *mtx)
{
    UNUSED u8 unused[8];
    struct MyVec3f sp1C;

    restart_timer("drawshape");
    D_801B9CF0++;
    if (shape == NULL)
        return;
    sp1C.x = sp1C.y = sp1C.z = 0.0f;
    if (b & 2)
    {
        func_8019F19C(f, g, h);
        sp1C.x += f;
        sp1C.y += g;
        sp1C.z += h;
    }
    if ((b & 0x10) && mtx != NULL)
    {
        func_8019EF14(mtx);
        sp1C.x += (*mtx)[3][0];
        sp1C.y += (*mtx)[3][1];
        sp1C.z += (*mtx)[3][2];
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
        D_801A80F4 = (struct MyVec3f *)func_80178D98(o);
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
    if (D_801B9D80 != 0 && shape->mtlGroup != NULL)
    {
        if (mtx != NULL)
        {
            sp1C.x = (*mtx)[3][0];
            sp1C.y = (*mtx)[3][1];
            sp1C.z = (*mtx)[3][2];
        }
        else
        {
            sp1C.x = sp1C.y = sp1C.z = 0.0f;
        }
        update_shaders(shape, &sp1C);
    }
    if (b & 4)
        func_8019F0E4(i, j, k);
    if (b & 1)
        func_8019F258(c, d, e);
    func_8017A218(shape);
    D_801B9C04 = 0;
    func_8018CEEC("drawshape");
}

/* 226FDC -> 2270D0; orig name: func_8017880C */
void draw_shape_2d(struct ObjShape *shape, int b,
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

    if (shape == NULL)
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
    func_8017A218(shape);
    func_8018CEEC("drawshape2d");
}

/* 2270D0 -> 2272EC */
void Proc80178900(struct ObjLight *self)
{
    struct MyVec3f sp94;
    Mat4 sp54;
    UNUSED Mat4 *sp50;
    UNUSED float sp4C;
    struct ObjShape *sp48;

    if (D_801B9C00 == 27)
        return;
    D_801A80E8[0] = self->unk5C.x;
    D_801A80E8[1] = self->unk5C.y;
    D_801A80E8[2] = self->unk5C.z;
    if (self->unk2C & 2)
    {
        set_identity_mat4(&sp54);
        sp94.x = -self->unk80.x;
        sp94.y = -self->unk80.y;
        sp94.z = -self->unk80.z;
        func_80194358(&sp54, &sp94, 0.0f);
        sp4C = self->unk38 / 45.0;
        sp48 = D_801A82E4;
        sp50 = &sp54;
    }
    else
    {
        sp4C = 1.0f;
        sp48 = self->unk9C;
        sp50 = NULL;
        if (++D_801A81A0 >= 17)
            D_801A81A0 = 1;
        sp48->unk48[2] = D_801A81A0;
    }
    draw_shape_2d(sp48, 2, 1.0f, 1.0f, 1.0f, self->unk74.x, self->unk74.y, self->unk74.z,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1, 0);
}

/* 2272EC -> 227420 */
void draw_material(struct ObjMaterial *mtl)
{
    int sp24 = mtl->unk28;

    if (sp24 == 16)
    {
        if (D_801B9CF8 != NULL && D_801B9CF8->unk30 > 0.0f)
        {
            if (D_801A80F8 != NULL)
            {
                func_801A0478(mtl->unk5C, D_801A80F8, &D_801B9CF8->unk74, &D_801B9D10,
                    &D_801B9D00, &D_801B9CF8->unk5C);
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
        func_801A086C(mtl->unk5C, &mtl->vec3C, sp24);
    else
        func_801A086C(mtl->unk5C, D_801A80F4, 64);
}

/* 227420 -> 22747C */
void Unknown80178C50(struct ObjMaterial *mtl)
{
    if (mtl->unk5C == 0)
        mtl->unk5C = func_801A0354(mtl->unk28);
}

/* 22747C -> 227568 */
// Type of argument is a guess, but this function is not called
void Unknown80178CAC(struct ObjFace *face)
{
    int i;
    struct ObjVertex *vtx;

    for (i = 0; i < face->vtxCount; i++)
    {
        vtx = face->vertices[i];
        if ((int)vtx == 39)
        {
            printf("bad1\n");
            return;
        }
        if (vtx->unk44 == 0x3F800000)  // maybe a float (1.0f)?
            myPrintf("bad2 %x,%d,%d,%d\n", (u32) vtx, vtx->unk3C, vtx->unk38, vtx->header.type);
    }
}

/* 227568 -> 22769C */
Vec3f * func_80178D98(int a)  
{
    switch (a + 1)
    {
    case 1:
        return &D_801A80B8;
        break;
    case 2:
        return &D_801A8070;
        break;
    case 3:
        return &D_801A807C;
        break;
    case 4:
        return &D_801A8088;
        break;
    case 5:
        return &D_801A8094;
        break;
    case 6:
        return &D_801A80C4;
        break;
    case 7:
        return &D_801A80D0;
        break;
    case 8:
        return &D_801A80A0;
        break;
    case 11:
        return &D_801A80B8;
        break;
    case 9:
        return &D_801A80DC;
        break;
    case 10:
        return &D_801A80AC;
        break;
    case 0:
        return &D_801A80E8;
        break;
    default:
        return NULL;
    }
}

/* 22769C -> 2277B0 */
void Unknown80178ECC(float a, float b, float c, float d, float e, float f)
{
    float sp3C = e - b;
    float sp38 = d - a;
    float sp34 = f - c;

    func_8019FF54(a, b, c, d, e, f,
        a + sp3C * 0.1, b + sp38 * 0.1, c + sp34 * 0.1);
}

struct BetaVtx {
    /* 0x00 */ u8 pad[0x44-0];
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
};
/* 2277B0 -> 2279F8 */
void draw_face(struct ObjFace *self)
{
    struct ObjVertex *vtx;
    float sp38;
    float sp34;
    float sp30;
    UNUSED u8 unused[12];
    int sp20;
    int sp1C;
    struct ObjHeader* sp18;

    func_8018D420("draw_face");
    sp1C = 0;
    if (D_801B9C04 == 0 && self->unk44 >= 0)
    {
        if (self->unk48 != NULL)
        {
            if ((sp20 = self->unk48->unk5C) != 0)
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
    func_8019F9D8(self->vtxCount);
    if (D_801A805C == 0)
        func_801A15E8(&self->vec24);
    for (sp20 = 0; sp20 < self->vtxCount; sp20++)
    {
        vtx = self->vertices[sp20];
        sp30 = vtx->vec20.x;
        sp34 = vtx->vec20.y;
        sp38 = vtx->vec20.z;
        if (D_801A805C != 0)
            func_801A16C4(&vtx->vec2C);
        //! What follows seems to be based on older versions of ObjVertex
        //! as the struct requests fields passed the end of an ObjVertex
        // This code doesn't seems to be called in game, so...
        if (sp1C != 0)
            func_801A5B58(((struct BetaVtx *)vtx)->unk44, ((struct BetaVtx *)vtx)->unk48);
        sp18 = (struct ObjHeader *)func_8019FA60(sp30, sp34, sp38, vtx->unk40);
        // WTF???
        if (sp18 != NULL)
            *(int *)&vtx->unk44 = (int)make_link_2(*(void **)&vtx->unk44, sp18);
    }
    func_8019FEF0();
    imout();
}

/* 2279F8 -> 227A5C */
void func_80179228(int a, float b, float c, float d, float e)
{
    func_8019E2F8(func_80178D98(a));
    func_8019D360(b, c, d, e);
}

/* 227A5C -> 227AC0 */
void func_8017928C(int a, float b, float c, float d, float e)
{
    func_8019E2F8(func_80178D98(a));
    func_8019D708(b, c, d, e);
}

/* 227AC0 -> 227B20 */
void Unknown801792F0(struct ObjHeader* a)
{
    char sp28[32];
    struct MyVec3f sp1C;

    sprint_obj_id(sp28, a);
    set_cur_dynobj(a);
    d_get_world_pos(&sp1C);
    func_801A4438(sp1C.x, sp1C.y, sp1C.z);
    func_801A48D8(sp28);
}

typedef void (*SomeFunc)(union ObjVarVal *, union ObjVarVal);

/* 227B20 -> 227DF8 */
void Proc80179350(struct ObjLabel *label)
{
    struct MyVec3f sp144;
    char strbuf[0x100];
    UNUSED u8 unused[16];
    struct ObjValPtrs *valptr;
    union ObjVarVal sp28;
    SomeFunc valfn = (SomeFunc)label->valfn;

    if ((valptr = label->valptr) != NULL)
    {
        if (valptr->unk20 == 0x40000)
        {
            set_cur_dynobj(valptr->obj);
            d_get_world_pos(&sp144);
        }
        else
        {
            sp144.x = sp144.y = sp144.z = 0.0f;
        }
        switch (valptr->datatype)
        {
        case OBJ_VALUE_FLOAT:
            get_objvalue(&sp28, OBJ_VALUE_FLOAT, valptr->obj, valptr->offset);
            if (valfn != NULL)
                valfn(&sp28, sp28);
            sprintf(strbuf, label->fmtstr, sp28.f);
            break;
        case OBJ_VALUE_INT:
            get_objvalue(&sp28, OBJ_VALUE_INT, valptr->obj, valptr->offset);
            if (valfn != NULL)
                valfn(&sp28, sp28);
            sprintf(strbuf, label->fmtstr, sp28.i);
            break;
        default:
            if (label->fmtstr != NULL)
                func_8018DC98(strbuf, label->fmtstr);
            else
                func_8018DC98(strbuf, "NONAME");
            break;
        }
    }
    else
    {
        sp144.x = sp144.y = sp144.z = 0.0f;
        if (label->fmtstr != NULL)
            func_8018DC98(strbuf, label->fmtstr);
        else
            func_8018DC98(strbuf, "NONAME");
    }
    sp144.x += label->vec14.x;
    sp144.y += label->vec14.y;
    sp144.z += label->vec14.z;
    func_801A4438(sp144.x, sp144.y, sp144.z);
    func_801A48C4(label->unk30);
    func_801A48D8(strbuf);
}

/* 227DF8 -> 227F3C */
void Proc80179628(struct ObjNet *self)
{
    struct ObjNet *sp9C = self;
    int sp98;
    UNUSED u8 unused[80];

    if (D_801B9C00 == 27)
        return;
    if (sp9C->header.unk12 & 0x10)
        sp98 = 8;
    else
        sp98 = sp9C->unk40;
    if (sp9C->unk1A8 != NULL)
    {
        draw_shape((struct ObjShape *)sp9C->unk1A8, 16, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, sp98, &sp9C->mat168);
    }
    if (sp9C->unk1C8 != NULL)
        draw_group(sp9C->unk1C8);
}

/* 227F3C -> 22803C */
void Proc8017976C(struct ObjGadget *gdgt)
{
    int sp24 = 0;

    if (gdgt->unk5C != 0)
        sp24 = gdgt->unk5C;

    func_80179228(sp24, gdgt->unk14.x, gdgt->unk14.y,
        gdgt->unk14.x + gdgt->unk28 * gdgt->unk40.x, 
        gdgt->unk14.y + gdgt->unk40.y);
    
    if (gdgt->header.unk12 & 0x10)
    {
        func_8017928C(8, gdgt->unk14.x, gdgt->unk14.y,
            gdgt->unk14.x + gdgt->unk28 * gdgt->unk40.x, 
            gdgt->unk14.y + gdgt->unk40.y);
    }
    gdgt->header.unk12 &= ~0x10;
}

#define ABS(x) ((x) < 0.0f ? -(x) : (x))
/* 22803C -> 22829C */
void draw_camera(struct ObjCamera *a)
{
    struct MyVec3f sp44;
    UNUSED float sp40 = 0.0f;

    sp44.x = 0.0f;
    sp44.y = 0.0f;
    sp44.z = 0.0f;
    if (a->unk30 != NULL)
    {
        set_cur_dynobj(a->unk30);
        d_get_world_pos(&sp44);
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

/* 22829C -> 228334 */
void Unknown80179ACC(struct ObjHeader *obj)
{
    if (obj->type == OBJ_TYPE_NETS)
    {
        if (0)
        {
        }
        if (((struct ObjNet *)obj)->unk1C8 != NULL)
            func_80179B64(((struct ObjNet *)obj)->unk1C8);
    }
    else
    {
        if (0)
        {
        }
    }
    obj->unk12 &= ~1;
}
/* 228334 -> 22836C */
void func_80179B64(struct ObjGroup* group)
{
    apply_to_obj_types_in_group(
        OBJ_TYPE_LABELS | OBJ_TYPE_GADGETS | OBJ_TYPE_CAMERAS \
        | OBJ_TYPE_NETS | OBJ_TYPE_JOINTS | OBJ_TYPE_BONES, 
        Unknown80179ACC, 
        group
    );
}

/* 22836C -> 228498 */
void func_80179B9C(struct MyVec3f *a, struct ObjCamera *b, struct ObjView *c)
{
    func_80196430(a, b->unkE8);
    if (a->z > -256.0f)
        return;
    a->x *= 256.0 / -a->z;
    a->y *= 256.0 / a->z;
    a->x += c->unk54.x / 2.0f;
    a->y += c->unk54.y / 2.0f;
}

/* 228498 -> 2286A0 */
void Unknown80179CC8(struct ObjHeader *a)
{
    struct MyVec3f sp3C;
    UNUSED u8 unused[12];
    struct ObjHeader *obj;
    Mat4 *mtx;

    if (D_801A80F8 == NULL)
        return;
    obj = a;
    if (!(obj->unk12 & 8))
        return;
    set_cur_dynobj(obj);
    mtx = d_get_rot_mtx_ptr();
    sp3C.x = (*mtx)[3][0];
    sp3C.y = (*mtx)[3][1];
    sp3C.z = (*mtx)[3][2];
    func_80179B9C(&sp3C, D_801A80F8, D_801B9CE0.view);
    if (ABS(D_801B9920.unkD0 - sp3C.x) < 20.0f)
    {
        if (ABS(D_801B9920.unkD4 - sp3C.y) < 20.0f)
        {
            func_801A5A04(2);
            func_801A5A04(obj->type);
            func_801A5A04(obj->number);
            D_801B9D88.x = sp3C.x;
            D_801B9D88.y = sp3C.y;
        }
    }
}

/* 2286A0 -> 2286A0 */
void drawscene(int a, struct ObjGroup *groupB, struct ObjGroup* groupC)
{
    UNUSED u8 unused[16];

    restart_timer("drawscene");
    func_8018D420("draw_scene()");
    D_801A8100 = 0;
    D_801B9CE8 = 0;
    restart_timer("draw1");
    func_801A17B0(5);
    if (D_801B9CE0.view->unk38 == 1)
    {
        func_801A3C8C(D_801B9CE0.view->unk60.z, D_801B9CE0.view->unk54.x / D_801B9CE0.view->unk54.y,
            D_801B9CE0.view->unk60.x, D_801B9CE0.view->unk60.y);
    }
    else
    {
        func_801A3AF0(-D_801B9CE0.view->unk54.x / 2.0, D_801B9CE0.view->unk54.x / 2.0,
            -D_801B9CE0.view->unk54.y / 2.0, D_801B9CE0.view->unk54.y / 2.0,
            D_801B9CE0.view->unk60.x, D_801B9CE0.view->unk60.y);
    }

    if (groupC != NULL)
    {
        func_801A17B0(6);
        apply_to_obj_types_in_group(
            OBJ_TYPE_LIGHTS | OBJ_TYPE_PARTICLES, 
            apply_obj_draw_fn, 
            groupC
        );
        func_801A17B0(5);
    }

    if (D_801A80F8 != NULL)
        draw_camera(D_801A80F8);
    else
        func_8019F0E4(0.0f, 0.0f, -1000.0f);
    func_80178140();
    func_801A17B0(6);
    func_8019F02C();
    D_801B9C00 = a;
    if ((D_801B9D80 = D_801B9CE0.view->unk34 & 0x200000) != 0)
        D_801B9CE0.view->unk34 &= ~0x200000;
    D_801B9D80 = 1;
    apply_to_obj_types_in_group(OBJ_TYPE_LIGHTS, Proc8017A91C, D_801B9BB8);
    func_8018CEEC("draw1");
    restart_timer("drawobj");
    func_8018D420("process_group");
    if (D_801B9C00 == 27)
        apply_to_obj_types_in_group(OBJ_TYPE_ALL, Unknown80179CC8, groupB);
    else
        apply_to_obj_types_in_group(
            OBJ_TYPE_LIGHTS | OBJ_TYPE_GADGETS | OBJ_TYPE_NETS | OBJ_TYPE_PARTICLES, 
            apply_obj_draw_fn, 
            groupB
        );
    imout();
    func_8018CEEC("drawobj");
    gd_setproperty(11, 0.0f, 0.0f, 0.0f);
    apply_to_obj_types_in_group(OBJ_TYPE_LABELS, apply_obj_draw_fn, groupB);
    gd_setproperty(11, 1.0f, 0.0f, 0.0f);
    func_8019F098();
    imout();
    func_8018CEEC("drawscene");
    return;
}

/* 2289D4 -> 2289E8; orig name: Proc8017A204 */
void nop_obj_draw(UNUSED struct ObjHeader *nop)
{
}

/* 2289E8 -> 228ADC */
void func_8017A218(struct ObjShape *shape)
{
    D_801B9CEC = 0;
    D_801B9CE8 = 0;
    func_801A2374(0);
    D_801A8100 = (s32) shape->unk44 & 1;
    func_801A02B8(shape->unk58);
    if (shape->unk48[D_801A86B0] != 0)
    {
        func_8019BD0C(shape->unk48[D_801A86B0], shape->unk48[2]);
    }
    else if (shape->faceGroup != NULL)
    {
        func_801A0038();
        draw_group(shape->faceGroup);
        func_801A0070();
    }
}

/* 228ADC -> 228D20 */
void Proc8017A30C(struct ObjHeader *self)
{
    struct ObjParticle *ptc = (struct ObjParticle *)self;
    UNUSED u8 unused1[16];
    struct MyVec3f *sp60;
    struct MyVec3f *sp5C;
    float sp58;
    UNUSED u8 unused2[16];

    if (ptc->unk5C > 0)
    {
        sp60 = D_801A8104[0];
        sp5C = D_801A8118[1];
        sp58 = ptc->unk5C / 10.0;
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

    if (ptc->unk5C > 0)
    {
        ptc->unk1C->unk48[2] = ptc->unk5C;
        draw_shape_2d(ptc->unk1C, 2, 1.0f, 1.0f, 1.0f,
            ptc->unk20.x, ptc->unk20.y, ptc->unk20.z,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            -1, 0);
    }
    if (ptc->unk60 == 3)
    {
        if (ptc->unk6C != NULL)
            draw_group(ptc->unk6C);
    }
}

/* 228D20 -> 228E74 */
void Proc8017A550(struct ObjHeader *self)
{
    struct ObjBone *bone = (struct ObjBone *)self;
    UNUSED u8 unused1[4];
    int sp5C;
    UNUSED u8 unused2[4];
    struct MyVec3f sp4C;

    return;

    //! dead code
    sp4C.x = 1.0f;
    sp4C.y = 1.0f;
    sp4C.z = bone->unkF8 / 50.0f;
    if (bone->header.unk12 & 0x10)
        sp5C = 8;
    else
        sp5C = bone->unk100;
    bone->header.unk12 &= ~0x10;
    if (D_801B9C00 != 27)
    {
        draw_shape(bone->unkF0, 27, sp4C.x, sp4C.y, sp4C.z,
            bone->unk14.x, bone->unk14.y, bone->unk14.z,
            0.0f, 0.0f, 0.0f,
            bone->unk28.x, bone->unk28.y, bone->unk28.z,
            sp5C, &bone->unk70);
    }
}

/* 228E74 -> 228F90 */
void Proc8017A6A4(struct ObjHeader *a)
{
    struct ObjJoint *self = (struct ObjJoint *)a;
    UNUSED u8 unused1[4];
    UNUSED float sp7C = 70.0f;
    UNUSED u8 unused2[4];
    UNUSED int sp74 = 1;
    int sp70;
    UNUSED u8 unused[8];
    struct ObjShape *boneShape;
    UNUSED u8 unused3[28];

    if ((boneShape = self->unk20) == NULL)
        return;
    if (self->header.unk12 & 0x10)
        sp70 = 8;
    else
        sp70 = self->unk1C8;
    draw_shape(boneShape, 16, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, sp70, &self->mat128);
}

/* 228F90 -> 228FE8 */
void draw_group(struct ObjGroup *grp)
{
    if (grp == NULL)
        myPrint1("Draw_Group: Bad group definition!");
    apply_to_obj_types_in_group(OBJ_TYPE_ALL, apply_obj_draw_fn, grp);
}

/* 228FE8 -> 229070; draw_obj_plane? */
void Proc8017A818(struct ObjHeader *self)
{
    struct ObjPlane *shape = (struct ObjPlane *)self;

    if (self->unk12 & 0x10)
    {
        self->unk12 &= ~0x10;
        ;  // needed to match
    }
    else
    {
        D_801B9C04 = 0;
    }
    draw_face(shape->unk40);
}

/* 229070 -> 2290EC; orig name: func_8017A8A0 */
void apply_obj_draw_fn(struct ObjHeader *obj)
{
    if (obj == NULL)
        myPrint1("Bad object!");
    if (obj->unk12 & 2)
        return;
    obj->objDrawFn(obj);
}

/* 2290EC -> 229180; draw_obj_light? */
void Proc8017A91C(struct ObjLight *light)
{
    func_801A0324(light->unk1C);
    gd_setproperty(11, 2.0f, 0.0f, 0.0f);
    if (light->unk2C & 0x10)
        D_801B9D80++;
    light->unk2C &= ~0x10;
}

/* 229180 -> 229564 */
void Proc8017A980(struct ObjLight *light)
{
    float sp24;
    float sp20;
    float sp1C;

    light->unk5C.x = light->unk50.x * light->unk30;
    light->unk5C.y = light->unk50.y * light->unk30;
    light->unk5C.z = light->unk50.z * light->unk30;
    D_801B9D20[light->unk1C].x = light->unk74.x - D_801B9D10.x;
    D_801B9D20[light->unk1C].y = light->unk74.y - D_801B9D10.y;
    D_801B9D20[light->unk1C].z = light->unk74.z - D_801B9D10.z;
    func_80194BF4(&D_801B9D20[light->unk1C]);
    if (light->unk2C & 0x20)
    {
        D_801B9D00.x = D_801B9D20[light->unk1C].x;
        D_801B9D00.y = D_801B9D20[light->unk1C].y;
        D_801B9D00.z = D_801B9D20[light->unk1C].z;
        D_801B9CF8 = light;
    }
    sp24 = light->unk30;
    if (light->unk2C & 2)
    {
        sp20 = -func_80194DB8(&D_801B9D20[light->unk1C], &light->unk80);
        sp1C = 1.0 - light->unk38 / 90.0;
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
    func_801A0324(light->unk1C);
    gd_setproperty(13, light->unk50.x * sp24, light->unk50.y * sp24, light->unk50.z * sp24);
    gd_setproperty(15, D_801B9D20[light->unk1C].x, D_801B9D20[light->unk1C].y, D_801B9D20[light->unk1C].z);
    gd_setproperty(11, 2.0f, 0.0f, 0.0f);
}

/* 229568 -> 229658; orig name: func_8017AD98 */
void update_shaders(struct ObjShape *shape, struct MyVec3f *b)
{
    restart_timer("updateshaders");
    func_8019E874();
    D_801B9D10.x = b->x;
    D_801B9D10.y = b->y;
    D_801B9D10.z = b->z;
    D_801B9CF8 = NULL;
    if (D_801B9BB8 != NULL)
        apply_to_obj_types_in_group(OBJ_TYPE_LIGHTS, Proc8017A980, D_801B9BB8);
    if (shape->mtlGroup != NULL)
        apply_to_obj_types_in_group(OBJ_TYPE_MATERIALS, apply_obj_draw_fn, shape->mtlGroup);
    func_8019E894();
    func_8018CEEC("updateshaders");
}

/* 229658 -> 2296AC */
void func_8017AE88(struct ObjShape *shape)
{
    if (shape->mtlGroup != NULL)
        apply_to_obj_types_in_group(OBJ_TYPE_MATERIALS, Unknown80178C50, shape->mtlGroup);
}

/* 2296AC -> 229718 */
void Unknown8017AEDC(struct ObjGroup *grp)
{
    register struct Links *link = grp->link1C;

    while (link != NULL)
    {
        struct ObjHeader *obj = link->obj;

        func_8017BED0(grp, obj);
        link = link->next;
    }
}

/* 229718 -> 2297F8; should this fn return void? or is it older than the others? */
int Unknown8017AF48(struct ObjShape *a)
{
    struct ObjShape *shape = a;
    int sp20;
    UNUSED int sp1C;

    func_8017AE88(shape);
    sp20 = gd_startdisplist(7);
    if (sp20 == 0)
        return -1;
    func_80178140();
    D_801B9C04 = 0;
    if (shape->unk3C == 0)
        func_8017A218(shape);
    sp1C = func_8019EA6C();
    shape->unk48[0] = sp20;
    shape->unk48[1] = sp20;
    if (shape->name[0] != '\0')
    {   /* ifdef-ed out debug printing code? */
        if (0)
        {
        }
    }
    //! no return value
}

/* 2297F8 -> 229834 */
void func_8017B028(struct ObjGroup *grp)
{
    UNUSED int sp1C = apply_to_obj_types_in_group(
        OBJ_TYPE_SHAPES, 
        (void (*)())Unknown8017AF48, 
        grp
    );
}

/* 229834 -> 2298E8 */
void func_8017B064(struct ObjGroup *a, struct ObjGroup *b)
{
    struct ObjFace *face;
    register struct Links *linkA;
    struct ObjHeader *spC;
    register struct Links *linkB;
    struct ObjMaterial *mtl;

    linkA = a->link1C;
    while (linkA != NULL)
    {
        spC = linkA->obj;
        face = (struct ObjFace *)spC;
        linkB = b->link1C;
        while (linkB != NULL)
        {
            mtl = (struct ObjMaterial *)linkB->obj;
            if (mtl->unk1C == face->unk44)
                break;
            linkB = linkB->next;
        }
        if (linkB != NULL)
            face->unk48 = mtl;
        linkA = linkA->next;
    }
}

/* 2298E8 -> 229A6C */
void func_8017B118(struct ObjVertex *vtx, struct ObjGroup *facegrp)
{
    int i;
    int vecsAdded;
    register struct Links *faceLink;
    struct ObjFace *curFace;

    vtx->vec2C.x = vtx->vec2C.y = vtx->vec2C.z = 0.0f;
    vecsAdded = 0;
    faceLink = facegrp->link1C;
    while (faceLink != NULL)
    {
        curFace = (struct ObjFace *)faceLink->obj;
        for (i = 0; i < curFace->vtxCount; i++)
        {
            if (curFace->vertices[i] == vtx)
            {
                vtx->vec2C.x += curFace->vec24.x;
                vtx->vec2C.y += curFace->vec24.y;
                vtx->vec2C.z += curFace->vec24.z;
                vecsAdded++;
            }
        }
        faceLink = faceLink->next;
    }
    if (vecsAdded != 0)
    {
        vtx->vec2C.x /= vecsAdded;
        vtx->vec2C.y /= vecsAdded;
        vtx->vec2C.z /= vecsAdded;
    }
}

static const char sUnusedString1[] = "Generated '%s' (%d) display list ok.(%d)\n";
static const char sUnusedString2[] = "Generated 'UNKNOWN' (%d) display list ok.(%d)\n";
static const char sUnusedString3[] = "made %d display lists\n";
/* 229A6C -> 229BC8 */
void find_thisface_verts(struct ObjFace *face, struct ObjGroup *grp)
{
    int i;
    u32 linkVtxIdx;
    struct Links *link;

    for (i = 0; i < face->vtxCount; i++)
    {
        link = grp->link1C;
        linkVtxIdx = 0;
        while (link != NULL)
        {
            if (link->obj->type == OBJ_TYPE_VERTICES || link->obj->type == OBJ_TYPE_PARTICLES)
            {
                // it seems that the vertices in a face are first pointer-sized indices
                // to a given vertix or particle link in the second argument's group. 
                if (linkVtxIdx++ == (u32)face->vertices[i])
                    break;
            }
            link = link->next;
        }
        if (link == NULL)
            myPrintf("find_thisface_verts(): Vertex not found");
        face->vertices[i] = (struct ObjVertex*) link->obj;
    }
    calc_face_normal(face);
}

/* 229BC8 -> 229C98; orig name: func_8017B3F8 */
void map_vertices(struct ObjGroup *facegrp, struct ObjGroup *vtxgrp)
{
    register struct Links *faceLink;
    struct ObjFace *curFace;
    register struct Links *vtxLink;
    struct ObjVertex *vtx;

    func_8018D420("map_vertices");

    faceLink = facegrp->link1C;
    while (faceLink != NULL)
    {
        curFace = (struct ObjFace *)faceLink->obj;
        find_thisface_verts(curFace, vtxgrp);
        faceLink = faceLink->next;
    }

    vtxLink = vtxgrp->link1C;
    while (vtxLink != NULL)
    {
        vtx = (struct ObjVertex *)vtxLink->obj;
        func_8017B118(vtx, facegrp);
        vtxLink = vtxLink->next;
    }

    imout();
}

/* 229C98 -> 229CE4 */
void Unknown8017B4C8(struct ObjHeader *obj)
{
    struct ObjHeader *sp4 = obj;
    if (sp4->unk12 & 8)
        sp4->unk12 &= ~0x14;
}

/* 229CE4 -> 229DC0 */
void Unknown8017B514(struct ObjJoint *a)
{
    struct ObjJoint *joint = a;
    UNUSED u8 unused[12];
    float sp1C;

    if (joint->header.unk12 & 8)
    {
        if (joint->header.number == D_801B9CD0)
        {
            if (D_801A80F8 != NULL)
                sp1C = d_calc_world_dist_btwn(D_801A80F8, joint);
            else
                sp1C = 0.0f;
            if (sp1C < D_801B9CD4)
            {
                D_801B9CD4 = sp1C;
                D_801B9CD8 = joint;
            }
        }
    }
}

/* 229DC0 -> 229DF4 */
void Unknown8017B5F0(struct ObjCamera *a)
{
    if (D_801A80F8 != NULL)
        return;
    D_801A80F8 = a;
}

/* 229DF4 -> 22A470 */
void update_view(struct ObjView *view)
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
    if (!(view->unk34 & 0x800))
    {
        view->unk34 &= ~0x100000;
        return;
    }
    func_8018D420("UpdateView()");
    if (view->unk98 != NULL)
        view->unk98(view);
    if (!(view->unk34 & 0x100000))
        view->unk34 |= 0x100000;
    D_801A80F8 = NULL;
    if (view->unk28 != NULL)
    {
        apply_to_obj_types_in_group(OBJ_TYPE_CAMERAS, Unknown8017B5F0, view->unk28);
        view->unk24 = D_801A80F8;
        if (view->unk24 != NULL)
            D_801A80F8->unk18C = view;
    }
    if (view->unk34 & 0x40000)
    {
        func_8018CEEC("dlgen");
        restart_timer("dynamics");
        func_8018145C(view);
        func_8018CEEC("dynamics");
        restart_timer("dlgen");
        D_801A80F8 = view->unk24;
    }
    if (!(view->unk34 & 0x80000))
    {
        imout();
        return;
    }

    D_801B9CE0.view = view;
    func_801A48F0(view);
    view->unk70 = gd_startdisplist(8);
    func_801A2448(D_801B9CE0.view);
    gd_shading(9);
    if (view->unk34 & 0x6000)
        func_801A2310();
    if (view->unk28 != NULL)
    {
        if (D_801B9920.unkD8 >> 31 != 0)
        {
            if (gd_getproperty(3, 0) != 0 && (D_801B9920.unkD8 * 8) >> 31 != 0)
            {
                func_801A59D4(D_801B9C08, 100);
                drawscene(27, D_801B9CE0.view->unk28, NULL);
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
                                apply_to_obj_types_in_group(sp128, Unknown8017B514, D_801B9CE0.view->unk28);
                            }
                        }
                    }
                }
                if (D_801B9CD8 != NULL)
                {
                    D_801B9CD8->header.unk12 |= 4;
                    D_801B9CD8->header.unk12 |= 0x10;
                    D_801B9CE0.view->unk30 = D_801B9CD8;
                    D_801B9920.unkB8 = D_801B9920.unkD0 = D_801B9D88.x;
                    D_801B9920.unkBC = D_801B9920.unkD4 = D_801B9D88.y;
                }
            }
            func_80180974(D_801B9CE0.view->unk28);
        }
        else
        {
            if (D_801B9CE0.view->unk30 != NULL)
            {
                D_801B9CE0.view->unk30->header.unk12 &= ~4;
                D_801B9CE0.view->unk30->header.unk12 &= ~0x10;
                D_801B9CE0.view->unk30 = NULL;
            }
        }
        drawscene(26, D_801B9CE0.view->unk28, D_801B9CE0.view->unk2C);
    }
    func_801A34E0();
    func_8019EA6C();
    imout();
    return;
}

/* 22A464 -> 22A480 */
void unref_8017BC94(void)
{
}

/* Comment needed to prevent compiler from crashing */
/* Comment needed to prevent compiler from crashing */
/* Comment needed to prevent compiler from crashing */
