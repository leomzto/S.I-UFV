#include <stdio.h>

int main(void)
{
    int n;
    int soma = 0, qtd_pares = 0;
    int num_par = 0;

    do
    {
        printf("Entre com um número inteiro positivo: ");
        scanf("%d", &n);
    }
    while (n < 0);

    while (qtd_pares < n)
    {
        num_par += 2;
        soma += num_par;
        qtd_pares++;
    }

    printf("A soma dos primeiros %d números pares é: %d\n", n, soma);


    return 0;
}
