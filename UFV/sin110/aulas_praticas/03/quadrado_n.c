#include <stdio.h>

int main(void)
{
    int n;
    int soma = 0, qtd_impares = 0;
    int num_impar = 1;

    printf("Numero: ");
    scanf("%d", &n);

    while (qtd_impares < n)
    {
        if (num_impar % 2 != 0)
        {
            soma += num_impar;
            qtd_impares++;
        }

        num_impar++;
    }

    printf("O quadrado de %d é %d\n", n, soma);

    return 0;
}
