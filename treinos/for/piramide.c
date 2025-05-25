#include <stdio.h>

int main(void)
{
    int tamanho;

    do
    {
        printf("Defina o tamanho da base da piramide: ");
        scanf("%d", &tamanho);
    }
    while (tamanho <= 0 || tamanho >= 10);

    // para quando a quantidade de linhas for menor que o tamanho pedido, adicione +1 linha
    for (int linha = 1; linha <= tamanho; linha++)
    {
        // adiciona os espaços antes dos "*" para formar a piramide
            // para quando a diferença entre o tamanho pedido e o numero de linhas for maior que o numero de espaços, adicione +1 espaço
        for (int e = 0; e < (tamanho - linha); e++)
        {
            printf(" ");
        }
        // adiciona os "*" a cada linha
            // para quando o numero de * for menor que o numero de linhas, adicione +1 "*"
        for (int asterisco = 0; asterisco < linha; asterisco++)
        {
            printf("*");
        }

        // printf(" "); // espaçamento entra as duas piramides

        //adiciona os numeros a cada linha
            // sendo inicialmente 1, quando o numero for menor ou igual ao numero de linhas, adicione +1 numero
                // ex: 1
                //     12       linha nova
                //     123      linha nova
        for (int num = 1; num <= linha; num++)
        {
            printf("%d", num);
        }

        printf("\n");
    }
}
