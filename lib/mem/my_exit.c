#include "../../include/mem.h"

int my_string_len(char *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void my_exit(char *message, int code)
{
    int size = my_string_len(message);

    if (code != SUCCESS_CODE) {
        if (message != NULL)
            write(2, message, size);
        free_all();
        exit(code);
    }
    if (message != NULL)
        write(1, message, size);
    free_all();
    exit(code);
    return;
}
