#ifndef _STDARG_H_
#define _STDARG_H_

#include <ultra64.h>

typedef char *va_list;

#define _VA_FP_SAVE_AREA 0x10
#define _VA_ALIGN(p,a) (((unsigned int)(((char *)p)+((a)>4?(a):4)-1)) & -((a)>4?(a):4))
#define _OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))
#define _ALIGNOF(type) _OFFSETOF (struct { char c; type member; }, member)

#define va_start(vp, parmN) (vp = ((va_list)&parmN + sizeof(parmN)))

#define __va_stack_arg(list,mode)                                 \
(                                                                 \
    ((list)=(char *)_VA_ALIGN(list, _ALIGNOF(mode))+              \
        _VA_ALIGN(sizeof(mode),4)),                               \
     (((char *)list) - (_VA_ALIGN(sizeof(mode),4) - sizeof(mode))) \
)

#define __va_double_arg(list,mode)                                                \
(                                                                                 \
    (((long)list & 0x1) /* 1 byte aligned? */                                     \
    ?(list = (char *)((long)list + 7),(char *)((long)list-6-_VA_FP_SAVE_AREA))    \
    :(((long)list & 0x2) /* 2 byte aligned? */                                    \
      ?(list = (char *)((long)list +10),(char *)((long)list-24-_VA_FP_SAVE_AREA)) \
      :__va_stack_arg(list,mode) ))                                               \
)

/* Should have a `classof` macro/intrinsic to check for '_FP' (1), 
** not just the size (which will match long..) */
#define va_arg(list,mode) ((mode*)(                   \
    (( _ALIGNOF(mode)==sizeof(double))                \
                   ? __va_double_arg(list,mode)       \
                    : __va_stack_arg(list,mode))))[-1]

#define va_end(__list)

#endif
