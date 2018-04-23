#ifndef _MATH_UTIL_H_
#define _MATH_UTIL_H_

void *Vec3f_Copy(Vec3f dest, Vec3f src);
void *Vec3f_Set(Vec3f dest, float x, float y, float z);
void *Vec3f_Add(Vec3f dest, Vec3f a);
void *Vec3f_Sum(Vec3f dest, Vec3f a, Vec3f b);
void *Vec3s_Copy(Vec3s dest, Vec3s src);
void *Vec3s_Set(Vec3s dest, s16 x, s16 y, s16 z);
void *Vec3s_Add(Vec3s dest, Vec3s a);
void *Vec3s_Sum(Vec3s dest, Vec3s a, Vec3s b);
void *Vec3s_Sub(Vec3s dest, Vec3s a);
void *Vec3sToVec3f(Vec3f dest, Vec3s a);
void *Vec3fToVec3s(Vec3s dest, Vec3f a);
void *func_80378C50(Vec3f dest, Vec3f a, Vec3f b, Vec3f c);
void *Vec3f_CrossProd(Vec3f dest, Vec3f a, Vec3f b);
void *Vec3f_Normalize(Vec3f dest);
void Mtx_Copy(float dest[4][4], float src[4][4]);
void Mtx_Identity(float mtx[4][4]);
void func_80378F24(float a[4][4], Vec3f b);
void func_80378F84(float mtx[4][4], Vec3f b, Vec3f c, s16 d);
void func_80379440(float mtx[4][4], Vec3f b, Vec3s c);
void func_803795F0(float mtx[4][4], Vec3f b, u16 *c);
void func_80379798(float mtx1[4][4], float mtx2[4][4], Vec3f c, s16 d);
void func_80379918(float mtx[4][4], Vec3f b, Vec3f c, s16 d);
void func_80379AA4(float mtx[4][4], Vec3f b, s16 c, float d);
void Mtx_Mul(float dest[4][4], float a[4][4], float b[4][4]);
void func_8037A29C(float a[4][4], float b[4][4], Vec3f c);
void Unknown8037A348(float a[4][4], Vec3s b);
void func_8037A434(s16 *a, float b[4][4]);
void func_8037A4B8(s16 *a, s16 b);
void func_8037A550(Vec3f a, float b[4][4], float c[4][4]);
void func_8037A69C(Vec3f a, Vec3f b, float *c, s16 *d, s16 *e);
void func_8037A788(Vec3f a, Vec3f b, float c, s16 d, s16 e);
int approach_int(int a, int b, int c, int d);
float approach_float(float a, float b, float c, float d);
u16 func_8037A924(float a, float b);
s16 func_8037A9A8(float a, float b);
float Unknown8037AB88(float a, float b);
void func_8037ABEC(Vec4f a, float b, UNUSED int c);
void func_8037AFB8(Vec4s *a);
int func_8037AFE8(Vec3f a);

#endif
