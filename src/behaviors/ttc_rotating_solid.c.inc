
void bhv_ttc_rotating_solid_init(void)
{
    o->collisionData = segmented_to_virtual(sTTCRotatingSolidCollisionModels[o->oBehParams2ndByte]);
    o->oTTCRotatingSolidNumSides = o->oBehParams2ndByte == TTC_ROTATING_SOLID_BP_CUBE ? 4 : 3;
    o->oTTCRotatingSolidTimeUntilRotation = sTTCRotatingSolidRotationTimes[gTTCSpeedSetting];
}

void bhv_ttc_rotating_solid_update(void)
{
    s32 targetRoll;
    s32 startRoll;

    if (gTTCSpeedSetting != TTC_SPEED_STOPPED && o->oTimer > o->oTTCRotatingSolidTimeUntilRotation)
    {
        if (o->oTTCRotatingSolidSoundTimer != 0)
        {
            if (--o->oTTCRotatingSolidSoundTimer == 0)
            {
                PlaySound2(0x80590081);
            }
        }
        else if (o->oTTCRotatingSolidVelY > 0.0f && o->oPosY >= o->oHomeY)
        {
            targetRoll = (s32)((f32)o->oTTCRotatingSolidPhase / o->oTTCRotatingSolidNumSides * 0x10000);
            startRoll = o->oFaceAngleRoll;

            obj_face_roll_approach(targetRoll, 1200);

            o->oAngleVelRoll = o->oFaceAngleRoll - startRoll;
            if (o->oAngleVelRoll == 0)
            {
                PlaySound2(0x80400081);

                o->oTTCRotatingSolidPhase = (o->oTTCRotatingSolidPhase + 1) % o->oTTCRotatingSolidNumSides;

                o->oTimer = 0;
                if (gTTCSpeedSetting == TTC_SPEED_RANDOM)
                {
                    o->oTTCRotatingSolidTimeUntilRotation = random_mod_offset(5, 20, 7);
                }
            }
        }
        else
        {
            o->oTTCRotatingSolidVelY += 0.5f;
            if ((o->oPosY += o->oTTCRotatingSolidVelY) >= o->oHomeY)
            {
                o->oPosY = o->oHomeY;
                o->oTTCRotatingSolidSoundTimer = 6;
            }
        }
    }
    else
    {
        o->oTTCRotatingSolidVelY = -5.0f;
    }
}
