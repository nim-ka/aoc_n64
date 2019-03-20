// breakable_box.c.inc

void BehBreakableBoxSmallInit(void) {
    o->oGravity = 2.5f;
    o->oFriction = 0.99f;
    o->oBuoyancy = 1.4f;
    obj_scale(0.4f);
    set_object_hitbox(o, &sBreakableBoxSmallHitbox);
    o->oAnimState = 1;
    o->activeFlags |= 0x200;
}

void func_802F4CE8(void) {
    struct Object *sp24 = spawn_object(o, 150, beh_smoke);
    sp24->oPosX += (s32)(RandomFloat() * 80.0f) - 40;
    sp24->oPosZ += (s32)(RandomFloat() * 80.0f) - 40;
}

void func_802F4DB4(void) {
    s16 sp1E = ObjectStep();

    attack_collided_non_mario_object(o);
    if (sp1E == 1)
        PlaySound2(0x32240081);
    if (sp1E & 1) {
        if (o->oForwardVel > 20.0f) {
            PlaySound2(0x40130001);
            func_802F4CE8();
        }
    }

    if (sp1E & 2) {
        func_802A3004();
        func_802AD82C(20, 138, 0.7f, 3);
        ObjSpawnYellowCoins(o, 3);
        create_sound_spawner(0x3041C081);
        o->activeFlags = 0;
    }
    
    ObjCheckFloorDeath(sp1E, D_803600E0);
}

void func_802F4EB8(void) {
    o->oUnknownUnkFC_S32++;
    if (o->oUnknownUnkFC_S32 > 810) {
        if (o->oUnknownUnkFC_S32 & 1)
            o->header.gfx.node.flags |= 0x10;
        else
            o->header.gfx.node.flags &= ~0x10;
    }

    if (o->oUnknownUnkFC_S32 > 900) {
        RespawnBobombOrCorkbox(130, beh_breakable_box_small, 3000);
        o->activeFlags = 0;
    }
}

void func_802F4F84(void) {
    switch(o->oAction) {
        case 0: 
            func_802F4DB4();
            break;

        case 100:
            ObjLavaDeath();
            break;

        case 101:
            o->activeFlags = 0;
            RespawnBobombOrCorkbox(130, beh_breakable_box_small, 3000);
            break;
    }

    if (o->oUnknownUnkF4_S32 == 1)
        func_802F4EB8();
}

void func_802F5048(void) {
    obj_become_tangible();
    obj_enable_rendering();
    obj_get_dropped();
    o->header.gfx.node.flags &= ~0x10;
    o->oHeldState = 0;
    o->oUnknownUnkF4_S32 = 1;
    o->oUnknownUnkFC_S32 = 0;
}

void func_802F50C0(void) {
    obj_become_tangible();
    obj_enable_rendering_2();
    obj_enable_rendering();
    o->header.gfx.node.flags &= ~0x10;
    o->oHeldState = 0;
    o->oFlags &= ~0x08;
    o->oForwardVel = 40.0f;
    o->oVelY = 20.0f;
    o->oUnknownUnkF4_S32 = 1;
    o->oUnknownUnkFC_S32 = 0;
    o->activeFlags &= ~0x200;
}

void BehBreakableBoxSmallLoop(void) {
    switch (o->oHeldState) {
        case 0:
            func_802F4F84();
            break;

        case 1:
            obj_disable_rendering();
            obj_become_intangible();
            break;

        case 2:
            func_802F50C0();
            break;

        case 3:
            func_802F5048();
            break;
    }

    o->oInteractStatus = 0;
}
