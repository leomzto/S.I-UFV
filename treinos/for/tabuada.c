#include <stdio.h>

int main(void)
{
    int num = printf("Digite um número: ");
    scanf("%d", &num);

    for (int vezes = 0; vezes <= 10; vezes++)
    {
        int igual;
        for(int l = 0; l <= vezes; l++)
        {
            igual = num * l;
        }
        printf("%d x %d = %d\n", num, vezes, igual);
    }

    return 0;
}
