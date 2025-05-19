#include <stdio.h>
#include <ctype.h>

int ehVogal(char caracter);

int main(void)
{
    char string[501];
    int i;

    printf("Entre com uma string: ");
    fgets(string, sizeof(string), stdin);


    printf("Consoantes -> ");
    for (i = 0; string[i] != '\0' && string[i] != '\n'; i++)
    {
        if (isalpha(string[i]) && !ehVogal(string[i]))
            printf(" %c", string[i]);
    }
    printf("\n");

    return 0;
}

int ehVogal(char caracter)
{
    caracter = tolower(caracter);
    return (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u');
}
