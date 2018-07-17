.include "geo_commands.inc"

glabel wmotr_geo_0001F0 # 01F0
   geo_node_screen_area 10, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_background 3, Geo19_802763D4
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 45, 100, 20000, Geo0A_8029AA3C
            geo_open_node
               geo_todo_0F 16, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
               geo_open_node
                  geo_display_list 0x01, wmotr_seg7_dl_0700C1F8
                  geo_display_list 0x05, wmotr_seg7_dl_0700EFD8
                  geo_display_list 0x05, wmotr_seg7_dl_07010608
                  geo_todo_17
                  geo_asm 0, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
         geo_zbuffer 0
         geo_open_node
            geo_asm 0, Geo18_802CD1E8
         geo_close_node
      geo_close_node
   geo_end

.word 0x0
