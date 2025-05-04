#include "../../include/mem.h"

void *my_calloc(unsigned long size)
{
    void *ptr = NULL;
    char *pointer = NULL;
    unsigned long i = 0;

    ptr = my_malloc(size);
    if (ptr == NULL)
        return NULL;
    pointer = ptr;
    while (i < size) {
        pointer[i] = 0;
        i++;
    }
    return ptr;
}
