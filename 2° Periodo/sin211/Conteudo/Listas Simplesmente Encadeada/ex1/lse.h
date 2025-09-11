#include <bits/stdc++.h>

using namespace std;

#ifndef LSE_H
#define LSE_H

// Nó da lista
typedef struct sNo
{
    int info;
    struct sNo* prox;

    sNo(int valor) 
        {
            info = valor;
            prox = nullptr;
        }
} No;

// Lista encadeada
typedef struct sLista
{
    No* inicio;

    sLista() 
    {
        inicio = nullptr;
    }
} Lista;


// Auxiliares
No* criarNo(int valor);
void liberarNos(Lista* lista);
void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);
void imprimirLista(Lista* lista);
void liberarLista(Lista* &lista);

// Auxiliares de exercícios
bool existeNaLista(Lista* lista, int elemento); // auxiliar para o Ex2
void inverterLista(Lista* lista);              // auxiliar para o Ex3
void ordenarLista(Lista* lista);               // auxiliar para o Ex4

// Exercícios
void copiarLista(Lista* L1, Lista* L2);             // Ex1
void copiarSemRepeticao(Lista* L1, Lista* L2);      // Ex2
Lista* copiarListaInvertida(Lista* L1);        // Ex3
Lista* mergeListasOrdenadas(Lista* L1, Lista* L2);  // Ex4
Lista* dividirLista(Lista* lista, int n);           // Ex5

#endif