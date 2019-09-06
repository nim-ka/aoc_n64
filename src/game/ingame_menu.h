#ifndef INGAME_MENU_H
#define INGAME_MENU_H

#include "types.h"

#define MENU_MTX_PUSH   1
#define MENU_MTX_NOPUSH 2

#define MENU_SCROLL_VERTICAL   1
#define MENU_SCROLL_HORIZONTAL 2

#define HUD_STR_JPMENU 1
#define HUD_STR_GLOBAL 2

#define RENDER_PAUSE_SCREEN       1
#define RENDER_COURSE_DONE_SCREEN 2


extern s8 gDialogCourseActNum;
extern s8 gHudFlash;

struct DialogEntry
{
 /*0x00*/ u32 unused;
 /*0x04*/ s8 linesPerBox;
 /*0x06*/ s16 leftOffset;
 /*0x08*/ s16 width;
 /*0x0C*/ u8 *str;
};

enum HudFontType {
    FONT_JAPANESE = 1,
    FONT_ENGLISH
};

extern s32 gDialogResponse;
extern u16 gDialogColorFadeTimer;
extern s8 gLastDialogLineNum;
extern s32 gDialogVariable;
extern u16 gDialogTextAlpha;
extern s16 gCutsceneMsgXOffset;
extern s16 gCutsceneMsgYOffset;
extern s8 gRedCoinsCollected;

extern void create_dl_identity_matrix(void);
extern void create_dl_translation_matrix(s8 pushOp, f32 x, f32 y, f32 z);
extern void create_dl_ortho_matrix(void);
extern void print_generic_string(s16 x, s16 y, const u8 *str);
extern void print_hud_lut_string(s8 fontLut, s16 x, s16 y, const u8 *str);
extern void print_menu_generic_string(s16 x, s16 y, const u8 *str);
extern void handle_menu_scrolling(s8 scrollDirection, s8 *currentIndex, s8 minIndex, s8 maxIndex);
#if defined(VERSION_US) || defined(VERSION_EU)
extern s16 get_str_x_pos_from_center(s16 centerPos, u8 *str, f32 scale);
#endif
#if defined(VERSION_JP) || defined(VERSION_EU)
#ifdef VERSION_JP
// remap JP get_str_x_pos_from_center() calls to get_str_x_pos_from_center_scale()
#define get_str_x_pos_from_center get_str_x_pos_from_center_scale
#endif
extern s16 get_str_x_pos_from_center_scale(s16 centerPos, u8 *str, f32 scale);
#endif
extern void print_hud_my_score_coins(s32 useCourseCoinScore, s8 fileNum, s8 courseNum, s16 x, s16 y);
extern void int_to_str(s32 num, u8 *dst);
extern s16 get_dialog_id(void);
extern void create_dialog_box(s16 dialog);
extern void create_dialog_box_with_var(s16 dialog, s32 dialogVar);
extern void create_dialog_inverted_box(s16 dialog);
extern void create_dialog_box_with_response(s16 dialog);
extern void reset_dialog_render_state(void);
extern void set_menu_mode(s16 mode);
extern void reset_cutscene_msg_fade(void);
extern void start_dl_rgba16_cutscene_msg_fade(void);
extern void stop_dl_rgba16_cutscene_msg_fade(void);
extern void print_credits_str_ascii(s16 x, s16 y, const char *str);
extern void set_cutscene_message(s16 xOffset, s16 yOffset, s16 msgIndex, s16 msgDuration);
extern void do_cutscene_handler(void);
extern void render_hud_cannon_reticle(void);
extern void reset_red_coins_collected(void);
extern s16 render_menus_and_dialogs(void);

#endif /* INGAME_MENU_H */
