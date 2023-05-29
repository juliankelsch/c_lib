#include <stdio.h>

#include "src/allocators/allocator.h"

int main(int argc, char **argv)
{
    Allocator allocator = get_std_c_allocator();

    int *nums = ALLOCATE_N(&allocator, 20, int);

    printf("Hello, new c std library!");
    return 0;
}