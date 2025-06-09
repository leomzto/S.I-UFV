#include <stdio.h>


int retornaMaior(int vetor[], int tamanho);

int main(void)
{
    int vetor[] = {1, 2, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    int maior = retornaMaior(vetor, tamanho);
    printf("O maior numero do vetor e: %d\n", maior);
    
    return 0;
}

int retornaMaior(int vetor[], int tamanho)
{
    if (tamanho == 1)
        return vetor[0];
    else
    {
        int maior = retornaMaior(vetor, tamanho - 1);
        return (vetor[tamanho - 1] > maior) ? vetor[tamanho - 1] : maior;
    }
}