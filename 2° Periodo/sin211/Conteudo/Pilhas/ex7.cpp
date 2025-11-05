#include "pilha.hpp"

/*
Desenvolva uma função para testar se uma pilha P1 tem mais elementos que uma
pilha P2.
*/

template<typename T>
void pilhaMaior1(Pilha<T>& p1, Pilha<T>& p2)
{
    if (p1.tamanho > p2.tamanho)
        cout << "P1 maior que P2." << endl;
    else    
        cout << "P2 maior que P1."<< endl;
}

template<typename T>
bool pilhaMaior2(Pilha<T>& p1, Pilha<T>& p2)
{
    return p1.tamanho > p2.tamanho;
}

template<typename T>
bool pilhaMaior3(Pilha<T> p1, Pilha<T> p2)
{
    auto size = [](Pilha<T> pilha) -> int
    {
        int cont = 0;
        while (!pilha.is_empty())
        {
            pilha.pop();
            cont++;
        }
        return cont;
    };

    return size(p1) > size(p2);
}

