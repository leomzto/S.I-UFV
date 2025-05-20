/*
Ex 7 – Média de Notas
Descrição: Leia as notas de 5 alunos, calcule e imprima a média geral.
Protótipo: float calcular_media(float notas[], int n);
*/

#include <stdio.h>

float calcular_media(float nota[], int n);

int main(void)
{
    float nota[5];
    float media;
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("Entre com a nota do %d° aluno: ", i+1);
        scanf("%f", &nota[i]);
    }

    media = calcular_media(nota, 5);

    printf("Media das notas: %.2f\n", media);

    return 0;
}

float calcular_media(float nota[], int n)
{
    float soma = 0.0;
    float media;
    int i;

    for(i = 0; i < n; i++)
        soma += nota[i];
    media = soma / n;

    return media;
}