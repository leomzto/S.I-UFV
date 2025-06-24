#include <stdio.h>

int potencia(int base, int expoente);
int fatorialExponencial(int n);

int main(void)
{
  int n;
  printf("Digite o valor de n: ");
  scanf("%d", &n);

  printf("Fatorial exponencial de %d: %d\n", n, fatorialExponencial(n));

  return 0;
}

int potencia(int base, int expoente)
{
  int resultado = 1;
  int i;
  for (i = 0; i < expoente; i++)
    resultado *= base;
  return resultado;
}

int fatorialExponencial(int n)
{
  if (n == 1)
    return 1;
  else
    return potencia(n, fatorialExponencial(n - 1));
}
