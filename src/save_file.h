#ifndef _SAVE_FILE_H_
#define _SAVE_FILE_H_

#include "types.h"
#include "area.h"

struct WarpNode;

struct Struct8032CE34 {
    u8 specialTripleJump;
    s8 unused01;
    s8 unused02;
    s8 levelToCourseNumTable[LEVEL_MAX + 1];
};

extern u8 D_8032CE24;
extern s8 D_8032CE28;
extern u8 D_8032CE2C;
extern u8 D_8032CE30;
extern struct Struct8032CE34 D_8032CE34;

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
