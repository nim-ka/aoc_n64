// coin.c.inc

struct ObjectHitbox sYellowCoinHitbox =
{
    /* interactType: */      INTERACT_COIN,
    /* downOffset: */        0,
    /* damageOrCoinValue: */ 1,
    /* health: */            0,
    /* numLootCoins: */      0,
    /* radius: */            100,
    /* height: */            64,
    /* hurtboxRadius: */     0,
    /* hurtboxHeight: */     0,
};

s16 D_8032F2A4[][2] = {{0,-150},{0,-50},{0,50},{0,150},{-50,100},{-100,50},{50,100},{100,50}};

s32 func_802AAD54(void)
{
    if(o->oInteractStatus & 0x8000 && !(o->oInteractStatus & 0x800000))
    {
        spawn_object(o,149,beh_golden_coin_sparkles);
        mark_object_for_deletion(o);
        return 1;
    }
    o->oInteractStatus = 0;
    return 0;
}

void BehYellowCoinInit(void)
{
    obj_set_behavior(beh_yellow_coin);
    set_object_hitbox(o,&sYellowCoinHitbox);
    bhv_init_room();
    obj_update_floor_height();
    if(500.0f < absf(o->oPosY - o->oFloorHeight))
        obj_set_model(117);
    if(o->oFloorHeight < -10000.0f)
        mark_object_for_deletion(o);
}

void BehYellowCoinLoop(void)
{
    func_802AAD54();
    o->oAnimState++;
}

void BehTempCoinLoop(void)
{
    o->oAnimState++;
    if(obj_wait_then_blink(200,20))
        mark_object_for_deletion(o);
    func_802AAD54();
}

void BehCoinInit(void)
{
    o->oVelY = RandomFloat() * 10.0f + 30 + o->OBJECT_FIELD_F32(0x22);
    o->oForwardVel = RandomFloat() * 10.0f;
    o->oMoveAngleYaw = RandomU16();
    obj_set_behavior(beh_yellow_coin);
    set_object_hitbox(o,&sYellowCoinHitbox);
    obj_become_intangible();
}

void BehCoinLoop(void)
{
    struct Surface* sp1C;
    s16 sp1A;
    obj_update_floor_and_walls();
    obj_if_hit_wall_bounce_away();
    obj_move_standard(-62);
    if((sp1C = o->oFloor) != NULL)
    {
        if(o->oMoveFlags & 2)
            o->oSubAction = 1;
        if(o->oSubAction == 1)
        {
            o->oBounce = 0;
            if(sp1C->normal.y < 0.9)
            {
                sp1A = atan2s(sp1C->normal.z,sp1C->normal.x);
                obj_rotate_yaw_toward(sp1A,0x400);
            }
        }
    }
    if(o->oTimer == 0)
#ifndef VERSION_JP
        PlaySound2(SOUND_GENERAL_COINSPURT_2);
#else
        PlaySound2(SOUND_GENERAL_COINSPURT);
#endif
    if(o->oVelY < 0)
        obj_become_tangible();
    if(o->oMoveFlags & 1)
    {
#ifndef VERSION_JP
        if(o->oMoveFlags & 0x4800)
#else
        if(o->oMoveFlags & 0x800)	
#endif
            mark_object_for_deletion(o);
    }
#ifndef VERSION_JP
    if(o->oMoveFlags & 0x2000) {
	if(o->oUnk1B0 < 5)
            PlaySound2(SOUND_GENERAL_COINDROP);
        o->oUnk1B0++;
    }
#else
    if(o->oMoveFlags & 0x2000)
        PlaySound2(SOUND_GENERAL_COINDROP);
#endif
    if(obj_wait_then_blink(400,20))
        mark_object_for_deletion(o);
    func_802AAD54();
}

void BehCoinFormationSpawnLoop(void)
{
    if(o->oTimer == 0)
    {
        obj_set_behavior(beh_yellow_coin);
        set_object_hitbox(o,&sYellowCoinHitbox);
        bhv_init_room();
        if(o->OBJECT_FIELD_S32(0x1C))
        {
            o->oPosY += 300.0f;
            obj_update_floor_height();
            if(o->oPosY < o->oFloorHeight || o->oFloorHeight < -10000.0f)
                mark_object_for_deletion(o);
            else
                o->oPosY = o->oFloorHeight;
        }
        else
        {
            obj_update_floor_height();
            if(absf(o->oPosY-o->oFloorHeight) > 250.0f)
                obj_set_model(117);
        }
    }
    else
    {
        if(func_802AAD54())
            o->parentObj->OBJECT_FIELD_S32(0x1B) |= func_802A377C(o->oBehParams2ndByte);
        o->oAnimState++;
    }
    if(o->parentObj->oAction == 2)
        mark_object_for_deletion(o);
}

void func_802AB364(s32 sp50,s32 sp54)
{
    struct Object* sp4C;
    Vec3i sp40;
    s32 sp3C = 1;
    s32 sp38 = 1;
    UNUSED s32 unused;
    sp40[2] = 0;
    sp40[0] = (sp40[1] = sp40[2]);
    switch(sp54 & 7)
    {
    case 0:
        sp40[2] = 160*(sp50 - 2);
        if(sp50 > 4)
            sp3C = 0;
        break;
    case 1:
        sp38 = 0;
        sp40[1] = 160*sp50*0.8; // 128 * sp50
        if(sp50 > 4)
            sp3C = 0;
        break;
    case 2:
        sp40[0] = sins(sp50 << 13) * 300.0f;
        sp40[2] = coss(sp50 << 13) * 300.0f;
        break;
    case 3:
        sp38 = 0;
        sp40[0] = coss(sp50 << 13) * 200.0f;
        sp40[1] = sins(sp50 << 13) * 200.0f + 200.0f;
        break;
    case 4:
        sp40[0] = D_8032F2A4[sp50][0];
        sp40[2] = D_8032F2A4[sp50][1];
        break;
    }
    if(sp54 & 0x10)
        sp38 = 0;
    if(sp3C)
    {
        sp4C = spawn_object_relative(sp50,sp40[0],sp40[1],sp40[2],o,116,beh_coin_formation_spawn);
        sp4C->OBJECT_FIELD_S32(0x1C) = sp38;
    }
}

void BehCoinFormationInit(void)
{
    o->OBJECT_FIELD_S32(0x1B) = (o->oBehParams >> 8) & 0xFF;
}

void BehCoinFormationLoop(void)
{
    s32 bitIndex;
    switch(o->oAction)
    {
    case 0:
        if(o->oDistanceToMario < 2000.0f)
        {
            for(bitIndex=0;bitIndex<8;bitIndex++)
            {
                if(!(o->OBJECT_FIELD_S32(0x1B) & (1 << bitIndex)))
                    func_802AB364(bitIndex,o->oBehParams2ndByte);
            }
            o->oAction++;
        }
        break;
    case 1:
        if(o->oDistanceToMario > 2100.0f)
            o->oAction++;
        break;
    case 2:
        o->oAction = 0;
        break;
    }
    func_8029C6D8(o,o->OBJECT_FIELD_S32(0x1B) & 0xFF); // Casting to u8 doesn't seem to match
}

void ActionCoinInsideBoo1(void)
{
    obj_update_floor_and_walls();
    obj_if_hit_wall_bounce_away();
    if(o->oMoveFlags & 0x2000)
        PlaySound2(SOUND_GENERAL_COINDROP);
    if(o->oTimer > 90 || (o->oMoveFlags & 1))
    {
        set_object_hitbox(o,&sYellowCoinHitbox);
        obj_become_tangible();
        obj_set_behavior(beh_yellow_coin);
    }
    obj_move_standard(-30);
    func_802AAD54();
    if(obj_has_model(118))
        o->oDamageOrCoinValue = 5;
    if(obj_wait_then_blink(400,20))
        mark_object_for_deletion(o);
}

void ActionCoinInsideBoo0(void)
{
    s16 sp26;
    f32 sp20;
    struct Object* parent = o->parentObj;
    obj_become_intangible();
    if(o->oTimer == 0 && gCurrLevelNum == LEVEL_BBH)
    {
        obj_set_model(118);
        obj_scale(0.7);
    }
    copy_object_pos(o,parent);
    if(parent->oUnk88 == 1)
    {
        o->oAction = 1;
        sp26 = gMarioObject->oMoveAngleYaw;
        sp20 = 3.0f;
        o->oVelX = sins(sp26) * sp20;
        o->oVelZ = coss(sp26) * sp20;
        o->oVelY = 35.0f;
    }
}

void (*TableCoinInsideBooActions[])(void) = {ActionCoinInsideBoo0,ActionCoinInsideBoo1};

void BehCoinInsideBooLoop(void)
{
    obj_call_action_function(TableCoinInsideBooActions);
}

void BehCoinSparklesLoop(void)
{
    obj_scale(0.6f);
}

void BehGoldenCoinSparklesLoop(void)
{
    struct Object* sp2C;
    UNUSED s32 unused;
    f32 sp24 = 30.0f;
    sp2C = spawn_object(o,149,beh_coin_sparkles);
    sp2C->oPosX += RandomFloat() * sp24 - sp24/2;
    sp2C->oPosZ += RandomFloat() * sp24 - sp24/2;
}
