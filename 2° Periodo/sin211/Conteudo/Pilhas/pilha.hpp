#include <bits/stdc++.h>

using namespace std;

template <typename T>
class No
{
    public:
        T info;
        No<T>* prox;

        No(T valor) : info(valor), prox(nullptr) {}
};

template <typename T>
class Pilha
{
    private:
        No<T>* topo;

    public:
        int tamanho;
        
        Pilha() : topo(nullptr), tamanho(0) {}

        ~Pilha()
        {
            while (topo)
            {
                No<T>* aux = topo;
                topo = topo->prox;
                delete aux;
            }
        }

        void push(T info)
        {
            No<T>* novoNo = new No(info);
            novoNo->prox = topo;
            topo = novoNo;
            tamanho++;
        }

        void pop()
        {
            if (!topo)
                return;

            No<T>* noTemp = topo;
            topo = topo->prox;
            delete noTemp;
            tamanho --;
        }

        T top()
        {
            if (is_empty())
                throw runtime_error("Pilha vazia.");
            return topo->info;
        }

        bool is_empty()
        {
            return tamanho == 0;
        }
};

