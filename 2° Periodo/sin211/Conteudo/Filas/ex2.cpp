/*
Considere uma fila estática contendo números inteiros. Escreva uma função para
ordenar essa fila em ordem crescente de seus valores.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

struct Fila
{
    int tamanho;
    int dados[MAX];
};

void ordenar(Fila* fila)
{
    for (int i = 0; i < fila->tamanho - 1; i++)
    {
        for (int j = 0; j < fila->tamanho - 1 - i; j++)
        {
            if (fila->dados[j] > fila->dados[j + 1])
                swap(fila->dados[j], fila->dados[j + 1]);
        }
    }
}

