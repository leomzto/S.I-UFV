// Escreva uma função recursiva que calcule o fatorial de um número inteiro positivo n

#include <stdio.h>

int fatorial(int n);

int main(void)
{
  int n;
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);

  int fat = fatorial(n);
  printf("Fatorial de %d é %d\n", n, fat);

  return 0;
}

int fatorial(int n)
{
  if (n == 0 || n == 1)
    return 1;
  else
    return n * fatorial(n - 1);
}
