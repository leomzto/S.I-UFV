#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lancaMoeda(void);

int main(void)
{
    srand(time(NULL));

    int i;
    int resultado;
    int cara = 0, coroa = 0;

    for(i = 0; i < 100; i++)
    {
        resultado = lancaMoeda();
        
        if(resultado == 0)
            cara++;
        else if(resultado == 1)
            coroa++;
    }
    printf("Cara: %d vezes\n", cara);
    printf("Coroa: %d vezes\n", coroa);
    
    return 0;
}

int lancaMoeda(void)
{
    return rand() % 2;
}

