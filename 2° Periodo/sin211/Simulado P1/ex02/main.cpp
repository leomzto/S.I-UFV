#include "procurar.hpp"

int main(void)
{
    No* palavra1 = montarPalavra("amor");
    No* palavra2 = montarPalavra("roma");

    int resposta = letras_comuns(palavra1, palavra2);

    cout << resposta << endl;
    
    return 0;
}