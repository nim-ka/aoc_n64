.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/cake_end.mio0"
.align 4

.section .level, "a"

glabel level_ending_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ 0x0049C6B0, /*romEnd*/ 0x004AA450
    alloc_level_pool

    area /*index*/ 1, /*geo*/ 0x0E000050
    end_area

    free_level_pool
    sleep /*frames*/ 60
    blackout /*active*/ FALSE
    cmd29 /*unk2*/ 0x01
    transition /*unk2*/ 0, /*unk3*/ 75, /*color*/ 0, 0, 0
    sleep /*frames*/ 120
    call /*arg*/ 0, /*func*/ lvl_play_the_end_screen_sound
L1:
    sleep /*frames*/ 1
    jump /*target*/ L1

.align 4
.include "geo/level_ending.geo.s"
.align 4
