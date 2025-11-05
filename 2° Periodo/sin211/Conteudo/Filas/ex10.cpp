#include "fila.hpp"

/*
Faça uma função para retornar o número de elementos da fila que possuem valor
ímpar
*/

int qtd_impares(Fila<int> fila)
{
    int impares = 0;

    auto is_odd = [](int num) -> bool
    {
        return num % 2 != 0;
    };

    while (!fila.is_empty())
    {
        int valor = fila.dequeue();
        if (is_odd(valor))
            impares++;
    }

    return impares;
}