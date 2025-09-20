#include "palindromo.hpp"

int main(void)
{
    Lista* palavra1 = montarPalavra("arara");
    Lista* palavra2 = montarPalavra("bacia");

    cout << verificarPalindromo(palavra1) << endl;
    cout << verificarPalindromo(palavra2) << endl;

    return 0;
}