#include <stdio.h>

int main(void)
{
    int num[6];
    int i, par, impar;
    int soma_pares = 0, soma_impares = 0;;
    
    printf("Entre com 6 números inteiros: ");
    for (i = 0; i < 6; i++)
    {
        scanf("%d", &num[i]);
    }

    printf("Números pares: ");
    for (i = 0; i < 6; i++)
    {
        if (num[i] % 2 == 0)
        {
            par = num[i];
            printf("%d ", par);
            soma_pares += par;
        }
    }
    printf("\nSoma dos pares: %d\n", soma_pares); 

    printf("Números impares: ");
    for (i = 0; i < 6; i++)
    {
        if (num[i] % 2 != 0)
        {
            impar = num[i];
            printf("%d ", impar);
            soma_impares += impar;
        }
    }
    printf("\nSoma dos ímpares: %d\n", soma_impares); 

    return 0;
}
