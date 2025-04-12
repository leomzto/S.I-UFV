#include <stdio.h>

int main(void)
{
    int a[10];
    int b[10];
    int c[10];
    int i;

    printf("Entre com 10 números: ");
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    printf("Entre com mais 10 números: ");
    for(i = 0; i < 10; i++)
        scanf("%d", &b[i]);

    for(i = 0; i < 10; i++)
    {
        c[i] = a[i] - b[i];
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
