#include "fila.hpp"
#include "Pilhas/pilha.hpp"

/*
Faça uma função que inverta a ordem dos elementos da fila.
*/

template<typename T>
void inverter(Fila<T>& fila)
{
    Pilha<T> pilha;

    while (!fila.is_empty())
        pilha.push(fila.dequeue());

    while (!pilha.is_empty())
    {
        fila.enqueue(pilha.top());
        pilha.pop();
    }
}

template<typename T>
void inverter_recursivo(Fila<T>& fila)
{
    if (fila.is_empty())
        return;

    T valor = fila.dequeue();
    inverter_recursivo(fila);
    fila.enqueue(valor);
}