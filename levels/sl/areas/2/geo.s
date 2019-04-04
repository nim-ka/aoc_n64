glabel sl_geo_000484 # 0x0E000484
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
               geo_display_list LAYER_OPAQUE, sl_seg7_dl_0700BAE8
               geo_display_list LAYER_OPAQUE, sl_seg7_dl_0700BCF8
               geo_display_list LAYER_TRANSPARENT, sl_seg7_dl_0700C9E8
               geo_display_list LAYER_TRANSPARENT, sl_seg7_dl_0700CB58
               geo_render_obj
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
