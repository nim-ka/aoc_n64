#ifndef _GRAPH_NODE_H
#define _GRAPH_NODE_H

#include "types.h"

extern Vec3s D_80385FDC;

extern void InitSceneGraphNodeLinks(struct SceneGraphNode *, s32);
extern struct SceneGraphScreenAreaNode *func_8037B24C(struct Struct80278464 *, s32, s32, s32, s32, s32, s32);
extern struct SceneGraphNode *func_8037B30C(struct Struct80278464 *, s32, f32);
extern struct SceneGraphNode *func_8037B380(struct Struct80278464 *, s32, f32, s32, s32, s32, s32);
extern struct SceneGraphNode *func_8037B448(struct Struct80278464 *, s32);
extern struct SceneGraphNode *func_8037B4AC(struct Struct80278464 *, s32, s32);
extern struct SceneGraphNode *func_8037B530(struct Struct80278464 *, s32, s32, s32);
extern struct SceneGraphNode *func_8037B5B4(struct Struct80278464 *, s32, s32, s32, s32, s32);
extern struct SceneGraphNode *func_8037B670(struct Struct80278464 *, s32, s32 *, s32 *, s32, s32);
extern struct SceneGraphNode *func_8037B744(struct Struct80278464 *, s32, s32, s32, Vec3s, Vec3s);
extern struct SceneGraphNode *func_8037B7F8(struct Struct80278464 *, s32, s32, s32, Vec3s);
extern struct SceneGraphNode *func_8037B89C(struct Struct80278464 *, s32, s32, s32, Vec3s);
extern struct SceneGraphNode *func_8037B940(struct Struct80278464 *, s32, s32, s32, f32);
// extern ? func_8037B9E0(?);
extern struct SceneGraphNode *func_8037BAD4(struct Struct80278464 *, s32, s32);
extern struct SceneGraphNode *func_8037BB48(struct Struct80278464 *, s32, s32, void *, Vec3s);
extern struct SceneGraphNode *func_8037BBEC(struct Struct80278464 *, s32, s32, s32, Vec3s);
extern struct SceneGraphDListNode *func_8037BC90(struct Struct80278464 *, s32, s32, void *);
extern struct SceneGraphNode *func_8037BD24(struct Struct80278464 *, s32, s32, s32, s32);
extern struct SceneGraphNode *func_8037BDB4(struct Struct80278464 *, s32, u8 *); // a2 unconfirmed
extern struct SceneGraphNode *func_8037BE28(struct Struct80278464 *, s32, s32, s32);
extern struct SceneGraphNode *func_8037BECC(struct Struct80278464 *, s32, s32, s32, s32);
extern struct SceneGraphNode *func_8037BF84(struct Struct80278464 *, s32, s32, Vec3s, s32, s32);
extern void func_8037C044(void *, struct Object *);
extern void func_8037C0BC(struct Object *);
// extern ? func_8037C138(?);
// extern ? func_8037C1E4(?);
extern void func_8037C360();
// extern ? func_8037C3D0(?);
// extern ? func_8037C448(?);
// extern ? func_8037C51C(?);
extern void func_8037C658(struct Object *, void *);
// extern ? func_8037C708(?);
extern int func_8037C7D8();
extern int func_8037C844();
// extern ? Unknown8037C9E8(?);
// extern ? Unknown8037CB10(?);
extern u8 *func_8037CB60(Vec3i, u8 *);
extern s16 *Copy16BitTriple(Vec3s dst, s16 *src);
extern s16 *func_8037CBFC(Vec3s dst, s16 *src);
extern void RegisterSceneGraphNode(struct SceneGraphNode *);

#endif /* _GRAPH_NODE_H */
