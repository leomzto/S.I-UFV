#include <stdio.h>

int main(void)
{
    int l1, l2;

    printf("Insira os lados em CM:\n");

    printf("Lado 1: ");
    scanf("%d", &l1);

    printf("Lado 2: ");
    scanf("%d", &l2);

    int a = l1 * l2;

    printf("A area é: %dcm", a);

    return 0;
}
