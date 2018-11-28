
static void func_80303F78(void)
{
    o->oAction = PLATFORM_ON_TRACK_ACT_UNK0;
    o->oUnk88 += 99;
}

static void func_80303FA8(void)
{
    if (!((u16)(o->oBehParams >> 16) & 0x0200))
    {
        if (func_802A2EFC(150, 40))
        {
            func_80303F78();
            o->header.gfx.node.flags &= ~0x0010;
        }
    }
}

void bhv_platform_on_track_init(void)
{
    s16 val06;

    if (!(o->activeFlags & 0x00000008))
    {
        val06 = (u16)(o->oBehParams >> 16) & 0xF;
        o->oPlatformOnTrackUnk1B0 = ((u16)(o->oBehParams >> 16) & 0x0070) >> 4;
        o->oPlatformOnTrackUnk1AC = o->oPlatformOnTrackUnk1B0 - 1;
        o->collisionData = segmented_to_virtual(
            sPlatformOnTrackCollisionModels[o->oPlatformOnTrackUnk1B0]);
        o->oPlatformOnTrackUnkFC = segmented_to_virtual(D_803318CC[val06]);
        o->oPlatformOnTrackUnk1AE = val06 - 4;

        o->oBehParams2ndByte = o->oMoveAngleYaw;
        if (o->oPlatformOnTrackUnk1B0 == 2)
        {
            o->header.gfx.scale[1] = 2.0f;
        }
    }
}

static void func_80304148(void)
{
    s32 i;

    o->oPlatformOnTrackUnk100 = o->oPlatformOnTrackUnkFC;
    o->oPlatformOnTrackUnk104 = 0;
    o->oUnk88 = 0;

    o->oPosX = o->oHomeX = o->oPlatformOnTrackUnkFC[1];
    o->oPosY = o->oHomeY = o->oPlatformOnTrackUnkFC[2];
    o->oPosZ = o->oHomeZ = o->oPlatformOnTrackUnkFC[3];

    o->oFaceAngleYaw = o->oBehParams2ndByte;
    o->oForwardVel = o->oVelX = o->oVelY = o->oVelZ = o->oPlatformOnTrackUnkF4 = 0.0f;
    o->oPlatformOnTrackUnk1B2 = 0;
    if (o->oPlatformOnTrackUnk1AC != 0)
    {
        o->oFaceAngleRoll = 0;
    }

    for (i = 1; i < 6; i++)
    {
        func_802F8978(i, o->oHomeX, o->oHomeY, o->oHomeZ);
    }

    o->oAction = PLATFORM_ON_TRACK_ACT_UNK1;
}

static void func_803042F8(void)
{
    if (gMarioObject->platform == o)
    {
        if (o->oTimer > 20)
        {
            o->oAction = PLATFORM_ON_TRACK_ACT_UNK2;
        }
    }
    else
    {
        if (o->activeFlags & 0x00000008)
        {
            func_80303F78();
        }

        o->oTimer = 0;
    }
}

static void func_80304390(void)
{
    s16 sp1E;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;

    if (o->oPlatformOnTrackUnk1AC == 0)
    {
        PlaySound(0x400C0001);
    }
    else if (o->oPlatformOnTrackUnk1AE == 0)
    {
        PlaySound(0x40020001);
    }

    if (o->oPlatformOnTrackUnk104 == -1 &&
        !((u16)(o->oBehParams >> 16) & 0x100))
    {
        o->oAction = PLATFORM_ON_TRACK_ACT_UNK4;
    }
    else
    {
        if (o->oPlatformOnTrackUnk104 != 0 &&
            o->oPlatformOnTrackUnk1AC == 0)
        {
            if (o->oPlatformOnTrackUnk104 == -1 ||
                o->oPlatformOnTrackUnk104 == 3)
            {
                PlaySound2(0x303D0081);
                o->oForwardVel = 0.0f;
                if (o->oPlatformOnTrackUnk104 == -1)
                {
                    o->oAction = PLATFORM_ON_TRACK_ACT_UNK0;
                }
                else
                {
                    o->oAction = PLATFORM_ON_TRACK_ACT_UNK3;
                }
            }
        }
        else
        {
            if (o->oPlatformOnTrackUnk1AC == 0)
            {
                obj_forward_vel_approach(10.0, 0.1f);
            }
            else
            {
                o->oForwardVel = 10.0f;
            }

            if (approach_f32_ptr(&o->oPlatformOnTrackUnkF4, 300.0f, o->oForwardVel))
            {
                o->oPlatformOnTrackUnkF4 -= 300.0f;
                o->oHomeX = o->oPosX;
                o->oHomeY = o->oPosY;
                o->oHomeZ = o->oPosZ;
                o->oUnk88 = (u16)(o->oUnk88 + 1);
                func_802F8978(5, o->oHomeX, o->oHomeY, o->oHomeZ);
            }
        }

        func_802F8978(0, o->oPosX, o->oPosY, o->oPosZ);
        o->oMoveAnglePitch = o->oPlatformOnTrackPitch;
        o->oMoveAngleYaw = o->oPlatformOnTrackYaw;
        
        if (!((u16)(o->oBehParams >> 16) & 0x0400))
        {
            sp1C = o->oMoveAngleYaw + 0x4000;
            sp1A = abs_angle_diff(sp1C, o->oFaceAngleYaw) / 20;
            sp1E = o->oFaceAngleYaw;

            clamp_s16(&sp1A, 100, 500);
            obj_face_yaw_approach(sp1C, sp1A);
            o->oAngleVelYaw = (s16)o->oFaceAngleYaw - sp1E;
        }

        if (((u16)(o->oBehParams >> 16) & 0x0800))
        {
            sp18 = abs_angle_diff(o->oMoveAnglePitch, o->oFaceAngleRoll) / 20;
            sp1E = o->oFaceAngleRoll;

            clamp_s16(&sp18, 100, 500);
            obj_face_roll_approach(o->oMoveAnglePitch, sp18);
            o->oAngleVelRoll = (s16)o->oFaceAngleRoll - sp1E;
        }
    }

    if (gMarioObject->platform != o)
    {
        func_80303FA8();
    }
    else
    {
        o->oTimer = 0;
        o->header.gfx.node.flags &= ~0x10;
    }
}

static void func_80304788(void)
{
    if (o->oTimer > 20)
    {
        o->oAction = PLATFORM_ON_TRACK_ACT_UNK2;
    }
}

static void func_803047C0(void)
{
    obj_move_using_vel_and_gravity();
    if (gMarioObject->platform != o)
    {
        func_80303FA8();
    }
    else
    {
        o->oTimer = 0;
    }
}

static void func_80304820(void)
{
    s32 val04;
    UNUSED s32 val00;

    val04 = 0;
    val00 = o->oFaceAngleRoll;

    o->oFaceAngleRoll += (s32)o->oPlatformOnTrackUnkF8;

    if (gMarioObject->platform == o)
    {
        val04 = o->oForwardVel * sins(o->oMoveAngleYaw) * -50.0f +
            (s32)(o->oDistanceToMario * sins(o->oAngleToMario - o->oFaceAngleYaw) * -4.0f);
    }

    oscillate_toward(&o->oFaceAngleRoll, &o->oPlatformOnTrackUnkF8, val04, 5.0f, 6.0f, 1.5f);
    clamp_f32(&o->oPlatformOnTrackUnkF8, -100.0f, 100.0f);
}

void bhv_platform_on_track_update(void)
{
    switch (o->oAction)
    {
    case PLATFORM_ON_TRACK_ACT_UNK0: func_80304148(); break;
    case PLATFORM_ON_TRACK_ACT_UNK1: func_803042F8(); break;
    case PLATFORM_ON_TRACK_ACT_UNK2: func_80304390(); break;
    case PLATFORM_ON_TRACK_ACT_UNK3: func_80304788(); break;
    case PLATFORM_ON_TRACK_ACT_UNK4: func_803047C0(); break;
    }

    if (o->oPlatformOnTrackUnk1AC == 0)
    {
        func_80304820();
    }
    else if (o->oPlatformOnTrackUnk1B0 == 0)
    {
        if (o->oPlatformOnTrackUnk1B2 == 0 && gMarioObject->platform == o)
        {
            o->oPlatformOnTrackUnk110 = -8.0f;
            o->oPlatformOnTrackUnk1B2 = 1;
        }

        approach_f32_ptr(&o->oPlatformOnTrackUnk110, 0.0f, 0.5f);
        o->oPosY += o->oPlatformOnTrackUnk110;
    }
}

void BehMetalBallsForElevatorsLoop(void)
{
    s16 relativeIndex = (s16)o->oBehParams2ndByte - (s16)o->parentObj->oUnk88 - 1;
    if (relativeIndex <= 0 || relativeIndex >= 6)
    {
        mark_object_for_deletion(o);
    }
}
