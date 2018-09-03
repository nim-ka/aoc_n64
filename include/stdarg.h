#ifndef _STDARG_H_
#define _STDARG_H_

#define va_list void *
#define va_start(list, base) list = (void *)(&base + 1)
#define va_arg(list, type) *( (type *)(list = ((type *) (( ((u32) list) + sizeof(type) - 1) & -sizeof(type)) + 1)) - 1)
#define va_end(list)

#endif
