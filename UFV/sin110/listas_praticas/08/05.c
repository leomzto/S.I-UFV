#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    int *p_a = &a;
    int *p_b = &b;
    printf("Endereco de a: %p\n", p_a);
    printf("Endereco de b: %p\n", p_b); 

    if(p_a > p_b)
    {
        printf("O endereco de a (%p) e maior que o endereco de b (%p)\n", (void*)p_a, p_b);
    }
    else if(p_b > p_a)
    {
        printf("O endereco de b (%p) e maior que o endereco de a (%p)\n", (void*)p_b, p_a);
    }
    else
        printf("Os enderecos sao iguais: %p\n", p_a);
}