#include <stdio.h>

int main(void)
{
    int num, fat = 1;

    printf("Digite um número: ");
    scanf("%d", &num);

    for (int f = num; f >= 1; f--)
    {
        fat *= f;
    }

    printf("fatorial de %d é: %d\n", num, fat);

    return 0;
}
