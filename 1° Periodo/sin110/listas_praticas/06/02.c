#include <stdio.h>
#include <string.h>

struct End
{
    char rua[20];
    int numero;
    char cidade[20];
    char estado[3];
    int CEP;
};

int main(void)
{
    struct End endereco;

    printf("Rua: ");
    fgets(endereco.rua, sizeof(endereco.rua), stdin);
    endereco.rua[strcspn(endereco.rua, "\n")] = '\0';

    printf("Número: ");
    scanf("%d", &endereco.numero);
    while (getchar() != '\n');

    printf("Cidade: ");
    fgets(endereco.cidade, sizeof(endereco.cidade), stdin);
    endereco.cidade[strcspn(endereco.cidade, "\n")] = '\0';

    printf("Estado: ");
    fgets(endereco.estado, sizeof(endereco.estado), stdin);
    endereco.estado[strcspn(endereco.estado, "\n")] = '\0';

    printf("CEP: ");
    scanf("%d", &endereco.CEP);
while (getchar() != '\n');

    printf("\nENDEREÇO:\n");
    printf("%s, %d - %s - %s\n", endereco.rua, endereco.numero, endereco.cidade, endereco.estado);
    printf("CEP: %d\n", endereco.CEP);


    return 0;
}
