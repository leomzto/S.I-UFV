#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int *vetor = calloc(500, sizeof(int));
  if (vetor == NULL)
  {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  int i, j;
  for (i = 0; i < 500; i++)
  {
    if (vetor[i] == 0)
      vetor[i] = i;
  }

  printf("Primeiros 10 números do vetor:\n");
  for (i = 0; i < 10; i++)
      printf("%d ", vetor[i]);

  printf("\nUltimos 10 números do vetor:\n");
  for (j = 490; j < 500; j++)
      printf("%d ", vetor[j]);

  return 0;
}
