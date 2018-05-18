#include <ultra64.h>

#include "sm64.h"
#include "level_update.h"
#include "math_util.h"
#include "memory.h"
#include "segment2.h"
#include "save_file.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "rendering.h"
#include "memory.h"
#include "transparent_texture.h"

extern Gfx D_0702A880[];
extern s32 D_07019248;
extern Gfx D_070192F0[];
extern Gfx D_07019360[];
extern Gfx D_070193C8[];
extern Gfx D_07026400[];

s16 D_80330390 = 0x01, D_80330394 = 0, D_80330398 = 0;

extern struct GraphNode018 *D_8032CFA0;
extern u16 D_8032CFA8;

void make_vertex(Vtx *vtx, s32 n, s16 x, s16 y, s16 z, s16 tx, s16 ty, u8 r, u8 g, u8 b, u8 a)
{
    vtx[n].v.ob[0] = x;
    vtx[n].v.ob[1] = y;
    vtx[n].v.ob[2] = z;

    vtx[n].v.flag = 0;

    vtx[n].v.tc[0] = tx;
    vtx[n].v.tc[1] = ty;

    vtx[n].v.cn[0] = r;
    vtx[n].v.cn[1] = g;
    vtx[n].v.cn[2] = b;
    vtx[n].v.cn[3] = a;
}

s32 round_float(float f12)
{
    //! double literals instead of float literals
    if (f12 >= 0.0)
        return (s16)(f12 + 0.5);
    else
        return (s16)(f12 - 0.5);
}

struct StructGeo802D2360 *Geo18_802D2360(s32 sp30, short *sp34, UNUSED s32 sp38)
{
    s32 flags;
    short *sp28;
    Gfx *dlist = NULL;
    void *sp20 = NULL;

    if (sp30 == 1)
    {
        flags = save_file_get_flags();
        if (gDisplayedStars >= 0xa && (flags & SAVE_FLAG_HAVE_WING_CAP) == 0)
        {
            sp20 = alloc_display_list(0x10);
            if (sp20 == NULL)
                return NULL;
            else
                dlist = sp20;

            sp28 = sp34;
            sp28[1] = (sp28[1] & 0xFF) | 0x500;
            
            gSPDisplayList(dlist++, D_0702A880);
            gSPEndDisplayList(dlist);
        }
    }

    return sp20;
}

struct StructGeo802D2360 *Geo18_802D2470(s32 a0, UNUSED void *sp4, UNUSED s32 sp8) {

    if (a0 != 1)
    {
        D_80330398 = 0;
        D_80330394 = D_8032CFA8 - 1;
        D_80330390 = D_8032CFA8;
        D_8035FF80 = 0;
    }
    else
    {
        D_80330394 = D_80330390;
        D_80330390 = D_8032CFA8;
        if (D_80330394 != D_80330390) D_80330398 += 0x400;
    }

    return NULL;
}

void *Geo18_802D2520(s32 sp80, short *sp84, UNUSED s32 sp88)
{
    s16 n, sp7C, sp7A, x, y, z, tx, ty;
    Vtx *verts;
    short *sp68 = sp84;

    Gfx *sp64 = (Gfx *)segmented_to_virtual(&D_07019248);
    Gfx *sp60 = NULL, *sp5C = NULL;
    struct Object *sp58;
    

    if (sp80 == 1)
    {
        verts = alloc_display_list(0x150);
        sp60 = alloc_display_list(0x38);

        sp5C = sp60;

        if (verts == NULL || sp60 == NULL) return 0;

        sp68[1] = (sp68[1] & 0xFF) | 0x100;

        for (n = 0; n <= 20; n++)
        {
            sp7C = n / 3;
            sp7A = n % 3;

            x = ((s16 *)(u32) sp64 + (n << 2))[0];
            y = round_float(sins(D_80330398 + (sp7C << 0x0C) + (sp7A << 0x0E)) * 20.0);
            
            z = ((s16 *)(u32) sp64 + (n << 2))[1];
            tx = ((s16 *)(u32) sp64 + (n << 2))[2];
            ty = ((s16 *)(u32) sp64 + (n << 2))[3];

            make_vertex(verts, n, x, y, z, tx, ty, 0, 127, 0, 255);
        }

        gSPDisplayList(sp5C++, D_070192F0);
        gSPVertex(sp5C++, verts, 12, 0);
        gSPDisplayList(sp5C++, D_07019360);
        gSPVertex(sp5C++, verts + 9, 12, 0);
        gSPDisplayList(sp5C++, D_07019360);
        gSPDisplayList(sp5C++, D_070193C8);
        gSPEndDisplayList(sp5C);

        sp58 = (struct Object *) D_8032CFA0;
        if (gMarioObject->platform == sp58)
        {
            D_8035FF80 = 2;
        }
        else
        {
            if (sp58->forwardVel != 0.0)
                D_8035FF80 = 1;
            else
                D_8035FF80 = 0;
        }
    }

    return sp60; 
}

Gfx *Geo18_802D28CC(s32 sp30, short *sp34, UNUSED s32 sp38)
{
    short *sp2C = sp34;
    Gfx *sp28 = NULL;
    Gfx *sp24 = NULL;

    if (sp30 == 1)
    {
        sp28 = alloc_display_list(3 * sizeof(*sp28));
        sp24 = sp28;

        sp2C[1] = (sp2C[1] & 0xFF) | 0x100;
        gSPDisplayList(sp24++, seg2_f3d_014660);
        gSPDisplayList(sp24++, D_07026400);
        gSPEndDisplayList(sp24);
    }

    return sp28;  
}
