#include <stdio.h>

long hiper_factorial(int n);

int main(void)
{
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    long result = hiper_factorial(n);
    printf("Hiper-fatorial de %d: %ld\n", n, result);

    return 0;
}

long hiper_factorial(int n)
{
    if (n <= 1)
        return 1;
    else
    {
        long pow = 1;
        for (int i = 0; i < n; i++)
            pow *= n;
        return pow * hiper_factorial(n - 1);
    }
}
