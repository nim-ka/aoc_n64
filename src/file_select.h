#ifndef _FILE_SELECT_H
#define _FILE_SELECT_H

#include "types.h"

#define MENU_LAYER_MAIN 1
#define MENU_LAYER_SUBMENU 2

enum MainMenuButtonStates {
    MENU_BUTTON_STATE_DEFAULT,
    MENU_BUTTON_STATE_GROWING,
    MENU_BUTTON_STATE_FULLSCREEN,
    MENU_BUTTON_STATE_SHRINKING,
    MENU_BUTTON_STATE_ZOOM_IN_OUT,
    MENU_BUTTON_STATE_ZOOM_IN,
    MENU_BUTTON_STATE_ZOOM_OUT
};

enum MenuButtonTypes {
    MENU_BUTTON_NONE = -1,  // no button selected (on main menu screen)

    // Main Menu (SELECT FILE)
    MENU_BUTTON_PLAY_FILE_A,
    MENU_BUTTON_PLAY_FILE_B,
    MENU_BUTTON_PLAY_FILE_C,
    MENU_BUTTON_PLAY_FILE_D,
    MENU_BUTTON_SCORE,
    MENU_BUTTON_COPY,
    MENU_BUTTON_ERASE,

    // Score Menu (CHECK FILE)
    MENU_BUTTON_SCORE_FILE_A,
    MENU_BUTTON_SCORE_FILE_B,
    MENU_BUTTON_SCORE_FILE_C,
    MENU_BUTTON_SCORE_FILE_D,
    MENU_BUTTON_SCORE_RETURN,
    MENU_BUTTON_SCORE_COPY_FILE,
    MENU_BUTTON_SCORE_ERASE_FILE,

    // Copy Menu (COPY FILE)
    MENU_BUTTON_COPY_FILE_A,
    MENU_BUTTON_COPY_FILE_B,
    MENU_BUTTON_COPY_FILE_C,
    MENU_BUTTON_COPY_FILE_D,
    MENU_BUTTON_COPY_RETURN,
    MENU_BUTTON_COPY_CHECK_SCORE,
    MENU_BUTTON_COPY_ERASE_FILE,

    // Erase Menu (ERASE FILE)
    MENU_BUTTON_ERASE_FILE_A,
    MENU_BUTTON_ERASE_FILE_B,
    MENU_BUTTON_ERASE_FILE_C,
    MENU_BUTTON_ERASE_FILE_D,
    MENU_BUTTON_ERASE_RETURN,
    MENU_BUTTON_ERASE_CHECK_SCORE,
    MENU_BUTTON_ERASE_COPY_FILE,

    // Sound Mode Menu (SOUND SELECT)
    MENU_BUTTON_SOUND_MODE,
    MENU_BUTTON_STEREO,
    MENU_BUTTON_MONO,
    MENU_BUTTON_HEADSET
};

// extern ? sCursorClickingTimer;
// extern ? sMainMenuTimer;
// extern ? D_801A7C08;
// extern ? D_801A7C0C;
// extern ? sScoreFileCoinScoreMode;
// extern ? D_801A7C74;
// extern ? xIcon;
// extern ? textNew;
// extern ? textSelectFile;
// extern ? textScore;
// extern ? textCopy;
// extern ? textErase;
// extern ? textSoundModes;
// extern ? textMarioA;
// extern ? textMarioB;
// extern ? textMarioC;
// extern ? textMarioD;
// extern ? textCheckFile;
// extern ? textNoSavedDataExists;
// extern ? textReturn;
// extern ? textCopyFileButton;
// extern ? textEraseFileButton;
// extern ? textNoFileToCopyFrom;
// extern ? textCopyFile;
// extern ? textCopyItToWhere;
// extern ? textNoSavedDataExists2;
// extern ? textCopyFinished;
// extern ? textSavedDataExists;
// extern ? textViewScore;
// extern ? D_801B98E0;
// extern ? D_801A7C04;
// extern ? D_70110038;
// extern ? textYes;
// extern ? textNo;
// extern ? D_801A7D20;
// extern ? D_801A7D28;
// extern ? D_801A7D30;
// extern ? D_801A7D44;
// extern ? D_801A7D50;
// extern ? D_801A7D64;
// extern ? D_801A7D70;
// extern ? D_801A7D74;
// extern ? D_801A7D78;
// extern ? D_801A7D7C;
// extern ? D_801A7D98;
// extern ? D_801A7D9C;
// extern ? D_801A7DA0;
// extern ? D_801A7DA8;

// extern ? beh_yellow_background_menu_init(?);
// extern ? beh_yellow_background_menu_loop(?);
// extern ? button_clicked_test(?);
// extern ? beh_menu_button_growing_from_main_menu(?);
// extern ? beh_menu_button_shrinking_to_main_menu(?);
// extern ? beh_menu_button_growing_from_submenu(?);
// extern ? beh_menu_button_shrinking_to_submenu(?);
// extern ? beh_menu_button_zoom_in_out(?);
// extern ? beh_menu_button_zoom_in(?);
// extern ? beh_menu_button_zoom_out(?);
// extern ? beh_menu_button_init(?);
// extern ? beh_menu_button_loop(?);
// extern ? score_menu_file_exiting(?);
// extern ? score_menu_create_buttons(?);
// extern ? score_menu_check_clicked_buttons(?);
// extern ? copy_menu_create_buttons(?);
// extern ? copy_menu_copy_file(?);
// extern ? copy_menu_check_clicked_buttons(?);
// extern ? erase_menu_create_buttons(?);
// extern ? erase_menu_erase_file(?);
// extern ? erase_menu_check_clicked_buttons(?);
// extern ? sound_mode_menu_create_buttons(?);
// extern ? sound_mode_menu_check_clicked_buttons(?);
// extern ? main_menu_file_selected(?);
// extern ? return_to_main_menu(?);
// extern ? score_menu_init_from_submenu(?);
// extern ? copy_menu_init_from_submenu(?);
// extern ? erase_menu_init_from_submenu(?);
// extern ? beh_menu_button_manager_init(?);
// extern ? main_menu_check_clicked_buttons(?);
// extern ? beh_menu_button_manager_loop(?);
// extern ? handle_button_presses(?);
// extern ? handle_controller_input(?);
// extern ? draw_cursor(?);
// extern ? menu_print_title_text(?);
// extern ? menu_print_generic_text(?);
// extern ? update_text_fade(?);
// extern ? display_file_star_count(?);
// extern ? draw_main_menu(?);
// extern ? score_menu_display_message(?);
// extern ? draw_score_menu(?);
// extern ? copy_menu_display_message(?);
// extern ? copy_menu_update_message(?);
// extern ? draw_copy_menu(?);
// extern ? erase_menu_yes_no_prompt(?);
// extern ? erase_menu_display_message(?);
// extern ? erase_menu_update_message(?);
// extern ? draw_erase_menu(?);
// extern ? draw_sound_mode_menu(?);
// extern ? score_file_print_castle_secret_stars(?);
// extern ? score_file_print_course_coin_score(?);
// extern ? score_file_print_course_star_score(?);
// extern ? draw_file_scores(?);
// extern ? draw_current_menu(?);
// extern ? Geo18_80176688(?);
// extern ? LevelProc_801766DC(?);
// extern ? LevelProc_801768A0(?);

#endif /* _FILE_SELECT_H */
