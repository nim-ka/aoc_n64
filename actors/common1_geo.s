.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

actorgeo mist
actorgeo explosion
actorgeo butterfly
actorgeo coin
actorgeo warp_pipe
actorgeo door
actorgeo bowser_key
actorgeo flame
actorgeo blue_fish
actorgeo leaves
actorgeo mario_cap

# Hmm. this geo is where power_meter normally is. Perhaps the
# power meter used to be a number very early in development, like
# a placeholder?
glabel number_geo # 0x16000E14
   geo_node_start
   geo_open_node
      geo_switch_case 10, geo_switch_anim_state
      geo_open_node
         geo_display_list LAYER_ALPHA, seg2_dl_0200F078
         geo_display_list LAYER_ALPHA, seg2_dl_0200F0A8
         geo_display_list LAYER_ALPHA, seg2_dl_0200F0D8
         geo_display_list LAYER_ALPHA, seg2_dl_0200F108
         geo_display_list LAYER_ALPHA, seg2_dl_0200F138
         geo_display_list LAYER_ALPHA, seg2_dl_0200F168
         geo_display_list LAYER_ALPHA, seg2_dl_0200F198
         geo_display_list LAYER_ALPHA, seg2_dl_0200F1C8
         geo_display_list LAYER_ALPHA, seg2_dl_0200F1F8
         geo_display_list LAYER_ALPHA, seg2_dl_0200F228
      geo_close_node
   geo_close_node
   geo_end

actorgeo mushroom_1up
actorgeo star
actorgeo dirt
actorgeo transparent_star
actorgeo snowball
actorgeo wooden_signpost
actorgeo tree
