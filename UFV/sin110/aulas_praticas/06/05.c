#include <stdio.h>
#include <ctype.h>

struct Cadastro
{
    char nome[20];
    char sexo[10];
    char estado_civil[20];
    int idade, CPF, identidade, telefone;
    float salario;

    struct Endereco
    {
        char rua[50];
        int numero;
        char bairro[20];
        char complemento[20];
        char cidade[20];
        char estado[3];
        int CEP;
    } end;
};

int main(void)
{
    struct Cadastro cad[7];

    int maior_idade, i_maior_idade = 0;

    int i;

    for (i = 0; i < 7; i++)
    {
        printf("Cadastro %d:\n", i + 1);
        
        printf("Nome > ");
        fgets(cad[i].nome, sizeof(cad[i].nome), stdin);
        cad[i].nome[0] = toupper(cad[i].nome[0]);
        
        printf("Sexo (M | F) > ");
        fgets(cad[i].sexo, sizeof(cad[i].sexo), stdin);
        cad[i].sexo[0] = toupper(cad[i].sexo[0]);
        
        printf("Idade > ");
        scanf("%d", &cad[i].idade);
        getchar();
        
        printf("Identidade > ");
        scanf("%d", &cad[i].identidade);
        getchar();
        
        printf("CPF > ");
        scanf("%d", &cad[i].CPF);
        getchar();
        
        printf("Estado Civil > ");
        fgets(cad[i].estado_civil, sizeof(cad[i].estado_civil), stdin);
        
        printf("Telefone > ");
        scanf("%d", &cad[i].telefone);
        getchar();
        
        printf("Salario > R$");
        scanf("%f", &cad[i].salario);
        getchar();
        
        printf("Endereço:\n");
        printf("Rua > ");
        fgets(cad[i].end.rua, sizeof(cad[i].end.rua), stdin);
        printf("Numero > ");
        scanf("%d", &cad[i].end.numero);
        getchar();
        printf("Complemento > ");
        fgets(cad[i].end.complemento, sizeof(cad[i].end.complemento), stdin);
        printf("Bairro > ");
        fgets(cad[i].end.bairro, sizeof(cad[i].end.bairro), stdin);
        printf("Cidade > ");
        fgets(cad[i].end.cidade, sizeof(cad[i].end.cidade), stdin);
        printf("Estado > ");
        fgets(cad[i].end.estado, sizeof(cad[i].end.estado), stdin);

        printf("CEP > ");
        scanf("%d", &cad[i].end.CEP);
        getchar();
    }

    maior_idade = cad[0].idade;
    for (i = 1; i < 7; i++)
    {
        if (cad[i].idade > maior_idade)
        {
            maior_idade = cad[i].idade;
            i_maior_idade = i;
        }
    }

    printf("Homens:\n");
    for (i = 0; i < 7; i++)
    {
        if (cad[i].sexo[0] == 'M')
            printf("%s\n", cad[i].nome);
    }

    printf("Salarios acima de R$1.000:\n");
    for (i = 0; i < 7; i++)
    {
        if (cad[i].salario > 1000.00)
            printf("%s: R$%.2f\n", cad[i].nome, cad[i].salario);
    }

    return 0;
}
