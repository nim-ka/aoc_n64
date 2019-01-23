#include <ultra64.h>

void *memcpy(void *src, void *dst, size_t size)
{
    //  move  $v0, $a0
    //  beqz  $a2, .L803264E4
    //   move  $v1, $a1
    //.L803264CC:
    u8 *_src = src, *_dst = dst;
    while (size > 0)
    {
        *_src++ = *_dst++;
        size--;
    }
    return src;
    //  lbu   $t6, ($v1)
    //  addiu $a2, $a2, -1
    //  addiu $v0, $v0, 1
    //  addiu $v1, $v1, 1
    //  bnez  $a2, .L803264CC
    //   sb    $t6, -1($v0)
    //.L803264E4:
    //  jr    $ra
    //   move  $v0, $a0
}

//glabel strlen
//  lbu   $t6, ($a0)
//  move  $v1, $a0
//  beqz  $t6, .L8032650C
//   nop
//  lbu   $t7, 1($v1)
//.L80326500:
//  addiu $v1, $v1, 1
//  bnezl $t7, .L80326500
//   lbu   $t7, 1($v1)
//.L8032650C:
//  jr    $ra
//   subu  $v0, $v1, $a0
size_t strlen(u8 *str)
{
    u8 *ptr = str;
    while (*ptr)
        ptr++;
    return ptr - str;
}

u8 *strchr(u8 *str, u32 ch)
{
    u8 c = ch;
    while (*str != c)
    {
        if (*str == 0)
            return NULL;
        str++;
    }
    return str;
}
//glabel strchr
//  lbu   $v1, ($a0)
//  andi  $t6, $a1, 0xff
//  andi  $v0, $a1, 0xff
//  beql  $t6, $v1, .L8032654C
//   move  $v0, $a0
//.L80326528:
//  bnezl $v1, .L8032653C
//   lbu   $v1, 1($a0)
//  jr    $ra
//   move  $v0, $zero

//  lbu   $v1, 1($a0)
//.L8032653C:
//  addiu $a0, $a0, 1
//  bne   $v0, $v1, .L80326528
//   nop
//  move  $v0, $a0
//.L8032654C:
//  jr    $ra
//   nop

//  nop
//  nop
//  nop
