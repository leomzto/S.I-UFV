#include "pilha.hpp"

/*
Dada uma pilha que armazene números, escreva uma função que forneça o maior, o
menor e a média aritmética dos elementos da pilha.
*/

int maior(Pilha<int> pilha)
{
    if (pilha.is_empty())
    {    
        cout << "Pilha vazia." << endl;
        return;        
    }

    int maior = pilha.top();
    pilha.pop();

    while (!pilha.is_empty())
    {
        int topo = pilha.top();
        pilha.pop();

        if (topo > maior)
            maior = topo;
    }

    return maior;
}

int menor(Pilha<int> pilha)
{
    if (pilha.is_empty())
    {    
        cout << "Pilha vazia." << endl;
        return;        
    }

    int menor = pilha.top();
    pilha.pop();

    while (!pilha.is_empty())
    {
        int topo = pilha.top();
        pilha.pop();

        if (topo < menor)
            menor = topo;
    }

    return menor;
}

double media(Pilha<int> pilha)
{
    if (pilha.is_empty())
    {    
        cout << "Pilha vazia." << endl;
        return;        
    }

    int tamanho = pilha.tamanho;    
    auto soma = 0;

    while (!pilha.is_empty())
    {
        soma += pilha.top();
        pilha.pop();
    }

    return soma / tamanho;
}

void MMM(Pilha<int> pilha)
{
    if (pilha.is_empty())
    {
        cout << "Pilha vazia." << endl;
        return;
    }

    int maior = pilha.top();
    int menor = pilha.top();
    auto soma = 0.0 ;
    int tamanho = pilha.tamanho;

    while (!pilha.is_empty())
    {
        int topo = pilha.top();
        pilha.pop();

        soma += topo;

        if (topo > maior)
            maior = topo;
        if (topo < menor)
            menor = topo;
    }

    auto media = soma / tamanho;

    cout << "Maior: " << maior << endl;
    cout << "Menor: " << menor << endl;
    cout << "Media: " << media << endl;
}
