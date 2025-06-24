#include <stdio.h>

char verificar_nota(float nota);

int main(void)
{
    int matricula;
    float nota;
    char conceito;

    printf("Entre com a matricula: ");
    scanf("%d", &matricula);

    printf("Digite sua nota: ");
    scanf("%f", &nota);

    conceito = verificar_nota(nota);

    printf("Aluno: %d\nConceito: %c\n", 
        matricula, conceito);

    return 0;
}

char verificar_nota(float nota)
{
    if (nota >= 9)
    {
        return 'A';
    }
    else if (nota >= 8 && nota < 9)
    {
        return 'B';
    }
    else if (nota >= 6 && nota < 8)
    {
        return 'C';
    }
    else if (nota >= 3 && nota < 6)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}
