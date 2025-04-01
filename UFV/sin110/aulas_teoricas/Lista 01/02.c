// Faça um programa que calcule a diferença entre a soma dos quadrados dos
// primeiros 100 números naturais e o quadrado da soma, conforme exemplo abaixo:
//
// A soma dos quadrados dos dez primeiros é:
// 1² + 2² + ... + 10² = 385
//
// O quadrado da soma dos dez primeiros é:
// (1 + 2 + ... + 10)² = 55² = 3025
//
// A diferença entre a soma dos quadrados dos dez primeiros e o quadrado da soma é:
// 3025-385 = 2640

#include <stdio.h>
#include <math.h>

double soma_dos_quadrados();
double quadrado_da_soma();

int main(void)
{
    int primeiros = 100;

    double resultado_soma_quadrados = soma_dos_quadrados(primeiros);
    double resultado_quadrado_soma = quadrado_da_soma(primeiros);

    double resultado_diferenca = resultado_quadrado_soma - resultado_soma_quadrados;

    printf("A soma dos quadrados dos 100 primeiros números é: %.0f\n", resultado_soma_quadrados);
    printf("O quadrado da soma dos 100 primeiros números é: %.0f\n", resultado_quadrado_soma);

    printf("A diferença entre a soma dos quadrados e o quadrado da soma dos 100 primeiros números é: %.0f\n", resultado_diferenca);

    return 0;
}


double soma_dos_quadrados()
{
    double soma_quadrados = 0;

    for (double sq = 0; sq <= 100; sq++)
    {
        soma_quadrados += pow(sq, 2);
    }
    return soma_quadrados;
}

double quadrado_da_soma()
{
    double quadrado_soma = 0;

    for (double qs = 0; qs <= 100; qs++)
    {
        quadrado_soma += qs;
    }
    return pow(quadrado_soma, 2);
}
