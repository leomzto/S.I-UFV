#include "pilha.hpp"

/*
Dada uma pilha que armazene números, escreva uma função para ordenar os valores
da pilha em ordem crescente.
*/

void ordenar(Pilha<int> pOriginal)
{
    Pilha<int> pAux;

    while (!pOriginal.is_empty())
    {
        int ref = pOriginal.top();
        pOriginal.pop();

        while (!pAux.is_empty() && pOriginal.top() > ref)
        {
            pOriginal.push(pAux.top());
            pAux.pop();
        }

        pAux.push(ref);
    }

    while (!pAux.is_empty())
    {
        pOriginal.push(pAux.top());
        pAux.pop();
    }
}