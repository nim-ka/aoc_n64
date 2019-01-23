#include <ultra64.h>

u64 __ull_rshift(u64 a0, u64 a1)
{
    return a0 >> a1;
}
u64 __ull_rem(u64 a0, u64 a1)
{
    return a0 % a1;
}
u64 __ull_div(u64 a0, u64 a1)
{ 
    return a0 / a1;
}

u64 __ll_lshift(u64 a0, u64 a1)
{
    return a0 << a1;
}

s64 __ll_rem(u64 a0, s64 a1)
{
    return a0 % a1;
}

s64 __ll_div(s64 a0, s64 a1)
{
    return a0 / a1;
}

u64 __ll_mul(u64 a0, u64 a1)
{
    return a0 * a1;
}

void __ull_divremi(u64 *div, u64 *rem, u64 a2, u16 a3)
{
    *div = a2 / a3;
    *rem = a2 % a3; 
} 
s64 __ll_mod(s64 a0, s64 a1)
{
    s64 tmp = a0 % a1;
    if ((tmp < 0 && a1 > 0) || (tmp > 0 && a1 < 0))
    {

        tmp += a1; 
    }
    return tmp;
}
 
s64 __ll_rshift(s64 a0, s64 a1)
{
    return a0 >> a1;
}
