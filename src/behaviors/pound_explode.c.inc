// pound_explode.c.inc

void BehPoundExplodesLoop(void)
{
    obj_scale(1.02f);
    if(o->oAction == 0)
    {
        if(obj_is_mario_ground_pounding_platform())
        {
            func_802A3004();
            func_802AD82C(20,56,3.0f,0);
            o->oAction++;
        }
    }
    else if(o->oTimer > 7)
        mark_object_for_deletion(o);
    load_object_collision_model();
}
