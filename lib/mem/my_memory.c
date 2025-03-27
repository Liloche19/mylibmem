#include "../../include/mem.h"

memory_t *new_mem(void *ptr, unsigned long size)
{
    memory_t *new = NULL;

    new = malloc(sizeof(memory_t));
    if (new == NULL)
        return NULL;
    new->ptr = ptr;
    new->bytes = size;
    new->next = NULL;
    return new;
}

memory_t *add_pointer(void *ptr, unsigned long size, memory_t *pointers)
{
    if (pointers == NULL)
        return new_mem(ptr, size);
    pointers->next = add_pointer(ptr, size, pointers->next);
    return pointers;
}

memory_t *free_pointer(unsigned long ptr, memory_t *pointers)
{
    memory_t *temp = NULL;

    if (pointers == NULL)
        return NULL;
    if ((unsigned long) pointers->ptr <= ptr &&
        ptr <= (unsigned long) pointers->ptr + pointers->bytes){
        free(pointers->ptr);
        temp = pointers->next;
        free(pointers);
        return temp;
    }
    pointers->next = free_pointer(ptr, pointers->next);
    return pointers;
}

void free_all_pointers(memory_t *pointers)
{
    if (pointers == NULL)
        return;
    free_all_pointers(pointers->next);
    free(pointers->ptr);
    free(pointers);
    return;
}

int my_memory_manager(void *ptr, unsigned long size, bool add)
{
    static memory_t *pointers = NULL;

    if (add)
        pointers = add_pointer(ptr, size, pointers);
    else if (size > 0)
        free_all_pointers(pointers);
    else
        pointers = free_pointer((unsigned long) ptr, pointers);
    return 0;
}
