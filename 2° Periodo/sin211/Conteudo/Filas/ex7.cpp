#include "fila.hpp"

/*
Implemente uma função que imprima os elementos de uma fila.
*/

template<typename T>
void imprimir(Fila<T>& fila)
{
    while (!fila.is_empty())
    {
        cout << fila. front();
        fila.dequeue();
    }

    cout << endl;
}