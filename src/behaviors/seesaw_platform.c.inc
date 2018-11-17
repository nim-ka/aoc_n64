
void bhv_seesaw_platform_init(void)
{
    o->collisionData = segmented_to_virtual(D_803318F0[o->oBehParams2ndByte]);
    if (o->oBehParams2ndByte == 2)
    {
        o->oCollisionDistance = 2000.0f;
    }
}

void bhv_seesaw_platform_update(void)
{
    UNUSED s32 startPitch = o->oFaceAnglePitch;
    o->oFaceAnglePitch += (s32)o->oSeesawPlatformPitchVel;

    if (absf(o->oSeesawPlatformPitchVel) > 10.0f)
    {
        PlaySound(0x400B0001);
    }

    if (gMarioObject->platform == o)
    {
        f32 rotation = o->oDistanceToMario * coss(o->oAngleToMario - o->oMoveAngleYaw);
        UNUSED s32 unused;

        if (o->oSeesawPlatformPitchVel * rotation < 0)
        {
            rotation *= 0.04f;
        }
        else
        {
            rotation *= 0.02f;
        }

        o->oSeesawPlatformPitchVel += rotation;
        cap_f32(&o->oSeesawPlatformPitchVel, -50.0f, 50.0f);
    }
    else
    {
        func_802F9B68(&o->oFaceAnglePitch, &o->oSeesawPlatformPitchVel, 0.0f, 6.0f, 3.0f, 3.0f);
    }
}
