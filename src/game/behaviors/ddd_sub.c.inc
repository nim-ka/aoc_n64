// ddd_sub.c.inc

void BehBowsersSubLoop(void)
{
    if(save_file_get_flags() & (SAVE_FLAG_HAVE_KEY_2 | SAVE_FLAG_UNLOCKED_UPSTAIRS_DOOR))
        mark_object_for_deletion(o);
}
