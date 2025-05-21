#include <stdio.h>

void trocar(int *a, int *b);

int main(void)
{
    int x = 10;
    int y = 90;

    trocar(&x, &y);

    printf("x: %d\ny: %d\n", x, y);

    return 0;
}

void trocar(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
