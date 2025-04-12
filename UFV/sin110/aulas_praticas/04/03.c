#include <stdio.h>

int main(void)
{
    int num[15];
    int opcao, i, k;

    printf("Entre com 15 números: ");
    for (i = 0; i < 15; i++) 
    {
        scanf("%d", &num[i]);
    }

    do
    {
        printf("Escolha entre:\n1. Imprimir os numeros\n2. Imprimir na ordem contraria\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                for (i = 0; i < 15; i++)
                {
                    printf("%d ", num[i]);
                }
                printf("\n");
                break;

            case 2:
                for (k = 14; k >= 0; k--)
                {
                    printf("%d ", num[k]);
                }
                printf("\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 1 && opcao != 2);

    return 0;
}
