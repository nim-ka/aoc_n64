glabel wdw_geo_000580 # 0x0E000580
   geo_start_distance 550
   geo_open_node
      geo_display_list 0x01, wdw_seg7_dl_07012B90
   geo_close_node
   geo_end

glabel wdw_geo_000598 # 0x0E000598
   geo_start_distance 350
   geo_open_node
      geo_shadow SHADOW_SQUARE_TOGGLABLE, 0x96, 110
      geo_open_node
         geo_display_list 0x01, wdw_seg7_dl_07012E88
      geo_close_node
   geo_close_node
   geo_end

glabel wdw_geo_0005C0 # 0x0E0005C0
   geo_start_distance 200
   geo_open_node
      geo_shadow SHADOW_SQUARE_SCALABLE, 0x96, 90
      geo_open_node
         geo_display_list 0x05, wdw_seg7_dl_070131B8
      geo_close_node
   geo_close_node
   geo_end

glabel wdw_geo_0005E8 # 0x0E0005E8
   geo_start_distance 420
   geo_open_node
      geo_shadow SHADOW_SQUARE_TOGGLABLE, 0x96, 240
      geo_open_node
         geo_display_list 0x01, wdw_seg7_dl_07013490
      geo_close_node
   geo_close_node
   geo_end

glabel wdw_geo_000610 # 0x0E000610
   geo_start_distance 800
   geo_open_node
      geo_display_list 0x01, wdw_seg7_dl_07013B70
   geo_close_node
   geo_end

glabel wdw_geo_000628 # 0x0E000628
   geo_start_distance 900
   geo_open_node
      geo_display_list 0x01, wdw_seg7_dl_07013E40
   geo_close_node
   geo_end

glabel wdw_geo_000640 # 0x0E000640
   geo_start_distance 450
   geo_open_node
      geo_display_list 0x01, wdw_seg7_dl_070140E0
   geo_close_node
   geo_end

glabel wdw_geo_000658 # 0x0E000658
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 2, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 1, 0, 2000, 6000, -4352, 0, -4352, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, wdw_seg7_dl_07009AB0
               geo_display_list 0x04, wdw_seg7_dl_0700A138
               geo_display_list 0x05, wdw_seg7_dl_07012798
               geo_display_list 0x06, wdw_seg7_dl_07012908
               geo_asm    0, Geo18_802D0080
               geo_asm    0, Geo18_802D01E0
               geo_asm 4353, Geo18_802D104C
               geo_todo_17
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
