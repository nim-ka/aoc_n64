// 0x0E00051C
const GeoLayout ccm_geo_00051C[] = {
   GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
   GEO_OPEN_NODE(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_NODE_ORTHO(100),
         GEO_OPEN_NODE(),
            GEO_BACKGROUND(BACKGROUND_SNOW_MOUNTAINS, geo_skybox_main),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(1),
      GEO_OPEN_NODE(),
         GEO_CAMERA_FRUSTUM_WITH_FUNC(45, 100, 12800, geo_camera_fov),
         GEO_OPEN_NODE(),
            GEO_CAMERA(1, 0, 2000, 6000, 0, 0, 0, geo_camera_preset_and_pos),
            GEO_OPEN_NODE(),
               GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_seg7_dl_0700B090),
               GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_seg7_dl_0700B1D8),
               GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_seg7_dl_0700C380),
               GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_seg7_dl_0700D578),
               GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ccm_seg7_dl_0700DDF0),
               GEO_ASM(   0, geo_movtex_pause_control),
               GEO_ASM(0x0501, geo_movtex_draw_water_regions),
               GEO_RENDER_OBJ(),
               GEO_ASM(   1, geo_enfvx_main),
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

