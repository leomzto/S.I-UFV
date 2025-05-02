#include <stdio.h>

#define TAM 3

int main(void)
{
    float mat[TAM][TAM];
    int l, c;
    float soma = 0.0;
    float media;

    for (l = 0; l < TAM; l++)
    {
        for (c = 0; c < TAM; c++)
        {
            printf("Matriz[%d][%d]: ", l + 1, c + 1);
            scanf("%f", &mat[l][c]);
        }
    }

    for (l = 0; l < TAM; l++)
    {
        for (c = 0; c < TAM; c++)
            soma += mat[l][c];
    }

    media = soma / (TAM * TAM);
    printf("\nMedia de mat[%d][%d] -> %.2f", TAM, TAM, media);

    printf("\n");

    return 0;
}
