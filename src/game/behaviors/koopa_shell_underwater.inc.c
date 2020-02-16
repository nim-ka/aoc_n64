// koopa_shell_underwater.c.inc

struct ObjectHitbox sKoopaShellUnderwaterHitbox = {
    /* interactType: */ INTERACT_GRABBABLE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 80,
    /* height: */ 50,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

void func_802AA0D4(void) {
    set_object_hitbox(o, &sKoopaShellUnderwaterHitbox);
}

void bhv_koopa_shell_underwater_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            func_802AA0D4();
            break;
        case HELD_HELD:
            unrender_and_reset_obj_state(-1, 0);
            break;
        case HELD_THROWN:
        case HELD_DROPPED:
            mark_object_for_deletion(o);
            spawn_mist_particles();
            break;
    }
    if (o->oInteractStatus & INT_STATUS_STOP_RIDING) {
        mark_object_for_deletion(o);
        spawn_mist_particles();
    }
    o->oInteractStatus = 0;
}
