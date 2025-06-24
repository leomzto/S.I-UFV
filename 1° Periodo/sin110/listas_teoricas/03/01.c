#include <stdio.h>
#include <stdlib.h>

void lerNumeros(int *array, int quantidade);

int main(void)
{
  int *loteria = malloc(6 * sizeof(int));
  int *jogador = malloc(6 * sizeof(int));
  int acertos = 0;
  int i, j;

  if (loteria == NULL || jogador == NULL)
  {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  printf("Digite os números da loteria (6 números entre 1 e 20):\n");
  lerNumeros(loteria, 6);

  printf("Digite os números do jogador (6 números entre 1 e 20):\n");
  lerNumeros(jogador, 6);

  for (i = 0; i < 6; i++)
  {
    for (j = 0; j < 6; j++)
    {
      if (loteria[i] == jogador[j])
      {
        acertos++;
        break;
      }
    }
  }

  int *certos = malloc(acertos * sizeof(int));
  if (certos == NULL)
  {
    printf("Erro ao alocar memória para acertos.\n");
    free(loteria);
    free(jogador);
    exit(1);
  }

  int numeros = 0;
  for (i = 0; i < 6; i++)
  {
    for (j = 0; j < 6; j++)
    {
      if (loteria[i] == jogador[j])
      {
        certos[numeros] = loteria[i];
        numeros++;
        break;
      }
    }
  }

  printf("Números corretos:\n");
  for (i = 0; i < acertos; i++)
    printf("%d ", certos[i]);

  printf("\nNúmeros da loteria:\n");
  for (i = 0; i < 6; i++)
    printf("%d ", loteria[i]);

  printf("\n");

  free(loteria);
  free(jogador);
  free(certos);

  return 0;
}

void lerNumeros(int *array, int quantidade)
{
  int i, j, repetido;
  for (i = 0; i < quantidade; i++)
  {
    scanf("%d", &array[i]);
    if (array[i] < 1 || array[i] > 20)
    {
      printf("Número inválido. Deve estar entre 1 e 20.\n");
      i--;
      continue;
    }
    repetido = 0;
    for (j = 0; j < i; j++)
    {
      if (array[i] == array[j])
      {
        repetido = 1;
        break;
      }
    }
    if (repetido)
    {
      printf("Número repetido. Digite outro.\n");
      i--;
    }
  }
}
