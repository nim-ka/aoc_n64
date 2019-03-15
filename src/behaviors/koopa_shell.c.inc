// koopa_shell.c.inc

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

void BehKoopaShellFlameSpawn(void)
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
                    BehKoopaShellFlameSpawn();
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
