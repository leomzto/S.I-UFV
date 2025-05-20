/*
Ex 9 – Struct Produto
Descrição: Crie uma struct Produto com nome, preço e quantidade. Leia 3 produtos e mostre o nome do mais caro.
Protótipo: int mais_caro(Produto lista[], int n);
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void maisCaro(Produto produto[], int n);

int main(void)
{
    Produto p[3];
    int i;

    puts("Cadastro de produtos ->");
    for(i = 0; i < 3; i++)
    {
        printf("Produto: ");
        fgets(p[i].nome, sizeof(p[i].nome), stdin);
        p[i].nome[strcspn(p[i].nome, "\n")] = '\0';
        printf("Preço: R$");
        scanf("%f", &p[i].preco);
        printf("Quantidade: ");
        scanf("%d", &p[i].quantidade);
        while(getchar() != '\n');
    }

    maisCaro(p, 3);
}

void maisCaro(Produto produto[], int n)
{
    int i, mais_caro = 0;

    for(i = 0; i < n; i++)
    {
        if(produto[i].preco > produto[mais_caro].preco)
            mais_caro = i;
    }

    printf("Produto mais caro ->\n%s - R$%.2f\n", produto[mais_caro].nome, produto[mais_caro].preco);
}