glabel ddd_geo_0004C0 # 0x0E0004C0
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 0, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 2, 0, 2000, 6000, 2560, 0, 512, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, ddd_seg7_dl_07004D48
               geo_display_list 0x01, ddd_seg7_dl_070057E8
               geo_display_list 0x04, ddd_seg7_dl_07005C40
               geo_display_list 0x05, ddd_seg7_dl_07005F78
               geo_asm    0, Geo18_802D01E0
               geo_asm 8961, Geo18_802D104C
               geo_todo_17
               geo_asm   13, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
