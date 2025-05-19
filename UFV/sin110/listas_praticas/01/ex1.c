#include <stdio.h>
#include <ctype.h>

int main (void)
{
    char con;
    float nota;

    printf("Entre com um conceito (A | B | C | D): ");
    scanf("%c", &con);

    printf("Informe a nota: ");
    scanf("%f", &nota);

    con = toupper(con);

    printf("Conceito: %c   |   Nota: %.2f\n", con, nota);

    return 0;
}
