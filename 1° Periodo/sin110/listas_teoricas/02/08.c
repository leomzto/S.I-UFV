#include <stdio.h>

typedef struct
{
    float x, y;
} Ponto;

int dentroRet(Ponto *v1, Ponto *v2, Ponto *p);

int main(void)
{
    Ponto a = {0.0, 0.0};
    Ponto c = {6.0, 7.0};
    Ponto p;
    int resposta;

    printf("Entre com o ponto p (x, y): ");
    scanf("%f, %f", &p.x, &p.y);

    resposta = dentroRet(&a, &c, &p);

    if(resposta == -1)
        printf("Ponto (%.2f, %.2f) nao esta dentro do retangulo.\n", p.x, p.y);
    else
        printf("Ponto (%.2f, %.2f) esta dentro do retangulo.\n", p.x, p.y);

    return 0;
}

int dentroRet(Ponto *v1, Ponto *v2, Ponto *p)
{
    float min_x = (v1->x < v2->x) ? v1->x : v2->x;
    float max_x = (v1->x > v2->x) ? v1->x : v2->x;
    float min_y = (v1->y < v2->y) ? v1->y : v2->y;
    float max_y = (v1->y > v2->y) ? v1->y : v2->y;

    if(p->x > min_x && p->y < max_x && p->x > min_y && p->y < max_y)
        return 1;
    else
        return -1;
}