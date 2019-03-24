// bait_coin.c.inc

// TODO: This is not inside cannon. This is the bait coin from moneybag.
// I got baited.
void BehInsideCannonLoop(void)
{
    obj_set_pos_relative(gMarioObject,0,30.0f,300.0f);
    o->hitboxRadius = gDebugInfo[4][0] + 100;
    o->hitboxHeight = gDebugInfo[4][1] + 300;
    attack_collided_non_mario_object(o);
}
