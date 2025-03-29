#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char nome[100];

    printf("Qual o seu nome? ");
    scanf("%s", nome);

    printf("\nOla, %s\n", nome);
    sleep(2);

    return 0;
}
