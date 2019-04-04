glabel wdw_geo_000658 # 0x0E000658
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background BACKGROUND_UNDERWATER_CITY, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 1, 0, 2000, 6000, -4352, 0, -4352, Geo0F_80287D30
            geo_open_node
               geo_display_list LAYER_OPAQUE, wdw_seg7_dl_07009AB0
               geo_display_list LAYER_ALPHA, wdw_seg7_dl_0700A138
               geo_display_list LAYER_TRANSPARENT, wdw_seg7_dl_07012798
               geo_display_list LAYER_TRANSPARENT_DECAL, wdw_seg7_dl_07012908
               geo_asm    0, Geo18_802D0080
               geo_asm    0, Geo18_802D01E0
               geo_asm 4353, Geo18_802D104C
               geo_render_obj
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
