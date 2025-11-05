#include "lse.h"

int main(void)
{
    Lista* L1 = new Lista;

    inserirInicio(L1, 1);
    inserirFim(L1, 2);
    inserirFim(L1, 3);
    inserirFim(L1, 10);
    inserirFim(L1, 10);
    inserirFim(L1, 10);
    inserirFim(L1, 10);

    Lista* L2 = new Lista;

    // Exercício 1
    copiarLista(L1, L2);

    cout << "Lista 1: ";
    imprimirLista(L1);

    cout << "Lista 2 (copia L1): ";
    imprimirLista(L2);
    cout << endl << endl;

    // Exercício 2
    copiarSemRepeticao(L1, L2);

    cout << "Lista 1: ";
    imprimirLista(L1);

    cout << "Lista 2 (copia L1, sem repeticao): ";
    imprimirLista(L2);
    cout << endl << endl;

    // Exercício 3
    Lista* lAux = copiarListaInvertida(L1);

    cout << "Lista 1: ";
    imprimirLista(L1);

    cout << "Lista 2 (copia L1, invertida): ";
    imprimirLista(lAux);
    cout << endl << endl;

    // Exercício 4: Mesclagem de listas
    liberarNos(L2);

    inserirInicio(L2, 101);
    inserirFim(L2, 102);
    inserirFim(L2, 103);
    inserirFim(L2, 0);
    inserirFim(L2, 104);
    inserirFim(L2, 200);

    cout << "Lista 1: ";
    imprimirLista(L1);
    cout << "Lista 2: ";
    imprimirLista(L2);
    
    Lista* listaMesclada = mergeListasOrdenadas(L1, L2);
    ordenarLista(listaMesclada);

    cout << "Lista Mesclada: ";
    imprimirLista(listaMesclada);
    cout << endl << endl;

    // Exercício 5
    cout << "Lista 1: ";
    imprimirLista(L1);

    Lista* listaDividida = dividirLista(L1, 3);

    cout << "Lista dividida no 3° elemento: ";
    imprimirLista(listaDividida);
    cout << "Lista 1: ";
    imprimirLista(L1);
    cout << endl << endl;


    // Conferência final das listas
    cout << "Lista 1: ";
    imprimirLista(L1);
    cout << "Lista 2: ";
    imprimirLista(L2);

    // Liberação de memória
    liberarLista(L1);
    liberarLista(L2);
    liberarLista(lAux);
    liberarLista(listaMesclada);
    liberarLista(listaDividida);


    return 0;
}
