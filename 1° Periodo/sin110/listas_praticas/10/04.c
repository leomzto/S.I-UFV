#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void contar_letras(int ch, int letras[]);

int main(void)
{
  char *arq = malloc(50 * sizeof(char));
  if(arq == NULL)
  {
    printf("Falha ao alocar memoria.\n");
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

  int letras[26] = {0};
  int ch;
  while((ch = fgetc(arquivo)) != EOF)
  {
    if(isalpha(ch))
      contar_letras(tolower(ch), letras);
  }

  fclose(arquivo);
  int i;
  for(i = 0; i < 26; i++)
    printf("%c: %d\n", 'A' + i, letras[i]);
  free(arq);

  return 0;
}

void contar_letras(int ch, int letras[])
{
  if(ch >= 'a' && ch <= 'z')
    letras[ch - 'a']++;
}
