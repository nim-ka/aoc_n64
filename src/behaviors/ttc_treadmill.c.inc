
void bhv_ttc_treadmill_init(void)
{
    o->collisionData = segmented_to_virtual(D_8033197C[o->oBehParams2ndByte & 0x1]);

    o->oTTCTreadmillUnkF4 = segmented_to_virtual(ttc_seg7_arr_07016840);
    o->oTTCTreadmillUnkF8 = segmented_to_virtual(ttc_seg7_arr_07016904);

    *o->oTTCTreadmillUnkF4 = *o->oTTCTreadmillUnkF8 = sTTCTreadmillSpeeds[gTTCSpeedSetting];

    sMasterTreadmill = NULL;
}

void bhv_ttc_treadmill_update(void)
{
    if (sMasterTreadmill == o || sMasterTreadmill == NULL)
    {
        sMasterTreadmill = o;

        PlaySound(0x40080001);

        if (gTTCSpeedSetting == TTC_SPEED_RANDOM)
        {
            if (o->oTimer > o->oTTCTotalTimeUntilSwitch)
            {
                if (approach_f32_2(&o->oTTCTreadmillSpeed, 0.0f, 10.0f))
                {
                    o->oTTCTotalTimeUntilSwitch = random_mod_offset(10, 20, 7);
                    o->oTTCTreadmillTargetSpeed = RandomSign() * 50.0f;
                    o->oTimer = 0;
                }
            }
            else if (o->oTimer > 5)
            {
                approach_f32_2(&o->oTTCTreadmillSpeed, o->oTTCTreadmillTargetSpeed, 10.0f);
            }

            *o->oTTCTreadmillUnkF4 = *o->oTTCTreadmillUnkF8 = o->oTTCTreadmillSpeed;
        }
    }

    o->oForwardVel = 0.084f * *o->oTTCTreadmillUnkF4;
}
