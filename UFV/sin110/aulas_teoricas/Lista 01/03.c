// Faça um programa que calcule e escreva o valor de S:
// S = 1/1 + 3/2 = 5/3 + 7/4 + 9/5 ........ + 99/50

#include <stdio.h>

int main(void)
{
    double S = 0;
    int limite_denominador;
    
    printf("Qual o limite do denominador? ");
    scanf("%d", &limite_denominador);

    printf("\nS ->\n");
    for (int denominador = 1, numerador = 1; denominador <= limite_denominador; denominador++, numerador +=2)
    {
        printf("%d/%d", numerador, denominador);
        if (denominador < limite_denominador)
            printf(" +\n");

        S += (double) numerador / denominador;
    }
    printf("\nS = %.2f\n", S);

    return 0;
}
