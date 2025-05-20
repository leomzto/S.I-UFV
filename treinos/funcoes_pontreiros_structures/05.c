/*
Ex 5:
Protótipo: void soma_matrizes(int A[2][2], int B[2][2], int C[2][2]);
Descrição: Codifique uma função que soma duas matrizes 2x2 e armazena o resultado em C.
No main, preencha A e B, chame a função e imprima a matriz resultante.
*/

#include <stdio.h>

#define LINHAS 2
#define COLUNAS 2

void PreencherMatriz(int mat[][COLUNAS]);
void soma_matrizes(int A[2][2], int B[2][2], int C[2][2]);

int main(void)
{
    int matA[LINHAS][COLUNAS];
    int matB[LINHAS][COLUNAS];
    int matC[LINHAS][COLUNAS];

    int l, c;
    
    printf("Entre com a matriz A:\n");
    PreencherMatriz(matA);

    printf("Entre com a matriz B:\n");
    PreencherMatriz(matB);

    soma_matrizes(matA, matB, matC);
    printf("Soma de A[%d][%d] + B[%d][%d] = C[%d][%d]\n",
         LINHAS, COLUNAS, LINHAS, COLUNAS, LINHAS, COLUNAS);

    printf("Matriz C:\n");
    for(l = 0; l < LINHAS; l++)
    {
        for(c = 0; c < COLUNAS; c++)
            printf("%d\t", matC[l][c]);

        printf("\n");
    }

    return 0;
}

void PreencherMatriz(int mat[][COLUNAS])
{
    int l, c;

    for(l = 0; l < LINHAS; l++)
    {
        for(c = 0; c < COLUNAS; c++)
        {
            printf("Entre com [%d][%d]: ", l, c);
            scanf("%d", &mat[l][c]);
        }
    }
}

void soma_matrizes(int mat1[][COLUNAS], int mat2[][COLUNAS], int matSoma[][COLUNAS])
{
    int l, c;

    for(l = 0; l < LINHAS; l++)
    {
        for(c = 0; c < COLUNAS; c++)
        {
            matSoma[l][c] = mat1[l][c] + mat2[l][c];
        }
    }
}



