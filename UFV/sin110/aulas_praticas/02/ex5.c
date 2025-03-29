// formula de Kaprekar para 4 digitos: (X+Y)² = 100X+Y  ( x e y sao numeros de 2 digitos cada um)
//
// 3025 ÷ 100 = 30.25
//
// 3025 / 100 = 30.0
// 3025 % 100 = 0.25
//
// 30 + 25 = 55 > 55 * 55 = 3025

#include <stdio.h>

int main(void)
{
    int num, p1, p2, soma_partes;

    printf("-= Verificação de Kaprekar =-\n");
    printf("Digite um número de 4 digitos: ");
    scanf("%d", &num);

    p1 = num / 100;
    p2 = num % 100;

    soma_partes = p1 + p2;

    printf("O número %d %s com as propriedades de Kaprekar\n",
        num, (soma_partes * soma_partes == num) ? "condiz" : "não condiz");

    return 0;
}