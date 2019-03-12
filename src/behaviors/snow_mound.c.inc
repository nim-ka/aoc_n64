// snow_mound.c.inc

void BehSlidingSnowMoundLoop(void) {
    switch (o->oAction) {
        case 0:
            o->oVelX = -40.0f;
            o->oPosX += o->oVelX;
            if (o->oTimer >= 118)
                o->oAction = 1;

            PlaySound(0x40188001);
            break;

        case 1:
            o->oVelX = -5.0f;
            o->oPosX += o->oVelX;
            o->oVelY = -10.0f;
            o->oPosY += o->oVelY;
            o->oPosZ = o->oHomeZ - 2.0f;
            if (o->oTimer > 50)
                o->activeFlags = 0;
            break;
    }
}

void BehSnowMoundSpawnLoop(void) {
    struct Object *sp1C;

    if (!IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 6000) 
        || o->oPosY + 1000.0f < gMarioObject->header.gfx.pos[1]) 
        return;

    if (o->oTimer == 64 || o->oTimer == 128 || o->oTimer == 192 || o->oTimer == 224 || o->oTimer == 256) 
        sp1C = spawn_object(o, 54, beh_sliding_snow_mound);

    if (o->oTimer == 256) {
        sp1C->header.gfx.scale[0] = 2.0f;
        sp1C->header.gfx.scale[1] = 2.0f;
    }

    if (o->oTimer >= 256)
        o->oTimer = 0;
}