glabel bowser_2_geo_000170 # 0x0E000170
   geo_start_distance 5000
   geo_open_node
      geo_display_list 0x01, bowser_2_seg7_dl_07000FE0
   geo_close_node
   geo_end

glabel bowser_2_geo_000188 # 0x0E000188
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 1, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 20000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 11, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, bowser_2_seg7_dl_07001930
               geo_todo_17
               geo_asm 12, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
