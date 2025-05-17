#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_CLASSES 6
#define NUM_INIMIGOS 12

typedef struct
{
    char nome[20];
    float vida, ataque, defesa;
} Classe;
const Classe CLASSES[] = {
    {"Guerreiro", 120.0f, 20.0f, 15.0f},
    {"Mago", 80.0f, 30.0f, 5.0f},
    {"Arqueiro", 100.0f, 25.0f, 10.0f},
    {"Paladino", 130.0f, 18.0f, 20.0f},
    {"Barbaro", 160.0f, 28.0f, 12.0f},
    {"Ladino", 90.0f, 22.0f, 8.0f}
};

typedef struct {
    char nome[50];
    Classe classe;
    float vida, ataque, defesa;
} Personagem;

typedef struct
{
    char nome[50];
    float vida, ataque, defesa;

    float chances_de_aparecer;
} Inimigo;
const Inimigo INIMIGOS[] = {
    {"Esqueleto", 50.0f, 10.0f, 5, 25.0f},
    {"Esqueleto Guerreiro", 80.0f, 15.0f, 8, 15.0f},
    {"Orc", 120.0f, 20.0f, 10, 20.0f},
    {"Chefe Orc", 200.0f, 30.0f, 15, 5.0f},
    {"Goblin", 40.0f, 12.0f, 4, 25.0f},
    {"Goblin Chefe", 90.0f, 18.0f, 6, 10.0f},
    {"Dragao Jovem", 300.0f, 40.0f, 20, 3.0f},
    {"Dragao Anciao", 600.0f, 70.0f, 35, 1.0f},
    {"Slime", 30.0f, 8.0f, 2, 30.0f},
    {"Slime Rei", 150.0f, 18.0f, 10, 5.0f},
    {"Demonio", 100.0f, 25.0f, 10, 7.0f},
    {"Lorde Demonio", 500.0f, 50.0f, 25, 0.5f}
};

// prototipos das funçoes
void limparBuffer(void);

int menu(void);
Personagem criarPersonagem(void);
Inimigo gerarInimigos(void);
void iniciarBatalha(Personagem *p, Inimigo *i);
void iniciarJogo(Personagem p);

// main
int main(void)
{
    srand(time(NULL));

    while(1)
    {
        int opcao;
        
        opcao = menu();
        Personagem p;

        if(opcao == 1)
        {
            p = criarPersonagem();
            iniciarJogo(p);
        }
        else if(opcao == 2)
        {
            int i;
            puts("Saindo");
            for(i = 0; i < 5; i++)
            {
                sleep(1);
                putchar('.');
                fflush(stdout);
            }
            puts("");
            break;
        }
    }

    return 0;
}

// funçoes
void limparBuffer(void)
{
    while(getchar() != '\n');
}

int menu(void) 
{
    int opcao;
    
    do {
        system("clear");
        
        puts("-=- RPG -=-");
        puts("1. Novo Jogo");
        puts("2. Sair");
        printf(" --> ");
        
        if(scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 2)
        {
            puts("Opcao invalida!");
            limparBuffer();
            sleep(1);
            continue;
        }
        
        if(opcao == 1)
        {
            int i;
            system("clear");
            puts("\nCarregando jogo");
            printf("Progresso: [");
            
            for(i = 0; i < 10; i++)
            {
                usleep(250000);
                putchar('#');
                fflush(stdout);
            }
            
            puts("] 100%\n");
            sleep(1);
        }
        
    } while(opcao < 1 || opcao > 2);
    
    return opcao;
}

Personagem criarPersonagem(void)
{
    Personagem p;

    char escolha_classe[20];
    bool classe_valida = false;

    int i;

    // criaçao do personagem
    limparBuffer();
    system("clear");
    puts("Cricao de personagem:");
    printf("Nome -> ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    p.nome[0] = toupper(p.nome[0]);

    printf("%s esta nascendo.\n", p.nome);
    for(i = 0; i < 10; i++)
        {
            usleep(250000);
            putchar('.');
            fflush(stdout);
        }
    sleep(1);

    // escolha da classe
    puts("\n\nEscolha sua classe:");
    for (i = 0; i < NUM_CLASSES; i++)
        printf("%d. %s | HP: %.1f | ATQ: %.1f | DEF: %.1f\n",
                i + 1, CLASSES[i].nome, CLASSES[i].vida, CLASSES[i].ataque, CLASSES[i].defesa);

    while(!classe_valida)
    {
        printf("\nEu escolho ser ");
        fgets(escolha_classe, sizeof(escolha_classe), stdin);
        escolha_classe[strcspn(escolha_classe, "\n")] = '\0';

        for(i = 0; i < NUM_CLASSES; i++)
        {
            if(strcasecmp(escolha_classe, CLASSES[i].nome) == 0)
            {
                p.classe = CLASSES[i];
                printf("Atribuindo a classe %s a %s.\n",p.classe.nome, p.nome);
                for(i = 0; i < 10; i++)
                {
                    usleep(250000);
                    putchar('.');
                    fflush(stdout);
                }
                sleep(1);
                
                printf("\n\n%s agora e %s\n", p.nome, p.classe.nome);
                classe_valida = true;

                sleep(2);
                system("clear");
                break;
            }
        }

        if(!classe_valida)
            puts("Classe invalida.");
    }

    p.vida = p.classe.vida;
    p.ataque = p.classe.ataque;
    p.defesa = p.classe.defesa;

    return p;
}

Inimigo gerarInimigos(void)
{
    int i;

    float chance_spawn = 0.0f;

    for(i = 0; i < 12; i++)
        chance_spawn += INIMIGOS[i].chances_de_aparecer;

    float sortear_inimigos = ((float)rand() / RAND_MAX) * chance_spawn;

    float soma_chances = 0.0f;
    for(i = 0; i < 12; i++)
    {
        soma_chances += INIMIGOS[i].chances_de_aparecer;
        if(sortear_inimigos <= soma_chances)
            return INIMIGOS[i];
    }

    return INIMIGOS[0];
    
}

void iniciarBatalha(Personagem *p, Inimigo *i)
{
    char escolha_jogador[20];

    float golpe_jogador = (*p).ataque - (*i).defesa;
    if(golpe_jogador < 1) golpe_jogador = 1;
    float golpe_inimigo = (*i).ataque - (*p).defesa;
    if(golpe_inimigo < 1) golpe_inimigo = 1;

    int j;
    puts("\nProcurando inimigos");
    for(j = 0; j < 10; j++)
        {
            usleep(250000);
            putchar('.');
            fflush(stdout);
        }
    sleep(1);
    puts("\n\nInimigo encontrado.");
    puts("Iniciando batalha");
    for(j = 0; j < 10; j++)
        {
            usleep(250000);
            putchar('.');
            fflush(stdout);
        }
    sleep(2);
    system("clear");

    printf("%s - %.1f HP\nVS.\n%s - %.1f HP\n",
         (*p).nome, (*p).vida, (*i).nome, (*i).vida);

    while((*p).vida > 0 && (*i).vida > 0)
    {
        // encontro com o inimigo
        puts("\n1. Atacar");
        puts("2. Correr");
        
        while(1)
        {
            printf("Eu escolho ");
            fgets(escolha_jogador, sizeof(escolha_jogador), stdin);
            escolha_jogador[strcspn(escolha_jogador, "\n")] = '\0';
            
            for(j = 0; escolha_jogador[j]; j++)
                escolha_jogador[j] = tolower(escolha_jogador[j]);

            // escolheu atacar
            if(strcasecmp(escolha_jogador, "atacar") == 0)
            {
                // vez do jogador
                printf("\nAtacando %s [", (*i).nome);
                for(j = 0; j < 7; j++)
                {
                    usleep(250000);
                    printf(">");
                    fflush(stdout);
                }
                puts("]");
                sleep(1);
                (*i).vida -= golpe_jogador;
                printf("Voce atacou %s e causou %.1f de dano.\n%s agora tem %.1f HP\n\n",
                     (*i).nome, golpe_jogador, (*i).nome, (*i).vida);

                // vez do inimigo
                if((*i).vida > 0)
                {
                    printf("%s esta te atacando [", (*i).nome);
                    for(j = 0; j < 7; j++)
                    {
                        usleep(250000);
                        printf(">");
                        fflush(stdout);
                    }
                    puts("]");
                    sleep(1);
                    (*p).vida -= golpe_inimigo;
                    printf("%s realizou um contra ataque causando %.1f de dano.\nVoce agora tem %.1f de vida\n\n", 
                    (*i).nome, golpe_inimigo, (*p).vida);
                }
                break;
            }
            // escolheu correr
            else if(strcasecmp(escolha_jogador, "correr") == 0)
            {
                puts("Voce escolheu correr, seu cagao.");
                sleep(2);
                system("clear");
                return;
            }
            else
                puts("\nEscolha invalida.\nVoce so pode atacar ou correr.\n");
        }

        if((*i).vida <= 0)
        {
            printf("Voce venceu a luta contra %s!\n", (*i).nome);
            sleep(2);
            system("clear");
            break;
        }
        else if((*p).vida <= 0)
        {
            printf("Voce perdeu a luta contra %s.\n", (*i).nome);
            sleep(2);
            system("clear");
            puts("Game Over");
            sleep(2);
            exit(0);
        }
    }
}

void iniciarJogo(Personagem p)
{
    while(p.vida > 0)
    {
        int escolha;
        puts("");
        puts("O que voce que fazer agora?");
        puts("1. Procurar monstros");
        printf("2. Ver [%s]\n", p.nome);
        puts("3. Voltar ao menu");
        printf("Escolha -> ");
        scanf("%d", &escolha);
        limparBuffer();

        if(escolha == 1)
        {
            Inimigo inimigo = gerarInimigos();
            iniciarBatalha(&p, &inimigo);
        }
        else if(escolha == 2)
        {
            int i;
            printf("\nCarregando status: [");
            for(i = 0; i < 7; i++)
            {
                usleep(250000);
                printf("#");
                fflush(stdout);
            }
            puts("] 100%");
            sleep(1);

            puts("");
            printf("Nome: %s\n", p.nome);
            printf("Classe: %s\n", p.classe.nome);
            printf("Vida: %.1f\n", p.vida);
            printf("Ataque: %1.f\n", p.ataque);
            printf("Defesa: %.1f\n", p.defesa);
            puts("");
            usleep(2500000);
        }
        else if(escolha == 3)
            return;
    }
}
