#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int N, M, i, j, k, maior, l = 0, c = 0;
  printf("Digite o número de linhas: ");
  scanf("%d", &N);
  printf("Digite o número de colunas: ");
  scanf("%d", &M);
  int **mat = (int **)malloc(N * sizeof(int *));
  for(i = 0; i < N; i++)
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

for (k = 0; k < 3; k++)
{
  maior = mat[0][0];
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < M; j++)
    {
      if (mat[i][j] > maior)
      {
        maior = mat[i][j];
        l = i;
        c = j;
      }
    }
  }
  printf("%d maior valor %d encontrado em [%d][%d]\n",k+1 , maior, l, c);
  mat[l][c] = 0;
}

for (i = 1; i < N; i++)
  free(mat[i]);
free(mat);
  return 0;
}
