#ifndef _LEVEL_SCRIPT_H
#define _LEVEL_SCRIPT_H

extern u8 gFrameBuffer0[];
extern u8 gFrameBuffer1[];
extern u8 gFrameBuffer2[];

struct LevelCommand *level_script_execute(struct LevelCommand *cmd);

#endif /* _LEVEL_SCRIPT_H */
