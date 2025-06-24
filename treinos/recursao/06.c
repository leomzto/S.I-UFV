// Crie uma função recursiva que encontre o maior valor dentro de um vetor de inteiros

#include <stdio.h>
#include <stdlib.h>

int maiorValor(int *vetor, int tamanho);

int main(void)
{
  int tam;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tam);
  int *vetor = malloc(tam * sizeof(int));
  if (vetor == NULL)
  {
    printf("Erro ao alocar memória.\n");
    return 1;
  }

  for(int i = 0; i < tam; i++)
  {
    printf("Digite o elemento %d: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  printf("O maior valor do vetor é: %d\n", maiorValor(vetor, tam));

  free(vetor);
  return 0;
}

int maiorValor(int *vetor, int tamanho)
{
  if (tamanho == 0)
    return 0;
  else if (tamanho == 1)
    return vetor[0];
  else
  {
    int maior = maiorValor(vetor + 1, tamanho - 1);
    return (vetor[0] > maior) ? vetor[0] : maior;
  }
}