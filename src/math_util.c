#include <ultra64.h>

#include "sm64.h"

// These functions have bogus return values.
// Disable the compiler warning.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-local-addr"

void *Vec3f_Copy(Vec3f dest, Vec3f src)
{
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = src[2];
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3f_Set(Vec3f dest, float x, float y, float z)
{
    dest[0] = x;
    dest[1] = y;
    dest[2] = z;
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3f_Add(Vec3f dest, Vec3f a)
{
    dest[0] += a[0];
    dest[1] += a[1];
    dest[2] += a[2];
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3f_Sum(Vec3f dest, Vec3f a, Vec3f b)
{
    dest[0] = a[0] + b[0];
    dest[1] = a[1] + b[1];
    dest[2] = a[2] + b[2];
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3s_Copy(Vec3s dest, Vec3s src)
{
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = src[2];
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3s_Set(Vec3s dest, s16 x, s16 y, s16 z)
{
    dest[0] = x;
    dest[1] = y;
    dest[2] = z;
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3s_Add(Vec3s dest, Vec3s a)
{
    dest[0] += a[0];
    dest[1] += a[1];
    dest[2] += a[2];
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3s_Sum(Vec3s dest, Vec3s a, Vec3s b)
{
    dest[0] = a[0] + b[0];
    dest[1] = a[1] + b[1];
    dest[2] = a[2] + b[2];
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3s_Sub(Vec3s dest, Vec3s a)
{
    dest[0] -= a[0];
    dest[1] -= a[1];
    dest[2] -= a[2];
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3sToVec3f(Vec3f dest, Vec3s a)
{
    dest[0] = a[0];
    dest[1] = a[1];
    dest[2] = a[2];
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3fToVec3s(Vec3s dest, Vec3f a)
{
    // add/subtract 0.5 in order to round to the nearest int instead of truncating
    dest[0] = a[0] + ((a[0] > 0) ? 0.5f : -0.5f);
    dest[1] = a[1] + ((a[1] > 0) ? 0.5f : -0.5f);
    dest[2] = a[2] + ((a[2] > 0) ? 0.5f : -0.5f);
    return &dest;  //! warning: function returns address of local variable
}

void *func_80378C50(Vec3f dest, Vec3f a, Vec3f b, Vec3f c)
{
    dest[0] = (b[1] - a[1]) * (c[2] - b[2]) - (c[1] - b[1]) * (b[2] - a[2]);
    dest[1] = (b[2] - a[2]) * (c[0] - b[0]) - (c[2] - b[2]) * (b[0] - a[0]);
    dest[2] = (b[0] - a[0]) * (c[1] - b[1]) - (c[0] - b[0]) * (b[1] - a[1]);
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3f_CrossProd(Vec3f dest, Vec3f a, Vec3f b)
{
    dest[0] = a[1] * b[2] - b[1] * a[2];
    dest[1] = a[2] * b[0] - b[2] * a[0];
    dest[2] = a[0] * b[1] - b[0] * a[1];
    return &dest;  //! warning: function returns address of local variable
}

void *Vec3f_Normalize(Vec3f dest)
{
    float invsqrt = 1.0f / sqrtf(dest[0] * dest[0] + dest[1] * dest[1] + dest[2] * dest[2]);

    dest[0] *= invsqrt;
    dest[1] *= invsqrt;
    dest[2] *= invsqrt;
    return &dest;  //! warning: function returns address of local variable
}

#pragma GCC diagnostic pop

void Mtx_Copy(float dest[4][4], float src[4][4])
{
    register int i;
    register u32 *d = (u32 *)dest;
    register u32 *s = (u32 *)src;

    for (i = 0; i < 16; i++)
        *d++ = *s++;
}

void Mtx_Identity(float mtx[4][4])
{
    register int i;
    register float *dest;

    // initialize everything except the first and last cells to 0
    for (i = 0, dest = (float *)mtx + 1; i < 14; i++, dest += 1)
        *dest = 0;
    // initialize the diagonal cells to 1
    for (i = 0, dest = (float *)mtx;     i <  4; i++, dest += 5)
        *dest = 1;
}

void func_80378F24(float a[4][4], Vec3f b)
{
    Mtx_Identity(a);
    a[3][0] = b[0];
    a[3][1] = b[1];
    a[3][2] = b[2];
}

void func_80378F84(float mtx[4][4], Vec3f b, Vec3f c, s16 d)
{
    register float f20;
    float sp48;
    float sp44;
    float sp40;
    float sp3C;
    float sp38;
    float sp34;
    float sp30;
    float sp2C;
    float sp28;
    float sp24;
    float sp20;

    sp48 = c[0] - b[0];
    sp44 = c[2] - b[2];

    f20 = -1.0 / sqrtf(sp48 * sp48 + sp44 * sp44);
    sp48 *= f20;
    sp44 *= f20;

    sp3C = D_80387000[(u16)d >> 4];
    sp40 = D_80386000[(u16)d >> 4] * sp44;
    sp38 = -D_80386000[(u16)d >> 4] * sp48;

    sp34 = c[0] - b[0];
    sp30 = c[1] - b[1];
    sp2C = c[2] - b[2];

    f20 = -1.0 / sqrtf(sp34 * sp34 + sp30 * sp30 + sp2C * sp2C);
    sp34 *= f20;
    sp30 *= f20;
    sp2C *= f20;

    sp28 = sp3C * sp2C - sp38 * sp30;
    sp24 = sp38 * sp34 - sp40 * sp2C;
    sp20 = sp40 * sp30 - sp3C * sp34;

    f20 = 1.0 / sqrtf(sp28 * sp28 + sp24 * sp24 + sp20 * sp20);

    sp28 *= f20;
    sp24 *= f20;
    sp20 *= f20;

    sp40 = sp30 * sp20 - sp2C * sp24;
    sp3C = sp2C * sp28 - sp34 * sp20;
    sp38 = sp34 * sp24 - sp30 * sp28;

    f20 = 1.0 / sqrtf(sp40 * sp40 + sp3C * sp3C + sp38 * sp38);
    sp40 *= f20;
    sp3C *= f20;
    sp38 *= f20;

    mtx[0][0] = sp28;
    mtx[1][0] = sp24;
    mtx[2][0] = sp20;
    mtx[3][0] = -(b[0] * sp28 + b[1] * sp24 + b[2] * sp20);

    mtx[0][1] = sp40;
    mtx[1][1] = sp3C;
    mtx[2][1] = sp38;
    mtx[3][1] = -(b[0] * sp40 + b[1] * sp3C + b[2] * sp38);

    mtx[0][2] = sp34;
    mtx[1][2] = sp30;
    mtx[2][2] = sp2C;
    mtx[3][2] = -(b[0] * sp34 + b[1] * sp30 + b[2] * sp2C);

    mtx[0][3] = 0;
    mtx[1][3] = 0;
    mtx[2][3] = 0;
    mtx[3][3] = 1;
}

void func_80379440(float mtx[4][4], Vec3f b, Vec3s c)
{
    register float f12 = D_80386000[(u16) c[0] >> 4];
    register float f14 = D_80387000[(u16) c[0] >> 4];
    register float f16 = D_80386000[(u16) c[1] >> 4];
    register float f18 = D_80387000[(u16) c[1] >> 4];
    register float spC = D_80386000[(u16) c[2] >> 4];
    register float sp8 = D_80387000[(u16) c[2] >> 4];

    mtx[0][0] = f18 * sp8 + f12 * f16 * spC;
    mtx[1][0] = -f18 * spC + f12 * f16 * sp8;
    mtx[2][0] = f14 * f16;
    mtx[3][0] = b[0];

    mtx[0][1] = f14 * spC;
    mtx[1][1] = f14 * sp8;
    mtx[2][1] = -f12;
    mtx[3][1] = b[1];

    mtx[0][2] = -f16 * sp8 + f12 * f18 * spC;
    mtx[1][2] = f16 * spC + f12 * f18 * sp8;
    mtx[2][2] = f14 * f18;
    mtx[3][2] = b[2];

    mtx[0][3] = mtx[1][3] = mtx[2][3] = 0;
    mtx[3][3] = 1;
}

void func_803795F0(float mtx[4][4], Vec3f b, u16 *c)
{
    register float f12 = D_80386000[c[0] >> 4];
    register float f14 = D_80387000[c[0] >> 4];
    register float f16 = D_80386000[c[1] >> 4];
    register float f18 = D_80387000[c[1] >> 4];
    register float sp4 = D_80386000[c[2] >> 4];
    register float sp0 = D_80387000[c[2] >> 4];

    mtx[0][0] = f18 * sp0;
    mtx[0][1] = f18 * sp4;
    mtx[0][2] = -f16;
    mtx[0][3] = 0;

    mtx[1][0] = f12 * f16 * sp0 - f14 * sp4;
    mtx[1][1] = f12 * f16 * sp4 + f14 * sp0;
    mtx[1][2] = f12 * f18;
    mtx[1][3] = 0;

    mtx[2][0] = f14 * f16 * sp0 + f12 * sp4;
    mtx[2][1] = f14 * f16 * sp4 - f12 * sp0;
    mtx[2][2] = f14 * f18;
    mtx[2][3] = 0;

    mtx[3][0] = b[0];
    mtx[3][1] = b[1];
    mtx[3][2] = b[2];
    mtx[3][3] = 1;
}

void func_80379798(float mtx1[4][4], float mtx2[4][4], Vec3f c, s16 d)
{
    mtx1[0][0] = D_80387000[(u16)d >> 4];
    mtx1[0][1] = D_80386000[(u16)d >> 4];
    mtx1[0][2] = 0;
    mtx1[0][3] = 0;

    mtx1[1][0] = -mtx1[0][1];
    mtx1[1][1] = mtx1[0][0];
    mtx1[1][2] = 0;
    mtx1[1][3] = 0;

    mtx1[2][0] = 0;
    mtx1[2][1] = 0;
    mtx1[2][2] = 1;
    mtx1[2][3] = 0;

    mtx1[3][0] = mtx2[0][0] * c[0] + mtx2[1][0] * c[1] + mtx2[2][0] * c[2] + mtx2[3][0];
    mtx1[3][1] = mtx2[0][1] * c[0] + mtx2[1][1] * c[1] + mtx2[2][1] * c[2] + mtx2[3][1];
    mtx1[3][2] = mtx2[0][2] * c[0] + mtx2[1][2] * c[1] + mtx2[2][2] * c[2] + mtx2[3][2];
    mtx1[3][3] = 1;
}

void func_80379918(float mtx[4][4], Vec3f b, Vec3f c, s16 d)
{
    Vec3f sp34;
    Vec3f sp28;
    Vec3f sp1C;

    Vec3f_Set(sp34, D_80386000[(u16)d >> 4], 0, D_80387000[(u16)d >> 4]);
    Vec3f_Normalize(b);
    Vec3f_CrossProd(sp28, b, sp34);
    Vec3f_Normalize(sp28);
    Vec3f_CrossProd(sp1C, sp28, b);
    Vec3f_Normalize(sp1C);

    mtx[0][0] = sp28[0];
    mtx[0][1] = sp28[1];
    mtx[0][2] = sp28[2];

    mtx[3][0] = c[0];
    mtx[1][0] = b[0];
    mtx[1][1] = b[1];
    mtx[1][2] = b[2];
    mtx[3][1] = c[1];
    mtx[2][0] = sp1C[0];
    mtx[2][1] = sp1C[1];
    mtx[2][2] = sp1C[2];
    mtx[3][2] = c[2];
    mtx[0][3] = 0;
    mtx[1][3] = 0;
    mtx[2][3] = 0;
    mtx[3][3] = 1;
}

void func_80379AA4(float mtx[4][4], Vec3f b, s16 c, float d)
{
    struct Surface *sp74;
    Vec3f sp68;
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;
    Vec3f sp38;
    Vec3f sp2C;
    Vec3f sp20;
    float sp1C;
    float sp18 = -d * 3;

    sp68[0] = b[0] + d * D_80386000[(u16)(c + 0x2AAA) >> 4];
    sp68[2] = b[2] + d * D_80387000[(u16)(c + 0x2AAA) >> 4];
    sp5C[0] = b[0] + d * D_80386000[(u16)(c + 0x8000) >> 4];
    sp5C[2] = b[2] + d * D_80387000[(u16)(c + 0x8000) >> 4];
    sp50[0] = b[0] + d * D_80386000[(u16)(c + 0xD555) >> 4];
    sp50[2] = b[2] + d * D_80387000[(u16)(c + 0xD555) >> 4];

    sp68[1] = func_80381900(sp68[0], b[1] + 150, sp68[2], &sp74);
    sp5C[1] = func_80381900(sp5C[0], b[1] + 150, sp5C[2], &sp74);
    sp50[1] = func_80381900(sp50[0], b[1] + 150, sp50[2], &sp74);

    if (sp68[1] - b[1] < sp18)
        sp68[1] = b[1];

    if (sp5C[1] - b[1] < sp18)
        sp5C[1] = b[1];

    if (sp50[1] - b[1] < sp18)
        sp50[1] = b[1];

    sp1C = (sp68[1] + sp5C[1] + sp50[1]) / 3;

    Vec3f_Set(sp44, D_80386000[(u16)c >> 4], 0, D_80387000[(u16)c >> 4]);
    func_80378C50(sp2C, sp68, sp5C, sp50);
    Vec3f_Normalize(sp2C);
    Vec3f_CrossProd(sp38, sp2C, sp44);
    Vec3f_Normalize(sp38);
    Vec3f_CrossProd(sp20, sp38, sp2C);
    Vec3f_Normalize(sp20);

    mtx[0][0] = sp38[0];
    mtx[0][1] = sp38[1];
    mtx[0][2] = sp38[2];
    mtx[3][0] = b[0];

    mtx[1][0] = sp2C[0];
    mtx[1][1] = sp2C[1];
    mtx[1][2] = sp2C[2];
    mtx[3][1] = (sp1C < b[1]) ? b[1] : sp1C;

    mtx[2][0] = sp20[0];
    mtx[2][1] = sp20[1];
    mtx[2][2] = sp20[2];
    mtx[3][2] = b[2];

    mtx[0][3] = 0;
    mtx[1][3] = 0;
    mtx[2][3] = 0;
    mtx[3][3] = 1;
}

// Multiplies a * b, as 3x3 matrices
void Mtx_Mul(float dest[4][4], float a[4][4], float b[4][4])
{
    float temp[4][4];
    register float col0;
    register float col1;
    register float col2;

    // row 0
    col0 = a[0][0];
    col1 = a[0][1];
    col2 = a[0][2];
    temp[0][0] = col0 * b[0][0] + col1 * b[1][0] + col2 * b[2][0];
    temp[0][1] = col0 * b[0][1] + col1 * b[1][1] + col2 * b[2][1];
    temp[0][2] = col0 * b[0][2] + col1 * b[1][2] + col2 * b[2][2];

    // row 1
    col0 = a[1][0];
    col1 = a[1][1];
    col2 = a[1][2];
    temp[1][0] = col0 * b[0][0] + col1 * b[1][0] + col2 * b[2][0];
    temp[1][1] = col0 * b[0][1] + col1 * b[1][1] + col2 * b[2][1];
    temp[1][2] = col0 * b[0][2] + col1 * b[1][2] + col2 * b[2][2];

    // row 2
    col0 = a[2][0];
    col1 = a[2][1];
    col2 = a[2][2];
    temp[2][0] = col0 * b[0][0] + col1 * b[1][0] + col2 * b[2][0];
    temp[2][1] = col0 * b[0][1] + col1 * b[1][1] + col2 * b[2][1];
    temp[2][2] = col0 * b[0][2] + col1 * b[1][2] + col2 * b[2][2];

    // row 3
    col0 = a[3][0];
    col1 = a[3][1];
    col2 = a[3][2];
    temp[3][0] = col0 * b[0][0] + col1 * b[1][0] + col2 * b[2][0] + b[3][0];
    temp[3][1] = col0 * b[0][1] + col1 * b[1][1] + col2 * b[2][1] + b[3][1];
    temp[3][2] = col0 * b[0][2] + col1 * b[1][2] + col2 * b[2][2] + b[3][2];

    temp[0][3] = temp[1][3] = temp[2][3] = 0;
    temp[3][3] = 1;

    Mtx_Copy(dest, temp);
}

void func_8037A29C(float a[4][4], float b[4][4], Vec3f c)
{
    register int i;

    for (i = 0; i < 4; i++)
    {
        a[0][i] = b[0][i] * c[0];
        a[1][i] = b[1][i] * c[1];
        a[2][i] = b[2][i] * c[2];
        a[3][i] = b[3][i];
    }
}

void Unknown8037A348(float a[4][4], Vec3s b)
{
    register float f12 = b[0];
    register float f14 = b[1];
    register float f16 = b[2];

    b[0] = f12 * a[0][0] + f14 * a[1][0] + f16 * a[2][0] + a[3][0];
    b[1] = f12 * a[0][1] + f14 * a[1][1] + f16 * a[2][1] + a[3][1];
    b[2] = f12 * a[0][2] + f14 * a[1][2] + f16 * a[2][2] + a[3][2];
}

void func_8037A434(s16 *a, float b[4][4])
{
    int sp14;
    register int i;
    register s16 *a3 = a;
    register s16 *t0 = a + 16;
    register float *t1 = (float *)b;

    for (i = 0; i < 16; i++)
    {
        sp14 = *t1++ * 0x10000;
        //! endian-dependent code
        *a3++ = ((s16 *)&sp14)[0];
        *t0++ = ((s16 *)&sp14)[1];
    }
}

void func_8037A4B8(s16 *a, s16 b)
{
    float temp[4][4];

    Mtx_Identity(temp);
    temp[0][0] = D_80387000[(u16)b >> 4];
    temp[0][1] = D_80386000[(u16)b >> 4];
    temp[1][0] = -temp[0][1];
    temp[1][1] = temp[0][0];
    func_8037A434(a, temp);
}

void func_8037A550(Vec3f a, float b[4][4], float c[4][4])
{
    float spC = c[3][0] * c[0][0] + c[3][1] * c[0][1] + c[3][2] * c[0][2];
    float sp8 = c[3][0] * c[1][0] + c[3][1] * c[1][1] + c[3][2] * c[1][2];
    float sp4 = c[3][0] * c[2][0] + c[3][1] * c[2][1] + c[3][2] * c[2][2];

    a[0] = b[3][0] * c[0][0] + b[3][1] * c[0][1] + b[3][2] * c[0][2] - spC;
    a[1] = b[3][0] * c[1][0] + b[3][1] * c[1][1] + b[3][2] * c[1][2] - sp8;
    a[2] = b[3][0] * c[2][0] + b[3][1] * c[2][1] + b[3][2] * c[2][2] - sp4;
}

void func_8037A69C(Vec3f a, Vec3f b, float *c, s16 *d, s16 *e)
{
    register float f20 = b[0] - a[0];
    register float f22 = b[1] - a[1];
    register float f24 = b[2] - a[2];

    *c = sqrtf(f20 * f20 + f22 * f22 + f24 * f24);
    *d = func_8037A9A8(sqrtf(f20 * f20 + f24 * f24), f22);
    *e = func_8037A9A8(f24, f20);
}

void func_8037A788(Vec3f a, Vec3f b, float c, s16 d, s16 e)
{
    b[0] = a[0] + c * D_80387000[(u16)d >> 4] * D_80386000[(u16)e >> 4];
    b[1] = a[1] + c * D_80386000[(u16)d >> 4];
    b[2] = a[2] + c * D_80387000[(u16)d >> 4] * D_80387000[(u16)e >> 4];
}

int func_8037A860(int a, int b, int c, int d)
{
    if (a < b)
    {
        a += c;
        if (a > b)
            a = b;
    }
    else
    {
        a -= d;
        if (a < b)
            a = b;
    }
    return a;
}

float func_8037A8B4(float a, float b, float c, float d)
{
    if (a < b)
    {
        a += c;
        if (a > b)
            a = b;
    }
    else
    {
        a -= d;
        if (a < b)
            a = b;
    }
    return a;
}

u16 func_8037A924(float a, float b)
{
    u16 ret;

    if (b == 0)
        ret = D_8038B000[0];
    else
        ret = D_8038B000[(int)(a / b * 1024 + 0.5f)];
    return ret;
}

s16 func_8037A9A8(float a, float b)
{
    u16 ret;

    if (b >= 0)
    {
        if (a >= 0)
        {
            if (a >= b)
                ret = func_8037A924(b, a);
            else
                ret = 0x4000 - func_8037A924(a, b);
        }
        else
        {
            a = -a;
            if (a < b)
                ret = 0x4000 + func_8037A924(a, b);
            else
                ret = 0x8000 - func_8037A924(b, a);
        }
    }
    else
    {
        b = -b;
        if (a < 0)
        {
            a = -a;
            if (a >= b)
                ret = 0x8000 + func_8037A924(b, a);
            else
                ret = 0xC000 - func_8037A924(a, b);
        }
        else
        {
            if (a < b)
                ret = 0xC000 + func_8037A924(a, b);
            else
                ret = -func_8037A924(b, a);
        }
    }
    return ret;
}

float Unknown8037AB88(float a, float b)
{
    return (float)func_8037A9A8(a, b) * M_PI / 0x8000;
}

void func_8037ABEC(Vec4f a, float b, UNUSED int c)
{
    float sp14 = 1 - b;
    float sp10 = sp14 * sp14;
    float spC = sp10 * sp14;
    float sp8 = b * b;
    float sp4 = sp8 * b;

    switch (D_8038BC98)
    {
    case 1:
        a[0] = spC;
        a[1] = sp4 * 1.75f - sp8 * 4.5f + b * 3.0f;
        a[2] = -sp4 * 0.9166667f + sp8 * 1.5f;
        a[3] = sp4 * 0.16666667f;
        break;
    case 2:
        a[0] = spC * 0.25f;
        a[1] = sp4 * 0.5833333f - sp8 * 1.25f + b * 0.25f + 0.5833333f;
        a[2] = -sp4 * 0.5f + sp8 * 0.5f + b * 0.5f + 0.16666667f;
        a[3] = sp4 * 0.16666667f;
        break;
    case 3:
        a[0] = spC * 0.16666667f;
        a[1] = sp4 * 0.5f - sp8 + 0.6666667f;
        a[2] = -sp4 * 0.5f + sp8 * 0.5f + b * 0.5f + 0.16666667f;
        a[3] = sp4 * 0.16666667f;
        break;
    case 4:
        a[0] = spC * 0.16666667f;
        a[1] = -spC * 0.5f + sp10 * 0.5f + sp14 * 0.5f + 0.16666667f;
        a[2] = spC * 0.5833333f - sp10 * 1.25f + sp14 * 0.25f + 0.5833333f;
        a[3] = sp4 * 0.25f;
        break;
    case 5:
        a[0] = spC * 0.16666667f;
        a[1] = -spC * 0.9166667f + sp10 * 1.5f;
        a[2] = spC * 1.75f - sp10 * 4.5f + sp14 * 3.0f;
        a[3] = sp4;
        break;
    }
}

void func_8037AFB8(Vec4s *a)
{
    D_8038BC90 = a;
    D_8038BC94 = 0;
    D_8038BC98 = 1;
}

int func_8037AFE8(Vec3f a)
{
    Vec4f sp30;
    int i;
    int sp28 = 0;

    Vec3f_Copy(a, D_80385FD0);
    func_8037ABEC(sp30, D_8038BC94, D_8038BC98);
    for (i = 0; i < 4; i++)
    {
        a[0] += sp30[i] * D_8038BC90[i][1];
        a[1] += sp30[i] * D_8038BC90[i][2];
        a[2] += sp30[i] * D_8038BC90[i][3];
    }
    
    if ((D_8038BC94 += D_8038BC90[0][0] / 1000.0f) >= 1)
    {
        D_8038BC90++;
        D_8038BC94--;
        switch (D_8038BC98)
        {
        case 5:
            sp28 = 1;
            break;
        case 3:
            if (D_8038BC90[2][0] == 0)
                D_8038BC98 = 4;
            break;
        default:
            D_8038BC98++;
            break;
        }
        
    }
    
    return sp28;
}
