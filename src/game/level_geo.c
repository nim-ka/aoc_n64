#include <ultra64.h>

#include "sm64.h"
#include "rendering_graph_node.h"
#include "mario_misc.h"
#include "skybox.h"
#include "engine/math_util.h"
#include "camera.h"
#include "envfx_snow.h"
#include "level_geo.h"

Gfx *geo_exec_level(s32 run, struct GraphNode *node, f32 c[4][4])
{
    Vec3s sp50;
    Vec3s sp48;
    Vec3s sp40;
    void *sp3C;
    Gfx *sp38 = NULL;

    if (run == TRUE  && gCurGraphNodeCamera != NULL)
    {
        struct GraphNodeGenerated *execNode = (struct GraphNodeGenerated *)node;
        u32 *params = &execNode->parameter; // accessed a s32 as 2 u16s by pointing to the variable and casting to a local struct as necessary.

        if (GET_HIGH_U16_OF_32(*params) != gAreaUpdateCounter)
        {
            UNUSED struct LevelCamera *sp2C = gCurGraphNodeCamera->levelCamera;
            s32 sp28 = GET_LOW_U16_OF_32(*params);

            vec3f_to_vec3s(sp40, gCurGraphNodeCamera->to);
            vec3f_to_vec3s(sp48, gCurGraphNodeCamera->from);
            vec3f_to_vec3s(sp50, gPlayerStatusForCamera->pos);
            sp3C = envfx_update_particles(sp28, sp50, sp40, sp48);
            if (sp3C != NULL)
            {
                Mtx *mtx = alloc_display_list(sizeof(*mtx));

                sp38 = alloc_display_list(2 * sizeof(*sp38));
                mtxf_to_mtx(mtx, c);
                gSPMatrix(&sp38[0], VIRTUAL_TO_PHYSICAL(mtx), G_MTX_MODELVIEW | G_MTX_LOAD);
                gSPBranchList(&sp38[1], VIRTUAL_TO_PHYSICAL(sp3C));
                execNode->fnNode.node.flags = (execNode->fnNode.node.flags & 0xFF) | 0x400;
            }
            SET_HIGH_U16_OF_32(*params, gAreaUpdateCounter);
        }
    }
    else if (run == 4)
    {
        vec3s_copy(sp40, gCurGeoAngle);
        vec3s_copy(sp48, gCurGeoAngle);
        vec3s_copy(sp50, gCurGeoAngle);
        envfx_update_particles(0, sp50, sp40, sp48);
    }
    return sp38;
}

Gfx *geo_skybox_main(s32 run, struct GraphNode *node, UNUSED Mat4 *mtx)
{
    Gfx *gfx = NULL;
    struct GraphNodeBackground *backgroundNode = (struct GraphNodeBackground *)node;

    if (run == 3) // pretty sure this cant be called: 3 is never passed via geo function calls.
    {
        backgroundNode->unused = 0;
    }
    else if (run == TRUE)
    {
        struct GraphNodeCamera *sp34 = (struct GraphNodeCamera *)gCurGraphNodeRoot->camera[0];
        struct GraphNodePerspective *camFrustum = (struct GraphNodePerspective *)sp34->fnNode.node.parent;

        gfx = func_802CF414(0, backgroundNode->background, camFrustum->fov,
            gCameraStatus.pos[0], gCameraStatus.pos[1], gCameraStatus.pos[2],
            gCameraStatus.focus[0], gCameraStatus.focus[1], gCameraStatus.focus[2]);
    }
    return gfx;
}
