#ifndef _SAVE_FILE_H_
#define _SAVE_FILE_H_

// game progress flags
#define FLAG_FILE_EXISTS            0x00000001
#define FLAG_HAVE_WING_CAP          0x00000002
#define FLAG_HAVE_METAL_CAP         0x00000004
#define FLAG_HAVE_VANISH_CAP        0x00000008
#define FLAG_HAVE_KEY_1             0x00000010
#define FLAG_HAVE_KEY_2             0x00000020
#define FLAG_UNLOCKED_BASEMENT_DOOR 0x00000040
#define FLAG_UNLOCKED_UPSTAIRS_DOOR 0x00000080
#define FLAG_DDD_MOVED_BACK         0x00000100
#define FLAG_MOAT_DRAINED           0x00000200
#define FLAG_UNLOCKED_PSS_DOOR      0x00000400
#define FLAG_UNLOCKED_WF_DOOR       0x00000800
#define FLAG_UNLOCKED_CCM_DOOR      0x00001000
#define FLAG_UNLOCKED_JRB_DOOR      0x00002000
#define FLAG_UNLOCKED_BITDW_DOOR    0x00004000
#define FLAG_UNLOCKED_BITFS_DOOR    0x00008000
#define FLAG_CAP_ON_GROUND          0x00010000
#define FLAG_CAP_ON_KLEPTO          0x00020000
#define FLAG_CAP_ON_UKIKI           0x00040000
#define FLAG_CAP_ON_MR_BLIZZARD     0x00080000
#define FLAG_UNLOCKED_50_STAR_DOOR  0x00100000

void backup_main_menu_data(int slot);
void SaveMenuData(void);
void func_80278F6C(void);
int func_80278FF0(int a, int b);
void func_80279024(int a, int b, int c);
void func_802790A0(int a, int b);
void func_80279150(int a);
void backup_save_file_data(int file, int slot);
void save_file_do_save(int file);
void save_file_erase(int file);
void save_file_copy(int srcFile, int destFile);
void save_file_load_all(void);
void func_80279618(void);
void save_file_collect_star_or_key(s16 coins, s16 b);
int save_file_exists(int file);
int func_802798D0(int course);
int save_file_get_course_star_count(int file, int course);
int save_file_get_total_star_count(int file, int minCourse, int maxCourse);
void save_file_set_flags(int flags);
void save_file_clear_flags(int flags);
int save_file_get_flags(void);
int save_file_get_obtained_stars(int file, int course);
void save_file_set_obtained_stars(int file, int course, int stars);
int save_file_get_course_coin_score(int file, int course);
int save_file_is_cannon_unlocked(void);
void save_file_set_cannon_unlocked(void);
void save_file_set_cap_location(s16 x, s16 y, s16 z);
int save_file_get_cap_coords(Vec3s capCoords);
void save_file_set_sound_mode(u16 mode);
u16 save_file_get_sound_mode(void);
void func_8027A024(void);
void func_8027A0E8(void);
void func_8027A100(u8 *a);
int func_8027A168(u8 *a);

#endif
