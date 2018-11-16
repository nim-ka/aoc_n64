
static void bird_act_init(void)
{
    s32 i;

    if (o->oBehParams2ndByte == BIRD_BP_SPAWNED || o->oDistanceToMario < 2000.0f)
    {
        if (o->oBehParams2ndByte != BIRD_BP_SPAWNED)
        {
            PlaySound2(0x30690081);

            for (i = 0; i < 6; i++)
            {
                SpawnObj(o, 0x54, bBird);
            }

            o->oHomeX = -20.0f;
            o->oHomeZ = -3990.0f;
        }

        o->oAction = BIRD_ACT_FLY;
        o->oAnglePitch = 5000 - (s32)(4000.0f * RandomFloat());
        o->oAngleYaw = RandomU16();
        o->oBirdSpeed = 40.0f;

        func_8029EF18();
    }
}

static void bird_act_fly(void)
{
    UNUSED s32 unused;
    f32 distance;

    func_802F9148(o->oBirdSpeed);
    if (o->parentObj->oPosY > 8000.0f)
    {
        DeactivateObject(o);
    }
    else
    {
        if (o->oBehParams2ndByte != BIRD_BP_SPAWNED)
        {
            distance = obj_lateral_dist_to_home();
            o->oBirdPitch = atan2s(distance, o->oPosY - 10000.0f);
            o->oBirdYaw = obj_angle_to_home();
        }
        else
        {
            distance = DistanceFromObject(o, o->parentObj);
            o->oBirdPitch = atan2s(distance, o->oPosY - o->parentObj->oPosY);
            o->oBirdYaw = func_8029DF18(o, o->parentObj);

            o->oBirdSpeed = 0.04f * objects_calc_distance(o, o->parentObj) + 20.0f;
        }

        func_802F95B0(o->oBirdPitch, 140);
        func_8029DE70(o->oBirdYaw, 800);
        func_802F9850(o->oBirdYaw, 0x3000, 600);
    }

    MoveObj2();
}

void bhv_bird_update(void)
{
    switch (o->oAction)
    {
    case BIRD_ACT_INIT: bird_act_init(); break;
    case BIRD_ACT_FLY:  bird_act_fly();  break;
    }
}
