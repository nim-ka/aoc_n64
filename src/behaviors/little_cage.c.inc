// little_cage.c.inc

void BehLittleCage2Loop(void)
{
    switch(o->oAction)
    {
    case 0:
        if(o->oTimer == 0)
            if(func_802A377C(1) & save_file_get_star_flags(gCurrSaveFileNum-1,gCurrCourseNum-1))
                obj_set_model(121);
        copy_object_pos(o,o->parentObj);
        copy_object_behavior_params(o,o->parentObj);
        if(o->parentObj->oAction == 3)
            o->oAction++;
        break;
    case 1:
        mark_object_for_deletion(o);
        func_802A3004();
        func_802AD82C(20,138,0.7,3);
        CreateStar(2500.0f,-1200.0f,1300.0f);
        break;
    }
    o->oFaceAngleYaw += 0x400;
}

void ActionLittleCage0(void)
{
    if(o->oUnk88 != 0)
        o->oAction = 1;
    load_object_collision_model();
}

void ActionLittleCage1(void)
{
    if(o->oUnk88 != 1)
        o->oAction = 2;
    o->oMoveAngleYaw += 0x800;
    load_object_collision_model();
}

void ActionLittleCage2(void)
{
    obj_update_floor_and_walls();
    obj_move_standard(78);
    if(o->oMoveFlags & (8 | 1))
        o->oAction = 3;
}

void ActionLittleCage3(void)
{
    obj_hide();
}

void (*TableLittleCageActions[])(void) = {ActionLittleCage0,ActionLittleCage1,ActionLittleCage2,ActionLittleCage3};

f32 D_8032F420[] = {1.9f,2.4f,4.0f,4.8f};

struct ObjectHitbox D_8032F430 = {0x8000,0,2,1,3,90,80,80,70};

struct ObjectHitbox D_8032F440 = {0,0,0,1,0,220,300,220,300};

struct ObjectHitbox D_8032F450 = {0x200,20,0,1,0,150,200,150,200};

s16 D_8032F460[][2] = {{30,0},{42,1},{52,0},{64,1},{74,0},{86,1},{96,0},{108,1},{118,0},{-1,0}};

void BehLittleCageLoop(void)
{
    obj_call_action_function(TableLittleCageActions);
}
