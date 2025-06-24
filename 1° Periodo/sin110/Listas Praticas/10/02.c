#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int EhVogal(char c);

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

  int vogais = 0, consoantes = 0;
  int ch;
  while ((ch = fgetc(arquivo)) != EOF)
  {
    if (EhVogal(ch))
        vogais++;
    else if(isalpha(ch))
      consoantes++;
  }

  fclose(arquivo);
  printf("Vogais presentes em %s: %d\n", arq, vogais);
  printf("Consoantes presentes em %s: %d\n", arq, consoantes);
  free(arq);
  
  return 0;
}

int EhVogal(char c)
{
  c = tolower(c);
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      return 1;
  return 0;
}