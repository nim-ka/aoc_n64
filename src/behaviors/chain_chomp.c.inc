
void bhv_chain_chomp_chain_part_update(void)
{
    struct ChainSegment *segment;

    if (o->parentObj->oAction == CHAIN_CHOMP_ACT_UNLOAD_CHAIN)
    {
        DeactivateObject(o);
    }
    else if (o->oBehParams2ndByte != 0)
    {
        segment = &o->parentObj->oChainChompSegments[o->oBehParams2ndByte];
        
        o->oPosX = o->parentObj->parentObj->oPosX + segment->posX;
        o->oPosY = o->parentObj->parentObj->oPosY + segment->posY;
        o->oPosZ = o->parentObj->parentObj->oPosZ + segment->posZ;;
    }
    else if (o->parentObj->oChainChompUnk1AC != 0)
    {
        obj_update_floor_and_walls();
        obj_move_standard(78);
    }
}

static void chain_chomp_act_uninitialized(void)
{
    struct ChainSegment *segments;
    s32 i;

    if (o->oDistanceToMario < 3000.0f)
    {
        segments = mem_pool_alloc(D_8035FE0C, 5 * sizeof(struct ChainSegment));
        if (segments != NULL)
        {
            o->oChainChompSegments = segments;
            for (i = 0; i < 5; i++)
            {
                chain_segment_init(&segments[i]);
            }

            obj_set_pos_to_home();

            if ((o->parentObj = SpawnObj(o, 0, bChainChompChainPart)) != NULL)
            {
                for (i = 1; i < 5; i++)
                {
                    spawn_obj_adv(i, 0, 0, 0, o, 0x65, bChainChompChainPart);
                }

                o->oAction = CHAIN_CHOMP_ACT_MOVE;
                obj_unhide();
            }
        }
    }
}

static void func_802FECFC(void)
{
    struct ChainSegment *val24;
    struct ChainSegment *val20;
    f32 val1C;
    f32 val18;
    f32 val14;
    f32 val10;
    f32 val0C;
    f32 val08;
    s32 val04;

    if (o->oVelY < 0.0f)
    {
        val0C = o->oVelY;
    }
    else
    {
        val0C = -20.0f;
    }

    for (val04 = 1; val04 < 5; val04++)
    {
        val24 = &o->oChainChompSegments[val04 - 1];
        val20 = &o->oChainChompSegments[val04];

        if ((val20->posY += val0C) < 0.0f)
        {
            val20->posY = 0.0f;
        }

        val1C = val20->posX - val24->posX;
        val18 = val20->posY - val24->posY;
        val14 = val20->posZ - val24->posZ;
        val10 = sqrtf(val1C*val1C + val18*val18 + val14*val14);

        if (val10 > o->oChainChompUnkFC)
        {
            val10 = o->oChainChompUnkFC / val10;
            val1C *= val10;
            val18 *= val10;
            val14 *= val10;
        }

        val1C += val24->posX;
        val18 += val24->posY;
        val14 += val24->posZ;
        val10 = sqrtf(val1C*val1C + val18*val18 + val14*val14);

        val08 = o->oChainChompUnkF8 * (5 - val04);
        if (val10 > val08)
        {
            val10 = val08 / val10;
            val1C *= val10;
            val18 *= val10;
            val14 *= val10;
        }

        val20->posX = val1C;
        val20->posY = val18;
        val20->posZ = val14;
    }
}

static void func_802FEFEC(void)
{
    approach_f32_2(&o->oChainChompUnkF8, 150.0f, 4.0f);
    o->oChainChompUnkFC = o->oChainChompUnkF8;
}

static void chain_chomp_phase_turning(void)
{
    o->oGravity = -4.0f;

    func_802FEFEC();
    func_802F95B0(0, 0x100);

    if (o->oMoveFlags & 0x00000003)
    {
        obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
        if (abs_angle_diff(o->oAngleToMario, o->oMoveAngleYaw) < 0x800)
        {
            if (o->oTimer > 30)
            {
                if (obj_check_anim_frame(0))
                {
                    func_8029F6F0();
                    if (o->oTimer > 40)
                    {
                        PlaySound2(0x303A0081);
                        o->oSubAction = CHAIN_CHOMP_PHASE_LUNGING;
                        o->oChainChompUnkF8 = 180.0f;
                        o->oForwardVel = 140.0f;
                        o->oVelY = 20.0f;
                        o->oGravity = 0.0f;
                        o->oChainChompTargetPitch = func_802F86C0();
                    }
                }
                else
                {
                    o->oTimer -= 1;
                }
            }
            else
            {
                o->oForwardVel = 0.0f;
            }
        }
        else
        {
            PlaySound2(0x30390081);
            o->oForwardVel = 10.0f;
            o->oVelY = 20.0f;
        }
    }
    else
    {
        obj_rotate_yaw_toward(o->oAngleToMario, 400);
        o->oTimer = 0;
    }
}

static void chain_chomp_phase_lunging(void)
{
    f32 val04;

    face_pitch_approach(o->oChainChompTargetPitch, 0x400);

    if (o->oForwardVel != 0.0f)
    {
        if (o->oChainChompUnk108 == 1)
        {
            o->oForwardVel = o->oVelY = 0.0f;
            o->oChainChompUnk104 = 30.0f;
        }

        if ((val04 = 900.0f - o->oChainChompUnk100) > 220.0f)
        {
            val04 = 220.0f;
        }

        o->oChainChompUnkFC = val04 / 220.0f * o->oChainChompUnkF8;
        o->oTimer = 0;;
    }
    else
    {
        obj_rotate_yaw_toward(
            atan2s(o->oChainChompSegments[0].posZ, o->oChainChompSegments[0].posX),
            0x1000);

        if (o->oChainChompUnk104 != 0.0f)
        {
            approach_f32_2(&o->oChainChompUnk104, 0.0f, 0.8f);
        }
        else
        {
            o->oSubAction = CHAIN_CHOMP_PHASE_TURNING;
        }

        o->oChainChompUnkFC = o->oChainChompUnk104;
        if (gGlobalTimer % 2 != 0)
        {
            o->oChainChompUnkFC = -o->oChainChompUnk104;
        }
    }

    if (o->oTimer < 30)
    {
        func_8029F6F0();
    }
}

static void func_802FF440(void)
{
    o->oForwardVel = 0.0f;
    o->oGravity = -4.0f;

    if (func_802573C8(2) == 2 && (o->oMoveFlags & 0x00000003) && func_8028F9E8(0xAD, o) == 1)
    {
        o->oChainChompUnk1AC = 2;
        o->oTimer = 0;
    }
}

static void func_802FF4EC(void)
{
    func_802FEFEC();

    if (o->oMoveFlags & 0x00000003)
    {
        if (o->oChainChompUnk110 == 0)
        {
            if (obj_rotate_yaw_toward(o->oAngleToMario, 0x320))
            {
                if (o->oTimer > 60)
                {
                    o->oChainChompUnk110 += 1;
                    o->oWallHitboxRadius = 200.0f;
                }
            }
            else
            {
                o->oTimer = 0;
            }
        }
        else
        {
            if (++o->oChainChompUnk110 <= 5)
            {
                PlaySound2(0x30390081);
                o->oMoveAngleYaw = o->oAngleToMario + RandomSign() * 0x2000;
                o->oForwardVel = 30.0f;
                o->oVelY = 50.0f;
            }
            else
            {
                o->oChainChompUnk1AC = 3;
                o->oHomeX = 1450.0f;
                o->oHomeZ = 562.0f;
                o->oMoveAngleYaw = obj_angle_to_home();
                o->oForwardVel = obj_lateral_dist_to_home() / 8.0f;
                o->oVelY = 50.0f;
            }
        }
    }
}

static void func_802FF6C8(void)
{
    if (o->oChainChompUnk1B0 == 0)
    {
        if (o->oMoveFlags & 0x00000200)
        {
            o->oChainChompUnk1B0 = 1;
            o->oMoveAngleYaw = obj_reflect_move_angle_off_wall();
            o->oForwardVel *= 0.4f;
        }
    }
    else
    {
        if (o->oMoveFlags & 0x00000003)
        {
            o->oChainChompUnk1AC = 4;
            o->oHomeX = 3288.0f;
            o->oHomeZ = -1770.0f;
            o->oMoveAngleYaw = obj_angle_to_home();
            o->oForwardVel = obj_lateral_dist_to_home() / 50.0f;
            o->oVelY = 120.0f;
        }
    }
}

static void func_802FF7F8(void)
{
    if (o->oMoveFlags & 0x00000003)
    {
        D_8033B858 = 1;
        o->oChainChompUnk1AC = 5;
    }
}

static void func_802FF83C(void)
{
    if (func_8028F9E8(0xAD, o) == -1)
    {
        func_802573C8(0);
        o->oAction = CHAIN_CHOMP_ACT_UNLOAD_CHAIN;
    }
}

static void chain_chomp_act_move(void)
{
    f32 val0C;
    f32 val08;
    f32 val04;

    if (o->oChainChompUnk1AC == 0 && o->oDistanceToMario > 4000.0f)
    {
        o->oAction = CHAIN_CHOMP_ACT_UNLOAD_CHAIN;
        o->oForwardVel = o->oVelY = 0.0f;
    }
    else
    {
        obj_update_floor_and_walls();

        switch (o->oChainChompUnk1AC)
        {
        case 0:
            switch (o->oSubAction)
            {
            case CHAIN_CHOMP_PHASE_TURNING: chain_chomp_phase_turning(); break;
            case CHAIN_CHOMP_PHASE_LUNGING: chain_chomp_phase_lunging(); break;
            }
            break;
        case 1: func_802FF440(); break;
        case 2: func_802FF4EC(); break;
        case 3: func_802FF6C8(); break;
        case 4: func_802FF7F8(); break;
        case 5: func_802FF83C(); break;
        }

        obj_move_standard(78);

        o->oChainChompSegments[0].posX = o->oPosX - o->parentObj->oPosX;
        o->oChainChompSegments[0].posY = o->oPosY - o->parentObj->oPosY;
        o->oChainChompSegments[0].posZ = o->oPosZ - o->parentObj->oPosZ;

        o->oChainChompUnk100 = sqrtf(
            o->oChainChompSegments[0].posX * o->oChainChompSegments[0].posX +
            o->oChainChompSegments[0].posY * o->oChainChompSegments[0].posY +
            o->oChainChompSegments[0].posZ * o->oChainChompSegments[0].posZ);

        val0C = o->oChainChompUnkF8 * 5.0f;
        if (o->oChainChompUnk100 > val0C)
        {
            val08 = val0C / o->oChainChompUnk100;
            o->oChainChompUnk100 = val0C;

            o->oChainChompSegments[0].posX *= val08;
            o->oChainChompSegments[0].posY *= val08;
            o->oChainChompSegments[0].posZ *= val08;

            if (o->oChainChompUnk1AC == 0)
            {
                o->oPosX = o->parentObj->oPosX + o->oChainChompSegments[0].posX;
                o->oPosY = o->parentObj->oPosY + o->oChainChompSegments[0].posY;
                o->oPosZ = o->parentObj->oPosZ + o->oChainChompSegments[0].posZ;

                o->oChainChompUnk108 = 1;
            }
            else
            {
                val04 = o->parentObj->oPosY;

                o->parentObj->oPosX = o->oPosX - o->oChainChompSegments[0].posX;
                o->parentObj->oPosY = o->oPosY - o->oChainChompSegments[0].posY;
                o->parentObj->oVelY = o->parentObj->oPosY - val04;
                o->parentObj->oPosZ = o->oPosZ - o->oChainChompSegments[0].posZ;
            }
        }
        else
        {
            o->oChainChompUnk108 = 0;
        }

        func_802FECFC();

        if (func_802FA888(&D_803317F0, o->oAction))
        {
            o->oSubAction = CHAIN_CHOMP_PHASE_LUNGING;
            o->oChainChompUnkF8 = 180.0f;
            o->oForwardVel = 0.0f;
            o->oVelY = 300.0f;
            o->oGravity = -4.0f;
            o->oChainChompTargetPitch = -0x3000;
        }
    }
}

static void chain_chomp_act_unload_chain(void)
{
    obj_hide();
    mem_pool_free(D_8035FE0C, o->oChainChompSegments);

    o->oAction = CHAIN_CHOMP_ACT_UNINITIALIZED;
    
    if (o->oChainChompUnk1AC != 0)
    {
        DeactivateObject(o);
    }
}

void bhv_chain_chomp_update(void)
{
    switch (o->oAction)
    {
    case CHAIN_CHOMP_ACT_UNINITIALIZED: chain_chomp_act_uninitialized(); break;
    case CHAIN_CHOMP_ACT_MOVE:          chain_chomp_act_move();          break;
    case CHAIN_CHOMP_ACT_UNLOAD_CHAIN:  chain_chomp_act_unload_chain();  break;
    }
}

void bhv_wooden_post_update(void)
{
    if (!o->oWoodenPostMarioPounding)
    {
        if ((o->oWoodenPostMarioPounding = obj_is_mario_ground_pounding_platform()))
        {
            PlaySound2(0x3065C081);
            o->oWoodenPostSpeedY = -70.0f;
        }
    }
    else if (approach_f32_2(&o->oWoodenPostSpeedY, 0.0f, 25.0f))
    {
        o->oWoodenPostMarioPounding = obj_is_mario_ground_pounding_platform();
    }
    else if ((o->oWoodenPostOffsetY += o->oWoodenPostSpeedY) < -190.0f)
    {
        o->oWoodenPostOffsetY = -190.0f;
        if (o->parentObj != o)
        {
            func_80321228();
            o->parentObj->oChainChompUnk1AC = 1;
            o->parentObj = o;
        }
    }

    if (o->oWoodenPostOffsetY != 0.0f)
    {
        o->oPosY = o->oHomeY + o->oWoodenPostOffsetY;
    }
    else if (!(o->oBehParams & 0x0000FF00))
    {
        if (o->oDistanceToMario > 400.0f)
        {
            o->oTimer = o->oWoodenPostTotalMarioAngle = 0;
        }
        else
        {
            o->oWoodenPostTotalMarioAngle += (s16)(o->oAngleToMario - o->oWoodenPostPrevAngleToMario);
            if (absi(o->oWoodenPostTotalMarioAngle) > 0x30000 && o->oTimer < 200)
            {
                spawn_object_loot_yellow_coins(o, 5, 20.0f);
                func_8029C6D8(o, 1);
            }
        }

        o->oWoodenPostPrevAngleToMario = o->oAngleToMario;
    }
}

void bhv_chain_chomp_freed_explosion_init(void)
{
    o->parentObj = obj_nearest_object_with_behavior(bChainChomp);
}

void bhv_chain_chomp_freed_explosion_update(void)
{
    if (o->parentObj->oChainChompUnk1B0 != 0)
    {
        func_802A3034(0x300F0081);
        func_8027F440(1, o->oPosX, o->oPosY, o->oPosZ);
        func_802AA618(0, 0x7F, 200.0f);
        func_802AD82C(30, 0x8A, 3.0f, 4);
        DeactivateObject(o);
    }
}
