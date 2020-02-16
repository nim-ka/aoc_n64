// tower_door.c.inc

void bhv_tower_door_loop(void) {
    if (o->oTimer == 0)
        o->oMoveAngleYaw -= 0x4000;
    if (func_802A9A0C(0)) {
        explode_obj_and_spawn_coins(80.0f, 0);
        create_sound_spawner(SOUND_GENERAL_WALL_EXPLOSION);
    }
}
