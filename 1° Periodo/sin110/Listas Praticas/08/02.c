#include <stdio.h>

int mdc(int a, int b);

int main(void)
{
    int a, b;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);

    int result = mdc(a, b);
    printf("MDC de %d e %d: %d\n", a, b, result);

    return 0;
}

int mdc(int a, int b)
{
    if (b == 0)
        return a;
    else
        return mdc(b, a % b);
}