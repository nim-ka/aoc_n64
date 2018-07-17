.include "geo_commands.inc"

glabel main_menu_geo_0001D0 # 01D0
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_07003330
            geo_display_list 0x01, main_menu_seg7_dl_070033D0
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_000200 # 0200
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_07003330
            geo_display_list 0x01, main_menu_seg7_dl_07003400
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_000230 # 0230
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_07003380
            geo_display_list 0x01, main_menu_seg7_dl_070033D0
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_000260 # 0260
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_07003380
            geo_display_list 0x01, main_menu_seg7_dl_07003400
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_000290 # 0290
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_070061C8
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_0002B8 # 02B8
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_070061F8
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_0002E0 # 02E0
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_07006228
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_000308 # 0308
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_07006258
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_000330 # 0330
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_07006288
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_000358 # 0358
   geo_node_start
      geo_open_node
         geo_scale 0x00, 524288
         geo_open_node
            geo_display_list 0x01, main_menu_seg7_dl_070062B8
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_000380 # 0380
   geo_node_screen_area 10, 160, 120, 160, 120
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
            geo_camera_frustum 45, 100, 25000
            geo_open_node
               geo_todo_0F 0, 0, 0, 1000, 0, 0, 0, 0x00000000
               geo_open_node
                  geo_todo_17
               geo_close_node
            geo_close_node
         geo_close_node
         geo_zbuffer 0
         geo_open_node
            geo_asm 0, Geo18_80176688
         geo_close_node
      geo_close_node
   geo_end

glabel main_menu_geo_000408 # 0408
   geo_node_screen_area 10, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_background 0xFFFF
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 45, 100, 25000
            geo_open_node
               geo_todo_0F 0, 0, 0, 1000, 0, 0, 0, 0x00000000
               geo_open_node
                  geo_todo_17
               geo_close_node
            geo_close_node
         geo_close_node
         geo_zbuffer 0
         geo_open_node
            geo_asm 0, Geo18_80177518
         geo_close_node
      geo_close_node
   geo_end
