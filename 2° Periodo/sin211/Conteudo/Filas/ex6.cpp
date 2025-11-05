#include "fila.hpp"

/*
Faça uma função que receba três filas, duas já preenchidas em ordem crescente, e
preencha a última com os valores das duas primeiras em ordem crescente.
*/

void copiar2em1(Fila<int> f1, Fila<int> f2, Fila<int>& f3)
{
    while (!f1.is_empty() && !f2.is_empty())
    {
        if (f1.front() <= f2.front())
            f3.enqueue(f1.dequeue());
        
        else
            f3.enqueue(f2.dequeue());
    }

    while (!f1.is_empty())
        f3.enqueue(f1.dequeue());

    while (!f2.is_empty())
        f3.enqueue(f2.dequeue());
}