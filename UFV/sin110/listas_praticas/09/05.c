#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char nome[31];
  int codigo;
  float preco;
} sProduto;

int main (void)
{
  void *vetor = malloc(1024);
  if (vetor == NULL)
  {
    printf("Falha ao alocar memória.\n");
    exit(1);
  }

  int i;  
  int **matriz = malloc(10 * sizeof(int *));
  if (matriz == NULL)
  {
    printf("Falha ao alocar memória.\n");
    free(vetor);
    exit(1);
  }
  for (i = 0; i < 10; i++)
  matriz[i] = malloc(10 * sizeof(int));

  int i2;
  char **texto = malloc(100 * sizeof(char *));
  if (texto == NULL)
  {
    printf("Falha ao alocar memória.\n");
    free(vetor);
    for (i = 0; i < 10; i++)
      free(matriz[i]);
    free(matriz);
    exit(1);
  }
  for (i2 = 0; i < 100; i++)
    texto[i2] = malloc(80 * sizeof(char));
  
  sProduto *produtos = malloc(50 * sizeof(sProduto));
  if (produtos == NULL)
  {
    printf("Falha ao alocar memória.\n");
    free(vetor);
    for (i = 0; i < 10; i++)
      free(matriz[i]);
    free(matriz);
    for (i = 0; i < 100; i++)
      free(texto[i2]);
    free(texto);
    exit(1);
  }





  free(vetor);

  for (i = 0; i < 10; i++)
    free(matriz[i]);
  free(matriz);

  for (i = 0; i < 100; i++)
    free(texto[i2]);
  free(texto);

  free(produtos);

  return 0;
}