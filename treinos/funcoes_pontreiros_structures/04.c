#include <stdio.h>

int soma(int *n1, int *n2, int *resultado);

int main (void)
{
    int x = 5;
    int y = 9;
    int res;

    printf("%d + %d = %d\n", x, y, soma(&x, &y, &res));

    return 0;
}

int soma(int *n1, int *n2, int *resultado)
{
    *resultado = *n1 + *n2;

    return *resultado;
}