#include <stdio.h>

int main(void)
{

    int num = 1000;
    int p1, p2, soma_partes;

    while (num < 9999)
    {
        p1 = num / 100;
        p2 = num % 100;

        soma_partes = p1 + p2;

        if (soma_partes * soma_partes == num)
        {
            printf("%d\n", num);
        }

        num++;
    }

    return 0;
}
