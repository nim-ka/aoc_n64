// manta_ray.c.inc

void BehMantaRayInit(void) {
    struct Object *sp1C;
    sp1C = spawn_object(o, 0, beh_manta_ray_ring_manager);
    o->parentObj = sp1C;
    set_object_hitbox(o, &sMantaRayHitbox);
    obj_scale(2.5f);
}

void func_802F5E20(void) {
    s16 sp1E;
    s32 sp18;

    sp1E = o->header.gfx.unk38.animFrame;
    gCurrentObject->oUnknownUnkFC_VOIDP = &D_803316A8;
    sp18 = obj_follow_path(sp18);
    o->oUnknownUnkF8_S32 = o->oUnknownUnk10C_S32;
    o->oUnknownUnkF4_S32 = o->oUnknownUnk108_S32;
    o->oForwardVel = 10.0f;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oUnknownUnkF8_S32, 0x80);
    o->oMoveAnglePitch = approach_s16_symmetric(o->oMoveAnglePitch, o->oUnknownUnkF4_S32, 0x80);
    if ((s16) o->oUnknownUnkF8_S32 != (s16)o->oMoveAngleYaw) {
        o->oMoveAngleRoll -= 91;
        if (o->oMoveAngleRoll < -5461.3332)
            o->oMoveAngleRoll = -0x4000 / 3;
    }
    else {
        o->oMoveAngleRoll += 91;
        if (o->oMoveAngleRoll > 5461.3332)
            o->oMoveAngleRoll = 0x4000 / 3;
    }

    func_802A2A38();
    if (sp1E == 0)
        PlaySound2(0x30090081);
}

void func_802F5FD8(void) {
    struct Object *sp1C = o->parentObj;
    struct Object *sp18;

    if (o->oTimer == 300) 
        o->oTimer = 0;

    if (o->oTimer == 0 || o->oTimer == 50 || o->oTimer == 150 || o->oTimer == 200 || o->oTimer == 250) {
        sp18 = spawn_object(o, 104, beh_manta_ray_water_ring);
        sp18->oFaceAngleYaw = o->oMoveAngleYaw;
        sp18->oFaceAnglePitch = o->oMoveAnglePitch + 0x4000;
        sp18->oPosX = o->oPosX + 200.0f * sins(o->oMoveAngleYaw + 0x8000);
        sp18->oPosY = o->oPosY + 10.0f + 200.0f * sins(o->oMoveAnglePitch);
        sp18->oPosZ = o->oPosZ + 200.0f * coss(o->oMoveAngleYaw + 0x8000);
        sp18->oUnknownUnk110_S32 = sp1C->oUnknownUnkF4_S32;

        sp1C->oUnknownUnkF4_S32++;
        if (sp1C->oUnknownUnkF4_S32 > 0x2710)
            sp1C->oUnknownUnkF4_S32 = 0;
    }
}

void BehMantaRayLoop(void) {
    switch (o->oAction) {
        case 0:
            func_802F5E20();
            func_802F5FD8();
            if (o->oUnk1AC_S32 == 5) {
                func_802A3004();
                CreateStar(-3180.0f, -3600.0f, 120.0f);
                o->oAction = 1;
            }
            break;

        case 1:
            func_802F5E20();
            break; 
    }

    if (o->oInteractStatus & 0x8000)
        o->oInteractStatus = 0;
}
