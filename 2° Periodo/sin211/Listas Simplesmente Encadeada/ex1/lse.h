#include <bits/stdc++.h>

using namespace std;

#ifndef LSE_H
#define LSE_H

typedef struct sNo
{
    int info;
    struct sNo* prox;
} No;

typedef struct sLista
{
    No* inicio;
} Lista;

No* criarNo(int valor);
void liberarLista(Lista* lista);


void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);

void imprimirLista(Lista* lista);

void copiarLista(Lista* L1, Lista* L2);

#endif