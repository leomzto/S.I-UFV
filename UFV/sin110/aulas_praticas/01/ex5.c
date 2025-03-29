#include <stdio.h>

int main (void)
{
    int m, i;
    float a;

    printf("Entre com sua matricula: ");
    scanf("%d", &m);

    printf("Entre com sua idade: ");
    scanf("%d", &i);

    printf("Entre com sua altura: ");
    scanf("%f", &a);

    printf("\nMatricula: %d\nIdade: %d anos\nAltura: %.2fm\n", m, i, a);

    return 0;
}
