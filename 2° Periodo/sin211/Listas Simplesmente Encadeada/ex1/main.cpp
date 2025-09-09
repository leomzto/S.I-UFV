#include "lse.h"

int main(void)
{
    Lista L1;
    L1.inicio = nullptr;

    Lista L2;
    L2.inicio = nullptr;

    inserirInicio(&L1, 1);
    inserirFim(&L1, 2);
    inserirFim(&L1, 3);
    inserirFim(&L1, 100);

    copiarLista(&L1, &L2);

    cout << "Lista 1:";
    imprimirLista(&L1);

    cout << "Lista 2 (copia L1):";
    imprimirLista(&L2);

    liberarLista(&L1);
    liberarLista(&L2);

    return 0;
}