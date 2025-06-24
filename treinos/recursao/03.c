// Implemente uma função recursiva que calcule base^expoente

#include <stdio.h>

int potencia(int base, int expoente);

int main(void)
{
  int base, expoente;
  printf("Digite a base: ");
  scanf("%d", &base);
  printf("Digite o expoente: ");
  scanf("%d", &expoente);

  int res = potencia(base, expoente);
  printf("%d^%d = %d\n", base, expoente, res);

  return 0;
}

int potencia(int base, int expoente)
{
  if (expoente == 0)
    return 1;
  else
    return base * potencia(base, expoente - 1);
}