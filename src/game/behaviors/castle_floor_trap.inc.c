// castle_floor_trap.c.inc

void BehFloorTrapInCastleLoop(void)
{
    if(gMarioObject->platform == o)
        o->parentObj->oInteractStatus |= 0x100000;
    o->oFaceAngleRoll = o->parentObj->oFaceAngleRoll;
}

void BehCastleFloorTrapInit(void)
{
    struct Object* sp2C;
    sp2C = spawn_object_relative(0,-358,0,0,o,MODEL_CASTLE_BOWSER_TRAP,beh_floor_trap_in_castle);
    sp2C = spawn_object_relative(0, 358,0,0,o,MODEL_CASTLE_BOWSER_TRAP,beh_floor_trap_in_castle);
    sp2C->oMoveAngleYaw += 0x8000;
}

void func_802C567C(void)
{
    if(gMarioStates->action == ACT_SPECIAL_EXIT_AIRBORNE || gMarioStates->action == ACT_SPECIAL_DEATH_EXIT)
        o->oAction = 4;
    else
    {
    o->oAngleVelRoll = 0x400;
    if(o->oInteractStatus & 0x100000)
        o->oAction = 1;
    }
}

void func_802C5700(void)
{
    if(o->oTimer == 0)
        PlaySound2(SOUND_GENERAL_UNUSED);
    o->oAngleVelRoll -= 0x100;
    o->oFaceAngleRoll += o->oAngleVelRoll;
    if(o->oFaceAngleRoll < -0x4000)
    {
        o->oFaceAngleRoll = -0x4000;
        o->oAction = 2;
    }
}

void func_802C57A4(void)
{
    if(o->oDistanceToMario > 1000.0f)
        o->oAction = 3;
}

void func_802C57E8(void)
{
    o->oFaceAngleRoll += 0x400;
    if(o->oFaceAngleRoll > 0)
    {
        o->oFaceAngleRoll = 0;
        o->oAction = 0;
        o->oInteractStatus &= 0xFFEFFFFF;
    }
}

void func_802C5854(void)
{
    o->oFaceAngleRoll = -0x3C00;
}

void BehCastleFloorTrapLoop(void)
{
    UNUSED s32 unused[3];
    switch(o->oAction)
    {
    case 0: func_802C567C(); break;
    case 1: func_802C5700(); break;
    case 2: func_802C57A4(); break;
    case 3: func_802C57E8(); break;
    case 4: func_802C5854(); break;
    }
}
