#include <ultra64.h>

#include "sm64.h"
#include "behavior_script.h"

void func_80383B70(u32 segptr)
{
	gBehCommand = (u32 *)SegmentedToVirtual(segptr);
	gCurrentObject->stackIndex = 0;
}

u16 RandomU16(void)
{
	u16 temp1, temp2;

	if(gRandomSeed16 == 22026)
	{
		gRandomSeed16 = 0;
	}

	temp1 = (gRandomSeed16 & 0xFF) << 8;
	temp1 = temp1 ^ gRandomSeed16;

	gRandomSeed16 = ((temp1 & 0x00FF) << 8) + ((temp1 & 0xFF00) >> 8);

	temp1 = ((temp1 & 0xFF) << 1) ^ gRandomSeed16;
	temp2 = (temp1 >> 1) ^ 0xFF80;

	if((temp1 & 1) == 0)
	{
		if(temp2 == 43605)
		{
			gRandomSeed16 = 0;
		}
		else
		{
			gRandomSeed16 = temp2 ^ 0x1ff4;
		}
	}
	else
	{
		gRandomSeed16 = temp2 ^ 0x8180;
	}

	return gRandomSeed16;
}

f32 RandomFloat(void)
{
	f32 rnd = RandomU16();
	return rnd / (double)0x10000;
}

s32 RandomSign(void)
{
	if(RandomU16() >= 0x7FFF)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void func_80383D68(struct Object *object)
{
	/* TODO un-hack this */

	struct MyVec3f { f32 x, y, z; };

	object->gfx.unk20[0] = object->pos[0];
	object->gfx.unk20[1] = object->unkDC + ((struct MyVec3f *)&object->pos)->y;
	object->gfx.unk20[2] = object->pos[2];

	object->gfx.unk1A[0] = object->faceAngle[0] & 0xFFFF;
	object->gfx.unk1A[1] = object->faceAngle[1] & 0xFFFF;
	object->gfx.unk1A[2] = object->faceAngle[2] & 0xFFFF;
}

void cur_object_stack_push(u32 value)
{
	gCurrentObject->stack[gCurrentObject->stackIndex] = value;
	gCurrentObject->stackIndex++;
}

u32 cur_object_stack_pop(void)
{
	u32 value;
	gCurrentObject->stackIndex--;
	value = gCurrentObject->stack[gCurrentObject->stackIndex];
	return value;
}

void Unknown80383E44(void) // ?
{
	for(;;);
}

s32 Behavior22(void)
{
	UnHideObject();
	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior35(void)
{
	gCurrentObject->gfx.graphFlags &= ~GRAPH_0001;
	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior21(void)
{
	gCurrentObject->gfx.graphFlags |= GRAPH_BILLBOARD;
	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior1B(void)
{
	s32 index = (s16)(gBehCommand[0] & 0xFFFF);
	gCurrentObject->gfx.geoLayout = gLoadedGeoLayouts[index];
	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior1C(void)
{
	u32 arg0 = gBehCommand[1];
	u32 arg1 = gBehCommand[2];
	
	struct Object *object = func_8029E5A4(gCurrentObject, 0, arg0, arg1);
	
	CopyObjParams(object, gCurrentObject);
	
	gBehCommand += 3;
	return BEH_CONTINUE;
}

s32 Behavior2C(void)
{
	u32 arg0 = gBehCommand[1];
	u32 arg1 = gBehCommand[2];
	
	struct Object *object = func_8029E5A4(gCurrentObject, 0, arg0, arg1);
	
	CopyObjParams(object, gCurrentObject);
	
	gCurrentObject->unk6C = object;
	
	gBehCommand += 3;
	return BEH_CONTINUE;
}

s32 Behavior29(void)
{
	u32 behParam = (s16)(gBehCommand[0] & 0xFFFF);
	u32 arg1 = gBehCommand[1];
	u32 arg2 = gBehCommand[2];
	
	struct Object *object = func_8029E5A4(gCurrentObject, 0, arg1, arg2);
	
	CopyObjParams(object, gCurrentObject);
	
	object->behParam = behParam;
	
	gBehCommand += 3;
	return BEH_CONTINUE;
}

s32 Behavior1D(void)
{
	gCurrentObject->active = 0;
	return BEH_BREAK;
}

s32 Behavior0A(void)
{
	return BEH_BREAK;
}

s32 Behavior0B(void)
{
	return BEH_BREAK;
}

s32 Behavior02(void)
{
	u32* jumpAddress;

	gBehCommand++;
	cur_object_stack_push((u32)&gBehCommand[1]);
	jumpAddress = (u32 *)SegmentedToVirtual(gBehCommand[0]);
	gBehCommand = jumpAddress;

	return BEH_CONTINUE;
}

s32 Behavior03(void)
{
	gBehCommand = (u32 *)cur_object_stack_pop();
	return BEH_CONTINUE;
}

s32 Behavior01(void)
{
	s16 arg0 = gBehCommand[0] & 0xFFFF;

	if(gCurrentObject->unk1F4 < arg0 - 1)
	{
		gCurrentObject->unk1F4++;
	}
	else
	{
		gCurrentObject->unk1F4 = 0;
		gBehCommand++;
	}

	return BEH_BREAK;
}

s32 Behavior25(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s32 arg0 = cur_object_get_s32(objectOffset);

	if(gCurrentObject->unk1F4 < (arg0 - 1))
	{
		gCurrentObject->unk1F4++;
	}
	else
	{
		gCurrentObject->unk1F4 = 0;
		gBehCommand++;
	}

	return BEH_BREAK;
}

s32 Behavior04(void)
{
	gBehCommand++;
	gBehCommand = (u32 *)SegmentedToVirtual(gBehCommand[0]);
	return BEH_CONTINUE;
}

s32 Behavior26(void)
{
	s32 value = (u8)(gBehCommand[0] >> 16) & 0xFF;
	
	cur_object_stack_push((u32)&gBehCommand[1]);
	cur_object_stack_push(value);
	
	gBehCommand++;
	
	return BEH_CONTINUE;
}

s32 Behavior05(void)
{
	s32 value = (s16)(gBehCommand[0] & 0xFFFF);
	
	cur_object_stack_push((u32)&gBehCommand[1]);
	cur_object_stack_push(value);
	
	gBehCommand++;
	
	return BEH_CONTINUE;
}

s32 Behavior06(void)
{
	u32 count = cur_object_stack_pop();
	
	count--;

	if(count != 0)
	{
		gBehCommand = (u32 *)cur_object_stack_pop();
		cur_object_stack_push((u32)gBehCommand);
		cur_object_stack_push(count);
	}
	else
	{
		cur_object_stack_pop();
		gBehCommand++;
	}

	return BEH_BREAK;
}

s32 Behavior07(void)
{
	u32 count = cur_object_stack_pop();
	
	count--;

	if(count != 0)
	{
		gBehCommand = (u32 *)cur_object_stack_pop();
		cur_object_stack_push((u32)gBehCommand);
		cur_object_stack_push(count);
	}
	else
	{
		cur_object_stack_pop();
		gBehCommand++;
	}

	return BEH_CONTINUE;
}

s32 Behavior08(void)
{
	cur_object_stack_push((u32)&gBehCommand[1]);

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior09(void)
{
	gBehCommand = (u32 *)cur_object_stack_pop();
	cur_object_stack_push((u32)gBehCommand);

	return BEH_BREAK;
}

typedef void (*BehaviorCallProc)(void);

s32 Behavior0C(void)
{
	BehaviorCallProc behavior_proc = (BehaviorCallProc)gBehCommand[1];
	
	behavior_proc();
	
	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior0E(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    f32 value = (s16)(gBehCommand[0] & 0xFFFF);

    cur_object_set_f32(objectOffset, value);

    gBehCommand++;
    return BEH_CONTINUE;
}

s32 Behavior10(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s16 value = gBehCommand[0] & 0xFFFF;
	
	cur_object_set_s32(objectOffset, value);

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior36(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	u32 value = (s16)(gBehCommand[1] & 0xFFFF);
	
	cur_object_set_s32(objectOffset, value);

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior14(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	f32 sp20 = (s16)(gBehCommand[0] & 0xFFFF);
	f32 sp1c = (s16)(gBehCommand[1] >> 16);

	cur_object_set_f32(objectOffset, (sp1c * RandomFloat()) + sp20);

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior15(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s32 sp20 = (s16)(gBehCommand[0] & 0xFFFF);
	s32 sp1c = (s16)(gBehCommand[1] >> 16);

	cur_object_set_s32(objectOffset, (s32)((f32)sp1c * RandomFloat()) + sp20);

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior13(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s32 sp20 = (s16)(gBehCommand[0] & 0xFFFF);
	s32 sp1c = (s16)(gBehCommand[1] >> 16);
	
	cur_object_set_s32(objectOffset, (RandomU16() >> sp1c) + sp20);

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior16(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	f32 sp20 = (s16)(gBehCommand[0] & 0xFFFF);
	f32 sp1c = (s16)(gBehCommand[1] >> 16);
	
	cur_object_set_f32(objectOffset, (cur_object_get_f32(objectOffset) + sp20) + (sp1c * RandomFloat()));

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior17(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s32 sp20 = (s16)(gBehCommand[0] & 0xFFFF);
	s32 sp1c = (s16)(gBehCommand[1] >> 16);
	s32 sp18 = RandomU16();

	cur_object_set_s32(objectOffset,
		(cur_object_get_s32(objectOffset) + sp20) + (sp18 >> sp1c));

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior0D(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	f32 value = (s16)(gBehCommand[0] & 0xFFFF);
	
	cur_object_add_f32(objectOffset, value);
	
	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior0F(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s16 value = gBehCommand[0] & 0xFFFF;

	cur_object_add_s32(objectOffset, value);

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior11(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s32 value = (s16)(gBehCommand[0] & 0xFFFF);
	value &= 0xFFFF;

	cur_object_or_s32(objectOffset, value);
	
	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior12(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s32 value = (s16)(gBehCommand[0] & 0xFFFF);
	value = (value & 0xFFFF) ^ 0xFFFF;
	
	cur_object_and_s32(objectOffset, value);

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior27(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;

	cur_object_set_s32(objectOffset, gBehCommand[1]);

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior28(void)
{	
	s32 animIndex = (u8)((gBehCommand[0] >> 16) & 0xFF);
	u32* animations = gCurrentObject->animations;

	func_8037C658(gCurrentObject, &animations[animIndex]);

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior1E(void)
{
	f32 x = gCurrentObject->pos[0];
	f32 y = gCurrentObject->pos[1];
	f32 z = gCurrentObject->pos[2];
	f32 sp18 = func_80381794(x, y + 200.0f, z);

	gCurrentObject->pos[1] = sp18;
	gCurrentObject->unkEC |= 2;

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior18(void)
{
	/* no operation */
	UNUSED u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior1A(void)
{
	/* no operation */
	UNUSED u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior19(void)
{
	/* no operation */
	UNUSED u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior1F(void)
{
	u32 objectOffsetDst = (u8)((gBehCommand[0] >> 16) & 0xFF);
	u32 objectOffsetSrc1 = (u8)((gBehCommand[0] >> 8) & 0xFF);
	u32 objectOffsetSrc2 = (u8)((gBehCommand[0]) & 0xFF);

	cur_object_set_f32(objectOffsetDst,
		cur_object_get_f32(objectOffsetSrc1) + cur_object_get_f32(objectOffsetSrc2));

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior20(void)
{
	u32 objectOffsetDst = (u8)((gBehCommand[0] >> 16) & 0xFF);
	u32 objectOffsetSrc1 = (u8)((gBehCommand[0] >> 8) & 0xFF);
	u32 objectOffsetSrc2 = (u8)((gBehCommand[0]) & 0xFF);

	cur_object_set_s32(objectOffsetDst,
		cur_object_get_s32(objectOffsetSrc1) + cur_object_get_s32(objectOffsetSrc2));

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior23(void)
{
	s16 colSphereX = gBehCommand[1] >> 16;
	s16 colSphereY = gBehCommand[1] & 0xFFFF;

	gCurrentObject->collisionSphere[0] = colSphereX;
	gCurrentObject->collisionSphere[1] = colSphereY;

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior2E(void)
{
	s16 arg0 = gBehCommand[1] >> 16;
	s16 arg1 = gBehCommand[1] & 0xFFFF;

	gCurrentObject->unk200 = arg0;
	gCurrentObject->unk204 = arg1;

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior2B(void)
{
	s16 colSphereX = gBehCommand[1] >> 16;
	s16 colSphereY = gBehCommand[1] & 0xFFFF;
	s16 unknown = gBehCommand[2] >> 16;

	gCurrentObject->collisionSphere[0] = colSphereX;
	gCurrentObject->collisionSphere[1] = colSphereY;
	gCurrentObject->unk208 = unknown;

	gBehCommand += 3;
	return BEH_CONTINUE;
}

s32 Behavior24(void)
{
	/* no operation */
	UNUSED s16 arg0 = (u8)((gBehCommand[0] >> 16) & 0xFF);
	UNUSED s16 arg1 = gBehCommand[0] & 0xFFFF;

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior00(void)
{
	if(CheckObjBehavior((u32 *)&D_13004FB4))
	{
		BehCommonInit();
	}

	if(CheckObjBehavior((u32 *)&D_13005004))
	{
		BehCommonInit();
	}

	if(CheckObjBehavior((u32 *)&D_130032C0))
	{
		gCurrentObject->collisionDistance = 150.0f;
	}

	gBehCommand++;
	return BEH_CONTINUE;
}

void Unknown8038556C(s32 lastIndex)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	u32 table[16];
	s32 i;

	for(i = 0; i <= lastIndex / 2; i += 2)
	{
		table[i] = (s16)(gBehCommand[i + 1] >> 16);
		table[i + 1] = (s16)(gBehCommand[i + 1] & 0xFFFF);
	}

	cur_object_set_s32(objectOffset, table[(s32)(lastIndex * RandomFloat())]);
}

s32 Behavior2A(void)
{
	u32* collisionData = (u32 *)SegmentedToVirtual(gBehCommand[1]);
	gCurrentObject->collisionData = collisionData;
	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior2D(void)
{
	gCurrentObject->unk164[0] = gCurrentObject->pos[0];
	gCurrentObject->unk164[1] = gCurrentObject->pos[1];
	gCurrentObject->unk164[2] = gCurrentObject->pos[2];
	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior2F(void)
{
	gCurrentObject->interaction = gBehCommand[1];

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior31(void)
{
	gCurrentObject->unk190 = gBehCommand[1];

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior32(void)
{
	UNUSED u8 sp1f = (gBehCommand[0] >> 16) & 0xFF;
	s16 sp1c = gBehCommand[0] & 0xFFFF;

	ScaleObject((f32)sp1c / 100.0f);

	gBehCommand++;
	return BEH_CONTINUE;
}

s32 Behavior30(void)
{
	UNUSED f32 sp04, sp00;

	gCurrentObject->unk128 = (f32)(s16)(gBehCommand[1] >> 16);
	gCurrentObject->unkE4 = (f32)(s16)(gBehCommand[1] & 0xFFFF) / 100.0f;
	gCurrentObject->unk158 = (f32)(s16)(gBehCommand[2] >> 16) / 100.0f;
	gCurrentObject->unk12C = (f32)(s16)(gBehCommand[2] & 0xFFFF) / 100.0f;
	gCurrentObject->unk170 = (f32)(s16)(gBehCommand[3] >> 16) / 100.0f;
	gCurrentObject->unk174 = (f32)(s16)(gBehCommand[3] & 0xFFFF) / 100.0f;

	// unused parameters
	sp04 = (f32)(s16)(gBehCommand[4] >> 16) / 100.0f;
	sp00 = (f32)(s16)(gBehCommand[4] & 0xFFFF) / 100.0f;

	gBehCommand += 5;
	return BEH_CONTINUE;
}

s32 Behavior33(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s32 flags = gBehCommand[1];

	flags = flags ^ 0xFFFFFFFF;

	object_and_s32(gCurrentObject->unk68, objectOffset, flags);

	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior37(void)
{
	u32 arg0 = gBehCommand[1];
	func_8029E388(gCurrentObject, arg0);
	gBehCommand += 2;
	return BEH_CONTINUE;
}

s32 Behavior34(void)
{
	u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
	s16 arg1 = (gBehCommand[0] & 0xFFFF);

	if((D_8032C694 % arg1) == 0)
	{
		cur_object_add_s32(objectOffset, 1);
	}

	gBehCommand++;
	return BEH_CONTINUE;
}

void func_80385BF0(void)
{
	// (empty function)
}

void cur_object_exec_behavior(void)
{
	UNUSED u32 unused;

	s16 flagsLo;
	f32 distanceFromMario;
	BehCommandProc next_behavior_proc;
	s32 behProcResult;
	
	flagsLo = (s16)gCurrentObject->objFlags;

	if(flagsLo & OBJ_FLAG_0040)
	{
		gCurrentObject->distanceFromMario = objects_calc_distance(gCurrentObject, gMarioObject);
		distanceFromMario = gCurrentObject->distanceFromMario;
	}
	else
	{
		distanceFromMario = 0.0f;
	}

	if(flagsLo & OBJ_FLAG_2000)
	{
		gCurrentObject->unk160 = func_8029DF18(gCurrentObject, gMarioObject);
	}

	if(gCurrentObject->previousAction != gCurrentObject->action)
	{
		(void) (gCurrentObject->timer = 0,
		gCurrentObject->unk150 = 0,
		gCurrentObject->previousAction = gCurrentObject->action);
	}

	gBehCommand = gCurrentObject->behScript;

	do
	{
		next_behavior_proc = BehaviorJumpTable[gBehCommand[0] >> 24];
		behProcResult = next_behavior_proc();
	} while(behProcResult == BEH_CONTINUE);

	gCurrentObject->behScript = gBehCommand;

	if(gCurrentObject->timer < 0x3FFFFFFF)
	{
		gCurrentObject->timer++;
	}

	if(gCurrentObject->previousAction != gCurrentObject->action) 
	{
		(void) (gCurrentObject->timer = 0,
		gCurrentObject->unk150 = 0,
		gCurrentObject->previousAction = gCurrentObject->action);
	}

	flagsLo = (s16)gCurrentObject->objFlags;

	if(flagsLo & OBJ_FLAG_0010)
	{
		func_8029F170(gCurrentObject);
	}

	if(flagsLo & OBJ_FLAG_0008)
	{
		gCurrentObject->faceAngle[1] = gCurrentObject->angle[1];
	}

	if(flagsLo & OBJ_FLAG_0002)
	{
		func_802A0A90();	
	}

	if(flagsLo & OBJ_FLAG_0004)
	{
		func_802A0B28();
	}

	if(flagsLo & OBJ_FLAG_0200)
	{
		func_802A22DC(gCurrentObject);
	}

	if(flagsLo & OBJ_FLAG_0800)
	{
		func_802A2270(gCurrentObject);
	}

	if(flagsLo & OBJ_FLAG_0001)
	{
		func_80383D68(gCurrentObject);
	}

	if(gCurrentObject->unk1A0 != 0xFFFFFFFF)
	{
		func_802A3A68();
	}
	else if((flagsLo & OBJ_FLAG_0040) && gCurrentObject->collisionData == NULL)
	{
		if((flagsLo & OBJ_FLAG_0080) == 0)
		{
			if(distanceFromMario > gCurrentObject->drawingDistance)
			{
				gCurrentObject->gfx.graphFlags &= 0xFFFFFFFE;
				gCurrentObject->active |= 2;
			}
			else if(gCurrentObject->unk124 == 0)
			{
				gCurrentObject->gfx.graphFlags |= 1;
				gCurrentObject->active &= 0xFFFFFFFD;
			}
		}	
	}
}
