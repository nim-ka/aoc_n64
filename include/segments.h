#ifndef _SEGMENTS_H
#define _SEGMENTS_H

// Memory addresses for segments. Ideally, this header file would not be
// needed, and the addresses would be defined in sm64.ld and linker-inserted
// into C code. However, there are some cases where that would not match, where
// addresses are loaded using lui/ori rather than lui/addiu.
// To avoid duplication, this file is included from sm64.ld. We make sure not
// to cast the addresses to pointers in this file, since that would be invalid
// linker script syntax.

#define SEG_POOL_START   0x8005C000
#define SEG_POOL_END     SEG_STACK
#define SEG_GODDARD      0x8016F000
#define SEG_STACK        0x801C1000
#define SEG_MAIN         0x80246000
#define SEG_ENGINE       0x80378800
#define SEG_FRAMEBUFFERS 0x8038F800

#endif // _SEGMENTS_H
