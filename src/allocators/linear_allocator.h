#ifndef __C_LIB_LINEAR_ALLOCATOR_H__
#define __C_LIB_LINEAR_ALLOCATOR_H__

#include "../common/types.h"
#include "allocator.h"

typedef struct LinearAllocator;

struct LinearAllocator
{
    usize used;
    usize size;
    u8 *base;
};

Allocator linear_allocator_get_allocator(const LinearAllocator *linear_allocator);

LinearAllocator linear_allocator_init(void *buffer, usize buffer_size);

#endif // __C_LIB_LINEAR_ALLOCATOR_H__