// mushroom_1up.c.inc

void Beh1UpInteract(void) {
    UNUSED s32 sp1C;

    if (are_objects_collided(o, gMarioObject) == 1) {
        SetSound(SOUND_GENERAL_1UP, D_803320E0);
        gMarioState->numLives++;
        o->activeFlags = 0;
    }
}

void Beh1UpCommonInit(void) {
    o->oMoveAnglePitch = -0x4000;
    o->oGravity = 3.0f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 1.0f;
}

void Beh1UpInit(void) {
    Beh1UpCommonInit();
    if (o->oBehParams2ndByte == 1) {
        if ((save_file_get_flags() & 0x50) == 0)
            o->activeFlags = 0;
    } 
    else if (o->oBehParams2ndByte == 2) {
        if ((save_file_get_flags() & 0xa0) == 0)
            o->activeFlags = 0;
    }
}

void func_802F2D40(void) {
    if (o->oTimer < 5) {
        o->oVelY = 40.0f;
    }
    else {
        o->oAngleVelPitch = -0x1000;
        o->oMoveAnglePitch += o->oAngleVelPitch;
        o->oVelY = coss(o->oMoveAnglePitch) * 30.0f + 2.0f;
        o->oForwardVel = -sins(o->oMoveAnglePitch) * 30.0f;
    }
}

void func_802F2E18(void) {
    f32 sp34 = gMarioObject->header.gfx.pos[0] - o->oPosX;
    f32 sp30 = gMarioObject->header.gfx.pos[1] + 120.0f - o->oPosY;
    f32 sp2C = gMarioObject->header.gfx.pos[2] - o->oPosZ;
    s16 sp2A = atan2s(sqrtf(sqr(sp34) + sqr(sp2C)), sp30);

    obj_turn_toward_object(o, gMarioObject, 16, 0x1000);
    o->oMoveAnglePitch = approach_s16_symmetric(o->oMoveAnglePitch, sp2A, 0x1000);
    o->oVelY = sins(o->oMoveAnglePitch) * 30.0f;
    o->oForwardVel = coss(o->oMoveAnglePitch) * 30.0f;
    Beh1UpInteract();
}

void func_802F2F8C(s16 sp1A) {
    o->oForwardVel = 8.0f;
    o->oMoveAngleYaw = o->oAngleToMario + 0x8000;
    Beh1UpInteract();
    if (sp1A & 0x02) 
        o->oAction = 2;

    if (!IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 3000))
        o->oAction = 2;
}

void Beh1UpWalkingLoop(void) {
    ObjectStep();

    switch(o->oAction) {
        case 0:
            if (o->oTimer >= 18) 
                spawn_object(o, 0, beh_powerup_sparkles2);

            if (o->oTimer == 0)
                SetSound(SOUND_CH8_UNK63, D_803320E0);

            func_802F2D40();

            if (o->oTimer == 37) {
                obj_become_tangible();
                o->oAction = 1;
                o->oForwardVel = 2.0f;
            }
            break;

        case 1:
            if (o->oTimer > 300)
                o->oAction = 2;

            Beh1UpInteract();
            break;

        case 2:
            ObjFlickerAndDisappear(o, 30);
            Beh1UpInteract();
            break;
    }

    SetObjectVisibility(o, 3000);
}

void Beh1UpRunningAwayLoop(void) {
    s16 sp26;

    sp26 = ObjectStep();
    switch (o->oAction) {
        case 0:
            if (o->oTimer >= 18) 
                spawn_object(o, 0, beh_powerup_sparkles2);

            if (o->oTimer == 0)
                SetSound(SOUND_CH8_UNK63, D_803320E0);

            func_802F2D40();

            if (o->oTimer == 37) {
                obj_become_tangible();
                o->oAction = 1;
                o->oForwardVel = 8.0f;
            }
            break;

        case 1:
            spawn_object(o, 0, beh_powerup_sparkles2);
            func_802F2F8C(sp26);
            break;

        case 2:
            ObjFlickerAndDisappear(o, 30);
            Beh1UpInteract();
            break;
    }

    SetObjectVisibility(o, 3000);
}

void func_802F3328(void) {
    s16 sp1E;

    sp1E = ObjectStep();
    if (sp1E & 0x01) {
        o->oForwardVel += 25.0f;
        o->oVelY = 0;
    } else {
        o->oForwardVel *= 0.98;
    }

    if (o->oForwardVel > 40.0)
        o->oForwardVel = 40.0f;

    if (!IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 5000)) 
        o->oAction = 2;
}

void Beh1UpSlidingLoop(void) {
    switch (o->oAction) {
        case 0:
            SetObjectVisibility(o, 3000);
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 1000)) 
                o->oAction = 1;
            break;

        case 1:
            func_802F3328();
            break;

        case 2:
            ObjFlickerAndDisappear(o, 30);
            Beh1UpInteract();
            break;
    }

    Beh1UpInteract();
    spawn_object(o, 0, beh_powerup_sparkles2);
}

void Beh1UpLoop(void) {
    Beh1UpInteract();
    SetObjectVisibility(o, 3000);
}

void Beh1UpJumpOnApproachLoop(void) {
    s16 sp26;

    switch (o->oAction) {
        case 0:
            if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 1000)) {
                o->oVelY = 40.0f;
                o->oAction = 1;
            }
            break;

        case 1:
            sp26 = ObjectStep();
            func_802F2F8C(sp26);
            spawn_object(o, 0, beh_powerup_sparkles2);
            break;

        case 2:
            sp26 = ObjectStep();
            Beh1UpInteract();
            ObjFlickerAndDisappear(o, 30);
            break;
    }

    SetObjectVisibility(o, 3000);
}

void Beh1UpHiddenLoop(void) {
    s16 sp26;
    switch (o->oAction) {
        case 0:
            o->header.gfx.node.flags |= 0x10;
            if (o->o1UpHiddenUnkF4 == o->oBehParams2ndByte)  {
                o->oVelY = 40.0f; 
                o->oAction = 3;
                o->header.gfx.node.flags &= ~0x10;
                SetSound(SOUND_CH8_UNK63, D_803320E0);
            }
            break;

        case 1:
            sp26 = ObjectStep();
            func_802F2F8C(sp26);
            spawn_object(o, 0, beh_powerup_sparkles2);
            break;

        case 2:
            sp26 = ObjectStep();
            Beh1UpInteract();
            ObjFlickerAndDisappear(o, 30);
            break;

        case 3:
            sp26 = ObjectStep();
            if (o->oTimer >= 18) 
                spawn_object(o, 0, beh_powerup_sparkles2);

            func_802F2D40();

            if (o->oTimer == 37) {
                obj_become_tangible();
                o->oAction = 1;
                o->oForwardVel = 8.0f;
            }
            break;
    }
}

void Beh1UpHiddenTriggerLoop(void) {
    struct Object *sp1C;
    if (are_objects_collided(o, gMarioObject) == 1) {
        sp1C = obj_nearest_object_with_behavior(beh_hidden_1up);
        if (sp1C != NULL) 
            sp1C->o1UpHiddenUnkF4++;

        o->activeFlags = 0;
    }
}

void Beh1UpHiddenInPoleLoop(void) {
    UNUSED s16 sp26;
    switch (o->oAction) {
        case 0:
            o->header.gfx.node.flags |= 0x10;
            if (o->o1UpHiddenUnkF4 == o->oBehParams2ndByte)  {
                o->oVelY = 40.0f; 
                o->oAction = 3;
                o->header.gfx.node.flags &= ~0x10;
                SetSound(SOUND_CH8_UNK63, D_803320E0);
            }
            break;

        case 1:
            func_802F2E18();
            sp26 = ObjectStep();
            break;

        case 3:
            sp26 = ObjectStep();
            if (o->oTimer >= 18) 
                spawn_object(o, 0, beh_powerup_sparkles2);

            func_802F2D40();

            if (o->oTimer == 37) {
                obj_become_tangible();
                o->oAction = 1;
                o->oForwardVel = 10.0f;
            }
            break;
    }
}

void Beh1UpHiddenInPoleTriggerLoop(void) {
    struct Object *sp1C;

    if (are_objects_collided(o, gMarioObject) == 1) {
        sp1C = obj_nearest_object_with_behavior(beh_hidden_1up_in_pole);
        if (sp1C != NULL) {
            sp1C->o1UpHiddenUnkF4++;;
        }

        o->activeFlags = 0;
    }
}

void Beh1UpHiddenInPoleSpawnerLoop(void) {
    s8 sp2F;

    if (IsPointCloseToMario(o->oPosX, o->oPosY, o->oPosZ, 700)) {
        spawn_object_relative(2, 0, 50, 0, o, 212, beh_hidden_1up_in_pole);
        for (sp2F = 0; sp2F < 2; sp2F++) {
            spawn_object_relative(0, 0, sp2F * -200, 0, o, 0, beh_hidden_1up_in_pole_trigger);
        }

        o->activeFlags = 0;
    }
}
