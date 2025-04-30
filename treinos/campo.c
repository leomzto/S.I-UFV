#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3
#define NUM_BOMBAS (TAM * TAM) / 3
#define VIDAS 3

void inicializar(char campo[TAM][TAM], char valor);
void exibirCampo(char campo[TAM][TAM]);
void posicionarBombas(char campo[TAM][TAM]);

int main(void)
{
    char campo_real[TAM][TAM];
    char campo_visivel[TAM][TAM];
    int linha_escolhida, coluna_escolhida;
    bool posicao_valida;
    int vidas = VIDAS;

    inicializar(campo_real, '~');
    inicializar(campo_visivel, '~');

    while(1)
    {
        exibirCampo(campo_visivel);
        posicao_valida = false;

        posicionarBombas(campo_real);

        while (!posicao_valida)
        {
            printf("\nDigite a linha e a coluna para sua jogada: ");
            scanf("%d %d", &linha_escolhida, &coluna_escolhida);

            linha_escolhida -= 1;
            coluna_escolhida -= 1;

            if(linha_escolhida >= 0 && linha_escolhida < TAM && coluna_escolhida >= 0 && coluna_escolhida < TAM && campo_real[linha_escolhida][coluna_escolhida] == '~')
                {
                    campo_visivel[linha_escolhida][coluna_escolhida] = ' ';
                    posicao_valida = true;
                }
                else
                    printf("\nJogada repetida.\nEscolha outra posição.\n");
            if (linha_escolhida >= 0 && linha_escolhida < TAM && coluna_escolhida >= 0 && coluna_escolhida < TAM && campo_real[linha_escolhida][coluna_escolhida] == '*')
                {
                    campo_visivel[linha_escolhida][coluna_escolhida] = 'X';
                    posicao_valida = true;
                    vidas -= 1;
                }
                else
                    printf("\nJogada repetida.\nEscolha outra posição.\n");
        }
        if (vidas == 0)
        {
            printf("Você perdeu as vidas.\n");
            break;
        }
    }
 
    return 0;
}


void inicializar(char campo[TAM][TAM], char valor)
{
    int l, c;

    for (l = 0; l < TAM; l++)
    {
        for (c = 0; c < TAM; c++)
        {
            campo[l][c] = valor;
        }
    }
}
void exibirCampo(char campo[TAM][TAM])
{
    int linha, coluna;

    for(linha = 0; linha < TAM; linha++)
    {
        for(coluna = 0; coluna < TAM; coluna++)
        {
            printf(" %c ", campo[linha][coluna]);
            if (coluna < 2) printf("|");
        }
        printf("\n");
        if (linha < 2) printf("---|---|---\n");
    }
}

void posicionarBombas(char campo[TAM][TAM])
{
    int bombas = 0;

    while (bombas < NUM_BOMBAS)
    {
        int linha = rand() % TAM;
        int coluna = rand() % TAM;

        if(campo[linha][coluna]  != '*')
        {
            campo[linha][coluna] = '*';
            bombas++;
        }
    }
}