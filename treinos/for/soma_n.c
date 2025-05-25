#include <stdio.h>

int main(void)
{
    int num, soma = 0;

    printf("Digite um número: ");
    scanf("%d", &num);

    for (int t = 1; t <= num; t++)
    {
        soma += t;
    }

    printf("A soma de 1 até %d é: %d\n", num, soma);

    return 0;
}
