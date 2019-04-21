#include <ultra64.h>

#include "sm64.h"
#include "level_update.h"
#include "engine/math_util.h"
#include "memory.h"
#include "segment2.h"
#include "save_file.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "area.h"
#include "memory.h"
#include "transparent_texture.h"
#include "rendering_graph_node.h"

extern Gfx inside_castle_seg7_dl_0702A880[];
extern s16 rr_seg7_transparent_texture_data_07019248[];
extern Gfx rr_seg7_dl_070192F0[];
extern Gfx rr_seg7_dl_07019360[];
extern Gfx rr_seg7_dl_070193C8[];
extern Gfx cake_end_dl_07026400[];

s16 D_80330390 = 0x01, D_80330394 = 0, D_80330398 = 0;

s8 D_8035FF80;

extern u16 gAreaUpdateCounter;

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

s32 round_float(f32 f12)
{
    //! double literals instead of f32 literals
    if (f12 >= 0.0)
        return (s16)(f12 + 0.5);
    else
        return (s16)(f12 - 0.5);
}

Gfx *Geo18_802D2360(s32 run, struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    s32 flags;
    struct GraphNode12A *sp28;
    Gfx *dlist = NULL;
    Gfx *gfx = NULL;

    if (run == TRUE)
    {
        flags = save_file_get_flags();
        if (gDisplayedStars >= 0xa && (flags & SAVE_FLAG_HAVE_WING_CAP) == 0)
        {
            gfx = alloc_display_list(0x10);
            if (gfx == NULL)
                return NULL;
            else
                dlist = gfx;

            sp28 = (struct GraphNode12A *)node;
            sp28->fnNode.node.flags = (sp28->fnNode.node.flags & 0xFF) | 0x500;
            
            gSPDisplayList(dlist++, inside_castle_seg7_dl_0702A880);
            gSPEndDisplayList(dlist);
        }
    }

    return gfx;
}

Gfx *Geo18_802D2470(s32 run, UNUSED struct GraphNode *node, UNUSED f32 mtx[4][4])
{
    if (run != TRUE)
    {
        D_80330398 = 0;
        D_80330394 = gAreaUpdateCounter - 1;
        D_80330390 = gAreaUpdateCounter;
        D_8035FF80 = 0;
    }
    else
    {
        D_80330394 = D_80330390;
        D_80330390 = gAreaUpdateCounter;
        if (D_80330394 != D_80330390) D_80330398 += 0x400;
    }

    return NULL;
}

Gfx *Geo18_802D2520(s32 run, struct GraphNode *node, UNUSED s32 sp88)
{
    s16 n, sp7C, sp7A, x, y, z, tx, ty;
    Vtx *verts;
    struct GraphNode12A *sp68 = (struct GraphNode12A *)node;

    s16 *sp64 = (s16 *)segmented_to_virtual(&rr_seg7_transparent_texture_data_07019248);
    Gfx *sp60 = NULL, *sp5C = NULL;
    struct Object *sp58;
    

    if (run == TRUE)
    {
        verts = alloc_display_list(0x150);
        sp60 = alloc_display_list(0x38);

        sp5C = sp60;

        if (verts == NULL || sp60 == NULL) return 0;

        sp68->fnNode.node.flags = (sp68->fnNode.node.flags & 0xFF) | 0x100;

        for (n = 0; n <= 20; n++)
        {
            sp7C = n / 3;
            sp7A = n % 3;

            x = sp64[n*4 + 0];
            y = round_float(sins(D_80330398 + (sp7C << 0x0C) + (sp7A << 0x0E)) * 20.0);
            
            z = sp64[n*4 + 1];
            tx = sp64[n*4 + 2];
            ty = sp64[n*4 + 3];

            make_vertex(verts, n, x, y, z, tx, ty, 0, 127, 0, 255);
        }

        gSPDisplayList(sp5C++, rr_seg7_dl_070192F0);
        gSPVertex(sp5C++, verts, 12, 0);
        gSPDisplayList(sp5C++, rr_seg7_dl_07019360);
        gSPVertex(sp5C++, verts + 9, 12, 0);
        gSPDisplayList(sp5C++, rr_seg7_dl_07019360);
        gSPDisplayList(sp5C++, rr_seg7_dl_070193C8);
        gSPEndDisplayList(sp5C);

        sp58 = (struct Object *) D_8032CFA0;
        if (gMarioObject->platform == sp58)
        {
            D_8035FF80 = 2;
        }
        else
        {
            if (sp58->oForwardVel != 0.0)
                D_8035FF80 = 1;
            else
                D_8035FF80 = 0;
        }
    }

    return sp60; 
}

Gfx *Geo18_802D28CC(s32 run, struct GraphNode *node, UNUSED s32 sp38)
{
    struct GraphNode12A *sp2C = (struct GraphNode12A *)node;
    Gfx *gfxRet = NULL;
    Gfx *gfx = NULL;

    if (run == TRUE)
    {
        gfxRet = alloc_display_list(3 * sizeof(*gfxRet));
        gfx = gfxRet;

        sp2C->fnNode.node.flags = (sp2C->fnNode.node.flags & 0xFF) | 0x100;
        gSPDisplayList(gfx++, seg2_dl_02014660);
        gSPDisplayList(gfx++, cake_end_dl_07026400);
        gSPEndDisplayList(gfx);
    }

    return gfxRet;  
}
