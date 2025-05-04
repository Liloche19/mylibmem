# mylibmem
A C library to easily manage the memory (heap)

---

## Allocation functions (my_malloc, my_calloc, my_realloc)

- ### my_malloc: void *my_malloc(unsigned long size)

    Takes the size you want to allocate in the heap, and return the pointers to the place where it's allocated. This pointer is saved in my_memory with the size: "*size*" it is allocated.

- ### my_calloc: void *my_calloc(unsigned long size)

    Like my_malloc, but it initialise all bytes to zero.

- ### my_realloc: void *my_realloc(void *ptr, unsigned long size)

    It allocate a new adress in the heap, of size: "*size*", it initialise all bytes to zero using my_calloc function, and copy the content of the ptr into the dew adress. After that, the old pointer is free.

## Free functions (my_free, free_all)

- ### my_free: void my_free(void *ptr)

    It free the memory allocated by the my_malloc function. If the pointer given had not been allocated using my_malloc, it does nothing. You can give any adress for the pointer, while the adress is between the adress: "*pointer*" and "*pointer + size*".

- ### free_all: void free_all(void)

    This function free everything that had been allocated using my_malloc.

## Exit function (my_exit)

- ### my_exit: void my_exit(char *message, int code)

    This function print the "*message*" given on the standard output if the "*code*" given is zero, else it print it on the standard error output. After that, the function call the free_all function and exit the program with the "*code*" given.

---

## Installation:

Simply run the following commands to compile the library:

        git clone https://github.com/Liloche19/mylibmem.git # Clone the repository
        cd mylibmem # Enter the folder
        make # Compile the library

Then to use it into your projects:

        cp libmem.a /path/to/your/project # Copy the library to your project folder
        cp include/mem.h /path/to/your/project # Copy the header file into your project

To compile your project with the library:

        gcc source_code.c -L. -lmem

---

Thank you for using my library !
Don't hesitate to contribute to this project !
