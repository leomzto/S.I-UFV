#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float altura, peso;   
} Pessoa;

float calculaIMC(Pessoa p);

int main(void)
{
    Pessoa pss[30];
    int i;

    for(i = 0; i < 30; i++)
    {
        printf("%d. Nome: ", i+1);
        fgets(pss[i].nome, sizeof(pss[i].nome), stdin);
        pss[i].nome[strcspn(pss[i].nome, "\n")] = '\0';
        

        printf("%d. Peso: ", i+1);
        scanf("%f", &pss[i].peso);

        printf("%d. ALtura: ", i+1);
        scanf("%f", &pss[i].altura);
        while(getchar() != '\n');
    
        printf("%d. IMC -> %.2f\n", i + 1, calculaIMC(pss[i]));
    }

    return 0;
}

float calculaIMC(Pessoa p)
{
    return p.peso / (p.altura * p.altura);
}