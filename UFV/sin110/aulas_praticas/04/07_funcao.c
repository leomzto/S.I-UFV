// trangulo pascal = linha! / (coluna! * (linha - coluna)!)

#include <stdio.h>

int fatorial(int numero);
int main(void)
{
    int qtd_linhas;
    int linha, coluna;
    int triangulo;

    printf("Digite o número de linhas: ");
    scanf("%d", &qtd_linhas);

    for (linha = 0; linha < qtd_linhas; linha++)
    {
        for (coluna = 0; coluna <= linha; coluna++)
        {
            int fatorial_linha = fatorial(linha);
            int fatorial_coluna = fatorial(coluna);
            int fatorial_linha_menos_coluna = fatorial(linha - coluna);

            triangulo = fatorial_linha / (fatorial_coluna * fatorial_linha_menos_coluna);

            printf("%d ", triangulo);
        }

        printf("\n");
    }

    return 0;
}

int fatorial(int numero)
{
    int fatoracao = 1;
    int i;
    for (i = 1; i <= numero; i++)
    {
        fatoracao *= i;
    }
    return fatoracao;
}
