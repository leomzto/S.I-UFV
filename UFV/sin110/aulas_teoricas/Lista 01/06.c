// Escreva um programa que leia um número inteiro de obrigatoriamente quatro
// algarismos, ou seja, de 1000 a 9999 imprima 1 dígito por linha. Caso o usuário digite
// um valor fora do intervalo, deverá ser solicitado nova entrada do referido número
// enquanto o mesmo não estiver válido. Por fim, imprima na tela cada um dos
// algarismos do número, sendo um em cada linha.
//
// Exemplo de tela de saída:
// Entre com um número de quatro algarismos: 333
// Entre com um número de quatro algarismos: 2
// Entre com um número de quatro algarismos: 1234
// 1
// 2
// 3
// 4

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char numero[6];
    int num;

    do{
        printf("Entre com um número de quatro algarismos: ");
        fgets(numero, sizeof(numero), stdin);

        num = atoi(numero);

    }
    while (num < 1000 || num > 9999);

    for (int i = 0; i < 4; i++)
    {
        printf("%c\n", numero[i]);
    }

    return 0;
}
