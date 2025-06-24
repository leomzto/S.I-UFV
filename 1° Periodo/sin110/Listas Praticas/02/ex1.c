#include <stdio.h>

void verifica(int num1, int num2);

int main(void)
{
    int num1, num2;

    printf("Digite o 1° número: ");
    scanf("%d", &num1);

    printf("Digite o 2° número: ");
    scanf("%d", &num2);

    verifica(num1, num2);

    return 0; 
}

void verifica(int num1, int num2)
{
    int maior, menor;

    if (num1 < num2)
    {
        menor = num1;
        maior = num2;
    }
    else
    {
        menor = num2;
        maior = num1;
    }

    printf("%d é %s e %s\n",
    num1,
    (num1 % 2 == 0) ? "par" : "impar",
    (num1 == maior) ? "maior" : "menor");


    printf("%d é %s e %s\n",
    num2,
    (num2 % 2 == 0) ? "par" : "impar",
    (num2 == menor) ? "menor" : "maior");
}