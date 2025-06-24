#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int qtd;
  char **nomes = NULL;

  printf("Menu de nomes:\n");
  printf("[1]. Gravar um nome em uma linha\n");
  printf("[2]. Apagar um nome contido em uma linha\n");
  printf("[3]. Informar um nome, procurar onde esta e se encontrar, trocar por outro\n");
  printf("[4]. Informar um nome, procurar onde esta e se encontrar, apagar\n");
  printf("[5]. Recuperar um nome contido em uma linha\n");
  int opcao;
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);
  if (opcao < 1 || opcao > 5)
  {
    printf("Opção inválida.\n");
    return 1;
  }
  switch (opcao)
  {
    case 1:
      {
        printf("Informe a quantidade de nomes: ");
        scanf("%d", &qtd);
        nomes = malloc(qtd * sizeof(char *));
        if (nomes == NULL)
        {
          printf("Falha ao alocar memória.\n");
          exit(1);
        }
        int i, j;
        for (i = 0; i < qtd; i++)
        {
          nomes[i] = malloc(31 * sizeof(char));
          if (nomes[i] == NULL)
          {
            printf("Falha ao alocar memória.\n");
            for (j = 0; j < i; j++)
              free(nomes[j]);
            free(nomes);
            exit(1);
          }
        } 

        for (i = 0; i < qtd; i++)
        {
          printf("Informe o nome %d: ", i + 1);
          scanf("%s", nomes[i]);
        }
        printf("Nomes gravados com sucesso!\n");

        break;
      }
      case 2:
      {
        if (nomes == NULL || qtd <= 0)
        {
            printf("Nenhum nome foi gravado ainda.\n");
            break;
        }
        printf("Informe o nome a ser apagado: ");
        char nome[31];
        scanf("%s", nome);
        int encontrado = 0;
        for (int i = 0; i < qtd; i++)
        {
          if (strcmp(nomes[i], nome) == 0)
          {
            free(nomes[i]);
            nomes[i] = NULL;
            encontrado = 1;
            printf("Nome '%s' apagado com sucesso!\n", nome);
            break;
          }
        }

        break;
      }
      case 3:
      {
        if (nomes == NULL || qtd <= 0)
        {
            printf("Nenhum nome foi gravado ainda.\n");
            break;
        }
        printf("Informe o nome a ser trocado: ");
        char nomeAntigo[31], nomeNovo[31];
        scanf("%s", nomeAntigo);
        printf("Informe o novo nome: ");
        scanf("%s", nomeNovo);
        int encontrado = 0;
        for (int i = 0; i < qtd; i++)
        {
          if (nomes[i] != NULL && strcmp(nomes[i], nomeAntigo) == 0)
          {
            free(nomes[i]);
            nomes[i] = malloc(31 * sizeof(char));
            if (nomes[i] == NULL)
            {
              printf("Falha ao alocar memória.\n");
              exit(1);
            }
            strcpy(nomes[i], nomeNovo);
            encontrado = 1;
            printf("Nome '%s' trocado por '%s'.\n", nomeAntigo, nomeNovo);
            break;
          }
        }

        break;
      }
      case 4:
      {
        if (nomes == NULL || qtd <= 0)
        {
            printf("Nenhum nome foi gravado ainda.\n");
            break;
        }
        printf("Informe o nome a ser apagado: ");
        char nome[31];
        scanf("%s", nome);
        int encontrado = 0;
        for (int i = 0; i < qtd; i++)
        {
          if (nomes[i] != NULL && strcmp(nomes[i], nome) == 0)
          {
            free(nomes[i]);
            nomes[i] = NULL;
            encontrado = 1;
            printf("Nome '%s' apagado.\n", nome);
            break;
          }
        }
        if (!encontrado)
          printf("Nome '%s' não encontrado.\n", nome);

        break;
      }
      case 5:
      {
        if (nomes == NULL || qtd <= 0)
        {
            printf("Nenhum nome foi gravado ainda.\n");
            break;
        }
        printf("Informe o nome a ser recuperado: ");
        char nome[31];
        scanf("%s", nome);
        int encontrado = 0;
        for (int i = 0; i < qtd; i++)
        {
          if (nomes[i] != NULL && strcmp(nomes[i], nome) == 0)
          {
            printf("Nome '%s' encontrado na linha %d.\n", nome, i + 1);
            encontrado = 1;
            break;
          }
        }
        if (!encontrado)
          printf("Nome '%s' não encontrado.\n", nome);

        break;
      }
  }
  if (nomes != NULL)
  {
    for (int i = 0; i < qtd; i++)
    {
      if (nomes[i] != NULL)
        free(nomes[i]);
    }
    free(nomes);
  }
  return 0;
}
