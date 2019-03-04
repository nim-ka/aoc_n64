// wind_particle.c.inc

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
