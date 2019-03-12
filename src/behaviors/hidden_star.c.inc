// hidden_star.c.inc

void BehHiddenStarInit(void) {
    s16 sp36;
    struct Object *sp30;

    sp36 = count_objects_with_behavior(beh_hidden_star_trigger);
    if (sp36 == 0) {
        sp30 = spawn_object_abs_with_rot(o, 0, 122, beh_star, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
        sp30->oBehParams = o->oBehParams;
        o->activeFlags = 0;
    }

    o->oHiddenStarSecretsCollected = 5 - sp36;
}

void BehHiddenStarLoop(void) {
    switch(o->oAction) {
        case 0:
            if (o->oHiddenStarSecretsCollected == 5)
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

/* TODO: this is likely not a checkpoint but a Secret */
void BehHiddenStarTriggerLoop(void) {
    struct Object *hiddenStar;
    if (are_objects_collided(o, gMarioObject) == 1) {
        hiddenStar = obj_nearest_object_with_behavior(beh_hidden_star);
        if (hiddenStar != NULL) {
            hiddenStar->oHiddenStarSecretsCollected++;
            if (hiddenStar->oHiddenStarSecretsCollected != 5) {
                SpawnOrangeNumber(hiddenStar->oHiddenStarSecretsCollected, 0, 0, 0);
            }

#ifdef VERSION_JP
            SetSound(0x701EFF81, D_803320E0);
#else
            SetSound(0x70302081 + (((u8)hiddenStar->oHiddenStarSecretsCollected - 1) << 16), D_803320E0);
#endif
        }

        o->activeFlags = 0;
    }
}

void BehBowserCourseRedCoinStarLoop(void) {
    D_8036008E = o->oBowserCourseRedCoinStarCoinsCollected;
    switch(o->oAction) {
        case 0:
            if (o->oBowserCourseRedCoinStarCoinsCollected == 8)
                o->oAction = 1;
            break;

        case 1:
            if (o->oTimer > 2) {
                func_802F1BD4(o->oPosX, o->oPosY, o->oPosZ);
                func_802A3004();
                o->activeFlags = 0;
            }
            break;
    }
}
