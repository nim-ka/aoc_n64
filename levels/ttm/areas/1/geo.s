glabel ttm_geo_000A70 # 0x0E000A70
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
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 1, 0, 2000, 6000, 0, -2200, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list LAYER_OPAQUE, ttm_seg7_dl_0700A120
               geo_display_list LAYER_OPAQUE, ttm_seg7_dl_0700A2E0
               geo_render_obj
               geo_asm     0, Geo18_802D5D0C
               geo_asm   512, Geo18_802D5B98
               geo_asm     0, Geo18_802D01E0
               geo_asm 13825, Geo18_802D1B70
               geo_asm 13826, Geo18_802D1B70
               geo_asm 13827, Geo18_802D1B70
               geo_asm 13828, Geo18_802D1B70
               geo_asm 13829, Geo18_802D1B70
               geo_asm 13825, Geo18_802D104C
               geo_asm     0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
      geo_zbuffer 0
      geo_open_node
         geo_asm 0, Geo18_802CD1E8
      geo_close_node
   geo_close_node
   geo_end
