#include "fila.hpp"

/*
Dada uma fila de inteiros, escreva um programa que exclua todos os números negativos,
sem alterar a posição dos outros elementos da fila
*/

void remover_negativos(Fila<int>& fila)
{
    Fila<int> aux;

    while (!fila.is_empty())
    {
        int valor = fila.front();
        fila.dequeue();

        if (valor >= 0)
            aux.enqueue(valor);
    }

    while (!aux.is_empty())
        fila.enqueue(aux.dequeue());
}