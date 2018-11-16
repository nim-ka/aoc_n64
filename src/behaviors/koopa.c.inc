
void bhv_koopa_init(void)
{
    if ((o->oKoopaMovementType = o->oBehParams2ndByte) == KOOPA_BF_SMALL)
    {
        o->oKoopaMovementType = KOOPA_BP_NORMAL;
        o->oKoopaUnkF4 = 1.6f / 3.0f;
        o->oDrawingDistance = 1500.0f;
        ScaleObject(0.8f);
        o->oGravity = -6.4f / 3.0f;
    }
    else if (o->oKoopaMovementType >= KOOPA_BP_KOOPA_THE_QUICK_BASE)
    {
        o->oKoopaTheQuickRaceIndex = o->oKoopaMovementType - KOOPA_BP_KOOPA_THE_QUICK_BASE;
        o->oKoopaUnkF4 = 4.0f;
        ScaleObject(3.0f);
    }
    else
    {
        o->oKoopaUnkF4 = 1.0f;
    }
}

static void func_802FACAC(s8 arg0, s8 arg1)
{
    s32 val04;
    if (o->header.gfx.scale[0] > 1.5f)
        val04 = 0x50342081;
    else
        val04 = 0x50350081;

    func_802F9378(arg0, arg1, val04);
}

static s32 koopa_check_run_from_mario(void)
{
    if (o->oKoopaDistanceToMario < 300.0f &&
        abs_angle_diff(o->oKoopaAngleToMario, o->oAngleYaw) < 0x3000)
    {
        o->oAction = KOOPA_SHELLED_ACT_RUNNING;
        return TRUE;
    }

    return FALSE;
}

static void koopa_shelled_update_stopped(void)
{
    o->oForwardVel = 0.0f;
    if (func_802F92B0(7))
    {
        o->oAction = KOOPA_SHELLED_ACT_WALKING;
        o->oKoopaTargetYaw = o->oAngleYaw + 0x2000 * (s16)RandomSign();
    }
}

static void func_802FAE1C(void)
{
    forward_vel_approach(
        3.0f * o->oKoopaUnkF4,
        0.3f * o->oKoopaUnkF4);
    
    if (func_802F92B0(11))
    {
        o->oUnk150 += 1;
        o->oKoopaUnk1AC = random_linear_offset(30, 100);
    }
}

static void func_802FAEA8(void)
{
    func_8029ED38(9);
    func_802FACAC(2, 17);

    if (o->oKoopaUnk1AC != 0)
    {
        o->oKoopaUnk1AC -= 1;
    }
    else if (func_8029F788())
    {
        o->oUnk150 += 1;
    }
}

static void func_802FAF2C(void)
{
    forward_vel_approach(0.0f, 1.0f * o->oKoopaUnkF4);
    if (func_802F92B0(10))
    {
        o->oAction = KOOPA_SHELLED_ACT_STOPPED;
    }
}

static void koopa_shelled_update_walking(void)
{
    if (o->oKoopaTurning)
    {
        o->oKoopaTurning =
            resolve_collisions_and_turn(o->oKoopaTargetYaw, 0x200);
    }
    else
    {
        if (o->oDistanceToMario >= 25000.0f)
            o->oKoopaTargetYaw = o->oAngleToMario;

        o->oKoopaTurning =
            func_802F9F6C(&o->oKoopaTargetYaw);
        func_8029DE70(o->oKoopaTargetYaw, 0x200);
    }

    switch (o->oUnk150)
    {
    case 0: func_802FAE1C(); break;
    case 1: func_802FAEA8(); break;
    case 2: func_802FAF2C(); break;
    }

    koopa_check_run_from_mario();
}

static void koopa_shelled_update_running(void)
{
    func_8029ED38(1);
    func_802FACAC(0, 11);

    if (o->oDistanceToMario >= 25000.0f)
    {
        o->oAngleToMario += 0x8000;
        o->oDistanceToMario = 0.0f;
    }

    if (o->oTimer > 30 && o->oDistanceToMario > 800.0f)
    {
        if (forward_vel_approach(0.0f, 1.0f))
            o->oAction = KOOPA_SHELLED_ACT_STOPPED;
    }
    else
    {
        func_8029DE70(o->oAngleToMario + 0x8000, 0x400);
        forward_vel_approach(17.0f, 1.0f);
    }
}

static void func_802FB1D8(f32 arg0)
{
    if (o->oMoveFlags & 0x00000003)
    {
        forward_vel_approach(0.0f, arg0);
        if (o->oForwardVel > 5.0f)
        {
            if (!(o->oTimer % 4))
                func_8029E73C(o, 150, beh_white_puff_smoke2, 1.0f);
        }
    }
}

static void koopa_shelled_update_lying(void)
{
    if (o->oForwardVel != 0.0f)
    {
        if (o->oMoveFlags & 0x00000200)
            o->oAngleYaw = func_802A2AC0();

        func_802F927C(5);
        func_802FB1D8(0.3f);
    }
    else if (o->oKoopaUnk1AC != 0)
    {
        o->oKoopaUnk1AC -= 1;
        func_8029F728();
    }
    else if (func_802F92B0(6))
    {
        o->oAction = KOOPA_SHELLED_ACT_STOPPED;
    }
}

void func_802FB364(s32 arg0)
{
    if (o->header.gfx.scale[0] > 0.8f)
    {
        PlaySound2(0x503EA081);

        o->oKoopaMovementType = KOOPA_BP_UNSHELLED;
        o->oAction = KOOPA_UNSHELLED_ACT_LYING;
        o->oForwardVel = 20.0f;

        if (arg0 != 3 && arg0 != 4)
            o->oAngleYaw = func_8029DF18(gMarioObject, o);

        SetModel(0xBF);
        SpawnObj(o, 0xBE, beh_koopa_shell);
        func_8029FE38();
    }
    else
    {
        func_802FA078();
    }
}

static void koopa_shelled_update(void)
{
    MoveRelated();
    update_blinking(&o->oKoopaBlinkTimer, 20, 50, 4);

    switch (o->oAction)
    {
    case KOOPA_SHELLED_ACT_STOPPED:
        koopa_shelled_update_stopped();
        koopa_check_run_from_mario();
        break;

    case KOOPA_SHELLED_ACT_WALKING:
        koopa_shelled_update_walking();
        break;

    case KOOPA_SHELLED_ACT_RUNNING:
        koopa_shelled_update_running();
        break;

    case KOOPA_SHELLED_ACT_LYING:
        koopa_shelled_update_lying();
        break;
    }

    if (o->header.gfx.scale[0] > 0.8f)
    {
        func_802FA468(&D_80331730, o->oAction, D_80331748);
    }
    else
    {
        func_802FA468(&D_80331730, KOOPA_SHELLED_ACT_UNK4, D_80331740);
        if (o->oAction == KOOPA_SHELLED_ACT_UNK4)
            func_802FA078();
    }

    MoveObj(-78);
}

static void koopa_unshelled_update_running(void)
{
    f32 val0C = 99999.0f;
    struct Object *val08;

    func_8029ED38(3);
    func_802FACAC(0, 6);

    if (o->oKoopaTurning)
    {
        o->oKoopaTurning =
            resolve_collisions_and_turn(o->oKoopaTargetYaw, 0x600);
    }
    else
    {
        if (o->oDistanceToMario >= 25000.0f)
            o->oKoopaTargetYaw = o->oAngleToMario;

        val08 = func_8029F270(beh_koopa_shell, &val0C);
        if (val08 != NULL)
        {
            o->oKoopaTargetYaw = func_8029DF18(o, val08);
        }
        else if (!(o->oKoopaTurning = func_802F9F6C(&o->oKoopaTargetYaw)))
        {
            if (o->oKoopaUnk100 != 0)
                o->oKoopaUnk100 -= 1;
            else
                o->oKoopaTargetYaw = random_fixed_turn(0x2000);
        }

        if (o->oDistanceToMario > 800.0f ||
            (val08 != NULL &&
            abs_angle_diff(o->oKoopaTargetYaw, o->oAngleToMario + 0x8000) < 0x2000))
        {
            func_8029DE70(o->oKoopaTargetYaw, 0x600);
        }
        else
        {
            func_8029DE70(o->oAngleToMario + 0x8000, 0x600);
        }
    }

    if (forward_vel_approach(20.0f, 1.0f) &&
        val0C < 600.0f &&
        abs_angle_diff(o->oKoopaTargetYaw, o->oAngleYaw) < 0xC00)
    {
        o->oAngleYaw = o->oKoopaTargetYaw;
        o->oAction = KOOPA_UNSHELLED_ACT_DIVING;
        o->oForwardVel *= 1.2f;
        o->oVelY = val0C / 20.0f;
        o->oKoopaUnk1AC = 20;
    }
}

static void koopa_unshelled_update_lying(void)
{
    struct Object *val04;
    f32 val00;

    if (o->oTimer > 10)
        func_8029FE58();

    if (o->oTimer > 10)
    {
        val04 = func_8029F270(beh_koopa_shell, &val00);

        if (val04 != NULL &&
            objects_calc_distance(val04, gMarioObject) > 200.0f &&
            val00 < 50.0f)
        {
            o->oKoopaMovementType = KOOPA_BP_NORMAL;
            o->oAction = KOOPA_UNSHELLED_ACT_UNKNOWN_3;
            o->oForwardVel *= 0.5f;

            SetModel(0x68);
            DeactivateObject(val04);
            goto end;
        }
    }

    if (o->oForwardVel != 0.0f)
    {
        if (o->oAction == KOOPA_UNSHELLED_ACT_LYING)
        {
            o->oAnimState = 1;
            func_802F927C(2);
        }
        else
        {
            func_802F927C(5);
        }
        func_802FB1D8(0.5f);
    }
    else if (o->oKoopaUnk1AC != 0)
    {
        o->oKoopaUnk1AC -= 1;
        func_8029F728();
    }
    else if (func_802F92B0(6))
    {
        o->oAction = KOOPA_UNSHELLED_ACT_RUNNING;
    }

end:
    ;
}

static void func_802FBA44(void)
{
    func_802F927C(0);
}

static void koopa_unshelled_update(void)
{
    MoveRelated();
    update_blinking(&o->oKoopaBlinkTimer, 10, 15, 3);

    switch (o->oAction)
    {
    case KOOPA_UNSHELLED_ACT_RUNNING: koopa_unshelled_update_running(); break;
    case KOOPA_UNSHELLED_ACT_DIVING:
    case KOOPA_UNSHELLED_ACT_LYING: koopa_unshelled_update_lying(); break;
    case KOOPA_UNSHELLED_ACT_UNKNOWN_3: func_802FBA44(); break;
    }

    func_802FA468(&D_80331730, o->oAction, D_80331740);
    MoveObj(-78);
}

s32 obj_begin_race(s32 noTimer)
{
    if (o->oTimer == 50)
    {
        PlaySound2(0x314D4081);

        if (!noTimer)
        {
            func_80320AE8(0, 0x409, 0);
            level_control_timer(TIMER_CONTROL_SHOW);
            level_control_timer(TIMER_CONTROL_START);
            o->parentObj->oUnknownUnkF4_S32 = 1;
        }

        func_802573C8(0);
        func_802A4CC0();
    }
    else if (o->oTimer > 50)
    {
        return TRUE;
    }

    return FALSE;
}

static void koopa_the_quick_act_wait_before_race(void)
{
    koopa_shelled_update_stopped();

    if (o->oKoopaTheQuickInitTextboxCooldown != 0)
    {
        o->oKoopaTheQuickInitTextboxCooldown -= 1;
    }
    else if (func_802A4114(400.0f, 400.0f))
    {
        o->oAction = KOOPA_THE_QUICK_ACT_UNK2;
        o->oForwardVel = 0.0f;
        func_8029ED38(7);
    }
}

static void koopa_the_quick_act_show_init_text(void)
{
    s32 response = func_802F870C(sKoopaTheQuickData[o->oKoopaTheQuickRaceIndex].initText);
    UNUSED s32 unused;

    if (response == 1)
    {
        D_8035FEEA = 0;
        o->oAction = KOOPA_THE_QUICK_ACT_UNK3;
        o->oForwardVel = 0.0f;
        
        o->parentObj = func_8029F1E0(bKoopaRaceEndpoint);
        o->oKoopaTheQuickUnkFC = o->oKoopaTheQuickUnk100 =
            segmented_to_virtual(sKoopaTheQuickData[o->oKoopaTheQuickRaceIndex].unk04);

        o->oKoopaTurning = FALSE;

        o->oFlags |= 0x00000080;;
    }
    else if (response == 2)
    {
        o->oAction = KOOPA_THE_QUICK_ACT_WAIT_BEFORE_RACE;
        o->oKoopaTheQuickInitTextboxCooldown = 60;
    }
}

static s32 func_802FBDE4(void)
{
    struct Object *val0C;
    f32 val08;
    s16 val06;
    f32 val00;

    val0C = func_8029F270(beh_bowling_ball, &val08);

    if (val0C != NULL)
    {
        val06 = UnknownMove(o, val0C, 16, 0);
        val00 = val0C->oForwardVel * coss(val0C->oAngleYaw - o->oAngleYaw);

        if (abs_angle_diff(o->oAngleYaw, val06) < 0x4000)
        {
            if (val08 < 400.0f)
            {
                if (val00 < o->oForwardVel * 0.7f)
                    return 1;
                else
                    o->oForwardVel -= 2.0f;
            }
        }
        else if (val08 < 300.0f && val00 > o->oForwardVel)
        {
            return -1;
        }
    }

    return 0;
}

static void func_802FBF64(void)
{
    func_8029ED98(9, o->oForwardVel * 0.09f);
    func_802FACAC(2, 17);
}

static void func_802FBFB8(void)
{
    f32 val0C;
    s32 val08;

    if (obj_begin_race(FALSE))
    {
        func_802A3164(180.0f, 300.0f);
        if (func_802A24B4(0) == -1)
        {
            o->oAction = KOOPA_THE_QUICK_ACT_UNK4;
        }
        else
        {
            val0C = 1.0f + sins((s16)(f32)o->oKoopaUnk108_2);
            func_8029DE70(o->oKoopaAngleToMario, (s32)(o->oKoopaUnkF4 * 150.0f));

            switch (o->oUnk150)
            {
            case 0:
                func_802FAE1C();
                break;

            case 1:
                func_802FBF64();

                if (o->parentObj->oUnknownUnkFC_S32 != 0 &&
                    o->oDistanceToMario > 1500.0f &&
                    (o->oKoopaUnk104_2 & 0x000000FF) < 28)
                {
                    o->oKoopaUnkF4 = 8.0f;
                }
                else if (o->oKoopaTheQuickRaceIndex != 0)
                {
                    o->oKoopaUnkF4 = 6.0f;
                }
                else
                {
                    o->oKoopaUnkF4 = 4.0f;
                }

                forward_vel_approach(o->oKoopaUnkF4 * 6.0f * val0C, o->oKoopaUnkF4 * 0.1f);
                if (o->oMoveFlags & 0x00000200)
                    o->oVelY = 20.0f;
                
                val08 = func_802FBDE4();
                if (val08 != 0 || (o->oMoveFlags & 0x00000400))
                {
                    if (val08 < 0)
                        o->oForwardVel = 0.0f;
                    
                    if (val08 != 0 || (o->oKoopaUnk104_2 & 0x000000FF) >= 8)
                        o->oVelY = 80.0f;
                    else
                        o->oVelY = 40.0f;

                    o->oGravity = -6.0f;
                    o->oUnk150 = 2;
                    o->oMoveFlags = 0;
                    func_8029ED38(12);
                }
                break;

            case 2:
                if (o->oMoveFlags & 0x00000003)
                {
                    if (func_802F92B0(13))
                        o->oUnk150 -= 1;
                    
                    func_802FBDE4();
                }
            }
        }
    }
}

static void func_802FC334(void)
{
    forward_vel_approach(3.0f, 1.0f);
    func_8029ED98(9, 0.99f);

    if (func_8029F788())
    {
        o->oAction = KOOPA_THE_QUICK_ACT_UNK5;
        o->oForwardVel = 3.0f;
    }
}

static void func_802FC3B4(void)
{
    func_802FAF2C();
    if (o->oAction == KOOPA_THE_QUICK_ACT_WAIT_BEFORE_RACE)
        o->oAction = KOOPA_THE_QUICK_ACT_UNK6;
}

static void func_802FC400(void)
{
    s32 val04;

    func_8029ED38(7);

    if (o->parentObj->oUnknownUnk100_S32 == 0)
    {
        if (func_802A4114(400.0f, 400.0f))
        {
            func_80320CE8(0x409);

            if (o->parentObj->oUnknownUnkFC_S32 != 0)
            {
                if (o->parentObj->oUnknownUnkFC_S32 < 0)
                {
                    o->parentObj->oUnknownUnkFC_S32 = 0;
                    o->parentObj->oUnknownUnk100_S32 = 6;
                }
                else
                {
                    o->parentObj->oUnknownUnk100_S32 = sKoopaTheQuickData[o->oKoopaTheQuickRaceIndex].unk02;
                }
            }
            else
            {
                o->parentObj->oUnknownUnk100_S32 = 41;
            }

            o->oFlags &= ~0x00000080;
        }
    }
    else if (o->parentObj->oUnknownUnk100_S32 > 0)
    {
        val04 = CreateMessageBox(2, 1, 162, o->parentObj->oUnknownUnk100_S32);
        if (val04 != 0)
        {
            o->parentObj->oUnknownUnk100_S32 = -1;
            o->oTimer = 0;
        }
    }
    else if (o->parentObj->oUnknownUnkFC_S32 != 0)
    {
        CreateStar(
            sKoopaTheQuickData[o->oKoopaTheQuickRaceIndex].starPos[0],
            sKoopaTheQuickData[o->oKoopaTheQuickRaceIndex].starPos[1],
            sKoopaTheQuickData[o->oKoopaTheQuickRaceIndex].starPos[2]);

        o->parentObj->oUnknownUnkFC_S32 = 0;
    }
}

static void koopa_the_quick_update(void)
{
    MoveRelated();
    update_blinking(&o->oKoopaBlinkTimer, 10, 15, 3);

    switch (o->oAction)
    {
    case KOOPA_THE_QUICK_ACT_WAIT_BEFORE_RACE:
    case KOOPA_THE_QUICK_ACT_UNK1: koopa_the_quick_act_wait_before_race(); break;
    case KOOPA_THE_QUICK_ACT_UNK2: koopa_the_quick_act_show_init_text(); break;
    case KOOPA_THE_QUICK_ACT_UNK3: func_802FBFB8(); break;
    case KOOPA_THE_QUICK_ACT_UNK4: func_802FC334(); break;
    case KOOPA_THE_QUICK_ACT_UNK5: func_802FC3B4(); break;
    case KOOPA_THE_QUICK_ACT_UNK6: func_802FC400(); break;
    }

    if (o->parentObj != o)
    {
        if (objects_calc_distance(o, o->parentObj) < 400.0f)
            o->parentObj->oUnknownUnkF8_S32 = 1;
    }
    
    func_802A3164(140.0f, 300.0f);
    MoveObj(-78);
}

void bhv_koopa_update(void)
{
    o->oUnk1C4 = 0x5063B081;
    
    if (o->oKoopaMovementType >= KOOPA_BP_KOOPA_THE_QUICK_BASE)
    {
        koopa_the_quick_update();
    }
    else if (func_802FA7CC(o->oKoopaUnkF4 * 1.5f))
    {
        o->oKoopaDistanceToMario = o->oDistanceToMario;
        o->oKoopaAngleToMario = o->oAngleToMario;
        treat_far_home_as_mario(1000.0f);

        switch (o->oKoopaMovementType)
        {
        case KOOPA_BP_UNSHELLED:           koopa_unshelled_update(); break;
        case KOOPA_BP_NORMAL:              koopa_shelled_update();   break;
        case KOOPA_BP_KOOPA_THE_QUICK_BOB:
        case KOOPA_BP_KOOPA_THE_QUICK_THI: koopa_the_quick_update(); break;
        }
    }
    else
    {
        o->oAnimState = 1;
    }

    face_yaw_approach(o->oAngleYaw, 0x600);
}

void bhv_koopa_race_endpoint_update(void)
{
    if (o->oKoopaRaceEndpointUnkF4 && o->oKoopaRaceEndpointUnk104 == 0)
    {
        if (o->oKoopaRaceEndpointUnkF8 != 0 || o->oDistanceToMario < 400.0f)
        {
            o->oKoopaRaceEndpointUnk104 = 1;
            level_control_timer(TIMER_CONTROL_STOP);

            if (o->oKoopaRaceEndpointUnkF8 == 0)
            {
                func_803212F0();
                if (D_8035FEEA != 0)
                {
                    o->oKoopaRaceEndpointUnkFC = -1;
                }
                else
                {
                    o->oKoopaRaceEndpointUnkFC = 1;
                }
            }
        }
    }
}
