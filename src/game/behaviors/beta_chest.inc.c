// beta_chest.c.inc

void BehBetaChestInit(void)
{
    obj_set_model(MODEL_TREASURE_CHEST_BASE);
    o->oMoveAngleYaw = RandomU16(); // Pointless
    o->oMoveAngleYaw = 0;
    spawn_object_relative(0,0,97,-77,o,MODEL_TREASURE_CHEST_LID,beh_beta_chest_upper);
}

void BehBetaChestLoop(void)
{
    obj_push_mario_away_from_cylinder(200.0f,200.0f);
}

void BehBetaChestUpperLoop(void)
{
    switch(o->oAction)
    {
    case 0:
        if(dist_between_objects(o->parentObj,gMarioObject) < 300.0f)
            o->oAction++;
        break;
    case 1:
        if(o->oTimer == 0)
        {
            spawn_object_relative(0,0,-80,120,o,MODEL_BUBBLE,beh_water_air_bubble);
            SetSound(SOUND_GENERAL_CLAMSHELL1,&o->header.gfx.unk54);
        }
        o->oFaceAnglePitch -= 0x400;
        if(o->oFaceAnglePitch < -0x4000)
            o->oAction++;
    case 2:
        break;
    }
}
