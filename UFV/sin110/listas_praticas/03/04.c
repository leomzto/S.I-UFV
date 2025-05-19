#include <stdio.h>

int main(void)
{

int dividendo;
int divisor = 1;

printf("Insira um número para descobrir seus divisores: ");
scanf("%d", &dividendo);

while (divisor <= dividendo)
{
    if (dividendo % divisor == 0)
    {
        printf("%d ", divisor);
    }
    divisor++;
}

printf("\n");

    return 0;
}
