#include "../include/mem.h"

int main(void)
{
    char *str = NULL;

    str = my_calloc(sizeof(char) * 3);
    str[0] = 'a';
    str[1] = 'b';
    str = my_realloc(str, 5);
    str[2] = 'c';
    str[3] = 'd';
    printf("%s\n", str);
    free_all();
    return 0;
}
