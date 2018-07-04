#ifndef _BEHAVIOR_SCRIPT_H_
#define _BEHAVIOR_SCRIPT_H_

#define BEH_BREAK    1
#define BEH_CONTINUE 0 

#define BEH_OBJ_OFFSET_PUBLIC 0x88

#define _object_offset(object, offset) ((u8*)object + BEH_OBJ_OFFSET_PUBLIC + (offset)*sizeof(u32))

#define cur_object_get_f32(offset) (*(f32*)_object_offset(gCurrentObject, offset))
#define cur_object_get_s32(offset) (*(s32*)_object_offset(gCurrentObject, offset))

#define cur_object_set_f32(offset, value) *(f32*)_object_offset(gCurrentObject, offset) = (f32)(value)
#define cur_object_add_f32(offset, value) *(f32*)_object_offset(gCurrentObject, offset) += (f32)(value)
#define cur_object_set_s32(offset, value) *(s32*)_object_offset(gCurrentObject, offset) = (s32)(value)
#define cur_object_add_s32(offset, value) *(s32*)_object_offset(gCurrentObject, offset) += (s32)(value)
#define cur_object_and_s32(offset, value) *(s32*)_object_offset(gCurrentObject, offset) &= (s32)(value)
#define cur_object_or_s32(offset, value)  *(s32*)_object_offset(gCurrentObject, offset) |= (s32)(value)

#define object_and_s32(object, offset, value) *(s32*)_object_offset(object, offset) &= (s32)(value)
extern struct Object *gCurrentObject;

u16 RandomU16(void);
float RandomFloat(void);
s32 RandomSign(void);

void func_80383D68(struct Object *object);

void func_80385BF0(void);

void cur_object_exec_behavior(void);

#endif /* _BEHAVIOR_SCRIPT_H_ */
