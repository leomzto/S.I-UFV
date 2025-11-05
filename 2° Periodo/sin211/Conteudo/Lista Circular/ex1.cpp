#include <bits/stdc++.h>

using namespace std;

/*
Fazer uma TAD para Lista Circular Simplesmente Encadeada (LCSE) com todas as operações básicas:
• Inicializar;
• Alocar e desalocar Nó;
• Verificar lista Vazia;
• Inserir no início e no fim;
• Remover no início e no fim;
• Buscar elemento;
• Imprimir lista;
*/

template<typename T>
struct No
{
    T info;
    No<T>* prox;

    // Alocar no (utilizando constructor)
    No(T valor) : info(valor), prox(this) {}
};

template<typename T>
struct Lista
{
    No<T>* inicio;
    No<T>* fim;
    int tamanho;

    // Inicializar (utilizando construtor)
    Lista() : inicio(nullptr), fim(nullptr), tamanho(0) {}

    // Desalocar os nos (utilizando deconstrutor)
    ~Lista()
    {
        if (!inicio) return;
    
        No<T>* atual = inicio->prox;
        while (atual != inicio)
        {
            No<T>* temp = atual;
            atual = atual->prox;
            delete temp;
        }
        delete inicio;
    }

    // Verificar lista vazia
    bool is_empty()
    {
        return inicio == nullptr;
    }

    // Inserir inicio e fim
    void inserir(string pos, T valor)
    {
        if (is_empty())
        {
            No<T>* novoNo = new No<T>(valor);
            inicio = fim = novoNo;
            tamanho = 1;
            return;
        }

        if (pos == "inicio")
        {
            No<T>* novoNo = new No<T>(valor);
            novoNo->prox = inicio; 
            fim->prox = novoNo;   
            inicio = novoNo;    
            tamanho++;
            return;
        }

        if (pos == "fim")
        {
            No<T>* novoNo = new No<T>(valor);
            novoNo->prox = inicio;
            fim->prox = novoNo;    
            fim = novoNo;    
            tamanho++;
            return;
        }
    }

    // Remover inicio e fim
    void remover(string pos)
    {
        if (is_empty())
        {
            cout << "Lista vazia." << endl;
            return;
        }

        if (inicio == fim)
        {
            delete inicio;
            inicio = fim = nullptr;
            tamanho = 0;
            return;
        }

        if (pos == "inicio")
        {
            No<T>* temp = inicio;
            inicio = inicio->prox;
            fim->prox = inicio;
            delete temp;
            tamanho--;
            return;
        }

        if (pos == "fim")
        {
            No<T>* posAtual = inicio;
            while (posAtual->prox != fim)
                posAtual = posAtual->prox;
        
            No<T>* temp = fim;
            fim = posAtual;    
            fim->prox = inicio;  
            delete temp;
            tamanho--;
            return;
        }
    }

    // Buscar elemento
    bool buscar(T elemento)
    {
        if (is_empty())
            return false;

        No<T>* posAtual = inicio;
        
        do
        {
            if (posAtual->info == elemento)
                return true;
            
            posAtual = posAtual->prox;

        } while (posAtual != inicio);

        return false;
    }

    // Imprimir lista
    void imprimir()
    {
        if (is_empty())
        {
            cout << "Lista vazia." << endl;
            return;
        }

        No<T>* posAtual = inicio;
        
        do
        {
            cout << posAtual->info;
            posAtual = posAtual->prox;
            if (posAtual != inicio) cout << " -> ";
            
        } while (posAtual != inicio);
        
        cout << " -> (inicio)" << endl;
    }
};