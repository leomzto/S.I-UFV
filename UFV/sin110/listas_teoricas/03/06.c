#include <stdio.h>
#include <stdlib.h>

int catalan(int n);

int main(void) {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Número de Catalan para n = %d: %d\n", n, catalan(n));

    return 0;
}

int catalan(int n)
{
  int i;
  if (n == 0)
    return 1;
  else if (n > 0)
  {
    int resultado = 0;
    for (i = 0; i < n; i++)   
      resultado += catalan(i) * catalan(n - 1 - i);
    return resultado;
  }
  return 0;
}
