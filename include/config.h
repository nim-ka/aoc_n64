#ifndef _CONFIG_H_
#define _CONFIG_H_

// Bug fixes
#ifdef VERSION_US
// Fixes bug where obtaining over 999 coins sets the number of lives to 999 (or -25)
#define BUGFIX_MAX_LIVES 1
// Fixes bug in Bob-Omb Battlefield where entering a warp stops the Koopa race music
#define BUGFIX_KOOPA_RACE_MUSIC 1
#endif

#endif
