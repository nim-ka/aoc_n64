// bbh_tumbling_bookshelf.c.inc

void BehTumblingBookshelfLoop(void)
{
    o->oDistanceToMario = dist_between_objects(o,gMarioObject); //hmm...
    o->oFaceAngleYaw = 0;
    switch(o->oAction)
    {
    case 0:
        if(o->oTimer == 0) {}
        if(o->oUnk88 != 0)
            o->oAction++;
        break;
    case 1:
        o->oPosX += 5.0f;
        PlaySound(0x410D0001);
        if(o->oTimer > 101)
            mark_object_for_deletion(o);
        break;
    default:
        break;
    }
}