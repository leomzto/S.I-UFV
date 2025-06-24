#include <stdio.h>

int main(void)
{
    int qtd_residencias;
    float valor_kwh, consumo_kwh;

    int residencia = 1;

    float soma = 0.0;
    float maior, menor;

    printf("Insira a quantidade de residencias na rua: ");
    scanf("%d", &qtd_residencias);

    printf("Preço do kWh: R$");
    scanf("%f", &valor_kwh);

    do
    {
        printf("Insira o valor de consumo da residencia %d: ", residencia);
        scanf("%f", &consumo_kwh);
        soma += consumo_kwh;

        if (residencia == 1)
        {
            maior = menor = consumo_kwh;
        }
        else
        {
            if (consumo_kwh > maior)
            {
                maior = consumo_kwh;
            }

            if (consumo_kwh < menor)
            {
                menor = consumo_kwh;
            }
        }

        residencia++;
    }
    while (residencia <= qtd_residencias);

    float media_consumo = soma / qtd_residencias;

    printf("Consumo médio: %.2f\n", media_consumo);
    printf("Maior consumo: %.2f\n", maior);
    printf("Menor consumo: %.2f\n", menor);

    return 0;
}
