/*
Ex 10 – Contar Vogais
Descrição: Leia uma string com fgets e conte quantas vogais existem.
Protótipo: int contar_vogais(char str[]);
*/

#include <stdio.h>
#include <string.h>

int EhVogal(char string[]);

int main(void)
{
    char string[100];

    printf("Entre com a string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    printf("Quantidade de vogais presentes: %d.\n", EhVogal(string));

    return 0;
}

int EhVogal(char string[])
{
    char vogais[] = {"aeiouAEIOU"};
    int encontrou= 0;
    int i;

    for(i = 0; i < strlen(string); i++)
    {
        if(strchr(vogais, string[i]) != NULL)
            encontrou++;
    }
    return encontrou;
}