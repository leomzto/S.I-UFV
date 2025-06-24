#include <stdio.h>
#include <string.h>

#define MAX_CTTS 100

typedef struct
{
    char nome[50];
    char email[100];
    char observacao[500];

    struct Endereco
    {
        char rua[20];
        int numero;
        char complemento[20];
        char bairro[50];
        int cep;
        char cidade[50];
        char estado[3];
        char pais[20];
    } end;

    struct Telefone
    {
        int ddd;
        int numero;
    } fone;

    struct Aniversario
    {
        int dia, mes, ano;
    } niver;
    
} Agenda;

void cadastroAgenda(Agenda *ctt);
int adicionarContato(void);
void buscarPorNome(Agenda contatos[], int qtd, char nome[]);
void buscarPorMes(Agenda contatos[], int qtd, int mes);
void buscarPorDiaEMes(Agenda contatos[], int qtd, int dia, int mes);
void imprimirContato(Agenda ctt);

int main(void)
{
    Agenda contatos[MAX_CTTS];
    int qtd = 0, i, opcao;

    int adicionar_qtd = adicionarContato();
    if (adicionar_qtd > MAX_CTTS)
    {
        printf("Máximo de %d contatos permitido.\n", MAX_CTTS);
        return 1;
    }

    for(i = 0; i < adicionar_qtd; i++)
    {
        Agenda novo;
        printf("\nCadastro do Contato %d:\n", i + 1);
        cadastroAgenda(&novo);
    }

    do{
        puts("");
        puts("1. Buscar por nome");
        puts("2. Buscar por mês de aniversario");
        puts("3. Buscar por dia/mes de aniversario");
        puts("0. Sair");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch(opcao)
        {
            case 0:
                break;
            case 1:
            {
                char nomeBusca[50];
                printf("Digite o primeiro nome: ");
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
                buscarPorNome(contatos, qtd, nomeBusca);
                break;
            }
            case 2:
            {
                int mes;
                printf("Digite o mes do aniversario: ");
                scanf("%d", &mes);
                while (getchar() != '\n');
                buscarPorMes(contatos, qtd, mes);
                break;
            }
            case 3:
            {
                int dia, mes;
                printf("Digite o dia/mes do aniversario: ");
                scanf("%d/%d", &dia, &mes);
                while (getchar() != '\n');
                buscarPorDiaEMes(contatos, qtd, dia, mes);
                break;
            }
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 0);

    return 0;
}

void cadastroAgenda(Agenda *ctt)
{
    printf("Nome: ");
    fgets(ctt->nome, sizeof(ctt->nome), stdin);
    ctt->nome[strcspn(ctt->nome, "\n")] = '\0';

    printf("Email: ");
    fgets(ctt->email, sizeof(ctt->email), stdin);
    ctt->email[strcspn(ctt->email, "\n")] = '\0';

    puts("Endereço ");
    printf("Rua: ");
    fgets(ctt->end.rua, sizeof(ctt->end.rua), stdin);
    ctt->end.rua[strcspn(ctt->end.rua, "\n")] = '\0';

    printf("Número: ");
    scanf("%d", &ctt->end.numero);
    while (getchar() != '\n');

    printf("Complemento: ");
    fgets(ctt->end.complemento, sizeof(ctt->end.complemento), stdin);
    ctt->end.complemento[strcspn(ctt->end.complemento, "\n")] = '\0';

    printf("Bairro: ");
    fgets(ctt->end.bairro, sizeof(ctt->end.bairro), stdin);
    ctt->end.bairro[strcspn(ctt->end.bairro, "\n")] = '\0';

    printf("CEP: ");
    scanf("%d", &ctt->end.cep);
    while (getchar() != '\n');

    printf("Cidade: ");
    fgets(ctt->end.cidade, sizeof(ctt->end.cidade), stdin);
    ctt->end.cidade[strcspn(ctt->end.cidade, "\n")] = '\0';

    printf("Estado (UF): ");
    fgets(ctt->end.estado, sizeof(ctt->end.estado), stdin);
    ctt->end.estado[strcspn(ctt->end.estado, "\n")] = '\0';

    printf("País: ");
    fgets(ctt->end.pais, sizeof(ctt->end.pais), stdin);
    ctt->end.pais[strcspn(ctt->end.pais, "\n")] = '\0';

    puts("Telefone:");
    printf("DDD: ");
    scanf("%d", &ctt->fone.ddd);
    printf("Número: ");
    scanf("%d", &ctt->fone.numero);
    while (getchar() != '\n');

    puts("Data de aniversário (dia/mês/ano): ");
    scanf("%d/%d/%d", &ctt->niver.dia, &ctt->niver.mes, &ctt->niver.ano);
    while (getchar() != '\n');

    printf("Observação: ");
    fgets(ctt->observacao, sizeof(ctt->observacao), stdin);
    ctt->observacao[strcspn(ctt->observacao, "\n")] = '\0';
}

int adicionarContato(void)
{
    int qtd;
    printf("Quantos contatos vai adicionar?\n    >>>> ");
    scanf("%d", &qtd);
    while (getchar() != '\n');
    return qtd;
}

void imprimirContato(Agenda ctt)
{
    printf("\n--- Agenda ---\n");
    printf("Nome: %s\nEmail: %s\n", ctt.nome, ctt.email);
    printf("Endereço: Rua %s, Nº %d, %s, Bairro %s, CEP %d, %s - %s, %s\n",
        ctt.end.rua, ctt.end.numero, ctt.end.complemento, ctt.end.bairro,
        ctt.end.cep, ctt.end.cidade, ctt.end.estado, ctt.end.pais);
    printf("Telefone: (%d) %d\n", ctt.fone.ddd, ctt.fone.numero);
    printf("Aniversário: %02d/%02d/%04d\n", ctt.niver.dia, ctt.niver.mes, ctt.niver.ano);
    printf("Observação: %s\n", ctt.observacao);
}

void buscarPorNome(Agenda contatos[], int qtd, char nome[])
{
    int encontrou = 0;
    for(int i = 0; i < qtd; i++)
    {
        if(strncmp(contatos[i].nome, nome, strlen(nome)) == 0)
        {
            imprimirContato(contatos[i]);
            encontrou = 1;
        }
    }
    if(!encontrou)
        printf("Nenhum contato com esse nome.\n");
}

void buscarPorMes(Agenda contatos[], int qtd, int mes)
{
    int encontrou = 0;
    for(int i = 0; i < qtd; i++)
    {
        if(contatos[i].niver.mes == mes)
        {
            imprimirContato(contatos[i]);
            encontrou = 1;
        }
    }
    if(!encontrou)
        printf("Nenhum contato encontrado.\n");
}

void buscarPorDiaEMes(Agenda contatos[], int qtd, int dia, int mes)
{
    int encontrou = 0;
    for(int i = 0; i < qtd; i++)
    {
        if(contatos[i].niver.dia == dia && contatos[i].niver.mes == mes)
        {
            imprimirContato(contatos[i]);
            encontrou = 1;
        }
    }
    if(!encontrou)
        printf("Nenhum contato encontrado.\n");
}
