#include <stdio.h>

int somar(int *vetor, int tamanho);

int main(void)
{
    int vet[5] = {'1', '2', '3', '4', '5'};

    printf("Soma dos 5 elementos do vetor: %d\n", somar(vet, 5));
    return 0;
}

int somar(int *vetor, int tamanho)
{
    int i;
    int soma = 0;

    for (i = 0; i <= tamanho; i++)
        soma += i;

    return soma;
}