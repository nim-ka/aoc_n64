.section .mio0_c, "ax"

.include "levels/game_over_level.s"

.align 4, 0
.global intro_segment7
intro_segment7:
.incbin "build/mio0/intro_segment7.mio0"
.align 4, 0
intro_segment7_end:

.align 4, 0
.global debug_level_select
debug_level_select:
.incbin "build/mio0/debug_level_select.mio0"
.align 4, 0
debug_level_select_end:

.align 4, 0
.global mario_bg
.global mario_bg_end
mario_bg:
.incbin "build/mio0/mario_bg.mio0"
.align 4, 0
mario_bg_end:

