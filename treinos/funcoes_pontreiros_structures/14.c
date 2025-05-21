/*
Ex 8 – Matriz Identidade
Descrição: Preencha uma matriz 3x3 como identidade (1 na diagonal, 0 fora).
Protótipo: void matriz_identidade(int mat[3][3]);
*/

#include <stdio.h>

void matriz_identidade(int mat[3][3]);

int main(void)
{
    int mat[3][3];

    matriz_identidade(mat);


    return 0;
}

void matriz_identidade(int mat[3][3])
{
    int l, c;
    for(l = 0; l < 3; l++)
    {
        for(c = 0; c < 3; c++)
        {
            if(l == c)
                mat[l][c] = 1;
            else
                mat[l][c] = 0;

            printf("%d ", mat[l][c]);
        }
        printf("\n");
    }
}

