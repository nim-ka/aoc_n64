.section .mio0_c, "ax"

.align 4, 0
.global debug_level_select
debug_level_select:
.incbin "build/mio0/debug_level_select.mio0"
.align 4, 0
debug_level_select_end:

.align 4, 0
.global title_screen_bg
.global title_screen_bg_end
title_screen_bg:
.incbin "build/mio0/title_screen_bg.mio0"
.align 4, 0
title_screen_bg_end:

