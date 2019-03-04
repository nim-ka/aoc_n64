// breakable_wall.c.inc

void BehWFBreakableWallLoop(void)
{
    if(gMarioStates->action == ACT_SHOT_FROM_CANNON)
    {
        obj_become_tangible();
        if(are_objects_collided(o,gMarioObject))
        {
            if(obj_has_behavior(beh_wf_breakable_wall_right))
                func_80321228();
            create_sound_spawner(0x300F0081);
            o->oInteractType = 8;
            o->oDamageOrCoinValue = 1;
            func_802A3C98(80.0f,0);
        }
    }
    else
        obj_become_intangible();
}
