// lll_volcano_flames.c.inc

void bhv_volcano_flames_loop(void) {
    cur_obj_update_floor_height();
    cur_obj_compute_vel_xz();
    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    cur_obj_move_y(-4.0f, -0.7f, 2.0f);
    if (o->oMoveFlags & 0x33)
        obj_mark_for_deletion(o);
}

void func_802BBFDC(void) {
    struct Object *sp1C;
    f32 size;
    sp1C = spawn_object(o, MODEL_RED_FLAME, bhvVolcanoFlames);
    sp1C->oPosY += 550.0f;
    sp1C->oMoveAngleYaw = RandomU16() << 0x10 >> 0x10;
    sp1C->oForwardVel = RandomFloat() * 40.0f + 20.0f;
    sp1C->oVelY = RandomFloat() * 50.0f + 10.0f;
    size = RandomFloat() * 6.0 + 3.0;
    obj_scale_xyz(sp1C, size, size, size);
    if (RandomFloat() < 0.1)
        PlaySound2(SOUND_GENERAL_VOLCANO_EXPLOSION);
}
