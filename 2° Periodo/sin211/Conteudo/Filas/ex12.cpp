#include "fila.hpp"

/*
Faça uma função para intercalar filas: a função recebe as duas filas e retorna uma
nova fila com os elementos das duas intercalados conforme a ordem em que aparecem.
*/

template<typename T>
Fila<T> intercalar(Fila<T> f1, Fila<T> f2)
{
    Fila<T> f3;

    while (!f1.is_empty() && !f2.is_empty())
    {
        T v_f1 = f1.dequeue();
        T v_f2 = f2.dequeue();

        f3.enqueue(v_f1);
        f3.enqueue(v_f2);
    }

    while (!f1.is_empty())
        f3.enqueue(f1.dequeue());

    while (!f2.is_empty())
        f3.enqueue(f2.dequeue());

    return f3;
}