#include "pilha.hpp"

/*
(beecrowd | 1068) Balanço de Parênteses I — Por Neilor Tonin, URI Brasil
Dada uma expressão qualquer com parênteses, indique se a quantidade de parênteses
está correta ou não, sem levar em conta o restante da expressão.
Por exemplo:
    a+(b*c)-2-a -> correct
    (a+b*(2-c)-2+a)*2 -> correct
    (a*b-(2+c) -> incorrect
    2*(3-a)) -> incorrect
    )3+b*(2-c)( -> incorrect
Todo parêntese que fecha deve ter um outro parêntese que abre correspondente, e
não pode haver parêntese que fecha sem um prévio parêntese que abre. A quantidade
total de parênteses que abrem e fecham deve ser igual.

Entrada: haverá N expressões (1 ≤ N ≤ 10000), cada uma com até 1000 caracteres.
Saída: para cada expressão, imprimir “correct” ou “incorrect”.
*/

// pensar melhor depois
