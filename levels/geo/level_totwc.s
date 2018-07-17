.include "geo_commands.inc"

glabel totwc_geo_000160 # 0160
   geo_start_distance 2000
      geo_open_node
         geo_billboard
         geo_open_node
            geo_display_list 0x05, totwc_seg7_dl_070079A8
         geo_close_node
      geo_close_node
   geo_end

glabel totwc_geo_000188 # 0188
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
            geo_camera_frustum 45, 100, 25000, Geo0A_8029AA3C
            geo_open_node
               geo_todo_0F 16, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
               geo_open_node
                  geo_display_list 0x01, totwc_seg7_dl_07005D28
                  geo_display_list 0x05, totwc_seg7_dl_07007048
                  geo_display_list 0x05, totwc_seg7_dl_070078B8
                  geo_todo_17
                  geo_asm 0, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end
