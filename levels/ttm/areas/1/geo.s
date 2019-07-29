glabel ttm_geo_000A70 # 0x0E000A70
   geo_node_screen_area 10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_node_ortho 100
         geo_open_node
            geo_background BACKGROUND_OCEAN_SKY, geo_skybox_main
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 12800, geo_camera_fov
         geo_open_node
            geo_camera 1, 0, 2000, 6000, 0, -2200, 0, geo_camera_preset_and_pos
            geo_open_node
               geo_display_list LAYER_OPAQUE, ttm_seg7_dl_0700A120
               geo_display_list LAYER_OPAQUE, ttm_seg7_dl_0700A2E0
               geo_render_obj
               geo_asm     0, Geo18_802D5D0C
               geo_asm   512, Geo18_802D5B98
               geo_asm     0, Geo18_802D01E0
               geo_asm 0x3601, Geo18_802D1B70
               geo_asm 0x3602, Geo18_802D1B70
               geo_asm 0x3603, Geo18_802D1B70
               geo_asm 0x3604, Geo18_802D1B70
               geo_asm 0x3605, Geo18_802D1B70
               geo_asm 0x3601, geo_exec_movtex_box
               geo_asm     0, geo_enfvx_main
            geo_close_node
         geo_close_node
      geo_close_node
      geo_zbuffer 0
      geo_open_node
         geo_asm 0, Geo18_802CD1E8
      geo_close_node
   geo_close_node
   geo_end
