glabel ssl_geo_0005C0 # 0x0E0005C0
   geo_start_distance 2000
   geo_open_node
      geo_asm 2049, Geo18_802D1FA8
   geo_close_node
   geo_end

glabel ssl_geo_0005D8 # 0x0E0005D8
   geo_start_distance 2000
   geo_open_node
      geo_render_range -1000, 4000
      geo_open_node
         geo_asm 2050, Geo18_802D1FA8
      geo_close_node
      geo_render_range 4000, 12800
      geo_open_node
         geo_display_list 0x01, ssl_seg7_dl_07004AE0
      geo_close_node
   geo_close_node
   geo_end

glabel ssl_geo_000618 # 0x0E000618
   geo_start_distance 1000
   geo_open_node
      geo_display_list 0x01, ssl_seg7_dl_0700BF18
   geo_close_node
   geo_end

glabel ssl_geo_000630 # 0x0E000630
   geo_start_distance 4000
   geo_open_node
      geo_display_list 0x01, ssl_seg7_dl_0700FCE0
   geo_close_node
   geo_end

glabel ssl_geo_000648 # 0x0E000648
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 5, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 20000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 1, 0, 2000, 6000, -2048, 0, -1024, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, ssl_seg7_dl_07009F48
               geo_display_list 0x01, ssl_seg7_dl_0700BA78
               geo_display_list 0x04, ssl_seg7_dl_0700BC18
               geo_display_list 0x06, ssl_seg7_dl_0700BD00
               geo_asm 2049, Geo18_802D2108
               geo_asm    0, Geo18_802D01E0
               geo_asm 2049, Geo18_802D104C
               geo_asm 2129, Geo18_802D104C
               geo_asm 2049, Geo18_802D1CDC
               geo_asm 2050, Geo18_802D1CDC
               geo_asm 2051, Geo18_802D1CDC
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

glabel ssl_geo_000734 # 0x0E000734
   geo_start_distance 700
   geo_open_node
      geo_shadow SHADOW_SQUARE_SCALABLE, 0xB4, 550
      geo_open_node
         geo_display_list 0x01, ssl_seg7_dl_070220A8
         geo_display_list 0x04, ssl_seg7_dl_070221E8
      geo_close_node
   geo_close_node
   geo_end

glabel ssl_geo_000764 # 0x0E000764
   geo_start_distance 550
   geo_open_node
      geo_shadow 0x00 + SHADOW_RECTANGLE_HARDCODED_OFFSET, 0xB4, 0
      geo_open_node
         geo_display_list 0x01, ssl_seg7_dl_070228A8
         geo_display_list 0x04, ssl_seg7_dl_070229E8
      geo_close_node
   geo_close_node
   geo_end

glabel ssl_geo_000794 # 0x0E000794
   geo_start_distance 700
   geo_open_node
      geo_display_list 0x01, ssl_seg7_dl_07022CF8
   geo_close_node
   geo_end

glabel ssl_geo_0007AC # 0x0E0007AC
   geo_start_distance 900
   geo_open_node
      geo_display_list 0x01, ssl_seg7_dl_070233A8
      geo_display_list 0x04, ssl_seg7_dl_070235C0
   geo_close_node
   geo_end

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

glabel ssl_geo_00088C # 0x0E00088C
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
               geo_display_list 0x01, ssl_seg7_dl_07021A08
               geo_display_list 0x05, ssl_seg7_dl_07021DE8
               geo_todo_17
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
