#include "../../include/mem.h"

void *my_realloc(void *ptr, unsigned long size)
{
    char *new = NULL;
    memory_t *previous = NULL;
    char *pointer = ptr;
    unsigned long i = 0;

    previous = my_memory_manager(ptr, size, REALLOC);
    if (previous == NULL)
        return my_calloc(size);
    new = my_calloc(size);
    while (i < size && i < previous->bytes){
        new[i] = pointer[i];
        i++;
    }
    my_free(ptr);
    return new;
}
