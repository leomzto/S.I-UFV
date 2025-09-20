#include <bits/stdc++.h>

using namespace std;

#ifndef PROCURAR_HPP
#define PROCURAR_HPP

typedef struct sNo {
    char info;
    sNo* prox;

    sNo(char elemento) : info(elemento), prox(nullptr) {};
} No;

int letras_comuns(No* palavra1, No* palavra2);

No* montarPalavra(string palavra);

#endif