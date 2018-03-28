#ifndef PLATFORM_INFO_H
#define PLATFORM_INFO_H

#define IS_64_BIT 0
#define IS_BIG_ENDIAN 1

#define DOUBLE_SIZE_ON_64_BIT(size) ((size) * (sizeof(void *) / 4))

#endif // PLATFORM_INFO_H
