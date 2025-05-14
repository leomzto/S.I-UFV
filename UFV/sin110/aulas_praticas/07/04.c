#include <stdio.h>
void consumoKmL(int km, int l);

int main(void)
{
    int km, l;
    
    printf("Entre com o Km: ");
    scanf("%d", &km);
    printf("Entre com os litros: ");
    scanf("%d", &l);

    printf("Consumo Km/L:\n %d/%d = %d\n", km, l, km/l);
    consumoKmL(km, l);

    return 0;
}

void consumoKmL(int km, int l)
{
    int consumo = km/l;

    if (consumo < 8)
        puts("Venda o carro");
    else if (consumo >= 8 && consumo <= 14)
        puts("Econômico!");
    else if(consumo > 14)
        puts("Super econômico");
}
