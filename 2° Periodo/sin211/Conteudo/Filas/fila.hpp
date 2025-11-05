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
class Fila
{
    private:
        No<T>* primeiro;
        No<T>* ultimo;
        int tamanho;

    public:
        Fila() : primeiro(nullptr), ultimo(nullptr), tamanho(0) {}

        ~Fila()
        {
            while (primeiro)
            {
                No<T>* temp = primeiro;
                primeiro = primeiro->prox;
                delete temp;
            }
        }

        bool is_empty()
        {
            return tamanho == 0;
        }

        void enqueue(T info)
        {
            No<T>* novoNo = new No(info);

            if (is_empty())
                primeiro = ultimo = novoNo;
            else
            {
                ultimo->prox = novoNo;
                ultimo = novoNo;
            }

            tamanho++;
        }

        T dequeue()
        {
            if (is_empty())
                throw runtime_error("Fila vazia.");

            No<T>* temp = primeiro;
            T removido = primeiro->info;

            if (primeiro == ultimo)
                primeiro = ultimo = nullptr;
            else
                primeiro = primeiro->prox;

            delete temp;
            tamanho--;

            return removido;
        }

        T front()
        {
            if (is_empty())
                throw runtime_error("Fila vazia.");
            return primeiro->info;
        }

        T back()
        {
            if (is_empty())
                throw runtime_error("Fila vazia.");
            return ultimo->info;
        }

        int length()
        {
            return tamanho;
        }
};