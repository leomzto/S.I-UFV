#include <stdio.h>

typedef struct
{
    float x, y, z;
} Vetor;

void soma(Vetor *v1, Vetor *v2, Vetor *res);

int main(void)
{
    Vetor v1 = {1, 2, 3};
    Vetor v2 = {4, 5, 6};
    Vetor resultado;

    soma(&v1, &v2, &resultado);

    printf("Resultado da soma dos vetores: %.1fx, %.1fy, %.1fz\n", resultado.x, resultado.y, resultado.z);

    return 0;
}

void soma(Vetor *v1, Vetor *v2, Vetor *res)
{
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
}
