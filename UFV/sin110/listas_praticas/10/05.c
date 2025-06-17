#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int EhVogal(char ch);

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

  fseek(arquivo, 0, SEEK_END);
  int tamanho = ftell(arquivo);
  rewind(arquivo);

  char *texto_original = malloc(tamanho + 1);
  char *novo_texto = malloc(tamanho + 1);
  if (texto_original == NULL || novo_texto == NULL)
  {
    printf("Falha ao alocar memoria.\n");
    fclose(arquivo);
    free(arq);
    exit(1);
  }

  fread(texto_original, 1, tamanho, arquivo);
  texto_original[tamanho] = '\0';

  fclose(arquivo);

  int i;
  for (i = 0; i < tamanho; i++)
  {
    if (EhVogal(texto_original[i]))
      novo_texto[i] = '*';
    else
      novo_texto[i] = texto_original[i];
  }
  novo_texto[tamanho] = '\0';

  FILE *novo_arquivo = fopen("arquivo_sem_vogal.txt", "w");
  if (novo_arquivo == NULL)
  {
    printf("Falha ao criar o arquivo.\n");
    free(texto_original);
    free(novo_texto);
    free(arq);
    exit(1);
  }

  fputs(novo_texto, novo_arquivo);
  fclose(novo_arquivo);

  free(texto_original);
  free(novo_texto);
  free(arq);

  return 0;
}

int EhVogal(char ch)
{
  ch = tolower(ch);
  if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return 1;
  return 0;
}
