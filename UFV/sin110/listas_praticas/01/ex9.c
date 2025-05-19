#include <stdio.h>

int main (void)
{
    float sal;

    printf("Entre com o salario: ");
    scanf("%f", &sal);

    float reaj = (sal / 100) * 25;
    float novo_sal = sal + reaj;
    float dif = novo_sal - sal;

    printf("Com um reajuste, seu salario sobe de R$%.2f para R$%.2f. Com uma diferença de R$%.2f", sal, novo_sal, dif);

    return 0;
}
