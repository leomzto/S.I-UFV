#include <stdio.h>

int main(void)
{
    int x = 7;
    printf("x antes: %d\n", x);

    int *p = &x;
    *p = 20;

    puts("Depois:");
    printf("x: %d\n*p: %d\n", x, *p);

    return 0;
}
