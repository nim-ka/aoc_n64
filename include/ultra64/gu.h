#ifndef _ULTRA64_GU_H_
#define _ULTRA64_GU_H_

/* Functions */

void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect,
    float near, float far, float scale);
void guPerspective(Mtx *m, u16 *perspNorm, float fovy, float aspect, float near,
    float far, float scale);
void guFrustum(Mtx *m, float left, float right, float bottom, float top,
    float near, float far, float scale);

#endif
