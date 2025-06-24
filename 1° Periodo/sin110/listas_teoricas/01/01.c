// Faça programa que some os números ímpares contidos em um intervalo definido
// pelo usuário. O usuário define o valor inicial do intervalo e o valor final deste
// intervalo e o programa deve somar todos os números ímpares contidos neste
// intervalo. Caso o usuário digite um intervalo inválido (começando por um valor maior
// que o valor final) deve ser escrito uma mensagem de erro na tela, “Intervalo de
// valores invalido” e o programa termina.
// Exemplo de tela de saída:
//      Digite o valor inicial e valor final: 5 10
//      Soma dos ímpares neste intervalo: 21

#include <stdio.h>

int main(void)
{
    int inicio, fim;
    int soma = 0;

    printf("Digite o valor inicial e valor final: ");
    scanf("%d%d", &inicio, &fim);

    for (int intervalo = inicio; intervalo <= fim; intervalo++)
    {
        if (intervalo % 2 != 0)
        {
            soma += intervalo;
        }
    }

    printf("Soma dos ímpares neste intervalo: %d\n", soma);

    return 0;
}
