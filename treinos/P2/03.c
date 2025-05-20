/*
Ex 3:
Protótipo: void dobra_valores(int v[], int n);
Descrição: Codifique uma função que dobra cada valor do vetor.
No main, leia 4 números, chame a função e imprima o vetor alterado.
*/

#include <stdio.h>

void dobra_valores(int v[], int n);

int main(void)
{
    int vet[4];
    int i;

    puts("Preencher vetor ->");
    for(i = 0; i < 4; i++)
    {
        printf("Entre com o valor de vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("Vetor: {");
    for(i = 0; i < 4; i++)
    {
        printf("%d", vet[i]);
        if(i < 3)
            printf(", ");
    }
    puts("}");
    

    printf("Vetor * 2: {");
    dobra_valores(vet, 4);

    return 0;
}

void dobra_valores(int v[], int n)
{
    int i;
    
    for(i = 0; i < n; i++)
    {
        v[i] *= 2;
        printf("%d", v[i]);
        if(i < n - 1)
            printf(", ");
    }
    puts("}");

}