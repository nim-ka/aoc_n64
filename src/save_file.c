#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"
#include "save_file.h"

#define MENU_DATA_MAGIC 0x4849
#define SAVE_FILE_MAGIC 0x4441

struct SaveBlockSignature
{
    u16 magic;
    u16 chksum;
};

struct SaveFile
{
    // location of lost cap
    // Note: the coordinates get set, but are never actually used, since the
    // cap can always be found in a fixed spot within the course
    u8 unk0;
    u8 unk1;
    Vec3s capCoords;

    u32 flags;
    u8 courseStars[25];
    u8 courseCoinScores[19];
};

struct MainMenuSaveData
{
    u32 unk0[3];
    u8 fillerC[4];
    u16 soundMode;
    u8 filler12[0x20-0x12];
};

struct SaveBuffer
{
    // Each of the four save files has two copies. If one is bad, the other is used as a backup.
    struct SaveFile files[4][2];
    // The main menu data has two copies. If one is bad, the other is used as a backup.
    struct MainMenuSaveData menuData[2];
};


u8 D_8032CE20 = 0;
u8 D_8032CE24 = 0;
s8 D_8032CE28 = 0;
s8 D_8032CE2C = 0;

// TODO: This should be defined in this file.
extern struct SaveBuffer gSaveBuffer;


static void func_80278BB0(void)
{
    UNUSED int pad;
}

static int read_eeprom_data(void *buffer, int size)
{
    int result = 0;

    if (gEepromProbe != 0)
    {
        int tries = 4;
        u32 offset = (u32)((u8 *)buffer - (u8 *)&gSaveBuffer) >> 3;

        do
        {
            tries--;
            result = osEepromLongRead(&D_80339C08, offset, buffer, size);
        } while (tries > 0 && result != 0);
    }
    return result;
}

static int write_eeprom_data(void *buffer, int size)
{
    int result = 1;

    if (gEepromProbe != 0)
    {
        int tries = 4;
        u32 offset = (u32)((u8 *)buffer - (u8 *)&gSaveBuffer) >> 3;

        do
        {
            tries--;
            result = osEepromLongWrite(&D_80339C08, offset, buffer, size);
        } while (tries > 0 && result != 0);
    }
    return result;
}

static int calc_checksum(u8 *data, int size)
{
    u16 chksum = 0;

    while (size-- > 2)
        chksum += *data++;
    return chksum;
}

// Verify the signature at the end of the block to make sure the data is valid
static int verify_save_block_signature(void *buffer, int size, u16 magic)
{
    struct SaveBlockSignature *sig = (struct SaveBlockSignature *)((size - 4) + (u8 *)buffer);

    if (sig->magic != magic)
        return FALSE;
    if (sig->chksum != calc_checksum(buffer, size))
        return FALSE;
    return TRUE;
}

// Write a signature at the end of the block to make sure the data is valid
static void add_save_block_signature(void *buffer, int size, u16 magic)
{
    struct SaveBlockSignature *sig = (struct SaveBlockSignature *)((size - 4) + (u8 *)buffer);

    sig->magic = magic;
    sig->chksum = calc_checksum(buffer, size);
}

void backup_main_menu_data(int slot)
{
    int backup = slot ^ 1;

    add_save_block_signature(&gSaveBuffer.menuData[slot], sizeof(gSaveBuffer.menuData[slot]), MENU_DATA_MAGIC);
    bcopy(&gSaveBuffer.menuData[slot], &gSaveBuffer.menuData[backup], sizeof(gSaveBuffer.menuData[backup]));
    write_eeprom_data(&gSaveBuffer.menuData[backup], sizeof(gSaveBuffer.menuData[backup]));
}

void SaveMenuData(void)
{
    if (gMainMenuDataModified)
    {
        add_save_block_signature(&gSaveBuffer.menuData[0], sizeof(gSaveBuffer.menuData[0]), MENU_DATA_MAGIC);
        bcopy(&gSaveBuffer.menuData[0], &gSaveBuffer.menuData[1], sizeof(gSaveBuffer.menuData[1]));
        write_eeprom_data(gSaveBuffer.menuData, sizeof(gSaveBuffer.menuData));
        gMainMenuDataModified = FALSE;
    }
}

void func_80278F6C(void)
{
    bzero(&gSaveBuffer.menuData[0], sizeof(gSaveBuffer.menuData[0]));
    gSaveBuffer.menuData[0].unk0[0] = 0x3FFFFFFF;
    gSaveBuffer.menuData[0].unk0[1] = 0x2AAAAAAA;
    gSaveBuffer.menuData[0].unk0[2] = 0x15555555;

    gMainMenuDataModified = TRUE;
    SaveMenuData();
}

int func_80278FF0(int a, int b)
{
    return (gSaveBuffer.menuData[0].unk0[a] >> (b * 2)) & 3;
}

void func_80279024(int a, int b, int c)
{
    int sp4 = 3 << (b * 2);

    gSaveBuffer.menuData[0].unk0[a] &= ~sp4;
    gSaveBuffer.menuData[0].unk0[a] |= c << (b * 2);
}

void func_802790A0(int a, int b)
{
    int i;
    u32 sp20;
    u32 sp1C = func_80278FF0(a, b);

    if (sp1C != 0)
    {
        for (i = 0; i < 4; i++)
        {
            sp20 = func_80278FF0(i, b);
            if (sp20 < sp1C)
                func_80279024(i, b, sp20 + 1);
        }
        func_80279024(a, b, 0);
        gMainMenuDataModified = TRUE;
    }
}

void func_80279150(int a)
{
    int i;

    for (i = 0; i < 15; i++)
        func_802790A0(a, i);
}

void backup_save_file_data(int file, int slot)
{
    int backup = slot ^ 1;

    add_save_block_signature(&gSaveBuffer.files[file][slot],
                             sizeof(gSaveBuffer.files[file][slot]),
                             SAVE_FILE_MAGIC);
    bcopy(&gSaveBuffer.files[file][slot],
          &gSaveBuffer.files[file][backup],
          sizeof(gSaveBuffer.files[file][backup]));
    write_eeprom_data(&gSaveBuffer.files[file][backup], sizeof(gSaveBuffer.files[file][backup]));
}

void save_file_do_save(int file)
{
    if (gSaveFileModified)
    {
        add_save_block_signature(&gSaveBuffer.files[file][0],
                                 sizeof(gSaveBuffer.files[file][0]),
                                 SAVE_FILE_MAGIC);

        // create backup copy
        bcopy(&gSaveBuffer.files[file][0],
              &gSaveBuffer.files[file][1],
              sizeof(gSaveBuffer.files[file][1]));

        // write both slots to EEPROM
        write_eeprom_data(gSaveBuffer.files[file], sizeof(gSaveBuffer.files[file]));
        gSaveFileModified = FALSE;
    }
    SaveMenuData();
}

void save_file_erase(int file)
{
    func_80279150(file);
    bzero(&gSaveBuffer.files[file][0], sizeof(gSaveBuffer.files[file][0]));

    gSaveFileModified = TRUE;
    save_file_do_save(file);
}

void save_file_copy(int srcFile, int destFile)
{
    UNUSED int pad;

    func_80279150(destFile);
    bcopy(&gSaveBuffer.files[srcFile][0],
          &gSaveBuffer.files[destFile][0],
          sizeof(gSaveBuffer.files[destFile][0]));

    gSaveFileModified = TRUE;
    save_file_do_save(destFile);
}

void save_file_load_all(void)
{
    int file;
    int validSlots;

    gMainMenuDataModified = FALSE;
    gSaveFileModified = FALSE;

    bzero(&gSaveBuffer, sizeof(gSaveBuffer));
    read_eeprom_data(&gSaveBuffer, sizeof(gSaveBuffer));

    // Verify the main menu data and create a backup copy if only one of the slots is valid.
    validSlots = verify_save_block_signature(&gSaveBuffer.menuData[0], sizeof(gSaveBuffer.menuData[0]), MENU_DATA_MAGIC);
    validSlots |= verify_save_block_signature(&gSaveBuffer.menuData[1], sizeof(gSaveBuffer.menuData[1]), MENU_DATA_MAGIC) << 1;
    switch (validSlots)
    {
    case 0:
        func_80278F6C();
        break;
    case 1:
        backup_main_menu_data(0);
        break;
    case 2:
        backup_main_menu_data(1);
        break;
    }

    for (file = 0; file < 4; file++)
    {
        // Verify the save file and create a backup copy if only one of the slots is valid.
        validSlots = verify_save_block_signature(&gSaveBuffer.files[file][0], sizeof(gSaveBuffer.files[file][0]), SAVE_FILE_MAGIC);
        validSlots |= verify_save_block_signature(&gSaveBuffer.files[file][1], sizeof(gSaveBuffer.files[file][1]), SAVE_FILE_MAGIC) << 1;
        switch (validSlots)
        {
        case 0:
            save_file_erase(file);
            break;
        case 1:
            backup_save_file_data(file, 0);
            break;
        case 2:
            backup_save_file_data(file, 1);
            break;
        }
    }

    func_80278BB0();
}

void func_80279618(void)
{
    bcopy(&gSaveBuffer.files[gCurrSaveFileNum - 1][1],
          &gSaveBuffer.files[gCurrSaveFileNum - 1][0],
          sizeof(gSaveBuffer.files[gCurrSaveFileNum - 1][0]));

    bcopy(&gSaveBuffer.menuData[1],
          &gSaveBuffer.menuData[0],
          sizeof(gSaveBuffer.menuData[0]));

    gMainMenuDataModified = FALSE;
    gSaveFileModified = FALSE;
}

void save_file_update_coin_score(s16 coins, s16 b)
{
    int file = gCurrSaveFileNum - 1;
    int course = gCurrCourseNum - 1;
    int sp2C = 1 << b;
    UNUSED int flags = save_file_get_flags();

    D_8032CE20 = course + 1;
    D_8032CE24 = b + 1;
    D_8032CE28 = 0;
    D_8032CE2C = 0;

    if (course >= 0 && course < 15)
    {
        if (coins > ((u16)func_802798D0(course) & 0xFFFF))
            D_8032CE28 = 1;
        if (save_file_get_course_coin_score(file, course) < coins)
        {
            gSaveBuffer.files[file][0].courseCoinScores[course] = coins;
            func_802790A0(file, course);
            D_8032CE2C = 1;
            gSaveFileModified = TRUE;
        }
    }

    switch (gCurrLevelNum)
    {
    case 30:
        if (!(save_file_get_flags() & (FLAG_HAVE_KEY_1 | FLAG_UNLOCKED_BASEMENT_DOOR)))
            save_file_set_flags(FLAG_HAVE_KEY_1);
        break;
    case 33:
        if (!(save_file_get_flags() & (FLAG_HAVE_KEY_2 | FLAG_UNLOCKED_UPSTAIRS_DOOR)))
            save_file_set_flags(FLAG_HAVE_KEY_2);
        break;
    case 34:
        break;
    default:
        if (!(save_file_get_obtained_stars(file, course) & sp2C))
            save_file_set_obtained_stars(file, course, sp2C);
        break;
    }
}

int save_file_exists(int file)
{
    return (gSaveBuffer.files[file][0].flags & FLAG_FILE_EXISTS) != 0;
}

int func_802798D0(int course)
{
    int file;
    int sp38 = -1;
    int sp34 = -1;
    int sp30 = 0;

    for (file = 0; file < 4; file++)
    {
        if (save_file_get_obtained_stars(file, course) != 0)
        {
            int sp2C = save_file_get_course_coin_score(file, course);
            int sp28 = func_80278FF0(file, course);

            if (sp2C > sp38 || (sp2C == sp38 && sp28 > sp34))
            {
                sp38 = sp2C;
                sp34 = sp28;
                sp30 = file + 1;
            }
        }
    }
    return (sp30 << 16) + max(sp38, 0);
}

int save_file_get_course_star_count(int file, int course)
{
    int i;
    int count = 0;
    u8 bit = 1;
    u8 stars = save_file_get_obtained_stars(file, course);

    for (i = 0; i < 7; i++, bit <<= 1)
    {
        if (stars & bit)
            count++;
    }
    return count;
}

int save_file_get_total_star_count(int file, int minCourse, int maxCourse)
{
    int count = 0;

    // Get standard course star count.
    for (; minCourse <= maxCourse; minCourse++)
        count += save_file_get_course_star_count(file, minCourse);
    // Add castle secret star count.
    return save_file_get_course_star_count(file, -1) + count;
}

void save_file_set_flags(int flags)
{
    gSaveBuffer.files[gCurrSaveFileNum - 1][0].flags |= (flags | FLAG_FILE_EXISTS);
    gSaveFileModified = TRUE;
}

void save_file_clear_flags(int flags)
{
    gSaveBuffer.files[gCurrSaveFileNum - 1][0].flags &= ~flags;
    gSaveBuffer.files[gCurrSaveFileNum - 1][0].flags |= FLAG_FILE_EXISTS;
    gSaveFileModified = TRUE;
}

int save_file_get_flags(void)
{
    if (D_8032CE70 != 0 || gDemoInputs != NULL)
        return 0;
    return gSaveBuffer.files[gCurrSaveFileNum - 1][0].flags;
}

// Returns the bitset of obtained stars in the specified course.
// If course is -1, returns the bitset of obtained castle secret stars.
int save_file_get_obtained_stars(int file, int course)
{
    int stars;

    if (course == -1)
        stars = (gSaveBuffer.files[file][0].flags >> 24) & 0x7F;
    else
        stars = gSaveBuffer.files[file][0].courseStars[course] & 0x7F;
    return stars;
}

// Sets the bitset of obtained stars in the specified course.
// If course is -1, sets the bitset of obtained castle secret stars.
void save_file_set_obtained_stars(int file, int course, int stars)
{
    if (course == -1)
        gSaveBuffer.files[file][0].flags |= stars << 24;
    else
        gSaveBuffer.files[file][0].courseStars[course] |= stars;
    gSaveBuffer.files[file][0].flags |= FLAG_FILE_EXISTS;
    gSaveFileModified = TRUE;
}

int save_file_get_course_coin_score(int file, int course)
{
    return gSaveBuffer.files[file][0].courseCoinScores[course];
}

// Returns TRUE if the cannon is unlocked in the current course.
int save_file_is_cannon_unlocked(void)
{
    return (gSaveBuffer.files[gCurrSaveFileNum - 1][0].courseStars[gCurrCourseNum] & 0x80) != 0;
}

// Sets the cannon status to unlocked in the current course.
void save_file_set_cannon_unlocked(void)
{
    gSaveBuffer.files[gCurrSaveFileNum - 1][0].courseStars[gCurrCourseNum] |= 0x80;
    gSaveBuffer.files[gCurrSaveFileNum - 1][0].flags |= FLAG_FILE_EXISTS;
    gSaveFileModified = TRUE;
}

void save_file_set_cap_location(s16 x, s16 y, s16 z)
{
    struct SaveFile *saveFile = &gSaveBuffer.files[gCurrSaveFileNum - 1][0];

    saveFile->unk0 = gCurrLevelNum;
    saveFile->unk1 = D_8033A75A;
    Vec3s_Set(saveFile->capCoords, x, y, z);
    save_file_set_flags(FLAG_CAP_ON_GROUND);
}

int save_file_get_cap_coords(Vec3s capCoords)
{
    struct SaveFile *saveFile = &gSaveBuffer.files[gCurrSaveFileNum - 1][0];
    int flags = save_file_get_flags();

    if (saveFile->unk0 == gCurrLevelNum && saveFile->unk1 == D_8033A75A && (flags & FLAG_CAP_ON_GROUND))
    {
        Vec3s_Copy(capCoords, saveFile->capCoords);
        return TRUE;
    }
    return FALSE;
}

void save_file_set_sound_mode(u16 mode)
{
    func_80248DD8(mode);
    gSaveBuffer.menuData[0].soundMode = mode;

    gMainMenuDataModified = TRUE;
    SaveMenuData();
}

u16 save_file_get_sound_mode(void)
{
    return gSaveBuffer.menuData[0].soundMode;
}

void func_8027A024(void)
{
    if (save_file_get_flags() & FLAG_CAP_ON_GROUND)
    {
        switch (gSaveBuffer.files[gCurrSaveFileNum - 1][0].unk0)
        {
        case 8:
            save_file_set_flags(FLAG_CAP_ON_KLEPTO);
            break;
        case 10:
            save_file_set_flags(FLAG_CAP_ON_MR_BLIZZARD);
            break;
        case 36:
            save_file_set_flags(FLAG_CAP_ON_UKIKI);
            break;
        }
        save_file_clear_flags(FLAG_CAP_ON_GROUND);
    }
}

void func_8027A0E8(void)
{
    D_8033A131 = 0;
}

void func_8027A100(u8 *a)
{
    if (a[1] & 0x80)
    {
        D_8033A130 = D_8033A758;
        D_8033A131 = gCurrCourseNum;
        D_8033A132 = a[1] & 0x7F;
        D_8033A133 = a[2];
        D_8033A134 = a[3];
    }
}

int func_8027A168(u8 *a)
{
    s16 sp6 = 0;
    s16 sp4 = D_8032CE37[a[1] & 0x7F];

    if (D_8033A131 != 0 && D_8033A75C == sp4 && D_8033A130 == D_8033A758)
    {
        a[1] = D_8033A132;
        a[2] = D_8033A133;
        a[3] = D_8033A134;
        sp6 = 1;
    }
    else
    {
        D_8033A131 = 0;
    }
    return sp6;
}
