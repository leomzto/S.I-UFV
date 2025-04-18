// triangulo de floyd = n ( n 2 + 1)/2
#include <stdio.h>

int main(void)
{
    int qtd_linhas;
    int linha, coluna;
    int numero = 1;

    printf("Quantidade de linhas: ");
    scanf("%d", &qtd_linhas);

    for(linha = 0; linha < qtd_linhas; linha++)
    {
        for(coluna = 0; coluna <= linha; coluna++)
        {
            printf("%d ", numero);
            numero++;
        }
        printf("\n");
    }
}
