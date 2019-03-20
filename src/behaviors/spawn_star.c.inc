// spawn_star.c.inc

void BehCollectStarInit(void) {
    s8 sp1F;
    u8 sp1E;

    sp1F = (o->oBehParams >> 24) & 0xFF;
    sp1E = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1);
    if (sp1E & (1 << sp1F)) {
        o->header.gfx.asGraphNode = gLoadedGraphNodes[121];
    } 
    else {
        o->header.gfx.asGraphNode = gLoadedGraphNodes[122];
    }

    set_object_hitbox(o, &sCollectStarHitbox);
}

void BehCollectStarLoop(void) {
    o->oFaceAngleYaw += 0x800;
    
    if (o->oInteractStatus & 0x8000) {
        hide_object(o);
        o->oInteractStatus = 0;
    }

}

void BehStarSpawnInit(void) {
    o->oMoveAngleYaw = atan2s(o->oHomeZ - o->oPosZ, o->oHomeX - o->oPosX);
    o->oStarSpawnDisFromHome = sqrtf(sqr(o->oHomeX - o->oPosX) + sqr(o->oHomeZ - o->oPosZ));
    o->oVelY = (o->oHomeY - o->oPosY) / 30.0f;
    o->oForwardVel = o->oStarSpawnDisFromHome / 30.0f;
    o->oStarSpawnUnkFC = o->oPosY;
    if (o->oBehParams2ndByte == 0 || gCurrCourseNum == 5)
        func_8028F9E8(173, o);
    else 
        func_8028F9E8(176, o);

    set_time_stop_flag(10);
    o->activeFlags |= 0x20;
    obj_become_intangible();
}

void BehStarSpawnLoop(void) {
    switch (o->oAction) {
        case 0:
            o->oFaceAngleYaw += 0x1000;
            if (o->oTimer > 20)
                o->oAction = 1;
            break;

        case 1:
            func_802E4250(o);
            o->oStarSpawnUnkFC += o->oVelY;
            o->oPosY = o->oStarSpawnUnkFC + sins((o->oTimer * 0x8000) / 30) * 400.0f;
            o->oFaceAngleYaw += 0x1000;
            spawn_object(o, 0, beh_powerup_sparkles2);
            PlaySound(0x40140011);
            if (o->oTimer == 30) {
                o->oAction = 2;
                o->oForwardVel = 0;
                func_803212A0(1);
            }
            break;

        case 2:
            if (o->oTimer < 20)
                o->oVelY = 20 - o->oTimer;
            else    
                o->oVelY = -10.0f; 

            spawn_object(o, 0, beh_powerup_sparkles2);
            func_802E4250(o);
            o->oFaceAngleYaw = o->oFaceAngleYaw - o->oTimer * 0x10 + 0x1000;
            PlaySound(0x40140011);

            if (o->oPosY < o->oHomeY) {
                PlaySound2(0x3057FF91);
                obj_become_tangible();
                o->oPosY = o->oHomeY;
                o->oAction = 3;
            }
            break;

        case 3:
            o->oFaceAngleYaw += 0x800;
            if (o->oTimer == 20) {
                D_8033B858 = 1;
                clear_time_stop_flag(10);
                o->activeFlags &= ~0x20;
            }

            if (o->oInteractStatus & 0x8000) {
                hide_object(o);
                o->oInteractStatus = 0;
            }
            break;
    }
}

struct Object *func_802F1A50(struct Object *sp30, f32 sp34, f32 sp38, f32 sp3C) {
    sp30 = spawn_object_abs_with_rot(o, 0, 122, beh_star_spawn_coordinates, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
    sp30->oBehParams = o->oBehParams;
    sp30->oHomeX = sp34;
    sp30->oHomeY = sp38;
    sp30->oHomeZ = sp3C;
    sp30->oFaceAnglePitch = 0;
    sp30->oFaceAngleRoll = 0;
    return sp30;
}

void CreateStar(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = func_802F1A50(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 0;
}

void func_802F1B84(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = func_802F1A50(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 1;
}

void func_802F1BD4(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = func_802F1A50(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 1;
    sp1C->oUnk190 |= 0x400;
}

void BehHiddenRedCoinStarInit(void) {
    s16 sp36;
    struct Object *sp30;

    if (gCurrCourseNum != 3)
        spawn_object(o, 121, bRedCoinStarMarker);

    sp36 = count_objects_with_behavior(beh_red_coin);
    if (sp36 == 0) {
        sp30 = spawn_object_abs_with_rot(o, 0, 122, beh_star, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
        sp30->oBehParams = o->oBehParams;
        o->activeFlags = 0;
    }

    o->oHiddenRedCoinStarCoinsCollected = 8 - sp36;
}

void BehHiddenRedCoinStarLoop(void) {
    D_8036008E = o->oHiddenRedCoinStarCoinsCollected;
    switch (o->oAction) {
        case 0:
            if (o->oHiddenRedCoinStarCoinsCollected == 8) 
                o->oAction = 1;
            break;

        case 1:
            if (o->oTimer > 2) {
                func_802F1B84(o->oPosX, o->oPosY, o->oPosZ);
                func_802A3004();
                o->activeFlags = 0;
            }
            break;
    }
}
