#include "pilha.hpp"

/*
Uma sequência de operações de inserção (I) e eliminação (E) numa pilha é dita válida
se ela tem igual número de Is e Es e todas as operações podem ser efetuadas na
pilha, ou seja, a eliminação só pode acontecer se a pilha não estiver vazia. Formule
uma regra que permita determinar se uma sequência (ex: IIEE) é válida ou não.
*/

bool valido(string operacoes)
{
    int count = 0;

    for (char op : operacoes)
    {
        if (op == 'I')
            count += 1;
        else if (op == 'E')
            count -= 1;

        if (count < 0)
            return false;

    }

    return count == 0;
}
