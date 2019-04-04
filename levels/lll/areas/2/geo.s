glabel lll_geo_000EC0 # 0x0E000EC0
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
            geo_todo_0F 2, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list LAYER_OPAQUE, lll_seg7_dl_070235C8
               geo_display_list LAYER_OPAQUE, lll_seg7_dl_07024C18
               geo_display_list LAYER_TRANSPARENT, lll_seg7_dl_070255D8
               geo_display_list LAYER_OPAQUE, lll_seg7_dl_07025A48
               geo_display_list LAYER_ALPHA, lll_seg7_dl_07025BD8
               geo_asm    0, Geo18_802D01E0
               geo_asm 8706, Geo18_802D1B70
               geo_asm 8706, Geo18_802D104C
               geo_render_obj
               geo_asm    0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
