#ifndef FRAMEBUFFERS_H
#define FRAMEBUFFERS_H

#include <PR/ultratypes.h>

#include "config.h"

// level_script.c assumes that the frame buffers are adjacent, while game.c's
// -g codegen implies that they are separate variables. This is impossible to
// reconcile without undefined behavior. Avoid that when possible.
extern u16 gFrameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

#endif // FRAMEBUFFERS_H
