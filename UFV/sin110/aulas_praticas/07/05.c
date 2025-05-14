#include <stdio.h>

void retornoSerie(int N);

int main(void)
{
    int N;
    
    printf("Insira o valor de N: ");
    scanf("%d", &N);

    retornoSerie(N);

    return 0;
}

void retornoSerie(int num)
{
    int N;
    float soma = 0.0;

    if (num <= 0) {
        puts("N deve ser maior que 0.");
        return;
    }

    printf("S = ");
    for (N = 1; N <= num; N++)
    {
        int numerador = (N * N) + 1;
        int denominador = N + 3;
        float formula = (float)numerador / denominador;
        
        soma += formula;
        
        printf("%d/%d", numerador, denominador);
        if (N < num) 
            printf(" + ");
    }
    
    printf("\nS = %.2f\n", soma);
}
