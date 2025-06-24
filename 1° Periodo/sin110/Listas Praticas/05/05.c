#include <stdio.h>

int main(void)
{
    int mat[3][3];
    int l, c;
    int maior, menor;

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Matriz[%d][%d]: ", l + 1, c + 1);
            scanf("%d", &mat[l][c]);
        }
    }

    maior = menor = mat[0][0];

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (mat[l][c] > maior)
                maior = mat[l][c];

            if (mat[l][c] < menor)
                menor = mat[l][c];
        }
    }

    printf("Maior -> %d\n", maior);
    printf("Menor -> %d\n", menor);

    return 0;
}
