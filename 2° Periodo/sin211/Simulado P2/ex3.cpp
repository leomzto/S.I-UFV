/*
Dadas duas filas de prioridade (filas contendo um campo inteiro adicional na sua estrutura que
indica o nível de prioridade do elemento, i.e a fila será ordenada de acordo com a prioridade de cada informação) 
implementar uma função que recebe como entrada as duas filas de prioridade e retorna
como resultado uma fila de prioridade contendo os elementos de ambas as filas. As funções básicas
de uma fila convencional podem ser consideradas já implementadas (vazia, enfileirar e desenfileirar).
Seguir o seguinte protótipo:
Fila* concatenaFilas(Fila *f1, Fila *f2)
*/

Fila* concatenaFilas(Fila *f1, Fila *f2)
{
    Fila* f3 = new Fila;
    f3->inicio = f3->fim = nullptr;

    No* aux1 = f1->inicio;
    No* aux2 = f2->inicio;

    while (aux1 && aux2)
    {
        if (aux1->prioridade >= aux2->prioridade)
        {
            enfileirar(f3, aux1->valor, aux1->prioridade);
            aux1 = aux1->prox;
        }
        else
        {
            enfileirar(f3, aux2->valor, aux2->prioridade);
            aux2 = aux2->prox;
        }
    }

    while (aux1)
    {
        enfileirar(f3, aux1->valor, aux1->prioridade);
        aux1 = aux1->prox;
    }

    while (aux2)
    {
        enfileirar(f3, aux2->valor, aux2->prioridade);
        aux2 = aux2->prox;
    }

    return f3;
}


