#include "palindromo.hpp"

int verificarPalindromo(Lista* p1)
{
    No* posInicial = p1->inicio;
    No* posFinal = p1->fim;

    while (posInicial != posFinal && posInicial->ant != posFinal)
    {
        if (posInicial->info != posFinal->info)
            return 0;

        posInicial = posInicial->prox;
        posFinal = posFinal->ant;
    }

    return 1;
}

Lista* montarPalavra(string palavra)
{
    Lista* lista = new Lista();

    for (int  i = 0; palavra[i] != '\0'; i++)
    {
        No* letra_atual = new No(palavra[i]);

        if (lista->inicio == nullptr)
        {
            lista->inicio = letra_atual;
            lista->fim = letra_atual;
        }
        else
        {
            lista->fim->prox = letra_atual;
            lista->fim = letra_atual;
        }
    }

    return lista;
}