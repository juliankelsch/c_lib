#include <stdio.h>

#include "src/allocators/allocator.h"

int main(int argc, char **argv)
{
    Allocator allocator = get_std_c_allocator();

    printf("Hello, new c std library!");
    return 0;
}