#include <stdio.h>


int EhPrimo(int numero);
int main(void)
{
    int num, qtd_primos = 0, soma = 0;

    printf("Entre com um número: ");
    scanf("%d", &num);

    printf("Números primos até %d: ", num);
    for (int i = 2; i <= num; i++)
    {
        if (EhPrimo(i))
        {
            printf("%d ", i);
            qtd_primos++;
            soma += i;
        }
    }

    printf("\nQuantidade de primos até %d: %d\n", num, qtd_primos);
    printf("Soma dos primos até %d: %d\n", num, soma);

    return 0;
}


int EhPrimo(int numero)
{
    int i;

    if (numero <= 1)
        return 0;

    for (i = 2; i < numero; i++)
    {
        if (numero % i == 0)
            return 0;
    }
    return 1;
}