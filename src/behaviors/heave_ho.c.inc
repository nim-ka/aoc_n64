// heave_ho.c.inc

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
