
void bhv_racing_penguin_init(void)
{
    if (gMarioState->numStars == 120)
    {
        ScaleObject(8.0f);
        o->header.gfx.scale[1] = 5.0f;
        o->oBehParams2ndByte = 1;
    }
}

static void racing_penguin_act_wait_for_mario(void)
{
    if (o->oTimer > o->oRacingPenguinInitTextCooldown &&
        o->oPosY - gMarioObject->oPosY <= 0.0f &&
        func_802A4114(400.0f, 400.0f))
    {
        o->oAction = RACING_PENGUIN_ACT_SHOW_INIT_TEXT;
    }
}

static void racing_penguin_act_show_init_text(void)
{
    s32 response;
    struct Object *child;

    response = func_802F870C(sRacingPenguinData[o->oBehParams2ndByte].text);
    if (response == 1)
    {
        child = func_8029F1E0(bPenguinRaceFinishLine);
        child->parentObj = o;

        child = func_8029F1E0(bPenguinRaceShortcutCheck);
        child->parentObj = o;

        o->oRacingPenguinUnkFC = o->oRacingPenguinUnk100 = segmented_to_virtual(ccm_seg7_trajectory_penguin_race);
        o->oRacingPenguinUnk104 = 0;

        o->oAction = RACING_PENGUIN_ACT_PREPARE_FOR_RACE;
        o->oVelY = 60.0f;;
    }
    else if (response == 2)
    {
        o->oAction = RACING_PENGUIN_ACT_WAIT_FOR_MARIO;
        o->oRacingPenguinInitTextCooldown = 60;
    }
}

static void racing_penguin_act_prepare_for_race(void)
{
    if (obj_begin_race(TRUE))
    {
        o->oAction = RACING_PENGUIN_ACT_RACE;
        o->oForwardVel = 20.0f;
    }

    func_8029DE70(0x4000, 2500);
}

static void racing_penguin_act_race(void)
{
    f32 targetSpeed;
    f32 minSpeed;

    if (func_802A24B4(0) == -1)
    {
        o->oRacingPenguinReachedBottom = TRUE;
        o->oAction = RACING_PENGUIN_ACT_FINISH_RACE;
    }
    else
    {
        targetSpeed = o->oPosY - gMarioObject->oPosY;
        minSpeed = 70.0f;

        PlaySound(0x60050001);

        if (targetSpeed < 100.0f || (o->oRacingPenguinUnk104 & 0xFF) >= 35)
        {
            if ((o->oRacingPenguinUnk104 & 0xFF) >= 35)
            {
                minSpeed = 60.0f;
            }

            approach_f32_2(&o->oRacingPenguinWeightedNewTargetSpeed, -500.0f, 100.0f);
        }
        else
        {
            approach_f32_2(&o->oRacingPenguinWeightedNewTargetSpeed, 1000.0f, 30.0f);
        }

        targetSpeed = 0.1f * (o->oRacingPenguinWeightedNewTargetSpeed + targetSpeed);
        cap_f32(&targetSpeed, minSpeed, 150.0f);
        forward_vel_approach(targetSpeed, 0.4f);

        func_8029ED38(1);
        func_8029DE70(o->oRacingPenguinUnk10C, (s32)(15.0f * o->oForwardVel));

        if (func_8029F828() && (o->oMoveFlags & 0x00000003))
        {
            func_8029E880(0, 0, -100, 0, 4.0f, o, 150, beh_white_puff_smoke2);
        }
    }

    if (func_8029F998())
    {
        if (o->oTimer > 60)
        {
            o->oRacingPenguinMarioCheated = TRUE;
        }
    }
    else
    {
        o->oTimer = 0;
    }
}

static void racing_penguin_act_finish_race(void)
{
    if (o->oForwardVel != 0.0f)
    {
        if (o->oTimer > 5 && (o->oMoveFlags & 0x00000200))
        {
            PlaySound2(0x50684081);
            func_8027F440(1, o->oPosX, o->oPosY, o->oPosZ);
            o->oForwardVel = 0.0f;
        }
    }
    else if (func_802F92B0(2) != 0)
    {
        o->oAction = RACING_PENGUIN_ACT_SHOW_FINAL_TEXT;
    }
}

static void racing_penguin_act_show_final_text(void)
{
    s32 textResult;

    if (o->oRacingPenguinFinalTextbox == 0)
    {
        if (func_8029DE70(0, 200))
        {
            func_8029ED38(3);
            o->oForwardVel = 0.0f;

            if (func_802A4114(400.0f, 400.0f))
            {
                if (o->oRacingPenguinMarioWon)
                {
                    if (o->oRacingPenguinMarioCheated)
                    {
                        o->oRacingPenguinFinalTextbox = 0x84;
                        o->oRacingPenguinMarioWon = FALSE;
                    }
                    else
                    {
                        o->oRacingPenguinFinalTextbox = 0x38;
                    }
                }
                else
                {
                    o->oRacingPenguinFinalTextbox = 0x25;
                }
            }
        }
        else
        {
            func_8029ED38(0);

#ifndef VERSION_JP
            func_802BE3B4(1);
#endif

            o->oForwardVel = 4.0f;
        }
    }
    else if (o->oRacingPenguinFinalTextbox > 0)
    {
        if ((textResult = CreateMessageBox(2, 1, 0xA2, o->oRacingPenguinFinalTextbox)) != 0)
        {
            o->oRacingPenguinFinalTextbox = -1;
            o->oTimer = 0;
        }
    }
    else if (o->oRacingPenguinMarioWon)
    {
#ifdef VERSION_JP
        CreateStar(-7339.0f, -5700.0f, -6774.0f);
#else
        func_u_802A5588(-7339.0f, -5700.0f, -6774.0f, 200.0f);
#endif
        o->oRacingPenguinMarioWon = FALSE;
    }
}

void bhv_racing_penguin_update(void)
{
    MoveRelated();

    switch (o->oAction)
    {
    case RACING_PENGUIN_ACT_WAIT_FOR_MARIO:   racing_penguin_act_wait_for_mario();   break;
    case RACING_PENGUIN_ACT_SHOW_INIT_TEXT:   racing_penguin_act_show_init_text();   break;
    case RACING_PENGUIN_ACT_PREPARE_FOR_RACE: racing_penguin_act_prepare_for_race(); break;
    case RACING_PENGUIN_ACT_RACE:             racing_penguin_act_race();             break;
    case RACING_PENGUIN_ACT_FINISH_RACE:      racing_penguin_act_finish_race();      break;
    case RACING_PENGUIN_ACT_SHOW_FINAL_TEXT:  racing_penguin_act_show_final_text();  break;
    }

    MoveObj(78);
    func_802A4780();
    func_802A3164(sRacingPenguinData[o->oBehParams2ndByte].radius, sRacingPenguinData[o->oBehParams2ndByte].height);
}

void bhv_penguin_race_finish_line_update(void)
{
    if (o->parentObj->oRacingPenguinReachedBottom ||
        (o->oDistanceToMario < 1000.0f && gMarioObject->oPosZ - o->oPosZ < 0.0f))
    {
        if (!o->parentObj->oRacingPenguinReachedBottom)
        {
            o->parentObj->oRacingPenguinMarioWon = TRUE;
        }
    }
}

void bhv_penguin_race_shortcut_check_update(void)
{
    if (o->oDistanceToMario < 500.0f)
    {
        o->parentObj->oRacingPenguinMarioCheated = TRUE;
    }
}
