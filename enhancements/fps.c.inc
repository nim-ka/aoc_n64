/*
 * Framerate counter
 * 
 * Calculates the game's current framerate by using osGetTime() and
 * prints it out on the lower left side of the screen.
 * 
 * HOW TO USE:
 * 
 * Add this include statement to the top of game.c
 *  
 * #include "../enhancements/fps.c.inc"
 * 
 * Then, at the end of the while(1) loop in the function thread5_game_loop()
 * add the function call render_fps()
 *
 * That's it! Build the rom file and press L when the game boots up 
 * to toggle the FPS counter.
 */

#define SECONDS_PER_CYCLE 0.00000002133f

#define FPS_COUNTER_X_POS 28
#define FPS_COUNTER_Y_POS 30

OSTime gLastOSTimeValue = 0;
u16 gFPS = 0;
u8 gRenderFPS = FALSE;
s8 gDelayRenderFPS = 0;

// TODO: replace this with a function that calls the asm opcode "round.w.s"
int round(float num) 
{ 
    return num + 0.5f;
} 

u16 calculate_fps_from_OSTime(OSTime diff)
{
    float fps = 1.0f / (diff * SECONDS_PER_CYCLE);
    
    return (u16)round(fps); // Round to the nearest whole integer.
}

void render_fps(void)
{
    // Toggle rendering framerate with the L button.
    if (gPlayer1Controller->buttonPressed & L_TRIG) 
    {
        gRenderFPS ^= 1;
    }
    
    if(gRenderFPS)
    {
        OSTime newTime = osGetTime();
        
        if(--gDelayRenderFPS < 0)
        {
            gFPS = calculate_fps_from_OSTime(newTime - gLastOSTimeValue);
            
            gDelayRenderFPS = 10; // Update the display 3 times per second.
        }
        
        print_text_fmt_int(FPS_COUNTER_X_POS, FPS_COUNTER_Y_POS, "FPS %d", gFPS);
        
        gLastOSTimeValue = newTime;
    }
    
}
