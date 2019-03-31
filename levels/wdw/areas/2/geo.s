glabel wdw_geo_000724 # 0x0E000724
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
            geo_todo_0F 1, 0, 2000, 6000, -4352, 0, -4352, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, wdw_seg7_dl_07011E48
               geo_display_list 0x04, wdw_seg7_dl_07012258
               geo_display_list 0x06, wdw_seg7_dl_07012908
               geo_asm    0, Geo18_802D01E0
               geo_asm 4354, Geo18_802D104C
               geo_todo_17
               geo_asm    0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
