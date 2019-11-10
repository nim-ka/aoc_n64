#ifndef _COURSE_TABLE_H
#define _COURSE_TABLE_H

// Please use the COURSE_ defines from level_defines.h.

enum CourseNum
{
    COURSE_NONE,                       // (0)  Overworld (Castle Grounds, etc)
    COURSE_MIN,
    /* -------------- Main Courses -------------- */
    COURSE_STAGES_MIN = COURSE_MIN,
    COURSE_BOB = COURSE_STAGES_MIN,    // (1)  Bob Omb Battlefield
    COURSE_WF,                         // (2)  Whomp's Fortress
    COURSE_JRB,                        // (3)  Jolly Rodger's Bay
    COURSE_CCM,                        // (4)  Cool Cool Mountain
    COURSE_BBH,                        // (5)  Big Boo's Haunt
    COURSE_HMC,                        // (6)  Hazy Maze Cave
    COURSE_LLL,                        // (7)  Lethal Lava Land
    COURSE_SSL,                        // (8)  Shifting Sand Land
    COURSE_DDD,                        // (9)  Dire Dire Docks
    COURSE_SL,                         // (10) Snowman's Land
    COURSE_WDW,                        // (11) Wet Dry World
    COURSE_TTM,                        // (12) Tall Tall Mountain
    COURSE_THI,                        // (13) Tiny Huge Island
    COURSE_TTC,                        // (14) Tick Tock Clock
    COURSE_RR,                         // (15) Rainbow Ride
    COURSE_BONUS_STAGES,
    COURSE_STAGES_MAX = COURSE_BONUS_STAGES - 1,
    COURSE_STAGES_COUNT = COURSE_STAGES_MAX,
    /* -------------- Bonus Courses -------------- */
    COURSE_BITDW,                      // (16) Bowser in the Dark World
    COURSE_BITFS,                      // (17) Bowser in the Fire Sea
    COURSE_BITS,                       // (18) Bowser in the Sky
    COURSE_PSS,                        // (19) Princess's Secret Slide
    COURSE_CAP_COURSES,
    COURSE_COTMC = COURSE_CAP_COURSES, // (20) Cavern of the Metal Cap
    COURSE_TOTWC,                      // (21) Tower of the Wing Cap
    COURSE_VCUTM,                      // (22) Vanish Cap Under the Moat
    COURSE_WMOTR,                      // (23) Winged Mario over the Rainbow
    COURSE_SA,                         // (24) Secret Aquarium
    COURSE_CAKE_END,                   // (25) The End (Cake Scene)
    COURSE_AFTER_END,
    COURSE_MAX = COURSE_AFTER_END - 1,
    COURSE_COUNT = COURSE_MAX
};

#define COURSE_IS_MAIN_COURSE(cmd) (cmd >= COURSE_STAGES_MIN && cmd <= COURSE_STAGES_MAX)

#endif // _COURSE_TABLE_H
