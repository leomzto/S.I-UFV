// Escreva um programa que leia um inteiro não negativo n e imprima a soma dos n
// primeiros números primos
//
// Entre com o valor de n: 4
// A soma dos n primeiros números primos é: 17

#include <stdio.h>

int EhPrimo(int num);

int main(void)
{
    int n, checagem = 0, num_primo = 2, soma = 0;

    printf("Entre com o valor de n: ");
    scanf("%d", &n);

    while (checagem < n)
    {
        if (EhPrimo(num_primo))
        {
            soma += num_primo;
            checagem++;
        }
        num_primo++;
    }
    
    printf("A soma dos %d primeiros números primos é: %d\n", n, soma);

    return 0;
}

int EhPrimo(int num)
{
    if (num < 2)
        return 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
