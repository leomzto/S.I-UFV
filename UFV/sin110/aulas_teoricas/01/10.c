// H(n) = 1 + 1/2 + 1/3 + 1/4 + … + 1/n
#include <stdio.h>

int main(void)
{
    double H = 0.0;
    int n;
    int i;

    printf("Insira um número para calcular seu harmonico: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        H += 1.0 / i;
    }

    printf("H(%d) = %.2f\n", n, H);
    
    return 0;
}
