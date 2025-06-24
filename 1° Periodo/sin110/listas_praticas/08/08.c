#include <stdio.h>

int retornaMaior(int *a, int *b);

int main(void)
{
    int a, b;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);

    retornaMaior(&a, &b);
    printf("Maior valor: %d, Menor valor: %d\n", a, b);

    return 0;
}

int retornaMaior(int *a, int *b)
{
    if (*a < *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    return 0;
}