#include <stdio.h>

int main(void)
{
  int a, b;
  printf("Digite dois numeros inteiros: ");
  scanf("%d %d", &a, &b);

  int *p_a = &a;
  int *p_b = &b;

  if (p_a > p_b)
    printf("Endereco de a: %p, Conteudo: %d\n", p_a, *p_a);
  else if (p_b > p_a)
    printf("Endereco de b: %p, Conteudo: %d\n", p_b, *p_b);
  else
    printf("Os enderecos sao iguais: %p, Conteudo: %d\n", p_a, *p_a);
  
}