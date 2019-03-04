// water_splash.c.inc

void BehWaterSplashLoop(void)
{
    s32 i;
    if(o->oTimer == 0)
        o->oPosY = find_water_level(o->oPosX,o->oPosZ);
    if(o->oPosY > -10000.0f)
        for(i=0;i<3;i++)
            func_8029E388(o,&D_8032FDAC);
}

void BehWaterDropsLoop(void)
{
    UNUSED s32 unused;
    f32 sp20 = find_water_level(o->oPosX,o->oPosZ);
    if(o->oTimer == 0)
    {
        if(obj_has_model(185))
            o->header.gfx.node.flags &= ~4;
        else
            o->header.gfx.node.flags |= 4;
        o->oFaceAngleYaw = RandomU16();
    }
    o->oVelY -= 4.0f;
    o->oPosY += o->oVelY;
    if(o->oVelY < 0.0f)
    {
        if(sp20 > o->oPosY)
        {
            try_to_spawn_object(0,1.0f,o,165,beh_water_surface_white_wave);
            mark_object_for_deletion(o);
        }
        else if(o->oTimer > 20)
            mark_object_for_deletion(o);
    }
    if(sp20 < -10000.0f)
        mark_object_for_deletion(o);
}

void BehSurfaceWavesLoop(void)
{
    copy_object_pos(o,gMarioObject);
    o->oPosY = gMarioStates->waterLevel + 5;
    if(!(gMarioObject->oMarioParticleFlags & 0x80))
    {
        gMarioObject->oUnkE0 &= 0xFF7F;
        o->activeFlags = 0;
    }
}

void BehWaterSurfaceWhiteWaveInit(void)
{
    obj_scale(RandomFloat()+1.5);
}

void BehObjectBubbleRipplesInit(void)
{
    f32 sp1C = find_water_level(o->oPosX,o->oPosZ);
    scale_object_xyz(o,0.5,1.0f,0.5f);
    o->oPosY = sp1C + 5.0f;
}

void BehSurfaceWaveShrinkingInit(void)
{
    UNUSED struct Object* sp1C;
    if((RandomU16() & 0xFF) <= 0) // weird
    {
        sp1C = func_8029E388(o,&D_8032FDF4);
        func_8029EE20(sp1C,blue_fish_seg3_anims_0301C2B0,0);
    }
}

void BehWaveTrailLoop(void)
{
    f32 sp1C = find_water_level(o->oPosX,o->oPosZ);
    if(o->oTimer == 0)
        if(gGlobalTimer & 1)
            mark_object_for_deletion(o);
    o->oPosY = sp1C + 5.0f;
    if(o->oTimer == 0)
        o->oWaveTrailUnkF8 = o->header.gfx.scale[0];
    if(o->oAnimState > 3)
    {
        o->oWaveTrailUnkF8 = o->oWaveTrailUnkF8 - 0.1;
        if(o->oWaveTrailUnkF8 < 0.0f)
            o->oWaveTrailUnkF8 = 0.0f;
        o->header.gfx.scale[0] = o->oWaveTrailUnkF8;
        o->header.gfx.scale[2] = o->oWaveTrailUnkF8;
    }
}
