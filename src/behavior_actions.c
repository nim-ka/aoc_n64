#include <ultra64.h>

#include "sm64.h"
#include "types.h"
#include "behavior_actions.h"
#include "game.h"
#include "main.h"
#include "mario.h"
#include "behavior_script.h"
#include "math_util.h"
#include "object_helpers.h"
#include "object_helpers2.h"
#include "behavior_data.h"
#include "obj_behaviors.h"
#include "surface_collision.h"
#include "surface_load.h"
#include "level_update.h"
#include "audio/interface_2.h"
#include "save_file.h"
#include "area.h"
#include "graph_node.h"
#include "camera.h"
#include "display.h"
#include "spawn_object.h"
#include "mario_actions_cutscene.h"
#include "object_list_processor.h"
#include "spawn_sound.h"
#include "debug.h"
#include "object_constants.h"
#include "mario_step.h"
#include "obj_behaviors_2.h"
#include "platform_displacement.h"
#include "interaction.h"
#include "ingame_menu.h"
#include "room.h"
#include "rendering_graph_node.h"

#define o gCurrentObject

// BSS
s16 D_8035FF10;

struct Struct8032F24A {
    s16 pad;
    s16 unk0;
    void* unk1;
    s16 unk2;
};

struct Struct8032F34C {
    s16 unk0;
    s16 unk1;
    s16 unk2;
    s16 unk3;
    void* unk4;
};

struct Struct8032FB4C {
    u8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s8* unk4;
};

struct Struct8032F698 {
    void* unk0;
    s16 unk1;
    s16 unk2;
    s16 unk3;
    s16 unk4;
};

struct Struct802C0DF0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    void* unk4;
};

struct Struct8032FE4C {
    s32 unk0;
    s32 unk1;
    f32 unk2;
    f32 unk3;
};

struct Struct8032F754 {
    s32 unk0;
    Vec3f unk1;
    f32 unk2;
};

struct Struct8032FCE8 {
    s16 unk0;
    s16 unk1;
    void* unk2;
};

extern void BehClimbDetectLoop();
extern s16 gDebugInfo[][8];
extern s8 D_8035FE68[][2];
extern s32 inside_castle_seg7_dl_0702A880;
extern u8 inside_castle_seg7_collision_ddd_warp_2[];
extern u8 inside_castle_seg7_collision_ddd_warp[];
extern s32 gDialogueResponse;
extern s32 D_8033B858;
extern u8 D_8032CFF4;
extern s8* D_8032F96C[];
extern u32 bowser_seg6_unkmoveshorts_060576FC[];
extern u32 blue_fish_seg3_anims_0301C2B0[];
extern u32 cyan_fish_seg6_anims_0600E264[];
extern u32 blue_fish_seg3_anims_0301C2B0[];

void func_802A8D18(f32,f32,s32);

s32 func_802BDAD4(void);
void func_802C49E0(void);

s32 D_8032F0C0[] = {SAVE_FLAG_HAVE_WING_CAP,SAVE_FLAG_HAVE_METAL_CAP,SAVE_FLAG_HAVE_VANISH_CAP};

s16 D_8032F0CC[] = {6047,5664,5292,4934,4587,4254,3933,3624,3329,3046,2775,2517,2271,2039,1818,1611,1416,1233,1063,906,761,629,509,402,308,226,157,100,56,25,4,0};

void func_802A4DB0(void)
{
    o->oVelX = (o->oUnkBC) * coss(o->oMoveAngleYaw);
    o->oVelZ = (o->oUnkBC) * - sins(o->oMoveAngleYaw);
    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
}

void BehStarDoorLoop(void)
{
    UNUSED u8 pad[4];
    struct Object* sp18;
    sp18 = obj_nearest_object_with_behavior(beh_star_door);
    switch(o->oAction)
    {
    case 0:
        obj_become_tangible();
        if (0x30000 & o->oInteractStatus)
            o->oAction = 1;
        if(sp18 != NULL && sp18->oAction != 0)
            o->oAction = 1;
        break;
    case 1:
        if(o->oTimer == 0 && (s16)(o->oMoveAngleYaw) >= 0)
            PlaySound2(0x304EC081);
        obj_become_intangible();
        o->oUnkBC = -8.0f;
        func_802A4DB0();
        if(o->oTimer >= 16)
            o->oAction++;
        break;
    case 2:
        if(o->oTimer >= 31)
            o->oAction++;
        break;
    case 3:
        if(o->oTimer == 0 && (s16)(o->oMoveAngleYaw) >= 0)
            PlaySound2(0x304FC081);
        o->oUnkBC = 8.0f;
        func_802A4DB0();
        if(o->oTimer >= 16)
            o->oAction++;
        break;
    case 4:
        o->oInteractStatus = 0;
        o->oAction = 0;
        break;
    }
}

void BehPiranhaParticleLoop(void)
{
    if(o->oTimer == 0)
    {
        o->oVelY = 20.0f + 20.0f * RandomFloat();
        o->oForwardVel = 20.0f + 20.0f * RandomFloat();
        o->oMoveAngleYaw = RandomU16();
    }
    obj_move_using_fvel_and_gravity();
}

void ActionMrIParticle0(void)
{
    obj_scale(3.0f);
    o->oForwardVel = 20.0f;
    obj_update_floor_and_walls();
    if(0x8000 & o->oInteractStatus)
        o->oAction = 1;
    else if((o->oTimer >= 101) || (0x200 & o->oMoveFlags) || (8 & (s16)o->activeFlags))
    {
        mark_object_for_deletion(o);
        func_802A3004();
    }
}

void ActionMrIParticle1(void)
{
    s32 i;
    mark_object_for_deletion(o);
    for(i = 0;i<10;i++)
        spawn_object(o,0xaa,beh_giant_piranha_particle);
}

void (*TableMrIParticleActions[])(void) = {ActionMrIParticle0,ActionMrIParticle1};

void BehMrIParticleLoop(void)
{
    obj_call_action_function(TableMrIParticleActions);
}

void func_802A525C(void)
{
    struct Object* particle;
    f32 sp18 = o->header.gfx.scale[1];
    particle = spawn_object(o,170,beh_mr_i_particle);
    particle->oPosY += 50.0f * sp18;
    particle->oPosX += sins(o->oMoveAngleYaw) * 90.0f * sp18;
    particle->oPosZ += coss(o->oMoveAngleYaw) * 90.0f * sp18;
    PlaySound2(0x50010081);
}

void BehMrIBodyLoop(void)
{
    copy_object_pos_and_angle(o,o->parentObj);
    if(!(8 & o->activeFlags))
    {
        copy_object_scale(o,o->parentObj);
        set_object_parent_relative_pos(o,0,0,o->header.gfx.scale[1] * 100.0f);
        build_object_transform_from_pos_and_angle(o,44,15);
        translate_object_local(o,6,44);
        o->oFaceAnglePitch = o->oMoveAnglePitch;
        o->oGraphYOffset = o->header.gfx.scale[1] * 100.f;
    }
    if(o->parentObj->OBJECT_FIELD_S32(0x22) != 1)
        o->OBJECT_FIELD_S32(0x1a) = -1;
    else
    {
        o->OBJECT_FIELD_S32(0x1a)++;
        if(o->OBJECT_FIELD_S32(0x1a) == 15)
            o->parentObj->OBJECT_FIELD_S32(0x22) = 0;
    }
    if(!o->parentObj->activeFlags)
        mark_object_for_deletion(o);
}

void ActionMrI3(void)
{
    s16 sp36;
    s16 sp34;
    f32 sp30;
    f32 sp2C;
    UNUSED u8 pad[8];
    f32 sp20;
    f32 sp1C;
    if(o->oBehParams2ndByte)
        sp1C = 2.0f;
    else
        sp1C = 1.0f;
    if(o->OBJECT_FIELD_S32(0x1E) < 0)
        sp34 = 0x1000;
    else
        sp34 = -0x1000;
    sp2C = (o->oTimer + 1)/96.0f;
    if(o->oTimer < 64)
    {
        sp36 = o->oMoveAngleYaw;
        o->oMoveAngleYaw += sp34 * coss(0x4000 * sp2C);
        if(sp36 < 0 && o->oMoveAngleYaw >= 0)
            PlaySound2(0x906B0081);
        o->oMoveAnglePitch = (1.0 - coss(0x4000 * sp2C)) * -0x4000;
        obj_shake_y(4.0f);
    }
    else if(o->oTimer < 96)
    {
        if(o->oTimer == 64)
            PlaySound2(0x50140081);
        sp30 = (o->oTimer - 63)/32.0f;
        o->oMoveAngleYaw += sp34 * coss(0x4000 * sp2C);
        o->oMoveAnglePitch = (1.0 - coss(0x4000 * sp2C)) * - 0x4000;
        obj_shake_y((s32)((1.0f - sp30) * 4)); // trucating the float?
        sp20 = coss(0x4000 * sp30) * 0.4 + 0.6;
        obj_scale(sp20*sp1C);
    }
    else if(o->oTimer < 104) {} // do nothing
    else if(o->oTimer < 168)
    {
        if(o->oTimer == 104)
        {
            obj_become_intangible();
            func_802A3004();
            o->oMrISize = sp1C * 0.6;
            if(o->oBehParams2ndByte)
            {
                o->oPosY += 100.0f;
                CreateStar(1370,2000.0f,-320.0f);
                mark_object_for_deletion(o);
            }
            else obj_spawn_loot_blue_coin();
        }
        o->oMrISize -= 0.2 * sp1C;
        if(o->oMrISize < 0)
            o->oMrISize = 0;
        obj_scale(o->oMrISize);
    }
    else mark_object_for_deletion(o);
}

void ActionMrI2(){
    s16 sp1E;
    s16 sp1C;
    sp1E = o->oMoveAngleYaw;
    if(o->oTimer == 0){
        if(o->oBehParams2ndByte)
            o->OBJECT_FIELD_S32(0x1B) = 200;
        else
            o->OBJECT_FIELD_S32(0x1B) = 120;
        o->OBJECT_FIELD_S32(0x1D) = 0;
        o->OBJECT_FIELD_S32(0x1E) = 0;
        o->OBJECT_FIELD_S32(0x1F) = 0;
    }
    obj_turn_toward_object(o,gMarioObject,0x10,0x800);
    obj_turn_toward_object(o,gMarioObject,0x0F,0x400);
    sp1C = sp1E - (s16)(o->oMoveAngleYaw);
    if(!sp1C)
    {
        o->OBJECT_FIELD_S32(0x1D) = 0;
        o->OBJECT_FIELD_S32(0x1E) = 0;
    }
    else if(sp1C > 0)
    {
        if(o->OBJECT_FIELD_S32(0x1E) > 0)
            o->OBJECT_FIELD_S32(0x1D) += sp1C;
        else
            o->OBJECT_FIELD_S32(0x1D) = 0;
        o->OBJECT_FIELD_S32(0x1E) = 1;
    }
    else
    {
        if(o->OBJECT_FIELD_S32(0x1E) < 0)
            o->OBJECT_FIELD_S32(0x1D) -= sp1C;
        else
            o->OBJECT_FIELD_S32(0x1D) = 0;
        o->OBJECT_FIELD_S32(0x1E) = -1;
    }
    if(!o->OBJECT_FIELD_S32(0x1D))
        o->OBJECT_FIELD_S32(0x1B) = 120;
    if(o->OBJECT_FIELD_S32(0x1D) > 1<<16)
        o->oAction = 3;
    o->OBJECT_FIELD_S32(0x1B) -= 1;
    if(!o->OBJECT_FIELD_S32(0x1B))
    {
        o->OBJECT_FIELD_S32(0x1B) = 120;
        o->OBJECT_FIELD_S32(0x1D) = 0;
    }
    if(o->OBJECT_FIELD_S32(0x1D) < 5000)
    {
        if(o->OBJECT_FIELD_S32(0x1F) == o->OBJECT_FIELD_S32(0x20))
            o->OBJECT_FIELD_S32(0x22) = 1;
        if(o->OBJECT_FIELD_S32(0x1F) == o->OBJECT_FIELD_S32(0x20) + 20)
        {
            func_802A525C();
            o->OBJECT_FIELD_S32(0x1F) = 0;
            o->OBJECT_FIELD_S32(0x20) = (s32)(RandomFloat() * 50.0f + 50.0f);
        }
        o->OBJECT_FIELD_S32(0x1F)++;
    }
    else
    {
        o->OBJECT_FIELD_S32(0x1F) = 0;
        o->OBJECT_FIELD_S32(0x20) = (s32)(RandomFloat() * 50.0f + 50.0f);
    }
    if(o->oDistanceToMario > 800.0f)
        o->oAction = 1;
}

void ActionMrI1(void)
{
    s16 sp1E;
    s16 sp1C;
    s16 sp1A;
    sp1E = angle_to_object(o,gMarioObject);
    sp1C = abs_angle_diff(o->oMoveAngleYaw,sp1E);
    sp1A = abs_angle_diff(o->oMoveAngleYaw,gMarioObject->oFaceAngleYaw);
    if(o->oTimer == 0)
    {
        obj_become_tangible();
        o->oMoveAnglePitch = 0;
        o->OBJECT_FIELD_S32(0x1F) = 30;
        o->OBJECT_FIELD_S32(0x20) = RandomFloat() * 20.0f;
        if(o->OBJECT_FIELD_S32(0x20) & 1)
            o->oAngleVelYaw = -256;
        else
            o->oAngleVelYaw = 256;
    }
    if(sp1C < 1024 && sp1A > 0x4000)
    {
        if(o->oDistanceToMario < 700.0f)
            o->oAction = 2;
        else
            o->OBJECT_FIELD_S32(0x1F)++;
    }
    else
    {
        o->oMoveAngleYaw += o->oAngleVelYaw;
        o->OBJECT_FIELD_S32(0x1F) = 30;
    }
    if(o->OBJECT_FIELD_S32(0x1F) == o->OBJECT_FIELD_S32(0x20) + 60)
        o->OBJECT_FIELD_S32(0x22) = 1;
    if(o->OBJECT_FIELD_S32(0x20) + 80 < o->OBJECT_FIELD_S32(0x1F))
    {
        o->OBJECT_FIELD_S32(0x1F) = 0;
        o->OBJECT_FIELD_S32(0x20) = RandomFloat() * 80.0f;
        func_802A525C();
    }
}

void ActionMrI0(void)
{
#ifndef VERSION_JP
    set_object_angle(o, 0, 0, 0);
#else
    o->oMoveAnglePitch = 0;
    o->oMoveAngleYaw     = 0;
    o->oMoveAngleRoll    = 0;
#endif
    obj_scale(o->oBehParams2ndByte + 1);
    if(o->oTimer == 0)
        obj_set_pos_to_home();
    if(o->oDistanceToMario < 1500.0f)
        o->oAction = 1;
}

void (*TableMrIActions[])(void) = {ActionMrI0,ActionMrI1,ActionMrI2,ActionMrI3};

struct ObjectHitbox D_8032F124 = {8,0,2,2,5,80,150,0,0};

struct SpawnParticlesInfo D_8032F134 = {0,30,164,0,40,0,20,40,252,30,20.0f,0.0f};

UNUSED u8 unused8032F134[] = {10,11,12};

void BehMrILoop(void)
{
    set_object_hitbox(o,&D_8032F124);
    obj_call_action_function(TableMrIActions);
    if(o->oAction != 3)
        if(o->oDistanceToMario > 3000.0f || o->activeFlags & 8)
            o->oAction = 0;
    o->oInteractStatus = 0;
}

void BehPoleInit(void)
{
    s32 sp04;
    sp04 = o->oBehParams >> 0x10 & 0xFF;
    o->hitboxHeight = (f32)(sp04 * 10);
}

void BehGiantPoleLoop(void)
{
    struct Object* topBall;
    if(o->oTimer == 0)
    {
        topBall = spawn_object(o,85,beh_yellow_ball);
        topBall->oPosY += o->hitboxHeight + 50.0f;
    }
    BehClimbDetectLoop();
}

void BehTHIHugeIslandTopLoop(void)
{
    if(D_8035FEE6 & 1)
    {
        if(o->oTimer == 0)
            gWaterRegions[18] = 3000;
        obj_hide();
    }
    else
        load_object_collision_model();
}

void BehTHITinyIslandTopLoop(void)
{
    if(!(D_8035FEE6 & 1)) // last bit not set
    {
        if(o->oAction == 0)
        {
            if(o->oDistanceToMario < 500.0f)
                if(gMarioStates->action == ACT_GROUND_POUND_LAND)
                {
                    o->oAction++;
                    obj_spawn_particles(&D_8032F134);
                    func_802AD82C(20,138,0.3f,3);
                    PlaySound2(0x30008081);
                    obj_hide();
                }
        }
        else
        {
            if(o->oTimer < 50)
            {
                gWaterRegions[18]--;
                PlaySound(0x41160001);
            }
            else
            {
                D_8035FEE6 |= 1; // set last bit
                func_80321228();
                o->oAction += 1;
            }
        }
    }
    else
    {
        if(o->oTimer == 0)
            gWaterRegions[18] = 700;
        obj_hide();
    }
}

void ActionActivateCapSwitch0(void)
{
    o->oAnimState = o->oBehParams2ndByte;
    obj_scale(0.5f);
    o->oPosY += 71.0f;
    spawn_object_relative_with_scale(0,0,-71,0,0.5f,o,86,beh_cap_switch_base);
    if(gCurrLevelNum != LEVEL_UNKNOWN_32)
    {
        if(save_file_get_flags() & D_8032F0C0[o->oBehParams2ndByte])
        {
            o->oAction = 3;
            o->header.gfx.scale[1] = 0.1f;
        }
        else
            o->oAction = 1;
    }
    else
        o->oAction = 1;
}

void ActionActivateCapSwitch1(void)
{
    if(obj_is_mario_on_platform())
    {
        save_file_set_flags(D_8032F0C0[o->oBehParams2ndByte]);
        o->oAction = 2;
        PlaySound2(0x30008081);
    }
}

void ActionActivateCapSwitch2(void)
{
    s32 sp1C;
    if(o->oTimer < 5)
    {
        func_802A3398(2,4,0.5f,0.1f);
        if(o->oTimer == 4)
        {
            ShakeScreen(1);
            func_802A3004();
            func_802AD82C(60,139,0.3f,o->oBehParams2ndByte);
        }
    }
    else
    {
        sp1C = obj_update_dialogue_unk2(1,12,161,0);
        if(sp1C)
            o->oAction = 3;
    }
}

void ActionActivateCapSwitch3(){} // dead function

void (*TableCapSwitchActions[])(void) = {ActionActivateCapSwitch0,ActionActivateCapSwitch1,ActionActivateCapSwitch2,ActionActivateCapSwitch3};

void BehCapSwitchLoop(void)
{
    obj_call_action_function(TableCapSwitchActions);
}

int Geo18_802A719C(s32 arg0,UNUSED s32 arg1,Mat4 arg2)
{
    Mat4 sp20;
    struct Object* sp1C;
    if(arg0 == 1)
    {
        sp1C = (struct Object*)D_8032CFA0;
        if(sp1C->prevObj != NULL)
        {
            func_8029D704(sp20,arg2,D_8032CF9C->unk34);
            func_8029D558(sp20,sp1C->prevObj);
            func_8029EA0C(sp1C->prevObj);
        }
    }
    return 0;
}

void BehBobombAnchorMarioLoop(void)
{
    func_802A8D18(50.0f,50.0f,64);
}

void ActionKingBobomb0(void)
{
#ifdef VERSION_US
    o->oForwardVel = 0;
    o->oVelY = 0;
#endif
    if(o->oSubAction == 0)
    {
        obj_become_intangible();
        D_8032CFD0 = o;
        func_8029ED38(5);
        obj_set_pos_to_home();
        o->oHealth = 3;
        if(obj_is_mario_in_range_and_ready_to_speak(500.0f,100.0f))
        {
            o->oSubAction++;
            func_8031FFB4(0,60,40);
        }
    }
    else if(obj_update_dialogue_unk2(2,1,162,17))
    {
        o->oAction = 2;
        o->oFlags |= OBJ_FLAG_HOLDABLE;
    }
}

int func_802A6AF8(f32 arg0)
{
    if(arg0 < o->oPosY - gMarioObject->oPosY)
        return 1;
    else
        return 0;
}

void ActionKingBobomb2(void)
{
    obj_become_tangible();
    if(o->oPosY - o->oHomeY < -100.0f) // Thrown off hill
    {
        o->oAction =    5;
        obj_become_intangible();
    }
    if(o->OBJECT_FIELD_S32(0x1E) == 0)
    {
        if(obj_check_anim_frame(15))
            ShakeScreen(1);
        if(func_802A4AB0(4))
            o->OBJECT_FIELD_S32(0x1E)++;
    }
    else
    {
        if(o->OBJECT_FIELD_S32(0x1E) == 1)
        {
            func_802A4A70(11,7);
            o->OBJECT_FIELD_S32(0x1E) = 2;
        }
        else
            func_8029ED38(11);
        if(o->OBJECT_FIELD_S32(0x20) == 0)
        {
            o->oForwardVel = 3.0f;
            obj_rotate_yaw_toward(o->oAngleToMario,0x100);
        }
        else
        {
            o->oForwardVel = 0.0f;
            o->OBJECT_FIELD_S32(0x20)--;
        }
    }
    if(obj_check_grabbed_mario())
        o->oAction = 3;
    if(func_802A6AF8(1200.0f))
    {
        o->oAction = 0;
        func_80320CE8(1046);
    }
}


void ActionKingBobomb3(void)
{
    if(o->oSubAction == 0)
    {
        o->oForwardVel = 0;
        o->OBJECT_FIELD_S32(0x1F) = 0;
        o->OBJECT_FIELD_S32(0x1D) = 0;
        if(o->oTimer == 0)
            PlaySound2(0x501D8081);
        if(func_802A4AB0(0))
        {
            o->oSubAction++;
            func_802A4A70(1,0);
        }
    }
    else
    {
        if(o->oSubAction == 1)
        {
            func_8029ED38(1);
            o->OBJECT_FIELD_S32(0x1D) += player_performed_grab_escape_action();
            print_debug_bottom_up("%d",o->OBJECT_FIELD_S32(0x1D));
            if(o->OBJECT_FIELD_S32(0x1D) > 10)
            {
                o->oUnk88 = 3;
                o->oAction = 2;
                o->OBJECT_FIELD_S32(0x20) = 35;
                o->oInteractStatus &= ~0x800;
            }
            else
            {
                o->oForwardVel = 3.0f;
                if(o->OBJECT_FIELD_S32(0x1F) > 20 && obj_rotate_yaw_toward(0,0x400))
                {
                    o->oSubAction++;
                    func_802A4A70(9,22);
                }
            }
            o->OBJECT_FIELD_S32(0x1F)++;
        }
        else
        {
            func_8029ED38(9);
            if(obj_check_anim_frame(31))
            {
                o->oUnk88 = 2;
                PlaySound2(0x501EA081);
            }
            else if(func_8029F788())
            {
                o->oAction = 1;
                o->oInteractStatus &= ~0x800;
            }
        }
    }
}

void ActionKingBobomb1(void)
{
    o->oForwardVel = 0;
    o->oVelY = 0;
    func_8029ED38(11);
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw,o->oAngleToMario,512);
    if(o->oDistanceToMario < 2500.0f)
        o->oAction = 2;
    if(func_802A6AF8(1200.0f)){
        o->oAction = 0;
        func_80320CE8(1046);
    }
}

void ActionKingBobomb6(void)
{
    if(o->oSubAction == 0)
    {
        if(o->oTimer == 0)
        {
            o->OBJECT_FIELD_S32(0x1F) = 0;
            PlaySound2(0x50168081);
            PlaySound2(0x91424081);
            ShakeScreen(1);
            func_802AA618(0,0,100.0f);
            o->oInteractType = 8;
            obj_become_tangible();
        }
        if(func_802A4AB0(2))
            o->OBJECT_FIELD_S32(0x1F)++;
        if(o->OBJECT_FIELD_S32(0x1F) > 3)
        {
            o->oSubAction++;
            ; // Needed to match
        }
    }
    else
    {
        if(o->oSubAction == 1)
        {
            if(func_802A4AB0(10))
            {
                o->oSubAction++;
                o->oInteractType = 2;
                obj_become_intangible();
            }
        }
        else
        {
            func_8029ED38(11);
            if(obj_rotate_yaw_toward(o->oAngleToMario,0x800) == 1)
                o->oAction = 2;
        }
    }
}


void ActionKingBobomb7(void)
{
    func_8029ED38(2);
    if(obj_update_dialogue_unk2(2,2,162,116))
    {
        create_sound_spawner(0x5147C081);
        obj_hide();
        obj_become_intangible();
        func_802AA618(0,0,200.0f);
        func_802AD82C(20,138,3.0f,4);
        ShakeScreen(1);
#ifndef VERSION_JP
        obj_spawn_star_at_y_offset(2000.0f, 4500.0f, -4500.0f, 200.0f);
#else
        o->oPosY += 100.0f;
        CreateStar(2000.0f,4500.0f,-4500.0f);
#endif
        o->oAction = 8;
    }
}

void ActionKingBobomb8(void)
{
    if(o->oTimer == 60)
        func_80320CE8(1046);
}

void ActionKingBobomb4() // bobomb been thrown
{
    if(o->oPosY - o->oHomeY > -100.0f) // not thrown off hill
    {
        if(o->oMoveFlags & 1)
        {
            o->oHealth--;
            o->oForwardVel = 0;
            o->oVelY = 0;
            PlaySound2(0x50168081);
            if(o->oHealth)
                o->oAction = 6;
            else
                o->oAction = 7;
        }
    }
    else
    {
        if(o->oSubAction == 0)
        {
            if(o->oMoveFlags & 2)
            {
                o->oForwardVel = 0;
                o->oVelY = 0;
                o->oSubAction++;
            }
            else if(o->oMoveFlags & 1)
                PlaySound2(0x50168081);
        }
        else
        {
            if(func_802A4AB0(10))
                o->oAction = 5; // Go back to top of hill
            o->oSubAction++;
        }
    }
}

void ActionKingBobomb5() // bobomb returns home
{
    switch(o->oSubAction)
    {
    case 0:
        if(o->oTimer == 0)
            PlaySound2(0x50468081);
        o->OBJECT_FIELD_S32(0x1C) = 1;
        func_802A4AEC(8);
        o->oMoveAngleYaw = obj_angle_to_home();
        if(o->oPosY < o->oHomeY)
            o->oVelY = 100.0f;
        else
        {
            func_802B2894(&o->oHomeX,&o->oPosX,100.0f,-4.0f); // the Vec3fs oHome and oPos are being passed by reference
            o->oSubAction++;
        }
        break;
    case 1:
        func_802A4AEC(8);
        if(o->oVelY < 0 && o->oPosY < o->oHomeY)
        {
            o->oPosY = o->oHomeY;
            o->oVelY = 0;
            o->oForwardVel = 0;
            o->oGravity = -4.0f;
            o->OBJECT_FIELD_S32(0x1C) = 0;
            func_8029ED38(7);
            PlaySound2(0x50168081);
            ShakeScreen(1);
            o->oSubAction++;
        }
        break;
    case 2:
        if(func_802A4AB0(7))
            o->oSubAction++;
        break;
    case 3:
        if(func_802A6AF8(1200.0f))
        {
            o->oAction = 0;
            func_80320CE8(1046);
        }
        if(obj_is_mario_in_range_and_ready_to_speak(500.0f,100.0f))
            o->oSubAction++;
        break;
    case 4:
        if(obj_update_dialogue_unk2(2,1,162,128))
            o->oAction = 2;
        break;
    }
}

void (*TableKingBobombActions[])(void) = {ActionKingBobomb0,ActionKingBobomb1,ActionKingBobomb2,ActionKingBobomb3,ActionKingBobomb4,ActionKingBobomb5,ActionKingBobomb6,ActionKingBobomb7,ActionKingBobomb8};
struct SoundState TableKingBobombSoundStates[] = {{0,0,0,0},{1,1,20,0x50158081},{0,0,0,0},{0,0,0,0},{1,15,-1,0x50158081},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,33,-1,0x50158081},{0,0,0,0},{1,1,15,0x50158081}};

void func_802A7748(void)
{
    obj_update_floor_and_walls();
    if(o->OBJECT_FIELD_S32(0x1C) == 0)
        obj_move_standard(-78);
    else
        obj_move_using_fvel_and_gravity();
    obj_call_action_function(TableKingBobombActions);
    exec_anim_sound_state(TableKingBobombSoundStates);
    if(o->oDistanceToMario < 5000.0f)
        obj_enable_rendering();
    else
        obj_disable_rendering();
}

void BehKingBobombLoop(void)
{
    f32 sp34 = 20.0f;
    f32 sp30 = 50.0f;
    UNUSED u8 pad[8];
    o->oUnk190 |= 4;
    switch(o->oHeldState)
    {
    case HELD_FREE:
        func_802A7748();
        break;
    case HELD_HELD:
        func_8029FA5C(6,1);
        break;
    case HELD_THROWN:
    case HELD_DROPPED:
        obj_get_thrown_or_placed(sp34,sp30,4);
        obj_become_intangible();
        o->oPosY += 20.0f;
        break;
    }
    o->oInteractStatus = 0;
}

void BehBetaChestInit(void)
{
    obj_set_model(101);
    o->oMoveAngleYaw = RandomU16(); // Pointless
    o->oMoveAngleYaw = 0;
    spawn_object_relative(0,0,97,-77,o,102,beh_beta_chest_upper);
}

void BehBetaChestLoop(void)
{
    obj_push_mario_away_from_cylinder(200.0f,200.0f);
}

void BehBetaChestUpperLoop(void)
{
    switch(o->oAction)
    {
    case 0:
        if(dist_between_objects(o->parentObj,gMarioObject) < 300.0f)
            o->oAction++;
        break;
    case 1:
        if(o->oTimer == 0)
        {
            spawn_object_relative(0,0,-80,120,o,168,beh_water_air_bubble);
            SetSound(0x31228081,&o->header.gfx.unk54);
        }
        o->oFaceAnglePitch -= 0x400;
        if(o->oFaceAnglePitch < -0x4000)
            o->oAction++;
    case 2:
        break;
    }
}

void BehWaterAirBubbleInit(void)
{
    obj_scale(4.0f);
}

// Fields 0xF4 & 0xF8 seem to be angles for bubble and cannon

void BehWaterAirBubbleLoop(void)
{
    s32 i;
    o->header.gfx.scale[0] = sins(o->OBJECT_FIELD_S32(0x1B)) * 0.5 + 4.0;
    o->header.gfx.scale[1] = -sins(o->OBJECT_FIELD_S32(0x1B)) * 0.5 + 4.0;
    o->OBJECT_FIELD_S32(0x1B) += 0x400;
    if(o->oTimer < 30)
    {
        obj_become_intangible();
        o->oPosY += 3.0f;
    }
    else
    {
        obj_become_tangible();
        obj_obj_forward_vel_approach_upward(2.0f,10.0f);
        o->oMoveAngleYaw = angle_to_object(o,gMarioObject);
        obj_move_using_fvel_and_gravity();
    }
    o->oPosX += RandomFloat() * 4.0f - 2.0f;
    o->oPosZ += RandomFloat() * 4.0f - 2.0f;
    if(o->oInteractStatus & 0x8000 || o->oTimer > 200)
    {
        PlaySound2(0x300B0081);
        mark_object_for_deletion(o);
        for(i=0;i<30;i++)
            spawn_object(o,168,beh_bubble_maybe);
    }
    if(find_water_level(o->oPosX,o->oPosZ) < o->oPosY)
        mark_object_for_deletion(o);
    o->oInteractStatus = 0;
}

void BehBubbleWaveInit(void)
{
    o->OBJECT_FIELD_S32(0x1D) = 0x800 + (s32)(RandomFloat() * 2048.0f);
    o->OBJECT_FIELD_S32(0x1E) = 0x800 + (s32)(RandomFloat() * 2048.0f);
    PlaySound2(0x300B0081);
}

void Unknown802A7E48(void)
{
    obj_scale(RandomFloat() + 1.0);
}

void BehBubbleMaybeLoop(void)
{
    o->oPosY += RandomFloat() * 3.0f    + 6.0f;
    o->oPosX += RandomFloat() * 10.0f - 5.0f;
    o->oPosZ += RandomFloat() * 10.0f - 5.0f;
    o->header.gfx.scale[0] = sins(o->OBJECT_FIELD_S32(0x1B)) * 0.2 + 1.0;
    o->OBJECT_FIELD_S32(0x1B) += o->OBJECT_FIELD_S32(0x1D);
    o->header.gfx.scale[1] = sins(o->OBJECT_FIELD_S32(0x1C)) * 0.2 + 1.0;
    o->OBJECT_FIELD_S32(0x1C) += o->OBJECT_FIELD_S32(0x1E);
}

void BehSmallWaterWaveLoop(void)
{
    f32 sp1C = find_water_level(o->oPosX,o->oPosZ);
    o->header.gfx.scale[0] = sins(o->OBJECT_FIELD_S32(0x1B)) * 0.2 + 1.0;
    o->OBJECT_FIELD_S32(0x1B) += o->OBJECT_FIELD_S32(0x1D);
    o->header.gfx.scale[1] = sins(o->OBJECT_FIELD_S32(0x1C)) * 0.2 + 1.0;
    o->OBJECT_FIELD_S32(0x1C) += o->OBJECT_FIELD_S32(0x1E);
    if(o->oPosY > sp1C)
    {
        o->activeFlags = 0;
        o->oPosY += 5.0f;
        if(gFreeObjectList.next != NULL)
            spawn_object(o,165,beh_water_surface_white_wave_2);
    }
    if(o->oInteractStatus & 0x8000)
        mark_object_for_deletion(o);
}

void func_802A81C4(void)
{
    o->header.gfx.scale[0] = sins(o->OBJECT_FIELD_S32(0x1B)) * 0.5 + 2.0;
    o->OBJECT_FIELD_S32(0x1B) += o->OBJECT_FIELD_S32(0x1D);
    o->header.gfx.scale[1] = sins(o->OBJECT_FIELD_S32(0x1C)) * 0.5 + 2.0;
    o->OBJECT_FIELD_S32(0x1C) += o->OBJECT_FIELD_S32(0x1E);
}

void BehParticleInit(void)
{
    scale_object_xyz(o,2.0f,2.0f,1.0f);
    o->OBJECT_FIELD_S32(0x1D) = 0x800 + (s32)(RandomFloat() * 2048.0f);
    o->OBJECT_FIELD_S32(0x1E) = 0x800 + (s32)(RandomFloat() * 2048.0f);
    translate_object_xyz_random(o,100.0f);
}
void BehParticleLoop() {
    f32 sp24 = find_water_level(o->oPosX,o->oPosZ);
    o->oPosY += 5.0f;
    translate_object_xz_random(o,4.0f);
    func_802A81C4();
    if(o->oPosY > sp24 && o->oTimer)
    {
        mark_object_for_deletion(o);
        try_to_spawn_object(5,0,o,165,beh_water_surface_white_wave_2);
    }
}

void BehSmallBubblesLoop(void)
{
    o->oPosY += 5.0f;
    translate_object_xz_random(o,4.0f);
    func_802A81C4();
}

void BehFishGroupLoop(void)
{
    if(gMarioCurrentRoom == 15 || gMarioCurrentRoom == 7)
        if(gGlobalTimer & 1)
            spawn_object(o,164,beh_small_particle_bubbles);
}

void BehWaterWavesInit(void)
{
    s32 sp1C;
    for(sp1C=0;sp1C<3;sp1C++)
        spawn_object(o,164,beh_small_particle);

}

void BehCannonBaseUnusedLoop(void)
{
    o->oPosY += o->oVelY;
}

void ActionOpenedCannon0(void)
{
    if(o->oTimer == 0)
    {
        o->oInteractStatus = 0;
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
        o->oMoveAnglePitch = 0;
        o->oMoveAngleYaw = (s16)(o->oBehParams2ndByte << 8);
        o->OBJECT_FIELD_S32(0x1B) = 0;
        o->OBJECT_FIELD_S32(0x21) = 0;
        obj_enable_rendering();
        obj_become_tangible();
    }
    if(o->oDistanceToMario < 500.0f)
    {
        obj_become_tangible();
        obj_enable_rendering();
        if(o->oInteractStatus & 0x8000 && (!(o->oInteractStatus & 0x800000)))
        {
            o->oAction = 4;
            o->OBJECT_FIELD_S32(0x21) = 1;
            o->OBJECT_FIELD_S32(0x1C) = 1;
        }
        else
            o->oInteractStatus = 0;
    }
    else
    {
        obj_become_intangible();
        obj_disable_rendering();
        o->OBJECT_FIELD_S32(0x21) = 0;
    }
}

void ActionOpenedCannon4(void)
{
    if(o->oTimer == 0)
        PlaySound2(0x500DF081);
    o->oPosY += 5.0f;
    o->oPosX += (f32)((o->oTimer/2 & 1) - 0.5) * 2.0f;
    o->oPosZ += (f32)((o->oTimer/2 & 1) - 0.5) * 2.0f;
    if(o->oTimer > 67)
    {
        o->oPosX += (f32)((o->oTimer/2 & 1) - 0.5) * 4.0f;
        o->oPosZ += (f32)((o->oTimer/2 & 1) - 0.5) * 4.0f;
        o->oAction = 6;
    }
}

void ActionOpenedCannon6(void)
{
    if(o->oTimer == 0)
        PlaySound2(0x500EF081);
    if(o->oTimer < 4)
    {
        o->oPosX += (f32)((o->oTimer/2 & 1) - 0.5) * 4.0f;
        o->oPosZ += (f32)((o->oTimer/2 & 1) - 0.5) * 4.0f;
    }
    else
    {
        if(o->oTimer < 6) {}
        else
        {
            if(o->oTimer < 22)
            {
                o->oMoveAngleYaw = sins(o->OBJECT_FIELD_S32(0x1B)) * 0x4000 + ((s16)(o->oBehParams2ndByte << 8));
                o->OBJECT_FIELD_S32(0x1B) += 0x400;
            }
            else if(o->oTimer < 26) {}
            else
            {
                o->OBJECT_FIELD_S32(0x1B) = 0;
                o->oAction = 5;
            }
        }
    }
}

void ActionOpenedCannon5(void)
{
    if(o->oTimer == 0)
        PlaySound2(0x500FF081);
    if(o->oTimer < 4) {}
    else
    {
        if(o->oTimer < 20)
        {
            o->OBJECT_FIELD_S32(0x1B) += 0x400;
            o->oMoveAnglePitch = sins(o->OBJECT_FIELD_S32(0x1B)) * 0x2000;
        }
        else if(o->oTimer < 25) {}
        else
            o->oAction = 1;
    }
}

void ActionOpenedCannon1(void)
{
    UNUSED s32 unused;
    obj_become_intangible();
    obj_disable_rendering();
    o->OBJECT_FIELD_S32(0x21) = 0;
    gMarioShotFromCannon = 1;
}

void ActionOpenedCannon2(void)
{
    o->oAction = 3;
}

void ActionOpenedCannon3(void)
{
    UNUSED s32 unused;
    if(o->oTimer > 3)
        o->oAction = 0;
}

void (*TableOpenedCannonActions[])(void) =    {ActionOpenedCannon0,ActionOpenedCannon1,ActionOpenedCannon2,ActionOpenedCannon3,ActionOpenedCannon4,ActionOpenedCannon5,ActionOpenedCannon6};

u8 unused0EA1FC[] = {2,0,0,0,0,0,0,0,63,128,0,0,2,0,0,0,65,32,0,0,63,128,0,0,2,0,0,0,65,160,0,0,63,128,0,0,2,0,0,0,65,160,0,0,63,128,0,0,8,0,0,0,65,32,0,0,63,128,0,0};

void BehCannonBaseLoop(void)
{
    obj_call_action_function(TableOpenedCannonActions);
    if(o->OBJECT_FIELD_S32(0x1C))
        o->OBJECT_FIELD_S32(0x1C)++;
    o->oInteractStatus = 0;
}

void BehCannonBarrelLoop(void)
{
    struct Object* parent = o->parentObj;
    if(parent->header.gfx.node.flags & GRAPH_RENDER_01)
    {
        obj_enable_rendering();
        copy_object_pos(o,o->parentObj);
        o->oMoveAngleYaw = o->parentObj->oMoveAngleYaw;
        o->oFaceAnglePitch = o->parentObj->oMoveAnglePitch;
    }
    else
        obj_disable_rendering();
}

void func_802A8D18(f32 sp28,f32 sp2C,s32 sp30)
{
    switch(o->parentObj->oUnk88)
    {
    case 0:
        break;
    case 1:
        func_802A2008(gMarioObject,o);
        break;
    case 2:
        gMarioObject->oInteractStatus |= sp30+4;
        gMarioStates->forwardVel = sp28;
        gMarioStates->vel[1] = sp2C;
        o->parentObj->oUnk88 = 0;
        break;
    case 3:
        gMarioObject->oInteractStatus |= 0x44;
        gMarioStates->forwardVel = 10.0f;
        gMarioStates->vel[1] = 10.0f;
        o->parentObj->oUnk88 = 0;
        break;
    }
    o->oMoveAngleYaw = o->parentObj->oMoveAngleYaw;
    if(!o->parentObj->activeFlags)
        mark_object_for_deletion(o);
}

void BehChuckyaAnchorMarioLoop(void)
{
    func_802A8D18(40.0f,40.0f,64);
}

s32 Unknown802A8EC8(s32 sp20,f32 sp24,f32 sp28,s32 sp2C)
{
    s32 sp1C = 0;
    if(o->OBJECT_FIELD_S32(0x1C) != 4)
    {
        if(sp24 < obj_lateral_dist_from_mario_to_home())
        {
            if(obj_lateral_dist_to_home() < 200.0f)
                sp1C    = 0;
            else
            {
                sp1C = 1;
                o->oAngleToMario = obj_angle_to_home();
            }
        }
        else if(o->oDistanceToMario > sp28)
        {
            if(gGlobalTimer % (s16)sp2C == 0)
                o->oAngleToMario = angle_to_object(o,gMarioObject);
            sp1C = 2;
        }
        else
            sp1C = 3;
        if(sp20 && func_802C5A64(&o->oAngleToMario))
        {
            sp1C = 4;
            o->OBJECT_FIELD_S32(0x1C) = 4;
        }
    }
    else
        sp1C = 4;
    return sp1C;
}

s32 func_802A9050(f32* arr,f32 spC,f32 sp10)
{
    s32 sp4 = 0;
    if(arr[0] > spC)
    {
        arr[0] -= sp10;
        if(arr[0] < spC)
            arr[0] = spC;
    }
    else if(arr[0] < spC)
    {
        arr[0] += sp10;
        if(arr[0] > spC)
            arr[0] = spC;
    }
    else
        sp4 = 1;
    return sp4;
}

void ActionChuckya0(void)
{
    s32 sp3C;
    UNUSED u8 pad[16];
    s32 sp28;
    if(o->oTimer == 0)
        o->OBJECT_FIELD_S32(0x1D) = 0;
    o->oAngleToMario = angle_to_object(o,gMarioObject);
    switch(sp28 = o->oSubAction)
    {
    case 0:
        o->oForwardVel = 0;
        if(obj_lateral_dist_from_mario_to_home() < 2000.0f)
        {
            obj_rotate_yaw_toward(o->oAngleToMario,0x400);
            if(o->OBJECT_FIELD_S32(0x1D) > 40 || abs_angle_diff(o->oMoveAngleYaw,o->oAngleToMario) < 0x1000)
                o->oSubAction = 1;
        }
        else
            o->oSubAction = 3;
        break;
    case 1:
        func_802A9050(&o->oForwardVel,30.0f,4.0f);
        if(abs_angle_diff(o->oMoveAngleYaw,o->oAngleToMario) > 0x4000)
            o->oSubAction = 2;
        if(obj_lateral_dist_from_mario_to_home() > 2000.0f)
            o->oSubAction = 3;
        break;
    case 2:
        func_802A9050(&o->oForwardVel,0,4.0f);
        if(o->OBJECT_FIELD_S32(0x1D) > 48)
            o->oSubAction = 0;
        break;
    case 3:
        if(obj_lateral_dist_to_home() < 500.0f)
            o->oForwardVel = 0;
        else
        {
            func_802A9050(&o->oForwardVel,10.0f,4.0f);
            o->oAngleToMario = obj_angle_to_home();
            obj_rotate_yaw_toward(o->oAngleToMario,0x800);
        }
        if(obj_lateral_dist_from_mario_to_home() < 1900.0f)
            o->oSubAction = 0;
        break;
    }
    if(o->oSubAction != sp28)
        o->OBJECT_FIELD_S32(0x1D) = 0;
    else
        o->OBJECT_FIELD_S32(0x1D)++;
    func_8029ED38(4);
    if(o->oForwardVel > 1.0f)
        PlaySound(0x600A4001);
    print_debug_bottom_up("fg %d",sp3C);
    print_debug_bottom_up("sp %d",o->oForwardVel);
}

void ActionChuckya1(void)
{
    if(o->oSubAction == 0)
    {
        if(func_802A4AB0(0))
            o->oSubAction++;
        o->OBJECT_FIELD_S32(0x1D) = RandomFloat() * 30.0f + 10.0f;
        o->OBJECT_FIELD_S32(0x1E) = 0;
        o->oForwardVel = 0.0f;
    }
    else
    {
        if(o->oSubAction == 1)
        {
            o->OBJECT_FIELD_S32(0x1E) += player_performed_grab_escape_action();
            print_debug_bottom_up("%d",o->OBJECT_FIELD_S32(0x1E));
            if(o->OBJECT_FIELD_S32(0x1E) > 10)
            {
                o->oUnk88 = 3;
                o->oAction = 3;
                o->oInteractStatus &= ~0x800;
            }
            else
            {
                func_8029ED38(1);
                o->oMoveAngleYaw += 0x800;
                if(o->OBJECT_FIELD_S32(0x1D)-- < 0)
                    if(func_802B0C54(50.0f,150.0f) || o->OBJECT_FIELD_S32(0x1D) < -16)
                    {
                        o->oSubAction++;
                        ;
                    }
            }
        }
        else
        {
            func_8029ED38(3);
            if(obj_check_anim_frame(18))
            {
                PlaySound2(0x501EA081);
                o->oUnk88 = 2;
                o->oAction = 3;
                o->oInteractStatus &= ~0x800;
            }
        }
    }
}

void ActionChuckya3(void)
{
    o->oForwardVel = 0;
    o->oVelY = 0;
    func_8029ED38(4);
    if(o->oTimer > 100)
        o->oAction = 0;
}

void ActionChuckya2(void)
{
    if(o->oMoveFlags & (0x200 | 0x40 | 0x20 | 0x10 | 0x8 | 0x1))
    {
        mark_object_for_deletion(o);
        spawn_object_loot_yellow_coins(o,5,20.0f);
        func_802A3034(0x516E0081);
    }
}

void (*TableChuckyaActions[])(void) = {ActionChuckya0,ActionChuckya1,ActionChuckya2,ActionChuckya3};

extern u8 wf_seg7_collision_rotating_platform[];
extern u8 wdw_seg7_collision_070186B4[];
struct Struct8032F24A D_8032F24A[] = {{0,100,wf_seg7_collision_rotating_platform,2000},{0,150,wdw_seg7_collision_070186B4,1000}};
struct ObjectHitbox D_8032F260 = {2,0,0,1,0,80,50,0,0};
struct SpawnParticlesInfo D_8032F270 = {2,20,142,0,40,5,30,20,252,30,330.0f,10.0f};
struct ObjectHitbox D_8032F284 = {0x1000,0,0,0,0,80,50,0,0};
struct ObjectHitbox D_8032F294 = {16,0,1,0,0,100,64,0,0};
s16 D_8032F2A4[][2] = {{0,-150},{0,-50},{0,50},{0,150},{-50,100},{-100,50},{50,100},{100,50}};

void func_802A97B8(void)
{
    obj_update_floor_and_walls();
    obj_call_action_function(TableChuckyaActions);
    obj_move_standard(-30);
    if(o->oInteractStatus & 0x800)
    {
        o->oAction = 1;
        o->oUnk88 = 1;
        PlaySound2(0x501D8081);
    }
}

void BehChuckyaLoop(void)
{
    f32 sp2C = 20.0f;
    f32 sp28 = 50.0f;
    obj_scale(2.0f);
    o->oUnk190 |= 4;
    switch(o->oHeldState)
    {
    case HELD_FREE:        func_802A97B8();                        break;
    case HELD_HELD:        func_8029FA5C(2,0);                 break;
    case HELD_THROWN:
    case HELD_DROPPED: obj_get_thrown_or_placed(sp2C,sp28,2); break;
    }
    o->oInteractStatus = 0;
    print_debug_bottom_up("md %d",o->oAction);
}

void BehWFBreakableWallLoop(void)
{
    if(gMarioStates->action == ACT_SHOT_FROM_CANNON)
    {
        obj_become_tangible();
        if(are_objects_collided(o,gMarioObject))
        {
            if(obj_has_behavior(beh_wf_breakable_wall_right))
                func_80321228();
            create_sound_spawner(0x300F0081);
            o->oInteractType = 8;
            o->oDamageOrCoinValue = 1;
            func_802A3C98(80.0f,0);
        }
    }
    else
        obj_become_intangible();
}

s32 func_802A9A0C(UNUSED s32 sp18)
{
    if(are_objects_collided(o,gMarioObject))
    {
        if(abs_angle_diff(o->oMoveAngleYaw,gMarioObject->oMoveAngleYaw) > 0x6000)
        {
            if(gMarioStates->action == ACT_SLIDE_KICK)
                return 1;
             if(gMarioStates->action == ACT_PUNCHING)
                return 1;
             if(gMarioStates->action == ACT_MOVE_PUNCHING)
                return 1;
             if(gMarioStates->action == ACT_SLIDE_KICK_SLIDE)
                return 1;
             if(gMarioStates->action == ACT_JUMP_KICK)
                return 2;
             if(gMarioStates->action == ACT_WALL_KICK_AIR)
                return 2;
        }
    }
    return 0;
}

void func_802A9B54(void)
{
    o->OBJECT_FIELD_S32(0x1C) = 1600;
    o->OBJECT_FIELD_S32(0x1B) = 0;
}

void BehKickableBoardLoop(void)
{
    s32 sp24;
    switch(o->oAction)
    {
    case 0:
        o->oFaceAnglePitch = 0;
        if(func_802A9A0C(0))
        {
            func_802A9B54();
            o->oAction++;
        }
        load_object_collision_model();
        break;
    case 1:
        o->oFaceAnglePitch = 0;
        load_object_collision_model();
        o->oFaceAnglePitch = -sins(o->OBJECT_FIELD_S32(0x1B)) * o->OBJECT_FIELD_S32(0x1C);
        if(o->oTimer > 30 && (sp24 = func_802A9A0C(0)))
        {
            if(gMarioObject->oPosY > o->oPosY + 160.0f && sp24 == 2)
            {
                o->oAction++;
                PlaySound2(0x315A4081);
            }
            else
                o->oTimer = 0;
        }
        if(o->oTimer != 0)
        {
            o->OBJECT_FIELD_S32(0x1C) -= 8;
            if(o->OBJECT_FIELD_S32(0x1C) < 0)
                o->oAction = 0;
        }
        else
            func_802A9B54();
        if(!(o->OBJECT_FIELD_S32(0x1B) & 0x7FFF))
            PlaySound2(0x315A4081);
        o->OBJECT_FIELD_S32(0x1B) += 0x400;
        break;
    case 2:
        obj_become_intangible();
        obj_set_model(58);
        o->oAngleVelPitch -= 0x80;
        o->oFaceAnglePitch += o->oAngleVelPitch;
        if(o->oFaceAnglePitch < -0x4000)
        {
            o->oFaceAnglePitch = -0x4000;
            o->oAngleVelPitch = 0;
            o->oAction++;
            ShakeScreen(1);
            PlaySound2(0x303D8081);
        }
        load_object_collision_model();
        break;
    case 3:
        load_object_collision_model();
        break;
    }
    o->header.gfx.throwMatrix = NULL;
}

void BehTowerDoorLoop(void)
{
    if(o->oTimer == 0)
        o->oMoveAngleYaw -= 0x4000;
    if(func_802A9A0C(0))
    {
        func_802A3C98(80.0f,0);
        create_sound_spawner(0x300F0081);
    }
}

void BehWFRotatingWoodenPlatformLoop(void)
{
    if(o->oAction == 0)
    {
        o->oAngleVelYaw = 0;
        if(o->oTimer > 60)
        {
            o->oAction++;
            ; // needed to match
        }
    }
    else
    {
    o->oAngleVelYaw = 0x100;
    if(o->oTimer > 126)
        o->oAction = 0;
    PlaySound(0x40080001);
    }
    obj_rotate_face_angle_using_vel();
}

void BehRotatingPlatformLoop(void)
{
    s8 sp1F = o->oBehParams >> 24;
    if(o->oTimer == 0)
    {
        set_object_collision_data(o,D_8032F24A[o->oBehParams2ndByte].unk1);
        o->oCollisionDistance = D_8032F24A[o->oBehParams2ndByte].unk2;
        obj_scale(D_8032F24A[o->oBehParams2ndByte].unk0 * 0.01f);
    }
    o->oAngleVelYaw = sp1F << 4;
    o->oFaceAngleYaw += o->oAngleVelYaw;
}

void func_802AA0D4(void)
{
    set_object_hitbox(o,&D_8032F260);
}

void BehKoopaShellUnderwaterLoop(void)
{
    switch(o->oHeldState)
    {
    case HELD_FREE:
        func_802AA0D4();
        break;
    case HELD_HELD:
        func_8029FA5C(-1,0);
        break;
    case HELD_THROWN:
    case HELD_DROPPED:
        mark_object_for_deletion(o);
        func_802A3004();
        break;
    }
    if(o->oInteractStatus & 0x400000)
    {
        mark_object_for_deletion(o);
        func_802A3004();
    }
    o->oInteractStatus = 0;
}

void BehWarpLoop(void)
{
    u16 sp6;
    if(o->oTimer == 0)
    {
        sp6 = (o->oBehParams >> 24) & 0xFF;
        if(sp6 == 0)
            o->hitboxRadius = 50.0f;
        else if(sp6 == 0xFF)
            o->hitboxRadius = 10000.0f;
        else
            o->hitboxRadius = sp6 * 10.0;
        o->hitboxHeight = 50.0f;
    }
    o->oInteractStatus = 0;
}

void BehFadingWarpLoop() // identical to the above function
{
    u16 sp6;
    if(o->oTimer == 0)
    {
        sp6 = (o->oBehParams >> 24) & 0xFF;
        if(sp6 == 0)
            o->hitboxRadius = 85.0f;
        else if(sp6 == 0xFF)
            o->hitboxRadius = 10000.0f;
        else
            o->hitboxRadius = sp6 * 10.0;
        o->hitboxHeight = 50.0f;
    }
    o->oInteractStatus = 0;
}

void BehWhitePuffExplosingLoop(void)
{
    f32 sp24;
    if(o->oTimer == 0)
    {
        obj_compute_vel_xz();
        o->OBJECT_FIELD_F32(0x1B) = o->header.gfx.scale[0];
        switch(o->oBehParams2ndByte)
        {
        case 2:
            o->oOpacity = 254;
            o->OBJECT_FIELD_S32(0x1C) = -21;
            o->OBJECT_FIELD_S32(0x1D) = 0;
            break;
        case 3:
            o->oOpacity = 254;
            o->OBJECT_FIELD_S32(0x1C) = -13;
            o->OBJECT_FIELD_S32(0x1D) = 1;
            break;
        }
    }
    obj_move_using_vel_and_gravity();
    obj_apply_drag_xz(o->oDragStrength);
    if(o->oVelY > 100.0f)
        o->oVelY = 100.0f;
    if(o->oTimer > 20)
        mark_object_for_deletion(o);
    if(o->oOpacity)
    {
        o->oOpacity += o->OBJECT_FIELD_S32(0x1C);
        if(o->oOpacity < 2)
            mark_object_for_deletion(o);
        if(o->OBJECT_FIELD_S32(0x1D))
            sp24 = o->OBJECT_FIELD_F32(0x1B) * ((254 - o->oOpacity)/254.0);
        else
            sp24 = o->OBJECT_FIELD_F32(0x1B) * (o->oOpacity/254.0);
        obj_scale(sp24);
    }
}

void func_802AA618(s32 sp18,s32 sp1C,f32 sp20)
{
    D_8032F270.sizeBase = sp20;
    D_8032F270.sizeRange = sp20/20.0;
    D_8032F270.offsetY = sp1C;
    if(sp18 == 0)
        D_8032F270.count = 20;
    else if(sp18 > 20)
        D_8032F270.count = sp18;
    else
        D_8032F270.count = 4;
    obj_spawn_particles(&D_8032F270);
}

void BehUnused080CInit(void)
{
    s32 sp24;
    if(!(o->oUnk190 & 0x400))
        o->oBehParams = o->parentObj->oBehParams;
    sp24 =(o->oBehParams >> 24) & 0xFF;
    if(func_802A377C(sp24) & save_file_get_star_flags(gCurrSaveFileNum-1,gCurrCourseNum-1))
        obj_set_model(121);
    PlaySound2(0x8057FF91);
}

void func_802AA788(void)
{
    set_object_hitbox(o,&D_8032F284);
    if(o->oInteractStatus & 0x8000)
    {
        hide_object(o);
        o->oInteractStatus = 0;
    }
}

void func_802AA7EC(void)
{
    f32 sp1C;
    f32 sp18;
    o->oHomeX = gMarioObject->oPosX;
    o->oHomeZ = gMarioObject->oPosZ;
    o->oHomeY = gMarioObject->oPosY;
    o->oHomeY += 250.0f;
    o->oPosY = o->oHomeY;
    sp1C = o->oHomeX    - o->oPosX;
    sp18 = o->oHomeZ - o->oPosZ;
    o->oForwardVel = sqrtf(sp1C*sp1C+sp18*sp18)/23.0f;
}

void func_802AA8E4(void)
{
    o->oForwardVel = 0;
    o->oHomeY = o->oPosY;
}

void func_802AA918(void)
{
    if(o->oAngleVelYaw > 0x400)
        o->oAngleVelYaw -= 0x40;
}

void BehUnused080CLoop(void)
{
    if(o->oAction == 0)
    {
        if(o->oTimer == 0)
        {
            func_8028F9E8(173,o);
            set_time_stop_flag(10);
            o->activeFlags |= 0x20;
            o->oAngleVelYaw = 0x800;
            if(o->oBehParams2ndByte == 0)
                func_802AA7EC();
            else
                func_802AA8E4();
            o->oMoveAngleYaw = obj_angle_to_home();
            o->oVelY = 50.0f;
            o->oGravity = -4.0f;
            func_802A3004();
        }
        PlaySound(0x40140011);
        spawn_object(o,0,beh_powerup_sparkles2);
        if(o->oVelY < 0 && o->oPosY < o->oHomeY)
        {
            o->oAction++;
            o->oForwardVel = 0;
            o->oVelY = 20.0f;
            o->oGravity = -1.0f;
            if(o->oUnk190 & 0x400)
#ifndef VERSION_JP
                func_803212A0(1);
#else
                func_803212A0(0);
#endif
            else
                func_803212A0(1);
        }
    }
    else if(o->oAction == 1)
    {
        if(o->oVelY < -4.0f)
            o->oVelY = -4.0f;
        if(o->oVelY < 0 && o->oPosY < o->oHomeY)
        {
            D_8033B858 = 1;
            o->oVelY = 0;
            o->oGravity = 0;
            o->oAction++;
        }
        spawn_object(o,0,beh_powerup_sparkles2);
    }
    else if(o->oAction == 2)
    {
        if(D_8033B860->unk30 == 0 && D_8032CFF4 == 0)
        {
            clear_time_stop_flag(10);
            o->activeFlags &= ~0x20;
            o->oAction++;
        }
    }
    else
    {
        func_802AA788();
        func_802AA918();
    }
    obj_move_using_fvel_and_gravity();
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oInteractStatus = 0;
}

void func_802AACE4(u32 sp20)
{
    struct Object* sp1C = spawn_object(o,122,beh_unused_080C);
    sp1C->oBehParams = sp20 << 24;
    sp1C->oUnk190 = 0x400;
    set_object_angle(sp1C,0,0,0);
}

s32 func_802AAD54(void)
{
    if(o->oInteractStatus & 0x8000 && !(o->oInteractStatus & 0x800000))
    {
        spawn_object(o,149,beh_golden_coin_sparkles);
        mark_object_for_deletion(o);
        return 1;
    }
    o->oInteractStatus = 0;
    return 0;
}

void BehYellowCoinInit(void)
{
    obj_set_behavior(beh_yellow_coin);
    set_object_hitbox(o,&D_8032F294);
    bhv_init_room();
    obj_update_floor_height();
    if(500.0f < absf(o->oPosY - o->oFloorHeight))
        obj_set_model(117);
    if(o->oFloorHeight < -10000.0f)
        mark_object_for_deletion(o);
}

void BehYellowCoinLoop(void)
{
    func_802AAD54();
    o->oAnimState++;
}

void BehTempCoinLoop(void)
{
    o->oAnimState++;
    if(obj_wait_then_blink(200,20))
        mark_object_for_deletion(o);
    func_802AAD54();
}

void BehCoinInit(void)
{
    o->oVelY = RandomFloat() * 10.0f + 30 + o->OBJECT_FIELD_F32(0x22);
    o->oForwardVel = RandomFloat() * 10.0f;
    o->oMoveAngleYaw = RandomU16();
    obj_set_behavior(beh_yellow_coin);
    set_object_hitbox(o,&D_8032F294);
    obj_become_intangible();
}

void BehCoinLoop(void)
{
    struct Surface* sp1C;
    s16 sp1A;
    obj_update_floor_and_walls();
    obj_if_hit_wall_bounce_away();
    obj_move_standard(-62);
    if((sp1C = o->oFloor) != NULL)
    {
        if(o->oMoveFlags & 2)
            o->oSubAction = 1;
        if(o->oSubAction == 1)
        {
            o->oBounce = 0;
            if(sp1C->normal.y < 0.9)
            {
                sp1A = atan2s(sp1C->normal.z,sp1C->normal.x);
                obj_rotate_yaw_toward(sp1A,0x400);
            }
        }
    }
    if(o->oTimer == 0)
#ifndef VERSION_JP
        PlaySound2(0x38300081);
#else
        PlaySound2(0x30300081);
#endif
    if(o->oVelY < 0)
        obj_become_tangible();
    if(o->oMoveFlags & 1)
    {
#ifndef VERSION_JP
        if(o->oMoveFlags & 0x4800)
#else
        if(o->oMoveFlags & 0x800)	
#endif
            mark_object_for_deletion(o);
    }
#ifndef VERSION_JP
    if(o->oMoveFlags & 0x2000) {
	if(o->oUnk1B0 < 5)
            PlaySound2(0x30364081);
        o->oUnk1B0++;
    }
#else
    if(o->oMoveFlags & 0x2000)
        PlaySound2(0x30364081);
#endif
    if(obj_wait_then_blink(400,20))
        mark_object_for_deletion(o);
    func_802AAD54();
}

void BehCoinFormationSpawnLoop(void)
{
    if(o->oTimer == 0)
    {
        obj_set_behavior(beh_yellow_coin);
        set_object_hitbox(o,&D_8032F294);
        bhv_init_room();
        if(o->OBJECT_FIELD_S32(0x1C))
        {
            o->oPosY += 300.0f;
            obj_update_floor_height();
            if(o->oPosY < o->oFloorHeight || o->oFloorHeight < -10000.0f)
                mark_object_for_deletion(o);
            else
                o->oPosY = o->oFloorHeight;
        }
        else
        {
            obj_update_floor_height();
            if(absf(o->oPosY-o->oFloorHeight) > 250.0f)
                obj_set_model(117);
        }
    }
    else
    {
        if(func_802AAD54())
            o->parentObj->OBJECT_FIELD_S32(0x1B) |= func_802A377C(o->oBehParams2ndByte);
        o->oAnimState++;
    }
    if(o->parentObj->oAction == 2)
        mark_object_for_deletion(o);
}

void func_802AB364(s32 sp50,s32 sp54)
{
    struct Object* sp4C;
    Vec3i sp40;
    s32 sp3C = 1;
    s32 sp38 = 1;
    UNUSED s32 unused;
    sp40[2] = 0;
    sp40[0] = (sp40[1] = sp40[2]);
    switch(sp54 & 7)
    {
    case 0:
        sp40[2] = 160*(sp50 - 2);
        if(sp50 > 4)
            sp3C = 0;
        break;
    case 1:
        sp38 = 0;
        sp40[1] = 160*sp50*0.8; // 128 * sp50
        if(sp50 > 4)
            sp3C = 0;
        break;
    case 2:
        sp40[0] = sins(sp50 << 13) * 300.0f;
        sp40[2] = coss(sp50 << 13) * 300.0f;
        break;
    case 3:
        sp38 = 0;
        sp40[0] = coss(sp50 << 13) * 200.0f;
        sp40[1] = sins(sp50 << 13) * 200.0f + 200.0f;
        break;
    case 4:
        sp40[0] = D_8032F2A4[sp50][0];
        sp40[2] = D_8032F2A4[sp50][1];
        break;
    }
    if(sp54 & 0x10)
        sp38 = 0;
    if(sp3C)
    {
        sp4C = spawn_object_relative(sp50,sp40[0],sp40[1],sp40[2],o,116,beh_coin_formation_spawn);
        sp4C->OBJECT_FIELD_S32(0x1C) = sp38;
    }
}

void BehCoinFormationInit(void)
{
    o->OBJECT_FIELD_S32(0x1B) = (o->oBehParams >> 8) & 0xFF;
}

void BehCoinFormationLoop(void)
{
    s32 bitIndex;
    switch(o->oAction)
    {
    case 0:
        if(o->oDistanceToMario < 2000.0f)
        {
            for(bitIndex=0;bitIndex<8;bitIndex++)
            {
                if(!(o->OBJECT_FIELD_S32(0x1B) & (1 << bitIndex)))
                    func_802AB364(bitIndex,o->oBehParams2ndByte);
            }
            o->oAction++;
        }
        break;
    case 1:
        if(o->oDistanceToMario > 2100.0f)
            o->oAction++;
        break;
    case 2:
        o->oAction = 0;
        break;
    }
    func_8029C6D8(o,o->OBJECT_FIELD_S32(0x1B) & 0xFF); // Casting to u8 doesn't seem to match
}

void ActionCoinInsideBoo1(void)
{
    obj_update_floor_and_walls();
    obj_if_hit_wall_bounce_away();
    if(o->oMoveFlags & 0x2000)
        PlaySound2(0x30364081);
    if(o->oTimer > 90 || (o->oMoveFlags & 1))
    {
        set_object_hitbox(o,&D_8032F294);
        obj_become_tangible();
        obj_set_behavior(beh_yellow_coin);
    }
    obj_move_standard(-30);
    func_802AAD54();
    if(obj_has_model(118))
        o->oDamageOrCoinValue = 5;
    if(obj_wait_then_blink(400,20))
        mark_object_for_deletion(o);
}

void ActionCoinInsideBoo0(void)
{
    s16 sp26;
    f32 sp20;
    struct Object* parent = o->parentObj;
    obj_become_intangible();
    if(o->oTimer == 0 && gCurrLevelNum == LEVEL_BBH)
    {
        obj_set_model(118);
        obj_scale(0.7);
    }
    copy_object_pos(o,parent);
    if(parent->oUnk88 == 1)
    {
        o->oAction = 1;
        sp26 = gMarioObject->oMoveAngleYaw;
        sp20 = 3.0f;
        o->oVelX = sins(sp26) * sp20;
        o->oVelZ = coss(sp26) * sp20;
        o->oVelY = 35.0f;
    }
}

void (*TableCoinInsideBooActions[])(void) = {ActionCoinInsideBoo0,ActionCoinInsideBoo1};

s16 D_8032F2CC[] = {0xD000,0,0x3000,0,0xDE67,0x2199,0x2199,0x2199,0xDE67,0xDE67,0x2199,0xDE67};

s16 D_8032F2E4[] = {0xE000,0,0,0,0x2000,0,0xE99A,0x1666,0x1666,0x1666,0xE99A,0xE99A,0x1666,0xE99A};

s32 D_8032F300[][2] = {{0x40000,3},{0x80000,4},{0x10000,1},{0x20000,2},{-1,0}};

s32 D_8032F328[] = {0x3004C081,0x3006C081};

s32 D_8032F330[] = {0x3005C081,0x3007C081};

void BehCoinInsideBooLoop(void)
{
    obj_call_action_function(TableCoinInsideBooActions);
}

void BehCoinSparklesLoop(void)
{
    obj_scale(0.6f);
}

void BehGoldenCoinSparklesLoop(void)
{
    struct Object* sp2C;
    UNUSED s32 unused;
    f32 sp24 = 30.0f;
    sp2C = spawn_object(o,149,beh_coin_sparkles);
    sp2C->oPosX += RandomFloat() * sp24 - sp24/2;
    sp2C->oPosZ += RandomFloat() * sp24 - sp24/2;
}

void BehPunchTinyTriangleLoop(void)
{
    s16 sp1E;
    if(o->oTimer == 0)
    {
        sp1E = o->oMoveAngleYaw;
        o->OBJECT_FIELD_F32(0x1B) = 1.28f;
        obj_set_pos_relative(gMarioObject,0.0f,60.0f,100.0f);
        o->oMoveAngleYaw = sp1E; // does obj_set_pos_relative modify currentObject?
    }
    obj_move_using_fvel_and_gravity();
    o->oAnimState = 5;
    obj_scale(o->OBJECT_FIELD_F32(0x1B));
    o->OBJECT_FIELD_F32(0x1B) -= 0.2f;
    if(gDebugInfo[4][0] + 6 < o->oTimer)
        mark_object_for_deletion(o);
}

void BehPunchTinyTriangleInit(void)
{
    s32 i;
    UNUSED s32 unused;
    struct Object* triangle;
    for(i=0;i<6;i++)
    {
        triangle = spawn_object(o,138,beh_punch_tiny_triangle);
        triangle->oMoveAngleYaw = gMarioObject->oMoveAngleYaw + D_8032F2CC[2*i] + 0x8000;
        triangle->oVelY = sins(D_8032F2CC[2*i+1]) * 25.0f;
        triangle->oForwardVel = coss(D_8032F2CC[2*i+1]) * 25.0f;
    }
}

void BehWallTinyStarParticleLoop(void)
{
    s16 sp1E;
    if(o->oTimer == 0)
    {
        sp1E = o->oMoveAngleYaw;
        o->OBJECT_FIELD_F32(0x1B) = 0.28f;
        obj_set_pos_relative(gMarioObject,0.0f,30.0f,110.0f);
        o->oMoveAngleYaw = sp1E;
    }
    obj_move_using_fvel_and_gravity();
    o->oAnimState = 4;
    obj_scale(o->OBJECT_FIELD_F32(0x1B));
    o->OBJECT_FIELD_F32(0x1B) -= 0.015f;
}

void BehTinyStarParticlesInit(void)
{
    s32 i;
    UNUSED s32 unused;
    struct Object* particle;
    for(i=0;i<7;i++)
    {
        particle = spawn_object(o,139,beh_wall_tiny_star_particle);
        particle->oMoveAngleYaw = gMarioObject->oMoveAngleYaw + D_8032F2E4[2*i] + 0x8000;
        particle->oVelY = sins(D_8032F2E4[2*i+1]) * 25.0f;
        particle->oForwardVel = coss(D_8032F2E4[2*i+1]) * 25.0f;
    }
}

void BehPoundTinyStarParticleLoop(void)
{
    if(o->oTimer == 0)
    {
        o->OBJECT_FIELD_F32(0x1B) = 0.28f;
        o->oForwardVel = 25.0f;
        o->oPosY -= 20.0f;
        o->oVelY = 14.0f;
    }
    obj_move_using_fvel_and_gravity();
    o->oAnimState = 4;
    obj_scale(o->OBJECT_FIELD_F32(0x1B));
    o->OBJECT_FIELD_F32(0x1B) -= 0.015f;
}

void BehPoundTinyStarParticleInit(void)
{
    s32 sp24;
    s32 sp20 = 8;
    struct Object* particle;
    for(sp24=0;sp24<sp20;sp24++)
    {
        particle = spawn_object(o,139,beh_pound_tiny_star_particle);
        particle->oMoveAngleYaw = (sp24 << 16)/sp20;
    }
}

void func_802AC070(s32 sp18)
{
    func_8029ED38(sp18);
    if(func_8029F788())
        o->oAction = 0;
}

void func_802AC0B8(void)
{
    if(segmented_to_virtual(beh_door) == o->behavior)
        D_8033B1B0->unk1C[1] = 6;
    else
        D_8033B1B0->unk1C[1] = 5;
    D_8033B1B0->unk20 = o;
}

void func_802AC130(void)
{
    s32 sp1C = obj_has_model(31);
    if(o->oTimer == 0)
    {
        PlaySound2(D_8032F328[sp1C]);
        gTimeStopState |= 0x20;
    }
    if(o->oTimer == 70)
    {
        PlaySound2(D_8032F330[sp1C]);
    }
}

void func_802AC1CC(void)
{
    s32 sp1C = obj_has_model(31);
    if(o->oTimer == 30)
        PlaySound2(D_8032F330[sp1C]);
}

void BehDoorLoop(void)
{
    s32 sp1C = 0;
    while(D_8032F300[sp1C][0] != -1)
    {
        if(obj_clear_interact_status_flag(D_8032F300[sp1C][0]))
        {
            func_802AC0B8();
            obj_change_action(D_8032F300[sp1C][1]);
        }
        sp1C++;
    }
    switch(o->oAction)
    {
    case 0: func_8029ED38(0); break;
    case 1: func_802AC070(1); func_802AC130(); break;
    case 2: func_802AC070(2); func_802AC130(); break;
    case 3: func_802AC070(3); func_802AC1CC(); break;
    case 4: func_802AC070(4); func_802AC1CC(); break;
    }
    if(o->oAction == 0)
        load_object_collision_model();
    BehStarDoorLoop2();
}

void BehDoorInit(void)
{
    f32 sp24 = o->oPosX;
    f32 sp20 = o->oPosZ;
    struct Surface* sp1C;
    find_floor(sp24,o->oPosY,sp20,&sp1C);
    if(sp1C != NULL)
        o->OBJECT_FIELD_S32(0x1C) = sp1C->room;
    sp24 = o->oPosX + sins(o->oMoveAngleYaw) * 200.0f;
    sp20 = o->oPosZ + coss(o->oMoveAngleYaw) * 200.0f;
    find_floor(sp24,o->oPosY,sp20,&sp1C);
    if(sp1C != NULL)
        o->OBJECT_FIELD_S32(0x1D) = sp1C->room;
    sp24 = o->oPosX + sins(o->oMoveAngleYaw) * -200.0f;
    sp20 = o->oPosZ + coss(o->oMoveAngleYaw) * -200.0f;
    find_floor(sp24,o->oPosY,sp20,&sp1C);
    if(sp1C != NULL)
        o->OBJECT_FIELD_S32(0x1E) = sp1C->room;
    if(o->OBJECT_FIELD_S32(0x1C) > 0 && o->OBJECT_FIELD_S32(0x1C) < 60)
    {
        D_8035FE68[o->OBJECT_FIELD_S32(0x1C)][0] = o->OBJECT_FIELD_S32(0x1D);
        D_8035FE68[o->OBJECT_FIELD_S32(0x1C)][1] = o->OBJECT_FIELD_S32(0x1E);
    }
}

void BehStarDoorLoop2(void)
{
    s32 sp4 = 0;
    if(gMarioCurrentRoom != 0)
    {
        if(o->OBJECT_FIELD_S32(0x1C) == gMarioCurrentRoom)
            sp4 = 1;
        else if(gMarioCurrentRoom == o->OBJECT_FIELD_S32(0x1D))
            sp4 = 1;
        else if(gMarioCurrentRoom == o->OBJECT_FIELD_S32(0x1E))
            sp4 = 1;
        else if(D_8035FE68[gMarioCurrentRoom][0] == o->OBJECT_FIELD_S32(0x1D))
            sp4 = 1;
        else if(D_8035FE68[gMarioCurrentRoom][0] == o->OBJECT_FIELD_S32(0x1E))
            sp4 = 1;
        else if(D_8035FE68[gMarioCurrentRoom][1] == o->OBJECT_FIELD_S32(0x1D))
            sp4 = 1;
        else if(D_8035FE68[gMarioCurrentRoom][1] == o->OBJECT_FIELD_S32(0x1E))
            sp4 = 1;
    }
    else
        sp4 = 1;
    if(sp4 == 1)
    {
        o->header.gfx.node.flags |= 1;
        D_8035FEE4++;
    }
    if(sp4 == 0)
    {
        o->header.gfx.node.flags &= ~1;
    }
    o->oUnk88 = sp4;
}

void ActionGrindelThwomp4(void)
{
    if(o->oTimer == 0)
        o->OBJECT_FIELD_S32(0x1B) = RandomFloat() * 10.0f + 20.0f;
    if(o->oTimer > o->OBJECT_FIELD_S32(0x1B))
        o->oAction = 0;
}

void ActionGrindelThwomp2(void)
{
    o->oVelY += -4.0f;
    o->oPosY += o->oVelY;
    if(o->oPosY < o->oHomeY)
    {
        o->oPosY = o->oHomeY;
        o->oVelY = 0;
        o->oAction = 3;
    }
}

void ActionGrindelThwomp3(void)
{
    if(o->oTimer == 0)
        if(o->oDistanceToMario < 1500.0f)
        {
            ShakeScreen(1);
            PlaySound2(0x500CA081);
        }
    if(o->oTimer > 9)
        o->oAction = 4;
}

void ActionGrindelThwomp1(void)
{
    if(o->oTimer == 0)
        o->OBJECT_FIELD_S32(0x1B) = RandomFloat() * 30.0f + 10.0f;
    if(o->oTimer > o->OBJECT_FIELD_S32(0x1B))
        o->oAction = 2;
}

void ActionGrindelThwomp0(void)
{
    if(o->oBehParams2ndByte + 40 < o->oTimer)
    {
        o->oAction = 1;
        o->oPosY += 5.0f;
    }
    else
        o->oPosY += 10.0f;
}

void (*TableGrindelThwompActions[])(void) = {ActionGrindelThwomp0,ActionGrindelThwomp1,ActionGrindelThwomp2,ActionGrindelThwomp3,ActionGrindelThwomp4};

extern u8 wf_seg7_collision_tumbling_bridge[];
extern u8 bbh_seg7_collision_07026B1C[];
extern u8 lll_seg7_collision_0701D21C[];
extern u8 bitfs_seg7_collision_07015288[];
struct Struct8032F34C D_8032F34C[] = {{9,-512,0x80,0xB0,wf_seg7_collision_tumbling_bridge},{9,-412,103,56,bbh_seg7_collision_07026B1C},{9,-512,0x80,60,lll_seg7_collision_0701D21C},{9,-512,0x80,0x40,bitfs_seg7_collision_07015288}};

void BehGrindelThwompLoop(void)
{
    obj_call_action_function(TableGrindelThwompActions);
}

void BehTumblingBridgePlatformLoop(void)
{
    switch(o->oAction)
    {
    case 0:
        if(gMarioObject->platform == o)
        {
            o->oAction++;
            o->OBJECT_FIELD_S32(0x1B) = RandomSign() * 0x80;
        }
        break;
    case 1:
        obj_update_floor_height();
        if(o->oTimer > 5)
        {
            o->oAction++;
            PlaySound2(0x302D8081);
        }
        break;
    case 2:
        if(o->oAngleVelPitch < 0x400)
            o->oAngleVelPitch += 0x80;
        if(o->oAngleVelRoll > -0x400 && o->oAngleVelRoll < 0x400)
            o->oAngleVelRoll+=o->OBJECT_FIELD_S32(0x1B); // acceleraration?
        o->oGravity = -3.0f;
        obj_rotate_face_angle_using_vel();
        obj_move_using_fvel_and_gravity();
        if(o->oPosY < o->oFloorHeight - 300.0f)
            o->oAction++;
        break;
    case 3:
        break;
    }
    if(o->parentObj->oAction == 3)
        mark_object_for_deletion(o);
}

void ActionTumblingBridge1(void)
{
    struct Object* sp44;
    s32 sp40;
    s32 sp3C = o->oBehParams2ndByte;
    s32 sp38;
    s32 sp34;
    s32 sp30 = 0;
    s32 sp2C = 0;
    for(sp40=0;sp40 < D_8032F34C[sp3C].unk0 ;sp40++)
    {
        sp38 = 0;
        sp34 = 0;
        if(sp3C == 3)
            sp38 = D_8032F34C[sp3C].unk1 + D_8032F34C[sp3C].unk2 * sp40;
        else
            sp34 = D_8032F34C[sp3C].unk1 + D_8032F34C[sp3C].unk2 * sp40;
        if(obj_has_behavior(beh_tumbling_platform))
        {
            if(sp40 % 3 == 0)
                sp30 -= 150;
            sp2C = 450;
        }
        sp44 = spawn_object_relative(0,sp38,sp30+sp2C,sp34,o,D_8032F34C[sp3C].unk3,beh_tumbling_bridge_platform);
        set_object_collision_data(sp44,D_8032F34C[sp3C].unk4);
    }
    o->oAction = 2;
}

void ActionTumblingBridge2(void)
{
    obj_hide();
    if(obj_has_behavior(beh_tumbling_platform))
        obj_unhide();
    else if(o->oDistanceToMario > 1200.0f)
    {
        o->oAction = 3;
        obj_unhide();
    }
}

void ActionTumblingBridge3(void)
{
    obj_unhide();
    o->oAction = 0;
}

void ActionTumblingBridge0(void)
{
    if(obj_has_behavior(beh_tumbling_platform) || o->oDistanceToMario < 1000.0f)
        o->oAction = 1;
}

void (*TableTumblingBridgeActions[])(void) = {ActionTumblingBridge0,ActionTumblingBridge1,ActionTumblingBridge2,ActionTumblingBridge3};

s16 D_8032F38C[] = {-51,0,0,-461,0,0,-512,0,0,-2611,0,0,-2360,0,0,214,0,0,-50,1945,1,0};

void BehTumblingBridgeLoop(void)
{
    obj_call_action_function(TableTumblingBridgeActions);
}

void func_802AD01C(void)
{
    PlaySound2(0x30404081);
    ShakeScreen(1);
}

void ActionElevator0(void)
{
    o->oVelY = 0;
    if(o->OBJECT_FIELD_S32(0x1E) == 2)
    {
        if(gMarioObject->platform == o)
        {
            if(o->oPosY > o->OBJECT_FIELD_F32(0x1D))
                o->oAction = 2;
            else
                o->oAction = 1;
        }
    }
    else if(gMarioObject->oPosY > o->OBJECT_FIELD_F32(0x1D) || o->OBJECT_FIELD_S32(0x1E) == 1)
    {
        o->oPosY = o->OBJECT_FIELD_F32(0x1C);
        if(gMarioObject->platform == o)
            o->oAction = 2;
    }
    else
    {
        o->oPosY = o->OBJECT_FIELD_F32(0x1B);
        if(gMarioObject->platform == o)
            o->oAction = 1;
    }
}

void ActionElevator1(void)
{
    PlaySound(0x40020001);
    if(o->oTimer == 0 && obj_is_mario_on_platform())
        func_802AD01C();
    approach_f32_signed(&o->oVelY,10.0f,2.0f);
    o->oPosY+=o->oVelY;
    if(o->oPosY > o->OBJECT_FIELD_F32(0x1C))
    {
        o->oPosY=o->OBJECT_FIELD_F32(0x1C);
        if(o->OBJECT_FIELD_S32(0x1E) == 2 || o->OBJECT_FIELD_S32(0x1E) == 1)
            o->oAction = 3;
        else if(gMarioObject->oPosY < o->OBJECT_FIELD_F32(0x1D))
            o->oAction = 2;
        else
            o->oAction = 3;
    }
}

void ActionElevator2() // Pretty similar code to action 1
{
    PlaySound(0x40020001);
    if(o->oTimer == 0 && obj_is_mario_on_platform())
        func_802AD01C();
    approach_f32_signed(&o->oVelY,-10.0f,-2.0f);
    o->oPosY+=o->oVelY;
    if(o->oPosY < o->OBJECT_FIELD_F32(0x1B))
    {
        o->oPosY=o->OBJECT_FIELD_F32(0x1B);
        if(o->OBJECT_FIELD_S32(0x1E) == 1)
            o->oAction = 4;
        else if(o->OBJECT_FIELD_S32(0x1E) == 2)
            o->oAction = 3;
        else if(gMarioObject->oPosY > o->OBJECT_FIELD_F32(0x1D))
            o->oAction = 1;
        else
            o->oAction = 3;
    }
}

void ActionElevator4() { o->oVelY = 0; if(o->oTimer == 0)
    {
        ShakeScreen(1);
        PlaySound2(0x306B8081);
    }
    if(!mario_is_in_air_action() && !obj_is_mario_on_platform())
        o->oAction = 1;
}

void ActionElevator3() // nearly identical to action 2
{
    o->oVelY = 0;
    if(o->oTimer == 0)
    {
        ShakeScreen(1);
        PlaySound2(0x306B8081);
    }
    if(!mario_is_in_air_action() && !obj_is_mario_on_platform())
        o->oAction = 0;
}

void BehElevatorInit(void)
{
    s32 sp1C = D_8032F38C[o->oBehParams2ndByte*3+2];
    if(sp1C == 0)
    {
        o->OBJECT_FIELD_F32(0x1B) = D_8032F38C[o->oBehParams2ndByte*3];
        o->OBJECT_FIELD_F32(0x1C) = o->oHomeY;
        o->OBJECT_FIELD_F32(0x1D) = (o->OBJECT_FIELD_F32(0x1B) + o->OBJECT_FIELD_F32(0x1C))/2.0f;
        o->OBJECT_FIELD_S32(0x1E) = obj_has_behavior(beh_rr_elevator_platform);
    }
    else
    {
        o->OBJECT_FIELD_F32(0x1B) = D_8032F38C[o->oBehParams2ndByte*3];
        o->OBJECT_FIELD_F32(0x1C) = D_8032F38C[o->oBehParams2ndByte*3+1];
        o->OBJECT_FIELD_F32(0x1D) = (o->OBJECT_FIELD_F32(0x1B) + o->OBJECT_FIELD_F32(0x1C))/2.0f;
        o->OBJECT_FIELD_S32(0x1E) = 2;
    }
}

void (*TableElevatorActions[])(void) = {ActionElevator0,ActionElevator1,ActionElevator2,ActionElevator3,ActionElevator4};

struct SpawnParticlesInfo D_8032F3CC = {3,20,142,20,10,5,0,0,0,30,30.0f,1.5f};

struct SpawnParticlesInfo D_8032F3E0 = {0,5,159,0,0,20,20,0,252,30,5.0f,2.0f};

s16 D_8032F3F4[] = {2,-8,1,4};

struct SpawnParticlesInfo D_8032F3FC = {0,5,158,0,0,20,20,0,252,30,2.0f,2.0f};

void BehElevatorLoop(void)
{
    obj_call_action_function(TableElevatorActions);
}

void BehWaterMistSpawnLoop(void)
{
    func_802ADBBC(0x20000);
    spawn_object(o,142,beh_water_mist);
}

void BehWaterMistLoop(void)
{
    f32 sp1C;
    if(o->oTimer == 0)
    {
        o->oMoveAngleYaw = gMarioObject->oMoveAngleYaw;
        translate_object_xz_random(o,10.0f);
    }
    obj_move_using_fvel_and_gravity();
    o->oOpacity -= 42;
    sp1C = (254 - o->oOpacity)/254.0 * 1.0 + 0.5; // seen this before
    obj_scale(sp1C);
    if(o->oOpacity < 2)
        mark_object_for_deletion(o);
}

void func_802AD82C(s16 arg0,s16 arg1,f32 arg2,s16 arg3)
{
    struct Object* triangle;
    s32 i;
    for(i=0;i<arg0;i++)
    {
        triangle = spawn_object(o,arg1,beh_break_box_triangle);
        triangle->oAnimState = arg3;
        triangle->oPosY += 100.0f;
        triangle->oMoveAngleYaw = RandomU16();
        triangle->oFaceAngleYaw = triangle->oMoveAngleYaw;
        triangle->oFaceAnglePitch = RandomU16();
        triangle->oVelY = random_f32_around_zero(50.0f);
        if(arg1 == 138 || arg1 == 56)
        {
            triangle->oAngleVelPitch = 0xF00;
            triangle->oAngleVelYaw = 0x500;
            triangle->oForwardVel = 30.0f;
        }
        else
        {
            triangle->oAngleVelPitch = 0x80 * (s32)(RandomFloat() + 50.0f);
            triangle->oForwardVel = 30.0f;
        }
        scale_object(triangle,arg2);
    }
}

void BehWaterMist2Loop(void)
{
    o->oPosY = find_water_level(o->oHomeX,o->oHomeZ) + 20.0f;
    o->oPosX = o->oHomeX + random_f32_around_zero(150.0f);
    o->oPosZ = o->oHomeZ + random_f32_around_zero(150.0f);
    o->oOpacity = RandomFloat() * 50.0f + 200.0f;
}

void BehPoundWhitePuffsInit(void)
{
    func_802ADBBC(0x8000);
    func_802ADA94();
}

void func_802ADA94(void)
{
    obj_spawn_particles(&D_8032F3CC);
}

void BehUnused0E40Init(void)
{
    func_802ADBBC(0x4000);
    obj_spawn_particles(&D_8032F3E0);
}

void Unknown802ADAF4(void)
{
    struct Object* smoke = spawn_object_with_scale(o,150,beh_white_puff_smoke2,1.0f);
    smoke->oForwardVel = D_8032F3F4[0];
    smoke->oVelY = D_8032F3F4[1];
    smoke->oGravity = D_8032F3F4[2];
    translate_object_xyz_random(smoke,D_8032F3F4[3]);
}

//TODO Fix name
void func_802ADBBC(u32 flags)
{
    o->parentObj->oUnkE0 &= flags^-1; // Clear the flags given (could just be ~flags)
}

void BehGroundSnowInit(void)
{
    func_802ADBBC(1<<16);
    obj_spawn_particles(&D_8032F3FC);
}

void func_802ADC20(s16 pitch, s16 yaw)
{
    s32 i;
    for(i=0;i<3;i++)
    {
        struct Object* wind = spawn_object(o,142,beh_wind);
        wind->oMoveAngleYaw = yaw;
        wind->oMoveAnglePitch = pitch;
    }
}


void BehWindLoop(void)
{
    s16 sp2E = 500;
    f32 sp28 = 1.0f;
    if(o->oTimer == 0)
    {
        o->oOpacity = 100;
        if(o->oMoveAnglePitch == 0)
        {
            translate_object_xz_random(o,900.0f);
            o->oPosX += sins(o->oMoveAngleYaw + 0x8000) * sp2E; // NOP as Pitch is 0
            o->oPosY += 80.0f + random_f32_around_zero(200.0f);
            o->oPosZ += coss(o->oMoveAngleYaw + 0x8000) * sp2E; // -coss(a) * sp2E
            o->oMoveAngleYaw += random_f32_around_zero(4000.0f);
            o->oForwardVel = RandomFloat() * 70.0f + 50.0f;
        }
        else
        {
            translate_object_xz_random(o,600.0f);
            o->oPosY -= sp2E - 200; // 300
            o->oVelY = RandomFloat() * 30.0f + 50.0f;
            o->oMoveAngleYaw = RandomU16();
            o->oForwardVel = 10.0f;
        }
        func_802A1230(o);
        obj_scale(sp28);
    }
    if(o->oTimer > 8)
        mark_object_for_deletion(o);
    o->oFaceAnglePitch += 4000.0f + 2000.0f * RandomFloat();
    o->oFaceAngleYaw += 4000.0f + 2000.0f * RandomFloat();
    obj_move_using_fvel_and_gravity();
}

void BehPiranhaParticlesSpawnLoop(void)
{
    s32 i;
    obj_update_floor_and_walls();
    obj_move_standard(78);
    if(o->oMoveFlags & 2)
        mark_object_for_deletion(o);
    if(are_objects_collided(o,gMarioObject))
    {
        mark_object_for_deletion(o);
        for(i=0;i<10;i++)
            spawn_object(o,170,beh_giant_piranha_particle);
    }
}

void BehLittleCage2Loop(void)
{
    switch(o->oAction)
    {
    case 0:
        if(o->oTimer == 0)
            if(func_802A377C(1) & save_file_get_star_flags(gCurrSaveFileNum-1,gCurrCourseNum-1))
                obj_set_model(121);
        copy_object_pos(o,o->parentObj);
        copy_object_behavior_params(o,o->parentObj);
        if(o->parentObj->oAction == 3)
            o->oAction++;
        break;
    case 1:
        mark_object_for_deletion(o);
        func_802A3004();
        func_802AD82C(20,138,0.7,3);
        CreateStar(2500.0f,-1200.0f,1300.0f);
        break;
    }
    o->oFaceAngleYaw += 0x400;
}

void ActionLittleCage0(void)
{
    if(o->oUnk88 != 0)
        o->oAction = 1;
    load_object_collision_model();
}

void ActionLittleCage1(void)
{
    if(o->oUnk88 != 1)
        o->oAction = 2;
    o->oMoveAngleYaw += 0x800;
    load_object_collision_model();
}

void ActionLittleCage2(void)
{
    obj_update_floor_and_walls();
    obj_move_standard(78);
    if(o->oMoveFlags & (8 | 1))
        o->oAction = 3;
}

void ActionLittleCage3(void)
{
    obj_hide();
}

void (*TableLittleCageActions[])(void) = {ActionLittleCage0,ActionLittleCage1,ActionLittleCage2,ActionLittleCage3};

f32 D_8032F420[] = {1.9f,2.4f,4.0f,4.8f};

struct ObjectHitbox D_8032F430 = {0x8000,0,2,1,3,90,80,80,70};

struct ObjectHitbox D_8032F440 = {0,0,0,1,0,220,300,220,300};

struct ObjectHitbox D_8032F450 = {0x200,20,0,1,0,150,200,150,200};

s16 D_8032F460[][2] = {{30,0},{42,1},{52,0},{64,1},{74,0},{86,1},{96,0},{108,1},{118,0},{-1,0}};

void BehLittleCageLoop(void)
{
    obj_call_action_function(TableLittleCageActions);
}

void BehSquishablePlatformLoop(void)
{
    o->header.gfx.scale[1] = (sins(o->oPlatformTimer) + 1.0) * 0.3 + 0.4;
    o->oPlatformTimer += 0x80;
}

void BehBifsSinkingPlatformLoop(void)
{
    o->oPosY -= sins(o->oPlatformTimer) * 0.58; //! float double conversion error accumulates on Wii VC causing the platform to rise up
    o->oPlatformTimer += 0x100;
}

void BehDddMovingPoleLoop(void)
{
    copy_object_pos_and_angle(o,o->parentObj);
}

void BehBifsSinkingCagePlatformLoop(void)
{
    if(o->oBehParams2ndByte != 0)
    {
        if(o->oTimer == 0)
            o->oPosY -= 300.0f;
        o->oPosY += sins(o->oPlatformTimer) * 7.0f;
    }
    else
        o->oPosY -= sins(o->oPlatformTimer) * 3.0f;
    o->oPlatformTimer += 0x100;
}

void BehBetaMovingFlamesSpawnLoop(void)
{
    o->oDistanceToMario = lateral_dist_between_objects(o,gMarioObject);
    o->oPosY -= 100.0f;
    switch(o->oAction)
    {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        spawn_object(o,144,beh_beta_moving_flames);
        o->oAction++;
        break;
    case 8:
        break;
    case 9:
        o->oAction++;
        break;
    }
}

void BehBetaMovingFlamesLoop(void)
{
    obj_scale(5.0f);
    o->oForwardVel = sins(o->oMovingFlameTimer) * 70.0f;
    o->oMovingFlameTimer += 0x800;
}

void BehFlamethrowerFlameLoop(void)
{
    f32 size;
    s32 sp18;
    if(o->oTimer == 0)
    {
        o->oAnimState = (s32)(RandomFloat() * 10.0f);
        translate_object_xyz_random(o,10.0f);
    }
    if(o->oBehParams2ndByte == 2)
        size = o->oTimer * (o->oForwardVel - 6.0f)/100.0 + 2.0;
    else
        size = o->oTimer * (o->oForwardVel - 20.0)/100.0 + 1.0;
    if(o->oBehParams2ndByte == 3)
    {
        o->hitboxHeight = 200.0f;
        o->hitboxDownOffset = 150.0f;
        o->oVelY = -28.0f;
        obj_update_floor_height();
        if(o->oPosY - 25.0f * size < o->oFloorHeight)
        {
            o->oVelY = 0;
            o->oPosY = o->oFloorHeight + 25.0f * size;
        }
        sp18 = o->parentObj->oFlameThowerFlameUnk110/1.2;
    }
    else
        sp18 = o->parentObj->oFlameThowerFlameUnk110;
    obj_scale(size);
    if(o->oBehParams2ndByte == 4)
        o->oPosY += o->oForwardVel; // weird?
    else
        obj_move_using_fvel_and_gravity();
    if(o->oTimer > sp18)
        mark_object_for_deletion(o);
    o->oInteractStatus = 0;
}

void BehFlamethrowerLoop(void)
{
    struct Object* flame;
    f32 flameVel;
    s32 sp34;
    s32 sp30;
    UNUSED u8 pad[8];
    if(o->oAction == 0)
    {
        if(gCurrLevelNum != LEVEL_BBH || D_8035FEF4 == 1)
            if(o->oDistanceToMario < 2000.0f)
                o->oAction++;
    }
    else if(o->oAction == 1)
    {
        sp30 = 144;
        flameVel = 95.0f;
        if(o->oBehParams2ndByte == 1)
            sp30 = 145;
        if(o->oBehParams2ndByte == 2)
            flameVel = 50.0f;
        sp34 = 1;
        if(o->oTimer < 60)
            sp34 = 15;
        else if(o->oTimer < 74)
            sp34 = 75 - o->oTimer; // Range: [15..2]
        else
            o->oAction++;
        o->oFlameThowerUnk110 = sp34;
        flame = spawn_object_relative(o->oBehParams2ndByte,0,0,0,o,sp30,beh_flamethrower_flame);
        flame->oForwardVel = flameVel;
        PlaySound(0x60048001);
    }
    else if(o->oTimer > 60)
        o->oAction = 0;
}

void BehRRRotatingBridgePlatformLoop(void)
{
    o->oMoveAngleYaw -= 0x80;
    o->oAngleVelYaw = -0x80;
    BehFlamethrowerLoop();
}

void BehBouncingFireballFlameLoop(void)
{
    o->activeFlags |= 0x400;
    obj_update_floor_and_walls();
    switch(o->oAction)
    {
    case 0:
        if(o->oTimer == 0)
        {
            o->oAnimState = RandomFloat() * 10.0f;
            o->oVelY = 30.0f;
        }
        if(o->oMoveFlags & 1)
            o->oAction++;
        break;
    case 1:
        if(o->oTimer == 0)
        {
            o->oVelY = 50.0f;
            o->oForwardVel = 30.0f;
        }
        if(o->oMoveFlags & (0x40 | 0x10 | 0x2) && o->oTimer > 100)
            mark_object_for_deletion(o);
        break;
    }
    if(o->oTimer > 300)
        mark_object_for_deletion(o);
    obj_move_standard(78);
    o->oInteractStatus = 0;
}

void BehBouncingFireballLoop(void)
{
    struct Object* sp2C;
    f32 sp28;
    switch(o->oAction)
    {
    case 0:
        if(o->oDistanceToMario < 2000.0f)
            o->oAction = 1;
        break;
    case 1:
        sp2C = spawn_object(o,144,beh_bouncing_fireball_flame);
        sp28 = (10 - o->oTimer) * 0.5;
        scale_object_xyz(sp2C,sp28,sp28,sp28);
        if(o->oTimer == 0)
            make_object_tangible(sp2C);
        if(o->oTimer > 10)
            o->oAction++;
        break;
    case 2:
        if(o->oTimer == 0)
            o->oBouncingFireBallUnkF4 = RandomFloat() * 100.0f;
        if(o->oBouncingFireBallUnkF4 + 100 < o->oTimer)
            o->oAction = 0;
        break;
    }
}

void BehBowserShockWave(void)
{
    f32 sp2C,sp28,sp24,sp20;
    s16 sp1E = 70;
    o->oBowserShockWaveUnkF4 = o->oTimer * 10;
    obj_scale(o->oBowserShockWaveUnkF4);
    if(gGlobalTimer % 3)
        o->oOpacity -= 1;
    if(o->oTimer > sp1E)
        o->oOpacity -= 5;
    if(o->oOpacity <= 0)
        mark_object_for_deletion(o);
    if(o->oTimer < sp1E && mario_is_in_air_action() == 0)
    {
        sp2C = o->oBowserShockWaveUnkF4 * D_8032F420[0];
        sp28 = o->oBowserShockWaveUnkF4 * D_8032F420[1];
        sp24 = o->oBowserShockWaveUnkF4 * D_8032F420[2];
        sp20 = o->oBowserShockWaveUnkF4 * D_8032F420[3];
        if((sp2C < o->oDistanceToMario && o->oDistanceToMario < sp28) || (sp24 < o->oDistanceToMario && o->oDistanceToMario < sp20))
            gMarioObject->oInteractStatus |= 0x10;
    }
}

void BehBlackSmokeUpwardLoop(void)
{
    spawn_object_with_scale(o,148,beh_black_smoke_bowser,o->header.gfx.scale[0]);
}

void BehBlackSmokeBowserLoop(void)
{
    if(o->oTimer == 0)
    {
        o->oForwardVel = RandomFloat() * 2.0f + 0.5;
        o->oMoveAngleYaw = RandomU16();
        o->oVelY = 8.0f;
        o->oBlackSmokeBowserUnkF4 = o->header.gfx.scale[0];
    }
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY += o->oVelY;
}

void BehBlackSmokeMarioLoop(void)
{
    if(o->oTimer == 0)
    {
        obj_set_pos_relative(gMarioObject,0,0,-30.0f);
        o->oForwardVel = RandomFloat() * 2.0f + 0.5;
        o->oMoveAngleYaw = (gMarioObject->oMoveAngleYaw + 0x7000) + RandomFloat() * 8192.0f;
        o->oVelY = 8.0f;
    }
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY += o->oVelY;
}

void BehFlameMarioLoop(void)
{
    obj_scale(2.0f);
    if(o->oTimer != 0)
        if(o->oTimer&1)
            spawn_object(o,148,beh_black_smoke_mario);
    gMarioObject->prevObj = o; // weird?
    set_object_parent_relative_pos(o,40,-120,0);
    if(!(gMarioObject->oMarioParticleFlags & 0x800))
    {
        o->parentObj->oUnkE0 &= ~0x800;
        mark_object_for_deletion(o);
        gMarioObject->prevObj = NULL;
    }
}

void BehMultipleCoinsLoop(void)
{
    UNUSED u8 pad[12];
    UNUSED f32 unused = find_water_level(o->oPosX,o->oPosZ);
}

void BehSpindriftLoop(void)
{
    o->activeFlags |= 0x400;
    if(obj_set_hitbox_and_die_if_attacked(&D_8032F430,0x50244081,0))
        obj_change_action(1);
    obj_update_floor_and_walls();
    switch(o->oAction)
    {
    case 0:
        func_802A9050(&o->oForwardVel,4.0f,1.0f);
        if(obj_lateral_dist_from_mario_to_home() > 1000.0f)
            o->oAngleToMario = obj_angle_to_home();
        else if(o->oDistanceToMario > 300.0f)
            o->oAngleToMario = angle_to_object(o,gMarioObject);
        obj_rotate_yaw_toward(o->oAngleToMario,0x400);
        break;
    case 1:
        o->oFlags &= ~8;
        o->oForwardVel = -10.0f;
        if(o->oTimer > 20)
        {
            o->oAction = 0;
            o->oInteractStatus = 0;
            o->oFlags |= 8;
        }
        break;
    }
    obj_move_standard(-60);
}

void BehWFSolidTowerPlatformLoop(void)
{
    if(o->parentObj->oAction==3)
        mark_object_for_deletion(o);
}

void BehWFElevatorTowerPlatformLoop(void)
{
    switch(o->oAction)
    {
    case 0:
        if(gMarioObject->platform == o)
            o->oAction++;
        break;
    case 1:
        PlaySound(0x40020001);
        if(o->oTimer > 140)
            o->oAction++;
        else
            o->oPosY += 5.0f;
        break;
    case 2:
        if(o->oTimer > 60)
            o->oAction++;
        break;
    case 3:
        PlaySound(0x40020001);
        if(o->oTimer > 140)
            o->oAction = 0;
        else
            o->oPosY -= 5.0f;
        break;
    }
    if(o->parentObj->oAction == 3)
        mark_object_for_deletion(o);
}

void BehWFSlidingTowerPlatformLoop(void)
{
    s32 sp24 = o->oPlatformUnk110/o->oPlatformUnk10C;
    switch(o->oAction)
    {
    case 0:
        if(o->oTimer > sp24)
            o->oAction++;
        o->oForwardVel = -o->oPlatformUnk10C;
        break;
    case 1:
        if(o->oTimer > sp24)
            o->oAction = 0;
        o->oForwardVel = o->oPlatformUnk10C;
        break;
    }
    obj_compute_vel_xz();
    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    if(o->parentObj->oAction == 3)
        mark_object_for_deletion(o);
}

void func_802AF9A4(s16 a,u32* beh)
{
    s16 yaw;
    struct Object* platform = spawn_object(o,a,beh);
    yaw = o->oPlatformSpawnerUnkF4 * o->oPlatformSpawnerUnkFC + o->oPlatformSpawnerUnkF8;
    platform->oMoveAngleYaw = yaw;
    platform->oPosX += o->oPlatformSpawnerUnk100 * sins(yaw);
    platform->oPosY += 100 * o->oPlatformSpawnerUnkF4;
    platform->oPosZ += o->oPlatformSpawnerUnk100 * coss(yaw);
    platform->oPlatformUnk110 = o->oPlatformSpawnerUnk104;
    platform->oPlatformUnk10C = o->oPlatformSpawnerUnk108;
    o->oPlatformSpawnerUnkF4++;
}

void func_802AFAFC(void)
{
    UNUSED s32 unused = 8;
    o->oPlatformSpawnerUnkF4 = 0;
    o->oPlatformSpawnerUnkF8 = 0;
    o->oPlatformSpawnerUnkFC = 0x2000;
    o->oPlatformSpawnerUnk100 = 704.0f;
    o->oPlatformSpawnerUnk104 = 380.0f;
    o->oPlatformSpawnerUnk108 = 3.0f;
    func_802AF9A4(45,beh_wf_solid_tower_platform);
    func_802AF9A4(45,beh_wf_sliding_tower_platform);
    func_802AF9A4(45,beh_wf_solid_tower_platform);
    func_802AF9A4(45,beh_wf_sliding_tower_platform);
    func_802AF9A4(45,beh_wf_solid_tower_platform);
    func_802AF9A4(45,beh_wf_sliding_tower_platform);
    func_802AF9A4(45,beh_wf_solid_tower_platform);
    func_802AF9A4(47,beh_wf_elevator_tower_platform);
}

void BehTowerPlatformGroupLoop(void)
{
    f32 marioY = gMarioObject->oPosY;
    o->oDistanceToMario = dist_between_objects(o,gMarioObject);
    switch(o->oAction)
    {
    case 0:
        if(marioY > o->oHomeY-1000.0f)
            o->oAction++;
        break;
    case 1:
        func_802AFAFC();
        o->oAction++;
        break;
    case 2:
        if(marioY < o->oHomeY-1000.0f)
            o->oAction++;
        break;
    case 3:
        o->oAction = 0;
        break;
    }
}

void BehTreeSnowOrLeafLoop(void)
{
    obj_update_floor_height();
    if(o->oTimer == 0)
    {
        o->oAngleVelPitch = (RandomFloat() - 0.5) * 0x1000;
        o->oAngleVelRoll = (RandomFloat() - 0.5) * 0x1000;
        o->oTreeSnowOrLeafUnkF8 = 4;
        o->oTreeSnowOrLeafUnkFC = RandomFloat() * 0x400 + 0x600;
    }
    if(o->oPosY < o->oFloorHeight)
        mark_object_for_deletion(o);
    if(o->oFloorHeight < -11000.0f)
        mark_object_for_deletion(o);
    if(o->oTimer > 100)
        mark_object_for_deletion(o);
    if(gPostUpdateObjCount > 212)
        mark_object_for_deletion(o);
    o->oFaceAnglePitch += o->oAngleVelPitch;
    o->oFaceAngleRoll += o->oAngleVelRoll;
    o->oVelY += -3.0f;
    if(o->oVelY < -8.0f)
        o->oVelY = -8.0f;
    if(o->oForwardVel > 0)
        o->oForwardVel -= 0.3;
    else
        o->oForwardVel = 0;
    o->oPosX += sins(o->oMoveAngleYaw) * sins(o->oTreeSnowOrLeafUnkF4) * o->oTreeSnowOrLeafUnkF8;
    o->oPosZ += coss(o->oMoveAngleYaw) * sins(o->oTreeSnowOrLeafUnkF4) * o->oTreeSnowOrLeafUnkF8;
    o->oTreeSnowOrLeafUnkF4 += o->oTreeSnowOrLeafUnkFC;
    o->oPosY += o->oVelY;
}

void BehSnowLeafParticleSpawnInit(void)
{
    struct Object* obj; // Either snow or leaf
    UNUSED s32 unused;
    s32 isSnow;
    f32 scale;
    UNUSED s32 unused2;
    gMarioObject->oUnkE0 &= ~0x2000;
    if(gCurrLevelNum == LEVEL_CCM || gCurrLevelNum == LEVEL_SL)
        isSnow = 1;
    else
        isSnow = 0;
    if(isSnow)
    {
        if(RandomFloat() < 0.5)
        {
            obj = spawn_object(o,158,beh_tree_snow);
            scale = RandomFloat();
            scale_object_xyz(obj,scale,scale,scale);
            obj->oMoveAngleYaw = RandomU16();
            obj->oForwardVel = RandomFloat() * 5.0f;
            obj->oVelY = RandomFloat() * 15.0f;
        }
    }
    else
    {
        if(RandomFloat() < 0.3)
        {
            obj = spawn_object(o,162,beh_tree_leaf);
            scale = RandomFloat() * 3.0f;
            scale_object_xyz(obj,scale,scale,scale);
            obj->oMoveAngleYaw = RandomU16();
            obj->oForwardVel = RandomFloat() * 5.0f + 5.0f;
            obj->oVelY = RandomFloat() * 15.0f;
            obj->oFaceAnglePitch = RandomU16();
            obj->oFaceAngleRoll = RandomU16();
            obj->oFaceAngleYaw = RandomU16();
        }
    }
}

s32 func_802B02FC(u16 yaw,s32 a)
{
    o->oMoveAngleYaw = yaw;
    if(a < o->oTimer)
        return 1;
    else
        return 0;
}

void BehSquarishPathMovingLoop(void)
{
    o->oForwardVel = 10.0f;
    switch(o->oAction)
    {
    case 0:
        o->oAction = (o->oBehParams2ndByte&3)+1;
        break;
    case 1:
        if(func_802B02FC(0,60))
            o->oAction++;
        break;
    case 2:
        if(func_802B02FC(0x4000,60))
            o->oAction++;
        break;
    case 3:
        if(func_802B02FC(0x8000,60))
            o->oAction++;
        break;
    case 4:
        if(func_802B02FC(0xc000,60))
            o->oAction = 1;
        break;
    default:
        break;
    }
    obj_move_using_fvel_and_gravity();
    load_object_collision_model();
}

void BehPiranhaPlantWakingBubblesLoop(void)
{
    if(o->oTimer == 0)
    {
        o->oVelY = RandomFloat() * 10.0f + 5.0f;
        o->oForwardVel = RandomFloat() * 10.0f + 5.0f;
        o->oMoveAngleYaw = RandomU16();
    }
    obj_move_using_fvel_and_gravity();
}

void BehPiranhaPlantBubbleLoop(void)
{
    struct Object* parent = o->parentObj;
    f32 scale = 0;
    s32 i;
    s32 sp40 = parent->header.gfx.unk38.animFrame;
    s32 sp3C = parent->header.gfx.unk38.curAnim->unk08 - 2;
    s32 UNUSED unused;
    f32 sp34;
    f32 sp30;
    obj_set_pos_relative(parent,0,72.0f,180.0f);
    switch(o->oAction)
    {
    case 0:
        obj_disable_rendering();
        scale = 0;
        if(parent->oAction == 1)
            o->oAction++;
        break;
    case 1:
        if(parent->oDistanceToMario < parent->oDrawingDistance)
        {
            obj_enable_rendering();
            if(parent->oAction == 1)
            {
                sp34 = sp3C/2.0f - 4.0f;
                sp30 = sp3C/2.0f + 4.0f;
                if(sp40 < sp34)
                    scale = coss(sp40/sp34 * 0x4000) * 4.0f + 1.0;
                else if(sp40 > sp30)
                    scale = sins((sp40 - (sp3C/2.0f + 4.0f))/sp30 * 0x4000) * 4.0f + 1.0;
                else
                    scale = 1.0f;
            }
            else
                o->oAction++;
        }
        else
            obj_disable_rendering();
        break;
    case 2:
        obj_disable_rendering();
        scale = 0;
        for(i=0;i<15;i++)
            try_to_spawn_object(0,1.0f,o,168,beh_piranha_plant_waking_bubbles);
        o->oAction = 0;
        scale = 1.0f;
        break;
    }
    obj_scale(scale);
}

void BehFloorSwitchLoop(void)
{
    UNUSED s32 unused;
    switch(o->oAction)
    {
    case 0:
        obj_set_model(207);
        obj_scale(1.5f);
        if(gMarioObject->platform == o && !(gMarioStates->action & 0x2000))
            if(lateral_dist_between_objects(o,gMarioObject) < 127.5)
                o->oAction = 1;
        break;
    case 1:
        func_802A3398(2,3,1.5f,0.2f);
        if(o->oTimer == 3)
        {
            PlaySound2(0x803EC081);
            o->oAction = 2;
            ShakeScreen(1);
        }
        break;
    case 2:
        if(o->oBehParams2ndByte != 0)
        {
            if(o->oBehParams2ndByte == 1 && gMarioObject->platform != o)
                o->oAction++;
            else
            {
                if(o->oTimer < 360)
                    SetSound(0x8054F011,D_803320E0);
                else
                    SetSound(0x8055F011,D_803320E0);
                if(o->oTimer > 400)
                    o->oAction = 4;
            }
        }
        break;
    case 3:
        func_802A3398(2,3,0.2f,1.5f);
        if(o->oTimer == 3)
            o->oAction = 0;
        break;
    case 4:
        if(!obj_is_mario_on_platform())
            o->oAction = 3;
        break;
    }
}

s32 func_802B0C54(f32 a0,f32 a1)
{
    struct Surface* sp24;
    f32 sp20 = o->oPosX + sins(o->oMoveAngleYaw) * a1;
    f32 floorHeight;
    f32 sp18 = o->oPosZ + coss(o->oMoveAngleYaw) * a1;
    floorHeight = find_floor(sp20,o->oPosY,sp18,&sp24);
    if(absf(floorHeight - o->oPosY) < a0) // abs
        return 1;
    else
        return 0;
}

void BehPushableLoop(void)
{
    UNUSED s16 unused;
    s16 sp1C;
    set_object_hitbox(o,&D_8032F440);
    o->oForwardVel = 0.0f;
    if(are_objects_collided(o,gMarioObject) && gMarioStates->flags & 0x80000000)
    {
        sp1C = angle_to_object(o,gMarioObject);
        if(abs_angle_diff(sp1C,gMarioObject->oMoveAngleYaw) > 0x4000)
        {
            o->oMoveAngleYaw = (s16)((gMarioObject->oMoveAngleYaw + 0x2000) & 0xc000);
            if(func_802B0C54(8.0f,150.0f))
            {
                o->oForwardVel = 4.0f;
                PlaySound(0x40178001);
            }
        }
    }
    obj_move_using_fvel_and_gravity();
}

void func_802B0E74(void)
{
    o->oUnknownUnkF4_S32 = 0;
    o->oAnimState = 1;
    switch(o->oBehParams2ndByte)
    {
    case 0:
        o->oNumLootCoins = 0;
        break;
    case 1:
        o->oNumLootCoins = 3;
        break;
    case 2:
        o->oNumLootCoins = 5;
        break;
    case 3:
        obj_scale(1.5f);
        break;
    }
}


void func_802B0F54(void)
{
    struct Object* sp1C;
    set_object_hitbox(o,&D_8032F450);
    obj_set_model(130);
    if(o->oAction == 0)
    {
        obj_disable_rendering();
        obj_become_intangible();
        if(o->oTimer == 0)
            func_802B0E74();
        if(o->oUnknownUnkF4_S32 == 0)
            o->oHiddenObjectUnkF4 = obj_nearest_object_with_behavior(beh_floor_switch_hidden_objects);
        if((sp1C = o->oHiddenObjectUnkF4) != NULL)
            if(sp1C->oAction == 2)
            {
                o->oAction++;
                obj_enable_rendering();
                obj_unhide();
            }
    }
    else if(o->oAction == 1)
    {
        obj_become_tangible();
        if(obj_wait_then_blink(360,20))
            o->oAction = 0;
        if(obj_was_attacked_or_ground_pounded())
        {
            func_802A3004();
            func_802AD82C(30,138,3.0f,4);
            o->oAction++;
            PlaySound2(0x3041c081);
        }
        load_object_collision_model();
    }
    else
    {
        obj_become_intangible();
        obj_disable_rendering();
        o->oInteractStatus = 0;
        if((sp1C = o->oHiddenObjectUnkF4) != NULL)
            if(sp1C->oAction == 0)
                o->oAction = 0;
    }
}

void func_802B1138(void)
{
    struct Object* sp1C;
    set_object_collision_data(o,wdw_seg7_collision_07018528);
    if(o->oAction == 0)
    {
        obj_disable_rendering();
        obj_become_intangible();
        if(o->oHiddenObjectUnkF4 == NULL)
            o->oHiddenObjectUnkF4 = obj_nearest_object_with_behavior(beh_floor_switch_hidden_objects);
        if((sp1C = o->oHiddenObjectUnkF4) != NULL)
            if(sp1C->oAction == 2)
            {
                o->oAction++;
                obj_enable_rendering();
                obj_unhide();
            }
    }
    else
    {
        obj_become_tangible();
        if(obj_wait_then_blink(360,20))
            o->oAction = 0;
        load_object_collision_model();
    }
}

void BehHiddenObjectLoop(void)
{
    if(o->oBehParams2ndByte == 0)
        func_802B0F54(); // Confused, that function has code depending on the action
    else
        func_802B1138();
}

void BehBreakableBoxLoop(void)
{
    set_object_hitbox(o,&D_8032F450);
    obj_set_model(130);
    if(o->oTimer == 0)
        func_802B0E74();
    if(obj_was_attacked_or_ground_pounded() != 0)
    {
        func_802A3C98(46.0f,1);
        create_sound_spawner(0x3041C081);
    }
}

s32 Geo18_802B1BB0(s32 a0,UNUSED s32 a1, Mat4 a2)
{
    Mat4 sp20;
    struct Object* sp1C;
    if(a0 == 1)
    {
        sp1C = (struct Object*)D_8032CFA0;
        if(sp1C == gMarioObject && sp1C->prevObj != NULL)
        {
            func_8029D704(sp20,a2,D_8032CF9C->unk34);
            func_8029D558(sp20,sp1C->prevObj);
            func_8029EA0C(sp1C->prevObj);
        }
    }
    return 0;
}

void BehHeaveHoThrowMarioLoop(void)
{
    o->oParentRelativePosX = 200.0f;
    o->oParentRelativePosY = -50.0f;
    o->oParentRelativePosZ = 0.0f;
    o->oMoveAngleYaw = o->parentObj->oMoveAngleYaw;
    switch(o->parentObj->oUnk88)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        PlaySound2(0x505D4081);
        gMarioObject->oInteractStatus |= 4;
        gMarioStates->forwardVel = -45.0f;
        gMarioStates->vel[1] = 95.0f;
        o->parentObj->oUnk88 = 0;
        break;
    }
}

void ActionHeaveHo1(void)
{
    s32 sp1C=0;
    o->oForwardVel = 0.0f;
    func_8029F6F0();
    while(1)
    {
        if(D_8032F460[sp1C][0] == -1)
        {
            o->oAction = 2;
            break;
        }
        if(o->oTimer < D_8032F460[sp1C][0])
        {
            func_8029ED98(2,D_8032F460[sp1C][1]);
            break;
        }
        sp1C++;
    }
}

void ActionHeaveHo2(void)
{
    UNUSED s32 unused;
    s16 angleVel;
    if(1000.0f < obj_lateral_dist_from_mario_to_home())
        o->oAngleToMario = obj_angle_to_home();
    if(o->oTimer > 150)
    {
        o->oHeaveHoUnkF4 = (302 - o->oTimer)/152.0f;
        if(o->oHeaveHoUnkF4 < 0.1)
        {
            o->oHeaveHoUnkF4 = 0.1;
            o->oAction = 1;
        }
    }
    else
        o->oHeaveHoUnkF4 = 1.0f;
    func_8029ED98(0,o->oHeaveHoUnkF4);
    o->oForwardVel = o->oHeaveHoUnkF4 * 10.0f;
    angleVel = o->oHeaveHoUnkF4 * 0x400;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw,o->oAngleToMario,angleVel);
}

void ActionHeaveHo3(void)
{
    o->oForwardVel = 0.0f;
    if(o->oTimer == 0)
        o->oUnk88 = 2;
    if(o->oTimer == 1)
    {
        func_8029ED98(1,1.0f);
        o->numCollidedObjs = 20;
    }
    if(func_8029F788())
        o->oAction = 1;
}

void ActionHeaveHo0(void)
{
    obj_set_pos_to_home();
    if(find_water_level(o->oPosX,o->oPosZ) < o->oPosY && o->oDistanceToMario < 4000.0f)
    {
        obj_become_tangible();
        obj_unhide();
        o->oAction = 1;
    }
    else
    {
        obj_become_intangible();
        obj_hide();
    }
}

void (*TableHeaveHoActions[])(void) = {ActionHeaveHo0,ActionHeaveHo1,ActionHeaveHo2,ActionHeaveHo3};
struct ObjectHitbox D_8032F498 = {2,20,0,1,5,150,250,150,250};

void func_802B18B4(void)
{
    obj_update_floor_and_walls();
    obj_call_action_function(TableHeaveHoActions);
    obj_move_standard(-78);
    if(o->oMoveFlags & (0x40 | 0x20 | 0x10 | 0x8))
        o->oGraphYOffset = -15.0f;
    else
        o->oGraphYOffset = 0.0f;
    if(o->oForwardVel > 3.0f)
        PlaySound(0x60064001);
    if(o->oAction != 0 && o->oMoveFlags & (0x40 | 0x20 | 0x10 | 0x8))
        o->oAction = 0;
    if(o->oInteractStatus & 0x800)
    {
        o->oInteractStatus = 0;
        o->oUnk88 = 1;
        o->oAction = 3;
    }
}

void BehHeaveHoLoop(void)
{
    obj_scale(2.0f);
    switch(o->oHeldState)
    {
    case HELD_FREE:        func_802B18B4();        break;
    case HELD_HELD:        func_8029FA5C(0,0); break;
    case HELD_THROWN:    obj_get_dropped();        break;
    case HELD_DROPPED: obj_get_dropped();        break;
    }
    o->oInteractStatus = 0;
}

void BehCcmTouchedStarSpawnLoop(void)
{
    if(D_8035FEEC & 1)
    {
        o->oPosY += 100.0f;
        o->oPosX = 2780.0f;
        o->oPosZ = 4666.0f;
        CreateStar(2500.0f,-4350.0f,5750.0f);
        mark_object_for_deletion(o);
    }
}

void BehPoundExplodesLoop(void)
{
    obj_scale(1.02f);
    if(o->oAction == 0)
    {
        if(obj_is_mario_ground_pounding_platform())
        {
            func_802A3004();
            func_802AD82C(20,56,3.0f,0);
            o->oAction++;
        }
    }
    else if(o->oTimer > 7)
        mark_object_for_deletion(o);
    load_object_collision_model();
}

void BehBetaTrampolineSpawnLoop(void)
{
    f32 yScale;
    f32 yDisplacement;
    copy_object_pos_and_angle(o,o->parentObj);
    func_8029E94C(o,o->parentObj);
    o->oPosY -= 75.0f;
    if((yDisplacement = o->oPosY - o->oHomeY) >= 0)
        yScale = yDisplacement/10.0 + 1.0;
    else
    {
        yDisplacement = -yDisplacement;
        yScale = 1.0 - yDisplacement/500.0;
    }
    scale_object_xyz(o,1.0f,yScale,1.0f);
}

void BehBetaTrampolineLoop(void)
{
    struct Object* sp1C;
    obj_set_model(181);
    if(o->oTimer == 0)
    {
        sp1C = spawn_object(o,182,beh_beta_trampoline_spawn);
        sp1C->oPosY -= 75.0f;
        sp1C = spawn_object(o,183,beh_static_object);
        sp1C->oPosY -= 150.0f;
    }
    if(gMarioObject->platform == o)
        o->oBetaTrampolineUnk110 = 1;
    else
    {
        o->oBetaTrampolineUnk110 = 0;
        o->oPosY = o->oHomeY;
    }
    nop_80254E50();
}

void ActionJumpingBox0(void)
{
    if(o->oSubAction == 0)
    {
        if(o->oJumpingBoxUnkF8-- < 0)
            o->oSubAction++;
        if(o->oTimer > o->oJumpingBoxUnkF4)
        {
            o->oVelY = RandomFloat() * 5.0f + 15.0f;
            o->oSubAction++;
        }
    }
    else if(o->oMoveFlags & 2)
    {
        o->oSubAction = 0;
        o->oJumpingBoxUnkF8 = RandomFloat() * 60.0f + 30.0f;
    }
}

void ActionJumpingBox1(void)
{
    if(o->oMoveFlags & (0x200 | 0x40 | 0x20 | 0x10 | 0x8 | 0x1))
    {
        mark_object_for_deletion(o);
        func_802A3004();
    }
}

void (*TableJumpingBoxActions[])(void) = {ActionJumpingBox0,ActionJumpingBox1};
struct ObjectHitbox D_8032F4B0 = {0x8000000,0,0,0,0,120,300,0,0};

void func_802B1F84(void)
{
    obj_set_model(129);
    obj_scale(0.5f);
    set_object_hitbox(o,&D_8032F498);
    obj_update_floor_and_walls();
    obj_move_standard(78);
    obj_call_action_function(TableJumpingBoxActions);
}

void BehJumpingBoxLoop(void)
{
    switch(o->oHeldState)
    {
    case HELD_FREE:
        func_802B1F84();
        break;
    case HELD_HELD:
        copy_object_pos(o,gMarioObject);
        obj_set_model(130);
        func_8029FA5C(-1,0);
        break;
    case HELD_THROWN:
        obj_get_thrown_or_placed(40.0f,20.0f,1);
        break;
    case HELD_DROPPED:
        obj_get_dropped();
        o->oAction = 1;
        break;
    }
    if(o->oInteractStatus & 0x400000)
    {
        create_sound_spawner(0x3041C081);
        func_802A3C98(46.0f,1);
    }
    o->oInteractStatus = 0;
}

void BehBooCageLoop(void)
{
    UNUSED s32 unused;
    set_object_hitbox(o,&D_8032F4B0);
    switch(o->oAction)
    {
    case 0:
        obj_become_intangible();
        obj_scale(1.0f);
        if(o->parentObj->oUnk88 != 0)
        {
            o->oAction++;
            o->oVelY = 60.0f;
            func_80321228();
        }
        else
            copy_object_pos_and_angle(o,o->parentObj);
        break;
    case 1:
        o->oFaceAnglePitch = 0;
        o->oFaceAngleRoll = 0;
        obj_update_floor_and_walls();
        obj_move_standard(-78);
        spawn_object(o,0,beh_powerup_sparkles2);
        if(o->oMoveFlags & 1)
            PlaySound2(0x305E0081);
        if(o->oMoveFlags & (0x40 | 0x10 | 0x2))
            o->oAction++;
        break;
    case 2:
        obj_become_tangible();
        obj_scale(1.0f);
        if(are_objects_collided(o,gMarioObject))
            o->oAction++;
        break;
    case 3:
        if(o->oTimer > 100)
            o->oAction++;
        break;
    case 4:
        break;
    }
}

void func_802B2328(s32 n,s32 a1,s32 a2,s32 r) // n is the number of objects to spawn, r if the rate of change of phase (frequency?)
{
    s32 i;
    s16 seperation = 0x10000/n; // Evenly spread around a circle
    for(i=0;i<n;i++)
        spawn_object_relative(0,
                                    sins(D_8035FF10+i*seperation)*a1,
                                    (i+1)*a2,
                                    coss(D_8035FF10+i*seperation)*a1,
                                    o,0,beh_powerup_sparkles2);

    D_8035FF10 += r*0x100;
}

void BehBetaBooKeyOutsideLoop(void)
{
    o->oFaceAngleRoll += 0x200;
    o->oFaceAngleYaw    += 0x200;
    if(are_objects_collided(o,gMarioObject))
    {
        o->parentObj->oUnk88 = 1;
        mark_object_for_deletion(o);
        spawn_object(o,149,beh_golden_coin_sparkles);
    }
}

void ActionBetaBooKeyInside2(void)
{
    obj_update_floor_and_walls();
    obj_move_standard(78);
    if(o->oGraphYOffset < 26.0f)
        o->oGraphYOffset += 2.0f;
    if(o->oFaceAngleRoll & 0xFFFF) // is it not a full rotation
    {
        o->oFaceAngleRoll &= 0xF800;
        o->oFaceAngleRoll += 0x800;
    }
    if(o->oMoveFlags & 2)
    {
        o->oVelX = 0.0f;
        o->oVelZ = 0.0f;
    }
    o->oFaceAngleYaw += 0x800;
    if(o->oTimer > 90 || o->oMoveFlags & 1)
    {
        obj_become_tangible();
        if(are_objects_collided(o,gMarioObject))
        {
            o->parentObj->oInteractStatus = 1;
            mark_object_for_deletion(o);
            spawn_object(o,149,beh_golden_coin_sparkles);
        }
    }
}

void ActionBetaBooKeyInside1(void)
{
    s16 sp26;
    f32 sp20;
    struct Object* parent = o->parentObj;
    copy_object_pos(o,parent);
    if(o->oTimer == 0)
    {
        o->parentObj = parent->parentObj;
        o->oAction = 2;
        sp26 = gMarioObject->oMoveAngleYaw;
        sp20 = 3.0f;
        o->oVelX = sins(sp26) * sp20;
        o->oVelZ = coss(sp26) * sp20;
        o->oVelY = 40.0f;
    }
    o->oFaceAngleYaw    += 0x200;
    o->oFaceAngleRoll += 0x200;
}

void ActionBetaBooKeyInside0(void)
{
    struct Object* parent = o->parentObj;
    copy_object_pos(o,parent);
    o->oPosY += 40.0f;
    if(parent->oUnk88 != 0)
        o->oAction = 1;
    o->oFaceAngleRoll += 0x200;
    o->oFaceAngleYaw    += 0x200;
}

void (*TableBetaBooKeyInsideActions[])(void) = {ActionBetaBooKeyInside0,ActionBetaBooKeyInside1,ActionBetaBooKeyInside2};
struct ObjectHitbox D_8032F4CC = {0x1000,0,0,0,0,160,100,160,100};

void BehBetaBooKeyInsideLoop(void)
{
    obj_call_action_function(TableBetaBooKeyInsideActions);
}

s32 func_802B2894(Vec3f a0,Vec3f a1,f32 yVel,f32 gravity)
{
    f32 dx = a0[0] - a1[0];
    f32 dz = a0[2] - a1[2];
    f32 planarDist = sqrtf(dx*dx + dz*dz);
    s32 time;
    o->oMoveAngleYaw = atan2s(dz,dx);
    o->oVelY = yVel;
    o->oGravity = gravity;
    time = -2.0f/o->oGravity * yVel - 1.0f;
    o->oForwardVel = planarDist/time;
    return time;
}

void func_802B29B0(void)
{
    o->oGravity        = 0.0f;
    o->oVelY             = 0.0f;
    o->oForwardVel = 0.0f;
}

void BehGrandStarLoop(void)
{
    UNUSED s32 unused;
    Vec3f sp28;
    sp28[0] = sp28[1] = sp28[2] = 0.0f;
    if(o->oAction == 0)
    {
        if(o->oTimer == 0)
        {
            set_object_angle(o,0,0,0);
            o->oAngleVelYaw = 0x400;
            PlaySound2(0x8057FF91);
        }
        if(o->oTimer > 70)
            o->oAction++;
        func_802B2328(3,200,80,-60);
    }
    else if(o->oAction == 1)
    {
        if(o->oTimer == 0)
        {
            PlaySound2(0x30730081);
            func_8028F9E8(173,o);
            o->oGrandStarUnk108 = func_802B2894(sp28,&o->oPosX,80.0f,-2.0f);
        }
        obj_move_using_fvel_and_gravity();
        if(o->oSubAction == 0)
        {
            if(o->oPosY < o->oHomeY)
            {
                o->oPosY = o->oHomeY;
                o->oVelY = 60.0f;
                o->oForwardVel = 0.0f;
                o->oSubAction++;
                PlaySound2(0x30740081);
            }
        }
        else if(o->oVelY < 0.0f && o->oPosY < o->oHomeY + 200.0f)
        {
            o->oPosY = o->oHomeY + 200.0f;
            func_802B29B0();
            D_8033B858 = 1;
            set_mario_npc_dialogue(0);
            o->oAction++;
            o->oInteractStatus = 0;
            PlaySound2(0x30740081);
        }
        func_802B2328(3,200,80,-60);
    }
    else
    {
        obj_become_tangible();
        if(o->oInteractStatus & 0x8000)
        {
            mark_object_for_deletion(o);
            o->oInteractStatus = 0;
        }
    }
    if(o->oAngleVelYaw > 0x400)
        o->oAngleVelYaw -= 0x100;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    obj_scale(2.0f);
    o->oGraphYOffset = 110.0f;
}

void BehBowserKey2Loop(void)
{
    obj_scale(0.5f);
    if(o->oAngleVelYaw > 0x400)
        o->oAngleVelYaw -= 0x100;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oFaceAngleRoll = -0x4000;
    o->oGraphYOffset = 165.0f;
    if(o->oAction == 0)
    {
        if(o->oTimer == 0)
            o->oVelY = 70.0f;
        func_802B2328(3,200,80,-60);
        spawn_object(o,0,beh_powerup_sparkles2);
        obj_update_floor_and_walls();
        obj_move_standard(78);
        if(o->oMoveFlags & 2)
            o->oAction++;
        else if(o->oMoveFlags & 1)
#ifndef VERSION_JP
            PlaySound2(0x38378081);
#else
            PlaySound2(0x30370081);	
#endif
    }
    else
    {
        set_object_hitbox(o,&D_8032F4CC);
        if(o->oInteractStatus & 0x8000)
        {
            hide_object(o);
            o->oInteractStatus = 0;
        }
    }
}

void BehWhitePuffSmokeInit(void)
{
    obj_scale(RandomFloat()*2.0f + 2.0);
}

void BehBulletBillInit(void)
{
    o->oBulletBillUnkF8 = o->oMoveAngleYaw;
}

void ActionBulletBill0(void)
{
    obj_become_tangible();
    o->oForwardVel = 0.0f;
    o->oMoveAngleYaw = o->oBulletBillUnkF8;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
    o->oMoveFlags = 0;
    obj_set_pos_to_home();
    o->oAction = 1;
}

void ActionBulletBill1(void)
{
    s16 sp1E = abs_angle_diff(o->oAngleToMario,o->oMoveAngleYaw);
    if(sp1E < 0x2000 && 400.0f < o->oDistanceToMario && o->oDistanceToMario < 1500.0f)
        o->oAction = 2;
}

void ActionBulletBill2(void)
{
    if(o->oTimer < 40)
        o->oForwardVel = 3.0f;
    else if(o->oTimer < 50)
    {
        if(o->oTimer % 2)
            o->oForwardVel = 3.0f;
        else
            o->oForwardVel = -3.0f;
    }
    else
    {
        if(o->oTimer > 70)
            obj_update_floor_and_walls();
        spawn_object(o,150,beh_white_puff_smoke);
        o->oForwardVel = 30.0f;
        if(o->oDistanceToMario > 300.0f)
            obj_rotate_yaw_toward(o->oAngleToMario,0x100);
        if(o->oTimer == 50)
        {
            PlaySound2(0x501A5081);
            ShakeScreen(1);
        }
        if(o->oTimer > 150 || o->oMoveFlags & 0x200)
        {
            o->oAction = 3;
            func_802A3004();
        }
    }
}

void ActionBulletBill3(void)
{
    o->oAction = 0;
}

void ActionBulletBill4(void)
{
    if(o->oTimer == 0)
    {
        o->oForwardVel = -30.0f;
        obj_become_intangible();
    }
    o->oFaceAnglePitch += 0x1000;
    o->oFaceAngleRoll += 0x1000;
    o->oPosY += 20.0f;
    if(o->oTimer > 90)
        o->oAction = 0;
}

void (*TableBulletBillActions[])(void) = {ActionBulletBill0,ActionBulletBill1,ActionBulletBill2,ActionBulletBill3,ActionBulletBill4};

void BehBulletBillLoop(void)
{
    obj_call_action_function(TableBulletBillActions);
    if(obj_check_interacted())
        o->oAction = 4;
}

void ActionBowserTailAnchor0(void)
{
    struct Object* bowser = o->parentObj;
    obj_become_tangible();
    obj_scale(1.0f);
    if(bowser->oAction == 19)
        bowser->oIntangibleTimer = -1;
    else if(are_objects_collided(o,gMarioObject))
    {
        bowser->oIntangibleTimer = 0;
        o->oAction = 2;
    }
    else
        bowser->oIntangibleTimer = -1;
}

void ActionBowserTailAnchor1(void)
{
    if(o->oTimer > 30)
        o->oAction = 0;
}

void ActionBowserTailAnchor2(void)
{
    if(o->parentObj->oAction == 19)
    {
        o->parentObj->oIntangibleTimer = -1;
        o->oAction = 0;
    }
    obj_become_intangible();
}

void (*TableBowserTailAnchorActions[])(void) = {ActionBowserTailAnchor0,ActionBowserTailAnchor1,ActionBowserTailAnchor2};
s8 D_8032F4FC[] = {7,8,9,12,13,14,15,4,3,16,17,19,3,3,3,3};
s16 D_8032F50C[] = {60,0};
s16 D_8032F510[] = {50,0};
s8 D_8032F514[] = {24,42,60,-1};
s16 D_8032F518[][3] = {{119,120,121},{0,1,10},{40,0,0},{74,-1,-10},{114,1,-20},{134,-1,20},{154,1,40},{164,-1,-40},{174,1,-80},{179,-1,80},{184,1,160},{186,-1,-160},{186,1,0}}; // probably wrong. the first three should be separate from the rest

void BehBowserTailAnchorLoop(void)
{
    obj_call_action_function(TableBowserTailAnchorActions);
    o->oParentRelativePosX = 90.0f;
    if(o->parentObj->oAction == 4)
        o->parentObj->oIntangibleTimer = -1;
    o->oInteractStatus = 0;
}

void BehBowserFlameSpawnLoop(void)
{
    struct Object* bowser = o->parentObj;
    s32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24 = coss(bowser->oMoveAngleYaw);
    f32 sp20 = sins(bowser->oMoveAngleYaw);
    s16 *sp1C = segmented_to_virtual(bowser_seg6_unkmoveshorts_060576FC);
    if(bowser->oSoundStateID == 6)
    {
        sp30 = bowser->header.gfx.unk38.animFrame + 1.0f;
        if(bowser->header.gfx.unk38.curAnim->unk08 == sp30)
            sp30 = 0;
        if(sp30 > 45 && sp30 < 85)
        {
            PlaySound(0x60000001);
            sp2C = sp1C[5*sp30];
            sp28 = sp1C[5*sp30+2];
            o->oPosX = bowser->oPosX + (sp28 * sp20 + sp2C * sp24);
            o->oPosY = bowser->oPosY + sp1C[5*sp30+1];
            o->oPosZ = bowser->oPosZ + (sp28 * sp24 - sp2C * sp20);
            o->oMoveAnglePitch = sp1C[5*sp30+4] + 0xC00;
            o->oMoveAngleYaw = sp1C[5*sp30+3] + (s16)bowser->oMoveAngleYaw;
            if(!(sp30 & 1))
                spawn_object(o,144,beh_flame_moving_forward_growing);
        }
    }
}

void BehBowserBodyAnchorLoop(void)
{
    copy_object_pos_and_angle(o,o->parentObj);
    if(o->parentObj->oAction == 4) {
#ifdef VERSION_US
        if(o->parentObj->oSubAction == 11)
            o->oInteractType = 0;
        else
	    o->oInteractType = 0x800000;    
#else
        o->oInteractType = 0x800000;
#endif
    }
    else
    {
        o->oInteractType = 8;
        if(o->parentObj->oOpacity < 100)
            obj_become_intangible();
        else
            obj_become_tangible();
    }
    if(o->parentObj->oHeldState != HELD_FREE)
        obj_become_intangible();
    o->oInteractStatus = 0;
}

s32 func_802B38B4(void)
{
    struct Object* wave;
    if(o->oBehParams2ndByte == 2)
    {
        wave = spawn_object(o,104,beh_bowser_shock_wave);
        wave->oPosY = o->oFloorHeight;
        return 1;
    }
    return 0;
}

void func_802B392C(s32* a)
{
    if(o->oMoveFlags & 1)
    {
        a[0]++;
        if(a[0] < 4)
        {
            func_802A11B4(o,8);
            func_802AA618(0,0,60.0f);
            PlaySound2(0x50030081);
        }
    }
}

#define BITDW (o->oBehParams2ndByte==0)
#define BITFS (o->oBehParams2ndByte==1)
#define BITS    (o->oBehParams2ndByte==2)

s32 func_802B39B8(void)
{
    func_8029ED38(15);
    if(obj_check_anim_frame(21))
        o->oForwardVel = 3.0f;
    if(func_8029F788())
        return 1;
    else
        return 0;
}

s32 func_802B3A30(void)
{
    o->oForwardVel = 3.0f;
    func_8029ED38(13);
    if(func_8029F788())
        return 1;
    else
        return 0;
}

s32 func_802B3A98(void)
{
    func_8029ED38(14);
    if(obj_check_anim_frame(20))
        o->oForwardVel = 0.0f;
    if(func_8029F788())
        return 1;
    else
        return 0;
}

void func_802B3B0C(void)
{
    if(o->oUnk88 == 0)
        o->oAction = 5;
    else if(o->oUnk88 == 1)
        o->oAction = 6;
    else if(o->oBehParams2ndByte == 1)
        o->oAction = 13;
    else
        o->oAction = 0;
}

void ActionBowser5() // not much
{
    o->oForwardVel = 0.0f;
    func_8029ED38(12);
    func_802B3B0C();
}

void ActionBowser6(void)
{
    if(o->oSubAction == 0)
    {
        if(func_802B39B8())
            o->oSubAction++;
    }
    else if(o->oSubAction == 1)
    {
        if(func_802B3A30())
            o->oSubAction++;
    }
    else if(func_802B3A98())
    {
        if(o->oUnk88 == 1)
            o->oUnk88 = 0;
        func_802B3B0C();
    }
}

void Unknown802B3CCC(void) // unused
{
    if(gDebugInfo[5][1] != 0)
    {
        o->oAction = D_8032F4FC[gDebugInfo[5][2] & 0xf];
        gDebugInfo[5][1] = 0;
    }
}

void func_802B3D24(void)
{
    f32 rand = RandomFloat();
    if(o->oBowserUnk110 == 0)
    {
        if(o->oBowserUnkF4 & 2)
        {
            if(o->oDistanceToMario < 1500.0f)
                o->oAction = 15; // nearby
            else
                o->oAction = 17; // far away
        }
        else
            o->oAction = 14;
        o->oBowserUnk110++;
    }
    else
    {
        o->oBowserUnk110 = 0;
#ifndef VERSION_JP
        if(!gCurrDemoInput) {
            if(rand < 0.1)
                o->oAction = 3; // rare 1/10 chance
            else
                o->oAction = 14; // common
        } else {
            o->oAction = 14; // ensure demo starts with action 14.
        }
#else
        if(rand < 0.1)
            o->oAction = 3; // rare 1/10 chance
        else
            o->oAction = 14; // common
#endif
    }
}

void func_802B3E44(void)
{
    f32 rand = RandomFloat();
    if(o->oBowserUnk110 == 0)
    {
        if(o->oBowserUnkF4 & 2)
        {
            if(o->oDistanceToMario < 1300.0f) // nearby
            {
                if(rand < 0.5) // 50/50
                    o->oAction = 16;
                else
                    o->oAction = 9;
            }
            else // far away
            {
                o->oAction = 7;
                if(500.0f < o->oBowserDistToCentre && o->oBowserDistToCentre < 1500.0f && rand < 0.5) // away from centre and good luck
                    o->oAction = 13;
            }
        }
        else
            o->oAction = 14;
        o->oBowserUnk110++;
    }
    else
    {
        o->oBowserUnk110 = 0;
        o->oAction = 14;
    }
}

void func_802B3FDC(void)
{
    f32 rand = RandomFloat();
    if(o->oBowserUnkF4 & 2)
    {
        if(o->oDistanceToMario < 1000.0f)
        {
            if(rand < 0.4)
                o->oAction = 9;
            else if(rand < 0.8)
                o->oAction = 8;
            else
                o->oAction = 15;
        }
        else if(rand < 0.5)
            o->oAction = 13;
        else
            o->oAction = 7;
    }
    else
        o->oAction = 14;
}

void func_802B4124(void)
{
    o->oAction = 13;
}

void func_802B4144(void)
{
    switch(o->oBowserUnk110)
    {
    case 0:
        if(o->oBowserUnk106 == 0)
            func_802B3FDC();
        else
            func_802B4124();
        o->oBowserUnk110 = 1;
        break;
    case 1:
        o->oBowserUnk110 = 0;
        o->oAction = 14;
        break;
    }
}

#ifdef VERSION_US
void func_u_802B4AF4(void)
{
    if(o->oVelY < 0 && o->oPosY < (o->oHomeY - 300.0f))
    {
        o->oPosX = o->oPosZ = 0;
        o->oPosY = o->oHomeY + 2000.0f;
        o->oVelY = 0;
        o->oForwardVel = 0;
    }
}
#endif

void ActionBowser18() // unused?
{
    if(func_802A4AB0(12))
        o->oAction = 0;
}

void ActionBowser0() // only lasts one frame
{
    o->oUnk1B0_S16 = 0;
    func_8029ED38(12);
    // stop him still
    o->oAngleVelYaw = 0;
    o->oForwardVel = 0.0f;
    o->oVelY = 0.0f;
    if(BITDW)
        func_802B3D24();
    else if(BITFS)
        func_802B3E44();
    else
        func_802B4144();
    // Action 14 commonly follows
}

void ActionBowser15(void)
{
    o->oForwardVel = 0.0f;
    if(o->oTimer == 0)
        PlaySound2(0x50080081);
    if(func_802A4AB0(6))
        o->oAction = 0;
}

void ActionBowser14() // turn towards Mario
{
    UNUSED s32 facing; // is Bowser facing Mario?
    s16 turnSpeed;
    s16 angleFromMario = abs_angle_diff(o->oMoveAngleYaw,o->oAngleToMario);
    if(BITFS)
        turnSpeed = 0x400;
    else if(o->oHealth > 2)
        turnSpeed = 0x400;
    else if(o->oHealth == 2)
        turnSpeed = 0x300;
    else
        turnSpeed = 0x200;
    facing = obj_rotate_yaw_toward(o->oAngleToMario,turnSpeed);
    if(o->oSubAction == 0)
    {
        o->oBowserUnkF8 = 0;
        if(func_802B39B8())
            o->oSubAction++;
    }
    else if(o->oSubAction == 1)
    {
        if(func_802B3A30())
        {
            o->oBowserUnkF8++;
            if(o->oBowserUnkF4 & 0x20000)
            {
                if(o->oBowserUnkF8 > 4)
                    o->oBowserUnkF4 &= ~0x20000;
            }
            else if(angleFromMario < 0x2000)
                o->oSubAction++;
        }
    }
    else if(func_802B3A98())
        o->oAction = 0;
}

void ActionBowser16(void)
{
    switch(o->oSubAction)
    {
    case 0:
        obj_become_intangible();
        o->oUnk1AC_S16 = 0;
        o->oBowserUnkF8 = 30;
        if(o->oTimer == 0)
            PlaySound2(0x90668081);
        if(o->oOpacity == 0)
        {
            o->oSubAction++;
            o->oMoveAngleYaw = o->oAngleToMario;
        }
        break;
    case 1:
        if(o->oBowserUnkF8--)
            o->oForwardVel = 100.0f;
        else
        {
            o->oSubAction = 2;
            o->oMoveAngleYaw = o->oAngleToMario;
        }
        if(abs_angle_diff(o->oMoveAngleYaw,o->oAngleToMario) > 0x4000)
            if(o->oDistanceToMario > 500.0f)
            {
                o->oSubAction = 2;
                o->oMoveAngleYaw =    o->oAngleToMario; // large change in angle?
                PlaySound2(0x90668081);
            }
        break;
    case 2:
        o->oForwardVel = 0.0f;
        o->oUnk1AC_S16 = 0xFF;
        if(o->oOpacity == 0xFF)
            o->oAction = 0;
        obj_become_tangible();
        break;
    }
}

void ActionBowser8(void) // only in sky
{
    s32 frame;
    func_8029ED38(11);
    frame = o->header.gfx.unk38.animFrame;
    if(frame > 24 && frame < 36)
        {
            PlaySound(0x60000001);
            if(frame == 35)
                spawn_object_relative(1,0,0x190,0x64,o,0x90,beh_blue_bowser_flame);
            else
                spawn_object_relative(0,0,0x190,0x64,o,0x90,beh_blue_bowser_flame);
        }
    if(func_8029F788())
        o->oAction = 0;
    o->oBowserUnkF4 |= 0x20000;
}

void ActionBowser12(void)
{
    if(o->oTimer == 0)
    {
        o->oForwardVel = -400.0f;
        o->oVelY = 100.0f;
        o->oMoveAngleYaw = o->oBowserAngleToCentre + 0x8000;
        o->oUnk1B0_S16 = 1;
    }
    if(o->oSubAction == 0)
    {
        func_8029ED38(25);
        o->oSubAction++;
        o->oBowserUnkF8 = 0;
    }
    else if(o->oSubAction == 1)
    {
        func_8029ED38(25);
        func_8029F728();
        func_802B392C(&o->oBowserUnkF8);
        if((o->oBowserUnkF8 > 2))
        {
            func_8029ED38(26);
            o->oVelY = 0.0f;
            o->oForwardVel = 0.0f;
            o->oSubAction++;
        }
    }
    else if(o->oSubAction == 2)
    {
        if(func_8029F788())
        {
            if(o->oHealth == 1)
                o->oAction = 3;
            else
                o->oAction = 0;
            o->oUnk1B0_S16 = 0;
        }
    }
    else {}
}

s32 func_802B4A44(void)
{
    func_8029ED38(9);
    if(obj_check_anim_frame(11))
        return 1;
    else
        return 0;
}

s32 func_802B4A94(void)
{
    if(o->oMoveFlags & 1)
    {
        o->oForwardVel = 0;
        o->oVelY = 0;
        func_802AA618(0,0,60.0f);
        func_8029ED38(8);
        o->header.gfx.unk38.animFrame = 0;
        func_802A11B4(o,7);
        if(BITDW)
        {
            if(o->oDistanceToMario < 850.0f)
                gMarioObject->oInteractStatus |= 2;
            else
                gMarioObject->oInteractStatus |= 1;
        }
        return 1;
    }
    else
        return 0;
}

void func_802B4BA4(void)
{
    if(BITS && o->oBowserUnkF4 & 0x10000)
        if(o->oBowserDistToCentre > 1000.0f)
            o->oForwardVel = 60.0f;
}

void ActionBowser13(void)
{
    UNUSED s32 unused;
    if(o->oSubAction == 0)
    {
        if(func_802B4A44())
        {
            if(BITS && o->oBowserUnkF4 & 0x10000)
                o->oVelY = 70.0f;
            else
                o->oVelY = 80.0f;
            o->oBowserUnkF8 = 0;
            func_802B4BA4();
            o->oSubAction++;
        }
    }
    else if(o->oSubAction == 1)
    {
#ifndef VERSION_JP
        if(o->oBehParams2ndByte == 2 && o->oUnknownUnkF4_S32 & 0x10000)
            func_u_802B4AF4();
        if(func_802B4A94())
        {
            o->oBowserUnkF4 &= 0xfffeffff;
            o->oForwardVel = 0.0f;
            o->oSubAction++;
            func_802B38B4();
            if(BITFS)
                o->oAction = 19;
        }
        else {}
#else
        if(func_802B4A94())
        {
            o->oBowserUnkF4 &= 0xfffeffff;
            o->oForwardVel = 0.0f;
            o->oSubAction++;
            func_802B38B4();
            if(BITFS)
                o->oAction = 19;
        }
        else {}
#endif
    }
    else if(func_8029F788())
        o->oAction = 0;
}

void ActionBowser17(void)
{
    f32 sp1C = D_8032F50C[0];
    f32 sp18 = D_8032F510[0];
    if(o->oSubAction == 0)
    {
        if(func_802B4A44())
        {
            o->oVelY = sp1C;
            o->oForwardVel = sp18;
            o->oBowserUnkF8 = 0;
            o->oSubAction++;
        }
    }
    else if(o->oSubAction == 1)
    {
        if(func_802B4A94())
            o->oSubAction++;
    }
    else if(func_8029F788())
        o->oAction = 0;
}

void ActionBowser10(void)
{
    o->oForwardVel = 0.0f;
    if(o->oTimer == 0)
        o->oBowserUnkF8 = 0;
    switch(o->oSubAction)
    {
    case 0:
        func_8029ED38(23);
        if(func_8029F788())
            o->oBowserUnkF8++;
        if(o->oBowserUnkF8 > 0)
            o->oSubAction++;
        break;
    case 1:
        func_8029ED38(24);
        if(func_8029F788())
            o->oAction = 11;
        break;
    }
}

void ActionBowser9(void)
{
    if(gDisplayedHealthWedges < 4)
        o->oBowserUnk108 = 3;
    else
        o->oBowserUnk108 = RandomFloat() * 3.0f + 1.0f;
    func_8029ED38(22);
    if(obj_check_anim_frame(5))
        obj_spit_fire(0,200,180,7.0f,144,30.0f,10.0f,0x1000);
    if(func_8029F788())
        o->oSubAction++;
    if(o->oSubAction >= o->oBowserUnk108)
        o->oAction = 0;
}

s32 func_802B5108(s32 a0,s16 a1)
{
    if(o->oSubAction == 0)
    {
        if(func_802A4AB0(15))
            o->oSubAction++;
    }
    else if(o->oSubAction == 1)
    {
        if(func_802A4AB0(14))
            o->oSubAction++;
    }
    else
        func_8029ED38(12);
    o->oForwardVel = 0.0f;
    o->oMoveAngleYaw += a1;
    if(o->oTimer >= a0)
        return 1;
    else
        return 0;
}

void ActionBowser11(void)
{
    if(func_802B5108(63,0x200))
        o->oAction = 0;
}

void ActionBowser7(void)
{
    s32 sp34;
    if(o->oTimer == 0)
        o->oForwardVel = 0.0f;
    switch(o->oSubAction)
    {
    case 0:
        o->oBowserUnkF8 = 0;
        if(func_802A4AB0(18))
            o->oSubAction = 1;
        break;
    case 1:
        o->oForwardVel = 50.0f;
        if(func_802A4AB0(0x13) != 0)
        {
            o->oBowserUnkF8++;
            if(o->oBowserUnkF8 >= 6)
                o->oSubAction = 3;
            if(o->oBowserUnkF8 >= 2)
                if(abs_angle_diff(o->oAngleToMario,o->oMoveAngleYaw) > 0x2000)
                    o->oSubAction = 3;
        }
        obj_rotate_yaw_toward(o->oAngleToMario,0x200);
        break;
    case 3:
        o->oBowserUnkF8 = 0;
        func_8029ED38(21);
        spawn_object_relative_with_scale(0, 100,-50,0,3.0f,o,150,&beh_white_puff_smoke2);
        spawn_object_relative_with_scale(0,-100,-50,0,3.0f,o,150,&beh_white_puff_smoke2);
        if(approach_f32_signed(&o->oForwardVel,0,-1.0f))
            o->oSubAction = 2;
        func_8029F728();
        break;
    case 2:
        o->oForwardVel = 0.0f;
        func_8029ED38(20);
        if(func_8029F788())
        {
            if(BITS)
                sp34 = 10;
            else
                sp34 = 30;
            if(o->oBowserUnkF8 > sp34)
                o->oAction = 0;
            o->oBowserUnkF8++;
        }
        func_8029F728();
        break;
    }
    if(o->oMoveFlags & 0x400)
        o->oAction = 10;
}

s32 func_802B5588(void)
{
    struct Object* mine;
    f32 sp18;
    mine = obj_find_nearest_object_with_behavior(beh_bowser_bomb, &sp18);
    if(mine != NULL && sp18 < 800.0f)
    {
        mine->oInteractStatus |= 0x200000;
        return 1;
    }
    return 0;
}

void ActionBowser1(void) // unused?
{
    UNUSED s32 unused;
    if(o->oTimer < 2)
        o->oBowserUnkF8 = 0;
    if(o->oSubAction == 0)
    {
        func_8029ED38(2);
        func_802B392C(&o->oBowserUnkF8);
        if(o->oMoveFlags & 2)
        {
            o->oForwardVel = 0.0f;
            o->oSubAction++;
        }
    }
    else if(func_802A4AB0(0))
        o->oAction = 0;
    if(func_802B5588())
    {
        o->oHealth--;
        if(o->oHealth <= 0)
            o->oAction = 4;
        else
            o->oAction = 12;
    }
}

void func_802B5738(void)
{
    o->oUnk1AC_S16 = 0;
    if(o->oOpacity == 0)
    {
        o->oForwardVel = 0.0f;
        o->oVelY = 0.0f;
        o->oPosY = o->oHomeY - 1000.0f;
    }
}

void ActionBowser2(void)
{
    s32 sp2C;
    UNUSED s32 unused;
    s8* sp24 = (s8*)o->oFloor;
    if(sp24 != NULL && sp24[4] & 1)
        sp2C = 1;
    else
        sp2C = 0;
    o->oBowserUnkF4 |= 0x10000;
    switch(o->oSubAction)
    {
    case 0:
        if(o->oTimer == 0)
        {
            o->oFaceAnglePitch = 0;
            o->oFaceAngleRoll = 0;
        } //? missing else
        o->oFaceAnglePitch += 0x800;
        o->oFaceAngleRoll += 0x800;
        if(!(o->oFaceAnglePitch & 0xFFFF))
            o->oSubAction++;
        func_802B5738();
        break;
    case 1:
        func_8029ED38(9);
        if(obj_check_anim_frame(11))
        {
            o->oMoveAngleYaw = o->oBowserAngleToCentre;
            o->oVelY = 150.0f;
            o->oUnk1AC_S16 = 0xFF;
            o->oBowserUnkF8 = 0;
            o->oSubAction++;
        }
        else
            func_802B5738();
        break;
    case 2:
        if(o->oPosY > o->oHomeY)
        {
            o->oDragStrength = 0.0f;
            if(o->oBowserDistToCentre < 2500.0f)
            {
                if(absf(o->oFloorHeight - o->oHomeY) < 100.0f)
                    approach_f32_signed(&o->oForwardVel,0,-5.0f);
                else
                    obj_obj_forward_vel_approach_upward(150.0f,2.0f);
            }
            else
                obj_obj_forward_vel_approach_upward(150.0f,2.0f);
        }
        if(func_802B4A94())
        {
            o->oDragStrength = 10.0f;
            o->oSubAction++;
            if(sp2C == 0)
                func_802B38B4();
            else if(BITS)
                o->oAction = 13;
            if(BITFS)
                o->oAction = 19;
        }
#ifndef VERSION_JP
        func_u_802B4AF4();
#else
        if(o->oVelY < 0.0f && o->oPosY < o->oHomeY - 300.0f)
        {
            o->oPosZ = 0.0f, o->oPosX = o->oPosZ;
            o->oPosY = o->oHomeY + 2000.0f;
            o->oVelY = 0.0f;
        }
#endif
        break;
    case 3:
        if(func_8029F788())
        {
            o->oAction = 0;
            o->oBowserUnkF4 &= ~0x10000;
            func_8029F728();
        }
        break;
    }
    print_debug_bottom_up("sp %d",o->oForwardVel);
}

void ActionBowser3(void)
{
    if(item_in_array(o->oTimer,D_8032F514))
        PlaySound2(0x50030081);
    if(func_802A4AB0(10))
        o->oAction = 0;
}

void func_802B5C78(void)
{
    if(BITS)
        D_8032CFD0 = spawn_object(o,122,&beh_grand_star);
    else
    {
        D_8032CFD0 = spawn_object(o,204,&beh_bowser_key_2);
        PlaySound2(0x80610081);
    }
    D_8032CFD0->oAngleVelYaw = o->oAngleVelYaw;
}

void func_802B5D18(void)
{
    func_8029ED38(16);
    if(BITS)
        o->oForwardVel = -400.0f;
    else
        o->oForwardVel = -200.0f;
    o->oVelY = 100.0f;
    o->oMoveAngleYaw = o->oBowserAngleToCentre + 0x8000;
    o->oBowserUnkF8 = 0;
    o->oSubAction++;
}

void func_802B5DD8(void)
{
    o->oUnk1B0_S16 = 1;
    func_802B392C(&o->oBowserUnkF8);
    if(o->oMoveFlags & 1)
        PlaySound2(0x50030081);
    if(o->oMoveFlags & 2)
    {
        o->oForwardVel = 0.0f;
        o->oSubAction++;
    }
}

s32 func_802B5E7C(void)
{
    s32 ret = 0;
    obj_become_intangible();
    if(func_802A4AB0(17) && o->oDistanceToMario < 700.0f && abs_angle_diff(gMarioObject->oMoveAngleYaw,o->oAngleToMario) > 0x6000)
        ret = 1;
    func_8029F728();
    o->oBowserUnkF8 = 0;
    return ret;
}

s32 func_802B5F20(void)
{
    s32 ret = 0;
    if(o->header.gfx.scale[0] < 0.8)
        o->oAngleVelYaw += 0x80;
    if(o->header.gfx.scale[0] > 0.2)
    {
        o->header.gfx.scale[0] = o->header.gfx.scale[0] - 0.02;
        o->header.gfx.scale[2] = o->header.gfx.scale[2] - 0.02;
    }
    else
    {
        o->header.gfx.scale[1] = o->header.gfx.scale[1] - 0.01;
        o->oVelY = 20.0f;
        o->oGravity = 0.0f;
    }
    if(o->header.gfx.scale[1] < 0.5)
        ret = 1;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    if(o->oOpacity >= 3)
        o->oOpacity -= 2;
    return ret;
}

void func_802B60B8(void)
{
    obj_scale(0);
    o->oForwardVel = 0.0f;
    o->oVelY = 0.0f;
    o->oGravity = 0.0f;
}

s32 func_802B6120(void)
{
    s32 ret = 0;
    if(o->oBowserUnkF8 < 2)
    {
        if(o->oBowserUnkF8 == 0)
        {
            func_8031FFB4(0,60,40);
            o->oBowserUnkF8++;
        }
        if(obj_update_dialogue_unk1(2,18,D_8032F518[0][o->oBehParams2ndByte],0))
        {
            o->oBowserUnkF8++;
            PlaySound2(0x80600081);
            func_80320040(0,60);
            func_8031F7CC(0,1);
        }
    }
    else if(func_802B5F20())
    {
        func_802B60B8();
        func_802AD82C(20,116,1.0f,0);
        func_802B5C78();
        set_mario_npc_dialogue(0);
        ret = 1;
    }
    return ret;
}

s32 func_802B6254(void)
{
    UNUSED s32 unused;
    s32 ret = 0;
    s32 sp1C;
    if(o->oBowserUnkF8 < 2)
    {
        if(gDisplayedStars < 120)
            sp1C = 121;
        else
            sp1C = 163;
        if(o->oBowserUnkF8 == 0)
        {
            func_8031FFB4(0,60,40);
            o->oBowserUnkF8++;
        }
        if(obj_update_dialogue_unk1(2,18,sp1C,0))
        {
            obj_set_model(0x69);
            func_80320040(0,60);
            func_8031F7CC(0,1);
            func_802B5C78();
            o->oBowserUnkF8++;
        }
    }
    else if(o->oOpacity > 4)
        o->oOpacity -= 4;
    else
    {
        func_802B60B8();
        ret = 1;
    }
    return ret;
}

void ActionBowser4(void)
{
    switch(o->oSubAction)
    {
    case 0:
        func_802B5D18();
        break;
    case 1:
        func_802B5DD8();
        break;
    case 2:
        if(func_802B5E7C())
        {
            o->oBowserUnkF8 = 0;
            if(BITS)
                o->oSubAction = 10;
            else
            {
                o->activeFlags |= 0x80;
                o->oSubAction++;
            }
        }
        break;
    case 3:
        if(func_802B6120())
            o->oSubAction++;
        break;
    case 4:
        break;
    case 10:
        if(func_802B6254())
            o->oSubAction++;
        break;
    case 11:
        break;
    }
}

void func_802B64E8(struct Object* bowser,s16 a1)
{
    s16 angle;
    angle = o->oBowserAngleToCentre + 0x8000;
    bowser->oAngleVelPitch = coss(angle) * a1;
    bowser->oAngleVelRoll = -sins(angle) * a1;
}

void ActionBowser19(void)
{
    struct Object* platform = obj_nearest_object_with_behavior(beh_tilting_bowser_lava_platform);
    UNUSED s16 sp2A = o->oBowserAngleToCentre + 0x8000;
    s16 sp28;
    UNUSED s32 unused;
    s32 i;
    s32 sp1C;
    if(platform == NULL)
        o->oAction = 0;
    else
    {
        i = 0;
        sp1C = 1;
        while(D_8032F518[1+i][3]!=0)
        {
            if(o->oTimer < D_8032F518[1+i][3])
            {
                sp28 = D_8032F518[1+i][2];
                if(D_8032F518[1+i][1] > 0)
                    sp28 = (D_8032F518[1+i][3]-o->oTimer-1)*sp28;
                else
                    sp28 = (o->oTimer-D_8032F518[1+i][0])*sp28;
                func_802B64E8(platform,sp28);
                if(sp28 != 0)
                    SetSound(0x41150001,&platform->header.gfx.unk54);
                sp1C = 0;
                break;
            }
            i++;
        }
        if(sp1C)
        {
            o->oAction = 0;
            platform->oAngleVelPitch = 0;
            platform->oAngleVelRoll = 0;
            platform->oFaceAnglePitch = 0;
            platform->oFaceAngleRoll = 0;
        }
    }
    func_8029F728();
}

s32 func_802B67C4(void) // bowser off stage?
{
    if(o->oAction != 2 && o->oAction != 19)
    {
        if(o->oPosY < o->oHomeY - 1000.0f)
            return 1;
        if(o->oMoveFlags & 1)
        {
            if(o->oFloorType == 1)
                return 1;
            if(o->oFloorType == 10)
                return 1;
        }
    }
    return 0;
}

void (*TableBowserActions[])(void) = {ActionBowser0,ActionBowser1,ActionBowser2,ActionBowser3,ActionBowser4,ActionBowser5,ActionBowser6,ActionBowser7,ActionBowser8,ActionBowser9,ActionBowser10,ActionBowser11,ActionBowser12,ActionBowser13,ActionBowser14,ActionBowser15,ActionBowser16,ActionBowser17,ActionBowser18,ActionBowser19};
struct SoundState D_8032F5B8[] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,0,-1,0x50030081},{1,0,-1,0x90040081},{1,0,-1,0x90040081},{0,0,0,0},{0,0,0,0},{1,20,40,0x50030081},{1,20,-1,0x50030081},{1,20,40,0x50030081},{1,0,-1,0x50050081},{1,0,-1,0x50060081},{1,8,-1,0x50030081},{1,8,17,0x50030081},{1,8,-10,0x50030081},{0,0,0,0},{1,5,-1,0x50558081},{0,0,0,0},{0,0,0,0},{1,0,-1,0x50050081},{1,0,-1,0x90040081}};
s8 D_8032F690[4] = {0,0,1,0};
s8 D_8032F694[4] = {1,1,3,0};
extern u8 bowser_3_seg7_collision_07004B94[];
extern u8 bowser_3_seg7_collision_07004C18[];
extern u8 bowser_3_seg7_collision_07004C9C[];
extern u8 bowser_3_seg7_collision_07004D20[];
extern u8 bowser_3_seg7_collision_07004DA4[];
extern u8 bowser_3_seg7_collision_07004E28[];
extern u8 bowser_3_seg7_collision_07004EAC[];
extern u8 bowser_3_seg7_collision_07004F30[];
extern u8 bowser_3_seg7_collision_07004FB4[];
extern u8 bowser_3_seg7_collision_07005038[];
struct Struct8032F698 D_8032F698[] = {{NULL,0,0,0,0},{bowser_3_seg7_collision_07004B94,-800,-1000,-20992,0},{bowser_3_seg7_collision_07004C18,-1158,390,-18432,0},{bowser_3_seg7_collision_07004C9C,-1158,390,-7680,0},{bowser_3_seg7_collision_07004D20,0,1240,-6144,0},{bowser_3_seg7_collision_07004DA4,0,1240,6144,0},{bowser_3_seg7_collision_07004E28,1158,390,7680,0},{bowser_3_seg7_collision_07004EAC,1158,390,18432,0},{bowser_3_seg7_collision_07004F30,800,-1000,20992,0},{bowser_3_seg7_collision_07004FB4,800,-1000,-31744,0},{bowser_3_seg7_collision_07005038,-800,-1000,31744,0}};

void func_802B688C(void)
{
    struct Surface* floor;
    struct Object* platform;
    UNUSED f32 floorHeight;
    if((platform = o->platform) != NULL)
        apply_platform_displacement(0,platform);
    o->oBowserUnk10E = 0;
    obj_update_floor_and_walls();
    obj_call_action_function(TableBowserActions);
    obj_move_standard(-78);
    if(func_802B67C4())
        o->oAction = 2; // bowser go home?
    floorHeight = find_floor(o->oPosX,o->oPosY,o->oPosZ,&floor);
    if((floor != NULL) && (floor->object != 0))
        o->platform = floor->object;
    else
        o->platform = NULL;
    exec_anim_sound_state(D_8032F5B8);
}

void func_802B697C(void)
{
    o->oBowserUnkF4 &= ~0x20000;
    obj_become_intangible();
    switch(o->oBowserUnk10E)
    {
    case 0:
        PlaySound2(0x50050081);
        func_8029FA5C(3,1);
        o->oBowserUnk10E++;
        break;
    case 1:
        if(func_8029F788())
        {
            func_8029ED38(2);
            o->oBowserUnk10E++;
        }
        break;
    case 2:
        break;
    }
    o->oMoveFlags = 0;
    o->oBowserHeldAnglePitch = gMarioObject->oMoveAnglePitch;
    o->oBowserHeldAngleVelYaw = gMarioObject->oAngleVelYaw;
    o->oMoveAngleYaw = gMarioObject->oMoveAngleYaw;
}

void func_802B6AC0(void)
{
    f32 sp1C;
    o->oBowserUnk10E = 0;
    obj_get_thrown_or_placed(1.0f,1.0f,1);
    sp1C = o->oBowserHeldAngleVelYaw / 3000.0 * 70.0f;
    if(sp1C < 0.0f)
        sp1C = -sp1C;
    if(sp1C > 90.0f)
        sp1C *= 2.5; // > 90 => get bigger?
    o->oForwardVel = coss(o->oBowserHeldAnglePitch) * sp1C;
    o->oVelY = -sins(o->oBowserHeldAnglePitch) * sp1C;
    obj_become_intangible();
    o->prevObj->oAction = 1; // not sure what prevObj is
    o->prevObj->oTimer = 0;
    o->prevObj->oSubAction = 0;
    o->oTimer = 0;
    o->oSubAction = 0;
}

void BehBowserLoop(void)
{
    s16 angleToMario;    // AngleToMario    from Bowser's perspective
    s16 angleToCentre; // AngleToCentre from Bowser's perspective

    o->oBowserDistToCentre = sqrtf(o->oPosX*o->oPosX + o->oPosZ*o->oPosZ);
    o->oBowserAngleToCentre = atan2s(0.0f-o->oPosZ,0.0f-o->oPosX);
    angleToMario = abs_angle_diff(o->oMoveAngleYaw,o->oAngleToMario);
    angleToCentre = abs_angle_diff(o->oMoveAngleYaw,o->oBowserAngleToCentre);
    o->oBowserUnkF4 &= ~0xFF;
    if(angleToMario < 0x2000)
        o->oBowserUnkF4 |= 2;
    if(angleToCentre < 0x3800)
        o->oBowserUnkF4 |= 4;
    if(o->oBowserDistToCentre < 1000.0f)
        o->oBowserUnkF4 |= 0x10;
    if(o->oDistanceToMario < 850.0f)
        o->oBowserUnkF4 |= 8;
    switch(o->oHeldState)
    {
    case HELD_FREE:        func_802B688C(); break;
    case HELD_HELD:        func_802B697C(); break;
    case HELD_THROWN:    func_802B6AC0(); break;
    case HELD_DROPPED: func_802B6AC0(); break;
    }
    obj_align_gfx_with_floor();
    if(o->oAction != 4)
        if(o->oUnk1AC_S16 != o->oOpacity)
        {
            if(o->oUnk1AC_S16 > o->oOpacity)
            {
                o->oOpacity += 20;
                if(o->oOpacity >= 0x100)
                    o->oOpacity = 0xFF;
            }
            else
            {
                o->oOpacity -= 20;
                if(o->oOpacity < 0)
                    o->oOpacity = 0;
            }
        }
}

void BehBowserInit(void)
{
    s32 level; // 0 is dw, 1 is fs, 2 is sky
    o->oBowserUnk110 = 1;
    o->oOpacity = 0xFF;
    o->oUnk1AC_S16 = 0xFF;
    if(gCurrLevelNum == LEVEL_BOWSER_2)
        level = 1;
    else if(gCurrLevelNum == LEVEL_BOWSER_3)
        level = 2;
    else
        level = 0;
    o->oBehParams2ndByte = level;
    o->oUnk1B2 = D_8032F690[level];
    o->oHealth = D_8032F694[level];
    func_802A11B4(o,4);
    o->oAction = 5;
    o->oUnk1AE = 0;
    o->oUnk1B0_S16 = 0;
}

#undef BITDW
#undef BITFS
#undef BITS

s32 Geo18_802B798C(s32 arg0,UNUSED s32 arg1, Mat4 arg2)
{
    Mat4 sp20;
    struct Object* sp1C;
    if(arg0 == 1)
    {
        sp1C = (struct Object*)D_8032CFA0;
        if(sp1C->prevObj != NULL)
        {
            func_8029D704(sp20,arg2,D_8032CF9C->unk34);
            func_8029D558(sp20,sp1C->prevObj);
            func_8029EA0C(sp1C->prevObj);
        }
    }
    return 0;
}

void func_802B70C8(struct Object* a0,struct GraphNodeObject* a1)
{
    s32 sp1C;
    s16 sp1A;
    sp1A = abs_angle_diff(a0->oMoveAngleYaw,a0->oAngleToMario);
    sp1C = a1->angle[2];
    switch(sp1C)
    {
    case 0:
        if(sp1A > 0x2000)
        {
            if(a0->oAngleVelYaw > 0)
                a1->angle[2] = 5;
            if(a0->oAngleVelYaw < 0)
                a1->angle[2] = 3;
        }
        if(a0->oUnk1AE > 50)
            a1->angle[2] = 1;
        break;
    case 1:
        if(a0->oUnk1AE > 2)
            a1->angle[2] = 2;
        break;
    case 2:
        if(a0->oUnk1AE > 2)
            a1->angle[2] = 9;
        break;
    case 9:
        if(a0->oUnk1AE > 2)
            a1->angle[2] = 0;
        break;
    case 5:
        if(a0->oUnk1AE > 2)
        {
            a1->angle[2] = 6;
            if(a0->oAngleVelYaw <= 0)
                a1->angle[2] = 0;
        }
        break;
    case 6:
        if(a0->oAngleVelYaw <= 0)
            a1->angle[2] = 5;
        break;
    case 3:
        if(a0->oUnk1AE > 2)
        {
            a1->angle[2] = 4;
            if(a0->oAngleVelYaw >= 0)
                a1->angle[2] = 0;
        }
        break;
    case 4:
        if(a0->oAngleVelYaw >= 0)
            a1->angle[2] = 3;
        break;
    default:
        a1->angle[2] = 0;
    }
    if(a1->angle[2] != sp1C)
        a0->oUnk1AE = -1;
}

s32 GeoSwitchCase802B7C64(s32 a0,struct GraphNodeObject* a1,UNUSED s32 a2)
{
    UNUSED s16 sp36;
    UNUSED s32 unused;
    struct Object* sp2C = (struct Object*)D_8032CFA0;
    struct GraphNodeObject* sp28 = a1;
    if(a0 == 1)
    {
        if(D_8032CFA4 != NULL)
            sp2C = (struct Object*)D_8032CFA4->unk1C;
        switch(sp36 = sp2C->oUnk1B0_S16)
        {
        case 0:
            func_802B70C8(sp2C,sp28);
            break;
        case 1:
            sp28->angle[2] = 2;
            break;
        }
        sp2C->oUnk1AE++;
    }
    return 0;
}

Gfx* Geo18_802B7D44(s32 a0,struct GraphNode* a1,UNUSED s32 a2)
{
    Gfx* sp2C = NULL;
    Gfx* sp28;
    struct Object* sp24;
    struct GraphNode* sp20;
    Gfx* sp1C;
    Gfx* sp18;
    if(a0 == 1)
    {
        sp24 = (struct Object*)D_8032CFA0;
        sp20 = a1;
        if(D_8032CFA4 != 0)
            sp24 = (struct Object*)D_8032CFA4->unk1C;
        if(sp24->oOpacity == 0xFF)
            sp20->flags = (sp20->flags & 0xFF) | 0x100;
        else
            sp20->flags = (sp20->flags & 0xFF) | (0x100 | 0x400);
        sp28 = sp2C = alloc_display_list(16);
        if(sp24->oUnk1B2 != 0)
        {
            sp1C = sp28++;
            sp1C->words.w0 = 0xb6000000;
            sp1C->words.w1 = 0x20000;
        }
        sp18 = sp28;
        sp18->words.w0 = 0xb8000000;
        sp18->words.w1 = 0;
    }
    return sp2C;
}

void ActionFallingBowserPlatform0(void)
{
    o->oPlatformUnkF8 = obj_nearest_object_with_behavior(&beh_bowser);
    set_object_collision_data(o,D_8032F698[o->oBehParams2ndByte].unk0);
    if(o->oBowserUnkF8 != 0)
        o->oAction = 1;
}

void ActionFallingBowserPlatform1(void)
{
    UNUSED s32 unused;
    struct Object* sp0 = o->oPlatformUnkF8;
    if(sp0->platform == o)
        if(sp0->oAction == 13 && sp0->oUnknownUnkF4_S32 & 0x10000)
                o->oAction = 2;
    if(sp0->oHealth == 1 && (sp0->oAction == 3 || sp0->oHeldState != HELD_FREE))
        o->oSubAction = 1;
    if(o->oSubAction == 0)
        o->oPlatformUnkFC = 0;
    else
    {
        if((gDebugInfo[4][6] + 20) * (o->oBehParams2ndByte-1) < o->oPlatformUnkFC)
            o->oAction = 2;
        o->oPlatformUnkFC++;
    }
}

void ActionFallingBowserPlatform2(void)
{
    Vec3f sp24;
    s16 sp22;
    f32 sp1C;
    UNUSED struct Object* sp18 = o->oPlatformUnkF8;
    if(o->oTimer == 0 || o->oTimer == 22)
        PlaySound2(0x31628081);
    if(o->oTimer < 22)
    {
        func_8027F308(10);
        o->oVelY = 8.0f;
        o->oGravity = 0.0f;
    }
    else
        o->oGravity = -4.0f;
    if((o->oTimer & 1) == 0 && o->oTimer < 14)
    {
        sp22 = D_8032F698[o->oBehParams2ndByte].unk3 + (gDebugInfo[4][1] << 8);
        sp1C = -(o->oTimer/2) * 290 + 1740;
        func_802B8F7C(sp24,&o->oPosX);
        o->oPosX = D_8032F698[o->oBehParams2ndByte].unk1 + sins(sp22 + 5296) * sp1C;
        o->oPosZ = D_8032F698[o->oBehParams2ndByte].unk2 + coss(sp22 + 5296) * sp1C;
        o->oPosY = 307.0f;
        func_802AA618(4,0,100.0f);
        o->oPosX = D_8032F698[o->oBehParams2ndByte].unk1 + sins(sp22 - 5296) * sp1C;
        o->oPosZ = D_8032F698[o->oBehParams2ndByte].unk2 + coss(sp22 - 5296) * sp1C;
        func_802AA618(4,0,100);
        func_802B8F7C(&o->oPosX,sp24);
    }
    obj_move_using_fvel_and_gravity();
    if(o->oTimer > 300)
        mark_object_for_deletion(o);
}

void (*TableFallingBowserPlatformActions[])(void) = {ActionFallingBowserPlatform0,ActionFallingBowserPlatform1,ActionFallingBowserPlatform2};
struct ObjectHitbox D_8032F728 = {0x40000,20,1,0,0,10,40,0,0};
struct ObjectHitbox D_8032F738 = {0x40000,0,1,0,0,10,40,0,0};
f32 D_8032F748[] = {-8.0f,-6.0f,-3.0f};
struct Struct8032F754 D_8032F754[] = {{145,{0.7f,1.5f,0.7f},7.0f},{235,{1.2f,2.0f,1.2f},11.6f}};
s32 D_8032F77C[] = {1011,151191267,1151,151059970,1723,122027068,2082,116390808,2489,112589707,2662,111082380,2902,100727885,2946,100728365,2924,100663368,2908,100663832,2886,100664079,-(1<<16)};
struct SoundState D_8032F7D8[] = {{1,1,10,0x503B0081},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,0,-1,0x50390081},{1,0,-1,0x50210081},{0,0,0,0},{0,0,0,0},{1,0,-1,0x50210081},{1,0,-1,0x503C0081},{1,0,-1,0x503A0081},{0,0,0,0},{0,0,0,0}};

void BehFallingBowserPlatformLoop(void)
{
    obj_call_action_function(TableFallingBowserPlatformActions);
}

void func_802B7A58(void)
{
    mark_object_for_deletion(o);
    spawn_object_with_scale(o,0,&beh_black_smoke_upward,1.0f);
    if(RandomFloat() < 0.1)
        spawn_object(o,116,&beh_temporary_yellow_coin);
}

s32 func_802B7ADC(s32 a0)
{
    if(a0 < o->oTimer)
        return 1;
    if(o->oFloorType == 1)
        return 1;
    if(o->oFloorType == 10)
        return 1;
    return 0;
}

void BehFlameBowserInit(void)
{
    o->oAnimState = (s32)(RandomFloat() * 10.0f);
    o->oMoveAngleYaw = RandomU16();
    if(RandomFloat() < 0.2)
        o->oVelY = 80.0f;
    else
        o->oVelY = 20.0f;
    o->oForwardVel = 10.0f;
    o->oGravity = -1.0f;
    o->oFlameUnkF4 = RandomFloat() + 1.0f;
}

void BehFlameLargeBurningOutInit(void)
{
    o->oAnimState = (s32)(RandomFloat() * 10.0f);
    o->oMoveAngleYaw = RandomU16();
    o->oVelY = 10.0f;
    o->oForwardVel = 0.0f;
    o->oFlameUnkF4 = 7.0f;
}

void func_802B7CFC(void)
{
    s32 sp4;
    sp4 = ((o->oFlameUnkF8 + gGlobalTimer) & 0x3F) << 10;
    o->oPosX += sins(o->oMoveAngleYaw) * sins(sp4) * 4.0f;
    o->oPosZ += coss(o->oMoveAngleYaw) * sins(sp4) * 4.0f;
}

void BehFlameBowserLoop(void)
{
    obj_update_floor_and_walls();
    obj_move_standard(78);
    if(o->oVelY < -4.0f)
        o->oVelY = -4.0f;
    if(o->oAction == 0)
    {
        obj_become_intangible();
        func_802B7CFC();
        if(o->oMoveFlags & 1)
        {
            o->oAction++;
            if(obj_has_behavior(beh_flame_large_burning_out))
                o->oFlameUnkF4 = 8.0f;
            else
                o->oFlameUnkF4 = RandomFloat() * 2.0f + 6.0f;
            o->oForwardVel = 0.0f;
            o->oVelY = 0.0f;
            o->oGravity = 0.0f;
        }
    }
    else
    {
        obj_become_tangible();
        if(o->oTimer > o->oFlameUnkF4 * 10.0f + 5.0f)
        {
            o->oFlameUnkF4 -= 0.15;
            if(o->oFlameUnkF4 <= 0.0f)
                func_802B7A58();
        }
    }
    obj_scale(o->oFlameUnkF4);
    o->oGraphYOffset = o->header.gfx.scale[1] * 14.0f;
    set_object_hitbox(o,&D_8032F738);
}

void BehFlameMovingForwardGrowingInit(void)
{
    o->oForwardVel = 30.0f;
    translate_object_xz_random(o,80.0f);
    o->oAnimState = (s32)(RandomFloat() * 10.0f);
    o->oFlameUnkF4 = 3.0f;
}

void BehFlameMovingForwardGrowingLoop(void)
{
    UNUSED s32 unused;
    UNUSED struct Object* sp18;
    set_object_hitbox(o,&D_8032F728);
    o->oFlameUnkF4 = o->oFlameUnkF4 + 0.5;
    obj_scale(o->oFlameUnkF4);
    if(o->oMoveAnglePitch > 0x800)
        o->oMoveAnglePitch -= 0x200;
    func_802A2A38();
    obj_update_floor_height();
    if(o->oFlameUnkF4 > 30.0f)
        mark_object_for_deletion(o);
    if(o->oPosY < o->oFloorHeight)
    {
        o->oPosY = o->oFloorHeight;
        sp18 = spawn_object(o,0x90,&beh_flame_bowser);
        mark_object_for_deletion(o);
    }
}

void BehFlameFloatingLandingInit(void)
{
    o->oAnimState = (s32)(RandomFloat() * 10.0f);
    o->oMoveAngleYaw = RandomU16();
    if(o->oBehParams2ndByte != 0)
        o->oForwardVel = RandomFloat() * 5.0f;
    else
        o->oForwardVel = RandomFloat() * 70.0f;
    o->oVelY = RandomFloat() * 20.0f;
    o->oGravity = -1.0f;
    o->oFlameUnkF8 = RandomFloat() * 64.0f;
}

void BehFlameFloatingLandingLoop(void)
{
    UNUSED s32 unused;
    obj_update_floor_and_walls();
    obj_move_standard(0x4e);
    func_802B7CFC();
    if(func_802B7ADC(900))
        mark_object_for_deletion(o);
    if(o->oVelY < D_8032F748[o->oBehParams2ndByte])
        o->oVelY = D_8032F748[o->oBehParams2ndByte];
    if(o->oMoveFlags & 1)
    {
        if(o->oBehParams2ndByte == 0)
            spawn_object(o,0x90,&beh_flame_large_burning_out);
        else
            spawn_object(o,0,&beh_blue_flames_group);
        mark_object_for_deletion(o);
    }
    o->oGraphYOffset = o->header.gfx.scale[1] * 14.0f;
}

void BehBlueBowserFlameInit(void)
{
    translate_object_xz_random(o,80.0f);
    o->oAnimState = (s32)(RandomFloat() * 10.0f);
    o->oVelY = 7.0f;
    o->oForwardVel = 35.0f;
    o->oFlameUnkF4 = 3.0f;
    o->oFlameUnkFC = RandomFloat() * 0.5;
    o->oGravity = 1.0f;
    o->oFlameUnkF8 = (s32)(RandomFloat() * 64.0f);
}

void BehBlueBowserFlameLoop(void)
{
    s32 i;
    set_object_hitbox(o,&D_8032F728);
    if(o->oFlameUnkF4 < 16.0f)
        o->oFlameUnkF4 = o->oFlameUnkF4 + 0.5;
    obj_scale(o->oFlameUnkF4);
    obj_update_floor_and_walls();
    obj_move_standard(0x4e);
    if(o->oTimer > 0x14)
    {
        if(o->oBehParams2ndByte == 0)
            for(i=0;i<3;i++)
                spawn_object_relative_with_scale(0,0,0,0,5.0f,o,144,&beh_flame_floating_landing);
        else
        {
            spawn_object_relative_with_scale(1,0,0,0,8.0f,o,145,&beh_flame_floating_landing);
            spawn_object_relative_with_scale(2,0,0,0,8.0f,o,145,&beh_flame_floating_landing);
        }
        mark_object_for_deletion(o);
    }
}

void BehFlameBouncingInit(void)
{
    o->oAnimState = (s32)(RandomFloat() * 10.0f);
    o->oVelY = 30.0f;
    o->oForwardVel = 20.0f;
    o->oFlameUnkF4 = o->header.gfx.scale[0];
    o->oFlameUnkF8 = (s32)(RandomFloat() * 64.0f);
}

void BehFlameBouncingLoop(void)
{
    struct Object* sp1C;
    if(o->oTimer == 0)
        o->oFlameUnk100 = obj_nearest_object_with_behavior(&beh_bowser);
    sp1C = o->oFlameUnk100;
    o->oForwardVel = 15.0f;
    o->oBounce = -1.0f;
    obj_scale(o->oFlameUnkF4);
    set_object_hitbox(o,&D_8032F728);
    obj_update_floor_and_walls();
    obj_move_standard(78);
    if(func_802B7ADC(300))
        mark_object_for_deletion(o);
    if(sp1C != NULL)
        if(sp1C->oHeldState == 0)
            if(lateral_dist_between_objects(o,sp1C) < 300.0f)
                mark_object_for_deletion(o);
}

void BehBlueFlamesGroupLoop(void)
{
    struct Object* flame;
    s32 i;
    if(o->oTimer == 0)
    {
        o->oMoveAngleYaw = angle_to_object(o,gMarioObject);
        o->oBlueFlameUnkF8 = 5.0f;
    }
    if(o->oTimer < 16)
    {
        if((o->oTimer & 1) == 0)
        {
            for(i=0;i<3;i++)
            {
                flame = spawn_object(o,145,beh_flame_bouncing);
                flame->oMoveAngleYaw += i * 0x5555;
                flame->header.gfx.scale[0] = o->oBlueFlameUnkF8;
            }
            o->oBlueFlameUnkF8 -= 0.5;
        }
    }
    else
        mark_object_for_deletion(o);
}

void BehBlueFishLoop(void)
{
    f32 sp24;
    switch(o->oAction)
    {
    case 0:
        func_8029ED98(0,1.0f);
        if(o->oTimer == 0)
        {
            o->oBlueFishUnk100 = RandomSign() << 11;
            o->oBlueFishUnkF4 = RandomFloat() * 2.0f;
            o->oBlueFishUnkF8 = (s32)(RandomFloat() * 30.0f) & 0xFE;
            sp24 = RandomFloat() * 5.0f;
            if(sp24 < 2.0f)
                o->oAngleVelPitch = random_f32_around_zero(128);
            else
                o->oAngleVelPitch = 0;
        }
        o->oForwardVel = o->oBlueFishUnkF4 + 3.0f;
        if(o->oTimer >= o->oBlueFishUnkF8 + 60)
            o->oAction++;
        if(o->oTimer < (o->oBlueFishUnkF8 + 60)/2)
            o->oFaceAnglePitch += o->oAngleVelPitch;
        else
            o->oFaceAnglePitch -= o->oAngleVelPitch;
        o->oVelY = -sins(o->oFaceAnglePitch) * o->oForwardVel;
        break;
    case 1:
        func_8029ED98(0,2.0f);
        o->oMoveAngleYaw = (s32)(o->oBlueFishUnk100 + o->oMoveAngleYaw);
        if(o->oTimer == 15)
            o->oAction++;
        break;
    case 2:
        func_8029ED98(0,1.0f);
        if(o->oTimer >= o->oBlueFishUnkF8 + 60)
            o->oAction++;
        if(o->oTimer < (o->oBlueFishUnkF8 + 60)/2)
            o->oFaceAnglePitch -= o->oAngleVelPitch;
        else
            o->oFaceAnglePitch += o->oAngleVelPitch;
        break;
    case 3:
        func_8029ED98(0,2.0f);
        o->oMoveAngleYaw = (s32)(o->oBlueFishUnk100 + o->oMoveAngleYaw);
        if(o->oTimer == 15)
            o->oAction = 0;
        break;
    }
    o->oVelY = -sins(o->oFaceAnglePitch) * o->oForwardVel;
    obj_move_using_fvel_and_gravity();
    if(o->parentObj->oAction == 2)
        mark_object_for_deletion(o);
}

void BehTankFishGroupsLoop(void)
{
    struct Object* fish;
    s32 i;
    switch(o->oAction)
    {
    case 0:
        if(gMarioCurrentRoom == 15 || gMarioCurrentRoom == 7)
        {
            for(i=0;i<15;i++)
            {
                fish = spawn_object_relative(0,300,0,-200,o,185,beh_blue_fish);
                translate_object_xyz_random(fish,200.0f);
            }
            o->oAction++;
        }
        break;
    case 1:
     if(gMarioCurrentRoom != 15 && gMarioCurrentRoom != 7)
             o->oAction++;
     break;
    case 2:
        o->oAction = 0;
        break;
    }
}

void func_802B8F7C(Vec3f dest,Vec3f src)
{
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = src[2];
}

void BehCheckerboardElevatorGroupInit(void)
{
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 i;
    struct Object* sp2C;
    if(o->oBehParams2ndByte == 0)
        o->oBehParams2ndByte = 65;
    sp3C = o->oBehParams2ndByte * 10;
    sp34 = (o->oBehParams >> 24) & 0XFF;
    for(i=0;i<2;i++)
    {
        if(i == 0)
            sp38 = -D_8032F754[sp34].unk0;
        else
            sp38 = D_8032F754[sp34].unk0;
        sp2C = spawn_object_relative(i,0,i*sp3C,sp38,o,202,beh_checkerboard_platform_sub);
        sp2C->oUnk1AC_F32 = D_8032F754[sp34].unk2;
        func_802B8F7C(sp2C->header.gfx.scale,D_8032F754[sp34].unk1);
    }
}

void func_802B9120(UNUSED s32 unused,f32 vel,s32 a2)
{
    o->oMoveAnglePitch = 0;
    o->oAngleVelPitch = 0;
    o->oForwardVel = 0.0f;
    o->oVelY = vel;
    if(o->oTimer > a2)
        o->oAction++;
}

void func_802B91A0(s32 a0,s16 a1)
{
    o->oVelY = 0.0f;
    o->oAngleVelPitch = a1;
    if(o->oTimer+1 == 0x8000/absi(a1))
        o->oAction = a0;
    o->oCheckerBoardPlatformUnkF8 = a0;
}

void BehCheckerboardPlatformInit(void)
{
    o->oCheckerBoardPlatformUnkFC = o->parentObj->oBehParams2ndByte;
}

void BehCheckerboardPlatformLoop(void)
{
    f32 sp24 = o->oUnk1AC_F32;
    o->oCheckerBoardPlatformUnkF8 = 0;
    if(o->oDistanceToMario < 1000.0f)
        PlaySound(0x400D0001);
    switch(o->oAction)
    {
    case 0:
        if(o->oBehParams2ndByte == 0)
            o->oAction = 1;
        else
            o->oAction = 3;
        break;
    case 1:
        func_802B9120(2,10.0f,o->oCheckerBoardPlatformUnkFC);
        break;
    case 2:
        func_802B91A0(3,512);
        break;
    case 3:
        func_802B9120(4,-10.0f,o->oCheckerBoardPlatformUnkFC);
        break;
    case 4:
        func_802B91A0(1,-512);
        break;
    }
    o->oMoveAnglePitch += absi(o->oAngleVelPitch);
    o->oFaceAnglePitch += absi(o->oAngleVelPitch);
    o->oFaceAngleYaw = o->oMoveAngleYaw;
    if(o->oMoveAnglePitch != 0)
    {
        o->oForwardVel = signum_positive(o->oAngleVelPitch) * sins(o->oMoveAnglePitch) * sp24;
        o->oVelY =             signum_positive(o->oAngleVelPitch) * coss(o->oMoveAnglePitch) * sp24;
    }
    if(o->oCheckerBoardPlatformUnkF8 == 1)
    {
        o->oAngleVelPitch = 0;
        o->oFaceAnglePitch &= ~0x7FFF;
        obj_move_using_fvel_and_gravity();
    }
    else
        obj_move_using_fvel_and_gravity();
    load_object_collision_model();
}

void BehDddWarpLoop(void)
{
    if(D_8035FFAC & 2)
        o->collisionData = segmented_to_virtual(inside_castle_seg7_collision_ddd_warp_2);
    else
        o->collisionData = segmented_to_virtual(inside_castle_seg7_collision_ddd_warp);
}

void func_802B95A4(void)
{
    struct Object* sp1C;
    switch(o->oAction)
    {
    case 0:
        if(obj_is_mario_ground_pounding_platform())
        {
            o->oAction++;
            func_802A3004();
        }
        break;
    case 1:
        if(o->oTimer < 4)
            o->oPosY -= 20.0f;
        else
            o->oAction++;
        break;
    case 2:
        sp1C = obj_nearest_object_with_behavior(beh_water_level_pillar);
        if(sp1C != NULL)
        {
            if(sp1C->oAction < 2)
                o->oAction++;
        }
        break;
    case 3:
        sp1C = obj_nearest_object_with_behavior(beh_water_level_pillar);
        if(sp1C != NULL)
        {
            if(sp1C->oAction > 1)
            {
                o->oAction++;
                save_file_set_flags(512);
                func_80321228();
            }
        }
        break;
    case 4:
        PlaySound(0x41160001);
        if(o->oTimer < 300)
        {
            gWaterLevels[2] = (s32)approach_f32_symmetric(gWaterLevels[2],-2450.0f,5.0f);
            gWaterLevels[0] = (s32)approach_f32_symmetric(gWaterLevels[0],-2450.0f,5.0f);
        }
        else
            o->oAction++;
        break;
    case 5:
        break;
    }
}

void func_802B97E4(void)
{
    if(o->oTimer == 0)
    {
        o->oPosY -= 80.0f;
        gWaterLevels[2] = -2450;
        gWaterLevels[0] = -2450;
    }
}

void BehWaterLevelPillarInit(void)
{
    if(save_file_get_flags() & SAVE_FLAG_MOAT_DRAINED)
        o->oWaterLevelPillarUnkF8 = 1;
}

void BehWaterLevelPillarLoop(void)
{
    if(o->oWaterLevelPillarUnkF8)
        func_802B97E4();
    else
        func_802B95A4();
    gWaterRegions[18] = gWaterLevels[2];
    gWaterRegions[6]    = gWaterLevels[0];
}

void BehInvisibleObjUnderBridge(void)
{
    if(save_file_get_flags() & SAVE_FLAG_MOAT_DRAINED)
    {
        gWaterRegions[6]    = -800;
        gWaterRegions[12] = -800;
    }
}

s32 Geo18_802BA2B0(s32 a0,struct GraphNode* a1,UNUSED void* a2)
{
    struct Object* sp4;
    if(a0 == 1)
    {
        sp4 = (struct Object*)D_8032CFA0;
        (*(f32*)&((struct GraphNodeObject*)a1->next)->unk18) = sp4->oUnknownUnkF4_F32; // FIXME
    }
    return 0;
}

void BehDoorKey1Loop(void)
{
    s32 sp1C;
    sp1C = o->header.gfx.unk38.animFrame;
    func_8029ED38(0);
    if(sp1C < 38)
        o->oDoorKey1UnkF4 = 0.0f;
    else if(sp1C < 49)
        o->oDoorKey1UnkF4 = 0.2f;
    else if(sp1C < 58)
        o->oDoorKey1UnkF4 = (sp1C - 53) * 0.11875f + 0.2; // 0.11875?
    else if(sp1C < 59)
        o->oDoorKey1UnkF4 = 1.1f;
    else if(sp1C < 60)
        o->oDoorKey1UnkF4 = 1.05f;
    else
        o->oDoorKey1UnkF4 = 1.0f;
    if(o->oTimer > 150)
        mark_object_for_deletion(o);
}

void BehDoorKey2Loop(void)
{
    s32 sp1C = o->header.gfx.unk38.animFrame;
    func_8029ED38(1);
    if(sp1C < 38)
        o->oDoorKey2UnkF4 = 0.2f;
    else if(sp1C < 52)
        o->oDoorKey2UnkF4 = (sp1C - 42) * 0.042857f + 0.2; // TODO 3/70?
    else if(sp1C < 94)
        o->oDoorKey2UnkF4 = 0.8f;
    else if(sp1C < 0x65)
        o->oDoorKey2UnkF4 = (101 - sp1C) * 0.085714f + 0.2; //TODO 6/70?
    else
        o->oDoorKey2UnkF4 = 0.2f;
    if(o->oTimer > 138)
        mark_object_for_deletion(o);
}

void BehMoatGrillsLoop(void)
{
    if(save_file_get_flags() & SAVE_FLAG_MOAT_DRAINED)
        obj_set_model(0);
    else
        load_object_collision_model();
}

void BehRotatingClockArmLoop(void)
{
    struct Surface* sp1C;
    u16 sp1A = o->oFaceAngleRoll;
    o->oFloorHeight = find_floor(gMarioObject->oPosX,gMarioObject->oPosY,gMarioObject->oPosZ,&sp1C);
    if(o->oAction == 0)
    {
        if(sp1C->type == SURFACE_DEFAULT)
            if(o->oTimer >= 4)
                o->oAction++;
    }
    else if(o->oAction == 1)
    {
        if(sp1C != NULL && (sp1C->type == SURFACE_TTC_PAINTING_1 || sp1C->type == SURFACE_TTC_PAINTING_2 || sp1C->type == SURFACE_TTC_PAINTING_3))
        {
            if(obj_has_behavior(beh_clock_minute_hand))
            {
                if(sp1A < 0xAAA)
                    gTTCSpeedSetting = 3;
                else if(sp1A < 0x6aa4)
                    gTTCSpeedSetting = 1;
                else if(sp1A < 0x954C)
                    gTTCSpeedSetting = 2;
                else if(sp1A < 0xf546)
                    gTTCSpeedSetting = 0;
                else
                    gTTCSpeedSetting = 3;
            }
            o->oAction++;
        }
        else {}
    }
    if(o->oAction < 2)
        obj_rotate_face_angle_using_vel();
}

void func_802B9E88(void)
{
    if(o->oBehParams2ndByte == 1)
    {
        if(obj_mario_far_away())
        {
            obj_set_pos_to_home_and_stop();
            o->oAction = 0;
        }
        else if(o->oMoveFlags & (0x40 | 0x20 | 0x10 | 8))
            o->oAction = 5;
    }
}

s32 func_802B9F10(void)
{
    if(o->oBehParams2ndByte == 1)
        if(func_8024C75C(gMarioState))
            return 1;
    return 0;
}

s32 Unknown802B9F6C(s32 a0,UNUSED s32 a1,Mat4 a2)
{
    Mat4 sp20;
    struct Object* sp1C;
    if(a0 == 1)
    {
        sp1C = (struct Object*)D_8032CFA0;
        if(sp1C->prevObj != NULL)
        {
            func_8029D704(sp20,a2,D_8032CF9C->unk34);
            func_8029D558(sp20,sp1C->prevObj);
            func_8029EA0C(sp1C->prevObj);
        }
    }
    return 0;
}

void func_802BA000(void)
{
    o->oForwardVel = 0.0f;
    if(o->oSubAction == 0)
    {
        o->oSubAction = (s32)(RandomFloat() * 4.0f + 1.0f);
        o->oUkikiOpenCageUnkF4 = 0;
        o->oUkikiOpenCageUnkF6 = (s16)(RandomFloat() * 4.0f + 2.0f);
    }
    switch(o->oSubAction)
    {
    case 1:
        func_8029ED38(9);
        if(func_8029F788())
            o->oSubAction = 0;
        break;
    case 2:
        func_8029ED38(4);
        if(func_8029F788())
            o->oUkikiOpenCageUnkF4++;
        if(o->oUkikiOpenCageUnkF4 >= o->oUkikiOpenCageUnkF6 * 2)
            o->oSubAction = 0;
        break;
    case 3:
        func_8029ED38(5);
        if(func_8029F788())
            o->oUkikiOpenCageUnkF4++;
        if(o->oUkikiOpenCageUnkF4 >= o->oUkikiOpenCageUnkF6)
            o->oSubAction = 0;
        break;
    case 4:
        func_8029ED38(10);
        if(func_8029F788())
            o->oSubAction = 0;
        break;
    }
}

void ActionUkikiOpenCage0(void)
{
    func_802BA000();
    if(func_802B9F10())
    {
        if(o->oDistanceToMario > 700.0f && o->oDistanceToMario < 1000.0f)
            o->oAction = 1;
        else if(o->oDistanceToMario <= 700.0f && 200.0f < o->oDistanceToMario)
            if(abs_angle_diff(o->oAngleToMario,o->oMoveAngleYaw) > 0x1000)
                o->oAction = 2;
    }
    else if(o->oDistanceToMario < 300.0f)
        o->oAction = 1;
    if(o->oUnk1AC_S16 == 2)
        o->oAction = 4;
    if(o->oUnk1AC_S16 == 3)
    {
        o->oMoveAngleYaw = gMarioObject->oMoveAngleYaw + 0x8000;
        if(func_802B0C54(50.0f,150.0f))
            o->oAction = 3;
        else
        {
            o->oMoveAngleYaw = gMarioObject->oMoveAngleYaw + 0x4000;
            if(func_802B0C54(50.0f,150.0f))
                o->oAction = 3;
            else
            {
                o->oMoveAngleYaw = gMarioObject->oMoveAngleYaw - 0x4000;
                if(func_802B0C54(50.0f,150.0f))
                    o->oAction = 3;
            }
        }
        o->oUnk1AC_S16 = 4;
    }
    if(o->oBehParams2ndByte == 1)
        if(o->oPosY < -1550.0f)
            o->oAction = 7;
}

void ActionUkikiOpenCage7(void)
{
    UNUSED s32 unused;
    func_8029ED38(0);
    o->oMoveAngleYaw = obj_angle_to_home();
    o->oForwardVel = 10.0f;
    if(o->oPosY > -1550.0f)
        o->oAction = 0;
}

void ActionUkikiOpenCage5(void)
{
    func_802BA000();
    if(obj_mario_far_away())
    {
        obj_set_pos_to_home_and_stop();
        o->oAction = 0;
    }
}

void ActionUkikiOpenCage6(void)
{
    func_802BA000();
    if(o->oSubAction == 3)
        obj_rotate_yaw_toward(o->oAngleToMario,0x400);
}

void ActionUkikiOpenCage2(void)
{
    s32 sp1C;
    if(o->oTimer == 0)
        o->oForwardVel = RandomFloat() * 3.0f + 2.0f;
    func_8029ED38(11);
    sp1C = obj_rotate_yaw_toward(o->oAngleToMario,0x800);
    if(sp1C)
        o->oAction = 0;
    if(func_802B9F10())
    {
        if(o->oDistanceToMario > 500.0f)
            o->oAction = 1;
    }
    else if(o->oDistanceToMario < 300.0f)
        o->oAction = 1;
}

void ActionUkikiOpenCage1(void)
{
    s32 sp1C = 1;
    s16 sp1A = o->oAngleToMario + 0x8000;
    if(func_802B9F10())
    {
        sp1C = 0;
        sp1A = o->oAngleToMario;
    }
    if(o->oTimer == 0)
        o->oUkikiOpenCageUnk110 = RandomFloat() * 100.0f + 350.0f;
    func_8029ED38(0);
    obj_rotate_yaw_toward(sp1A,0x800);
    func_8029F684(20.0f,0.9f);
    if(sp1C)
    {
        if(o->oDistanceToMario > o->oUkikiOpenCageUnk110)
            o->oAction = 2;
    }
    else if(o->oDistanceToMario < o->oUkikiOpenCageUnk110)
        o->oAction = 2;
    if(sp1C)
    {
        if(o->oDistanceToMario < 200.0f)
        {
            if((o->oMoveFlags & 0x200) && obj_is_mario_moving_fast_or_in_air(10))
            {
                o->oAction = 3;
                o->oMoveAngleYaw = o->oWallAngle;
            }
            else if((o->oMoveFlags & 0x400))
                if(obj_is_mario_moving_fast_or_in_air(10))
                {
                    o->oAction = 3;
                    o->oMoveAngleYaw += 0x8000;
                }
        }
    }
}

void ActionUkikiOpenCage3(void)
{
    o->oForwardVel = 10.0f;
    obj_become_intangible();
    if(o->oSubAction == 0)
    {
        if(o->oTimer == 0)
            func_8029FA1C(RandomFloat() * 10.0f + 45.0f,8);
        else if(o->oMoveFlags & (0x40 | 0x10 | 2 | 1))
        {
            o->oSubAction++;
            o->oVelY = 0.0f;
        }
    }
    else
    {
        o->oForwardVel = 0.0f;
        func_8029ED38(7);
        obj_become_tangible();
        if(func_8029F788())
            o->oAction = 1;
    }
}

void ActionUkikiOpenCage4(void)
{
    struct Object* sp24;
    f32 sp20 = 0.0f;
    s16 sp1E = 0;
    sp24 = obj_nearest_object_with_behavior(beh_unused_0F14);
    if(sp24 != NULL)
    {
        sp20 = lateral_dist_between_objects(o,sp24->parentObj);
        sp1E = angle_to_object(o,sp24->parentObj);
    }
    obj_become_intangible();
    o->oFlags |= 0x80;
    switch(o->oSubAction)
    {
    case 0:
        func_8029ED38(0);
        o->oUkikiOpenCageUnkFC = D_8032F77C;
        if(obj_follow_path(0) != -1)
        {
            o->oForwardVel = 10.0f;
            obj_rotate_yaw_toward(o->oUkikiOpenCageUnk10C,0x400);
            o->oPosY = o->oFloorHeight;
        }
        else
        {
            o->oForwardVel = 0.0f;
            o->oSubAction++;
        }
        break;
    case 1:
        func_8029ED38(5);
        obj_rotate_yaw_toward(o->oAngleToMario,0x400);
        if(func_802A3FF8(200.0f,30.0f,0x7FFF))
            o->oSubAction++;
        else // weird?
            break;
    case 2:
        func_8029ED38(10);
        if(obj_update_dialogue_unk2(3,1,162,80))
            o->oSubAction++;
        break;
    case 3:
        func_8029ED38(0);
        if(obj_rotate_yaw_toward(sp1E,0x400))
        {
            o->oForwardVel = 10.0f;
            o->oSubAction++;
        }
        break;
    case 4:
        func_8029FA1C(55.0f,8);
        o->oForwardVel = 36.0f;
        o->oSubAction++;
        break;
    case 5:
        if(sp20 < 50.0f)
            o->oForwardVel = 0.0f;
        if(o->oMoveFlags & 1)
        {
            func_80321228();
            func_8029ED38(5);
            o->oSubAction++;
            o->oUnk1B0_S16 = 32;
            sp24->parentObj->oUnk88 = 1;
            o->oForwardVel = 0.0f;
        }
        break;
    case 6:
        o->oMoveAngleYaw += 0x800;
        o->oUnk1B0_S16--;
        if(o->oUnk1B0_S16 < 0)
        {
            o->oSubAction++;
            sp24->parentObj->oUnk88 = 2;
        }
        break;
    case 7:
        if(o->oPosY < -1300.0f)
            mark_object_for_deletion(o);
        break;
    }
}

void (*TableUkikiOpenCageActions[])(void) = {ActionUkikiOpenCage0,ActionUkikiOpenCage1,ActionUkikiOpenCage2,ActionUkikiOpenCage3,ActionUkikiOpenCage4,ActionUkikiOpenCage5,ActionUkikiOpenCage6,ActionUkikiOpenCage7};
s16 D_8032F860[] = {2,30,0x4000,0,1,220,900,30,1,30,0,-30,2,30,-0x4000,0,1,220,900,30,1,30,0,-30,3,0};
s16 D_8032F894[] = {4,0 ,0         ,0,1,475,900,30,1,30,0,-30,2,30, 0x8000,0,1,475,900,30,1,30,0,-30,3,0};
s16* D_8032F8C8[] = {D_8032F860,D_8032F894};

void func_802BAE40(void)
{
    s32 sp1C;
    obj_update_floor_and_walls();
    obj_call_action_function(TableUkikiOpenCageActions);
    if(o->oAction == 4 || o->oAction == 7)
        sp1C = -88;
    else
        sp1C = -20;
    obj_move_standard(sp1C);
    func_802B9E88();
    if(!(o->oMoveFlags & (0x40 | 0x20 | 0x10 | 8)))
        exec_anim_sound_state(D_8032F7D8);
}

void Unknown802BAEE0(void)
{
    if(gGlobalTimer % 50 < 7)
        o->oAnimState = 1;
    else
        o->oAnimState = 0;
}

void func_802BAF30(void)
{
    if(o->oPosY - o->oHomeY > -100.0f)
        switch(o->oUnk1AC_S16)
        {
        case 0:
            if(set_mario_npc_dialogue(2) == 2)
            {
                func_802D8050(79);
                o->oUnk1AC_S16 = 1;
            }
            break;
        case 1:
            if(gDialogueResponse != 0)
            {
                set_mario_npc_dialogue(0);
                if(gDialogueResponse == 1)
                {
                    o->oUnk190 |= 0x40;
                    o->oUnk1AC_S16 = 2;
                }
                else
                {
                    o->oUnk1AC_S16 = 6;
                    o->oUnk1AE = 60;
                }
            }
            break;
        case 2:
            break;
        case 6:
            if(o->oUnk1AE-- < 0)
                o->oUnk1AC_S16 = 0;
            break;
        }
    else
    {
        o->oUnk1AC_S16 = 0;
        o->oTimer = 0;
        o->oAction = 5;
    }
}

void func_802BB0E4(void)
{
    switch(o->oUnk1AC_S16)
    {
    case 0:
        if(mario_lose_cap_to_enemy(2))
        {
            o->oUnk1AC_S16 = 7;
            o->oUnk1B2 |= 1;
        }
        else {}
        break;
    case 7:
        if(obj_update_dialogue_unk1(2,2,100,0))
        {
            o->oUnk190 |= 0x40;
            o->oUnk1AC_S16 = 3;
        }
        break;
    case 3:
        break;
    case 4:
        if(obj_update_dialogue_unk1(2,18,101,0))
        {
            mario_retrieve_cap();
            set_mario_npc_dialogue(0);
            o->oUnk1B2 &= ~1;
            o->oUnk1AC_S16 = 5;
        }
        break;
    case 5:
        o->oUnk1AC_S16 = 0;
        o->oAction = 0;
        break;
    }
}

void BehUkikiOpenCageInit(void)
{
    if(o->oBehParams2ndByte == 1)
        if(save_file_get_flags() & SAVE_FLAG_CAP_ON_UKIKI)
        {
            o->oUnk1AC_S16 = 4;
            o->oUnk1B2 |= 1;
        }
}

void BehUkikiOpenCageLoop(void)
{
    switch(o->oHeldState)
    {
    case HELD_FREE:
        o->oUnk1AE = 0;
        func_802BAE40();
        break;
    case HELD_HELD:
        func_8029FA5C(12,0);
        copy_object_pos(o,gMarioObject);
        if(o->oBehParams2ndByte == 1)
            func_802BB0E4();
        else
            func_802BAF30();
        break;
    case HELD_THROWN:
    case HELD_DROPPED:
        obj_get_dropped();
        break;
    }
    if(o->oUnk1B2 & 1)
        o->oAnimState = 2;
    else
        o->oAnimState = 0;
    o->oInteractStatus = 0;
    print_debug_bottom_up("mode   %d\n",o->oAction);
    print_debug_bottom_up("action %d\n",o->oHeldState);
}

s32 func_802BB414(s16* a0,s32 a1)
{
    switch(a0[a1])
    {
    case 4:
        o->oMoveAngleYaw = a0[a1+2];
        o->oForwardVel = a0[a1+3]/100.0f;
        if(obj_is_mario_on_platform())
        {
            a1 += 4;
            o->oTimer = 0;
        }
        break;
    case 2:
        o->oMoveAngleYaw = a0[a1+2];
        o->oForwardVel = a0[a1+3]/100.0f;
        if(o->oTimer > a0[a1+1])
        {
            a1 += 4;
            o->oTimer = 0;
        }
        break;
    case 1:
        approach_f32_signed(&o->oForwardVel,a0[a1+2]/100.0f,a0[a1+3]/100.0f);
        if(o->oTimer > a0[a1+1])
        {
            a1 += 4;
            o->oTimer = 0;
        }
        break;
    case 3:
        o->oForwardVel = 0.0f;
        a1 = 0;
        break;
    }
    return a1;
}

s32 func_802BB680(s32* a0,f32* a1,s32 a2,s32 a3)
{
    if(obj_is_mario_on_platform())
    {
        if(a0[0] < 0x4000)
            a0[0] += a2;
        else
            a0[0] = 0x4000;
    }
    else
    {
        if(a0[0] > 0)
            a0[0] -= a2;
        else
            a0[0] = 0;
    }
    a1[0] = sins(a0[0]) * a3;
    if(a0[0] == 0 || a0[0] == 0x4000)
        return 1;
    else
        return 0;
}

void BehLLLMovingOctagonalMeshPlatformLoop(void)
{
    if(o->oAction == 0)
    {
        o->oHorizontalMovementUnkF8 = 0;
        o->oAction++;
    }
    else
        o->oHorizontalMovementUnkF8 = func_802BB414(D_8032F8C8[o->oBehParams2ndByte],o->oHorizontalMovementUnkF8);
    print_debug_top_down_objectinfo("number %d\n",o->oHorizontalMovementUnkF8);
    obj_move_using_fvel_and_gravity();
    if(func_802BB680(&o->oHorizontalMovementUnk104,&o->oHorizontalMovementUnk108,0x400,-80))
    {
        o->oHorizontalMovementUnkF4 += 0x800;
        o->oHorizontalMovementUnk100 -= sins(o->oHorizontalMovementUnkF4) * 2.0f;
    }
    o->oPosY = o->oHorizontalMovementUnk100 + o->oHomeY + o->oHorizontalMovementUnk108;
}

void BehLLLSinkingRockBlockLoop(void)
{
    func_802BB680(&o->oSinkWhenSteppedOnUnk104,&o->oSinkWhenSteppedOnUnk108,124,-110);
    o->oGraphYOffset = 0.0f;
    o->oPosY = o->oHomeY + o->oSinkWhenSteppedOnUnk108;
}

void BehLllRotatingHexFlameLoop(void)
{
    f32 sp24 = o->oLllRotatingHexFlameUnkF4;
    f32 sp20 = o->oLllRotatingHexFlameUnkF8;
    f32 sp1C = o->oLllRotatingHexFlameUnkFC;
    obj_set_pos_relative(o->parentObj,sp24,sp20,sp1C);
    o->oPosY = o->parentObj->oPosY + 100.0f;
    if(o->parentObj->oAction == 3)
        mark_object_for_deletion(o);
}

void func_802BB9F0(s32 a0)
{
    struct Object* sp2C;
    UNUSED s32 unused;
    s32 i;
    s32 sp20;
    f32 sp1C = sins(a0) * 200.0f;
    f32 sp18 = coss(a0) * 200.0f;
    if(o->oBehParams2ndByte == 0)
        sp20 = 4;
    else
        sp20 = 3;
    for(i=0;i<sp20;i++)
    {
        sp2C = spawn_object(o,144,beh_lll_rotating_hex_flame);
        sp2C->oLllRotatingHexFlameUnkF4 += sp1C;
        sp2C->oLllRotatingHexFlameUnkF8 = o->oPosY - 200.0f;
        sp2C->oLllRotatingHexFlameUnkFC += sp18;
        scale_object_xyz(sp2C,6.0f,6.0f,6.0f);
        sp1C += sins(a0) * 150.0f;
        sp18 += coss(a0) * 150.0f;
    }
}

void ActionRotatingCwFireBars0(void)
{
    if(o->oDistanceToMario < 3000.0f)
        o->oAction = 1;
}

void ActionRotatingCwFireBars1(void)
{
    func_802BB9F0(0);
    func_802BB9F0(-0x8000);
    o->oAngleVelYaw = 0;
    o->oMoveAngleYaw = 0;
    o->oAction = 2;
}

void ActionRotatingCwFireBars2(void)
{
    o->oAngleVelYaw = -0x100;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    if(o->oDistanceToMario > 3200.0f)
        o->oAction = 3;
}

void ActionRotatingCwFireBars3(void)
{
    o->oAction = 0;
}

void (*TableRotatingCwFireBarsActions[])(void) = {ActionRotatingCwFireBars0,ActionRotatingCwFireBars1,ActionRotatingCwFireBars2,ActionRotatingCwFireBars3};
struct ObjectHitbox D_8032F8E0 = {0x80000,0,4,1,1,50,50,50,50};
s8 D_8032F8F0[] = {4,1,4,1,6,1,6,1,5,1,5,1,6,1,6,1,5,1,2,4,1,4,1,4,1,2,5,1,5,1,7,1,7,1,4,1,4,1,7,1,7,1,5,1,5,1,5,1,2,4,1,-1};
s8 D_8032F924[] = {4,1,4,1,7,1,7,1,7,1,2,6,1,6,1,6,1,5,1,5,1,6,1,5,1,5,1,2,4,1,4,1,7,1,-1};
s8 D_8032F948[] = {4,1,4,1,4,1,4,1,4,1,2,5,1,5,1,5,1,5,1,5,1,7,1,2,6,1,6,1,5,1,2,4,1,7,1,-1};
s8* D_8032F96C[] = {D_8032F8F0,D_8032F924,D_8032F948};

void BehLLLRotatingBlockFireBarsLoop(void)
{
    obj_call_action_function(TableRotatingCwFireBarsActions);
    if(o->oBehParams2ndByte == 0)
        load_object_collision_model();
}

void BehLllWoodPieceLoop(void)
{
    if(o->oTimer == 0)
        o->oPosY -= 100.0f;
    o->oPosY += sins(o->oLllWoodPieceUnkF4) * 3.0f;
    o->oLllWoodPieceUnkF4 += 0x400;
    if(o->parentObj->oAction == 2)
        mark_object_for_deletion(o);
}

void BehLLLFloatingWoodBridgeLoop(void)
{
    struct Object* sp3C;
    s32 i;
    switch(o->oAction)
    {
    case 0:
        if(o->oDistanceToMario < 2500.0f)
        {
            for(i=1;i<4;i++)
            {
                sp3C = spawn_object_relative(0,(i-2)*300,0,0,o,53,beh_lll_wood_piece);
                sp3C->oLllWoodPieceUnkF4 = i * 4096;
            }
            o->oAction = 1;
        }
        break;
    case 1:
        if(o->oDistanceToMario > 2600.0f)
            o->oAction = 2;
        break;
    case 2:
        o->oAction = 0;
        break;
    }
}

void BehVolcanoFlamesLoop(void)
{
    obj_update_floor_height();
    obj_compute_vel_xz();
    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    obj_move_y(-4.0f,-0.7f,2.0f);
    if(o->oMoveFlags & 0x33)
        mark_object_for_deletion(o);
}

void func_802BBFDC(void)
{
    struct Object* sp1C;
    f32 size;
    sp1C = spawn_object(o,144,beh_volcano_flames);
    sp1C->oPosY += 550.0f;
    sp1C->oMoveAngleYaw = RandomU16() << 0x10 >> 0x10;
    sp1C->oForwardVel = RandomFloat() * 40.0f + 20.0f;
    sp1C->oVelY = RandomFloat() * 50.0f + 10.0f;
    size = RandomFloat() * 6.0 + 3.0;
    scale_object_xyz(sp1C,size,size,size);
    if(RandomFloat() < 0.1)
        PlaySound2(0x300C8081);
}

void BehLLLRotatingHexagonalRingLoop(void)
{
    UNUSED s32 unused;
    o->oCollisionDistance = 4000.0f;
    o->oDrawingDistance = 8000.0f;
    switch(o->oAction)
    {
    case 0:
        if(gMarioObject->platform == o)
            o->oAction++;
        o->oAngleVelYaw = 0x100;
        break;
    case 1:
        o->oAngleVelYaw = 256.0f - sins(o->oTimer << 7) * 256.0f;
        if(o->oTimer > 128)
            o->oAction++;
        break;
    case 2:
        if(gMarioObject->platform != o)
            o->oAction++;
        if(o->oTimer > 128)
            o->oAction++;
        o->oAngleVelYaw = 0;
        func_802BBFDC();
        break;
    case 3:
        o->oAngleVelYaw = sins(o->oTimer << 7) * 256.0f;
        if(o->oTimer > 128)
            o->oAction = 0;
        break;
    case 4:
        o->oAction = 0;
        break;
    }
    o->oAngleVelYaw = -o->oAngleVelYaw;
    o->oMoveAngleYaw += o->oAngleVelYaw;
}

void func_802BC390(f32 a0,s32 a1)
{
    switch(o->oAction)
    {
    case 0:
        o->oAction++;
        break;
    case 1:
        o->oPosY -= sins(o->oLllWoodPieceUnkF4) * a0;
        o->oLllWoodPieceUnkF4 += a1;
        break;
    case 2:
        break;
        break; // Two breaks needed?
    }
}

void BehLLLSinkingRectangularPlatformLoop(void)
{
    f32 sp1C = 0.4f;
    s32 sp18 = 0x100;
    if(o->oMoveAngleYaw != 0)
        func_802BC390(sp1C,sp18);
    else
    {
        o->oFaceAnglePitch = sins(o->oLllWoodPieceUnkF4) * 512.0f;
        o->oLllWoodPieceUnkF4 += 0x100;
    }
}

void BehLLLSinkingSquarePlatformsLoop(void)
{
    f32 sp1C = 0.5f;
    s32 sp18 = 0x100;
    func_802BC390(sp1C,sp18);
}

void func_802BC544(Mat4 a0,f32 a1,f32 a2,f32 a3)
{
    Vec3f sp24;
    Vec3f sp18;
    sp18[0] = o->oPosX;
    sp18[1] = o->oPosY;
    sp18[2] = o->oPosZ;
    sp24[0] = a1;
    sp24[1] = a2;
    sp24[2] = a3;
    mtxf_from_up_direction(a0,sp24,sp18,0);
}

void BehTiltingPlatformInit(void)
{
    Mat4* sp1C = &o->transform;
    o->oTiltingPlatformUnkF4 = 0.0f;
    o->oTiltingPlatformUnkF8 = 1.0f;
    o->oTiltingPlatformUnkFC = 0.0f;
    func_802BC544(*sp1C,0.0f,1.0f,0.0f);
}

f32 func_802BC66C(f32 a0,f32 a1,f32 a2)
{
    f32 sp4;
    if(a1 <= a0)
    {
        if(a0 - a1 < a2)
            sp4 = a0;
        else
            sp4 = a1 + a2;
    }
    else if(a0 - a1 > -a2)
        sp4 = a0;
    else
        sp4 = a1 - a2;
    return sp4;
}

void BehTiltingPlatformLoop(void)
{
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    Vec3f dist;
    Vec3f sp58;
    Vec3f sp4C;
    f32 mx;
    f32 my;
    f32 mz;
    s32 sp3C = 0;
    UNUSED s32 unused;
    Mat4* sp34 = &o->transform;
    UNUSED s32 unused2[7];
    if(gMarioObject->platform == o)
    {
        get_mario_pos(&mx,&my,&mz);
        dist[0] = gMarioObject->oPosX - o->oPosX;
        dist[1] = gMarioObject->oPosY - o->oPosY;
        dist[2] = gMarioObject->oPosZ - o->oPosZ;
        linear_mtxf_mul_vec3f(*sp34,sp58,dist);
        dx = gMarioObject->oPosX - o->oPosX;
        dy = 500.0f;
        dz = gMarioObject->oPosZ - o->oPosZ;
        d = sqrtf(dx*dx+dy*dy+dz*dz);
        if(d != 0.0f) // Normalizing
        {
            d = 1.0/d;
            dx *= d;
            dy *= d;
            dz *= d;
        }
        else
        {
            dx = 0.0f;
            dy = 1.0f;
            dz = 0.0f;
        }
        if(o->oTiltingPlatformUnk10C == 1)
            sp3C++;
        o->oTiltingPlatformUnk10C = 1;
    }
    else
    {
        dx = 0.0f;
        dy = 1.0f;
        dz = 0.0f;
        o->oTiltingPlatformUnk10C = 0;
    }
    o->oTiltingPlatformUnkF4 = func_802BC66C(dx,o->oTiltingPlatformUnkF4,0.01f);
    o->oTiltingPlatformUnkF8 = func_802BC66C(dy,o->oTiltingPlatformUnkF8,0.01f);
    o->oTiltingPlatformUnkFC = func_802BC66C(dz,o->oTiltingPlatformUnkFC,0.01f);
    func_802BC544(*sp34,o->oTiltingPlatformUnkF4,o->oTiltingPlatformUnkF8,o->oTiltingPlatformUnkFC);
    if(sp3C != 0)
    {
        linear_mtxf_mul_vec3f(*sp34,sp4C,dist);
        mx += sp4C[0] - sp58[0];
        my += sp4C[1] - sp58[1];
        mz += sp4C[2] - sp58[2];
        set_mario_pos(mx,my,mz);
    }
    o->header.gfx.throwMatrix = sp34;
}

void func_802BCA8C(void)
{
    UNUSED s32 unused;
    struct Object* drop;
    spawn_object(o,163,beh_water_type);
    if(gMarioStates->forwardVel > 10.0f)
    {
        drop = spawn_object_with_scale(o,164,beh_water_drops,1.5f);
        drop->oVelY = RandomFloat() * 30.0f;
        translate_object_xz_random(drop,110.0f);
    }
}

void BehKoopaShellFlameLoop(void)
{
    if(o->oTimer == 0)
    {
        o->oMoveAngleYaw = RandomU16();
        o->oVelY = RandomFloat() * 30.0f;
        o->oGravity = -4.0f;
        o->oAnimState = RandomFloat() * 10.0f;
        translate_object_xz_random(o,110.0f);
        o->oKoopaShellFlameUnkF8 = 4.0f;
    }
    obj_update_floor_height();
    obj_move_using_fvel_and_gravity();
    if(o->oFloorHeight > o->oPosY || o->oTimer > 10)
        mark_object_for_deletion(o);
    o->oKoopaShellFlameUnkF8 += -0.3;
    obj_scale(o->oKoopaShellFlameUnkF8);
}

void func_802BCC84(void)
{
    s32 i;
    for(i=0;i<2;i++)
        spawn_object(o,144,beh_koopa_shell_flame);
}

void func_802BCCD4(f32 a)
{
    struct Object* sp1C = spawn_object(o,0,beh_powerup_sparkles2);
    sp1C->oPosY += a;
}

void BehKoopaShellLoop(void)
{
    struct Surface* sp34;
    set_object_hitbox(o,&D_8032F8E0);
    obj_scale(1.0f);
    switch(o->oAction)
    {
    case 0:
        obj_update_floor_and_walls();
        obj_if_hit_wall_bounce_away();
        if(o->oInteractStatus & 0x8000)
            o->oAction++;
        o->oFaceAngleYaw += 0x1000;
        obj_move_standard(-20);
        func_802BCCD4(10.0f);
        break;
    case 1:
        copy_object_pos(o,gMarioObject);
        sp34 = obj_update_floor_height_and_get_floor();
        if(absf(find_water_level(o->oPosX,o->oPosZ)-o->oPosY) < 10.0f)
            func_802BCA8C();
        else if(5.0f > absf(o->oPosY-o->oFloorHeight))
        {
            if(sp34 != NULL && sp34->type == 1)
                    func_802BCC84();
            else
                    func_802BCCD4(10.0f);
        }
        else
            func_802BCCD4(10.0f);
        o->oFaceAngleYaw = gMarioObject->oMoveAngleYaw;
        if(o->oInteractStatus & 0x400000)
        {
            mark_object_for_deletion(o);
            func_802A3004();
            o->oAction = 0;
        }
        break;
    }
    o->oInteractStatus = 0;
}

void func_802BCF78(void)
{
    if(o->oDistanceToMario < 3000.0f)
        ShakeScreen(1);
}

void func_802BCFC4(f32 a0,f32 a1,s16 a2,s16 a3) // 0x18 0x1c 0x22 0x26
{
    o->oPosY = 99.41124 * sins((o->oTimer+1)/8.0f * 0x8000) + o->oHomeY + 3.0f;
    o->oForwardVel = a0;
    o->oUnkC0 = a1;
    o->oFaceAnglePitch += a2;
    if((s16)o->oFaceAnglePitch < 0)
        a3 = - a3;
    o->oFaceAngleRoll += a3;
    func_802A2A38();
    if(o->oTimer == 7)
    {
        o->oAction = func_802A32E0();
#ifndef VERSION_JP
        PlaySound2(0x30468081);
#else
        PlaySound2(0x30460081);
#endif
    }
}

void ActionToxBox4(void)
{
    func_802BCFC4(64.0f,0.0f,0x800,0);
}
void ActionToxBox5(void)
{
    func_802BCFC4(-64.0f,0.0f,-0x800,0);
}
void ActionToxBox6(void)
{
    func_802BCFC4(0.0f,-64.0f,0,0x800);
}
void ActionToxBox7(void)
{
    func_802BCFC4(0.0f,64.0f,0,-0x800);
}

void ActionToxBox1(void)
{
    o->oForwardVel = 0.0f;
    if(o->oTimer == 0)
        func_802BCF78();
    o->oPosY = o->oHomeY + 3.0f;
    if(o->oTimer == 20)
        o->oAction = func_802A32E0();
}

void ActionToxBox2(void)
{
    if(o->oTimer == 20)
        o->oAction = func_802A32E0();
}

void ActionToxBox3(void)
{
    if(o->oTimer == 20)
        o->oAction = func_802A32E0();
}

void ActionToxBox0(void)
{
    s8* sp1C = D_8032F96C[o->oBehParams2ndByte];
    o->oAction = func_802A32A4(sp1C);
}

void (*TableToxBoxActions[])(void) = {ActionToxBox0,ActionToxBox1,ActionToxBox2,ActionToxBox3,ActionToxBox4,ActionToxBox5,ActionToxBox6,ActionToxBox7};
s8 D_8032F998[] = {12,28,50,64,-1};

void BehToxBoxLoop(void)
{
    obj_call_action_function(TableToxBoxActions);
    load_object_collision_model();
}

void ActionPiranhaPlant20(void)
{
    obj_become_intangible();
    func_8029ED38(8);
#ifdef VERSION_US
    obj_scale(1);
#endif
    if(o->oDistanceToMario < 1200.0f)
        o->oAction = 1;
}

s32 func_802BD4A8(void)
{
    s32 i;
    s32 sp18 = 1;
    if(o->oInteractStatus & 0x8000)
    {
        func_80321080(50);
        if(o->oInteractStatus & 0x4000)
        {
            PlaySound2(0x90116081);
            for(i=0;i<20;i++)
                spawn_object(o,170,beh_giant_piranha_particle);
            o->oAction = 5;
        }
        else
            o->oAction = 3;
        o->oInteractStatus = 0;
    }
    else
        sp18 = 0;
    return sp18;
}

void ActionPiranhaPlant21(void)
{
    obj_become_tangible();
    o->oInteractType = 0x8000;
    func_8029ED38(8);
    obj_set_hitbox_radius_and_height(250.0f,200.0f);
    func_802A1274(150.0f,100.0f);
#ifdef VERSION_US
    o->oDamageOrCoinValue = 0;
#endif
    if(o->oDistanceToMario < 400.0f)
    {
        if(func_802BDAD4())
            o->oAction = 3;
    }
    else if(o->oDistanceToMario < 1000.0f)
    {
        func_80320F84(11,0,255,1000);
        o->oPiranhaPlant2UnkF4 = 0;
    }
    else if(o->oPiranhaPlant2UnkF4 == 0)
    {
        o->oPiranhaPlant2UnkF4++;
        func_80321080(0x32);
    }
    func_802BD4A8();
}

void ActionPiranhaPlant23(void)
{
#ifdef VERSION_US
    o->oDamageOrCoinValue = 3;
#endif
    if(o->oTimer == 0)
        func_80321080(50);
    if(func_802BD4A8() == 0)
        if(o->oTimer > 10)
            o->oAction = 2;
}

#ifdef VERSION_US
void func_u_802BE0B8(void)
{
    if(o->activeFlags & 2)
        o->oAction = 0;
}
#endif

void ActionPiranhaPlant25(void)
{
    obj_become_intangible();
    func_8029ED38(2);
    o->oInteractStatus = 0;
    if(func_8029F788())
        o->oAction = 6;
#ifdef VERSION_US
    func_u_802BE0B8();
#endif
}

void ActionPiranhaPlant26(void)
{
    if(o->oTimer == 0)
    {
        PlaySound2(0x50744081);
        o->oPiranhaPlant2UnkF8 = 1.0f;
    }
    if(o->oPiranhaPlant2UnkF8 > 0.0f)
        o->oPiranhaPlant2UnkF8 = o->oPiranhaPlant2UnkF8 - 0.04;
    else
    {
        o->oPiranhaPlant2UnkF8 = 0.0f;
        obj_spawn_loot_blue_coin();
        o->oAction = 7;
    }
    obj_scale(o->oPiranhaPlant2UnkF8);
#ifdef VERSION_US
    func_u_802BE0B8();
#endif
}

void ActionPiranhaPlant27(void)
{
    if(o->oDistanceToMario > 1200.0f)
        o->oAction = 8;
}

void ActionPiranhaPlant28(void)
{
    func_8029ED38(8);
    if(o->oTimer == 0)
        o->oPiranhaPlant2UnkF8 = 0.3f;
    if(o->oPiranhaPlant2UnkF8 < 1.0)
        o->oPiranhaPlant2UnkF8 += 0.02;
    else
    {
        o->oPiranhaPlant2UnkF8 = 1.0f;
        o->oAction = 0;
    }
    obj_scale(o->oPiranhaPlant2UnkF8);
}

void ActionPiranhaPlant22(void)
{

    s32 frame = o->header.gfx.unk38.animFrame;
    obj_become_tangible();
    o->oInteractType = 8;
    func_8029ED38(0);
    obj_set_hitbox_radius_and_height(150.0f,100.0f);
    func_802A1274(150.0f,100.0f);
    if(item_in_array(frame,D_8032F998))
        PlaySound2(0x90105081);
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);
    if(o->oDistanceToMario > 500.0f)
        if(func_8029F788())
            o->oAction = 4;
    if(o->oInteractStatus & 0x8000)
        if(gMarioState->flags & 4)
            o->oAction = 5;
}
s32 func_802BDAD4(void)
{
    if(gMarioStates->vel[1] > 10.0f)
        return 1;
    if(gMarioStates->forwardVel > 10.0f)
        return 1;
    return 0;
}

void ActionPiranhaPlant24(void)
{
    obj_become_intangible();
    func_8029ED38(6);
    if(func_8029F788())
        o->oAction = 1;
    if(o->oDistanceToMario < 400.0f)
        if(func_802BDAD4())
            o->oAction = 2;
}

void (*TablePiranhaPlantActions[])(void) = {ActionPiranhaPlant20,ActionPiranhaPlant21,ActionPiranhaPlant22,ActionPiranhaPlant23,ActionPiranhaPlant24,ActionPiranhaPlant25,ActionPiranhaPlant26,ActionPiranhaPlant27,ActionPiranhaPlant28};
s8 D_8032F9C4[] = {2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,-1};
s8 D_8032F9E0[] = {2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,-1};
s8 D_8032F9FC[] = {2,2,2,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,2,2,-1};
s8 D_8032FA18[] = {2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,-1};
s8 D_8032FA34[] = {2,2,2,2,2,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,2,2,2,2,-1};
s8 D_8032FA50[] = {2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,-1};
s8 D_8032FA6C[] = {2,2,2,2,2,2,2,5,2,2,2,2,2,2,2,2,2,2,6,2,2,2,2,2,2,2,-1};
s8 D_8032FA88[] = {2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,-1};
s8 D_8032FAA4[] = {2,2,2,2,2,2,2,2,2,6,2,2,2,2,2,2,5,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FAC0[] = {2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FADC[] = {2,2,2,2,2,2,2,2,2,2,2,6,2,2,5,2,2,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FAF8[] = {2,2,2,2,2,2,2,2,2,2,2,2,3,4,2,2,2,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FB14[] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,-1};
s8 D_8032FB30[] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,-1};

struct Struct8032FB4C D_8032FB4C[] = {{67,251,241,1,D_8032F9C4},{68,5,241,0,D_8032F9E0},{69,241,251,0,D_8032FADC},{70,251,251,0,D_8032FAF8},{71,5,251,0,D_8032F9FC},{72,15,251,0,D_8032FA18},{73,241,5,0,D_8032FAC0},{74,251,5,0,D_8032FAA4},{75,5,5,0,D_8032FA50},{76,15,5,0,D_8032FA34},{77,241,15,0,D_8032FB14},{78,251,15,0,D_8032FA88},{79,5,15,0,D_8032FA6C},{80,15,15,0,D_8032FB30}};

void BehPiranhaPlant2Loop(void)
{
    obj_call_action_function(TablePiranhaPlantActions);
    if(gCurrLevelNum == LEVEL_WF)
    {
        if(gMarioObject->oPosY > 3400.0f)
            obj_hide();
        else
            obj_unhide();
    }
    o->oInteractStatus = 0;
}

void func_802BDC60(s16 a0,void* a1,f32 a2,f32 a3,s8 a4,s8* a5)
{
    struct Object* sp1C = spawn_object(o,a0,a1); // bowser_puzzle_piece
    sp1C->oPosX += a2;
    sp1C->oPosY += 50.0f;
    sp1C->oPosZ += a3;
    sp1C->oAction = a4;
    sp1C->oBowserPuzzlePieceUnk10C = a5;
    sp1C->oBowserPuzzlePieceUnk110 = a5;
}

void func_802BDD0C(f32 a0)
{
    s32 i;
    for(i=0;i<14;i++)
        func_802BDC60(D_8032FB4C[i].unk0,beh_lll_bowser_puzzle_piece,D_8032FB4C[i].unk1*a0/10.0f,D_8032FB4C[i].unk2*a0/10.0f,D_8032FB4C[i].unk3,D_8032FB4C[i].unk4);
    o->oAction++;
}

void BehLLLBowserPuzzleLoop(void)
{
    s32 i;
    UNUSED struct Object* sp28;
    switch(o->oAction)
    {
    case 0:
        func_802BDD0C(480.0f);
        break;
    case 1:
        if(o->oBowserPuzzleUnkF4 == 3 && o->oDistanceToMario < 1000.0f)
        {
            for(i=0;i<5;i++)
                sp28 = spawn_object(o,116,beh_single_coin_gets_spawned);
            o->oBowserPuzzleUnkF4 = 0;
            o->oAction++;
        }
        break;
    case 2:
        break;
    }
}

void ActionBowserPuzzlePiece0(void) {}

void ActionBowserPuzzlePiece1(void)
{
    o->oPosY += 50.0f;
    o->oAction = 3;
}

void func_802BDF2C(void)
{
    s8* sp1C = o->oBowserPuzzlePieceUnk110;
    if(gMarioObject->platform == o)
        o->parentObj->oBowserPuzzleUnkF4 = 1;
    if(o->oBowserPuzzlePieceUnk108 == 0)
    {
        obj_change_action(*sp1C);
        sp1C++;
        o->oBowserPuzzlePieceUnk110 = sp1C;
        if(*sp1C == -1)
        {
            o->parentObj->oBowserPuzzleUnkF4 |= 2;
            o->oBowserPuzzlePieceUnk110 = o->oBowserPuzzlePieceUnk10C;
        }
        o->oBowserPuzzlePieceUnk108 = 1;
    }
}

void func_802BE014(f32 a0,f32 a1,s32 a2,UNUSED s32 a3)
{
    if(o->oTimer < 20)
    {
        if(o->oTimer%2)
            o->oBowserPuzzlePieceUnk100 = 0.0f;
        else
            o->oBowserPuzzlePieceUnk100 = -6.0f;
    }
    else
    {
        if(o->oTimer == 20)
            PlaySound2(0x90192081);
        if(o->oTimer < a2 + 20)
        {
            o->oBowserPuzzlePieceUnkFC += a0;
            o->oBowserPuzzlePieceUnk104 += a1;
        }
        else
        {
            o->oAction = 2;
            o->oBowserPuzzlePieceUnk108 = 0;
        }
    }
}

void ActionBowserPuzzlePiece2(void)
{
    UNUSED s32 sp4;
    if(o->oTimer < 24)
        sp4 = 0;
    else
        o->oBowserPuzzlePieceUnk108 = 0;
}

void ActionBowserPuzzlePiece3(void)
{
    func_802BE014(-120.0f,0.0f,4,4);
}

void ActionBowserPuzzlePiece4(void)
{
    func_802BE014(120.0f,0.0f,4,5);
}

void ActionBowserPuzzlePiece5(void)
{
    func_802BE014(0.0f,-120.0f,4,6);
}

void ActionBowserPuzzlePiece6(void)
{
    func_802BE014(0.0f,120.0f,4,3);
}

void (*TableBowserPuzzlePieceActions[])(void) = {ActionBowserPuzzlePiece0,ActionBowserPuzzlePiece1,ActionBowserPuzzlePiece2,ActionBowserPuzzlePiece3,ActionBowserPuzzlePiece4,ActionBowserPuzzlePiece5,ActionBowserPuzzlePiece6};

void BehLLLBowserPuzzlePieceLoop(void)
{
    func_802BDF2C();
    obj_call_action_function(TableBowserPuzzlePieceActions);
    o->oPosX = o->oBowserPuzzlePieceUnkFC + o->oHomeX;
    o->oPosY = o->oBowserPuzzlePieceUnk100 + o->oHomeY;
    o->oPosZ = o->oBowserPuzzlePieceUnk104 + o->oHomeZ;
}

s32 func_802BE2E8(s16 a0,s16 a1,s32 a2)
{
    f32 sp1C;
    if((sp1C = o->header.gfx.unk38.animAccel/(f32)0x10000) == 0)
        sp1C = 1.0f;
    if(func_8029F8D4(a0,sp1C) || func_8029F8D4(a1,sp1C))
    {
        PlaySound2(a2);
        return 1;
    }
    return 0;
}

void func_802BE3B4(s32 a0)
{
    s32 sp1C;
    if(o->oSoundStateID == 0)
    {
        if(a0 == 0)
            sp1C = 0x50020081; // TODO: Sound macro
        else
            sp1C = 0x50098081;
        func_802BE2E8(1,11,sp1C);
    }
}

void ActionTuxiesMother2(void)
{
    f32 sp24;
    UNUSED s32 unused;
    struct Object* sp1C = obj_find_nearest_object_with_behavior(beh_small_penguin,&sp24);
    UNUSED s32 unused2;
    if(obj_find_nearby_held_actor(beh_unused_20E0,1000.0f) != NULL)
    {
        if(o->oSubAction == 0)
        {
            func_8029ED38(0);
            o->oForwardVel = 10.0f;
            if(800.0f < obj_lateral_dist_from_mario_to_home())
                o->oSubAction = 1;
            obj_rotate_yaw_toward(o->oAngleToMario,0x400);
        }
        else
        {
            o->oForwardVel = 0.0f;
            func_8029ED38(3);
            if(obj_lateral_dist_from_mario_to_home() < 700.0f)
                o->oSubAction = 0;
        }
    }
    else
    {
        o->oForwardVel = 0.0f;
        func_8029ED38(3);
    }
    if(sp1C != NULL && sp24 < 300.0f && sp1C->oHeldState != HELD_FREE)
    {
        o->oAction = 1;
        sp1C->oUnk88 = 1;
        o->prevObj = sp1C;
    }
}

void ActionTuxiesMother1(void)
{
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    switch(o->oSubAction)
    {
    case 0:
        func_8029ED38(3);
        if(!obj_is_mario_on_platform())
        {
            sp2C = (o->oBehParams >> 0x10) & 0xFF;
            sp28 = (o->prevObj->oBehParams >> 0x10) & 0xFF;
            if(sp2C == sp28)
                sp24 = 58;
            else
                sp24 = 59;
            if(obj_update_dialogue_unk2(2,1,162,sp24))
            {
                if(sp24 == 58)
                    o->oSubAction = 1;
                else
                    o->oSubAction = 2;
                o->prevObj->oUnk190 |= 0x40;
            }
        }
        else
            func_8029ED38(0);
        break;
    case 1:
        if(o->prevObj->oHeldState == HELD_FREE)
        {
            ((s32*)o->prevObj)[o->oUnk190+34] &= ~0x40; //FIXME: find something more normal?
            set_object_behavior(o->prevObj,beh_unused_20E0);
#ifndef VERSION_JP
            obj_spawn_star_at_y_offset(3167.0f, -4300.0f, 5108.0f, 200.0f);
#else
            CreateStar(3500.0f,-4300.0f,4650.0f);
#endif
            o->oAction = 2;
        }
        break;
    case 2:
        if(o->prevObj->oHeldState == HELD_FREE)
        {
            ((s32*)o->prevObj)[o->oUnk190+34] &= ~0x40;
            set_object_behavior(o->prevObj,beh_penguin_baby);
            o->oAction = 2;
        }
        break;
    }
}

void ActionTuxiesMother0(void)
{
    s32 sp2C;
    f32 sp28;
    struct Object* sp24;
    sp2C = 0;
    sp24 = obj_find_nearest_object_with_behavior(beh_small_penguin,&sp28);
    obj_scale(4.0f);
    func_8029ED38(3);
    if(sp28 < 500.0f)
        sp2C = 1;
    if(sp24 != NULL && sp28 < 300.0f && sp24->oHeldState != HELD_FREE)
    {
        o->oAction = 1;
        sp24->oUnk88 = 1;
        o->prevObj = sp24;
    }
    else
    {
        switch(o->oSubAction)
        {
        case 0:
            if(obj_is_mario_in_range_and_ready_to_speak(300.0f,100.0f))
                if(sp2C == 0)
                    o->oSubAction++;
            break;
        case 1:
            if(obj_update_dialogue_unk2(2,1,162,57))
                o->oSubAction++;
            break;
        case 2:
            if(o->oDistanceToMario > 450.0f)
                o->oSubAction = 0;
            break;
        }
    }
    if(obj_check_anim_frame(1))
        PlaySound2(0x502D0081);
}

void (*TableTuxiesMotherActions[])(void) = {ActionTuxiesMother0,ActionTuxiesMother1,ActionTuxiesMother2};

void BehTuxiesMotherLoop(void)
{
    o->activeFlags |= 0x400;
    obj_update_floor_and_walls();
    obj_call_action_function(TableTuxiesMotherActions);
    obj_move_standard(-78);
    func_802BE3B4(1);
    o->oInteractStatus = 0;
}

void func_802BEA58(void)
{
    if(mario_is_dive_sliding())
    {
        o->oSmallPenguinUnk100 = o->oAction;
        o->oAction = 3;
    }
}

void ActionSmallPenguin2(void)
{
    s32 sp1C = 0;
    if(o->oTimer == 0)
        if(obj_dist_to_nearest_object_with_behavior(beh_tuxies_mother) < 1000.0f)
            sp1C = 1;
    func_8029ED38(0);
    o->oForwardVel = o->oSmallPenguinUnk104 + 3.0f;
    obj_rotate_yaw_toward(o->oAngleToMario+0x8000,o->oSmallPenguinUnk110+0x600);
    if(o->oDistanceToMario > o->oSmallPenguinUnk108 + 500.0f)
        o->oAction = 0;
    func_802BEA58();
    if(sp1C)
        o->oAction = 5;
}

void ActionSmallPenguin1(void)
{
    func_8029ED38(0);
    o->oForwardVel = o->oSmallPenguinUnk104 + 3.0f;
    obj_rotate_yaw_toward(o->oAngleToMario,o->oSmallPenguinUnk110+0x600);
    if(o->oDistanceToMario < o->oSmallPenguinUnk108 + 300.0f)
        o->oAction = 0;
    if(o->oDistanceToMario > 1100.0f)
        o->oAction = 0;
    func_802BEA58();
}

void ActionSmallPenguin3(void)
{
    if(o->oTimer > 5)
    {
        if(o->oTimer == 6)
            PlaySound2(0x501F4081);
        func_8029ED38(1);
        if(o->oTimer > 25)
            if(!mario_is_dive_sliding())
                o->oAction = 4;
    }
}

void ActionSmallPenguin4(void)
{
    if(o->oTimer > 20)
    {
        o->oForwardVel = 0.0f;
        func_8029ED38(2);
        if(o->oTimer > 40)
            o->oAction = o->oSmallPenguinUnk100;
    }
}

void ActionSmallPenguin0(void)
{
    s32 sp1C;

    sp1C = 0;
    func_8029ED38(3);
    if(o->oTimer == 0)
    {
        o->oSmallPenguinUnk110 = (s32)(RandomFloat() * 0x400);
        o->oSmallPenguinUnk108 = RandomFloat() * 100.0f;
        o->oSmallPenguinUnk104 = RandomFloat();
        o->oForwardVel = 0.0f;
        if(obj_dist_to_nearest_object_with_behavior(beh_tuxies_mother) < 1000.0f)
            sp1C = 1;
    }
    if(o->oDistanceToMario < 1000.0f && o->oSmallPenguinUnk108 + 600.0f < o->oDistanceToMario)
        o->oAction = 1;
    else if(o->oDistanceToMario < o->oSmallPenguinUnk108 + 300.0f)
        o->oAction = 2;
    if(sp1C)
        o->oAction = 5;
    if(obj_mario_far_away())
        obj_set_pos_to_home();
}

void ActionSmallPenguin5(void)
{
    f32 sp24;
    s16 sp22;
    struct Object* sp1C = obj_nearest_object_with_behavior(beh_tuxies_mother);
    if(sp1C != NULL)
    {
        if(o->oDistanceToMario < 1000.0f)
            o->oForwardVel = 2.0f;
        else
            o->oForwardVel = 0.0f;
        sp24 = dist_between_objects(o,sp1C);
        sp22 = angle_to_object(o,sp1C);
        if(sp24 > 200.0f)
            obj_rotate_yaw_toward(sp22,0x400);
        else
            obj_rotate_yaw_toward(sp22+0x8000,0x400);
        func_8029ED38(0);
    }
    func_802BEA58();
}

void (*TableSmallPenguinActions[])(void) = {ActionSmallPenguin0,ActionSmallPenguin1,ActionSmallPenguin2,ActionSmallPenguin3,ActionSmallPenguin4,ActionSmallPenguin5};

void func_802BF048(void)
{
    if(o->oUnk88 != 0)
    {
        o->oAction = 5;
        o->oUnk88 = 0;
    }
    obj_update_floor_and_walls();
    obj_call_action_function(TableSmallPenguinActions);
    obj_move_standard(-78);
    func_802BE3B4(0);
}

void BehSmallPenguinLoop(void)
{
    switch(o->oHeldState)
    {
    case 0:
        func_802BF048();
        break;
    case 1:
        func_8029FA5C(0,0);
        if(obj_has_behavior(beh_penguin_baby))
            set_object_behavior(o,beh_small_penguin);
        copy_object_pos(o,gMarioObject);
        if(gGlobalTimer % 30 == 0)
#ifndef VERSION_JP
            SetSound(0x90450081,&gMarioObject->header.gfx.unk54);
#else
            SetSound(0x90450081,&o->header.gfx.unk54);
#endif
        break;
    case 2:
        obj_get_thrown_or_placed(0, 0, 0);
        break;
    case 3:
        obj_get_dropped();
        break;
    }
}

s32    GeoSwitchCase802BFBAC(s32 a0,struct GraphNodeObject* a1,UNUSED Mat4 *a2)
{
    struct Object* sp24;
    struct GraphNodeObject* sp20;
    s32 sp1C;
    if(a0 == 1)
    {
        sp24 = (struct Object*)D_8032CFA0;
        sp20 = a1;
        sp20->angle[2] = 0;
        sp1C = gGlobalTimer % 50;
        if(sp1C < 43)
            sp20->angle[2] = 0;
        else if(sp1C < 45)
            sp20->angle[2] = 1;
        else if(sp1C < 47)
            sp20->angle[2] = 2;
        else
            sp20->angle[2] = 1;
        if(segmented_to_virtual(beh_tuxies_mother) == sp24->behavior)
            if(sp24->oForwardVel > 5.0f)
                sp20->angle[2] = 3;
    }
    return 0;
}

void ActionFish0(void)
{
    s32 i;
    s32 sp38;
    s16 sp36;
    f32 sp30;
    u32* sp2C;
    struct Object* sp28;
    switch(o->oBehParams2ndByte)
    {
    case 0:
        sp36 = 185;
        sp38 = 20;
        sp30 = 1500.0f;
        sp2C = blue_fish_seg3_anims_0301C2B0;
        break;
    case 1:
        sp36 = 185;
        sp38 = 5;
        sp30 = 1500.0f;
        sp2C = blue_fish_seg3_anims_0301C2B0;
        break;
    case 2:
        sp36 = 103;
        sp38 = 20;
        sp30 = 1500.0f;
        sp2C = cyan_fish_seg6_anims_0600E264;
        break;
    case 3:
        sp36 = 103;
        sp38 = 5;
        sp30 = 1500.0f;
        sp2C = cyan_fish_seg6_anims_0600E264;
        break;
    }
    if(o->oDistanceToMario < sp30 || gCurrLevelNum == LEVEL_SA)
    {
        for(i=0;i<sp38;i++)
        {
            sp28 = spawn_object(o,sp36,beh_fish_group2);
            sp28->oBehParams2ndByte = o->oBehParams2ndByte;
            func_8029EE20(sp28,sp2C,0);
            translate_object_xyz_random(sp28,700.0f);
        }
        o->oAction = 1;
    }
}

void ActionFish1(void)
{
    if(gCurrLevelNum != LEVEL_SA)
        if(gMarioObject->oPosY - o->oPosY > 2000.0f)
            o->oAction = 2;
}

void ActionFish2(void)
{
    o->oAction = 0;
}

void (*TableFishActions[])(void) = {ActionFish0,ActionFish1,ActionFish2};

void BehFishLoop(void)
{
    obj_call_action_function(TableFishActions);
}

void func_802BF59C(s32 a0)
{
    f32 sp1C = o->parentObj->oPosY;
    if(gCurrLevelNum == LEVEL_SA)
    {
        if(500.0f < absf(o->oPosY-o->oFishGroupUnkF8))
            a0 = 10;
        o->oPosY = approach_f32_symmetric(o->oPosY,o->oFishGroupUnkF8,a0);
    }
    else if(sp1C - 100.0f - o->oFishGroupUnk10C < o->oPosY && o->oPosY < sp1C + 1000.0f + o->oFishGroupUnk10C)
            o->oPosY = approach_f32_symmetric(o->oPosY,o->oFishGroupUnkF8,a0);
}

void ActionFishGroup1(void)
{
    f32 sp1C = o->oPosY - gMarioObject->oPosY;
    if(o->oTimer < 10)
        func_8029ED98(0,2.0f);
    else
        func_8029ED98(0,1.0f);
    if(o->oTimer == 0)
    {
        o->oForwardVel = RandomFloat() * 2.0f + 3.0f;
        if(gCurrLevelNum == LEVEL_SA)
            o->oFishGroupUnkFC = RandomFloat() * 700.0f;
        else
            o->oFishGroupUnkFC = RandomFloat() * 100.0f;
        o->oFishGroupUnk104 = RandomFloat() * 500.0f + 200.0f;
    }
    o->oFishGroupUnkF8 = gMarioObject->oPosY + o->oFishGroupUnkFC;
    obj_rotate_yaw_toward(o->oAngleToMario,0x400);
    if(o->oPosY < o->oFishGroupUnkF4 - 50.0f)
    {
        if(sp1C < 0.0f)
            sp1C = 0.0f - sp1C;
        if(sp1C < 500.0f)
            func_802BF59C(2);
        else
            func_802BF59C(4);
    }
    else
    {
        o->oPosY = o->oFishGroupUnkF4 - 50.0f;
        if(sp1C > 300.0f)
            o->oPosY = o->oPosY - 1.0f;
    }
    if(o->oDistanceToMario < o->oFishGroupUnk104 + 150.0f)
        o->oAction = 2;
}

void ActionFishGroup2(void)
{
    f32 sp1C = o->oPosY - gMarioObject->oPosY;
    s32 sp18;
    o->oFishGroupUnkF8 = gMarioObject->oPosY + o->oFishGroupUnkFC;
    if(o->oTimer == 0)
    {
        o->oFishGroupUnk110 = RandomFloat() * 300.0f;
        o->oFishGroupUnk100 = RandomFloat() * 1024.0f + 1024.0f;
        o->oFishGroupUnk108 = RandomFloat() * 4.0f + 8.0f + 5.0f;
        if(o->oDistanceToMario < 600.0f)
            sp18 = 1;
        else
            sp18 = (s32)(1.0/(o->oDistanceToMario/600.0));
        sp18 *= 127;
        PlaySound2(0x30090081);
    }
    if(o->oTimer < LEVEL_SA)
        func_8029ED98(0,4.0f);
    else
        func_8029ED98(0,1.0f);
    if(o->oForwardVel < o->oFishGroupUnk108)
        o->oForwardVel = o->oForwardVel + 0.5;
    o->oFishGroupUnkF8 = gMarioObject->oPosY + o->oFishGroupUnkFC;
    obj_rotate_yaw_toward(o->oAngleToMario+0x8000,o->oFishGroupUnk100);
    if(o->oPosY < o->oFishGroupUnkF4 - 50.0f)
    {
        if(sp1C < 0.0f)
            sp1C = 0.0f - sp1C;
        if(sp1C < 500.0f)
            func_802BF59C(2);
        else
            func_802BF59C(4);
    }
    else
    {
        o->oPosY = o->oFishGroupUnkF4 - 50.0f;
        if(sp1C > 300.0f)
            o->oPosY -= 1.0f;
    }
    if(o->oDistanceToMario > o->oFishGroupUnk110 + 500.0f)
        o->oAction = 1;
}

void ActionFishGroup0(void)
{
    func_8029ED98(0,1.0f);
    o->header.gfx.unk38.animFrame = (s16)(RandomFloat() * 28.0f);
    o->oFishGroupUnk10C = RandomFloat() * 300.0f;
    obj_scale(RandomFloat()*0.4+0.8);
    o->oAction = 1;
}

void (*TableFishGroupActions[])(void) = {ActionFishGroup0,ActionFishGroup1,ActionFishGroup2};

void BehFishGroup2Loop(void) //TODO rename
{
    UNUSED s32 unused[4];
    obj_scale(1.0f);
    o->oFishGroupUnkF4 = find_water_level(o->oPosX,o->oPosZ);
    if(gCurrLevelNum == LEVEL_SA)
        o->oFishGroupUnkF4 = 0.0f;
    o->oWallHitboxRadius = 30.0f;
    obj_resolve_wall_collisions();
    if(gCurrLevelNum != LEVEL_UNKNOWN_32)
    {
        if(o->oFishGroupUnkF4 < -10000.0f)
        {
            mark_object_for_deletion(o);
            return;
        }
    }
    else
        o->oFishGroupUnkF4 = 1000.0f;
    obj_call_action_function(TableFishGroupActions);
    obj_move_using_fvel_and_gravity();
    if(o->parentObj->oAction == 2)
        mark_object_for_deletion(o);
}

void BehWdwExpressElevatorLoop(void)
{
    o->oVelY = 0.0f;
    if(o->oAction == 0)
    {
        if(obj_is_mario_on_platform())
            o->oAction++;
    }
    else if(o->oAction == 1)
    {
        o->oVelY = -20.0f;
        o->oPosY += o->oVelY;
        PlaySound(0x400D0001);
        if(o->oTimer > 132)
            o->oAction++;
    }
    else if(o->oAction == 2)
    {
        if(o->oTimer > 110)
            o->oAction++;
    }
    else if(o->oAction == 3)
    {
        o->oVelY = 10.0f;
        o->oPosY += o->oVelY;
        PlaySound(0x400D0001);
        if(o->oPosY >= o->oHomeY)
        {
            o->oPosY = o->oHomeY;
            o->oAction++;
        }
    }
    else if(!obj_is_mario_on_platform())
        o->oAction = 0;
}

void ActionBirdChirpChirp0(void)
{
    s32 i;
    s32 sp18 = o->oBirdChirpChirpUnkF4;
    if(o->oDistanceToMario < 1500.0f)
    {
        for(i=0;i<sp18;i++)
            spawn_object(o,100,beh_bub);
        o->oAction = 1;
    }
}

void ActionBirdChirpChirp1(void)
{
    if(gMarioObject->oPosY - o->oPosY > 2000.0f)
        o->oAction = 2;
}

void ActionBirdChirpChirp2(void)
{
    o->oAction = 3;
}

void ActionBirdChirpChirp3(void)
{
    o->oAction = 0;
}

void (*TableBirdChirpChirpActions[])(void) = {ActionBirdChirpChirp0,ActionBirdChirpChirp1,ActionBirdChirpChirp2,ActionBirdChirpChirp3};

void BehBirdChirpChirpLoop(void)
{
    obj_call_action_function(TableBirdChirpChirpActions);
}

void func_802C0240(s32 a0)
{
    f32 sp1C = o->parentObj->oPosY;
    if(sp1C - 100.0f - o->oCheepCheepUnk104 < o->oPosY && o->oPosY < sp1C + 1000.0f + o->oCheepCheepUnk104)
        o->oPosY = approach_f32_symmetric(o->oPosY,o->oCheepCheepUnkF8,a0);
    else {}
}

void ActionCheepCheep0(void)
{
    o->oCheepCheepUnkFC = RandomFloat() * 100.0f;
    o->oCheepCheepUnk104 = RandomFloat() * 300.0f;
    o->oAction = 1;
}

void ActionCheepCheep1(void)
{
    f32 dy;
    if(o->oTimer == 0)
    {
        o->oForwardVel = RandomFloat() * 2.0f + 2.0f;
        o->oCheepCheepUnk108 = RandomFloat();
    }
    dy = o->oPosY - gMarioObject->oPosY;
    if(o->oPosY < o->oCheepCheepUnkF4 - 50.0f)
    {
        if(dy < 0.0f)
            dy = 0.0f - dy;
        if(dy < 500.0f)
            func_802C0240(1);
        else
            func_802C0240(4);
    }
    else
    {
        o->oPosY = o->oCheepCheepUnkF4 - 50.0f;
        if(dy > 300.0f)
            o->oPosY = o->oPosY - 1.0f;
    }
    if(800.0f < obj_lateral_dist_from_mario_to_home())
        o->oAngleToMario = obj_angle_to_home();
    obj_rotate_yaw_toward(o->oAngleToMario,0x100);
    if(o->oDistanceToMario < 200.0f)
        if(o->oCheepCheepUnk108 < 0.5)
            o->oAction = 2;
    if(o->oInteractStatus & 0x8000)
        o->oAction = 2;
}

void ActionCheepCheep2(void)
{
    f32 dy;
    if(o->oTimer < 20)
    {
        if(o->oInteractStatus & 0x8000)
            spawn_object(o,164,beh_small_particle_snow);
    }
    else
        o->oInteractStatus = 0;
    if(o->oTimer == 0)
        PlaySound2(0x30090081);
    if(o->oForwardVel == 0.0f)
        o->oForwardVel = 6.0f;
    dy = o->oPosY - gMarioObject->oPosY;
    if(o->oPosY < o->oCheepCheepUnkF4 - 50.0f)
    {
        if(dy < 0.0f)
            dy = 0.0f - dy;
        if(dy < 500.0f)
            func_802C0240(2);
        else
            func_802C0240(4);
    }
    else
    {
        o->oPosY = o->oCheepCheepUnkF4 - 50.0f;
        if(dy > 300.0f)
            o->oPosY -= 1.0f;
    }
    if(obj_lateral_dist_from_mario_to_home() > 800.0f)
        o->oAngleToMario = obj_angle_to_home();
    obj_rotate_yaw_toward(o->oAngleToMario+0x8000,0x400);
    if(o->oTimer > 200 && o->oDistanceToMario > 600.0f)
            o->oAction = 1;
}

void (*TableCheepCheepActions[])(void) = {ActionCheepCheep0,ActionCheepCheep1,ActionCheepCheep2};
struct ObjectHitbox D_8032FC30 = {0x200,5,0,1,0,40,30,40,30};
struct Struct802C0DF0 D_8032FC40[] = {{0,0,0,135,beh_wing_cap},{1,0,0,134,beh_metal_cap},{2,0,0,136,beh_vanish_cap},{3,0,0,190,beh_koopa_shell},{4,0,0,116,beh_single_coin_gets_spawned},{5,0,0,0,beh_three_coins_spawn},{6,0,0,0,beh_ten_coins_spawn},{7,0,0,212,beh_1up_walking},{8,0,0,122,beh_spawned_star},{9,0,0,212,beh_1up_running_away},{10,0,1,122,beh_spawned_star},{11,0,2,122,beh_spawned_star},{12,0,3,122,beh_spawned_star},{13,0,4,122,beh_spawned_star},{14,0,5,122,beh_spawned_star},{99,0,0,0,NULL}};

void BehCheepCheepLoop(void)
{
    o->oCheepCheepUnkF4 = find_water_level(o->oPosX,o->oPosZ);
    o->oCheepCheepUnkF8 = gMarioObject->oPosY + o->oCheepCheepUnkFC;
    o->oWallHitboxRadius = 30.0f;
    obj_update_floor_and_walls();
    obj_call_action_function(TableCheepCheepActions);
    obj_move_using_fvel_and_gravity();
    if(o->parentObj->oAction == 2)
        mark_object_for_deletion(o);
}

void BehRotatinExclamationBoxLoop(void)
{
    if(o->parentObj->oAction != 1)
        mark_object_for_deletion(o);
}

void ActionExclamationBox0(void)
{
    if(o->oBehParams2ndByte < 3)
    {
        o->oAnimState = o->oBehParams2ndByte;
        if((save_file_get_flags() & D_8032F0C0[o->oBehParams2ndByte]) || ((o->oBehParams >> 24) & 0xFF) != 0)
            o->oAction = 2;
        else
            o->oAction = 1;
    }
    else
    {
        o->oAnimState = 3;
        o->oAction = 2;
    }
}

void ActionExclamationBox1(void)
{
    obj_become_intangible();
    if(o->oTimer == 0)
    {
        spawn_object(o,132,beh_rotating_exclamation_mark);
        obj_set_model(131);
    }
    if((save_file_get_flags() & D_8032F0C0[o->oBehParams2ndByte]) || ((o->oBehParams >> 24) & 0xFF) != 0)
    {
        o->oAction = 2;
        obj_set_model(137);
    }
}

void ActionExclamationBox2(void)
{
    set_object_hitbox(o,&D_8032FC30);
    if(o->oTimer == 0)
    {
        obj_unhide();
        obj_become_tangible();
        o->oInteractStatus = 0;
        o->oPosY = o->oHomeY;
        o->oGraphYOffset = 0.0f;
    }
    if(obj_was_attacked_or_ground_pounded())
    {
        obj_become_intangible();
        o->oExclamationBoxUnkFC = 0x4000;
        o->oVelY = 30.0f;
        o->oGravity = -8.0f;
        o->oFloorHeight = o->oPosY;
        o->oAction = 3;
    }
    load_object_collision_model();
}

void ActionExclamationBox3(void)
{
    UNUSED s32 unused;
    obj_move_using_fvel_and_gravity();
    if(o->oVelY < 0.0f)
    {
        o->oVelY = 0.0f;
        o->oGravity = 0.0f;
    }
    o->oExclamationBoxUnkF8 =    (sins(o->oExclamationBoxUnkFC) + 1.0) * 0.3 + 0.0;
    o->oExclamationBoxUnkF4 = (-sins(o->oExclamationBoxUnkFC) + 1.0) * 0.5 + 1.0;
    o->oGraphYOffset = (-sins(o->oExclamationBoxUnkFC) + 1.0) * 26.0;
    o->oExclamationBoxUnkFC += 0x1000;
    o->header.gfx.scale[0] = o->oExclamationBoxUnkF4 * 2.0f;
    o->header.gfx.scale[1] = o->oExclamationBoxUnkF8 * 2.0f;
    o->header.gfx.scale[2] = o->oExclamationBoxUnkF4 * 2.0f;
    if(o->oTimer == 7)
        o->oAction = 4;
}

void func_802C0DF0(struct Struct802C0DF0* a0,u8 a1)
{
    struct Object* sp1C = NULL;
    while(a0->unk0!=99)
    {
        if(a1 == a0->unk0)
        {
            sp1C = spawn_object(o,a0->unk3,a0->unk4);
            sp1C->oVelY = 20.0f;
            sp1C->oForwardVel = 3.0f;
            sp1C->oMoveAngleYaw = gMarioObject->oMoveAngleYaw;
            o->oBehParams |= a0->unk2 << 24;
            if(a0->unk3 == 122)
                o->oFlags |= 0x4000;
            break;
        }
        a0++;
    }
}

void ActionExclamationBox4(void)
{
    func_802C0DF0(D_8032FC40,o->oBehParams2ndByte);
    func_802AA618(0,0,46.0f);
    func_802AD82C(20,139,0.3f,o->oAnimState);
    create_sound_spawner(0x3041C081);
    if(o->oBehParams2ndByte < 3)
    {
        o->oAction = 5;
        obj_hide();
    }
    else
        mark_object_for_deletion(o);
}

void ActionExclamationBox5(void)
{
    if(o->oTimer > 300)
        o->oAction = 2;
}

void (*TableExclamationBoxActions[])(void) = {ActionExclamationBox0,ActionExclamationBox1,ActionExclamationBox2,ActionExclamationBox3,ActionExclamationBox4,ActionExclamationBox5};
struct ObjectHitbox D_8032FCD8 = {8,0,1,1,0,130,100,0,0};
extern u8 bob_seg7_collision_gate[];
extern u8 hmc_seg7_collision_0702B65C[];
struct Struct8032FCE8 D_8032FCE8[] = {{320,56,bob_seg7_collision_gate},{410,60,hmc_seg7_collision_0702B65C}};
struct ObjectHitbox D_8032FCF8 = {0x1000000,0,0,0,0,1500,4000,0,0};

void BehExclamationBoxLoop(void)
{
    obj_scale(2.0f);
    obj_call_action_function(TableExclamationBoxActions);
}

void BehPlaySound(void)
{
    s32 sp1C = o->oUnknownUnkF4_S32; // sound spawner
    SetSound(sp1C,&o->header.gfx.unk54);
}

void BehBowsersSubLoop(void)
{
    if(save_file_get_flags() & (SAVE_FLAG_HAVE_KEY_2 | SAVE_FLAG_UNLOCKED_UPSTAIRS_DOOR))
        mark_object_for_deletion(o);
}

void BehSushiSharkCollisionLoop(void) {}

void BehSushiSharkLoop(void)
{
    f32 sp1C = find_water_level(o->oPosX,o->oPosZ);
    o->oPosX = o->oHomeX + sins(o->oSushiSharkUnkF4) * 1700.0f; 
    o->oPosZ = o->oHomeZ + coss(o->oSushiSharkUnkF4) * 1700.0f;
    o->oPosY = sp1C + o->oHomeY + sins(o->oSushiSharkUnkF4) * 200.0f;
    o->oMoveAngleYaw = o->oSushiSharkUnkF4 + 0x4000;
    o->oSushiSharkUnkF4 += 0x80;
    if(gMarioObject->oPosY - sp1C > -500.0f)
        if(o->oPosY - sp1C > -200.0f)
            spawn_object_with_scale(o,163,beh_water_type,4.0f);
    if((o->oTimer & 0xF) == 0)
        PlaySound2(0x50008081);
    o->oInteractStatus = 0;
}

void BehSunkenShipPartLoop(void)
{
    if(o->oDistanceToMario > 10000.0f)
        o->oOpacity = 140;
    else
        o->oOpacity = o->oDistanceToMario*140.0f/10000.0;
    obj_disable_rendering();
}

void BehShipPart3Loop(void)
{
    s16 sp1E = o->oFaceAnglePitch;
    s16 sp1C = o->oFaceAngleRoll;
    func_802A3470();
    o->oShipPart3UnkF4 += 0x100;
    o->oFaceAnglePitch = sins(o->oShipPart3UnkF4) * 1024.0f;
    o->oFaceAngleRoll    = sins(o->oShipPart3UnkF8) * 1024.0f;
    o->oAngleVelPitch = o->oFaceAnglePitch - sp1E;
    o->oAngleVelRoll = o->oFaceAngleRoll - sp1C;
    if(gMarioObject->oPosY > 1000.0f)
        PlaySound(0x400B0001);
}

void BehJrbSlidingBox(void)
{
    Mat4 sp60;
    Vec3f sp54;
    Vec3f sp48;
    Vec3s sp40;
    struct Object* sp3C;
    struct Surface* sp38;
    UNUSED Vec3f sp2C;
    Vec3f sp20;
    s16 sp1E;
    if(o->oJrbSlidingBoxUnkF4 == NULL)
    {
        sp3C = obj_nearest_object_with_behavior(beh_in_sunken_ship_3);
        if(sp3C != NULL) // NULL check only for assignment, not for dereference?
            o->oJrbSlidingBoxUnkF4 = sp3C;
        o->oParentRelativePosX = o->oPosX - sp3C->oPosX;
        o->oParentRelativePosY = o->oPosY - sp3C->oPosY;
        o->oParentRelativePosZ = o->oPosZ - sp3C->oPosZ;
    }
    else
    {
        sp3C = o->oJrbSlidingBoxUnkF4;
        sp40[0] = sp3C->oFaceAnglePitch;
        sp40[1] = sp3C->oFaceAngleYaw;
        sp40[2] = sp3C->oFaceAngleRoll;
        sp54[0] = o->oParentRelativePosX;
        sp54[1] = o->oParentRelativePosY;
        sp54[2] = o->oParentRelativePosZ;
        mtxf_rotate_zxy_and_translate(sp60,sp54,sp40);
        linear_mtxf_mul_vec3f(sp60,sp48,sp54);
        o->oPosX = sp3C->oPosX + sp48[0];
        o->oPosY = sp3C->oPosY + sp48[1];
        o->oPosZ = sp3C->oPosZ + sp48[2];
        sp1E = sp3C->oFaceAnglePitch;
    }
    sp20[0] = o->oPosX;
    sp20[1] = o->oPosY;
    sp20[2] = o->oPosZ;
    find_floor(sp20[0],sp20[1],sp20[2],&sp38);
    if(sp38 != NULL)
    {
        sp2C[0] = sp38->normal.x;
        sp2C[1] = sp38->normal.y;
        sp2C[2] = sp38->normal.z;
        o->oFaceAnglePitch = sp1E;
    }
    o->oJrbSlidingBoxUnkFC = sins(o->oJrbSlidingBoxUnkF8) * 20.0f;
    o->oJrbSlidingBoxUnkF8 += 0x100;
    o->oParentRelativePosZ += o->oJrbSlidingBoxUnkFC;
    if(gMarioObject->oPosY > 1000.0f)
        if(absf(o->oJrbSlidingBoxUnkFC) > 3.0f)
            PlaySound(0x60050001);
    set_object_hitbox(o,&D_8032FCD8);
    if(!(o->oJrbSlidingBoxUnkF8 & 0x7FFF))
        obj_become_tangible();
    if(are_objects_collided(o,gMarioObject))
    {
        o->oInteractStatus = 0;
        obj_become_intangible();
    }
}

void BehWhitePuff1Loop(void)
{
    f32 sp1C = 0.1f;
    f32 sp18 = 0.5f;
    if(o->oTimer == 0)
    {
        translate_object_xz_random(o,40.0f);
        o->oPosY += 30.0f;
    }
    obj_scale(o->oTimer*sp18+sp1C);
    o->oOpacity = 50;
    obj_move_using_fvel_and_gravity();
    if(o->oTimer > 4)
        mark_object_for_deletion(o);
}

void BehWhitePuff2Loop(void)
{
    if(o->oTimer == 0)
        translate_object_xz_random(o,40.0f);
}

void BehHiddenBlueCoinsLoop(void)
{
    struct Object* coinSwitch;
    switch(o->oAction)
    {
    case 0:
        obj_disable_rendering();
        obj_become_intangible();
        o->oHiddenBlueCoinsUnkF8 = obj_nearest_object_with_behavior(beh_blue_coin_switch);
        if(o->oHiddenBlueCoinsUnkF8 != NULL)
            o->oAction++;
        break;
    case 1:
        coinSwitch = o->oHiddenBlueCoinsUnkF8;
        if(coinSwitch->oAction == 2)
            o->oAction++;
        break;
    case 2:
        obj_enable_rendering();
        obj_become_tangible();
        if(o->oInteractStatus & 0x8000)
        {
            spawn_object(o,149,beh_golden_coin_sparkles);
            mark_object_for_deletion(o);
        }
        if(obj_wait_then_blink(200,20))
            mark_object_for_deletion(o);
        break;
    }
    o->oInteractStatus = 0;
}

void BehBlueCoinSwitchLoop(void)
{
    obj_scale(3.0f);
    switch(o->oAction)
    {
    case 0:
        if(gMarioObject->platform == o)
            if(gMarioStates->action == ACT_GROUND_POUND_LAND)
            {
                o->oAction++;
                o->oVelY = -20.0f;
                o->oGravity = 0.0f;
                PlaySound2(0x3067A081);
            }
        load_object_collision_model();
        break;
    case 1:
        if(o->oTimer > 5)
        {
            obj_hide();
            o->oAction++;
            o->oPosY = gMarioObject->oPosY - 40.0f;
            func_802AA618(0,0,46.0f);
        }
        else
        {
            load_object_collision_model();
            obj_move_using_fvel_and_gravity();
        }
        break;
    case 2:
        if(o->oTimer < 200)
            SetSound(0x8054F011,D_803320E0);
        else
            SetSound(0x8055F011,D_803320E0);
        if(obj_nearest_object_with_behavior(beh_hidden_blue_coin) == 0 || o->oTimer > 240)
            mark_object_for_deletion(o);
        break;
    }
}

void BehBobHmcCageDoorLoop(void)
{
    if(gCurrentObject->oAction == 0)
    {
        if(gCurrentObject->parentObj->oUnk88 != 0)
            gCurrentObject->oAction++;
    }
    else if(gCurrentObject->oAction == 1)
    {
        if(gCurrentObject->oTimer < 64)
            gCurrentObject->oMoveAngleYaw -= gCurrentObject->oBehParams2ndByte * 0x100;
        else
            gCurrentObject->oAction++;
    }
}

void BehOpenableGrillLoop(void)
{
    struct Object* sp3C;
    s32 sp38;
    switch(o->oAction)
    {
    case 0:
        sp38 = o->oBehParams2ndByte;
        sp3C = spawn_object_relative(-1,D_8032FCE8[sp38].unk0,0,0,o,D_8032FCE8[sp38].unk1,beh_bob_hmc_cage_door);
        sp3C->oMoveAngleYaw += 0x8000;
        set_object_collision_data(sp3C,D_8032FCE8[sp38].unk2);
        sp3C = spawn_object_relative(1,-D_8032FCE8[sp38].unk0,0,0,o,D_8032FCE8[sp38].unk1,beh_bob_hmc_cage_door);
        set_object_collision_data(sp3C,D_8032FCE8[sp38].unk2);
        o->oAction++;
        break;
    case 1:
        if((o->oOpenableGrillUnkF4 = obj_nearest_object_with_behavior(&beh_floor_switch_grills)) != NULL)
            o->oAction++;
        break;
    case 2:
        sp3C = o->oOpenableGrillUnkF4;
        if(sp3C->oAction == 2)
        {
            o->oUnk88 = 2;
            PlaySound2(0x303FA081);
            o->oAction++;
            if(o->oBehParams2ndByte != 0)
                func_80321228();
        }
        break;
    case 3:
        break;
    }
}

void BehInitChangingWaterLevelLoop(void)
{
    if(gCurrentObject->oAction == 0)
    {
        if(gWaterRegions != NULL)
            gCurrentObject->oAction++;
    }
    else if(gCurrentObject->oTimer < 10)
        *gWaterLevels = gWaterRegions[6];
    else
    {
        gWaterRegions[6] = *gWaterLevels + sins(o->oWaterLevelTriggerUnkF4) * 20.0f;
        gCurrentObject->oWaterLevelTriggerUnkF4 += 0x200;
    }
}

void BehWaterLevelDiamondLoop(void)
{
    if(gWaterRegions != NULL)
    {
        switch(o->oAction)
        {
        case 0:
            o->oFaceAngleYaw = 0;
            o->oWaterLevelTriggerUnkF8 = (s32)o->oPosY;
            if(o->oTimer > 10)
                o->oAction++;
            break;
        case 1:
            if(are_objects_collided(o,gMarioObject))
            {
                if(D_8035FEF2 == 0)
                {
                    o->oAction++;
                    D_8035FEF2 = 1;
                }
            }
            break;
        case 2:
            o->oAngleVelYaw = 0;
            *gWaterLevels = (s32)approach_f32_symmetric((f32)*gWaterLevels,(f32)o->oWaterLevelTriggerUnkF8,10.0f);
            if(*gWaterLevels == o->oWaterLevelTriggerUnkF8)
            {
                if((s16)o->oFaceAngleYaw == 0)
                    o->oAction++;
                else
                    o->oAngleVelYaw = 0x800;
            }
            else
            {
                if(o->oTimer == 0)
                    PlaySound2(0x30668081);
                else
                {
                    if(*gWaterLevels > o->oWaterLevelTriggerUnkF8)
                        PlaySound(0x41160001);
                    else
                        PlaySound(0x41160001); // same as above
                }
                o->oAngleVelYaw = 0x800;
            }
            break;
        case 3:
            if(!are_objects_collided(o,gMarioObject))
            {
                D_8035FEF2 = 0;
                o->oAction = 1;
                o->oAngleVelYaw = 0;
            }
            break;
        }
        o->oFaceAngleYaw += o->oAngleVelYaw;
    }
}

void func_802C231C(f32 a0)
{
    s16 sp6 = 0x2C00;
    f32 sp0 = a0 * 0.4;
    o->header.gfx.scale[0] = ((( coss(o->oTweesterUnkF4) + 1.0) * 0.5 * 0.3) + 1.0) * sp0;
    o->header.gfx.scale[1] = (((-coss(o->oTweesterUnkF4) + 1.0) * 0.5 * 0.5) + 0.5) * sp0;
    o->header.gfx.scale[2] = ((( coss(o->oTweesterUnkF4) + 1.0) * 0.5 * 0.3) + 1.0) * sp0;
    o->oTweesterUnkF4 += 0x200;
    o->oForwardVel = 14.0f;
    o->oFaceAngleYaw += sp6;
}

void ActionTweester0(void)
{
    if(o->oSubAction == 0)
    {
        obj_become_tangible();
        obj_set_pos_to_home();
        obj_scale(0);
        o->oTweesterUnkF8 = 0;
        if(o->oDistanceToMario < 1500.0f)
            o->oSubAction++;
        o->oTimer = 0;
    }
    else
    {
        PlaySound(0x40050001);
        func_802C231C(o->oTimer / 60.0f);
        if(o->oTimer > 59)
            o->oAction = 1;
    }
}

void ActionTweester1(void)
{
    f32 sp1C = o->oBehParams2ndByte * 0x64;
    o->oUnk1BC = obj_angle_to_home();
    PlaySound(0x40050001);
    if(obj_lateral_dist_from_mario_to_home() < sp1C && o->oSubAction == 0)
    {
        o->oForwardVel = 20.0f;
        obj_rotate_yaw_toward(o->oAngleToMario,0x200);
        print_debug_top_down_objectinfo("off ",0);
        if(gMarioStates->action == ACT_TWIRLING)
            o->oSubAction++;
    }
    else
    {
        o->oForwardVel = 20.0f;
        obj_rotate_yaw_toward(o->oUnk1BC,0x200);
        if(obj_lateral_dist_to_home() < 200.0f)
            o->oAction = 2;
    }
    if(o->oDistanceToMario > 3000.0f)
        o->oAction = 2;
    obj_update_floor_and_walls();
    if(o->oMoveFlags & 0x200)
        o->oMoveAngleYaw = o->oWallAngle;
    obj_move_standard(60);
    func_802C231C(1.0f);
    spawn_object(o,159,beh_tornado_sand_particle);
}

void ActionTweester2(void)
{
    f32 sp1C = 60.0f - o->oTimer;
    if(sp1C >= 0.0f)
        func_802C231C(sp1C / 60.0f);
    else
    {
        obj_become_intangible();
        if(obj_lateral_dist_from_mario_to_home() > 2500.0f)
            o->oAction = 0;
        if(o->oTimer > 360)
            o->oAction = 0;
    }
}

void (*TableTweesterActions[])(void) = {ActionTweester0,ActionTweester1,ActionTweester2};
struct ObjectHitbox D_8032FD14 = {0,0,3,3,0,140,80,40,60};
s16 D_8032FD24[][3] = {{0,50,0},{210,110,210},{-210,70,-210}};

void BehTweesterLoop(void)
{
    set_object_hitbox(o,&D_8032FCF8);
    obj_call_action_function(TableTweesterActions);
    o->oInteractStatus = 0;
}

void BehTweesterSandParticleLoop(void)
{
    o->oMoveAngleYaw += 0x3700;
    o->oForwardVel += 15.0f;
    o->oPosY += 22.0f;
    obj_scale(RandomFloat() + 1.0);
    if(o->oTimer == 0)
    {
        translate_object_xz_random(o,100.0f);
        o->oFaceAnglePitch = RandomU16();
        o->oFaceAngleYaw = RandomU16();
    }
    if(o->oTimer > 15)
        mark_object_for_deletion(o);
}

void func_802C2A28(void)
{
    o->oForwardVel = 0.0f;
    o->oVelY = 0.0f;
    o->oGravity = 0.0f;
}

void BehBooInit(void)
{
    o->oBooUnk110 = o->oMoveAngleYaw;
}

s32 func_802C2A94(void)
{
    if(obj_has_behavior(beh_spawned_boo) || obj_has_behavior(beh_spawned_boo_2))
    {
        if(D_8035FEF4 == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(o->activeFlags & 8)
            return 1;
        if(o->oRoom == 10)
            if(gTimeStopState & 0x20)
                return 1;
    }
    return 0;
}

s32 func_802C2B68(void)
{
    f32 sp1C;
    if(obj_has_behavior(beh_patrolling_boo))
        sp1C = 5000.0f;
    else
        sp1C = 1500.0f;
    if(obj_has_behavior(beh_spawned_boo) || obj_has_behavior(beh_spawned_boo_2))
    {
        if(D_8035FEF4 == 1)
            return 1;
        else
            return 0;
    }
    else if(o->oRoom == -1)
    {
        if(o->oDistanceToMario < sp1C)
            return 1;
    }
    else if(!func_802C2A94())
    {
        if(o->oDistanceToMario < sp1C && (o->oRoom == gMarioCurrentRoom || gMarioCurrentRoom == 0))
                return 1;
    }
    return 0;
}

void BehBooGroupInit(void)
{
    s32 i;
    struct Object* sp28;
    if(gDisplayedStars < 12)
        mark_object_for_deletion(o);
    else
    {
        for(i=0;i<3;i++)
        {
            sp28 = spawn_object_relative(1,D_8032FD24[i][0],D_8032FD24[i][1],D_8032FD24[i][2],o,84,beh_boo_2);
            sp28->oMoveAngleYaw = RandomU16();
        }
    }
}

void func_802C2D7C(void)
{
    f32 sp1C;
    if(o->oBooUnkF4 != o->oOpacity)
    {
        if(o->oBooUnkF4 > o->oOpacity)
        {
            o->oOpacity += 20;
            if(o->oBooUnkF4 < o->oOpacity)
                o->oOpacity = o->oBooUnkF4;
        }
        else
        {
            o->oOpacity -= 20;
            if(o->oBooUnkF4 > o->oOpacity)
                o->oOpacity = o->oBooUnkF4;
        }
    }
    sp1C = (o->oOpacity/255.0f * 0.4 + 0.6) * o->oBooUnkF8;
    scale_object(o,sp1C);
}

void func_802C2EB8(s32 a0)
{
    o->oFaceAnglePitch = sins(o->oBooUnkFC) * 0x400;
    if(o->oOpacity == 0xFF || a0 == 1)
    {
        o->header.gfx.scale[0] =    sins(o->oBooUnkFC) * 0.08 + o->oBooUnkF8;
        o->header.gfx.scale[1] = -sins(o->oBooUnkFC) * 0.08 + o->oBooUnkF8;
        o->header.gfx.scale[2] = o->header.gfx.scale[0];
        o->oGravity = sins(o->oBooUnkFC) * o->oBooUnkF8;
        o->oBooUnkFC += 0x400;
    }
}

s32 func_802C3008(void)
{
    s16 sp26 = abs_angle_diff(o->oAngleToMario,o->oMoveAngleYaw);
    s16 sp24 = abs_angle_diff(o->oMoveAngleYaw,gMarioObject->oFaceAngleYaw);
    s16 sp22 = 0x1568;
    s16 sp20 = 0x6b58;
    s32 sp1C = 0;
    o->oVelY = 0.0f;
    if(sp26 > sp22 || sp24 < sp20)
    {
        if(o->oOpacity == 40)
        {
            o->oBooUnkF4 = 0xFF;
            PlaySound2(0x50480081);
        }
        if(o->oOpacity > 180)
            sp1C = 1;
    }
    else if(o->oOpacity == 0xFF)
        o->oBooUnkF4 = 40;
    return sp1C;
}

void func_802C313C(s32 a0)
{
    obj_become_intangible();
    o->oFlags &= ~8;
    o->oBooUnk104 = (f32) o->oMoveAngleYaw;
    if(a0 != 0)
        o->oBooUnk100 = gMarioObject->oMoveAngleYaw;
    else if(coss((s16)o->oMoveAngleYaw - (s16)o->oAngleToMario) < 0.0f)
        o->oBooUnk100 = o->oMoveAngleYaw;
    else
        o->oBooUnk100 = (s16)(o->oMoveAngleYaw + 0x8000);
}

void func_802C3238(s32 a0,f32 a1)
{
    s32 sp4 = o->oTimer * 0x800 + 0x800;
    o->oForwardVel = a1;
    o->oVelY = coss(sp4);
    o->oMoveAngleYaw = o->oBooUnk100;
    if(a0 != 0)
    {
        o->oFaceAngleYaw    += D_8032F0CC[o->oTimer];
        o->oFaceAngleRoll += D_8032F0CC[o->oTimer];
    }
}

void func_802C3304(void)
{
    s32 sp4 = o->oTimer * 0x2000 + 0xFFFC2000;
    o->oFaceAngleYaw += coss(sp4) * 0x400;
}

void func_802C3384(void)
{
    o->oMoveAngleYaw = o->oBooUnk104;
    o->oFlags |= 8;
    o->oInteractStatus = 0;
}

s32 func_802C33D0(f32 a0)
{
    func_802C2A28();
    if(o->oTimer == 0)
        func_802C313C(0);
    if(o->oTimer < 32)
        func_802C3238(0,D_8032F0CC[o->oTimer]/5000.0f*a0);
    else
    {
        obj_become_tangible();
        func_802C3384();
        o->oAction = 1;
        return 1;
    }
    return 0;
}

s32 func_802C34B4(f32 a0)
{
    func_802C2A28();
    if(o->oTimer == 0)
        func_802C313C(1);
    if(o->oTimer < 32)
        func_802C3238(1,D_8032F0CC[o->oTimer]/5000.0f*a0);
    else if(o->oTimer < 48)
        func_802C3304();
    else
    {
        obj_become_tangible();
        func_802C3384();
        o->oAction = 1;
        return 1;
    }
    return 0;
}

s32 func_802C35C0(void)
{
    s32* sp1C; //FIXME
    if(o->oTimer == 0)
    {
        o->oForwardVel = 40.0f;
        o->oMoveAngleYaw = gMarioObject->oMoveAngleYaw;
        o->oUnk88 = 1;
        o->oFlags &= ~8;
    }
    else
    {
        if(o->oTimer == 5)
            o->oBooUnkF4 = 0;
        if(o->oTimer > 30 || o->oMoveFlags & 0x200)
        {
            func_802A3004();
            o->oUnk88 = 2;
#ifndef VERSION_JP
            if(o->oBooUnk108 != 0)
            {
		sp1C = o->oBooUnk108;
                if(!obj_has_behavior(beh_boo_3))
                {
                    sp1C[107]++;
                }
            }
#else
            if(o->oBooUnk108 != 0)
            {
                sp1C = o->oBooUnk108;
                sp1C[107]++;
            }
#endif
            return 1;
        }
    }
    o->oVelY = 5.0f;
    o->oFaceAngleRoll += 0x800;
    o->oFaceAngleYaw += 0x800;
    return 0;
}

s32 func_802C3738(u32 a0)
{
    if((o->oInteractStatus & 0xFF) == a0)
        return 1;
    else
        return 0;
}

s32 func_802C3778(void)
{
    s32 sp1C = 0;
    if(o->oInteractStatus & 0x8000)
    {
        if(o->oInteractStatus & 0x4000 && func_802C3738(3) == 0)
        {
            obj_become_intangible();
            o->oInteractStatus = 0;
            PlaySound2(0x500B0081);
            sp1C = 1;
        }
        else
        {
            PlaySound2(0x500A0081);
            o->oInteractStatus = 0;
            sp1C = -1;
        }
    }
    return sp1C;
}

void func_802C3830(f32 a0,s16 a1,f32 a2)
{
    f32 sp1C;
    s16 sp1A;
    if(func_802C3008())
    {
        o->oInteractType = 0x8000;
        if(obj_lateral_dist_from_mario_to_home() > 1500.0f)
            sp1A = obj_angle_to_home();
        else
            sp1A = o->oAngleToMario;
        obj_rotate_yaw_toward(sp1A,a1);
        o->oVelY = 0.0f;
        if(mario_is_in_air_action() == 0)
        {
            sp1C = o->oPosY - gMarioObject->oPosY;
            if(a0 < sp1C && sp1C < 500.0f)
                o->oVelY = func_802A0BF4(o->oPosY,gMarioObject->oPosY+50.0f,10.f,2.0f);
        }
        func_8029F684(10.0f-o->oBooUnk10C,a2);
        if(o->oForwardVel != 0.0f)
            func_802C2EB8(0);
    }
    else
    {
        o->oInteractType = 0;
        o->oForwardVel = 0.0f;
        o->oVelY = 0.0f;
        o->oGravity = 0.0f;
    }
}

void ActionBoo0(void)
{
    o->activeFlags |= 0x40;
    if(o->oBehParams2ndByte == 2)
        o->oRoom = 10;
    obj_set_pos_to_home();
    o->oMoveAngleYaw = o->oBooUnk110;
    func_802C2A28();
    o->oBooUnk108 = obj_nearest_object_with_behavior(beh_boo_giving_star);
    o->oBooUnkF8 = 1.0f;
    o->oBooUnkF4 = 0xFF;
    if(func_802C2B68())
    {
        if(o->oBehParams2ndByte == 2)
        {
            o->oBooUnk108 = 0;
            o->oAction = 5;
        }
        else
            o->oAction = 1;
    }
}

void ActionBoo5(void)
{
    if(o->oTimer < 30)
    {
        o->oVelY = 0.0f;
        o->oForwardVel = 13.0f;
        func_802C2EB8(0);
        o->oWallHitboxRadius = 0.0f;
    }
    else
    {
        o->oAction = 1;
        o->oWallHitboxRadius = 30.0f;
    }
}

void ActionBoo1(void)
{
    s32 sp1C;
    if(o->oTimer == 0)
    {
        o->oBooUnk10C = -RandomFloat() * 5.0f;
        o->oUnk1B0_S16 = (s32)(RandomFloat() * 128.0f);
    }
    func_802C3830(-100.0f,o->oUnk1B0_S16+0x180,0.5f);
    sp1C = func_802C3778();
    if(func_802C2A94())
        o->oAction = 0;
    if(sp1C == -1)
        o->oAction = 2;
    if(sp1C == 1)
        o->oAction = 3;
    if(sp1C == 1)
        create_sound_spawner(0x50244081);
}

void ActionBoo2(void)
{
    if(func_802C33D0(20.0f))
        o->oAction = 1;
}

void ActionBoo3(void)
{
    if(func_802C35C0())
    {
        if(o->oBehParams2ndByte != 0)
            mark_object_for_deletion(o);
        else
        {
            o->oAction = 4;
            func_8029FE00();
        }
    }
}

void ActionBoo4(void)
{
    s32 sp1C;
    if(obj_nearest_object_with_behavior(beh_boo_2) == NULL)
        sp1C = 108;
    else
        sp1C = 107;
    if(obj_update_dialogue_unk1(2,2,sp1C,0))
    {
        create_sound_spawner(0x50244081);
        mark_object_for_deletion(o);
        if(sp1C == 108)
            func_80321228();
    }
}

void (*TableBooActions[])(void) = {ActionBoo0,ActionBoo1,ActionBoo2,ActionBoo3,ActionBoo4,ActionBoo5};

void BehBooLoop(void)
{
    obj_update_floor_and_walls();
    obj_call_action_function(TableBooActions);
    obj_move_standard(78);
    func_802C2D7C();
    if(object_has_behavior(o->parentObj,beh_spawn_big_boo))
    {
        if(o->activeFlags == 0)
            o->parentObj->oUnk88++;
    }
    o->oInteractStatus = 0;
}

void ActionBooGivingStar0(void)
{
    if(obj_has_behavior(beh_patrolling_boo))
    {
        func_802C49E0();
        o->oUnk1AC_S32 = 10;
    }
    o->oBooUnk108 = 0;
#ifndef VERSION_JP
    if(func_802C2B68() && gDebugInfo[5][0] + 5 <= o->oUnk1AC_S32)
#else
    if(func_802C2B68() && o->oUnk1AC_S32 >= 5)
#endif
    {
        o->oAction = 1;
        obj_set_pos_to_home();
        o->oMoveAngleYaw = o->oBooUnk110;
        obj_unhide();
        o->oBooUnkF4 = 0xFF;
        o->oBooUnkF8 = 3.0f;
        o->oHealth = 3;
        obj_scale(3.0f);
        obj_become_tangible();
    }
    else
    {
        obj_hide();
        obj_become_intangible();
        func_802C2A28();
    }
}

void ActionBooGivingStar1(void)
{
    s32 sp24;
    s16 sp22;
    f32 sp1C;
    if(o->oHealth == 3)
    {
        sp22 = 0x180;
        sp1C = 0.5f;
    }
    else if(o->oHealth == 2)
    {
        sp22 = 0x240;
        sp1C = 0.6f;
    }
    else
    {
        sp22 = 0x300;
        sp1C = 0.8f;
    }
    func_802C3830(-100.0f,sp22,sp1C);
    sp24 = func_802C3778();
    if(obj_has_behavior(beh_spawned_boo))
    {
        if(D_8035FEF4 == 0)
            o->oAction = 0;
    }
    else if(func_802C2A94())
        o->oAction = 0;
    if(sp24 == -1)
        o->oAction = 2;
    if(sp24 == 1)
        o->oAction = 3;
    if(sp24 == 1)
        create_sound_spawner(0x500CA081);
}

void ActionBooGivingStar2(void)
{
    if(func_802C33D0(20.0f))
        o->oAction = 1;
}

void func_802C41AC(void)
{
    CreateStar(980.0f,1100.0f,250.0f);
}

void func_802C41E4(void)
{
    CreateStar(700.0f,3200.0f,1900.0f);
}

void func_802C4220(void)
{
    struct Object* sp1C;
    CreateStar(-1600.0f,-2100.0f,205.0f);
    sp1C = obj_nearest_object_with_behavior(beh_rotating_merry_go_round);
    if(sp1C != NULL)
        sp1C->oUnk88 = 1;
}

void ActionBooGivingStar3(void)
{
    if(o->oTimer == 0)
        o->oHealth--;
    if(o->oHealth == 0)
    {
        if(func_802C35C0())
        {
            func_8029FE00();
            o->oAction = 4;
            set_object_angle(o,0,0,0);
            if(o->oBehParams2ndByte == 0)
                func_802C41AC();
            else if(o->oBehParams2ndByte == 1)
                func_802C4220();
            else
                func_802C41E4();
        }
    }
    else
    {
        if(o->oTimer == 0)
        {
            func_802A3004();
            o->oBooUnkF8 -= 0.5;
        }
        if(func_802C34B4(40.0f))
            o->oAction = 1;
    }
}

void ActionBooGivingStar4(void)
{
#ifdef VERSION_US
    func_802C2A28();
#endif
    if(o->oBehParams2ndByte == 0)
    {
        set_object_pos(o,973,0,626);
        if(o->oTimer > 60 && o->oDistanceToMario < 600.0f)
        {
            set_object_pos(o,973,0,717);
            spawn_object_relative(0,0,0,     0,o,53,beh_boo_boss_spawned_bridge);
            spawn_object_relative(1,0,0,-200,o,53,beh_boo_boss_spawned_bridge);
            spawn_object_relative(2,0,0, 200,o,53,beh_boo_boss_spawned_bridge);
            mark_object_for_deletion(o);
        }
    }
    else
        mark_object_for_deletion(o);
}

void (*TableBooGivingStarActions[])(void) = {ActionBooGivingStar0,ActionBooGivingStar1,ActionBooGivingStar2,ActionBooGivingStar3,ActionBooGivingStar4};

void BehBooGivingStarLoop(void)
{
    set_object_hitbox(o,&D_8032FD14);
    o->oGraphYOffset = o->oBooUnkF8 * 60.0f;
    obj_update_floor_and_walls();
    obj_call_action_function(TableBooGivingStarActions);
    obj_move_standard(78);
    func_802C2D7C();
    o->oInteractStatus = 0;
}

void ActionBooWithCage0(void)
{
    o->oBooUnk108 = 0;
    o->oBooUnkF4 = 0xFF;
    o->oBooUnkF8 = 2.0f;
    obj_scale(2.0f);
    obj_become_tangible();
    if(func_802C2B68())
        o->oAction = 1;
}

void ActionBooWithCage1(void)
{
    s32 sp1C;

    func_802C3830(100.0f,512,0.5f);
    sp1C = func_802C3778();
    if(func_802C2A94())
        o->oAction = 0;
    if(sp1C == -1)
        o->oAction = 2;
    if(sp1C == 1)
        o->oAction = 3;
}

void ActionBooWithCage2(void)
{
    if(func_802C33D0(20.0f))
        o->oAction = 1;
}

void ActionBooWithCage3(void)
{
    if(func_802C35C0())
        mark_object_for_deletion(o);
}

void BehBooWithCageInit(void)
{
    struct Object* cage;
    if(gDisplayedStars < 12)
        mark_object_for_deletion(o);
    else
    {
        cage = spawn_object(o,90,beh_boo_cage);
        cage->oBehParams = o->oBehParams;
    }
}

void (*TableBooWithCageActions[])(void) = {ActionBooWithCage0,ActionBooWithCage1,ActionBooWithCage2,ActionBooWithCage3};
struct ObjectHitbox D_8032FD74 = {0x8000,0,1,1,3,130,70,90,60};

void BehBooWithCageLoop(void)
{
    obj_update_floor_and_walls();
    obj_call_action_function(TableBooWithCageActions);
    obj_move_standard(78);
    func_802C2D7C();
    o->oInteractStatus = 0;
}

void BehSpawnBigBooLoop(void)
{
    struct Object* sp24;
    switch(o->oAction)
    {
    case 0:
        if(o->oDistanceToMario < 1000.0f)
        {
            if(o->oUnk88 < 5)
            {
                if(o->oBooUnkFC != 5)
                {
                    if(o->oBooUnkFC - o->oUnk88 < 2)
                    {
                        spawn_object(o,84,beh_spawned_boo_2);
                        o->oBooUnkFC++;
                    }
                }
                o->oAction++;
            }
            if(o->oUnk88 > 4)
            {
                sp24 = spawn_object(o,84,beh_spawned_boo);
                copy_object_behavior_params(sp24,o);
                o->oAction = 2;
#ifndef VERSION_JP
                func_80321228();
#else
                SetSound(0x806AA081,D_803320E0);
#endif
            }
        }
        break;
    case 1:
            if(o->oTimer > 60)
                o->oAction = 0;
        break;
    case 2:
        break;
    }
}

void func_802C49E0(void)
{
    D_8032CFD0 = o;
}

void BehAnimatedTextureLoop(void)
{
    func_802A3470();
}

void BehBooInCastleLoop(void)
{
    s16 sp1E;
    o->oBooUnkF8 = 2.0f;
    if(o->oAction == 0)
    {
        obj_hide();
        if(gDisplayedStars < 12)
            mark_object_for_deletion(o);
        if(gMarioCurrentRoom == 1)
            o->oAction++;
    }
    else if(o->oAction == 1)
    {
        obj_unhide();
        o->oOpacity = 180;
        if(o->oTimer == 0)
            obj_scale(o->oBooUnkF8);
        if(o->oDistanceToMario < 1000.0f)
        {
            o->oAction++;
            PlaySound2(0x50480081);
        }
        o->oForwardVel = 0.0f;
        sp1E = o->oAngleToMario;
    }
    else
    {
        obj_obj_forward_vel_approach_upward(32.0f,1.0f);
        o->oHomeX = -1000.0f;
        o->oHomeZ = -9000.0f;
        sp1E = obj_angle_to_home();
        if(o->oPosZ < -5000.0f)
        {
            if(o->oOpacity > 0)
                o->oOpacity -= 20;
            else
                o->oOpacity = 0;
        }
        if(o->activeFlags & 8)
            o->oAction = 1;
    }
    o->oVelY = 0.0f;
    sp1E = obj_angle_to_home();
    obj_rotate_yaw_toward(sp1E,0x5A8);
    func_802C2EB8(1);
    obj_move_using_fvel_and_gravity();
}

void BehBooBossSpawnedBridgeLoop(void)
{
    f32 sp24;
    switch(o->oBehParams2ndByte)
    {
    case 1: sp24 = 0.0f;        break;
    case 0: sp24 = -206.0f; break;
    case 2: sp24 = -413.0f; break;
    }
    switch(o->oAction)
    {
    case 0:
        o->oPosY = o->oHomeY - 620.0f;
        o->oAction++;
    case 1:
        o->oPosY += 8.0f;
        PlaySound(0x40080001);
        if(o->oPosY > sp24)
        {
            o->oPosY = sp24;
            o->oAction++;
        }
        break;
    case 2:
        if(o->oTimer == 0)
            PlaySound2(0x303D0081);
        if(func_802A362C(o->oTimer))
            o->oAction++;
        break;
    case 3:
        if(o->oTimer == 0 && o->oBehParams2ndByte == 1)
            func_80321228();
        break;
    }
}

void BehBbhTiltFloorPlatformLoop(void)
{
#ifndef VERSION_JP
    UNUSED s32 unused;
    if (gMarioObject->platform == o)
        o->oAction = 0;
    else
        o->oAction = 1;
    
    if (o->oAction == 0)
    {
        o->oAngleVelPitch = (s32)(o->oDistanceToMario * coss(o->oAngleToMario));
        o->oFaceAnglePitch += o->oAngleVelPitch;
    }
    else
    {
        if ((absi(o->oFaceAnglePitch) < 3000) || (o->oTimer >= 16))
        {
            o->oAngleVelPitch = 0;
            if((s16)o->oFaceAnglePitch > 0)
            {
                if(o->oFaceAnglePitch < 200)
                    o->oFaceAnglePitch = 0;
                else
                    o->oAngleVelPitch = -200;
            }
            else
            {
                if (o->oFaceAnglePitch > -200)
                    o->oFaceAnglePitch = 0;
                else
                    o->oAngleVelPitch = 200;
            }
        }
    }
    o->oFaceAnglePitch += o->oAngleVelPitch;
#else
    UNUSED s32 unused;
    if(gMarioObject->platform == o)
    {
        o->oAngleVelPitch = (s32)(o->oDistanceToMario * coss(o->oAngleToMario));
        o->oFaceAnglePitch += o->oAngleVelPitch;
    }
    else
    {
        o->oAngleVelPitch = 0;
        if((s16)o->oFaceAnglePitch > 0)
        {
            if(o->oFaceAnglePitch < 200)
                o->oFaceAnglePitch = 0;
            else
                o->oAngleVelPitch = -200;
        }
        else if(o->oFaceAnglePitch > -200)
            o->oFaceAnglePitch = 0;
        else
            o->oAngleVelPitch = 200;
    }
    o->oFaceAnglePitch += o->oAngleVelPitch;
#endif
}

void BehTumblingBookshelfLoop(void)
{
    o->oDistanceToMario = dist_between_objects(o,gMarioObject); //hmm...
    o->oFaceAngleYaw = 0;
    switch(o->oAction)
    {
    case 0:
        if(o->oTimer == 0) {}
        if(o->oUnk88 != 0)
            o->oAction++;
        break;
    case 1:
        o->oPosX += 5.0f;
        PlaySound(0x410D0001);
        if(o->oTimer > 101)
            mark_object_for_deletion(o);
        break;
    default:
        break;
    }
}

void func_802C50F4(void)
{
    struct Surface* sp1C;
    u16 sp1A;
    if(o->oRotatingMerryGoRoundUnkF8 == 0)
    {
        if(gMarioCurrentRoom == 10)
        {
            func_80320F84(19,45,20,200);
            o->oRotatingMerryGoRoundUnkF8++;
        }
    }
    else
    {
        find_floor(gMarioObject->oPosX,gMarioObject->oPosY,gMarioObject->oPosZ,&sp1C);
        if(sp1C == NULL)
            sp1A = 0;
        else
            sp1A = sp1C->type;
        if(obj_is_mario_on_platform() || sp1A == SURFACE_001A)  //Surface 1A is floor of Merry-Go-Round
        {
            func_80320F84(19,0,78,50);
            D_8035FEF4 = 1;
        }
        else
        {
            func_80320F84(19,45,20,200);
            D_8035FEF4 = 0;
        }
        if(gMarioCurrentRoom != 0 && gMarioCurrentRoom != 10)
        {
            func_80321080(300);
            o->oRotatingMerryGoRoundUnkF8 = 0;
        }
        else
            PlaySound(0x400F4001);
    }
}

void BehRotatingMerryGoRoundLoop(void)
{
    if(o->oRotatingMerryGoRoundUnkFC == 0)
    {
        if(gMarioCurrentRoom == 13)
            o->oRotatingMerryGoRoundUnkFC++;
    }
    else
    {
        SetSound(0x60098001,D_803320E0);
        if(gMarioCurrentRoom != 13 && gMarioCurrentRoom != 0)
            o->oRotatingMerryGoRoundUnkFC = 0;
    }
    if(o->oUnk88 == 0)
    {
        o->oAngleVelYaw = 0x80;
        o->oMoveAngleYaw += o->oAngleVelYaw;
        o->oFaceAngleYaw += o->oAngleVelYaw;
        func_802C50F4();
    }
    else
    {
        o->oAngleVelYaw = 0;
        func_80321080(300);
    }
}

void BehStaticCheckeredPlatformLoop(void)
{
    if(gDebugInfo[5][0] == 1)
    {
        set_object_angle(o,0,0,0);
        o->oAngleVelPitch = 0;
        o->oAngleVelYaw = 0;
        o->oAngleVelRoll = 0;
    }
    if(gDebugInfo[5][0] == 2)
    {
        o->oFaceAnglePitch = gDebugInfo[5][1] << 12;
        o->oFaceAngleYaw = gDebugInfo[5][2] << 12;
        o->oFaceAngleRoll = gDebugInfo[5][3] << 12;
    }
    o->oAngleVelPitch = gDebugInfo[5][4];
    o->oAngleVelYaw = gDebugInfo[5][5];
    o->oAngleVelRoll = gDebugInfo[5][6];
    if(gDebugInfo[5][0] == 3)
    {
        o->oFaceAnglePitch += o->oAngleVelPitch;
        o->oFaceAngleYaw += o->oAngleVelYaw;
        o->oFaceAngleRoll += o->oAngleVelRoll;
    }
}

void BehInsideCannonLoop(void)
{
    obj_set_pos_relative(gMarioObject,0,30.0f,300.0f);
    o->hitboxRadius = gDebugInfo[4][0] + 100;
    o->hitboxHeight = gDebugInfo[4][1] + 300;
    attack_collided_non_mario_object(o);
}

#ifdef VERSION_US
void BehPlayMusicTrackWhenTouchedLoop(void)
{
    if(o->oAction == 0)
    {
        if(o->oDistanceToMario < 200.0f)
        {
            func_80321228();
            o->oAction++;
        }
    }
}
#endif

void BehFloorTrapInCastleLoop(void)
{
    if(gMarioObject->platform == o)
        o->parentObj->oInteractStatus |= 0x100000;
    o->oFaceAngleRoll = o->parentObj->oFaceAngleRoll;
}

void BehCastleFloorTrapInit(void)
{
    struct Object* sp2C;
    sp2C = spawn_object_relative(0,-358,0,0,o,53,beh_floor_trap_in_castle);
    sp2C = spawn_object_relative(0, 358,0,0,o,53,beh_floor_trap_in_castle);
    sp2C->oMoveAngleYaw += 0x8000;
}

void func_802C567C(void)
{
    if(gMarioStates->action == ACT_SPECIAL_EXIT_AIRBORNE || gMarioStates->action == ACT_SPECIAL_DEATH_EXIT)
        o->oAction = 4;
    else
    {
    o->oAngleVelRoll = 0x400;
    if(o->oInteractStatus & 0x100000)
        o->oAction = 1;
    }
}

void func_802C5700(void)
{
    if(o->oTimer == 0)
        PlaySound2(0x300E8081);
    o->oAngleVelRoll -= 0x100;
    o->oFaceAngleRoll += o->oAngleVelRoll;
    if(o->oFaceAngleRoll < -0x4000)
    {
        o->oFaceAngleRoll = -0x4000;
        o->oAction = 2;
    }
}

void func_802C57A4(void)
{
    if(o->oDistanceToMario > 1000.0f)
        o->oAction = 3;
}

void func_802C57E8(void)
{
    o->oFaceAngleRoll += 0x400;
    if(o->oFaceAngleRoll > 0)
    {
        o->oFaceAngleRoll = 0;
        o->oAction = 0;
        o->oInteractStatus &= 0xFFEFFFFF;
    }
}

void func_802C5854(void)
{
    o->oFaceAngleRoll = -0x3C00;
}

void BehCastleFloorTrapLoop(void)
{
    UNUSED s32 unused[3];
    switch(o->oAction)
    {
    case 0: func_802C567C(); break;
    case 1: func_802C5700(); break;
    case 2: func_802C57A4(); break;
    case 3: func_802C57E8(); break;
    case 4: func_802C5854(); break;
    }
}

void BehClimbDetectLoop(void)
{
    if(o->oPosY - 10.0f < gMarioObject->oPosY && gMarioObject->oPosY < o->oPosY + o->hitboxHeight + 30.0f)
        if(o->oTimer > 10)
            if(!(gMarioStates->action & MARIO_PUNCHING))
                obj_push_mario_away(70.0f);
}

void BehPowerupSparklesLoop(void)
{
    struct Object* sp24 = try_to_spawn_object(0,1.0f,o,143,beh_powerup_sparkles1);
    if(sp24 != NULL)
    {
        translate_object_xyz_random(sp24,90.0f);
        scale_object_random(sp24,1.0f,0.0f);
    }
    if(o->oTimer > 1)
        mark_object_for_deletion(o);
}

s32 func_802C5A64(s32* a0)
{
    if(o->oMoveFlags & 0x200)
    {
        *a0 = o->oWallAngle;
        return 1;
    }
    else if(o->oMoveFlags & 0x400)
    {
        *a0 = o->oMoveAngleYaw + 0x8000;
        return -1;
    }
    return 0;
}

void BehScuttlebugLoop(void)
{
    UNUSED s32 unused;
    f32 sp18;
    obj_update_floor_and_walls();
    if(o->oSubAction != 0 && obj_set_hitbox_and_die_if_attacked(&D_8032FD74,0x50244081,o->oScuttlebugUnkF4))
        o->oSubAction = 3;
    if(o->oSubAction != 1)
        o->oScuttlebugUnkF8 = 0;
    switch(o->oSubAction)
    {
    case 0:
        if(o->oMoveFlags & 1)
            PlaySound2(0x502F0081);
        if(o->oMoveFlags & 3)
        {
            o->oHomeX = o->oPosX;
            o->oHomeY = o->oPosY;
            o->oHomeZ = o->oPosZ;
            o->oSubAction++;
        }
        break;
    case 1:
        o->oForwardVel = 5.0f;
        if(obj_lateral_dist_from_mario_to_home() > 1000.0f)
            o->oAngleToMario = obj_angle_to_home();
        else
        {
            if(o->oScuttlebugUnkF8 == 0)
            {
                o->oScuttlebugUnkFC = 0;
                o->oAngleToMario = angle_to_object(o,gMarioObject);
                if(abs_angle_diff(o->oAngleToMario,o->oMoveAngleYaw) < 0x800)
                {
                    o->oScuttlebugUnkF8 = 1;
                    o->oVelY = 20.0f;
                    PlaySound2(0x90444081);
                }
            }
            else if(o->oScuttlebugUnkF8 == 1)
            {
                o->oForwardVel = 15.0f;
                o->oScuttlebugUnkFC++;
                if(o->oScuttlebugUnkFC > 50)
                    o->oScuttlebugUnkF8 = 0;
            }
        }
        if(func_802C5A64(&o->oAngleToMario))
            o->oSubAction = 2;
        obj_rotate_yaw_toward(o->oAngleToMario,0x200);
        break;
    case 2:
        o->oForwardVel = 5.0f;
        if((s16)o->oMoveAngleYaw == (s16)o->oAngleToMario)
            o->oSubAction = 1;
        if(o->oPosY - o->oHomeY < -200.0f)
            mark_object_for_deletion(o);
        obj_rotate_yaw_toward(o->oAngleToMario,0x400);
        break;
    case 3:
        o->oFlags &= ~8;
        o->oForwardVel = -10.0f;
        o->oVelY = 30.0f;
        PlaySound2(0x90444081);
        o->oSubAction++;
        break;
    case 4:
        o->oForwardVel = -10.0f;
        if(o->oMoveFlags & 1)
        {
            o->oSubAction++;
            o->oVelY = 0.0f;
            o->oScuttlebugUnkFC = 0;
            o->oFlags |= 8;
            o->oInteractStatus = 0;
        }
        break;
    case 5:
        o->oForwardVel = 2.0f;
        o->oScuttlebugUnkFC++;
        if(o->oScuttlebugUnkFC > 30)
            o->oSubAction = 0;
        break;
    }
    if(o->oForwardVel < 10.0f)
        sp18 = 1.0f;
    else
        sp18 = 3.0f;
    func_8029ED98(0,sp18);
    if(o->oMoveFlags & 3)
        func_802BE2E8(1,23,0x90434081);
    if(o->parentObj != o)
    {
        if(obj_is_hidden(o))
            mark_object_for_deletion(o);
        if(o->activeFlags == 0)
            o->parentObj->oUnk88 = 1;
    }
    obj_move_standard(-50);
}

void BehScuttlebugSpawnLoop(void)
{
    struct Object* scuttlebug;
    if(o->oAction == 0)
    {
        if(o->oTimer > 30 && 500.0f < o->oDistanceToMario && o->oDistanceToMario < 1500.0f)
        {
            PlaySound2(0x90444081);
            scuttlebug = spawn_object(o,101,beh_scuttlebug);
            scuttlebug->oScuttlebugUnkF4 = o->oScuttlebugSpawnerUnkF4;
            scuttlebug->oForwardVel = 30.0f;
            scuttlebug->oVelY = 80.0f;
            o->oAction++;
            o->oScuttlebugUnkF4 = 1;
        }
    }
    else if(o->oUnk88 != 0)
    {
        o->oUnk88 = 0;
        o->oAction = 0;
    }
}

void func_802C61CC(void)
{
    UNUSED s32 sp2C = o->header.gfx.unk38.animFrame;
    s32 sp28 = 0;
    if(o->oForwardVel < 5.0f)
    {
        sp28 = obj_check_anim_frame(0);
        sp28 |= obj_check_anim_frame(23);
    }
    else
    {
        sp28 = func_8029F8D4(0,3);
        sp28 |= func_8029F8D4(23,3);
    }
    if(sp28)
        PlaySound2(0x50155081);
}

void ActionWhomp0(void)
{
    func_8029ED98(0,1.0f);
    obj_set_pos_to_home();
    if(o->oBehParams2ndByte != 0)
    {
        D_8032CFD0 = o;
        obj_scale(2.0f);
        if(o->oSubAction == 0)
        {
            if(o->oDistanceToMario < 600.0f)
            {
                o->oSubAction++;
                func_8031FFB4(0, 0x3c, 0x28);
            }
            else
            {
                obj_set_pos_to_home();
                o->oHealth = 3;
            }
        }
        else if(obj_update_dialogue_unk2(2,1,162,114))
            o->oAction = 2;
    }
    else if(o->oDistanceToMario < 500.0f)
        o->oAction = 1;
    func_802C61CC();
}

void ActionWhomp7(void)
{
    if(o->oSubAction == 0)
    {
        o->oForwardVel = 0.0f;
        func_8029ED98(0,1.0f);
        if(o->oTimer > 31)
            o->oSubAction++;
        else
            o->oMoveAngleYaw += 0x400;
    }
    else
    {
        o->oForwardVel = 3.0f;
        if(o->oTimer > 42)
            o->oAction = 1;
    }
    func_802C61CC();
}

void ActionWhomp1(void)
{
    s16 sp26;
    f32 sp20;
    f32 sp1C;
    sp26 = abs_angle_diff(o->oAngleToMario,o->oMoveAngleYaw);
    sp20 = obj_lateral_dist_to_home();
    if(gCurrLevelNum == LEVEL_BITS)
        sp1C = 200.0f;
    else
        sp1C = 700.0f;
    func_8029ED98(0,1.0f);
    o->oForwardVel = 3.0f;
    if(sp20 > sp1C)
        o->oAction = 7;
    else if(sp26 < 0x2000)
    {
        if(o->oDistanceToMario < 1500.0f)
        {
            o->oForwardVel = 9.0f;
            func_8029ED98(0,3.0f);
        }
        if(o->oDistanceToMario < 300.0f)
            o->oAction = 3;
    }
    func_802C61CC();
}

void ActionWhomp2(void)
{
    s16 sp1E;
    func_8029ED98(0,1.0f);
    o->oForwardVel = 3.0f;
    obj_rotate_yaw_toward(o->oAngleToMario,0x200);
    if(o->oTimer > 30)
    {
        sp1E = abs_angle_diff(o->oAngleToMario,o->oMoveAngleYaw);
        if(sp1E < 0x2000)
        {
            if(o->oDistanceToMario < 1500.0f)
            {
                o->oForwardVel = 9.0f;
                func_8029ED98(0,3.0f);
            }
            if(o->oDistanceToMario < 300.0f)
                o->oAction = 3;
        }
    }
    func_802C61CC();
    if(func_802A6AF8(1000.0f))
    {
        o->oAction = 0;
        func_80320CE8(1046);
    }
}

void ActionWhomp3(void)
{
    o->oForwardVel = 0.0f;
    func_8029ED98(1,1.0f);
    if(func_8029F788())
        o->oAction = 4;
}

void ActionWhomp4(void)
{
    if(o->oTimer == 0)
        o->oVelY = 40.0f;
    if(o->oTimer < 8) {}
    else
    {
        o->oAngleVelPitch += 0x100;
        o->oFaceAnglePitch += o->oAngleVelPitch;
        if(o->oFaceAnglePitch > 0x4000)
        {
                o->oAngleVelPitch = 0;
            o->oFaceAnglePitch = 0x4000;
            o->oAction = 5;
        }
    }
}

void ActionWhomp5(void)
{
    if(o->oSubAction == 0 && o->oMoveFlags & 1)
    {
        PlaySound2(0x50166081);
        ShakeScreen(1);
        o->oVelY = 0.0f;
        o->oSubAction++;
    }
    if(o->oMoveFlags & 2)
        o->oAction = 6;
}

void func_802C6954(void)
{
    Vec3f pos;
    if(o->oSubAction == 0)
    {
        if(obj_is_mario_ground_pounding_platform())
        {
            o->oHealth--;
            PlaySound2(0x935AC081);
            PlaySound2(0x5147C081);
            if(o->oHealth == 0)
                o->oAction = 8;
            else
            {
                func_802B8F7C(pos,&o->oPosX);
                func_802B8F7C(&o->oPosX,&gMarioObject->oPosX);
                func_802AA618(0,0,100.0f);
                func_802AD82C(20,138,3.0f,4);
                ShakeScreen(1);
                func_802B8F7C(&o->oPosX,pos);
            }
            o->oSubAction++;
        }
        o->oWhompUnkF8 = 0;
    }
    else
    {
        if(o->oWhompUnkF8 < 10)
        {
            if(o->oWhompUnkF8 % 2)
                o->oPosY += 8.0f;
            else
                o->oPosY -= 8.0f;
        }
        else
            o->oSubAction = 10;
        o->oWhompUnkF8++;
    }
}

void func_802C6B28(void)
{
    if(o->oSubAction == 0)
    {
        if(gMarioObject->platform == o)
        {
            if(obj_is_mario_ground_pounding_platform())
            {
                o->oNumLootCoins = 5;
                spawn_object_loot_yellow_coins(o,5,20.0f);
                o->oAction = 8;
            }
            else
            {
                obj_spawn_loot_coin_at_mario_pos();
                o->oSubAction++;
            }
        }
    }
    else if(!obj_is_mario_on_platform())
        o->oSubAction = 0;
}

void ActionWhomp6(void)
{
    if(o->oSubAction != 10)
    {
        o->oForwardVel = 0.0f;
        o->oAngleVelPitch = 0;
        o->oAngleVelYaw = 0;
        o->oAngleVelRoll = 0;
        if(o->oBehParams2ndByte != 0)
            func_802C6954();
        else
            func_802C6B28();
        if(o->oTimer > 100 || (gMarioState->action == ACT_SQUISHED && o->oTimer > 30))
            o->oSubAction = 10;
    }
    else
    {
        if(o->oFaceAnglePitch > 0)
        {
            o->oAngleVelPitch = -0x200;
            o->oFaceAnglePitch += o->oAngleVelPitch;
        }
        else
        {
            o->oAngleVelPitch = 0;
            o->oFaceAnglePitch = 0;
            if(o->oBehParams2ndByte != 0)
                o->oAction = 2;
            else
                o->oAction = 1;
        }
    }
}

void ActionWhomp8(void)
{
    if(o->oBehParams2ndByte != 0)
    {
        if(obj_update_dialogue_unk2(2,2,162,115))
        {
            set_object_angle(o,0,0,0);
            obj_hide();
            obj_become_intangible();
            func_802AA618(0,0,200.0f);
            func_802AD82C(20,138,3.0f,4);
            ShakeScreen(1);
            o->oPosY += 100.0f;
            CreateStar(180.0f,3880.0f,340.0f);
            PlaySound2(0x5147C081);
            o->oAction = 9;
        }
    }
    else
    {
        func_802AA618(0,0,100.0f);
        func_802AD82C(20,138,3.0f,4);
        ShakeScreen(1);
        create_sound_spawner(0x500Ca081);
        mark_object_for_deletion(o);
    }
}

void ActionWhomp9(void)
{
    if(o->oTimer == 60)
        func_80320CE8(1046);
}

void (*TableWhompActions[])(void) = {ActionWhomp0,ActionWhomp1,ActionWhomp2,ActionWhomp3,ActionWhomp4,ActionWhomp5,ActionWhomp6,ActionWhomp7,ActionWhomp8,ActionWhomp9};
struct Struct8029E388 D_8032FDAC = {2 ,164,beh_water_drops,0,0,5.0f,3.0f,30.0f,20.0f,0.5f,1.0f};
struct Struct8029E388 D_8032FDD0 = {34,164,beh_water_drops,0,0,2.0f,3.0f,20.0f,20.0f,0.5f,1.0f};
struct Struct8029E388 D_8032FDF4 = {34,185,beh_water_drops,0,0,2.0f,3.0f,20.0f,20.0f,1.0f,0.0f};
struct Struct8029E388 D_8032FE18 = {98,164,beh_water_drops,0x6000,0,2.0f,8.0f,10.0f,10.0f,0.5f,1.0f};
struct ObjectHitbox D_8032FE3C = {0x400,0,0,0,0,20,70,20,70};
struct Struct8032FE4C D_8032FE4C[] = {{60,0,6.0f,1.0f},{30,3,0.0f,1.0f},{30,0,12.0f,2.0f},{30,3,0.0f,1.0f},{30,0,-6.0f,1.0f},{30,3,0.0f,1.0f},{-1,0,0.0f,0.0f}};

//MM
void BehWhompLoop(void)
{
    obj_update_floor_and_walls();
    obj_call_action_function(TableWhompActions);
    obj_move_standard(-20);
    if(o->oAction != 9)
    {
        if(o->oBehParams2ndByte != 0)
            obj_hide_if_mario_far_away_y(2000.0f);
        else
            obj_hide_if_mario_far_away_y(1000.0f);
        load_object_collision_model();
    }
}

void BehWaterSplashLoop(void)
{
    s32 i;
    if(o->oTimer == 0)
        o->oPosY = find_water_level(o->oPosX,o->oPosZ);
    if(o->oPosY > -10000.0f)
        for(i=0;i<3;i++)
            func_8029E388(o,&D_8032FDAC);
}

void BehWaterDropsLoop(void)
{
    UNUSED s32 unused;
    f32 sp20 = find_water_level(o->oPosX,o->oPosZ);
    if(o->oTimer == 0)
    {
        if(obj_has_model(185))
            o->header.gfx.node.flags &= ~4;
        else
            o->header.gfx.node.flags |= 4;
        o->oFaceAngleYaw = RandomU16();
    }
    o->oVelY -= 4.0f;
    o->oPosY += o->oVelY;
    if(o->oVelY < 0.0f)
    {
        if(sp20 > o->oPosY)
        {
            try_to_spawn_object(0,1.0f,o,165,beh_water_surface_white_wave);
            mark_object_for_deletion(o);
        }
        else if(o->oTimer > 20)
            mark_object_for_deletion(o);
    }
    if(sp20 < -10000.0f)
        mark_object_for_deletion(o);
}

void BehSurfaceWavesLoop(void)
{
    copy_object_pos(o,gMarioObject);
    o->oPosY = gMarioStates->waterLevel + 5;
    if(!(gMarioObject->oMarioParticleFlags & 0x80))
    {
        gMarioObject->oUnkE0 &= 0xFF7F;
        o->activeFlags = 0;
    }
}

void BehWaterSurfaceWhiteWaveInit(void)
{
    obj_scale(RandomFloat()+1.5);
}

void BehObjectBubbleRipplesInit(void)
{
    f32 sp1C = find_water_level(o->oPosX,o->oPosZ);
    scale_object_xyz(o,0.5,1.0f,0.5f);
    o->oPosY = sp1C + 5.0f;
}

void BehSurfaceWaveShrinkingInit(void)
{
    UNUSED struct Object* sp1C;
    if((RandomU16() & 0xFF) <= 0) // weird
    {
        sp1C = func_8029E388(o,&D_8032FDF4);
        func_8029EE20(sp1C,blue_fish_seg3_anims_0301C2B0,0);
    }
}

void BehWaveTrailLoop(void)
{
    f32 sp1C = find_water_level(o->oPosX,o->oPosZ);
    if(o->oTimer == 0)
        if(gGlobalTimer & 1)
            mark_object_for_deletion(o);
    o->oPosY = sp1C + 5.0f;
    if(o->oTimer == 0)
        o->oWaveTrailUnkF8 = o->header.gfx.scale[0];
    if(o->oAnimState > 3)
    {
        o->oWaveTrailUnkF8 = o->oWaveTrailUnkF8 - 0.1;
        if(o->oWaveTrailUnkF8 < 0.0f)
            o->oWaveTrailUnkF8 = 0.0f;
        o->header.gfx.scale[0] = o->oWaveTrailUnkF8;
        o->header.gfx.scale[2] = o->oWaveTrailUnkF8;
    }
}

void BehWhiteWindParticleLoop(void)
{
    struct Object* sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    set_object_hitbox(o,&D_8032FE3C);
    if(o->oTimer == 0)
    {
        o->oWhiteWindParticleUnkF4 = obj_nearest_object_with_behavior(beh_walking_penguin);
        translate_object_xyz_random(o,100.0f);
        o->oForwardVel = coss(o->oMoveAnglePitch) * 100.0f;
        o->oVelY = sins(o->oMoveAnglePitch) * -100.0f;
        o->oMoveAngleYaw += random_f32_around_zero(o->oBehParams2ndByte*500);
        o->oOpacity = 100;
    }
    obj_move_using_fvel_and_gravity();
    if(o->oTimer > 15)
        mark_object_for_deletion(o);
    sp34 = o->oWhiteWindParticleUnkF4;
    if(sp34 != 0)
    {
        sp2C = sp34->oWalkingPenguinUnk100 - o->oPosX;
        sp28 = sp34->oWalkingPenguinUnk104 - o->oPosZ;
        sp30 = sqrtf(sp2C*sp2C+sp28*sp28);
        if(sp30 < 300.0f)
        {
            mark_object_for_deletion(o);
            obj_become_intangible();
        }
    }
}

void func_802C76E0(s32 a0,f32 a1,f32 a2,f32 a3,f32 a4)
{
    if((gGlobalTimer & 1) != 0)
    {
        spawn_object_relative_with_scale(a0,a2,a3,a4,0.5f,o,158,beh_tiny_white_wind_particle);
        spawn_object_relative_with_scale(a0,a2,a3,a4,a1,o,0,beh_wind_particle);
    }
    else
        spawn_object_relative_with_scale(a0,a2,a3,a4,a1,o,142,beh_wind_particle);
    spawn_object_relative_with_scale(a0,a2,a3,a4,a1,o,0,beh_wind_particle);
}

void BehSnowmanWindBlowingLoop(void)
{
    UNUSED s32 sp34;
    s16 sp32;
    Vec3f pos;
    sp34 = 0;
    if(o->oTimer == 0)
        o->oSnowmanWindBlowingUnkF4 = o->oMoveAngleYaw;
    if(o->oSubAction == 0)
    {
        o->oDistanceToMario = 0.0f;
        func_802B8F7C(pos,&o->oPosX);
        set_object_pos(o,1100,3328,1164);
        if(func_802A3FF8(1000.0f,30.0f,0x7FFF))
            o->oSubAction++;
        func_802B8F7C(&o->oPosX,pos);
    }
    else if(o->oSubAction == 1)
    {
        if(obj_update_dialogue_unk1(2,2,153,0))
            o->oSubAction++;
    }
    else if(o->oDistanceToMario < 1500.0f && absf(gMarioObject->oPosY-o->oHomeY) < 500.0f)
    {
        if((sp32 = o->oAngleToMario - o->oSnowmanWindBlowingUnkF4) > 0)
        {
            if(sp32 < 0x1500)
                o->oMoveAngleYaw = o->oAngleToMario;
            else
                o->oMoveAngleYaw = o->oSnowmanWindBlowingUnkF4 + 0x1500;
        }
        else
        {
            if(sp32 >= -0x14ff)
                o->oMoveAngleYaw = o->oAngleToMario;
            else
                o->oMoveAngleYaw = o->oSnowmanWindBlowingUnkF4 - 0x1500;
        }
        func_802C76E0(12,3.0f,0,0,0.0f);
        PlaySound(0x60044001);
    }
}

s32 func_802C7AD0(void)
{
    o->oForwardVel = 0.0f;
    func_8029ED98(0,1.0f);
    o->oAngleVelYaw = 0x400;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    if(o->oTimer == 31)
        return 1;
    else
        return 0;
}

void BehWalkingPenguinLoop(void)
{
    f32 sp2C;
    f32 sp28;
    f32 sp24 = 100.0f;
    o->oAngleVelYaw = 0;
    obj_update_floor_and_walls();
    switch(o->oAction)
    {
    case 0:
        if(o->oTimer == 0)
        {
            o->oWalkingPenguinUnk10C = 0;
            o->oWalkingPenguinUnk110 = 0;
        }
        if(o->oWalkingPenguinUnk110 < D_8032FE4C[o->oWalkingPenguinUnk10C].unk0)
            o->oWalkingPenguinUnk110++;
        else
        {
            o->oWalkingPenguinUnk110 = 0;
            o->oWalkingPenguinUnk10C++;
            if(D_8032FE4C[o->oWalkingPenguinUnk10C].unk0 < 0)
                o->oWalkingPenguinUnk10C = 0;
        }
        if(o->oPosX < 300.0f)
            o->oAction++;
        else
        {
            o->oForwardVel = D_8032FE4C[o->oWalkingPenguinUnk10C].unk2;
            func_8029ED98(D_8032FE4C[o->oWalkingPenguinUnk10C].unk1,D_8032FE4C[o->oWalkingPenguinUnk10C].unk3);
        }
        break;
    case 1:
        if(func_802C7AD0())
            o->oAction++;
        break;
    case 2:
        o->oForwardVel = 12.0f;
        func_8029ED98(0,2.0f);
        if(o->oPosX > 1700.0f)
            o->oAction++;
        break;
    case 3:
        if(func_802C7AD0())
            o->oAction = 0;
        break;
    }
    obj_move_standard(-78);
    if(!obj_hide_if_mario_far_away_y(1000.0f))
        func_802BE3B4(1);
    sp2C = o->oPosX + sins(0xDBB0) * 60.0f;
    sp28 = o->oPosZ + coss(0xDBB0) * 60.0f;
    sp2C += sp24 * sins(0x1BB0);
    sp28 += sp24 * coss(0x1BB0);
    o->oWalkingPenguinUnk100 = sp2C;
    o->oWalkingPenguinUnk104 = sp28;
    print_debug_bottom_up("x %d",o->oPosX);
    print_debug_bottom_up("z %d",o->oPosZ);
}
