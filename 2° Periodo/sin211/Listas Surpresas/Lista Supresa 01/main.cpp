#include <bits/stdc++.h>

using namespace std;

typedef struct sNo
{
    string info;
    sNo* prox;

    sNo(string nome) : info(nome), prox(nullptr) {}
} No;

typedef struct sLista
{
    No* inicio;
    No* fim;

    sLista() : inicio(nullptr), fim(nullptr) {}
} Lista;

No* alocarNo(string nome);
void desalocarNo(No* no);
void liberarLista(Lista* l);
// void adicionarLivro(Lista* l, string titulo); // adicionar no inicio
Lista* buscarLivro(Lista* l, string busca);
void adicionarFim(Lista* l, string titulo);
void imprimirLista(Lista* l);


int main(void)
{
    Lista* listaLivros = new Lista();
    int n;
    cin >> n;

    string tituloLivro;

    int x;

    string tituloBusca;

    for (int i = 0; i < n; i++)
    {
        cin >> tituloLivro;
        adicionarFim(listaLivros, tituloLivro);
    }

    cin >> x;

    for (int i = 0; i < x; i++)
    {
        cin >> tituloBusca;
        buscarLivro(listaLivros, tituloBusca);
    }

    imprimirLista(listaLivros);
    liberarLista(listaLivros);

    return 0;
}

No* alocarNo(string nome)
{
    return new No(nome);
}
void desalocarNo(No* no)
{
    delete no;
}

void liberarLista(Lista* l)
{
    No* posAtual = l->inicio;

    while(posAtual)
    {
        No* aux = posAtual->prox;
        delete posAtual;
        posAtual = aux;
    }

    l->inicio = nullptr;
    l->fim = nullptr;
}

void adicionarFim(Lista* l, string titulo)
{
    No* novoNo = alocarNo(titulo);

    if (l->inicio == nullptr)
    {
        l->inicio = novoNo;
        l->fim = novoNo;
    }
    else
    {
        l->fim->prox = novoNo;
        l->fim = novoNo;
    }
}

/*
minha função: chamar adicionarLivro() criava duplicada cada vez que "busca" era encontrado.
a funçao cria um novo no toda vez que é chamada
Lista* buscarLivro(Lista* l, string busca)
{
    if (l->inicio == nullptr)
        return l;

    No* posAtual = l->inicio;

    while (posAtual)
    {
        if (posAtual->info == busca)
            adicionarLivro(l, busca);
    
        posAtual = posAtual->prox;
    }

    return l;
}*/

// funcao correta:
Lista* buscarLivro(Lista* l, string busca)
{
    if (l->inicio == nullptr)
        return l;

    No* aux = nullptr;
    No* posAtual = l->inicio;

    while (posAtual)
    {
        if (posAtual->info == busca)
        {
            if (aux != nullptr)
            {
                aux->prox = posAtual->prox;

                if (posAtual == l->fim)
                    l->fim = aux;

                posAtual->prox = l->inicio;
                l->inicio = posAtual;
            }
            break;
        }

        aux = posAtual;
        posAtual = posAtual->prox;
    }

    return l;
}

void imprimirLista(Lista* l)
{
    No* posAtual = l->inicio;

    while (posAtual)
    {
        cout << posAtual->info << endl;
        posAtual = posAtual->prox;
    }
}
