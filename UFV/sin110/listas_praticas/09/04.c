#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int cont = 0;
  int i;
  int tamanho = 10;
  int numero;
  int *vetor = malloc(tamanho * sizeof(int));
  if (vetor == NULL)
  {
    printf("Falha ao alocar memória.\n");
    exit(1);
  }

  do
  {
    printf("Digite um número inteiro (0 para sair): ");
    scanf("%d", &numero);

    if (numero == 0)
      break;

    if (cont == tamanho)
    {
      int *novo_vetor = malloc((tamanho + 10) * sizeof(int));
      if (novo_vetor == NULL)
      {
        printf("Falha ao alocar memória.\n");
        free(vetor);
        exit(1);
      }
      for (i = 0; i < cont; i++)
        novo_vetor[i] = vetor[i];

      free(vetor);
      vetor = novo_vetor;
      tamanho += 10;
    }

    vetor[cont] = numero;
    cont++;
    } while (1);

printf("Números digitados:\n");
for (i = 0; i < cont; i++)
    printf("%d ", vetor[i]);
printf("\n");

  free(vetor);

  return 0;
} 