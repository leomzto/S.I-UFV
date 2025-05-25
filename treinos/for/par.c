#include <stdio.h>

int main(void)
{
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);


    printf("\nOs Seguinte números são pares: \n");
    for (int par = 0; par <= num; par += 2)
    {
        printf("%d ", par);
    }

    printf("\nOs Seguinte números são impares: \n");
    for (int impar = 1; impar <= num; impar+=2)
    {
        printf("%d ", impar);
    }
    printf("\n");

    return 0;
}
