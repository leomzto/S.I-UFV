// Crie uma função recursiva para retornar o n-ésimo termo da sequência de Fibonacci

#include <stdio.h>

int fibonacci(int n);

int main(void)
{
  int n;
  printf("Digite o termo da sequência de Fibonacci que deseja calcular: ");
  scanf("%d", &n);
  
  int fibo = fibonacci(n);
  printf("O %dº termo da sequência de Fibonacci é: %d\n", n, fibo);

  return 0;
}

int fibonacci(int n)
{
  if (n == 0 || n == 1)
    return n;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}