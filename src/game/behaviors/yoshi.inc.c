// yoshi.c.inc

//Variety of X,Z coordinates that Yoshi's home swaps between
static s16 D_8033171C[] = {
     0,     -5625, 
    -1364,  -5912, 
    -1403,  -4609, 
    -1004,  -5308
};

void BehYoshiInit(void) {
    o->oGravity = 2.0f;
    o->oFriction = 0.9f;
    o->oBuoyancy = 1.3f;
    o->oUnk190 = 0x4000;

    if (save_file_get_total_star_count(gCurrSaveFileNum - 1, 0, 24) < 120 
        || D_80331508 == 1) {
        o->activeFlags = 0;
    }
}

void func_802F7E58(void) {
    UNUSED s16 sp26;
    s16 sp24 = o->header.gfx.unk38.animFrame;

    o->oForwardVel = 10.0f;
    sp26 = ObjectStep();
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oYoshiUnk100, 0x500);
    if (IsPointCloseToObject(o, o->oHomeX, 3174.0f, o->oHomeZ, 200))
        o->oAction = 0;

    SetObjAnimation(1);
    if (sp24 == 0 || sp24 == 15) 
        PlaySound2(SOUND_GENERAL_UNKNOWN5);

    if (o->oInteractStatus == 0x8000)
        o->oAction = 2;

    if (o->oPosY < 2100.0f) {
        RespawnBobombOrCorkbox(85, beh_yoshi, 3000);
        o->activeFlags = 0;
    }
}

void func_802F7FA4(void) {
    s16 sp1E;
    UNUSED s16 sp1C = o->header.gfx.unk38.animFrame;

    if (o->oTimer > 90) {
        sp1E = RandomFloat() * 3.99;
        if (o->oYoshiUnkFC == sp1E) {
            return;
        }
        else {
            o->oYoshiUnkFC = sp1E;
        }

        o->oHomeX = D_8033171C[o->oYoshiUnkFC * 2];
        o->oHomeZ = D_8033171C[o->oYoshiUnkFC * 2 + 1];
        o->oYoshiUnk100 = atan2s(o->oHomeZ - o->oPosZ, o->oHomeX - o->oPosX);
        o->oAction = 1; 
    }

    SetObjAnimation(0);
    if (o->oInteractStatus == 0x8000) 
        o->oAction = 2;

    if (D_8033B1B0->unk1C[1] == 11 || D_8033B1B0->unk1C[1] == 12) {
        o->oAction = 10;
        o->oPosX = -1798.0f;
        o->oPosY = 3174.0f;
        o->oPosZ = -3644.0f;
    }
}

void func_802F818C(void) {
    if ((s16) o->oMoveAngleYaw == (s16)o->oAngleToMario) {
        SetObjAnimation(0);
        if (set_mario_npc_dialogue(1) == 2) {
            o->activeFlags |= 0x20;
            if (func_8028F8E0(162, o, 161)) {
                o->activeFlags &= ~0x20;
                o->oInteractStatus = 0;
                o->oHomeX = D_8033171C[2];
                o->oHomeZ = D_8033171C[3];
                o->oYoshiUnk100 = atan2s(o->oHomeZ - o->oPosZ, o->oHomeX - o->oPosX);
                o->oAction = 5;
            }
        }
    }
    else {
        SetObjAnimation(1);
        func_80321228();
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x500);
    }
}

void func_802F82F8(void) {
    s16 sp26 = o->header.gfx.unk38.animFrame;

    o->oForwardVel = 10.0f;
    ObjectStep();
    SetObjAnimation(1);
    if (o->oTimer == 0)
        func_8028F9E8(173, o);

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oYoshiUnk100, 0x500);
    if (IsPointCloseToObject(o, o->oHomeX, 3174.0f, o->oHomeZ, 200)) {
        SetObjAnimation(2);
        PlaySound2(SOUND_GENERAL_ENEMYALERT1);
        o->oForwardVel = 50.0f;
        o->oVelY = 40.0f;
        o->oMoveAngleYaw = -0x3FFF;
        o->oAction = 4;
    }

    if (sp26 == 0 || sp26 == 15) {
        PlaySound2(SOUND_GENERAL_UNKNOWN5);
    }
}

void func_802F8450(void) {
    func_8029F728();
    func_802E4250(o);
    o->oVelY -= 2.0;
    if (o->oPosY < 2100.0f) {
        set_mario_npc_dialogue(0);
        D_8033B858 = 1;
        D_80331508 = 1;
        o->activeFlags = 0;
    }
}

void func_802F84FC(void) {
    s32 sp1C = gGlobalTimer;
    
    if (gDisplayedLives == 100) {
        SetSound(SOUND_GENERAL_1UP, D_803320E0);
        D_8032CE34.specialTripleJump = 1;
        o->oAction = 3;
        return;
    }

    if ((sp1C & 0x03) == 0) {
        SetSound(SOUND_MENU_YOSHIGAINLIVES, D_803320E0);
        gMarioState->numLives++;
    }
}

void BehYoshiLoop(void) {
    switch (o->oAction) {
        case 0:
            func_802F7FA4();
            break;

        case 1:
            func_802F7E58();
            break;

        case 2:
            func_802F818C();
            break;

        case 3:
            func_802F82F8();
            break;

        case 4: 
            func_802F8450();
            break;

        case 5:
            func_802F84FC();
            break;

        case 10:
            SetObjAnimation(0);
            break;
    }

    ObjRandomBlink(&o->oYoshiUnkF4);
}
