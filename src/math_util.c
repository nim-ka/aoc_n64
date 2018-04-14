#include <ultra64.h>

#include "sm64.h"

// These functions have bogus return values.
// Disable the compiler warning.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-local-addr"

struct Vec3f **Copy32BitTriple(struct Vec3f *dest, struct Vec3f *src)
{
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3f **func_80378840(struct Vec3f *dest, float x, float y, float z)
{
    dest->x = x;
    dest->y = y;
    dest->z = z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3f **func_8037888C(struct Vec3f *dest, struct Vec3f *a)
{
    dest->x += a->x;
    dest->y += a->y;
    dest->z += a->z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3f **Unknown803788E4(struct Vec3f *dest, struct Vec3f *a, struct Vec3f *b)
{
    dest->x = b->x + a->x;
    dest->y = b->y + a->y;
    dest->z = b->z + a->z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3s **func_8037893C(struct Vec3s *dest, struct Vec3s *src)
{
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3s **func_8037897C(struct Vec3s *dest, s16 x, s16 y, s16 z)
{
    dest->x = x;
    dest->y = y;
    dest->z = z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3s **Unknown803789C8(struct Vec3s *dest, struct Vec3s *a)
{
    dest->x += a->x;
    dest->y += a->y;
    dest->z += a->z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3s **Unknown80378A20(struct Vec3s *dest, struct Vec3s *a, struct Vec3s *b)
{
    dest->x = b->x + a->x;
    dest->y = b->y + a->y;
    dest->z = b->z + a->z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3s **Unknown80378A78(struct Vec3s *dest, struct Vec3s *a)
{
    dest->x -= a->x;
    dest->y -= a->y;
    dest->z -= a->z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3f **func_80378AD0(struct Vec3f *dest, struct Vec3s *a)
{
    dest->x = a->x;
    dest->y = a->y;
    dest->z = a->z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3s **func_80378B34(struct Vec3s *dest, struct Vec3f *a)
{
    dest->x = ((a->x > 0) ? 0.5f : -0.5f) + a->x;
    dest->y = ((a->y > 0) ? 0.5f : -0.5f) + a->y;
    dest->z = ((a->z > 0) ? 0.5f : -0.5f) + a->z;
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3f **func_80378C50(struct Vec3f *dest, struct Vec3f *a, struct Vec3f *b, struct Vec3f *c)
{
    dest->x = (b->y - a->y) * (c->z - b->z) - (b->z - a->z) * (c->y - b->y);
    dest->y = (b->z - a->z) * (c->x - b->x) - (b->x - a->x) * (c->z - b->z);
    dest->z = (b->x - a->x) * (c->y - b->y) - (b->y - a->y) * (c->x - b->x);
    return &dest;  //! warning: function returns address of local variable
}

struct Vec3f **func_80378D38(struct Vec3f *dest, struct Vec3f *a, struct Vec3f *b)
{
    dest->x = a->y * b->z - a->z * b->y;
    dest->y = a->z * b->x - a->x * b->z;
    dest->z = a->x * b->y - a->y * b->x;
    return &dest;  //! warning: function returns address of local variable
}

float **func_80378DC0(float *dest)
{
    float invsqrt = 1.0f / sqrtf(dest[0] * dest[0] + dest[1] * dest[1] + dest[2] * dest[2]);

    dest[0] *= invsqrt;
    dest[1] *= invsqrt;
    dest[2] *= invsqrt;
    return &dest;  //! warning: function returns address of local variable
}

#pragma GCC diagnostic pop

void func_80378E68(int *dest, int *src)
{
    register int i;
    register int *d = dest;
    register int *s = src;

    for (i = 0; i < 16; i++)
        *d++ = *s++;
}

void func_80378EB4(float *a)
{
    register int i;
    register float *dest;

    for (i = 0, dest = a + 1; i < 14; i++, dest += 1)
        *dest = 0.0f;
    for (i = 0, dest = a;     i <  4; i++, dest += 5)
        *dest = 1.0f;
}

void func_80378F24(float *a, float *b)
{
    func_80378EB4(a);
    a[12] = b[0];
    a[13] = b[1];
    a[14] = b[2];
}

void func_80378F84(float *a, float *b, float *c, u16 d)
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

    sp3C = D_80387000[d >> 4];
    sp40 = D_80386000[d >> 4] * sp44;
    sp38 = -D_80386000[d >> 4] * sp48;
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

    a[0] = sp28;
    a[4] = sp24;
    a[8] = sp20;
    a[12] = -(b[0] * sp28 + b[1] * sp24 + b[2] * sp20);

    a[1] = sp40;
    a[5] = sp3C;
    a[9] = sp38;
    a[13] = -(b[0] * sp40 + b[1] * sp3C + b[2] * sp38);

    a[2] = sp34;
    a[6] = sp30;
    a[10] = sp2C;
    a[14] = -(b[0] * sp34 + b[1] * sp30 + b[2] * sp2C);

    a[3] = 0.0;
    a[7] = 0.0;
    a[11] = 0.0;
    a[15] = 1.0;
}
