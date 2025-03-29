#include <stdio.h>

int main (void)
{
    int n1, n2, n3, n4, n5;

    printf("Entre com a nota 1: ");
    scanf("%d", &n1);

    printf("Entre com a nota 2: ");
    scanf("%d", &n2);

    printf("Entre com a nota 3: ");
    scanf("%d", &n3);

    printf("Entre com a nota 4: ");
    scanf("%d", &n4);

    printf("Entre com a nota 5: ");
    scanf("%d", &n5);

    float md = (n1 + n2 + n3 + n4 + n5) / 5.0f;

    printf("A media de suas notas é: %.2f", md);

    return 0;
}
