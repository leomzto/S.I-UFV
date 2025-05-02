#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char nome[51], sobrenome[51], terceiro_nome[51];
    char concatenacao[153];
    int i = 0, j;

    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Sobrenome: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);

    printf("3° Nome: ");
    fgets(terceiro_nome, sizeof(terceiro_nome), stdin);

    for (j = 0; nome[j] != '\0' && nome[j] != '\n'; j++)
    {
        nome[0] = toupper(nome[0]);
        concatenacao[i++] = nome[j];
    }

    for (j = 0; sobrenome[j] != '\0' && sobrenome[j] != '\n'; j++)
    {
        sobrenome[0] = toupper(sobrenome[0]);
        concatenacao[i++] = sobrenome[j];
    }

    for (j = 0; terceiro_nome[j] != '\0' && terceiro_nome[j] != '\n'; j++)
    {
        terceiro_nome[0] = toupper(terceiro_nome[0]);
        concatenacao[i++] = terceiro_nome[j];
    }

    concatenacao[i] = '\0';

    printf("Concatenação: %s\n", concatenacao);

    return 0;
}
