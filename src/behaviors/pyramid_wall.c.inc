// pyramid_wall.c.inc

void BehSSLMovingPyramidWallInit(void) {

    switch (o->oBehParams2ndByte) {
        case 0:
            break;

        case 1:
            o->oPosY -= 256.0f;
            o->oTimer += 50;
            break;

        case 2:
            o->oPosY -= 512.0f;
            o->oAction = 1;
            break;
    }
}

void BehSSLMovingPyramidWallLoop(void) {
    switch (o->oAction) {
        case 0:
            o->oVelY = -5.12f;
            if (o->oTimer == 100)
                o->oAction = 1;
            break;

        case 1:
            o->oVelY = 5.12f;
            if (o->oTimer == 100)
                o->oAction = 0;
            break;
    }

    o->oPosY += o->oVelY;
}
