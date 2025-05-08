#include <stdio.h>

struct Pessoa
{
    char nome[20];
    char sexo[2];
    float peso;

    struct Data
    {
        int dia, mes, ano;
    } dt;

    struct End
    {
        char rua[20];
        int numero;
        char cidade[20];
        char estado[3];
        int CEP;
    } end;
};

int main(void)
{
    struct Pessoa pss;

    printf("Nome: ");
    gets(pss.nome);

    printf("Sexo: ");
    gets(pss.sexo);

    printf("Peso: ");
    scanf("%f", &pss.peso);
    getchar();

    printf("Dia Nascimento: ");
    scanf("%d", &pss.dt.dia);
    getchar();

    printf("Mes Nascimento: ");
    scanf("%d", &pss.dt.mes);
    getchar();

    printf("Ano Nascimento: ");
    scanf("%d", &pss.dt.ano);
    getchar();

    printf("Rua: ");
    gets(pss.end.rua);

    printf("Número da rua: ");
    scanf("%d", &pss.end.numero);
    getchar();

    printf("Cidade: ");
    gets(pss.end.cidade);

    printf("Estado: ");
    gets(pss.end.estado);

    printf("CEP: ");
    scanf("%d", &pss.end.CEP);
    getchar();

    printf("\nDados:\n");
    printf("Nome: %s\nSexo: %s\nPeso: %.2f\nNascimento: %d/%d/%d\nRua: %s, %d, %s - %s\nCEP: %d\n", pss.nome, pss.sexo, pss.peso, pss.dt.dia, pss.dt.mes, pss.dt.ano, pss.end.rua, pss.end.numero, pss.end.cidade, pss.end.estado, pss.end.CEP);

    return 0;
}
