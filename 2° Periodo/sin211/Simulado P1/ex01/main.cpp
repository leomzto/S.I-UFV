#include <bits/stdc++.h>

using namespace std;

#define MAX 100

typedef struct sLista {
    int tamanho;
    int dados[MAX];
} Lista;

int buscaBinaria(Lista lista, int elemento)
{
    int inicio = 0;
    int fim = lista.tamanho - 1;

    int lidos = 0;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        lidos++;
        
        if (lista.dados[meio] == elemento)
            return lidos;

        if (lista.dados[meio] > elemento)
            fim = meio - 1;
        else
            inicio = meio + 1;
        
    }
    return lidos;
}

int main(void)
{
    Lista lista = {15, {2, 5, 7, 10, 25, 27, 28, 33, 50, 52, 60, 61, 80, 88, 99}};

    cout << "Buscas feitas: " << buscaBinaria(lista, 9) << endl;

    return 0;
}