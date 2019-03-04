// tweester.c.inc

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
