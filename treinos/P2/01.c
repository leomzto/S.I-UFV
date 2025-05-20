/*
Ex 1:
Protótipo: float calcula_media(int v[], int n);
Descrição: Codifique uma função que calcula a média simples de um vetor de inteiros.
Fórmula da média:
Média = (soma dos valores) / (quantidade de valores)
No main, leia 5 números, chame a função e imprima a média.
*/

#include <stdio.h>

float calcula_media(int v[], int n);

int main(void)
{
    int vet[5];
    float media;
    int i;

    puts("Preencher vetor ->");
    for(i = 0; i < 5; i++)
    {
        printf("Entre com vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    media = calcula_media(vet, 5);
    printf("Media do vetor: %.2f\n", media);

    return 0;
}
float calcula_media(int v[], int n)
{
    int soma = 0;
    float media = 0.0;
    int i;

    for(i = 0; i < n; i++)
        soma += v[i];
    media = (float)soma / n;

    return media;
}