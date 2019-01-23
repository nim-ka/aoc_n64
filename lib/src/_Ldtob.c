#include <ultra64.h>
#include <stdlib.h>
#include "printf.h"
#define BUFF_LEN 0x20
s16 _Ldunscale(s16 *, printf_struct *);
void _Genld(printf_struct *, u8, u8 *, s16, s16);
const double D_80338670[] = {10e0L, 10e1L, 10e3L, 10e7L, 10e15L, 10e31L, 10e63L, 10e127L, 10e255L};

const u8 D_803386B8[] = "NaN";
const u8 D_803386BC[] = "Inf";
const u8 D_803386C0[] = "0"; //(0x3000000000000000);
typedef union {
    struct
    {
        u32 upper;
        u32 lower;
    } i;
    f64 d;
} du;
const du D_803386C8 = {0x4197d784, 0x00000000}; //10.0e8;

/* float properties */
#define _D0 0
#define _DBIAS 0x3ff
#define _DLONG 1
#define _DOFF 4
#define _FBIAS 0x7e
#define _FOFF 7
#define _FRND 1
#define _LBIAS 0x3ffe
#define _LOFF 15
/* integer properties */
#define _C2 1
#define _CSIGN 1
#define _ILONG 0
#define _MBMAX 8
#define NAN 2
#define INF 1
#define FINITE -1
#define _DFRAC ((1 << _DOFF) - 1)
#define _DMASK (0x7fff & ~_DFRAC)
#define _DMAX ((1 << (15 - _DOFF)) - 1)
#define _DNAN (0x8000 | _DMAX << _DOFF | 1 << (_DOFF - 1))
#define _DSIGN 0x8000
#if _D0 == 3
#define _D1 2 /* little-endian order */
#define _D2 1
#define _D3 0
#else
#define _D1 1 /* big-endian order */
#define _D2 2
#define _D3 3
#endif
void _Ldtob(printf_struct *args, u8 type)
{
    u8 sp78[BUFF_LEN];
    u8 *sp74;
    u32 sp70;
    f64 sp68;
    /* maybe struct? */
    s16 sp66;
    s16 sp64;
    s16 sp62;

    s32 sp5c;
    s32 sp58;
    f64 sp50;
    s32 sp4c;
    s32 sp48;
    s32 sp44;
    ldiv_t sp3c;
    u8 sp3b;
    s32 sp34;
    /* */
    u8 unused[0x4];
    sp74 = sp78;
    sp68 = args->value.f64;
    if (args->precision < 0)
    {
        args->precision = 6;
    }
    else
    {
        if (args->precision == 0 && (type == 'g' || type == 'G'))
        {
            args->precision = 1;
        }
    }
    sp66 = _Ldunscale(&sp62, args);
    if (sp66 > 0)
    {
        memcpy(args->buff, sp66 == 2 ? D_803386B8 : D_803386BC, args->part2_len = 3);
        return;
    }
    if (sp66 == 0)
    {
        sp64 = 0;
        sp62 = 0;
    }
    else
    {
        if (sp68 < 0)
            sp68 = -sp68;
        sp62 = sp62 * 30103 / 0x000186A0 - 4;
        if (sp62 < 0)
        {
            sp58 = (3 - sp62) & ~3;
            sp62 = -sp58;
            for (sp5c = 0; sp58 > 0; sp58 >>= 1, sp5c++)
            {
                if ((sp58 & 1) != 0)
                {
                    sp68 *= D_80338670[sp5c];
                }
            }
        }
        else
        {
            if (sp62 > 0)
            {
                sp50 = 1;
                sp62 &= ~3;
                sp58 = sp62;

                for (sp5c = 0; sp58 > 0; sp58 >>= 1, sp5c++)
                {
                    if (sp58 & 1 != 0)
                    {
                        sp50 *= D_80338670[sp5c];
                    }
                }
                sp68 /= sp50;
            }
        }
        sp4c = ((type == 'f') ? sp62 + 10 : 6) + args->precision;
        if (sp4c > 0x13)
            sp4c = 0x13;
        *sp74++ = '0';
        while (sp4c > 0 && 0 < sp68)
        {
            sp44 = sp68;
            if ((sp4c -= 8) > 0)
            {
                sp68 = (sp68 - sp44) * D_803386C8.d;
            }
            sp74 = sp74 + 8;
            for (sp48 = 8; sp44 > 0 && --sp48 >= 0;)
            {
                sp3c = ldiv(sp44, 10);
                *--sp74 = sp3c.rem + '0';
                sp44 = sp3c.quot;
            }
            while (--sp48 >= 0)
            {
                sp74--;
                *sp74 = '0';
            }
            sp74 += 8;
        }

        sp4c = sp74 - &sp78[1];
        for (sp74 = &sp78[1], sp62 += 7; *sp74 == '0'; sp74++)
        {
            --sp4c, --sp62;
        }
        
        sp64 = ((type == 'f') ? sp62 + 1 : ((type == 'e' || type == 'E') ? 1 : 0)) + args->precision;
        if (sp4c < sp64)
            sp64 = sp4c;
        if (sp64 > 0)
        {
            if (sp64 < sp4c && sp74[sp64] > '4')
                sp3b = '9';
            else
                sp3b = '0';

            for (sp34 = sp64; sp74[--sp34] == sp3b;)
            {
                sp64--;
            }
            if (sp3b == '9')
            {
                sp74[sp34]++;
            }
            if (sp34 < 0)
            {
                --sp74, ++sp64,
                    ++sp62;
            }
        }
    }
    _Genld(args, type, sp74, sp64, sp62);
}

s16 _Ldunscale(s16 *pex, printf_struct *px)
{

    unsigned short *ps = (unsigned short *)px;
    short xchar = (ps[_D0] & _DMASK) >> _DOFF;
    if (xchar == _DMAX)
    { /* NaN or INF */
        *pex = 0;
        return (s16)(ps[_D0] & _DFRAC || ps[_D1] || ps[_D2] || ps[_D3] ? NAN : INF);
    }
    else if (0 < xchar)
    {
        ps[_D0] = ps[_D0] & ~_DMASK | _DBIAS << _DOFF;
        *pex = xchar - (_DBIAS - 1);
        return (FINITE);
    }
    if (0 > xchar)
        return NAN;
    else
    {
        *pex = 0;
        return (0);
    }
}
void _Genld(printf_struct *px, u8 code, u8 *p, s16 nsig, s16 xexp)
{
    u8 point = '.';
    if (nsig <= 0)
        nsig = 1,

        p = D_803386C0;

    if (code == 'f' || (code == 'g' || code == 'G') && -4 <= xexp && xexp < px->precision)
    {           /* 'f' format */
        ++xexp; /* change to leading digit count */
        if (code != 'f')
        { /* fixup for 'g' */
            if (!(px->flags & FLAGS_HASH) && nsig < px->precision)
                px->precision = nsig;
            if ((px->precision -= xexp) < 0)
                px->precision = 0;
        }
        if (xexp <= 0)
        { /* digits only to right of point */
            px->buff[px->part2_len++] = '0';
            if (0 < px->precision || px->flags & FLAGS_HASH)
                px->buff[px->part2_len++] = point;
            if (px->precision < -xexp)
                xexp = -px->precision;
            px->num_mid_zeros = -xexp;
            px->precision += xexp;
            if (px->precision < nsig)
                nsig = px->precision;
            memcpy(&px->buff[px->part2_len], p, px->part3_len = nsig);
            px->num_trailing_zeros = px->precision - nsig;
        }
        else if (nsig < xexp)
        { /* zeros before point */
            memcpy(&px->buff[px->part2_len], p, nsig);
            px->part2_len += nsig;
            px->num_mid_zeros = xexp - nsig;
            if (0 < px->precision || px->flags & FLAGS_HASH)
                px->buff[px->part2_len] = point, ++px->part3_len;
            px->num_trailing_zeros = px->precision;
        }
        else
        { /* enough digits before point */
            memcpy(&px->buff[px->part2_len], p, xexp);
            px->part2_len += xexp;
            nsig -= xexp;
            if (0 < px->precision || px->flags & FLAGS_HASH)
                px->buff[px->part2_len++] = point;
            if (px->precision < nsig)
                nsig = px->precision;
            memcpy(&px->buff[px->part2_len], p + xexp, nsig);
            px->part2_len += nsig;
            px->num_mid_zeros = px->precision - nsig;
        }
    }
    else
    { /* 'e' format */
        if (code == 'g' || code == 'G')
        { /* fixup for 'g' */
            if (nsig < px->precision)
                px->precision = nsig;
            if (--px->precision < 0)
                px->precision = 0;
            code = code == 'g' ? 'e' : 'E';
        }
        px->buff[px->part2_len++] = *p++;
        if (0 < px->precision || px->flags & FLAGS_HASH)
            px->buff[px->part2_len++] = point;
        if (0 < px->precision)
        { /* put fraction digits */
            if (px->precision < --nsig)
                nsig = px->precision;
            memcpy(&px->buff[px->part2_len], p, nsig);
            px->part2_len += nsig;
            px->num_mid_zeros = px->precision - nsig;
        }
        p = &px->buff[px->part2_len]; /* put exponent */
        *p++ = code;
        if (0 <= xexp)
            *p++ = '+';
        else
        { /* negative exponent */
            *p++ = '-';
            xexp = -xexp;
        }
        if (100 <= xexp)
        { /* put oversize exponent */
            if (1000 <= xexp)
                *p++ = xexp / 1000 + '0', xexp %= 1000;
            *p++ = xexp / 100 + '0', xexp %= 100;
        }
        *p++ = xexp / 10 + '0', xexp %= 10;
        *p++ = xexp + '0';
        px->part3_len = (u32)p - (u32)&px->buff[px->part2_len];
    }
    if ((px->flags & (FLAGS_ZERO | FLAGS_MINUS)) == FLAGS_ZERO)
    { /* pad with leading zeros */
        int n = px->part1_len + px->part2_len + px->num_mid_zeros + px->part3_len + px->num_trailing_zeros;

        if (n < px->width)
            px->num_leading_zeros = px->width - n;
    }
}
