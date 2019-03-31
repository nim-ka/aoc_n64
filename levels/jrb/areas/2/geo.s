glabel jrb_geo_000AFC # 0x0E000AFC
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
         geo_camera_frustum 45, 100, 10000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 16, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, jrb_seg7_dl_0700EF00
               geo_display_list 0x04, jrb_seg7_dl_0700FE48
               geo_display_list 0x01, jrb_seg7_dl_07010548
               geo_asm    0, Geo18_802D01E0
               geo_asm 4610, Geo18_802D104C
               geo_todo_17
               geo_asm    2, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
