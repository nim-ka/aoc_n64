// warp.c.inc

void BehWarpLoop(void)
{
    u16 sp6;
    if(o->oTimer == 0)
    {
        sp6 = (o->oBehParams >> 24) & 0xFF;
        if(sp6 == 0)
            o->hitboxRadius = 50.0f;
        else if(sp6 == 0xFF)
            o->hitboxRadius = 10000.0f;
        else
            o->hitboxRadius = sp6 * 10.0;
        o->hitboxHeight = 50.0f;
    }
    o->oInteractStatus = 0;
}

void BehFadingWarpLoop() // identical to the above function
{
    u16 sp6;
    if(o->oTimer == 0)
    {
        sp6 = (o->oBehParams >> 24) & 0xFF;
        if(sp6 == 0)
            o->hitboxRadius = 85.0f;
        else if(sp6 == 0xFF)
            o->hitboxRadius = 10000.0f;
        else
            o->hitboxRadius = sp6 * 10.0;
        o->hitboxHeight = 50.0f;
    }
    o->oInteractStatus = 0;
}