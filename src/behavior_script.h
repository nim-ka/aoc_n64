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

typedef s32 (*BehCommandProc)(void);
extern BehCommandProc BehaviorJumpTable[];

u16 RandomU16(void);
float RandomFloat(void);
s32 RandomSign(void);

void func_80383D68(struct Object *object);
void cur_object_stack_push(u32 value);
u32 cur_object_stack_pop(void);

void Unknown80383E44(void);

s32 Behavior22(void);
s32 Behavior35(void);
s32 Behavior21(void);
s32 Behavior1B(void);
s32 Behavior1C(void);
s32 Behavior2C(void);
s32 Behavior29(void);
s32 Behavior1D(void);
s32 Behavior0A(void);
s32 Behavior0B(void);
s32 Behavior02(void);
s32 Behavior03(void);
s32 Behavior01(void);
s32 Behavior25(void);
s32 Behavior04(void);
s32 Behavior26(void);
s32 Behavior05(void);
s32 Behavior06(void);
s32 Behavior07(void);
s32 Behavior08(void);
s32 Behavior09(void);
s32 Behavior0C(void);
s32 Behavior0E(void);
s32 Behavior10(void);
s32 Behavior36(void);
s32 Behavior14(void);
s32 Behavior15(void);
s32 Behavior13(void);
s32 Behavior16(void);
s32 Behavior17(void);
s32 Behavior0D(void);
s32 Behavior0F(void);
s32 Behavior11(void);
s32 Behavior12(void);
s32 Behavior27(void);
s32 Behavior28(void);
s32 Behavior1E(void);
s32 Behavior18(void);
s32 Behavior1A(void);
s32 Behavior19(void);
s32 Behavior1F(void);
s32 Behavior20(void);
s32 Behavior23(void);
s32 Behavior2E(void);
s32 Behavior2B(void);
s32 Behavior24(void);
s32 Behavior00(void);

void Unknown8038556C(s32 lastIndex);

s32 Behavior2A(void);
s32 Behavior2D(void);
s32 Behavior2F(void);
s32 Behavior31(void);
s32 Behavior32(void);
s32 Behavior30(void);
s32 Behavior33(void);
s32 Behavior37(void);
s32 Behavior34(void);

void func_80385BF0(void);

void cur_object_exec_behavior(void);

#endif /* _BEHAVIOR_SCRIPT_H_ */
