// bubble.c.inc

void BehObjectBubbleInit(void)
{
    o->oPosX += RandomFloat() * 30.0f;
    o->oPosY += RandomFloat() * 30.0f;
    o->oPosZ += RandomFloat() * 30.0f;
}

void BehObjectBubbleLoop(void)
{
    struct Object *bubbleRipples;
    f32 waterY = find_water_level(o->oPosX, o->oPosZ);
    f32 bubbleY = o->oPosY;
    
    if (bubbleY > waterY)
    {
        if (gFreeObjectList.next)
        {
            bubbleRipples = spawn_object_at_origin(o, 0, 165, beh_object_bubble_ripples);
            bubbleRipples->oPosX = o->oPosX;
            bubbleRipples->oPosY = bubbleY + 5.0f;
            bubbleRipples->oPosZ = o->oPosZ;
        }
        
        o->activeFlags = 0;
    }
}
