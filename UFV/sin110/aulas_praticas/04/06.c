#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num[10];
    int i, j, repetido, numero;

    printf("Entre com 10 números inteiros diferentes: ");

    for (i = 0; i < 10; i++)
    {
        do
        {
            scanf("%d", &numero);

            repetido = false;
            for (j = 0; j < i; j++)
            {
                if (num[j] == numero)
                {
                    repetido = true;
                    printf("%d ja foi inserido.\n", numero);
                    printf("Entre com outro número.\n");
                    break;
                }
            }
        }while (repetido);

        num[i] = numero;
    }

    printf("\nNúmeros digitados: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}