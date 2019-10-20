// 0x07015584 - 0x07015650
const Collision ttc_seg7_collision_07015584[] = {
    COL_INIT(),
    COL_VERTEX_INIT(0xC),
    COL_VERTEX(-153, 0, -265),
    COL_VERTEX(-306, 0, 0),
    COL_VERTEX(-153, 0, 266),
    COL_VERTEX(154, 0, 266),
    COL_VERTEX(307, 0, 0),
    COL_VERTEX(154, 0, -265),
    COL_VERTEX(307, -153, 0),
    COL_VERTEX(154, -153, -265),
    COL_VERTEX(154, -153, 266),
    COL_VERTEX(-153, -153, 266),
    COL_VERTEX(-306, -153, 0),
    COL_VERTEX(-153, -153, -265),
    COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 20),
    COL_TRI(0, 1, 2),
    COL_TRI(0, 2, 3),
    COL_TRI(0, 3, 4),
    COL_TRI(0, 4, 5),
    COL_TRI(3, 6, 4),
    COL_TRI(4, 6, 7),
    COL_TRI(4, 7, 5),
    COL_TRI(3, 8, 6),
    COL_TRI(2, 8, 3),
    COL_TRI(2, 9, 8),
    COL_TRI(9, 6, 8),
    COL_TRI(9, 10, 11),
    COL_TRI(9, 11, 7),
    COL_TRI(9, 7, 6),
    COL_TRI(5, 7, 11),
    COL_TRI(5, 11, 0),
    COL_TRI(0, 10, 1),
    COL_TRI(0, 11, 10),
    COL_TRI(1, 10, 9),
    COL_TRI(1, 9, 2),
    COL_TRI_STOP(),
    COL_END(),
};

