#include <stdio.h>

int somaDobro(int *a, int *b);

int main(void)
{
    int a, b;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);

    int resultado = somaDobro(&a, &b);
    printf("Soma do dobro de %d e %d: %d\n", a, b, resultado);

    return 0;
}

int somaDobro(int *a, int *b)
{
    return (*a * 2) + (*b * 2);
}