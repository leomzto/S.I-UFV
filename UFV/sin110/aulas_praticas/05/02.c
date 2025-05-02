#include <stdio.h>

int main(void)
{
    int mat[5][5];
    int l, c;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 5; c++)
        {
            printf("Matriz[%d][%d]: ", l + 1, c + 1);
            scanf("%d", &mat[l][c]);
        }
    }
    printf("\n");

/*
    printf("Matriz[5][5] ->\n");
    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 5; c++)
            printf("%d ", mat[l][c]);

        printf("\n");
    }
    printf("\n");
*/

    printf("Elementos da diagonal principal ->\n");
    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 5; c++)
        {
            if (l == c)
                printf("%d ", mat[l][c]);
        }
    }
    printf("\n");

    return 0;
}
