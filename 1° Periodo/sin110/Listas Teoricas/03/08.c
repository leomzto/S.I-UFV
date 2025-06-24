#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *arquivo = fopen("arq.txt", "a");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  char ch;
  while (1)
  {
    printf("Digite um caractere (0 para parar): ");
    scanf(" %c", &ch);

    if (ch == '0')
      break;

    fprintf(arquivo, "%c\n", ch);
  }

  fclose(arquivo);
  return 0;
}
