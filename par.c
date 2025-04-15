#include <stdio.h>

int EhPar(int numero);

int main(void)
{
    int num;
    int i;

    printf("Insira um número: ");
    scanf("%d", &num);

    printf("Números pares até %d: ", num);
    for (i = 0; i <= num; i++)
    {
        if (EhPar(i))
        {
            printf("%d", i);
            if (i < num)
                printf(", ");
        }
    }
    printf("\n");

    return 0;
}

int EhPar(int numero)
{
    if(numero % 2 == 0)
        return 1;
    else
        return 0;
}
