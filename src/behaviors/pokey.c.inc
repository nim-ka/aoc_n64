
void bhv_pokey_body_part_update(void)
{
    s16 offsetAngle;
    f32 val00;

    if (func_802FA7CC(3.0f))
    {
        if (o->parentObj->oAction == POKEY_ACT_UNK2)
        {
            DeactivateObject(o);
        }
        else
        {
            obj_update_floor_and_walls();
            update_blinking(&o->oPokeyBodyPartBlinkTimer, 30, 60, 4);

            if (o->oBehParams2ndByte > 1 &&
                !(o->parentObj->oPokeyUnkF4 & (1 << (o->oBehParams2ndByte + 31))))
            {
                o->parentObj->oPokeyUnkF4 =
                    o->parentObj->oPokeyUnkF4 |
                        1 << (o->oBehParams2ndByte + 31);

                o->parentObj->oPokeyUnkF4 =
                    o->parentObj->oPokeyUnkF4 &
                        ((1 << o->oBehParams2ndByte) ^ 0xFFFFFFFF);
                
                o->oBehParams2ndByte -= 1;
            }
            else if (o->parentObj->oPokeyUnkFC < 1.0f &&
                o->oBehParams2ndByte + 1 == o->parentObj->oPokeyNumBodyParts)
            {
                approach_f32_2(&o->parentObj->oPokeyUnkFC, 1.0f, 0.1f);
                obj_scale(o->parentObj->oPokeyUnkFC * 3.0f);
            }
            
            offsetAngle = o->oBehParams2ndByte * 0x4000 + gGlobalTimer * 0x800;
            o->oPosX = o->parentObj->oPosX + coss(offsetAngle) * 6.0f;
            o->oPosZ = o->parentObj->oPosZ + sins(offsetAngle) * 6.0f;

            val00 =
                o->parentObj->oPosY +
                (120 * (o->parentObj->oPokeyNumBodyParts - o->oBehParams2ndByte) - 240) +
                120.0f * o->parentObj->oPokeyUnkFC;

            if (o->oPosY < val00)
            {
                o->oPosY = val00;
                o->oVelY = 0.0f;
            }
            
            if (o->oBehParams2ndByte == 0)
            {
                o->oNumLootCoins = 1;
            }
            else
            {
                o->oNumLootCoins = 0;
            }
            
            if (func_802FA468(&D_80331770, o->oAction, D_80331780))
            {
                o->parentObj->oPokeyNumBodyParts -= 1;
                if (o->oBehParams2ndByte == 0)
                {
                    o->parentObj->oPokeyUnk100 = 1;
                    o->oNumLootCoins = -1;
                }

                o->parentObj->oPokeyUnkF4 =
                    o->parentObj->oPokeyUnkF4 &
                        ((1 << o->oBehParams2ndByte) ^ 0xFFFFFFFF);
            }
            else if (o->parentObj->oPokeyUnk100 != 0)
            {
                obj_become_intangible();

                if (--o->oPokeyBodyPartUnkF8 < 0)
                {
                    o->parentObj->oPokeyNumBodyParts -= 1;
                    func_802FA078();
                }
            }
            else
            {
                o->oPokeyBodyPartUnkF8 = (o->oBehParams2ndByte << 2) + 20;
            }

            obj_move_standard(-78);
        }
    }
    else
    {
        o->oAnimState = 1;
    }

    o->oGraphYOffset = o->header.gfx.scale[1] * 22.0f;
}

static void pokey_act_uninitialized(void)
{
    struct Object *bodyPart;
    s32 i;
    s16 partModel;

    if (o->oDistanceToMario < 2000.0f)
    {
        partModel = 0x54;
        
        for (i = 0; i < 5; i++)
        {
            bodyPart = spawn_obj_adv(i, 0, -i * 120 + 480, 0, o, partModel, bPokeyBodyPart);
            if (bodyPart != NULL)
            {
                scale_object(bodyPart, 3.0f);
            }

            partModel = 0x55;
        }

        o->oPokeyUnkF4 = 0x1F;
        o->oPokeyNumBodyParts = 5;
        o->oPokeyUnkFC = 1.0f;
        o->oAction = POKEY_ACT_WANDER;
    }
}

static void pokey_act_wander(void)
{
    s32 targetAngleOffset;
    struct Object *bodyPart;

    if (o->oPokeyNumBodyParts == 0)
    {
        DeactivateObject(o);
    }
    else if (o->oDistanceToMario > 2500.0f)
    {
        o->oAction = POKEY_ACT_UNK2;
        o->oForwardVel = 0.0f;
    }
    else
    {
        treat_far_home_as_mario(1000.0f);
        obj_update_floor_and_walls();

        if (o->oPokeyUnk100 != 0)
        {
            o->oForwardVel = 0.0f;
        }
        else
        {
            o->oForwardVel = 5.0f;
            if (o->oPokeyNumBodyParts < 5)
            {
                if (o->oTimer > 100)
                {
                    bodyPart = spawn_obj_adv(
                        o->oPokeyNumBodyParts, 0, 0, 0, o, 0x55, bPokeyBodyPart);

                    if (bodyPart != NULL)
                    {
                        o->oPokeyUnkF4 = o->oPokeyUnkF4 |
                            (1 << o->oPokeyNumBodyParts);
                        o->oPokeyNumBodyParts += 1;
                        o->oPokeyUnkFC = 0.0f;

                        scale_object(bodyPart, 0.0f);
                    }
                    
                    o->oTimer = 0;
                }
            }
            else
            {
                o->oTimer = 0;
            }

            if (o->oPokeyTurning)
            {
                o->oPokeyTurning = resolve_collisions_and_turn(o->oPokeyTargetYaw, 0x200);
            }
            else
            {
                if (o->oDistanceToMario >= 25000.0f)
                {
                    o->oPokeyTargetYaw = o->oAngleToMario;
                }

                if (!(o->oPokeyTurning = func_802F9F6C(&o->oPokeyTargetYaw)))
                {
                    if (o->oPokeyChangeTargetTimer != 0)
                    {
                        o->oPokeyChangeTargetTimer -= 1;
                    }
                    else if (o->oDistanceToMario > 2000.0f)
                    {
                        o->oPokeyTargetYaw = random_fixed_turn(0x2000);
                        o->oPokeyChangeTargetTimer = random_linear_offset(30, 50);
                    }
                    else
                    {
                        targetAngleOffset = (s32)(0x4000 - (o->oDistanceToMario - 200.0f) * 10.0f);
                        
                        if (targetAngleOffset < 0)
                            targetAngleOffset = 0;
                        else if (targetAngleOffset > 0x4000)
                            targetAngleOffset = 0x4000;

                        if ((s16)(o->oAngleToMario - o->oMoveAngleYaw) > 0)
                            targetAngleOffset = -targetAngleOffset;

                        o->oPokeyTargetYaw = o->oAngleToMario + targetAngleOffset;
                    }
                }

                obj_rotate_yaw_toward(o->oPokeyTargetYaw, 0x200);
            }

        }
        
        obj_move_standard(-78);
    }
}

static void func_802FD2CC(void)
{
    o->oAction = POKEY_ACT_UNINITIALIZED;
    obj_set_pos_to_home();
}

void bhv_pokey_update(void)
{
    o->oDeathSound = 0x5063C081;

    switch (o->oAction)
    {
    case POKEY_ACT_UNINITIALIZED: pokey_act_uninitialized(); break;
    case POKEY_ACT_WANDER: pokey_act_wander(); break;
    case POKEY_ACT_UNK2: func_802FD2CC(); break;
    }
}
