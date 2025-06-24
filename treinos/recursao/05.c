// Escreva uma função recursiva que conte quantos elementos há em um vetor de inteiros

#include <stdio.h>

int main(void)
{
  int tam;
  printf("Digite o tamanho do vetor (deve ser 10): ");
  scanf("%d", &tam);

  int *vetor = malloc(tam * sizeof(int));
  if (vetor == NULL)
  {
    printf("Erro ao alocar memória.\n");
    return 1;
  }
  printf("Digite 10 números inteiros:\n");
  for (int i = 0; i < 10; i++)
    scanf("%d", &vetor[i]);
  
  printf("O vetor contém %d elementos.\n", contarElementos(vetor, tam));

  free(vetor);
  return 0;
}

int contarElementos(int *vetor, int tamanho)
{
  if(tamanho == 0)
    return 0;
  else
    return 1 + contarElementos(vetor + 1, tamanho - 1);
}
