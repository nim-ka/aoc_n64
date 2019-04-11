// tuxie.c.inc

s32 func_802BE2E8(s16 a0,s16 a1,s32 a2)
{
    f32 sp1C;
    if((sp1C = o->header.gfx.unk38.animAccel/(f32)0x10000) == 0)
        sp1C = 1.0f;
    if(obj_check_anim_frame_in_range(a0,sp1C) || obj_check_anim_frame_in_range(a1,sp1C))
    {
        PlaySound2(a2);
        return 1;
    }
    return 0;
}

void func_802BE3B4(s32 a0)
{
    s32 sp1C;
    if(o->oSoundStateID == 0)
    {
        if(a0 == 0)
            sp1C = SOUND_OBJECT_PENGUINWALKING1;
        else
            sp1C = SOUND_OBJECT_PENGUINWALKING2;
        func_802BE2E8(1,11,sp1C);
    }
}

void ActionTuxiesMother2(void)
{
    f32 sp24;
    UNUSED s32 unused;
    struct Object* sp1C = obj_find_nearest_object_with_behavior(beh_small_penguin,&sp24);
    UNUSED s32 unused2;
    if(obj_find_nearby_held_actor(beh_unused_20E0,1000.0f) != NULL)
    {
        if(o->oSubAction == 0)
        {
            func_8029ED38(0);
            o->oForwardVel = 10.0f;
            if(800.0f < obj_lateral_dist_from_mario_to_home())
                o->oSubAction = 1;
            obj_rotate_yaw_toward(o->oAngleToMario,0x400);
        }
        else
        {
            o->oForwardVel = 0.0f;
            func_8029ED38(3);
            if(obj_lateral_dist_from_mario_to_home() < 700.0f)
                o->oSubAction = 0;
        }
    }
    else
    {
        o->oForwardVel = 0.0f;
        func_8029ED38(3);
    }
    if(sp1C != NULL && sp24 < 300.0f && sp1C->oHeldState != HELD_FREE)
    {
        o->oAction = 1;
        sp1C->oUnk88 = 1;
        o->prevObj = sp1C;
    }
}

void ActionTuxiesMother1(void)
{
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    switch(o->oSubAction)
    {
    case 0:
        func_8029ED38(3);
        if(!obj_is_mario_on_platform())
        {
            sp2C = (o->oBehParams >> 0x10) & 0xFF;
            sp28 = (o->prevObj->oBehParams >> 0x10) & 0xFF;
            if(sp2C == sp28)
                sp24 = 58;
            else
                sp24 = 59;
            if(obj_update_dialogue_unk2(2,1,162,sp24))
            {
                if(sp24 == 58)
                    o->oSubAction = 1;
                else
                    o->oSubAction = 2;
                o->prevObj->oUnk190 |= 0x40;
            }
        }
        else
            func_8029ED38(0);
        break;
    case 1:
        if(o->prevObj->oHeldState == HELD_FREE)
        {
            ((s32*)o->prevObj)[o->oUnk190+34] &= ~0x40; //FIXME: find something more normal?
            set_object_behavior(o->prevObj,beh_unused_20E0);
#ifndef VERSION_JP
            obj_spawn_star_at_y_offset(3167.0f, -4300.0f, 5108.0f, 200.0f);
#else
            CreateStar(3500.0f,-4300.0f,4650.0f);
#endif
            o->oAction = 2;
        }
        break;
    case 2:
        if(o->prevObj->oHeldState == HELD_FREE)
        {
            ((s32*)o->prevObj)[o->oUnk190+34] &= ~0x40;
            set_object_behavior(o->prevObj,beh_penguin_baby);
            o->oAction = 2;
        }
        break;
    }
}

void ActionTuxiesMother0(void)
{
    s32 sp2C;
    f32 sp28;
    struct Object* sp24;
    sp2C = 0;
    sp24 = obj_find_nearest_object_with_behavior(beh_small_penguin,&sp28);
    obj_scale(4.0f);
    func_8029ED38(3);
    if(sp28 < 500.0f)
        sp2C = 1;
    if(sp24 != NULL && sp28 < 300.0f && sp24->oHeldState != HELD_FREE)
    {
        o->oAction = 1;
        sp24->oUnk88 = 1;
        o->prevObj = sp24;
    }
    else
    {
        switch(o->oSubAction)
        {
        case 0:
            if(obj_is_mario_in_range_and_ready_to_speak(300.0f,100.0f))
                if(sp2C == 0)
                    o->oSubAction++;
            break;
        case 1:
            if(obj_update_dialogue_unk2(2,1,162,57))
                o->oSubAction++;
            break;
        case 2:
            if(o->oDistanceToMario > 450.0f)
                o->oSubAction = 0;
            break;
        }
    }
    if(obj_check_anim_frame(1))
        PlaySound2(SOUND_OBJECT_BIGPENGUIN);
}

void (*TableTuxiesMotherActions[])(void) = {ActionTuxiesMother0,ActionTuxiesMother1,ActionTuxiesMother2};

void BehTuxiesMotherLoop(void)
{
    o->activeFlags |= 0x400;
    obj_update_floor_and_walls();
    obj_call_action_function(TableTuxiesMotherActions);
    obj_move_standard(-78);
    func_802BE3B4(1);
    o->oInteractStatus = 0;
}

void func_802BEA58(void)
{
    if(mario_is_dive_sliding())
    {
        o->oSmallPenguinUnk100 = o->oAction;
        o->oAction = 3;
    }
}

void ActionSmallPenguin2(void)
{
    s32 sp1C = 0;
    if(o->oTimer == 0)
        if(obj_dist_to_nearest_object_with_behavior(beh_tuxies_mother) < 1000.0f)
            sp1C = 1;
    func_8029ED38(0);
    o->oForwardVel = o->oSmallPenguinUnk104 + 3.0f;
    obj_rotate_yaw_toward(o->oAngleToMario+0x8000,o->oSmallPenguinUnk110+0x600);
    if(o->oDistanceToMario > o->oSmallPenguinUnk108 + 500.0f)
        o->oAction = 0;
    func_802BEA58();
    if(sp1C)
        o->oAction = 5;
}

void ActionSmallPenguin1(void)
{
    func_8029ED38(0);
    o->oForwardVel = o->oSmallPenguinUnk104 + 3.0f;
    obj_rotate_yaw_toward(o->oAngleToMario,o->oSmallPenguinUnk110+0x600);
    if(o->oDistanceToMario < o->oSmallPenguinUnk108 + 300.0f)
        o->oAction = 0;
    if(o->oDistanceToMario > 1100.0f)
        o->oAction = 0;
    func_802BEA58();
}

void ActionSmallPenguin3(void)
{
    if(o->oTimer > 5)
    {
        if(o->oTimer == 6)
            PlaySound2(SOUND_OBJECT_BABYPENGUINTRICK);
        func_8029ED38(1);
        if(o->oTimer > 25)
            if(!mario_is_dive_sliding())
                o->oAction = 4;
    }
}

void ActionSmallPenguin4(void)
{
    if(o->oTimer > 20)
    {
        o->oForwardVel = 0.0f;
        func_8029ED38(2);
        if(o->oTimer > 40)
            o->oAction = o->oSmallPenguinUnk100;
    }
}

void ActionSmallPenguin0(void)
{
    s32 sp1C;

    sp1C = 0;
    func_8029ED38(3);
    if(o->oTimer == 0)
    {
        o->oSmallPenguinUnk110 = (s32)(RandomFloat() * 0x400);
        o->oSmallPenguinUnk108 = RandomFloat() * 100.0f;
        o->oSmallPenguinUnk104 = RandomFloat();
        o->oForwardVel = 0.0f;
        if(obj_dist_to_nearest_object_with_behavior(beh_tuxies_mother) < 1000.0f)
            sp1C = 1;
    }
    if(o->oDistanceToMario < 1000.0f && o->oSmallPenguinUnk108 + 600.0f < o->oDistanceToMario)
        o->oAction = 1;
    else if(o->oDistanceToMario < o->oSmallPenguinUnk108 + 300.0f)
        o->oAction = 2;
    if(sp1C)
        o->oAction = 5;
    if(obj_mario_far_away())
        obj_set_pos_to_home();
}

void ActionSmallPenguin5(void)
{
    f32 sp24;
    s16 sp22;
    struct Object* sp1C = obj_nearest_object_with_behavior(beh_tuxies_mother);
    if(sp1C != NULL)
    {
        if(o->oDistanceToMario < 1000.0f)
            o->oForwardVel = 2.0f;
        else
            o->oForwardVel = 0.0f;
        sp24 = dist_between_objects(o,sp1C);
        sp22 = angle_to_object(o,sp1C);
        if(sp24 > 200.0f)
            obj_rotate_yaw_toward(sp22,0x400);
        else
            obj_rotate_yaw_toward(sp22+0x8000,0x400);
        func_8029ED38(0);
    }
    func_802BEA58();
}

void (*TableSmallPenguinActions[])(void) = {ActionSmallPenguin0,ActionSmallPenguin1,ActionSmallPenguin2,ActionSmallPenguin3,ActionSmallPenguin4,ActionSmallPenguin5};

void func_802BF048(void)
{
    if(o->oUnk88 != 0)
    {
        o->oAction = 5;
        o->oUnk88 = 0;
    }
    obj_update_floor_and_walls();
    obj_call_action_function(TableSmallPenguinActions);
    obj_move_standard(-78);
    func_802BE3B4(0);
}

void BehSmallPenguinLoop(void)
{
    switch(o->oHeldState)
    {
    case 0:
        func_802BF048();
        break;
    case 1:
        func_8029FA5C(0,0);
        if(obj_has_behavior(beh_penguin_baby))
            set_object_behavior(o,beh_small_penguin);
        copy_object_pos(o,gMarioObject);
        if(gGlobalTimer % 30 == 0)
#ifndef VERSION_JP
            SetSound(SOUND_CH9_UNK45,&gMarioObject->header.gfx.unk54);
#else
            SetSound(SOUND_CH9_UNK45,&o->header.gfx.unk54);
#endif
        break;
    case 2:
        obj_get_thrown_or_placed(0, 0, 0);
        break;
    case 3:
        obj_get_dropped();
        break;
    }
}

s32    GeoSwitchCase802BFBAC(s32 a0,struct GraphNodeObject* a1,UNUSED Mat4 *a2)
{
    struct Object* sp24;
    struct GraphNodeObject* sp20;
    s32 sp1C;
    if(a0 == 1)
    {
        sp24 = (struct Object*)D_8032CFA0;
        sp20 = a1;
        sp20->angle[2] = 0;
        sp1C = gGlobalTimer % 50;
        if(sp1C < 43)
            sp20->angle[2] = 0;
        else if(sp1C < 45)
            sp20->angle[2] = 1;
        else if(sp1C < 47)
            sp20->angle[2] = 2;
        else
            sp20->angle[2] = 1;
        if(segmented_to_virtual(beh_tuxies_mother) == sp24->behavior)
            if(sp24->oForwardVel > 5.0f)
                sp20->angle[2] = 3;
    }
    return 0;
}
