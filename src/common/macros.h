#ifndef __C_LIB_MACROS_H__
#define __C_LIB_MACROS_H__

#include <stddef.h>

#define ALIGN_OF(type) offsetof(struct {char x, type test}, test)

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(*array))

#endif // __C_LIB_MACROS_H__
