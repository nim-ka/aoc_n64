#include <ultra64.h>

#include "sm64.h"
#include "rendering_graph_node.h"
#include "castle_message_behaviors.h"
#include "skybox.h"
#include "engine/math_util.h"
#include "camera.h"
#include "envfx_snow.h"

// level_geo_main?
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
            vec3f_to_vec3s(sp50, D_8033B1B0->unk4);
            sp3C = envfx_update_particles(sp28, sp50, sp40, sp48);
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
        envfx_update_particles(0, sp50, sp40, sp48);
    }
    return sp38;
}

// skybox_geo_main?
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
