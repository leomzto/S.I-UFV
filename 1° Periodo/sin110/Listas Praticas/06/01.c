#include <stdio.h>

struct Hora
{
    int horas;
    int minutos;
    int segundos;
};

int main(void)
{
    struct Hora horario;

    printf("Entre com a hora: ");
    scanf("%d", &horario.horas);

    printf("Entre com os minutos: ");
    scanf("%d", &horario.minutos);

    printf("Entre com os segundos: ");
    scanf("%d", &horario.segundos);

    printf("%d:%d:%d\n", horario.horas, horario.minutos, horario.segundos);

    return 0;
}
