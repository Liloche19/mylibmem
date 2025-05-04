#ifndef MEM_H
    #define MEM_H

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <stdio.h>

    #define ERROR_STATUS 84
    #define SUCCESS_CODE 0
    #define MALLOC_FAILED_STATUS ERROR_STATUS


typedef struct memory_s memory_t;

typedef enum function_s {
    MALLOC,
    FREE,
    FREE_ALL,
    REALLOC
} function_t;

struct memory_s {
    void *ptr;
    unsigned long bytes;
    memory_t *next;
};

// Memory manager
memory_t *my_memory_manager(void *ptr, unsigned long size, function_t usage,
    bool *failed);

// malloc functions
void *my_malloc(unsigned long size);
void *my_calloc(unsigned long size);

// realloc function
void *my_realloc(void *ptr, unsigned long size);

// exit function
void my_exit(char *message, int code);

// free functions
void my_free(void *ptr);
void free_all(void);

#endif // MEM_H
