#include <stdio.h>

int main(void)
{
    int num;
    int divisores;
    int qtd_primos = 0;
    int soma = 0;
    
    printf("Entre com um número: ");
    scanf("%d", &num);

    int numerador, divisor;

    printf("Números primos até %d: ", num);
    for (numerador = 2; numerador <= num; numerador++)
    {
        divisores = 0;
        for (divisor = 1; divisor <= numerador; divisor++)
        {
            if (numerador % divisor == 0)
                divisores++;
        }
        
        if (divisores == 2)
        {
            qtd_primos++;
            printf("%d ",numerador);
            soma += numerador;
        }
    }

    printf("\nQuantidade de primos até %d: %d\n", num, qtd_primos);
    printf("Soma dos primos até %d: %d\n", num, soma);

    return 0;
}