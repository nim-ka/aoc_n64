// corkbox.c.inc
// TODO: This split seems weird. Investigate further?

void BehBobombBullyDeathSmokeInit(void)
{
    o->oPosY -= 300.0f;
    
    obj_scale(10.0f);
}

void BehBobombExplosionBubbleInit(void)
{
    scale_object_xyz(o, 2.0f, 2.0f, 1.0f);
    
    o->oBobombExpBubGfxExpRateX = (s32)(RandomFloat() * 2048.0f) + 0x800;
    o->oBobombExpBubGfxExpRateY = (s32)(RandomFloat() * 2048.0f) + 0x800;
    o->oTimer = RandomFloat() * 10.0f;
    o->oVelY = (s32)(RandomFloat() * 4.0f) + 4;
}

void BehBobombExplosionBubbleLoop(void)
{
    f32 waterY = gMarioStates[0].waterLevel;
    
    o->header.gfx.scale[0] = sins(o->oBobombExpBubGfxScaleFacX) * 0.5 + 2.0;
    o->oBobombExpBubGfxScaleFacX += o->oBobombExpBubGfxExpRateX;
    
    o->header.gfx.scale[1] = sins(o->oBobombExpBubGfxScaleFacY) * 0.5 + 2.0;
    o->oBobombExpBubGfxScaleFacY += o->oBobombExpBubGfxExpRateY;
    
    if (o->oPosY > waterY)
    {
        o->activeFlags = 0;
        o->oPosY += 5.0f;
        spawn_object(o, 165, beh_water_surface_white_wave_2);
    }
    
    if (o->oTimer >= 61) o->activeFlags = 0;
    
    o->oPosY += o->oVelY;
    o->oTimer++;
}

void BehBobombCorkBoxRespawnerLoop(void)
{
    struct Object *sp1c;
    
    if (!IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, o->oBBCBRespawnerMinSpawnDist))
    {
        sp1c = spawn_object(o, o->oBreakableBoxBackupUnkF4, o->oBBCBRespawnerBehaviorToSpawn);
        sp1c->oBehParams = o->oBehParams;
        o->activeFlags = 0;
    }
}

//sp38 = arg0
//sp3c = behToSpawn
//sp40 = minSpawnDist

void RespawnBobombOrCorkbox(s32 arg0, void *behToSpawn, s32 minSpawnDist)
{
    struct Object *respawner = spawn_object_abs_with_rot(o, 0, 0, beh_bobomb_cork_box_respawner, o->oHomeX, o->oHomeY, o->oHomeZ, 0, 0, 0);
    respawner->oBehParams = o->oBehParams;
    respawner->oBreakableBoxBackupUnkF4 = arg0;
    respawner->oBBCBRespawnerMinSpawnDist = minSpawnDist;
    respawner->oBBCBRespawnerBehaviorToSpawn = behToSpawn;
}
