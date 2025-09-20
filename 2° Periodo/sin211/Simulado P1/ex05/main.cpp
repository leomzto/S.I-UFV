#include <bits/stdc++.h>

using namespace std;

typedef struct sNo {
    sNo* ant;
    int info;
    sNo* prox;

    sNo(int elemento) : ant(nullptr), info(elemento), prox(nullptr) {};
} No;

typedef struct sLista {
    No* inicio;
    No* fim;
    int tamanho;

    sLista() : inicio(nullptr), fim(nullptr), tamanho(0) {};
} Lista;

void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);
Lista* removerIndice(Lista* lista, int indice);

void imprimirLista(Lista* lista);

int main(void)
{
    Lista* lista = new Lista();

    int valor;
    int indice;
    int qtdInicio;
    int qtdFim;

    cout << "Qtd a inserir no inicio: ";
    cin >> qtdInicio;
    cout << "Qtd a inserir no fim: ";
    cin >> qtdFim;

    for (int i = 0; i < qtdInicio; i++)
    {
        cin >> valor;
        inserirInicio(lista, valor);
    }

    for (int i = 0; i < qtdFim; i++)
    {
        cin >> valor;
        inserirFim(lista, valor);
    }
    
    cout << "indice a ser removido: ";
    cin >> indice;
    removerIndice(lista, indice);

    imprimirLista(lista);

    return 0;
}

void inserirInicio(Lista* lista, int valor)
{
    No* novoNo = new No(valor);

    novoNo->prox = lista->inicio;
    novoNo->ant = nullptr;

    if (lista->inicio != nullptr)
        lista->inicio->ant = novoNo;
    else
        lista->fim = novoNo;

    lista->inicio = novoNo;
    lista->tamanho++;
}

void inserirFim(Lista* lista, int valor)
{
    No* novoNo = new No(valor);

    novoNo->ant = lista->fim;
    novoNo->prox = nullptr;

    if (lista->fim != nullptr)
        lista->fim->prox = novoNo;
    else
        lista->inicio = novoNo;

    lista->fim = novoNo;
    lista->tamanho++;
}


Lista* removerIndice(Lista* lista, int indice)
{
    if (indice < -lista->tamanho || indice >= lista->tamanho)
    {
        cout << "Indice invalido" << endl;
        return lista;
    }

    if (indice < 0)
        indice = lista->tamanho + indice;

    No* posAtual;

    if (indice < lista->tamanho / 2)
    {
        posAtual = lista->inicio;
        for (int i = 0; i < indice; i++)
            posAtual = posAtual->prox;

    }
    else
    {
        posAtual = lista->fim;
        for (int i = lista->tamanho - 1; i > indice; i--)
            posAtual= posAtual->ant;
    }

    if (posAtual->ant != nullptr)
        posAtual->ant->prox = posAtual->prox;
    else 
        lista->inicio = posAtual->prox;

    if (posAtual->prox != nullptr)
        posAtual->prox->ant = posAtual->ant;
    else    
        lista->fim = posAtual->ant;

    delete posAtual;
    lista->tamanho--;
    return lista;
}

void imprimirLista(Lista* lista)
{
    if (lista->inicio == nullptr || lista->fim == nullptr)
    {
        cout << "A lista esta vazia." << endl;
        return;
    }
    
    No* posAtual = lista->inicio;

    while(posAtual != nullptr)
    {
        cout << posAtual->info << " -> ";
        posAtual = posAtual->prox;
    }

    cout << "NULL" << endl;
}