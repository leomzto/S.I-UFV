#include "pilha.hpp"

/*
Considere uma pilha que armazene caracteres. Faça uma função para determinar
se uma string é um palíndromo.
*/

bool Eh_Palindromo(Pilha<char> pPalavra)
{
    Pilha<char> pInvertida;

    Pilha<char> pTemp = pPalavra;

    while (!pTemp.is_empty())
    {
        pInvertida.push(pTemp.top());
        pTemp.pop();
    }

    while (!pPalavra.is_empty() && !pInvertida.is_empty())
    {
        if (pPalavra.top() != pInvertida.top())
            return false;

        pPalavra.pop();
        pInvertida.pop();
    }

    return true;
}