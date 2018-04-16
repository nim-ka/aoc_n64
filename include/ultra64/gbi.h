#ifndef _ULTRA64_GBI_H_
#define _ULTRA64_GBI_H_

/* Types */

typedef struct
{
    unsigned int w0;
    unsigned int w1;
} Gwords;

/* TODO: fill in the rest of the members */
typedef union
{
    Gwords words;
    long long int force_structure_alignment;
} Gfx;

#endif
