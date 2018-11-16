
void bhv_ttc_pit_block_init(void)
{
    o->collisionData = segmented_to_virtual(D_803319A8[o->oBehParams2ndByte]);
    o->oTTCPitBlockPeakY = o->oPosY + 330.0f;

    if (gTTCSpeedSetting == TTC_SPEED_STOPPED)
    {
        o->oPosY += 330.0f;
    }
}

void bhv_ttc_pit_block_update(void)
{
    if (o->oTimer > o->oTTCPitBlockWaitTime)
    {
        MoveObj2();

        if (cap_f32(&o->oPosY, o->oHomeY, o->oTTCPitBlockPeakY))
        {
            o->oTTCPitBlockDir = o->oTTCPitBlockDir ^ 0x1;

            if ((o->oTTCPitBlockWaitTime = sTTCPitBlockProps[gTTCSpeedSetting][o->oTTCPitBlockDir & 0x1].waitTime) < 0)
            {
                o->oTTCPitBlockWaitTime = random_mod_offset(10, 20, 6);
            }

            o->oVelY = sTTCPitBlockProps[gTTCSpeedSetting][o->oTTCPitBlockDir].speed;
            o->oTimer = 0;
        }
    }
}
