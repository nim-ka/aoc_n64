.include "geo_commands.inc"

glabel intro_geo_0002D0 # 02D0
   geo_node_screen_area 0, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_background 0x0001
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 45, 128, 16384
            geo_open_node
               geo_todo_0F 0, 0, 0, 3200, 0, 0, 0, 0x00000000
               geo_open_node
                  geo_asm 0, geo18_title_screen
               geo_close_node
            geo_close_node
         geo_close_node
         geo_zbuffer 0
         geo_open_node
            geo_asm 0, geo18_fade_transition
         geo_close_node
      geo_close_node
   geo_end

glabel intro_geo_00035C # 035C
   geo_node_screen_area 0, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_asm 0, geo18_intro_backdrop
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 45, 128, 16384
            geo_open_node
               geo_asm 2, Geo18_802764B0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel intro_geo_0003B8 # 03B8
   geo_node_screen_area 0, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_asm 0, geo18_game_over_tile
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 45, 128, 16384
            geo_open_node
               geo_asm 3, Geo18_802764B0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel intro_geo_000414 # 0414
   geo_node_screen_area 0, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_asm 0, geo18_intro_backdrop
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 45, 128, 16384
            geo_open_node
               geo_todo_0F 0, 0, 0, 1200, 0, 0, 0, 0x00000000
               geo_open_node
                  geo_todo_11 0x01, -230, 300, 0, debug_seg7_dl_07000858
                  geo_todo_11 0x01, -120, 300, 0, debug_seg7_dl_07001100
                  geo_todo_11 0x01,  -20, 300, 0, debug_seg7_dl_07001BA0
                  geo_todo_11 0x01,  100, 300, 0, debug_seg7_dl_070025F0
                  geo_todo_11 0x01,  250, 300, 0, debug_seg7_dl_07003258
                  geo_todo_11 0x01, -310, 100, 0, debug_seg7_dl_07003DB8
                  geo_todo_11 0x01,  -90, 100, 0, debug_seg7_dl_070048C8
                  geo_todo_11 0x01,   60, 100, 0, debug_seg7_dl_07005558
                  geo_todo_11 0x01,  180, 100, 0, debug_seg7_dl_070059F8
                  geo_todo_11 0x01,  300, 100, 0, debug_seg7_dl_070063B0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

.word 0x0
