glabel wf_geo_000BF8 # 0x0E000BF8
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
            geo_todo_0F 1, 0, 2000, 6000, 0, 2000, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, wf_seg7_dl_070050C8
               geo_display_list 0x02, wf_seg7_dl_070052B8
               geo_display_list 0x06, wf_seg7_dl_07005538
               geo_display_list 0x05, wf_seg7_dl_07005690
               geo_todo_17
               geo_asm    0, Geo18_802D01E0
               geo_asm 9217, Geo18_802D104C
               geo_asm    0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
      geo_zbuffer 0
      geo_open_node
         geo_asm 0, Geo18_802CD1E8
      geo_close_node
   geo_close_node
   geo_end
