// explosion.c.inc

void BehExplosionInit(void)
{
    create_sound_spawner(SOUND_CH8_UNK2E);
    func_8027F308(1);
    
    o->oOpacity = 255;
}

void BehExplosionLoop(void)
{
    s32 i;
    
    if (o->oTimer == 9)
    {
        if (find_water_level(o->oPosX, o->oPosZ) > o->oPosY)
        {
            for (i = 0; i < 40; i++)
                spawn_object(o, MODEL_SMALL_SNOW_BALL, beh_bobomb_explosion_bubble);
        }
        else spawn_object(o, MODEL_SMOKE, beh_bobomb_bully_death_smoke);
        
        o->activeFlags = 0;
    }
    
    o->oOpacity -= 14;
    
    obj_scale((f32)o->oTimer / 9.0f + 1.0);
}
