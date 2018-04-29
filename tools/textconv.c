#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"
#include "utf8.h"

#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))

struct CharmapEntry
{
    uint32_t unicode;
    int bytesCount;
    uint8_t bytes[2];
};

static struct HashTable *charmap;

static void fatal_error(const char *msgfmt, ...)
{
    va_list args;

    fputs("error: ", stderr);

    va_start(args, msgfmt);
    vfprintf(stderr, msgfmt, args);
    va_end(args);

    fputc('\n', stderr);

    exit(1);
}

static void parse_error(const char *filename, int lineNum, const char *msgfmt, ...)
{
    va_list args;

    fprintf(stderr, "%s: line %i: ", filename, lineNum);

    va_start(args, msgfmt);
    vfprintf(stderr, msgfmt, args);
    va_end(args);

    fputc('\n', stderr);

    exit(1);
}

// Reads the whole file and returns a null-terminated buffer with its contents
void *read_text_file(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    uint8_t *buffer;
    size_t size;

    if (file == NULL)
        fatal_error("failed to open file '%s' for reading: %s", filename, strerror(errno));

    // get size
    fseek(file, 0, SEEK_END);
    size = ftell(file);

    // allocate buffer
    buffer = malloc(size + 1);

    // read file
    fseek(file, 0, SEEK_SET);
    if (fread(buffer, size, 1, file) != 1)
        fatal_error("error reading from file '%s': %s", filename, strerror(errno));

    // null-terminate the buffer
    buffer[size] = 0;

    fclose(file);

    return buffer;
}

static char *skip_whitespace(char *str)
{
    while (isspace(*str))
        str++;
    return str;
}

// null terminates the current line and returns a pointer to the next line
static char *line_split(char *str)
{
    while (*str != '\n')
    {
        if (*str == 0)
            return str;  // end of string
        str++;
    }
    *str = 0;  // terminate line
    return str + 1;
}

static char *parse_number(const char *str, unsigned int *num)
{
    char *endptr;
    unsigned int n = strtol(str, &endptr, 0);

    *num = n;
    if (endptr > str)
        return endptr;
    else
        return NULL;
}

static int is_identifier_char(char c)
{
    return isalnum(c) || c == '_';
}

static int get_escape_char(int c)
{
    const uint8_t escapeTable[] =
    {
        ['a'] = '\a',
        ['b'] = '\b',
        ['f'] = '\f',
        ['n'] = '\n',
        ['r'] = '\r',
        ['t'] = '\t',
        ['v'] = '\v',
        ['\\'] = '\\',
        ['\''] = '\'',
        ['"'] = '"',
    };

    if ((unsigned int)c < ARRAY_COUNT(escapeTable) && escapeTable[c] != 0)
        return escapeTable[c];
    else
        return 0;
}

static void read_charmap(const char *filename)
{
    char *filedata = read_text_file(filename);
    char *line = filedata;
    int lineNum = 1;

    while (line[0] != 0)
    {
        char *nextLine = line_split(line);

        struct CharmapEntry entry;

        line = skip_whitespace(line);
        if (line[0] != 0 && line[0] != '#')  // ignore empty lines and comments
        {
            /* Read Character */

            // opening quote
            if (*line != '\'')
                parse_error(filename, lineNum, "expected '");
            line++;

            if (*line == '\\')
            {
                line++;
                entry.unicode = get_escape_char(*line);
                if (entry.unicode == 0)
                    parse_error(filename, lineNum, "unknown escape sequence \\%c", *line);
                line++;
            }
            else
            {
                line = utf8_decode(line, &entry.unicode);
                if (line == NULL)
                    parse_error(filename, lineNum, "invalid UTF8");
            }

            // closing quote
            if (*line != '\'')
                parse_error(filename, lineNum, "expected ' after character");
            line++;

            // equals sign
            line = skip_whitespace(line);
            if (*line != '=')
                parse_error(filename, lineNum, "expected = after character");
            line++;

            entry.bytesCount = 0;

            // value
            while (1)
            {
                uint32_t value;

                if (entry.bytesCount >= 2)
                    parse_error(filename, lineNum, "more than 2 values specified");

                line = skip_whitespace(line);

                line = parse_number(line, &value);
                if (line == NULL)
                    parse_error(filename, lineNum, "expected number after =");
                if (value > 0xFF)
                    parse_error(filename, lineNum, "0x%X is larger than 1 byte", value);

                entry.bytes[entry.bytesCount] = value;
                entry.bytesCount++;

                line = skip_whitespace(line);
                if (*line == 0)
                    break;
                if (*line != ',')
                    parse_error(filename, lineNum, "junk at end of line");
                line++;
            }

            if (hashtable_query(charmap, &entry) != NULL)
                parse_error(filename, lineNum, "entry for character already exists");
            hashtable_insert(charmap, &entry);
        }

        line = nextLine;
        lineNum++;
    }

    free(filedata);
}

static int count_line_num(const char *start, const char *pos)
{
    const char *c;
    int lineNum = 1;

    for (c = start; c < pos; c++)
    {
        if (*c == '\n')
            lineNum++;
    }
    return lineNum;
}

static char *convert_string(char *pos, FILE *fout, const char *inputFileName, char *start)
{
    while (*pos != '"')
    {
        struct CharmapEntry input;
        struct CharmapEntry *entry;
        int i;
        int lineNum = count_line_num(start, pos);

        if (*pos == 0)
            parse_error(inputFileName, lineNum, "EOF in string literal");
        if (*pos == '\\')
        {
            pos++;
            input.unicode = get_escape_char(*pos);
            if (input.unicode == 0)
                parse_error(inputFileName, lineNum, "unknown escape sequence \\%c", *pos);
            pos++;
        }
        else
        {
            pos = utf8_decode(pos, &input.unicode);
            if (pos == NULL)
                parse_error(inputFileName, lineNum, "invalid unicode encountered in file");
        }
        entry = hashtable_query(charmap, &input);
        if (entry == NULL)
            parse_error(inputFileName, lineNum, "no charmap entry for U+%X", input.unicode);
        for (i = 0; i < entry->bytesCount; i++)
            fprintf(fout, "0x%02X,", entry->bytes[i]);
    }
    pos++;

    fputs("0xFF", fout);
    return pos;
}

static void convert_file(const char *infilename, const char *outfilename)
{
    char *in = read_text_file(infilename);
    FILE *fout = fopen(outfilename, "wb");

    if (fout == NULL)
        fatal_error("failed to open file '%s' for writing: %s", strerror(errno));

    char *start = in;
    char *end = in;
    char *pos = in;

    while (1)
    {
        if (*pos == 0)  // end of file
            goto eof;

        // check for comment
        if (*pos == '/')
        {
            pos++;
            // skip over // comment
            if (*pos == '/')
            {
                pos++;
                // skip over next newline
                while (*pos != '\n')
                {
                    if (*pos == 0)
                        goto eof;
                    pos++;
                }
                pos++;
            }
            // skip over /* */ comment
            else if (*pos == '*')
            {
                pos++;
                while (*pos != '*' && pos[1] != '/')
                {
                    if (*pos == 0)
                        goto eof;
                    pos++;
                }
                pos += 2;
            }
        }
        // skip over normal string literal
        else if (*pos == '"')
        {
            pos++;
            while (*pos != '"')
            {
                if (*pos == 0)
                    goto eof;
                if (*pos == '\\')
                    pos++;
                pos++;
            }
            pos++;
        }
        // check for _(" sequence
        else if (*pos == '_' && (pos == in || !is_identifier_char(pos[-1])))
        {
            end = pos;
            pos++;
            if (*pos == '(')
            {
                pos++;
                pos = skip_whitespace(pos);
                if (*pos == '"')
                {
                    pos++;
                    fwrite(start, end - start, 1, fout);
                    pos = convert_string(pos, fout, infilename, in);
                    pos = skip_whitespace(pos);
                    if (*pos != ')')
                    {
                        parse_error(infilename, count_line_num(in, pos),
                            "expected closing )");
                    }
                    pos++;
                    start = pos;
                }
            }
        }
        else
        {
            pos++;
        }
    }
    
  eof:
    fwrite(start, pos - start, 1, fout);
    fclose(fout);
    free(in);
}

static unsigned int charmap_hash(const void *value)
{
    return ((struct CharmapEntry *)value)->unicode & 0xFF;
}

static int charmap_cmp(const void *a, const void *b)
{
    return ((struct CharmapEntry *)a)->unicode == ((struct CharmapEntry *)b)->unicode;
}

static void usage(const char *execName)
{
    fprintf(stderr, "Usage: %s CHARMAP INPUT OUTPUT\n", execName);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        usage(argv[0]);
        return 1;
    }

    charmap = hashtable_new(charmap_hash, charmap_cmp, 256, sizeof(struct CharmapEntry));

    read_charmap(argv[1]);
    convert_file(argv[2], argv[3]);
    
    hashtable_free(charmap);

    return 0;
}
