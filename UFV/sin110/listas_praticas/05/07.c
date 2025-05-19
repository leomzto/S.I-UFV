#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char string[501], string_contra[501];
    int i, j;
    bool iguais = true;

    printf("Entre com uma string: ");
    fgets(string, sizeof(string), stdin);

    for (j = 0; string[j] != '\0' && string[j] != '\n'; j++);

    j--;

    for (i = 0; i < j; i++, j--)
        string_contra[i] = string[j];

    string_contra[i] = '\0';

    for (i = 0; string[i] != '\0' && string_contra[i] != '\0'; i++)
    {
        if (string[i] != string_contra[i])
        {
            iguais = false;
            break;
        }
    }

    if (iguais)
        printf("É um palindromo.\n");
    else
        printf("Não é um palindromo.\n");
    
    return 0;
}
