// Escreva uma função recursiva que receba um número inteiro positivo e retorne a soma de seus dígitos

#include <stdio.h>

int somaDigitos(int n);

int main(void)
{
  int n;
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);

  int res = somaDigitos(n);
  printf("A soma dos dígitos de %d é %d\n", n, res);

  return 0;
}

int somaDigitos(int n)
{
  if (n == 0)
    return 0;
  else
    return (n % 10) + somaDigitos(n / 10);
}