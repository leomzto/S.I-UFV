#include <stdio.h>

#define MEDIA 60.0f

struct Alunos
{
    char nome[20];
    int matricula;
    float nota_p1, nota_p2, nota_p3;
};

int main(void)
{
    struct Alunos al[5];
    float soma[5] = {0}; 
    float media[5] = {0};
    float maior_p1, maior_media, menor_media;
    
    int p1maior = 0, media_maior = 0, media_menor = 0;

    int i;

    for (i = 0; i < 5; i++)
    {
        printf("Nome 0%d: ", i + 1);
        gets(al[i].nome);

        printf("Matricula 0%d: ", i + 1);
        scanf("%d", &al[i].matricula);
        getchar();

        printf("Nota P1 0%d: ", i + 1);
        scanf("%f", &al[i].nota_p1);
        getchar();

        printf("Nota P2 0%d: ", i + 1);
        scanf("%f", &al[i].nota_p2);
        getchar();

        printf("Nota P3 0%d: ", i + 1);
        scanf("%f", &al[i].nota_p3);
        getchar();
    }

    maior_p1 = al[0].nota_p1;
    for (i = 1; i < 5; i++)
    {
        if (al[i].nota_p1 > maior_p1)
        {
            maior_p1 = al[i].nota_p1;
            p1maior = i;
        }
    }

    for (i = 0; i < 5; i++)
    {
        soma[i] = al[i].nota_p1 + al[i].nota_p2 + al[i].nota_p3;
        media[i] = soma[i] / 3;
    }

    maior_media = menor_media = media[0];
    for (i = 1; i < 5; i++)
    {
        if (media[i] > maior_media)
        {
            maior_media = media[i];
            media_maior = i;
        }
        
        if (media[i] < menor_media)
        {
            menor_media = media[i];
            media_menor = i;
        }
    }

    printf("Maior Nota P1:\n%s\n", al[p1maior].nome);
    printf("Maior Media:\n%s\n", al[media_maior].nome);
    printf("Menor Media:\n%s\n", al[media_menor].nome);
    for (i = 0; i < 5; i++)
    {
        printf("%s -> %s\n", al[i].nome, media[i] >= MEDIA ? "APROVADO" : "REPROVADO");
    }

    return 0;

}
