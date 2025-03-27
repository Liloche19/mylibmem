#ifndef MEM_H
    #define MEM_H

    #include <stdlib.h>
    #include <stdbool.h>
    #include <stdio.h>

typedef struct memory_s memory_t;

struct memory_s {
    void *ptr;
    unsigned long bytes;
    memory_t *next;
};

// Memory manager
int my_memory_manager(void *ptr, unsigned long size, bool add);

// malloc functions
void *my_malloc(unsigned long size);

// free functions
void my_free(void *ptr);
void free_all(void);

#endif // MEM_H
