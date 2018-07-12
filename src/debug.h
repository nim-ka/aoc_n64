#ifndef _DEBUG_H
#define _DEBUG_H

#include "types.h"

extern s64 get_current_clock(void);
extern s64 get_clock_difference(s64 cycles);
extern void set_text_array_x_y(s32 xOffset, s32 yOffset);
extern void print_debug_top_down_objectinfo(const char *str, int number);
extern void print_debug_top_down_mapinfo(void *, s32);
extern void debug_unknown_level_select_check(void);
extern void reset_debug_objectinfo(void);
extern void stub_802CA5D0(void);
extern void try_print_debug_mario_object_info(void);

#endif /* _DEBUG_H */
