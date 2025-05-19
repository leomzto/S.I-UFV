// ℎ𝑖𝑝𝑜𝑡𝑒𝑛𝑢𝑠𝑎 = sqrt(𝑎² + 𝑏²)
#include <stdio.h>
#include <math.h>

float calcularHipotenusa(int n1, int n2);

int main(void)
{
    int cateto1, cateto2;
    printf("Entre com os catetos: ");
    scanf("%d %d", &cateto1, &cateto2);

    printf("Hipotenusa: %.2f\n", calcularHipotenusa(cateto1, cateto2));

    return 0;
}

float calcularHipotenusa(int n1, int n2)
{
    float a = pow(n1, 2);
    float b = pow(n2, 2);
    float hipotenusa = sqrt(a + b);

    return hipotenusa;
}