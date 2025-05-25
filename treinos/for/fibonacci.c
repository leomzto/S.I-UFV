// 0,1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, ...
// a sequencia se baseia em:
// 1° termo é 0
// 2° termo é 1
// o proximo termo é a soma dos 2 ultimos
// no caso, t1 = 0 | t2 = 1 | t3 = 0+1 --> t3 = 1
// t4 --> t3 + t2 --> 1 + 1 --> t4 = 2
// e assim vai.

#include <stdio.h>

int main(void)
{
    int qtd;
    int termo1 = 0, termo2 = 1, termox;

    printf("Quantos termos você deseja ver? ");
    scanf("%d", &qtd);

    printf("Sequencia de FIBONACCI:\n");

    for (int termos = 0; termos < qtd; termos++)
    {
        printf("%d ", termo1);
        termox = termo1 + termo2; // proximo termo é a soma dos dois ultimos
        termo1 = termo2; // termo 1 passa a ser o termo 2
        termo2 = termox; // o termo 2 passa a ser o proximo termo
    }
    printf("\n");

    return 0;
}
