/*
Ex 4:
Struct Aluno com nome e nota (float).
Faça uma função que recebe um ponteiro para Aluno e atualiza a nota para 10 se for menor que 5.
No main, crie 3 alunos, chame a função para cada um e imprima as notas.
*/

#include <stdio.h>

typedef struct
{
    char nome[20];
    float nota;
} Aluno;

void ajusteNota(Aluno *aluno);

int main(void)
{
    Aluno aluno[3];
    int i;

    puts("Cadastro de aluno ->");
    for(i = 0; i < 3; i++)
    {
        printf("[%d] - Nome: ", i+1);
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);

        printf("[%d] - Nota: ", i+1);
        scanf("%f", &aluno[i].nota);
        while(getchar() != '\n');
    }

    puts("\nAtualização de notas ->");
    for(i = 0; i < 3; i++)
    {
        ajusteNota(&aluno[i]);
        printf("[%d] - Nome: %s", i+1, aluno[i].nome);
        printf("[%d] - Nota: %.2f\n", i+1, aluno[i].nota);
    }

    return 0;
}

void ajusteNota(Aluno *aluno)
{
    if(aluno->nota < 5.0)
        aluno->nota = 10.0;
}