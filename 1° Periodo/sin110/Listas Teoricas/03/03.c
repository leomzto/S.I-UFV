#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int codigo;
  char nome[50];
  int estoque;
  float preco;
} sProdutos;

int main(void)
{
  int N;
  printf("Digite o número de produtos: ");
  scanf("%d", &N);

  sProdutos *produtos = malloc(N * sizeof(sProdutos));
  if (produtos == NULL)
  {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  int i;
  for (i = 0; i < N; i++)
  {
    printf("Digite o código do produto %d: ", i + 1);
    scanf("%d", &produtos[i].codigo);
    while (getchar() != '\n');
    printf("Digite o nome do produto %d: ", i + 1);
    fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
    produtos[i].nome[strcspn(produtos[i].nome, "\n")] = 0;
    printf("Digite o estoque do produto %d: ", i + 1);
    scanf("%d", &produtos[i].estoque);
    printf("Digite o preço do produto %d: ", i + 1);
    scanf("%f", &produtos[i].preco);
  }

  int maiorEstoque = produtos[0].estoque;
  float meiorPreco = produtos[0].preco;
  for (i = 1; i < N; i++)
  {
    if (produtos[i].preco > meiorPreco)
      meiorPreco = produtos[i].preco;

    if (produtos[i].estoque > maiorEstoque)
      maiorEstoque = produtos[i].estoque;
  }

  printf("Produto com maior estoque:\n");
  for (i = 0; i < N; i++)
  {
    if (produtos[i].estoque == maiorEstoque)
    {
      printf("Código: %d, Nome: %s, Estoque: %d, Preço: %.2f\n",
             produtos[i].codigo, produtos[i].nome,
             produtos[i].estoque, produtos[i].preco);
    }
  }
  printf("Produto com maior preço:\n");
  for (i = 0; i < N; i++)
  {
    if (produtos[i].preco == meiorPreco)
    {
      printf("Código: %d, Nome: %s, Estoque: %d, Preço: %.2f\n",
             produtos[i].codigo, produtos[i].nome,
             produtos[i].estoque, produtos[i].preco);
    }
  }

  free(produtos);
  
  return 0;
}
