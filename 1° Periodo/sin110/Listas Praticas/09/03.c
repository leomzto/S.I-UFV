#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int N, M, i, j;
  printf("Digite o número de linhas: ");
  scanf("%d", &N);
  printf("Digite o número de colunas: ");
  scanf("%d", &M);
  int **mat = (int **)malloc(N * sizeof(int *));
  for (i = 0; i < N; i++)
    mat[i] = (int *)malloc(M * sizeof(int));

  if (mat == NULL)
  {
    printf("Erro ao alocar memória para a matriz.\n");
    exit(1);
  }

  for (i = 0; i < N; i++)
  {
    for (j = 0; j < M; j++)
    {
      printf("Digite o valor para [%d][%d]: ", i, j);
      scanf("%d", &mat[i][j]);
    }
  }
  printf("\nMatriz:\n");
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < M; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }

  printf("Matiz transposta:\n");
  for (j = 0; j < M; j++)
  {
    for (i = 0; i < N; i++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }
  
  for (i = 0; i < N; i++)
    free(mat[i]);
  free(mat);

  return 0;
}