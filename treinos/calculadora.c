#include <stdio.h>
#include <math.h>

int fatorial(int n);
float soma(int numeros[], int qtd);
float subtracao(int numeros[], int qtd);
float multiplicacao(int numeros[], int qtd);
float divisao(int numeros[], int qtd);
float exponenciacao(int base, int expoente);
void raiz(int numeros[], int qtd);
void verificarParImpar(int numeros[], int qtd);
void verificarPrimos(int numeros[], int qtd);
void conversorDeBase(int numero);
int calcularMDC(int a, int b);
int calcularMMC(int a, int b);
float porcentagem(int parte, int total);
float mediaAritmetica(int numeros[], int qtd);

int main(void)
{
    int qtd, i;
    printf("Quantos números você deseja inserir? > ");
    scanf("%d", &qtd);

    int numeros[qtd];
    for (i = 0; i < qtd; i++)
    {
        printf("Insira o %d° número: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int operacao;
    int escolha;
    int resultado_fat;
    float resultado;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        printf("\nCalculadora:\n");
        printf("1. Soma\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Fatoração\n6. Exponenciação\n7. Raiz\n");
        printf("8. Par ou ímpar\n9. Primos\n10. Conversor de base\n11. MDC\n12. MMC\n13. Porcentagem\n14. Média aritmética\n");
        printf("Escolha a operação: ");
        scanf("%d", &operacao);

        switch (operacao)
        {
            case 1:
                resultado = soma(numeros, qtd);
                for (i = 0; i < qtd; i++) {
                    printf("%d", numeros[i]);
                    if (i < qtd - 1) printf(" + ");
                }
                printf(" = %.2f\n", resultado);
                break;

            case 2:
                resultado = subtracao(numeros, qtd);
                for (i = 0; i < qtd; i++) {
                    printf("%d", numeros[i]);
                    if (i < qtd - 1) printf(" - ");
                }
                printf(" = %.2f\n", resultado);
                break;

            case 3:
                resultado = multiplicacao(numeros, qtd);
                for (i = 0; i < qtd; i++) {
                    printf("%d", numeros[i]);
                    if (i < qtd - 1) printf(" * ");
                }
                printf(" = %.2f\n", resultado);
                break;

            case 4:
                resultado = divisao(numeros, qtd);
                if (resultado != -1) {
                    for (i = 0; i < qtd; i++) {
                        printf("%d", numeros[i]);
                        if (i < qtd - 1) printf(" / ");
                    }
                    printf(" = %.2f\n", resultado);
                } else {
                    printf("Erro: divisão por zero.\n");
                }
                break;

            case 5:
                printf("Qual dos números você quer calcular o fatorial?\n");
                for (i = 0; i < qtd; i++)
                    printf("%d. %d\n", i + 1, numeros[i]);
                printf(">>>>> ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= qtd) {
                    resultado_fat = fatorial(numeros[escolha - 1]);
                    printf("%d! = %d\n", numeros[escolha - 1], resultado_fat);
                } else {
                    printf("Escolha inválida.\n");
                }
                break;

            case 6:
                printf("Escolha uma base:\n");
                for (i = 0; i < qtd; i++)
                    printf("%d. %d\n", i + 1, numeros[i]);
                printf(">>>>> ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= qtd) {
                    int expoente;
                    printf("Digite o expoente: ");
                    scanf("%d", &expoente);
                    resultado = exponenciacao(numeros[escolha - 1], expoente);
                    printf("%d^%d = %.2f\n", numeros[escolha - 1], expoente, resultado);
                } else {
                    printf("Escolha inválida.\n");
                }
                break;

            case 7:
                raiz(numeros, qtd);
                break;

            case 8:
                verificarParImpar(numeros, qtd);
                break;

            case 9:
                verificarPrimos(numeros, qtd);
                break;

            case 10:
                printf("Escolha um número para converter: \n");
                for (i = 0; i < qtd; i++)
                    printf("%d. %d\n", i + 1, numeros[i]);
                printf(">>>>> ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= qtd) {
                    conversorDeBase(numeros[escolha - 1]);
                } else {
                    printf("Escolha inválida.\n");
                }
                break;

            case 11:
                printf("Digite dois números para calcular o MDC:\n");
                int a, b;
                scanf("%d %d", &a, &b);
                printf("MDC(%d, %d) = %d\n", a, b, calcularMDC(a, b));
                break;

            case 12:
                printf("Digite dois números para calcular o MMC:\n");
                scanf("%d %d", &a, &b);
                printf("MMC(%d, %d) = %d\n", a, b, calcularMMC(a, b));
                break;

            case 13:
                printf("Digite a parte e o total (Ex: 20 de 80): ");
                scanf("%d %d", &a, &b);
                printf("%d é %.2f%% de %d\n", a, porcentagem(a, b), b);
                break;

            case 14:
                printf("Média dos números: %.2f\n", mediaAritmetica(numeros, qtd));
                break;

            default:
                printf("Opção inválida.\n");
        }

        printf("\nDeseja continuar? (s/n): ");
        scanf(" %c", &continuar);
    }

    printf("Encerrando o programa...\n");
    return 0;
}

int fatorial(int n)
{
    int resultado = 1;
    for (int i = 2; i <= n; i++) resultado *= i;
    return resultado;
}

float soma(int numeros[], int qtd)
{
    float r = 0;
    int i;
    for (i = 0; i < qtd; i++) r += numeros[i];
    return r;
}

float subtracao(int numeros[], int qtd)
{
    float r = numeros[0];
    int i;
    for (i = 1; i < qtd; i++) r -= numeros[i];
    return r;
}

float multiplicacao(int numeros[], int qtd)
{
    float r = 1;
    int i;
    for (i = 0; i < qtd; i++) r *= numeros[i];
    return r;
}

float divisao(int numeros[], int qtd)
{
    if (numeros[0] == 0) return -1;
    float r = numeros[0];
    int i;
    for (i = 1; i < qtd; i++) {
        if (numeros[i] == 0) return -1;
        r /= numeros[i];
    }
    return r;
}

float exponenciacao(int base, int expoente)
{
    return pow(base, expoente);
}

void raiz(int numeros[], int qtd)
{
    int i;
    for (i = 0; i < qtd; i++) {
        if (numeros[i] < 0)
            printf("Raiz de %d: erro (negativo)\n", numeros[i]);
        else
            printf("Raiz de %d = %.2f\n", numeros[i], sqrt(numeros[i]));
    }
}

void verificarParImpar(int numeros[], int qtd)
{
    int i;
    printf("\nSão pares: ");
    for (i = 0; i < qtd; i++) {
        if (numeros[i] % 2 == 0)
            printf("%d ", numeros[i]);
    }

    printf("\nSão ímpares: ");
    for (i = 0; i < qtd; i++) {
        if (numeros[i] % 2 != 0)
            printf("%d ", numeros[i]);
    }
    printf("\n");
}

void verificarPrimos(int numeros[], int qtd)
{
    int i;
    printf("\nSão primos: ");
    for (i = 0; i < qtd; i++) {
        int n = numeros[i], primo = 1, j;
        if (n <= 1) primo = 0;
        for (j = 2; j <= sqrt(n); j++) {
            if (n % j == 0) {
                primo = 0;
                break;
            }
        }
        if (primo)
            printf("%d ", n);
    }
    printf("\n");
}

void conversorDeBase(int numero)
{
    int i;
    printf("Decimal: %d\n", numero);
    printf("Binário: ");
    for (i = 31; i >= 0; i--) {
        printf("%d", (numero >> i) & 1);
    }
    printf("\nOctal: %o\n", numero);
    printf("Hexadecimal: %X\n", numero);
}

int calcularMDC(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int calcularMMC(int a, int b)
{
    return (a * b) / calcularMDC(a, b);
}

float porcentagem(int parte, int total)
{
    return ((float)parte / total) * 100;
}

float mediaAritmetica(int numeros[], int qtd)
{
    float total = 0;
    int i;
    for (i = 0; i < qtd; i++) total += numeros[i];
    return total / qtd;
}
