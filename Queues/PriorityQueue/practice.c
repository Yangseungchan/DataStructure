#include <stdio.h>

int main(void)
{
    char c = NULL;

    printf("|%c|\n", c);
    if (c == NULL)
    {
        printf("It is NULL\n");
    }
    return 0;
}