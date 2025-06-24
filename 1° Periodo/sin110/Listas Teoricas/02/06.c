#include <stdio.h>

void preencheVetor(int *vet, int n);
void imprimeVetor(int *vet, int n);
int retornaMaiorElemento(int *vet, int n);

int main(void)
{
    int qtd = 5;
    int vet[qtd];

    preencheVetor(vet, qtd);
    printf("Vetor: ");
    imprimeVetor(vet, qtd);
    printf("Maior elemento: %d\n", retornaMaiorElemento(vet, qtd));

    return 0;
}

void preencheVetor(int *vet, int n)
{
    int i;
    
    for(i = 0; i < n; i++)
    {
        printf("Entre com o %d° valor: ", i + 1);
        scanf("%d", &vet[i]);
    }
    puts("");
}

void imprimeVetor(int *vet, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", vet[i]);
    puts("");
}

int retornaMaiorElemento(int *vet, int n)
{
    int maior = vet[0];
    int i;

    for(i = 1; i < n; i++)
    {
        if(vet[i] > maior)
            maior = vet[i];
    }

    return maior;
}