
static s32 spiny_check_active(void)
{
    if (o->parentObj != o)
    {
        if (o->oDistanceToMario > 2500.0f)
        {
            o->parentObj->oEvilLakituNumSpinies -= 1;
            DeactivateObject(o);
            return FALSE;
        }
    }

    return TRUE;
}

static void spiny_act_walk(void)
{
    if (spiny_check_active())
    {
        obj_update_floor_and_walls();
        o->oGraphYOffset = -17.0f;
        func_8029ED38(0);

        if (o->oMoveFlags & 0x00000003)
        {
            if (!(o->oFlags & 0x00000008))
            {
                if (forward_vel_approach(0.0f, 1.0f))
                {
                    o->oFlags |= 0x00000008;
                    o->oMoveAngleYaw = o->oFaceAngleYaw;
                }
            }
            else
            {
                forward_vel_approach(1.0f, 0.2f);
            }

            if (o->oSpinyTurning)
            {
                o->oSpinyTurning = resolve_collisions_and_turn(o->oSpinyTargetYaw, 0x80);
            }
            else
            {
                if (!(o->oSpinyTurning = func_802F9F6C(&o->oSpinyTargetYaw)))
                {
                    if (o->oSpinyTimeUntilTurn != 0)
                    {
                        o->oSpinyTimeUntilTurn -= 1;
                    }
                    else
                    {
                        o->oSpinyTargetYaw = o->oMoveAngleYaw + (s16)RandomSign() * 0x2000;
                        o->oSpinyTimeUntilTurn = random_linear_offset(100, 100);
                    }
                }

                obj_rotate_yaw_toward(o->oSpinyTargetYaw, 0x80);
            }

        }
        else if (o->oMoveFlags & 0x00000200)
        {
            o->oMoveAngleYaw = obj_reflect_move_angle_off_wall();
        }

        obj_move_standard(-78);
        if (func_802FA468(&D_80331844, 3, D_80331854))
        {
            o->oAction = SPINY_ACT_WALK;
            o->oForwardVel *= 0.1f;
            o->oVelY *= 0.7f;
            o->oMoveFlags = 0;
            o->oInteractType = INTERACT_MR_BLIZZARD;
        }
        else
        {
            o->oInteractType = INTERACT_UNKNOWN_08;
        }
    }
}

static void spiny_act_held_by_lakitu(void)
{
    o->oGraphYOffset = 15.0f;
    func_8029ED38(0);

    o->oParentRelativePosX = -50.0f;
    o->oParentRelativePosY = 35.0f;
    o->oParentRelativePosZ = -100.0f;

    if (o->parentObj->prevObj == NULL)
    {
        o->oAction = SPINY_ACT_THROWN_BY_LAKITU;
        o->oMoveAngleYaw = o->parentObj->oFaceAngleYaw;
        o->oForwardVel =
            o->parentObj->oForwardVel * coss(o->oMoveAngleYaw - o->parentObj->oMoveAngleYaw) + 10.0f;
        o->oVelY = 30.0f;
        o->oMoveFlags = 0;
    }
}

static void spiny_act_thrown_by_lakitu(void)
{
    if (spiny_check_active())
    {
        obj_update_floor_and_walls();
        o->oGraphYOffset = 15.0f;

        o->oFaceAnglePitch -= 0x2000;

        func_8029ED38(0);
        if (o->oMoveFlags & 0x00000001)
        {
            PlaySound2(0x50591081);
            obj_set_model(0x56);
            func_8029EE20(o, spiny_seg5_anims_05016EAC, 0);
            o->oGraphYOffset = -17.0f;
            o->oFaceAnglePitch = 0;
            o->oAction = SPINY_ACT_WALK;
        }
        else if (o->oMoveFlags & 0x00000200)
        {
            o->oMoveAngleYaw = obj_reflect_move_angle_off_wall();
        }

        obj_move_standard(-78);
        if (func_802FA888(&D_80331844, o->oAction))
        {
            if (o->parentObj != o)
            {
                o->parentObj->oEvilLakituNumSpinies -= 1;
            }
        }
    }
}

void bhv_spiny_update(void)
{
    switch (o->oAction)
    {
    case SPINY_ACT_WALK:             spiny_act_walk();              break;
    case SPINY_ACT_HELD_BY_LAKITU:   spiny_act_held_by_lakitu();    break;
    case SPINY_ACT_THROWN_BY_LAKITU: spiny_act_thrown_by_lakitu();  break;
    case SPINY_ACT_UNK3:             func_802FA990(SPINY_ACT_WALK); break;
    }
}
