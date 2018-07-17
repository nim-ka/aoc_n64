.include "macros.inc"
.include "level_commands.inc"

.section .seg07, "a"
.align 4
.incbin "build/mio0/cake_end.mio0"
.align 4

.section .level, "a"

glabel level_ending_entry
    init_level
    load_mio0 /*seg*/ 0x07, /*romStart*/ _level_ending_segment_7SegmentRomStart, /*romEnd*/ _level_ending_segment_7SegmentRomEnd
    alloc_level_pool

    area /*index*/ 1, /*geo*/ ending_geo_000050
    end_area

    free_level_pool
    sleep /*frames*/ 60
    blackout /*active*/ FALSE
    load_area /*area*/ 1
    transition /*unk2*/ 0, /*unk3*/ 75, /*color*/ 0, 0, 0
    sleep /*frames*/ 120
    call /*arg*/ 0, /*func*/ lvl_play_the_end_screen_sound
L1:
    sleep /*frames*/ 1
    jump /*target*/ L1

.align 4
.include "levels/geo/level_ending.s"
.align 4
