#include <stdio.h>

int trocar(int *a, int *b);

int main(void)
{
    int a, b;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);

    printf("Antes da troca: a = %d, b = %d\n", a, b);
    trocar(&a, &b);
    printf("Depois da troca: a = %d, b = %d\n", a, b);

    return 0;
}

int trocar(int *a, int *b)
{
    int temp = *a; 
    *a = *b;      
    *b = temp;    
    return 0;
}