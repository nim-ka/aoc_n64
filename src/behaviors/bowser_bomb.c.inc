// bowser_bomb.c.inc

void BehBowserBombLoop(void)
{
    if (are_objects_collided(o, gMarioObject) == 1)
    {
        o->oInteractStatus &= ~0x8000; /* bit 15 */
        spawn_object(o, 205, beh_explosion);
        o->activeFlags = 0;
    }
    
    if (o->oInteractStatus & 0x200000) /* bit 21 */
    {
        spawn_object(o, 103, beh_bowser_bomb_explosion);
        create_sound_spawner(0x312F0081);
        func_8027F440(3, o->oPosX, o->oPosY, o->oPosZ);
        o->activeFlags = 0;
    }
    
    SetObjectVisibility(o, 7000);
}

void BehBowserBombExplosionLoop(void)
{
    struct Object *mineSmoke;
    
    obj_scale((f32)o->oTimer / 14.0f * 9.0 + 1.0);
    if ((o->oTimer % 4 == 0) && (o->oTimer < 20))
    {
        mineSmoke = spawn_object(o, 102, beh_bowser_bomb_smoke);
        mineSmoke->oPosX += RandomFloat() * 600.0f - 400.0f;
        mineSmoke->oPosZ += RandomFloat() * 600.0f - 400.0f;
        mineSmoke->oVelY += RandomFloat() * 10.0f;
    }
    
    if (o->oTimer % 2 == 0) o->oAnimState++;
    if (o->oTimer == 28) o->activeFlags = 0;
}

void BehBowserBombSmokeLoop(void)
{
    obj_scale((f32)o->oTimer / 14.0f * 9.0 + 1.0);
    if (o->oTimer % 2 == 0) o->oAnimState++;
    
    o->oOpacity -= 10;
    if (o->oOpacity < 10) o->oOpacity = 0;
    
    o->oPosY += o->oVelY;
    
    if (o->oTimer == 28) o->activeFlags = 0;
}
