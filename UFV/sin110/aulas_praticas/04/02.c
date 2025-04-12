#include <stdio.h>

int main(void)
{
    int num[10];
    int i;
    int qtd_impar = 0;

    printf("Insira 10 numeros: ");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if (num[i] % 2 != 0)
        {
            printf("%d ", num[i]);
            qtd_impar++;
        }
    }

    printf("\n");
    printf("Quantidade de impares: %d \n", qtd_impar);

    return 0;
}
