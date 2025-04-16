#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_PALAVRA 100
#define TENTATIVAS_MAX 6

void jogar();
void esconder(char *palavra_oculta);
void exibir_erradas( char *letras_erradas, int contabilizar_erradas);
int letras_usadas(char *letras_erradas, int contabilizar_erradas, char letra);
int atualizar_palavra(char *palavra, char *palavra_oculta, char letra);


int main(void)
{
    jogar();

    return 0;
}

void jogar()
{
    char palavra[TAMANHO_PALAVRA];
    char palavra_oculta[TAMANHO_PALAVRA];
    char letras_erradas[TENTATIVAS_MAX];
    char letra;
    int tentativas = TENTATIVAS_MAX;
    int acertou;
    int contabilizar_erradas = 0;
    int i;

    printf("Escolha a palavra: ");
    scanf("%s", palavra);

    for (i = 0; i < strlen(palavra); i++)
    {
        palavra_oculta[i] = '_';
    }
    palavra_oculta[strlen(palavra)] = '\0';

    while (tentativas > 0)
    {
        printf("\nTente adivinar a palavra: ");
        esconder(palavra_oculta);

        printf("\nTentativas restantes: %d\n", tentativas);
        exibir_erradas(letras_erradas, contabilizar_erradas);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        if (letras_usadas(letras_erradas, contabilizar_erradas, letra))
        {
            printf("Você ja tentou essa letra.\nTente uma diferente.\n");
            continue;
        }

        acertou = atualizar_palavra(palavra, palavra_oculta, letra);

        if (acertou)
            printf("Boa! A letra %c está na palavra.\n", letra);
        else
        {
            printf("Opa!, a letra %c não está na palavra.\n", letra);
            letras_erradas[TENTATIVAS_MAX - tentativas] = letra;
            tentativas--;
        }

        if (strcmp(palavra, palavra_oculta) == 0)
        {
            printf("Ai sim!, você adivinhou a palavra: %s\n", palavra);
            break;
        }

        if (tentativas == 0)
        {
            printf("Você esgotou suas tentativas.\nBoa Sorte na próxima.");
            break;
        }

    }
    printf("\n");

}

void esconder(char *palavra_oculta)
{
    int i;
    for (i = 0; i < strlen(palavra_oculta); i++)
    {
        printf("%c ", palavra_oculta[i]);
    }
    printf("\n");
}

void exibir_erradas( char *letras_erradas, int contabilizar_erradas)
{
    int i;
    printf("Letras erradas: ");
    for (i = 0; i < contabilizar_erradas; i++)
    {
        printf("%c ", letras_erradas[i]);
    }
    printf("\n");
}

int letras_usadas(char *letras_erradas, int contabilizar_erradas, char letra)
{
    int i;
    for (int i = 0; i < contabilizar_erradas; i++) {
        if (letras_erradas[i] == letra) {
            return 1;
        }
    }
    return 0;
}

int atualizar_palavra(char *palavra, char *palavra_oculta, char letra)
{
    int i;
    int acertou = 0;
    for (i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] == letra)
        {
            palavra_oculta[i] = letra;
            acertou = 1;
        }
    }
    return acertou;
}
