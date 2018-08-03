#ifndef _OBJECT_LIST_PROCESSOR_H
#define _OBJECT_LIST_PROCESSOR_H

struct Object;
struct SpawnInfo;

#define OBJECT_ARRAY_SIZE 240

extern u32 gTimeStopState;
extern struct Object gObjectPool[];
extern struct Object D_8035FB18;
extern struct ObjectNode *gObjectLists;

void nop_change_course(void);
void BehMarioLoop2(void);
void func_8029C6D8(struct Object *, u8);
void func_8029C75C(s32, s32);
void spawn_objects_from_info(s32, struct SpawnInfo *spawnInfo);
void func_8029CA60(void);
void update_objects(s32);

#endif /* _OBJECT_LIST_PROCESSOR_H */
