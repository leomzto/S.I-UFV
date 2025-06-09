#include <stdio.h>

void soma(int *a, int *b);

int main(void)
{
  int a, b;
  printf("Digite dois numeros inteiros: ");
  scanf("%d %d", &a, &b);
  printf("Soma entre %d e %d: ", a, b);
  soma(&a, &b);
  printf("%d\n", a);
  
  return 0;
}

void soma(int *a, int *b)
{
  *a += *b;
}