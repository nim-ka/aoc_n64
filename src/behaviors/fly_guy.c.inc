
static void fly_guy_act_idle(void)
{
    o->oForwardVel = 0.0f;
    if (approach_f32_2(&o->header.gfx.scale[0], 1.5f, 0.02f))
    {
        // If we are >2000 units from home or Mario is <2000 units from us
        if (o->oDistanceToMario >= 25000.0f || o->oDistanceToMario < 2000.0f)
        {
            // Turn toward home or Mario
            face_yaw_approach(o->oAngleToMario, 0x300);
            if (obj_rotate_yaw_toward(o->oAngleToMario, 0x300))
            {
                o->oAction = FLY_GUY_ACT_APPROACH_MARIO;
            }
        }
        else
        {
            if (o->oFlyGuyIdleTimer >= 3 || o->oFlyGuyIdleTimer == (RandomU16() & 1) + 2)
            {
                o->oFlyGuyIdleTimer = 0;
                o->oAction = FLY_GUY_ACT_APPROACH_MARIO;
            }
            else
            {
                o->oFlyGuyUnkFC = o->oMoveAngleYaw + D_803317A8[o->oFlyGuyIdleTimer];
                o->oFlyGuyIdleTimer += 1;
            }
        }
    }
}

static void fly_guy_act_approach_mario(void)
{
    // If we are >2000 units from home or Mario is <2000 units from us
    if (o->oDistanceToMario >= 25000.0f || o->oDistanceToMario < 2000.0f)
    {
        forward_vel_approach(10.0f, 0.5f);

        // Turn toward home or Mario
        face_yaw_approach(o->oAngleToMario, 0x400);
        obj_rotate_yaw_toward(o->oAngleToMario, 0x200);

        if (abs_angle_diff(o->oAngleToMario, o->oFaceAngleYaw) < 0x2000)
        {
            if (o->oPosY - gMarioObject->oPosY > 400.0f || o->oDistanceToMario < 400.0f)
            {
                if (o->oBehParams2ndByte != 0 && RandomU16() % 2)
                {
                    o->oAction = FLY_GUY_ACT_SHOOT_FIRE;
                    o->oFlyGuyScaleVel = 0.06f;
                }
                else
                {
                    o->oAction = FLY_GUY_ACT_LUNGE;
                    o->oFlyGuyLungeTargetPitch = func_802F9414(-200.0f, 0);

                    o->oForwardVel = 25.0f * coss(o->oFlyGuyLungeTargetPitch);
                    o->oVelY = 25.0f * -sins(o->oFlyGuyLungeTargetPitch);
                    o->oFlyGuyLungeYAccel = -o->oVelY / 30.0f;
                }
            }
        }
    }
    else if (forward_vel_approach(0.0f, 0.2f))
    {
        o->oAction = FLY_GUY_ACT_IDLE;
    }
}

static void fly_guy_act_lunge(void)
{
    if (o->oVelY < 0.0f)
    {
        o->oVelY += o->oFlyGuyLungeYAccel;

        obj_rotate_yaw_toward(o->oFaceAngleYaw, 0x800);
        face_pitch_approach(o->oFlyGuyLungeTargetPitch, 0x400);

        // Range [-0x1000, 0x2000]
        o->oFlyGuyTargetRoll = 0x1000 * (s16)(RandomFloat() * 3.0f) - 0x1000;
        o->oTimer = 0;
    }
    else
    {
        face_pitch_approach(0, 0x100);
        face_roll_approach(o->oFlyGuyTargetRoll, 300);

        o->oMoveAngleYaw -= o->oFaceAngleRoll / 4;
        face_yaw_approach(o->oMoveAngleYaw, 0x800);

        if (o->oPosY < gMarioObject->oPosY + 200.0f)
        {
            y_vel_approach(20.0f, 0.5f);
        }
        else if (y_vel_approach(0.0f, 0.5f))
        {
            if (o->oFaceAngleRoll == 0)
            {
                o->oAction = FLY_GUY_ACT_APPROACH_MARIO;
            }

            o->oFlyGuyTargetRoll = 0;
        }
    }
}

static void fly_guy_act_shoot_fire(void)
{
    s32 scaleStatus;
    s16 val02;

    o->oForwardVel = 0.0f;

    if (face_yaw_approach(o->oAngleToMario, 0x800))
    {
        o->oMoveAngleYaw = o->oFaceAngleYaw;

        // Increase scale by 0.06, 0.05, ..., -0.03. Then wait ~8 frames, then
        // starting moving scale by 0.05 each frame toward 1.1. The first time
        // it becomes below 1.2 during this latter portion, shoot fire.
        scaleStatus = grow_then_shrink(&o->oFlyGuyScaleVel, 1.2f, 1.1f);
        if (scaleStatus != 0)
        {
            if (scaleStatus < 0)
            {
                // We have reached scale 1.1
                o->oAction = FLY_GUY_ACT_IDLE;
            }
            else
            {
                // We have reached below scale 1.2 in the shrinking portion
                val02 = func_802F9414(0.0f, 0);
                PlaySound2(0x50558081);
                func_802F91AC(&val02, 0x800, 0x3000);
                obj_spit_fire(0, 38, 20, 2.5f, 203, 25.0f, 20.0f, val02);
            }
        }
    }
    else
    {
        //! By triggering this repeatedly, we can keep the grow_then_shrink
        // in the "grow" phase. But because oFlyGuyScaleVel continues decreasing
        // past -0.03, the fly guy shrinks more than he is supposed to. We can
        // arbitrarily decrease the fly guy's scale in this way.
        o->oTimer = 0;
    }
}

void bhv_fly_guy_update(void)
{
    if (!(o->activeFlags & 0x0008))
    {
        o->oDeathSound = 0x5063B081;
        obj_scale(o->header.gfx.scale[0]);

        treat_far_home_as_mario(2000.0f);
        
        obj_update_floor_and_walls();
        if (o->oMoveFlags & 0x00000200)
        {
            o->oMoveAngleYaw = obj_reflect_move_angle_off_wall();
        }
        else if (o->oMoveFlags & 0x00000078)
        {
            o->oVelY = 6.0f;
        }

        o->oFlyGuyOscTimer += 1;
        o->oPosY += coss(0x400 * o->oFlyGuyOscTimer) * 1.5f;

        switch (o->oAction)
        {
        case FLY_GUY_ACT_IDLE:           fly_guy_act_idle();           break;
        case FLY_GUY_ACT_APPROACH_MARIO: fly_guy_act_approach_mario(); break;
        case FLY_GUY_ACT_LUNGE:          fly_guy_act_lunge();          break;
        case FLY_GUY_ACT_SHOOT_FIRE:     fly_guy_act_shoot_fire();     break;
        }

        obj_move_standard(78);
        func_802FA888(&sFlyGuyHitbox, o->oAction);
    }
}
