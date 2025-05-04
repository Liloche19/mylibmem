#include "../../include/mem.h"

void free_all(void)
{
    bool failed = false;

    my_memory_manager(NULL, 1, FREE_ALL, &failed);
    if (failed)
        return;
    return;
}

void my_free(void *ptr)
{
    bool failed = false;

    my_memory_manager(ptr, 0, FREE, &failed);
    if (failed)
        return;
    return;
}
