#include <stdio.h>

int diagSecundaria(int mat[5][5]);

int main(void) 
{
    int mat[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    int soma_elementos = diagSecundaria(mat);
    printf("Soma dos elementos da Diagonal secundaria: %d\n", soma_elementos);

    return 0;
}

int diagSecundaria(int mat[5][5])
{
    int soma_elementos = 0, l, c;
    printf("Elementos da Diagonal secundaria: ");
    for (l = 0; l < 5; l++) 
    {
        c = 4 - l;
        printf("%d ", mat[l][c]);
        soma_elementos += mat[l][c];
    }
    puts("");
    return soma_elementos;
}