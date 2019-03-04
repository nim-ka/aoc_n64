// koopa_shell_underwater.c.inc

void func_802AA0D4(void)
{
    set_object_hitbox(o,&D_8032F260);
}

void BehKoopaShellUnderwaterLoop(void)
{
    switch(o->oHeldState)
    {
    case HELD_FREE:
        func_802AA0D4();
        break;
    case HELD_HELD:
        func_8029FA5C(-1,0);
        break;
    case HELD_THROWN:
    case HELD_DROPPED:
        mark_object_for_deletion(o);
        func_802A3004();
        break;
    }
    if(o->oInteractStatus & 0x400000)
    {
        mark_object_for_deletion(o);
        func_802A3004();
    }
    o->oInteractStatus = 0;
}
