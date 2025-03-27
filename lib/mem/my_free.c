#include "../../include/mem.h"

void free_all(void)
{
    my_memory_manager(NULL, 1, FREE_ALL);
    return;
}

void my_free(void *ptr)
{
    my_memory_manager(ptr, 0, FREE);
    return;
}
