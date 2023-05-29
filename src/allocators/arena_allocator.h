#ifndef __C_LIB_ARENA_ALLOCATOR_H__
#define __C_LIB_ARENA_ALLOCATOR_H__

#include "../common/types.h"
#include "allocator.h"

typedef struct Arena;

struct Arena
{
    usize used;
    usize size;
    u8 *base;
};

Allocator arena_get_allocator(const Arena *linear_allocator);

Arena arena_init(void *buffer, usize buffer_size);

#endif // __C_LIB_ARENA_ALLOCATOR_H__