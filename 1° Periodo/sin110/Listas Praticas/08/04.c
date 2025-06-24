#include <stdio.h>

int main(void)
{
    int inteiro = 10;
    float real = 5.5;
    char caractere = 'A';

    int *p_inteiro = &inteiro;
    float *p_real = &real;
    char *p_caractere = &caractere;

    printf("Antes da modificacao:\n");
    printf("Inteiro: %d, Real: %.2f, Caractere: %c\n", inteiro, real, caractere);

    *p_inteiro += 5;
    *p_real *= 2;
    *p_caractere += 1;

    printf("Depois da modificacao:\n");
    printf("Inteiro: %d, Real: %.2f, Caractere: %c\n", inteiro, real, caractere);

    return 0;
}