#include <stdio.h>

int main(void)
{
    int n;
    int soma = 0;
    int num_par = 0;

    do
    {
        printf("Entre com um número inteiro positivo: ");
        scanf("%d", &n);
    }
    while (n < 0);

    while (num_par <= n)
    {
        soma += num_par;
        num_par += 2;
    }

    printf("A soma dos números pares até %d é: %d\n", n, soma);

    return 0;
}
