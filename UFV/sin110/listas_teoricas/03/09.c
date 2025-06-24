#include <stdio.h>

int main(void)
{
  char arq[100];
  printf("Digite o nome do arquivo: ");
  fgets(arq, 100, stdin);
  arq[strcspn(arq, "\n")] = 0;
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  FILE *arquivo = fopen(arq, "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  
  int linhas = 0;
  char ch;

  while ((ch = fgetc(arquivo)) != EOF)
  {
    if (ch == '\n')
      linhas++;
  }

  fclose(arquivo);
  printf("O arquivo tem %d linhas.\n", linhas);

  return 0;
}
