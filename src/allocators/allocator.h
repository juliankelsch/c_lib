#ifndef __C_LIB_ALLOCATOR_H__
#define __C_LIB_ALLOCATOR_H__

#include "../common/types.h"
#include "../common/macros.h"

typedef struct Allocator Allocator;

typedef struct Allocation Allocation;

struct Allocation
{
    u8 *bytes;
    usize size;
    usize alignment;
};

// Requests [size] number of bytes from the allocator aligned to [alignment].
typedef Allocation AllocationFunc(void *allocator, usize size, usize alignment);
typedef bool ReallocationFunc(void *allocator, Allocation *allocation, usize new_size);
typedef void DeallocationFunc(void *allocator, Allocation *allocation);

struct Allocator
{
    void *allocator;
    AllocationFunc *allocate;
    ReallocationFunc *reallocate;
    DeallocationFunc *deallocate;
};

Allocator get_std_c_allocator();

Allocation allocator_allocate(const Allocator *allocator, usize size, usize alignment);
bool allocator_reallocate(const Allocator *allocator, Allocation *allocation, usize new_size);
void allocator_deallocate(const Allocator *allocator, Allocation *allocation);

#define ALLOCATE(allocator, type) (type *)allocator_allocate(allocator, sizeof(type), ALIGN_OF(type)).bytes
#define ALLOCATE_N(allocator, count, type) (type *)allocator_allocate(allocator, count * sizeof(type), ALIGN_OF(type)).bytes

#endif // __C_LIB_ALLOCATOR_H__