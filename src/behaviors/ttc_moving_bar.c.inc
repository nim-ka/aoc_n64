
void bhv_ttc_moving_bar_init(void)
{
    if ((o->oTTCMovingBarTotalWaitTime = sTTCMovingBarWaitTimes[gTTCSpeedSetting]) == 0)
    {
        o->oTTCMovingBarOffset = 250.0f;
    }

    o->oTTCMovingBarStoppedTimer = 10 * o->oBehParams2ndByte;
    o->oMoveAngleYaw = 0x4000 - o->oMoveAngleYaw;
}

static void ttc_moving_bar_act_wait(void)
{
    if (o->oTTCMovingBarTotalWaitTime != 0 && o->oTimer > o->oTTCMovingBarTotalWaitTime)
    {
        if (o->oTTCMovingBarStoppedTimer != 0)
        {
            o->oTTCMovingBarStoppedTimer -= 1;
        }
        else
        {
            if (gTTCSpeedSetting == TTC_SPEED_RANDOM)
            {
                o->oTTCMovingBarTotalWaitTime = sTTCMovingBarRandomWaitTimes[RandomU16() & 0x3];

                if (RandomU16() % 2 == 0)
                {
                    o->oTTCMovingBarStoppedTimer = random_linear_offset(20, 100);
                }
            }

            o->oAction = TTC_MOVING_BAR_ACT_PULL_BACK;
            o->oTTCMovingBarSpeed = -8.0f;
        }
    }
}

static void ttc_moving_bar_act_pull_back(void)
{
    if ((o->oTTCMovingBarSpeed += 0.73f) > 0.0f)
    {
        if (o->oTTCMovingBarStoppedTimer != 0)
        {
            o->oTTCMovingBarStoppedTimer -= 1;
            o->oTTCMovingBarSpeed = 0.0f;
        }
        else
        {
            o->oAction = TTC_MOVING_BAR_ACT_EXTEND;
            o->oTTCMovingBarSpeed = 29.0f;
        }
    }
}

static void ttc_moving_bar_reset(void)
{
    o->oTTCMovingBarOffset = o->oTTCMovingBarSpeed = 0.0f;
    o->oAction = TTC_MOVING_BAR_ACT_WAIT;
}

static void ttc_moving_bar_act_extend(void)
{
    f32 accel;

    // If we passed the 250 threshold and we aren't moving too fast
    if ((o->oTTCMovingBarOffset == 250.0f ||
            (250.0f - o->oTTCMovingBarOffset) * (250.0f - o->oTTCMovingBarStartOffset) < 0.0f) &&
        o->oTTCMovingBarSpeed > -8.0f &&
        o->oTTCMovingBarSpeed < 8.0f)
    {
        o->oAction = TTC_MOVING_BAR_ACT_RETRACT;
        o->oTTCMovingBarSpeed = 0;
    }
    else
    {
        if (o->oTTCMovingBarOffset < 250.0f)
        {
            accel = 6.4f;
        }
        else
        {
            accel = -6.4f;
        }

        if (o->oTTCMovingBarSpeed * accel < 0.0f)
        {
            accel *= 2.35f;
        }

        o->oTTCMovingBarSpeed += accel;

        if (gTTCSpeedSetting == 2 &&
            o->oTTCMovingBarOffset * o->oTTCMovingBarStartOffset < 0.0f &&
            RandomU16() % 4 == 0)
        {
            ttc_moving_bar_reset();
        }
    }
}

static void ttc_moving_bar_act_retract(void)
{
    if (o->oTimer > 30)
    {
        o->oTTCMovingBarSpeed = -5.0f;
        if (o->oTTCMovingBarOffset < 0.0f)
        {
            ttc_moving_bar_reset();
        }
    }
}

void bhv_ttc_moving_bar_update(void)
{
    o->oTTCMovingBarStartOffset = o->oTTCMovingBarOffset;
    func_802F8854(0);
    o->oTTCMovingBarOffset += o->oTTCMovingBarSpeed;

    switch (o->oAction)
    {
    case TTC_MOVING_BAR_ACT_WAIT:      ttc_moving_bar_act_wait();      break;
    case TTC_MOVING_BAR_ACT_PULL_BACK: ttc_moving_bar_act_pull_back(); break;
    case TTC_MOVING_BAR_ACT_EXTEND:    ttc_moving_bar_act_extend();    break;
    case TTC_MOVING_BAR_ACT_RETRACT:   ttc_moving_bar_act_retract();   break;
    }

    func_802F8770(o->oTTCMovingBarOffset);
    func_802F8854(1);
}
