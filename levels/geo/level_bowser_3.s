.include "geo_commands.inc"

glabel bowser_3_geo_000290 # 0290
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_070022A8
      geo_close_node
   geo_end

glabel bowser_3_geo_0002A8 # 02A8
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_070025E0
      geo_close_node
   geo_end

glabel bowser_3_geo_0002C0 # 02C0
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_07002918
      geo_close_node
   geo_end

glabel bowser_3_geo_0002D8 # 02D8
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_07002C50
      geo_close_node
   geo_end

glabel bowser_3_geo_0002F0 # 02F0
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_07002F88
      geo_close_node
   geo_end

glabel bowser_3_geo_000308 # 0308
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_070032C0
      geo_close_node
   geo_end

glabel bowser_3_geo_000320 # 0320
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_070035F8
      geo_close_node
   geo_end

glabel bowser_3_geo_000338 # 0338
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_07003930
      geo_close_node
   geo_end

glabel bowser_3_geo_000350 # 0350
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_07003C68
      geo_close_node
   geo_end

glabel bowser_3_geo_000368 # 0368
   geo_start_distance 5000
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_07003FA0
      geo_close_node
   geo_end

glabel bowser_3_geo_000380 # 0380
   geo_start_distance 700
      geo_open_node
         geo_display_list 0x01, bowser_3_seg7_dl_07004958
      geo_close_node
   geo_end

glabel bowser_3_geo_000398 # 0398
   geo_node_screen_area 10, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_background 9, Geo19_802763D4
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
            geo_open_node
               geo_todo_0F 11, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
               geo_open_node
                  geo_display_list 0x01, bowser_3_seg7_dl_070046B0
                  geo_todo_17
                  geo_asm 0, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end
