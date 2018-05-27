.include "macros.inc"
.include "level_commands.inc"

.section .level, "a"

L1:
    init_level
    sleep /*frames*/ 2
    blackout /*active*/ FALSE
    set_reg /*value*/ 0
    execute /*seg*/ 0x14, /*script*/ _level_introSegmentRomStart, /*scriptEnd*/ _level_introSegmentRomEnd, /*entry*/ level_intro_entry_1
    jump /*target*/ L1

.align 4
