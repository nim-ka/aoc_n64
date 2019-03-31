glabel jrb_geo_000A18 # 0x0E000A18
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 8, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 25000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 16, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x04, jrb_seg7_dl_07002FD0
               geo_display_list 0x01, jrb_seg7_dl_07004940
               geo_display_list 0x01, jrb_seg7_dl_07004C78
               geo_display_list 0x01, jrb_seg7_dl_070058C8
               geo_display_list 0x01, jrb_seg7_dl_070069B0
               geo_display_list 0x01, jrb_seg7_dl_07007570
               geo_display_list 0x04, jrb_seg7_dl_07007718
               geo_asm    0, Geo18_802D01E0
               geo_asm 4609, Geo18_802D104C
               geo_asm 4613, Geo18_802D104C
               geo_todo_17
               geo_asm   14, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
      geo_zbuffer 0
      geo_open_node
         geo_asm 0, Geo18_802CD1E8
      geo_close_node
   geo_close_node
   geo_end
