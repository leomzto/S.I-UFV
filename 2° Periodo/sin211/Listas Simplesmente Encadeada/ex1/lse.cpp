#include "lse.h"

// Auxiliares
No* criarNo(int valor)
{
    return new No(valor);
}

void liberarNos(Lista* lista)
{
    if (!lista) return;

    No* atual = lista->inicio;
    while (atual != nullptr)
   
    {
        No* prox = atual->prox;
        delete atual;
        atual = prox;
    }
    lista->inicio = nullptr;
}

void liberarLista(Lista* &lista)
{
    if (!lista)
        return;

    No* atual = lista->inicio;

    while (atual != nullptr)
   
    {
        No* prox = atual->prox;
        delete atual;
        atual = prox;
    }

    delete lista;
    lista = nullptr;
}


void inserirInicio(Lista* lista, int valor)
{
    No* novoNo = criarNo(valor);
    novoNo->prox = lista->inicio;
    lista->inicio = novoNo;
}

void inserirFim(Lista* lista, int valor)
{
    No* novoNo = criarNo(valor);
    if (lista->inicio == nullptr)
   
    {
        lista->inicio = novoNo;
    }
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

// Exercício 1
void copiarLista(Lista* L1, Lista* L2)
{
    liberarNos(L2);
    L2->inicio = nullptr;
    No* atualL1 = L1->inicio;
    No* ultimoL2 = nullptr;

    while (atualL1 != nullptr)
    {
        No* novoNo = criarNo(atualL1->info);

        if (!L2->inicio)
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

// Exercício 2
bool existeNaLista(Lista* lista, int elemento)
{
    No* atual = lista->inicio;

    while (atual != nullptr)
   
    {
        if (atual->info == elemento)
            return true;
        atual = atual->prox;
    }
    return false;
}

void copiarSemRepeticao(Lista* L1, Lista* L2)
{
    liberarNos(L2);

    No* atualL1 = L1->inicio;
    No* ultimoL2 = nullptr;

    while (atualL1 != nullptr)
   
    {
        if (!existeNaLista(L2, atualL1->info))
       
        {
            No* novoNo = criarNo(atualL1->info);

            if (L2->inicio == nullptr)
           
            {
                L2->inicio = novoNo;
                ultimoL2 = novoNo;
            }
            else
           
            {
                ultimoL2->prox = novoNo;
                ultimoL2 = novoNo;
            }
        }
        atualL1 = atualL1->prox;
    }
}

// Exercício 3
void inverterLista(Lista* lista)
{
    No* anterior = nullptr;
    No* atual = lista->inicio;

    while (atual != nullptr)
   
    {
        No* proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->inicio = anterior;
}

Lista* copiarListaInvertida(Lista* L1)
{
    Lista* lAux = new Lista;

    No* atual = L1->inicio;
    No* ultimo = nullptr;

    while (atual != nullptr)
    {
        No* novoNo = criarNo(atual->info);
        if (!lAux->inicio)
        {
            lAux->inicio = novoNo;
            ultimo = novoNo;
        }
        else
        {
            ultimo->prox = novoNo;
            ultimo = novoNo;
        }
        atual = atual->prox;
    }

    inverterLista(lAux);

    return lAux;
}


// Exercício 4
void ordenarLista(Lista* lista)
{
    if (lista == nullptr)
        return;

    bool trocou;
    do
   
    {
        trocou = false;
        No* atual = lista->inicio;
        while (atual != nullptr && atual->prox != nullptr)
       
        {
            if (atual->info > atual->prox->info)
           
            {
                swap(atual->info, atual->prox->info);
                trocou = true;
            }
            atual = atual->prox;
        }
    } while (trocou);
}

Lista* mergeListasOrdenadas(Lista* L1, Lista* L2)
{
    Lista* L3 = new Lista;
    
    No* atualL1 = L1->inicio;
    No* atualL2 = L2->inicio;
    No* ultimoL3 = nullptr;

    while (atualL1 && atualL2)
    {
        No* novoNo;
        if (atualL1->info <= atualL2->info)
        {
            novoNo = criarNo(atualL1->info);
            atualL1 = atualL1->prox;
        }
        else
        {
            novoNo = criarNo(atualL2->info);
            atualL2 = atualL2->prox;
        }

        if (!L3->inicio)
        {
            L3->inicio = novoNo;
            ultimoL3 = novoNo;
        }
        else
        {
            ultimoL3->prox = novoNo;
            ultimoL3 = novoNo;
        }
    }

    while (atualL1)
    {
        No* novoNo = criarNo(atualL1->info);
        if (!L3->inicio)
        {
            L3->inicio = novoNo;
            ultimoL3 = novoNo;
        } else
        {
            ultimoL3->prox = novoNo;
            ultimoL3 = novoNo;
        }
        atualL1 = atualL1->prox;
    }

    while (atualL2)
    {
        No* novoNo = criarNo(atualL2->info);
        if (!L3->inicio)
        {
            L3->inicio = novoNo;
            ultimoL3 = novoNo;
        } else
        {
            ultimoL3->prox = novoNo;
            ultimoL3 = novoNo;
        }
        atualL2 = atualL2->prox;
    }

    return L3;
}


// Exercício 5
Lista* dividirLista(Lista* lista, int n)
{
    Lista* novaLista = new Lista;

    if (lista == nullptr || n <= 0 || lista->inicio == nullptr)
        return novaLista;

    No* atual = lista->inicio;
    int cont = 1;
    while (atual != nullptr && cont < n)
   
    {
        atual = atual->prox;
        cont++;
    }

    if (atual == nullptr || atual->prox == nullptr)
        return novaLista;

    novaLista->inicio = atual->prox;
    atual->prox = nullptr;

    return novaLista;
}
