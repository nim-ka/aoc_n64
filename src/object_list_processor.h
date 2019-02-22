#ifndef _OBJECT_LIST_PROCESSOR_H
#define _OBJECT_LIST_PROCESSOR_H

struct Object;
struct SpawnInfo;

#define OBJECT_ARRAY_SIZE 240

extern struct ObjectNode D_8033B870[];

#ifndef INCLUDED_FROM_OBJ_LIST_PROC
extern int gDebugInfoFlags;
extern int gNumFindFloorMisses;
extern UNUSED s32 D_8033bef8;
extern int gUnknownWallCount;
extern u32 gUpdatedObjectCount;
extern s16 gNumFindFloorCalls;
extern s16 gNumFindCeilCalls;
extern s16 gNumFindWallCalls;

// these were 2d grids that probably functioned as
// recording debug information for all debug info
// systems. however, the only used ones are [4]
// and [5] (effectinfo and enemyinfo). The first
// 4 rows are effectively unused, despite being
// modifyable by the debug control function.
extern s16 gDebugInfo[][8];
extern s16 gDebugInfoOverwrite[][8]; // most likely used to manually copy in
                                     // preset controls, since it is never set

extern u32 gTimeStopState;
extern struct Object gObjectPool[];
extern struct Object D_8035FB18;
extern struct ObjectNode *gObjectLists;
extern struct ObjectNode gFreeObjectList;
extern struct Object *gCurrentObject;
extern u32 *gBehCommand;
extern s16 gPostUpdateObjCount;
extern s32 gSurfaceNodesAllocated;
extern s32 gSurfacesAllocated;
extern s32 gNumStaticSurfaceNodes;
extern s32 gNumStaticSurfaces;
extern struct MemoryPool *D_8035FE0C;
#endif

void nop_change_course(void);
void BehMarioLoop2(void);
void func_8029C6D8(struct Object *, u8);
void func_8029C75C(s32, s32);
void spawn_objects_from_info(s32, struct SpawnInfo *spawnInfo);
void func_8029CA60(void);
void update_objects(s32);

#endif /* _OBJECT_LIST_PROCESSOR_H */
