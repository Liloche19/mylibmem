#include "../../include/mem.h"

void *my_malloc(unsigned long size)
{
    void *ptr = NULL;

    ptr = malloc(size);
    if (ptr == NULL){
        free_all();
        exit(ERROR_STATUS);
    }
    my_memory_manager(ptr, size, true);
    return ptr;
}
