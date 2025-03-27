#include "../../include/mem.h"

void free_all(void)
{
    my_memory_manager(NULL, 1, false);
    return;
}

void my_free(void *ptr)
{
    my_memory_manager(ptr, 0, false);
    return;
}
