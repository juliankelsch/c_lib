#include "allocator.h"

#include <stdlib.h>
#include <string.h>

void *allocator_allocate(const Allocator *allocator, usize size, usize alignment)
{
    return allocator->allocate(allocator->allocator, size, alignment);
}

void *allocator_allocate_zeroed(const Allocator *allocator, usize size, usize alignment)
{
    void *data = allocator_allocate(allocator, size, alignment);
    if (data != NULL)
    {
        memset(data, 0, size);
    }
    return data;
}

void *allocator_reallocate(const Allocator *allocator, void *data, usize new_size, usize alignment)
{
    return allocator->reallocate(allocator->allocator, data, new_size, alignment);
}

void allocator_deallocate(const Allocator *allocator, void *data)
{
    allocator->deallocate(allocator->allocator, data);
}

static void *_c_std_allocate(void *allocator, usize size, usize alignment)
{
    return malloc(size);
}

static void *_c_std_reallocate(void *allocator, void *data, usize new_size)
{
    return realloc(data, new_size);
}

static void _c_std_deallocate(void *allocator, void *data)
{
    free(data);
}

Allocator get_std_c_allocator()
{
    Allocator allocator = {0};

    allocator.allocate = _c_std_allocate;
    allocator.reallocate = _c_std_reallocate;
    allocator.deallocate = _c_std_deallocate;

    return allocator;
}