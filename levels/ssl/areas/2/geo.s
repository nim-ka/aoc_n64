glabel ssl_geo_0007CC # 0x0E0007CC
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
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 4, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, ssl_seg7_dl_0701EE80
               geo_display_list 0x04, ssl_seg7_dl_0701F920
               geo_display_list 0x06, ssl_seg7_dl_0701FCE0
               geo_asm 2050, Geo18_802D2108
               geo_asm    0, Geo18_802D01E0
               geo_asm 2049, Geo18_802D1B70
               geo_asm 2050, Geo18_802D1B70
               geo_asm 2051, Geo18_802D1B70
               geo_todo_17
               geo_asm    0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
