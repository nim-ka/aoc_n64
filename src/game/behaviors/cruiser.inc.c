// cruiser.c.inc

void BehRRCruiserWingInit(void)
{
    o->oRRCruiserWingUnkF4 = o->oFaceAngleYaw;
    o->oRRCruiserWingUnkF8 = o->oFaceAnglePitch;
}

void BehRRCruiserWingLoop(void)
{
    if (o->oBehParams2ndByte == 0)
    {
        o->oFaceAngleYaw = o->oRRCruiserWingUnkF4 + sins(o->oTimer * 0x400) * 8192.0f;
        o->oFaceAnglePitch = o->oRRCruiserWingUnkF8 + coss(o->oTimer * 0x400) * 2048.0f;
    }
    else
    {
        o->oFaceAngleYaw = o->oRRCruiserWingUnkF4 - sins(o->oTimer * 0x400) * 8192.0f;
        o->oFaceAnglePitch = o->oRRCruiserWingUnkF8 + coss(o->oTimer * 0x400) * 2048.0f;
    }
#ifndef VERSION_JP
    if (o->oTimer == 64)
    {
        PlaySound2(SOUND_GENERAL_BOATROCK);
        o->oTimer = 0;
    }
#endif
}
