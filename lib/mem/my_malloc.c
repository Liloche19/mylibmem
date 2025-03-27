#include "../../include/mem.h"

void *my_malloc(unsigned long size)
{
    void *ptr = NULL;

    ptr = malloc(size);
    if (ptr == NULL){
        free_all();
        return NULL;
    }
    my_memory_manager(ptr, size, true);
    return ptr;
}
