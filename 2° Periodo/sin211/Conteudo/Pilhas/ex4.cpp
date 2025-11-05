#include "pilha.hpp"

/*
Escreva um algoritmo, usando uma pilha, que inverte as letras de cada palavra de
um texto terminado por ponto (.) preservando a ordem das palavras.
Por exemplo, dado o texto:
    ESTE EXERCICIO E MUITO FACIL.
A saída deve ser:
    ETSE OICICREXE E OTIUM LICAF.
*/

string inverter_texto(string& texto)
{
    Pilha<char> pilha;
    string invertido;

    for (char ch : texto)
    {
        if (ch != ' ' && ch != '.')
            pilha.push(ch);
        else
        {
            while (!pilha.is_empty())
            {
                invertido += pilha.top();
                pilha.pop();
            }

            invertido += ch;
        }
    }

    return invertido;
}