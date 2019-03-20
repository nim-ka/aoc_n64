// red_coin.c.inc

void BehRedCoinInit(void) {
    struct Surface *sp24;
    UNUSED f32 sp20 = find_floor(o->oPosX, o->oPosY, o->oPosZ, &sp24);
    struct Object *sp1C;

    sp1C = obj_nearest_object_with_behavior(beh_hidden_red_coin_star);
    if (sp1C != NULL) 
        o->parentObj = sp1C;
    else {
        sp1C = obj_nearest_object_with_behavior(beh_bowser_course_red_coin_star);
        if (sp1C != NULL) 
            o->parentObj = sp1C;
        else
            o->parentObj = NULL;
    }

    set_object_hitbox(o, &sRedCoinHitbox);
}

void BehRedCoinLoop(void) {
    if (o->oInteractStatus & 0x8000) {
        if (o->parentObj != NULL) {
            o->parentObj->oHiddenRedCoinStarCoinsCollected++;
#ifdef VERSION_JP
            create_sound_spawner(0x30689081);
#endif
            if (o->parentObj->oHiddenRedCoinStarCoinsCollected != 8) {
                SpawnOrangeNumber(o->parentObj->oHiddenRedCoinStarCoinsCollected, 0, 0, 0);
            }

#ifdef VERSION_US
            SetSound(0x78289081 + (((u8)o->parentObj->oHiddenRedCoinStarCoinsCollected - 1) << 16), D_803320E0);
#endif
        }

        CoinCollected();
        o->oInteractStatus = 0;
    }
}
