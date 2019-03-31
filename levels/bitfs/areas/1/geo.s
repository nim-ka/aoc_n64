glabel bitfs_geo_0007A0 # 0x0E0007A0
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
            geo_todo_0F 14, 0, 2000, 6000, 0, -4500, -8000, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x04, bitfs_seg7_dl_07002118
               geo_asm    0, Geo18_802D01E0
               geo_asm 6401, Geo18_802D1B70
               geo_asm 6402, Geo18_802D1B70
               geo_asm 6403, Geo18_802D1B70
               geo_todo_17
               geo_asm   12, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
