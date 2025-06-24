#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
  char *arq = malloc(50 * sizeof(char));
  if(arq == NULL)
  {
    printf("Falha ao alocar memória.\n");
    exit(1);
  }

  printf("Entre com um arquivo .txt: ");
  fgets(arq, 50, stdin);
  arq[strcspn(arq, "\n")] = '\0';
  FILE *arquivo = fopen(arq, "r");
  if(arquivo == NULL)
  {
    printf("Falha ao abrir o arquivo.\n");
    free(arq);
    exit(1);
  }

  char ch;
  printf("Entre com um caractere: ");
  scanf("%c", &ch);
  ch = tolower(ch);

  int qtd = 0;
  int chars;
  while((chars = fgetc(arquivo)) != EOF)
  {
    if(tolower(chars) == ch)
      qtd++;
  }

  fclose(arquivo);
  printf("%c aparece  %d vezes em %s.\n", ch, qtd, arq);
  free(arq);

  return 0;
}
