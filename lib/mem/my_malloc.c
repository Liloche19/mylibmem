#include "../../include/mem.h"

void *my_malloc(unsigned long size)
{
    void *ptr = NULL;
    bool failed = false;

    ptr = malloc(size);
    if (ptr == NULL){
        free_all();
        exit(ERROR_STATUS);
    }
    my_memory_manager(ptr, size, MALLOC, &failed);
    if (failed) {
        free(ptr);
        free_all();
        exit(MALLOC_FAILED_STATUS);
    }
    return ptr;
}
