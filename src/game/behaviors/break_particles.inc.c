// break_particles.c.inc

void func_802AD82C(s16 arg0,s16 arg1,f32 arg2,s16 arg3)
{
    struct Object* triangle;
    s32 i;
    for(i=0;i<arg0;i++)
    {
        triangle = spawn_object(o,arg1,beh_break_box_triangle);
        triangle->oAnimState = arg3;
        triangle->oPosY += 100.0f;
        triangle->oMoveAngleYaw = RandomU16();
        triangle->oFaceAngleYaw = triangle->oMoveAngleYaw;
        triangle->oFaceAnglePitch = RandomU16();
        triangle->oVelY = random_f32_around_zero(50.0f);
        if(arg1 == 138 || arg1 == 56)
        {
            triangle->oAngleVelPitch = 0xF00;
            triangle->oAngleVelYaw = 0x500;
            triangle->oForwardVel = 30.0f;
        }
        else
        {
            triangle->oAngleVelPitch = 0x80 * (s32)(RandomFloat() + 50.0f);
            triangle->oForwardVel = 30.0f;
        }
        scale_object(triangle,arg2);
    }
}
