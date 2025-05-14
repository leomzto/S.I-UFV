#include <stdio.h>

void tamanho(char *str, int *strsize);

int main(void)
{
    char String[100];
    int comprimento;

    printf("Entre com a string: ");
    fgets(String, sizeof(String), stdin);

    tamanho(String, &comprimento);

    printf("A string inserida possui: %d caracteres.\n", comprimento);

    return 0;
}

void tamanho(char *str, int *strsize)
{
    int comprimento = 0;

    while (str[comprimento] != '\0' && str[comprimento] != '\n')
        comprimento++;

    *strsize = comprimento;
}
