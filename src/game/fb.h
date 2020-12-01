#ifndef _CUSTOM_H_
#define _CUSTOM_H_

extern void fb_print_char(int x, int y, char ch);
extern void fb_print_str(int x, int y, const char *str);
extern void fb_print_byte_str(int x, int y, u8 *str, int len);

extern void fb_init(void);
extern void fb_display(void);

#endif
