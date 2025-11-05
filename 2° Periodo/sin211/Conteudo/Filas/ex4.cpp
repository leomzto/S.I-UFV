#include "fila.hpp"

/*
Desenvolva uma função para testar se uma fila F1 tem mais elementos do que uma
fila F2.
*/

template<typename T>
void filaMaior1(Fila<T> f1, Fila<T> f2)
{
    if (f1.length() > f2.length())
     cout << "F1 maior que F2." << endl;
    else    
        cout << "F2 maior que F1."<< endl;
}

template<typename T>
bool filaMaior2(Fila<T> f1, Fila<T> f2)
{
    return f1.length() > f2.length();
}

template<typename T>
bool filaMaior3(Fila<T> f1, Fila<T> f2)
{
    auto size = [](Fila<T> fila) -> int
    {
        int cont = 0;
        while (!fila.is_empty())    
        {
            fila.dequeue();
            cont++;
        }
        
        return cont;
        
    };

    return size(f1) > size(f2);

}