#include <ultra64.h>

#include "sm64.h"
#include "gd_main.h"
#include "debug_memory.h"
#include "mario_head_1.h"
#include "profiler_utils.h"
#include "../mario_head_6.h"

/* This file was spilt out of debug_memory.asm based on rodata.
 * The rodata for functions after this "__main__" function have string literals following 
 * float literal, which implies that this is its own file
 */

/* D_801A8050 and D_801A8058 might be declared here, or in some big common
 * file with the oddly placed and used symbols that follow
 */

struct GdMem801B9920 D_801B9920;
struct GdMem801B9A18 D_801B9A18;

/* @ 225DA0 for 0x110 */
u32 __main__(void)
{
    UNUSED u32 pad1C;

    printf("%x, %x\n", (u32) &D_801A8058, (u32) &D_801A8050);
    add_to_stacktrace("main");
    gd_init();

    D_801B9920.unk88 = 0.46799f;
    D_801B9920.unkA0 = -34.0f;
    D_801B9920.unkAC = 34.0f;
    D_801B9920.unk00 = 2;
    D_801B9920.unk54 = 0;
    D_801B9920.unkF0 = &D_801B9A18;

    add_to_stacktrace("main - make_scene");
    //TODO: rename to "make_scene"?; called function does nothing, so the note could be about all of these functions
    func_8017E20C();
    imout();
    
    _InitControllers();
    print_all_memtrackers();

    start_timer("dlgen");
    stop_timer("dlgen");
    mem_stats();

    while (TRUE)
        func_801A520C();
    
    imout();
    return 0;
}
