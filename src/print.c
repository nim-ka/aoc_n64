#include <ultra64.h>

#include "sm64.h"
#include "game.h"
#include "mario.h"
#include "memory.h"
#include "save_file.h"
#include "main.h"
#include "surface_collision.h"
#include "transparent_texture.h"

struct TextLabel
{
    u32 x;
    u32 y;
    s16 length;
    char buffer[1];  // unknown length
};
extern struct MemoryPool *D_8033A124;
extern u8 seg2_dl_0200EC60[];
extern u8 seg2_dl_0200ECC8[];
extern u8 seg2_hud_lut[];
extern u8 seg2_dl_0200EC98[];

struct TextLabel *sTextLabels[52];

s16 sTextLabelsCount = 0;

static int int_pow(int n, int exponent)
{
    int result = 1;
    int i;

    for (i = 0; i < exponent; i++)
        result = n * result;
    return result;
}

static void format_integer(int n, int base, char *dest, int *totalLength, u8 width, s8 zeroPad)
{
    u32 powBase;
    int numDigits = 0;
    int i;
    int len = 0;
    s8 digit;
    s8 negative = FALSE;
    char pad;

    if (zeroPad == TRUE)
        pad = '0';
    else
        pad = -1;

    if (n != 0)
    {
        if (n < 0)
        {
            n = -n;
            negative = TRUE;
        }

        // calculate number of digits required
        while (1)
        {
            powBase = int_pow(base, numDigits);
            if (powBase > (u32)n)
                break;
            numDigits++;
        }

        // add leading pad
        if (width > numDigits)
        {
            for (len = 0; len < width - numDigits; len++)
                dest[len] = pad;
            if (negative == TRUE)
                len--;
        }

        if (negative == TRUE)
        {
            dest[len] = 'M';  // use 'M' prefix to indicate negative numbers
            len++;
        }

        for (i = numDigits - 1; i >= 0; i--)
        {
            powBase = int_pow(base, i);
            digit = n / powBase;
            // FIXME: Why doesn't [] match?
            if (digit < 10)
                *(dest + len + numDigits - i - 1) = digit + '0';
            else
                *(dest + len + numDigits - i - 1) = digit + '7';
            n -= digit * powBase;
        }
    }
    else  // n is zero
    {
        numDigits = 1;
        if (width > numDigits)
        {
            for (len = 0; len < width - numDigits; len++)
                dest[len] = pad;
        }
        dest[len] = '0';
    }

    *totalLength += numDigits + len;
}

static void parse_width_field(const char *str, int *srcIndex, u8 *width, s8 *zeroPad)
{
    s8 digits[12];  // unknown length
    s8 digitsLen = 0;
    s16 i;

    // if first character is 0, then the string should be zero padded
    if (str[*srcIndex] == '0')
        *zeroPad = TRUE;

    // read width digits up until the 'd' or 'x' format specifier
    while (str[*srcIndex] != 'd' && str[*srcIndex] != 'x')
    {
        digits[digitsLen] = str[*srcIndex] - '0';
        if (digits[digitsLen] < 0 || digits[digitsLen] >= 10)  // not a valid digit
        {
            *width = 0;
            return;
        }
        digitsLen++;
        (*srcIndex)++;
    }
    if (digitsLen == 0)  // no digits
        return;

    // sum the digits to calculate the total width
    for (i = 0; i < digitsLen - 1; i++)
        *width = *width + digits[i] * ((digitsLen - i - 1) * 10);
    *width = *width + digits[digitsLen - 1];
}

void print_text_fmt_int(int x, int y, const char *str, int n)
{
    char c = 0;
    s8 zeroPad = FALSE;
    u8 width = 0;
    int base = 0;
    int len = 0;
    int srcIndex = 0;

    if ((sTextLabels[sTextLabelsCount] = (struct TextLabel *)mem_pool_alloc(D_8033A124, 60)) == NULL)
        return;

    sTextLabels[sTextLabelsCount]->x = x;
    sTextLabels[sTextLabelsCount]->y = y;

    c = str[srcIndex];
    while (c != 0)
    {
        if (c == '%')
        {
            srcIndex++;
            parse_width_field(str, &srcIndex, &width, &zeroPad);
            if (str[srcIndex] != 'd' && str[srcIndex] != 'x')
                break;
            if (str[srcIndex] == 'd')
                base = 10;
            if (str[srcIndex] == 'x')
                base = 16;
            srcIndex++;
            format_integer(n, base, sTextLabels[sTextLabelsCount]->buffer + len, &len, width, zeroPad);
        }
        else  // straight copy
        {
            sTextLabels[sTextLabelsCount]->buffer[len] = c;
            len++;
            srcIndex++;
        }
        c = str[srcIndex];
    }
    sTextLabels[sTextLabelsCount]->length = len;
    sTextLabelsCount++;
}

void print_text(int x, int y, const char *str)
{
    char c = 0;
    int len = 0;
    int srcIndex = 0;

    if ((sTextLabels[sTextLabelsCount] = (struct TextLabel *)mem_pool_alloc(D_8033A124, 60)) == NULL)
        return;

    sTextLabels[sTextLabelsCount]->x = x;
    sTextLabels[sTextLabelsCount]->y = y;

    c = str[srcIndex];
    while (c != 0)
    {
        sTextLabels[sTextLabelsCount]->buffer[len] = c;
        len++;
        srcIndex++;
        c = str[srcIndex];
    }
    sTextLabels[sTextLabelsCount]->length = len;
    sTextLabelsCount++;
}

void print_text_centered(int x, int y, const char *str)
{
    char c = 0;
    UNUSED s8 sp36 = 0;
    UNUSED int sp30 = 0;
    int len = 0;
    int srcIndex = 0;
    
    if ((sTextLabels[sTextLabelsCount] = (struct TextLabel *)mem_pool_alloc(D_8033A124, 60)) == NULL)
        return;

    c = str[srcIndex];
    while (c != 0)
    {
        sTextLabels[sTextLabelsCount]->buffer[len] = c;
        len++;
        srcIndex++;
        c = str[srcIndex];
    }
    sTextLabels[sTextLabelsCount]->length = len;
    sTextLabels[sTextLabelsCount]->x = x - len * 12 / 2;
    sTextLabels[sTextLabelsCount]->y = y;
    sTextLabelsCount++;
}

static s8 char_to_glyph_index(char a)
{
    if (a >= 'A' && a <= 'Z')
        return a - 55;
    if (a >= 'a' && a <= 'z')
        return a - 87;
    if (a >= '0' && a <= '9')
        return a - 48;
    if (a == ' ')
        return -1;
    if (a == '!')
        return 36;
    if (a == '#')
        return 37;
    if (a == '?')
        return 38;
    if (a == '&')
        return 39;
    if (a == '%')
        return 40;
    if (a == '*')
        return 50;
    if (a == '+')
        return 51;
    if (a == ',')
        return 52;
    if (a == '-')
        return 53;
    if (a == '.')
        return 54;
    if (a == '/')
        return 55;
    return -1;
}

static void add_glyph_texture(s8 glyphIndex)
{
    u32 *glyphs = segmented_to_virtual(seg2_hud_lut);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, glyphs[glyphIndex]);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EC98);
}

static void func_802D5FEC(int *x, int *y)
{
    if (*x < 10)
        *x = 10;
    if (*x > 300)
        *x = 300;

    if (*y < 5)
        *y = 5;
    if (*y > 220)
        *y = 220;
}

static void func_802D605C(int x, int y, int pos)
{
    int sp34 = x + pos * 12;
    int sp30 = 224 - y;
    int sp2C;
    int sp28;

    func_802D5FEC(&sp34, &sp30);
    sp2C = sp34;
    sp28 = sp30;
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xE4000000
                    | ((((sp2C + 15) << 2) & 0xFFF) << 12)
                    | (((sp28 + 15) << 2) & 0xFFF);
        g->words.w1 = (((sp2C << 2) & 0xFFF) << 12) | ((sp28 << 2) & 0xFFF);
    }
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB3000000;
        g->words.w1 = 0;
    }
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB2000000;
        g->words.w1 = 0x10000400;
    }
}

void func_802D61A8(void)
{
    int i;
    int j;
    s8 glyphIndex;
    Mtx *mtx;

    if (sTextLabelsCount == 0)
        return;
    mtx = alloc_display_list(sizeof(*mtx));
    if (mtx == NULL)
    {
        sTextLabelsCount = 0;
        return;
    }
    guOrtho(mtx, 0.0f, 320.0f, 0.0f, 240.0f, -10.0f, 10.0f, 1.0f);
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0xB4000000;
        g->words.w1 = 0xFFFF;
    }
    {
        Gfx *g = gDisplayListHead++;
        g->words.w0 = 0x01030040;
        g->words.w1 = VIRTUAL_TO_PHYSICAL(mtx);
    }
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EC60);

    for (i = 0; i < sTextLabelsCount; i++)
    {
        for (j = 0; j < sTextLabels[i]->length; j++)
        {
            glyphIndex = char_to_glyph_index(sTextLabels[i]->buffer[j]);
            if (glyphIndex != -1)
            {
                add_glyph_texture(glyphIndex);
                func_802D605C(sTextLabels[i]->x, sTextLabels[i]->y, j);
            }
        }
        mem_pool_free(D_8033A124, (void *)sTextLabels[i]);
    }
    
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ECC8);

    sTextLabelsCount = 0;
}
