.include "geo_commands.inc"

glabel ttc_geo_000240 # 0240
   geo_start_distance 410
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_0700ECB8
      geo_close_node
   geo_end

glabel ttc_geo_000258 # 0258
   geo_start_distance 410
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_0700EFE0
      geo_close_node
   geo_end

glabel ttc_geo_000270 # 0270
   geo_start_distance 1100
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_0700F760
      geo_close_node
   geo_end

glabel ttc_geo_000288 # 0288
   geo_start_distance 720
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_0700FBB8
         geo_asm 5120, Geo18_802D1E48
      geo_close_node
   geo_end

glabel ttc_geo_0002A8 # 02A8
   geo_start_distance 520
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_0700FFE8
         geo_asm 5121, Geo18_802D1E48
      geo_close_node
   geo_end

glabel ttc_geo_0002C8 # 02C8
   geo_start_distance 500
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_070102B8
      geo_close_node
   geo_end

glabel ttc_geo_0002E0 # 02E0
   geo_start_distance 400
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_07010868
      geo_close_node
   geo_end

glabel ttc_geo_0002F8 # 02F8
   geo_start_distance 520
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_07010D38
      geo_close_node
   geo_end

glabel ttc_geo_000310 # 0310
   geo_start_distance 250
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_07011040
      geo_close_node
   geo_end

glabel ttc_geo_000328 # 0328
   geo_start_distance 250
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_07011360
      geo_close_node
   geo_end

glabel ttc_geo_000340 # 0340
   geo_start_distance 380
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_070116A8
      geo_close_node
   geo_end

glabel ttc_geo_000358 # 0358
   geo_start_distance 1700
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_07011B38
      geo_close_node
   geo_end

glabel ttc_geo_000370 # 0370
   geo_start_distance 500
      geo_open_node
         geo_display_list 0x01, ttc_seg7_dl_07012028
      geo_close_node
   geo_end

glabel ttc_geo_000388 # 0388
   geo_start_distance 200
      geo_open_node
         geo_display_list 0x04, ttc_seg7_dl_07012148
      geo_close_node
   geo_end

glabel ttc_geo_0003A0 # 03A0
   geo_start_distance 300
      geo_open_node
         geo_display_list 0x04, ttc_seg7_dl_07012278
      geo_close_node
   geo_end

glabel ttc_geo_0003B8 # 03B8
   geo_node_screen_area 10, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_background 0xC7FF
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
            geo_open_node
               geo_todo_0F 2, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
               geo_open_node
                  geo_asm    0, Geo18_802D01E0
                  geo_asm 5120, Geo18_802D2108
                  geo_asm 5121, Geo18_802D2108
                  geo_display_list 0x01, ttc_seg7_dl_0700AD38
                  geo_display_list 0x05, ttc_seg7_dl_0700B1D8
                  geo_display_list 0x04, ttc_seg7_dl_0700E878
                  geo_todo_17
                  geo_asm    0, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

.word 0x0
.word 0x0
