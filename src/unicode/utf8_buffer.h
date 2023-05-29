#ifndef __C_LIB_UTF8_BUFFER_H___
#define __C_LIB_UTF8_BUFFER_H___

#include "../common/types.h"

typedef struct Utf8Buffer Utf8Buffer;

struct Utf8Buffer
{
    u8 *bytes;

    usize used;
    usize capacity;
};

bool utf8_buffer_append(Utf8Buffer *buffer, u32 codepoint);
bool utf8_buffer_append_c_str(Utf8Buffer *buffer, const char *c_str);
bool utf8_buffer_append_char(Utf8Buffer *buffer, char character);
bool utf8_buffer_append_bytes(Utf8Buffer *buffer, const u8 *utf8_bytes, usize count);

usize utf8_buffer_get_char_count(Utf8Buffer *buffer);

#endif // __C_LIB_UTF8_BUFFER_H___