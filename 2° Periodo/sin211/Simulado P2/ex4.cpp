/*
Uma palavra é palíndromo se a sequência de letras que a forma é a mesma, quer seja lida da
esquerda para a direita ou da direita para a esquerda (exemplo raiar). 
Escrever um algoritmo eficiente para reconhecer se uma dada palavra é um palíndromo. 
Escolher a estrutura de dados conveniente para representar a palavra
*/

// Algoritimo:
/*
Passo 1: Receber a palavra
Passo 2: Criar uma pilha vazia
Passo 3: Para cada char na palavra, empilha ele na pilha criada
Passo 4: Percorrer a palavra, para cada char, desempilha o topo da pilha, compara o char lido com o desempilhado, se
algum for diferente, entao retorna FALSO e encerra o programa
Passo 5: Se tudo for igual, entao retorna TRUE, e encerra o programa
*/

// Em Código:

#include "Pilhas/pilha.hpp"

bool is_palindrome(string palavra)
{
    Pilha<char> pilha;

    for (char ch : palavra)
        pilha.push(ch);

    for (char ch : palavra)
    {
        if (ch != pilha.top())
            return false;
        pilha.pop();
    }

    return true;
}