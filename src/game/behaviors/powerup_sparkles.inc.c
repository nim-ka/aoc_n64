// powerup_sparkles.c.inc

void BehPowerupSparklesLoop(void)
{
    struct Object* sp24 = try_to_spawn_object(0,1.0f,o,MODEL_SPARKLES_ANIMATION,beh_powerup_sparkles1);
    if(sp24 != NULL)
    {
        translate_object_xyz_random(sp24,90.0f);
        scale_object_random(sp24,1.0f,0.0f);
    }
    if(o->oTimer > 1)
        mark_object_for_deletion(o);
}
