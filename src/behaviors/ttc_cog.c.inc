
void bhv_ttc_cog_init(void)
{
    o->collisionData = segmented_to_virtual(sTTCCogCollisionModels[(o->oBehParams2ndByte & TTC_COG_BP_SHAPE_MASK) >> 1]);
    o->oTTCCogDir = sTTCCogDirections[o->oBehParams2ndByte & TTC_COG_BP_DIR_MASK];
}

void bhv_ttc_cog_update(void)
{
    switch (gTTCSpeedSetting)
    {
    case TTC_SPEED_SLOW:
    case TTC_SPEED_FAST:
        o->oTTCCogSpeed = sTTCCogNormalSpeeds[gTTCSpeedSetting];
        break;

    case TTC_SPEED_RANDOM:
        if (approach_f32_2(&o->oTTCCogSpeed, o->oTTCCogTargetSpeed, 50.0f))
        {
            o->oTTCCogTargetSpeed = 200.0f * (RandomU16() % 7) * RandomSign();
        }

    case TTC_SPEED_STOPPED:
        break;
    }

    o->oAngleVelYaw = (s32)(o->oTTCCogSpeed * o->oTTCCogDir);
    o->oFaceAngleYaw += o->oAngleVelYaw;
}
