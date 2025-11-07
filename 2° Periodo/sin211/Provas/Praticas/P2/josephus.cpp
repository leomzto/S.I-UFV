#include <bits/stdc++.h>
using namespace std;

typedef struct sNo
{
    int info;
    sNo* prox;

    sNo(int valor) : info(valor), prox(nullptr) {}

} No;

typedef struct sListaCircular
{
    No* fim;
    int tamanho;

    sListaCircular() : fim(nullptr), tamanho(0) {}

    ~sListaCircular()
    {
        if (!fim)
            return;

        No* aux = fim->prox;
        
        while (aux != fim)
        {
            No* temp = aux;
            aux = aux->prox;
            delete temp;
        }
        
        delete fim;
    }

} LC;

bool vazio(LC* lista)
{
    return lista->tamanho == 0;
}

void insereFim(LC* lista, int valor)
{
    No* novo = new No(valor);

    if (vazio(lista))
    {
        lista->fim = novo;
        novo->prox = novo;
    }
    else
    {
        novo->prox = lista->fim->prox;
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
}

void removeElemento(LC* lista, int valor)
{
    if (vazio(lista))
        return;

    No* atual = lista->fim->prox;
    No* anterior = lista->fim;
    bool achou = false;

    do
    {
        if (atual->info == valor)
        {
            achou = true;
            break;
        }
        anterior = atual;
        atual = atual->prox;
        
    } while (atual != lista->fim->prox);

    if (!achou)
        return;

    if (lista->tamanho == 1)
    {
        delete atual;
        lista->fim = nullptr;
        lista->tamanho = 0;
        return;
    }

    if (atual == lista->fim->prox) // inicio
        lista->fim->prox = atual->prox;

    else if (atual == lista->fim) // fim
    {
        anterior->prox = atual->prox;
        lista->fim = anterior;
    }

    else // outra pos
        anterior->prox = atual->prox;

    delete atual;
    lista->tamanho--;
}

int josephus(LC* lista, int k)
{
    if (vazio(lista))
        return -1;

    int regra = k - 1; 
    
    No* aux = lista->fim->prox; 

    do 
    {
        for (int i = 0; i < regra; i++)
            aux = aux->prox;

        int eliminado = aux->info;
        
        aux = aux->prox;
        
        removeElemento(lista, eliminado);
        
    } while (lista->tamanho > 1);

    return lista->fim->info;
}

int main(void)
{
    int nc, n, k;
    cin >> nc;

    for (int i = 1; i <= nc; i++)
    {
        cin >> n >> k;

        LC* lista = new LC;

        for (int j = 1; j <= n; j++)
            insereFim(lista, j);

        int m = josephus(lista, k);
        cout << "Case " << i << ": " << m << "\n";

        delete lista;
    }

    return 0;
}
