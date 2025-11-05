#include "Pilhas/pilha.hpp"

/*
Implemente uma fila utilizando duas pilhas auxiliares. Leve em consideração a seguinte estrutura:
typedef struct fila{
Pilha A;
Pilha B;
} Fila;
 */

typedef struct fila
{
    Pilha<int> A;
    Pilha<int> B;
} Fila;

 void enqueue(Fila& fila, int valor)
 {
    fila.A.push(valor);
 }

 int dequeue(Fila& fila)
 {
    if (fila.B.is_empty())
    {
        while (!fila.A.is_empty())
        {
            fila.B.push(fila.A.top());
            fila.A.pop();
        }
    }

    if (fila.B.is_empty())
        throw runtime_error("Fila vazia");

    int valor = fila.B.top();
    fila.B.pop();

    return valor;
 }
 