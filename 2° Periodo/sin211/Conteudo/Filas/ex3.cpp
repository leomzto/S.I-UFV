/*
Considere uma fila estática contendo números inteiros. Escreva uma função que
calcule o maior, o menor e a média aritmética dos seus elementos.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

struct Fila
{
    int tamanho;
    int dados[MAX];
    int primeiro;
    int ultimo;

    Fila() : primeiro(0), ultimo(-1), tamanho(0) {}
};


void MMM(Fila* fila)
{
    if (fila->tamanho == 0)
    {
        cout << "Fila vazia." << endl;
        return;
    }

    int maior, menor;
    auto soma = 0.0;

    maior = menor = fila->dados[fila->primeiro];
    for (int i = 1; i < fila->tamanho; i++)
    {
        auto val = fila->dados[i];

        soma += val;

        if (val > maior)
            maior = val;
        
        if (val < menor)
            menor = val;

    }

    auto media = soma / fila->tamanho;

    cout << "Maior: " << maior << endl;
    cout << "Menor: " << menor << endl;
    cout << "Media: " << media << endl;
}

