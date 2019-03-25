// express_elevator.c.inc

void BehWdwExpressElevatorLoop(void)
{
    o->oVelY = 0.0f;
    if(o->oAction == 0)
    {
        if(obj_is_mario_on_platform())
            o->oAction++;
    }
    else if(o->oAction == 1)
    {
        o->oVelY = -20.0f;
        o->oPosY += o->oVelY;
        PlaySound(0x400D0001);
        if(o->oTimer > 132)
            o->oAction++;
    }
    else if(o->oAction == 2)
    {
        if(o->oTimer > 110)
            o->oAction++;
    }
    else if(o->oAction == 3)
    {
        o->oVelY = 10.0f;
        o->oPosY += o->oVelY;
        PlaySound(0x400D0001);
        if(o->oPosY >= o->oHomeY)
        {
            o->oPosY = o->oHomeY;
            o->oAction++;
        }
    }
    else if(!obj_is_mario_on_platform())
        o->oAction = 0;
}