#include <stdio.h>
#include <stdlib.h>

void lerMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

int main(void)
{
  int a, b, c, d; 

  printf("Digite o número de linhas e colunas da primeira matriz (linhas colunas): ");
  scanf("%d %d", &a, &b);
  printf("Digite o número de linhas e colunas da segunda matriz (linhas colunas): ");
  scanf("%d %d", &c, &d);

  if (b != c)
  {
    printf("Número de colunas da primeira matriz deve ser igual ao número de linhas da segunda.\n");
    return 1;
  }

  int mat1[a][b], mat2[c][d];
  int matProduto[a][d];

  lerMatriz(a, b, mat1);
  lerMatriz(c, d, mat2);

  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < d; j++)
      matProduto[i][j] = 0;
  }

  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < d; j++)
    {
      for (int k = 0; k < b; k++)
        matProduto[i][j] += mat1[i][k] * mat2[k][j];
    }
  }

  printf("Matriz 1:\n");
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
      printf("%d ", mat1[i][j]);
    printf("\n");
  }

  printf("Matriz 2:\n");
  for (int i = 0; i < c; i++)
  {
    for (int j = 0; j < d; j++)
      printf("%d ", mat2[i][j]);
    printf("\n");
  }

  printf("Produto das matrizes:\n");
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < d; j++)
      printf("%d ", matProduto[i][j]);
    printf("\n");
  }

  return 0;
}

void lerMatriz(int linhas, int colunas, int matriz[linhas][colunas])
{
  for (int linha = 0; linha < linhas; linha++)
  {
    for (int coluna = 0; coluna < colunas; coluna++)
    {
      printf("Digite o elemento [%d][%d]: ", linha + 1, coluna + 1);
      scanf("%d", &matriz[linha][coluna]);
    }
  }
}
