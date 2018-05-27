#include <ultra64.h>
#include "sm64.h"

#include "geo_layout.h"
#include "math_util.h"
#include "memory.h"
#include "graph_node.h"

typedef void (*GeoLayoutCommandProc)(void);

GeoLayoutCommandProc GeoLayoutJumpTable[] = 
{
    geo_layout_cmd_00,
    geo_layout_cmd_01,
    geo_layout_cmd_02,
    geo_layout_cmd_03,
    geo_layout_cmd_04,
    geo_layout_cmd_05,
    geo_layout_cmd_06,
    geo_layout_cmd_07,
    geo_layout_cmd_08,
    geo_layout_cmd_09,
    geo_layout_cmd_0A,
    geo_layout_cmd_0B,
    geo_layout_cmd_0C,
    geo_layout_cmd_0D,
    geo_layout_cmd_0E,
    geo_layout_cmd_0F,
    geo_layout_cmd_10,
    geo_layout_cmd_11,
    geo_layout_cmd_12,
    geo_layout_cmd_13,
    geo_layout_cmd_14,
    geo_layout_cmd_15,
    geo_layout_cmd_16,
    geo_layout_cmd_17,
    geo_layout_cmd_18,
    geo_layout_cmd_19,
    geo_layout_cmd_1A,
    geo_layout_cmd_1B,
    geo_layout_cmd_1C,
    geo_layout_cmd_1D,
    geo_layout_cmd_1E,
    geo_layout_cmd_1F,
    geo_layout_cmd_20,
};

u32 unused_8038B894[3] = { 0 };

extern struct GraphNode D_8038BD88;

extern Vec3s D_80385FDC;
extern Vec3f D_80385FE4;

// branch and store
void geo_layout_cmd_00(void)
{
    gGeoLayoutStack[gGeoLayoutStackIndex++] = (u32) &gGeoLayoutCommand[8];
    gGeoLayoutStack[gGeoLayoutStackIndex++] = (gCurGraphNodeIndex << 16) + D_8038BD7E;
    D_8038BD7E = gGeoLayoutStackIndex;
    gGeoLayoutCommand = (u8 *) segmented_to_virtual((void *) cur_geo_cmd_s32(0x04));
}

// terminate geo layout
void geo_layout_cmd_01(void)
{
    gGeoLayoutStackIndex = D_8038BD7E;
    D_8038BD7E = gGeoLayoutStack[--gGeoLayoutStackIndex] & 0xFFFF;
    gCurGraphNodeIndex = gGeoLayoutStack[gGeoLayoutStackIndex] >> 16;
    gGeoLayoutCommand = (u8 *) gGeoLayoutStack[--gGeoLayoutStackIndex];
}

// branch geo layout
void geo_layout_cmd_02(void)
{
    if(cur_geo_cmd_u8(0x01) == 1)
    {
        gGeoLayoutStack[gGeoLayoutStackIndex++] = (u32) &gGeoLayoutCommand[8];
    }

    gGeoLayoutCommand = (u8 *) segmented_to_virtual((void *) cur_geo_cmd_s32(0x04));
}

// return from branch
void geo_layout_cmd_03(void)
{
    gGeoLayoutCommand = (u8 *) gGeoLayoutStack[--gGeoLayoutStackIndex];
}

// open node
void geo_layout_cmd_04(void)
{
    gCurGraphNodeList[gCurGraphNodeIndex + 1] = gCurGraphNodeList[gCurGraphNodeIndex];
    gCurGraphNodeIndex++;
    gGeoLayoutCommand += 0x04;
}

// close node
void geo_layout_cmd_05(void)
{
    gCurGraphNodeIndex--;
    gGeoLayoutCommand += 0x04;
}

void geo_layout_cmd_06(void)
{
    u16 index = cur_geo_cmd_s16(0x02);

    // if index is less than num allocated (see geo_layout_cmd_08)
    if(index < D_8038BCB0)
    {
        D_8038BCAC[index] = gCurGraphNodeList[gCurGraphNodeIndex];
    }

    gGeoLayoutCommand += 0x04;
}

// update node flags
void geo_layout_cmd_07(void)
{
    u16 operation = cur_geo_cmd_u8(0x01);
    u16 flagBits = cur_geo_cmd_s16(0x02);

    switch(operation)
    {
    case GEO_CMD_FLAGS_RESET:
        gCurGraphNodeList[gCurGraphNodeIndex]->flags = flagBits;
        break;
    case GEO_CMD_FLAGS_SET:
        gCurGraphNodeList[gCurGraphNodeIndex]->flags |= flagBits;
        break;
    case GEO_CMD_FLAGS_CLEAR:
        gCurGraphNodeList[gCurGraphNodeIndex]->flags &= ~flagBits;
        break;
    }

    gGeoLayoutCommand += 0x04;
}

// set screen area
void geo_layout_cmd_08(void)
{
    s32 sp34;
    struct GraphNodeScreenArea *graphNode;

    s16 x = cur_geo_cmd_s16(0x04); // x
    s16 y = cur_geo_cmd_s16(0x06); // y
    s16 width = cur_geo_cmd_s16(0x08); // width
    s16 height = cur_geo_cmd_s16(0x0A); // height
    
    // number of entries to allocate for D_8038BCAC array
    // at least 2 are allocated by default
    // cmd+0x02 = 0x00: mario face, 0x0A: all other levels
    D_8038BCB0 = cur_geo_cmd_s16(0x02) + 2;

    graphNode = init_graph_node_screen_area(gGraphNodePool, NULL, 0, x, y, width, height);

    // TODO: check type
    D_8038BCAC = (struct GraphNode **) alloc_only_pool_alloc(gGraphNodePool, D_8038BCB0 * sizeof(s32));

    graphNode->unk20 = D_8038BCAC;
    graphNode->unk1E = D_8038BCB0;
    
    // clear D_8038BCAC array
    for(sp34 = 0; sp34 < D_8038BCB0; sp34++)
    {
        D_8038BCAC[sp34] = NULL;
    }

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x0C;
}

void geo_layout_cmd_09(void)
{
    struct GraphNode002 *graphNode;
    f32 sp18 = (f32) cur_geo_cmd_s16(0x02) / 100.0f;
    
    graphNode = init_graph_node_002(gGraphNodePool, NULL, sp18);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04;
}

// set camera frustum
void geo_layout_cmd_0A(void)
{
    struct GraphNodeCamFrustum *graphNode;
    GraphNodeFunc frustumProc = NULL;
    s16 fov = cur_geo_cmd_s16(0x02);
    s16 near = cur_geo_cmd_s16(0x04);
    s16 far = cur_geo_cmd_s16(0x06);

    if(cur_geo_cmd_u8(0x01))
    {
        // optional asm function
        frustumProc = (GraphNodeFunc) cur_geo_cmd_s32(0x08);
        gGeoLayoutCommand += 0x04;
    }

    graphNode = init_graph_node_cam_frustum(gGraphNodePool, NULL, (float)fov, near, far, frustumProc, 0);

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoLayoutCommand += 0x08;
}

// start geo layout
void geo_layout_cmd_0B(void)
{
    struct GraphNode00A *graphNode;
    
    graphNode = init_graph_node_00A(gGraphNodePool, NULL);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04;
}

void geo_layout_cmd_1F(void)
{
    /* no operation */
    gGeoLayoutCommand += 0x10;
}

// toggle zbuffer
void geo_layout_cmd_0C(void)
{
    struct GraphNode004 *graphNode;
    
    graphNode = init_graph_node_004(gGraphNodePool, NULL, cur_geo_cmd_u8(0x01));

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04;
}

// set render range
void geo_layout_cmd_0D(void)
{
    struct GraphNode00B *graphNode;
    s16 minDistance = cur_geo_cmd_s16(0x04);
    s16 maxDistance = cur_geo_cmd_s16(0x06);

    graphNode = init_graph_node_00B(gGraphNodePool, NULL, minDistance, maxDistance);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x08;
}

// switch case
// 0x02 = numCases, 0x04 = asm function
void geo_layout_cmd_0E(void)
{
    struct GraphNode10C *graphNode;
    
    graphNode = init_graph_node_10C(gGraphNodePool, NULL,
        cur_geo_cmd_s16(0x02), // num cases
        0,
        (GraphNodeFunc) cur_geo_cmd_s32(0x04), // asm routine
        0);

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoLayoutCommand += 0x08;
}

void geo_layout_cmd_0F(void)
{
    struct GraphNode114 *graphNode;
    s16 *cmdPos = (s16 *) &gGeoLayoutCommand[4];

    Vec3f sp2c, sp20;

    cmdPos = read_vec3s_to_vec3f(sp2c, cmdPos);
    cmdPos = read_vec3s_to_vec3f(sp20, cmdPos);

    graphNode = init_graph_node_114(gGraphNodePool, NULL, sp2c, sp20,
        (GraphNodeFunc) cur_geo_cmd_s32(0x10),
        cur_geo_cmd_s16(0x02));

    register_scene_graph_node(&graphNode->fnNode.node);

    D_8038BCAC[0] = &graphNode->fnNode.node;

    gGeoLayoutCommand += 0x14;
}

// translate and rotate
void geo_layout_cmd_10(void)
{
    struct GraphNode015 *graphNode;

    Vec3s sp44, sp3c;

    void *dlist = NULL;
    s16 sp36 = 0;

    s16 sp34 = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;

    switch((sp34 & 0x70) >> 4)
    {
    case 0:
        cmdPos = read_vec3s(sp44, &cmdPos[2]);
        cmdPos = read_vec3s_angle(sp3c, cmdPos);
        break;
    case 1:
        cmdPos = read_vec3s(sp44, &cmdPos[1]);
        vec3s_copy(sp3c, D_80385FDC);
        break;
    case 2:
        cmdPos = read_vec3s_angle(sp3c, &cmdPos[1]);
        vec3s_copy(sp44, D_80385FDC);
        break;
    case 3:
        vec3s_copy(sp44, D_80385FDC);
        vec3s_set(sp3c, 0, (cmdPos[1] << 15) / 180, 0);
        cmdPos += 2;
        break;
    }

    if(sp34 & 0x80)
    {
        dlist = *(void **)&cmdPos[0];
        sp36 = sp34 & 0x0F;
        cmdPos += 2;
    }

    graphNode = init_graph_node_015(gGraphNodePool, NULL, sp36, dlist, sp44, sp3c);
    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

void geo_layout_cmd_11(void)
{
    struct GraphNode016 *graphNode;

    Vec3s sp2c;

    s16 sp2a = 0;
    s16 sp28 = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    void *dlist = NULL;

    cmdPos = read_vec3s(sp2c, &cmdPos[1]);

    if(sp28 & 0x80)
    {
        dlist = *(void **)&cmdPos[0];
        sp2a = sp28 & 0x0F;
        cmdPos += 2;
    }

    graphNode = init_graph_node_016(gGraphNodePool, NULL, sp2a, dlist, sp2c);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

void geo_layout_cmd_12(void)
{
    struct GraphNode017 *graphNode;

    Vec3s sp2c;

    s16 sp2a = 0;
    s16 sp28 = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    void *dlist = NULL;

    cmdPos = read_vec3s_angle(sp2c, &cmdPos[1]);

    if(sp28 & 0x80)
    {
        dlist = *(void **)&cmdPos[0];
        sp2a = sp28 & 0x0F;
        cmdPos += 2;
    }

    graphNode = init_graph_node_017(gGraphNodePool, NULL, sp2a, dlist, sp2c);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

// scale model
void geo_layout_cmd_1D(void)
{
    struct GraphNode01C *graphNode;

    s16 sp2a = 0;
    s16 sp28 = cur_geo_cmd_u8(0x01);
    f32 scale = cur_geo_cmd_u32(0x04) / 65536.0f;
    void *dlist = NULL;

    if(sp28 & 0x80)
    {
        dlist = (void *) cur_geo_cmd_s32(0x08);
        sp2a = sp28 & 0x0F;
        gGeoLayoutCommand += 0x04;
    }

    graphNode = init_graph_node_01C(gGraphNodePool, NULL, sp2a, dlist, scale);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x08;
}

void geo_layout_cmd_1E(void)
{
    /* no operation */
    gGeoLayoutCommand += 0x08;
}

// load display list
void geo_layout_cmd_13(void)
{
    struct GraphNode019 *graphNode;
    Vec3s relativePos;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    void *displayList = (void *) cur_geo_cmd_s32(0x08);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;

    read_vec3s(relativePos, &cmdPos[1]);

    graphNode = init_graph_node_019(gGraphNodePool, NULL, drawingLayer, displayList, relativePos);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x0C;
}

// billboard model
void geo_layout_cmd_14(void)
{
    struct GraphNode01A *graphNode;
    Vec3s sp2c;
    s16 sp2a = 0;
    s16 sp28 = cur_geo_cmd_u8(0x01);
    s16 *cmdPos = (s16 *) gGeoLayoutCommand;
    void *dlist = NULL;

    cmdPos = read_vec3s(sp2c, &cmdPos[1]);

    if(sp28 & 0x80)
    {
        dlist = *(void **)&cmdPos[0];
        sp2a = sp28 & 0x0F;
        cmdPos += 2;
    }

    graphNode = init_graph_node_01A(gGraphNodePool, NULL, sp2a, dlist, sp2c);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand = (u8 *) cmdPos;
}

// load display list
void geo_layout_cmd_15(void)
{
    struct GraphNode01B *graphNode;
    s32 drawingLayer = cur_geo_cmd_u8(0x01);
    void *dlist = (void *) cur_geo_cmd_s32(0x04);

    graphNode = init_graph_node_01B(gGraphNodePool, NULL, drawingLayer, dlist);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x08;
}

// start geo layout with shadow
void geo_layout_cmd_16(void)
{
    struct GraphNode028 *graphNode;
    u8 shadowType = cur_geo_cmd_s16(0x02);
    u8 shadowSolidity = cur_geo_cmd_s16(0x04);
    s16 shadowScale = cur_geo_cmd_s16(0x06);

    graphNode = init_graph_node_028(gGraphNodePool, NULL, shadowScale, shadowSolidity, shadowType);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x08;
}

void geo_layout_cmd_17(void)
{
    struct GraphNode029 *graphNode;

    graphNode = init_graph_node_029(gGraphNodePool, NULL, &D_8038BD88);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04;
}

// load polygons asm
void geo_layout_cmd_18(void)
{
    struct GraphNode12A *graphNode;

    graphNode = init_graph_node_12A(gGraphNodePool, NULL,
        (GraphNodeFunc) cur_geo_cmd_s32(0x04), // asm function
        cur_geo_cmd_s16(0x02)); // parameter

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoLayoutCommand += 0x08;
}

// set background
void geo_layout_cmd_19(void)
{
    struct GraphNode12C *graphNode;

    graphNode = init_graph_node_12C(gGraphNodePool, NULL,
        cur_geo_cmd_s16(0x02), // background ID, or RGBA5551 color if asm function is null
        (GraphNodeFunc) cur_geo_cmd_s32(0x04), // asm function
        0);
    
    register_scene_graph_node(&graphNode->fnNode.node);
    
    gGeoLayoutCommand += 0x08;
}

void geo_layout_cmd_1A(void)
{
    /* no operation */
    gGeoLayoutCommand += 0x08;
}

void geo_layout_cmd_1B(void)
{
    struct GraphNode029 *graphNode;
    struct GraphNode *sp20 = NULL;
    s16 index = cur_geo_cmd_s16(0x02);

    if(index >= 0)
    {
        sp20 = D_8038BCAC[index];

        if(sp20->type == GRAPH_NODE_TYPE_029)
        {
            sp20 = ((struct GraphNode029 *)sp20)->unk14;
        }
        else
        {
            sp20 = NULL;
        }
    }

    graphNode = init_graph_node_029(gGraphNodePool, NULL, sp20);

    register_scene_graph_node(&graphNode->node);

    gGeoLayoutCommand += 0x04;
}

void geo_layout_cmd_1C(void)
{
    struct GraphNode12E *graphNode;
    Vec3s sp24;

    read_vec3s(sp24, (s16 *) &gGeoLayoutCommand[0x02]);

    graphNode = init_graph_node_12E(gGraphNodePool, NULL, 0, sp24,
        (GraphNodeFunc) cur_geo_cmd_s32(0x08),
        cur_geo_cmd_u8(0x01));

    register_scene_graph_node(&graphNode->fnNode.node);

    gGeoLayoutCommand += 0x0C;
}

void geo_layout_cmd_20(void)
{
    struct GraphNode02F *graphNode;
    graphNode = init_graph_node_12F(gGraphNodePool, NULL, cur_geo_cmd_s16(0x02));
    register_scene_graph_node(&graphNode->node);
    gGeoLayoutCommand += 0x04;
}

struct GraphNode *process_geo_layout(struct AllocOnlyPool *pool, void *segptr)
{
    gCurRootGraphNode = NULL;

    D_8038BCB0 = 0; // number of entries in D_8038BCAC

    gCurGraphNodeList[0] = 0;
    gCurGraphNodeIndex = 0;

    gGeoLayoutStackIndex = 2;
    D_8038BD7E = 2; // stack index is often copied here

    gGeoLayoutCommand = (u8 *) segmented_to_virtual(segptr);

    gGraphNodePool = pool; 

    gGeoLayoutStack[0] = 0;
    gGeoLayoutStack[1] = 0;

    while(gGeoLayoutCommand != NULL)
    {
        GeoLayoutJumpTable[gGeoLayoutCommand[0x00]]();
    }

    return gCurRootGraphNode;
}
