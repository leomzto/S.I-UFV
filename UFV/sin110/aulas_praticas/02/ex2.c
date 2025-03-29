#include <stdio.h>
#include <ctype.h>

int main(void) 
{
    char codigo;

    do
    {
    printf("Entre com um código de consumo energético (A | B | C | D | E): ");
    scanf(" %c", &codigo);
    codigo = toupper(codigo);

    if (codigo != 'A' && codigo != 'B' && codigo != 'C' && codigo != 'D' && codigo != 'E') 
    {
        printf("Inválido, tente novamente.\n");
    }

    } while (codigo != 'A' && codigo != 'B' && codigo != 'C' && codigo != 'D' && codigo != 'E');

    switch(codigo)
    {
        case 'A':
            printf("Ventilador, Televisão\n");
            break;
        case 'B':
            printf("Aparelho de som, Batedeira\n");
            break;
        case 'C':
            printf("Fogão elétrico, Liquidificador\n");
            break;
        case 'D':
            printf("Freezer, Geladeira, Máquina de Lavar\n");
            break;
        case 'E':
            printf("Ar-condicionado, Micro-ondas\n");
            break;
    }

    return 0;
}
