#include "../include/mem.h"

int main(void)
{
    char *str = NULL;

    str = my_calloc(sizeof(char) * 3);
    str[0] = 'a';
    str[1] = 'b';
    printf("%s\n", str);
    my_free(&str[1]);
    return 0;
}
