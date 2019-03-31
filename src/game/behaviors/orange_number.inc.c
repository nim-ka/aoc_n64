// orange_number.c.inc

void BehOrangeNumberInit(void) {
    o->oAnimState = o->oBehParams2ndByte;
    o->oVelY = 26.0f;
}

void BehOrangeNumberLoop(void) {
    struct Object *sp1C;
    o->oPosY += o->oVelY;
    o->oVelY -= 2.0f;
    if (o->oVelY < -21.0f)
        o->oVelY = 14.0;

    if (o->oTimer == 35) {
        sp1C = spawn_object(o, 149, beh_golden_coin_sparkles);
        sp1C->oPosY -= 30.f;
        o->activeFlags = 0;
    }
}
