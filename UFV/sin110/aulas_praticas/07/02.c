#include <stdio.h>

typedef struct
{
    int dia, mes, ano;
} Data;

void exibirData(Data dt);

int main(void)
{
    int dia, mes, ano;
    printf("Entre com a data.\nFormatação: dia/mes/ano\n >>> ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    Data data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    exibirData(data);
}

void exibirData(Data dt)
{
    char *meses[13] = {"", "janeiro", "fevereiro", "março", "abril", "maio",
                   "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

    if (dt.mes >= 1 && dt.mes <= 12)
        printf("%d de %s de %d\n", dt.dia, meses[dt.mes], dt.ano);
    else
    {
        printf("Mês inválido.\n");
    }
}
