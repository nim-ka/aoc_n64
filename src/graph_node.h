#ifndef _GRAPH_NODE_H_
#define _GRAPH_NODE_H_

#include "types.h"

extern struct GraphNodeScreenArea *D_8032CF90;
extern struct GraphNode004 *D_8032CF94;
extern struct GraphNodeCamFrustum *D_8032CF98;
extern struct GraphNode114 *D_8032CF9C;
extern struct GraphNode018 *D_8032CFA0;
extern struct GraphNode12E *D_8032CFA4;
extern u16 D_8032CFA8;

extern struct GraphNode *gCurRootGraphNode;
extern struct GraphNode *gCurGraphNodeList[];

extern s16 gCurGraphNodeIndex;

extern struct GraphNode D_8038BD88;

extern Vec3f D_80385FD0;
extern Vec3s D_80385FDC;
extern Vec3f D_80385FE4;

#define GRAPH_RENDER_01      0x01
#define GRAPH_RENDER_02      0x02
#define GRAPH_RENDER_BILLBOARD 0x04
#define GRAPH_RENDER_08      0x08
#define GRAPH_RENDER_10      0x10
#define GRAPH_RENDER_20      0x20

#define GRAPH_NODE_TYPE_FUNCTIONAL  0x100
#define GRAPH_NODE_TYPE_SCREEN_AREA 0x001
#define GRAPH_NODE_TYPE_002         0x002
#define GRAPH_NODE_TYPE_103        (0x003 | GRAPH_NODE_TYPE_FUNCTIONAL)
#define GRAPH_NODE_TYPE_004         0x004
#define GRAPH_NODE_TYPE_00A         0x00A
#define GRAPH_NODE_TYPE_00B         0x00B
#define GRAPH_NODE_TYPE_10C        (0x00C | GRAPH_NODE_TYPE_FUNCTIONAL)
#define GRAPH_NODE_TYPE_114        (0x014 | GRAPH_NODE_TYPE_FUNCTIONAL)
#define GRAPH_NODE_TYPE_015         0x015
#define GRAPH_NODE_TYPE_016         0x016
#define GRAPH_NODE_TYPE_017         0x017
#define GRAPH_NODE_TYPE_018         0x018
#define GRAPH_NODE_TYPE_019         0x019
#define GRAPH_NODE_TYPE_01A         0x01A
#define GRAPH_NODE_TYPE_01B         0x01B
#define GRAPH_NODE_TYPE_01C         0x01C
#define GRAPH_NODE_TYPE_028         0x028
#define GRAPH_NODE_TYPE_029         0x029
#define GRAPH_NODE_TYPE_12A        (0x02A | GRAPH_NODE_TYPE_FUNCTIONAL)
#define GRAPH_NODE_TYPE_12C        (0x02C | GRAPH_NODE_TYPE_FUNCTIONAL)
#define GRAPH_NODE_TYPE_12E        (0x02E | GRAPH_NODE_TYPE_FUNCTIONAL)
#define GRAPH_NODE_TYPE_02F         0x02F

struct GraphNode
{
    /*0x00*/ s16 type; // structure type
    /*0x00*/ s16 flags; // hi = drawing layer, lo = rendering modes
    /*0x04*/ struct GraphNode *prev;
    /*0x08*/ struct GraphNode *next;
    /*0x0C*/ struct GraphNode *parent;
    /*0x10*/ struct GraphNode *children;
};

typedef int (*GraphNodeFunc)(s32 unk, struct GraphNode *node, void *);

struct FnGraphNode
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ GraphNodeFunc func;
};

struct GraphNodeScreenArea
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ u8 unk14;
    /*0x15*/ s8 unk15;
    /*0x16*/ s16 x;
    /*0x18*/ s16 y;
    /*0x1A*/ s16 width;
    /*0x1C*/ s16 height;
    /*0x1E*/ s16 unk1E;
    /*0x20*/ struct GraphNode **unk20; // TODO: check type
};

struct GraphNode002
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ f32 unk14;
};

struct GraphNodeCamFrustum
{
    /*0x00*/ struct FnGraphNode fnNode;
    /*0x18*/ s32 unk18;
    /*0x1C*/ f32 fov;
    /*0x20*/ s16 near;
    /*0x22*/ s16 far;
};

struct GraphNode004_sub
{
    void *unk0;
    void *unk4;
    struct GraphNode004_sub *unk8;
};

struct GraphNode004
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ struct GraphNode004_sub *unk14[8];
    /*0x34*/ struct GraphNode004_sub *unk34[1];  // unknown length
    u8 filler38[0x54-0x38];
};

struct GraphNode00A
{
    /*0x00*/ struct GraphNode node;
};

struct GraphNode00B
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ s16 unk14;
    /*0x16*/ s16 unk16;
};

struct GraphNode10C
{
    /*0x00*/ struct FnGraphNode fnNode;
    /*0x18*/ s32 unk18;
    /*0x1C*/ s16 numCases;
    /*0x1E*/ s16 unk1E;
};

struct GraphNode114
{
    /*0x00*/ struct FnGraphNode fnNode;
    /*0x18*/ s32 unk18;
    /*0x1C*/ Vec3f unk1C;
    /*0x28*/ Vec3f unk28;
    /*0x34*/ void *unk34; // matrix ptr
    /*0x38*/ s16 unk38;
    /*0x3A*/ s16 unk3A;
};

struct GraphNode015
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ void *dlist;
    /*0x18*/ Vec3s unk18;
    /*0x1E*/ Vec3s unk1E;
};

struct GraphNode016
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ void *dlist;
    /*0x18*/ Vec3s unk18;
    u8 pad1E[2];
};

struct GraphNode017
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ void *dlist;
    /*0x18*/ Vec3s unk18;
    u8 pad1E[2];
};

struct Struct8037C51C
{
    /*0x00*/ s16 posX; // node.unk20[0] x
    /*0x02*/ s16 posY; // node.unk20[1] y 
    /*0x04*/ s16 posZ; // node.unk20[2] z
    /*0x06*/ Vec3s angle; // node.unk1A
    /*0x0C*/ s8 unk0C; // node.unk18
    /*0x0D*/ s8 unk0D; // node.unk19
    /*0x0E*/ u8 filler0E[0x18-0x0E];
    /*0x18*/ void* unk18; // node.unk14
};

struct GraphNode018_sub
{
    /*0x00 0x38*/ s16 unk00;
    /*0x02 0x3A*/ s16 unk02;
    /*0x04 0x3C*/ struct UnknownStruct5 *unk04;
    /*0x08 0x40*/ s16 animFrame;
    /*0x0A 0x42*/ u16 animTimer;
    /*0x0C 0x44*/ s32 unk0C;
    /*0x10 0x48*/ s32 unk10;
};

// TODO this is the first member of GfxNode/Object
struct GraphNode018
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ struct GraphNode *unk14;
    /*0x18*/ s8 unk18;
    /*0x19*/ s8 unk19;
    /*0x1A*/ Vec3s angle;
    /*0x20*/ Vec3f pos;
    /*0x2C*/ Vec3f scale;
    /*0x38*/ struct GraphNode018_sub unk38;
    /*0x4C*/ struct Struct8037C51C *unk4C;
    /*0x50*/ void *unk50; // matrix ptr
    /*0x54*/ f32 unk54;
    /*0x58*/ f32 unk58;
    /*0x5C*/ f32 unk5C;
};

struct GraphNode019
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ void *dlist;
    /*0x18*/ Vec3s relativePos;
};

struct GraphNode01A
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ void *dlist;
    /*0x18*/ Vec3s unk18;
};

struct GraphNode01B
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ void *dlist;
};

struct GraphNode01C
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ void *dlist;
    /*0x18*/ f32 unk18;
};

struct GraphNode028
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ s16 shadowScale;
    /*0x16*/ u8 shadowSolidity;
    /*0x17*/ u8 shadowType;
};

struct GraphNode029
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ struct GraphNode *unk14;
};

struct GraphNode12A
{
    /*0x00*/ struct FnGraphNode fnNode;
    /*0x18*/ s32 unk18;
};

struct GraphNode12C
{
    /*0x00*/ struct FnGraphNode fnNode;
    /*0x18*/ s32 unk18;
    /*0x1C*/ s32 unk1C;
};

struct GraphNode12E
{
    /*0x00*/ struct FnGraphNode fnNode;
    /*0x18*/ s32 unk18;
    /*0x1C*/ struct GraphNode018 *unk1C; // assumed type
    /*0x20*/ Vec3s unk20;
};

struct GraphNode02F
{
    /*0x00*/ struct GraphNode node;
    /*0x14*/ s16 unk14;
    u8 pad1E[2];
};

void init_scene_graph_node_links(struct GraphNode *, s32);

struct GraphNodeScreenArea *init_graph_node_screen_area(struct Struct80278464 *, struct GraphNodeScreenArea *,
    s16, s16 x, s16 y, s16 width, s16 height);
struct GraphNode002 *init_graph_node_002(struct Struct80278464 *, struct GraphNode002 *, f32);
struct GraphNodeCamFrustum *init_graph_node_cam_frustum(struct Struct80278464 *pool, struct GraphNodeCamFrustum *sp1c,
    f32 sp20, s16 sp26, s16 sp2a, GraphNodeFunc sp2c, s32 sp30);
struct GraphNode00A *init_graph_node_00A(struct Struct80278464 *pool, struct GraphNode00A *sp1c);
struct GraphNode004 *init_graph_node_004(struct Struct80278464 *pool, struct GraphNode004 *, s16 sp22);
struct GraphNode00B *init_graph_node_00B(struct Struct80278464 *pool, struct GraphNode00B *sp1c,
    s16 sp22, s16 sp26);
struct GraphNode10C *init_graph_node_10C(struct Struct80278464 *, struct GraphNode10C *sp1c,
    s16 sp22, s16 sp26, GraphNodeFunc sp28, s32 sp2c);
struct GraphNode114 *init_graph_node_114(struct Struct80278464 *pool, struct GraphNode114 * sp1c,
    f32 *sp20, f32 *sp24, GraphNodeFunc sp28, s32 sp2c);
struct GraphNode015 *init_graph_node_015(struct Struct80278464 *pool, struct GraphNode015 *graphNode,
    s32 drawingLayer, void *dlist, Vec3s sp28, Vec3s sp2c);
struct GraphNode016 *init_graph_node_016(struct Struct80278464 *pool, struct GraphNode016 *graphNode,
    s32 drawingLayer, void *dlist, Vec3s sp28);
struct GraphNode017 *init_graph_node_017(struct Struct80278464 *pool, struct GraphNode017 *graphNode,
    s32 drawingLayer, void *dlist, Vec3s sp28);
struct GraphNode01C *init_graph_node_01C(struct Struct80278464 *pool, struct GraphNode01C *graphNode,
    s32 drawingLayer, void *dlist, f32 sp28);
struct GraphNode018 *init_graph_node_018(struct Struct80278464 *pool, struct GraphNode018 *graphNode,
    struct GraphNode *sp20, Vec3f pos, Vec3s angle, Vec3f scale);
struct GraphNode02F *init_graph_node_12F(struct Struct80278464 *pool, struct GraphNode02F *sp1c,
    s16 sp22);
struct GraphNode019 *init_graph_node_019(struct Struct80278464 *pool, struct GraphNode019 * graphNode,
    s32 drawingLayer, void *dlist, Vec3s relativePos);
struct GraphNode01A *init_graph_node_01A(struct Struct80278464 *pool, struct GraphNode01A *graphNode,
    s32 drawingLayer, void *dlist, Vec3s sp28);
struct GraphNode01B *init_graph_node_01B(struct Struct80278464 *pool, struct GraphNode01B *graphNode,
    s32 drawingLayer, void *dlist);
struct GraphNode028 *init_graph_node_028(struct Struct80278464 *pool, struct GraphNode028 *sp1c,
    s16 sp22, u8 sp27, u8 sp2b);
struct GraphNode029 *init_graph_node_029(struct Struct80278464 *pool, struct GraphNode029 *sp1c,
    struct GraphNode *sp20);
struct GraphNode12A *init_graph_node_12A(struct Struct80278464 *pool, struct GraphNode12A *sp1c,
    GraphNodeFunc sp20, s32 sp24);
struct GraphNode12C *init_graph_node_12C(struct Struct80278464 *pool, struct GraphNode12C *sp1c,
    u16 sp22, GraphNodeFunc sp24, s32 sp28);
struct GraphNode12E *init_graph_node_12E(struct Struct80278464 *pool, struct GraphNode12E *sp1c,
    s32 sp20, Vec3s sp24, GraphNodeFunc sp28, s32 sp2c);

struct GraphNode *func_8037C044(struct GraphNode *, struct GraphNode *);
struct GraphNode *func_8037C0BC(struct GraphNode *);
struct GraphNode *func_8037C138(struct GraphNode *a0);

void func_8037C1E4(struct GraphNode *, s32);
void func_8037C360(struct GraphNode *graphNode, s32 sp1c);

void func_8037C3D0(struct GraphNode018 *sp20);
void func_8037C448(struct GraphNode018 *sp18, void *sp1c, Vec3f sp20, Vec3s sp24);
void func_8037C51C(struct GraphNode018 *sp18, struct Struct8037C51C *sp1c);
void func_8037C658(struct GraphNode018 *, void *);
void func_8037C708(struct GraphNode018 *sp30, void *sp34, u32 sp38);

s32 func_8037C7D8(s32 a0, u16 **a1);

s16 func_8037C844(struct GraphNode018_sub *a0, s32* a1);
void Unknown8037C9E8(struct GraphNode018 *sp28, Vec3f sp2c);

struct GraphNodeScreenArea *Unknown8037CB10(struct GraphNode *graphNode);

s16 *read_vec3s_to_vec3f(Vec3f, s16 *src);
s16 *read_vec3s(Vec3s dst, s16 *src);
s16 *read_vec3s_angle(Vec3s dst, s16 *src);

void register_scene_graph_node(struct GraphNode *);

#endif /* _GRAPH_NODE_H_ */
