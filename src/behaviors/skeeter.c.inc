
static void skeeter_spawn_waves(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        func_8029E880(0, D_80331C38[i].unk00, 0, D_80331C38[i].unk02, 0.8f, o, 0xA6, bSkeeterWave);
    }
}

static void skeeter_act_idle(void)
{
    if (o->oMoveFlags & 0x00000003)
    {
        func_8029ED38(3);
        o->oForwardVel = 0.0f;

        if (o->oTimer > o->oSkeeterWaitTime && func_8029F788())
        {
            o->oAction = SKEETER_ACT_WALK;
        }
    }
    else
    {
        func_8029ED38(1);

        if (o->oMoveFlags & 0x00000010)
        {
            skeeter_spawn_waves();
            if (o->oTimer > 60 &&
                func_802F9780(&o->oSkeeterUnk1AC, &o->oMoveAngleYaw, o->oSkeeterTargetAngle, 0.02f, 5, 50, 200))
            {
                if (o->oSkeeterWaitTime != 0)
                {
                    o->oSkeeterWaitTime -= 1;
                }
                else if (func_8029F788())
                {
                    PlaySound2(0x504F0081);
                    o->oAction = SKEETER_ACT_LUNGE;
                    o->oForwardVel = 80.0f;
                    o->oSkeeterUnk1AC = 0;
                }
            }
        }
    }
}

static void skeeter_act_lunge(void)
{
    if (!(o->oMoveFlags & 0x00000010))
    {
        o->oAction = SKEETER_ACT_IDLE;
    }
    else
    {
        skeeter_spawn_waves();
        func_8029ED38(0);

        if (o->oMoveFlags & 0x00000200)
        {
            o->oMoveAngleYaw = obj_reflect_move_angle_off_wall();
            o->oForwardVel *= 0.3f;
            o->oFlags &= ~0x00000008;
        }

        if (forward_vel_approach(0.0f, 0.8f) && func_8029F828())
        {
            o->oMoveAngleYaw = o->oFaceAngleYaw;

            if (o->oDistanceToMario >= 25000.0f)
            {
                o->oSkeeterTargetAngle = o->oAngleToMario;
            }
            else
            {
                o->oSkeeterTargetAngle = random_fixed_turn(RandomU16() % 0x2000);
            }

            o->oAction = SKEETER_ACT_IDLE;
            o->oSkeeterWaitTime = random_linear_offset(0, 30);
            o->oFlags |= 0x00000008;
        }
    }
}

static void skeeter_act_walk(void)
{
    f32 sp24;

    if (!(o->oMoveFlags & 0x00000003))
    {
        o->oAction = SKEETER_ACT_IDLE;
    }
    else
    {
        forward_vel_approach(o->oSkeeterUnkFC, 0.4f);
        sp24 = 0.12f * o->oForwardVel;

        func_8029ED98(2, sp24);
        func_802F9378(3, 13, 0x504E0081);

        if (o->oSkeeterUnkF8 != 0)
        {
            o->oSkeeterUnkF8 = resolve_collisions_and_turn(o->oSkeeterTargetAngle, 0x400);
        }
        else
        {
            if (o->oDistanceToMario >= 25000.0f)
            {
                o->oSkeeterTargetAngle = o->oAngleToMario;
                o->oSkeeterWaitTime = random_linear_offset(20, 30);
            }

            if ((o->oSkeeterUnkF8 = func_802F9F6C(&o->oSkeeterTargetAngle)) == 0)
            {
                if (o->oDistanceToMario < 500.0f)
                {
                    o->oSkeeterTargetAngle = o->oAngleToMario;
                    o->oSkeeterUnkFC = 20.0f;
                }
                else
                {
                    o->oSkeeterUnkFC = 10.0f;
                    if (o->oSkeeterWaitTime != 0)
                    {
                        o->oSkeeterWaitTime -= 1;
                    }
                    else if (func_8029F788() != 0)
                    {
                        if (RandomU16() & 0x0003)
                        {
                            o->oSkeeterTargetAngle = random_fixed_turn(0x2000);
                            o->oSkeeterWaitTime = random_linear_offset(100, 100);
                        }
                        else
                        {
                            o->oAction = SKEETER_ACT_IDLE;
                            o->oSkeeterWaitTime = random_linear_offset(100, 100);
                        }
                    }
                }
            }
        }

        obj_rotate_yaw_toward(o->oSkeeterTargetAngle, 0x400);
    }
}

void bhv_skeeter_update(void)
{
    o->oDeathSound = 0x5072C081;
    treat_far_home_as_mario(1000.0f);

    obj_update_floor_and_walls();

    switch (o->oAction)
    {
    case SKEETER_ACT_IDLE:  skeeter_act_idle();  break;
    case SKEETER_ACT_LUNGE: skeeter_act_lunge(); break;
    case SKEETER_ACT_WALK:  skeeter_act_walk();  break;
    }

    func_802FA888(&D_80331C28, o->oAction);
    obj_move_standard(-78);
}

void bhv_skeeter_wave_update(void)
{
    if (approach_f32_2(&o->header.gfx.scale[0], 0.0f, 0.3f))
    {
        DeactivateObject(o);
    }

    obj_scale(o->header.gfx.scale[0]);
    o->oAnimState = gGlobalTimer / 6;
}
