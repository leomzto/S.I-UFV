#include <stdio.h>
#include <stdlib.h>

int calcular(int k, int n);

int main(void)
{
  int k, n;
  printf("Digite o valor de k: ");
  scanf("%d", &k);
  printf("Digite o valor de n: ");
  scanf("%d", &n);

  printf("Resultado: %d\n", calcular(k, n));

  return 0;
}

int calcular(int k, int n)
{
  if (n == 0)
    return 1;
  else if (n < 0)
    return 0;
  else
    return k * calcular(k, n - 1);
}
