#include <stdio.h>

int main(void)
{
    int mat[4][4];
    int l, c;
    int index;

    for (l = 0; l < 4; l++)
    {
        for (c = 0; c < 4; c++)
        {
            printf("Matriz[%d][%d]: ", l + 1, c + 1);
            scanf("%d", &mat[l][c]);
        }
    }

    printf("Matriz[4][4]:\n");
    for (l = 0; l < 4; l++)
    {
        for (c = 0; c < 4; c++)
            printf("%d ", mat[l][c]);

        printf("\n");
    }

    printf("Pares[4][4] ->\n");
    for (l = 0; l < 4; l++)
    {
        for (c = 0; c < 4; c++)
        {
            if (mat[l][c] % 2 == 0)
                printf("[%d][%d] --> %d \n", l + 1, c + 1, mat[l][c]);
        }
    }

    return 0;
}
