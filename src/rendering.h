#ifndef _RENDERING_H
#define _RENDERING_H

#include "graph_node.h"
#include "level_update.h"

struct AllocOnlyPool;

extern struct GraphNode004 *D_8032CF94;
extern struct GraphNodeCamFrustum *D_8032CF98;
extern struct GraphNode114 *D_8032CF9C;
extern struct GraphNode018 *D_8032CFA0;
extern struct GraphNode12E *D_8032CFA4;
extern u16 D_8032CFA8;
extern struct Object *D_8038BD98;
extern u8 D_8033A743;
// extern ? D_8033A741;
// extern ? D_8033A742;
// extern ? D_8033A744;
// extern ? D_8033A745;
// extern ? D_8033A746;
// extern ? D_8033A74C;
// extern ? D_8033A74E;
// extern ? D_8033A750;
// extern ? D_8033A752;
// extern ? D_8033A754;
// extern ? D_8033A748;
// extern ? D_8033A74A;
extern u8 D_8032CF00[];
// extern ? D_8032CF10;
// extern ? D_8032CF50;
extern struct AllocOnlyPool *D_8033B018;
extern s16 D_8033A770;
// extern ? D_8033A778;
extern u8 D_8033B008;
extern s16 D_8033B00A;
extern u16 *D_8033B010;
extern s16 *D_8033B014;
extern u8 D_8033B009;
extern s8 D_8035FF44;
extern s8 D_8035FF45;
// extern ? D_80340001;
extern u8 D_8033AFF8;
extern u8 D_8033AFF9;
extern s16 D_8033AFFA;
extern u16 *D_8033B000;
extern float D_8033AFFC;
extern s16 *D_8033B004;
extern u8 D_8033A740;
extern struct SpawnInfo gPlayerSpawnInfos[];
extern struct SpawnInfo *gMarioSpawnInfo;

extern Vp *D_8032CE74;
extern Vp *D_8032CE78;
extern s16 D_8032CE7C;
extern u32 D_8032CE80;
extern u32 D_8032CE84;
extern u8 D_8032CE88;
extern u8 D_8032CE8C;
extern u8 D_8032CE90;

// extern ? func_8027A28C(?);
// extern ? func_8027A220(?);
extern void IntroPrintText(void);
extern u32 func_8027A38C(struct Object *);
extern struct ObjectWarpNode *func_8027A418(u8);
// extern ? func_8027A478(?);
// extern ? func_8027A4C4(?);
extern void func_8027A554(void);
extern void func_8027A7C4(void);
extern void func_8027A894(int);
extern void func_8027A998(void);
extern void func_8027AA0C(void);
extern void func_8027AA88(void);
extern void func_8027AB10(int);
extern void func_8027ABB4(void);
extern void func_8027ABF0(s16, s16, u8, u8, u8);
extern void func_8027ADAC(s16, s16, u8, u8, u8, s16);
extern void func_8027AE04(void);
// extern ? func_8027B110(?);
// extern ? func_8027B354(?);
// extern ? func_8027B450(?);
// extern ? func_8027B4E8(?);
// extern ? func_8027B6C4(?);
// extern ? func_8027B840(?);
// extern ? func_8027B8D4(?);
// extern ? func_8027B9A8(?);
// extern ? func_8027BB64(?);
// extern ? func_8027BC88(?);
// extern ? func_8027BDAC(?);
// extern ? func_8027BEC4(?);
// extern ? func_8027BFE4(?);
// extern ? func_8027C18C(?);
// extern ? func_8027C1F4(?);
// extern ? func_8027C2A8(?);
// extern ? func_8027C4C0(?);
// extern ? func_8027C988(?);
// extern ? func_8027CB08(?);
// extern ? func_8027CF68(?);
// extern ? func_8027D14C(?);
// extern ? func_8027D460(?);
// extern ? func_8027D4D4(?);
// extern ? func_8027D8B8(?);
extern void func_8027D8F8(struct GraphNode *rootGraphNode);
extern void func_8027DB80();

#endif
