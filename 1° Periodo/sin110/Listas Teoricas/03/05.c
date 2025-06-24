#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n, m;
  printf("Digite o valor de n: ");
  scanf("%d", &n);
  printf("Digite o valor de m: ");
  scanf("%d", &m);

  int **matriz = malloc(n * sizeof(int *));
  if (matriz == NULL)
  {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }
  
  for (int l = 0; l < n; l++)
  {
    matriz[l] = malloc(m * sizeof(int));
    if (matriz[l] == NULL)
    {
      printf("Erro ao alocar memória para a linha %d.\n", l);
      exit(1);
    }
  }

  for (int l = 0; l < n; l++)
  {
    for (int c = 0; c < m; c++)
    {
      printf("Digite o valor da posição [%d][%d]: ", l, c);
      scanf("%d", &matriz[l][c]);
    }
  }

  printf("Transposta da matriz:\n");
  for (int c = 0; c < m; c++)
  {
    for (int l = 0; l < n; l++)
    {
      printf("%d ", matriz[l][c]);
    }
    printf("\n");
  }

  for (int l = 0; l < n; l++)
    free(matriz[l]);
  free(matriz);

  return 0;
}
