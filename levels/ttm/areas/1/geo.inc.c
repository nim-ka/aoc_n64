// 0x0E000A70
const GeoLayout ttm_geo_000A70[] = {
   GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
   GEO_OPEN_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_NODE_ORTHO(100),
         GEO_OPEN_NODE(),
            GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(1),
      GEO_OPEN_NODE(),
         GEO_CAMERA_FRUSTUM_WITH_FUNC(45, 100, 12800, geo_camera_fov),
         GEO_OPEN_NODE(),
            GEO_CAMERA(1, 0, 2000, 6000, 0, -2200, 0, geo_camera_preset_and_pos),
            GEO_OPEN_NODE(),
               GEO_DISPLAY_LIST(LAYER_OPAQUE, ttm_seg7_dl_0700A120),
               GEO_DISPLAY_LIST(LAYER_OPAQUE, ttm_seg7_dl_0700A2E0),
               GEO_RENDER_OBJ(),
               GEO_ASM(    0, Geo18_802D5D0C),
               GEO_ASM(  512, Geo18_802D5B98),
               GEO_ASM(    0, geo_movtex_pause_control),
               GEO_ASM(0x3601, geo_movtex_draw_nocolor),
               GEO_ASM(0x3602, geo_movtex_draw_nocolor),
               GEO_ASM(0x3603, geo_movtex_draw_nocolor),
               GEO_ASM(0x3604, geo_movtex_draw_nocolor),
               GEO_ASM(0x3605, geo_movtex_draw_nocolor),
               GEO_ASM(0x3601, geo_movtex_draw_water_regions),
               GEO_ASM(    0, geo_enfvx_main),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_ASM(0, Geo18_802CD1E8),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

