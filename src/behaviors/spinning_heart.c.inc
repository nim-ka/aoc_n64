
void bhv_spinning_heart_update(void)
{
    set_object_hitbox(o, &D_80331AE0);
    if (are_objects_collided(o, gMarioObject))
    {
        if (o->oSpinningHeartPlayedSound == 0)
        {
            PlaySound2(0x3064C081);
            o->oSpinningHeartPlayedSound += 1;
        }

        o->oAngleVelYaw = (s32)(200.0f * gMarioStates[0].forwardVel) + 1000;
    }
    else
    {
        o->oSpinningHeartPlayedSound = 0;

        if ((o->oAngleVelYaw -= 50) < 400)
        {
            o->oAngleVelYaw = 400;
            o->oSpinningHeartTotalSpin = 0;
        }
    }

    if ((o->oSpinningHeartTotalSpin += o->oAngleVelYaw) >= 0x10000)
    {
        gMarioStates[0].healCounter += 4;
        o->oSpinningHeartTotalSpin -= 0x10000;
    }

    o->oFaceAngleYaw += o->oAngleVelYaw;
}
