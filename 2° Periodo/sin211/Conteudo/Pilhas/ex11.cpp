#include "pilha.hpp"

/*
Faça uma função para retornar o número de elementos da pilha que possuem valor
ímpar.
*/

int qtd_impar(Pilha<int> pilha)
{
    auto is_even = [](int num) -> bool
    {
        return num % 2 == 0;
    };

    int impares = 0;

    while (!pilha.is_empty())
    {
        int topo = pilha.top();
        pilha.pop();
        if (!is_even(topo))
            impares++;
    }

    return impares;
}