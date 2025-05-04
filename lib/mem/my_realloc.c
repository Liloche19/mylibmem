#include "../../include/mem.h"

void *my_realloc(void *ptr, unsigned long size)
{
    char *new = NULL;
    memory_t *previous = NULL;
    char *pointer = ptr;
    bool failed = false;

    previous = my_memory_manager(ptr, size, REALLOC, &failed);
    if (previous == NULL)
        return my_calloc(size);
    new = my_calloc(size);
    if (new == NULL)
        return NULL;
    for (unsigned long i = 0; i < size && i < previous->bytes; i++)
        new[i] = pointer[i];
    my_free(ptr);
    return new;
}
