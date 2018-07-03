#ifndef _AUDIODEFINES_H
#define _AUDIODEFINES_H

// Sound Magic Definition:
// First Byte (Upper Nibble): Sound Bank
// First Byte (Lower Nibble): Bitflags for audio playback?
// Second Byte: Sound ID
// Third Byte: Bitflags for audio properties
// Fourth Byte (Upper Nibble): Envelope? (0-8, 8 is play the full sound)
// Fourth Byte (Lower Nibble): Sound Status (this is set to SOUND_PLAYING when passed to the audio driver.)
#define SOUND_ARG_LOAD(bank, playFlags, soundID, propFlags, envelope) (((u32) (bank) << 28)     | \
                 ((u32) (playFlags) << 24) | ((u32) (soundID) << 16) | ((u32) (propFlags) << 8) | \
                 ((u32) (envelope)  << 4)  |  SOUND_STARTING)

/* Audio Status */
#define SOUND_STOPPED  0
#define SOUND_STARTING 1
#define SOUND_PLAYING  2

/* Audio Playback Bitflags */
#define SOUND_PL_BITFLAG_UNK0     (1 << 0) // 0x01
#define SOUND_PL_BITFLAG_UNK1     (1 << 1) // 0x02
#define SOUND_PL_BITFLAG_UNK2     (1 << 2) // 0x04
#define SOUND_PL_BITFLAG_UNK3     (1 << 3) // 0x08

/* Audio Property Bitflags */
#define SOUND_BITFLAG_UNK0        (1 << 0) // 0x01
#define SOUND_BITFLAG_UNK1        (1 << 1) // 0x02
#define SOUND_BITFLAG_UNK2        (1 << 2) // 0x04
#define SOUND_BITFLAG_UNK3        (1 << 3) // 0x08
#define SOUND_BITFLAG_UNK4        (1 << 4) // 0x10
#define SOUND_BITFLAG_UNK5        (1 << 5) // 0x20
#define SOUND_BITFLAG_UNK6        (1 << 6) // 0x40
#define SOUND_BITFLAG_PRIORITY    (1 << 7) // 0x80

#define SOUND_BITFLAG_ALLFLAGS    (SOUND_BITFLAG_UNK0 | SOUND_BITFLAG_UNK1 | \
                                   SOUND_BITFLAG_UNK2 | SOUND_BITFLAG_UNK3 | \
                                   SOUND_BITFLAG_UNK4 | SOUND_BITFLAG_UNK5 | \
                                   SOUND_BITFLAG_UNK6 | SOUND_BITFLAG_PRIORITY)

#define SOUND_BITFLAG_NOFLAGS     0 // for readability

// silence
#define NO_SOUND                  0

/* Terrain Sounds */
/* not verified */ #define SOUND_TERRAIN_NORMAL         0x0000
/* not verified */ #define SOUND_TERRAIN_GRASS          0x0001
/* not verified */ #define SOUND_TERRAIN_WATER          0x0002
/* not verified */ #define SOUND_TERRAIN_NORMALDUPE     0x0003
/* not verified */ #define SOUND_TERRAIN_SQUEAKY_FLOOR  0x0004
/* not verified */ #define SOUND_TERRAIN_SNOW           0x0005
/* not verified */ #define SOUND_TERRAIN_ICE            0x0006
/* not verified */ #define SOUND_TERRAIN_SAND           0x0007
/* not verified */ #define SOUND_TERRAIN_NORMAL2        0x0008
/* not verified */ #define SOUND_ACTION_UNKNOWN408      SOUND_ARG_LOAD(0, 4, 0x08, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_TERRAIN_GRASS2         0x0009
/* not verified */ #define SOUND_TERRAIN_WATER2         0x000A
/* not verified */ #define SOUND_TERRAIN_NORMALDUPE2    0x000B
/* not verified */ #define SOUND_TERRAIN_SQUEAKY_FLOOR2 0x000C
/* not verified */ #define SOUND_TERRAIN_SNOW2          0x000D
/* not verified */ #define SOUND_TERRAIN_ICE2           0x000E
/* not verified */ #define SOUND_TERRAIN_SAND2          0x000F
/* not verified */ #define SOUND_TERRAIN_NORMAL3        0x0010
/* not verified */ #define SOUND_ACTION_UNKNOWN610      SOUND_ARG_LOAD(0, 6, 0x10, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_TERRAIN_GRASS3         0x0011
/* not verified */ #define SOUND_TERRAIN_WATER3         0x0012
/* not verified */ #define SOUND_TERRAIN_NORMALDUPE3    0x0013
/* not verified */ #define SOUND_TERRAIN_SQUEAKY_FLOOR3 0x0014
/* not verified */ #define SOUND_TERRAIN_SNOW3          0x0015
/* not verified */ #define SOUND_TERRAIN_ICE3           0x0016
/* not verified */ #define SOUND_TERRAIN_SAND3          0x0017
/* not verified */ #define SOUND_ACTION_UNKNOWN418      SOUND_ARG_LOAD(0, 4, 0x18, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN620      SOUND_ARG_LOAD(0, 6, 0x20, (SOUND_BITFLAG_PRIORITY), 8)
// missing entries? TODO: someone figure out the rest
/* not verified */ #define SOUND_TERRAIN_SNOW5          0x0025
// more missing entries
/* not verified */ #define SOUND_ACTION_UNKNOWN42A      SOUND_ARG_LOAD(0, 4, 0x2A, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN42D      SOUND_ARG_LOAD(0, 4, 0x2D, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK5), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN42E      SOUND_ARG_LOAD(0, 4, 0x2E, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN42F      SOUND_ARG_LOAD(0, 4, 0x2F, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN430      SOUND_ARG_LOAD(0, 4, 0x30, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK6), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN431      SOUND_ARG_LOAD(0, 4, 0x31, (SOUND_BITFLAG_UNK6 | SOUND_BITFLAG_UNK5), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN433      SOUND_ARG_LOAD(0, 4, 0x33, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN434      SOUND_ARG_LOAD(0, 4, 0x34, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN435      SOUND_ARG_LOAD(0, 4, 0x35, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_SWISH1          0x0436
/* not verified */ #define SOUND_ACTION_SWISH2          SOUND_ARG_LOAD(0, 4, 0x37, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN438      SOUND_ARG_LOAD(0, 4, 0x38, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_CLIMBUPTREE     SOUND_ARG_LOAD(0, 4, 0x3A, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_CLIMBDOWNTREE   0x043B
/* not verified */ #define SOUND_ACTION_UNKNOWN43C      0x043C
/* not verified */ #define SOUND_ACTION_UNKNOWN43D      0x043D
/* not verified */ #define SOUND_ACTION_UNKNOWN43E      0x043E
/* not verified */ #define SOUND_ACTION_PATBACK         0x043F
/* not verified */ #define SOUND_ACTION_BRUSHHAIR       0x0440
/* not verified */ #define SOUND_ACTION_UNKNOWN441      SOUND_ARG_LOAD(0, 4, 0x41, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN442      SOUND_ARG_LOAD(0, 4, 0x42, (SOUND_BITFLAG_PRIORITY), 8)
// missing entries? TODO: someone figure out the rest
/* not verified */ #define SOUND_ACTION_UNKNOWN444      SOUND_ARG_LOAD(0, 4, 0x44, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK6), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN444_2    SOUND_ARG_LOAD(0, 4, 0x44, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK5 | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN445      SOUND_ARG_LOAD(0, 4, 0x45, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK5), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN447      SOUND_ARG_LOAD(0, 4, 0x47, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK5), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN450      SOUND_ARG_LOAD(0, 4, 0x50, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN451      SOUND_ARG_LOAD(0, 4, 0x51, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN452      SOUND_ARG_LOAD(0, 4, 0x52, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN456      SOUND_ARG_LOAD(0, 4, 0x56, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN458      SOUND_ARG_LOAD(0, 4, 0x58, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK5), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN459      SOUND_ARG_LOAD(0, 4, 0x59, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK5 | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN45A      SOUND_ARG_LOAD(0, 4, 0x5A, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_ACTION_UNKNOWN45B      0x045B
/* not verified */ #define SOUND_ACTION_UNKNOWN45C      0x045C

/* Moving Sound Effects */
// might be a bad name, consider something else.
/* not verified */ #define SOUND_MOVING_SLIDING1        0x1000
/* not verified */ #define SOUND_UNKNOWN_UNK1400        SOUND_ARG_LOAD(1, 4, 0x00, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_MOVING_SLIDING2        0x1001
/* not verified */ #define SOUND_UNKNOWN_UNK1401        SOUND_ARG_LOAD(1, 4, 0x01, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_MOVING_SLIDINGWATER1   0x1002
/* not verified */ #define SOUND_UNKNOWN_UNK1402        SOUND_ARG_LOAD(1, 4, 0x02, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_MOVING_SLIDING3        0x1003
/* not verified */ #define SOUND_UNKNOWN_UNK1403        SOUND_ARG_LOAD(1, 4, 0x03, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_MOVING_SLIDINGGHOST    0x1004
/* not verified */ #define SOUND_UNKNOWN_UNK1404        SOUND_ARG_LOAD(1, 4, 0x04, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_MOVING_SLIDINGGRASS    0x1005
/* not verified */ #define SOUND_UNKNOWN_UNK1405        SOUND_ARG_LOAD(1, 4, 0x05, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_MOVING_SLIDINGSNOW     0x1006
/* not verified */ #define SOUND_UNKNOWN_UNK1406        SOUND_ARG_LOAD(1, 4, 0x06, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_MOVING_SLIDINGSAND     0x1007
/* not verified */ #define SOUND_MOVING_SLIDING4        0x1008
/* not verified */ #define SOUND_MOVING_SLIDING5        0x1009
/* not verified */ #define SOUND_MOVING_SLIDINGWATER2   0x100A
/* not verified */ #define SOUND_MOVING_SLIDING6        0x100B
/* not verified */ #define SOUND_UNKNOWN_UNK1410        SOUND_ARG_LOAD(1, 4, 0x10, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_UNKNOWN_UNK1411        SOUND_ARG_LOAD(1, 4, 0x11, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_UNKNOWN_UNK1412        SOUND_ARG_LOAD(1, 4, 0x12, (SOUND_BITFLAG_PRIORITY), 0)
/* not verified */ #define SOUND_UNKNOWN_UNK1414        SOUND_ARG_LOAD(1, 4, 0x14, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_UNKNOWN_UNK1416        SOUND_ARG_LOAD(1, 4, 0x16, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_UNKNOWN_UNK1417        SOUND_ARG_LOAD(1, 4, 0x17, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_MOVING_UNKNOWN19       SOUND_ARG_LOAD(1, 0xD, 0x19, (SOUND_BITFLAG_UNK5), 0)
/* not verified */ #define SOUND_MOVING_ONFIRE          0x1020
/* not verified */ #define SOUND_UNKNOWN_UNK1420        SOUND_ARG_LOAD(1, 4, 0x20, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_MOVING_UNKNOWN         0x1021
/* not verified */ #define SOUND_UNKNOWN_UNK1428        SOUND_ARG_LOAD(1, 4, 0x28, (SOUND_BITFLAG_NOFLAGS), 0)

/* Mario Sound Effects */
/* not verified */ #define SOUND_MARIO_YAH              0x2400
/* not verified */ #define SOUND_MARIO_WAH1             0x2401
/* not verified */ #define SOUND_MARIO_WOOH             0x2402
/* not verified */ #define SOUND_MARIO_HOOHOO           SOUND_ARG_LOAD(2, 4, 0x03, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_YAHOO            SOUND_ARG_LOAD(2, 4, 0x04, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_UH               SOUND_ARG_LOAD(2, 4, 0x05, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_HRMM             SOUND_ARG_LOAD(2, 4, 0x06, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_WAH2             SOUND_ARG_LOAD(2, 4, 0x07, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_WHOA             SOUND_ARG_LOAD(2, 4, 0x08, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK6), 8)
/* not verified */ #define SOUND_MARIO_EEUH             SOUND_ARG_LOAD(2, 4, 0x09, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_ATTACKED         SOUND_ARG_LOAD(2, 4, 0x0A, (SOUND_BITFLAG_ALLFLAGS), 8)
/* not verified */ #define SOUND_MARIO_OOOF             SOUND_ARG_LOAD(2, 4, 0x0B, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_HEREWEGO         SOUND_ARG_LOAD(2, 4, 0x0C, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_YAWNING          0x240D
/* not verified */ #define SOUND_MARIO_SNORING1         0x240E
/* not verified */ #define SOUND_MARIO_SNORING2         0x240F
/* not verified */ #define SOUND_MARIO_WAAAOOOW         SOUND_ARG_LOAD(2, 4, 0x10, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK6), 8)
/* not verified */ #define SOUND_MARIO_HAHA             SOUND_ARG_LOAD(2, 4, 0x11, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_HAHA_2           SOUND_ARG_LOAD(2, 4, 0x11, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK6 | SOUND_BITFLAG_UNK5 | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_MARIO_HOO              0x2412
/* not verified */ #define SOUND_MARIO_UH2              SOUND_ARG_LOAD(2, 4, 0x13, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK6 | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_MARIO_UH2_2            SOUND_ARG_LOAD(2, 4, 0x13, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_ONFIRE           SOUND_ARG_LOAD(2, 4, 0x14, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK5), 8)
/* not verified */ #define SOUND_MARIO_DYING            0x2415
/* not verified */ #define SOUND_MARIO_HOO2             0x2416
/* not verified */ #define SOUND_MARIO_COUGHING         0x2417
/* not verified */ #define SOUND_MARIO_HOO3             0x2418
/* not verified */ #define SOUND_MARIO_HOO4             0x2419
/* not verified */ #define SOUND_MARIO_HOO5             0x241A
/* not verified */ #define SOUND_MARIO_COUGHING2        0x241B
/* not verified */ #define SOUND_MARIO_COUGHING3        0x241C
/* not verified */ #define SOUND_MARIO_COUGHING4        0x241D
/* not verified */ #define SOUND_MARIO_YAH2             SOUND_ARG_LOAD(2, 4, 0x1E, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_HOO6             SOUND_ARG_LOAD(2, 4, 0x1F, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_MAMAMIA          SOUND_ARG_LOAD(2, 4, 0x20, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_OKEYDOKEY        0x2421
/* not verified */ #define SOUND_MARIO_WAH3             SOUND_ARG_LOAD(2, 4, 0x22, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_DROWNING         SOUND_ARG_LOAD(2, 4, 0x23, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK6 | SOUND_BITFLAG_UNK5 | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_MARIO_WAH4             SOUND_ARG_LOAD(2, 4, 0x24, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_UH3              0x2425
/* not verified */ #define SOUND_MARIO_HEAVYLIFT        0x2426
/* not verified */ #define SOUND_MARIO_WAH5             0x2427

/* Mario Sound Effects (Added in US) */
/* not verified */ #define SOUND_PEACH_DEARMARIO        0x2428
/* not verified */ #define SOUND_MARIO_WOOH2            0x2429
/* not verified */ #define SOUND_MARIO_WOOH3            0x242A
/* not verified */ // the next 5 sounds are in a group of 5 for which the sound is determined by the SetSound call used.
/* not verified */ #define SOUND_MARIO_YAHOO2           SOUND_ARG_LOAD(2, 4, 0x2B, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_YAHOO3           SOUND_ARG_LOAD(2, 4, 0x2C, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_YAHOO4           SOUND_ARG_LOAD(2, 4, 0x2D, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_WAHA             SOUND_ARG_LOAD(2, 4, 0x2E, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_YIPEE            SOUND_ARG_LOAD(2, 4, 0x2F, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_DOH              SOUND_ARG_LOAD(2, 4, 0x30, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_GAMEOVER         0x2431
/* not verified */ #define SOUND_MARIO_HELLO            0x2432
/* not verified */ #define SOUND_MARIO_PRESSSTARTTOPLAY 0x2433
/* not verified */ #define SOUND_MARIO_BOING            SOUND_ARG_LOAD(2, 4, 0x34, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MARIO_SNORING3         0x2435
/* not verified */ #define SOUND_MARIO_SOLONGABOWSER    0x2436
/* not verified */ #define SOUND_MARIO_IMATIRED         0x2437

/* Princess Peach Sound Effects (US Only) */
/* not verified */ #define SOUND_PEACH_MARIO            0x2438
/* not verified */ #define SOUND_PEACH_POWEROFTHESTARS  0x2439
/* not verified */ #define SOUND_PEACH_THANKSTOYOU      0x243A
/* not verified */ #define SOUND_PEACH_THANKYOUMARIO    0x243B
/* not verified */ #define SOUND_PEACH_SOMETHINGSPECIAL 0x243C
/* not verified */ #define SOUND_PEACH_BAKEACAKE        0x243D
/* not verified */ #define SOUND_PEACH_FORMARIO         0x243E
/* not verified */ #define SOUND_PEACH_MARIO2           0x243F

/* General Sound Effects */
/* not verified */ #define SOUND_GENERAL_EXPLOSION      0x3000
/* not verified */ #define SOUND_GENERAL_MARIOHOLE1     0x3001
/* not verified */ #define SOUND_GENERAL_MARIOHOLE2     0x3002
/* not verified */ #define SOUND_GENERAL_FLAMEOUT       SOUND_ARG_LOAD(3, 0, 0x03, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_GENERAL_OPENWOODDOOR   0x3004
/* not verified */ #define SOUND_GENERAL_CLOSEWOODDOOR  0x3005
/* not verified */ #define SOUND_GENERAL_OPENIRONDOOR   0x3006
/* not verified */ #define SOUND_GENERAL_CLOSEIRONDOOR  0x3007
/* not verified */ #define SOUND_GENERAL_BUBBLES1       0x3008
/* not verified */ #define SOUND_GENERAL_MOVINGWATER    0x3009
/* not verified */ #define SOUND_GENERAL_SWISHWATER     0x300A
/* not verified */ #define SOUND_GENERAL_QUIETBUBBLE    0x300B
/* not verified */ #define SOUND_GENERAL_EXPLOSION2     0x300C
/* not verified */ #define SOUND_GENERAL_QUIETBUBBLE2   0x300D
/* not verified */ #define SOUND_GENERAL_UNUSED         0x300E
/* not verified */ #define SOUND_GENERAL_EXPLOSION3     0x300F
/* not verified */ #define SOUND_GENERAL_COIN1          0x3010
/* not verified */ #define SOUND_GENERAL_COIN2          0x3011
/* not verified */ #define SOUND_GENERAL_COINWATER1     0x3012
/* not verified */ #define SOUND_GENERAL_COINWATER2     0x3013
/* not verified */ #define SOUND_GENERAL_COINWATER3     0x3014
/* not verified */ #define SOUND_GENERAL_COINWATER4     0x3015
/* not verified */ #define SOUND_GENERAL_SHORTSTAR      SOUND_ARG_LOAD(3, 0, 0x16, (SOUND_BITFLAG_NOFLAGS), 9)
/* not verified */ #define SOUND_GENERAL_BIGCLOCK       0x3017
/* not verified */ #define SOUND_GENERAL_LOUDPOUND      0x3018
/* not verified */ #define SOUND_GENERAL_SHORTPOUND1    0x3019
/* not verified */ #define SOUND_GENERAL_SHORTPOUND2    0x301A
/* not verified */ #define SOUND_GENERAL_SHORTPOUND3    0x301B
/* not verified */ #define SOUND_GENERAL_SHORTPOUND4    0x301C
/* not verified */ #define SOUND_GENERAL_SHORTPOUND5    0x301D
/* not verified */ #define SOUND_GENERAL_SHORTPOUND6    0x301E
/* not verified */ #define SOUND_GENERAL_SHORTPOUND7    0x301F
/* not verified */ #define SOUND_GENERAL_OPENCHEST1     0x3020
/* not verified */ #define SOUND_GENERAL_OPENCHEST2     0x3021
/* not verified */ #define SOUND_GENERAL_CLAMSHELL1     0x3022
/* not verified */ #define SOUND_GENERAL_CLAMSHELL2     0x3023
/* not verified */ #define SOUND_GENERAL_BOXLANDING     0x3024
/* not verified */ #define SOUND_GENERAL_UNKNOWN1       0x3025
/* not verified */ #define SOUND_GENERAL_CLAMSHELL3     0x3026
/* not verified */ #define SOUND_GENERAL_CLAMSHELL4     0x3027
/* not verified */ #define SOUND_GENERAL_EXITPAINTING1  0x3028
/* not verified */ #define SOUND_UNKNOWN_UNK3828        SOUND_ARG_LOAD(3, 8, 0x28, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_GENERAL_EXITPAINTING2  0x3029
/* not verified */ #define SOUND_GENERAL_EXITPAINTING3  0x302A
/* not verified */ #define SOUND_GENERAL_EXITPAINTING4  SOUND_ARG_LOAD(3, 0, 0x2B, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_GENERAL_GETSTAR        0x302C
/* not verified */ #define SOUND_GENERAL_PLATFORM       0x302D
/* not verified */ #define SOUND_GENERAL_EXPLOSION4     0x302E
/* not verified */ #define SOUND_GENERAL_EXPLOSION5     0x302F
/* not verified */ #define SOUND_GENERAL_COINSPURT      0x3030
/* not verified */ #define SOUND_GENERAL_EXPLOSION6     0x3031
/* not verified */ #define SOUND_GENERAL_UNKNOWN2       0x3032
/* not verified */ #define SOUND_GENERAL_GETCOIN        0x3033
/* not verified */ #define SOUND_GENERAL_BOATTILT1      0x3034
/* not verified */ #define SOUND_GENERAL_BOATTILT2      0x3035
/* not verified */ #define SOUND_GENERAL_COINDROP       0x3036
/* not verified */ #define SOUND_GENERAL_UNKNOWN3       0x3037
/* not verified */ #define SOUND_GENERAL_SWITCH1        0x3038
/* not verified */ #define SOUND_GENERAL_CHAINCHOMP1    0x3039
/* not verified */ #define SOUND_GENERAL_CHAINCHOMP2    0x303A
/* not verified */ #define SOUND_GENERAL_SWITCH2        0x303B
/* not verified */ #define SOUND_GENERAL_MOVINGINSAND   0x303C
/* not verified */ #define SOUND_GENERAL_UNKNOWN4       0x303D
/* not verified */ #define SOUND_GENERAL_SWITCH3        0x303E
/* not verified */ #define SOUND_GENERAL_CAGEOPEN       0x303F
/* not verified */ #define SOUND_GENERAL_QUIETPOUND1    0x3040
/* not verified */ #define SOUND_GENERAL_BREAKBOX       0x3041
/* not verified */ #define SOUND_GENERAL_SWITCH4        0x3042
/* not verified */ #define SOUND_GENERAL_QUIETPOUND2    0x3043
/* not verified */ #define SOUND_GENERAL_BIGPOUND       0x3044
// missing 3 entries
/* not verified */ #define SOUND_GENERAL_CANNONUP       0x3047
/* not verified */ #define SOUND_GENERAL_GRINDELROLL    0x3048
/* not verified */ #define SOUND_GENERAL_EXPLOSION7     0x3049
/* not verified */ #define SOUND_GENERAL_SHAKECOFFIN    0x304A
/* not verified */ #define SOUND_GENERAL_PYRAMIDTOP     0x304B
/* not verified */ #define SOUND_GENERAL_EXPLOSION8     0x304C
/* not verified */ #define SOUND_GENERAL_RACEGUNSHOT    0x304D
/* not verified */ #define SOUND_GENERAL_STARDOOROPEN   0x304E
/* not verified */ #define SOUND_GENERAL_STARDOORCLOSE  0x304F
/* not verified */ #define SOUND_GENERAL_BIRDCHIRP1     0x3050
/* not verified */ #define SOUND_GENERAL_BIRDCHIRP2     0x3051
/* not verified */ #define SOUND_GENERAL_BIRDCHIRP3     0x3052
/* not verified */ #define SOUND_GENERAL_BIRDCHIRP4     0x3053
/* not verified */ #define SOUND_GENERAL_SWITCH5        0x3054
/* not verified */ #define SOUND_GENERAL_SWITCH6        0x3055
/* not verified */ #define SOUND_GENERAL_POUNDROCK      0x3056
/* not verified */ #define SOUND_GENERAL_STARAPPEARS    0x3057
/* not verified */ #define SOUND_GENERAL_1UP            0x3058
/* not verified */ #define SOUND_GENERAL_ELEVATORHMC    0x3059
/* not verified */ #define SOUND_GENERAL_BUTTONPRESS    0x305A
/* not verified */ #define SOUND_GENERAL_ELEVATORMOVE   0x305B
/* not verified */ #define SOUND_GENERAL_SWISHAIR       0x305C
/* not verified */ #define SOUND_GENERAL_HAUNTEDCHAIR   0x305D
/* not verified */ #define SOUND_GENERAL_SOFTLANDING    0x305E
/* not verified */ #define SOUND_GENERAL_MOVINGBOOMAYBE 0x305F // not certain
/* not verified */ #define SOUND_GENERAL_BOWSEREXPLODE  0x3060
/* not verified */ #define SOUND_GENERAL_BOWSERKEY      0x3061
/* not verified */ #define SOUND_GENERAL_BOWSERPLATFORM 0x3062
/* not verified */ #define SOUND_GENERAL_1UP2           0x3063
/* not verified */ #define SOUND_GENERAL_HEARTSPIN      0x3064
/* not verified */ #define SOUND_GENERAL_POUNDWOODPOST  0x3065
/* not verified */ #define SOUND_GENERAL_WATERLEVELTRIG 0x3066
/* not verified */ #define SOUND_GENERAL_SWITCHDOOROPEN 0x3067
/* not verified */ #define SOUND_GENERAL_REDCOIN        0x3068
/* not verified */ #define SOUND_GENERAL_BIRDSFLYAWAY   0x3069
/* not verified */ #define SOUND_GENERAL_RIGHTANSWER    0x306A
/* not verified */ #define SOUND_GENERAL_METALPOUND     0x306B
/* not verified */ #define SOUND_GENERAL_BOING1         SOUND_ARG_LOAD(3, 0, 0x6C, (SOUND_BITFLAG_UNK6), 8)
/* not verified */ #define SOUND_GENERAL_BOING2         SOUND_ARG_LOAD(3, 0, 0x6D, (SOUND_BITFLAG_UNK6), 8)
/* not verified */ #define SOUND_GENERAL_UNKNOWN5       0x306E
/* not verified */ #define SOUND_GENERAL_ENEMYALERT1    0x306F
/* not verified */ #define SOUND_GENERAL_YOSHI          0x3070
/* not verified */ #define SOUND_GENERAL_SPLATTERING    0x3071
/* not verified */ #define SOUND_GENERAL_BOING3         0x3072
/* not verified */ #define SOUND_GENERAL_GRANDSTAR      0x3073
/* not verified */ #define SOUND_GENERAL_GRANDSTARJUMP  0x3074
/* not verified */ #define SOUND_GENERAL_BOATROCK       0x3075
/* not verified */ #define SOUND_GENERAL_VANISHSFX      0x3076
/* not verified */ #define SOUND_GENERAL_MARIOHOLE3     0x3077
/* not verified */ #define SOUND_GENERAL_REDCOIN2       0x3078
/* not verified */ #define SOUND_GENERAL_BIRDSFLYAWAY2  0x3079
/* not verified */ #define SOUND_GENERAL_RIGHTANSWER2   0x307A
/* not verified */ #define SOUND_GENERAL_METALPOUND2    0x307B
/* not verified */ #define SOUND_GENERAL_BOING4         0x307C
/* not verified */ #define SOUND_GENERAL_BOING5         0x307D
/* not verified */ #define SOUND_GENERAL_YOSHIWALK      0x307E
/* not verified */ #define SOUND_GENERAL_ENEMYALERT2    0x307F

/* Environment Sound Effects */
/* not verified */ #define SOUND_ENVIRONMENT_WATERFALL1      SOUND_ARG_LOAD(4, 0, 0x00, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_WATERFALL2      SOUND_ARG_LOAD(4, 0, 0x01, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_ELEVATOR1       SOUND_ARG_LOAD(4, 0, 0x02, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_DRONING1        SOUND_ARG_LOAD(4, 1, 0x03, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_DRONING2        SOUND_ARG_LOAD(4, 0, 0x04, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_WIND1           SOUND_ARG_LOAD(4, 0, 0x05, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_MOVINGSANDSNOW  0x4006
/* not verified */ #define SOUND_ENVIRONMENT_UNKNOWN1        0x4007
/* not verified */ #define SOUND_ENVIRONMENT_ELEVATOR2       SOUND_ARG_LOAD(4, 0, 0x08, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_WATER           SOUND_ARG_LOAD(4, 0, 0x09, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_UNKNOWN2        SOUND_ARG_LOAD(4, 0, 0x0A, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_BOATROCKING1    SOUND_ARG_LOAD(4, 0, 0x0B, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_ELEVATOR3       SOUND_ARG_LOAD(4, 0, 0x0C, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_ELEVATOR4       SOUND_ARG_LOAD(4, 0, 0x0D, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_ENVIRONMENT_MOVINGSAND      0x400E
/* not verified */ #define SOUND_ENVIRONMENT_BOATROCKING2    0x400F
/* not verified */ #define SOUND_ENVIRONMENT_WIND2           SOUND_ARG_LOAD(4, 0, 0x10, (SOUND_BITFLAG_PRIORITY), 0)
/* not verified */ #define SOUND_ENVIRONMENT_MOVINGSANDSNOW2 0x4011
/* not verified */ #define SOUND_ENVIRONMENT_UNKNOWN3        0x4012
/* not verified */ #define SOUND_ENVIRONMENT_SLIDING         0x4013
/* not verified */ #define SOUND_ENVIRONMENT_STAR            0x4014
/* not verified */ #define SOUND_ENVIRONMENT_UNKNOWN4        0x4015
/* not verified */ #define SOUND_ENVIRONMENT_WATERDRAIN      0x4016
/* not verified */ #define SOUND_ENVIRONMENT_METALBOXPUSH    0x4017
/* not verified */ #define SOUND_ENVIRONMENT_SINKQUICKSAND   0x4018
/* not verified */ #define SOUND_ENVIRONMENT_PEACHSPARKLE    0x4019
/* not verified */ #define SOUND_ENVIRONMENT_ELEVATOR5       0x401A
/* not verified */ #define SOUND_ENVIRONMENT_FIRE            0x401B

/* Object Sound Effects */
/* not verified */ #define SOUND_OBJECT_WATERSOUND           0x5000
/* not verified */ #define SOUND_OBJECT_MRISHOOT             0x5001
/* not verified */ #define SOUND_OBJECT_PENGUINWALKING1      0x5002
/* not verified */ #define SOUND_OBJECT_BOWSERWALK           0x5003
/* not verified */ #define SOUND_OBJECT_BOWSERROAR           0x5004
/* not verified */ #define SOUND_OBJECT_BOWSERTAILPICKUP     0x5005
/* not verified */ #define SOUND_OBJECT_BOWSERDEFEATED       0x5006
/* not verified */ #define SOUND_OBJECT_BOWSERSPINNING       SOUND_ARG_LOAD(5, 0, 0x07, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_OBJECT_BOWSERINHALING       0x5008
/* not verified */ #define SOUND_OBJECT_PENGUINWALKING2      0x5009
/* not verified */ #define SOUND_OBJECT_UNKNOWN1             0x500A
/* not verified */ #define SOUND_OBJECT_BOOLAUGH1            0x500B
/* not verified */ #define SOUND_OBJECT_THWOMP               0x500C
/* not verified */ #define SOUND_OBJECT_CANNON1              0x500D
/* not verified */ #define SOUND_OBJECT_CANNON2              0x500E
/* not verified */ #define SOUND_OBJECT_CANNON3              0x500F
/* not verified */ #define SOUND_OBJECT_PIRANHAPLANTCHOMP    0x5010
/* not verified */ #define SOUND_OBJECT_PIRANHAPLANTDEATH    0x5011
/* not verified */ #define SOUND_OBJECT_JUMPWALKWATER        0x5012
/* not verified */ #define SOUND_OBJECT_UNKNOWN2             0x5013
/* not verified */ #define SOUND_OBJECT_MRIDEATH             0x5014
/* not verified */ #define SOUND_OBJECT_POUNDING1            0x5015
/* not verified */ #define SOUND_OBJECT_BULLYTHWOMP          0x5016
/* not verified */ #define SOUND_OBJECT_BULLYMETAL           SOUND_ARG_LOAD(5, 0, 0x17, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_OBJECT_BULLYEXPLODE         0x5018
/* not verified */ #define SOUND_OBJECT_BOWSERPUZZLE         0x5019
/* not verified */ #define SOUND_OBJECT_POUNDINGCANNON       SOUND_ARG_LOAD(5, 0, 0x1A, (SOUND_BITFLAG_UNK6 | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_OBJECT_BULLYWALK            0x501B
/* not verified */ #define SOUND_OBJECT_BULLYATTACKED        0x501C
/* not verified */ #define SOUND_OBJECT_UNKNOWN3             0x501D
/* not verified */ #define SOUND_OBJECT_UNKNOWN4             0x501E
/* not verified */ #define SOUND_OBJECT_BABYPENGUINTRICK     0x501F
/* not verified */ #define SOUND_OBJECT_GOOMBAWALK           0x5020
/* not verified */ #define SOUND_OBJECT_MONKEY1              0x5021
/* not verified */ #define SOUND_OBJECT_MONTYMOLEATTACK      0x5022
/* not verified */ #define SOUND_OBJECT_UNKNOWN5             0x5023
/* not verified */ #define SOUND_OBJECT_DYINGENEMY1          0x5024
/* not verified */ #define SOUND_OBJECT_CANNON4              0x5025
/* not verified */ #define SOUND_OBJECT_DYINGENEMY2          0x5026
/* not verified */ #define SOUND_OBJECT_BOBOMBWALK           0x5027
/* not verified */ #define SOUND_OBJECT_SOMETHINGLANDING     0x5028
/* not verified */ #define SOUND_OBJECT_DIVINGINWATER        0x5029
/* not verified */ #define SOUND_OBJECT_SNOWSAND1            0x502A
/* not verified */ #define SOUND_OBJECT_SNOWSAND2            0x502B
/* not verified */ #define SOUND_OBJECT_FLAMEVANISHING       0x502C
/* not verified */ #define SOUND_OBJECT_BIGPENGUIN           0x502D
/* not verified */ #define SOUND_OBJECT_WATERBOMBBOUNCING    0x502E
/* not verified */ #define SOUND_OBJECT_GOOMBAALERT          0x502F
/* not verified */ #define SOUND_OBJECT_GOOMBASTOMPED        0x5030
/* not verified */ #define SOUND_OBJECT_UNKNOWN6             0x5031
/* not verified */ #define SOUND_OBJECT_DIVINGINTOWATER      0x5032
/* not verified */ #define SOUND_OBJECT_PIRANHAPLANTSHRINK   0x5033
/* not verified */ #define SOUND_OBJECT_YOSHIWALK            0x5034
/* not verified */ #define SOUND_OBJECT_UNKNOWNWALKING       0x5035
/* not verified */ #define SOUND_OBJECT_BULLYWALKING         0x5036
/* not verified */ #define SOUND_OBJECT_DORRIE               0x5037
/* not verified */ #define SOUND_OBJECT_BOWSERLAUGH          0x5038
/* not verified */ #define SOUND_OBJECT_MONKEY2              0x5039
/* not verified */ #define SOUND_OBJECT_MONKEY3              0x503A
/* not verified */ #define SOUND_OBJECT_UNKNOWN7             0x503B
/* not verified */ #define SOUND_OBJECT_UNKNOWN8             0x503C
/* not verified */ #define SOUND_OBJECT_KOOPA                0x503D
/* not verified */ #define SOUND_OBJECT_KOOPADAMAGE          0x503E
/* not verified */ #define SOUND_OBJECT_KLEPTO1              0x503F
/* not verified */ #define SOUND_OBJECT_KLEPTO2              0x5040
/* not verified */ #define SOUND_OBJECT_KINGBOBOMB           0x5041
/* not verified */ #define SOUND_OBJECT_KINGBOBOMBDAMAGE     0x5042
/* not verified */ #define SOUND_OBJECT_SCUTTLEBUGWALK       0x5043
/* not verified */ #define SOUND_OBJECT_SCUTTLEBUGALERT      0x5044
/* not verified */ #define SOUND_OBJECT_BABYPENGUIN          0x5045
/* not verified */ #define SOUND_OBJECT_KINGBOBOMBJUMP       0x5046
/* not verified */ #define SOUND_OBJECT_KINGWHOMPDEATH       0x5047
/* not verified */ #define SOUND_OBJECT_BOOLAUGH2            0x5048
/* not verified */ #define SOUND_OBJECT_BAT                  0x5049
/* not verified */ #define SOUND_OBJECT_EEL                  0x504A
/* not verified */ #define SOUND_OBJECT_BRIDGEEXPLODE        0x504B
/* not verified */ #define SOUND_OBJECT_ENEMYALERT           0x504C
/* not verified */ #define SOUND_OBJECT_SNUFITSHOOT          0x504D
/* not verified */ #define SOUND_OBJECT_SKEETERWALK          0x504E
/* not verified */ #define SOUND_OBJECT_WALKINGWATER         0x504F
/* not verified */ #define SOUND_OBJECT_BIRDS1               0x5050
/* not verified */ #define SOUND_OBJECT_BIRDS2               SOUND_ARG_LOAD(5, 0, 0x51, (SOUND_BITFLAG_UNK6), 0)
/* not verified */ #define SOUND_OBJECT_BIRDS3               0x5052
/* not verified */ #define SOUND_OBJECT_BIRDS4               0x5053
/* not verified */ #define SOUND_OBJECT_PIRANHAPLANTAPPEAR   0x5054
/* not verified */ #define SOUND_OBJECT_FLAMEBLOWN           0x5055
/* not verified */ #define SOUND_OBJECT_MADPIANOCHOMPING     0x5056
/* not verified */ #define SOUND_OBJECT_BULLYOTHERENEMY      0x5057
/* not verified */ #define SOUND_OBJECT_BOBOMBBUDDY          0x5058
/* not verified */ #define SOUND_OBJECT_ENEMYDEATHSHORT      0x5059
/* not verified */ #define SOUND_OBJECT_THWOMPSOUNDSHORT     0x505A
/* not verified */ #define SOUND_OBJECT_THWOMPSOUNDLONG      0x505B
/* not verified */ #define SOUND_OBJECT_WIGGLER              0x505C
/* not verified */ #define SOUND_OBJECT_HEAVEHOTOSSED        0x505D
/* not verified */ #define SOUND_OBJECT_WIGGLERDEATH         0x505E
/* not verified */ #define SOUND_OBJECT_BOWSERINTROLAUGH     0x505F
/* not verified */ #define SOUND_OBJECT_ENEMYDEATHHIGH       0x5060
/* not verified */ #define SOUND_OBJECT_ENEMYDEATHLOW        0x5061
/* not verified */ #define SOUND_OBJECT_BATDEATH             0x5062
/* not verified */ #define SOUND_OBJECT_KOOPADEATH           0x5063
/* not verified */ #define SOUND_OBJECT_WATERBOMBBOUNCING2   0x5064
/* not verified */ #define SOUND_OBJECT_EXPLODE              0x5065
/* not verified */ #define SOUND_OBJECT_TELEPORT             0x5066
/* not verified */ #define SOUND_OBJECT_UNKNOWN9             0x5067
/* not verified */ #define SOUND_OBJECT_POUNDINGLOUD         0x5068
/* not verified */ #define SOUND_OBJECT_KINGWHOMP            0x5069
/* not verified */ #define SOUND_OBJECT_MIPSRABBIT           0x506A
/* not verified */ #define SOUND_OBJECT_MRISPINNING          0x506B
/* not verified */ #define SOUND_OBJECT_MIPSRABBITWATER      0x506C
/* not verified */ #define SOUND_OBJECT_EYEROKEXPLODE        0x506D
/* not verified */ #define SOUND_OBJECT_CHUCKYADEATH         0x506E
/* not verified */ #define SOUND_OBJECT_WIGGLER2             0x506F
/* not verified */ #define SOUND_OBJECT_WIGGLERATTACK        0x5070
/* not verified */ #define SOUND_OBJECT_WIGGLERWALK          0x5071
/* not verified */ #define SOUND_OBJECT_SNUFITDEATH          0x5072
/* not verified */ #define SOUND_OBJECT_CHOMPINGSOUND        0x5073
/* not verified */ #define SOUND_OBJECT_ENEMYDEFEATSHRINK    0x5074
/* not verified */ #define SOUND_OBJECT_BOWSERTAILPICKUP2    0x5075
/* not verified */ #define SOUND_OBJECT_BOWSERDEFEATED2      0x5076
/* not verified */ #define SOUND_OBJECT_BOWSERSWINGTAIL      0x5077
/* not verified */ #define SOUND_OBJECT_KLEPTO3              0x5078
/* not verified */ #define SOUND_OBJECT_KINGBOBOMB2          0x5079
/* not verified */ #define SOUND_OBJECT_PENGUINWALKING3      0x507A
/* not verified */ #define SOUND_OBJECT_POUNDING2            0x507B
/* not verified */ #define SOUND_OBJECT_BOWSERROAR2          0x507C
/* not verified */ #define SOUND_OBJECT_BOWSERTAILPICKUP3    0x507D
/* not verified */ #define SOUND_OBJECT_BOWSERDEFEATED3      0x507E
/* not verified */ #define SOUND_OBJECT_BOWSERSWINGTAIL2     0x507F

// Channel 6 sound effects are not yet explored.
/* not verified */ #define SOUND_CH6_UNKNOWN000              SOUND_ARG_LOAD(6, 0, 0x00, (SOUND_BITFLAG_NOFLAGS), 0)
/* not verified */ #define SOUND_CH6_UNKNOWN002              SOUND_ARG_LOAD(6, 0, 0x02, (SOUND_BITFLAG_PRIORITY), 0)
/* not verified */ #define SOUND_CH6_UNKNOWN003              SOUND_ARG_LOAD(6, 0, 0x03, (SOUND_BITFLAG_UNK6), 0)
/* not verified */ #define SOUND_CH6_UNKNOWN004              SOUND_ARG_LOAD(6, 0, 0x04, (SOUND_BITFLAG_PRIORITY), 0)
/* not verified */ #define SOUND_CH6_UNKNOWN004_2            SOUND_ARG_LOAD(6, 0, 0x04, (SOUND_BITFLAG_UNK6), 0)
/* not verified */ #define SOUND_CH6_UNKNOWN010              SOUND_ARG_LOAD(6, 0, 0x10, (SOUND_BITFLAG_UNK6), 0)

/* Menu Sound Effects */
/* not verified */ #define SOUND_MENU_CHANGESELECT           0x7000
/* not verified */ #define SOUND_MENU_REVERSEPAUSE           0x7001
/* not verified */ #define SOUND_MENU_PAUSE1                 0x7002
/* not verified */ #define SOUND_MENU_PAUSE2                 0x7003
/* not verified */ #define SOUND_MENU_MESSAGEAPPEAR          0x7004
/* not verified */ #define SOUND_MENU_MESSAGEDISAPPEAR       0x7005
/* not verified */ #define SOUND_MENU_CAMERAZOOMIN           SOUND_ARG_LOAD(7, 0, 0x06, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_CAMERAZOOMOUT          SOUND_ARG_LOAD(7, 0, 0x07, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_PINCHMARIOFACE         SOUND_ARG_LOAD(7, 0, 0x08, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_LETGOMARIOFACE         SOUND_ARG_LOAD(7, 0, 0x09, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_HANDAPPEAR             SOUND_ARG_LOAD(7, 0, 0x0A, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_HANDDISAPPEAR          SOUND_ARG_LOAD(7, 0, 0x0B, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_UNKNOWN1               SOUND_ARG_LOAD(7, 0, 0x0C, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_POWERMETER             SOUND_ARG_LOAD(7, 0, 0x0D, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_CAMERABUZZ             SOUND_ARG_LOAD(7, 0, 0x0E, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_CAMERATURN             0x700F
/* not verified */ #define SOUND_MENU_UNKNOWN2               0x7010
/* not verified */ #define SOUND_MENU_CLICKFILESELECT        SOUND_ARG_LOAD(7, 0, 0x11, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_READSIGN               0x7012
/* not verified */ #define SOUND_MENU_MESSAGENEXTPAGE        0x7013
/* not verified */ #define SOUND_MENU_COINITSAMEMARIO        SOUND_ARG_LOAD(7, 0, 0x14, (SOUND_BITFLAG_NOFLAGS), 8)
/* not verified */ #define SOUND_MENU_YOSHIGAINLIVES         0x7015
/* not verified */ #define SOUND_MENU_ENTERPIPE              SOUND_ARG_LOAD(7, 0, 0x16, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK5), 8)
/* not verified */ #define SOUND_MENU_EXITPIPE               0x7017
/* not verified */ #define SOUND_MENU_BOWSERLAUGH            SOUND_ARG_LOAD(7, 0, 0x18, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MENU_MARIOHOLE              SOUND_ARG_LOAD(7, 1, 0x19, (SOUND_BITFLAG_PRIORITY), 8)
/* not verified */ #define SOUND_MENU_CLICKCHANGEVIEW        0x701A
/* not verified */ #define SOUND_MENU_CAMERAUNUSED1          0x701B
/* not verified */ #define SOUND_MENU_CAMERAUNUSED2          0x701C
/* not verified */ #define SOUND_MENU_MARIOCASTLEWARP        SOUND_ARG_LOAD(7, 0, 0x1D, (SOUND_BITFLAG_PRIORITY | SOUND_BITFLAG_UNK5 | SOUND_BITFLAG_UNK4), 8)
/* not verified */ #define SOUND_MENU_STARSOUND              SOUND_ARG_LOAD(7, 0, 0x1E, (SOUND_BITFLAG_ALLFLAGS), 8)
/* not verified */ #define SOUND_MENU_THANKYOUPLAYINGMYGAME  SOUND_ARG_LOAD(7, 0, 0x1F, (SOUND_BITFLAG_ALLFLAGS), 8)
/* not verified */ #define SOUND_MENU_READASIGN              0x7020
/* not verified */ #define SOUND_MENU_EXITASIGN              0x7021
/* not verified */ #define SOUND_MENU_MARIOCASTLEWARP2       0x7022
/* not verified */ #define SOUND_MENU_STARSOUNDOKEYDOKEY     0x7023
/* not verified */ #define SOUND_MENU_STARSOUNDLETSAGO       0x7024

/* Channel 8 Sound Effects */
// not yet documented
/* not verified */ #define SOUND_CH8_UNK50      SOUND_ARG_LOAD(8, 0, 0x50, (SOUND_BITFLAG_UNK6), 0)

/* Channel 9 Sound Effects */
// not yet documented
/* not verified */ #define SOUND_CH9_UNK52      SOUND_ARG_LOAD(9, 0, 0x52, (SOUND_BITFLAG_UNK6), 0)

#endif /* _AUDIODEFINES_H */
