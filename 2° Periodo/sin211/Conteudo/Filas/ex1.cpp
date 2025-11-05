/*
Implemente a função reverso, que reposiciona os elementos na fila estática de tal
forma que o início da fila torna-se o fim, e vice-versa.
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 100

struct Fila
{
    int tamanho;
    int dados[MAX];
};

void reverso1(Fila* fila)
{
    for (int i = 0; i < fila->tamanho / 2; i++)
    {
        int temp = fila->dados[i];
        fila->dados[i] = fila->dados[fila->tamanho - 1 - i];
        fila->dados[fila->tamanho - 1 - i] = temp;
    }
}

void reverso2(Fila* fila)
{
    for (int i = 0; i < fila->tamanho / 2; i++)
        swap(fila->dados[i], fila->dados[fila->tamanho - 1 - i]);
}