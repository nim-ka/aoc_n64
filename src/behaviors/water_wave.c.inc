// water_wave.c.inc

void BehObjectWaterWaveInit(void)
{
    o->oPosY = find_water_level(o->oPosX, o->oPosZ);
}

void BehObjectWaterWaveLoop(void)
{
    s32 globalTimer = gGlobalTimer;
    if ((globalTimer % 16) == 0) o->activeFlags = 0;
}
