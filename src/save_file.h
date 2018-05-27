#ifndef _SAVE_FILE_H_
#define _SAVE_FILE_H_

#include "types.h"
#include "level_update.h"

extern s8 gMainMenuDataModified;
extern s8 gSaveFileModified;
extern s8 D_8032CE28;
extern s8 D_8032CE2C;
extern s8 D_8032CE30;
extern u8 D_8032CE34;
extern u8 D_8033A131;
extern u8 D_8033A130;
extern u8 D_8033A132;
extern u8 D_8033A133;
extern u8 D_8033A134;

extern s8 D_8032CE37[];

// game progress flags
#define SAVE_FLAG_FILE_EXISTS            (1 << 0)
#define SAVE_FLAG_HAVE_WING_CAP          (1 << 1)
#define SAVE_FLAG_HAVE_METAL_CAP         (1 << 2)
#define SAVE_FLAG_HAVE_VANISH_CAP        (1 << 3)
#define SAVE_FLAG_HAVE_KEY_1             (1 << 4)
#define SAVE_FLAG_HAVE_KEY_2             (1 << 5)
#define SAVE_FLAG_UNLOCKED_BASEMENT_DOOR (1 << 6)
#define SAVE_FLAG_UNLOCKED_UPSTAIRS_DOOR (1 << 7)
#define SAVE_FLAG_DDD_MOVED_BACK         (1 << 8)
#define SAVE_FLAG_MOAT_DRAINED           (1 << 9)
#define SAVE_FLAG_UNLOCKED_PSS_DOOR      (1 << 10)
#define SAVE_FLAG_UNLOCKED_WF_DOOR       (1 << 11)
#define SAVE_FLAG_UNLOCKED_CCM_DOOR      (1 << 12)
#define SAVE_FLAG_UNLOCKED_JRB_DOOR      (1 << 13)
#define SAVE_FLAG_UNLOCKED_BITDW_DOOR    (1 << 14)
#define SAVE_FLAG_UNLOCKED_BITFS_DOOR    (1 << 15)
#define SAVE_FLAG_CAP_ON_GROUND          (1 << 16)
#define SAVE_FLAG_CAP_ON_KLEPTO          (1 << 17)
#define SAVE_FLAG_CAP_ON_UKIKI           (1 << 18)
#define SAVE_FLAG_CAP_ON_MR_BLIZZARD     (1 << 19)
#define SAVE_FLAG_UNLOCKED_50_STAR_DOOR  (1 << 20)

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
    COURSE_STAGES_MAX = COURSE_RR,
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
    COURSE_MAX = COURSE_CAKE_END
};

enum LevelNum
{
    LEVEL_NONE,                  // not indexed
    LEVEL_MIN,
    LEVEL_UNKNOWN_1 = LEVEL_MIN, // (1)  ""
    LEVEL_UNKNOWN_2,             // (2)  ""
    LEVEL_UNKNOWN_3,             // (3)  ""
    LEVEL_BBH,                   // (4)  "TERESA OBAKE"   Big Boo's Haunt
    LEVEL_CCM,                   // (5)  "YYAMA1 % YSLD1" Cool Cool Mountain
    LEVEL_CASTLE,                // (6)  "SELECT ROOM"    Castle lobby
    LEVEL_HMC,                   // (7)  "HORROR DUNGEON" Hazy Maze Cave
    LEVEL_SSL,                   // (8)  "SABAKU % PYRMD" Shifting Sand Land
    LEVEL_BOB,                   // (9)  "BATTLE FIELD"   Bob Omb Battlefield
    LEVEL_SL,                    // (10) "YUKIYAMA2"      Snowman's Land
    LEVEL_WDW,                   // (11) "POOL KAI"       Wet Dry World
    LEVEL_JRB,                   // (12) "WTDG % TINBOTU" Jolly Rodger's Bay
    LEVEL_THI,                   // (13) "BIG WORLD"      Tiny Huge Island
    LEVEL_TTC,                   // (14) "CLOCK TOWER"    Tick Tock Clock
    LEVEL_RR,                    // (15) "RAINBOW CRUISE" Rainbow Ride
    LEVEL_CASTLE_GROUNDS,        // (16) "MAIN MAP"       Castle grounds (outside)
    LEVEL_BITDW,                 // (17) "EXT1 YOKO SCRL" Bowser in the Dark World
    LEVEL_VCUTM,                 // (18) "EXT7 HORI MINI" Vanish Cap under the Moat
    LEVEL_BITFS,                 // (19) "EXT2 TIKA LAVA" Bowser in the Fire Sea
    LEVEL_SA,                    // (20) "EXT9 SUISOU"    Secret Aquarium
    LEVEL_BITS,                  // (21) "EXT3 HEAVEN"    Bowser in the Sky
    LEVEL_LLL,                   // (22) "FIREB1 % INVLC" Lethal Lava Land
    LEVEL_DDD,                   // (23) "WATER LAND"     Dire Dire Docks
    LEVEL_WF,                    // (24) "MOUNTAIN"       Whomp's Fortress
    LEVEL_ENDING,                // (25) "ENDING"         (Ending Cutscene)
    LEVEL_CASTLE_COURTYARD,      // (26) "URANIWA"        Castle courtyard (BBH entrance)
    LEVEL_PSS,                   // (27) "EXT4 MINI SLID" Princess's Secret Slide
    LEVEL_COTMC,                 // (28) "IN THE FALL"    Cavern of the Metal Cap
    LEVEL_TOTWC,                 // (29) "EXT6 MARIO FLY" Tower of the Wing Cap
    LEVEL_BOWSER_1,              // (30) "KUPPA1"         Bowser in the Dark World (Boss)
    LEVEL_WMOTR,                 // (31) "EXT8 BLUE SKY"  Winged Mario over the Rainbow
    LEVEL_UNKNOWN_32,            // (32) ""
    LEVEL_BOWSER_2,              // (33) "KUPPA2"         Bowser in the Fire Sea (Boss)
    LEVEL_BOWSER_3,              // (34) "KUPPA3"         Bowser in the Sky (Final Boss)
    LEVEL_UNKNOWN_35,            // (35) ""
    LEVEL_TTM,                   // (36) "DONKEY % SLID2" Tall Tall Mountain
    LEVEL_UNKNOWN_37,            // (37) ""
    LEVEL_UNKNOWN_38,            // (38) ""
    LEVEL_MAX = LEVEL_UNKNOWN_38
};

extern u8 D_8033A130;
extern u8 D_8033A131;
extern u8 D_8033A132;
extern u8 D_8033A133;
extern u8 D_8033A134;
extern s8 gMainMenuDataModified;
extern s8 gSaveFileModified;

void save_file_do_save(s32 fileIndex);
void save_file_erase(s32 fileIndex);
void save_file_copy(s32 srcFileIndex, s32 destFileIndex);
void save_file_load_all(void);
void save_file_reload(void);
void save_file_collect_star_or_key(s16 coinScore, s16 starIndex);
s32 save_file_exists(s32 fileIndex);
u32 save_file_get_max_coin_score(s32 courseIndex);
s32 save_file_get_course_star_count(s32 fileIndex, s32 courseIndex);
s32 save_file_get_total_star_count(s32 fileIndex, s32 minCourse, s32 maxCourse);
void save_file_set_flags(s32 flags);
void save_file_clear_flags(s32 flags);
s32 save_file_get_flags(void);
s32 save_file_get_star_flags(s32 fileIndex, s32 courseIndex);
void save_file_set_star_flags(s32 fileIndex, s32 courseIndex, s32 starFlags);
s32 save_file_get_course_coin_score(s32 fileIndex, s32 courseIndex);
s32 save_file_is_cannon_unlocked(void);
void save_file_set_cannon_unlocked(void);
void save_file_set_cap_pos(s16 x, s16 y, s16 z);
s32 save_file_get_cap_pos(Vec3s capPos);
void save_file_set_sound_mode(u16 mode);
u16 save_file_get_sound_mode(void);
void save_file_move_cap_to_default_location(void);
void func_8027A0E8(void);
void func_8027A100(struct WarpNode *a);
s32 func_8027A168(struct WarpNode *a);

#endif
