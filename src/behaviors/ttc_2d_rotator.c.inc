
void bhv_ttc_2d_rotator_init(void)
{
    o->oTTC2DRotatorTimeUntilIncrement = D_803319D8[o->oBehParams2ndByte][gTTCSpeedSetting];
    o->oTTC2DRotatorIncrement = o->oTTC2DRotatorSpeed = D_803319D4[o->oBehParams2ndByte];
}

void bhv_ttc_2d_rotator_update(void)
{
    s32 startYaw;

    startYaw = o->oFaceAngleYaw;

    if (o->oTTC2DRotatorRandomDirTimer != 0)
    {
        o->oTTC2DRotatorRandomDirTimer -= 1;
    }

    if (o->oTTC2DRotatorTimeUntilIncrement != 0 && face_yaw_approach(o->oTTC2DRotatorTargetYaw, 200))
    {
        if (o->oTimer > o->oTTC2DRotatorTimeUntilIncrement)
        {
            o->oTTC2DRotatorTargetYaw += o->oTTC2DRotatorIncrement;
            o->oTimer = 0;

            if (gTTCSpeedSetting == TTC_SPEED_RANDOM)
            {
                if (o->oTTC2DRotatorRandomDirTimer == 0)
                {
                    if (RandomU16() & 0x3)
                    {
                        o->oTTC2DRotatorIncrement = o->oTTC2DRotatorSpeed;
                        o->oTTC2DRotatorRandomDirTimer = random_mod_offset(90, 60, 4);
                    }
                    else
                    {
                        o->oTTC2DRotatorIncrement = -o->oTTC2DRotatorSpeed;
                        o->oTTC2DRotatorRandomDirTimer = random_mod_offset(30, 30, 3);
                    }
                }

                o->oTTC2DRotatorTimeUntilIncrement = random_mod_offset(10, 20, 3);
            }
        }
    }

    o->oAngleVelYaw = o->oFaceAngleYaw - startYaw;
    if (o->oBehParams2ndByte == 0)
    {
        load_object_collision_model();
    }
}
