glabel vcutm_geo_000208 # 0x0E000208
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
         geo_camera_frustum 45, 100, 25000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 14, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list LAYER_OPAQUE, vcutm_seg7_dl_07007E88
               geo_display_list LAYER_OPAQUE, vcutm_seg7_dl_07008E10
               geo_display_list LAYER_OPAQUE, vcutm_seg7_dl_070093E8
               geo_display_list LAYER_ALPHA, vcutm_seg7_dl_070080D0
               geo_render_obj
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
