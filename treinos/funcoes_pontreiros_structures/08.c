/*
Ex 2:
Defina uma struct Ponto com float x, y;.
Faça uma função que calcula a distância entre dois pontos com a fórmula:
Distância = √((x2 - x1)² + (y2 - y1)²)
No main, leia dois pontos, chame a função e mostre a distância.
*/

#include <stdio.h>
#include <math.h>

typedef struct
{
    float x, y;
} Ponto;

float calculaDistancia(Ponto *p1, Ponto *p2);

int main(void)
{
    Ponto p1, p2;
    float distancia;

    printf("Entre com as coordenadas do ponto 1: ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Entre com as coordenadas do ponto 2: ");
    scanf("%f %f", &p2.x, &p2.y);

    distancia = calculaDistancia(&p1, &p2);
    printf("Distancia entre (%.2f, %.2f) e (%.2f, %.2f): %.2f\n",
         p1.x, p1.y, p2.x, p2.y, distancia);

    return 0;
}

    float calculaDistancia(Ponto *p1, Ponto *p2)
{
    // Distância = √((x2 - x1)² + (y2 - y1)²)
    float quadrado_x = pow((p2->x - p1->x), 2);
    float quadrado_y = pow((p2->y - p1->y), 2);
    float distancia = sqrt(quadrado_x + quadrado_y);

    return distancia;
}