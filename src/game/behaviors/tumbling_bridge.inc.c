// tumbling_bridge.c.inc

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
            PlaySound2(SOUND_GENERAL_PLATFORM);
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
