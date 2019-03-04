// breakable_box.c.inc

void BehBreakableBoxLoop(void)
{
    set_object_hitbox(o,&D_8032F450);
    obj_set_model(130);
    if(o->oTimer == 0)
        func_802B0E74();
    if(obj_was_attacked_or_ground_pounded() != 0)
    {
        func_802A3C98(46.0f,1);
        create_sound_spawner(0x3041C081);
    }
}
