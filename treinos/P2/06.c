/*
Ex 6:
Protótipo: int busca_nome(struct Contato agenda[], int n, char nome[]);
Descrição: Função que busca o índice de um contato pelo nome, ou -1 se não achar.
No main, crie 4 contatos, faça a busca e mostre o telefone se achar.
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char numero[20];
} Contato;

int busca_nome(Contato agenda[], int n, char nome[]);

int main(void)
{
    Contato agenda[] = 
    {
        {"Leonardo", "(34) 99140-3837"},
        {"Guilherme", "(34) 99722-0410"},
        {"Anderson", "(34) 99139-1098"},
        {"Fernanda", "(34) 99226-3848"}
    };

    char nome[20];
    printf("Busque um contato pelo nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int busca = busca_nome(agenda, 4, nome);
    if(busca == -1)
        puts("Contato nao encontrado.");
    else
        printf("%s - %s\n", agenda[busca].nome, agenda[busca].numero);

    return 0;
}

int busca_nome(Contato agenda[], int n, char nome[])
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(strcasecmp(agenda[i].nome, nome) == 0)
            return i;
    }
    return -1;
}