#include <stdio.h>

int* retornaMaior(int *n1, int *n2);

int main(void)
{
    int x = 6;
    int y = 9;
    int *maior = retornaMaior(&x, &y);

    printf("Maior entre %d e %d: %d\n", x, y, *maior);

    return 0;
}

int* retornaMaior(int *n1, int *n2)
{
    if (*n1 > *n2) return n1;
    else return n2;
}