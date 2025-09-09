#include "lse.h"

No* criarNo(int valor)
{
    No* novoNo = new No;

    novoNo->info = valor;
    novoNo->prox = nullptr;

    return novoNo;
}

void liberarLista(Lista* lista)
{
    No* atual = lista->inicio;
    No* proxNo = nullptr;

    while (atual != nullptr)
    {
        proxNo = atual->prox;

        delete atual;
        atual = proxNo;
    }

    lista->inicio = nullptr;
}

void inserirInicio(Lista* lista, int valor)
{
    No* novoNo = criarNo(valor);

    if (novoNo == nullptr)
        return;

    novoNo->prox = lista->inicio;
    lista->inicio = novoNo;
}

void inserirFim(Lista* lista, int valor)
{
    No* novoNo = criarNo(valor);
    if (novoNo == nullptr) 
        return;

    if (lista->inicio == nullptr) 
        lista->inicio = novoNo;
    else
    {
        No* atual = lista->inicio;
        while (atual->prox != nullptr)
            atual = atual->prox;

        atual->prox = novoNo;
    }
}

void imprimirLista(Lista* lista)
{
    No* atual = lista->inicio;

    while (atual != nullptr)
    {
        cout << atual->info << " -> ";

        atual = atual->prox;
    }

    cout << "NULL" << endl;
}


void copiarLista(Lista* L1, Lista* L2)
{
    No* atualL1 = L1->inicio;
    No* ultimoL2 = nullptr;
    L2->inicio = nullptr;

    while (atualL1 != nullptr)
    {
        No* novoNo = criarNo(atualL1->info);

        if (L2->inicio == NULL)
        {
            L2->inicio = novoNo;
            ultimoL2 = novoNo;
        }
        else
        {
            ultimoL2->prox = novoNo;
            ultimoL2 = novoNo;
        }

        atualL1 = atualL1->prox;
    }
}