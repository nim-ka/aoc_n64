#ifndef _SM64_H_
#define _SM64_H_

// Global header for Super Mario 64

#include "types.h"
#include "variables.h"
#include "functions.h"

// Avoid compiler warnings for unused variables
#ifdef __GNUC__
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

// convert a virtual address to physical.
#define TOPHYSICAL(addr)    ((u32)addr & 0x1FFFFFFF)

/*
 this input mask is unused by the controller, 
 but END_DEMO is used internally to signal 
 the demo to end. These two buttons cannot 
 be pressed normally by a controller.
*/
#define END_DEMO       DUMMY_1

#define VALID_BUTTONS (A_BUTTON   | B_BUTTON   | Z_TRIG     | START_BUTTON | \
                       U_JPAD     | D_JPAD     | L_JPAD     | R_JPAD       | \
                       L_TRIG     | R_TRIG     |                             \
                       U_CBUTTONS | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS   )

#endif
