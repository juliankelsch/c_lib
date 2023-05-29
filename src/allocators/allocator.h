#ifndef __C_LIB_ALLOCATOR_H__
#define __C_LIB_ALLOCATOR_H__

#include "../common/types.h"
#include "../common/macros.h"

typedef struct Allocator Allocator;

// Requests [size] number of bytes from the allocator aligned to [alignment].
typedef void *AllocationFunc(void *allocator, usize size, usize alignment);
typedef void *ReallocationFunc(void *allocator, void *data, usize new_size, usize alignment);
typedef void DeallocationFunc(void *allocator, void *data);

struct Allocator
{
    void *allocator;
    AllocationFunc *allocate;
    ReallocationFunc *reallocate;
    DeallocationFunc *deallocate;
};

Allocator get_std_c_allocator();

void *allocator_allocate(const Allocator *allocator, usize size, usize alignment);
void *allocator_allocate_zeroed(const Allocator *allocator, usize size, usize alignment);
void *allocator_reallocate(const Allocator *allocator, void *data, usize new_size, usize alignment);
void allocator_deallocate(const Allocator *allocator, void *data);

#define ALLOCATE(allocator, type) (type *)allocator_allocate(allocator, sizeof(type), ALIGN_OF(type))
#define ALLOCATE_N(allocator, count, type) (type *)allocator_allocate(allocator, count * sizeof(type), ALIGN_OF(type))
#define REALLOCATE_N(allocator, data, count, type) (type *)allocator_reallocate(allocator, data, count * sizeof(type), ALIGN_OF(type))

#endif // __C_LIB_ALLOCATOR_H__