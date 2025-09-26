#include <bits/stdc++.h>

using namespace std;

typedef struct sRena {
    string nome;
    int peso;
    int idade;
    float altura;

    sRena() : nome(""), peso(0), idade(0), altura(0.0) {};

    sRena(string n, int p, int i, float a) : nome(n), peso(p), idade(i), altura(a) {};

} Rena;

typedef struct sNo {
    sNo* ant;
    Rena info;
    sNo* prox;

    sNo(Rena rena) : ant(nullptr), info(rena), prox(nullptr) {};

} No;

typedef struct sLista {
    No* inicio;
    No* fim;
    int tamanho;

    sLista() : inicio(nullptr), fim(nullptr), tamanho(0) {};

    void adicionar(Rena &rena) // insere no fim
    {
        No* novoNo = new No(rena);

        if (inicio == nullptr)
            inicio = fim = novoNo;
        else
        {
            fim->prox = novoNo;
            novoNo->ant = fim;
            fim = novoNo;
        }

        tamanho++;
    }

    bool comparar(Rena &renaA, Rena &renaB)
    {
        if (renaA.peso != renaB.peso) 
            return renaA.peso > renaB.peso; // se peso de A > que peso de B, retorna A (ja que é descrescente), caso contrario, retorna B

        if (renaA.idade != renaB.idade)
            return renaA.idade < renaB.idade; // se idade de A < que idade de B, retorna A (ja que é ascendente), caso contrario, retorna B

        if (renaA.altura != renaB.altura)
            return renaA.altura < renaB.altura; // mesma coisa aqui

        return renaA.nome < renaB.nome; // mesma coisa aqui tbm
    }

    void ordenar()
    {
        if (inicio == nullptr) return;

        bool trocou;

        do
        {
            trocou = false;

            No* aux = inicio;

            while (aux != nullptr && aux->prox != nullptr)
            {
                if (comparar(aux->info, aux->prox->info) > 0)
                {
                    swap(aux->info, aux->prox->info);
                    trocou = true;
                }

                aux = aux->prox;
            }

        } while (trocou);
    }

    void imprimir(int m)
    {
        No* aux = inicio;

        for (int i = 0; i <= m && aux != nullptr; i++)
        {   
            cout << i << " " << aux->info.nome << endl;

            aux = aux->prox;
        }
    }

} Lista;

int main(void)
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        Lista listaRenas;

        for(int j = 0; j < n; j++)
        {
            Rena rena;
            cin >> rena.nome >> rena.peso >> rena.idade >> rena.altura;

            listaRenas.adicionar(rena);
        }

        listaRenas.ordenar();   

        cout << "CENARIO {" << i + 1 << "}" << endl;

        listaRenas.imprimir(m);
    }

    return 0;
}