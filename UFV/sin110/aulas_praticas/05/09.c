#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char string[51];
    int i;
    int tam = 0;

    printf("Entre com seu nome completo: ");
    fgets(string, sizeof(string), stdin);

    for (i = 0; string[i] != '\0' && string[i] != '\n'; i++)
    {
        if (isalpha(string[i]) || isspace(string[i]))
            tam++;
    }

    printf("Quantidade de caracteres em seu nome (incluindo espaços): %d\n", tam);

    return 0;
}
