#include <stdio.h>

#define TAMANHO_TABULEIRO 3  // O tabuleiro é 3x3

// Função para exibir o tabuleiro
void exibir_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO_TABULEIRO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO_TABULEIRO - 1) printf("---+---+---\n");
    }
}

// Função para verificar se um jogador venceu
int verificar_vitoria(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], char jogador) {
    // Verificando linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return 1;
    }
    
    // Verificando colunas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return 1;
    }
    
    // Verificando diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return 1;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return 1;
    
    return 0;  // Nenhuma vitória
}

// Função para verificar empate
int verificar_empate(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;  // Se houver espaço vazio, não é empate
            }
        }
    }
    return 1;  // Se não houver espaços vazios, é empate
}

int main() {
    // Inicializando o tabuleiro com espaços vazios
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int linha, coluna, jogada_valida;
    char jogador_atual = 'X';  // Começa com o jogador X
    
    while (1) {
        exibir_tabuleiro(tabuleiro);
        jogada_valida = 0;
        
        // Pedir para o jogador fazer uma jogada
        while (!jogada_valida) {
            printf("Jogador %c, digite a linha e a coluna (1-3) para sua jogada: ", jogador_atual);
            scanf("%d %d", &linha, &coluna);
            
            // Ajustando para 0-2 (subtraindo 1)
            linha -= 1;
            coluna -= 1;
            
            // Verifica se a jogada é válida
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO && tabuleiro[linha][coluna] == ' ') {
                tabuleiro[linha][coluna] = jogador_atual;
                jogada_valida = 1;  // Jogada válida
            } else {
                printf("Jogada inválida. Tente novamente.\n");
            }
        }

        // Verificar se o jogador atual venceu
        if (verificar_vitoria(tabuleiro, jogador_atual)) {
            exibir_tabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", jogador_atual);
            break;
        }

        // Verificar empate
        if (verificar_empate(tabuleiro)) {
            exibir_tabuleiro(tabuleiro);
            printf("Empate!\n");
            break;
        }

        // Alternar entre os jogadores
        jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
    }

    return 0;
}
