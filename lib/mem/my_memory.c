#include "../../include/mem.h"

static memory_t *new_mem(void *ptr, unsigned long size, bool *failed)
{
    memory_t *new = NULL;

    new = malloc(sizeof(memory_t));
    if (new == NULL) {
        *failed = true;
        return NULL;
    }
    new->ptr = ptr;
    new->bytes = size;
    new->next = NULL;
    return new;
}

static memory_t *add_pointer(void *ptr, unsigned long size, memory_t *pointers,
    bool *failed)
{
    if (pointers == NULL)
        return new_mem(ptr, size, failed);
    pointers->next = add_pointer(ptr, size, pointers->next, failed);
    return pointers;
}

static memory_t *free_pointer(unsigned long ptr, memory_t *pointers)
{
    memory_t *temp = NULL;

    if (pointers == NULL)
        return NULL;
    if ((unsigned long) pointers->ptr <= ptr &&
        ptr <= (unsigned long) pointers->ptr + pointers->bytes) {
        free(pointers->ptr);
        temp = pointers->next;
        free(pointers);
        return temp;
    }
    pointers->next = free_pointer(ptr, pointers->next);
    return pointers;
}

static void free_all_pointers(memory_t *pointers)
{
    if (pointers == NULL)
        return;
    free_all_pointers(pointers->next);
    free(pointers->ptr);
    free(pointers);
    return;
}

static memory_t *get_infos(unsigned long ptr, memory_t *pointers)
{
    if (pointers == NULL)
        return NULL;
    if ((unsigned long) pointers->ptr <= ptr &&
        ptr <= (unsigned long) pointers->ptr + pointers->bytes)
        return pointers;
    return get_infos(ptr, pointers->next);
}

memory_t *my_memory_manager(void *ptr, unsigned long size, function_t usage,
    bool *failed)
{
    static memory_t *pointers = NULL;

    switch (usage){
        case MALLOC:
            pointers = add_pointer(ptr, size, pointers, failed);
            return NULL;
        case FREE:
            pointers = free_pointer((unsigned long) ptr, pointers);
            return NULL;
        case FREE_ALL:
            free_all_pointers(pointers);
            return NULL;
        case REALLOC:
            return get_infos((unsigned long) ptr, pointers);
    }
    return NULL;
}
