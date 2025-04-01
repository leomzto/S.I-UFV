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

int main(void)
{
    int num;
    
    do
    {
        printf("Entre com um número de quatro algarismos: ");
        scanf("%d", &num);
    }
    while (num < 1000 || num > 9999);
    
    printf("%d\n", num / 1000);
    printf("%d\n", (num / 100) % 10);
    printf("%d\n", (num / 10) % 10);
    printf("%d\n", num % 10);
    
    return 0;
}