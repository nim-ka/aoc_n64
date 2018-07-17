.include "geo_commands.inc"

glabel geo_bitdw_0003C0 # 03C0
   geo_start_distance 2000
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_070028A0
      geo_close_node
   geo_end

glabel geo_bitdw_0003D8 # 03D8
   geo_start_distance 2300
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_070032F8
      geo_close_node
   geo_end

glabel geo_bitdw_0003F0 # 03F0
   geo_start_distance 2000
      geo_open_node
         geo_display_list 0x04, bitdw_seg7_dl_07003608
      geo_close_node
   geo_end

glabel geo_bitdw_000408 # 0408
   geo_start_distance 4000
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_07003BF0
      geo_close_node
   geo_end

glabel geo_bitdw_000420 # 0420
   geo_start_distance 3500
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_07004318
      geo_close_node
   geo_end

glabel geo_bitdw_000438 # 0438
   geo_start_distance 2500
      geo_open_node
         geo_display_list 0x04, bitdw_seg7_dl_070045C0
      geo_close_node
   geo_end

glabel geo_bitdw_000450 # 0450
   geo_start_distance 1300
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_07005078
      geo_close_node
   geo_end

glabel geo_bitdw_000468 # 0468
   geo_start_distance 2900
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_07005BC0
      geo_close_node
   geo_end

glabel geo_bitdw_000480 # 0480
   geo_start_distance 1500
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_070065F0
      geo_close_node
   geo_end

glabel geo_bitdw_000498 # 0498
   geo_start_distance 2400
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_07007AA8
      geo_close_node
   geo_end

glabel geo_bitdw_0004B0 # 04B0
   geo_start_distance 2400
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_07008FF0
      geo_close_node
   geo_end

glabel geo_bitdw_0004C8 # 04C8
   geo_start_distance 300
      geo_open_node
         geo_display_list 0x05, bitdw_seg7_dl_070093B0
      geo_close_node
   geo_end

glabel geo_bitdw_0004E0 # 04E0
   geo_start_distance 2400
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700A368
      geo_close_node
   geo_end

glabel geo_bitdw_0004F8 # 04F8
   geo_start_distance 1100
      geo_open_node
         geo_display_list 0x04, bitdw_seg7_dl_0700A6A8
      geo_close_node
   geo_end

glabel geo_bitdw_000510 # 0510
   geo_start_distance 1400
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700AD10
      geo_close_node
   geo_end

glabel geo_bitdw_000528 # 0528
   geo_start_distance 1500
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700AFA0
      geo_close_node
   geo_end

glabel geo_bitdw_000540 # 0540
   geo_start_distance 1100
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700B220
      geo_close_node
   geo_end

glabel geo_bitdw_000558 # 0558
   geo_start_distance 600
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700B480
      geo_close_node
   geo_end

glabel geo_bitdw_000570 # 0570
   geo_start_distance 600
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700B8D8
      geo_close_node
   geo_end

glabel geo_bitdw_000588 # 0588
   geo_start_distance 600
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700BB58
      geo_close_node
   geo_end

glabel geo_bitdw_0005A0 # 05A0
   geo_start_distance 2000
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700C0E0
      geo_close_node
   geo_end

glabel geo_bitdw_0005B8 # 05B8
   geo_start_distance 2000
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700C670
      geo_close_node
   geo_end

glabel geo_bitdw_0005D0 # 05D0
   geo_start_distance 2000
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700CC00
      geo_close_node
   geo_end

glabel geo_bitdw_0005E8 # 05E8
   geo_start_distance 2000
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700D190
      geo_close_node
   geo_end

glabel geo_bitdw_000600 # 0600
   geo_start_distance 2000
      geo_open_node
         geo_display_list 0x01, bitdw_seg7_dl_0700D3E8
      geo_close_node
   geo_end

glabel geo_bitdw_000618 # 0618
   geo_node_screen_area 10, 160, 120, 160, 120
      geo_open_node
         geo_zbuffer 0
         geo_open_node
            geo_todo_09 100
            geo_open_node
               geo_background 7, Geo19_802763D4
            geo_close_node
         geo_close_node
         geo_zbuffer 1
         geo_open_node
            geo_camera_frustum 45, 100, 20000, Geo0A_8029AA3C
            geo_open_node
               geo_todo_0F 14, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
               geo_open_node
                  geo_display_list 0x04, bitdw_seg7_dl_070020C8
                  geo_todo_17
                  geo_asm 0, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end
