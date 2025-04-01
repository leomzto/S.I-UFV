// Faça um programa que some os números ímpares contidos em um intervalo definido
// pelo usuário. O usuário define o valor inicial do intervalo e o valor final deste
// intervalo é o programa deve somar todos os números ímpares contidos neste
// intervalo. Caso o usuário digite um intervalo inválido (começando por um valor maior
// que o valor final) deve ser solicitado novamente os valores para o usuário, sendo
// que este processo irá repetir enquanto o usuário não entrar com um valor dentro do
// intervalo válido (começando por um valor menor que o valor final).
//
// Exemplo de tela de saída:
// Digite o valor inicial e valor final: 5 1
// Digite o valor inicial e valor final: 5 3
// Digite o valor inicial e valor final: 5 10
// Soma dos ımpares neste intervalo: 21

#include <stdio.h>

int main(void)
{
    int inicio, fim;
    int soma = 0;

    do{
        printf("Digite o valor inicial e valor final: ");
        scanf("%d%d", &inicio, &fim);
        
        if (inicio > fim)
        {
            printf("Você não pode colocar o valor inicial sendo menor que o final.\nTente novamente: ");
        }
    }
    while (inicio > fim);

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
