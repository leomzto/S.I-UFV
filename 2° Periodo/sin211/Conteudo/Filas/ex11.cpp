#include "fila.hpp"

/*
Faça uma função para retornar o número de elementos da fila que possuem valor
par.
*/

int qtd_pares(Fila<int> fila)
{
    int pares = 0;

    auto is_even = [](int num) -> bool
    {
        return num % 2 == 0;
    };

    while (!fila.is_empty())
    {
        int valor = fila.dequeue();
        
        if (is_even(valor))
            pares++;
    }

    return pares;
}