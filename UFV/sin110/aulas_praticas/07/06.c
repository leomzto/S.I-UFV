#include <stdio.h>

float somaDiag2(float mat[5][5]);

int main(void)
{
    float matriz[5][5];
    int l, c;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 5; c++)
        {
            printf("Entre com o elemento [%d][%d]: ", l + 1, c + 1);
            scanf("%f", &matriz[l][c]);
        }
    }

    printf("A soma da diagonal secundaria dessa matriz[5][5] é:\n >>> %.2f\n", somaDiag2(matriz));

    return 0;
}

float somaDiag2(float mat[5][5])
{
    int l, c;
    float soma = 0.0;

    soma += mat[0][4] + mat [1][3] + mat[2][2] + mat[3][1] + mat[4][0];

    return soma;
}
