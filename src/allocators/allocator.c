#include "allocator.h"

#include <stdlib.h>

Allocation allocator_allocate(const Allocator *allocator, usize size, usize alignment)
{
    // TODO: null checks/ error handling
    return allocator->allocate(allocator->allocator, size, alignment);
}

bool allocator_reallocate(const Allocator *allocator, Allocation *allocation, usize new_size)
{
    // TODO: null checks/ error handling
    return allocator->reallocate(allocator->allocator, allocation, new_size);
}

void allocator_deallocate(const Allocator *allocator, Allocation *allocation)
{
    // TODO: null checks/ error handling
    allocator->deallocate(allocator->allocator, allocation);
}

static Allocation _c_std_allocate(void *allocator, usize size, usize alignment)
{
    void *memory = malloc(size);
    Allocation allocation = {0};
    if (memory != NULL)
    {
        allocation.bytes = memory;
        allocation.size = size;
        allocation.alignment = alignment;
    }
    return allocation;
}

bool _c_std_reallocate(void *allocator, Allocation *allocation, usize new_size)
{
    void *memory = realloc(allocation->bytes, new_size);
    if (memory == NULL)
    {
        return false;
    }

    allocation->bytes = memory;
    allocation->size = new_size;
    return true;
}

void _c_std_deallocate(void *allocator, Allocation *allocation)
{
    free(allocation->bytes);
    allocation->bytes = NULL;
    allocation->size = 0;
    allocation->alignment = 0;
}

Allocator get_std_c_allocator()
{
    Allocator allocator = {0};

    allocator.allocate = _c_std_allocate;
    allocator.reallocate = _c_std_reallocate;
    allocator.deallocate = _c_std_deallocate;

    return allocator;
}