#include <ultra64.h>

#include "sm64.h"
#include "behavior_script.h"
#include "memory.h"
#include "graph_node.h"
#include "surface_collision.h"
#include "object_helpers.h"
#include "mario.h"
#include "display.h"
#include "obj_behaviors_2.h"
#include "behavior_data.h"

extern u32 *gBehCommand;
static u16 gRandomSeed16;

// unused
static void func_80383B70(u32 segptr)
{
    gBehCommand = segmented_to_virtual((void *)segptr);
    gCurrentObject->stackIndex = 0;
}

u16 RandomU16(void)
{
    u16 temp1, temp2;

    if (gRandomSeed16 == 22026)
        gRandomSeed16 = 0;

    temp1 = (gRandomSeed16 & 0xFF) << 8;
    temp1 = temp1 ^ gRandomSeed16;

    gRandomSeed16 = ((temp1 & 0x00FF) << 8) + ((temp1 & 0xFF00) >> 8);

    temp1 = ((temp1 & 0xFF) << 1) ^ gRandomSeed16;
    temp2 = (temp1 >> 1) ^ 0xFF80;

    if ((temp1 & 1) == 0)
    {
        if (temp2 == 43605)
            gRandomSeed16 = 0;
        else
            gRandomSeed16 = temp2 ^ 0x1ff4;
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
    if (RandomU16() >= 0x7FFF)
        return 1;
    else
        return -1;
}

void func_80383D68(struct Object *object)
{
    object->header.gfx.pos[0] = object->oPosX;
    object->header.gfx.pos[1] = object->oPosY + object->oGraphYOffset;
    object->header.gfx.pos[2] = object->oPosZ;

    object->header.gfx.angle[0] = object->oFaceAnglePitch & 0xFFFF;
    object->header.gfx.angle[1] = object->oFaceAngleYaw & 0xFFFF;
    object->header.gfx.angle[2] = object->oFaceAngleRoll & 0xFFFF;
}

static void cur_object_stack_push(u32 value)
{
    gCurrentObject->stack[gCurrentObject->stackIndex] = value;
    gCurrentObject->stackIndex++;
}

static u32 cur_object_stack_pop(void)
{
    u32 value;
    gCurrentObject->stackIndex--;
    value = gCurrentObject->stack[gCurrentObject->stackIndex];
    return value;
}

static void Unknown80383E44(void) // ?
{
    for (;;);
}

static s32 beh_cmd_unhide(void)
{
    UnHideObject();
    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 Behavior35(void)
{
    gCurrentObject->header.gfx.node.flags &= ~GRAPH_RENDER_01;
    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_billboard(void)
{
    gCurrentObject->header.gfx.node.flags |= GRAPH_RENDER_BILLBOARD;
    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_graph_node(void)
{
    s32 index = (s16)(gBehCommand[0] & 0xFFFF);
    gCurrentObject->header.gfx.asGraphNode = gLoadedGraphNodes[index];
    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 Behavior1C(void)
{
    u32 arg0 = gBehCommand[1];
    void *arg1 = (void *) gBehCommand[2];
    
    struct Object *object = func_8029E5A4(gCurrentObject, 0, arg0, arg1);
    
    CopyObjParams(object, gCurrentObject);
    
    gBehCommand += 3;
    return BEH_CONTINUE;
}

static s32 Behavior2C(void)
{
    u32 arg0 = gBehCommand[1];
    void *arg1 = (void *) gBehCommand[2];
    
    struct Object *object = func_8029E5A4(gCurrentObject, 0, arg0, arg1);
    
    CopyObjParams(object, gCurrentObject);
    
    gCurrentObject->prevObj = object;
    
    gBehCommand += 3;
    return BEH_CONTINUE;
}

static s32 Behavior29(void)
{
    u32 behParam = (s16)(gBehCommand[0] & 0xFFFF);
    u32 arg1 = gBehCommand[1];
    void *arg2 = (void *) gBehCommand[2];
    
    struct Object *object = func_8029E5A4(gCurrentObject, 0, arg1, arg2);
    
    CopyObjParams(object, gCurrentObject);
    
    object->oBehParam = behParam;
    
    gBehCommand += 3;
    return BEH_CONTINUE;
}

static s32 beh_cmd_deactivate(void)
{
    gCurrentObject->active = 0;
    return BEH_BREAK;
}

static s32 beh_cmd_break(void)
{
    return BEH_BREAK;
}

// unused
static s32 Behavior0B(void)
{
    return BEH_BREAK;
}

static s32 beh_cmd_call(void)
{
    u32* jumpAddress;

    gBehCommand++;
    cur_object_stack_push((u32)(gBehCommand + 1));
    jumpAddress = (u32 *)segmented_to_virtual((void *)gBehCommand[0]);
    gBehCommand = jumpAddress;

    return BEH_CONTINUE;
}

static s32 beh_cmd_return(void)
{
    gBehCommand = (u32 *)cur_object_stack_pop();
    return BEH_CONTINUE;
}

static s32 beh_cmd_delay(void)
{
    s16 arg0 = gBehCommand[0] & 0xFFFF;

    if (gCurrentObject->unk1F4 < arg0 - 1)
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

static s32 beh_cmd_delay_var(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s32 arg0 = cur_object_get_s32(objectOffset);

    if (gCurrentObject->unk1F4 < (arg0 - 1))
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

static s32 beh_cmd_goto(void)
{
    gBehCommand++;
    gBehCommand = (u32 *)segmented_to_virtual((void *)gBehCommand[0]);
    return BEH_CONTINUE;
}

// unused
static s32 Behavior26(void)
{
    s32 value = (u8)(gBehCommand[0] >> 16) & 0xFF;
    
    cur_object_stack_push((u32)(gBehCommand + 1));
    cur_object_stack_push(value);
    
    gBehCommand++;
    
    return BEH_CONTINUE;
}

static s32 beh_cmd_begin_repeat(void)
{
    s32 count = (s16)(gBehCommand[0] & 0xFFFF);
    
    cur_object_stack_push((u32)(gBehCommand + 1));
    cur_object_stack_push(count);
    
    gBehCommand++;
    
    return BEH_CONTINUE;
}

static s32 beh_cmd_end_repeat(void)
{
    u32 count = cur_object_stack_pop();

    count--;
    if (count != 0)
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

static s32 beh_cmd_end_repeat_nobreak(void)
{
    u32 count = cur_object_stack_pop();

    count--;
    if (count != 0)
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

static s32 beh_cmd_begin_loop(void)
{
    cur_object_stack_push((u32)(gBehCommand + 1));

    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_end_loop(void)
{
    gBehCommand = (u32 *)cur_object_stack_pop();
    cur_object_stack_push((u32)gBehCommand);

    return BEH_BREAK;
}

typedef void (*BehaviorCallProc)(void);

static s32 beh_cmd_callnative(void)
{
    BehaviorCallProc behavior_proc = (BehaviorCallProc)gBehCommand[1];
    
    behavior_proc();
    
    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_set_float(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    f32 value = (s16)(gBehCommand[0] & 0xFFFF);

    cur_object_set_f32(objectOffset, value);

    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_set_int(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s16 value = gBehCommand[0] & 0xFFFF;

    cur_object_set_s32(objectOffset, value);

    gBehCommand++;
    return BEH_CONTINUE;
}

// unused
static s32 Behavior36(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    u32 value = (s16)(gBehCommand[1] & 0xFFFF);

    cur_object_set_s32(objectOffset, value);

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_set_float_rand(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    f32 min = (s16)(gBehCommand[0] & 0xFFFF);
    f32 max = (s16)(gBehCommand[1] >> 16);

    cur_object_set_f32(objectOffset, (max * RandomFloat()) + min);

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_set_int_rand(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s32 min = (s16)(gBehCommand[0] & 0xFFFF);
    s32 max = (s16)(gBehCommand[1] >> 16);

    cur_object_set_s32(objectOffset, (s32)(max * RandomFloat()) + min);

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_set_int_rand_rshift(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s32 min = (s16)(gBehCommand[0] & 0xFFFF);
    s32 rshift = (s16)(gBehCommand[1] >> 16);

    cur_object_set_s32(objectOffset, (RandomU16() >> rshift) + min);

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_add_float_rand(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    f32 min = (s16)(gBehCommand[0] & 0xFFFF);
    f32 max = (s16)(gBehCommand[1] >> 16);

    cur_object_set_f32(objectOffset,
        (cur_object_get_f32(objectOffset) + min) + (max * RandomFloat()));

    gBehCommand += 2;
    return BEH_CONTINUE;
}

// unused
static s32 beh_cmd_obj_add_int_rand_rshift(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s32 min = (s16)(gBehCommand[0] & 0xFFFF);
    s32 rshift = (s16)(gBehCommand[1] >> 16);
    s32 rnd = RandomU16();

    cur_object_set_s32(objectOffset,
        (cur_object_get_s32(objectOffset) + min) + (rnd >> rshift));

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_add_float(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    f32 value = (s16)(gBehCommand[0] & 0xFFFF);
    
    cur_object_add_f32(objectOffset, value);
    
    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_add_int(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s16 value = gBehCommand[0] & 0xFFFF;

    cur_object_add_s32(objectOffset, value);

    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_or_int(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s32 value = (s16)(gBehCommand[0] & 0xFFFF);

    value &= 0xFFFF;
    cur_object_or_s32(objectOffset, value);
    
    gBehCommand++;
    return BEH_CONTINUE;
}

// unused
static s32 beh_cmd_obj_bic_int(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s32 value = (s16)(gBehCommand[0] & 0xFFFF);

    value = (value & 0xFFFF) ^ 0xFFFF;
    cur_object_and_s32(objectOffset, value);

    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_set_int32(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;

    cur_object_set_s32(objectOffset, gBehCommand[1]);

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 Behavior28(void)
{    
    s32 animIndex = (u8)((gBehCommand[0] >> 16) & 0xFF);
    u32* animations = gCurrentObject->oAnimations;

    func_8037C658((struct GraphNodeObject *) gCurrentObject, &animations[animIndex]);

    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 Behavior1E(void)
{
    f32 x = gCurrentObject->oPosX;
    f32 y = gCurrentObject->oPosY;
    f32 z = gCurrentObject->oPosZ;
    f32 sp18 = find_floor_height(x, y + 200.0f, z);

    gCurrentObject->oPosY = sp18;
    gCurrentObject->oUnkEC |= 2;

    gBehCommand++;
    return BEH_CONTINUE;
}

// unused
static s32 Behavior18(void)
{
    /* no operation */
    UNUSED u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;

    gBehCommand++;
    return BEH_CONTINUE;
}

// unused
static s32 Behavior1A(void)
{
    /* no operation */
    UNUSED u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;

    gBehCommand++;
    return BEH_CONTINUE;
}

// unused
static s32 Behavior19(void)
{
    /* no operation */
    UNUSED u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;

    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_sum_float(void)
{
    u32 objectOffsetDst = (u8)((gBehCommand[0] >> 16) & 0xFF);
    u32 objectOffsetSrc1 = (u8)((gBehCommand[0] >> 8) & 0xFF);
    u32 objectOffsetSrc2 = (u8)((gBehCommand[0]) & 0xFF);

    cur_object_set_f32(objectOffsetDst,
        cur_object_get_f32(objectOffsetSrc1) + cur_object_get_f32(objectOffsetSrc2));

    gBehCommand++;
    return BEH_CONTINUE;
}

// unused
static s32 beh_cmd_obj_sum_int(void)
{
    u32 objectOffsetDst = (u8)((gBehCommand[0] >> 16) & 0xFF);
    u32 objectOffsetSrc1 = (u8)((gBehCommand[0] >> 8) & 0xFF);
    u32 objectOffsetSrc2 = (u8)((gBehCommand[0]) & 0xFF);

    cur_object_set_s32(objectOffsetDst,
        cur_object_get_s32(objectOffsetSrc1) + cur_object_get_s32(objectOffsetSrc2));

    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_set_hitbox(void)
{
    s16 colSphereX = gBehCommand[1] >> 16;
    s16 colSphereY = gBehCommand[1] & 0xFFFF;

    gCurrentObject->hitboxRadius = colSphereX;
    gCurrentObject->hitboxHeight = colSphereY;

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 Behavior2E(void)
{
    s16 arg0 = gBehCommand[1] >> 16;
    s16 arg1 = gBehCommand[1] & 0xFFFF;

    gCurrentObject->unk200 = arg0;
    gCurrentObject->unk204 = arg1;

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 Behavior2B(void)
{
    s16 colSphereX = gBehCommand[1] >> 16;
    s16 colSphereY = gBehCommand[1] & 0xFFFF;
    s16 unknown = gBehCommand[2] >> 16;

    gCurrentObject->hitboxRadius = colSphereX;
    gCurrentObject->hitboxHeight = colSphereY;
    gCurrentObject->unk208 = unknown;

    gBehCommand += 3;
    return BEH_CONTINUE;
}

// unused
static s32 Behavior24(void)
{
    /* no operation */
    UNUSED s16 arg0 = (u8)((gBehCommand[0] >> 16) & 0xFF);
    UNUSED s16 arg1 = gBehCommand[0] & 0xFFFF;

    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_begin(void)
{
    if (CheckObjBehavior(beh_haunted_chair))
        BehCommonInit();
    if (CheckObjBehavior(beh_mad_piano))
        BehCommonInit();
    if (CheckObjBehavior(beh_message_panel))
        gCurrentObject->oCollisionDistance = 150.0f;
    gBehCommand++;
    return BEH_CONTINUE;
}

static void Unknown8038556C(s32 lastIndex)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    u32 table[16];
    s32 i;

    for (i = 0; i <= lastIndex / 2; i += 2)
    {
        table[i] = (s16)(gBehCommand[i + 1] >> 16);
        table[i + 1] = (s16)(gBehCommand[i + 1] & 0xFFFF);
    }

    cur_object_set_s32(objectOffset, table[(s32)(lastIndex * RandomFloat())]);
}

static s32 beh_cmd_collision_data(void)
{
    u32* collisionData = segmented_to_virtual((void *)gBehCommand[1]);
    gCurrentObject->collisionData = collisionData;
    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 Behavior2D(void)
{
    gCurrentObject->oHomeX = gCurrentObject->oPosX;
    gCurrentObject->oHomeY = gCurrentObject->oPosY;
    gCurrentObject->oHomeZ = gCurrentObject->oPosZ;
    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 beh_cmd_interact_type(void)
{
    gCurrentObject->oInteractType = gBehCommand[1];

    gBehCommand += 2;
    return BEH_CONTINUE;
}

// unused
static s32 Behavior31(void)
{
    gCurrentObject->oUnk190 = gBehCommand[1];

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 beh_cmd_scale(void)
{
    UNUSED u8 sp1f = (gBehCommand[0] >> 16) & 0xFF;
    s16 sp1c = gBehCommand[0] & 0xFFFF;

    ScaleObject((f32)sp1c / 100.0f);

    gBehCommand++;
    return BEH_CONTINUE;
}

static s32 Behavior30(void)
{
    UNUSED f32 sp04, sp00;

    gCurrentObject->oUnk128 = (f32)(s16)(gBehCommand[1] >> 16);
    gCurrentObject->oGravity = (f32)(s16)(gBehCommand[1] & 0xFFFF) / 100.0f;
    gCurrentObject->oUnk158 = (f32)(s16)(gBehCommand[2] >> 16) / 100.0f;
    gCurrentObject->oUnk12C = (f32)(s16)(gBehCommand[2] & 0xFFFF) / 100.0f;
    gCurrentObject->oFriction = (f32)(s16)(gBehCommand[3] >> 16) / 100.0f;
    gCurrentObject->oBuoyancy = (f32)(s16)(gBehCommand[3] & 0xFFFF) / 100.0f;

    // unused parameters
    sp04 = (f32)(s16)(gBehCommand[4] >> 16) / 100.0f;
    sp00 = (f32)(s16)(gBehCommand[4] & 0xFFFF) / 100.0f;

    gBehCommand += 5;
    return BEH_CONTINUE;
}

static s32 beh_cmd_obj_bic_int32(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s32 flags = gBehCommand[1];

    flags = flags ^ 0xFFFFFFFF;

    object_and_s32(gCurrentObject->parentObj, objectOffset, flags);

    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 Behavior37(void)
{
    struct struct8029E388 *arg0 = (struct struct8029E388 *) gBehCommand[1];
    func_8029E388(gCurrentObject, arg0);
    gBehCommand += 2;
    return BEH_CONTINUE;
}

static s32 Behavior34(void)
{
    u8 objectOffset = (gBehCommand[0] >> 16) & 0xFF;
    s16 arg1 = (gBehCommand[0] & 0xFFFF);

    if ((gGlobalTimer % arg1) == 0)
        cur_object_add_s32(objectOffset, 1);

    gBehCommand++;
    return BEH_CONTINUE;
}

void func_80385BF0(void)
{
    // (empty function)
}

typedef s32 (*BehCommandProc)(void);
static BehCommandProc BehaviorJumpTable[] =
{
    beh_cmd_begin,
    beh_cmd_delay,
    beh_cmd_call,
    beh_cmd_return,
    beh_cmd_goto,
    beh_cmd_begin_repeat,
    beh_cmd_end_repeat,
    beh_cmd_end_repeat_nobreak,
    beh_cmd_begin_loop,
    beh_cmd_end_loop,
    beh_cmd_break,
    Behavior0B,
    beh_cmd_callnative,
    beh_cmd_obj_add_float,
    beh_cmd_obj_set_float,
    beh_cmd_obj_add_int,
    beh_cmd_obj_set_int,
    beh_cmd_obj_or_int,
    beh_cmd_obj_bic_int,
    beh_cmd_obj_set_int_rand_rshift,
    beh_cmd_obj_set_float_rand,
    beh_cmd_obj_set_int_rand,
    beh_cmd_obj_add_float_rand,
    beh_cmd_obj_add_int_rand_rshift,
    Behavior18,
    Behavior19,
    Behavior1A,
    beh_cmd_graph_node,
    Behavior1C,
    beh_cmd_deactivate,
    Behavior1E,
    beh_cmd_obj_sum_float,
    beh_cmd_obj_sum_int,
    beh_cmd_billboard,
    beh_cmd_unhide,
    beh_cmd_set_hitbox,
    Behavior24,
    beh_cmd_delay_var,
    Behavior26,
    beh_cmd_obj_set_int32,
    Behavior28,
    Behavior29,
    beh_cmd_collision_data,
    Behavior2B,
    Behavior2C,
    Behavior2D,
    Behavior2E,
    beh_cmd_interact_type,
    Behavior30,
    Behavior31,
    beh_cmd_scale,
    beh_cmd_obj_bic_int32,
    Behavior34,
    Behavior35,
    Behavior36,
    Behavior37,
};

void cur_object_exec_behavior(void)
{
    UNUSED u32 unused;

    s16 flagsLo = gCurrentObject->oFlags;
    f32 distanceFromMario;
    BehCommandProc behCmdFunc;
    s32 behProcResult;

    if (flagsLo & OBJ_FLAG_0040)
    {
        gCurrentObject->oDistanceToMario = objects_calc_distance(gCurrentObject, gMarioObject);
        distanceFromMario = gCurrentObject->oDistanceToMario;
    }
    else
    {
        distanceFromMario = 0.0f;
    }

    if (flagsLo & OBJ_FLAG_2000)
        gCurrentObject->oAngleToMario = func_8029DF18(gCurrentObject, gMarioObject);

    if (gCurrentObject->oAction != gCurrentObject->oPrevAction)
    {
        (void) (gCurrentObject->oTimer = 0,
        gCurrentObject->oUnk150 = 0,
        gCurrentObject->oPrevAction = gCurrentObject->oAction);
    }

    gBehCommand = gCurrentObject->behScript;

    do
    {
        behCmdFunc = BehaviorJumpTable[*gBehCommand >> 24];
        behProcResult = behCmdFunc();
    } while (behProcResult == BEH_CONTINUE);

    gCurrentObject->behScript = gBehCommand;

    if (gCurrentObject->oTimer < 0x3FFFFFFF)
        gCurrentObject->oTimer++;

    if (gCurrentObject->oAction != gCurrentObject->oPrevAction) 
    {
        (void) (gCurrentObject->oTimer = 0,
        gCurrentObject->oUnk150 = 0,
        gCurrentObject->oPrevAction = gCurrentObject->oAction);
    }

    flagsLo = (s16)gCurrentObject->oFlags;

    if (flagsLo & OBJ_FLAG_0010)
        func_8029F170(gCurrentObject);

    if (flagsLo & OBJ_FLAG_0008)
        gCurrentObject->oFaceAngleYaw = gCurrentObject->oAngleYaw;

    if (flagsLo & OBJ_FLAG_0002)
        func_802A0A90();    

    if (flagsLo & OBJ_FLAG_0004)
        func_802A0B28();

    if (flagsLo & OBJ_FLAG_0200)
        func_802A22DC(gCurrentObject);

    if (flagsLo & OBJ_FLAG_0800)
        func_802A2270(gCurrentObject);

    if (flagsLo & OBJ_FLAG_0001)
        func_80383D68(gCurrentObject);

    if (gCurrentObject->oUnk1A0 != 0xFFFFFFFF)
    {
        func_802A3A68();
    }
    else if ((flagsLo & OBJ_FLAG_0040) && gCurrentObject->collisionData == NULL)
    {
        if ((flagsLo & OBJ_FLAG_0080) == 0)
        {
            if (distanceFromMario > gCurrentObject->oDrawingDistance)
            {
                gCurrentObject->header.gfx.node.flags &= 0xFFFFFFFE;
                gCurrentObject->active |= 2;
            }
            else if (gCurrentObject->oHeldState == HELD_FREE)
            {
                gCurrentObject->header.gfx.node.flags |= 1;
                gCurrentObject->active &= 0xFFFFFFFD;
            }
        }    
    }
}
