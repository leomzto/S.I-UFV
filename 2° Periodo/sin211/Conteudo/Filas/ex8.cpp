#include "fila.hpp"

/*
Faça uma função que receba uma fila como argumento e retorne o valor armazenado
em seu início. A função deve também remover esse elemento.
*/

template<typename T>
T front_remove(Fila<T>& fila)
{
    T valor = fila.front();
    fila.dequeue();

    return valor;
}