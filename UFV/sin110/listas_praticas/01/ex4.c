#include <stdio.h>

int main(void)
{
    char nome[100];
    int mat, idd;

    printf("Insira seu nome: ");
    scanf("%s", &nome);

    printf("Insira sua matricula: ");
    scanf("%d", &mat);

    printf("Insira sua idade: ");
    scanf("%d", &idd);

    printf("\nNome: %s\nMatricula: %d\nIdade: %d anos\n", nome, mat, idd);

    return 0;
}
