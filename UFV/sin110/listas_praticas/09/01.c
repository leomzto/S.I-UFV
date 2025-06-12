#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int l, c, i, j;
  float **m;

  printf("Digite o número de l: ");
  scanf("%d", &l);
  printf("Digite o número de c: ");
  scanf("%d", &c);

  m = (float **)malloc(l * sizeof(float *));
  for (i = 0; i < l; i++)
    m[i] = (float *)malloc(c * sizeof(float));

  if (m == NULL)
  {
    printf("Erro ao alocar memória para a m.\n");
    exit(1);
  }
 
  for (i = 0; i < l; i++)
  {
    for (j = 0; j < c; j++)
    {
      printf("Digite o valor para [%d][%d]: ", i, j);
      scanf("%f", &m[i][j]);
    }
  }

  printf("\nMatriz:\n");
  for (i = 0; i < l; i++)
  {
    for (j = 0; j < c; j++)
      printf("%.2f ", m[i][j]);
    printf("\n");
  }

  for (i = 0; i < l; i++)
    free(m[i]);
  free(m);

  return 0;

}