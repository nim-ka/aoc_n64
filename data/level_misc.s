
.section .mio0_c, "ax"

.include "levels/game_over_level.s"

.align 4, 0x01
.global wood_trademark
wood_trademark:
.incbin "bin/mio0/wood_trademark.mio0"
wood_trademark_end:

.align 4, 0x01
.global debug_level_select
debug_level_select:
.incbin "bin/mio0/debug_level_select.mio0"
debug_level_select_end:

.align 4, 0x01
.global mario_bg
.global mario_bg_end
mario_bg:
.incbin "bin/mio0/mario_bg.mio0"
mario_bg_end:
