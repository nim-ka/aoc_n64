// ground_particles.c.inc

void BehPoundWhitePuffsInit(void)
{
    func_802ADBBC(0x8000);
    func_802ADA94();
}

void func_802ADA94(void)
{
    obj_spawn_particles(&D_8032F3CC);
}

void BehUnused0E40Init(void)
{
    func_802ADBBC(0x4000);
    obj_spawn_particles(&D_8032F3E0);
}

void Unknown802ADAF4(void)
{
    struct Object* smoke = spawn_object_with_scale(o,MODEL_SMOKE,beh_white_puff_smoke2,1.0f);
    smoke->oForwardVel = D_8032F3F4[0];
    smoke->oVelY = D_8032F3F4[1];
    smoke->oGravity = D_8032F3F4[2];
    translate_object_xyz_random(smoke,D_8032F3F4[3]);
}

//TODO Fix name
void func_802ADBBC(u32 flags)
{
    o->parentObj->oActiveParticleFlags &= flags^-1; // Clear the flags given (could just be ~flags)
}

void BehGroundSnowInit(void)
{
    func_802ADBBC(1<<16);
    obj_spawn_particles(&D_8032F3FC);
}
