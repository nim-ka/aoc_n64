
void bhv_goomba_triplet_spawner_update(void)
{
    UNUSED s32 unused1;
    s16 goombaFlag;
    UNUSED s16 unused2;
    s32 angle;
    s32 dAngle;
    s16 dx;
    s16 dz;

    if (o->oAction == GOOMBA_TRIPLET_SPAWNER_ACT_UNLOADED)
    {
        if (o->oDistanceToMario < 3000.0f)
        {
            dAngle = 0x10000 / (((o->oBehParams2ndByte & GOOMBA_TRIPLET_SPAWNER_BP_EXTRA_GOOMBAS_MASK) >> 2) + 3);

            goombaFlag = 0x100;
            for (angle = 0; angle < 0xFFFF; angle += dAngle, goombaFlag *= 2)
            {
                // Only spawn goombas which haven't been killed yet
                if (!(o->oBehParams & goombaFlag))
                {
                    dx = 500.0f * coss(angle);
                    dz = 500.0f * sins(angle);

                    spawn_obj_adv(
                        (o->oBehParams2ndByte & GOOMBA_TRIPLET_SPAWNER_BP_SIZE_MASK) | (goombaFlag >> 6),
                        dx, 0, dz,
                        o,
                        0xC0,
                        bGoomba);
                }
            }

            o->oAction += 1;
        }
    }
    else if (o->oDistanceToMario > 4000.0f)
    {
        o->oAction = GOOMBA_TRIPLET_SPAWNER_ACT_UNLOADED;
    }
}

void bhv_goomba_init(void)
{
    o->oGoombaSize = o->oBehParams2ndByte & GOOMBA_BP_SIZE_MASK;

    o->oGoombaBaseSpeed = sGoombaProperties[o->oGoombaSize].baseSpeed;
    o->oDeathSound = sGoombaProperties[o->oGoombaSize].unk04;

    set_object_hitbox(o, &sGoombaHitbox);

    o->oDrawingDistance = sGoombaProperties[o->oGoombaSize].drawDistance;
    o->oUnk180 = sGoombaProperties[o->oGoombaSize].unk0A;

    o->oGravity = -8.0f / 3.0f * o->oGoombaBaseSpeed;
}

static void goomba_begin_jump(void)
{
    PlaySound2(0x502F0081);
    o->oAction = GOOMBA_ACT_JUMP;
    o->oForwardVel = 0.0f;
    o->oVelY = 50.0f / 3.0f * o->oGoombaBaseSpeed;
}

static void mark_goomba_as_dead(void)
{
    if (o->parentObj != o)
    {
        func_8029C6D8(o->parentObj, (o->oBehParams2ndByte & GOOMBA_BP_TRIPLET_FLAG_MASK) >> 2);
        
        o->parentObj->oBehParams = o->parentObj->oBehParams |
            (o->oBehParams2ndByte & GOOMBA_BP_TRIPLET_FLAG_MASK) << 6;
    }
}

static void goomba_act_walk(void)
{
    treat_far_home_as_mario(1000.0f);

    forward_vel_approach(o->oGoombaRelativeSpeed * o->oGoombaBaseSpeed, 0.4f);
    
    if (o->oGoombaRelativeSpeed > 4.0f / 3.0f)
    {
        func_802F9378(2, 17, 0x50200081);
    }

    if (o->oGoombaTurning)
    {
        o->oGoombaTurning = resolve_collisions_and_turn(o->oGoombaTargetYaw, 0x200);
    }
    else
    {
        // If far from home, walk toward home.
        if (o->oDistanceToMario >= 25000.0f)
        {
            o->oGoombaTargetYaw = o->oAngleToMario;
            o->oGoombaWalkTimer = random_linear_offset(20, 30);
        }

        if (!(o->oGoombaTurning = func_802F9F6C(&o->oGoombaTargetYaw)))
        {
            if (o->oDistanceToMario < 500.0f)
            {
                if (o->oGoombaRelativeSpeed <= 2.0f)
                {
                    goomba_begin_jump();
                }

                o->oGoombaTargetYaw = o->oAngleToMario;
                o->oGoombaRelativeSpeed = 20.0f;
            }
            else
            {
                o->oGoombaRelativeSpeed = 4.0f / 3.0f;
                if (o->oGoombaWalkTimer != 0)
                {
                    o->oGoombaWalkTimer -= 1;
                }
                else
                {
                    if (RandomU16() & 0x00000003)
                    {
                        o->oGoombaTargetYaw = random_fixed_turn(0x2000);
                        o->oGoombaWalkTimer = random_linear_offset(100, 100);
                    }
                    else
                    {
                        goomba_begin_jump();
                        o->oGoombaTargetYaw = random_fixed_turn(0x6000);
                    }
                }
            }
        }

        obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x200);
    }
}

static void goomba_act_soft_attacked(void)
{
    if (o->oGoombaSize == GOOMBA_SIZE_TINY)
    {
        mark_goomba_as_dead();
        o->oNumLootCoins = 0;
        func_802FA078();
    }
    else
    {
        goomba_begin_jump();
        o->oGoombaTargetYaw = o->oAngleToMario;
        o->oGoombaTurning = FALSE;
    }
}

static void goomba_act_jump(void)
{
    resolve_obj_collisions(NULL);

    //! If the goomba is deactivated the frame it enters the jump action, then
    // it will keep its velY, but it will still be counted as being on the ground.
    // Next frame, the jump action will think it has already ended because it is
    // still on the ground.
    // This puts the goomba back in the walk action, but the positive velY will
    // make it hop into the air. We can then trigger another jump.
    if (o->oMoveFlags & 0x00000003)
    {
        o->oAction = GOOMBA_ACT_WALK;
    }
    else
    {
        obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x800);
    }
}

void goomba_soft_attacked(void)
{
    o->oAction = GOOMBA_ACT_SOFT_ATTACKED;
}

void bhv_goomba_update(void)
{
    f32 val04;

    if (func_802FA7CC(o->oGoombaBaseSpeed))
    {
        if (o->parentObj != o)
        {
            if (o->parentObj->oAction == GOOMBA_ACT_WALK)
            {
                DeactivateObject(o);
            }
        }

        obj_scale(o->oGoombaBaseSpeed);
        update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);
        obj_update_floor_and_walls();

        if ((val04 = o->oForwardVel / o->oGoombaBaseSpeed * 0.4f) < 1.0f)
        {
            val04 = 1.0f;
        }

        func_8029ED98(0, val04);

        switch (o->oAction)
        {
        case GOOMBA_ACT_WALK:          goomba_act_walk();          break;
        case GOOMBA_ACT_SOFT_ATTACKED: goomba_act_soft_attacked(); break;
        case GOOMBA_ACT_JUMP:          goomba_act_jump();          break;
        }

        if (func_802FA468(&sGoombaHitbox, 1, sGoombaAttackHandlers[o->oGoombaSize & 1]) != 0)
        {
            mark_goomba_as_dead();
        }

        obj_move_standard(-78);
    }
    else
    {
        o->oAnimState = TRUE;
    }
}
