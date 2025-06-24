#include <stdio.h>

int main(void)
{
    int num[10];
    int i;
    int cont2 = 0;
    int cont3 = 0;
    int cont5 = 0;


    printf("Digite 10 números: ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
    }

    for(i = 0; i < 10; i++)
    {
        if (num[i] == 2)
            cont2++;
        if (num[i] == 3)
            cont3++;
        if (num[i] == 5)
            cont5++;
    }

    printf("%d numeros 2\n", cont2);
    printf("%d numeros 3\n", cont3);
    printf("%d numeros 5\n", cont5);

    return 0.;
}
