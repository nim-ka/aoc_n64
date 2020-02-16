// breakable_box.c.inc

void bhv_breakable_box_loop(void) {
    set_object_hitbox(o, &sBreakableBoxHitbox);
    obj_set_model(MODEL_BREAKABLE_BOX_SMALL);
    if (o->oTimer == 0)
        func_802B0E74();
    if (obj_was_attacked_or_ground_pounded() != 0) {
        explode_obj_and_spawn_coins(46.0f, 1);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
    }
}
