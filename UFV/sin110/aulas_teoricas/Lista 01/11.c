#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n1[10], n2[10], inters[10];
    int i, i2, qtd_iguais = 0;

    printf("Entre com o vetor 01: ");
    for(i = 0; i < 10; i++)
        scanf("%d", &n1[i]);

    printf("Entre com o vetor 02: ");
    for(i = 0; i < 10; i++)
        scanf("%d", &n2[i]);

    bool repetido[10] = {false};

    for (i = 0; i < 10; i++)
    {
        for (i2 = 0; i2 < 10; i2++)
        {
            if(n1[i] == n2[i2] && !repetido[i2])
            {
                inters[qtd_iguais] = n1[i];
                qtd_iguais++;
                repetido[i2] = true;
                break;
            }
        }
    }

    printf("Interseção:\n");
    for(i = 0; i < qtd_iguais; i++)
        printf("%d ", inters[i]);

    printf("\n");

    return 0;
}