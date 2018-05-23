#include <ultra64.h>
#include "sm64.h"

#include "level_update.h"
#include "math_util.h"
#include "memory.h"
#include "graph_node.h"

void init_scene_graph_node_links(struct GraphNode *graphNode, s32 type)
{
    graphNode->type = type;
    graphNode->flags = GRAPH_RENDER_01;
    graphNode->prev = graphNode;
    graphNode->next = graphNode;
    graphNode->parent = NULL;
    graphNode->children = NULL;
}

struct GraphNodeScreenArea *init_graph_node_screen_area(struct Struct80278464 *pool, struct GraphNodeScreenArea *graphNode,
    s16 sp20, s16 x, s16 y, s16 width, s16 height)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNodeScreenArea));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_SCREEN_AREA);

        graphNode->unk14 = sp20;
        graphNode->unk15 = 0;
        graphNode->x = x;
        graphNode->y = y;
        graphNode->width = width;
        graphNode->height = height;
        graphNode->unk20 = NULL;
        graphNode->unk1E = 0;
    }

    return graphNode;
}

struct GraphNode002 *init_graph_node_002(struct Struct80278464 *pool, struct GraphNode002 *graphNode, f32 sp20)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode002));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_002);

        graphNode->unk14 = sp20;
    }

    return graphNode;
}

struct GraphNodeCamFrustum *init_graph_node_cam_frustum(struct Struct80278464 *pool, struct GraphNodeCamFrustum *graphNode,
    f32 fov, s16 near, s16 far, GraphNodeFunc nodeFunc, s32 sp30)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNodeCamFrustum));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->fnNode.node, GRAPH_NODE_TYPE_103);

        graphNode->fov = fov;
        graphNode->near = near;
        graphNode->far = far;
        graphNode->fnNode.func = nodeFunc;
        graphNode->unk18 = sp30;

        if(nodeFunc != NULL)
        {
            nodeFunc(0, &graphNode->fnNode.node, pool);
        }
    }

    return graphNode;
}

struct GraphNode00A *init_graph_node_00A(struct Struct80278464 *pool, struct GraphNode00A *graphNode)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode00A));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_00A);
    }

    return graphNode;
}

struct GraphNode004 *init_graph_node_004(struct Struct80278464 *pool, struct GraphNode004 *graphNode, s16 sp22)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode004));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_004);

        if(sp22)
        {
            graphNode->node.flags |= GRAPH_RENDER_08;
        }
    }

    return graphNode;
}

struct GraphNode00B *init_graph_node_00B(struct Struct80278464 *pool, struct GraphNode00B *graphNode,
    s16 sp22, s16 sp26)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode00B));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_00B);
        graphNode->unk14 = sp22;
        graphNode->unk16 = sp26;
    }

    return graphNode;
}

// switch
struct GraphNode10C *init_graph_node_10C(struct Struct80278464 *pool, struct GraphNode10C *graphNode,
    s16 numCases, s16 sp26, GraphNodeFunc nodeFunc, s32 sp2c)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode10C));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->fnNode.node, GRAPH_NODE_TYPE_10C);
        graphNode->numCases = numCases;
        graphNode->unk1E = sp26;
        graphNode->fnNode.func = nodeFunc;
        graphNode->unk18 = sp2c;

        if(nodeFunc != NULL)
        {
            nodeFunc(0, &graphNode->fnNode.node, pool);
        }
    }

    return graphNode;
}

struct GraphNode114 *init_graph_node_114(struct Struct80278464 *pool, struct GraphNode114 * graphNode,
    f32 *sp20, f32 *sp24, GraphNodeFunc sp28, s32 sp2c)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode114));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->fnNode.node, GRAPH_NODE_TYPE_114);
        vec3f_copy(graphNode->unk1C, sp20);
        vec3f_copy(graphNode->unk28, sp24);
        graphNode->fnNode.func = sp28;
        graphNode->unk18 = sp2c;
        graphNode->unk38 = 0;
        graphNode->unk3A = 0;

        if(sp28 != NULL)
        {
            sp28(0, &graphNode->fnNode.node, pool);
        }
    }

    return graphNode;
}

struct GraphNode015 *init_graph_node_015(struct Struct80278464 *pool, struct GraphNode015 *graphNode,
    s32 drawingLayer, void *dlist, Vec3s sp28, Vec3s sp2c)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode015));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_015);

        vec3s_copy(graphNode->unk18, sp28);
        vec3s_copy(graphNode->unk1E, sp2c);
        graphNode->node.flags = (drawingLayer << 8) | (graphNode->node.flags & 0xFF);
        graphNode->dlist = dlist;
    }

    return graphNode;
}

struct GraphNode016 *init_graph_node_016(struct Struct80278464 *pool, struct GraphNode016 *graphNode,
    s32 drawingLayer, void *dlist, Vec3s sp28)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode016));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_016);

        vec3s_copy(graphNode->unk18, sp28);
        graphNode->node.flags = (drawingLayer << 8) | (graphNode->node.flags & 0xFF);
        graphNode->dlist = dlist;
    }

    return graphNode;
}

struct GraphNode017 *init_graph_node_017(struct Struct80278464 *pool, struct GraphNode017 *graphNode,
    s32 drawingLayer, void *dlist, Vec3s sp28)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode017));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_017);
        vec3s_copy(graphNode->unk18, sp28);
        graphNode->node.flags = (drawingLayer << 8) | (graphNode->node.flags & 0xFF);
        graphNode->dlist = dlist;
    }

    return graphNode;
}

struct GraphNode01C *init_graph_node_01C(struct Struct80278464 *pool, struct GraphNode01C *graphNode,
    s32 drawingLayer, void *dlist, f32 sp28)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode01C));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_01C);
        graphNode->node.flags = (drawingLayer << 8) | (graphNode->node.flags & 0xFF);
        graphNode->unk18 = sp28;
        graphNode->dlist = dlist;
    }

    return graphNode;
}

struct GraphNode018 *init_graph_node_018(struct Struct80278464 *pool, struct GraphNode018 *graphNode,
    struct GraphNode *sp20, Vec3f pos, Vec3s angle, Vec3f scale)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode018));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_018);
        vec3f_copy(graphNode->pos, pos);
        vec3f_copy(graphNode->scale, scale);
        vec3s_copy(graphNode->angle, angle);
        graphNode->unk14 = sp20;
        graphNode->unk50 = 0;
        graphNode->unk38.unk00 = 0;
        graphNode->unk38.unk04 = NULL;
        graphNode->unk38.animFrame = 0;
        graphNode->unk38.unk0C = 0;
        graphNode->unk38.unk10 = 0x10000;
        graphNode->unk38.animTimer = 0;
        graphNode->node.flags |= GRAPH_RENDER_20;
    }

    return graphNode;
}

struct GraphNode02F *init_graph_node_12F(struct Struct80278464 *pool, struct GraphNode02F *graphNode,
    s16 sp22)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode02F));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_02F);
        graphNode->unk14 = sp22;
    }

    return graphNode;
}

struct GraphNode019 *init_graph_node_019(struct Struct80278464 *pool, struct GraphNode019 * graphNode,
    s32 drawingLayer, void *dlist, Vec3s relativePos)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode019));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_019);
        vec3s_copy(graphNode->relativePos, relativePos);
        graphNode->node.flags = (drawingLayer << 8) | (graphNode->node.flags & 0xFF);
        graphNode->dlist = dlist;
    }

    return graphNode;
}

struct GraphNode01A *init_graph_node_01A(struct Struct80278464 *pool, struct GraphNode01A *graphNode,
    s32 drawingLayer, void *dlist, Vec3s sp28)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode01A));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_01A);
        vec3s_copy(graphNode->unk18, sp28);
        graphNode->node.flags = (drawingLayer << 8) | (graphNode->node.flags & 0xFF);
        graphNode->dlist = dlist;
    }

    return graphNode;
}

struct GraphNode01B *init_graph_node_01B(struct Struct80278464 *pool, struct GraphNode01B *graphNode,
    s32 drawingLayer, void *dlist)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode01B));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_01B);
        graphNode->node.flags = (drawingLayer << 8) | (graphNode->node.flags & 0xFF);
        graphNode->dlist = dlist;
    }

    return graphNode;
}

struct GraphNode028 *init_graph_node_028(struct Struct80278464 *pool, struct GraphNode028 *graphNode,
    s16 shadowScale, u8 shadowSolidity, u8 shadowType)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode028));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_028);
        graphNode->shadowScale = shadowScale;
        graphNode->shadowSolidity = shadowSolidity;
        graphNode->shadowType = shadowType;
    }

    return graphNode;
}

struct GraphNode029 *init_graph_node_029(struct Struct80278464 *pool, struct GraphNode029 *graphNode,
    struct GraphNode *sp24)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode029));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->node, GRAPH_NODE_TYPE_029);
        graphNode->unk14 = sp24;
    }

    return graphNode;
}

struct GraphNode12A *init_graph_node_12A(struct Struct80278464 *pool, struct GraphNode12A *graphNode,
    GraphNodeFunc sp20, s32 sp24)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode12A));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->fnNode.node, GRAPH_NODE_TYPE_12A);
        graphNode->fnNode.func = sp20;
        graphNode->unk18 = sp24;

        if(sp20 != NULL)
        {
            sp20(0, &graphNode->fnNode.node, pool);
        }
    }

    return graphNode;
}

// background
struct GraphNode12C *init_graph_node_12C(struct Struct80278464 *pool, struct GraphNode12C *graphNode,
    u16 sp22, GraphNodeFunc sp24, s32 sp28)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode12C));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->fnNode.node, GRAPH_NODE_TYPE_12C);

        graphNode->unk1C = (sp22 << 16) | sp22;
        graphNode->fnNode.func = sp24;
        graphNode->unk18 = sp28;

        if(sp24 != NULL)
        {
            sp24(0, &graphNode->fnNode.node, pool);
        }
    }

    return graphNode;
}

struct GraphNode12E *init_graph_node_12E(struct Struct80278464 *pool, struct GraphNode12E *graphNode,
    s32 sp20, Vec3s sp24, GraphNodeFunc nodeFunc, s32 sp2c)
{
    if(pool != NULL)
    {
        graphNode = SimpleAllocate(pool, sizeof(struct GraphNode12E));
    }

    if(graphNode != NULL)
    {
        init_scene_graph_node_links(&graphNode->fnNode.node, GRAPH_NODE_TYPE_12E);
        vec3s_copy(graphNode->unk20, sp24);
        graphNode->unk1C = (struct GraphNode018 *) sp20; // assumed type
        graphNode->fnNode.func = nodeFunc;
        graphNode->unk18 = sp2c;

        if(nodeFunc != NULL)
        {
            nodeFunc(0, &graphNode->fnNode.node, pool);
        }
    }

    return graphNode;
}

struct GraphNode *func_8037C044(struct GraphNode *prevNode, struct GraphNode *node)
{
    struct GraphNode *sp04;
    struct GraphNode *sp00;

    if(node != NULL)
    {
        node->parent = prevNode;
        sp04 = prevNode->children;

        if(sp04 == NULL)
        {
            prevNode->children = node;
            node->prev = node;
            node->next = node;
        }
        else
        {
            sp00 = sp04->prev;
            node->prev = sp00;
            node->next = sp04;
            sp04->prev = node;
            sp00->next = node;
        }
    }

    return node;
}

struct GraphNode *func_8037C0BC(struct GraphNode *graphNode)
{
    struct GraphNode *sp04;
    struct GraphNode **sp00;

    sp04 = graphNode->parent;
    sp00 = &sp04->children;

    graphNode->prev->next = graphNode->next;
    graphNode->next->prev = graphNode->prev;

    if(*sp00 == graphNode)
    {
        if(graphNode->next == graphNode)
        {
            *sp00 = NULL;
        }
        else
        {
            *sp00 = graphNode->next;
        }
    }

    return sp04;
}

struct GraphNode *func_8037C138(struct GraphNode *a0)
{
    struct GraphNode *sp0c;
    struct GraphNode *sp08;
    struct GraphNode **sp04;

    sp08 = a0->parent;
    sp04 = &sp08->children;

    if(*sp04 != a0)
    {
        if((*sp04)->prev != a0)
        {
            a0->prev->next = a0->next;
            a0->next->prev = a0->prev;
            sp0c = (*sp04)->prev;
            a0->prev = sp0c;
            a0->next = *sp04;
            (*sp04)->prev = a0;
            sp0c->next = a0;
        }
        *sp04 = a0;
    }
    
    return sp08;
}

// recursive
void func_8037C1E4(struct GraphNode *graphNode, s32 sp34)
{
    struct GraphNode **sp2c;
    struct GraphNode *sp28;
    struct FnGraphNode *sp24;
    
    sp28 = graphNode;

    do
    {
        sp24 = (struct FnGraphNode *) sp28;

        if(sp28->type & GRAPH_NODE_TYPE_FUNCTIONAL)
        {
            if(sp24->func != NULL)
            {
                sp24->func(sp34, sp28, 0);
            }
        }

        if(sp28->children != NULL)
        {
            switch(sp28->type)
            {
            case GRAPH_NODE_TYPE_004: // zbuffer
                sp2c = (struct GraphNode **) &D_8032CF94;
                break;
            case GRAPH_NODE_TYPE_103: // camera frustum
                sp2c = (struct GraphNode **) &D_8032CF98;
                break;
            case GRAPH_NODE_TYPE_114:
                sp2c = (struct GraphNode **) &D_8032CF9C;
                break;
            case GRAPH_NODE_TYPE_018: // object
                sp2c = (struct GraphNode **) &D_8032CFA0;
                break;
            default:
                sp2c = NULL;
                break;
            }

            if(sp2c != NULL)
            {
                *sp2c = sp28;
            }

            func_8037C1E4(sp28->children, sp34);

            if(sp2c != NULL)
            {
                *sp2c = NULL;
            }
        }
    } while((sp28 = sp28->next) != graphNode);
}

// a0 = GraphNodeScreenArea?
void func_8037C360(struct GraphNode *graphNode, s32 sp1c)
{
    if(graphNode->flags & GRAPH_RENDER_01)
    {
        D_8032CF90 = (struct GraphNodeScreenArea *) graphNode;

        if(graphNode->children != NULL)
        {
            func_8037C1E4(graphNode->children, sp1c);
        }

        D_8032CF90 = 0;
    }
}

void func_8037C3D0(struct GraphNode018 *graphNode)
{
    init_graph_node_018(NULL, graphNode, 0, D_80385FD0, D_80385FDC, D_80385FE4);
    
    func_8037C044(&D_8038BD88, &graphNode->node);
    graphNode->node.flags &= ~GRAPH_RENDER_01;
}

void func_8037C448(struct GraphNode018 *graphNode, void *sp1c, Vec3f pos, Vec3s angle)
{
    vec3f_set(graphNode->scale, 1.0f, 1.0f, 1.0f);
    vec3f_copy(graphNode->pos, pos);
    vec3s_copy(graphNode->angle, angle);

    graphNode->unk14 = sp1c;
    graphNode->unk4C = 0;
    graphNode->unk50 = 0;
    graphNode->unk38.unk04 = NULL;

    graphNode->node.flags |= GRAPH_RENDER_01;
    graphNode->node.flags &= ~GRAPH_RENDER_10;
    graphNode->node.flags |= GRAPH_RENDER_20;
    graphNode->node.flags &= ~GRAPH_RENDER_BILLBOARD;
}

void func_8037C51C(struct GraphNode018 *graphNode, struct SpawnInfo *sp1c)
{
    vec3f_set(graphNode->scale, 1.0f, 1.0f, 1.0f);
    vec3s_copy(graphNode->angle, sp1c->startAngle);

    graphNode->pos[0] = (f32) sp1c->startPos[0];
    graphNode->pos[1] = (f32) sp1c->startPos[1];
    graphNode->pos[2] = (f32) sp1c->startPos[2];

    graphNode->unk18 = sp1c->areaIndex;
    graphNode->unk19 = sp1c->unk0D;
    graphNode->unk14 = sp1c->unk18;
    graphNode->unk4C = sp1c;
    graphNode->unk50 = 0;
    graphNode->unk38.unk04 = 0;

    graphNode->node.flags |= GRAPH_RENDER_01;
    graphNode->node.flags &= ~GRAPH_RENDER_10;
    graphNode->node.flags |= GRAPH_RENDER_20;
    graphNode->node.flags &= ~GRAPH_RENDER_BILLBOARD;
}

void func_8037C658(struct GraphNode018 *graphNode, void *sp34)
{
    void *sp2c = segmented_to_virtual(sp34);
    struct UnknownStruct5 *sp28 = segmented_to_virtual((void*)*(s32*)sp2c);

    if(graphNode->unk38.unk04 != sp28)
    {
        graphNode->unk38.unk04 = sp28;
        graphNode->unk38.animFrame = (sp28->unk04) + ((sp28->unk00 & 0x0002) ? 1 : -1);
        graphNode->unk38.unk10 = 0;
        graphNode->unk38.unk02 = 0;
    }
}

void func_8037C708(struct GraphNode018 *graphNode, void *sp34, u32 sp38)
{
    void **sp2c = segmented_to_virtual(sp34);
    struct UnknownStruct5 *sp28 = segmented_to_virtual(sp2c[0]);

    if(graphNode->unk38.unk04 != sp28)
    {
        graphNode->unk38.unk04 = sp28;
        graphNode->unk38.unk02 = 0;
        graphNode->unk38.unk0C = (sp28->unk04 << 16) + ((sp28->unk00 & 0x0002) ? sp38 : -sp38);
        graphNode->unk38.animFrame = graphNode->unk38.unk0C >> 16;
    }

    graphNode->unk38.unk10 = sp38;
}

s32 func_8037C7D8(s32 a0, u16 **a1)
{
    s32 sp04;

    if(a0 < (*a1)[0])
    {
        sp04 = (*a1)[1] + a0;
    }
    else
    {
        sp04 = (*a1)[1] + (*a1)[0] - 1;
    }

    *a1 += 2;

    return sp04;
}

s16 func_8037C844(struct GraphNode018_sub *a0, s32* a1)
{
    s32 sp04;
    struct UnknownStruct5 *sp00;
    
    sp00 = a0->unk04;

    if(a0->animTimer == D_8032CFA8 || sp00->unk00 & 0x0004)
    {
        if(a1 != NULL)
        {
            a1[0] = a0->unk0C;
        }

        return a0->animFrame;
    }

    if(sp00->unk00 & 0x0002)
    {
        if(a0->unk10)
        {
            sp04 = a0->unk0C - a0->unk10;
        }
        else
        {
            sp04 = (a0->animFrame - 1) << 16;
        }

        if(*(s16*)&sp04 < sp00->unk06)
        {
            if(sp00->unk00 & 0x0001)
            {
                *(s16 *)&sp04 = sp00->unk06;
            }
            else
            {
                *(s16 *)&sp04 = sp00->unk08 - 1;
            }
        }
    }
    else
    {
        if(a0->unk10 != 0)
        {
            sp04 = a0->unk0C + a0->unk10;
        }
        else
        {
            sp04 = (a0->animFrame + 1) << 16;
        }

        if(*(s16 *)&sp04 >= sp00->unk08)
        {
            if(sp00->unk00 & 0x0001)
            {
                *(s16 *) &sp04 = sp00->unk08 - 1;
            }
            else
            {
                *(s16 *) &sp04 = sp00->unk06;
            }
        }
    }

    if(a1 != 0)
    {
        a1[0] = sp04;
    }

    return *(s16 *) &sp04;
}

void Unknown8037C9E8(struct GraphNode018 *sp28, Vec3f sp2c)
{
    struct UnknownStruct5 *sp24 = sp28->unk38.unk04;
    u16 *sp20;
    s16 *sp1c;
    s16 sp1a;
    
    if(sp24 != NULL)
    {
        sp20 = segmented_to_virtual(sp24->unk10);
        sp1c = segmented_to_virtual(sp24->unk0C);

        sp1a = sp28->unk38.animFrame;

        if(sp1a < 0)
        {
            sp1a = 0;
        }

        if(1) // ? necessary to match
        {
            sp2c[0] = (f32) sp1c[func_8037C7D8(sp1a, &sp20)];
            sp2c[1] = (f32) sp1c[func_8037C7D8(sp1a, &sp20)];
            sp2c[2] = (f32) sp1c[func_8037C7D8(sp1a, &sp20)];
        }
    }
    else
    {
        vec3f_set(sp2c, 0, 0, 0);
    }
}

struct GraphNodeScreenArea *Unknown8037CB10(struct GraphNode *graphNode)
{
    struct GraphNodeScreenArea *resGraphNode = NULL;

    while(graphNode->parent != NULL)
    {
        graphNode = graphNode->parent;
    }

    if(graphNode->type == GRAPH_NODE_TYPE_SCREEN_AREA)
    {
        resGraphNode = (struct GraphNodeScreenArea *) graphNode;
    }

    return resGraphNode;
}

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
