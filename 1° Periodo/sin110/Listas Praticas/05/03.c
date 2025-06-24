// exercicio repetido, igual ao 01, vou fazer para ao inves de numeros pares, imprimir os impares.
#include <stdio.h>

int main(void)
{
    int mat[4][4];
    int l, c;

    for (l = 0; l < 4; l++)
    {
        for (c = 0; c < 4; c++)
        {
            printf("Matriz[%d][%d]: ", l + 1, c + 1);
            scanf("%d", &mat[l][c]);
        }
    }

    printf("Matriz[4][4] ->\n");
    for (l = 0; l < 4; l++)
    {
        for (c = 0; c < 4; c++)
            printf("%d ", mat[l][c]);

        printf("\n");
    }

    printf("Impares[4][4] ->\n");
    for (l = 0; l < 4; l++)
    {
        for (c = 0; c < 4; c++)
        {
            if (mat[l][c] % 2 != 0)
                printf("[%d][%d] --> %d \n", l + 1, c + 1, mat[l][c]);
        }
    }

    return 0;
}
