// pendulum.c.inc

void BehOscillatingPendulumInit(void) {
    o->oAngleVelRoll = 0x100;
    bhv_init_room();
}

void BehOscillatingPendulumLoop(void) {
    if (o->oFaceAngleRoll > 0) 
        o->oAngleVelRoll += -0x08;
    else 
        o->oAngleVelRoll += 0x08;

    o->oFaceAngleRoll += o->oAngleVelRoll;
    if (o->oAngleVelRoll == 0x10 || o->oAngleVelRoll == -0x10)
        PlaySound2(0x30170081);
}