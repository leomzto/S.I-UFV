#include <stdio.h>
#include <ctype.h>

void operacoes(float num1, float num2, int opcao);

int main(void)
{
    float num1, num2;
    char opcao;

    printf("Insira o 1° número: ");
    scanf("%f", &num1);

    printf("Insira o 2° número: ");
    scanf("%f", &num2);

    printf("Escolha a operação:\n");
    printf("A. Soma\nB. Subtração\nC. Multiplicação\nD. Divisão\n\nOpção: ");
    scanf(" %c", &opcao);

    opcao = tolower(opcao);

    operacoes(num1, num2, opcao);

    return 0;
}

void operacoes(float num1, float num2, int opcao)
{
    float resultado;

    switch(opcao)
    {
        case 'a':
            resultado = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 'b':
            resultado = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 'c':
            resultado = num1 * num2;
            printf("%.2f x %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 'd':
            resultado = num1 / num2;
            printf("%.2f ÷ %.2f = %.2f\n", num1, num2, resultado);
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
}