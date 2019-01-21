glabel sa_geo_000170 # 0x0E000170
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
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 1, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, sa_seg7_dl_07002DE8
               geo_display_list 0x05, sa_seg7_dl_07002FD0
               geo_todo_17
               geo_asm 2, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
