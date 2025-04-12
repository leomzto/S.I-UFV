// trangulo pascal = linha! / (coluna! * (linha - coluna)!)

#include <stdio.h>

int main(void)
{
    int qtd_linhas;
    int linha, coluna;
    int i;
    int fatorial_linha, fatorial_coluna, fatorial_linha_menos_coluna;
    int triangulo;

    printf("Digite o número de linhas: ");
    scanf("%d", &qtd_linhas);

    for (linha = 0; linha < qtd_linhas; linha++)
    {
        for (coluna = 0; coluna <= linha; coluna++)
        {
            fatorial_linha = 1;
            fatorial_coluna = 1;
            fatorial_linha_menos_coluna = 1;
    
            for (i = 1; i <= linha; i++)
                fatorial_linha *= i;

            for (i = 1; i <= coluna; i++)
                fatorial_coluna *= i;

            for (i = 1; i <= (linha - coluna); i++)
                fatorial_linha_menos_coluna *= i;

            triangulo = fatorial_linha / (fatorial_coluna * fatorial_linha_menos_coluna);

            printf("%d ", triangulo);
        }

        printf("\n");
    }

    return 0;
}
