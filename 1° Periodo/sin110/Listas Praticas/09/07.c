#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char nome[21];
    float x, y;
} Cidade;

float calcular_distancia(Cidade a, Cidade b);

int main()
{
    int n;

    printf("Quantidade de cidades? ");
    scanf("%d", &n);
    while (getchar() != '\n');

    Cidade* cidades = malloc(n * sizeof(Cidade));
    if (cidades == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < n; i++) {
        printf("Nome da cidade %d: ", i);
        fgets(cidades[i].nome, sizeof(cidades[i].nome), stdin);
        cidades[i].nome[strcspn(cidades[i].nome, "\n")] = 0;
        printf("Coordenada X: ");
        scanf("%f", &cidades[i].x);
        printf("Coordenada Y: ");
        scanf("%f", &cidades[i].y);
        while (getchar() != '\n');
    }

    float** distancias = malloc(n * sizeof(float*));
    if (distancias == NULL)
    {
        printf("Erro ao alocar memória para distâncias.\n");
        free(cidades);
        exit(1);
    }
    for (i = 0; i < n; i++)
        distancias[i] = malloc(n * sizeof(float));

    int j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            distancias[i][j] = calcular_distancia(cidades[i], cidades[j]);
    }

    printf("\nMatriz de Distâncias:\n      ");
    for (i = 0; i < n; i++)
        printf("[%d] ", i);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("[%d] ", i);
        for (j = 0; j < n; j++)
            printf("%.2f ", distancias[i][j]);
        printf("\n");
    }

    while (1)
    {
        printf("\nDigite os índices de duas cidades (-1 para sair): ");
        scanf("%d %d", &i, &j);
        if (i == -1 || j == -1)
            break;
        if (i >= 0 && i < n && j >= 0 && j < n)
            printf("Distância entre %s e %s: %.2f\n", cidades[i].nome, cidades[j].nome, distancias[i][j]);
        else
            printf("Índices inválidos!\n");
    }

    for (i = 0; i < n; i++)
        free(distancias[i]);
    free(distancias);
    free(cidades);

    return 0;
}

float calcular_distancia(Cidade a, Cidade b) 
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
