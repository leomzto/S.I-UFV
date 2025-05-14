#include <stdio.h>

float retornaMenor(float n1, float n2);

int main(void)
{
    float n1, n2;

    printf("Entre com dois números.\nFormatação: n1 n2:\n >>> ");
    scanf("%f %f", &n1, &n2);

    printf("O menor número entre %.2f e %.2f é: %.2f\n", n1, n2, retornaMenor(n1, n2));
    
    return 0;
}

float retornaMenor(float n1, float n2)
{
    float menor = n1;
    if (n2 < menor)
        menor = n2;

    return menor;
}
