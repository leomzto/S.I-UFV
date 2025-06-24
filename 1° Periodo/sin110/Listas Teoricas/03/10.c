#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char nome[40];
  float nota_final;
} sDados;

int main(void)
{
  int alunos;
  printf("Digite o número de alunos: ");
  scanf("%d", &alunos);

  sDados *dados = malloc(alunos * sizeof(sDados));
  if (dados == NULL)
  {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  int i;
  for (i = 0; i < alunos; i++)
  {
    printf("Digite o nome do aluno %d: ", i + 1);
    scanf(" %[^\n]", dados[i].nome);
    printf("Digite a nota final do aluno %d: ", i + 1);
    scanf("%f", &dados[i].nota_final);
  }

  FILE *arquivo = fopen("alunos.bin", "ab");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    free(dados);
    return 1;
  }

  for (i = 0; i < alunos; i++)
    fwrite(&dados[i], sizeof(sDados), 1, arquivo);

  fclose(arquivo);
  free(dados);
  return 0;
}
