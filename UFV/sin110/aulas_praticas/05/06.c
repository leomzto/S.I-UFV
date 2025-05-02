#include <stdio.h>
#include <ctype.h>


int ehVogal(char caracter);

int main(void)
{
    char string[501];
    int i, qtd_vogal = 0, qtd_nao_vogal = 0;
    int minimo = 10;
    int tam = 0;

    printf("Digite uma string[10]: ");
    fgets(string, sizeof(string), stdin);

    while (string[tam] != '\0')
        tam++;

    if (tam < minimo)
    {
        printf("String muito pequena, deve ter no minimo 10 caracteres.\n");
        
        return 1;
    }

    printf("Vogais -> ");
    for (i = 0; string[i] != '\0'; i++)
    {
        if(ehVogal(string[i]))
        {
            printf(" %c ", string[i]);
            qtd_vogal++;
        }
        else
        {
            if (isalpha(string[i]))
                qtd_nao_vogal++;
        }
    }
    printf("\n");

    printf("Quantidade de vogais: %d\n", qtd_vogal);
    printf("Quantidade de não vogais: %d\n", qtd_nao_vogal);

    return 0;
}

int ehVogal(char caracter)
{
    caracter = tolower(caracter);
    return (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u');
}
