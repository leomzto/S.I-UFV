#include <stdio.h>

int main(void)
{
    int ent;
    float sal;

    printf("Ano em que entrou: ");
    scanf("%d", &ent);

    printf("Salario: ");
    scanf("%f", &sal);

    printf("\nAno de entrada: %d \nSalario: %.2f\n", ent, sal);

    return 0;
}
