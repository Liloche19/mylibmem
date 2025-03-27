#include "../include/mem.h"

int main(void)
{
    char *str = NULL;

    str = my_malloc(sizeof(char) * 2);
    str[1] = '\0';
    str[0] = 'a';
    printf("%s\n", str);
    free_all();
    return 0;
}
