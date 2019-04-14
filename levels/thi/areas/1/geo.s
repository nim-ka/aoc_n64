glabel thi_geo_000608 # 0x0E000608
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background BACKGROUND_OCEAN_SKY, geo_skybox_main
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 20000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 1, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list LAYER_OPAQUE, thi_seg7_dl_07005260
               geo_display_list LAYER_OPAQUE, thi_seg7_dl_07006968
               geo_display_list LAYER_ALPHA, thi_seg7_dl_07007008
               geo_display_list LAYER_TRANSPARENT, thi_seg7_dl_070072E8
               geo_display_list LAYER_TRANSPARENT_DECAL, thi_seg7_dl_070073C0
               geo_asm    0, Geo18_802D01E0
               geo_asm 4865, Geo18_802D104C
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
