#include <stdio.h>

int main(void)
{
    int num[8];
    int i, x, y;
    int soma = 0;

    printf("Entre com 8 números: ");
    for (i = 0; i < 8; i++) 
    {
        scanf("%d", &num[i]);
    }

    printf("Entre com a posição do 1° e do 2° número desejado: ");
    scanf("%d%*[, ]%d", &x, &y);

    if (x < 1 || x > 8 || y < 1 || y > 8)
    {
        printf("Posições inválidas.\n");
        return 1;
    }

    x -= 1;
    y -= 1;

    soma = num[x] + num[y];

    printf("%d + %d = %d \n", num[x], num[y], soma);

    return 0;
}
