#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s INFILE OUTFILE\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    fseek(in, 0, SEEK_END);
    size_t size = ftell(in);
    fseek(in, 0, SEEK_SET);
    char *buffer = malloc(size);
    size_t r = fread(buffer, 1, size, in);
    if (r != size) {
        fprintf(stderr, "Failed to read file: %s\n", argv[1]);
        return 1;
    }
    fclose(in);

    if (size > 0 && size % 16 == 0) {
        static const char zeros[8] = {0};
        if (memcmp(buffer + size - 8, zeros, 8) == 0) {
            size -= 8;
        }
    }

    FILE *out = fopen(argv[2], "wb");
    fwrite(buffer, 1, size, in);
    fclose(out);

    free(buffer);
}
