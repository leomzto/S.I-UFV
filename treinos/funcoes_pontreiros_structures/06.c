#include <stdio.h>

void stringlenght(char *string, int *stringsize);

int main(void)
{
    char frase[] = "exemplo teste";
    int tamanhoString;

    stringlenght(frase, &tamanhoString);

    printf("%s possui %d caracteres.\n", frase, tamanhoString);


    return 0;
}

void stringlenght(char *string, int *stringsize)
{
    int contagem = 0;

    while(string[contagem] != '\0' && string[contagem] != '\n' && string[contagem != ' '])
        contagem++;

    *stringsize = contagem;
}