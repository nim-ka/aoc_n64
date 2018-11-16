
void bhv_ttc_pendulum_init(void)
{
    if (gTTCSpeedSetting != TTC_SPEED_STOPPED)
    {
        o->oTTCPendulumAngleAccel = sTTCPendulumAngleAccels[gTTCSpeedSetting];
        o->oTTCPendulumAngle = 6500.0f;
    }
    else
    {
        o->oTTCPendulumAngle = 6371.5557f;
    }
}

void bhv_ttc_pendulum_update(void)
{
    UNUSED f32 startVel;

    if (gTTCSpeedSetting != TTC_SPEED_STOPPED)
    {
        startVel = o->oTTCPendulumAngleVel;
        
        if (o->oTTCPendulumSoundTimer != 0)
        {
            if (--o->oTTCPendulumSoundTimer == 0)
            {
                PlaySound2(0x30380081);
            }
        }

        if (o->oTTCPendulumStoppedTimer != 0)
        {
            o->oTTCPendulumStoppedTimer -= 1;
        }
        else
        {
            if (o->oTTCPendulumAngle * o->oTTCPendulumAccelDir > 0.0f)
            {
                o->oTTCPendulumAccelDir = -o->oTTCPendulumAccelDir;
            }

            o->oTTCPendulumAngleVel += o->oTTCPendulumAngleAccel * o->oTTCPendulumAccelDir;
            if (o->oTTCPendulumAngleVel == 0.0f)
            {
                if (gTTCSpeedSetting == TTC_SPEED_RANDOM)
                {
                    if (RandomU16() % 3 != 0)
                    {
                        o->oTTCPendulumAngleAccel = 13.0f;
                    }
                    else
                    {
                        o->oTTCPendulumAngleAccel = 42.0f;
                    }

                    if (RandomU16() % 2 == 0)
                    {
                        o->oTTCPendulumStoppedTimer = random_linear_offset(5, 30);
                    }
                }

                o->oTTCPendulumSoundTimer = o->oTTCPendulumStoppedTimer + 15;
            }

            o->oTTCPendulumAngle += o->oTTCPendulumAngleVel;
        }
    }
    else
    {
    }

    o->oFaceAngleRoll = (s32)o->oTTCPendulumAngle;
}
