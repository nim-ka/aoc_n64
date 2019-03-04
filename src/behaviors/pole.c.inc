// pole.c.inc

void BehPoleInit(void)
{
    s32 sp04;
    sp04 = o->oBehParams >> 0x10 & 0xFF;
    o->hitboxHeight = (f32)(sp04 * 10);
}

void BehGiantPoleLoop(void)
{
    struct Object* topBall;
    if(o->oTimer == 0)
    {
        topBall = spawn_object(o,85,beh_yellow_ball);
        topBall->oPosY += o->hitboxHeight + 50.0f;
    }
    BehClimbDetectLoop();
}
