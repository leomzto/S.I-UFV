#include <bits/stdc++.h>

using namespace std;

#ifndef PALINDROMO_HPP
#define PALINDROMO_HPP

typedef struct sNo {
    sNo* ant;
    char info;
    sNo* prox;

    sNo(char elemento) : ant(nullptr), info(elemento), prox(nullptr) {};
} No;

typedef struct sLista {
    No* inicio;
    No* fim;

    sLista() : inicio(nullptr), fim(nullptr) {};
} Lista;

int verificarPalindromo(Lista* p1);
Lista* montarPalavra(string palavra);

#endif