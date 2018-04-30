#ifndef _SAVE_FILE_H_
#define _SAVE_FILE_H_

// game progress flags
#define SAVE_FLAG_FILE_EXISTS            0x00000001
#define SAVE_FLAG_HAVE_WING_CAP          0x00000002
#define SAVE_FLAG_HAVE_METAL_CAP         0x00000004
#define SAVE_FLAG_HAVE_VANISH_CAP        0x00000008
#define SAVE_FLAG_HAVE_KEY_1             0x00000010
#define SAVE_FLAG_HAVE_KEY_2             0x00000020
#define SAVE_FLAG_UNLOCKED_BASEMENT_DOOR 0x00000040
#define SAVE_FLAG_UNLOCKED_UPSTAIRS_DOOR 0x00000080
#define SAVE_FLAG_DDD_MOVED_BACK         0x00000100
#define SAVE_FLAG_MOAT_DRAINED           0x00000200
#define SAVE_FLAG_UNLOCKED_PSS_DOOR      0x00000400
#define SAVE_FLAG_UNLOCKED_WF_DOOR       0x00000800
#define SAVE_FLAG_UNLOCKED_CCM_DOOR      0x00001000
#define SAVE_FLAG_UNLOCKED_JRB_DOOR      0x00002000
#define SAVE_FLAG_UNLOCKED_BITDW_DOOR    0x00004000
#define SAVE_FLAG_UNLOCKED_BITFS_DOOR    0x00008000
#define SAVE_FLAG_CAP_ON_GROUND          0x00010000
#define SAVE_FLAG_CAP_ON_KLEPTO          0x00020000
#define SAVE_FLAG_CAP_ON_UKIKI           0x00040000
#define SAVE_FLAG_CAP_ON_MR_BLIZZARD     0x00080000
#define SAVE_FLAG_UNLOCKED_50_STAR_DOOR  0x00100000

void save_file_do_save(s32 fileIndex);
void save_file_erase(s32 fileIndex);
void save_file_copy(s32 srcFileIndex, s32 destFileIndex);
void save_file_load_all(void);
void save_file_reload(void);
void save_file_collect_star_or_key(s16 coinScore, s16 starIndex);
s32 save_file_exists(s32 fileIndex);
s32 save_file_get_max_coin_score(s32 courseIndex);
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
void func_8027A100(u8 *a);
s32 func_8027A168(u8 *a);

#endif
