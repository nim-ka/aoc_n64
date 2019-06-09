#include <ultra64.h>
#include "sm64.h"

#include "game/level_update.h"
#include "math_util.h"
#include "game/memory.h"
#include "graph_node.h"
#include "game/rendering_graph_node.h"
#include "game/area.h"
#include "geo_layout.h"

s16 *read_vec3s_to_vec3f(Vec3f dst, s16 *src)
{
    dst[0] = *src++;
    dst[1] = *src++;
    dst[2] = *src++;
    return src;
}

s16 *read_vec3s(Vec3s dst, s16 *src)
{
    dst[0] = *src++;
    dst[1] = *src++;
    dst[2] = *src++;
    return src;
}

s16 *read_vec3s_angle(Vec3s dst, s16 *src)
{
    dst[0] = ((*src++) << 15) / 180;
    dst[1] = ((*src++) << 15) / 180;
    dst[2] = ((*src++) << 15) / 180;
    return src;
}

void register_scene_graph_node(struct GraphNode *graphNode)
{
    if(graphNode != NULL)
    {
        gCurGraphNodeList[gCurGraphNodeIndex] = graphNode;

        if(gCurGraphNodeIndex == 0)
        {
            if(gCurRootGraphNode == NULL)
            {
                gCurRootGraphNode = graphNode;
            }
        }
        else
        {
            if(gCurGraphNodeList[gCurGraphNodeIndex-1]->type == GRAPH_NODE_TYPE_029)
            {
                ((struct GraphNode029 *) gCurGraphNodeList[gCurGraphNodeIndex-1])->unk14 = graphNode;
            }
            else
            {
                func_8037C044(gCurGraphNodeList[gCurGraphNodeIndex-1], graphNode);
            }
        }
    }
}
