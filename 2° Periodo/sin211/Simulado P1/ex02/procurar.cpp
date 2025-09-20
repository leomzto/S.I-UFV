#include "procurar.hpp"

int letras_comuns(No* palavra1, No* palavra2)
{
    No* atual1 = palavra1;

    while (atual1 != nullptr)
    {       
        No* atual2 = palavra2;

        while (atual2 != nullptr) 
        {     
            if (atual1->info == atual2->info)
                return 1;               
            atual2 = atual2->prox;
        }

        atual1 = atual1->prox;
    }

    return 0; 
}

No* montarPalavra(string palavra)
{
    No* inicio = nullptr;
    No* fim = nullptr;

    for (int  i = 0; palavra[i] != '\0'; i++)
    {
        No* letra_atual = new No(palavra[i]);

        if (inicio == nullptr)
        {
            inicio = letra_atual;
            fim = letra_atual;
        }
        else
        {
            fim->prox = letra_atual;
            fim = letra_atual;
        }
    }

    return inicio;
}